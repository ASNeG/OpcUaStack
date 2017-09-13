#include "unittest.h"
#include "OpcUaStackServer/EventType/EventTypeGenerator.h"

using namespace OpcUaStackServer;

BOOST_AUTO_TEST_SUITE(EventTypeGenerator_)

BOOST_AUTO_TEST_CASE(EventTypeGenerator_)
{
	std::cout << "EventTypeGenerator_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(EventTypeGenerator_construct_destruct)
{
	EventTypeGenerator eventTypeGenerator;
}

BOOST_AUTO_TEST_SUITE_END()
