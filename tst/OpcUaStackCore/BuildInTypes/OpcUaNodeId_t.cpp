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

BOOST_AUTO_TEST_CASE(OpcUaNodeId_null)
{
	std::stringstream ss;
	OpcUaNodeId value1, value2;
	
	value1.opcUaBinaryEncode(ss);
	BOOST_REQUIRE(count(ss) == 2);
	value2.opcUaBinaryDecode(ss);

	BOOST_REQUIRE(value2.namespaceIndex() == 0);
	BOOST_REQUIRE(value2.nodeId<OpcUaUInt32>() == 0);
}

BOOST_AUTO_TEST_CASE(OpcUaNodeId_isdNull)
{
	OpcUaNodeId nodeId;
	BOOST_REQUIRE(nodeId.isNull() == true);
	nodeId.set("Id", 0);
	BOOST_REQUIRE(nodeId.isNull() == false);
	nodeId.setNull();
	BOOST_REQUIRE(nodeId.isNull() == true);

	nodeId.set("Id", 0);
	BOOST_REQUIRE(nodeId.isNull() == false);
	nodeId.set(OpcUaNodeIdNullType());
	BOOST_REQUIRE(nodeId.isNull() == true);
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

BOOST_AUTO_TEST_CASE(OpcUaNodeId_type_OpcUaUInt32_ptree)
{
	boost::property_tree::ptree pt;
	OpcUaNodeId value1, value2;
	Xmlns xmlns;

	value1.namespaceIndex(123);
	value1.nodeId((OpcUaInt32)0x10000);

	value1.xmlEncode(pt, xmlns);
	value2.xmlDecode(pt, xmlns);

	BOOST_REQUIRE(value2.nodeIdType() == OpcUaBuildInType_OpcUaUInt32);
	BOOST_REQUIRE(value2.namespaceIndex() == 123);
	BOOST_REQUIRE(value2.nodeId<OpcUaUInt32>() == 0x10000);
}

BOOST_AUTO_TEST_CASE(OpcUaNodeId_type_OpcUaString_SPtr)
{
	std::string str;
	std::stringstream ss;
	OpcUaNodeId value1, value2;
	
	OpcUaString::SPtr opcUaStringSPtr = constructSPtr<OpcUaString>();
	opcUaStringSPtr->value("Dies ist ein String");

	value1.namespaceIndex(123);
	value1.nodeId(opcUaStringSPtr);
	
	value1.opcUaBinaryEncode(ss);
	value2.opcUaBinaryDecode(ss);

	BOOST_REQUIRE(value2.nodeIdType() == OpcUaBuildInType_OpcUaString);
	BOOST_REQUIRE(value2.namespaceIndex() == 123);
	BOOST_REQUIRE(value2.nodeId<OpcUaString::SPtr>()->value() == "Dies ist ein String");
}

BOOST_AUTO_TEST_CASE(OpcUaNodeId_type_OpcUaString_SPtr_ptree)
{
	std::string str;
	boost::property_tree::ptree pt;
	OpcUaNodeId value1, value2;
	Xmlns xmlns;

	OpcUaString::SPtr opcUaStringSPtr = constructSPtr<OpcUaString>();
	opcUaStringSPtr->value("Dies ist ein String");

	value1.namespaceIndex(123);
	value1.nodeId(opcUaStringSPtr);

	value1.xmlEncode(pt, xmlns);
	value2.xmlDecode(pt, xmlns);

	BOOST_REQUIRE(value2.nodeIdType() == OpcUaBuildInType_OpcUaString);
	BOOST_REQUIRE(value2.namespaceIndex() == 123);
	BOOST_REQUIRE(value2.nodeId<OpcUaString::SPtr>()->value() == "Dies ist ein String");
}

BOOST_AUTO_TEST_CASE(OpcUaNodeId_type_OpcUaGuid_SPtr)
{
	std::string str;
	std::stringstream ss;
	OpcUaNodeId value1, value2;
	
	OpcUaGuid::SPtr opcUaGuidSPtr = constructSPtr<OpcUaGuid>();
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

BOOST_AUTO_TEST_CASE(OpcUaNodeId_type_OpcUaGuid_SPtr_ptree)
{
	std::string str;
	boost::property_tree::ptree pt;
	OpcUaNodeId value1, value2;
	Xmlns xmlns;

	OpcUaGuid::SPtr opcUaGuidSPtr = constructSPtr<OpcUaGuid>();
	*opcUaGuidSPtr = "12345678-9ABC-DEF0-1234-56789ABCDEF0";

	value1.namespaceIndex(123);
	value1.nodeId(opcUaGuidSPtr);

	value1.xmlEncode(pt, xmlns);
	value2.xmlDecode(pt, xmlns);

	str = *value2.nodeId<OpcUaGuid::SPtr>();
	BOOST_REQUIRE(value2.nodeIdType() == OpcUaBuildInType_OpcUaGuid);
	BOOST_REQUIRE(value2.namespaceIndex() == 123);
	BOOST_REQUIRE(str == "12345678-9ABC-DEF0-1234-56789ABCDEF0");
}

BOOST_AUTO_TEST_CASE(OpcUaNodeId_type_OpcUaByteString_SPtr)
{
	std::stringstream ss;
	OpcUaNodeId value1, value2;
	
	OpcUaByteString::SPtr opcUaByteStringSPtr = constructSPtr<OpcUaByteString>();
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

	opcUaString1 = constructSPtr<OpcUaString>();
	opcUaString1->value("ABC");

	opcUaNodeId1.namespaceIndex(4711);
	opcUaNodeId1.nodeId(opcUaString1);

	opcUaNodeId1.copyTo(opcUaNodeId2);

	BOOST_REQUIRE(opcUaNodeId2.namespaceIndex() == 4711);
	opcUaString2 = opcUaNodeId2.nodeId<OpcUaString::SPtr>(); 
	std::string nodeId = opcUaString2->value();
	BOOST_REQUIRE(nodeId == "ABC");

	opcUaString1->value("DEF");

	BOOST_REQUIRE(opcUaNodeId1.namespaceIndex() == 4711);
	opcUaString1 = opcUaNodeId1.nodeId<OpcUaString::SPtr>(); 
	nodeId = opcUaString1->value();
	BOOST_REQUIRE(nodeId == "DEF");
	BOOST_REQUIRE(opcUaNodeId2.namespaceIndex() == 4711);
	opcUaString2 = opcUaNodeId2.nodeId<OpcUaString::SPtr>(); 
	nodeId = opcUaString2->value();
	BOOST_REQUIRE(nodeId == "ABC");
}

BOOST_AUTO_TEST_CASE(OpcUaNodeId_map_OpcUaUInt32)
{
	typedef std::map<OpcUaNodeId, uint32_t> OpcUaNodeIdMap;
	OpcUaNodeIdMap opcUaNodeIdMap;
	OpcUaNodeIdMap::iterator it;
	OpcUaByte* buf;
	OpcUaInt32 bufLen;

	OpcUaNodeId opcUaNodeId1, opcUaNodeId2;
	OpcUaString::SPtr opcUaString1, opcUaString2;
	OpcUaByteString::SPtr opcUaByteString1, opcUaByteString2;
	OpcUaGuid::SPtr opcUaGuid1, opcUaGuid2;

	// insert: OpcUaUInt32
	opcUaNodeId1.namespaceIndex(4711);
	opcUaNodeId1.nodeId(4712);
	opcUaNodeIdMap.insert(std::make_pair(opcUaNodeId1, 34567));
	
	// insert: opcUaString
	opcUaString1 = constructSPtr<OpcUaString>();
	opcUaString1->value("ABC");
	opcUaNodeId1.namespaceIndex(4712);
	opcUaNodeId1.nodeId(opcUaString1);
	opcUaNodeIdMap.insert(std::make_pair(opcUaNodeId1, 45678));

	// insert: opcUaByteString
	opcUaByteString1 = constructSPtr<OpcUaByteString>();
	opcUaByteString1->value("0123456789", 10);
	opcUaNodeId1.namespaceIndex(4713);
	opcUaNodeId1.nodeId(opcUaByteString1);
	opcUaNodeIdMap.insert(std::make_pair(opcUaNodeId1, 5678));

	// insert: opcUaGuid
	opcUaGuid1 = constructSPtr<OpcUaGuid>();
	*opcUaGuid1 = "12345678-9ABC-DEF0-1234-56789ABCDEF0";
	opcUaNodeId1.namespaceIndex(4714);
	opcUaNodeId1.nodeId(opcUaGuid1);
	opcUaNodeIdMap.insert(std::make_pair(opcUaNodeId1, 678));


	// find: OpcUaUInt32
	opcUaNodeId2.namespaceIndex(4711);
	opcUaNodeId2.nodeId(4712);
	it = opcUaNodeIdMap.find(opcUaNodeId2);
	BOOST_REQUIRE(it != opcUaNodeIdMap.end());
	BOOST_REQUIRE(it->first.namespaceIndex() == 4711);
	BOOST_REQUIRE(it->first.nodeId<OpcUaUInt32>() == 4712);
	BOOST_REQUIRE(it->second == 34567);

	// find: opcUaString
	opcUaString2 = constructSPtr<OpcUaString>();
	opcUaString2->value("ABC");
	opcUaNodeId2.namespaceIndex(4712);
	opcUaNodeId2.nodeId(opcUaString1);
	it = opcUaNodeIdMap.find(opcUaNodeId2);
	BOOST_REQUIRE(it != opcUaNodeIdMap.end());
	BOOST_REQUIRE(it->first.namespaceIndex() == 4712);
	BOOST_REQUIRE(it->first.nodeId<OpcUaString::SPtr>()->value() == "ABC");
	BOOST_REQUIRE(it->second == 45678);

	// find: opcUaByteString
	opcUaByteString2 = constructSPtr<OpcUaByteString>();
	opcUaByteString2->value("0123456789", 10);
	opcUaNodeId2.namespaceIndex(4713);
	opcUaNodeId2.nodeId(opcUaByteString2);
	it = opcUaNodeIdMap.find(opcUaNodeId2);
	opcUaByteString2 = it->first.nodeId<OpcUaByteString::SPtr>();
	opcUaByteString2->value(&buf, &bufLen);
	BOOST_REQUIRE(it != opcUaNodeIdMap.end());
	BOOST_REQUIRE(bufLen == 10);
	BOOST_REQUIRE(strncmp((char*)buf, "0123456789", 10) == 0);
	BOOST_REQUIRE(it->second == 5678);

	// find: opcUaGuid
	opcUaGuid2 = constructSPtr<OpcUaGuid>();
	*opcUaGuid2 = "12345678-9ABC-DEF0-1234-56789ABCDEF0";
	opcUaNodeId2.namespaceIndex(4714);
	opcUaNodeId2.nodeId(opcUaGuid2);
	it = opcUaNodeIdMap.find(opcUaNodeId2);
	opcUaGuid2 = it->first.nodeId<OpcUaGuid::SPtr>();
	BOOST_REQUIRE(it != opcUaNodeIdMap.end());
	std::string str = *opcUaGuid2;
	BOOST_REQUIRE(str == "12345678-9ABC-DEF0-1234-56789ABCDEF0");
	BOOST_REQUIRE(it->second == 678);
}

BOOST_AUTO_TEST_CASE(OpcUaNodeId_access_helper)
{
	OpcUaNodeId opcUaNodeId;

	OpcUaUInt16 namespaceIndex;
	OpcUaUInt32 nodeId1;
	std::string nodeId2;
	OpcUaByte* buf;
	OpcUaInt32 bufLen;

	opcUaNodeId.set(4711);
	BOOST_REQUIRE(opcUaNodeId.nodeIdType() == OpcUaBuildInType_OpcUaUInt32);
	BOOST_REQUIRE(opcUaNodeId.get(nodeId1, namespaceIndex) == true);
	BOOST_REQUIRE(namespaceIndex == 0);
	BOOST_REQUIRE(nodeId1 == 4711);

	opcUaNodeId.set("string");
	BOOST_REQUIRE(opcUaNodeId.nodeIdType() == OpcUaBuildInType_OpcUaString);
	BOOST_REQUIRE(opcUaNodeId.get(nodeId2, namespaceIndex) == true);
	BOOST_REQUIRE(namespaceIndex == 0);
	BOOST_REQUIRE(nodeId2 == "string");

	opcUaNodeId.set("12345678-9ABC-DEF0-1234-56789ABCDEF0");
	BOOST_REQUIRE(opcUaNodeId.nodeIdType() == OpcUaBuildInType_OpcUaGuid);
	BOOST_REQUIRE(opcUaNodeId.get(nodeId2, namespaceIndex) == true);
	BOOST_REQUIRE(namespaceIndex == 0);
	BOOST_REQUIRE(nodeId2 == "12345678-9ABC-DEF0-1234-56789ABCDEF0");

	opcUaNodeId.set((OpcUaByte*)"0123456789", 10);
	BOOST_REQUIRE(opcUaNodeId.nodeIdType() == OpcUaBuildInType_OpcUaByteString);
	BOOST_REQUIRE(namespaceIndex == 0);
	BOOST_REQUIRE(opcUaNodeId.get(&buf, &bufLen, namespaceIndex) == true);
	BOOST_REQUIRE(bufLen == 10);
	BOOST_REQUIRE(strncmp((char*)buf, "0123456789", 10) == 0);
}

BOOST_AUTO_TEST_SUITE_END()
