#include "unittest.h"
#include "boost/asio.hpp"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackCore/SecureChannel/MessageHeader.h"
#include "OpcUaStackCore/SecureChannel/SequenceHeader.h"
#include "OpcUaStackCore/ServiceSet/CreateSessionRequest.h"
#include "OpcUaStackCore/ServiceSet/CreateSessionResponse.h"
#include "OpcUaStackCore/Base/Utility.h"

#include <streambuf>
#include <iostream>

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(CreateSession_)

BOOST_AUTO_TEST_CASE(CreateSession_)
{
	std::cout << "CreateSession_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(CreateSession_Request)
{
	uint32_t pos;
	MessageHeader::SPtr messageHeaderSPtr;
	boost::posix_time::ptime ptime = boost::posix_time::from_iso_string("16010101T120000.000000000");
	OpcUaGuid::SPtr opcUaGuidSPtr;
	CreateSessionRequest::SPtr createSessionRequestSPtr;
	SequenceHeader::SPtr sequenceHeaderSPtr;
	OpcUaNodeId typeId;
	OpcUaByte* opcUaByte;
	OpcUaInt32 opcUaByteLen;

	// stream
	boost::asio::streambuf sb1;
	std::iostream ios1(&sb1);
	boost::asio::streambuf sb2;
	std::iostream ios2(&sb2);
	boost::asio::streambuf sb;
	std::iostream ios(&sb);

	// encode channel id
	OpcUaUInt32 channelId;
	channelId = 153451225;
	OpcUaStackCore::opcUaBinaryEncode(ios1, channelId);

	// encode token id
	OpcUaInt32 tokenId;
	tokenId = 1;
	OpcUaStackCore::opcUaBinaryEncode(ios1, tokenId);

	// encode sequence header
	sequenceHeaderSPtr = SequenceHeader::construct();
	sequenceHeaderSPtr->sequenceNumber(52);
	sequenceHeaderSPtr->requestId(2);
	sequenceHeaderSPtr->opcUaBinaryEncode(ios1);

	// encode message type id
	typeId.nodeId(OpcUaId_CreateSessionRequest_Encoding_DefaultBinary);
	typeId.opcUaBinaryEncode(ios1);

	// encode CreateSessionRequest
	opcUaGuidSPtr = OpcUaGuid::construct();
	*opcUaGuidSPtr = "12345678-9ABC-DEF0-1234-56789ABCDEF0";

	OpcUaByte clientNonce[1];
	clientNonce[0] = 0x00;
	createSessionRequestSPtr = CreateSessionRequest::construct();
	createSessionRequestSPtr->requestHeader(RequestHeader::construct());
	createSessionRequestSPtr->clientDescription(ApplicationDescription::construct());
	createSessionRequestSPtr->clientDescription()->discoveryUrls(OpcUaStringArray::construct());

	createSessionRequestSPtr->requestHeader()->sessionAuthenticationToken().namespaceIndex(1);
	createSessionRequestSPtr->requestHeader()->sessionAuthenticationToken().nodeId(opcUaGuidSPtr);
	createSessionRequestSPtr->requestHeader()->time(ptime);
	createSessionRequestSPtr->requestHeader()->requestHandle(1);
	createSessionRequestSPtr->requestHeader()->returnDisagnostics(0);
	createSessionRequestSPtr->requestHeader()->timeoutHint(10000);

	createSessionRequestSPtr->clientDescription()->applicationUri("urn:localhost:compyny:Unittest");
	createSessionRequestSPtr->clientDescription()->productUri("urn:company:Unittest");
	createSessionRequestSPtr->clientDescription()->applicationName().text("company Unittest");
	createSessionRequestSPtr->clientDescription()->applicationType(ApplicationType_Client);

	createSessionRequestSPtr->endpointUrl("opc.tcp://localhost:4841");
	createSessionRequestSPtr->sessionName("urn:localhost:company:Unittest");
	createSessionRequestSPtr->clientNonce((OpcUaByte*)"0123456789", 10);
	createSessionRequestSPtr->clientCertificate((OpcUaByte*)"0123456789", 10);
	createSessionRequestSPtr->requestSessionTimeout(1200000);
	createSessionRequestSPtr->maxResponseMessageSize(0);

	createSessionRequestSPtr->opcUaBinaryEncode(ios1);

	// encode MessageHeader
	messageHeaderSPtr = MessageHeader::construct();
	messageHeaderSPtr->messageType(MessageType_Message);
	messageHeaderSPtr->messageSize(OpcUaStackCore::count(sb1)+8);
	messageHeaderSPtr->opcUaBinaryEncode(ios2);

	// stream
	ios << ios2.rdbuf() << ios1.rdbuf();
	OpcUaStackCore::dumpHex(ios);

	std::stringstream ss;
	ss	<< "4d 53 47 46 13 01 00 00  d9 7a 25 09 01 00 00 00"
		<< "34 00 00 00 02 00 00 00  01 00 cd 01 04 01 00 12"
		<< "34 56 78 9a bc de f0 12  34 56 78 9a bc de f0 00"
		<< "00 00 00 00 00 00 00 01  00 00 00 00 00 00 00 ff"
		<< "ff ff ff 10 27 00 00 00  00 00 1e 00 00 00 75 72"
		<< "6e 3a 6c 6f 63 61 6c 68  6f 73 74 3a 63 6f 6d 70"
		<< "79 6e 79 3a 55 6e 69 74  74 65 73 74 14 00 00 00"
		<< "75 72 6e 3a 63 6f 6d 70  61 6e 79 3a 55 6e 69 74"
		<< "74 65 73 74 02 10 00 00  00 63 6f 6d 70 61 6e 79"
		<< "20 55 6e 69 74 74 65 73  74 01 00 00 00 ff ff ff"
		<< "ff ff ff ff ff 00 00 00  00 ff ff ff ff 18 00 00"
		<< "00 6f 70 63 2e 74 63 70  3a 2f 2f 6c 6f 63 61 6c"
		<< "68 6f 73 74 3a 34 38 34  31 1e 00 00 00 75 72 6e"
		<< "3a 6c 6f 63 61 6c 68 6f  73 74 3a 63 6f 6d 70 61"
		<< "6e 79 3a 55 6e 69 74 74  65 73 74 0a 00 00 00 30"
		<< "31 32 33 34 35 36 37 38  39 0a 00 00 00 30 31 32"
		<< "33 34 35 36 37 38 39 00  00 00 00 80 4f 32 41 00"
		<< "00 00 00";
		BOOST_REQUIRE(OpcUaStackCore::compare(ios, ss.str(), pos) == true);

	// decode MessageHeader
	messageHeaderSPtr = MessageHeader::construct();
	messageHeaderSPtr->opcUaBinaryDecode(ios);
	BOOST_REQUIRE(messageHeaderSPtr->messageType() == MessageType_Message);
	
	// decode channel id
	OpcUaStackCore::opcUaBinaryDecode(ios, channelId);
	BOOST_REQUIRE(channelId == 153451225);

	// decode token id
	OpcUaStackCore::opcUaBinaryDecode(ios, tokenId);
	BOOST_REQUIRE(tokenId == 1);
	
	// decode sequence header
	sequenceHeaderSPtr = SequenceHeader::construct();
	sequenceHeaderSPtr->opcUaBinaryDecode(ios);
	BOOST_REQUIRE(sequenceHeaderSPtr->sequenceNumber() == 52);
	BOOST_REQUIRE(sequenceHeaderSPtr->requestId() == 2);

	// decode message type id
	typeId.opcUaBinaryDecode(ios);
	BOOST_REQUIRE(typeId.namespaceIndex() == 0);
	BOOST_REQUIRE(typeId.nodeId<OpcUaUInt32>() == OpcUaId_CreateSessionRequest_Encoding_DefaultBinary);

	// decode CreateSessionRequest
	createSessionRequestSPtr = CreateSessionRequest::construct();
	createSessionRequestSPtr->requestHeader(RequestHeader::construct());
	createSessionRequestSPtr->clientDescription(ApplicationDescription::construct());
	createSessionRequestSPtr->clientDescription()->discoveryUrls(OpcUaStringArray::construct());
	createSessionRequestSPtr->opcUaBinaryDecode(ios);

	std::string str;
	str = *createSessionRequestSPtr->requestHeader()->sessionAuthenticationToken().nodeId<OpcUaGuid::SPtr>();
	BOOST_REQUIRE(createSessionRequestSPtr->requestHeader()->sessionAuthenticationToken().namespaceIndex() == 1);
	BOOST_REQUIRE(str == "12345678-9ABC-DEF0-1234-56789ABCDEF0");
	BOOST_REQUIRE(createSessionRequestSPtr->requestHeader()->time().dateTime() == ptime);
	BOOST_REQUIRE(createSessionRequestSPtr->requestHeader()->requestHandle() == 1);
	BOOST_REQUIRE(createSessionRequestSPtr->requestHeader()->returnDisagnostics() == 0);
	BOOST_REQUIRE(createSessionRequestSPtr->requestHeader()->timeoutHint() == 10000);

	BOOST_REQUIRE(createSessionRequestSPtr->clientDescription()->applicationUri() == "urn:localhost:compyny:Unittest");
	BOOST_REQUIRE(createSessionRequestSPtr->clientDescription()->productUri() == "urn:company:Unittest");
	BOOST_REQUIRE(createSessionRequestSPtr->clientDescription()->applicationName().text().value() == "company Unittest");
	BOOST_REQUIRE(createSessionRequestSPtr->clientDescription()->applicationType() == ApplicationType_Client);


	BOOST_REQUIRE(createSessionRequestSPtr->endpointUrl() == "opc.tcp://localhost:4841");
	BOOST_REQUIRE(createSessionRequestSPtr->sessionName() == "urn:localhost:company:Unittest");
	createSessionRequestSPtr->clientNonce(&opcUaByte, &opcUaByteLen);
	BOOST_REQUIRE(opcUaByteLen == 10);
	BOOST_REQUIRE(strncmp((char*)opcUaByte, "0123456789", 10) == 0);
	createSessionRequestSPtr->clientCertificate(&opcUaByte, &opcUaByteLen);
	BOOST_REQUIRE(opcUaByteLen == 10);
	BOOST_REQUIRE(strncmp((char*)opcUaByte, "0123456789", 10) == 0);
	BOOST_REQUIRE(createSessionRequestSPtr->requestSessionTimeout() == 1200000);
	BOOST_REQUIRE(createSessionRequestSPtr->maxResponseMessageSize() == 0);
}


BOOST_AUTO_TEST_CASE(CreateSession_Response)
{
	uint32_t pos;
	MessageHeader::SPtr messageHeaderSPtr;
	boost::posix_time::ptime ptime = boost::posix_time::from_iso_string("16010101T120000.000000000");
	OpcUaGuid::SPtr opcUaGuidSPtr;
	CreateSessionResponse::SPtr createSessionResponseSPtr;
	SequenceHeader::SPtr sequenceHeaderSPtr;
	OpcUaNodeId typeId;
	OpcUaByte* opcUaByte;
	OpcUaInt32 opcUaByteLen;

	// stream
	boost::asio::streambuf sb1;
	std::iostream ios1(&sb1);
	boost::asio::streambuf sb2;
	std::iostream ios2(&sb2);
	boost::asio::streambuf sb;
	std::iostream ios(&sb);

	// encode channel id
	OpcUaUInt32 channelId;
	channelId = 153451225;
	OpcUaStackCore::opcUaBinaryEncode(ios1, channelId);

	// encode token id
	OpcUaInt32 tokenId;
	tokenId = 1;
	OpcUaStackCore::opcUaBinaryEncode(ios1, tokenId);

	// encode sequence header
	sequenceHeaderSPtr = SequenceHeader::construct();
	sequenceHeaderSPtr->sequenceNumber(52);
	sequenceHeaderSPtr->requestId(2);
	sequenceHeaderSPtr->opcUaBinaryEncode(ios1);

	// encode message type id
	typeId.nodeId(OpcUaId_CreateSessionResponse_Encoding_DefaultBinary);
	typeId.opcUaBinaryEncode(ios1);

	// encode CreateSessionResponse
	opcUaGuidSPtr = OpcUaGuid::construct();
	*opcUaGuidSPtr = "12345678-9ABC-DEF0-1234-56789ABCDEF0";

	createSessionResponseSPtr = CreateSessionResponse::construct();
	createSessionResponseSPtr->responseHeader(ResponseHeader::construct());
	createSessionResponseSPtr->responseHeader()->diagnosticInfo(OpcUaDiagnosticInfo::construct());
	createSessionResponseSPtr->responseHeader()->stringTable(OpcUaStringArray::construct());

	createSessionResponseSPtr->responseHeader()->time(ptime);
	createSessionResponseSPtr->responseHeader()->requestHandle(1);
	createSessionResponseSPtr->responseHeader()->serviceResult(OpcUaStatusCode::Success);

	createSessionResponseSPtr->sessionId().namespaceIndex(1);
	createSessionResponseSPtr->sessionId().nodeId(1);
	createSessionResponseSPtr->authenticationToken().namespaceIndex(1);
	createSessionResponseSPtr->authenticationToken().nodeId(opcUaGuidSPtr);
	createSessionResponseSPtr->receivedSessionTimeout(120000);
	createSessionResponseSPtr->serverCertificate((OpcUaByte*)"0123456789", 10);

	//createSessionResponseSPtr->serverEndpoints()->resize(3);


	// encode MessageHeader
	messageHeaderSPtr = MessageHeader::construct();
	messageHeaderSPtr->messageType(MessageType_Message);
	messageHeaderSPtr->messageSize(OpcUaStackCore::count(sb1)+8);
	messageHeaderSPtr->opcUaBinaryEncode(ios2);

	// stream
	ios << ios2.rdbuf() << ios1.rdbuf();
	OpcUaStackCore::dumpHex(ios);

#if 0
	std::stringstream ss;
	ss	<< "4d 53 47 46 13 01 00 00  d9 7a 25 09 01 00 00 00"
		<< "34 00 00 00 02 00 00 00  01 00 cd 01 04 01 00 12"
		<< "34 56 78 9a bc de f0 12  34 56 78 9a bc de f0 00"
		<< "00 00 00 00 00 00 00 01  00 00 00 00 00 00 00 ff"
		<< "ff ff ff 10 27 00 00 00  00 00 1e 00 00 00 75 72"
		<< "6e 3a 6c 6f 63 61 6c 68  6f 73 74 3a 63 6f 6d 70"
		<< "79 6e 79 3a 55 6e 69 74  74 65 73 74 14 00 00 00"
		<< "75 72 6e 3a 63 6f 6d 70  61 6e 79 3a 55 6e 69 74"
		<< "74 65 73 74 02 10 00 00  00 63 6f 6d 70 61 6e 79"
		<< "20 55 6e 69 74 74 65 73  74 01 00 00 00 ff ff ff"
		<< "ff ff ff ff ff 00 00 00  00 ff ff ff ff 18 00 00"
		<< "00 6f 70 63 2e 74 63 70  3a 2f 2f 6c 6f 63 61 6c"
		<< "68 6f 73 74 3a 34 38 34  31 1e 00 00 00 75 72 6e"
		<< "3a 6c 6f 63 61 6c 68 6f  73 74 3a 63 6f 6d 70 61"
		<< "6e 79 3a 55 6e 69 74 74  65 73 74 0a 00 00 00 30"
		<< "31 32 33 34 35 36 37 38  39 0a 00 00 00 30 31 32"
		<< "33 34 35 36 37 38 39 00  00 00 00 80 4f 32 41 00"
		<< "00 00 00";
		BOOST_REQUIRE(OpcUaStackCore::compare(ios, ss.str(), pos) == true);
#endif

	// decode MessageHeader
	messageHeaderSPtr = MessageHeader::construct();
	messageHeaderSPtr->opcUaBinaryDecode(ios);
	BOOST_REQUIRE(messageHeaderSPtr->messageType() == MessageType_Message);
	
	// decode channel id
	OpcUaStackCore::opcUaBinaryDecode(ios, channelId);
	BOOST_REQUIRE(channelId == 153451225);

	// decode token id
	OpcUaStackCore::opcUaBinaryDecode(ios, tokenId);
	BOOST_REQUIRE(tokenId == 1);
	
	// decode sequence header
	sequenceHeaderSPtr = SequenceHeader::construct();
	sequenceHeaderSPtr->opcUaBinaryDecode(ios);
	BOOST_REQUIRE(sequenceHeaderSPtr->sequenceNumber() == 52);
	BOOST_REQUIRE(sequenceHeaderSPtr->requestId() == 2);

	// decode message type id
	typeId.opcUaBinaryDecode(ios);
	BOOST_REQUIRE(typeId.namespaceIndex() == 0);
	BOOST_REQUIRE(typeId.nodeId<OpcUaUInt32>() == OpcUaId_CreateSessionResponse_Encoding_DefaultBinary);

	// FIXME
}

BOOST_AUTO_TEST_SUITE_END()