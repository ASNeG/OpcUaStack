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

BOOST_AUTO_TEST_CASE(NodeSet_read_xml)
{
	ConfigXml configXml;
	
	BOOST_REQUIRE(configXml.parse("TestData/Opc.Ua.NodeSet2.xml") == true);
	BOOST_REQUIRE(configXml.parse("TestData/Opc.Ua.NodeSet_Test1.xml") == true);
}

BOOST_AUTO_TEST_CASE(NodeSet_decode_xml)
{
	ConfigXml configXml;
	NodeSetXmlParser nodeSetXmlParser;
	
	std::cout << "Test NodeSet_decode_xml" << std::endl;

	BOOST_REQUIRE(configXml.parse("TestData/Opc.Ua.NodeSet2.xml") == true);
	BOOST_REQUIRE(nodeSetXmlParser.decode(configXml.ptree()) == true);

	std::cout << "Test finish" << std::endl << std::endl;
}

BOOST_AUTO_TEST_CASE(NodeSet_decode_encode_xml)
{
	ConfigXml decodeConfigXml;
	ConfigXml encodeConfigXml;
	NodeSetXmlParser nodeSetXmlParser;
	
	std::cout << "Test decode and encode NodeSet_xml" << std::endl;
	
	std::cout << "Decode. Pfad<TestData/Opc.Ua.NodeSet_Test1.xml>" << std::endl;
	BOOST_REQUIRE(decodeConfigXml.parse("TestData/Opc.Ua.NodeSet_Test1.xml") == true);
	BOOST_REQUIRE(nodeSetXmlParser.decode(decodeConfigXml.ptree()) == true);
	
	std::cout << "Encode." << std::endl;
	BOOST_REQUIRE(nodeSetXmlParser.encode(encodeConfigXml.ptree()) == true);
	
	std::cout << "Write new XML-File. Pfad<TestData/Opc.Ua.NodeSet_Test1_encodefile.xml>" << std::endl;
	boost::property_tree::xml_writer_settings<char> settings('\t', 1);
	write_xml("TestData/Opc.Ua.NodeSet_Test1_encodefile.xml", encodeConfigXml.ptree(), std::locale(), settings);

	std::cout << "Test finish" << std::endl;
}

BOOST_AUTO_TEST_SUITE_END()