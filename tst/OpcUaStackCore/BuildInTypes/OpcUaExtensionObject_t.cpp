#include "unittest.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaExtensionObject.h"
#include "OpcUaStackCore/Base/Utility.h"
#include <boost/iostreams/stream.hpp>

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(OpcUaExtensionObject_)

BOOST_AUTO_TEST_CASE(OpcUaExtensionObject_)
{
	std::cout << "OpcUaExtensionObject_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(OpcUaExtensionObject_body_no)
{
	std::string str;
	std::stringstream ss;
	OpcUaExtensionObject value1, value2;

	OpcUaString::SPtr opcUaStringSPtr = OpcUaString::construct();
	opcUaStringSPtr->value("Dies ist ein String");

	value1.typeId().namespaceIndex(123);
	value1.typeId().nodeId(opcUaStringSPtr);
	
	opcUaBinaryEncode(ss, value1);
	opcUaBinaryDecode(ss, value2);

	BOOST_REQUIRE(value2.typeId().namespaceIndex() == 123);
	BOOST_REQUIRE(value2.typeId().nodeId<OpcUaString::SPtr>()->value() == "Dies ist ein String");
	BOOST_REQUIRE(value2.body().exist() == false);
}

BOOST_AUTO_TEST_CASE(OpcUaExtensionObject_body_yes)
{
	std::string str;
	std::stringstream ss;
	OpcUaExtensionObject value1, value2;
	OpcUaByte buf1[5] = {0x01, 0x02, 0x03, 0x04, 0x05};
	OpcUaByte *buf2;
	OpcUaInt32 bufLen2;

	OpcUaString::SPtr opcUaStringSPtr = OpcUaString::construct();
	opcUaStringSPtr->value("Dies ist ein String");

	value1.typeId().namespaceIndex(123);
	value1.typeId().nodeId(opcUaStringSPtr);
	value1.body().value(buf1, 5);
	BOOST_REQUIRE(value1.body().exist() == true);
	
	opcUaBinaryEncode(ss, value1);
	opcUaBinaryDecode(ss, value2);

	value2.body().value(&buf2, &bufLen2);
	BOOST_REQUIRE(value2.typeId().namespaceIndex() == 123);
	BOOST_REQUIRE(value2.typeId().nodeId<OpcUaString::SPtr>()->value() == "Dies ist ein String");
	BOOST_REQUIRE(value2.body().exist() == true);
	BOOST_REQUIRE(bufLen2 == 5);
}

BOOST_AUTO_TEST_SUITE_END()