#include "unittest.h"
#include "boost/asio.hpp"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackCore/SecureChannel/MessageHeader.h"
#include "OpcUaStackCore/SecureChannel/SequenceHeader.h"
#include "OpcUaStackCore/ServiceSet/DeleteReferencesRequest.h"
#include "OpcUaStackCore/Base/Utility.h"
#include "OpcUaStackCore/ServiceSet/DeleteReferencesResponse.h"

#include <streambuf>
#include <iostream>

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(DeleteReferences_)

BOOST_AUTO_TEST_CASE(DeleteReferences_)
{
	std::cout << "DeleteReferences_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(DeleteReferences_Request)
{
	RequestHeader::SPtr requestHeader = boost::make_shared<RequestHeader>();
	MessageHeader::SPtr messageHeaderSPtr;
	boost::posix_time::ptime ptime = boost::posix_time::from_iso_string("16010101T000000.000000000");
	OpcUaGuid::SPtr opcUaGuidSPtr;
	DeleteReferencesRequest::SPtr deleteReferencesRequestSPtr;
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
	sequenceHeaderSPtr = boost::make_shared<SequenceHeader>();
	sequenceHeaderSPtr->sequenceNumber(52);
	sequenceHeaderSPtr->requestId(2);
	sequenceHeaderSPtr->opcUaBinaryEncode(ios1);

	// encode message type id
	typeId.nodeId(OpcUaId_DeleteReferencesRequest_Encoding_DefaultBinary);
	typeId.opcUaBinaryEncode(ios1);

	// encode AddReferencesRequest
	opcUaGuidSPtr = boost::make_shared<OpcUaGuid>();
	*opcUaGuidSPtr = "12345678-9ABC-DEF0-1234-56789ABCDEF0";

	OpcUaByte clientNonce[1];
	clientNonce[0] = 0x00;
	deleteReferencesRequestSPtr = boost::make_shared<DeleteReferencesRequest>();

	requestHeader->sessionAuthenticationToken().namespaceIndex(1);
	requestHeader->sessionAuthenticationToken().nodeId(opcUaGuidSPtr);
	requestHeader->time(ptime);
	requestHeader->requestHandle(1);
	requestHeader->returnDisagnostics(0);
	requestHeader->timeoutHint(10000);

	deleteReferencesRequestSPtr->referencesToDelete()->resize(1);

	// add  DeleteReferencesItem node
	{
		DeleteReferencesItem::SPtr deleteReferencesItemSPtr = boost::make_shared<DeleteReferencesItem>();
		deleteReferencesItemSPtr->sourceNodeId().set(11, 130);
		deleteReferencesItemSPtr->referenceTypeId().set(12, 130);
		deleteReferencesItemSPtr->isForward() = false;
		deleteReferencesItemSPtr->targetNodeId().set(13,130);
		deleteReferencesItemSPtr->deleteBidirectional() = true;
	
		deleteReferencesRequestSPtr->referencesToDelete()->set(0, deleteReferencesItemSPtr);
	}

	requestHeader->opcUaBinaryEncode(ios1);
	deleteReferencesRequestSPtr->opcUaBinaryEncode(ios1);

	// encode MessageHeader
	messageHeaderSPtr = boost::make_shared<MessageHeader>();
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
	messageHeaderSPtr = boost::make_shared<MessageHeader>();
	messageHeaderSPtr->opcUaBinaryDecode(ios);
	BOOST_REQUIRE(messageHeaderSPtr->messageType() == MessageType_Message);
	
	// decode channel id
	OpcUaNumber::opcUaBinaryDecode(ios, channelId);
	BOOST_REQUIRE(channelId == 153451225);

	// decode token id
	OpcUaNumber::opcUaBinaryDecode(ios, tokenId);
	BOOST_REQUIRE(tokenId == 1);
	
	// decode sequence header
	sequenceHeaderSPtr = boost::make_shared<SequenceHeader>();
	sequenceHeaderSPtr->opcUaBinaryDecode(ios);
	BOOST_REQUIRE(sequenceHeaderSPtr->sequenceNumber() == 52);
	BOOST_REQUIRE(sequenceHeaderSPtr->requestId() == 2);

	// decode message type id
	typeId.opcUaBinaryDecode(ios);
	BOOST_REQUIRE(typeId.namespaceIndex() == 0);
	BOOST_REQUIRE(typeId.nodeId<OpcUaUInt32>() == OpcUaId_DeleteReferencesRequest_Encoding_DefaultBinary);

	// decode DeleteReferencesRequest
	deleteReferencesRequestSPtr = boost::make_shared<DeleteReferencesRequest>();
	requestHeader->opcUaBinaryDecode(ios);
	deleteReferencesRequestSPtr->opcUaBinaryDecode(ios);

	std::string str;
	str = *requestHeader->sessionAuthenticationToken().nodeId<OpcUaGuid::SPtr>();
	BOOST_REQUIRE(requestHeader->sessionAuthenticationToken().namespaceIndex() == 1);
	BOOST_REQUIRE(str == "12345678-9ABC-DEF0-1234-56789ABCDEF0");
	BOOST_REQUIRE(requestHeader->time().dateTime() == ptime);
	BOOST_REQUIRE(requestHeader->requestHandle() == 1);
	BOOST_REQUIRE(requestHeader->returnDisagnostics() == 0);
	BOOST_REQUIRE(requestHeader->timeoutHint() == 10000);

	BOOST_REQUIRE(deleteReferencesRequestSPtr->referencesToDelete().get() != 0);
	BOOST_REQUIRE(deleteReferencesRequestSPtr->referencesToDelete()->size() == 1);

	// verify DeleteReferencesItem node
	{
		DeleteReferencesItem::SPtr deleteReferencesItemSPtr;
		BOOST_REQUIRE(deleteReferencesRequestSPtr->referencesToDelete()->get(0, deleteReferencesItemSPtr));
		BOOST_REQUIRE(deleteReferencesItemSPtr.get() != 0);

		BOOST_REQUIRE(deleteReferencesItemSPtr->sourceNodeId().namespaceIndex() == 130);
		BOOST_REQUIRE(deleteReferencesItemSPtr->sourceNodeId().nodeId<OpcUaUInt32>() == 11);
		BOOST_REQUIRE(deleteReferencesItemSPtr->referenceTypeId().namespaceIndex() == 130);
		BOOST_REQUIRE(deleteReferencesItemSPtr->referenceTypeId().nodeId<OpcUaUInt32>() == 12);

		BOOST_REQUIRE(deleteReferencesItemSPtr->isForward() == false);
		BOOST_REQUIRE(deleteReferencesItemSPtr->targetNodeId().namespaceIndex() == 130);
		BOOST_REQUIRE(deleteReferencesItemSPtr->targetNodeId().nodeId<OpcUaUInt32>() == 13);

		BOOST_REQUIRE(deleteReferencesItemSPtr->deleteBidirectional() == true);
	}

}


BOOST_AUTO_TEST_CASE(DeleteReferences_Response)
{
	ResponseHeader::SPtr responseHeader = boost::make_shared<ResponseHeader>();
	MessageHeader::SPtr messageHeaderSPtr;
	boost::posix_time::ptime ptime = boost::posix_time::from_iso_string("16010101T000000.000000000");
	OpcUaGuid::SPtr opcUaGuidSPtr;
	DeleteReferencesResponse::SPtr deleteReferencesResponseSPtr;
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
	sequenceHeaderSPtr = boost::make_shared<SequenceHeader>();
	sequenceHeaderSPtr->sequenceNumber(53);
	sequenceHeaderSPtr->requestId(3);
	sequenceHeaderSPtr->opcUaBinaryEncode(ios1);

	// encode message type id
	typeId.nodeId(OpcUaId_DeleteReferencesResponse_Encoding_DefaultBinary);
	typeId.opcUaBinaryEncode(ios1);

	// encode DeleteReferencesResponse
	deleteReferencesResponseSPtr = boost::make_shared<DeleteReferencesResponse>();

	responseHeader->time(ptime);
	responseHeader->requestHandle(1);
	responseHeader->serviceResult(Success);

	DeleteReferencesResultArray::SPtr deleteReferencesResultArraySPtr = boost::make_shared<DeleteReferencesResultArray>();
	deleteReferencesResultArraySPtr->resize(1);
	{
		DeleteReferencesResult::SPtr deleteReferencesResultSPtr = boost::make_shared<DeleteReferencesResult>();
		deleteReferencesResultSPtr->statusCode(Success);
		deleteReferencesResultArraySPtr->set(0, deleteReferencesResultSPtr);		
	}

	deleteReferencesResponseSPtr->results(deleteReferencesResultArraySPtr);

	responseHeader->opcUaBinaryEncode(ios1);
	deleteReferencesResponseSPtr->opcUaBinaryEncode(ios1);

	// encode MessageHeader
	messageHeaderSPtr = boost::make_shared<MessageHeader>();
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
	messageHeaderSPtr = boost::make_shared<MessageHeader>();
	messageHeaderSPtr->opcUaBinaryDecode(ios);
	BOOST_REQUIRE(messageHeaderSPtr->messageType() == MessageType_Message);
	
	// decode channel id
	OpcUaNumber::opcUaBinaryDecode(ios, channelId);
	BOOST_REQUIRE(channelId == 153451225);

	// decode token id
	OpcUaNumber::opcUaBinaryDecode(ios, tokenId);
	BOOST_REQUIRE(tokenId == 1);
	
	// decode sequence header
	sequenceHeaderSPtr = boost::make_shared<SequenceHeader>();
	sequenceHeaderSPtr->opcUaBinaryDecode(ios);
	BOOST_REQUIRE(sequenceHeaderSPtr->sequenceNumber() == 53);
	BOOST_REQUIRE(sequenceHeaderSPtr->requestId() == 3);

	// decode message type id
	typeId.opcUaBinaryDecode(ios);
	BOOST_REQUIRE(typeId.namespaceIndex() == 0);
	BOOST_REQUIRE(typeId.nodeId<OpcUaUInt32>() == OpcUaId_DeleteReferencesResponse_Encoding_DefaultBinary);

	//decode DeleteReferencesResponse
	deleteReferencesResponseSPtr = boost::make_shared<DeleteReferencesResponse>();
	responseHeader->opcUaBinaryDecode(ios);
	deleteReferencesResponseSPtr->opcUaBinaryDecode(ios);

	BOOST_REQUIRE(responseHeader->time().dateTime() == ptime);
	BOOST_REQUIRE(responseHeader->requestHandle() == 1);
	BOOST_REQUIRE(responseHeader->serviceResult() == Success);
	BOOST_REQUIRE(deleteReferencesResponseSPtr->results()->size() == 1);
	BOOST_REQUIRE(deleteReferencesResponseSPtr->diagnosticInfos()->size() == 0);

	{
		DeleteReferencesResult::SPtr deleteReferencesResultSPtr;
		BOOST_REQUIRE(deleteReferencesResponseSPtr->results()->get(0, deleteReferencesResultSPtr));
		BOOST_REQUIRE(deleteReferencesResultSPtr.get() != 0);
		BOOST_REQUIRE(deleteReferencesResultSPtr->statusCode() == Success);
	}

}

BOOST_AUTO_TEST_SUITE_END()
