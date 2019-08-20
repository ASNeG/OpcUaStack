#include "unittest.h"
#include "boost/asio.hpp"
#include "OpcUaStackCore/SecureChannel/ResponseHeader.h"
#include "OpcUaStackCore/Base/Utility.h"

#include <streambuf>
#include <iostream>

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(ResponseHeader_)

BOOST_AUTO_TEST_CASE(ResponseHeader_)
{
	std::cout << "ResponseHeader_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(ResponseHeader_encode_decode)
{
	boost::posix_time::ptime ptime1;
	boost::posix_time::ptime ptime2;
	boost::asio::streambuf sb1;
	std::iostream ios1(&sb1);
	ResponseHeader::SPtr responseHeaderSPtr;

	ptime1 = boost::posix_time::from_iso_string("20140629T200209.111000000");
	responseHeaderSPtr = boost::make_shared<ResponseHeader>();
	responseHeaderSPtr->time(ptime1);
	responseHeaderSPtr->opcUaBinaryEncode(ios1);

	// stream
	OpcUaStackCore::dumpHex(ios1);

	responseHeaderSPtr = boost::make_shared<ResponseHeader>();
	responseHeaderSPtr->opcUaBinaryDecode(ios1);
	ptime2 = responseHeaderSPtr->time().dateTime();
	BOOST_REQUIRE(ptime1 == ptime2);
}

BOOST_AUTO_TEST_SUITE_END()
