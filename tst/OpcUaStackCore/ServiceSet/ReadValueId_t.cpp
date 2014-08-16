#include "unittest.h"
#include "OpcUaStackCore/ServiceSet/ReadValueId.h"
#include "OpcUaStackCore/Base/Utility.h"
#include <boost/iostreams/stream.hpp>

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(ReadValueId_)

BOOST_AUTO_TEST_CASE(ReadValueId_)
{
	std::cout << "ReadValueId_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(ReadValueId_encode_decode)
{
	std::stringstream ss;
	
	ReadValueId value1, value2;

	value1.nodeId((OpcUaInt16) 2, (OpcUaInt32) 9);
	value1.attributeId((OpcUaInt32) 13);
	value1.indexRange("TestString");
	value1.dataEncoding((OpcUaInt16) 1, "ABCD");

	value1.opcUaBinaryEncode(ss);
	value2.opcUaBinaryDecode(ss);

	BOOST_REQUIRE(value2.nodeId()->namespaceIndex() == 2);
	BOOST_REQUIRE(value2.nodeId()->nodeId<OpcUaUInt32>() == 9);
	BOOST_REQUIRE(value2.attributeId() == 13);
	BOOST_REQUIRE(value2.indexRange() == "TestString");
	BOOST_REQUIRE(value2.dataEncoding().namespaceIndex() == 1);
	BOOST_REQUIRE(value2.dataEncoding().name().value() == "ABCD");
}

BOOST_AUTO_TEST_SUITE_END()