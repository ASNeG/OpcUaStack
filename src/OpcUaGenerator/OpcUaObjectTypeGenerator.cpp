/*
   Copyright 2019-2020 Kai Huebl (kai@huebl-sgh.de)

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
#include "OpcUaStackServer/Generator/ObjectTypeGenerator.h"
#include "OpcUaGenerator/OpcUaObjectTypeGenerator.h"
#include "BuildConfig.h"

using namespace OpcUaStackCore;
using namespace OpcUaStackServer;

namespace OpcUaObjectTypeGenerator
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUaObjectTypeGenerator
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	OpcUaObjectTypeGenerator::OpcUaObjectTypeGenerator(void)
	: objectTypeNodeId_(0)
	, informationModel_()
	, fileNames_()
	, objectTypeName_("")
	, namespaces_()
	, buildSubTypes_(false)
	, objectTypeNameVec_()
	, ignoreObjectTypeNameVec_()
	{
	}

	OpcUaObjectTypeGenerator::~OpcUaObjectTypeGenerator(void)
	{
		// FIXME: todo
	}

	uint32_t
	OpcUaObjectTypeGenerator::start(int argc, char** argv)
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
				"objecttype",
				boost::program_options::value<std::string>(),
				"set object type name (mandatory)"
			)
			(
				"namespaces",
				boost::program_options::value< std::vector<std::string> >(),
			    "set project namespaces"
			)
			(
				"buildSubTypes",
				boost::program_options::value<bool>()->default_value(false),
			    "build all subtypes"
			)
			(
				"ignoreObjectTypeName",
				boost::program_options::value< std::vector<std::string> >(),
			    "ignore object type name"
			)
			(
				"fileNamespace",
				boost::program_options::value<std::string>(),
				"namespace name in source and header file"
			)
			(
				"headerFilePath",
				boost::program_options::value<std::string>(),
				"file path of the header include in the source file"
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

		if (vm.count("objecttype") == 0) {
		    std::cout << desc << std::endl;
		    return 1;
		}

		if (vm.count("nodeset") != 0) {
			fileNames_ = vm["nodeset"].as< std::vector<std::string> >();
		}

		objectTypeName_ = vm["objecttype"].as<std::string>();

		if (vm.count("namespaces") != 0) {
			namespaces_ = vm["namespaces"].as< std::vector<std::string> >();
		}

		buildSubTypes_ = vm["buildSubTypes"].as<bool>();

		if (vm.count("ignoreEventTypeName") != 0) {
			ignoreObjectTypeNameVec_ = vm["ignoreObjectTypeName"].as< std::vector<std::string> >();
		}

		if (buildSubTypes_) {
			return buildAllSubTypes();
		}

		// ignore object data type
		if (objectTypeName_ == "ObjectTypes") {
			return 1;
		}

		// load information model
		int32_t rc = loadInformationModel();
		if (rc < 0) {
			return rc;
		}

		return generateObjectTypeSource();
	}

	bool
	OpcUaObjectTypeGenerator::findNodeId(const std::string& objectTypeName, const OpcUaNodeId& nodeId)
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
		if (browseName.name().toStdString() == objectTypeName) {
			objectTypeNodeId_ = nodeId;
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
			success = findNodeId(objectTypeName, *it);
			if (success) {
				return true;
			}
		}

		return false;
	}

	int32_t
	OpcUaObjectTypeGenerator::loadInformationModel(void)
	{
		// create a new information model
		informationModel_ = boost::make_shared<InformationModel>();

		for (auto fileName : fileNames_) {
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
	OpcUaObjectTypeGenerator::generateObjectTypeSource(void)
	{
		// check object type name
		for (auto objectTypeName : ignoreObjectTypeNameVec_) {
			if (objectTypeName == objectTypeName_) {
				return 0;
			}
		}

		// find node id for object type name
		objectTypeNodeId_.set(0,0);
		if (!findNodeId(objectTypeName_, OpcUaNodeId(58))) {
			std::cout << "node id not found for object type " << objectTypeName_ << std::endl;
			return -3;
		}

		// generate object type source code
		ObjectTypeGenerator objectTypeGenerator;
		for (auto namespaceName : namespaces_) {
			objectTypeGenerator.setNamespaceEntry(namespaceName);
		}
		objectTypeGenerator.informationModel(informationModel_);
		if (!objectTypeGenerator.generate(objectTypeNodeId_)) {
			std::cout << "source code generator error - " << objectTypeName_ << std::endl;
			return -4;
		}

		// save header and source file
		boost::filesystem::ofstream ofStream;
		std::string sourceContent = objectTypeGenerator.sourceContent();
		std::string headerContent = objectTypeGenerator.headerContent();

		std::string headerFileName = objectTypeName_ + ".h";
		boost::filesystem::remove(headerFileName);
		ofStream.open(headerFileName, std::ios::out);
		ofStream << headerContent;
		ofStream.close();

		std::string sourceFileName = objectTypeName_ + ".cpp";
		boost::filesystem::remove(sourceFileName);
		ofStream.open(sourceFileName, std::ios::out);
		ofStream << sourceContent;
		ofStream.close();

		return 0;
	}

	int32_t
	OpcUaObjectTypeGenerator::buildAllSubTypes(void)
	{
		// load information model
		int32_t rc = loadInformationModel();
		if (rc < 0) {
			return rc;
		}

		// find node id for object type name
		objectTypeNodeId_.set(0,0);
		if (!findNodeId(objectTypeName_, OpcUaNodeId(58))) {
			std::cout << "node id not found for object type " << objectTypeName_ << std::endl;
			return -3;
		}

		// find all sub types
		if (findAllSubTypes(objectTypeNodeId_) < 0) {
			return -4;
		}

		// create source
		std::vector<std::string>::iterator it;
		for (it = objectTypeNameVec_.begin(); it != objectTypeNameVec_.end(); it++) {
			objectTypeName_ = *it;

			// ignore structure data type
			if (objectTypeName_ == "ObjectTypes") {
				continue;
			}

			int32_t rc = generateObjectTypeSource();
			if (rc < 0) return rc;
		}

		return 0;
	}

	int32_t
	OpcUaObjectTypeGenerator::findAllSubTypes(const OpcUaNodeId& dataTypeNodeId)
	{
		// find node id in information model
		BaseNodeClass::SPtr nodeClass = informationModel_->find(dataTypeNodeId);
		if (!nodeClass) {
			std::cout << "node " << dataTypeNodeId << " not found in information model" << std::endl;
			return false;
		}

		// get browse name
		OpcUaQualifiedName browseName;
		if (!nodeClass->getBrowseName(browseName)) {
			std::cout << "browsename of node " << dataTypeNodeId << " error" << std::endl;
			return false;
		}

		if (browseName.name().toStdString() != "ObjectTypes") {
			objectTypeNameVec_.push_back(browseName.name().toStdString());
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
			std::cout << "node " << dataTypeNodeId << " subtype error" << std::endl;
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
