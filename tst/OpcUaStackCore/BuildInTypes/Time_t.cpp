#include "unittest.h"
#include "boost/date_time.hpp"

BOOST_AUTO_TEST_SUITE(Time_)

BOOST_AUTO_TEST_CASE(Time__)
{
	std::cout << "Time_t" << std::endl;
}


BOOST_AUTO_TEST_CASE(Time_time_zone)
{
	// local time and universal time
	std::cout << boost::posix_time::microsec_clock::local_time() << std::endl;
	std::cout << boost::posix_time::microsec_clock::universal_time() << std::endl;

	// parse universal time
	std::stringstream ss;
	boost::posix_time::time_input_facet* facet = new boost::posix_time::time_input_facet("%Y-%m-%dT%H:%M:%S");
	ss.imbue(std::locale(ss.getloc(), facet));
	ss.str("2002-10-10T10:20:10");
	boost::posix_time::ptime ptime;
	ss >> ptime;
	std::cout << ptime << std::endl;
}

BOOST_AUTO_TEST_SUITE_END()
