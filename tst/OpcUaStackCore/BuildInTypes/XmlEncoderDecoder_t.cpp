#include "unittest.h"
#include "OpcUaStackCore/Base/Utility.h"
#include "OpcUaStackCore/Base/ConfigXml.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/XmlNumber.h"
#include "OpcUaStackCore/StandardDataTypes/Argument.h"
#include <boost/iostreams/stream.hpp>

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(XmlEncoderDecoder_)

BOOST_AUTO_TEST_CASE(XmlEncoderDecoder_)
{
	std::cout << "XmlEncoderDecoder_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(XmlEncoderDecoder_Boolean)
{
	ConfigXml xml;
	boost::property_tree::ptree pt;
	OpcUaBoolean value1, value2;

	value1 = false;
	XmlNumber::xmlEncode(pt, value1);

	xml.ptree(pt);
	xml.write(std::cout);
	std::cout << std::endl;

	XmlNumber::xmlDecode(pt, value2);
	BOOST_REQUIRE(value2 == false);
}

BOOST_AUTO_TEST_CASE(XmlEncoderDecoder_Byte)
{
	ConfigXml xml;
	boost::property_tree::ptree pt;
	OpcUaByte value1, value2;

	value1 = 12;
	XmlNumber::xmlEncode(pt, value1);

	xml.ptree(pt);
	xml.write(std::cout);
	std::cout << std::endl;

	XmlNumber::xmlDecode(pt, value2);
	BOOST_REQUIRE(value2 == 12);
}

BOOST_AUTO_TEST_CASE(XmlEncoderDecoder_SByte)
{
	ConfigXml xml;
	boost::property_tree::ptree pt;
	OpcUaSByte value1, value2;

	value1 = -12;
	XmlNumber::xmlEncode(pt, value1);

	xml.ptree(pt);
	xml.write(std::cout);
	std::cout << std::endl;

	XmlNumber::xmlDecode(pt, value2);
	BOOST_REQUIRE(value2 == -12);
}

BOOST_AUTO_TEST_CASE(XmlEncoderDecoder_UInt16)
{
	ConfigXml xml;
	boost::property_tree::ptree pt;
	OpcUaUInt16 value1, value2;

	value1 = 123;
	XmlNumber::xmlEncode(pt, value1);

	xml.ptree(pt);
	xml.write(std::cout);
	std::cout << std::endl;

	XmlNumber::xmlDecode(pt, value2);
	BOOST_REQUIRE(value2 == 123);
}

BOOST_AUTO_TEST_CASE(XmlEncoderDecoder_Int16)
{
	ConfigXml xml;
	boost::property_tree::ptree pt;
	OpcUaInt16 value1, value2;

	value1 = -123;
	XmlNumber::xmlEncode(pt, value1);

	xml.ptree(pt);
	xml.write(std::cout);
	std::cout << std::endl;

	XmlNumber::xmlDecode(pt, value2);
	BOOST_REQUIRE(value2 == -123);
}

BOOST_AUTO_TEST_CASE(XmlEncoderDecoder_UInt32)
{
	ConfigXml xml;
	boost::property_tree::ptree pt;
	OpcUaUInt32 value1, value2;

	value1 = 1234;
	XmlNumber::xmlEncode(pt, value1);

	xml.ptree(pt);
	xml.write(std::cout);
	std::cout << std::endl;

	XmlNumber::xmlDecode(pt, value2);
	BOOST_REQUIRE(value2 == 1234);
}

BOOST_AUTO_TEST_CASE(XmlEncoderDecoder_Int32)
{
	ConfigXml xml;
	boost::property_tree::ptree pt;
	OpcUaInt32 value1, value2;

	value1 = -1234;
	XmlNumber::xmlEncode(pt, value1);

	xml.ptree(pt);
	xml.write(std::cout);
	std::cout << std::endl;

	XmlNumber::xmlDecode(pt, value2);
	BOOST_REQUIRE(value2 == -1234);
}

BOOST_AUTO_TEST_CASE(XmlEncoderDecoder_UInt64)
{
	ConfigXml xml;
	boost::property_tree::ptree pt;
	OpcUaUInt64 value1, value2;

	value1 = 12345;
	XmlNumber::xmlEncode(pt, value1);

	xml.ptree(pt);
	xml.write(std::cout);
	std::cout << std::endl;

	XmlNumber::xmlDecode(pt, value2);
	BOOST_REQUIRE(value2 == 12345);
}

BOOST_AUTO_TEST_CASE(XmlEncoderDecoder_Int64)
{
	ConfigXml xml;
	boost::property_tree::ptree pt;
	OpcUaInt64 value1, value2;

	value1 = -12345;
	XmlNumber::xmlEncode(pt, value1);

	xml.ptree(pt);
	xml.write(std::cout);
	std::cout << std::endl;

	XmlNumber::xmlDecode(pt, value2);
	BOOST_REQUIRE(value2 == -12345);
}

BOOST_AUTO_TEST_CASE(XmlEncoderDecoder_Float)
{
	ConfigXml xml;
	boost::property_tree::ptree pt;
	OpcUaFloat value1, value2;

	value1 = 12.34;
	XmlNumber::xmlEncode(pt, value1);

	xml.ptree(pt);
	xml.write(std::cout);
	std::cout << std::endl;

	XmlNumber::xmlDecode(pt, value2);
	BOOST_REQUIRE(value2 > 12.33 && value2 < 12.35);
}

BOOST_AUTO_TEST_CASE(XmlEncoderDecoder_Double)
{
	ConfigXml xml;
	boost::property_tree::ptree pt;
	OpcUaDouble value1, value2;

	value1 = 12.34;
	XmlNumber::xmlEncode(pt, value1);

	xml.ptree(pt);
	xml.write(std::cout);
	std::cout << std::endl;

	XmlNumber::xmlDecode(pt, value2);
	BOOST_REQUIRE(value2 > 12.33 && value2 < 12.35);
}

BOOST_AUTO_TEST_CASE(XmlEncoderDecoder_OpcUaString)
{
	Xmlns xmlns;
	ConfigXml xml;
	boost::property_tree::ptree pt;
	OpcUaString value1, value2;

	value1.value("Dies ist ein String");
	value1.xmlEncode(pt, xmlns);

	xml.ptree(pt);
	xml.write(std::cout);
	std::cout << std::endl;

	value2.xmlDecode(pt, xmlns);
	BOOST_REQUIRE(value2.value() == std::string("Dies ist ein String"));
}

BOOST_AUTO_TEST_CASE(XmlEncoderDecoder_OpcUaDataTime)
{
	boost::posix_time::ptime now = boost::posix_time::microsec_clock::universal_time();

	Xmlns xmlns;
	ConfigXml xml;
	boost::property_tree::ptree pt;
	OpcUaDateTime value1, value2;

	value1.dateTime(now);
	value1.xmlEncode(pt, xmlns);

	xml.ptree(pt);
	xml.write(std::cout);
	std::cout << std::endl;

	value2.xmlDecode(pt, xmlns);
	BOOST_REQUIRE(value1.toISO8601() == value2.toISO8601());
}

BOOST_AUTO_TEST_CASE(XmlEncoderDecoder_OpcUaGuid)
{
	Xmlns xmlns;
	ConfigXml xml;
	boost::property_tree::ptree pt;
	OpcUaGuid value1, value2;

	value1 = "12345678-9ABC-DEF0-1234-56789ABCDEF0";
	value1.xmlEncode(pt, xmlns);

	xml.ptree(pt);
	xml.write(std::cout);
	std::cout << std::endl;

	value2.xmlDecode(pt, xmlns);
	std::string str = value2;
	BOOST_REQUIRE(str == "12345678-9ABC-DEF0-1234-56789ABCDEF0");
}

BOOST_AUTO_TEST_CASE(XmlEncoderDecoder_OpcUaByteString)
{
	std::string str = "Dies ist ein ByteString";
	boost::property_tree::ptree pt;
	Xmlns xmlns;
	ConfigXml xml;
	OpcUaByteString value2;

	OpcUaByteString value1;
	value1.value(str);
	value1.xmlEncode(pt, xmlns);

	xml.ptree(pt);
	xml.write(std::cout);
	std::cout << std::endl;

	value2.xmlDecode(pt, xmlns);
	BOOST_REQUIRE(value2.toString() == str);
}

BOOST_AUTO_TEST_CASE(XmlEncoderDecoder_OpcUaNodeId)
{
	boost::property_tree::ptree pt;
	Xmlns xmlns;
	ConfigXml xml;
	OpcUaNodeId value1, value2;

	value1.set("NodeName", 123);
	value1.xmlEncode(pt, xmlns);

	xml.ptree(pt);
	xml.write(std::cout);
	std::cout << std::endl;

	value2.xmlDecode(pt, xmlns);
	BOOST_REQUIRE(value2 == OpcUaNodeId("NodeName", 123));
}

BOOST_AUTO_TEST_CASE(XmlEncoderDecoder_OpcUaExpandedNodeId)
{
	boost::property_tree::ptree pt;
	Xmlns xmlns;
	ConfigXml xml;
	OpcUaExpandedNodeId value1, value2;

	value1.fromString("svr=4711;ns=1;s=NodeName");
	value1.xmlEncode(pt, xmlns);

	xml.ptree(pt);
	xml.write(std::cout);
	std::cout << std::endl;

	value2.xmlDecode(pt, xmlns);
	BOOST_REQUIRE(value2.toString() == "svr=4711;ns=1;s=NodeName");
}

BOOST_AUTO_TEST_CASE(XmlEncoderDecoder_QualifiedName)
{
	boost::property_tree::ptree pt;
	Xmlns xmlns;
	ConfigXml xml;
	OpcUaQualifiedName value1, value2;

	value1.namespaceIndex(123);
	value1.name("Name");
	value1.xmlEncode(pt, xmlns);

	xml.ptree(pt);
	xml.write(std::cout);
	std::cout << std::endl;

	value2.xmlDecode(pt, xmlns);
	BOOST_REQUIRE(value2.namespaceIndex() == 123);
	BOOST_REQUIRE(value2.name().toStdString() == "Name");
}

BOOST_AUTO_TEST_CASE(XmlEncoderDecoder_LocalizedText)
{
	boost::property_tree::ptree pt;
	Xmlns xmlns;
	ConfigXml xml;
	OpcUaLocalizedText value1, value2;

	value1.locale("de");
	value1.text("Text");
	value1.xmlEncode(pt, xmlns);

	xml.ptree(pt);
	xml.write(std::cout);
	std::cout << std::endl;

	value2.xmlDecode(pt, xmlns);
	BOOST_REQUIRE(value2.locale().toStdString() == "de");
	BOOST_REQUIRE(value2.text().toStdString() == "Text");
}

BOOST_AUTO_TEST_CASE(XmlEncoderDecoder_ExtensionObject)
{
	OpcUaExtensionObject eo;
	eo.registerFactoryElement<Argument>(OpcUaId_Argument_Encoding_DefaultBinary);
	eo.registerFactoryElement<Argument>(OpcUaId_Argument_Encoding_DefaultXml);

	Argument::SPtr argument1, argument2;
	boost::property_tree::ptree pt;
	Xmlns xmlns;
	ConfigXml xml;
	OpcUaExtensionObject value1, value2;

	argument1 = value1.parameter<Argument>(OpcUaId_Argument_Encoding_DefaultBinary);
	argument1->name().value("ArgumentName");
	argument1->dataType().set("NodeName", 23);
	argument1->arrayDimensions().resize(3);
	argument1->arrayDimensions().set(0, 123);
	argument1->arrayDimensions().set(1, 456);
	argument1->arrayDimensions().set(2, 789);
	argument1->description().set("de", "Description");
	BOOST_REQUIRE(value1.xmlEncode(pt, xmlns) == true);

	xml.ptree(pt);
	xml.write(std::cout);
	std::cout << std::endl;

	BOOST_REQUIRE(value2.xmlDecode(pt, xmlns) == true);
	BOOST_REQUIRE(value2.typeId().nodeId<OpcUaUInt32>() == OpcUaId_Argument_Encoding_DefaultBinary);
	argument2 = value2.parameter<Argument>();
	BOOST_REQUIRE(argument2->name().toStdString() == "ArgumentName");
	BOOST_REQUIRE(argument2->dataType() == OpcUaNodeId("NodeName", 23));
	BOOST_REQUIRE(argument2->description() == OpcUaLocalizedText("de", "Description"));
}

BOOST_AUTO_TEST_CASE(XmlEncoderDecoder_DataValue)
{
	boost::posix_time::ptime now = boost::posix_time::microsec_clock::universal_time();

	boost::property_tree::ptree pt;
	Xmlns xmlns;
	ConfigXml xml;
	OpcUaDataValue value1, value2;

	value1.variant()->set((OpcUaInt32)12345);
	value1.statusCode(BadNoData);
	value1.sourceTimestamp(OpcUaDateTime(now));
	value1.serverTimestamp(OpcUaDateTime(now));
	BOOST_REQUIRE(value1.xmlEncode(pt, xmlns) == true);

	xml.ptree(pt);
	xml.write(std::cout);
	std::cout << std::endl;
	BOOST_REQUIRE(value2.xmlDecode(pt, xmlns) == true);
	BOOST_REQUIRE(value2.variant()->get<OpcUaInt32>() == 12345);
	BOOST_REQUIRE(value2.serverTimestamp().toISO8601() == value1.serverTimestamp().toISO8601());
	BOOST_REQUIRE(value2.sourceTimestamp().toISO8601() == value2.sourceTimestamp().toISO8601());
}

BOOST_AUTO_TEST_CASE(XmlEncoderDecoder_DiagnosticInfo)
{
	boost::posix_time::ptime now = boost::posix_time::microsec_clock::universal_time();

	boost::property_tree::ptree pt;
	Xmlns xmlns;
	ConfigXml xml;
	OpcUaDiagnosticInfo value1, value2;

	value1.setSymbolicId(123);
	value1.setNamespaceUri(456);
	value1.setAdditionalInfo(OpcUaString("AdditionalInfo"));
	BOOST_REQUIRE(value1.xmlEncode(pt, xmlns) == true);

	xml.ptree(pt);
	xml.write(std::cout);
	std::cout << std::endl;
	BOOST_REQUIRE(value2.xmlDecode(pt, xmlns) == true);
	BOOST_REQUIRE(value2.getSymbolicId() == 123);
	BOOST_REQUIRE(value2.getNamespaceUri() == 456);
	BOOST_REQUIRE(value2.getAdditionalInfo() == OpcUaString("AdditionalInfo"));
}

BOOST_AUTO_TEST_CASE(XmlEncoderDecoder_DiagnosticInfo_nested)
{
	boost::posix_time::ptime now = boost::posix_time::microsec_clock::universal_time();

	boost::property_tree::ptree pt;
	Xmlns xmlns;
	ConfigXml xml;
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
	BOOST_REQUIRE(value1.xmlEncode(pt, xmlns) == true);

	xml.ptree(pt);
	xml.write(std::cout);
	std::cout << std::endl;
	BOOST_REQUIRE(value2.xmlDecode(pt, xmlns) == true);
	BOOST_REQUIRE(value2.getSymbolicId() == 123);
	BOOST_REQUIRE(value2.getNamespaceUri() == 456);
	BOOST_REQUIRE(value2.getAdditionalInfo() == OpcUaString("AdditionalInfo"));
	BOOST_REQUIRE(value2.diagnosticInfo()->getSymbolicId() == 111);
	BOOST_REQUIRE(value2.diagnosticInfo()->getNamespaceUri() == 111);
	BOOST_REQUIRE(value2.diagnosticInfo()->getAdditionalInfo() == OpcUaString("AdditionalInfo111"));
}

BOOST_AUTO_TEST_CASE(XmlEncoderDecoder_OpcUaVariant_OpcUaBoolean)
{
	boost::property_tree::ptree pt;
	Xmlns xmlns;
	ConfigXml xml;
	OpcUaVariant value1, value2;

	value1.set((OpcUaBoolean)true);
	BOOST_REQUIRE(value1.xmlEncode(pt, xmlns) == true);

	xml.ptree(pt);
	xml.write(std::cout);
	std::cout << std::endl;

	BOOST_REQUIRE(value2.xmlDecode(pt, xmlns) == true);
	BOOST_REQUIRE(value2.get<OpcUaBoolean>() == true);
}

BOOST_AUTO_TEST_CASE(XmlEncoderDecoder_OpcUaVariant_SByte)
{
	boost::property_tree::ptree pt;
	Xmlns xmlns;
	ConfigXml xml;
	OpcUaVariant value1, value2;

	value1.set((OpcUaSByte)-12);
	BOOST_REQUIRE(value1.xmlEncode(pt, xmlns) == true);

	xml.ptree(pt);
	xml.write(std::cout);
	std::cout << std::endl;

	BOOST_REQUIRE(value2.xmlDecode(pt, xmlns) == true);
	BOOST_REQUIRE(value2.get<OpcUaSByte>() == -12);
}

BOOST_AUTO_TEST_CASE(XmlEncoderDecoder_OpcUaVariant_Byte)
{
	boost::property_tree::ptree pt;
	Xmlns xmlns;
	ConfigXml xml;
	OpcUaVariant value1, value2;

	value1.set((OpcUaByte)12);
	BOOST_REQUIRE(value1.xmlEncode(pt, xmlns) == true);

	xml.ptree(pt);
	xml.write(std::cout);
	std::cout << std::endl;

	BOOST_REQUIRE(value2.xmlDecode(pt, xmlns) == true);
	BOOST_REQUIRE(value2.get<OpcUaByte>() == 12);
}

BOOST_AUTO_TEST_CASE(XmlEncoderDecoder_OpcUaVariant_Int16)
{
	boost::property_tree::ptree pt;
	Xmlns xmlns;
	ConfigXml xml;
	OpcUaVariant value1, value2;

	value1.set((OpcUaInt16)-123);
	BOOST_REQUIRE(value1.xmlEncode(pt, xmlns) == true);

	xml.ptree(pt);
	xml.write(std::cout);
	std::cout << std::endl;

	BOOST_REQUIRE(value2.xmlDecode(pt, xmlns) == true);
	BOOST_REQUIRE(value2.get<OpcUaInt16>() == -123);
}

BOOST_AUTO_TEST_CASE(XmlEncoderDecoder_OpcUaVariant_UInt16)
{
	boost::property_tree::ptree pt;
	Xmlns xmlns;
	ConfigXml xml;
	OpcUaVariant value1, value2;

	value1.set((OpcUaUInt16)1234);
	BOOST_REQUIRE(value1.xmlEncode(pt, xmlns) == true);

	xml.ptree(pt);
	xml.write(std::cout);
	std::cout << std::endl;

	BOOST_REQUIRE(value2.xmlDecode(pt, xmlns) == true);
	BOOST_REQUIRE(value2.get<OpcUaUInt16>() == 1234);
}

BOOST_AUTO_TEST_CASE(XmlEncoderDecoder_OpcUaVariant_Int32)
{
	boost::property_tree::ptree pt;
	Xmlns xmlns;
	ConfigXml xml;
	OpcUaVariant value1, value2;

	value1.set((OpcUaInt32)-1234);
	BOOST_REQUIRE(value1.xmlEncode(pt, xmlns) == true);

	xml.ptree(pt);
	xml.write(std::cout);
	std::cout << std::endl;

	BOOST_REQUIRE(value2.xmlDecode(pt, xmlns) == true);
	BOOST_REQUIRE(value2.get<OpcUaInt32>() == -1234);
}

BOOST_AUTO_TEST_CASE(XmlEncoderDecoder_OpcUaVariant_UInt32)
{
	boost::property_tree::ptree pt;
	Xmlns xmlns;
	ConfigXml xml;
	OpcUaVariant value1, value2;

	value1.set((OpcUaUInt32)12345);
	BOOST_REQUIRE(value1.xmlEncode(pt, xmlns) == true);

	xml.ptree(pt);
	xml.write(std::cout);
	std::cout << std::endl;

	BOOST_REQUIRE(value2.xmlDecode(pt, xmlns) == true);
	BOOST_REQUIRE(value2.get<OpcUaUInt32>() == 12345);
}

BOOST_AUTO_TEST_CASE(XmlEncoderDecoder_OpcUaVariant_Int64)
{
	boost::property_tree::ptree pt;
	Xmlns xmlns;
	ConfigXml xml;
	OpcUaVariant value1, value2;

	value1.set((OpcUaInt64)-12345);
	BOOST_REQUIRE(value1.xmlEncode(pt, xmlns) == true);

	xml.ptree(pt);
	xml.write(std::cout);
	std::cout << std::endl;

	BOOST_REQUIRE(value2.xmlDecode(pt, xmlns) == true);
	BOOST_REQUIRE(value2.get<OpcUaInt64>() == -12345);
}

BOOST_AUTO_TEST_CASE(XmlEncoderDecoder_OpcUaVariant_UInt64)
{
	boost::property_tree::ptree pt;
	Xmlns xmlns;
	ConfigXml xml;
	OpcUaVariant value1, value2;

	value1.set((OpcUaUInt64)123456);
	BOOST_REQUIRE(value1.xmlEncode(pt, xmlns) == true);

	xml.ptree(pt);
	xml.write(std::cout);
	std::cout << std::endl;

	BOOST_REQUIRE(value2.xmlDecode(pt, xmlns) == true);
	BOOST_REQUIRE(value2.get<OpcUaUInt64>() == 123456);
}

BOOST_AUTO_TEST_CASE(XmlEncoderDecoder_OpcUaVariant_Float)
{
	boost::property_tree::ptree pt;
	Xmlns xmlns;
	ConfigXml xml;
	OpcUaVariant value1, value2;

	value1.set((OpcUaFloat)1.2);
	BOOST_REQUIRE(value1.xmlEncode(pt, xmlns) == true);

	xml.ptree(pt);
	xml.write(std::cout);
	std::cout << std::endl;

	BOOST_REQUIRE(value2.xmlDecode(pt, xmlns) == true);
	OpcUaFloat v = value2.get<OpcUaFloat>();
	BOOST_REQUIRE(v > 1.1 && v < 1.3);
}

BOOST_AUTO_TEST_CASE(XmlEncoderDecoder_OpcUaVariant_Double)
{
	boost::property_tree::ptree pt;
	Xmlns xmlns;
	ConfigXml xml;
	OpcUaVariant value1, value2;

	value1.set((OpcUaDouble)1.2);
	BOOST_REQUIRE(value1.xmlEncode(pt, xmlns) == true);

	xml.ptree(pt);
	xml.write(std::cout);
	std::cout << std::endl;

	BOOST_REQUIRE(value2.xmlDecode(pt, xmlns) == true);
	OpcUaDouble v = value2.get<OpcUaDouble>();
	BOOST_REQUIRE(v > 1.1 && v < 1.3);
}

BOOST_AUTO_TEST_CASE(XmlEncoderDecoder_OpcUaVariant_DateTime)
{
	boost::posix_time::ptime now = boost::posix_time::microsec_clock::universal_time();

	boost::property_tree::ptree pt;
	Xmlns xmlns;
	ConfigXml xml;
	OpcUaVariant value1, value2;

	value1.set(OpcUaDateTime(now));
	BOOST_REQUIRE(value1.xmlEncode(pt, xmlns) == true);

	xml.ptree(pt);
	xml.write(std::cout);
	std::cout << std::endl;

	BOOST_REQUIRE(value2.xmlDecode(pt, xmlns) == true);
	BOOST_REQUIRE(value2.get<OpcUaDateTime>().toISO8601() == value1.get<OpcUaDateTime>().toISO8601());
}

BOOST_AUTO_TEST_CASE(XmlEncoderDecoder_OpcUaVariant_ByteString)
{
	boost::property_tree::ptree pt;
	Xmlns xmlns;
	ConfigXml xml;
	OpcUaVariant value1, value2;

	OpcUaByteString::SPtr byteString1 = constructSPtr<OpcUaByteString>();
	byteString1->value("Das ist ein ByteString xxxx");
	value1.variant(byteString1);
	BOOST_REQUIRE(value1.xmlEncode(pt, xmlns) == true);

	xml.ptree(pt);
	xml.write(std::cout);
	std::cout << std::endl;

	BOOST_REQUIRE(value2.xmlDecode(pt, xmlns) == true);
	OpcUaByteString::SPtr byteString2 = value2.variantSPtr<OpcUaByteString>();
	BOOST_REQUIRE(byteString2->toString() == "Das ist ein ByteString xxxx");
}

BOOST_AUTO_TEST_CASE(XmlEncoderDecoder_OpcUaVariant_Guid)
{
	boost::property_tree::ptree pt;
	Xmlns xmlns;
	ConfigXml xml;
	OpcUaVariant value1, value2;

	OpcUaGuid::SPtr guid1 = constructSPtr<OpcUaGuid>();
	*guid1 = "12345678-9ABC-DEF0-1234-56789ABCDEF0";
	value1.variant(guid1);
	BOOST_REQUIRE(value1.xmlEncode(pt, xmlns) == true);

	xml.ptree(pt);
	xml.write(std::cout);
	std::cout << std::endl;

	BOOST_REQUIRE(value2.xmlDecode(pt, xmlns) == true);
	OpcUaGuid::SPtr guid2 = value2.variantSPtr<OpcUaGuid>();
	std::string str = *guid2;
	BOOST_REQUIRE(str == "12345678-9ABC-DEF0-1234-56789ABCDEF0");
}

BOOST_AUTO_TEST_CASE(XmlEncoderDecoder_OpcUaVariant_NodeId)
{
	boost::property_tree::ptree pt;
	Xmlns xmlns;
	ConfigXml xml;
	OpcUaVariant value1, value2;

	OpcUaNodeId::SPtr nodeId1 = constructSPtr<OpcUaNodeId>();
	nodeId1->set(4711,4712);
	value1.variant(nodeId1);
	BOOST_REQUIRE(value1.xmlEncode(pt, xmlns) == true);

	xml.ptree(pt);
	xml.write(std::cout);
	std::cout << std::endl;

	BOOST_REQUIRE(value2.xmlDecode(pt, xmlns) == true);
	OpcUaNodeId::SPtr nodeId2 = value2.variantSPtr<OpcUaNodeId>();
	BOOST_REQUIRE(*nodeId2 == OpcUaNodeId(4711,4712));
}

BOOST_AUTO_TEST_CASE(XmlEncoderDecoder_OpcUaVariant_ExpandedNodeId)
{
	boost::property_tree::ptree pt;
	Xmlns xmlns;
	ConfigXml xml;
	OpcUaVariant value1, value2;

	OpcUaExpandedNodeId::SPtr expandedNodeId1 = constructSPtr<OpcUaExpandedNodeId>();
	expandedNodeId1->set(4711, 4712);
	expandedNodeId1->serverIndex(4713);
	value1.variant(expandedNodeId1);
	BOOST_REQUIRE(value1.xmlEncode(pt, xmlns) == true);

	xml.ptree(pt);
	xml.write(std::cout);
	std::cout << std::endl;

	BOOST_REQUIRE(value2.xmlDecode(pt, xmlns) == true);
	OpcUaExpandedNodeId::SPtr expandedNodeId2 = value2.variantSPtr<OpcUaExpandedNodeId>();
	BOOST_REQUIRE(expandedNodeId2->namespaceIndex() == 4712);
	BOOST_REQUIRE(expandedNodeId2->serverIndex() == 4713);
}

BOOST_AUTO_TEST_CASE(XmlEncoderDecoder_OpcUaVariant_QualifiedName)
{
	boost::property_tree::ptree pt;
	Xmlns xmlns;
	ConfigXml xml;
	OpcUaVariant value1, value2;

	OpcUaQualifiedName::SPtr qualifiedName1 = constructSPtr<OpcUaQualifiedName>();
	qualifiedName1->set("Name", 4712);
	value1.variant(qualifiedName1);
	BOOST_REQUIRE(value1.xmlEncode(pt, xmlns) == true);

	xml.ptree(pt);
	xml.write(std::cout);
	std::cout << std::endl;

	BOOST_REQUIRE(value2.xmlDecode(pt, xmlns) == true);
	OpcUaQualifiedName::SPtr qualifiedName2 = value2.variantSPtr<OpcUaQualifiedName>();
	BOOST_REQUIRE(*qualifiedName2 == OpcUaQualifiedName("Name", 4712));
}

BOOST_AUTO_TEST_CASE(XmlEncoderDecoder_OpcUaVariant_LocalizedText)
{
	boost::property_tree::ptree pt;
	Xmlns xmlns;
	ConfigXml xml;
	OpcUaVariant value1, value2;

	OpcUaLocalizedText::SPtr localizedText1 = constructSPtr<OpcUaLocalizedText>();
	localizedText1->set("de", "Name");
	value1.variant(localizedText1);
	BOOST_REQUIRE(value1.xmlEncode(pt, xmlns) == true);

	xml.ptree(pt);
	xml.write(std::cout);
	std::cout << std::endl;

	BOOST_REQUIRE(value2.xmlDecode(pt, xmlns) == true);
	OpcUaLocalizedText::SPtr localizedText2 = value2.variantSPtr<OpcUaLocalizedText>();
	BOOST_REQUIRE(*localizedText2 == OpcUaLocalizedText("de", "Name"));
}

BOOST_AUTO_TEST_CASE(XmlEncoderDecoder_OpcUaVariant_ExtensionObject)
{
	OpcUaExtensionObject eo;
	eo.registerFactoryElement<Argument>(OpcUaId_Argument_Encoding_DefaultBinary);
	eo.registerFactoryElement<Argument>(OpcUaId_Argument_Encoding_DefaultXml);

	boost::property_tree::ptree pt;
	Xmlns xmlns;
	ConfigXml xml;
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
	BOOST_REQUIRE(value1.xmlEncode(pt, xmlns) == true);

	xml.ptree(pt);
	xml.write(std::cout);
	std::cout << std::endl;

	BOOST_REQUIRE(value2.xmlDecode(pt, xmlns) == true);
	OpcUaExtensionObject::SPtr extentionObject2 = value2.variantSPtr<OpcUaExtensionObject>();
	BOOST_REQUIRE(extentionObject2->typeId().nodeId<OpcUaUInt32>() == OpcUaId_Argument_Encoding_DefaultBinary);
	argument2 = extentionObject2->parameter<Argument>();
	BOOST_REQUIRE(argument2->name().toStdString() == "ArgumentName");
	BOOST_REQUIRE(argument2->dataType() == OpcUaNodeId("NodeName", 23));
	BOOST_REQUIRE(argument2->description() == OpcUaLocalizedText("de", "Description"));
}

BOOST_AUTO_TEST_CASE(XmlEncoderDecoder_Variant_DataValue)
{
	boost::posix_time::ptime now = boost::posix_time::microsec_clock::universal_time();

	boost::property_tree::ptree pt;
	Xmlns xmlns;
	ConfigXml xml;
	OpcUaDataValue::SPtr dataValue1, dataValue2;
	OpcUaVariant value1, value2;

	dataValue1 = constructSPtr<OpcUaDataValue>();
	dataValue1->variant()->set((OpcUaInt32)12345);
	dataValue1->statusCode(BadNoData);
	dataValue1->sourceTimestamp(OpcUaDateTime(now));
	dataValue1->serverTimestamp(OpcUaDateTime(now));
	value1.setValue(*dataValue1);
	BOOST_REQUIRE(value1.xmlEncode(pt, xmlns) == true);

	xml.ptree(pt);
	xml.write(std::cout);
	std::cout << std::endl;
	BOOST_REQUIRE(value2.xmlDecode(pt, xmlns) == true);
	dataValue2 = value2.variantSPtr<OpcUaDataValue>();
	BOOST_REQUIRE(dataValue2->variant()->get<OpcUaInt32>() == 12345);
	BOOST_REQUIRE(dataValue2->statusCode() == BadNoData);
	BOOST_REQUIRE(dataValue2->serverTimestamp().toISO8601() == dataValue1->serverTimestamp().toISO8601());
	BOOST_REQUIRE(dataValue2->sourceTimestamp().toISO8601() == dataValue2->sourceTimestamp().toISO8601());
}

BOOST_AUTO_TEST_CASE(XmlEncoderDecoder_Variant_DiagnosticInfo)
{
	boost::posix_time::ptime now = boost::posix_time::microsec_clock::universal_time();

	boost::property_tree::ptree pt;
	Xmlns xmlns;
	ConfigXml xml;
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
	BOOST_REQUIRE(value1.xmlEncode(pt, xmlns) == true);

	xml.ptree(pt);
	xml.write(std::cout);
	std::cout << std::endl;
	BOOST_REQUIRE(value2.xmlDecode(pt, xmlns) == true);
	diagnosticInfo2 = value2.variantSPtr<OpcUaDiagnosticInfo>();
	BOOST_REQUIRE(diagnosticInfo2->getSymbolicId() == 123);
	BOOST_REQUIRE(diagnosticInfo2->getNamespaceUri() == 456);
	BOOST_REQUIRE(diagnosticInfo2->getAdditionalInfo() == OpcUaString("AdditionalInfo"));
	BOOST_REQUIRE(diagnosticInfo2->diagnosticInfo()->getSymbolicId() == 111);
	BOOST_REQUIRE(diagnosticInfo2->diagnosticInfo()->getNamespaceUri() == 111);
	BOOST_REQUIRE(diagnosticInfo2->diagnosticInfo()->getAdditionalInfo() == OpcUaString("AdditionalInfo111"));
}

BOOST_AUTO_TEST_CASE(XmlEncoderDecoder_OpcUaVariant_Array_OpcUaBoolean)
{
	boost::property_tree::ptree pt;
	Xmlns xmlns;
	ConfigXml xml;
	OpcUaVariant value1, value2;

	for (uint32_t idx=0; idx<10; idx++) {
		value1.pushBack((OpcUaBoolean)true);
	}
	BOOST_REQUIRE(value1.xmlEncode(pt, xmlns) == true);

	xml.ptree(pt);
	xml.write(std::cout);
	std::cout << std::endl;

	BOOST_REQUIRE(value2.xmlDecode(pt, xmlns) == true);
	for (uint32_t idx=0; idx<10; idx++) {
		BOOST_REQUIRE(value2.get<OpcUaBoolean>(idx) == true);
	}
}

BOOST_AUTO_TEST_CASE(XmlEncoderDecoder_OpcUaVariant_Array_SByte)
{
	boost::property_tree::ptree pt;
	Xmlns xmlns;
	ConfigXml xml;
	OpcUaVariant value1, value2;

	for (uint32_t idx=0; idx<10; idx++) {
		value1.pushBack((OpcUaSByte)-idx);
	}
	BOOST_REQUIRE(value1.xmlEncode(pt, xmlns) == true);

	xml.ptree(pt);
	xml.write(std::cout);
	std::cout << std::endl;

	BOOST_REQUIRE(value2.xmlDecode(pt, xmlns) == true);
	for (uint32_t idx=0; idx<10; idx++) {
		BOOST_REQUIRE(value2.get<OpcUaSByte>(idx) == -idx);
	}
}

BOOST_AUTO_TEST_CASE(XmlEncoderDecoder_OpcUaVariant_Array_Byte)
{
	boost::property_tree::ptree pt;
	Xmlns xmlns;
	ConfigXml xml;
	OpcUaVariant value1, value2;

	for (uint32_t idx=0; idx<10; idx++) {
		value1.pushBack((OpcUaByte)idx);
	}
	BOOST_REQUIRE(value1.xmlEncode(pt, xmlns) == true);

	xml.ptree(pt);
	xml.write(std::cout);
	std::cout << std::endl;

	BOOST_REQUIRE(value2.xmlDecode(pt, xmlns) == true);
	for (uint32_t idx=0; idx<10; idx++) {
		BOOST_REQUIRE(value2.get<OpcUaByte>(idx) == idx);
	}
}

BOOST_AUTO_TEST_CASE(XmlEncoderDecoder_OpcUaVariant_Array_Int16)
{
	boost::property_tree::ptree pt;
	Xmlns xmlns;
	ConfigXml xml;
	OpcUaVariant value1, value2;

	for (uint32_t idx=0; idx<10; idx++) {
		value1.pushBack((OpcUaInt16)-idx);
	}
	BOOST_REQUIRE(value1.xmlEncode(pt, xmlns) == true);

	xml.ptree(pt);
	xml.write(std::cout);
	std::cout << std::endl;

	BOOST_REQUIRE(value2.xmlDecode(pt, xmlns) == true);
	for (uint32_t idx=0; idx<10; idx++) {
		BOOST_REQUIRE(value2.get<OpcUaInt16	>(idx) == -idx);
	}
}

BOOST_AUTO_TEST_CASE(XmlEncoderDecoder_OpcUaVariant_Array_UInt16)
{
	boost::property_tree::ptree pt;
	Xmlns xmlns;
	ConfigXml xml;
	OpcUaVariant value1, value2;

	for (uint32_t idx=0; idx<10; idx++) {
		value1.pushBack((OpcUaUInt16)idx);
	}
	BOOST_REQUIRE(value1.xmlEncode(pt, xmlns) == true);

	xml.ptree(pt);
	xml.write(std::cout);
	std::cout << std::endl;

	BOOST_REQUIRE(value2.xmlDecode(pt, xmlns) == true);
	for (uint32_t idx=0; idx<10; idx++) {
		BOOST_REQUIRE(value2.get<OpcUaUInt16>(idx) == idx);
	}
}

BOOST_AUTO_TEST_CASE(XmlEncoderDecoder_OpcUaVariant_Array_Int32)
{
	boost::property_tree::ptree pt;
	Xmlns xmlns;
	ConfigXml xml;
	OpcUaVariant value1, value2;

	for (uint32_t idx=0; idx<10; idx++) {
		value1.pushBack((OpcUaInt32)-idx);
	}
	BOOST_REQUIRE(value1.xmlEncode(pt, xmlns) == true);

	xml.ptree(pt);
	xml.write(std::cout);
	std::cout << std::endl;

	BOOST_REQUIRE(value2.xmlDecode(pt, xmlns) == true);
	for (uint32_t idx=0; idx<10; idx++) {
		BOOST_REQUIRE(value2.get<OpcUaInt32>(idx) == -idx);
	}
}

BOOST_AUTO_TEST_CASE(XmlEncoderDecoder_OpcUaVariant_Array_UInt32)
{
	boost::property_tree::ptree pt;
	Xmlns xmlns;
	ConfigXml xml;
	OpcUaVariant value1, value2;

	for (uint32_t idx=0; idx<10; idx++) {
		value1.pushBack((OpcUaUInt32)idx);
	}
	BOOST_REQUIRE(value1.xmlEncode(pt, xmlns) == true);

	xml.ptree(pt);
	xml.write(std::cout);
	std::cout << std::endl;

	BOOST_REQUIRE(value2.xmlDecode(pt, xmlns) == true);
	for (uint32_t idx=0; idx<10; idx++) {
		BOOST_REQUIRE(value2.get<OpcUaUInt32>(idx) == idx);
	}
}

BOOST_AUTO_TEST_CASE(XmlEncoderDecoder_OpcUaVariant_Array_Int64)
{
	boost::property_tree::ptree pt;
	Xmlns xmlns;
	ConfigXml xml;
	OpcUaVariant value1, value2;

	for (uint32_t idx=0; idx<10; idx++) {
		value1.pushBack((OpcUaInt64)-idx);
	}
	BOOST_REQUIRE(value1.xmlEncode(pt, xmlns) == true);

	xml.ptree(pt);
	xml.write(std::cout);
	std::cout << std::endl;

	BOOST_REQUIRE(value2.xmlDecode(pt, xmlns) == true);
	for (uint32_t idx=0; idx<10; idx++) {
		BOOST_REQUIRE(value2.get<OpcUaInt64>(idx) == -idx);
	}
}

BOOST_AUTO_TEST_CASE(XmlEncoderDecoder_OpcUaVariant_Array_UInt64)
{
	boost::property_tree::ptree pt;
	Xmlns xmlns;
	ConfigXml xml;
	OpcUaVariant value1, value2;

	for (uint32_t idx=0; idx<10; idx++) {
		value1.pushBack((OpcUaUInt64)idx);
	}
	BOOST_REQUIRE(value1.xmlEncode(pt, xmlns) == true);

	xml.ptree(pt);
	xml.write(std::cout);
	std::cout << std::endl;

	BOOST_REQUIRE(value2.xmlDecode(pt, xmlns) == true);
	for (uint32_t idx=0; idx<10; idx++) {
		BOOST_REQUIRE(value2.get<OpcUaUInt64>(idx) == idx);
	}
}

BOOST_AUTO_TEST_CASE(XmlEncoderDecoder_OpcUaVariant_Array_Float)
{
	boost::property_tree::ptree pt;
	Xmlns xmlns;
	ConfigXml xml;
	OpcUaVariant value1, value2;

	for (uint32_t idx=0; idx<10; idx++) {
		value1.pushBack((OpcUaFloat)idx);
	}
	BOOST_REQUIRE(value1.xmlEncode(pt, xmlns) == true);

	xml.ptree(pt);
	xml.write(std::cout);
	std::cout << std::endl;

	BOOST_REQUIRE(value2.xmlDecode(pt, xmlns) == true);
	for (uint32_t idx=0; idx<10; idx++) {
		BOOST_REQUIRE(value2.get<OpcUaFloat>(idx) == idx);
	}
}

BOOST_AUTO_TEST_CASE(XmlEncoderDecoder_OpcUaVariant_Array_Double)
{
	boost::property_tree::ptree pt;
	Xmlns xmlns;
	ConfigXml xml;
	OpcUaVariant value1, value2;

	for (uint32_t idx=0; idx<10; idx++) {
		value1.pushBack((OpcUaDouble)idx);
	}
	BOOST_REQUIRE(value1.xmlEncode(pt, xmlns) == true);

	xml.ptree(pt);
	xml.write(std::cout);
	std::cout << std::endl;

	BOOST_REQUIRE(value2.xmlDecode(pt, xmlns) == true);
	for (uint32_t idx=0; idx<10; idx++) {
		BOOST_REQUIRE(value2.get<OpcUaDouble>(idx) == idx);
	}
}

BOOST_AUTO_TEST_CASE(XmlEncoderDecoder_OpcUaVariant_Array_DateTime)
{
	boost::posix_time::ptime now = boost::posix_time::microsec_clock::universal_time();

	boost::property_tree::ptree pt;
	Xmlns xmlns;
	ConfigXml xml;
	OpcUaVariant value1, value2;

	for (uint32_t idx=0; idx<10; idx++) {
		value1.pushBack(OpcUaDateTime(now));
	}
	BOOST_REQUIRE(value1.xmlEncode(pt, xmlns) == true);

	xml.ptree(pt);
	xml.write(std::cout);
	std::cout << std::endl;

	BOOST_REQUIRE(value2.xmlDecode(pt, xmlns) == true);
	for (uint32_t idx=0; idx<10; idx++) {
		BOOST_REQUIRE(value2.get<OpcUaDateTime>(idx).toISO8601() == value1.get<OpcUaDateTime>(idx).toISO8601());
	}
}

BOOST_AUTO_TEST_CASE(XmlEncoderDecoder_OpcUaVariant_Array_String)
{
	boost::property_tree::ptree pt;
	Xmlns xmlns;
	ConfigXml xml;
	OpcUaVariant value1, value2;

	for (uint32_t idx=0; idx<10; idx++) {
		OpcUaString::SPtr string = constructSPtr<OpcUaString>();
		string->value("Das ist ein ByteString");
		value1.pushBack(string);
	}
	BOOST_REQUIRE(value1.xmlEncode(pt, xmlns) == true);

	xml.ptree(pt);
	xml.write(std::cout);
	std::cout << std::endl;

	BOOST_REQUIRE(value2.xmlDecode(pt, xmlns) == true);
	for (uint32_t idx=0; idx<10; idx++) {
		BOOST_REQUIRE(value2.getSPtr<OpcUaString>(idx)->value() == "Das ist ein ByteString");
	}
}

BOOST_AUTO_TEST_CASE(XmlEncoderDecoder_OpcUaVariant_Array_ByteString)
{
	boost::property_tree::ptree pt;
	Xmlns xmlns;
	ConfigXml xml;
	OpcUaVariant value1, value2;

	for (uint32_t idx=0; idx<10; idx++) {
		OpcUaByteString::SPtr byteString = constructSPtr<OpcUaByteString>();
		byteString->value("Das ist ein ByteString");
		value1.pushBack(byteString);
	}
	BOOST_REQUIRE(value1.xmlEncode(pt, xmlns) == true);

	xml.ptree(pt);
	xml.write(std::cout);
	std::cout << std::endl;

	BOOST_REQUIRE(value2.xmlDecode(pt, xmlns) == true);
	for (uint32_t idx=0; idx<10; idx++) {
		BOOST_REQUIRE(value2.getSPtr<OpcUaByteString>(idx)->toString() == "Das ist ein ByteString");
	}
}

BOOST_AUTO_TEST_CASE(XmlEncoderDecoder_OpcUaVariant_Array_Guid)
{
	boost::property_tree::ptree pt;
	Xmlns xmlns;
	ConfigXml xml;
	OpcUaVariant value1, value2;

	for (uint32_t idx=0; idx<10; idx++) {
		OpcUaGuid::SPtr guid = constructSPtr<OpcUaGuid>();
		*guid = "12345678-9ABC-DEF0-1234-56789ABCDEF0";
		value1.pushBack(guid);
	}
	BOOST_REQUIRE(value1.xmlEncode(pt, xmlns) == true);

	xml.ptree(pt);
	xml.write(std::cout);
	std::cout << std::endl;

	BOOST_REQUIRE(value2.xmlDecode(pt, xmlns) == true);
	for (uint32_t idx=0; idx<10; idx++) {
		BOOST_REQUIRE(value2.getSPtr<OpcUaGuid>(idx)->value() == "12345678-9ABC-DEF0-1234-56789ABCDEF0");
	}
}

BOOST_AUTO_TEST_CASE(XmlEncoderDecoder_OpcUaVariant_Array_NodeId)
{
	boost::property_tree::ptree pt;
	Xmlns xmlns;
	ConfigXml xml;
	OpcUaVariant value1, value2;

	for (uint32_t idx=0; idx<10; idx++) {
		OpcUaNodeId::SPtr nodeId = constructSPtr<OpcUaNodeId>();
		nodeId->set(4711, 4712);
		value1.pushBack(nodeId);
	}
	BOOST_REQUIRE(value1.xmlEncode(pt, xmlns) == true);

	xml.ptree(pt);
	xml.write(std::cout);
	std::cout << std::endl;

	BOOST_REQUIRE(value2.xmlDecode(pt, xmlns) == true);
	for (uint32_t idx=0; idx<10; idx++) {
		BOOST_REQUIRE(*value2.getSPtr<OpcUaNodeId>(idx) == OpcUaNodeId(4711, 4712));
	}
}

BOOST_AUTO_TEST_CASE(XmlEncoderDecoder_OpcUaVariant_Array_ExpandedNodeId)
{
	boost::property_tree::ptree pt;
	Xmlns xmlns;
	ConfigXml xml;
	OpcUaVariant value1, value2;

	for (uint32_t idx=0; idx<10; idx++) {
		OpcUaExpandedNodeId::SPtr expandedNodeId = constructSPtr<OpcUaExpandedNodeId>();
		expandedNodeId->set(4711, 4712);
		expandedNodeId->serverIndex(4713);
		value1.pushBack(expandedNodeId);
	}
	BOOST_REQUIRE(value1.xmlEncode(pt, xmlns) == true);

	xml.ptree(pt);
	xml.write(std::cout);
	std::cout << std::endl;

	BOOST_REQUIRE(value2.xmlDecode(pt, xmlns) == true);
	for (uint32_t idx=0; idx<10; idx++) {
		OpcUaExpandedNodeId::SPtr expandedNodeId = constructSPtr<OpcUaExpandedNodeId>();
		expandedNodeId->set(4711, 4712);
		expandedNodeId->serverIndex(4713);

		BOOST_REQUIRE(*value2.getSPtr<OpcUaExpandedNodeId>(idx) == *expandedNodeId);
	}
}

BOOST_AUTO_TEST_CASE(XmlEncoderDecoder_OpcUaVariant_Array_QualifiedName)
{
	boost::property_tree::ptree pt;
	Xmlns xmlns;
	ConfigXml xml;
	OpcUaVariant value1, value2;

	for (uint32_t idx=0; idx<10; idx++) {
		OpcUaQualifiedName::SPtr qualifiedName = constructSPtr<OpcUaQualifiedName>();
		qualifiedName->set("String", 4711);
		value1.pushBack(qualifiedName);
	}
	BOOST_REQUIRE(value1.xmlEncode(pt, xmlns) == true);

	xml.ptree(pt);
	xml.write(std::cout);
	std::cout << std::endl;

	BOOST_REQUIRE(value2.xmlDecode(pt, xmlns) == true);
	for (uint32_t idx=0; idx<10; idx++) {
		BOOST_REQUIRE(*value2.getSPtr<OpcUaQualifiedName>(idx) == OpcUaQualifiedName("String", 4711));
	}
}

BOOST_AUTO_TEST_CASE(XmlEncoderDecoder_OpcUaVariant_Array_LocalizedText)
{
	boost::property_tree::ptree pt;
	Xmlns xmlns;
	ConfigXml xml;
	OpcUaVariant value1, value2;

	for (uint32_t idx=0; idx<10; idx++) {
		OpcUaLocalizedText::SPtr localizedText = constructSPtr<OpcUaLocalizedText>();
		localizedText->set("de", "TextString");
		value1.pushBack(localizedText);
	}
	BOOST_REQUIRE(value1.xmlEncode(pt, xmlns) == true);

	xml.ptree(pt);
	xml.write(std::cout);
	std::cout << std::endl;

	BOOST_REQUIRE(value2.xmlDecode(pt, xmlns) == true);
	for (uint32_t idx=0; idx<10; idx++) {
		BOOST_REQUIRE(*value2.getSPtr<OpcUaLocalizedText>(idx) == OpcUaLocalizedText("de", "TextString"));
	}
}

BOOST_AUTO_TEST_CASE(XmlEncoderDecoder_OpcUaVariant_Array_ExtensionObject)
{
	boost::property_tree::ptree pt;
	Xmlns xmlns;
	ConfigXml xml;
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
	BOOST_REQUIRE(value1.xmlEncode(pt, xmlns) == true);

	xml.ptree(pt);
	xml.write(std::cout);
	std::cout << std::endl;

	BOOST_REQUIRE(value2.xmlDecode(pt, xmlns) == true);
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

BOOST_AUTO_TEST_CASE(XmlEncoderDecoder_Variant_Array_DataValue)
{
	boost::posix_time::ptime now = boost::posix_time::microsec_clock::universal_time();

	boost::property_tree::ptree pt;
	Xmlns xmlns;
	ConfigXml xml;
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
	BOOST_REQUIRE(value1.xmlEncode(pt, xmlns) == true);

	xml.ptree(pt);
	xml.write(std::cout);
	std::cout << std::endl;

	BOOST_REQUIRE(value2.xmlDecode(pt, xmlns) == true);
	for (uint32_t idx=0; idx<10; idx++) {
		dataValue2 = value2.variantSPtr<OpcUaDataValue>(idx);
		BOOST_REQUIRE(dataValue2->variant()->get<OpcUaInt32>() == 12345);
		BOOST_REQUIRE(dataValue2->statusCode() == BadNoData);
		BOOST_REQUIRE(dataValue2->serverTimestamp().toISO8601() == dataValue1->serverTimestamp().toISO8601());
		BOOST_REQUIRE(dataValue2->sourceTimestamp().toISO8601() == dataValue2->sourceTimestamp().toISO8601());
	}
}

BOOST_AUTO_TEST_CASE(XmlEncoderDecoder_Variant_Array_DiagnosticInfo)
{
	boost::posix_time::ptime now = boost::posix_time::microsec_clock::universal_time();

	boost::property_tree::ptree pt;
	Xmlns xmlns;
	ConfigXml xml;
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
	BOOST_REQUIRE(value1.xmlEncode(pt, xmlns) == true);

	xml.ptree(pt);
	xml.write(std::cout);
	std::cout << std::endl;
	BOOST_REQUIRE(value2.xmlDecode(pt, xmlns) == true);
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

BOOST_AUTO_TEST_SUITE_END()
