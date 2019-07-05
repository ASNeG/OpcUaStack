#include "unittest.h"
#include "boost/asio.hpp"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackCore/SecureChannel/MessageHeader.h"
#include "OpcUaStackCore/SecureChannel/OpenSecureChannelRequest.h"
#include "OpcUaStackCore/SecureChannel/OpenSecureChannelResponse.h"
#include "OpcUaStackCore/SecureChannel/SecurityHeader.h"
#include "OpcUaStackCore/SecureChannel/SequenceHeader.h"
#include "OpcUaStackCore/Base/Utility.h"

#include <streambuf>
#include <iostream>

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(OpenSecureChannel_)

BOOST_AUTO_TEST_CASE(OpenSecureChannel_)
{
	std::cout << "OpenSecureChannel_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(OpenSecureChannel_Request)
{
	uint32_t pos;
	boost::posix_time::ptime ptime = boost::posix_time::from_iso_string("16010101T000000.000000000");
	OpenSecureChannelRequest::SPtr openSecureChannelRequestSPtr;
	MessageHeader::SPtr messageHeaderSPtr;
	SecurityHeader::SPtr securityHeaderSPtr;
	SequenceHeader::SPtr sequenceHeaderSPtr;
	RequestHeader::SPtr requestHeaderSPtr;
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
	channelId = 0;
	OpcUaNumber::opcUaBinaryEncode(ios1, channelId);

	// encode security header
	OpcUaByteString securityPolicyUri("http://opcfoundation.org/UA/SecurityPolicy#None");
	CertificateChain certificateChain;
	OpcUaByteString receiverCertificateThumbprint;
	SecurityHeader::opcUaBinaryEncode(
		ios1,
		securityPolicyUri,
		certificateChain,
		receiverCertificateThumbprint
	);

	// encode sequence header
	sequenceHeaderSPtr = constructSPtr<SequenceHeader>();
	sequenceHeaderSPtr->sequenceNumber(51);
	sequenceHeaderSPtr->requestId(1);
	sequenceHeaderSPtr->opcUaBinaryEncode(ios1);

	// encode message type id
	typeId.nodeId(OpcUaId_OpenSecureChannelRequest_Encoding_DefaultBinary);
	typeId.opcUaBinaryEncode(ios1);

	// encode OpenSecureChannel
	OpcUaByte clientNonce[1];
	clientNonce[0] = 0x00;
	openSecureChannelRequestSPtr = constructSPtr<OpenSecureChannelRequest>();
	openSecureChannelRequestSPtr->requestHeader()->time(ptime);
	openSecureChannelRequestSPtr->securityMode(MessageSecurityMode::EnumNone);
	openSecureChannelRequestSPtr->clientNonce( clientNonce, 1);
	openSecureChannelRequestSPtr->requestedLifetime(300000);
	openSecureChannelRequestSPtr->opcUaBinaryEncode(ios1);

	// encode MessageHeader
	messageHeaderSPtr = constructSPtr<MessageHeader>();
	messageHeaderSPtr->messageType(MessageType_OpenSecureChannel);
	messageHeaderSPtr->messageSize(OpcUaStackCore::count(sb1)+8);
	messageHeaderSPtr->opcUaBinaryEncode(ios2);

	// stream
	ios << ios2.rdbuf() << ios1.rdbuf();
	OpcUaStackCore::dumpHex(ios);

	std::stringstream ss;
	ss	<< "4f 50 4e 46 85 00 00 00  00 00 00 00 2f 00 00 00" 
		<< "68 74 74 70 3a 2f 2f 6f  70 63 66 6f 75 6e 64 61" 
		<< "74 69 6f 6e 2e 6f 72 67  2f 55 41 2f 53 65 63 75"
		<< "72 69 74 79 50 6f 6c 69  63 79 23 4e 6f 6e 65 ff" 
		<< "ff ff ff ff ff ff ff 33  00 00 00 01 00 00 00 01"
		<< "00 be 01 00 00 00 00 00  00 00 00 00 00 00 00 00"
		<< "00 00 00 00 00 ff ff ff  ff 00 00 00 00 00 00 00" 
		<< "00 00 00 00 00 00 00 00  01 00 00 00 01 00 00 00" 
		<< "00 e0 93 04 00";
	BOOST_REQUIRE(OpcUaStackCore::compare(ios, ss.str(), pos) == true);

	// decode MessageHeader
	messageHeaderSPtr = constructSPtr<MessageHeader>();
	messageHeaderSPtr->opcUaBinaryDecode(ios);
	BOOST_REQUIRE(messageHeaderSPtr->messageType() == MessageType_OpenSecureChannel);
	
	// decode channel id
	OpcUaNumber::opcUaBinaryDecode(ios, channelId);
	BOOST_REQUIRE(channelId == 0);

	// decode security header
	OpcUaByteString securityPolicyUri1;
	CertificateChain certificateChain1;
	OpcUaByteString receiverCertificateThumbprint1;
	SecurityHeader::opcUaBinaryDecode(
		ios,
		securityPolicyUri1,
		certificateChain1,
		receiverCertificateThumbprint1
	);
	BOOST_REQUIRE(securityPolicyUri1 == OpcUaByteString("http://opcfoundation.org/UA/SecurityPolicy#None"));

	// decode sequence header
	sequenceHeaderSPtr = constructSPtr<SequenceHeader>();
	sequenceHeaderSPtr->opcUaBinaryDecode(ios);
	BOOST_REQUIRE(sequenceHeaderSPtr->sequenceNumber() == 51);
	BOOST_REQUIRE(sequenceHeaderSPtr->requestId() == 1);

	// decode message type id
	typeId.opcUaBinaryDecode(ios);
	BOOST_REQUIRE(typeId.namespaceIndex() == 0);
	BOOST_REQUIRE(typeId.nodeId<OpcUaUInt32>() == OpcUaId_OpenSecureChannelRequest_Encoding_DefaultBinary);

	// decode OpenSecureChannel
	openSecureChannelRequestSPtr = constructSPtr<OpenSecureChannelRequest>();
	openSecureChannelRequestSPtr->opcUaBinaryDecode(ios);
	openSecureChannelRequestSPtr->clientNonce(&opcUaByte, &opcUaByteLen);
	BOOST_REQUIRE(openSecureChannelRequestSPtr->requestHeader()->time().dateTime() == ptime);
	BOOST_REQUIRE(openSecureChannelRequestSPtr->requestType() == RT_ISSUE);
	BOOST_REQUIRE(openSecureChannelRequestSPtr->securityMode() == MessageSecurityMode::EnumNone);
	BOOST_REQUIRE(openSecureChannelRequestSPtr->requestedLifetime() == 300000);
	BOOST_REQUIRE(opcUaByteLen == 1);
	BOOST_REQUIRE(opcUaByte[0] == 0x00);
}


BOOST_AUTO_TEST_CASE(OpenSecureChannel_Response)
{
	uint32_t pos;
	boost::posix_time::ptime ptime = boost::posix_time::from_iso_string("16010101T000000.000000000");
	OpenSecureChannelResponse::SPtr openSecureChannelResponseSPtr;
	MessageHeader::SPtr messageHeaderSPtr;
	SecurityHeader::SPtr securityHeaderSPtr;
	SequenceHeader::SPtr sequenceHeaderSPtr;
	RequestHeader::SPtr requestHeaderSPtr;
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

	// encode security header
	OpcUaByteString securityPolicyUri("http://opcfoundation.org/UA/SecurityPolicy#None");
		CertificateChain certificateChain;
		OpcUaByteString receiverCertificateThumbprint;
		SecurityHeader::opcUaBinaryEncode(
			ios1,
			securityPolicyUri,
			certificateChain,
			receiverCertificateThumbprint
		);

	// encode sequence header
	sequenceHeaderSPtr = constructSPtr<SequenceHeader>();
	sequenceHeaderSPtr->sequenceNumber(51);
	sequenceHeaderSPtr->requestId(1);
	sequenceHeaderSPtr->opcUaBinaryEncode(ios1);

	// encode message type id
	typeId.nodeId(OpcUaId_OpenSecureChannelResponse_Encoding_DefaultBinary);
	typeId.opcUaBinaryEncode(ios1);

	// security token
	SecurityToken::SPtr securityTokenSPtr = constructSPtr<SecurityToken>();
	securityTokenSPtr->channelId(153451225);
	securityTokenSPtr->tokenId(1);
	securityTokenSPtr->createAt(OpcUaDateTime(ptime));
	securityTokenSPtr->revisedLifetime(600000);

	// encode OpenSecureChannel
	OpcUaByte clientNonce[1];
	clientNonce[0] = 0x01;
	openSecureChannelResponseSPtr = constructSPtr<OpenSecureChannelResponse>();
	openSecureChannelResponseSPtr->securityToken(securityTokenSPtr);
	openSecureChannelResponseSPtr->responseHeader()->time(ptime);
	openSecureChannelResponseSPtr->serverNonce( clientNonce, 1);
	openSecureChannelResponseSPtr->opcUaBinaryEncode(ios1);

	// encode MessageHeader
	messageHeaderSPtr = constructSPtr<MessageHeader>();
	messageHeaderSPtr->messageType(MessageType_OpenSecureChannel);
	messageHeaderSPtr->messageSize(OpcUaStackCore::count(sb1)+8);
	messageHeaderSPtr->opcUaBinaryEncode(ios2);

	// stream
	ios << ios2.rdbuf() << ios1.rdbuf();
	OpcUaStackCore::dumpHex(ios);

	std::stringstream ss;
	ss	<< "4f 50 4e 46 88 00 00 00  d9 7a 25 09 2f 00 00 00"
		<< "68 74 74 70 3a 2f 2f 6f  70 63 66 6f 75 6e 64 61"
		<< "74 69 6f 6e 2e 6f 72 67  2f 55 41 2f 53 65 63 75"
		<< "72 69 74 79 50 6f 6c 69  63 79 23 4e 6f 6e 65 ff"
		<< "ff ff ff ff ff ff ff 33  00 00 00 01 00 00 00 01"
		<< "00 c1 01 00 00 00 00 00  00 00 00 00 00 00 00 00"
		<< "00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 d9"
		<< "7a 25 09 01 00 00 00 00  00 00 00 00 00 00 00 c0"
		<< "27 09 00 01 00 00 00 01";

	BOOST_REQUIRE(OpcUaStackCore::compare(ios, ss.str(), pos) == true);

	// decode MessageHeader
	messageHeaderSPtr = constructSPtr<MessageHeader>();
	messageHeaderSPtr->opcUaBinaryDecode(ios);
	BOOST_REQUIRE(messageHeaderSPtr->messageType() == MessageType_OpenSecureChannel);
	
	// decode channel id
	OpcUaNumber::opcUaBinaryDecode(ios, channelId);
	BOOST_REQUIRE(channelId == 153451225);

	// decode security header
	OpcUaByteString securityPolicyUri1;
	CertificateChain certificateChain1;
	OpcUaByteString receiverCertificateThumbprint1;
	SecurityHeader::opcUaBinaryDecode(
		ios,
		securityPolicyUri1,
		certificateChain1,
		receiverCertificateThumbprint1
	);
	BOOST_REQUIRE(securityPolicyUri1 == OpcUaByteString("http://opcfoundation.org/UA/SecurityPolicy#None"));

	// decode sequence header
	sequenceHeaderSPtr = constructSPtr<SequenceHeader>();
	sequenceHeaderSPtr->opcUaBinaryDecode(ios);
	BOOST_REQUIRE(sequenceHeaderSPtr->sequenceNumber() == 51);
	BOOST_REQUIRE(sequenceHeaderSPtr->requestId() == 1);

	// decode message type id
	typeId.opcUaBinaryDecode(ios);
	BOOST_REQUIRE(typeId.namespaceIndex() == 0);
	BOOST_REQUIRE(typeId.nodeId<OpcUaUInt32>() == OpcUaId_OpenSecureChannelResponse_Encoding_DefaultBinary);

	// decode OpenSecureChannel
	openSecureChannelResponseSPtr = constructSPtr<OpenSecureChannelResponse>();
	openSecureChannelResponseSPtr->opcUaBinaryDecode(ios);
	openSecureChannelResponseSPtr->serverNonce(&opcUaByte, &opcUaByteLen);
	BOOST_REQUIRE(openSecureChannelResponseSPtr->securityToken()->channelId() == 153451225);
	BOOST_REQUIRE(openSecureChannelResponseSPtr->securityToken()->tokenId() == 1);
	BOOST_REQUIRE(openSecureChannelResponseSPtr->securityToken()->createAt().dateTime() == ptime);
	BOOST_REQUIRE(openSecureChannelResponseSPtr->securityToken()->revisedLifetime() == 600000);
	BOOST_REQUIRE(opcUaByteLen == 1);
	BOOST_REQUIRE(opcUaByte[0] == 0x01);
}

BOOST_AUTO_TEST_SUITE_END()
