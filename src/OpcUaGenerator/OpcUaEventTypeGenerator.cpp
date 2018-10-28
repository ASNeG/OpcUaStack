/*
   Copyright 2017 Kai Huebl (kai@huebl-sgh.de)

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
#include <OpcUaGenerator/OpcUaEventTypeGenerator.h>
#include <OpcUaStackServer/Generator/EventTypeGenerator.h>
#include <iostream>
#include <sstream>
#include "OpcUaStackCore/Utility/Environment.h"
#include "OpcUaStackCore/Base/ConfigXml.h"
#include "OpcUaStackServer/NodeSet/NodeSetXmlParser.h"
#include "OpcUaStackServer/InformationModel/InformationModelNodeSet.h"
#include "OpcUaStackServer/InformationModel/InformationModelAccess.h"
#include "BuildConfig.h"

using namespace OpcUaStackCore;
using namespace OpcUaStackServer;

namespace OpcUaEventTypeGenerator
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUaEventTypeGenerator
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	OpcUaEventTypeGenerator::OpcUaEventTypeGenerator(void)
	: eventTypeNodeId_(0)
	, informationModel_()
	, fileName_("")
	, eventTypeName_("")
	, projectNamespace_("")
	, parentProjectNamespace_("")
	, buildSubTypes_(false)
	, eventTypeNameVec_()
	, ignoreEventTypeNameVec_()
	{
	}

	OpcUaEventTypeGenerator::~OpcUaEventTypeGenerator(void)
	{
	}

	uint32_t
	OpcUaEventTypeGenerator::start(int argc, char** argv)
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
				boost::program_options::value<std::string>(),
				"set nodeset file name (mandatory)"
			)
			(
				"eventtype",
				boost::program_options::value<std::string>(),
				"set event type name (mandatory)"
			)
			(
				"projectNamespace",
				boost::program_options::value<std::string>()->default_value("OpcUaStackCore"),
			    "set project namespace"
			)
			(
				"parentProjectNamespace",
				boost::program_options::value<std::string>()->default_value("OpcUaStackCore"),
			    "set parent project namespace"
			)
			(
				"buildSubTypes",
				boost::program_options::value<bool>()->default_value(false),
			    "build all subtypes"
			)
			(
				"ignoreEventTypeName",
				boost::program_options::value< std::vector<std::string> >(),
			    "ignore event type name"
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

		if (vm.count("eventtype") == 0) {
		    std::cout << desc << std::endl;
		    return 1;
		}

		// vm["input-file"].as< vector<string> >()

		fileName_ = vm["nodeset"].as<std::string>();
		eventTypeName_ = vm["eventtype"].as<std::string>();
		projectNamespace_ = vm["projectNamespace"].as<std::string>();
		parentProjectNamespace_ = vm["parentProjectNamespace"].as<std::string>();
		buildSubTypes_ = vm["buildSubTypes"].as<bool>();
		if (vm.count("ignoreEventTypeName") != 0) {
			ignoreEventTypeNameVec_ = vm["ignoreEventTypeName"].as< std::vector<std::string> >();
		}

		if (buildSubTypes_) {
			return buildAllSubTypes();
		}

		// ignore BaseEventType
		if (eventTypeName_ == "BaseEventType") {
			return 1;
		}

		// load inforomation model
		int32_t rc = loadInformationModel();
		if (rc < 0) {
			return rc;
		}

		return generateEventTypeSource();
	}

	int32_t
	OpcUaEventTypeGenerator::loadInformationModel(void)
	{
		// read opc ua nodeset
		ConfigXml configXml;
	    if (!configXml.parse(fileName_)) {
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
		informationModel_ = constructSPtr<InformationModel>();
		if (!InformationModelNodeSet::initial(informationModel_, nodeSetXmlParser)) {
			std::cout << "init information model error" << std::endl;
			return -3;
		}
		informationModel_->checkForwardReferences();

		return 0;
	}

	int32_t
	OpcUaEventTypeGenerator::buildAllSubTypes(void)
	{
		// load inforomation model
		int32_t rc = loadInformationModel();
		if (rc < 0) {
			return rc;
		}

		// find node id for event type name
		eventTypeNodeId_.set(0,0);
		if (!findNodeId(eventTypeName_, OpcUaNodeId(2041))) {
			std::cout << "node id not found for event type " << eventTypeName_ << std::endl;
			return -3;
		}

		// find all sub types
		if (findAllSubTypes(eventTypeNodeId_) < 0) {
			return -4;
		}

		// create source
		std::vector<std::string>::iterator it;
		for (it = eventTypeNameVec_.begin(); it != eventTypeNameVec_.end(); it++) {
			eventTypeName_ = *it;
			int32_t rc = generateEventTypeSource();
			if (rc < 0) return rc;
		}

		return 0;
	}

	int32_t
	OpcUaEventTypeGenerator::findAllSubTypes(const OpcUaNodeId& eventTypeNodeId)
	{
		// find node id in information model
		BaseNodeClass::SPtr nodeClass = informationModel_->find(eventTypeNodeId);
		if (!nodeClass) {
			std::cout << "node " << eventTypeNodeId << " not found in information model" << std::endl;
			return false;
		}

		// get browse name
		OpcUaQualifiedName browseName;
		if (!nodeClass->getBrowseName(browseName)) {
			std::cout << "browsename of node " << eventTypeNodeId << " error" << std::endl;
			return false;
		}

		if (browseName.name().toStdString() != "BaseEventType") {
			eventTypeNameVec_.push_back(browseName.name().toStdString());
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
			std::cout << "node " << eventTypeNodeId << " subtype error" << std::endl;
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

	int32_t
	OpcUaEventTypeGenerator::generateEventTypeSource(void)
	{
		// check event type name
		std::vector<std::string>::iterator it;
		for (it=ignoreEventTypeNameVec_.begin(); it!=ignoreEventTypeNameVec_.end(); it++) {
			if (*it == eventTypeName_) {
				return 0;
			}
		}

		// find node id for event type name
		eventTypeNodeId_.set(0,0);
		if (!findNodeId(eventTypeName_, OpcUaNodeId(2041))) {
			std::cout << "node id not found for event type " << eventTypeName_ << std::endl;
			return -3;
		}

		// generate event type source code
		EventTypeGenerator eventTypeGenerator;
		eventTypeGenerator.projectNamespace(projectNamespace_);
		eventTypeGenerator.parentProjectNamespace(parentProjectNamespace_);
		eventTypeGenerator.informationModel(informationModel_);
		eventTypeGenerator.eventType(eventTypeNodeId_);
		if (!eventTypeGenerator.generate()) {
			std::cout << "source code generator error - " << eventTypeName_ << std::endl;
			return -4;
		}

		// save header and source file
		boost::filesystem::ofstream ofStream;
		std::string sourceContent = eventTypeGenerator.sourceContent();
		std::string headerContent = eventTypeGenerator.headerContent();

		std::string headerFileName = eventTypeName_ + ".h";
		boost::filesystem::remove(headerFileName);
		ofStream.open(headerFileName, std::ios::out);
		ofStream << headerContent;
		ofStream.close();

		std::string sourceFileName = eventTypeName_ + ".cpp";
		boost::filesystem::remove(sourceFileName);
		ofStream.open(sourceFileName, std::ios::out);
		ofStream << sourceContent;
		ofStream.close();

		return 0;
	}

	bool
	OpcUaEventTypeGenerator::findNodeId(const std::string& eventTypeName, const OpcUaNodeId& nodeId)
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
			eventTypeNodeId_ = nodeId;
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
	OpcUaEventTypeGenerator::OpcUaEventTypeGenerator projectBuilder;
	return projectBuilder.start(argc, argv);
}


