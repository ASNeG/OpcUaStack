#include "unittest.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaVariant.h"
#include "OpcUaStackCore/Base/Utility.h"
#include <boost/iostreams/stream.hpp>

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(OpcUaVariant_)

BOOST_AUTO_TEST_CASE(OpcUaVariant_)
{
	std::cout << "OpcUaVariant_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(OpcUaVariant_encode_decode)
{
	std::stringstream ss;
	OpcUaVariant value1, value2;
	
	opcUaBinaryEncode(ss, value1);
	opcUaBinaryDecode(ss, value2);

	BOOST_REQUIRE(value2.variantType() == OpcUaBuildInType_Unknown);
}

BOOST_AUTO_TEST_CASE(OpcUaVariant_OpcUaBoolean)
{
	std::stringstream ss;
	OpcUaVariant value1, value2;

	value1.variant((OpcUaBoolean)true);
	
	opcUaBinaryEncode(ss, value1);
	opcUaBinaryDecode(ss, value2);

	BOOST_REQUIRE(value2.variantType() == OpcUaBuildInType_OpcUaBoolean);
	BOOST_REQUIRE(value2.variant<OpcUaBoolean>() == true);
}

BOOST_AUTO_TEST_CASE(OpcUaVariant_OpcUaSByte)
{
	std::stringstream ss;
	OpcUaVariant value1, value2;

	value1.variant((OpcUaSByte)0x12);
	
	opcUaBinaryEncode(ss, value1);
	opcUaBinaryDecode(ss, value2);

	BOOST_REQUIRE(value2.variantType() == OpcUaBuildInType_OpcUaSByte);
	BOOST_REQUIRE(value2.variant<OpcUaSByte>() == 0x12);
}

BOOST_AUTO_TEST_CASE(OpcUaVariant_OpcUaByte)
{
	std::stringstream ss;
	OpcUaVariant value1, value2;

	value1.variant((OpcUaByte)0x12);
	
	opcUaBinaryEncode(ss, value1);
	opcUaBinaryDecode(ss, value2);

	BOOST_REQUIRE(value2.variantType() == OpcUaBuildInType_OpcUaByte);
	BOOST_REQUIRE(value2.variant<OpcUaByte>() == 0x12);
}

BOOST_AUTO_TEST_CASE(OpcUaVariant_OpcUaInt16)
{
	std::stringstream ss;
	OpcUaVariant value1, value2;

	value1.variant((OpcUaInt16)123);
	
	opcUaBinaryEncode(ss, value1);
	opcUaBinaryDecode(ss, value2);

	BOOST_REQUIRE(value2.variantType() == OpcUaBuildInType_OpcUaInt16);
	BOOST_REQUIRE(value2.variant<OpcUaInt16>() == 123);
}

BOOST_AUTO_TEST_CASE(OpcUaVariant_OpcUaUInt16)
{
	std::stringstream ss;
	OpcUaVariant value1, value2;

	value1.variant((OpcUaUInt16)0x123);
	
	opcUaBinaryEncode(ss, value1);
	opcUaBinaryDecode(ss, value2);

	BOOST_REQUIRE(value2.variantType() == OpcUaBuildInType_OpcUaUInt16);
	BOOST_REQUIRE(value2.variant<OpcUaUInt16>() == 0x123);
}

BOOST_AUTO_TEST_CASE(OpcUaVariant_OpcUaInt32)
{
	std::stringstream ss;
	OpcUaVariant value1, value2;

	value1.variant((OpcUaInt32)0x1234);
	
	opcUaBinaryEncode(ss, value1);
	opcUaBinaryDecode(ss, value2);

	BOOST_REQUIRE(value2.variantType() == OpcUaBuildInType_OpcUaInt32);
	BOOST_REQUIRE(value2.variant<OpcUaInt32>() == 0x1234);
}

BOOST_AUTO_TEST_CASE(OpcUaVariant_OpcUaUInt32)
{
	std::stringstream ss;
	OpcUaVariant value1, value2;

	value1.variant((OpcUaUInt32)0x1234);
	
	opcUaBinaryEncode(ss, value1);
	opcUaBinaryDecode(ss, value2);

	BOOST_REQUIRE(value2.variantType() == OpcUaBuildInType_OpcUaUInt32);
	BOOST_REQUIRE(value2.variant<OpcUaUInt32>() == 0x1234);
}

BOOST_AUTO_TEST_CASE(OpcUaVariant_OpcUaInt64)
{
	std::stringstream ss;
	OpcUaVariant value1, value2;

	value1.variant((OpcUaInt64)0x123456);
	
	opcUaBinaryEncode(ss, value1);
	opcUaBinaryDecode(ss, value2);

	BOOST_REQUIRE(value2.variantType() == OpcUaBuildInType_OpcUaInt64);
	BOOST_REQUIRE(value2.variant<OpcUaInt64>() == 0x123456);
}

BOOST_AUTO_TEST_CASE(OpcUaVariant_OpcUaUInt64)
{
	std::stringstream ss;
	OpcUaVariant value1, value2;

	value1.variant((OpcUaUInt64)0x123456);
	
	opcUaBinaryEncode(ss, value1);
	opcUaBinaryDecode(ss, value2);

	BOOST_REQUIRE(value2.variantType() == OpcUaBuildInType_OpcUaUInt64);
	BOOST_REQUIRE(value2.variant<OpcUaUInt64>() == 0x123456);
}

BOOST_AUTO_TEST_CASE(OpcUaVariant_OpcUaFloat)
{
	std::stringstream ss;
	OpcUaVariant value1, value2;

	value1.variant((OpcUaFloat)123);
	
	opcUaBinaryEncode(ss, value1);
	opcUaBinaryDecode(ss, value2);

	BOOST_REQUIRE(value2.variantType() == OpcUaBuildInType_OpcUaFloat);
	BOOST_REQUIRE(value2.variant<OpcUaFloat>() == 123);
}

BOOST_AUTO_TEST_CASE(OpcUaVariant_OpcUaDouble)
{
	std::stringstream ss;
	OpcUaVariant value1, value2;

	value1.variant((OpcUaDouble)123);
	
	opcUaBinaryEncode(ss, value1);
	opcUaBinaryDecode(ss, value2);

	BOOST_REQUIRE(value2.variantType() == OpcUaBuildInType_OpcUaDouble);
	BOOST_REQUIRE(value2.variant<OpcUaDouble>() == 123);
}

BOOST_AUTO_TEST_CASE(OpcUaVariant_OpcUaDateTime)
{
	boost::posix_time::ptime ptime1 = boost::posix_time::from_iso_string("16010101T120000.000000000");
	boost::posix_time::ptime ptime2; 
	std::stringstream ss;
	OpcUaVariant value1, value2;
	OpcUaDateTime dateTime1, dateTime2;

	dateTime1.dateTime(ptime1);
	value1.variant(dateTime1);
	
	opcUaBinaryEncode(ss, value1);
	opcUaBinaryDecode(ss, value2);

	dateTime2 = value1.variant<OpcUaDateTime>();
	ptime2 = dateTime2.dateTime();
	BOOST_REQUIRE(value2.variantType() == OpcUaBuildInType_OpcUaDateTime);
	BOOST_REQUIRE(boost::posix_time::to_iso_string(ptime2) == "16010101T120000");
}

BOOST_AUTO_TEST_CASE(OpcUaVariant_OpcUaStatusCode)
{
	std::stringstream ss;
	OpcUaVariant value1, value2;
 
	value1.variant((OpcUaStatusCode)123);
	
	opcUaBinaryEncode(ss, value1);
	opcUaBinaryDecode(ss, value2);

	BOOST_REQUIRE(value2.variantType() == OpcUaBuildInType_OpcUaStatusCode);
	BOOST_REQUIRE(value2.variant<OpcUaStatusCode>() == (OpcUaStatusCode)123);
}

BOOST_AUTO_TEST_CASE(OpcUaVariant_OpcUaGuid)
{
	std::stringstream ss;
	OpcUaVariant value1, value2;
	OpcUaGuid::SPtr guidSPtr = OpcUaGuid::construct();

	*guidSPtr = "12345678-9ABC-DEF0-1234-56789ABCDEF0";
	value1.variant(guidSPtr);
	
	opcUaBinaryEncode(ss, value1);
	opcUaBinaryDecode(ss, value2);

	BOOST_REQUIRE(value2.variantType() == OpcUaBuildInType_OpcUaGuid);
	std::string  str = *(value2.variantSPtr<OpcUaGuid>());
	BOOST_REQUIRE(str == "12345678-9ABC-DEF0-1234-56789ABCDEF0");
}

BOOST_AUTO_TEST_CASE(OpcUaVariant_OpcUaXmlElement)
{
	std::stringstream ss;
	OpcUaVariant value1, value2;
	OpcUaXmlElement::SPtr xmlElementSPtr = OpcUaXmlElement::construct();

	value1.variant(xmlElementSPtr);
	
	opcUaBinaryEncode(ss, value1);
	opcUaBinaryDecode(ss, value2);

	BOOST_REQUIRE(value2.variantType() == OpcUaBuildInType_OpcUaXmlElement);
}

BOOST_AUTO_TEST_CASE(OpcUaVariant_OpcUaNodeId)
{
	std::stringstream ss;
	OpcUaVariant value1, value2;
	OpcUaNodeId::SPtr nodeIdSPtr = OpcUaNodeId::construct();

	OpcUaString::SPtr opcUaStringSPtr = OpcUaString::construct();
	opcUaStringSPtr->value("ABC");

	nodeIdSPtr->namespaceIndex(123);
	nodeIdSPtr->nodeId(opcUaStringSPtr);
	value1.variant(nodeIdSPtr);
	
	opcUaBinaryEncode(ss, value1);
	opcUaBinaryDecode(ss, value2);

	BOOST_REQUIRE(value2.variantType() == OpcUaBuildInType_OpcUaNodeId);
	BOOST_REQUIRE(value2.variantSPtr<OpcUaNodeId>()->namespaceIndex() == 123);
	BOOST_REQUIRE(value2.variantSPtr<OpcUaNodeId>()->nodeId<OpcUaString::SPtr>()->value() == "ABC");
}

BOOST_AUTO_TEST_CASE(OpcUaVariant_OpcUaExpandedNodeId)
{
	std::stringstream ss;
	OpcUaVariant value1, value2;
	OpcUaExpandedNodeId::SPtr nodeIdSPtr = OpcUaExpandedNodeId::construct();

	OpcUaString::SPtr opcUaStringSPtr = OpcUaString::construct();
	opcUaStringSPtr->value("ABC");

	nodeIdSPtr->namespaceIndex(123);
	nodeIdSPtr->nodeId(opcUaStringSPtr);
	value1.variant(nodeIdSPtr);
	
	opcUaBinaryEncode(ss, value1);
	opcUaBinaryDecode(ss, value2);

	BOOST_REQUIRE(value2.variantType() == OpcUaBuildInType_OpcUaExpandedNodeId);
	BOOST_REQUIRE(value2.variantSPtr<OpcUaExpandedNodeId>()->namespaceIndex() == 123);
	BOOST_REQUIRE(value2.variantSPtr<OpcUaExpandedNodeId>()->nodeId<OpcUaString::SPtr>()->value() == "ABC");
}

BOOST_AUTO_TEST_CASE(OpcUaVariant_OpcUaQualifiedName)
{
	std::stringstream ss;
	OpcUaVariant value1, value2;
	OpcUaQualifiedName::SPtr qualifiedNameSPtr = OpcUaQualifiedName::construct();

	OpcUaString name;
	name = "ABC";

	qualifiedNameSPtr->namespaceIndex(1);
	qualifiedNameSPtr->name(name);
	value1.variant(qualifiedNameSPtr);
	
	opcUaBinaryEncode(ss, value1);
	opcUaBinaryDecode(ss, value2);

	BOOST_REQUIRE(value2.variantType() == OpcUaBuildInType_OpcUaQualifiedName);
	BOOST_REQUIRE(value2.variantSPtr<OpcUaQualifiedName>()->namespaceIndex() == 1);
	BOOST_REQUIRE(value2.variantSPtr<OpcUaQualifiedName>()->name().value() == "ABC");
}

BOOST_AUTO_TEST_CASE(OpcUaVariant_OpcUaLocalizedText)
{
	std::stringstream ss;
	OpcUaVariant value1, value2;
	OpcUaLocalizedText::SPtr localizedTextPtr = OpcUaLocalizedText::construct();

	OpcUaString locale;
	OpcUaString text;
	locale = "de";
	text = "text";

	localizedTextPtr->locale(locale);
	localizedTextPtr->text(text);
	value1.variant(localizedTextPtr);
	
	opcUaBinaryEncode(ss, value1);
	opcUaBinaryDecode(ss, value2);

	BOOST_REQUIRE(value2.variantType() == OpcUaBuildInType_OpcUaLocalizedText);
	BOOST_REQUIRE(value2.variantSPtr<OpcUaLocalizedText>()->locale().value() == "de");
	BOOST_REQUIRE(value2.variantSPtr<OpcUaLocalizedText>()->text().value() == "text");
}

BOOST_AUTO_TEST_CASE(OpcUaVariant_OpcUaExtensionObject)
{
	std::stringstream ss;
	OpcUaVariant value1, value2;
	OpcUaExtensionObject::SPtr extensionObjectSPtr = OpcUaExtensionObject::construct();

	value1.variant(extensionObjectSPtr);
	
	opcUaBinaryEncode(ss, value1);
	opcUaBinaryDecode(ss, value2);

	BOOST_REQUIRE(value2.variantType() == OpcUaBuildInType_OpcUaExtensionObject);
}

BOOST_AUTO_TEST_SUITE_END()