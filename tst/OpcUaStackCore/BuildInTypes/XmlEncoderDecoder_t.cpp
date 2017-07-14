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
	BOOST_REQUIRE(value2.dateTime() == now);
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
	// FIXME: core
#if 0
	boost::property_tree::ptree pt;
	Xmlns xmlns;
	ConfigXml xml;
	OpcUaByteString value2;

	OpcUaByteString value1;
	value1.value("Dies ist ein ByteString");
	value1.xmlEncode(pt, xmlns);

	xml.ptree(pt);
	xml.write(std::cout);
	std::cout << std::endl;

	value2.xmlDecode(pt, xmlns);
	BOOST_REQUIRE(value2.toString() == std::string("Dies ist ein ByteString"));
#endif
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

	Argument::SPtr argument;
	boost::property_tree::ptree pt;
	Xmlns xmlns;
	ConfigXml xml;
	OpcUaExtensionObject value1, value2;

	argument = value1.parameter<Argument>(OpcUaId_Argument_Encoding_DefaultBinary);
	argument->name().value("ArgumentName");
	argument->dataType().set("NodeName", 23);
	argument->description().set("de", "Description");
	BOOST_REQUIRE(value1.xmlEncode(pt, xmlns) == true);

	xml.ptree(pt);
	xml.write(std::cout);
	std::cout << std::endl;

	BOOST_REQUIRE(value2.xmlDecode(pt, xmlns) == true);
}

BOOST_AUTO_TEST_SUITE_END()
