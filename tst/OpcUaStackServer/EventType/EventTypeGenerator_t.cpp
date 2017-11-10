#include "unittest.h"
#include "OpcUaStackCore/Base/ConfigXml.h"
#include "OpcUaStackServer/Generator/EventTypeGenerator.h"
#include "OpcUaStackServer/NodeSet/NodeSetXmlParser.h"
#include "OpcUaStackServer/InformationModel/InformationModelNodeSet.h"

using namespace OpcUaStackServer;

BOOST_AUTO_TEST_SUITE(EventTypeGenerator_)

BOOST_AUTO_TEST_CASE(EventTypeGenerator_)
{
	std::cout << "EventTypeGenerator_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(EventTypeGenerator_construct_destruct)
{
	bool success;
	EventTypeGenerator eventTypeGenerator;
}

BOOST_AUTO_TEST_CASE(EventTypeGenerator_xx)
{
	bool success;

	// read opc ua nodeset
	ConfigXml configXml;
    success = configXml.parse("../tst/data/Opc.Ua.NodeSet.xml");
    if (!success) {
    	std::cout << configXml.errorMessage() << std::endl;
    }
    BOOST_REQUIRE(success == true);

    NodeSetXmlParser nodeSetXmlParser;
    success = nodeSetXmlParser.decode(configXml.ptree());
    BOOST_REQUIRE(success == true);

    NodeSetNamespace& nodeSetNamespace = nodeSetXmlParser.nodeSetNamespace();
    NamespaceVec& namespaceVec = nodeSetNamespace.localNamespaceVec();
    NamespaceVec::iterator it;

	InformationModel::SPtr informationModel = constructSPtr<InformationModel>();
	success = InformationModelNodeSet::initial(informationModel, nodeSetXmlParser);
	BOOST_REQUIRE(success == true);

	informationModel->checkForwardReferences();


	// gernerate event type source
	OpcUaNodeId eventTypeNodeId(2052);
	EventTypeGenerator eventTypeGenerator;
	eventTypeGenerator.informationModel(informationModel);
	eventTypeGenerator.eventType(eventTypeNodeId);
	BOOST_REQUIRE(eventTypeGenerator.generate() == true);

	std::string sourceContent = eventTypeGenerator.sourceContent();
	std::string headerContent = eventTypeGenerator.headerContent();

	std::cout << std::endl;
	std::cout << headerContent << std::endl;
	std::cout << std::endl;
	std::cout << sourceContent << std::endl;
	std::cout << std::endl;

}

BOOST_AUTO_TEST_SUITE_END()
