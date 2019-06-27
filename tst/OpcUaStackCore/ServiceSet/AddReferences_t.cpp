#include "unittest.h"
#include "boost/asio.hpp"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackCore/SecureChannel/MessageHeader.h"
#include "OpcUaStackCore/SecureChannel/SequenceHeader.h"
#include "OpcUaStackCore/SecureChannel/RequestHeader.h"
#include "OpcUaStackCore/SecureChannel/ResponseHeader.h"
#include "OpcUaStackCore/ServiceSet/AddReferencesRequest.h"
#include "OpcUaStackCore/Base/Utility.h"
#include "OpcUaStackCore/ServiceSet/AddReferencesResponse.h"

#include <streambuf>
#include <iostream>

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(AddReferences_)

BOOST_AUTO_TEST_CASE(AddReferences_)
{
	std::cout << "AddReferences_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(AddReferences_Request)
{
	RequestHeader::SPtr requestHeader = constructSPtr<RequestHeader>();
	MessageHeader::SPtr messageHeaderSPtr;
	boost::posix_time::ptime ptime = boost::posix_time::from_iso_string("16010101T000000.000000000");
	OpcUaGuid::SPtr opcUaGuidSPtr;
	AddReferencesRequest::SPtr addReferencesRequestSPtr;
	SequenceHeader::SPtr sequenceHeaderSPtr;
	OpcUaNodeId typeId;


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
	typeId.nodeId(OpcUaId_AddReferencesRequest_Encoding_DefaultBinary);
	typeId.opcUaBinaryEncode(ios1);

	// encode AddReferencesRequest
	opcUaGuidSPtr = constructSPtr<OpcUaGuid>();
	*opcUaGuidSPtr = "12345678-9ABC-DEF0-1234-56789ABCDEF0";

	OpcUaByte clientNonce[1];
	clientNonce[0] = 0x00;
	addReferencesRequestSPtr = constructSPtr<AddReferencesRequest>();

	requestHeader->sessionAuthenticationToken().namespaceIndex(1);
	requestHeader->sessionAuthenticationToken().nodeId(opcUaGuidSPtr);
	requestHeader->time(ptime);
	requestHeader->requestHandle(1);
	requestHeader->returnDisagnostics(0);
	requestHeader->timeoutHint(10000);


	addReferencesRequestSPtr->referencesToAdd()->resize(1);

	// add AddReferencesItem node
	{
		AddReferencesItem::SPtr addReferencesItemSPtr = constructSPtr<AddReferencesItem>();
		addReferencesItemSPtr->sourceNodeId().set(11, 130);
		addReferencesItemSPtr->referenceTypeId().set(12, 130);
		addReferencesItemSPtr->isForward() = false;
		addReferencesItemSPtr->targetServerUri().value("sample uri");
		addReferencesItemSPtr->targetNodeId().set(13,130);
		addReferencesItemSPtr->targetNodeClass().enumeration(NodeClass::EnumDataType);

		addReferencesRequestSPtr->referencesToAdd()->set(0, addReferencesItemSPtr);
	}

	requestHeader->opcUaBinaryEncode(ios1);
	addReferencesRequestSPtr->opcUaBinaryEncode(ios1);

	// encode MessageHeader
	messageHeaderSPtr = constructSPtr<MessageHeader>();
	messageHeaderSPtr->messageType(MessageType_Message);
	messageHeaderSPtr->messageSize(OpcUaStackCore::count(sb1)+8);
	messageHeaderSPtr->opcUaBinaryEncode(ios2);

	// stream
	ios << ios2.rdbuf() << ios1.rdbuf();
	OpcUaStackCore::dumpHex(ios);

	/*
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
    */

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
	BOOST_REQUIRE(typeId.nodeId<OpcUaUInt32>() == OpcUaId_AddReferencesRequest_Encoding_DefaultBinary);

	// decode AddReferencesRequest
	addReferencesRequestSPtr = constructSPtr<AddReferencesRequest>();
	requestHeader->opcUaBinaryDecode(ios);
	addReferencesRequestSPtr->opcUaBinaryDecode(ios);

	std::string str;
	str = *requestHeader->sessionAuthenticationToken().nodeId<OpcUaGuid::SPtr>();
	BOOST_REQUIRE(requestHeader->sessionAuthenticationToken().namespaceIndex() == 1);
	BOOST_REQUIRE(str == "12345678-9ABC-DEF0-1234-56789ABCDEF0");
	BOOST_REQUIRE(requestHeader->time().dateTime() == ptime);
	BOOST_REQUIRE(requestHeader->requestHandle() == 1);
	BOOST_REQUIRE(requestHeader->returnDisagnostics() == 0);
	BOOST_REQUIRE(requestHeader->timeoutHint() == 10000);

	BOOST_REQUIRE(addReferencesRequestSPtr->referencesToAdd().get() != 0);
	BOOST_REQUIRE(addReferencesRequestSPtr->referencesToAdd()->size() == 1);

	// verify AddReferencesItem node
	{
		AddReferencesItem::SPtr addReferencesItemSPtr;
		BOOST_REQUIRE(addReferencesRequestSPtr->referencesToAdd()->get(0, addReferencesItemSPtr));
		BOOST_REQUIRE(addReferencesItemSPtr.get() != 0);

		BOOST_REQUIRE(addReferencesItemSPtr->sourceNodeId().namespaceIndex() == 130);
		BOOST_REQUIRE(addReferencesItemSPtr->sourceNodeId().nodeId<OpcUaUInt32>() == 11);
		BOOST_REQUIRE(addReferencesItemSPtr->referenceTypeId().namespaceIndex() == 130);
		BOOST_REQUIRE(addReferencesItemSPtr->referenceTypeId().nodeId<OpcUaUInt32>() == 12);

		BOOST_REQUIRE(addReferencesItemSPtr->isForward() == false);
		BOOST_REQUIRE(addReferencesItemSPtr->targetServerUri().value() == "sample uri");
		BOOST_REQUIRE(addReferencesItemSPtr->targetNodeId().namespaceIndex() == 130);
		BOOST_REQUIRE(addReferencesItemSPtr->targetNodeId().nodeId<OpcUaUInt32>() == 13);

		BOOST_REQUIRE(addReferencesItemSPtr->targetNodeClass().enumeration() == NodeClass::EnumDataType);
	}

}


BOOST_AUTO_TEST_CASE(AddReferences_Response)
{
	ResponseHeader::SPtr responseHeader = constructSPtr<ResponseHeader>();
	MessageHeader::SPtr messageHeaderSPtr;
	boost::posix_time::ptime ptime = boost::posix_time::from_iso_string("16010101T000000.000000000");
	OpcUaGuid::SPtr opcUaGuidSPtr;
	AddReferencesResponse::SPtr addReferencesResponseSPtr;
	SequenceHeader::SPtr sequenceHeaderSPtr;
	OpcUaNodeId typeId;

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
	sequenceHeaderSPtr->sequenceNumber(53);
	sequenceHeaderSPtr->requestId(3);
	sequenceHeaderSPtr->opcUaBinaryEncode(ios1);

	// encode message type id
	typeId.nodeId(OpcUaId_AddReferencesResponse_Encoding_DefaultBinary);
	typeId.opcUaBinaryEncode(ios1);

	// encode AddReferencesResponse
	addReferencesResponseSPtr = constructSPtr<AddReferencesResponse>();

	responseHeader->time(ptime);
	responseHeader->requestHandle(1);
	responseHeader->serviceResult(Success);

	AddReferencesResultArray::SPtr addReferencesResultArraySPtr = constructSPtr<AddReferencesResultArray>();
	addReferencesResultArraySPtr->resize(1);
	{
		AddReferencesResult::SPtr addReferencesResultSPtr = constructSPtr<AddReferencesResult>();
		addReferencesResultSPtr->statusCode(Success);
		addReferencesResultArraySPtr->set(0, addReferencesResultSPtr);		
	}

	addReferencesResponseSPtr->results(addReferencesResultArraySPtr);

	responseHeader->opcUaBinaryEncode(ios1);
	addReferencesResponseSPtr->opcUaBinaryEncode(ios1);

	// encode MessageHeader
	messageHeaderSPtr = constructSPtr<MessageHeader>();
	messageHeaderSPtr->messageType(MessageType_Message);
	messageHeaderSPtr->messageSize(OpcUaStackCore::count(sb1)+8);
	messageHeaderSPtr->opcUaBinaryEncode(ios2);

	// stream
	ios << ios2.rdbuf() << ios1.rdbuf();
	OpcUaStackCore::dumpHex(ios);

	/*
	std::stringstream ss;
	ss	<< "4d 53 47 46 40 00 00 00  d9 7a 25 09 01 00 00 00"
		<< "35 00 00 00 03 00 00 00  01 00 d6 01 00 00 00 00"
		<< "00 00 00 00 01 00 00 00  00 00 00 00 00 00 00 00"
		<< "00 00 00 00 ff ff ff ff  00 00 00 00 00 00 00 00";
	BOOST_REQUIRE(OpcUaStackCore::compare(ios, ss.str(), pos) == true);
	*/

	
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
	BOOST_REQUIRE(sequenceHeaderSPtr->sequenceNumber() == 53);
	BOOST_REQUIRE(sequenceHeaderSPtr->requestId() == 3);

	// decode message type id
	typeId.opcUaBinaryDecode(ios);
	BOOST_REQUIRE(typeId.namespaceIndex() == 0);
	BOOST_REQUIRE(typeId.nodeId<OpcUaUInt32>() == OpcUaId_AddReferencesResponse_Encoding_DefaultBinary);

	//decode AddReferencesResponse
	addReferencesResponseSPtr = constructSPtr<AddReferencesResponse>();
	responseHeader->opcUaBinaryDecode(ios);
	addReferencesResponseSPtr->opcUaBinaryDecode(ios);

	BOOST_REQUIRE(responseHeader->time().dateTime() == ptime);
	BOOST_REQUIRE(responseHeader->requestHandle() == 1);
	BOOST_REQUIRE(responseHeader->serviceResult() == Success);
	BOOST_REQUIRE(addReferencesResponseSPtr->results()->size() == 1);
	BOOST_REQUIRE(addReferencesResponseSPtr->diagnosticInfos()->size() == 0);

	{
		AddReferencesResult::SPtr addReferencesResultSPtr;
		BOOST_REQUIRE(addReferencesResponseSPtr->results()->get(0, addReferencesResultSPtr));
		BOOST_REQUIRE(addReferencesResultSPtr.get() != 0);
		BOOST_REQUIRE(addReferencesResultSPtr->statusCode() == Success);
	}

}

BOOST_AUTO_TEST_SUITE_END()
