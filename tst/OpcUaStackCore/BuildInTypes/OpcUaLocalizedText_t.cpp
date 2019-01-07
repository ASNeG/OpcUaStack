#include "unittest.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaLocalizedText.h"
#include "OpcUaStackCore/Base/Utility.h"
#include <boost/iostreams/stream.hpp>

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(OpcUaLocalizedText_)

BOOST_AUTO_TEST_CASE(OpcUaLocalizedText_)
{
	std::cout << "OpcUaLocalizedText_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(OpcUaLocalizedText_locale_no_text_no)
{
	std::stringstream ss;
	OpcUaLocalizedText value1, value2;
	
	value1.opcUaBinaryEncode(ss);
	value2.opcUaBinaryDecode(ss);

	BOOST_REQUIRE(value2.locale().exist() == false);
	BOOST_REQUIRE(value2.text().exist() == false);
}

BOOST_AUTO_TEST_CASE(OpcUaLocalizedText_locale_no_text_no_ptree)
{
	boost::property_tree::ptree pt;
	OpcUaLocalizedText value1, value2;
	Xmlns xmlns;

	value1.xmlEncode(pt, xmlns);
	value2.xmlDecode(pt, xmlns);

	BOOST_REQUIRE(value2.locale().exist() == false);
	BOOST_REQUIRE(value2.text().exist() == false);
}

BOOST_AUTO_TEST_CASE(OpcUaLocalizedText_locale_yes_text_no)
{
	std::stringstream ss;
	OpcUaLocalizedText value1, value2;
	
	value1.locale("locale");
	value1.opcUaBinaryEncode(ss);
	value2.opcUaBinaryDecode(ss);

	BOOST_REQUIRE(value2.locale().exist() == true);
	BOOST_REQUIRE(value2.text().exist() == false);
	BOOST_REQUIRE(value2.locale().value() == "locale");
}

BOOST_AUTO_TEST_CASE(OpcUaLocalizedText_locale_yes_text_no_ptree)
{
	boost::property_tree::ptree pt;
	OpcUaLocalizedText value1, value2;
	Xmlns xmlns;

	value1.locale("locale");
	value1.xmlEncode(pt, xmlns);
	value2.xmlDecode(pt, xmlns);

	BOOST_REQUIRE(value2.locale().exist() == true);
	BOOST_REQUIRE(value2.text().exist() == false);
	BOOST_REQUIRE(value2.locale().value() == "locale");
}

BOOST_AUTO_TEST_CASE(OpcUaLocalizedText_locale_no_text_yes)
{
	std::stringstream ss;
	OpcUaLocalizedText value1, value2;
	
	value1.text("text");
	value1.opcUaBinaryEncode(ss);
	value2.opcUaBinaryDecode(ss);

	BOOST_REQUIRE(value2.locale().exist() == false);
	BOOST_REQUIRE(value2.text().exist() == true);
	BOOST_REQUIRE(value2.text().value() == "text");
}

BOOST_AUTO_TEST_CASE(OpcUaLocalizedText_locale_no_text_yes_ptree)
{
	boost::property_tree::ptree pt;
	OpcUaLocalizedText value1, value2;
	Xmlns xmlns;

	value1.text("text");
	value1.xmlEncode(pt, xmlns);
	value2.xmlDecode(pt, xmlns);

	BOOST_REQUIRE(value2.locale().exist() == false);
	BOOST_REQUIRE(value2.text().exist() == true);
	BOOST_REQUIRE(value2.text().value() == "text");
}

BOOST_AUTO_TEST_CASE(OpcUaLocalizedText_locale_yes_text_yes)
{
	std::stringstream ss;
	OpcUaLocalizedText value1, value2;
	
	value1.locale("locale");
	value1.text("text");
	value1.opcUaBinaryEncode(ss);
	value2.opcUaBinaryDecode(ss);

	BOOST_REQUIRE(value2.locale().exist() == true);
	BOOST_REQUIRE(value2.text().exist() == true);
	BOOST_REQUIRE(value2.locale().value() == "locale");
	BOOST_REQUIRE(value2.text().value() == "text");
}

BOOST_AUTO_TEST_CASE(OpcUaLocalizedText_locale_yes_text_yes_ptree)
{
	boost::property_tree::ptree pt;
	OpcUaLocalizedText value1, value2;
	Xmlns xmlns;

	value1.locale("locale");
	value1.text("text");
	value1.xmlEncode(pt, xmlns);
	value2.xmlDecode(pt, xmlns);

	BOOST_REQUIRE(value2.locale().exist() == true);
	BOOST_REQUIRE(value2.text().exist() == true);
	BOOST_REQUIRE(value2.locale().value() == "locale");
	BOOST_REQUIRE(value2.text().value() == "text");
}

BOOST_AUTO_TEST_CASE(OpcUaLocalizedText_copyTo)
{
	std::stringstream ss;
	OpcUaLocalizedText value1, value2;
	
	value1.locale("locale");
	value1.text("text");
	value1.copyTo(value2);

	BOOST_REQUIRE(value1.locale().exist() == true);
	BOOST_REQUIRE(value1.text().exist() == true);
	BOOST_REQUIRE(value1.locale().value() == "locale");
	BOOST_REQUIRE(value1.text().value() == "text");
	BOOST_REQUIRE(value2.locale().exist() == true);
	BOOST_REQUIRE(value2.text().exist() == true);
	BOOST_REQUIRE(value2.locale().value() == "locale");
	BOOST_REQUIRE(value2.text().value() == "text");

	value1.locale("locale1");
	value1.text("text1");

	BOOST_REQUIRE(value1.locale().exist() == true);
	BOOST_REQUIRE(value1.text().exist() == true);
	BOOST_REQUIRE(value1.locale().value() == "locale1");
	BOOST_REQUIRE(value1.text().value() == "text1");
	BOOST_REQUIRE(value2.locale().exist() == true);
	BOOST_REQUIRE(value2.text().exist() == true);
	BOOST_REQUIRE(value2.locale().value() == "locale");
	BOOST_REQUIRE(value2.text().value() == "text");
}

BOOST_AUTO_TEST_SUITE_END()
