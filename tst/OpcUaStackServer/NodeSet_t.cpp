#include "unittest.h"
#include "OpcUaStackCore/Base/ConfigXml.h"
#include "OpcUaStackServer/NodeSet/NodeSetXmlParser.h"

using namespace OpcUaStackCore;
using namespace OpcUaStackServer;

BOOST_AUTO_TEST_SUITE(NodeSet_)

BOOST_AUTO_TEST_CASE(NodeSet_)
{
	std::cout << "NodeSet_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(NodeSet_read_xml)
{
	ConfigXml configXml;
	
	BOOST_REQUIRE(configXml.parse("TestData/Opc.Ua.NodeSet2.xml") == true);
}

BOOST_AUTO_TEST_CASE(NodeSet_decode_xml)
{
	ConfigXml configXml;
	NodeSetXmlParser nodeSetXmlParser;
	
	BOOST_REQUIRE(configXml.parse("TestData/Opc.Ua.NodeSet2.xml") == true);
	BOOST_REQUIRE(nodeSetXmlParser.decode(configXml.ptree()) == true);
}

BOOST_AUTO_TEST_SUITE_END()