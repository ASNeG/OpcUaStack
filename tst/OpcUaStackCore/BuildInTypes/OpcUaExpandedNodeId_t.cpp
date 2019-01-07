#include "unittest.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaExpandedNodeId.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaNodeId.h"
#include "OpcUaStackCore/Base/Utility.h"
#include <boost/iostreams/stream.hpp>
#include <boost/property_tree/json_parser.hpp>

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(OpcUaExpandedNodeId_)

void writeDocument3(boost::property_tree::ptree& pt)
{
#if 0
	std::cout << "READ" << std::endl;

	std::stringstream ss1;
	boost::property_tree::ptree js;
	ss1 << "{ \"Value\": \"123\" }";
	boost::property_tree::json_parser::read_json(ss1, js);

	std::cout << "WRITE:" << std::endl;
#endif

	boost::property_tree::ptree xx;
	xx.add_child("AAA", pt);

	std::stringstream ss2;
	boost::property_tree::json_parser::write_json(ss2, xx);
	std::cout << "Document: " << ss2.str() << std::endl;
}

BOOST_AUTO_TEST_CASE(OpcUaExpandedNodeId_)
{
	std::cout << "OpcUaExpandedNodeId_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(OpcUaExpandedNodeId_two_byte_representation)
{
	std::stringstream ss;
	OpcUaExpandedNodeId value1, value2;

	value1.nodeId((OpcUaInt32)11);
	
	value1.opcUaBinaryEncode(ss);
	BOOST_REQUIRE(count(ss) == 2);
	value2.opcUaBinaryDecode(ss);

	BOOST_REQUIRE(value2.namespaceIndex() == 0);
	BOOST_REQUIRE(value2.nodeId<OpcUaUInt32>() == 11);
	BOOST_REQUIRE(value2.namespaceUri().exist() == false);
	BOOST_REQUIRE(value2.serverIndex() == 0);
}

BOOST_AUTO_TEST_CASE(OpcUaExpandedNodeId_namespaceUri_yes_ServerIndex_no)
{
	std::stringstream ss;
	OpcUaExpandedNodeId value1, value2;

	value1.namespaceIndex(345);
	value1.nodeId((OpcUaInt32)11);
	value1.namespaceUri("URI");
	
	value1.opcUaBinaryEncode(ss);
	value2.opcUaBinaryDecode(ss);

	BOOST_REQUIRE(value2.namespaceIndex() == 0);
	BOOST_REQUIRE(value2.nodeId<OpcUaUInt32>() == 11);
	BOOST_REQUIRE(value2.namespaceUri().exist() == true);
	BOOST_REQUIRE(value2.namespaceUri().value() == "URI");
	BOOST_REQUIRE(value2.serverIndex() == 0);
}

BOOST_AUTO_TEST_CASE(OpcUaExpandedNodeId_namespaceUri_yes_ServerIndex_no_ptree)
{
	boost::property_tree::ptree pt;
	OpcUaExpandedNodeId value1, value2;
	Xmlns xmlns;

	value1.namespaceIndex(345);
	value1.nodeId((OpcUaInt32)11);
	value1.namespaceUri("URI");

	value1.xmlEncode(pt, xmlns);
	value2.xmlDecode(pt, xmlns);

	BOOST_REQUIRE(value2.namespaceIndex() == 0);
	BOOST_REQUIRE(value2.nodeId<OpcUaUInt32>() == 11);
	BOOST_REQUIRE(value2.namespaceUri().exist() == true);
	BOOST_REQUIRE(value2.namespaceUri().value() == "URI");
	BOOST_REQUIRE(value2.serverIndex() == 0);
}

BOOST_AUTO_TEST_CASE(OpcUaExpandedNodeId_namespaceUri_no_ServerIndex_yes)
{
	std::stringstream ss;
	OpcUaExpandedNodeId value1, value2;

	value1.namespaceIndex(345);
	value1.nodeId((OpcUaInt32)11);
	value1.serverIndex(4711);
	
	value1.opcUaBinaryEncode(ss);
	value2.opcUaBinaryDecode(ss);

	BOOST_REQUIRE(value2.namespaceIndex() == 345);
	BOOST_REQUIRE(value2.nodeId<OpcUaUInt32>() == 11);
	BOOST_REQUIRE(value2.namespaceUri().exist() == false);
	BOOST_REQUIRE(value2.serverIndex() == 4711);
}

BOOST_AUTO_TEST_CASE(OpcUaExpandedNodeId_namespaceUri_no_ServerIndex_yes_ptree)
{
	boost::property_tree::ptree pt;
	OpcUaExpandedNodeId value1, value2;
	Xmlns xmlns;

	value1.namespaceIndex(345);
	value1.nodeId((OpcUaInt32)11);
	value1.serverIndex(4711);

	value1.xmlEncode(pt, xmlns);
	writeDocument3(pt);
	value2.xmlDecode(pt, xmlns);

	BOOST_REQUIRE(value2.namespaceIndex() == 345);
	BOOST_REQUIRE(value2.nodeId<OpcUaUInt32>() == 11);
	BOOST_REQUIRE(value2.namespaceUri().exist() == false);
	BOOST_REQUIRE(value2.serverIndex() == 4711);
}

BOOST_AUTO_TEST_CASE(OpcUaExpandedNodeId_namespaceUri_yes_ServerIndex_yes)
{
	std::stringstream ss;
	OpcUaExpandedNodeId value1, value2;

	value1.namespaceIndex(345);
	value1.nodeId((OpcUaInt32)11);
	value1.namespaceUri("URI");
	value1.serverIndex(4711);
	
	value1.opcUaBinaryEncode(ss);
	value2.opcUaBinaryDecode(ss);

	BOOST_REQUIRE(value2.namespaceIndex() == 0);
	BOOST_REQUIRE(value2.nodeId<OpcUaUInt32>() == 11);
	BOOST_REQUIRE(value2.namespaceUri().exist() == true);
	BOOST_REQUIRE(value2.namespaceUri().value() == "URI");
	BOOST_REQUIRE(value2.serverIndex() == 4711);
}

BOOST_AUTO_TEST_CASE(OpcUaExpandedNodeId_namespaceUri_yes_ServerIndex_yes_ptree)
{
	boost::property_tree::ptree pt;
	OpcUaExpandedNodeId value1, value2;
	Xmlns xmlns;

	value1.namespaceIndex(345);
	value1.nodeId((OpcUaInt32)11);
	value1.namespaceUri("URI");
	value1.serverIndex(4711);

 	BOOST_REQUIRE(value1.xmlEncode(pt, xmlns) == true);
	BOOST_REQUIRE(value2.xmlDecode(pt, xmlns) == true);

	BOOST_REQUIRE(value2.namespaceIndex() == 0);
	BOOST_REQUIRE(value2.nodeId<OpcUaUInt32>() == 11);
	BOOST_REQUIRE(value2.namespaceUri().exist() == true);
	BOOST_REQUIRE(value2.namespaceUri().value() == "URI");
	BOOST_REQUIRE(value2.serverIndex() == 4711);
}

BOOST_AUTO_TEST_CASE(OpcUaExpandedNodeId_copyTo)
{
	std::stringstream ss;
	OpcUaExpandedNodeId value1, value2;

	value1.namespaceIndex(0);
	value1.nodeId((OpcUaInt32)11);
	value1.namespaceUri("URI");
	value1.serverIndex(4711);
	
	value1.copyTo(value2);

	BOOST_REQUIRE(value1.namespaceIndex() == 0);
	BOOST_REQUIRE(value1.nodeId<OpcUaUInt32>() == 11);
	BOOST_REQUIRE(value1.namespaceUri().exist() == true);
	BOOST_REQUIRE(value1.namespaceUri().value() == "URI");
	BOOST_REQUIRE(value1.serverIndex() == 4711);

	BOOST_REQUIRE(value2.namespaceIndex() == 0);
	BOOST_REQUIRE(value2.nodeId<OpcUaUInt32>() == 11);
	BOOST_REQUIRE(value2.namespaceUri().exist() == true);
	BOOST_REQUIRE(value2.namespaceUri().value() == "URI");
	BOOST_REQUIRE(value2.serverIndex() == 4711);

	value1.namespaceUri("URI1");
	value1.serverIndex(4712);

	BOOST_REQUIRE(value1.namespaceIndex() == 0);
	BOOST_REQUIRE(value1.nodeId<OpcUaUInt32>() == 11);
	BOOST_REQUIRE(value1.namespaceUri().exist() == true);
	BOOST_REQUIRE(value1.namespaceUri().value() == "URI1");
	BOOST_REQUIRE(value1.serverIndex() == 4712);

	BOOST_REQUIRE(value2.namespaceIndex() == 0);
	BOOST_REQUIRE(value2.nodeId<OpcUaUInt32>() == 11);
	BOOST_REQUIRE(value2.namespaceUri().exist() == true);
	BOOST_REQUIRE(value2.namespaceUri().value() == "URI");
	BOOST_REQUIRE(value2.serverIndex() == 4711);
}

BOOST_AUTO_TEST_CASE(OpcUaExpandedNodeId_copyNodeId)
{
	OpcUaExpandedNodeId value1;
	OpcUaNodeId value2;

	value1.namespaceIndex(0);
	value1.nodeId((OpcUaInt32)11);

	value2.namespaceIndex(value1.namespaceIndex());
	value2.nodeIdValue(value1.nodeIdValue());

	BOOST_REQUIRE(value1.namespaceIndex() == 0);
	BOOST_REQUIRE(value1.nodeId<OpcUaUInt32>() == 11);

	BOOST_REQUIRE(value2.namespaceIndex() == 0);
	BOOST_REQUIRE(value2.nodeId<OpcUaUInt32>() == 11);

}

BOOST_AUTO_TEST_CASE(OpcUaExpandedNodeId_fromString_toString)
{
	OpcUaExpandedNodeId value1;
	BOOST_REQUIRE(value1.fromString("svr=4711;ns=1;s=NodeName") == true);
	BOOST_REQUIRE(value1.toString() == "svr=4711;ns=1;s=NodeName");

	OpcUaExpandedNodeId value2;
	BOOST_REQUIRE(value2.fromString("svr=4711;nsu=NamespaceUri;s=NodeName") == true);
	BOOST_REQUIRE(value2.toString() == "svr=4711;nsu=NamespaceUri;s=NodeName");
}

BOOST_AUTO_TEST_SUITE_END()
