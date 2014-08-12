#include "unittest.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaNodeId.h"
#include "OpcUaStackCore/Base/Utility.h"
#include <boost/iostreams/stream.hpp>

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(OpcUaNodeId_)

BOOST_AUTO_TEST_CASE(OpcUaNodeId_)
{
	std::cout << "OpcUaNodeId_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(OpcUaNodeId_two_byte_representation)
{
	std::stringstream ss;
	OpcUaNodeId value1, value2;

	value1.nodeId((OpcUaInt32)11);
	
	value1.opcUaBinaryEncode(ss);
	BOOST_REQUIRE(count(ss) == 2);
	value2.opcUaBinaryDecode(ss);

	BOOST_REQUIRE(value2.namespaceIndex() == 0);
	BOOST_REQUIRE(value2.nodeId<OpcUaUInt32>() == 11);
}

BOOST_AUTO_TEST_CASE(OpcUaNodeId_four_byte_representation)
{
	std::stringstream ss;
	OpcUaNodeId value1, value2;

	value1.namespaceIndex(123);
	value1.nodeId((OpcUaInt32)11);
	
	value1.opcUaBinaryEncode(ss);
	BOOST_REQUIRE(count(ss) == 4);
	value2.opcUaBinaryDecode(ss);

	BOOST_REQUIRE(value2.namespaceIndex() == 123);
	BOOST_REQUIRE(value2.nodeId<OpcUaUInt32>() == 11);
}

BOOST_AUTO_TEST_CASE(OpcUaNodeId_other1_byte_representation)
{
	std::stringstream ss;
	OpcUaNodeId value1, value2;

	value1.namespaceIndex(130);
	value1.nodeId((OpcUaUInt32)11);
	
	value1.opcUaBinaryEncode(ss);
	BOOST_REQUIRE(count(ss) == 4);
	value2.opcUaBinaryDecode(ss);

	BOOST_REQUIRE(value2.namespaceIndex() == 130);
	BOOST_REQUIRE(value2.nodeId<OpcUaUInt32>() == 11);
}

BOOST_AUTO_TEST_CASE(OpcUaNodeId_other2_byte_representation)
{
	std::stringstream ss;
	OpcUaNodeId value1, value2;

	value1.namespaceIndex(123);
	value1.nodeId((OpcUaUInt32)0x10000);
	
	value1.opcUaBinaryEncode(ss);
	BOOST_REQUIRE(count(ss) > 4);
	value2.opcUaBinaryDecode(ss);

	BOOST_REQUIRE(value2.namespaceIndex() == 123);
	BOOST_REQUIRE(value2.nodeId<OpcUaUInt32>() == 0x10000);
}

BOOST_AUTO_TEST_CASE(OpcUaNodeId_type_OpcUaUInt32)
{
	std::stringstream ss;
	OpcUaNodeId value1, value2;

	value1.namespaceIndex(123);
	value1.nodeId((OpcUaInt32)0x10000);
	
	value1.opcUaBinaryEncode(ss);
	value2.opcUaBinaryDecode(ss);
	
	BOOST_REQUIRE(value2.nodeIdType() == OpcUaBuildInType_OpcUaUInt32);
	BOOST_REQUIRE(value2.namespaceIndex() == 123);
	BOOST_REQUIRE(value2.nodeId<OpcUaUInt32>() == 0x10000);
}

BOOST_AUTO_TEST_CASE(OpcUaNodeId_type_OpcUaString_SPtr)
{
	std::string str;
	std::stringstream ss;
	OpcUaNodeId value1, value2;
	
	OpcUaString::SPtr opcUaStringSPtr = OpcUaString::construct();
	opcUaStringSPtr->value("Dies ist ein String");

	value1.namespaceIndex(123);
	value1.nodeId(opcUaStringSPtr);
	
	value1.opcUaBinaryEncode(ss);
	value2.opcUaBinaryDecode(ss);

	BOOST_REQUIRE(value2.nodeIdType() == OpcUaBuildInType_OpcUaString);
	BOOST_REQUIRE(value2.namespaceIndex() == 123);
	BOOST_REQUIRE(value2.nodeId<OpcUaString::SPtr>()->value() == "Dies ist ein String");
}

BOOST_AUTO_TEST_CASE(OpcUaNodeId_type_OpcUaGuid_SPtr)
{
	std::string str;
	std::stringstream ss;
	OpcUaNodeId value1, value2;
	
	OpcUaGuid::SPtr opcUaGuidSPtr = OpcUaGuid::construct();
	*opcUaGuidSPtr = "12345678-9ABC-DEF0-1234-56789ABCDEF0";

	value1.namespaceIndex(123);
	value1.nodeId(opcUaGuidSPtr);
	
	value1.opcUaBinaryEncode(ss);
	value2.opcUaBinaryDecode(ss);

	str = *value2.nodeId<OpcUaGuid::SPtr>();
	BOOST_REQUIRE(value2.nodeIdType() == OpcUaBuildInType_OpcUaGuid);
	BOOST_REQUIRE(value2.namespaceIndex() == 123);
	BOOST_REQUIRE(str == "12345678-9ABC-DEF0-1234-56789ABCDEF0");
}

BOOST_AUTO_TEST_CASE(OpcUaNodeId_type_OpcUaByteString_SPtr)
{
	std::stringstream ss;
	OpcUaNodeId value1, value2;
	
	OpcUaByteString::SPtr opcUaByteStringSPtr = OpcUaByteString::construct();
	opcUaByteStringSPtr->value("0123456789", 10);

	value1.namespaceIndex(123);
	value1.nodeId(opcUaByteStringSPtr);
	
	value1.opcUaBinaryEncode(ss);
	value2.opcUaBinaryDecode(ss);

	char *buf;
	OpcUaInt32 bufLen;
	value2.nodeId<OpcUaByteString::SPtr>()->value(&buf, &bufLen);
	BOOST_REQUIRE(value2.nodeIdType() == OpcUaBuildInType_OpcUaByteString);
	BOOST_REQUIRE(value2.namespaceIndex() == 123);
	BOOST_REQUIRE(bufLen == 10);
	BOOST_REQUIRE(memcmp(buf, "0123456789", 10) == 0);
}

BOOST_AUTO_TEST_CASE(OpcUaNodeId_copyTo1)
{
	OpcUaNodeId opcUaNodeId1, opcUaNodeId2;

	opcUaNodeId1.namespaceIndex(4711);
	opcUaNodeId1.nodeId(4712);

	opcUaNodeId1.copyTo(opcUaNodeId2);

	BOOST_REQUIRE(opcUaNodeId2.namespaceIndex() == 4711);
	OpcUaUInt32 nodeId = opcUaNodeId2.nodeId<OpcUaUInt32>(); 
	BOOST_REQUIRE(nodeId == 4712);
}

BOOST_AUTO_TEST_CASE(OpcUaNodeId_copyTo2)
{
	OpcUaNodeId opcUaNodeId1, opcUaNodeId2;
	OpcUaString::SPtr opcUaString1, opcUaString2;

	opcUaString1 = OpcUaString::construct();
	opcUaString1->value("ABC");

	opcUaNodeId1.namespaceIndex(4711);
	opcUaNodeId1.nodeId(opcUaString1);

	opcUaNodeId1.copyTo(opcUaNodeId2);

	BOOST_REQUIRE(opcUaNodeId2.namespaceIndex() == 4711);
	opcUaString2 = opcUaNodeId2.nodeId<OpcUaString::SPtr>(); 
	std::string nodeId = opcUaString2->value();
	BOOST_REQUIRE(nodeId == "ABC");
}

BOOST_AUTO_TEST_CASE(OpcUaNodeId_map)
{
	typedef std::map<OpcUaNodeId, uint32_t> OpcUaNodeIdMap;
	OpcUaNodeIdMap opcUaNodeIdMap;

	OpcUaNodeId opcUaNodeId1;

	opcUaNodeId1.namespaceIndex(4711);
	opcUaNodeId1.nodeId(4712);

	opcUaNodeIdMap.insert(std::make_pair(opcUaNodeId1, 34567));
}

BOOST_AUTO_TEST_SUITE_END()
