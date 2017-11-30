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

#define ENCODE_DECODE(header, hexString, restoredHeader) {								\
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


#define SHOULD_ENCODE_DECODE(header, hexString) { 										\
	NetworkMessageHeader restoredHeader;                                                \
	ENCODE_DECODE(header, hexString, restoredHeader);                                   \
                                                                                        \
	BOOST_REQUIRE(restoredHeader == header);                                            \
} while(0)


BOOST_AUTO_TEST_CASE(NetworkMessageHeader_encode_decode_all_flags_set)
{
	NetworkMessageHeader header;
	header.publisherIdEnabled(true);
	header.dataSetArrayEnabled(true);
	header.dataSetWriterIdEnabled(true);
	header.dataSetClassIdEnabled(true);
	header.timestampEnabled(true);
	header.picoSecondsEnabled(true);

	header.publisherIdType(PublisherIdType_UInt16);

	OpcUaVariant::SPtr publisherId = constructSPtr<OpcUaVariant>();
	publisherId->set<OpcUaUInt16>(0x23);
	header.publisherId(publisherId);

	header.dataSetPayloadHeader()->dataSetWriterIds()->resize(2);
	header.dataSetPayloadHeader()->dataSetWriterIds()->push_back(0x100);
	header.dataSetPayloadHeader()->dataSetWriterIds()->push_back(0x090);

	OpcUaGuid::SPtr classId = constructSPtr<OpcUaGuid>();
	classId->value("12345678-9ABC-DEF0-1234-56789ABCDEF0");
	header.dataSetClassId(classId);

	OpcUaDateTime time;
	time.fromISOString("20171125T203617.900");
	header.timestamp(time);

	header.picoSeconds(0x100);

	SHOULD_ENCODE_DECODE(header,
			"f4 69 "											// flags
			"23 00 "											// publisherId
			"12 34 56 78 9a bc de f0 12 34 56 78 9a bc de f0 "  // dataSetClassId
			"02 00 01 90 00 "									// dataSetPayloadHeader
			"c0 0a a8 0b 2d 66 d3 01 "	                        // timestamp
			"00 01"
	);
}

BOOST_AUTO_TEST_CASE(NetworkMessageHeader_encode_decode_UADPVersion)
{
	NetworkMessageHeader header;

	SHOULD_ENCODE_DECODE(header, "04");
}

BOOST_AUTO_TEST_CASE(NetworkMessageHeader_encode_decode_publisherId)
{
	NetworkMessageHeader header;
	header.publisherIdEnabled(true);

	OpcUaVariant::SPtr publisherId = constructSPtr<OpcUaVariant>();
	publisherId->set<OpcUaByte>(0x23);
	header.publisherId(publisherId);

	SHOULD_ENCODE_DECODE(header, "14 23");
}

BOOST_AUTO_TEST_CASE(NetworkMessageHeader_encode_decode_dataSetArrayEnabled)
{
	NetworkMessageHeader header;
	header.dataSetArrayEnabled(true);
	header.dataSetWriterIdEnabled(true);
	header.dataSetPayloadHeader()->dataSetWriterIds()->resize(2);
	header.dataSetPayloadHeader()->dataSetWriterIds()->push_back(0x100);
	header.dataSetPayloadHeader()->dataSetWriterIds()->push_back(0x090);

	SHOULD_ENCODE_DECODE(header, "64 02 00 01 90 00");
}

BOOST_AUTO_TEST_CASE(NetworkMessageHeader_encode_decode_dataSetWriterIdEnabled)
{
	NetworkMessageHeader header;
	header.dataSetWriterIdEnabled(true);
	header.dataSetPayloadHeader()->dataSetWriterIds()->resize(1);
	header.dataSetPayloadHeader()->dataSetWriterIds()->push_back(0x100);

	SHOULD_ENCODE_DECODE(header, "44 00 01");
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
	ENCODE_DECODE(header, "44 20 01", restoredHeader);

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

	SHOULD_ENCODE_DECODE(header, "84 00");
}

BOOST_AUTO_TEST_CASE(NetworkMessageHeader_encode_decode_publisherIdType_Uint16)
{
	NetworkMessageHeader header;
	header.publisherIdEnabled(true);
	header.publisherIdType(PublisherIdType_UInt16);

	OpcUaVariant::SPtr publisherId = constructSPtr<OpcUaVariant>();
	publisherId->set<OpcUaUInt16>(0x1234);
	header.publisherId(publisherId);

	SHOULD_ENCODE_DECODE(header, "94 01 34 12");
}

BOOST_AUTO_TEST_CASE(NetworkMessageHeader_encode_decode_publisherIdType_Uint32)
{
	NetworkMessageHeader header;
	header.publisherIdEnabled(true);
	header.publisherIdType(PublisherIdType_UInt32);

	OpcUaVariant::SPtr publisherId = constructSPtr<OpcUaVariant>();
	publisherId->set<OpcUaUInt32>(0x12345678);
	header.publisherId(publisherId);

	SHOULD_ENCODE_DECODE(header, "94 02 78 56 34 12");
}

BOOST_AUTO_TEST_CASE(NetworkMessageHeader_encode_decode_publisherIdType_Uint64)
{
	NetworkMessageHeader header;
	header.extendedFlags1Enabled(true);
	header.publisherIdEnabled(true);
	header.publisherIdType(PublisherIdType_UInt64);

	OpcUaVariant::SPtr publisherId = constructSPtr<OpcUaVariant>();
	publisherId->set<OpcUaUInt64>(0x123456780a0b0c0d);
	header.publisherId(publisherId);

	SHOULD_ENCODE_DECODE(header, "94 03 0D 0C 0B 0A 78 56 34 12");
}

BOOST_AUTO_TEST_CASE(NetworkMessageHeader_encode_decode_publisherIdType_GUID)
{
	NetworkMessageHeader header;
	header.publisherIdEnabled(true);
	header.publisherIdType(PublisherIdType_Guid);

	OpcUaVariant::SPtr publisherId = constructSPtr<OpcUaVariant>();
	OpcUaGuid guid;
	guid.value("12345678-9ABC-DEF0-1234-56789ABCDEF0");
	publisherId->setValue(guid);
	header.publisherId(publisherId);

	SHOULD_ENCODE_DECODE(header, "94 04 12 34 56 78 9a bc de f0 12 34 56 78 9a bc de f0");
}

BOOST_AUTO_TEST_CASE(NetworkMessageHeader_encode_decode_publisherIdType_String)
{
	NetworkMessageHeader header;
	header.publisherIdEnabled(true);
	header.publisherIdType(PublisherIdType_String);

	OpcUaVariant::SPtr publisherId = constructSPtr<OpcUaVariant>();
	publisherId->setValue(OpcUaString("StringID"));
	header.publisherId(publisherId);

	SHOULD_ENCODE_DECODE(header, "94 05 08 00 00 00 53 74 72 69 6e 67 49 44");
}

BOOST_AUTO_TEST_CASE(NetworkMessageHeader_encode_decode_dataSetClassIdEnabled)
{
	NetworkMessageHeader header;

	OpcUaGuid::SPtr classId = constructSPtr<OpcUaGuid>();
	classId->value("12345678-9ABC-DEF0-1234-56789ABCDEF0");
	header.dataSetClassId(classId);

	SHOULD_ENCODE_DECODE(header, "84 08 12 34 56 78 9a bc de f0 12 34 56 78 9a bc de f0");
}

BOOST_AUTO_TEST_CASE(NetworkMessageHeader_encode_decode_timestampEnabled)
{
	NetworkMessageHeader header;

	OpcUaDateTime time;
	time.fromISOString("20171125T203617.900");
	header.timestamp(time);

	SHOULD_ENCODE_DECODE(header, "84 20 c0 0a a8 0b 2d 66 d3 01");
}

BOOST_AUTO_TEST_CASE(NetworkMessageHeader_encode_decode_picosecondsEnabled)
{
	NetworkMessageHeader header;
	header.picoSeconds(0x100);

	SHOULD_ENCODE_DECODE(header, "84 40 00 01");
}

BOOST_AUTO_TEST_SUITE_END()

