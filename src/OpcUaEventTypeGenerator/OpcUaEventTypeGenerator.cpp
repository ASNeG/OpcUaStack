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

#include <boost/filesystem/fstream.hpp>
#include <iostream>
#include <sstream>
#include "OpcUaStackCore/Utility/Environment.h"
#include "OpcUaEventTypeGenerator/OpcUaEventTypeGenerator.h"
#include "OpcUaStackCore/Base/ConfigXml.h"
#include "OpcUaStackServer/EventType/EventTypeGenerator.h"
#include "OpcUaStackServer/NodeSet/NodeSetXmlParser.h"
#include "OpcUaStackServer/InformationModel/InformationModelNodeSet.h"

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
	{
	}

	OpcUaEventTypeGenerator::~OpcUaEventTypeGenerator(void)
	{
	}

	uint32_t
	OpcUaEventTypeGenerator::start(int argc, char** argv)
	{
		// check command line arguments
		if (argc != 3) {
			usage();
			return 1;
		}

		std::string fileName = argv[1];
		std::string eventTypeName = argv[2];

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
		InformationModel::SPtr informationModel = constructSPtr<InformationModel>();
		if (!InformationModelNodeSet::initial(informationModel, nodeSetXmlParser)) {
			std::cout << "init information model error" << std::endl;
			return -3;
		}
		informationModel->checkForwardReferences();

		return 0;
	}

	void
	OpcUaEventTypeGenerator::usage(void)
	{
		std::cout <<
			"OpcUaEventTypeGenerator <NodeSetFileName> <EventTypeName>\n"
			"\n"
			"<NodeSetFileName>\n"
			"  name of the nodesetfile\n"
			"<EventTypeName>\n"
			"  name of the event type\n"
			"\n";
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


