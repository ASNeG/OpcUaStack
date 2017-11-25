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

#define DECODE_ENCODE(header, hexString, restoredHeader) {								\
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
	restoredHeader.opcUaBinaryDecode(ios);                                              \
} while(0)


#define SHOULD_DECODE_ENCODE(header, hexString) { 										\
	NetworkMessageHeader restoredHeader;                                                \
	DECODE_ENCODE(header, hexString, restoredHeader);                                   \
                                                                                        \
	BOOST_REQUIRE(restoredHeader == header);                                            \
} while(0)



BOOST_AUTO_TEST_CASE(NetworkMessageHeader_encode_decode_UADPVersion)
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
	header.dataSetWriterIdEnabled(true);
	header.dataSetPayloadHeader()->dataSetWriterIds()->resize(2);
	header.dataSetPayloadHeader()->dataSetWriterIds()->push_back(0x100);
	header.dataSetPayloadHeader()->dataSetWriterIds()->push_back(0x090);

	SHOULD_DECODE_ENCODE(header, "64 02 00 01 90 00");
}

BOOST_AUTO_TEST_CASE(NetworkMessageHeader_encode_decode_dataSetWriterIdEnabled)
{
	NetworkMessageHeader header;
	header.dataSetWriterIdEnabled(true);
	header.dataSetPayloadHeader()->dataSetWriterIds()->resize(1);
	header.dataSetPayloadHeader()->dataSetWriterIds()->push_back(0x100);

	SHOULD_DECODE_ENCODE(header, "44 00 01");
}

BOOST_AUTO_TEST_CASE(NetworkMessageHeader_encode_decode_dataSetWriterIdDisabled_but_Array)
{
	NetworkMessageHeader header;
	header.dataSetWriterIdEnabled(true);
	header.dataSetPayloadHeader()->dataSetWriterIds()->resize(3);
	header.dataSetPayloadHeader()->dataSetWriterIds()->push_back(0x120);
	header.dataSetPayloadHeader()->dataSetWriterIds()->push_back(0x90);
	header.dataSetPayloadHeader()->dataSetWriterIds()->push_back(0x50);

	NetworkMessageHeader restoredHeader;
	DECODE_ENCODE(header, "44 20 01", restoredHeader);

	BOOST_REQUIRE(restoredHeader.dataSetArrayEnabled() == false);
	BOOST_REQUIRE(restoredHeader.dataSetWriterIdEnabled() == true);
	BOOST_REQUIRE_EQUAL(1, restoredHeader.dataSetPayloadHeader()->dataSetWriterIds()->size());

	OpcUaUInt16 id;
	restoredHeader.dataSetPayloadHeader()->dataSetWriterIds()->get(0, id);
	BOOST_REQUIRE_EQUAL(0x120, id);
}

BOOST_AUTO_TEST_CASE(NetworkMessageHeader_encode_decode_extendedFlags1Enabled)
{
	NetworkMessageHeader header;
	header.extendedFlags1Enabled(true);

	SHOULD_DECODE_ENCODE(header, "84 00");
}


BOOST_AUTO_TEST_SUITE_END()

