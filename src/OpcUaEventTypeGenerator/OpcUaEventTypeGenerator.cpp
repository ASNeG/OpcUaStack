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
#include <iostream>
#include <sstream>
#include "OpcUaStackCore/Utility/Environment.h"
#include "OpcUaEventTypeGenerator/OpcUaEventTypeGenerator.h"
#include "OpcUaStackCore/Base/ConfigXml.h"
#include "OpcUaStackServer/EventType/EventTypeGenerator.h"
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
		    ( "help",
		      "produce help message"
		    )
			( "version",
			  "print version string"
			)
		    ( "nodeset",
		      boost::program_options::value<std::string>(),
			  "set nodeset file name (mandatory)"
			)
			( "eventtype",
			  boost::program_options::value<std::string>(),
			  "set event type name (mandatory)"
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

		// ignore BaseEventType
		if (eventTypeName_ == "BaseEventType") {
			return 1;
		}

		return generateEventTypeSource();
	}

	int32_t
	OpcUaEventTypeGenerator::generateEventTypeSource(void)
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

		// find node id for event type name
		eventTypeNodeId_.set(0,0);
		if (!findNodeId(eventTypeName_, OpcUaNodeId(2041))) {
			std::cout << "node id not found for event type " << eventTypeName_ << std::endl;
			return -3;
		}

		// generate event type source code
		EventTypeGenerator eventTypeGenerator;
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


