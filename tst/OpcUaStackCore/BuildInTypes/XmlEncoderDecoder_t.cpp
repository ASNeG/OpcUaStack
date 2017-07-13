#include "unittest.h"
#include "OpcUaStackCore/BuildInTypes/XmlNumber.h"
#include "OpcUaStackCore/Base/Utility.h"
#include <boost/iostreams/stream.hpp>

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(XmlEncoderDecoder_)

BOOST_AUTO_TEST_CASE(XmlEncoderDecoder_)
{
	std::cout << "XmlEncoderDecoder_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(XmlEncoderDecoder_Boolean)
{
	boost::property_tree::ptree pt;
	OpcUaBoolean value1, value2;

	value1 = false;
	XmlNumber::xmlEncode(pt, value1);

	XmlNumber::xmlDecode(pt, value2);
	BOOST_REQUIRE(value2 == false);
}

BOOST_AUTO_TEST_CASE(XmlEncoderDecoder_Byte)
{
	boost::property_tree::ptree pt;
	OpcUaByte value1, value2;

	value1 = 12;
	XmlNumber::xmlEncode(pt, value1);

	XmlNumber::xmlDecode(pt, value2);
	BOOST_REQUIRE(value2 == 12);
}

BOOST_AUTO_TEST_CASE(XmlEncoderDecoder_SByte)
{
	boost::property_tree::ptree pt;
	OpcUaSByte value1, value2;

	value1 = -12;
	XmlNumber::xmlEncode(pt, value1);

	XmlNumber::xmlDecode(pt, value2);
	BOOST_REQUIRE(value2 == -12);
}

BOOST_AUTO_TEST_SUITE_END()
