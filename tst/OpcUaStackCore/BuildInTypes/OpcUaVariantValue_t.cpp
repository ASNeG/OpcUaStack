#include "unittest.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaVariant.h"

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(OpcUaVariantValue_)

BOOST_AUTO_TEST_CASE(OpcUaVariantValue_)
{
	std::cout << "OpcUaVariantValue_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(OpcUaVariantValue_uint32_copyTo)
{
	OpcUaVariantValue value1, value2;
	value1.variant((OpcUaUInt32)123);

	value1.copyTo(value2);

	BOOST_REQUIRE(value1.variant<OpcUaUInt32>() == 123);
	BOOST_REQUIRE(value2.variant<OpcUaUInt32>() == 123);

	value2.variant((OpcUaUInt32)456);

	BOOST_REQUIRE(value1.variant<OpcUaUInt32>() == 123);
	BOOST_REQUIRE(value2.variant<OpcUaUInt32>() == 456);
}

BOOST_AUTO_TEST_CASE(OpcUaVariantValue_localizedText_copyTo)
{
	OpcUaLocalizedText::SPtr localizedTextSPtr1 = boost::make_shared<OpcUaLocalizedText>();
	OpcUaLocalizedText::SPtr localizedTextSPtr2;

	localizedTextSPtr1->locale("de");
	localizedTextSPtr1->text("text1");

	OpcUaVariantValue value1, value2;
	value1.variant(localizedTextSPtr1);

	value1.copyTo(value2);

	localizedTextSPtr1 = value1.variantSPtr<OpcUaLocalizedText>();
	localizedTextSPtr2 = value2.variantSPtr<OpcUaLocalizedText>();
	BOOST_REQUIRE(localizedTextSPtr1->locale().value() == "de");
	BOOST_REQUIRE(localizedTextSPtr1->text().value() == "text1");
	BOOST_REQUIRE(localizedTextSPtr2->locale().value() == "de");
	BOOST_REQUIRE(localizedTextSPtr2->text().value() == "text1");

	localizedTextSPtr1->text("text2");

	BOOST_REQUIRE(localizedTextSPtr1->locale().value() == "de");
	BOOST_REQUIRE(localizedTextSPtr1->text().value() == "text2");
	BOOST_REQUIRE(localizedTextSPtr2->locale().value() == "de");
	BOOST_REQUIRE(localizedTextSPtr2->text().value() == "text1");
}

BOOST_AUTO_TEST_CASE(OpcUaVariantValue_fromString_Boolean)
{
	OpcUaVariantValue variantValue;
	BOOST_REQUIRE(variantValue.fromString("Boolean:true") == true);

	BOOST_REQUIRE(variantValue.variantType() == OpcUaBuildInType_OpcUaBoolean);

	OpcUaBoolean value = variantValue.variant<OpcUaBoolean>();
	BOOST_REQUIRE(value == true);
}

BOOST_AUTO_TEST_CASE(OpcUaVariantValue_fromString_SByte)
{
	OpcUaVariantValue variantValue;
	BOOST_REQUIRE(variantValue.fromString("SByte:-12") == true);

	BOOST_REQUIRE(variantValue.variantType() == OpcUaBuildInType_OpcUaSByte);

	OpcUaSByte value = variantValue.variant<OpcUaSByte>();
	BOOST_REQUIRE(value == -12);
}

BOOST_AUTO_TEST_CASE(OpcUaVariantValue_fromString_Byte)
{
	OpcUaVariantValue variantValue;
	BOOST_REQUIRE(variantValue.fromString("Byte:12") == true);

	BOOST_REQUIRE(variantValue.variantType() == OpcUaBuildInType_OpcUaByte);

	OpcUaByte value = variantValue.variant<OpcUaByte>();
	BOOST_REQUIRE(value == 12);
}

BOOST_AUTO_TEST_CASE(OpcUaVariantValue_fromString_Int16)
{
	OpcUaVariantValue variantValue;
	BOOST_REQUIRE(variantValue.fromString("Int16:-1234") == true);

	BOOST_REQUIRE(variantValue.variantType() == OpcUaBuildInType_OpcUaInt16);

	OpcUaInt16 value = variantValue.variant<OpcUaInt16>();
	BOOST_REQUIRE(value == -1234);
}

BOOST_AUTO_TEST_CASE(OpcUaVariantValue_fromString_UInt16)
{
	OpcUaVariantValue variantValue;
	BOOST_REQUIRE(variantValue.fromString("UInt16:1234") == true);

	BOOST_REQUIRE(variantValue.variantType() == OpcUaBuildInType_OpcUaUInt16);

	OpcUaUInt16 value = variantValue.variant<OpcUaUInt16>();
	BOOST_REQUIRE(value == 1234);
}

BOOST_AUTO_TEST_CASE(OpcUaVariantValue_fromString_Int32)
{
	OpcUaVariantValue variantValue;
	BOOST_REQUIRE(variantValue.fromString("Int32:-1234") == true);

	BOOST_REQUIRE(variantValue.variantType() == OpcUaBuildInType_OpcUaInt32);

	OpcUaInt32 value = variantValue.variant<OpcUaInt32>();
	BOOST_REQUIRE(value == -1234);
}

BOOST_AUTO_TEST_CASE(OpcUaVariantValue_fromString_UInt32)
{
	OpcUaVariantValue variantValue;
	BOOST_REQUIRE(variantValue.fromString("UInt32:1234") == true);

	BOOST_REQUIRE(variantValue.variantType() == OpcUaBuildInType_OpcUaUInt32);

	OpcUaUInt32 value = variantValue.variant<OpcUaUInt32>();
	BOOST_REQUIRE(value == 1234);
}

BOOST_AUTO_TEST_CASE(OpcUaVariantValue_fromString_Int64)
{
	OpcUaVariantValue variantValue;
	BOOST_REQUIRE(variantValue.fromString("Int64:-1234") == true);

	BOOST_REQUIRE(variantValue.variantType() == OpcUaBuildInType_OpcUaInt64);

	OpcUaInt64 value = variantValue.variant<OpcUaInt64>();
	BOOST_REQUIRE(value == -1234);
}

BOOST_AUTO_TEST_CASE(OpcUaVariantValue_fromString_UInt64)
{
	OpcUaVariantValue variantValue;
	BOOST_REQUIRE(variantValue.fromString("UInt64:1234") == true);

	BOOST_REQUIRE(variantValue.variantType() == OpcUaBuildInType_OpcUaUInt64);

	OpcUaUInt64 value = variantValue.variant<OpcUaUInt64>();
	BOOST_REQUIRE(value == 1234);
}

BOOST_AUTO_TEST_CASE(OpcUaVariantValue_fromString_Double)
{
	OpcUaVariantValue variantValue;
	BOOST_REQUIRE(variantValue.fromString("Double:1.1") == true);

	BOOST_REQUIRE(variantValue.variantType() == OpcUaBuildInType_OpcUaDouble);

	OpcUaDouble value = variantValue.variant<OpcUaDouble>();
	BOOST_REQUIRE(value > 1.09 && value < 1.11);
}

BOOST_AUTO_TEST_CASE(OpcUaVariantValue_fromString_Float)
{
	OpcUaVariantValue variantValue;
	BOOST_REQUIRE(variantValue.fromString("Float:1.1") == true);

	BOOST_REQUIRE(variantValue.variantType() == OpcUaBuildInType_OpcUaFloat);

	OpcUaFloat value = variantValue.variant<OpcUaFloat>();
	BOOST_REQUIRE(value > 1.09 && value < 1.11);
}

BOOST_AUTO_TEST_CASE(OpcUaVariantValue_fromString_DateTime)
{
	OpcUaVariantValue variantValue;
	BOOST_REQUIRE(variantValue.fromString("DateTime:20120101T101101") == true);

	BOOST_REQUIRE(variantValue.variantType() == OpcUaBuildInType_OpcUaDateTime);

	OpcUaDateTime value = variantValue.variant<OpcUaDateTime>();
	BOOST_REQUIRE(value.toISOString() == "20120101T101101");
}

BOOST_AUTO_TEST_CASE(OpcUaVariantValue_fromString_StatusCode)
{
	OpcUaVariantValue variantValue;
	BOOST_REQUIRE(variantValue.fromString("Status:Success") == true);

	BOOST_REQUIRE(variantValue.variantType() == OpcUaBuildInType_OpcUaStatusCode);

	OpcUaStatusCode value = variantValue.variant<OpcUaStatusCode>();
	BOOST_REQUIRE(value == Success);
}

BOOST_AUTO_TEST_CASE(OpcUaVariantValue_fromString_Guid)
{
	OpcUaVariantValue variantValue;
	BOOST_REQUIRE(variantValue.fromString("Guid:12345678-9ABC-DEF0-1234-56789ABCDEF0") == true);

	BOOST_REQUIRE(variantValue.variantType() == OpcUaBuildInType_OpcUaGuid);

	OpcUaGuid::SPtr value = variantValue.variantSPtr<OpcUaGuid>();
	std::string guidString = *value;
	BOOST_REQUIRE(guidString == "12345678-9ABC-DEF0-1234-56789ABCDEF0");
}

BOOST_AUTO_TEST_CASE(OpcUaVariantValue_fromString_ByteString)
{
	OpcUaVariantValue variantValue;
	BOOST_REQUIRE(variantValue.fromString("ByteString:0102030405060708090A0B0C0E0F") == true);

	BOOST_REQUIRE(variantValue.variantType() == OpcUaBuildInType_OpcUaByteString);

	OpcUaByteString::SPtr value = variantValue.variantSPtr<OpcUaByteString>();
	BOOST_REQUIRE(value->toHexString() == "0102030405060708090A0B0C0E0F");
}

BOOST_AUTO_TEST_CASE(OpcUaVariantValue_fromString_String)
{
	OpcUaVariantValue variantValue;
	BOOST_REQUIRE(variantValue.fromString("String:0102030405060708090A0B0C0E0F") == true);

	BOOST_REQUIRE(variantValue.variantType() == OpcUaBuildInType_OpcUaString);

	OpcUaString::SPtr value = variantValue.variantSPtr<OpcUaString>();
	BOOST_REQUIRE(value->value() == "0102030405060708090A0B0C0E0F");
}

BOOST_AUTO_TEST_CASE(OpcUaVariantValue_fromString_NodeId)
{
	OpcUaVariantValue variantValue;
	BOOST_REQUIRE(variantValue.fromString("NodeId:ns=3;s=nodename") == true);

	BOOST_REQUIRE(variantValue.variantType() == OpcUaBuildInType_OpcUaNodeId);

	OpcUaNodeId::SPtr value = variantValue.variantSPtr<OpcUaNodeId>();
	BOOST_REQUIRE(value->namespaceIndex() == 3);
	BOOST_REQUIRE(value->nodeId<OpcUaString::SPtr>()->value() == "nodename");
}

BOOST_AUTO_TEST_CASE(OpcUaVariantValue_fromString_QualifiedName)
{
	OpcUaVariantValue variantValue;
	BOOST_REQUIRE(variantValue.fromString("QualifiedName:1:string") == true);

	BOOST_REQUIRE(variantValue.variantType() == OpcUaBuildInType_OpcUaQualifiedName);

	OpcUaQualifiedName::SPtr value = variantValue.variantSPtr<OpcUaQualifiedName>();
	BOOST_REQUIRE(value->namespaceIndex() == 1);
	BOOST_REQUIRE(value->name().value() == "string");
}

BOOST_AUTO_TEST_CASE(OpcUaVariantValue_fromString_LocalizedText)
{
	OpcUaVariantValue variantValue;
	BOOST_REQUIRE(variantValue.fromString("LocalizedText:de,string") == true);

	BOOST_REQUIRE(variantValue.variantType() == OpcUaBuildInType_OpcUaLocalizedText);

	OpcUaLocalizedText::SPtr value = variantValue.variantSPtr<OpcUaLocalizedText>();
	BOOST_REQUIRE(value->locale().value() == "de");
	BOOST_REQUIRE(value->text().value() == "string");
}

BOOST_AUTO_TEST_SUITE_END()
