#include "unittest.h"
#include "boost/asio.hpp"
#include "OpcUaStackCore/ServiceSet/GetEndpointsRequest.h"
#include "OpcUaStackCore/ServiceSet/GetEndpointsResponse.h"
#include "OpcUaStackCore/SecureChannel/MessageHeader.h"
#include "OpcUaStackCore/SecureChannel/SequenceHeader.h"
#include "OpcUaStackCore/SecureChannel/RequestHeader.h"
#include "OpcUaStackCore/SecureChannel/ResponseHeader.h"
#include "OpcUaStackCore/Base/Utility.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"

#include <streambuf>
#include <iostream>

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(GetEndpoints_)

BOOST_AUTO_TEST_CASE(GetEndpoints_Title)
{
	std::cout << "GetEndpoints_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(GetEndpoints_Request)
{
	RequestHeader::SPtr requestHeader = constructSPtr<RequestHeader>();
	uint32_t pos;
	OpcUaNodeId typeId;
	OpcUaGuid::SPtr opcUaGuidSPtr;
	OpcUaString::SPtr stringSPtr;
	MessageHeader::SPtr messageHeaderSPtr;
	SequenceHeader::SPtr sequenceHeaderSPtr;
	GetEndpointsRequest::SPtr getEndpointsRequestSPtr;
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
	sequenceHeaderSPtr = constructSPtr<SequenceHeader>();
	sequenceHeaderSPtr->sequenceNumber(54);
	sequenceHeaderSPtr->requestId(4);
	sequenceHeaderSPtr->opcUaBinaryEncode(ios1);

	// encode TypeId
	typeId.nodeId(OpcUaId_GetEndpointsRequest_Encoding_DefaultBinary);
	typeId.opcUaBinaryEncode(ios1);

	// build 
	getEndpointsRequestSPtr = constructSPtr<GetEndpointsRequest>();

	// build RequestHeader
	opcUaGuidSPtr = constructSPtr<OpcUaGuid>();
	*opcUaGuidSPtr = "0D4455B2-8D2F-B74F-864F-0AF5945DD833";
	
	requestHeader->sessionAuthenticationToken().namespaceIndex(1);
	requestHeader->sessionAuthenticationToken().nodeId(opcUaGuidSPtr);
	requestHeader->time(ptime);
	requestHeader->requestHandle(0);
	requestHeader->returnDisagnostics(0);
	requestHeader->timeoutHint(300000);
	
	// build Parameter
	stringSPtr = constructSPtr<OpcUaString>();
	stringSPtr->value("TestString");

	getEndpointsRequestSPtr->requestHeader()->time(ptime);
	getEndpointsRequestSPtr->endpointUrl("EndpointUrl");
	getEndpointsRequestSPtr->localeIds()->set(stringSPtr);
	getEndpointsRequestSPtr->profileUris()->set(stringSPtr);

	// encode
	requestHeader->opcUaBinaryEncode(ios1);
	getEndpointsRequestSPtr->opcUaBinaryEncode(ios1);

	// encode MessageHeader
	messageHeaderSPtr = constructSPtr<MessageHeader>();
	messageHeaderSPtr->messageType(MessageType_Message);
	messageHeaderSPtr->messageSize(OpcUaStackCore::count(sb1)+8);
	messageHeaderSPtr->opcUaBinaryEncode(ios2);

	// stream
	ios << ios2.rdbuf() << ios1.rdbuf();
	OpcUaStackCore::dumpHex(ios);
	
	std::stringstream ss;
	ss << "4d 53 47 46 7d 00 00 00  d9 7a 25 09 01 00 00 00"
	   << "36 00 00 00 04 00 00 00  01 00 ac 01 04 01 00 0d"
	   << "44 55 b2 8d 2f b7 4f 86  4f 0a f5 94 5d d8 33 00"
	   << "00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 ff"
	   << "ff ff ff e0 93 04 00 00  00 00 0b 00 00 00 45 6e"
	   << "64 70 6f 69 6e 74 55 72  6c 01 00 00 00 0a 00 00"
	   << "00 54 65 73 74 53 74 72  69 6e 67 01 00 00 00 0a"
	   << "00 00 00 54 65 73 74 53  74 72 69 6e 67";
	BOOST_REQUIRE(OpcUaStackCore::compare(ios, ss.str(), pos) == true);

	// decode MessageHeader
	messageHeaderSPtr = constructSPtr<MessageHeader>();
	messageHeaderSPtr->opcUaBinaryDecode(ios);
	BOOST_REQUIRE(messageHeaderSPtr->messageType() == MessageType_Message);

	// decode security header
	OpcUaNumber::opcUaBinaryDecode(ios, secureChannelId);
	BOOST_REQUIRE(secureChannelId == 153451225);
	OpcUaNumber::opcUaBinaryDecode(ios, secureTokenId);
	BOOST_REQUIRE(secureTokenId == 1);

	// decode sequence header
	sequenceHeaderSPtr = constructSPtr<SequenceHeader>();
	sequenceHeaderSPtr->opcUaBinaryDecode(ios);
	BOOST_REQUIRE(sequenceHeaderSPtr->sequenceNumber() == 54);
	BOOST_REQUIRE(sequenceHeaderSPtr->requestId() == 4);

	// decode message type id
	typeId.opcUaBinaryDecode(ios);
	BOOST_REQUIRE(typeId.namespaceIndex() == 0);
	BOOST_REQUIRE(typeId.nodeId<OpcUaUInt32>() == OpcUaId_GetEndpointsRequest_Encoding_DefaultBinary);

	// decode
	getEndpointsRequestSPtr = constructSPtr<GetEndpointsRequest>();
	requestHeader->opcUaBinaryDecode(ios);
	getEndpointsRequestSPtr->opcUaBinaryDecode(ios);

	std::string str;
	str = *requestHeader->sessionAuthenticationToken().nodeId<OpcUaGuid::SPtr>();
	BOOST_REQUIRE(requestHeader->sessionAuthenticationToken().namespaceIndex() == 1);
	BOOST_REQUIRE(str == "0D4455B2-8D2F-B74F-864F-0AF5945DD833");
	BOOST_REQUIRE(requestHeader->time().dateTime() == ptime);
	BOOST_REQUIRE(requestHeader->requestHandle() == 0);
	BOOST_REQUIRE(requestHeader->returnDisagnostics() == 0);
	BOOST_REQUIRE(requestHeader->timeoutHint() == 300000);
	
	BOOST_REQUIRE(getEndpointsRequestSPtr->endpointUrl().value() == "EndpointUrl");
	
	BOOST_REQUIRE(getEndpointsRequestSPtr->localeIds()->size() == 1);
	getEndpointsRequestSPtr->localeIds()->get(stringSPtr);
	BOOST_REQUIRE(stringSPtr->value() == "TestString");

	BOOST_REQUIRE(getEndpointsRequestSPtr->profileUris()->size() == 1);
	getEndpointsRequestSPtr->profileUris()->get(stringSPtr);
	BOOST_REQUIRE(stringSPtr->value() == "TestString");
}


BOOST_AUTO_TEST_CASE(GetEndpoints_Response)
{
	ResponseHeader::SPtr responseHeader = constructSPtr<ResponseHeader>();
	uint32_t pos;
	OpcUaNodeId typeId;
	OpcUaStatusCode statusCode;
	MessageHeader::SPtr messageHeaderSPtr;
	SequenceHeader::SPtr sequenceHeaderSPtr;
	GetEndpointsResponse::SPtr getEndpointsResponseSPtr;
	OpcUaString::SPtr opcUaStringSPtr;
	EndpointDescription::SPtr endpointDescriptionSPtr;
	UserTokenPolicy::SPtr userTokenPolicySPtr;
	OpcUaByte* opcUaByte;
	OpcUaInt32 opcUaByteLen;
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
	sequenceHeaderSPtr = constructSPtr<SequenceHeader>();
	sequenceHeaderSPtr->sequenceNumber(54);
	sequenceHeaderSPtr->requestId(4);
	sequenceHeaderSPtr->opcUaBinaryEncode(ios1);

	// encode TypeId
	typeId.nodeId(OpcUaId_GetEndpointsResponse_Encoding_DefaultBinary);
	typeId.opcUaBinaryEncode(ios1);

	// build 
	getEndpointsResponseSPtr = constructSPtr<GetEndpointsResponse>();
	getEndpointsResponseSPtr->responseHeader()->time(ptime);

	// build ResponseHeader
	statusCode = Success;
	responseHeader->time(ptime);
	responseHeader->requestHandle(0);
	responseHeader->serviceResult(statusCode);

	// build EndpointDescription
	endpointDescriptionSPtr = constructSPtr<EndpointDescription>();
	
	endpointDescriptionSPtr->endpointUrl("opt.tcp://localhost:481/0.0.0.0");
	endpointDescriptionSPtr->applicationDescription()->applicationUri("urn:localhost:compyny:Unittest");
	endpointDescriptionSPtr->applicationDescription()->productUri("urn:company:Unittest");
	endpointDescriptionSPtr->applicationDescription()->applicationName().text("company Unittest");
	endpointDescriptionSPtr->applicationDescription()->applicationType(AT_Server);
	endpointDescriptionSPtr->applicationDescription()->discoveryUrls()->resize(1);
	opcUaStringSPtr = constructSPtr<OpcUaString>();
	opcUaStringSPtr->value("opt.tcp://localhost:4841/0.0.0.0");
	endpointDescriptionSPtr->applicationDescription()->discoveryUrls()->set(0, opcUaStringSPtr);
	endpointDescriptionSPtr->serverCertificate((OpcUaByte*)"0123456789", 10);
	endpointDescriptionSPtr->messageSecurityMode(SM_None);
	endpointDescriptionSPtr->securityPolicyUri("http://opcfoundation.org/UA/SecurityPolicy#None");

	endpointDescriptionSPtr->userIdentityTokens()->resize(1);
	userTokenPolicySPtr = constructSPtr<UserTokenPolicy>();
	userTokenPolicySPtr->policyId("OpcUaStack");
	userTokenPolicySPtr->tokenType(UserIdentityTokenType_Anonymous);
	endpointDescriptionSPtr->userIdentityTokens()->push_back(userTokenPolicySPtr);

	endpointDescriptionSPtr->transportProfileUri("http://opcfoundation.org/UA-Profile/Transport/uatcp-uasc-uabinary");
	endpointDescriptionSPtr->securityLevel(0);

	getEndpointsResponseSPtr->endpoints()->set(endpointDescriptionSPtr);

	// encode
	responseHeader->opcUaBinaryEncode(ios1);
	getEndpointsResponseSPtr->opcUaBinaryEncode(ios1);

	// encode MessageHeader
	messageHeaderSPtr = constructSPtr<MessageHeader>();
	messageHeaderSPtr->messageType(MessageType_Message);
	messageHeaderSPtr->messageSize(OpcUaStackCore::count(sb1)+8);
	messageHeaderSPtr->opcUaBinaryEncode(ios2);

	// stream
	ios << ios2.rdbuf() << ios1.rdbuf();
	OpcUaStackCore::dumpHex(ios);

	std::stringstream ss;
	ss << "4d 53 47 46 8b 01 00 00  d9 7a 25 09 01 00 00 00"
	   << "36 00 00 00 04 00 00 00  01 00 af 01 00 00 00 00"
	   << "00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00"
	   << "00 00 00 00 01 00 00 00  1f 00 00 00 6f 70 74 2e"
	   << "74 63 70 3a 2f 2f 6c 6f  63 61 6c 68 6f 73 74 3a"
	   << "34 38 31 2f 30 2e 30 2e  30 2e 30 1e 00 00 00 75"
	   << "72 6e 3a 6c 6f 63 61 6c  68 6f 73 74 3a 63 6f 6d"
	   << "70 79 6e 79 3a 55 6e 69  74 74 65 73 74 14 00 00"
	   << "00 75 72 6e 3a 63 6f 6d  70 61 6e 79 3a 55 6e 69"
	   << "74 74 65 73 74 02 10 00  00 00 63 6f 6d 70 61 6e"
	   << "79 20 55 6e 69 74 74 65  73 74 00 00 00 00 ff ff"
	   << "ff ff ff ff ff ff 01 00  00 00 20 00 00 00 6f 70"
	   << "74 2e 74 63 70 3a 2f 2f  6c 6f 63 61 6c 68 6f 73"
	   << "74 3a 34 38 34 31 2f 30  2e 30 2e 30 2e 30 0a 00"
	   << "00 00 30 31 32 33 34 35  36 37 38 39 01 00 00 00"
	   << "2f 00 00 00 68 74 74 70  3a 2f 2f 6f 70 63 66 6f"
	   << "75 6e 64 61 74 69 6f 6e  2e 6f 72 67 2f 55 41 2f"
	   << "53 65 63 75 72 69 74 79  50 6f 6c 69 63 79 23 4e"
	   << "6f 6e 65 01 00 00 00 0a  00 00 00 4f 70 63 55 61"
	   << "53 74 61 63 6b 00 00 00  00 ff ff ff ff ff ff ff"
	   << "ff ff ff ff ff 41 00 00  00 68 74 74 70 3a 2f 2f"
	   << "6f 70 63 66 6f 75 6e 64  61 74 69 6f 6e 2e 6f 72"
	   << "67 2f 55 41 2d 50 72 6f  66 69 6c 65 2f 54 72 61"
	   << "6e 73 70 6f 72 74 2f 75  61 74 63 70 2d 75 61 73"
	   << "63 2d 75 61 62 69 6e 61  72 79 00";

	BOOST_REQUIRE(OpcUaStackCore::compare(ios, ss.str(), pos) == true);

	// decode MessageHeader
	messageHeaderSPtr = constructSPtr<MessageHeader>();
	messageHeaderSPtr->opcUaBinaryDecode(ios);
	BOOST_REQUIRE(messageHeaderSPtr->messageType() == MessageType_Message);

	// decode security header
	OpcUaNumber::opcUaBinaryDecode(ios, secureChannelId);
	BOOST_REQUIRE(secureChannelId == 153451225);
	OpcUaNumber::opcUaBinaryDecode(ios, secureTokenId);
	BOOST_REQUIRE(secureTokenId == 1);

	// decode sequence header
	sequenceHeaderSPtr = constructSPtr<SequenceHeader>();
	sequenceHeaderSPtr->opcUaBinaryDecode(ios);
	BOOST_REQUIRE(sequenceHeaderSPtr->sequenceNumber() == 54);
	BOOST_REQUIRE(sequenceHeaderSPtr->requestId() == 4);

	// decode message type id
	typeId.opcUaBinaryDecode(ios);
	BOOST_REQUIRE(typeId.namespaceIndex() == 0);
	BOOST_REQUIRE(typeId.nodeId<OpcUaUInt32>() == OpcUaId_GetEndpointsResponse_Encoding_DefaultBinary);

	// decode 
	getEndpointsResponseSPtr = constructSPtr<GetEndpointsResponse>();
	responseHeader->opcUaBinaryDecode(ios);
	getEndpointsResponseSPtr->opcUaBinaryDecode(ios);

	BOOST_REQUIRE(responseHeader->time().dateTime() == ptime);
	BOOST_REQUIRE(responseHeader->requestHandle() == 0);
	BOOST_REQUIRE(responseHeader->serviceResult() == Success);

	BOOST_REQUIRE(getEndpointsResponseSPtr->endpoints()->size() == 1);
	endpointDescriptionSPtr = constructSPtr<EndpointDescription>();
	getEndpointsResponseSPtr->endpoints()->get(endpointDescriptionSPtr);

	BOOST_REQUIRE(endpointDescriptionSPtr->endpointUrl() == "opt.tcp://localhost:481/0.0.0.0");
	BOOST_REQUIRE(endpointDescriptionSPtr->applicationDescription()->applicationUri() == "urn:localhost:compyny:Unittest");
	BOOST_REQUIRE(endpointDescriptionSPtr->applicationDescription()->productUri() == "urn:company:Unittest");
	BOOST_REQUIRE(endpointDescriptionSPtr->applicationDescription()->applicationName().text().value() == "company Unittest");
	BOOST_REQUIRE(endpointDescriptionSPtr->applicationDescription()->applicationType() == AT_Server);
	BOOST_REQUIRE(endpointDescriptionSPtr->applicationDescription()->discoveryUrls()->size() == 1);
	endpointDescriptionSPtr->applicationDescription()->discoveryUrls()->get(0, opcUaStringSPtr);
	BOOST_REQUIRE(opcUaStringSPtr->value() == "opt.tcp://localhost:4841/0.0.0.0");

	endpointDescriptionSPtr->serverCertificate(&opcUaByte, &opcUaByteLen);
	BOOST_REQUIRE(opcUaByteLen == 10);
	BOOST_REQUIRE(strncmp((char*)opcUaByte, "0123456789", 10) == 0);
	BOOST_REQUIRE(endpointDescriptionSPtr->messageSecurityMode() == SM_None);
	BOOST_REQUIRE(endpointDescriptionSPtr->securityPolicyUri() == "http://opcfoundation.org/UA/SecurityPolicy#None");

	BOOST_REQUIRE(endpointDescriptionSPtr->userIdentityTokens()->size() == 1);
	endpointDescriptionSPtr->userIdentityTokens()->get(0, userTokenPolicySPtr);
	BOOST_REQUIRE(userTokenPolicySPtr->policyId() == "OpcUaStack");
	BOOST_REQUIRE(userTokenPolicySPtr->tokenType() == UserIdentityTokenType_Anonymous);
	
	BOOST_REQUIRE(endpointDescriptionSPtr->transportProfileUri() == "http://opcfoundation.org/UA-Profile/Transport/uatcp-uasc-uabinary");
	BOOST_REQUIRE(endpointDescriptionSPtr->securityLevel() == 0);
}

BOOST_AUTO_TEST_SUITE_END()
