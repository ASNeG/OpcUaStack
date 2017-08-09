#include "unittest.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaVariant.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackCore/Base/Utility.h"
#include "OpcUaStackCore/StandardDataTypes/StatusResult.h"
#include <boost/iostreams/stream.hpp>
#include <boost/property_tree/ptree.hpp>

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
	BOOST_REQUIRE(value1.variantType() == OpcUaBuildInType_Unknown);
	
	value1.opcUaBinaryEncode(ss);
	value2.opcUaBinaryDecode(ss);

	BOOST_REQUIRE(value2.arrayLength() == -1);
	BOOST_REQUIRE(value2.variantType() == OpcUaBuildInType_Unknown);
}

BOOST_AUTO_TEST_CASE(OpcUaVariant_isNull)
{
	std::stringstream ss;
	OpcUaVariant value1, value2;
	BOOST_REQUIRE(value1.variantType() == OpcUaBuildInType_Unknown);
	BOOST_REQUIRE(value1.isNull() == true);

	value1.opcUaBinaryEncode(ss);
	value2.opcUaBinaryDecode(ss);

	BOOST_REQUIRE(value2.arrayLength() == -1);
	BOOST_REQUIRE(value2.variantType() == OpcUaBuildInType_Unknown);
	BOOST_REQUIRE(value2.isNull() == true);
}

BOOST_AUTO_TEST_CASE(OpcUaVariant_OpcUaBoolean)
{
	std::stringstream ss;
	OpcUaVariant value1, value2;

	value1.variant((OpcUaBoolean)true);
	
	value1.opcUaBinaryEncode(ss);
	value2.opcUaBinaryDecode(ss);

	BOOST_REQUIRE(value2.arrayLength() == -1);
	BOOST_REQUIRE(value2.variantType() == OpcUaBuildInType_OpcUaBoolean);
	BOOST_REQUIRE(value2.variant<OpcUaBoolean>() == true);
}

BOOST_AUTO_TEST_CASE(OpcUaVariant_OpcUaBoolean_ptree)
{
	boost::property_tree::ptree pt;
	OpcUaVariant value1, value2;

	value1.variant((OpcUaBoolean)true);

	value1.encode(pt);
	value2.decode(pt, OpcUaBuildInType_OpcUaBoolean, false);

	BOOST_REQUIRE(value2.arrayLength() == -1);
	BOOST_REQUIRE(value2.variantType() == OpcUaBuildInType_OpcUaBoolean);
	BOOST_REQUIRE(value2.variant<OpcUaBoolean>() == true);
}

BOOST_AUTO_TEST_CASE(OpcUaVariant_OpcUaBoolean_copyTo)
{
	std::stringstream ss;
	OpcUaVariant value1, value2;

	value1.variant((OpcUaBoolean)true);
	
	value1.copyTo(value2);

	BOOST_REQUIRE(value1.arrayLength() == -1);
	BOOST_REQUIRE(value1.variantType() == OpcUaBuildInType_OpcUaBoolean);
	BOOST_REQUIRE(value1.variant<OpcUaBoolean>() == true);

	BOOST_REQUIRE(value2.arrayLength() == -1);
	BOOST_REQUIRE(value2.variantType() == OpcUaBuildInType_OpcUaBoolean);
	BOOST_REQUIRE(value2.variant<OpcUaBoolean>() == true);

	value1.variant((OpcUaBoolean)false);

	BOOST_REQUIRE(value1.arrayLength() == -1);
	BOOST_REQUIRE(value1.variantType() == OpcUaBuildInType_OpcUaBoolean);
	BOOST_REQUIRE(value1.variant<OpcUaBoolean>() == false);

	BOOST_REQUIRE(value2.arrayLength() == -1);
	BOOST_REQUIRE(value2.variantType() == OpcUaBuildInType_OpcUaBoolean);
	BOOST_REQUIRE(value2.variant<OpcUaBoolean>() == true);
}

BOOST_AUTO_TEST_CASE(OpcUaVariant_OpcUaSByte)
{
	std::stringstream ss;
	OpcUaVariant value1, value2;

	value1.variant((OpcUaSByte)0x12);
	
	value1.opcUaBinaryEncode(ss);
	value2.opcUaBinaryDecode(ss);

	BOOST_REQUIRE(value2.arrayLength() == -1);
	BOOST_REQUIRE(value2.variantType() == OpcUaBuildInType_OpcUaSByte);
	BOOST_REQUIRE(value2.variant<OpcUaSByte>() == 0x12);
}

BOOST_AUTO_TEST_CASE(OpcUaVariant_OpcUaSByte_ptree)
{
	boost::property_tree::ptree pt;
	OpcUaVariant value1, value2;

	value1.variant((OpcUaSByte)0x12);

	value1.encode(pt);
	value2.decode(pt, OpcUaBuildInType_OpcUaSByte, false);

	BOOST_REQUIRE(value2.arrayLength() == -1);
	BOOST_REQUIRE(value2.variantType() == OpcUaBuildInType_OpcUaSByte);
	BOOST_REQUIRE(value2.variant<OpcUaSByte>() == 0x12);
}

BOOST_AUTO_TEST_CASE(OpcUaVariant_OpcUaByte)
{
	std::stringstream ss;
	OpcUaVariant value1, value2;

	value1.variant((OpcUaByte)0x12);
	
	value1.opcUaBinaryEncode(ss);
	value2.opcUaBinaryDecode(ss);

	BOOST_REQUIRE(value2.arrayLength() == -1);
	BOOST_REQUIRE(value2.variantType() == OpcUaBuildInType_OpcUaByte);
	BOOST_REQUIRE(value2.variant<OpcUaByte>() == 0x12);
}

BOOST_AUTO_TEST_CASE(OpcUaVariant_OpcUaInt16)
{
	std::stringstream ss;
	OpcUaVariant value1, value2;

	value1.variant((OpcUaInt16)123);
	
	value1.opcUaBinaryEncode(ss);
	value2.opcUaBinaryDecode(ss);

	BOOST_REQUIRE(value2.arrayLength() == -1);
	BOOST_REQUIRE(value2.variantType() == OpcUaBuildInType_OpcUaInt16);
	BOOST_REQUIRE(value2.variant<OpcUaInt16>() == 123);
}

BOOST_AUTO_TEST_CASE(OpcUaVariant_OpcUaUInt16)
{
	std::stringstream ss;
	OpcUaVariant value1, value2;

	value1.variant((OpcUaUInt16)0x123);
	
	value1.opcUaBinaryEncode(ss);
	value2.opcUaBinaryDecode(ss);

	BOOST_REQUIRE(value2.arrayLength() == -1);
	BOOST_REQUIRE(value2.variantType() == OpcUaBuildInType_OpcUaUInt16);
	BOOST_REQUIRE(value2.variant<OpcUaUInt16>() == 0x123);
}

BOOST_AUTO_TEST_CASE(OpcUaVariant_OpcUaInt32)
{
	std::stringstream ss;
	OpcUaVariant value1, value2;

	value1.variant((OpcUaInt32)0x1234);
	
	value1.opcUaBinaryEncode(ss);
	value2.opcUaBinaryDecode(ss);

	BOOST_REQUIRE(value2.arrayLength() == -1);
	BOOST_REQUIRE(value2.variantType() == OpcUaBuildInType_OpcUaInt32);
	BOOST_REQUIRE(value2.variant<OpcUaInt32>() == 0x1234);
}

BOOST_AUTO_TEST_CASE(OpcUaVariant_OpcUaUInt32)
{
	std::stringstream ss;
	OpcUaVariant value1, value2;

	value1.variant((OpcUaUInt32)0x1234);
	
	value1.opcUaBinaryEncode(ss);
	value2.opcUaBinaryDecode(ss);

	BOOST_REQUIRE(value2.arrayLength() == -1);
	BOOST_REQUIRE(value2.variantType() == OpcUaBuildInType_OpcUaUInt32);
	BOOST_REQUIRE(value2.variant<OpcUaUInt32>() == 0x1234);
}

BOOST_AUTO_TEST_CASE(OpcUaVariant_OpcUaInt64)
{
	std::stringstream ss;
	OpcUaVariant value1, value2;

	value1.variant((OpcUaInt64)0x123456);
	
	value1.opcUaBinaryEncode(ss);
	value2.opcUaBinaryDecode(ss);

	BOOST_REQUIRE(value2.arrayLength() == -1);
	BOOST_REQUIRE(value2.variantType() == OpcUaBuildInType_OpcUaInt64);
	BOOST_REQUIRE(value2.variant<OpcUaInt64>() == 0x123456);
}

BOOST_AUTO_TEST_CASE(OpcUaVariant_OpcUaUInt64)
{
	std::stringstream ss;
	OpcUaVariant value1, value2;

	value1.variant((OpcUaUInt64)0x123456);
	
	value1.opcUaBinaryEncode(ss);
	value2.opcUaBinaryDecode(ss);

	BOOST_REQUIRE(value2.arrayLength() == -1);
	BOOST_REQUIRE(value2.variantType() == OpcUaBuildInType_OpcUaUInt64);
	BOOST_REQUIRE(value2.variant<OpcUaUInt64>() == 0x123456);
}

BOOST_AUTO_TEST_CASE(OpcUaVariant_OpcUaFloat)
{
	std::stringstream ss;
	OpcUaVariant value1, value2;

	value1.variant((OpcUaFloat)123);
	
	value1.opcUaBinaryEncode(ss);
	value2.opcUaBinaryDecode(ss);

	BOOST_REQUIRE(value2.arrayLength() == -1);
	BOOST_REQUIRE(value2.variantType() == OpcUaBuildInType_OpcUaFloat);
	BOOST_REQUIRE(value2.variant<OpcUaFloat>() == 123);
}

BOOST_AUTO_TEST_CASE(OpcUaVariant_OpcUaDouble)
{
	std::stringstream ss;
	OpcUaVariant value1, value2;

	value1.variant((OpcUaDouble)123);
	
	value1.opcUaBinaryEncode(ss);
	value2.opcUaBinaryDecode(ss);

	BOOST_REQUIRE(value2.arrayLength() == -1);
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
	
	value1.opcUaBinaryEncode(ss);
	value2.opcUaBinaryDecode(ss);

	dateTime2 = value1.variant<OpcUaDateTime>();
	ptime2 = dateTime2.dateTime();

	BOOST_REQUIRE(value2.arrayLength() == -1);
	BOOST_REQUIRE(value2.variantType() == OpcUaBuildInType_OpcUaDateTime);
	BOOST_REQUIRE(boost::posix_time::to_iso_string(ptime2) == "16010101T120000");
}

BOOST_AUTO_TEST_CASE(OpcUaVariant_OpcUaStatusCode)
{
	std::stringstream ss;
	OpcUaVariant value1, value2;
 
	value1.variant((OpcUaStatusCode)123);
	
	value1.opcUaBinaryEncode(ss);
	value2.opcUaBinaryDecode(ss);

	BOOST_REQUIRE(value2.arrayLength() == -1);
	BOOST_REQUIRE(value2.variantType() == OpcUaBuildInType_OpcUaStatusCode);
	BOOST_REQUIRE(value2.variant<OpcUaStatusCode>() == (OpcUaStatusCode)123);
}

BOOST_AUTO_TEST_CASE(OpcUaVariant_OpcUaGuid)
{
	std::stringstream ss;
	OpcUaVariant value1, value2;
	OpcUaGuid::SPtr guidSPtr = constructSPtr<OpcUaGuid>();

	*guidSPtr = "12345678-9ABC-DEF0-1234-56789ABCDEF0";
	value1.variant(guidSPtr);
	
	value1.opcUaBinaryEncode(ss);
	value2.opcUaBinaryDecode(ss);

	BOOST_REQUIRE(value2.arrayLength() == -1);
	BOOST_REQUIRE(value2.variantType() == OpcUaBuildInType_OpcUaGuid);
	std::string  str = *(value2.variantSPtr<OpcUaGuid>());
	BOOST_REQUIRE(str == "12345678-9ABC-DEF0-1234-56789ABCDEF0");
}

BOOST_AUTO_TEST_CASE(OpcUaVariant_OpcUaXmlElement)
{
	std::stringstream ss;
	OpcUaVariant value1, value2;
	OpcUaXmlElement::SPtr xmlElementSPtr = constructSPtr<OpcUaXmlElement>();

	value1.variant(xmlElementSPtr);
	
	value1.opcUaBinaryEncode(ss);
	value2.opcUaBinaryDecode(ss);

	BOOST_REQUIRE(value2.arrayLength() == -1);
	BOOST_REQUIRE(value2.variantType() == OpcUaBuildInType_OpcUaXmlElement);
}

BOOST_AUTO_TEST_CASE(OpcUaVariant_OpcUaNodeId)
{
	std::stringstream ss;
	OpcUaVariant value1, value2;
	OpcUaNodeId::SPtr nodeIdSPtr = constructSPtr<OpcUaNodeId>();

	OpcUaString::SPtr opcUaStringSPtr = constructSPtr<OpcUaString>();
	opcUaStringSPtr->value("ABC");

	nodeIdSPtr->namespaceIndex(123);
	nodeIdSPtr->nodeId(opcUaStringSPtr);
	value1.variant(nodeIdSPtr);
	
	value1.opcUaBinaryEncode(ss);
	value2.opcUaBinaryDecode(ss);

	BOOST_REQUIRE(value2.arrayLength() == -1);
	BOOST_REQUIRE(value2.variantType() == OpcUaBuildInType_OpcUaNodeId);
	BOOST_REQUIRE(value2.variantSPtr<OpcUaNodeId>()->namespaceIndex() == 123);
	BOOST_REQUIRE(value2.variantSPtr<OpcUaNodeId>()->nodeId<OpcUaString::SPtr>()->value() == "ABC");
}

BOOST_AUTO_TEST_CASE(OpcUaVariant_OpcUaExpandedNodeId)
{
	std::stringstream ss;
	OpcUaVariant value1, value2;
	OpcUaExpandedNodeId::SPtr nodeIdSPtr = constructSPtr<OpcUaExpandedNodeId>();

	OpcUaString::SPtr opcUaStringSPtr = constructSPtr<OpcUaString>();
	opcUaStringSPtr->value("ABC");

	nodeIdSPtr->namespaceIndex(123);
	nodeIdSPtr->nodeId(opcUaStringSPtr);
	value1.variant(nodeIdSPtr);
	
	value1.opcUaBinaryEncode(ss);
	value2.opcUaBinaryDecode(ss);

	BOOST_REQUIRE(value2.arrayLength() == -1);
	BOOST_REQUIRE(value2.variantType() == OpcUaBuildInType_OpcUaExpandedNodeId);
	BOOST_REQUIRE(value2.variantSPtr<OpcUaExpandedNodeId>()->namespaceIndex() == 123);
	BOOST_REQUIRE(value2.variantSPtr<OpcUaExpandedNodeId>()->nodeId<OpcUaString::SPtr>()->value() == "ABC");
}

BOOST_AUTO_TEST_CASE(OpcUaVariant_OpcUaQualifiedName)
{
	std::stringstream ss;
	OpcUaVariant value1, value2;
	OpcUaQualifiedName::SPtr qualifiedNameSPtr = constructSPtr<OpcUaQualifiedName>();

	OpcUaString name;
	name = "ABC";

	qualifiedNameSPtr->namespaceIndex(1);
	qualifiedNameSPtr->name(name);
	value1.variant(qualifiedNameSPtr);
	
	value1.opcUaBinaryEncode(ss);
	value2.opcUaBinaryDecode(ss);

	BOOST_REQUIRE(value2.arrayLength() == -1);
	BOOST_REQUIRE(value2.variantType() == OpcUaBuildInType_OpcUaQualifiedName);
	BOOST_REQUIRE(value2.variantSPtr<OpcUaQualifiedName>()->namespaceIndex() == 1);
	BOOST_REQUIRE(value2.variantSPtr<OpcUaQualifiedName>()->name().value() == "ABC");
}

BOOST_AUTO_TEST_CASE(OpcUaVariant_OpcUaLocalizedText)
{
	std::stringstream ss;
	OpcUaVariant value1, value2;
	OpcUaLocalizedText::SPtr localizedTextPtr = constructSPtr<OpcUaLocalizedText>();

	OpcUaString locale;
	OpcUaString text;
	locale = "de";
	text = "text";

	localizedTextPtr->locale(locale);
	localizedTextPtr->text(text);
	value1.variant(localizedTextPtr);
	
	value1.opcUaBinaryEncode(ss);
	value2.opcUaBinaryDecode(ss);

	BOOST_REQUIRE(value2.arrayLength() == -1);
	BOOST_REQUIRE(value2.variantType() == OpcUaBuildInType_OpcUaLocalizedText);
	BOOST_REQUIRE(value2.variantSPtr<OpcUaLocalizedText>()->locale().value() == "de");
	BOOST_REQUIRE(value2.variantSPtr<OpcUaLocalizedText>()->text().value() == "text");
}

BOOST_AUTO_TEST_CASE(OpcUaVariant_OpcUaString)
{
	std::stringstream ss;
	OpcUaVariant value1, value2;
	OpcUaString::SPtr stringSPtr = constructSPtr<OpcUaString>();

	stringSPtr->value("text");
	value1.variant(stringSPtr);
	
	value1.opcUaBinaryEncode(ss);
	value2.opcUaBinaryDecode(ss);

	BOOST_REQUIRE(value2.arrayLength() == -1);
	BOOST_REQUIRE(value2.variantType() == OpcUaBuildInType_OpcUaString);
	BOOST_REQUIRE(value2.variantSPtr<OpcUaString>()->value() == "text");
}

BOOST_AUTO_TEST_CASE(OpcUaVariant_OpcUaString_copyTo)
{
	std::stringstream ss;
	OpcUaVariant value1, value2;
	OpcUaString::SPtr stringSPtr = constructSPtr<OpcUaString>();

	stringSPtr->value("text");
	value1.variant(stringSPtr);
	
	value1.copyTo(value2);

	BOOST_REQUIRE(value1.arrayLength() == -1);
	BOOST_REQUIRE(value1.variantType() == OpcUaBuildInType_OpcUaString);
	BOOST_REQUIRE(value1.variantSPtr<OpcUaString>()->value() == "text");
	BOOST_REQUIRE(value2.arrayLength() == -1);
	BOOST_REQUIRE(value2.variantType() == OpcUaBuildInType_OpcUaString);
	BOOST_REQUIRE(value2.variantSPtr<OpcUaString>()->value() == "text");

	value1.variantSPtr<OpcUaString>()->value("text1");

	BOOST_REQUIRE(value1.arrayLength() == -1);
	BOOST_REQUIRE(value1.variantType() == OpcUaBuildInType_OpcUaString);
	BOOST_REQUIRE(value1.variantSPtr<OpcUaString>()->value() == "text1");
	BOOST_REQUIRE(value2.arrayLength() == -1);
	BOOST_REQUIRE(value2.variantType() == OpcUaBuildInType_OpcUaString);
	BOOST_REQUIRE(value2.variantSPtr<OpcUaString>()->value() == "text");
}

BOOST_AUTO_TEST_CASE(OpcUaVariant_OpcUaByteString)
{
	std::stringstream ss;
	OpcUaVariant value1, value2;
	OpcUaByteString::SPtr byteStringSPtr = constructSPtr<OpcUaByteString>();

	byteStringSPtr->value("text", 4);
	value1.variant(byteStringSPtr);
	
	value1.opcUaBinaryEncode(ss);
	value2.opcUaBinaryDecode(ss);

	OpcUaByte *buf;
	OpcUaInt32 bufLen;
	value2.variantSPtr<OpcUaByteString>()->value(&buf, &bufLen);
	BOOST_REQUIRE(value2.arrayLength() == -1);
	BOOST_REQUIRE(value2.variantType() == OpcUaBuildInType_OpcUaByteString);
	BOOST_REQUIRE(strncmp((char*)buf, "text", 4) == 0);
}

BOOST_AUTO_TEST_CASE(OpcUaVariant_OpcUaExtensionObject)
{
	std::stringstream ss;
	OpcUaVariant value1, value2;
	OpcUaExtensionObject::SPtr extensionObjectSPtr = constructSPtr<OpcUaExtensionObject>();

	value1.variant(extensionObjectSPtr);
	
	value1.opcUaBinaryEncode(ss);
	value2.opcUaBinaryDecode(ss);

	BOOST_REQUIRE(value2.arrayLength() == -1);
	BOOST_REQUIRE(value2.variantType() == OpcUaBuildInType_OpcUaExtensionObject);
}

BOOST_AUTO_TEST_CASE(OpcUaVariant_array_0)
{
	std::stringstream ss;
	OpcUaVariant value1, value2;
	
	OpcUaVariantValue::Vec variantVec1, variantVec2;
	
	value1.variant(variantVec1);
	value1.opcUaBinaryEncode(ss); 
	value2.opcUaBinaryDecode(ss);
	variantVec2 = value2.variant();

	BOOST_REQUIRE(value2.arrayLength() == 0);
    BOOST_REQUIRE(variantVec2.size() == 0);
}

BOOST_AUTO_TEST_CASE(OpcUaVariant_array_0_ptree)
{
	boost::property_tree::ptree pt;
	OpcUaVariant value1, value2;

	OpcUaVariantValue::Vec variantVec1, variantVec2;

	value1.variant(variantVec1);
	value1.encode(pt);
	value2.decode(pt, OpcUaBuildInType_OpcUaExtensionObject, true);
	variantVec2 = value2.variant();

	BOOST_REQUIRE(value2.arrayLength() == 0);
    BOOST_REQUIRE(variantVec2.size() == 0);
}

BOOST_AUTO_TEST_CASE(OpcUaVariant_array_1)
{
	std::stringstream ss;
	OpcUaVariant value1, value2;
	
	OpcUaVariantValue::Vec variantVec1, variantVec2;
	
	OpcUaVariantValue variantValue;
	variantValue.variant((OpcUaUInt32)1);
	variantVec1.push_back(variantValue);

	value1.variant(variantVec1);
	value1.opcUaBinaryEncode(ss); 
	value2.opcUaBinaryDecode(ss);
	variantVec2 = value2.variant();

	BOOST_REQUIRE(value2.arrayLength() == 1);
    BOOST_REQUIRE(variantVec2.size() == 1);
	BOOST_REQUIRE(variantVec2[0].variant<OpcUaUInt32>() == 1);
}

BOOST_AUTO_TEST_CASE(OpcUaVariant_array_1_ptree)
{
	boost::property_tree::ptree pt;
	OpcUaVariant value1, value2;

	OpcUaVariantValue::Vec variantVec1, variantVec2;

	OpcUaVariantValue variantValue;
	variantValue.variant((OpcUaUInt32)1);
	variantVec1.push_back(variantValue);

	value1.variant(variantVec1);
	value1.encode(pt);
	value2.decode(pt, OpcUaBuildInType_OpcUaUInt32, true);
	variantVec2 = value2.variant();

	BOOST_REQUIRE(value2.arrayLength() == 1);
    BOOST_REQUIRE(variantVec2.size() == 1);
	BOOST_REQUIRE(variantVec2[0].variant<OpcUaUInt32>() == 1);
}


BOOST_AUTO_TEST_CASE(OpcUaVariant_array_2)
{
	std::stringstream ss;
	OpcUaVariant value1, value2;
	
	OpcUaVariantValue::Vec variantVec1, variantVec2;
	
	OpcUaVariantValue variantValue;
	variantValue.variant((OpcUaUInt32)1);
	variantVec1.push_back(variantValue);
	variantValue.variant((OpcUaUInt32)2);
	variantVec1.push_back(variantValue);

	value1.variant(variantVec1);
	value1.opcUaBinaryEncode(ss); 
	value2.opcUaBinaryDecode(ss);
	variantVec2 = value2.variant();

	BOOST_REQUIRE(value2.arrayLength() == 2);
    BOOST_REQUIRE(variantVec2.size() == 2);
	BOOST_REQUIRE(variantVec2[0].variant<OpcUaUInt32>() == 1);
	BOOST_REQUIRE(variantVec2[1].variant<OpcUaUInt32>() == 2);
}

BOOST_AUTO_TEST_CASE(OpcUaVariant_array_2_ptree)
{
	boost::property_tree::ptree pt;
	OpcUaVariant value1, value2;

	OpcUaVariantValue::Vec variantVec1, variantVec2;

	OpcUaVariantValue variantValue;
	variantValue.variant((OpcUaUInt32)1);
	variantVec1.push_back(variantValue);
	variantValue.variant((OpcUaUInt32)2);
	variantVec1.push_back(variantValue);

	value1.variant(variantVec1);
	value1.encode(pt);
	value2.decode(pt, OpcUaBuildInType_OpcUaUInt32, true);
	variantVec2 = value2.variant();

	BOOST_REQUIRE(value2.arrayLength() == 2);
    BOOST_REQUIRE(variantVec2.size() == 2);
	BOOST_REQUIRE(variantVec2[0].variant<OpcUaUInt32>() == 1);
	BOOST_REQUIRE(variantVec2[1].variant<OpcUaUInt32>() == 2);
}

BOOST_AUTO_TEST_CASE(OpcUaVariant_array_2_copyTo)
{
	std::stringstream ss;
	OpcUaVariant value1, value2;
	
	OpcUaVariantValue::Vec variantVec1, variantVec2;
	
	OpcUaVariantValue variantValue;
	variantValue.variant((OpcUaUInt32)1);
	variantVec1.push_back(variantValue);
	variantValue.variant((OpcUaUInt32)2);
	variantVec1.push_back(variantValue);

	value1.variant(variantVec1);
	value1.copyTo(value2);
	variantVec2 = value2.variant();

	BOOST_REQUIRE(value1.arrayLength() == 2);
    BOOST_REQUIRE(variantVec1.size() == 2);
	BOOST_REQUIRE(variantVec1[0].variant<OpcUaUInt32>() == 1);
	BOOST_REQUIRE(variantVec1[1].variant<OpcUaUInt32>() == 2);

	BOOST_REQUIRE(value2.arrayLength() == 2);
    BOOST_REQUIRE(variantVec2.size() == 2);
	BOOST_REQUIRE(variantVec2[0].variant<OpcUaUInt32>() == 1);
	BOOST_REQUIRE(variantVec2[1].variant<OpcUaUInt32>() == 2);

	value1.variant(0, (OpcUaUInt32)3);
	value1.variant(1, (OpcUaUInt32)4);
	variantVec1 = value1.variant();
	variantVec2 = value2.variant();

	BOOST_REQUIRE(value1.arrayLength() == 2);
    BOOST_REQUIRE(variantVec1.size() == 2);
	BOOST_REQUIRE(variantVec1[0].variant<OpcUaUInt32>() == 3);
	BOOST_REQUIRE(variantVec1[1].variant<OpcUaUInt32>() == 4);

	BOOST_REQUIRE(value2.arrayLength() == 2);
    BOOST_REQUIRE(variantVec2.size() == 2);
	BOOST_REQUIRE(variantVec2[0].variant<OpcUaUInt32>() == 1);
	BOOST_REQUIRE(variantVec2[1].variant<OpcUaUInt32>() == 2);
}

BOOST_AUTO_TEST_CASE(OpcUaVariant_array_dimensions_2_2)
{
	std::stringstream ss;
	OpcUaVariant value1, value2;
	
	OpcUaVariantValue::Vec variantVec1, variantVec2;
	
	OpcUaVariantValue variantValue;
	for (uint32_t idx=0; idx<4; idx++) {
		variantValue.variant((OpcUaUInt32)idx);
		variantVec1.push_back(variantValue);
	}

	OpcUaArrayDimensionsVec arrayDimensionsVec;
	arrayDimensionsVec.push_back(2);
	arrayDimensionsVec.push_back(2);


	value1.variant(variantVec1);
	value1.arrayDimension(arrayDimensionsVec);
	value1.opcUaBinaryEncode(ss); 
	value2.opcUaBinaryDecode(ss);
	variantVec2 = value2.variant();

	BOOST_REQUIRE(value2.arrayLength() == 4);
    BOOST_REQUIRE(variantVec2.size() == 4);
	for (uint32_t idx=0; idx<4; idx++) {
		BOOST_REQUIRE(variantVec2[idx].variant<OpcUaUInt32>() == idx);
	}

	std::cout << "len=" << value2.arrayDimension().size() << std::endl;
	BOOST_REQUIRE(value2.arrayDimension().size() == 2);
	BOOST_REQUIRE(value2.arrayDimension()[0] == 2);
	BOOST_REQUIRE(value2.arrayDimension()[1] == 2);
}

BOOST_AUTO_TEST_CASE(OpcUaVariant_array_dimensions_2_3)
{
	std::stringstream ss;
	OpcUaVariant value1, value2;
	
	OpcUaVariantValue::Vec variantVec1, variantVec2;
	
	OpcUaVariantValue variantValue;
	for (uint32_t idx=0; idx<6; idx++) {
		variantValue.variant((OpcUaUInt32)idx);
		variantVec1.push_back(variantValue);
	}

	OpcUaArrayDimensionsVec arrayDimensionsVec;
	arrayDimensionsVec.push_back(2);
	arrayDimensionsVec.push_back(3);


	value1.variant(variantVec1);
	value1.arrayDimension(arrayDimensionsVec);
	value1.opcUaBinaryEncode(ss); 
	value2.opcUaBinaryDecode(ss);
	variantVec2 = value2.variant();

	BOOST_REQUIRE(value2.arrayLength() == 6);
    BOOST_REQUIRE(variantVec2.size() == 6);
	for (uint32_t idx=0; idx<6; idx++) {
		BOOST_REQUIRE(variantVec2[idx].variant<OpcUaUInt32>() == idx);
	}

	BOOST_REQUIRE(value2.arrayDimension().size() == 2);
	BOOST_REQUIRE(value2.arrayDimension()[0] == 2);
	BOOST_REQUIRE(value2.arrayDimension()[1] == 3);
}

BOOST_AUTO_TEST_CASE(OpcUaVariant_array_string)
{
	std::stringstream ss;
	OpcUaString::SPtr string1, string2;
	OpcUaVariant value1, value2;
	OpcUaVariantValue::Vec variantVec1, variantVec2;
	OpcUaVariantValue variantValue1, variantValue2;
	
	string1 = constructSPtr<OpcUaString>();
	string1->value("Dies ist der erste string");
	variantValue1.variant(string1);
	variantVec1.push_back(variantValue1);

	string1 = constructSPtr<OpcUaString>();
	string1->value("Dies ist der zweite string");
	variantValue1.variant(string1);
	variantVec1.push_back(variantValue1);

	string1 = constructSPtr<OpcUaString>();
	string1->value("Dies ist der dritte string");
	variantValue1.variant(string1);
	variantVec1.push_back(variantValue1);

	value1.variant(variantVec1);

	value1.opcUaBinaryEncode(ss);
	dumpHex(ss);
	value2.opcUaBinaryDecode(ss);
	
	BOOST_REQUIRE(value2.arrayLength() == 3);
}

BOOST_AUTO_TEST_CASE(OpcUaVariant_getValue_setValue_boolean_error)
{
	OpcUaByte value;
	std::stringstream ss;
	OpcUaVariant value1, value2;

	// OpcUaBoolean
	value1.setValue((OpcUaBoolean)true);
	value1.opcUaBinaryEncode(ss);
	value2.opcUaBinaryDecode(ss);
	BOOST_REQUIRE(value2.getValue(value) == false);
}

BOOST_AUTO_TEST_CASE(OpcUaVariant_getValue_setValue_boolean)
{
	OpcUaBoolean value;
	std::stringstream ss;
	OpcUaVariant value1, value2;

	value1.setValue((OpcUaBoolean)true);
	value1.opcUaBinaryEncode(ss);
	value2.opcUaBinaryDecode(ss);
	BOOST_REQUIRE(value2.getValue(value) == true);
	BOOST_REQUIRE(value == true);
}

BOOST_AUTO_TEST_CASE(OpcUaVariant_getValue_setValue_byte)
{
	OpcUaByte value;
	std::stringstream ss;
	OpcUaVariant value1, value2;

	value1.setValue((OpcUaByte)12);
	value1.opcUaBinaryEncode(ss);
	value2.opcUaBinaryDecode(ss);
	BOOST_REQUIRE(value2.getValue(value) == true);
	BOOST_REQUIRE(value == 12);
}

BOOST_AUTO_TEST_CASE(OpcUaVariant_getValue_setValue_sbyte)
{
	OpcUaSByte value;
	std::stringstream ss;
	OpcUaVariant value1, value2;

	value1.setValue((OpcUaSByte)-12);
	value1.opcUaBinaryEncode(ss);
	value2.opcUaBinaryDecode(ss);
	BOOST_REQUIRE(value2.getValue(value) == true);
	BOOST_REQUIRE(value == -12);
}

BOOST_AUTO_TEST_CASE(OpcUaVariant_getValue_setValue_uint16)
{
	OpcUaUInt16 value;
	std::stringstream ss;
	OpcUaVariant value1, value2;

	value1.setValue((OpcUaUInt16)123);
	value1.opcUaBinaryEncode(ss);
	value2.opcUaBinaryDecode(ss);
	BOOST_REQUIRE(value2.getValue(value) == true);
	BOOST_REQUIRE(value == 123);
}

BOOST_AUTO_TEST_CASE(OpcUaVariant_getValue_setValue_int16)
{
	OpcUaInt16 value;
	std::stringstream ss;
	OpcUaVariant value1, value2;

	value1.setValue((OpcUaInt16)-123);
	value1.opcUaBinaryEncode(ss);
	value2.opcUaBinaryDecode(ss);
	BOOST_REQUIRE(value2.getValue(value) == true);
	BOOST_REQUIRE(value == -123);
}

BOOST_AUTO_TEST_CASE(OpcUaVariant_getValue_setValue_uint32)
{
	OpcUaUInt32 value;
	std::stringstream ss;
	OpcUaVariant value1, value2;

	value1.setValue((OpcUaUInt32)1234);
	value1.opcUaBinaryEncode(ss);
	value2.opcUaBinaryDecode(ss);
	BOOST_REQUIRE(value2.getValue(value) == true);
	BOOST_REQUIRE(value == 1234);
}

BOOST_AUTO_TEST_CASE(OpcUaVariant_getValue_setValue_int32)
{
	OpcUaInt32 value;
	std::stringstream ss;
	OpcUaVariant value1, value2;

	value1.setValue((OpcUaInt32)-1234);
	value1.opcUaBinaryEncode(ss);
	value2.opcUaBinaryDecode(ss);
	BOOST_REQUIRE(value2.getValue(value) == true);
	BOOST_REQUIRE(value == -1234);
}

BOOST_AUTO_TEST_CASE(OpcUaVariant_getValue_setValue_uint64)
{
	OpcUaUInt64 value;
	std::stringstream ss;
	OpcUaVariant value1, value2;

	value1.setValue((OpcUaUInt64)12345);
	value1.opcUaBinaryEncode(ss);
	value2.opcUaBinaryDecode(ss);
	BOOST_REQUIRE(value2.getValue(value) == true);
	BOOST_REQUIRE(value == 12345);
}

BOOST_AUTO_TEST_CASE(OpcUaVariant_getValue_setValue_int64)
{
	OpcUaInt64 value;
	std::stringstream ss;
	OpcUaVariant value1, value2;

	value1.setValue((OpcUaInt64)-12345);
	value1.opcUaBinaryEncode(ss);
	value2.opcUaBinaryDecode(ss);
	BOOST_REQUIRE(value2.getValue(value) == true);
	BOOST_REQUIRE(value == -12345);
}

BOOST_AUTO_TEST_CASE(OpcUaVariant_getValue_setValue_float)
{
	OpcUaFloat value;
	std::stringstream ss;
	OpcUaVariant value1, value2;

	value1.setValue((OpcUaFloat)12);
	value1.opcUaBinaryEncode(ss);
	value2.opcUaBinaryDecode(ss);
	BOOST_REQUIRE(value2.getValue(value) == true);
	BOOST_REQUIRE(value == 12);
}

BOOST_AUTO_TEST_CASE(OpcUaVariant_getValue_setValue_double)
{
	OpcUaDouble value;
	std::stringstream ss;
	OpcUaVariant value1, value2;

	value1.setValue((OpcUaDouble)12);
	value1.opcUaBinaryEncode(ss);
	value2.opcUaBinaryDecode(ss);
	BOOST_REQUIRE(value2.getValue(value) == true);
	BOOST_REQUIRE(value == 12);
}

BOOST_AUTO_TEST_CASE(OpcUaVariant_getValue_setValue_string)
{
	OpcUaString value;
	std::stringstream ss;
	OpcUaVariant value1, value2;

	value1.setValue(OpcUaString("String"));
	value1.opcUaBinaryEncode(ss);
	value2.opcUaBinaryDecode(ss);
	BOOST_REQUIRE(value2.getValue(value) == true);
	BOOST_REQUIRE(value == OpcUaString("String"));
}

BOOST_AUTO_TEST_CASE(OpcUaVariant_getValue_setValue_datetime)
{
	boost::posix_time::ptime now = boost::posix_time::microsec_clock::local_time();
	OpcUaDateTime value;
	std::stringstream ss;
	OpcUaVariant value1, value2;

	value1.setValue(OpcUaDateTime(now));
	value1.opcUaBinaryEncode(ss);
	value2.opcUaBinaryDecode(ss);
	BOOST_REQUIRE(value2.getValue(value) == true);
	BOOST_REQUIRE(value == OpcUaDateTime(now));
}

BOOST_AUTO_TEST_CASE(OpcUaVariant_getValue_setValue_guid)
{
	OpcUaGuid value;
	std::stringstream ss;
	OpcUaVariant value1, value2;

	OpcUaGuid guid;
	guid.value("12345678-9ABC-DEF0-1234-56789ABCDEF0");
	value1.setValue(guid);
	value1.opcUaBinaryEncode(ss);
	value2.opcUaBinaryDecode(ss);
	BOOST_REQUIRE(value2.getValue(value) == true);
	BOOST_REQUIRE(value.value() == "12345678-9ABC-DEF0-1234-56789ABCDEF0");
}

BOOST_AUTO_TEST_CASE(OpcUaVariant_getValue_setValue_byteString)
{
	OpcUaByteString value;
	std::stringstream ss;
	OpcUaVariant value1, value2;

	OpcUaByteString byteString;
	byteString.fromString("ByteString");
	value1.setValue(byteString);
	value1.opcUaBinaryEncode(ss);
	value2.opcUaBinaryDecode(ss);
	BOOST_REQUIRE(value2.getValue(value) == true);
	BOOST_REQUIRE(value.toString() == "ByteString");
}

BOOST_AUTO_TEST_CASE(OpcUaVariant_getValue_setValue_nodeId)
{
	OpcUaNodeId value;
	std::stringstream ss;
	OpcUaVariant value1, value2;

	value1.setValue(OpcUaNodeId(12, 34));
	value1.opcUaBinaryEncode(ss);
	value2.opcUaBinaryDecode(ss);
	BOOST_REQUIRE(value2.getValue(value) == true);
	BOOST_REQUIRE(value == OpcUaNodeId(12, 34));
}

BOOST_AUTO_TEST_CASE(OpcUaVariant_getValue_setValue_expandedNodeId1)
{
	OpcUaExpandedNodeId value;
	std::stringstream ss;
	OpcUaVariant value1, value2;

	OpcUaExpandedNodeId expandedNodeId;
	BOOST_REQUIRE(expandedNodeId.fromString("svr=4711;ns=1;s=NodeName"));

	value1.setValue(expandedNodeId);
	value1.opcUaBinaryEncode(ss);
	value2.opcUaBinaryDecode(ss);
	BOOST_REQUIRE(value2.getValue(value) == true);
	BOOST_REQUIRE(value == expandedNodeId);
}

BOOST_AUTO_TEST_CASE(OpcUaVariant_getValue_setValue_expandedNodeId2)
{
	OpcUaExpandedNodeId value;
	std::stringstream ss;
	OpcUaVariant value1, value2;

	OpcUaExpandedNodeId expandedNodeId;
	BOOST_REQUIRE(expandedNodeId.fromString("svr=4711;nsu=xyz;s=NodeName"));

	value1.setValue(expandedNodeId);
	value1.opcUaBinaryEncode(ss);
	value2.opcUaBinaryDecode(ss);
	BOOST_REQUIRE(value2.getValue(value) == true);
	BOOST_REQUIRE(value == expandedNodeId);
}

BOOST_AUTO_TEST_CASE(OpcUaVariant_getValue_setValue_statusCode)
{
	OpcUaStatusCode value;
	std::stringstream ss;
	OpcUaVariant value1, value2;

	value1.setValue(Success);
	value1.opcUaBinaryEncode(ss);
	value2.opcUaBinaryDecode(ss);
	BOOST_REQUIRE(value2.getValue(value) == true);
	BOOST_REQUIRE(value == Success);
}

BOOST_AUTO_TEST_CASE(OpcUaVariant_getValue_setValue_qualifiedName)
{
	OpcUaQualifiedName value;
	std::stringstream ss;
	OpcUaVariant value1, value2;

	value1.setValue(OpcUaQualifiedName("QualifiedName", 123));
	value1.opcUaBinaryEncode(ss);
	value2.opcUaBinaryDecode(ss);
	BOOST_REQUIRE(value2.getValue(value) == true);
	BOOST_REQUIRE(value == OpcUaQualifiedName("QualifiedName", 123));
}

BOOST_AUTO_TEST_CASE(OpcUaVariant_getValue_setValue_localizedText)
{
	OpcUaLocalizedText value;
	std::stringstream ss;
	OpcUaVariant value1, value2;

	value1.setValue(OpcUaLocalizedText("de", "OpcUaLocalizedText"));
	value1.opcUaBinaryEncode(ss);
	value2.opcUaBinaryDecode(ss);
	BOOST_REQUIRE(value2.getValue(value) == true);
	BOOST_REQUIRE(value == OpcUaLocalizedText("de", "OpcUaLocalizedText"));
}

BOOST_AUTO_TEST_CASE(OpcUaVariant_getValue_setValue_extensionObject)
{
	OpcUaExtensionObject eo;
	eo.registerFactoryElement<StatusResult>(OpcUaId_StatusResult_Encoding_DefaultBinary);

	OpcUaExtensionObject v1, v2;
	std::stringstream ss;
	OpcUaVariant value1, value2;

	StatusResult::SPtr statusResult;
	statusResult = v1.parameter<StatusResult>(OpcUaId_StatusResult_Encoding_DefaultBinary);
	statusResult->statusCode(3494);

	value1.setValue(v1);
	value1.opcUaBinaryEncode(ss);
	value2.opcUaBinaryDecode(ss);
	BOOST_REQUIRE(value2.getValue(v2) == true);
	BOOST_REQUIRE(v1 == v2);
}

BOOST_AUTO_TEST_SUITE_END()
