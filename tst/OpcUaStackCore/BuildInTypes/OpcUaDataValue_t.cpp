#include "unittest.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaDataValue.h"
#include "OpcUaStackCore/Base/Utility.h"
#include <boost/iostreams/stream.hpp>
#include <boost/property_tree/ptree.hpp>

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(OpcUaDataValue_)

BOOST_AUTO_TEST_CASE(OpcUaDataValue_)
{
	std::cout << "OpcUaDataValue_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(OpcUaDataValue_encode_decode)
{
	std::stringstream ss;
	OpcUaDataValue value1, value2;

	value1.opcUaBinaryEncode(ss);
	BOOST_REQUIRE(count(ss) == 1);
	value2.opcUaBinaryDecode(ss);
}

BOOST_AUTO_TEST_CASE(OpcUaDataValue_all_elements)
{
	boost::posix_time::ptime ptime1 = boost::posix_time::from_iso_string("20140506T102013.123456789");
	boost::posix_time::ptime ptime2 = boost::posix_time::from_iso_string("20140506T102014.123456789");
	OpcUaDateTime sourceTimestamp, serverTimestamp;
	std::stringstream ss;
	OpcUaDataValue value1, value2;

	sourceTimestamp.dateTime(ptime1);
	serverTimestamp.dateTime(ptime2);

	value1.variant()->variant((OpcUaUInt16)1234);
	value1.statusCode((OpcUaStatusCode)12);
	value1.sourceTimestamp(sourceTimestamp);
	value1.sourcePicoseconds(1234);
	value1.serverTimestamp(serverTimestamp);
	value1.serverPicoseconds(5678);

	value1.opcUaBinaryEncode(ss);
	value2.opcUaBinaryDecode(ss);

	BOOST_REQUIRE(value1.variant()->variant<OpcUaUInt16>() == 1234);
	BOOST_REQUIRE(value1.statusCode() == (OpcUaStatusCode)12);
	BOOST_REQUIRE(boost::posix_time::to_iso_string(value1.sourceTimestamp().dateTime()) == "20140506T102013.123456");
	BOOST_REQUIRE(value1.sourcePicoseconds() == 1234);
	BOOST_REQUIRE(boost::posix_time::to_iso_string(value1.serverTimestamp().dateTime()) == "20140506T102014.123456");
	BOOST_REQUIRE(value1.serverPicoseconds() == 5678);
}

BOOST_AUTO_TEST_CASE(OpcUaDataValue_all_elements_ptree)
{
	boost::posix_time::ptime ptime1 = boost::posix_time::from_iso_string("20140506T102013.123456789");
	boost::posix_time::ptime ptime2 = boost::posix_time::from_iso_string("20140506T102014.123456789");
	OpcUaDateTime sourceTimestamp, serverTimestamp;
	boost::property_tree::ptree pt;
	OpcUaDataValue value1, value2;

	sourceTimestamp.dateTime(ptime1);
	serverTimestamp.dateTime(ptime2);

	value1.variant()->variant((OpcUaUInt16)1234);
	value1.statusCode((OpcUaStatusCode)12);
	value1.sourceTimestamp(sourceTimestamp);
	value1.sourcePicoseconds(1234);
	value1.serverTimestamp(serverTimestamp);
	value1.serverPicoseconds(5678);

	value1.encode(pt);
	value2.decode(pt, OpcUaBuildInType_OpcUaUInt16, false);

	BOOST_REQUIRE(value1.variant()->variant<OpcUaUInt16>() == 1234);
	BOOST_REQUIRE(value1.statusCode() == (OpcUaStatusCode)12);
	BOOST_REQUIRE(boost::posix_time::to_iso_string(value1.sourceTimestamp().dateTime()) == "20140506T102013.123456");
	BOOST_REQUIRE(value1.sourcePicoseconds() == 1234);
	BOOST_REQUIRE(boost::posix_time::to_iso_string(value1.serverTimestamp().dateTime()) == "20140506T102014.123456");
	BOOST_REQUIRE(value1.serverPicoseconds() == 5678);
}

BOOST_AUTO_TEST_CASE(OpcUaDataValue_copyTo_uint32)
{
	boost::posix_time::ptime ptime1 = boost::posix_time::from_iso_string("20140506T102013.123456789");
	boost::posix_time::ptime ptime2 = boost::posix_time::from_iso_string("20140506T102014.123456789");
	OpcUaDateTime sourceTimestamp, serverTimestamp;
	std::stringstream ss;
	OpcUaDataValue value1, value2;

	sourceTimestamp.dateTime(ptime1);
	serverTimestamp.dateTime(ptime2);

	value1.variant()->variant((OpcUaUInt32)1234);
	value1.statusCode((OpcUaStatusCode)12);
	value1.sourceTimestamp(sourceTimestamp);
	value1.sourcePicoseconds(1234);
	value1.serverTimestamp(serverTimestamp);
	value1.serverPicoseconds(5678);

	value1.copyTo(value2);

	BOOST_REQUIRE(value1.variant()->variant<OpcUaUInt32>() == 1234);
	BOOST_REQUIRE(value1.statusCode() == (OpcUaStatusCode)12);
	BOOST_REQUIRE(boost::posix_time::to_iso_string(value1.sourceTimestamp().dateTime()) == "20140506T102013.123456");
	BOOST_REQUIRE(value1.sourcePicoseconds() == 1234);
	BOOST_REQUIRE(boost::posix_time::to_iso_string(value1.serverTimestamp().dateTime()) == "20140506T102014.123456");
	BOOST_REQUIRE(value1.serverPicoseconds() == 5678);

	BOOST_REQUIRE(value2.variant()->variant<OpcUaUInt32>() == 1234);
	BOOST_REQUIRE(value2.statusCode() == (OpcUaStatusCode)12);
	BOOST_REQUIRE(boost::posix_time::to_iso_string(value2.sourceTimestamp().dateTime()) == "20140506T102013.123456");
	BOOST_REQUIRE(value2.sourcePicoseconds() == 1234);
	BOOST_REQUIRE(boost::posix_time::to_iso_string(value2.serverTimestamp().dateTime()) == "20140506T102014.123456");
	BOOST_REQUIRE(value2.serverPicoseconds() == 5678);

	value2.variant()->variant((OpcUaUInt32)5678);

	BOOST_REQUIRE(value1.variant()->variant<OpcUaUInt32>() == 1234);
	BOOST_REQUIRE(value1.statusCode() == (OpcUaStatusCode)12);
	BOOST_REQUIRE(boost::posix_time::to_iso_string(value1.sourceTimestamp().dateTime()) == "20140506T102013.123456");
	BOOST_REQUIRE(value1.sourcePicoseconds() == 1234);
	BOOST_REQUIRE(boost::posix_time::to_iso_string(value1.serverTimestamp().dateTime()) == "20140506T102014.123456");
	BOOST_REQUIRE(value1.serverPicoseconds() == 5678);

	BOOST_REQUIRE(value2.variant()->variant<OpcUaUInt32>() == 5678);
	BOOST_REQUIRE(value2.statusCode() == (OpcUaStatusCode)12);
	BOOST_REQUIRE(boost::posix_time::to_iso_string(value2.sourceTimestamp().dateTime()) == "20140506T102013.123456");
	BOOST_REQUIRE(value2.sourcePicoseconds() == 1234);
	BOOST_REQUIRE(boost::posix_time::to_iso_string(value2.serverTimestamp().dateTime()) == "20140506T102014.123456");
	BOOST_REQUIRE(value2.serverPicoseconds() == 5678);
}


BOOST_AUTO_TEST_CASE(OpcUaDataValue_copyTo_uint16)
{
	boost::posix_time::ptime ptime1 = boost::posix_time::from_iso_string("20140506T102013.123456789");
	boost::posix_time::ptime ptime2 = boost::posix_time::from_iso_string("20140506T102014.123456789");
	OpcUaDateTime sourceTimestamp, serverTimestamp;
	std::stringstream ss;
	OpcUaDataValue value1, value2;

	sourceTimestamp.dateTime(ptime1);
	serverTimestamp.dateTime(ptime2);

	value1.variant()->variant((OpcUaUInt16)1234);
	value1.statusCode((OpcUaStatusCode)12);
	value1.sourceTimestamp(sourceTimestamp);
	value1.sourcePicoseconds(1234);
	value1.serverTimestamp(serverTimestamp);
	value1.serverPicoseconds(5678);

	value1.copyTo(value2);

	BOOST_REQUIRE(value1.variant()->variant<OpcUaUInt16>() == 1234);
	BOOST_REQUIRE(value1.statusCode() == (OpcUaStatusCode)12);
	BOOST_REQUIRE(boost::posix_time::to_iso_string(value1.sourceTimestamp().dateTime()) == "20140506T102013.123456");
	BOOST_REQUIRE(value1.sourcePicoseconds() == 1234);
	BOOST_REQUIRE(boost::posix_time::to_iso_string(value1.serverTimestamp().dateTime()) == "20140506T102014.123456");
	BOOST_REQUIRE(value1.serverPicoseconds() == 5678);

	BOOST_REQUIRE(value2.variant()->variant<OpcUaUInt16>() == 1234);
	BOOST_REQUIRE(value2.statusCode() == (OpcUaStatusCode)12);
	BOOST_REQUIRE(boost::posix_time::to_iso_string(value2.sourceTimestamp().dateTime()) == "20140506T102013.123456");
	BOOST_REQUIRE(value2.sourcePicoseconds() == 1234);
	BOOST_REQUIRE(boost::posix_time::to_iso_string(value2.serverTimestamp().dateTime()) == "20140506T102014.123456");
	BOOST_REQUIRE(value2.serverPicoseconds() == 5678);

	value2.variant()->variant((OpcUaUInt16)5678);

	BOOST_REQUIRE(value1.variant()->variant<OpcUaUInt16>() == 1234);
	BOOST_REQUIRE(value1.statusCode() == (OpcUaStatusCode)12);
	BOOST_REQUIRE(boost::posix_time::to_iso_string(value1.sourceTimestamp().dateTime()) == "20140506T102013.123456");
	BOOST_REQUIRE(value1.sourcePicoseconds() == 1234);
	BOOST_REQUIRE(boost::posix_time::to_iso_string(value1.serverTimestamp().dateTime()) == "20140506T102014.123456");
	BOOST_REQUIRE(value1.serverPicoseconds() == 5678);

	BOOST_REQUIRE(value2.variant()->variant<OpcUaUInt16>() == 5678);
	BOOST_REQUIRE(value2.statusCode() == (OpcUaStatusCode)12);
	BOOST_REQUIRE(boost::posix_time::to_iso_string(value2.sourceTimestamp().dateTime()) == "20140506T102013.123456");
	BOOST_REQUIRE(value2.sourcePicoseconds() == 1234);
	BOOST_REQUIRE(boost::posix_time::to_iso_string(value2.serverTimestamp().dateTime()) == "20140506T102014.123456");
	BOOST_REQUIRE(value2.serverPicoseconds() == 5678);
}

BOOST_AUTO_TEST_CASE(OpcUaDataValue_copyTo_string)
{
	boost::posix_time::ptime ptime1 = boost::posix_time::from_iso_string("20140506T102013.123456789");
	boost::posix_time::ptime ptime2 = boost::posix_time::from_iso_string("20140506T102014.123456789");
	OpcUaDateTime sourceTimestamp, serverTimestamp;
	std::stringstream ss;
	OpcUaDataValue value1, value2;
	OpcUaString::SPtr strValue1, strValue2;

	sourceTimestamp.dateTime(ptime1);
	serverTimestamp.dateTime(ptime2);

	strValue1 = constructSPtr<OpcUaString>();
	strValue1->value("Text1");
	value1.variant()->variant(strValue1);
	value1.statusCode((OpcUaStatusCode)12);
	value1.sourceTimestamp(sourceTimestamp);
	value1.sourcePicoseconds(1234);
	value1.serverTimestamp(serverTimestamp);
	value1.serverPicoseconds(5678);

	value1.copyTo(value2);

	strValue1 = value1.variant()->variantSPtr<OpcUaString>();
	BOOST_REQUIRE(strValue1->value() == "Text1");
	BOOST_REQUIRE(value1.statusCode() == (OpcUaStatusCode)12);
	BOOST_REQUIRE(boost::posix_time::to_iso_string(value1.sourceTimestamp().dateTime()) == "20140506T102013.123456");
	BOOST_REQUIRE(value1.sourcePicoseconds() == 1234);
	BOOST_REQUIRE(boost::posix_time::to_iso_string(value1.serverTimestamp().dateTime()) == "20140506T102014.123456");
	BOOST_REQUIRE(value1.serverPicoseconds() == 5678);

	strValue2 = value2.variant()->variantSPtr<OpcUaString>();
	BOOST_REQUIRE(strValue1->value() == "Text1");
	BOOST_REQUIRE(value2.statusCode() == (OpcUaStatusCode)12);
	BOOST_REQUIRE(boost::posix_time::to_iso_string(value2.sourceTimestamp().dateTime()) == "20140506T102013.123456");
	BOOST_REQUIRE(value2.sourcePicoseconds() == 1234);
	BOOST_REQUIRE(boost::posix_time::to_iso_string(value2.serverTimestamp().dateTime()) == "20140506T102014.123456");
	BOOST_REQUIRE(value2.serverPicoseconds() == 5678);

	value2.variant()->variant((OpcUaUInt16)5678);

	strValue1 = value1.variant()->variantSPtr<OpcUaString>();
	BOOST_REQUIRE(strValue1->value() == "Text1");
	BOOST_REQUIRE(value1.statusCode() == (OpcUaStatusCode)12);
	BOOST_REQUIRE(boost::posix_time::to_iso_string(value1.sourceTimestamp().dateTime()) == "20140506T102013.123456");
	BOOST_REQUIRE(value1.sourcePicoseconds() == 1234);
	BOOST_REQUIRE(boost::posix_time::to_iso_string(value1.serverTimestamp().dateTime()) == "20140506T102014.123456");
	BOOST_REQUIRE(value1.serverPicoseconds() == 5678);

	BOOST_REQUIRE(value2.variant()->variant<OpcUaUInt16>() == 5678);
	BOOST_REQUIRE(value2.statusCode() == (OpcUaStatusCode)12);
	BOOST_REQUIRE(boost::posix_time::to_iso_string(value2.sourceTimestamp().dateTime()) == "20140506T102013.123456");
	BOOST_REQUIRE(value2.sourcePicoseconds() == 1234);
	BOOST_REQUIRE(boost::posix_time::to_iso_string(value2.serverTimestamp().dateTime()) == "20140506T102014.123456");
	BOOST_REQUIRE(value2.serverPicoseconds() == 5678);
}

BOOST_AUTO_TEST_CASE(OpcUaDataValue_constructor)
{
	boost::posix_time::ptime now = boost::posix_time::microsec_clock::universal_time();

	OpcUaDataValue value1(OpcUaByteString("String-Variable"), Success, OpcUaDateTime(now));
	OpcUaDataValue value2(OpcUaByteString("String-Variable"), Success, OpcUaDateTime(now));
	BOOST_REQUIRE(value1 == value2);
}

BOOST_AUTO_TEST_CASE(OpcUaDataValue_set)
{
	boost::posix_time::ptime now = boost::posix_time::microsec_clock::universal_time();

	OpcUaDataValue value1, value2;
	value1.set(OpcUaByteString("String-Variable"), Success, OpcUaDateTime(now));
	value2.set(OpcUaByteString("String-Variable"), Success, OpcUaDateTime(now));
	BOOST_REQUIRE(value1 == value2);
}

BOOST_AUTO_TEST_CASE(OpcUaDataValue_setValue_getValue)
{
	OpcUaDataValue value;
	value.setValue(OpcUaString("Dies ist ein TestString"));

	// get opc ua string
	OpcUaString str;
	BOOST_REQUIRE(value.getValue(str) == true);
	BOOST_REQUIRE(str == OpcUaString("Dies ist ein TestString"));

	// get value from invalid type
	OpcUaGuid guid;
	BOOST_REQUIRE(value.getValue(guid) == false);

	// get value from empty variable
	OpcUaDataValue value1;
	BOOST_REQUIRE(value1.getValue(guid) == false);
}

#if 0
BOOST_AUTO_TEST_CASE(OpcUaDataValue_string_array_with_timestamp)
{
	boost::posix_time::ptime ptime1 = boost::posix_time::from_iso_string("20140506T102014.123456789");
	boost::posix_time::ptime ptime2 = boost::posix_time::from_iso_string("20140506T102014.123456789");
	OpcUaDateTime sourceTimestamp, serverTimestamp;
	std::stringstream ss;
	OpcUaDataValue value1, value2;
	OpcUaString::SPtr string1, string2;

	sourceTimestamp.dateTime(ptime1);
	serverTimestamp.dateTime(ptime2);

	OpcUaVariantValue::Vec variantVec1, variantVec2;
	OpcUaVariantValue variantValue1, variantValue2;

	string1 = constructSPtr<OpcUaString>();
	string1->value("Dies ist der erste String");
	variantValue1.variant(string1);
	variantVec1.push_back(variantValue1);

	string1 = constructSPtr<OpcUaString>();
	string1->value("Dies ist der zweite String");
	variantValue1.variant(string1);
	variantVec1.push_back(variantValue1);

	string1 = constructSPtr<OpcUaString>();
	string1->value("Dies ist der dritte String");
	variantValue1.variant(string1);
	variantVec1.push_back(variantValue1);

	value1.sourceTimestamp(sourceTimestamp);
	value1.serverTimestamp(serverTimestamp);
	value1.variant()->variant(variantVec1);

	std::cout << "value1=" << value1 << std::endl;
	value1.opcUaBinaryEncode(ss);
	dumpHex(ss);
	std::cout << "************************************************" << std::endl;
	value2.opcUaBinaryDecode(ss);
	dumpHex(ss);
	std::cout << "value2=" << value2 << std::endl;


	
	BOOST_REQUIRE(boost::posix_time::to_iso_string(value2.sourceTimestamp().dateTime()) == "20140506T102014.123456");
	BOOST_REQUIRE(boost::posix_time::to_iso_string(value1.serverTimestamp().dateTime()) == "20140506T102014.123456");
}
#endif

BOOST_AUTO_TEST_SUITE_END()
