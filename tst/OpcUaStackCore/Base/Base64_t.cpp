#include "unittest.h"
#include "OpcUaStackCore/Base/Base64.h"

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(Base64_t)

BOOST_AUTO_TEST_CASE(Base64_)
{
	std::cout << "Base64_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(Base64_decode1)
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


BOOST_AUTO_TEST_CASE(Base64_decode2)
{
	std::stringstream ss1;
	char buffer[5000];
	uint32_t len = 5000;

	memset(buffer, 0x00, 5000);
	ss1	<< "PG9wYzpUeXBlRGljdGlvbmFyeSB4bWxuczp4c2k9Imh0dHA6Ly93d3cudzMub3JnLzIwMDEvWE1MU2NoZ"
        << "W1hLWluc3RhbmNlIiB4bWxuczp0bnM9Imh0dHA6Ly95b3Vyb3JnYW5pc2F0aW9uLm9yZy9Ob"
        << "2RlU2V0RXhhbXBsZS8iIERlZmF1bHRCeXRlT3JkZXI9IkxpdHRsZUVuZGlhbiIgeG1sbnM6b"
        << "3BjPSJodHRwOi8vb3BjZm91bmRhdGlvbi5vcmcvQmluYXJ5U2NoZW1hLyIgeG1sbnM6dWE9I"
        << "mh0dHA6Ly9vcGNmb3VuZGF0aW9uLm9yZy9VQS8iIFRhcmdldE5hbWVzcGFjZT0iaHR0cDovL"
        << "3lvdXJvcmdhbmlzYXRpb24ub3JnL05vZGVTZXRFeGFtcGxlLyI+CiA8b3BjOkltcG9ydCBOY"
        << "W1lc3BhY2U9Imh0dHA6Ly9vcGNmb3VuZGF0aW9uLm9yZy9VQS8iLz4KIDxvcGM6U3RydWN0d"
        << "XJlZFR5cGUgQmFzZVR5cGU9InVhOkV4dGVuc2lvbk9iamVjdCIgTmFtZT0iTXlDb21wbGV4U"
        << "3RydWN0dXJlVHlwZSI+CiAgPG9wYzpGaWVsZCBUeXBlTmFtZT0ib3BjOkRvdWJsZSIgTmFtZ"
        << "T0iRWxlbWVudDEiLz4KICA8b3BjOkZpZWxkIFR5cGVOYW1lPSJ0bnM6TXlTdHJ1Y3R1cmVUe"
        << "XBlIiBOYW1lPSJFbGVtZW50MiIvPgogIDxvcGM6RmllbGQgVHlwZU5hbWU9InRuczpFbnVtU"
        << "2ltcGxlVHlwZSIgTmFtZT0iRWxlbWVudDMiLz4KIDwvb3BjOlN0cnVjdHVyZWRUeXBlPgogP"
        << "G9wYzpTdHJ1Y3R1cmVkVHlwZSBCYXNlVHlwZT0idWE6RXh0ZW5zaW9uT2JqZWN0IiBOYW1lP"
        << "SJNeVN0cnVjdHVyZVR5cGUiPgogIDxvcGM6RmllbGQgVHlwZU5hbWU9Im9wYzpCaXQiIE5hb"
        << "WU9IkVsZW1lbnQzU3BlY2lmaWVkIi8+CiAgPG9wYzpGaWVsZCBMZW5ndGg9IjMxIiBUeXBlT"
        << "mFtZT0ib3BjOkJpdCIgTmFtZT0iUmVzZXJ2ZWQxIi8+CiAgPG9wYzpGaWVsZCBUeXBlTmFtZ"
        << "T0ib3BjOkRvdWJsZSIgTmFtZT0iRWxlbWVudDEiLz4KICA8b3BjOkZpZWxkIFR5cGVOYW1lP"
        << "SJvcGM6RG91YmxlIiBOYW1lPSJFbGVtZW50MiIvPgogIDxvcGM6RmllbGQgU3dpdGNoRmllb"
        << "GQ9IkVsZW1lbnQzU3BlY2lmaWVkIiBUeXBlTmFtZT0ib3BjOkRvdWJsZSIgTmFtZT0iRWxlb"
        << "WVudDMiLz4KIDwvb3BjOlN0cnVjdHVyZWRUeXBlPgogPG9wYzpFbnVtZXJhdGVkVHlwZSBMZ"
        << "W5ndGhJbkJpdHM9IjMyIiBOYW1lPSJFbnVtR2FwVHlwZSI+CiAgPG9wYzpFbnVtZXJhdGVkV"
        << "mFsdWUgTmFtZT0iRW51bTEiIFZhbHVlPSItMSIvPgogIDxvcGM6RW51bWVyYXRlZFZhbHVlI"
        << "E5hbWU9IkVudW0yIiBWYWx1ZT0iMyIvPgogIDxvcGM6RW51bWVyYXRlZFZhbHVlIE5hbWU9I"
        << "kVudW0zIiBWYWx1ZT0iNSIvPgogPC9vcGM6RW51bWVyYXRlZFR5cGU+CiA8b3BjOkVudW1lc"
        << "mF0ZWRUeXBlIExlbmd0aEluQml0cz0iMzIiIE5hbWU9IkVudW1TaW1wbGVUeXBlIj4KICA8b"
        << "3BjOkVudW1lcmF0ZWRWYWx1ZSBOYW1lPSJFbnVtMSIgVmFsdWU9IjAiLz4KICA8b3BjOkVud"
        << "W1lcmF0ZWRWYWx1ZSBOYW1lPSJFbnVtMiIgVmFsdWU9IjEiLz4KICA8b3BjOkVudW1lcmF0Z"
        << "WRWYWx1ZSBOYW1lPSJFbnVtMyIgVmFsdWU9IjIiLz4KIDwvb3BjOkVudW1lcmF0ZWRUeXBlP"
        << "go8L29wYzpUeXBlRGljdGlvbmFyeT4K";

	Base64::decode(ss1.str().c_str(), ss1.str().length(), buffer, len);
	std::cout << buffer << std::endl;
}



BOOST_AUTO_TEST_SUITE_END()
