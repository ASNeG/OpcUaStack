#include "OpcUaStackServer/ServiceSet/Session.h"
#include "OpcUaStackCore/BuildInTypes/OPcUaIdentifier.h"
#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackCore/SecureChannel/RequestHeader.h"
#include "OpcUaStackCore/ServiceSet/CreateSessionRequest.h"
#include "OpcUaStackCore/ServiceSet/CreateSessionResponse.h"
#include "OpcUaStackCore/ServiceSet/ActivateSessionRequest.h"
#include "OpcUaStackCore/ServiceSet/ActivateSessionResponse.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer 
{

	Session::Session(void)
	: sessionState_(SessionState_Close)
	, sessionId_(0)
	{
	}

	Session::~Session(void)
	{
	}

	void 
	Session::transactionManager(TransactionManager::SPtr transactionManagerSPtr)
	{
		transactionManagerSPtr_ = transactionManagerSPtr;
	}

	void 
	Session::sessionSecureChannelIf(SessionSecureChannelIf* sessionSecureChannelIf)
	{
		sessionSecureChannelIf_ = sessionSecureChannelIf;
	}

	void 
	Session::sessionId(uint32_t sessionId)
	{
		sessionId = sessionId;
	}

	void 
	Session::authenticationToken(uint32_t authenticationToken)
	{
		authenticationToken_ = authenticationToken;
	}

	void 
	Session::endpointDescriptionArray(EndpointDescriptionArray::SPtr endpointDescriptionArray)
	{
		endpointDescriptionArray_ = endpointDescriptionArray;
	}

	bool 
	Session::receive(OpcUaStackCore::OpcUaNodeId& typeId, boost::asio::streambuf& sb)
	{
		switch (typeId.nodeId<OpcUaStackCore::OpcUaUInt32>())
		{
			case OpcUaId_CreateSessionRequest_Encoding_DefaultBinary:
			{
				return receiveCreateSessionRequest(typeId, sb);
				break;
			}
			case OpcUaId_ActivateSessionRequest_Encoding_DefaultBinary:
			{
				return receiveActivateSessionRequest(typeId, sb);
				break;
			}
			default:
			{
				return receiveMessage(typeId, sb);
			}
		}
	}

	bool 
	Session::receiveCreateSessionRequest(OpcUaStackCore::OpcUaNodeId& typeId, boost::asio::streambuf& sb)
	{
		std::cout << "RECEIVE CREATE SESSION REQUEST" << std::endl;

		if (sessionState_ != SessionState_Close) {
			Log(Error, "receive create session request in invalid state")
				.parameter("SessionState", sessionState_);
			return false;
		}

		std::iostream ios(&sb);
		CreateSessionRequest createSessionRequest;
		createSessionRequest.opcUaBinaryDecode(ios);

		// FIXME: analyse request data

		boost::asio::streambuf sbres;
		std::iostream iosres(&sbres);

		CreateSessionResponse createSessionResponse;
		createSessionResponse.responseHeader()->requestHandle(createSessionRequest.requestHeader()->requestHandle());
		createSessionResponse.responseHeader()->serviceResult(Success);

		createSessionResponse.sessionId().namespaceIndex(1);
		createSessionResponse.sessionId().nodeId(sessionId_);
		createSessionResponse.authenticationToken().namespaceIndex(1);
		createSessionResponse.authenticationToken().nodeId(sessionId_);
		createSessionResponse.receivedSessionTimeout(120000);
		createSessionResponse.serverEndpoints(endpointDescriptionArray_);
		createSessionResponse.maxRequestMessageSize(0);

		createSessionResponse.opcUaBinaryEncode(iosres);

		sessionState_ = SessionState_CreateSessionResponse;

		typeId.nodeId(OpcUaId_CreateSessionResponse_Encoding_DefaultBinary);
		if (sessionSecureChannelIf_ != nullptr) sessionSecureChannelIf_->send(typeId, sbres);
		return true;
	}
		
	bool 
	Session::receiveActivateSessionRequest(OpcUaStackCore::OpcUaNodeId& typeId, boost::asio::streambuf& sb)
	{
		std::cout << "RECEIVE ACTIVATE SESSION REQUEST" << std::endl;

		if (sessionState_ != SessionState_CreateSessionResponse) {
			Log(Error, "receive create session request in invalid state")
				.parameter("SessionState", sessionState_);
			return false;
		}

		std::iostream ios(&sb);
		ActivateSessionRequest activateSessionRequest;
		activateSessionRequest.opcUaBinaryDecode(ios);

		// FIXME: analyse request data

		boost::asio::streambuf sbres;
		std::iostream iosres(&sbres);

		ActivateSessionResponse activateSessionResponse;
		activateSessionResponse.responseHeader()->requestHandle(activateSessionRequest.requestHeader()->requestHandle());
		activateSessionResponse.responseHeader()->serviceResult(Success);

		activateSessionResponse.opcUaBinaryEncode(iosres);

		sessionState_ = SessionState_Ready;

		typeId.nodeId(OpcUaId_ActivateSessionResponse_Encoding_DefaultBinary);
		if (sessionSecureChannelIf_ != nullptr) sessionSecureChannelIf_->send(typeId, sbres);
		return true;
	}

	bool 
	Session::receiveMessage(OpcUaStackCore::OpcUaNodeId& typeId, boost::asio::streambuf& sb)
	{
		std::cout << "RECEIVE MESSAGE" << std::endl;

		if (sessionState_ != SessionState_Ready) {
			Log(Error, "receive message request in invalid state")
				.parameter("SessionState", sessionState_);
			return false;
		}

		if (transactionManagerSPtr_.get() == nullptr) {
			Log(Error, "transaction manager empty");
			return false;
		}

		ServiceTransaction::SPtr serviceTransactionSPtr = transactionManagerSPtr_->getTransaction(typeId);
		if (serviceTransactionSPtr.get() == nullptr) {
			Log(Error, "receive invalid message type")
				.parameter("TypeId", typeId);
			return false;
		}
		serviceTransactionSPtr->serviceTransactionIfSession(this);

		std::iostream ios(&sb);
		RequestHeader::SPtr requestHeader = serviceTransactionSPtr->requestHeader();
		requestHeader->opcUaBinaryDecode(ios);
		serviceTransactionSPtr->opcUaBinaryDecodeResponse(ios);

		serviceTransactionSPtr->serviceTransactionIfService()->receive(typeId, serviceTransactionSPtr);
		return true;
	}

	void 
	Session::receive(OpcUaNodeId& typeId, ServiceTransaction::SPtr serviceTransactionSPtr) 
	{
		std::cout << "RECEIVE SESSION RESPONSE..." << std::endl;

		RequestHeader::SPtr requestHeader = serviceTransactionSPtr->requestHeader();
		ResponseHeader::SPtr responseHeader = serviceTransactionSPtr->responseHeader();
		responseHeader->requestHandle(requestHeader->requestHandle());

		boost::asio::streambuf sb;
		std::iostream ios(&sb);
		responseHeader->opcUaBinaryEncode(ios);
		serviceTransactionSPtr->opcUaBinaryEncodeResponse(ios);

		if (sessionSecureChannelIf_ != nullptr) sessionSecureChannelIf_->send(typeId, sb);

	}

}