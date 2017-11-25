#include "unittest.h"

#include <iostream>
#include <boost/asio.hpp>

#include "OpcUaStackPubSub/Network/NetworkMessageHeader.h"
#include "OpcUaStackCore/Base/Utility.h"

using namespace OpcUaStackCore;
using namespace OpcUaStackPubSub;



BOOST_AUTO_TEST_SUITE(NetworkMessageHeader_)

BOOST_AUTO_TEST_CASE(NetworkMessageHeader_)
{
	std::cout << "NetworkMessageHeader_t" << std::endl;
}

#define SHOULD_DECODE_ENCODE(header, hexString) { 										\
	boost::asio::streambuf sb;															\
	std::iostream ios(&sb);                                                             \
	uint32_t pos;                                                                       \
                                                                                        \
	header.opcUaBinaryEncode(ios);                                                      \
                                                                                        \
	OpcUaStackCore::dumpHex(ios);                                                       \
	std::stringstream ss;                                                               \
	ss	<< hexString;                                                                   \
                                                                                        \
	BOOST_REQUIRE(OpcUaStackCore::compare(ios, ss.str(), pos));                         \
                                                                                        \
	NetworkMessageHeader restoredHeader;                                                \
	restoredHeader.opcUaBinaryDecode(ios);                                              \
                                                                                        \
	BOOST_REQUIRE(restoredHeader == header);                                            \
} while(0)

BOOST_AUTO_TEST_CASE(NetworkMessageHeader_encode_decode)
{
	NetworkMessageHeader header;

	SHOULD_DECODE_ENCODE(header, "04");
}

BOOST_AUTO_TEST_CASE(NetworkMessageHeader_encode_decode_publisherId)
{
	NetworkMessageHeader header;
	header.publisherIdEnabled(true);

	OpcUaVariant::SPtr publisherId = constructSPtr<OpcUaVariant>();
	publisherId->set<OpcUaByte>(0x23);
	header.publisherId(publisherId);

	SHOULD_DECODE_ENCODE(header, "14 23");
}

BOOST_AUTO_TEST_CASE(NetworkMessageHeader_encode_decode_dataSetArrayEnabled)
{
	NetworkMessageHeader header;
	header.dataSetArrayEnabled(true);

	SHOULD_DECODE_ENCODE(header, "24");
}

BOOST_AUTO_TEST_SUITE_END()

