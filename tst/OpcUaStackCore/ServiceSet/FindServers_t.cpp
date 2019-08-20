#include "unittest.h"
#include "boost/asio.hpp"
#include "OpcUaStackCore/ServiceSet/FindServersRequest.h"
#include "OpcUaStackCore/ServiceSet/FindServersResponse.h"
#include "OpcUaStackCore/SecureChannel/MessageHeader.h"
#include "OpcUaStackCore/SecureChannel/SequenceHeader.h"
#include "OpcUaStackCore/Base/Utility.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"

#include <streambuf>
#include <iostream>

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(FindServers_)

BOOST_AUTO_TEST_CASE(FindServers_Title)
{
	std::cout << "FindServers_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(FindServers_Request)
{
	uint32_t pos;
	OpcUaNodeId typeId;
	OpcUaGuid::SPtr opcUaGuidSPtr;
	OpcUaString::SPtr stringSPtr;
	MessageHeader::SPtr messageHeaderSPtr;
	SequenceHeader::SPtr sequenceHeaderSPtr;
	FindServersRequest::SPtr findServersRequestSPtr;
	boost::posix_time::ptime ptime = boost::posix_time::from_iso_string("16010101T000000.000000000");
	
	// stream
	boost::asio::streambuf sb1;
	std::iostream ios1(&sb1);
	boost::asio::streambuf sb2;
	std::iostream ios2(&sb2);
	boost::asio::streambuf sb;
	std::iostream ios(&sb);

	// encode security header
	OpcUaInt32 secureChannelId;
	OpcUaInt32 secureTokenId;

	secureChannelId = 153451225;
	secureTokenId = 1;

	OpcUaNumber::opcUaBinaryEncode(ios1, secureChannelId);
	OpcUaNumber::opcUaBinaryEncode(ios1, secureTokenId);

	// encode sequence header
	sequenceHeaderSPtr = boost::make_shared<SequenceHeader>();
	sequenceHeaderSPtr->sequenceNumber(54);
	sequenceHeaderSPtr->requestId(4);
	sequenceHeaderSPtr->opcUaBinaryEncode(ios1);

	// encode TypeId
	typeId.nodeId(OpcUaId_FindServersRequest_Encoding_DefaultBinary);
	typeId.opcUaBinaryEncode(ios1);

	// build 
	findServersRequestSPtr = boost::make_shared<FindServersRequest>();

	// build RequestHeader
	opcUaGuidSPtr = boost::make_shared<OpcUaGuid>();
	*opcUaGuidSPtr = "0D4455B2-8D2F-B74F-864F-0AF5945DD833";
	
	// build Parameter
	stringSPtr = boost::make_shared<OpcUaString>();
	stringSPtr->value("TestString");

	findServersRequestSPtr->endpointUrl("EndpointUrl");
	findServersRequestSPtr->localeIds()->set(stringSPtr);
	findServersRequestSPtr->serverUris()->set(stringSPtr);

	// encode
	findServersRequestSPtr->opcUaBinaryEncode(ios1);

	// encode MessageHeader
	messageHeaderSPtr = boost::make_shared<MessageHeader>();
	messageHeaderSPtr->messageType(MessageType_Message);
	messageHeaderSPtr->messageSize(OpcUaStackCore::count(sb1)+8);
	messageHeaderSPtr->opcUaBinaryEncode(ios2);

	// stream
	ios << ios2.rdbuf() << ios1.rdbuf();
	OpcUaStackCore::dumpHex(ios);
	
	std::stringstream ss;
	ss << "4d 53 47 46 4f 00 00 00  d9 7a 25 09 01 00 00 00"
       << "36 00 00 00 04 00 00 00  01 00 a6 01 0b 00 00 00"
	   << "45 6e 64 70 6f 69 6e 74  55 72 6c 01 00 00 00 0a"
	   << "00 00 00 54 65 73 74 53  74 72 69 6e 67 01 00 00"
	   << "00 0a 00 00 00 54 65 73  74 53 74 72 69 6e 67";


	BOOST_REQUIRE(OpcUaStackCore::compare(ios, ss.str(), pos) == true);

	// decode MessageHeader
	messageHeaderSPtr = boost::make_shared<MessageHeader>();
	messageHeaderSPtr->opcUaBinaryDecode(ios);
	BOOST_REQUIRE(messageHeaderSPtr->messageType() == MessageType_Message);

	// decode security header
	OpcUaNumber::opcUaBinaryDecode(ios, secureChannelId);
	BOOST_REQUIRE(secureChannelId == 153451225);
	OpcUaNumber::opcUaBinaryDecode(ios, secureTokenId);
	BOOST_REQUIRE(secureTokenId == 1);

	// decode sequence header
	sequenceHeaderSPtr = boost::make_shared<SequenceHeader>();
	sequenceHeaderSPtr->opcUaBinaryDecode(ios);
	BOOST_REQUIRE(sequenceHeaderSPtr->sequenceNumber() == 54);
	BOOST_REQUIRE(sequenceHeaderSPtr->requestId() == 4);

	// decode message type id
	typeId.opcUaBinaryDecode(ios);
	BOOST_REQUIRE(typeId.namespaceIndex() == 0);
	BOOST_REQUIRE(typeId.nodeId<OpcUaUInt32>() == OpcUaId_FindServersRequest_Encoding_DefaultBinary);

	// decode
	findServersRequestSPtr = boost::make_shared<FindServersRequest>();
	findServersRequestSPtr->opcUaBinaryDecode(ios);
	
	BOOST_REQUIRE(findServersRequestSPtr->endpointUrl().value() == "EndpointUrl");
	
	BOOST_REQUIRE(findServersRequestSPtr->localeIds()->size() == 1);
	findServersRequestSPtr->localeIds()->get(stringSPtr);
	BOOST_REQUIRE(stringSPtr->value() == "TestString");

	BOOST_REQUIRE(findServersRequestSPtr->serverUris()->size() == 1);
	findServersRequestSPtr->serverUris()->get(stringSPtr);
	BOOST_REQUIRE(stringSPtr->value() == "TestString");
}


BOOST_AUTO_TEST_CASE(FindServers_Response)
{
	uint32_t pos;
	OpcUaNodeId typeId;
	OpcUaStatusCode statusCode;
	MessageHeader::SPtr messageHeaderSPtr;
	SequenceHeader::SPtr sequenceHeaderSPtr;
	FindServersResponse::SPtr findServersResponseSPtr;
	OpcUaString::SPtr opcUaStringSPtr;
	ApplicationDescription::SPtr applicationDescriptionSPtr;
	boost::posix_time::ptime ptime;
	
	// test-time
	ptime = boost::posix_time::from_iso_string("16010101T000000.000000000");

	// stream
	boost::asio::streambuf sb1;
	std::iostream ios1(&sb1);
	boost::asio::streambuf sb2;
	std::iostream ios2(&sb2);
	boost::asio::streambuf sb;
	std::iostream ios(&sb);

	// encode security header
	OpcUaInt32 secureChannelId;
	OpcUaInt32 secureTokenId;

	secureChannelId = 153451225;
	secureTokenId = 1;

	OpcUaNumber::opcUaBinaryEncode(ios1, secureChannelId);
	OpcUaNumber::opcUaBinaryEncode(ios1, secureTokenId);

	// encode sequence header
	sequenceHeaderSPtr = boost::make_shared<SequenceHeader>();
	sequenceHeaderSPtr->sequenceNumber(54);
	sequenceHeaderSPtr->requestId(4);
	sequenceHeaderSPtr->opcUaBinaryEncode(ios1);

	// encode TypeId
	typeId.nodeId(OpcUaId_FindServersResponse_Encoding_DefaultBinary);
	typeId.opcUaBinaryEncode(ios1);

	// build 
	findServersResponseSPtr = boost::make_shared<FindServersResponse>();

	// build ApplicationDescription
	applicationDescriptionSPtr = boost::make_shared<ApplicationDescription>();
	applicationDescriptionSPtr->applicationUri().value("urn:localhost:compyny:Unittest");
	applicationDescriptionSPtr->productUri().value("urn:company:Unittest");
	applicationDescriptionSPtr->applicationName().text("company Unittest");
	applicationDescriptionSPtr->applicationType().enumeration(ApplicationType::EnumServer);
	applicationDescriptionSPtr->discoveryUrls().resize(1);
	opcUaStringSPtr = boost::make_shared<OpcUaString>();
	opcUaStringSPtr->value("opt.tcp://localhost:4841/0.0.0.0");
	applicationDescriptionSPtr->discoveryUrls().set(0, opcUaStringSPtr);
	
	findServersResponseSPtr->servers()->set(applicationDescriptionSPtr);

	// encode 
	findServersResponseSPtr->opcUaBinaryEncode(ios1);

	// encode MessageHeader
	messageHeaderSPtr = boost::make_shared<MessageHeader>();
	messageHeaderSPtr->messageType(MessageType_Message);
	messageHeaderSPtr->messageSize(OpcUaStackCore::count(sb1)+8);
	messageHeaderSPtr->opcUaBinaryEncode(ios2);

	// stream
	ios << ios2.rdbuf() << ios1.rdbuf();
	OpcUaStackCore::dumpHex(ios);

	std::stringstream ss;
	ss << "4d 53 47 46 a3 00 00 00  d9 7a 25 09 01 00 00 00"
	   << "36 00 00 00 04 00 00 00  01 00 a9 01 01 00 00 00"
	   << "1e 00 00 00 75 72 6e 3a  6c 6f 63 61 6c 68 6f 73"
	   << "74 3a 63 6f 6d 70 79 6e  79 3a 55 6e 69 74 74 65"
	   << "73 74 14 00 00 00 75 72  6e 3a 63 6f 6d 70 61 6e"
	   << "79 3a 55 6e 69 74 74 65  73 74 02 10 00 00 00 63"
	   << "6f 6d 70 61 6e 79 20 55  6e 69 74 74 65 73 74 00"
       << "00 00 00 ff ff ff ff ff  ff ff ff 01 00 00 00 20"
	   << "00 00 00 6f 70 74 2e 74  63 70 3a 2f 2f 6c 6f 63"
	   << "61 6c 68 6f 73 74 3a 34  38 34 31 2f 30 2e 30 2e"
	   << "30 2e 30";

	BOOST_REQUIRE(OpcUaStackCore::compare(ios, ss.str(), pos) == true);

	// decode MessageHeader
	messageHeaderSPtr = boost::make_shared<MessageHeader>();
	messageHeaderSPtr->opcUaBinaryDecode(ios);
	BOOST_REQUIRE(messageHeaderSPtr->messageType() == MessageType_Message);

	// decode security header
	OpcUaNumber::opcUaBinaryDecode(ios, secureChannelId);
	BOOST_REQUIRE(secureChannelId == 153451225);
	OpcUaNumber::opcUaBinaryDecode(ios, secureTokenId);
	BOOST_REQUIRE(secureTokenId == 1);

	// decode sequence header
	sequenceHeaderSPtr = boost::make_shared<SequenceHeader>();
	sequenceHeaderSPtr->opcUaBinaryDecode(ios);
	BOOST_REQUIRE(sequenceHeaderSPtr->sequenceNumber() == 54);
	BOOST_REQUIRE(sequenceHeaderSPtr->requestId() == 4);

	// decode message type id
	typeId.opcUaBinaryDecode(ios);
	BOOST_REQUIRE(typeId.namespaceIndex() == 0);
	BOOST_REQUIRE(typeId.nodeId<OpcUaUInt32>() == OpcUaId_FindServersResponse_Encoding_DefaultBinary);

	// decode 
	findServersResponseSPtr = boost::make_shared<FindServersResponse>();
	findServersResponseSPtr->opcUaBinaryDecode(ios);

	BOOST_REQUIRE(findServersResponseSPtr->servers()->size() == 1);
	applicationDescriptionSPtr = boost::make_shared<ApplicationDescription>();
	findServersResponseSPtr->servers()->get(applicationDescriptionSPtr);
	BOOST_REQUIRE(applicationDescriptionSPtr->applicationUri().value() == "urn:localhost:compyny:Unittest");
	BOOST_REQUIRE(applicationDescriptionSPtr->productUri().value() == "urn:company:Unittest");
	BOOST_REQUIRE(applicationDescriptionSPtr->applicationName().text().value() == "company Unittest");
	BOOST_REQUIRE(applicationDescriptionSPtr->applicationType().enumeration() == ApplicationType::EnumServer);
	applicationDescriptionSPtr->discoveryUrls().get(0, opcUaStringSPtr);
	BOOST_REQUIRE(opcUaStringSPtr->value() == "opt.tcp://localhost:4841/0.0.0.0");
}

BOOST_AUTO_TEST_SUITE_END()
