#include "unittest.h"
#include "OpcUaStackCore/Base/Base64.h"

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(Base64_t)

BOOST_AUTO_TEST_CASE(Base64_)
{
	std::cout << "Base64_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(Base64_decode)
{
	std::stringstream ss1;
	char buffer[5000];
	uint32_t len = 5000;

	memset(buffer, 0x00, 5000);
	ss1 << "PG9wYzpUeXBlRGljdGlvbmFyeSB4bWxuczp4c2k9Imh0dHA6Ly93d3cudzMub3JnLzIwMDEvWE1MU2NoZ"
	    << "W1hLWluc3RhbmNlIiB4bWxuczp0bnM9Imh0dHA6Ly95b3Vyb3JnYW5pc2F0aW9uLm9yZy9jb"
	    << "21wbGV4LyIgRGVmYXVsdEJ5dGVPcmRlcj0iTGl0dGxlRW5kaWFuIiB4bWxuczpvcGM9Imh0d"
	    << "HA6Ly9vcGNmb3VuZGF0aW9uLm9yZy9CaW5hcnlTY2hlbWEvIiB4bWxuczp1YT0iaHR0cDovL"
	    << "29wY2ZvdW5kYXRpb24ub3JnL1VBLyIgVGFyZ2V0TmFtZXNwYWNlPSJodHRwOi8veW91cm9yZ"
	    << "2FuaXNhdGlvbi5vcmcvY29tcGxleC8iPgogPG9wYzpJbXBvcnQgTmFtZXNwYWNlPSJodHRwO"
	    << "i8vb3BjZm91bmRhdGlvbi5vcmcvVUEvIi8+CiA8b3BjOlN0cnVjdHVyZWRUeXBlIEJhc2VUe"
	    << "XBlPSJ1YTpFeHRlbnNpb25PYmplY3QiIE5hbWU9Ik15Q29tcGxleCI+CiAgPG9wYzpGaWVsZ"
	    << "CBUeXBlTmFtZT0ib3BjOkRvdWJsZSIgTmFtZT0iVmFyaWFibGUxIi8+CiAgPG9wYzpGaWVsZ"
	    << "CBUeXBlTmFtZT0ib3BjOkludDMyIiBOYW1lPSJOb09mVmFyaWFibGUyIi8+CiAgPG9wYzpGa"
	    << "WVsZCBMZW5ndGhGaWVsZD0iTm9PZlZhcmlhYmxlMiIgVHlwZU5hbWU9Im9wYzpEb3VibGUiI"
	    << "E5hbWU9IlZhcmlhYmxlMiIvPgogIDxvcGM6RmllbGQgVHlwZU5hbWU9Im9wYzpCeXRlU3Rya"
	    << "W5nIiBOYW1lPSJWYXJpYWJsZTMiLz4KIDwvb3BjOlN0cnVjdHVyZWRUeXBlPgo8L29wYzpUe"
	    << "XBlRGljdGlvbmFyeT4K";

	Base64::decode(ss1.str().c_str(), ss1.str().length(), buffer, len);
	std::cout << buffer << std::endl;
}

BOOST_AUTO_TEST_SUITE_END()
