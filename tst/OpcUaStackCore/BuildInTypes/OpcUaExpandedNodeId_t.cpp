#include "unittest.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaExpandedNodeId.h"
#include "OpcUaStackCore/Base/Utility.h"
#include <boost/iostreams/stream.hpp>

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(OpcUaExpandedNodeId_)

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


BOOST_AUTO_TEST_SUITE_END()