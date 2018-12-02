/*
   Copyright 2018 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   Informationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Kai Huebl (kai@huebl-sgh.de)
 */

#include <boost/filesystem.hpp>
#include <boost/filesystem/fstream.hpp>
#include <boost/program_options.hpp>
#include "OpcUaStackCore/Utility/Environment.h"
#include "OpcUaStackCore/Base/ConfigXml.h"
#include "OpcUaStackServer/NodeSet/NodeSetXmlParser.h"
#include "OpcUaStackServer/InformationModel/InformationModelNodeSet.h"
#include "OpcUaStackServer/InformationModel/InformationModelAccess.h"
#include "OpcUaStackServer/Generator/EnumTypeGenerator.h"
#include "OpcUaGenerator/OpcUaEnumTypeGenerator.h"
#include "BuildConfig.h"

namespace OpcUaEnumTypeGenerator
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUaEnumTypeGenerator
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	OpcUaEnumTypeGenerator::OpcUaEnumTypeGenerator(void)
	: enumTypeNodeId_(0)
	, informationModel_()
	, fileNames_()
	, enumTypeName_("")
	, namespaces_()
	, buildSubTypes_(false)
	, enumTypeNameVec_()
	, ignoreEnumTypeNameVec_()
	{
	}

	OpcUaEnumTypeGenerator::~OpcUaEnumTypeGenerator(void)
	{
		// FIXME: todo
	}

	uint32_t
	OpcUaEnumTypeGenerator::start(int argc, char** argv)
	{
		boost::program_options::options_description desc("Allowed options");
		desc.add_options()
		    (
		    	"help",
				"produce help message"
		    )
			(
				"version",
				"print version string"
			)
		    (
		    	"nodeset",
				boost::program_options::value< std::vector<std::string> >(),
				"set nodeset file name (mandatory)"
			)
			(
				"enumtype",
				boost::program_options::value<std::string>(),
				"set enum type name (mandatory)"
			)
			(
				"namespaces_",
				boost::program_options::value< std::vector<std::string> >(),
			    "set project namespaces"
			)
			(
				"buildSubTypes",
				boost::program_options::value<bool>()->default_value(false),
			    "build all subtypes"
			)
			(
				"ignoreEnumTypeName",
				boost::program_options::value< std::vector<std::string> >(),
			    "ignore data type name"
			)
			(
				"nodeId",
				boost::program_options::value<std::string>()->default_value("ns=0;i=0"),
			    "node id of the enum data type"
			)
		;

		boost::program_options::variables_map vm;
		boost::program_options::store(boost::program_options::parse_command_line(argc, argv, desc), vm);
		boost::program_options::notify(vm);

		if (vm.count("help")) {
		    std::cout << desc << std::endl;
		    return 1;
		}

		if (vm.count("version")) {
		    std::cout << VERSION_MAJOR << "." << VERSION_MINOR << "." << VERSION_PATCH <<  std::endl;
		    return 1;
		}

		if (vm.count("nodeset") == 0) {
		    std::cout << desc << std::endl;
		    return 1;
		}

		if (vm.count("enumtype") == 0) {
		    std::cout << desc << std::endl;
		    return 1;
		}

		// vm["input-file"].as< vector<string> >()

		if (vm.count("nodeset") != 0) {
			fileNames_ = vm["nodeset"].as< std::vector<std::string> >();
		}

		enumTypeName_ = vm["enumtype"].as<std::string>();

		nodeId_ = vm["nodeId"].as<std::string>();
		enumTypeNodeId_.fromString(nodeId_);

		if (vm.count("namespaces") != 0) {
			namespaces_ = vm["namespaces"].as< std::vector<std::string> >();
		}

		buildSubTypes_ = vm["buildSubTypes"].as<bool>();

		if (vm.count("ignoreEventTypeName") != 0) {
			ignoreEnumTypeNameVec_ = vm["ignoreEnumTypeName"].as< std::vector<std::string> >();
		}

		if (buildSubTypes_) {
			return buildAllSubTypes();
		}

		// ignore enum data type
		if (enumTypeName_ == "Enumeration") {
			return 1;
		}

		// load inforomation model
		int32_t rc = loadInformationModel();
		if (rc < 0) {
			return rc;
		}

		return generateEnumTypeSource();
	}

	bool
	OpcUaEnumTypeGenerator::findNodeId(const std::string& eventTypeName, const OpcUaNodeId& nodeId)
	{
		bool success;

		// find node id in information model
		BaseNodeClass::SPtr nodeClass = informationModel_->find(nodeId);
		if (!nodeClass) {
			std::cout << "node " << nodeId << " not found in information model" << std::endl;
			return false;
		}

		// get browse name
		OpcUaQualifiedName browseName;
		if (!nodeClass->getBrowseName(browseName)) {
			std::cout << "browsename of node " << nodeId << " error" << std::endl;
			return false;
		}

		// check browse name
		if (browseName.name().toStdString() == eventTypeName) {
			enumTypeNodeId_ = nodeId;
			return true;
		}

		// find subtype childs
		InformationModelAccess ima;
		OpcUaNodeId referenceType(45);
		std::vector<OpcUaNodeId> childNodeIdVec;
		std::vector<OpcUaNodeId>::iterator it;
		ima.informationModel(informationModel_);
		success = ima.getChildHierarchically(
			nodeClass,
			referenceType,
			childNodeIdVec
		);
		if (!success) {
			std::cout << "node " << nodeId << " subtype error" << std::endl;
			return false;
		}

		for (it = childNodeIdVec.begin(); it != childNodeIdVec.end(); it++) {
			success = findNodeId(eventTypeName, *it);
			if (success) {
				return true;
			}
		}

		return false;
	}

	bool
	OpcUaEnumTypeGenerator::existNodeId(const OpcUaNodeId& nodeId)
	{
		// find node id in information model
		BaseNodeClass::SPtr nodeClass = informationModel_->find(nodeId);
		if (!nodeClass) {
			std::cout << "node " << nodeId << " not found in information model" << std::endl;
			return false;
		}

		return true;
	}

	int32_t
	OpcUaEnumTypeGenerator::loadInformationModel(void)
	{
		// create a new information model
		informationModel_ = constructSPtr<InformationModel>();

		std::vector<std::string>::iterator it;
		for (it = fileNames_.begin(); it != fileNames_.end(); it++) {

			std::string fileName = *it;

			// read opc ua nodeset
			ConfigXml configXml;
			if (!configXml.parse(fileName)) {
				std::cout << configXml.errorMessage() << std::endl;
				return -1;
			}

			// parse node set file
			NodeSetXmlParser nodeSetXmlParser;
			if (!nodeSetXmlParser.decode(configXml.ptree())) {
				std::cout << "node set parser error" << std::endl;
				return -2;
			}

			// init information model
			if (!InformationModelNodeSet::initial(informationModel_, nodeSetXmlParser)) {
				std::cout << "init information model error" << std::endl;
				return -3;
			}

		}

		informationModel_->checkForwardReferences();

		return 0;
	}

	int32_t
	OpcUaEnumTypeGenerator::generateEnumTypeSource(void)
	{
		// check data type name
		std::vector<std::string>::iterator it;
		for (it=ignoreEnumTypeNameVec_.begin(); it!=ignoreEnumTypeNameVec_.end(); it++) {
			if (*it == enumTypeName_) {
				return 0;
			}
		}

		//std::cout << "Name=" << enumTypeName_ << std::endl;
		//std::cout << "NodeId=" << enumTypeNodeId_.toString() << std::endl;

		// find node id for data type name
		if (enumTypeNodeId_ == OpcUaNodeId(0,0)) {
			if (!findNodeId(enumTypeName_, OpcUaNodeId(29))) {
				std::cout << "node id not found for data type " << enumTypeName_ << std::endl;
				return -3;
			}
		}
		else {
			if (!existNodeId(enumTypeNodeId_)) {
				std::cout << "node id not found for data type " << enumTypeNodeId_.toString() << std::endl;
				return -3;
			}
		}

		//std::cout << "Name=" << enumTypeName_ << std::endl;
		//std::cout << "NodeId=" << enumTypeNodeId_.toString() << std::endl;

		// generate data type source code
		EnumTypeGenerator dataTypeGenerator;
		for (it = namespaces_.begin(); it != namespaces_.end(); it++) {
			dataTypeGenerator.setNamespaceEntry(*it);
		}
		dataTypeGenerator.informationModel(informationModel_);
		if (!dataTypeGenerator.generate(enumTypeNodeId_)) {
			std::cout << "source code generator error - " << enumTypeName_ << std::endl;
			return -4;
		}

		// save header and source file
		boost::filesystem::ofstream ofStream;
		std::string sourceContent = dataTypeGenerator.sourceContent();
		std::string headerContent = dataTypeGenerator.headerContent();

		std::string headerFileName = enumTypeName_ + ".h";
		boost::filesystem::remove(headerFileName);
		ofStream.open(headerFileName, std::ios::out);
		ofStream << headerContent;
		ofStream.close();

		std::string sourceFileName = enumTypeName_ + ".cpp";
		boost::filesystem::remove(sourceFileName);
		ofStream.open(sourceFileName, std::ios::out);
		ofStream << sourceContent;
		ofStream.close();

		std::cout << "generate " << enumTypeName_ << " success" << std::endl;
		return 0;
	}

	int32_t
	OpcUaEnumTypeGenerator::buildAllSubTypes(void)
	{
		// load inforomation model
		int32_t rc = loadInformationModel();
		if (rc < 0) {
			return rc;
		}

		// find node id for data type name. After the call the variable
		// enumTypeNodeId contains the node identifier
		enumTypeNodeId_.set(0);
		if (!findNodeId(enumTypeName_, OpcUaNodeId(29))) {
			std::cout << "node id not found for data type " << enumTypeName_ << std::endl;
			return -3;
		}

		// find all sub types. After the call the variable enumTypeNameVec_
		// contains all subtype names
		if (findAllSubTypes(enumTypeNodeId_) < 0) {
			return -4;
		}

		// create source
		std::vector<std::string>::iterator it;
		for (it = enumTypeNameVec_.begin(); it != enumTypeNameVec_.end(); it++) {
			enumTypeNodeId_.set(0);
			enumTypeName_ = *it;
			if (enumTypeName_ == "Enumeration") {
				continue;
			}
			int32_t rc = generateEnumTypeSource();
			if (rc < 0) return rc;
		}

		return 0;
	}

	int32_t
	OpcUaEnumTypeGenerator::findAllSubTypes(const OpcUaNodeId& enumTypeNodeId)
	{
		// find node id in information model
		BaseNodeClass::SPtr nodeClass = informationModel_->find(enumTypeNodeId);
		if (!nodeClass) {
			std::cout << "node " << enumTypeNodeId << " not found in information model" << std::endl;
			return false;
		}

		// get browse name
		OpcUaQualifiedName browseName;
		if (!nodeClass->getBrowseName(browseName)) {
			std::cout << "browsename of node " << enumTypeNodeId << " error" << std::endl;
			return false;
		}

		if (browseName.name().toStdString() != "BaseEnumType") {
			enumTypeNameVec_.push_back(browseName.name().toStdString());
		}

		// find subtype childs
		InformationModelAccess ima;
		OpcUaNodeId referenceType(45);
		std::vector<OpcUaNodeId> childNodeIdVec;
		std::vector<OpcUaNodeId>::iterator it;
		ima.informationModel(informationModel_);
		bool success = ima.getChildHierarchically(
			nodeClass,
			referenceType,
			childNodeIdVec
		);
		if (!success) {
			std::cout << "node " << enumTypeNodeId << " subtype error" << std::endl;
			return -1;
		}

		for (it = childNodeIdVec.begin(); it != childNodeIdVec.end(); it++) {
			success = findAllSubTypes(*it);
			if (success) {
				return 0;
			}
		}

		return 0;
	}

}

// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
//
// main application
//
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
int main(int argc, char** argv)
{
	OpcUaEnumTypeGenerator::OpcUaEnumTypeGenerator projectBuilder;
	return projectBuilder.start(argc, argv);
}


