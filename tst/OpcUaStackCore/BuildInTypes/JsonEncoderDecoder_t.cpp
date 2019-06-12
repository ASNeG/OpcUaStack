#include "unittest.h"
#include "OpcUaStackCore/Base/Utility.h"
#include "OpcUaStackCore/Base/ConfigJson.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/JsonNumber.h"
#include "OpcUaStackCore/StandardDataTypes/Argument.h"
#include <boost/iostreams/stream.hpp>

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(JsonEncoderDecoder_)

BOOST_AUTO_TEST_CASE(JsonEncoderDecoder_)
{
	std::cout << "JsonEncoderDecoder_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(JsonEncoderDecoder_Boolean)
{
	ConfigJson json;
	boost::property_tree::ptree pt;
	OpcUaBoolean value1, value2;

	value1 = false;
	JsonNumber::jsonEncode(pt, value1, "BooleanValue");

	json.ptree(pt);
	json.write(std::cout);
	std::cout << std::endl;

	JsonNumber::jsonDecode(pt, value2, "BooleanValue");
	BOOST_REQUIRE(value2 == false);
}

BOOST_AUTO_TEST_CASE(JsonEncoderDecoder_Byte)
{
	ConfigJson json;
	boost::property_tree::ptree pt;
	OpcUaByte value1, value2;

	value1 = 12;
	JsonNumber::jsonEncode(pt, value1, "ByteValue");

	json.ptree(pt);
	json.write(std::cout);
	std::cout << std::endl;

	JsonNumber::jsonDecode(pt, value2, "ByteValue");
	BOOST_REQUIRE(value2 == 12);
}

BOOST_AUTO_TEST_CASE(JsonEncoderDecoder_SByte)
{
	ConfigJson json;
	boost::property_tree::ptree pt;
	OpcUaSByte value1, value2;

	value1 = -12;
	JsonNumber::jsonEncode(pt, value1, "SByteValue");

	json.ptree(pt);
	json.write(std::cout);
	std::cout << std::endl;

	JsonNumber::jsonDecode(pt, value2, "SByteValue");
	BOOST_REQUIRE(value2 == -12);
}

BOOST_AUTO_TEST_CASE(JsonEncoderDecoder_UInt16)
{
	ConfigJson json;
	boost::property_tree::ptree pt;
	OpcUaUInt16 value1, value2;

	value1 = 123;
	JsonNumber::jsonEncode(pt, value1, "UInt16");

	json.ptree(pt);
	json.write(std::cout);
	std::cout << std::endl;

	JsonNumber::jsonDecode(pt, value2, "UInt16");
	BOOST_REQUIRE(value2 == 123);
}

BOOST_AUTO_TEST_CASE(JsonEncoderDecoder_Int16)
{
	ConfigJson json;
	boost::property_tree::ptree pt;
	OpcUaInt16 value1, value2;

	value1 = -123;
	JsonNumber::jsonEncode(pt, value1, "Int16");

	json.ptree(pt);
	json.write(std::cout);
	std::cout << std::endl;

	JsonNumber::jsonDecode(pt, value2, "Int16");
	BOOST_REQUIRE(value2 == -123);
}

BOOST_AUTO_TEST_CASE(JsonEncoderDecoder_UInt32)
{
	ConfigJson json;
	boost::property_tree::ptree pt;
	OpcUaUInt32 value1, value2;

	value1 = 1234;
	JsonNumber::jsonEncode(pt, value1, "UInt32");

	json.ptree(pt);
	json.write(std::cout);
	std::cout << std::endl;

	JsonNumber::jsonDecode(pt, value2, "UInt32");
	BOOST_REQUIRE(value2 == 1234);
}

BOOST_AUTO_TEST_CASE(JsonEncoderDecoder_Int32)
{
	ConfigJson json;
	boost::property_tree::ptree pt;
	OpcUaInt32 value1, value2;

	value1 = -1234;
	JsonNumber::jsonEncode(pt, value1, "Int32");

	json.ptree(pt);
	json.write(std::cout);
	std::cout << std::endl;

	JsonNumber::jsonDecode(pt, value2, "Int32");
	BOOST_REQUIRE(value2 == -1234);
}

BOOST_AUTO_TEST_CASE(JsonEncoderDecoder_UInt64)
{
	ConfigJson json;
	boost::property_tree::ptree pt;
	OpcUaUInt64 value1, value2;

	value1 = 12345;
	JsonNumber::jsonEncode(pt, value1, "UInt64");

	json.ptree(pt);
	json.write(std::cout);
	std::cout << std::endl;

	JsonNumber::jsonDecode(pt, value2, "UInt64");
	BOOST_REQUIRE(value2 == 12345);
}

BOOST_AUTO_TEST_CASE(JsonEncoderDecoder_Int64)
{
	ConfigJson json;
	boost::property_tree::ptree pt;
	OpcUaInt64 value1, value2;

	value1 = -12345;
	JsonNumber::jsonEncode(pt, value1, "Int64");

	json.ptree(pt);
	json.write(std::cout);
	std::cout << std::endl;

	JsonNumber::jsonDecode(pt, value2, "Int64");
	BOOST_REQUIRE(value2 == -12345);
}

BOOST_AUTO_TEST_CASE(JsonEncoderDecoder_Float)
{
	ConfigJson json;
	boost::property_tree::ptree pt;
	OpcUaFloat value1, value2;

	value1 = 12.34;
	JsonNumber::jsonEncode(pt, value1, "Float");

	json.ptree(pt);
	json.write(std::cout);
	std::cout << std::endl;

	JsonNumber::jsonDecode(pt, value2, "Float");
	BOOST_REQUIRE(value2 > 12.33 && value2 < 12.35);
}

BOOST_AUTO_TEST_CASE(JsonEncoderDecoder_Double)
{
	ConfigJson json;
	boost::property_tree::ptree pt;
	OpcUaDouble value1, value2;

	value1 = 12.34;
	JsonNumber::jsonEncode(pt, value1, "Double");

	json.ptree(pt);
	json.write(std::cout);
	std::cout << std::endl;

	JsonNumber::jsonDecode(pt, value2, "Double");
	BOOST_REQUIRE(value2 > 12.33 && value2 < 12.35);
}

BOOST_AUTO_TEST_CASE(JsonEncoderDecoder_OpcUaString)
{
	ConfigJson json;
	boost::property_tree::ptree pt;
	OpcUaString value1, value2;

	value1.value("Dies ist ein String");
	value1.jsonEncode(pt, "String");

	json.ptree(pt);
	json.write(std::cout);
	std::cout << std::endl;

	value2.jsonDecode(pt, "String");
	BOOST_REQUIRE(value2.value() == std::string("Dies ist ein String"));
}

BOOST_AUTO_TEST_CASE(JsonEncoderDecoder_OpcUaDataTime)
{
	boost::posix_time::ptime now = boost::posix_time::microsec_clock::universal_time();

	ConfigJson json;
	boost::property_tree::ptree pt;
	OpcUaDateTime value1, value2;

	value1.dateTime(now);
	value1.jsonEncode(pt, "DateTime");

	json.ptree(pt);
	json.write(std::cout);
	std::cout << std::endl;

	value2.jsonDecode(pt, "DateTime");
	BOOST_REQUIRE(value1.toISO8601() == value2.toISO8601());
}

BOOST_AUTO_TEST_CASE(JsonEncoderDecoder_OpcUaGuid)
{
	ConfigJson json;
	boost::property_tree::ptree pt;
	OpcUaGuid value1, value2;

	value1 = "12345678-9ABC-DEF0-1234-56789ABCDEF0";
	value1.jsonEncode(pt, "Guid");

	json.ptree(pt);
	json.write(std::cout);
	std::cout << std::endl;

	value2.jsonDecode(pt, "Guid");
	std::string str = value2;
	BOOST_REQUIRE(str == "12345678-9ABC-DEF0-1234-56789ABCDEF0");
}

BOOST_AUTO_TEST_CASE(JsonEncoderDecoder_OpcUaByteString)
{
	std::string str = "Dies ist ein ByteString";
	boost::property_tree::ptree pt;
	ConfigJson json;
	OpcUaByteString value2;

	OpcUaByteString value1;
	value1.value(str);
	value1.jsonEncode(pt, "ByteString");

	json.ptree(pt);
	json.write(std::cout);
	std::cout << std::endl;

	value2.jsonDecode(pt, "ByteString");
	BOOST_REQUIRE(value2.toString() == str);
}

BOOST_AUTO_TEST_CASE(JsonEncoderDecoder_OpcUaNodeId)
{
	boost::property_tree::ptree pt;
	ConfigJson json;
	OpcUaNodeId value1, value2;

	//
	// string node id
	//
	pt.clear();
	value1.set("NodeName", 123);
	value1.jsonEncode(pt, "NodeId");

	json.ptree(pt);
	json.write(std::cout);
	std::cout << std::endl;

	value2.jsonDecode(pt, "NodeId");
	BOOST_REQUIRE(value2 == OpcUaNodeId("NodeName", 123));

	//
	// uint32 node id
	//
	pt.clear();
	value1.set((uint32_t)4711, 123);
	value1.jsonEncode(pt, "NodeId");

	json.ptree(pt);
	json.write(std::cout);
	std::cout << std::endl;

	value2.jsonDecode(pt, "NodeId");
	BOOST_REQUIRE(value2 == OpcUaNodeId((uint32_t)4711, 123));

	//
	// guid node id
	//
	pt.clear();
	value1.set("12345678-9ABC-DEF0-1234-56789ABCDEF0");
	value1.jsonEncode(pt, "NodeId");

	json.ptree(pt);
	json.write(std::cout);
	std::cout << std::endl;

	value2.jsonDecode(pt, "NodeId");
	BOOST_REQUIRE(value2 == OpcUaNodeId("12345678-9ABC-DEF0-1234-56789ABCDEF0"));

	//
	// byte string node id
	//
	pt.clear();
	value1.set(OpcUaByteString("Das ist ein ByteString"));
	value1.jsonEncode(pt, "NodeId");

	json.ptree(pt);
	json.write(std::cout);
	std::cout << std::endl;

	value2.jsonDecode(pt, "NodeId");
	BOOST_REQUIRE(value2 == value1);
}

BOOST_AUTO_TEST_CASE(JsonEncoderDecoder_OpcUaExpandedNodeId)
{
	boost::property_tree::ptree pt;
	ConfigJson json;
	OpcUaExpandedNodeId value1, value2;

	pt.clear();
	value1.fromString("svr=4711;ns=1;s=NodeName");
	value1.jsonEncode(pt, "ExpandedNodeId");

	json.ptree(pt);
	json.write(std::cout);
	std::cout << std::endl;

	value2.jsonDecode(pt, "ExpandedNodeId");
	BOOST_REQUIRE(value2.toString() == "svr=4711;ns=1;s=NodeName");


	pt.clear();
	value1.fromString("svr=4711;nsu=NamespaceUri;s=NodeName");
	value1.jsonEncode(pt, "ExpandedNodeId");

	json.ptree(pt);
	json.write(std::cout);
	std::cout << std::endl;

	value2.jsonDecode(pt, "ExpandedNodeId");
	BOOST_REQUIRE(value2.toString() == "svr=4711;nsu=NamespaceUri;s=NodeName");
}

BOOST_AUTO_TEST_CASE(JsonEncoderDecoder_QualifiedName)
{
	boost::property_tree::ptree pt;
	ConfigJson json;
	OpcUaQualifiedName value1, value2;

	value1.namespaceIndex(123);
	value1.name("Name");
	value1.jsonEncode(pt, "QualifiedName");

	json.ptree(pt);
	json.write(std::cout);
	std::cout << std::endl;

	value2.jsonDecode(pt, "QualifiedName");
	BOOST_REQUIRE(value2.namespaceIndex() == 123);
	BOOST_REQUIRE(value2.name().toStdString() == "Name");
}

BOOST_AUTO_TEST_CASE(JsonEncoderDecoder_LocalizedText)
{
	boost::property_tree::ptree pt;
	ConfigJson json;
	OpcUaLocalizedText value1, value2;

	value1.locale("de");
	value1.text("Text");
	value1.jsonEncode(pt, "LocalizedText");

	json.ptree(pt);
	json.write(std::cout);
	std::cout << std::endl;

	value2.jsonDecode(pt, "LocalizedText");
	BOOST_REQUIRE(value2.locale().toStdString() == "de");
	BOOST_REQUIRE(value2.text().toStdString() == "Text");
}

BOOST_AUTO_TEST_CASE(JsonEncoderDecoder_ExtensionObject)
{
	OpcUaExtensionObject eo;
	eo.registerFactoryElement<Argument>(OpcUaId_Argument_Encoding_DefaultBinary);
	eo.registerFactoryElement<Argument>(15081);

	Argument::SPtr argument1, argument2;
	boost::property_tree::ptree pt;
	ConfigJson json;
	OpcUaExtensionObject value1, value2;

	argument1 = value1.parameter<Argument>(OpcUaId_Argument_Encoding_DefaultBinary);
	argument1->name().value("ArgumentName");
	argument1->dataType().set("NodeName", 23);
	argument1->arrayDimensions().resize(3);
	argument1->arrayDimensions().set(0, 123);
	argument1->arrayDimensions().set(1, 456);
	argument1->arrayDimensions().set(2, 789);
	argument1->description().set("de", "Description");
	BOOST_REQUIRE(value1.jsonEncode(pt, "ExtensionObject") == true);

	json.ptree(pt);
	json.write(std::cout);
	std::cout << std::endl;

	BOOST_REQUIRE(value2.jsonDecode(pt, "ExtensionObject") == true);
	BOOST_REQUIRE(value2.typeId().nodeId<OpcUaUInt32>() == OpcUaId_Argument_Encoding_DefaultBinary);
	argument2 = value2.parameter<Argument>();
	BOOST_REQUIRE(argument2->name().toStdString() == "ArgumentName");
	BOOST_REQUIRE(argument2->dataType() == OpcUaNodeId("NodeName", 23));
	BOOST_REQUIRE(argument2->description() == OpcUaLocalizedText("de", "Description"));
}

BOOST_AUTO_TEST_CASE(JsonEncoderDecoder_DataValue)
{
	boost::posix_time::ptime now = boost::posix_time::microsec_clock::universal_time();

	boost::property_tree::ptree pt;
	ConfigJson json;
	OpcUaDataValue value1, value2;

	value1.variant()->set((OpcUaInt32)12345);
	value1.statusCode(BadNoData);
	value1.sourceTimestamp(OpcUaDateTime(now));
	value1.serverTimestamp(OpcUaDateTime(now));
	BOOST_REQUIRE(value1.jsonEncode(pt, "DataValue") == true);

	json.ptree(pt);
	json.write(std::cout);
	std::cout << std::endl;
	BOOST_REQUIRE(value2.jsonDecode(pt, "DataValue") == true);
	BOOST_REQUIRE(value2.variant()->get<OpcUaInt32>() == 12345);
	BOOST_REQUIRE(value2.serverTimestamp().toISO8601() == value1.serverTimestamp().toISO8601());
	BOOST_REQUIRE(value2.sourceTimestamp().toISO8601() == value2.sourceTimestamp().toISO8601());
}

BOOST_AUTO_TEST_CASE(JsonEncoderDecoder_DiagnosticInfo)
{
	boost::posix_time::ptime now = boost::posix_time::microsec_clock::universal_time();

	boost::property_tree::ptree pt;
	ConfigJson json;
	OpcUaDiagnosticInfo value1, value2;

	value1.setSymbolicId(123);
	value1.setNamespaceUri(456);
	value1.setAdditionalInfo(OpcUaString("AdditionalInfo"));
	BOOST_REQUIRE(value1.jsonEncode(pt, "DiagnosticInfo") == true);

	json.ptree(pt);
	json.write(std::cout);
	std::cout << std::endl;
	BOOST_REQUIRE(value2.jsonDecode(pt, "DiagnosticInfo") == true);
	BOOST_REQUIRE(value2.getSymbolicId() == 123);
	BOOST_REQUIRE(value2.getNamespaceUri() == 456);
	BOOST_REQUIRE(value2.getAdditionalInfo() == OpcUaString("AdditionalInfo"));
}

BOOST_AUTO_TEST_CASE(JsonEncoderDecoder_DiagnosticInfo_nested)
{
	boost::posix_time::ptime now = boost::posix_time::microsec_clock::universal_time();

	boost::property_tree::ptree pt;
	ConfigJson json;
	OpcUaDiagnosticInfo value1, value2;
	OpcUaDiagnosticInfo::SPtr nested1, nested2;

	nested1 = constructSPtr<OpcUaDiagnosticInfo>();
	nested1->setSymbolicId(111);
	nested1->setNamespaceUri(111);
	nested1->setAdditionalInfo(OpcUaString("AdditionalInfo111"));

	value1.setSymbolicId(123);
	value1.setNamespaceUri(456);
	value1.setAdditionalInfo(OpcUaString("AdditionalInfo"));
	value1.diagnosticInfo(nested1);
	BOOST_REQUIRE(value1.jsonEncode(pt, "DiagnosticInfo") == true);

	json.ptree(pt);
	json.write(std::cout);
	std::cout << std::endl;
	BOOST_REQUIRE(value2.jsonDecode(pt, "DiagnosticInfo") == true);
	BOOST_REQUIRE(value2.getSymbolicId() == 123);
	BOOST_REQUIRE(value2.getNamespaceUri() == 456);
	BOOST_REQUIRE(value2.getAdditionalInfo() == OpcUaString("AdditionalInfo"));
	BOOST_REQUIRE(value2.diagnosticInfo()->getSymbolicId() == 111);
	BOOST_REQUIRE(value2.diagnosticInfo()->getNamespaceUri() == 111);
	BOOST_REQUIRE(value2.diagnosticInfo()->getAdditionalInfo() == OpcUaString("AdditionalInfo111"));
}


BOOST_AUTO_TEST_CASE(JsonEncoderDecoder_OpcUaVariant_OpcUaBoolean)
{
	boost::property_tree::ptree pt;
	ConfigJson json;
	OpcUaVariant value1, value2;

	value1.set((OpcUaBoolean)true);
	BOOST_REQUIRE(value1.jsonEncode(pt, "OpcUaVariantBoolean") == true);

	json.ptree(pt);
	json.write(std::cout);
	std::cout << std::endl;

	BOOST_REQUIRE(value2.jsonDecode(pt, "OpcUaVariantBoolean") == true);
	BOOST_REQUIRE(value2.get<OpcUaBoolean>() == true);
}

BOOST_AUTO_TEST_CASE(JsonEncoderDecoder_OpcUaVariant_SByte)
{
	boost::property_tree::ptree pt;
	ConfigJson json;
	OpcUaVariant value1, value2;

	value1.set((OpcUaSByte)-12);
	BOOST_REQUIRE(value1.jsonEncode(pt, "OpcUaVariantSByte") == true);

	json.ptree(pt);
	json.write(std::cout);
	std::cout << std::endl;

	BOOST_REQUIRE(value2.jsonDecode(pt, "OpcUaVariantSByte") == true);
	BOOST_REQUIRE(value2.get<OpcUaSByte>() == -12);
}

BOOST_AUTO_TEST_CASE(JsonEncoderDecoder_OpcUaVariant_Byte)
{
	boost::property_tree::ptree pt;
	ConfigJson json;
	OpcUaVariant value1, value2;

	value1.set((OpcUaByte)12);
	BOOST_REQUIRE(value1.jsonEncode(pt, "OpcUaVariantByte") == true);

	json.ptree(pt);
	json.write(std::cout);
	std::cout << std::endl;

	BOOST_REQUIRE(value2.jsonDecode(pt, "OpcUaVariantByte") == true);
	BOOST_REQUIRE(value2.get<OpcUaByte>() == 12);
}

BOOST_AUTO_TEST_CASE(JsonEncoderDecoder_OpcUaVariant_Int16)
{
	boost::property_tree::ptree pt;
	ConfigJson json;
	OpcUaVariant value1, value2;

	value1.set((OpcUaInt16)-123);
	BOOST_REQUIRE(value1.jsonEncode(pt, "OpcUaVariantInt16") == true);

	json.ptree(pt);
	json.write(std::cout);
	std::cout << std::endl;

	BOOST_REQUIRE(value2.jsonDecode(pt, "OpcUaVariantInt16") == true);
	BOOST_REQUIRE(value2.get<OpcUaInt16>() == -123);
}

BOOST_AUTO_TEST_CASE(JsonEncoderDecoder_OpcUaVariant_UInt16)
{
	boost::property_tree::ptree pt;
	ConfigJson json;
	OpcUaVariant value1, value2;

	value1.set((OpcUaUInt16)1234);
	BOOST_REQUIRE(value1.jsonEncode(pt, "OpcUaVariantUInt16") == true);

	json.ptree(pt);
	json.write(std::cout);
	std::cout << std::endl;

	BOOST_REQUIRE(value2.jsonDecode(pt, "OpcUaVariantUInt16") == true);
	BOOST_REQUIRE(value2.get<OpcUaUInt16>() == 1234);
}

BOOST_AUTO_TEST_CASE(JsonEncoderDecoder_OpcUaVariant_Int32)
{
	boost::property_tree::ptree pt;
	ConfigJson json;
	OpcUaVariant value1, value2;

	value1.set((OpcUaInt32)-1234);
	BOOST_REQUIRE(value1.jsonEncode(pt, "OpcUaVariantInt32") == true);

	json.ptree(pt);
	json.write(std::cout);
	std::cout << std::endl;

	BOOST_REQUIRE(value2.jsonDecode(pt, "OpcUaVariantInt32") == true);
	BOOST_REQUIRE(value2.get<OpcUaInt32>() == -1234);
}

BOOST_AUTO_TEST_CASE(JsonEncoderDecoder_OpcUaVariant_UInt32)
{
	boost::property_tree::ptree pt;
	ConfigJson json;
	OpcUaVariant value1, value2;

	value1.set((OpcUaUInt32)12345);
	BOOST_REQUIRE(value1.jsonEncode(pt, "OpcUaVariantUInt32") == true);

	json.ptree(pt);
	json.write(std::cout);
	std::cout << std::endl;

	BOOST_REQUIRE(value2.jsonDecode(pt, "OpcUaVariantUInt32") == true);
	BOOST_REQUIRE(value2.get<OpcUaUInt32>() == 12345);
}

BOOST_AUTO_TEST_CASE(JsonEncoderDecoder_OpcUaVariant_Int64)
{
	boost::property_tree::ptree pt;
	ConfigJson json;
	OpcUaVariant value1, value2;

	value1.set((OpcUaInt64)-12345);
	BOOST_REQUIRE(value1.jsonEncode(pt, "OpcUaVariantInt64") == true);

	json.ptree(pt);
	json.write(std::cout);
	std::cout << std::endl;

	BOOST_REQUIRE(value2.jsonDecode(pt, "OpcUaVariantInt64") == true);
	BOOST_REQUIRE(value2.get<OpcUaInt64>() == -12345);
}

BOOST_AUTO_TEST_CASE(JsonEncoderDecoder_OpcUaVariant_UInt64)
{
	boost::property_tree::ptree pt;
	ConfigJson json;
	OpcUaVariant value1, value2;

	value1.set((OpcUaUInt64)123456);
	BOOST_REQUIRE(value1.jsonEncode(pt, "OpcUaVariantUInt64") == true);

	json.ptree(pt);
	json.write(std::cout);
	std::cout << std::endl;

	BOOST_REQUIRE(value2.jsonDecode(pt, "OpcUaVariantUInt64") == true);
	BOOST_REQUIRE(value2.get<OpcUaUInt64>() == 123456);
}

BOOST_AUTO_TEST_CASE(JsonEncoderDecoder_OpcUaVariant_Float)
{
	boost::property_tree::ptree pt;
	ConfigJson json;
	OpcUaVariant value1, value2;

	value1.set((OpcUaFloat)1.2);
	BOOST_REQUIRE(value1.jsonEncode(pt, "OpcUaVariantFloat") == true);

	json.ptree(pt);
	json.write(std::cout);
	std::cout << std::endl;

	BOOST_REQUIRE(value2.jsonDecode(pt, "OpcUaVariantFloat") == true);
	OpcUaFloat v = value2.get<OpcUaFloat>();
	BOOST_REQUIRE(v > 1.1 && v < 1.3);
}

BOOST_AUTO_TEST_CASE(JsonEncoderDecoder_OpcUaVariant_Double)
{
	boost::property_tree::ptree pt;
	ConfigJson json;
	OpcUaVariant value1, value2;

	value1.set((OpcUaDouble)1.2);
	BOOST_REQUIRE(value1.jsonEncode(pt, "OpcUaVariantDouble") == true);

	json.ptree(pt);
	json.write(std::cout);
	std::cout << std::endl;

	BOOST_REQUIRE(value2.jsonDecode(pt, "OpcUaVariantDouble") == true);
	OpcUaDouble v = value2.get<OpcUaDouble>();
	BOOST_REQUIRE(v > 1.1 && v < 1.3);
}

BOOST_AUTO_TEST_CASE(JsonEncoderDecoder_OpcUaVariant_String)
{
	boost::property_tree::ptree pt;
	ConfigJson json;
	OpcUaVariant value1, value2;

	OpcUaString::SPtr string1 = constructSPtr<OpcUaString>();
	string1->value("Das ist ein String xxxx");
	value1.variant(string1);
	BOOST_REQUIRE(value1.jsonEncode(pt, "OpcUaVariantString") == true);

	json.ptree(pt);
	json.write(std::cout);
	std::cout << std::endl;

	BOOST_REQUIRE(value2.jsonDecode(pt, "OpcUaVariantString") == true);
	OpcUaString::SPtr string2 = value2.variantSPtr<OpcUaString>();
	BOOST_REQUIRE(string2->toStdString() == "Das ist ein String xxxx");
}

BOOST_AUTO_TEST_CASE(JsonEncoderDecoder_OpcUaVariant_DateTime)
{
	boost::posix_time::ptime now = boost::posix_time::microsec_clock::universal_time();

	boost::property_tree::ptree pt;
	ConfigJson json;
	OpcUaVariant value1, value2;

	value1.set(OpcUaDateTime(now));
	BOOST_REQUIRE(value1.jsonEncode(pt, "OpcUaVariantDateTime") == true);

	json.ptree(pt);
	json.write(std::cout);
	std::cout << std::endl;

	BOOST_REQUIRE(value2.jsonDecode(pt, "OpcUaVariantDateTime") == true);
	BOOST_REQUIRE(value2.get<OpcUaDateTime>().toISO8601() == value1.get<OpcUaDateTime>().toISO8601());
}

BOOST_AUTO_TEST_CASE(JsonEncoderDecoder_OpcUaVariant_ByteString)
{
	boost::property_tree::ptree pt;
	ConfigJson json;
	OpcUaVariant value1, value2;

	OpcUaByteString::SPtr byteString1 = constructSPtr<OpcUaByteString>();
	byteString1->value("Das ist ein ByteString xxxx");
	value1.variant(byteString1);
	BOOST_REQUIRE(value1.jsonEncode(pt, "OpcUaVariantByteString") == true);

	json.ptree(pt);
	json.write(std::cout);
	std::cout << std::endl;

	BOOST_REQUIRE(value2.jsonDecode(pt, "OpcUaVariantByteString") == true);
	OpcUaByteString::SPtr byteString2 = value2.variantSPtr<OpcUaByteString>();
	BOOST_REQUIRE(byteString2->toString() == "Das ist ein ByteString xxxx");
}

BOOST_AUTO_TEST_CASE(JsonEncoderDecoder_OpcUaVariant_Guid)
{
	boost::property_tree::ptree pt;
	ConfigJson json;
	OpcUaVariant value1, value2;

	OpcUaGuid::SPtr guid1 = constructSPtr<OpcUaGuid>();
	*guid1 = "12345678-9ABC-DEF0-1234-56789ABCDEF0";
	value1.variant(guid1);
	BOOST_REQUIRE(value1.jsonEncode(pt, "OpcUaVariantGuid") == true);

	json.ptree(pt);
	json.write(std::cout);
	std::cout << std::endl;

	BOOST_REQUIRE(value2.jsonDecode(pt, "OpcUaVariantGuid") == true);
	OpcUaGuid::SPtr guid2 = value2.variantSPtr<OpcUaGuid>();
	std::string str = *guid2;
	BOOST_REQUIRE(str == "12345678-9ABC-DEF0-1234-56789ABCDEF0");
}

BOOST_AUTO_TEST_CASE(JsonEncoderDecoder_OpcUaVariant_NodeId)
{
	boost::property_tree::ptree pt;
	ConfigJson json;
	OpcUaVariant value1, value2;

	OpcUaNodeId::SPtr nodeId1 = constructSPtr<OpcUaNodeId>();
	nodeId1->set(4711,4712);
	value1.variant(nodeId1);
	BOOST_REQUIRE(value1.jsonEncode(pt, "OpcUaVariantNodeId") == true);

	json.ptree(pt);
	json.write(std::cout);
	std::cout << std::endl;

	BOOST_REQUIRE(value2.jsonDecode(pt, "OpcUaVariantNodeId") == true);
	OpcUaNodeId::SPtr nodeId2 = value2.variantSPtr<OpcUaNodeId>();
	BOOST_REQUIRE(*nodeId2 == OpcUaNodeId(4711,4712));
}

BOOST_AUTO_TEST_CASE(JsonEncoderDecoder_OpcUaVariant_ExpandedNodeId)
{
	boost::property_tree::ptree pt;
	ConfigJson json;
	OpcUaVariant value1, value2;

	OpcUaExpandedNodeId::SPtr expandedNodeId1 = constructSPtr<OpcUaExpandedNodeId>();
	expandedNodeId1->set(4711, 4712);
	expandedNodeId1->serverIndex(4713);
	value1.variant(expandedNodeId1);
	BOOST_REQUIRE(value1.jsonEncode(pt, "OpcUaVariantExpandedNodeId") == true);

	json.ptree(pt);
	json.write(std::cout);
	std::cout << std::endl;

	BOOST_REQUIRE(value2.jsonDecode(pt, "OpcUaVariantExpandedNodeId") == true);
	OpcUaExpandedNodeId::SPtr expandedNodeId2 = value2.variantSPtr<OpcUaExpandedNodeId>();
	BOOST_REQUIRE(expandedNodeId2->namespaceIndex() == 4712);
	BOOST_REQUIRE(expandedNodeId2->serverIndex() == 4713);
}

BOOST_AUTO_TEST_CASE(JsonEncoderDecoder_OpcUaVariant_QualifiedName)
{
	boost::property_tree::ptree pt;
	ConfigJson json;
	OpcUaVariant value1, value2;

	OpcUaQualifiedName::SPtr qualifiedName1 = constructSPtr<OpcUaQualifiedName>();
	qualifiedName1->set("Name", 4712);
	value1.variant(qualifiedName1);
	BOOST_REQUIRE(value1.jsonEncode(pt, "OpcUaVariantQulifiedName") == true);

	json.ptree(pt);
	json.write(std::cout);
	std::cout << std::endl;

	BOOST_REQUIRE(value2.jsonDecode(pt, "OpcUaVariantQulifiedName") == true);
	OpcUaQualifiedName::SPtr qualifiedName2 = value2.variantSPtr<OpcUaQualifiedName>();
	BOOST_REQUIRE(*qualifiedName2 == OpcUaQualifiedName("Name", 4712));
}

BOOST_AUTO_TEST_CASE(JsonEncoderDecoder_OpcUaVariant_LocalizedText)
{
	boost::property_tree::ptree pt;
	ConfigJson json;
	OpcUaVariant value1, value2;

	OpcUaLocalizedText::SPtr localizedText1 = constructSPtr<OpcUaLocalizedText>();
	localizedText1->set("de", "Name");
	value1.variant(localizedText1);
	BOOST_REQUIRE(value1.jsonEncode(pt, "OpcUaVariantLocalizedText") == true);

	json.ptree(pt);
	json.write(std::cout);
	std::cout << std::endl;

	BOOST_REQUIRE(value2.jsonDecode(pt, "OpcUaVariantLocalizedText") == true);
	OpcUaLocalizedText::SPtr localizedText2 = value2.variantSPtr<OpcUaLocalizedText>();
	BOOST_REQUIRE(*localizedText2 == OpcUaLocalizedText("de", "Name"));
}

BOOST_AUTO_TEST_CASE(JsonEncoderDecoder_OpcUaVariant_ExtensionObject)
{
	OpcUaExtensionObject eo;
	eo.registerFactoryElement<Argument>(OpcUaId_Argument_Encoding_DefaultBinary);
	eo.registerFactoryElement<Argument>(15081);

	boost::property_tree::ptree pt;
	ConfigJson json;
	OpcUaVariant value1, value2;
	Argument::SPtr argument1, argument2;

	OpcUaExtensionObject::SPtr extentionObject1 = constructSPtr<OpcUaExtensionObject>();
	argument1 = extentionObject1->parameter<Argument>(OpcUaId_Argument_Encoding_DefaultBinary);
	argument1->name().value("ArgumentName");
	argument1->dataType().set("NodeName", 23);
	argument1->arrayDimensions().resize(3);
	argument1->arrayDimensions().set(0, 123);
	argument1->arrayDimensions().set(1, 456);
	argument1->arrayDimensions().set(2, 789);
	argument1->description().set("de", "Description");
	value1.variant(extentionObject1);
	BOOST_REQUIRE(value1.jsonEncode(pt, "OpcUaVariantExtensionObject") == true);

	json.ptree(pt);
	json.write(std::cout);
	std::cout << std::endl;

	BOOST_REQUIRE(value2.jsonDecode(pt, "OpcUaVariantExtensionObject") == true);
	OpcUaExtensionObject::SPtr extentionObject2 = value2.variantSPtr<OpcUaExtensionObject>();
	BOOST_REQUIRE(extentionObject2->typeId().nodeId<OpcUaUInt32>() == OpcUaId_Argument_Encoding_DefaultBinary);
	argument2 = extentionObject2->parameter<Argument>();
	BOOST_REQUIRE(argument2->name().toStdString() == "ArgumentName");
	BOOST_REQUIRE(argument2->dataType() == OpcUaNodeId("NodeName", 23));
	BOOST_REQUIRE(argument2->description() == OpcUaLocalizedText("de", "Description"));
}

BOOST_AUTO_TEST_CASE(JsonEncoderDecoder_Variant_DataValue)
{
	boost::posix_time::ptime now = boost::posix_time::microsec_clock::universal_time();

	boost::property_tree::ptree pt;
	ConfigJson json;
	OpcUaDataValue::SPtr dataValue1, dataValue2;
	OpcUaVariant value1, value2;

	dataValue1 = constructSPtr<OpcUaDataValue>();
	dataValue1->variant()->set((OpcUaInt32)12345);
	dataValue1->statusCode(BadNoData);
	dataValue1->sourceTimestamp(OpcUaDateTime(now));
	dataValue1->serverTimestamp(OpcUaDateTime(now));
	value1.setValue(*dataValue1);
	BOOST_REQUIRE(value1.jsonEncode(pt) == true);

	json.ptree(pt);
	json.write(std::cout);
	std::cout << std::endl;

	BOOST_REQUIRE(value2.jsonDecode(pt) == true);
	dataValue2 = value2.variantSPtr<OpcUaDataValue>();
	BOOST_REQUIRE(dataValue2->variant()->variantType() == OpcUaBuildInType_OpcUaInt32);
	BOOST_REQUIRE(dataValue2->variant()->get<OpcUaInt32>() == 12345);
	BOOST_REQUIRE(dataValue2->statusCode() == BadNoData);
	BOOST_REQUIRE(dataValue2->serverTimestamp().toISO8601() == dataValue1->serverTimestamp().toISO8601());
	BOOST_REQUIRE(dataValue2->sourceTimestamp().toISO8601() == dataValue2->sourceTimestamp().toISO8601());
}

BOOST_AUTO_TEST_CASE(JsonEncoderDecoder_Variant_DiagnosticInfo)
{
	boost::posix_time::ptime now = boost::posix_time::microsec_clock::universal_time();

	boost::property_tree::ptree pt;
	ConfigJson json;
	OpcUaDiagnosticInfo::SPtr diagnosticInfo1, diagnosticInfo2;
	OpcUaDiagnosticInfo::SPtr nested1, nested2;
	OpcUaVariant value1, value2;

	nested1 = constructSPtr<OpcUaDiagnosticInfo>();
	nested1->setSymbolicId(111);
	nested1->setNamespaceUri(111);
	nested1->setAdditionalInfo(OpcUaString("AdditionalInfo111"));

	diagnosticInfo1 = constructSPtr<OpcUaDiagnosticInfo>();
	diagnosticInfo1->setSymbolicId(123);
	diagnosticInfo1->setNamespaceUri(456);
	diagnosticInfo1->setAdditionalInfo(OpcUaString("AdditionalInfo"));
	diagnosticInfo1->diagnosticInfo(nested1);

	value1.setValue(*diagnosticInfo1);
	BOOST_REQUIRE(value1.jsonEncode(pt) == true);

	json.ptree(pt);
	json.write(std::cout);
	std::cout << std::endl;
	BOOST_REQUIRE(value2.jsonDecode(pt) == true);
	diagnosticInfo2 = value2.variantSPtr<OpcUaDiagnosticInfo>();
	BOOST_REQUIRE(diagnosticInfo2->getSymbolicId() == 123);
	BOOST_REQUIRE(diagnosticInfo2->getNamespaceUri() == 456);
	BOOST_REQUIRE(diagnosticInfo2->getAdditionalInfo() == OpcUaString("AdditionalInfo"));
	BOOST_REQUIRE(diagnosticInfo2->diagnosticInfo()->getSymbolicId() == 111);
	BOOST_REQUIRE(diagnosticInfo2->diagnosticInfo()->getNamespaceUri() == 111);
	BOOST_REQUIRE(diagnosticInfo2->diagnosticInfo()->getAdditionalInfo() == OpcUaString("AdditionalInfo111"));
}

BOOST_AUTO_TEST_CASE(JsonEncoderDecoder_OpcUaVariant_Array_OpcUaBoolean)
{
	boost::property_tree::ptree pt;
	ConfigJson json;
	OpcUaVariant value1, value2;

	for (uint32_t idx=0; idx<10; idx++) {
		value1.pushBack((OpcUaBoolean)true);
	}
	BOOST_REQUIRE(value1.jsonEncode(pt, "OpcUaVariantBooleanArray") == true);

	json.ptree(pt);
	json.write(std::cout);
	std::cout << std::endl;

	BOOST_REQUIRE(value2.jsonDecode(pt, "OpcUaVariantBooleanArray") == true);
	for (uint32_t idx=0; idx<10; idx++) {
		BOOST_REQUIRE(value2.get<OpcUaBoolean>(idx) == true);
	}
}

BOOST_AUTO_TEST_CASE(JsonEncoderDecoder_OpcUaVariant_Array_SByte)
{
	boost::property_tree::ptree pt;
	ConfigJson json;
	OpcUaVariant value1, value2;

	for (uint32_t idx=0; idx<10; idx++) {
		value1.pushBack((OpcUaSByte)-idx);
	}
	BOOST_REQUIRE(value1.jsonEncode(pt, "OpcUaVariantSByteArray") == true);

	json.ptree(pt);
	json.write(std::cout);
	std::cout << std::endl;

	BOOST_REQUIRE(value2.jsonDecode(pt, "OpcUaVariantSByteArray") == true);
	for (uint32_t idx=0; idx<10; idx++) {
		BOOST_REQUIRE(value2.get<OpcUaSByte>(idx) == -idx);
	}
}

BOOST_AUTO_TEST_CASE(JsonEncoderDecoder_OpcUaVariant_Array_Byte)
{
	boost::property_tree::ptree pt;
	ConfigJson json;
	OpcUaVariant value1, value2;

	for (uint32_t idx=0; idx<10; idx++) {
		value1.pushBack((OpcUaByte)idx);
	}
	BOOST_REQUIRE(value1.jsonEncode(pt, "OpcUaVariantByteArray") == true);

	json.ptree(pt);
	json.write(std::cout);
	std::cout << std::endl;

	BOOST_REQUIRE(value2.jsonDecode(pt, "OpcUaVariantByteArray") == true);
	for (uint32_t idx=0; idx<10; idx++) {
		BOOST_REQUIRE(value2.get<OpcUaByte>(idx) == idx);
	}
}

BOOST_AUTO_TEST_CASE(JsonEncoderDecoder_OpcUaVariant_Array_Int16)
{
	boost::property_tree::ptree pt;
	ConfigJson json;
	OpcUaVariant value1, value2;

	for (uint32_t idx=0; idx<10; idx++) {
		value1.pushBack((OpcUaInt16)-idx);
	}
	BOOST_REQUIRE(value1.jsonEncode(pt, "OpcUaVariantInt16Array") == true);

	json.ptree(pt);
	json.write(std::cout);
	std::cout << std::endl;

	BOOST_REQUIRE(value2.jsonDecode(pt, "OpcUaVariantInt16Array") == true);
	for (uint32_t idx=0; idx<10; idx++) {
		BOOST_REQUIRE(value2.get<OpcUaInt16	>(idx) == -idx);
	}
}

BOOST_AUTO_TEST_CASE(JsonEncoderDecoder_OpcUaVariant_Array_UInt16)
{
	boost::property_tree::ptree pt;
	ConfigJson json;
	OpcUaVariant value1, value2;

	for (uint32_t idx=0; idx<10; idx++) {
		value1.pushBack((OpcUaUInt16)idx);
	}
	BOOST_REQUIRE(value1.jsonEncode(pt, "OpcUaVariantUInt16Array") == true);

	json.ptree(pt);
	json.write(std::cout);
	std::cout << std::endl;

	BOOST_REQUIRE(value2.jsonDecode(pt, "OpcUaVariantUInt16Array") == true);
	for (uint32_t idx=0; idx<10; idx++) {
		BOOST_REQUIRE(value2.get<OpcUaUInt16>(idx) == idx);
	}
}

BOOST_AUTO_TEST_CASE(JsonEncoderDecoder_OpcUaVariant_Array_Int32)
{
	boost::property_tree::ptree pt;
	ConfigJson json;
	OpcUaVariant value1, value2;

	for (uint32_t idx=0; idx<10; idx++) {
		value1.pushBack((OpcUaInt32)-idx);
	}
	BOOST_REQUIRE(value1.jsonEncode(pt, "OpcUaVariantInt32Array") == true);

	json.ptree(pt);
	json.write(std::cout);
	std::cout << std::endl;

	BOOST_REQUIRE(value2.jsonDecode(pt, "OpcUaVariantInt32Array") == true);
	for (uint32_t idx=0; idx<10; idx++) {
		BOOST_REQUIRE(value2.get<OpcUaInt32>(idx) == -idx);
	}
}

BOOST_AUTO_TEST_CASE(JsonEncoderDecoder_OpcUaVariant_Array_UInt32)
{
	boost::property_tree::ptree pt;
	ConfigJson json;
	OpcUaVariant value1, value2;

	for (uint32_t idx=0; idx<10; idx++) {
		value1.pushBack((OpcUaUInt32)idx);
	}
	BOOST_REQUIRE(value1.jsonEncode(pt, "OpcUaVariantUInt32Array") == true);

	json.ptree(pt);
	json.write(std::cout);
	std::cout << std::endl;

	BOOST_REQUIRE(value2.jsonDecode(pt, "OpcUaVariantUInt32Array") == true);
	for (uint32_t idx=0; idx<10; idx++) {
		BOOST_REQUIRE(value2.get<OpcUaUInt32>(idx) == idx);
	}
}

BOOST_AUTO_TEST_CASE(JsonEncoderDecoder_OpcUaVariant_Array_Int64)
{
	boost::property_tree::ptree pt;
	ConfigJson json;
	OpcUaVariant value1, value2;

	for (uint32_t idx=0; idx<10; idx++) {
		value1.pushBack((OpcUaInt64)-idx);
	}
	BOOST_REQUIRE(value1.jsonEncode(pt, "OpcUaVariantInt64Array") == true);

	json.ptree(pt);
	json.write(std::cout);
	std::cout << std::endl;

	BOOST_REQUIRE(value2.jsonDecode(pt, "OpcUaVariantInt64Array") == true);
	for (uint32_t idx=0; idx<10; idx++) {
		BOOST_REQUIRE(value2.get<OpcUaInt64>(idx) == -idx);
	}
}

BOOST_AUTO_TEST_CASE(JsonEncoderDecoder_OpcUaVariant_Array_UInt64)
{
	boost::property_tree::ptree pt;
	ConfigJson json;
	OpcUaVariant value1, value2;

	for (uint32_t idx=0; idx<10; idx++) {
		value1.pushBack((OpcUaUInt64)idx);
	}
	BOOST_REQUIRE(value1.jsonEncode(pt, "OpcUaVariantUInt64Array") == true);

	json.ptree(pt);
	json.write(std::cout);
	std::cout << std::endl;

	BOOST_REQUIRE(value2.jsonDecode(pt, "OpcUaVariantUInt64Array") == true);
	for (uint32_t idx=0; idx<10; idx++) {
		BOOST_REQUIRE(value2.get<OpcUaUInt64>(idx) == idx);
	}
}

BOOST_AUTO_TEST_CASE(JsonEncoderDecoder_OpcUaVariant_Array_Float)
{
	boost::property_tree::ptree pt;
	ConfigJson json;
	OpcUaVariant value1, value2;

	for (uint32_t idx=0; idx<10; idx++) {
		value1.pushBack((OpcUaFloat)idx);
	}
	BOOST_REQUIRE(value1.jsonEncode(pt, "OpcUaVariantFloatArray") == true);

	json.ptree(pt);
	json.write(std::cout);
	std::cout << std::endl;

	BOOST_REQUIRE(value2.jsonDecode(pt, "OpcUaVariantFloatArray") == true);
	for (uint32_t idx=0; idx<10; idx++) {
		BOOST_REQUIRE(value2.get<OpcUaFloat>(idx) == idx);
	}
}

BOOST_AUTO_TEST_CASE(JsonEncoderDecoder_OpcUaVariant_Array_Double)
{
	boost::property_tree::ptree pt;
	ConfigJson json;
	OpcUaVariant value1, value2;

	for (uint32_t idx=0; idx<10; idx++) {
		value1.pushBack((OpcUaDouble)idx);
	}
	BOOST_REQUIRE(value1.jsonEncode(pt, "OpcUaVariantDoubleArray") == true);

	json.ptree(pt);
	json.write(std::cout);
	std::cout << std::endl;

	BOOST_REQUIRE(value2.jsonDecode(pt, "OpcUaVariantDoubleArray") == true);
	for (uint32_t idx=0; idx<10; idx++) {
		BOOST_REQUIRE(value2.get<OpcUaDouble>(idx) == idx);
	}
}

BOOST_AUTO_TEST_CASE(JsonEncoderDecoder_OpcUaVariant_Array_DateTime)
{
	boost::posix_time::ptime now = boost::posix_time::microsec_clock::universal_time();

	boost::property_tree::ptree pt;
	ConfigJson json;
	OpcUaVariant value1, value2;

	for (uint32_t idx=0; idx<10; idx++) {
		value1.pushBack(OpcUaDateTime(now));
	}
	BOOST_REQUIRE(value1.jsonEncode(pt, "OpcUaVariantDateTimeArray") == true);

	json.ptree(pt);
	json.write(std::cout);
	std::cout << std::endl;

	BOOST_REQUIRE(value2.jsonDecode(pt, "OpcUaVariantDateTimeArray") == true);
	for (uint32_t idx=0; idx<10; idx++) {
		BOOST_REQUIRE(value2.get<OpcUaDateTime>(idx).toISO8601() == value1.get<OpcUaDateTime>(idx).toISO8601());
	}
}

BOOST_AUTO_TEST_CASE(JsonEncoderDecoder_OpcUaVariant_Array_String)
{
	boost::property_tree::ptree pt;
	ConfigJson json;
	OpcUaVariant value1, value2;

	for (uint32_t idx=0; idx<10; idx++) {
		OpcUaString::SPtr string = constructSPtr<OpcUaString>();
		string->value("Das ist ein ByteString");
		value1.pushBack(string);
	}
	BOOST_REQUIRE(value1.jsonEncode(pt, "OpcUaVariantStringArray") == true);

	json.ptree(pt);
	json.write(std::cout);
	std::cout << std::endl;

	BOOST_REQUIRE(value2.jsonDecode(pt, "OpcUaVariantStringArray") == true);
	for (uint32_t idx=0; idx<10; idx++) {
		BOOST_REQUIRE(value2.getSPtr<OpcUaString>(idx)->value() == "Das ist ein ByteString");
	}
}

BOOST_AUTO_TEST_CASE(JsonEncoderDecoder_OpcUaVariant_Array_ByteString)
{
	boost::property_tree::ptree pt;
	ConfigJson json;
	OpcUaVariant value1, value2;

	for (uint32_t idx=0; idx<10; idx++) {
		OpcUaByteString::SPtr byteString = constructSPtr<OpcUaByteString>();
		byteString->value("Das ist ein ByteString");
		value1.pushBack(byteString);
	}
	BOOST_REQUIRE(value1.jsonEncode(pt, "OpcUaVariantByteArrayString") == true);

	json.ptree(pt);
	json.write(std::cout);
	std::cout << std::endl;

	BOOST_REQUIRE(value2.jsonDecode(pt, "OpcUaVariantByteArrayString") == true);
	for (uint32_t idx=0; idx<10; idx++) {
		BOOST_REQUIRE(value2.getSPtr<OpcUaByteString>(idx)->toString() == "Das ist ein ByteString");
	}
}

BOOST_AUTO_TEST_CASE(JsonEncoderDecoder_OpcUaVariant_Array_Guid)
{
	boost::property_tree::ptree pt;
	ConfigJson json;
	OpcUaVariant value1, value2;

	for (uint32_t idx=0; idx<10; idx++) {
		OpcUaGuid::SPtr guid = constructSPtr<OpcUaGuid>();
		*guid = "12345678-9ABC-DEF0-1234-56789ABCDEF0";
		value1.pushBack(guid);
	}
	BOOST_REQUIRE(value1.jsonEncode(pt, "OpcUaVariantGuidArray") == true);

	json.ptree(pt);
	json.write(std::cout);
	std::cout << std::endl;

	BOOST_REQUIRE(value2.jsonDecode(pt, "OpcUaVariantGuidArray") == true);
	for (uint32_t idx=0; idx<10; idx++) {
		BOOST_REQUIRE(value2.getSPtr<OpcUaGuid>(idx)->value() == "12345678-9ABC-DEF0-1234-56789ABCDEF0");
	}
}

BOOST_AUTO_TEST_CASE(JsonEncoderDecoder_OpcUaVariant_Array_NodeId)
{
	boost::property_tree::ptree pt;
	ConfigJson json;
	OpcUaVariant value1, value2;

	for (uint32_t idx=0; idx<10; idx++) {
		OpcUaNodeId::SPtr nodeId = constructSPtr<OpcUaNodeId>();
		nodeId->set(4711, 4712);
		value1.pushBack(nodeId);
	}
	BOOST_REQUIRE(value1.jsonEncode(pt, "OpcUaVariantNodeIdArray") == true);

	json.ptree(pt);
	json.write(std::cout);
	std::cout << std::endl;

	BOOST_REQUIRE(value2.jsonDecode(pt, "OpcUaVariantNodeIdArray") == true);
	for (uint32_t idx=0; idx<10; idx++) {
		BOOST_REQUIRE(*value2.getSPtr<OpcUaNodeId>(idx) == OpcUaNodeId(4711, 4712));
	}
}

BOOST_AUTO_TEST_CASE(JsonEncoderDecoder_OpcUaVariant_Array_ExpandedNodeId)
{
	boost::property_tree::ptree pt;
	ConfigJson json;
	OpcUaVariant value1, value2;

	for (uint32_t idx=0; idx<10; idx++) {
		OpcUaExpandedNodeId::SPtr expandedNodeId = constructSPtr<OpcUaExpandedNodeId>();
		expandedNodeId->set(4711, 4712);
		expandedNodeId->serverIndex(4713);
		value1.pushBack(expandedNodeId);
	}
	BOOST_REQUIRE(value1.jsonEncode(pt, "OpcUaVariantExpandedNodeIdArray") == true);

	json.ptree(pt);
	json.write(std::cout);
	std::cout << std::endl;

	BOOST_REQUIRE(value2.jsonDecode(pt, "OpcUaVariantExpandedNodeIdArray") == true);
	for (uint32_t idx=0; idx<10; idx++) {
		OpcUaExpandedNodeId::SPtr expandedNodeId = constructSPtr<OpcUaExpandedNodeId>();
		expandedNodeId->set(4711, 4712);
		expandedNodeId->serverIndex(4713);

		BOOST_REQUIRE(*value2.getSPtr<OpcUaExpandedNodeId>(idx) == *expandedNodeId);
	}
}

BOOST_AUTO_TEST_CASE(JsonEncoderDecoder_OpcUaVariant_Array_QualifiedName)
{
	boost::property_tree::ptree pt;
	ConfigJson json;
	OpcUaVariant value1, value2;

	for (uint32_t idx=0; idx<10; idx++) {
		OpcUaQualifiedName::SPtr qualifiedName = constructSPtr<OpcUaQualifiedName>();
		qualifiedName->set("String", 4711);
		value1.pushBack(qualifiedName);
	}
	BOOST_REQUIRE(value1.jsonEncode(pt, "OpcUaVariantQualifiedNameArray") == true);

	json.ptree(pt);
	json.write(std::cout);
	std::cout << std::endl;

	BOOST_REQUIRE(value2.jsonDecode(pt, "OpcUaVariantQualifiedNameArray") == true);
	for (uint32_t idx=0; idx<10; idx++) {
		BOOST_REQUIRE(*value2.getSPtr<OpcUaQualifiedName>(idx) == OpcUaQualifiedName("String", 4711));
	}
}

BOOST_AUTO_TEST_CASE(JsonEncoderDecoder_OpcUaVariant_Array_LocalizedText)
{
	boost::property_tree::ptree pt;
	ConfigJson json;
	OpcUaVariant value1, value2;

	for (uint32_t idx=0; idx<10; idx++) {
		OpcUaLocalizedText::SPtr localizedText = constructSPtr<OpcUaLocalizedText>();
		localizedText->set("de", "TextString");
		value1.pushBack(localizedText);
	}
	BOOST_REQUIRE(value1.jsonEncode(pt, "OpcUaVariantLocalizedTextArray") == true);

	json.ptree(pt);
	json.write(std::cout);
	std::cout << std::endl;

	BOOST_REQUIRE(value2.jsonDecode(pt, "OpcUaVariantLocalizedTextArray") == true);
	for (uint32_t idx=0; idx<10; idx++) {
		BOOST_REQUIRE(*value2.getSPtr<OpcUaLocalizedText>(idx) == OpcUaLocalizedText("de", "TextString"));
	}
}

BOOST_AUTO_TEST_CASE(JsonEncoderDecoder_OpcUaVariant_Array_ExtensionObject)
{
	boost::property_tree::ptree pt;
	ConfigJson json;
	OpcUaVariant value1, value2;

	for (uint32_t idx=0; idx<10; idx++) {
		Argument::SPtr argument;
		OpcUaExtensionObject::SPtr extentionObject = constructSPtr<OpcUaExtensionObject>();
		argument = extentionObject->parameter<Argument>(OpcUaId_Argument_Encoding_DefaultBinary);
		argument->name().value("ArgumentName");
		argument->dataType().set("NodeName", 23);
		argument->arrayDimensions().resize(3);
		argument->arrayDimensions().set(0, 123);
		argument->arrayDimensions().set(1, 456);
		argument->arrayDimensions().set(2, 789);
		argument->description().set("de", "Description");
		value1.pushBack(extentionObject);
	}
	BOOST_REQUIRE(value1.jsonEncode(pt, "OpcUaVariantExtensionObjectArray") == true);

	json.ptree(pt);
	json.write(std::cout);
	std::cout << std::endl;

	BOOST_REQUIRE(value2.jsonDecode(pt, "OpcUaVariantExtensionObjectArray") == true);
	for (uint32_t idx=0; idx<10; idx++) {
		Argument::SPtr argument;
		OpcUaExtensionObject::SPtr extentionObject2 = value2.getSPtr<OpcUaExtensionObject>(idx);
		BOOST_REQUIRE(extentionObject2->typeId().nodeId<OpcUaUInt32>() == OpcUaId_Argument_Encoding_DefaultBinary);
		argument = extentionObject2->parameter<Argument>();
		BOOST_REQUIRE(argument->name().toStdString() == "ArgumentName");
		BOOST_REQUIRE(argument->dataType() == OpcUaNodeId("NodeName", 23));
		BOOST_REQUIRE(argument->description() == OpcUaLocalizedText("de", "Description"));
	}
}

BOOST_AUTO_TEST_CASE(JsonEncoderDecoder_Variant_Array_DataValue)
{
	boost::posix_time::ptime now = boost::posix_time::microsec_clock::universal_time();

	boost::property_tree::ptree pt;
	ConfigJson json;
	OpcUaDataValue::SPtr dataValue1, dataValue2;
	OpcUaVariant value1, value2;

	for (uint32_t idx=0; idx<10; idx++) {
		dataValue1 = constructSPtr<OpcUaDataValue>();
		dataValue1->variant()->set((OpcUaInt32)12345);
		dataValue1->statusCode(BadNoData);
		dataValue1->sourceTimestamp(OpcUaDateTime(now));
		dataValue1->serverTimestamp(OpcUaDateTime(now));
		value1.pushBack(dataValue1);
	}
	BOOST_REQUIRE(value1.jsonEncode(pt) == true);

	json.ptree(pt);
	json.write(std::cout);
	std::cout << std::endl;

	BOOST_REQUIRE(value2.jsonDecode(pt) == true);

	for (uint32_t idx=0; idx<10; idx++) {
		dataValue2 = value2.variantSPtr<OpcUaDataValue>(idx);
		BOOST_REQUIRE(dataValue2->variant()->get<OpcUaInt32>() == 12345);
		BOOST_REQUIRE(dataValue2->statusCode() == BadNoData);
		BOOST_REQUIRE(dataValue2->serverTimestamp().toISO8601() == dataValue1->serverTimestamp().toISO8601());
		BOOST_REQUIRE(dataValue2->sourceTimestamp().toISO8601() == dataValue2->sourceTimestamp().toISO8601());
	}
}

BOOST_AUTO_TEST_CASE(JsonEncoderDecoder_Variant_Array_DiagnosticInfo)
{
	boost::posix_time::ptime now = boost::posix_time::microsec_clock::universal_time();

	boost::property_tree::ptree pt;
	ConfigJson json;
	OpcUaDiagnosticInfo::SPtr diagnosticInfo1, diagnosticInfo2;
	OpcUaDiagnosticInfo::SPtr nested1, nested2;
	OpcUaVariant value1, value2;

	for (uint32_t idx=0; idx<10; idx++) {
		nested1 = constructSPtr<OpcUaDiagnosticInfo>();
		nested1->setSymbolicId(111);
		nested1->setNamespaceUri(111);
		nested1->setAdditionalInfo(OpcUaString("AdditionalInfo111"));

		diagnosticInfo1 = constructSPtr<OpcUaDiagnosticInfo>();
		diagnosticInfo1->setSymbolicId(123);
		diagnosticInfo1->setNamespaceUri(456);
		diagnosticInfo1->setAdditionalInfo(OpcUaString("AdditionalInfo"));
		diagnosticInfo1->diagnosticInfo(nested1);

		value1.pushBack(diagnosticInfo1);
	}
	BOOST_REQUIRE(value1.jsonEncode(pt) == true);

	json.ptree(pt);
	json.write(std::cout);
	std::cout << std::endl;
	BOOST_REQUIRE(value2.jsonDecode(pt) == true);
	for (uint32_t idx=0; idx<10; idx++) {
		diagnosticInfo2 = value2.variantSPtr<OpcUaDiagnosticInfo>(idx);
		BOOST_REQUIRE(diagnosticInfo2->getSymbolicId() == 123);
		BOOST_REQUIRE(diagnosticInfo2->getNamespaceUri() == 456);
		BOOST_REQUIRE(diagnosticInfo2->getAdditionalInfo() == OpcUaString("AdditionalInfo"));
		BOOST_REQUIRE(diagnosticInfo2->diagnosticInfo()->getSymbolicId() == 111);
		BOOST_REQUIRE(diagnosticInfo2->diagnosticInfo()->getNamespaceUri() == 111);
		BOOST_REQUIRE(diagnosticInfo2->diagnosticInfo()->getAdditionalInfo() == OpcUaString("AdditionalInfo111"));
	}
}

BOOST_AUTO_TEST_CASE(JsonEncoderDecoder_Array_Empty)
{
	boost::property_tree::ptree pt;
	OpcUaStringArray value1, value2;

	BOOST_REQUIRE(value1.jsonEncode(pt, "Value") == true);

	std::string str;
	BOOST_REQUIRE(Json::toString(pt, str) == true);
	std::cout << str << std::endl;
	pt.clear();
	BOOST_REQUIRE(Json::fromString(str, pt) == true);

	BOOST_REQUIRE(value2.jsonDecode(pt, "Value") == true);
	BOOST_REQUIRE(value2.size() == 0);
	BOOST_REQUIRE(value2.isNull() == false);
}


BOOST_AUTO_TEST_SUITE_END()
