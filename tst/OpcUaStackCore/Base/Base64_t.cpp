#include "unittest.h"
#include <cmath>
#include <iostream>
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

BOOST_AUTO_TEST_CASE(Base64_decode3)
{
	std::stringstream ss1;
	char buffer[5000];
	uint32_t len = 5000;

	memset(buffer, 0x00, 5000);
	ss1	<< "PHhzOnNjaGVtYSBlbGVtZW50Rm9ybURlZmF1bHQ9InF1YWxpZmllZCIgdGFyZ2V0TmFtZXNwYWNlPSJod"
		<< "HRwOi8veW91cm9yZ2FuaXNhdGlvbi5vcmcvTm9kZVNldEV4YW1wbGUvVHlwZXMueHNkIiB4b"
        << "Wxuczp0bnM9Imh0dHA6Ly95b3Vyb3JnYW5pc2F0aW9uLm9yZy9Ob2RlU2V0RXhhbXBsZS9Ue"
        << "XBlcy54c2QiIHhtbG5zOnVhPSJodHRwOi8vb3BjZm91bmRhdGlvbi5vcmcvVUEvMjAwOC8wM"
        << "i9UeXBlcy54c2QiIHhtbG5zOnhzPSJodHRwOi8vd3d3LnczLm9yZy8yMDAxL1hNTFNjaGVtY"
        << "SI+CiA8eHM6aW1wb3J0IG5hbWVzcGFjZT0iaHR0cDovL29wY2ZvdW5kYXRpb24ub3JnL1VBL"
        << "zIwMDgvMDIvVHlwZXMueHNkIi8+CiA8eHM6c2ltcGxlVHlwZSBuYW1lPSJFbnVtR2FwVHlwZ"
        << "SI+CiAgPHhzOnJlc3RyaWN0aW9uIGJhc2U9InhzOnN0cmluZyI+CiAgIDx4czplbnVtZXJhd"
        << "GlvbiB2YWx1ZT0iRW51bTFfLTEiLz4KICAgPHhzOmVudW1lcmF0aW9uIHZhbHVlPSJFbnVtM"
        << "l8zIi8+CiAgIDx4czplbnVtZXJhdGlvbiB2YWx1ZT0iRW51bTNfNSIvPgogIDwveHM6cmVzd"
        << "HJpY3Rpb24+CiA8L3hzOnNpbXBsZVR5cGU+CiA8eHM6ZWxlbWVudCB0eXBlPSJ0bnM6RW51b"
        << "UdhcFR5cGUiIG5hbWU9IkVudW1HYXBUeXBlIi8+CiA8eHM6Y29tcGxleFR5cGUgbmFtZT0iT"
        << "GlzdE9mRW51bUdhcFR5cGUiPgogIDx4czpzZXF1ZW5jZT4KICAgPHhzOmVsZW1lbnQgbWluT"
        << "2NjdXJzPSIwIiBtYXhPY2N1cnM9InVuYm91bmRlZCIgdHlwZT0idG5zOkVudW1HYXBUeXBlI"
        << "iBuYW1lPSJFbnVtR2FwVHlwZSIgbmlsbGFibGU9InRydWUiLz4KICA8L3hzOnNlcXVlbmNlP"
        << "gogPC94czpjb21wbGV4VHlwZT4KIDx4czplbGVtZW50IHR5cGU9InRuczpMaXN0T2ZFbnVtR"
        << "2FwVHlwZSIgbmFtZT0iTGlzdE9mRW51bUdhcFR5cGUiIG5pbGxhYmxlPSJ0cnVlIi8+CiA8e"
        << "HM6c2ltcGxlVHlwZSBuYW1lPSJFbnVtU2ltcGxlVHlwZSI+CiAgPHhzOnJlc3RyaWN0aW9uI"
        << "GJhc2U9InhzOnN0cmluZyI+CiAgIDx4czplbnVtZXJhdGlvbiB2YWx1ZT0iRW51bTFfMCIvP"
        << "gogICA8eHM6ZW51bWVyYXRpb24gdmFsdWU9IkVudW0yXzEiLz4KICAgPHhzOmVudW1lcmF0a"
        << "W9uIHZhbHVlPSJFbnVtM18yIi8+CiAgPC94czpyZXN0cmljdGlvbj4KIDwveHM6c2ltcGxlV"
        << "HlwZT4KIDx4czplbGVtZW50IHR5cGU9InRuczpFbnVtU2ltcGxlVHlwZSIgbmFtZT0iRW51b"
        << "VNpbXBsZVR5cGUiLz4KIDx4czpjb21wbGV4VHlwZSBuYW1lPSJMaXN0T2ZFbnVtU2ltcGxlV"
        << "HlwZSI+CiAgPHhzOnNlcXVlbmNlPgogICA8eHM6ZWxlbWVudCBtaW5PY2N1cnM9IjAiIG1he"
        << "E9jY3Vycz0idW5ib3VuZGVkIiB0eXBlPSJ0bnM6RW51bVNpbXBsZVR5cGUiIG5hbWU9IkVud"
        << "W1TaW1wbGVUeXBlIiBuaWxsYWJsZT0idHJ1ZSIvPgogIDwveHM6c2VxdWVuY2U+CiA8L3hzO"
        << "mNvbXBsZXhUeXBlPgogPHhzOmVsZW1lbnQgdHlwZT0idG5zOkxpc3RPZkVudW1TaW1wbGVUe"
        << "XBlIiBuYW1lPSJMaXN0T2ZFbnVtU2ltcGxlVHlwZSIgbmlsbGFibGU9InRydWUiLz4KIDx4c"
        << "zpjb21wbGV4VHlwZSBuYW1lPSJNeUNvbXBsZXhTdHJ1Y3R1cmVUeXBlIj4KICA8eHM6c2Vxd"
        << "WVuY2U+CiAgIDx4czplbGVtZW50IG1pbk9jY3Vycz0iMCIgbWF4T2NjdXJzPSIxIiB0eXBlP"
        << "SJ4czpkb3VibGUiIG5hbWU9IkVsZW1lbnQxIi8+CiAgIDx4czplbGVtZW50IG1pbk9jY3Vyc"
        << "z0iMCIgbWF4T2NjdXJzPSIxIiB0eXBlPSJ0bnM6TXlTdHJ1Y3R1cmVUeXBlIiBuYW1lPSJFb"
        << "GVtZW50MiIvPgogICA8eHM6ZWxlbWVudCBtaW5PY2N1cnM9IjAiIG1heE9jY3Vycz0iMSIgd"
        << "HlwZT0idG5zOkVudW1TaW1wbGVUeXBlIiBuYW1lPSJFbGVtZW50MyIvPgogIDwveHM6c2Vxd"
        << "WVuY2U+CiA8L3hzOmNvbXBsZXhUeXBlPgogPHhzOmVsZW1lbnQgdHlwZT0idG5zOk15Q29tc"
        << "GxleFN0cnVjdHVyZVR5cGUiIG5hbWU9Ik15Q29tcGxleFN0cnVjdHVyZVR5cGUiLz4KIDx4c"
        << "zpjb21wbGV4VHlwZSBuYW1lPSJMaXN0T2ZNeUNvbXBsZXhTdHJ1Y3R1cmVUeXBlIj4KICA8e"
        << "HM6c2VxdWVuY2U+CiAgIDx4czplbGVtZW50IG1pbk9jY3Vycz0iMCIgbWF4T2NjdXJzPSJ1b"
        << "mJvdW5kZWQiIHR5cGU9InRuczpNeUNvbXBsZXhTdHJ1Y3R1cmVUeXBlIiBuYW1lPSJNeUNvb"
        << "XBsZXhTdHJ1Y3R1cmVUeXBlIiBuaWxsYWJsZT0idHJ1ZSIvPgogIDwveHM6c2VxdWVuY2U+C"
        << "iA8L3hzOmNvbXBsZXhUeXBlPgogPHhzOmVsZW1lbnQgdHlwZT0idG5zOkxpc3RPZk15Q29tc"
        << "GxleFN0cnVjdHVyZVR5cGUiIG5hbWU9Ikxpc3RPZk15Q29tcGxleFN0cnVjdHVyZVR5cGUiI"
        << "G5pbGxhYmxlPSJ0cnVlIi8+CiA8eHM6Y29tcGxleFR5cGUgbmFtZT0iTXlTdHJ1Y3R1cmVUe"
        << "XBlIj4KICA8eHM6c2VxdWVuY2U+CiAgIDx4czplbGVtZW50IG1pbk9jY3Vycz0iMCIgdHlwZ"
        << "T0ieHM6dW5zaWduZWRJbnQiIG5hbWU9IkVuY29kaW5nTWFzayIvPgogICA8eHM6ZWxlbWVud"
        << "CBtaW5PY2N1cnM9IjAiIG1heE9jY3Vycz0iMSIgdHlwZT0ieHM6ZG91YmxlIiBuYW1lPSJFb"
        << "GVtZW50MSIvPgogICA8eHM6ZWxlbWVudCBtaW5PY2N1cnM9IjAiIG1heE9jY3Vycz0iMSIgd"
        << "HlwZT0ieHM6ZG91YmxlIiBuYW1lPSJFbGVtZW50MiIvPgogICA8eHM6ZWxlbWVudCBtaW5PY"
        << "2N1cnM9IjAiIG1heE9jY3Vycz0iMSIgdHlwZT0ieHM6ZG91YmxlIiBuYW1lPSJFbGVtZW50M"
        << "yIvPgogIDwveHM6c2VxdWVuY2U+CiAgPHhzOmF0dHJpYnV0ZSBuYW1lPSJFbmNvZGluZ1RhY"
        << "mxlIiBmaXhlZD0iRWxlbWVudDM6MCIvPgogPC94czpjb21wbGV4VHlwZT4KIDx4czplbGVtZ"
        << "W50IHR5cGU9InRuczpNeVN0cnVjdHVyZVR5cGUiIG5hbWU9Ik15U3RydWN0dXJlVHlwZSIvP"
        << "gogPHhzOmNvbXBsZXhUeXBlIG5hbWU9Ikxpc3RPZk15U3RydWN0dXJlVHlwZSI+CiAgPHhzO"
        << "nNlcXVlbmNlPgogICA8eHM6ZWxlbWVudCBtaW5PY2N1cnM9IjAiIG1heE9jY3Vycz0idW5ib"
        << "3VuZGVkIiB0eXBlPSJ0bnM6TXlTdHJ1Y3R1cmVUeXBlIiBuYW1lPSJNeVN0cnVjdHVyZVR5c"
        << "GUiIG5pbGxhYmxlPSJ0cnVlIi8+CiAgPC94czpzZXF1ZW5jZT4KIDwveHM6Y29tcGxleFR5c"
        << "GU+CiA8eHM6ZWxlbWVudCB0eXBlPSJ0bnM6TGlzdE9mTXlTdHJ1Y3R1cmVUeXBlIiBuYW1lP"
        << "SJMaXN0T2ZNeVN0cnVjdHVyZVR5cGUiIG5pbGxhYmxlPSJ0cnVlIi8+CjwveHM6c2NoZW1hP"
        << "go=";

	Base64::decode(ss1.str().c_str(), ss1.str().length(), buffer, len);
	std::cout << buffer << std::endl;
}

BOOST_AUTO_TEST_CASE(Base64_buf_len)
{
	std::cout << "Base64Len=" << Base64::asciiLen2base64Len(22) << std::endl;
	std::cout << "AsciiLen= " << Base64::base64Len2asciiLen(32) << std::endl;
	BOOST_REQUIRE(Base64::asciiLen2base64Len(22) == 32);
	BOOST_REQUIRE(Base64::base64Len2asciiLen(33) == 24);
}

BOOST_AUTO_TEST_CASE(Base64_buf_len_padding)
{
	BOOST_REQUIRE(Base64::base64Len2asciiLen(4, 2) == 1);
	BOOST_REQUIRE(Base64::base64Len2asciiLen(4, 1) == 2);
	BOOST_REQUIRE(Base64::base64Len2asciiLen(4, 0) == 3);
	BOOST_REQUIRE(Base64::base64Len2asciiLen(8, 2) == 4);
	BOOST_REQUIRE(Base64::base64Len2asciiLen(8, 1) == 5);
	BOOST_REQUIRE(Base64::base64Len2asciiLen(8, 0) == 6);
}

BOOST_AUTO_TEST_CASE(Base64_encode_decode)
{
	std::string str = "Dies ist ein ByteString";

	char base64Buf[33];
	uint32_t base64BufLen = 32;
	memset(base64Buf, 0x00, 33);

	BOOST_REQUIRE(Base64::encode(str.c_str(), str.length(), base64Buf, base64BufLen) == true);
	std::cout << base64Buf << std::endl;

	char asciiBuf[25];
	uint32_t asciiBufLen = 24;
	memset(asciiBuf, 0x00, 24);

	BOOST_REQUIRE(Base64::decode(base64Buf, base64BufLen, asciiBuf, asciiBufLen) == true);
	BOOST_REQUIRE(strcmp(asciiBuf, "Dies ist ein ByteString") == 0);
}



BOOST_AUTO_TEST_SUITE_END()
