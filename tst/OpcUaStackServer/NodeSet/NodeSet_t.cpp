#include "unittest.h"
#include "OpcUaStackCore/Base/ConfigXml.h"
#include <boost/property_tree/xml_parser.hpp>
#include "OpcUaStackServer/NodeSet/NodeSetXmlParser.h"

using namespace OpcUaStackCore;
using namespace OpcUaStackServer;

BOOST_AUTO_TEST_SUITE(NodeSet_)

BOOST_AUTO_TEST_CASE(NodeSet_)
{
	std::cout << "NodeSet_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(NodeSet_clear)
{
	NodeSetNamespace nodeSetNamespace;

	nodeSetNamespace.clear();
	nodeSetNamespace.clearGlobal();
}

BOOST_AUTO_TEST_CASE(NodeSet_read_xml)
{
	ConfigXml configXml;
	
	// read xml file
	BOOST_REQUIRE(configXml.parse("../tst/data/Opc.Ua.NodeSet2.xml") == true);
}

BOOST_AUTO_TEST_CASE(NodeSet_decode_xml)
{
	ConfigXml configXml;
	NodeSetXmlParser nodeSetXmlParser;

	// read xml file and decode
	BOOST_REQUIRE(configXml.parse("../tst/data/Opc.Ua.NodeSet2.xml") == true);
	BOOST_REQUIRE(nodeSetXmlParser.decode(configXml.ptree()) == true);
}

BOOST_AUTO_TEST_CASE(NodeSet_encode_xml)
{
	ConfigXml configXml;
	NodeSetXmlParser nodeSetXmlParser;

	// read xml file and decode
	BOOST_REQUIRE(configXml.parse("../tst/data/Opc.Ua.NodeSet2.xml") == true);
	BOOST_REQUIRE(nodeSetXmlParser.decode(configXml.ptree()) == true);

	// encode xml file and write to stream
	boost::property_tree::ptree ptree;
	BOOST_REQUIRE(nodeSetXmlParser.encode(ptree) == true);
	configXml.ptree(ptree);
	BOOST_REQUIRE(configXml.write("tmp") == true);
}

BOOST_AUTO_TEST_SUITE_END()
