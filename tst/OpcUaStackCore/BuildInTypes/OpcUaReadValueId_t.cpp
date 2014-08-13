#include "unittest.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaReadValueId.h"
#include "OpcUaStackCore/Base/Utility.h"
#include <boost/iostreams/stream.hpp>

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(OpcUaReadValueId_)

BOOST_AUTO_TEST_CASE(OpcUaReadValueId_)
{
	std::cout << "OpcUaReadValueId_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(OpcUaReadValueId_encode_decode)
{
	std::stringstream ss;
	
	OpcUaReadValueId value1, value2;

	value1.nodeId((OpcUaInt16) 2, (OpcUaInt32) 9);
	value1.attributeId((OpcUaInt32) 13);
	value1.indexRange("TestString");
	value1.dataEncoding((OpcUaInt16) 1, "ABCD");

	value1.opcUaBinaryEncode(ss);
	value2.opcUaBinaryDecode(ss);
	
	BOOST_REQUIRE(value2.nodeId().namespaceIndex() == 2);
	BOOST_REQUIRE(value2.nodeId().nodeId<OpcUaUInt32>() == 9);
	BOOST_REQUIRE(value2.attributeId() == 13);
	BOOST_REQUIRE(value2.indexRange().value() == "TestString");
	BOOST_REQUIRE(value2.dataEncoding().namespaceIndex() == 1);
	BOOST_REQUIRE(value2.dataEncoding().name().value() == "ABCD");
}

BOOST_AUTO_TEST_SUITE_END()