#include "unittest.h"
#include "OpcUaStackCore/Base/ConfigXml.h"
#include "OpcUaStackCore/Base/Config.h"
#include <iostream>

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(ConfigXml_)

BOOST_AUTO_TEST_CASE(ConfigXml_)
{
	std::cout << "ConfigXml_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(ConfigXml_read_xml)
{
	Config config;
	ConfigXml configXml;

	BOOST_REQUIRE(configXml.parse("../tst/data/configData.xml", &config) == true);

	BOOST_REQUIRE(config.getValue("ConfigData.Section1.Parameter1", "") == "Value11");
	BOOST_REQUIRE(config.getValue("ConfigData.Section1.Parameter2", "") == "Value12");
	BOOST_REQUIRE(config.getValue("ConfigData.Section1.Parameter3", "") == "Value13");
	BOOST_REQUIRE(config.getValue("ConfigData.Section2.Parameter1", "") == "Value21");
	BOOST_REQUIRE(config.getValue("ConfigData.Section2.Parameter2", "") == "Value22");
	BOOST_REQUIRE(config.getValue("ConfigData.Section2.Parameter3", "") == "Value23");
}

BOOST_AUTO_TEST_CASE(ConfigXml_read_write_xml)
{
	Config config;
	ConfigXml configXml;

	BOOST_REQUIRE(configXml.parse("../tst/data/configData.xml", &config) == true);

	BOOST_REQUIRE(config.getValue("ConfigData.Section1.Parameter1", "") == "Value11");
	BOOST_REQUIRE(config.getValue("ConfigData.Section1.Parameter2", "") == "Value12");
	BOOST_REQUIRE(config.getValue("ConfigData.Section1.Parameter3", "") == "Value13");
	BOOST_REQUIRE(config.getValue("ConfigData.Section2.Parameter1", "") == "Value21");
	BOOST_REQUIRE(config.getValue("ConfigData.Section2.Parameter2", "") == "Value22");
	BOOST_REQUIRE(config.getValue("ConfigData.Section2.Parameter3", "") == "Value23");

	BOOST_REQUIRE(configXml.write("configData.xml") == true);
}

BOOST_AUTO_TEST_CASE(ConfigXml_read_write_read_xml)
{
	Config config;
	ConfigXml configXml;

	BOOST_REQUIRE(configXml.parse("configData.xml", &config) == true);

	BOOST_REQUIRE(config.getValue("ConfigData.Section1.Parameter1", "") == "Value11");
	BOOST_REQUIRE(config.getValue("ConfigData.Section1.Parameter2", "") == "Value12");
	BOOST_REQUIRE(config.getValue("ConfigData.Section1.Parameter3", "") == "Value13");
	BOOST_REQUIRE(config.getValue("ConfigData.Section2.Parameter1", "") == "Value21");
	BOOST_REQUIRE(config.getValue("ConfigData.Section2.Parameter2", "") == "Value22");
	BOOST_REQUIRE(config.getValue("ConfigData.Section2.Parameter3", "") == "Value23");
}

BOOST_AUTO_TEST_SUITE_END()
