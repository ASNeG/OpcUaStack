#include "unittest.h"
#include "boost/asio.hpp"
#include "OpcUaStackCore/SecureChannel/RequestHeader.h"
#include "OpcUaStackCore/Base/Utility.h"

#include <streambuf>
#include <iostream>

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(RequestHeader_)

BOOST_AUTO_TEST_CASE(RequestHeader_)
{
	std::cout << "RequestHeader_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(RequestHeader_encode_decode)
{
	boost::posix_time::ptime ptime1;
	boost::posix_time::ptime ptime2;
	boost::asio::streambuf sb1;
	std::iostream ios1(&sb1);
	RequestHeader::SPtr requestHeaderSPtr;

	ptime1 = boost::posix_time::from_iso_string("20140629T200209.111000000");
	requestHeaderSPtr = boost::make_shared<RequestHeader>();
	requestHeaderSPtr->time(ptime1);
	requestHeaderSPtr->opcUaBinaryEncode(ios1);

	// stream
	OpcUaStackCore::dumpHex(ios1);

	requestHeaderSPtr = boost::make_shared<RequestHeader>();
	requestHeaderSPtr->opcUaBinaryDecode(ios1);
	ptime2 = requestHeaderSPtr->time().dateTime();
	BOOST_REQUIRE(ptime1 == ptime2);
}

BOOST_AUTO_TEST_SUITE_END()
