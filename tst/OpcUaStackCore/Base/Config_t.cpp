#include "unittest.h"
#include "OpcUaStackCore/Base/Config.h"

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(Config_t)

BOOST_AUTO_TEST_CASE(Config_)
{
	std::cout << "Config_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(Config_set_get)
{
	Config cfg;
	
	BOOST_REQUIRE(cfg.set("p1", "v1") == true);
	BOOST_REQUIRE(cfg.set("p2.p3.p4", "v234") == true);
	BOOST_REQUIRE(cfg.set("p2.p5", "v25") == true);
	BOOST_REQUIRE(cfg.set("p2.p5", "v25") == false);
	BOOST_REQUIRE(cfg.get("path.not.exist") == false);

	BOOST_REQUIRE(!cfg.get("p2.p5") == false);
	BOOST_REQUIRE(*cfg.get("p2.p5") == "v25");

	BOOST_REQUIRE(cfg.get("path.not.exist", "default") == "default");
	BOOST_REQUIRE(cfg.get("p2.p5", "default") == "v25");

}


BOOST_AUTO_TEST_SUITE_END()