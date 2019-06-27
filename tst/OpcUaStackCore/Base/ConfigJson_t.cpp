#include "unittest.h"
#include "OpcUaStackCore/Base/ConfigJson.h"
#include "OpcUaStackCore/Base/Config.h"
#include <iostream>

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(ConfigJson_)

BOOST_AUTO_TEST_CASE(ConfigJson_)
{
	std::cout << "ConfigJson_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(ConfigJson_read_json)
{
	Config config;
	ConfigJson configJson;

	BOOST_REQUIRE(configJson.parse("../tst/data/configData.json", &config) == true);

	BOOST_REQUIRE(config.getValue("ConfigData.Section1.Parameter1", "") == "Value11");
	BOOST_REQUIRE(config.getValue("ConfigData.Section1.Parameter2", "") == "Value12");
	BOOST_REQUIRE(config.getValue("ConfigData.Section1.Parameter3", "") == "Value13");
	BOOST_REQUIRE(config.getValue("ConfigData.Section2.Parameter1", "") == "Value21");
	BOOST_REQUIRE(config.getValue("ConfigData.Section2.Parameter2", "") == "Value22");
	BOOST_REQUIRE(config.getValue("ConfigData.Section2.Parameter3", "") == "Value23");
}

BOOST_AUTO_TEST_CASE(ConfigJson_read_write_json)
{
	Config config;
	ConfigJson configJson;

	BOOST_REQUIRE(configJson.parse("../tst/data/configData.json", &config) == true);

	BOOST_REQUIRE(config.getValue("ConfigData.Section1.Parameter1", "") == "Value11");
	BOOST_REQUIRE(config.getValue("ConfigData.Section1.Parameter2", "") == "Value12");
	BOOST_REQUIRE(config.getValue("ConfigData.Section1.Parameter3", "") == "Value13");
	BOOST_REQUIRE(config.getValue("ConfigData.Section2.Parameter1", "") == "Value21");
	BOOST_REQUIRE(config.getValue("ConfigData.Section2.Parameter2", "") == "Value22");
	BOOST_REQUIRE(config.getValue("ConfigData.Section2.Parameter3", "") == "Value23");

	BOOST_REQUIRE(configJson.write("configData.json") == true);
}

BOOST_AUTO_TEST_CASE(ConfigJson_read_write_read_json)
{
	Config config;
	ConfigJson configJson;

	BOOST_REQUIRE(configJson.parse("configData.json", &config) == true);

	BOOST_REQUIRE(config.getValue("ConfigData.Section1.Parameter1", "") == "Value11");
	BOOST_REQUIRE(config.getValue("ConfigData.Section1.Parameter2", "") == "Value12");
	BOOST_REQUIRE(config.getValue("ConfigData.Section1.Parameter3", "") == "Value13");
	BOOST_REQUIRE(config.getValue("ConfigData.Section2.Parameter1", "") == "Value21");
	BOOST_REQUIRE(config.getValue("ConfigData.Section2.Parameter2", "") == "Value22");
	BOOST_REQUIRE(config.getValue("ConfigData.Section2.Parameter3", "") == "Value23");
}

BOOST_AUTO_TEST_SUITE_END()
