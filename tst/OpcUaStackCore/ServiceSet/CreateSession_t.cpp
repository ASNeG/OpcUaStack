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
	boost::posix_time::ptime ptime = boost::posix_time::from_iso_string("16010101T000000.000000000");
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
	OpcUaNumber::opcUaBinaryEncode(ios1, channelId);

	// encode token id
	OpcUaInt32 tokenId;
	tokenId = 1;
	OpcUaNumber::opcUaBinaryEncode(ios1, tokenId);

	// encode sequence header
	sequenceHeaderSPtr = constructSPtr<SequenceHeader>();
	sequenceHeaderSPtr->sequenceNumber(52);
	sequenceHeaderSPtr->requestId(2);
	sequenceHeaderSPtr->opcUaBinaryEncode(ios1);

	// encode message type id
	typeId.nodeId((OpcUaUInt32)OpcUaId_CreateSessionRequest_Encoding_DefaultBinary);
	typeId.opcUaBinaryEncode(ios1);

	// encode CreateSessionRequest
	opcUaGuidSPtr = constructSPtr<OpcUaGuid>();
	*opcUaGuidSPtr = "12345678-9ABC-DEF0-1234-56789ABCDEF0";

	OpcUaByte clientNonce[1];
	clientNonce[0] = 0x00;
	createSessionRequestSPtr = constructSPtr<CreateSessionRequest>();
	createSessionRequestSPtr->clientDescription()->applicationUri().value("urn:localhost:compyny:Unittest");
	createSessionRequestSPtr->clientDescription()->productUri().value("urn:company:Unittest");
	createSessionRequestSPtr->clientDescription()->applicationName().text("company Unittest");
	createSessionRequestSPtr->clientDescription()->applicationType().enumeration(ApplicationType::EnumClient);

	createSessionRequestSPtr->endpointUrl("opc.tcp://localhost:4841");
	createSessionRequestSPtr->sessionName("urn:localhost:company:Unittest");
	createSessionRequestSPtr->clientNonce((OpcUaByte*)"0123456789", 10);
	createSessionRequestSPtr->clientCertificate((OpcUaByte*)"0123456789", 10);
	createSessionRequestSPtr->requestSessionTimeout(1200000);
	createSessionRequestSPtr->maxResponseMessageSize(0);

	createSessionRequestSPtr->opcUaBinaryEncode(ios1);

	// encode MessageHeader
	messageHeaderSPtr = constructSPtr<MessageHeader>();
	messageHeaderSPtr->messageType(MessageType_Message);
	messageHeaderSPtr->messageSize(OpcUaStackCore::count(sb1)+8);
	messageHeaderSPtr->opcUaBinaryEncode(ios2);

	// stream
	ios << ios2.rdbuf() << ios1.rdbuf();
	OpcUaStackCore::dumpHex(ios);

	std::stringstream ss;
	ss	<< "4d 53 47 46 e5 00 00 00  d9 7a 25 09 01 00 00 00"
		<< "34 00 00 00 02 00 00 00  01 00 cd 01 1e 00 00 00"
		<< "75 72 6e 3a 6c 6f 63 61  6c 68 6f 73 74 3a 63 6f"
		<< "6d 70 79 6e 79 3a 55 6e  69 74 74 65 73 74 14 00"
		<< "00 00 75 72 6e 3a 63 6f  6d 70 61 6e 79 3a 55 6e"
		<< "69 74 74 65 73 74 02 10  00 00 00 63 6f 6d 70 61"
		<< "6e 79 20 55 6e 69 74 74  65 73 74 01 00 00 00 ff"
		<< "ff ff ff ff ff ff ff 00  00 00 00 ff ff ff ff 18"
		<< "00 00 00 6f 70 63 2e 74  63 70 3a 2f 2f 6c 6f 63"
		<< "61 6c 68 6f 73 74 3a 34  38 34 31 1e 00 00 00 75"
		<< "72 6e 3a 6c 6f 63 61 6c  68 6f 73 74 3a 63 6f 6d"
		<< "70 61 6e 79 3a 55 6e 69  74 74 65 73 74 0a 00 00"
		<< "00 30 31 32 33 34 35 36  37 38 39 0a 00 00 00 30"
		<< "31 32 33 34 35 36 37 38  39 00 00 00 00 80 4f 32"
		<< "41 00 00 00 00";
		BOOST_REQUIRE(OpcUaStackCore::compare(ios, ss.str(), pos) == true);

	// decode MessageHeader
	messageHeaderSPtr = constructSPtr<MessageHeader>();
	messageHeaderSPtr->opcUaBinaryDecode(ios);
	BOOST_REQUIRE(messageHeaderSPtr->messageType() == MessageType_Message);
	
	// decode channel id
	OpcUaNumber::opcUaBinaryDecode(ios, channelId);
	BOOST_REQUIRE(channelId == 153451225);

	// decode token id
	OpcUaNumber::opcUaBinaryDecode(ios, tokenId);
	BOOST_REQUIRE(tokenId == 1);
	
	// decode sequence header
	sequenceHeaderSPtr = constructSPtr<SequenceHeader>();
	sequenceHeaderSPtr->opcUaBinaryDecode(ios);
	BOOST_REQUIRE(sequenceHeaderSPtr->sequenceNumber() == 52);
	BOOST_REQUIRE(sequenceHeaderSPtr->requestId() == 2);

	// decode message type id
	typeId.opcUaBinaryDecode(ios);
	BOOST_REQUIRE(typeId.namespaceIndex() == 0);
	BOOST_REQUIRE(typeId.nodeId<OpcUaUInt32>() == OpcUaId_CreateSessionRequest_Encoding_DefaultBinary);

	// decode CreateSessionRequest
	createSessionRequestSPtr = constructSPtr<CreateSessionRequest>();
	createSessionRequestSPtr->opcUaBinaryDecode(ios);

	BOOST_REQUIRE(createSessionRequestSPtr->clientDescription()->applicationUri().value() == "urn:localhost:compyny:Unittest");
	BOOST_REQUIRE(createSessionRequestSPtr->clientDescription()->productUri().value() == "urn:company:Unittest");
	BOOST_REQUIRE(createSessionRequestSPtr->clientDescription()->applicationName().text().value() == "company Unittest");
	BOOST_REQUIRE(createSessionRequestSPtr->clientDescription()->applicationType().enumeration() == ApplicationType::EnumClient);


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
	boost::posix_time::ptime ptime = boost::posix_time::from_iso_string("16010101T000000.000000000");
	OpcUaGuid::SPtr opcUaGuidSPtr;
	CreateSessionResponse::SPtr createSessionResponseSPtr;
	SequenceHeader::SPtr sequenceHeaderSPtr;
	EndpointDescription::SPtr endpointDescriptionSPtr;
	UserTokenPolicy::SPtr userTokenPolicySPtr;
	OpcUaString::SPtr opcUaStringSPtr;
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
	OpcUaNumber::opcUaBinaryEncode(ios1, channelId);

	// encode token id
	OpcUaInt32 tokenId;
	tokenId = 1;
	OpcUaNumber::opcUaBinaryEncode(ios1, tokenId);

	// encode sequence header
	sequenceHeaderSPtr = constructSPtr<SequenceHeader>();
	sequenceHeaderSPtr->sequenceNumber(52);
	sequenceHeaderSPtr->requestId(2);
	sequenceHeaderSPtr->opcUaBinaryEncode(ios1);

	// encode message type id
	typeId.nodeId(OpcUaId_CreateSessionResponse_Encoding_DefaultBinary);
	typeId.opcUaBinaryEncode(ios1);

	// encode CreateSessionResponse
	opcUaGuidSPtr = constructSPtr<OpcUaGuid>();
	*opcUaGuidSPtr = "12345678-9ABC-DEF0-1234-56789ABCDEF0";

	createSessionResponseSPtr = constructSPtr<CreateSessionResponse>();

	createSessionResponseSPtr->sessionId().namespaceIndex(1);
	createSessionResponseSPtr->sessionId().nodeId(1);
	createSessionResponseSPtr->authenticationToken().namespaceIndex(1);
	createSessionResponseSPtr->authenticationToken().nodeId(opcUaGuidSPtr);
	createSessionResponseSPtr->receivedSessionTimeout(120000);
	createSessionResponseSPtr->serverCertificate((OpcUaByte*)"0123456789", 10);

	createSessionResponseSPtr->serverEndpoints()->resize(3);


	endpointDescriptionSPtr = constructSPtr<EndpointDescription>();
	endpointDescriptionSPtr->endpointUrl().value("opt.tcp://localhost:481/0.0.0.0");
	endpointDescriptionSPtr->server().applicationUri().value("urn:localhost:compyny:Unittest");
	endpointDescriptionSPtr->server().productUri().value("urn:company:Unittest");
	endpointDescriptionSPtr->server().applicationName().text("company Unittest");
	endpointDescriptionSPtr->server().applicationType().enumeration(ApplicationType::EnumServer);
	endpointDescriptionSPtr->server().discoveryUrls().resize(1);
	opcUaStringSPtr = constructSPtr<OpcUaString>();
	opcUaStringSPtr->value("opt.tcp://localhost:4841/0.0.0.0");
	endpointDescriptionSPtr->server().discoveryUrls().set(0, opcUaStringSPtr);
	endpointDescriptionSPtr->serverCertificate().value((OpcUaByte*)"0123456789", 10);
	endpointDescriptionSPtr->securityMode().enumeration(MessageSecurityMode::EnumNone);
	endpointDescriptionSPtr->securityPolicyUri().value("http://opcfoundation.org/UA/SecurityPolicy#None");

	endpointDescriptionSPtr->userIdentityTokens().resize(1);
	userTokenPolicySPtr = constructSPtr<UserTokenPolicy>();
	userTokenPolicySPtr->policyId().value("OpcUaStack");
	userTokenPolicySPtr->tokenType().enumeration(UserTokenType::EnumAnonymous);
	endpointDescriptionSPtr->userIdentityTokens().push_back(userTokenPolicySPtr);

	endpointDescriptionSPtr->transportProfileUri().value("http://opcfoundation.org/UA-Profile/Transport/uatcp-uasc-uabinary");
	endpointDescriptionSPtr->securityLevel() = 0;

	createSessionResponseSPtr->serverEndpoints()->push_back(endpointDescriptionSPtr);


	endpointDescriptionSPtr = constructSPtr<EndpointDescription>();
	endpointDescriptionSPtr->endpointUrl().value("opt.tcp://localhost:481/0.0.0.0");
	endpointDescriptionSPtr->server().applicationUri().value("urn:localhost:compyny:Unittest");
	endpointDescriptionSPtr->server().productUri().value("urn:company:Unittest");
	endpointDescriptionSPtr->server().applicationName().text("company Unittest");
	endpointDescriptionSPtr->server().applicationType().enumeration(ApplicationType::EnumServer);
	endpointDescriptionSPtr->server().discoveryUrls().resize(1);
	opcUaStringSPtr = constructSPtr<OpcUaString>();
	opcUaStringSPtr->value("opt.tcp://localhost:4841/0.0.0.0");
	endpointDescriptionSPtr->server().discoveryUrls().set(0, opcUaStringSPtr);
	endpointDescriptionSPtr->serverCertificate().value((OpcUaByte*)"0123456789", 10);
	endpointDescriptionSPtr->securityMode().enumeration(MessageSecurityMode::EnumNone);
	endpointDescriptionSPtr->securityPolicyUri().value("http://opcfoundation.org/UA/SecurityPolicy#Basic128Rsa15");

	endpointDescriptionSPtr->userIdentityTokens().resize(1);
	userTokenPolicySPtr = constructSPtr<UserTokenPolicy>();
	userTokenPolicySPtr->policyId().value("OpcUaStack");
	userTokenPolicySPtr->tokenType().enumeration(UserTokenType::EnumAnonymous);
	endpointDescriptionSPtr->userIdentityTokens().push_back(userTokenPolicySPtr);

	endpointDescriptionSPtr->transportProfileUri().value("http://opcfoundation.org/UA-Profile/Transport/uatcp-uasc-uabinary");
	endpointDescriptionSPtr->securityLevel() = 1;

	createSessionResponseSPtr->serverEndpoints()->push_back(endpointDescriptionSPtr);


	endpointDescriptionSPtr = constructSPtr<EndpointDescription>();
	endpointDescriptionSPtr->endpointUrl().value("opt.tcp://localhost:481/0.0.0.0");
	endpointDescriptionSPtr->server().applicationUri().value("urn:localhost:compyny:Unittest");
	endpointDescriptionSPtr->server().productUri().value("urn:company:Unittest");
	endpointDescriptionSPtr->server().applicationName().text("company Unittest");
	endpointDescriptionSPtr->server().applicationType().enumeration(ApplicationType::EnumServer);
	endpointDescriptionSPtr->server().discoveryUrls().resize(1);
	opcUaStringSPtr = constructSPtr<OpcUaString>();
	opcUaStringSPtr->value("opt.tcp://localhost:4841/0.0.0.0");
	endpointDescriptionSPtr->server().discoveryUrls().set(0, opcUaStringSPtr);
	endpointDescriptionSPtr->serverCertificate().value((OpcUaByte*)"0123456789", 10);
	endpointDescriptionSPtr->securityMode().enumeration(MessageSecurityMode::EnumNone);
	endpointDescriptionSPtr->securityPolicyUri().value("http://opcfoundation.org/UA/SecurityPolicy#Basic128Rsa15");

	endpointDescriptionSPtr->userIdentityTokens().resize(1);
	userTokenPolicySPtr = constructSPtr<UserTokenPolicy>();
	userTokenPolicySPtr->policyId().value("OpcUaStack");
	userTokenPolicySPtr->tokenType().enumeration(UserTokenType::EnumAnonymous);
	endpointDescriptionSPtr->userIdentityTokens().push_back(userTokenPolicySPtr);

	endpointDescriptionSPtr->transportProfileUri().value("http://opcfoundation.org/UA-Profile/Transport/uatcp-uasc-uabinary");
	endpointDescriptionSPtr->securityLevel() = 2;

	createSessionResponseSPtr->serverEndpoints()->push_back(endpointDescriptionSPtr);

	createSessionResponseSPtr->maxRequestMessageSize(0);

	createSessionResponseSPtr->opcUaBinaryEncode(ios1);

	// encode MessageHeader
	messageHeaderSPtr = constructSPtr<MessageHeader>();
	messageHeaderSPtr->messageType(MessageType_Message);
	messageHeaderSPtr->messageSize(OpcUaStackCore::count(sb1)+8);
	messageHeaderSPtr->opcUaBinaryEncode(ios2);

	// stream
	ios << ios2.rdbuf() << ios1.rdbuf();
	OpcUaStackCore::dumpHex(ios);

	std::stringstream ss;
	ss << "4d 53 47 46 6c 04 00 00  d9 7a 25 09 01 00 00 00"
	   << "34 00 00 00 02 00 00 00  01 00 d0 01 01 01 01 00"
	   << "04 01 00 12 34 56 78 9a  bc de f0 12 34 56 78 9a"
	   << "bc de f0 00 00 00 00 00  4c fd 40 ff ff ff ff 0a"
	   << "00 00 00 30 31 32 33 34  35 36 37 38 39 03 00 00"
	   << "00 1f 00 00 00 6f 70 74  2e 74 63 70 3a 2f 2f 6c"
	   << "6f 63 61 6c 68 6f 73 74  3a 34 38 31 2f 30 2e 30"
	   << "2e 30 2e 30 1e 00 00 00  75 72 6e 3a 6c 6f 63 61"
	   << "6c 68 6f 73 74 3a 63 6f  6d 70 79 6e 79 3a 55 6e"
	   << "69 74 74 65 73 74 14 00  00 00 75 72 6e 3a 63 6f"
	   << "6d 70 61 6e 79 3a 55 6e  69 74 74 65 73 74 02 10"
	   << "00 00 00 63 6f 6d 70 61  6e 79 20 55 6e 69 74 74"
	   << "65 73 74 00 00 00 00 ff  ff ff ff ff ff ff ff 01"
	   << "00 00 00 20 00 00 00 6f  70 74 2e 74 63 70 3a 2f"
	   << "2f 6c 6f 63 61 6c 68 6f  73 74 3a 34 38 34 31 2f"
	   << "30 2e 30 2e 30 2e 30 0a  00 00 00 30 31 32 33 34"
	   << "35 36 37 38 39 01 00 00  00 2f 00 00 00 68 74 74"
	   << "70 3a 2f 2f 6f 70 63 66  6f 75 6e 64 61 74 69 6f"
	   << "6e 2e 6f 72 67 2f 55 41  2f 53 65 63 75 72 69 74"
	   << "79 50 6f 6c 69 63 79 23  4e 6f 6e 65 01 00 00 00"
	   << "0a 00 00 00 4f 70 63 55  61 53 74 61 63 6b 00 00"
	   << "00 00 ff ff ff ff ff ff  ff ff ff ff ff ff 41 00"
	   << "00 00 68 74 74 70 3a 2f  2f 6f 70 63 66 6f 75 6e"
	   << "64 61 74 69 6f 6e 2e 6f  72 67 2f 55 41 2d 50 72"
	   << "6f 66 69 6c 65 2f 54 72  61 6e 73 70 6f 72 74 2f"
	   << "75 61 74 63 70 2d 75 61  73 63 2d 75 61 62 69 6e"
	   << "61 72 79 00 1f 00 00 00  6f 70 74 2e 74 63 70 3a"
	   << "2f 2f 6c 6f 63 61 6c 68  6f 73 74 3a 34 38 31 2f"
	   << "30 2e 30 2e 30 2e 30 1e  00 00 00 75 72 6e 3a 6c"
	   << "6f 63 61 6c 68 6f 73 74  3a 63 6f 6d 70 79 6e 79"
	   << "3a 55 6e 69 74 74 65 73  74 14 00 00 00 75 72 6e"
	   << "3a 63 6f 6d 70 61 6e 79  3a 55 6e 69 74 74 65 73"
	   << "74 02 10 00 00 00 63 6f  6d 70 61 6e 79 20 55 6e"
	   << "69 74 74 65 73 74 00 00  00 00 ff ff ff ff ff ff"
	   << "ff ff 01 00 00 00 20 00  00 00 6f 70 74 2e 74 63"
	   << "70 3a 2f 2f 6c 6f 63 61  6c 68 6f 73 74 3a 34 38"
	   << "34 31 2f 30 2e 30 2e 30  2e 30 0a 00 00 00 30 31"
	   << "32 33 34 35 36 37 38 39  01 00 00 00 38 00 00 00"
	   << "68 74 74 70 3a 2f 2f 6f  70 63 66 6f 75 6e 64 61"
	   << "74 69 6f 6e 2e 6f 72 67  2f 55 41 2f 53 65 63 75"
	   << "72 69 74 79 50 6f 6c 69  63 79 23 42 61 73 69 63"
	   << "31 32 38 52 73 61 31 35  01 00 00 00 0a 00 00 00"
	   << "4f 70 63 55 61 53 74 61  63 6b 00 00 00 00 ff ff"
	   << "ff ff ff ff ff ff ff ff  ff ff 41 00 00 00 68 74"
	   << "74 70 3a 2f 2f 6f 70 63  66 6f 75 6e 64 61 74 69"
	   << "6f 6e 2e 6f 72 67 2f 55  41 2d 50 72 6f 66 69 6c"
	   << "65 2f 54 72 61 6e 73 70  6f 72 74 2f 75 61 74 63"
	   << "70 2d 75 61 73 63 2d 75  61 62 69 6e 61 72 79 01"
	   << "1f 00 00 00 6f 70 74 2e  74 63 70 3a 2f 2f 6c 6f"
	   << "63 61 6c 68 6f 73 74 3a  34 38 31 2f 30 2e 30 2e"
	   << "30 2e 30 1e 00 00 00 75  72 6e 3a 6c 6f 63 61 6c"
	   << "68 6f 73 74 3a 63 6f 6d  70 79 6e 79 3a 55 6e 69"
	   << "74 74 65 73 74 14 00 00  00 75 72 6e 3a 63 6f 6d"
	   << "70 61 6e 79 3a 55 6e 69  74 74 65 73 74 02 10 00"
	   << "00 00 63 6f 6d 70 61 6e  79 20 55 6e 69 74 74 65"
	   << "73 74 00 00 00 00 ff ff  ff ff ff ff ff ff 01 00"
	   << "00 00 20 00 00 00 6f 70  74 2e 74 63 70 3a 2f 2f"
	   << "6c 6f 63 61 6c 68 6f 73  74 3a 34 38 34 31 2f 30"
	   << "2e 30 2e 30 2e 30 0a 00  00 00 30 31 32 33 34 35"
	   << "36 37 38 39 01 00 00 00  38 00 00 00 68 74 74 70"
	   << "3a 2f 2f 6f 70 63 66 6f  75 6e 64 61 74 69 6f 6e"
	   << "2e 6f 72 67 2f 55 41 2f  53 65 63 75 72 69 74 79"
	   << "50 6f 6c 69 63 79 23 42  61 73 69 63 31 32 38 52"
	   << "73 61 31 35 01 00 00 00  0a 00 00 00 4f 70 63 55"
	   << "61 53 74 61 63 6b 00 00  00 00 ff ff ff ff ff ff"
	   << "ff ff ff ff ff ff 41 00  00 00 68 74 74 70 3a 2f"
	   << "2f 6f 70 63 66 6f 75 6e  64 61 74 69 6f 6e 2e 6f"
	   << "72 67 2f 55 41 2d 50 72  6f 66 69 6c 65 2f 54 72"
	   << "61 6e 73 70 6f 72 74 2f  75 61 74 63 70 2d 75 61"
	   << "73 63 2d 75 61 62 69 6e  61 72 79 02 ff ff ff ff"
	   << "ff ff ff ff ff ff ff ff  00 00 00 00";
		
		BOOST_REQUIRE(OpcUaStackCore::compare(ios, ss.str(), pos) == true);

	// decode MessageHeader
	messageHeaderSPtr = constructSPtr<MessageHeader>();
	messageHeaderSPtr->opcUaBinaryDecode(ios);
	BOOST_REQUIRE(messageHeaderSPtr->messageType() == MessageType_Message);
	
	// decode channel id
	OpcUaNumber::opcUaBinaryDecode(ios, channelId);
	BOOST_REQUIRE(channelId == 153451225);

	// decode token id
	OpcUaNumber::opcUaBinaryDecode(ios, tokenId);
	BOOST_REQUIRE(tokenId == 1);
	
	// decode sequence header
	sequenceHeaderSPtr = constructSPtr<SequenceHeader>();
	sequenceHeaderSPtr->opcUaBinaryDecode(ios);
	BOOST_REQUIRE(sequenceHeaderSPtr->sequenceNumber() == 52);
	BOOST_REQUIRE(sequenceHeaderSPtr->requestId() == 2);

	// decode message type id
	typeId.opcUaBinaryDecode(ios);
	BOOST_REQUIRE(typeId.namespaceIndex() == 0);
	BOOST_REQUIRE(typeId.nodeId<OpcUaUInt32>() == OpcUaId_CreateSessionResponse_Encoding_DefaultBinary);

	//decode CreateSessionResponse
	createSessionResponseSPtr = constructSPtr<CreateSessionResponse>();
	createSessionResponseSPtr->opcUaBinaryDecode(ios);

	std::string  str = *createSessionResponseSPtr->authenticationToken().nodeId<OpcUaGuid::SPtr>();
	BOOST_REQUIRE(str == "12345678-9ABC-DEF0-1234-56789ABCDEF0");

	BOOST_REQUIRE(createSessionResponseSPtr->receivedSessionTimeout() == 120000);
	createSessionResponseSPtr->serverCertificate(&opcUaByte, &opcUaByteLen);
	BOOST_REQUIRE(opcUaByteLen == 10);
	BOOST_REQUIRE(strncmp((char*)opcUaByte, "0123456789", 10) == 0);

	BOOST_REQUIRE(createSessionResponseSPtr->serverEndpoints()->size() == 3);

	createSessionResponseSPtr->serverEndpoints()->get(0, endpointDescriptionSPtr);
	BOOST_REQUIRE(endpointDescriptionSPtr->endpointUrl().value() == "opt.tcp://localhost:481/0.0.0.0");
	BOOST_REQUIRE(endpointDescriptionSPtr->server().applicationUri().value() == "urn:localhost:compyny:Unittest");
	BOOST_REQUIRE(endpointDescriptionSPtr->server().productUri().value() == "urn:company:Unittest");
	BOOST_REQUIRE(endpointDescriptionSPtr->server().applicationName().text().value() == "company Unittest");
	BOOST_REQUIRE(endpointDescriptionSPtr->server().applicationType().enumeration() == ApplicationType::EnumServer);
	BOOST_REQUIRE(endpointDescriptionSPtr->server().discoveryUrls().size() == 1);
	endpointDescriptionSPtr->server().discoveryUrls().get(0, opcUaStringSPtr);
	BOOST_REQUIRE(opcUaStringSPtr->value() == "opt.tcp://localhost:4841/0.0.0.0");
	endpointDescriptionSPtr->serverCertificate().value(&opcUaByte, &opcUaByteLen);
	BOOST_REQUIRE(opcUaByteLen == 10);
	BOOST_REQUIRE(strncmp((char*)opcUaByte, "0123456789", 10) == 0);
	BOOST_REQUIRE(endpointDescriptionSPtr->securityMode().enumeration() == MessageSecurityMode::EnumNone);
	BOOST_REQUIRE(endpointDescriptionSPtr->securityPolicyUri().value() == "http://opcfoundation.org/UA/SecurityPolicy#None");
	BOOST_REQUIRE(endpointDescriptionSPtr->userIdentityTokens().size() == 1);
	endpointDescriptionSPtr->userIdentityTokens().get(0, userTokenPolicySPtr);
	BOOST_REQUIRE(userTokenPolicySPtr->policyId().value() == "OpcUaStack");
	BOOST_REQUIRE(userTokenPolicySPtr->tokenType().enumeration() == UserTokenType::EnumAnonymous);
	BOOST_REQUIRE(endpointDescriptionSPtr->transportProfileUri().value() == "http://opcfoundation.org/UA-Profile/Transport/uatcp-uasc-uabinary");
	BOOST_REQUIRE(endpointDescriptionSPtr->securityLevel() == 0);

	createSessionResponseSPtr->serverEndpoints()->get(1, endpointDescriptionSPtr);
	BOOST_REQUIRE(endpointDescriptionSPtr->endpointUrl().value() == "opt.tcp://localhost:481/0.0.0.0");
	BOOST_REQUIRE(endpointDescriptionSPtr->server().applicationUri().value() == "urn:localhost:compyny:Unittest");
	BOOST_REQUIRE(endpointDescriptionSPtr->server().productUri().value() == "urn:company:Unittest");
	BOOST_REQUIRE(endpointDescriptionSPtr->server().applicationName().text().value() == "company Unittest");
	BOOST_REQUIRE(endpointDescriptionSPtr->server().applicationType().enumeration() == ApplicationType::EnumServer);
	BOOST_REQUIRE(endpointDescriptionSPtr->server().discoveryUrls().size() == 1);
	endpointDescriptionSPtr->server().discoveryUrls().get(0, opcUaStringSPtr);
	BOOST_REQUIRE(opcUaStringSPtr->value() == "opt.tcp://localhost:4841/0.0.0.0");
	endpointDescriptionSPtr->serverCertificate().value(&opcUaByte, &opcUaByteLen);
	BOOST_REQUIRE(opcUaByteLen == 10);
	BOOST_REQUIRE(strncmp((char*)opcUaByte, "0123456789", 10) == 0);
	BOOST_REQUIRE(endpointDescriptionSPtr->securityMode().enumeration() == MessageSecurityMode::EnumNone);
	BOOST_REQUIRE(endpointDescriptionSPtr->securityPolicyUri().value() == "http://opcfoundation.org/UA/SecurityPolicy#Basic128Rsa15");
	BOOST_REQUIRE(endpointDescriptionSPtr->userIdentityTokens().size() == 1);
	endpointDescriptionSPtr->userIdentityTokens().get(0, userTokenPolicySPtr);
	BOOST_REQUIRE(userTokenPolicySPtr->policyId().value() == "OpcUaStack");
	BOOST_REQUIRE(userTokenPolicySPtr->tokenType().enumeration() == UserTokenType::EnumAnonymous);
	BOOST_REQUIRE(endpointDescriptionSPtr->transportProfileUri().value() == "http://opcfoundation.org/UA-Profile/Transport/uatcp-uasc-uabinary");
	BOOST_REQUIRE(endpointDescriptionSPtr->securityLevel() == 1);

	createSessionResponseSPtr->serverEndpoints()->get(2, endpointDescriptionSPtr);
	BOOST_REQUIRE(endpointDescriptionSPtr->endpointUrl().value() == "opt.tcp://localhost:481/0.0.0.0");
	BOOST_REQUIRE(endpointDescriptionSPtr->server().applicationUri().value() == "urn:localhost:compyny:Unittest");
	BOOST_REQUIRE(endpointDescriptionSPtr->server().productUri().value() == "urn:company:Unittest");
	BOOST_REQUIRE(endpointDescriptionSPtr->server().applicationName().text().value() == "company Unittest");
	BOOST_REQUIRE(endpointDescriptionSPtr->server().applicationType().enumeration() == ApplicationType::EnumServer);
	BOOST_REQUIRE(endpointDescriptionSPtr->server().discoveryUrls().size() == 1);
	endpointDescriptionSPtr->server().discoveryUrls().get(0, opcUaStringSPtr);
	BOOST_REQUIRE(opcUaStringSPtr->value() == "opt.tcp://localhost:4841/0.0.0.0");
	endpointDescriptionSPtr->serverCertificate().value(&opcUaByte, &opcUaByteLen);
	BOOST_REQUIRE(opcUaByteLen == 10);
	BOOST_REQUIRE(strncmp((char*)opcUaByte, "0123456789", 10) == 0);
	BOOST_REQUIRE(endpointDescriptionSPtr->securityMode().enumeration() == MessageSecurityMode::EnumNone);
	BOOST_REQUIRE(endpointDescriptionSPtr->securityPolicyUri().value() == "http://opcfoundation.org/UA/SecurityPolicy#Basic128Rsa15");
	BOOST_REQUIRE(endpointDescriptionSPtr->userIdentityTokens().size() == 1);
	endpointDescriptionSPtr->userIdentityTokens().get(0, userTokenPolicySPtr);
	BOOST_REQUIRE(userTokenPolicySPtr->policyId().value() == "OpcUaStack");
	BOOST_REQUIRE(userTokenPolicySPtr->tokenType().enumeration() == UserTokenType::EnumAnonymous);
	BOOST_REQUIRE(endpointDescriptionSPtr->transportProfileUri().value() == "http://opcfoundation.org/UA-Profile/Transport/uatcp-uasc-uabinary");
	BOOST_REQUIRE(endpointDescriptionSPtr->securityLevel() == 2);

	BOOST_REQUIRE(createSessionResponseSPtr->maxRequestMessageSize() == 0);
}

BOOST_AUTO_TEST_SUITE_END()
