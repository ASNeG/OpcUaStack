#include "OpcUaStackServer/ServiceSet/Session.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackCore/Base/Utility.h"
#include "OpcUaStackCore/SecureChannel/RequestHeader.h"
#include "OpcUaStackCore/ServiceSet/CreateSessionRequest.h"
#include "OpcUaStackCore/ServiceSet/CreateSessionResponse.h"
#include "OpcUaStackCore/ServiceSet/CloseSessionRequest.h"
#include "OpcUaStackCore/ServiceSet/CloseSessionResponse.h"
#include "OpcUaStackCore/ServiceSet/ActivateSessionResponse.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer 
{

	Session::Session(void)
	: Component()
	, sessionState_(SessionState_Close)
	, sessionId_(0)
	{
		componentName("Session");
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
	Session::sessionManagerIf(SessionManagerIf* sessionManagerIf)
	{
		sessionManagerIf_ = sessionManagerIf;
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
	Session::receive(OpcUaStackCore::OpcUaNodeId& typeId, boost::asio::streambuf& sb, SecureChannelTransaction& secureChannelTransaction)
	{
		switch (typeId.nodeId<OpcUaStackCore::OpcUaUInt32>())
		{
			case OpcUaId_CreateSessionRequest_Encoding_DefaultBinary:
			{
				return receiveCreateSessionRequest(typeId, sb, secureChannelTransaction);
				break;
			}
			case OpcUaId_ActivateSessionRequest_Encoding_DefaultBinary:
			{
				return receiveActivateSessionRequest(typeId, sb, secureChannelTransaction);
				break;
			}
			case OpcUaId_CloseSessionRequest_Encoding_DefaultBinary:
			{
				return receiveCloseSessionRequest(typeId, sb, secureChannelTransaction);
				break;
			}
			case OpcUaId_CancelRequest_Encoding_DefaultBinary:
			{
				return receiveCancelRequest(typeId, sb, secureChannelTransaction);
				break;
			}
			default:
			{
				return receiveMessage(typeId, sb, secureChannelTransaction);
			}
		}
	}

	bool 
	Session::receiveCreateSessionRequest(OpcUaStackCore::OpcUaNodeId& typeId, boost::asio::streambuf& sb, SecureChannelTransaction& secureChannelTransaction)
	{
		std::cout << "RECEIVE CREATE SESSION REQUEST" << this << std::endl;

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
		if (sessionManagerIf_ != nullptr) sessionManagerIf_->send(typeId, sbres, secureChannelTransaction);
		return true;
	}
		
	bool 
	Session::receiveActivateSessionRequest(OpcUaStackCore::OpcUaNodeId& typeId, boost::asio::streambuf& sb, SecureChannelTransaction& secureChannelTransaction)
	{
		std::cout << "RECEIVE ACTIVATE SESSION REQUEST" << this << std::endl;

		std::iostream ios(&sb);
		ActivateSessionRequest activateSessionRequest;
		activateSessionRequest.opcUaBinaryDecode(ios);

		if (sessionState_ != SessionState_CreateSessionResponse) {
			Log(Error, "receive activate session request in invalid state")
				.parameter("SessionState", sessionState_);
			activateSessionRequestError(activateSessionRequest, secureChannelTransaction, BadIdentityTokenInvalid);
			return true;
		}

		// FIXME: analyse request data

		boost::asio::streambuf sbres;
		std::iostream iosres(&sbres);

		ActivateSessionResponse activateSessionResponse;
		activateSessionResponse.responseHeader()->requestHandle(activateSessionRequest.requestHeader()->requestHandle());
		activateSessionResponse.responseHeader()->serviceResult(Success);

		activateSessionResponse.opcUaBinaryEncode(iosres);

		sessionState_ = SessionState_Ready;

		typeId.nodeId(OpcUaId_ActivateSessionResponse_Encoding_DefaultBinary);
		if (sessionManagerIf_ != nullptr) sessionManagerIf_->send(typeId, sbres, secureChannelTransaction);
		return true;
	}

	void
	Session::activateSessionRequestError(ActivateSessionRequest& activateSessionRequest, SecureChannelTransaction& secureChannelTransaction, OpcUaStatusCode statusCode)
	{
		boost::asio::streambuf sbres;
		std::iostream iosres(&sbres);

		ActivateSessionResponse activateSessionResponse;
		activateSessionResponse.responseHeader()->requestHandle(activateSessionRequest.requestHeader()->requestHandle());
		activateSessionResponse.responseHeader()->serviceResult(statusCode);

		activateSessionResponse.opcUaBinaryEncode(iosres);

		OpcUaNodeId typeId;
		typeId.nodeId(OpcUaId_ActivateSessionResponse_Encoding_DefaultBinary);
		if (sessionManagerIf_ != nullptr) sessionManagerIf_->send(typeId, sbres, secureChannelTransaction);
	}

	bool 
	Session::receiveCloseSessionRequest(OpcUaStackCore::OpcUaNodeId& typeId, boost::asio::streambuf& sb, SecureChannelTransaction& secureChannelTransaction)
	{
		std::iostream ios(&sb);
		CloseSessionRequest closeSessionRequest;
		closeSessionRequest.opcUaBinaryDecode(ios);

		boost::asio::streambuf sbres;
		std::iostream iosres(&sbres);

		CloseSessionResponse closeSessionResponse;
		closeSessionResponse.responseHeader()->requestHandle(closeSessionRequest.requestHeader()->requestHandle());
		closeSessionResponse.responseHeader()->serviceResult(Success);

		typeId.nodeId(OpcUaId_CloseSessionResponse_Encoding_DefaultBinary);
		if (sessionManagerIf_ != nullptr) sessionManagerIf_->send(typeId, sbres, secureChannelTransaction);
		return true;
	}

	bool 
	Session::receiveCancelRequest(OpcUaStackCore::OpcUaNodeId& typeId, boost::asio::streambuf& sb, SecureChannelTransaction& secureChannelTransaction)
	{
		std::cout << "not implemented..." << std::endl;
		return false;
	}

	bool 
	Session::receiveMessage(OpcUaStackCore::OpcUaNodeId& typeId, boost::asio::streambuf& sb, SecureChannelTransaction& secureChannelTransaction)
	{
		if (sessionState_ != SessionState_Ready) {
			Log(Error, "receive message request in invalid state")
				.parameter("SessionState", sessionState_)
				.parameter("TypeId", typeId);
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
		serviceTransactionSPtr->componentSession(this);
		serviceTransactionSPtr->sessionId(sessionId_);

		std::iostream ios(&sb);
		RequestHeader::SPtr requestHeader = serviceTransactionSPtr->requestHeader();
		OpcUaStackCore::dumpHex(sb);
		requestHeader->opcUaBinaryDecode(ios);
		OpcUaStackCore::dumpHex(sb);
		serviceTransactionSPtr->opcUaBinaryDecodeRequest(ios);
		OpcUaStackCore::dumpHex(sb);
		serviceTransactionSPtr->requestId_ = secureChannelTransaction.requestId_;
		serviceTransactionSPtr->statusCode(Success);


		Log(Debug, "receive request in session")
			.parameter("TrxId", serviceTransactionSPtr->transactionId())
			.parameter("TypeId", serviceTransactionSPtr->requestName());

		serviceTransactionSPtr->componentService()->send(typeId, serviceTransactionSPtr);
		return true;
	}

	void 
	Session::receive(OpcUaNodeId& typeId, Message::SPtr message) 
	{
		ServiceTransaction::SPtr serviceTransactionSPtr = boost::static_pointer_cast<ServiceTransaction>(message);
		Log(Debug, "receive response in session")
			.parameter("TrxId", serviceTransactionSPtr->transactionId())
			.parameter("TypeId", serviceTransactionSPtr->responseName())
			.parameter("StatusCode", OpcUaStatusCodeMap::shortString(serviceTransactionSPtr->statusCode()));

		RequestHeader::SPtr requestHeader = serviceTransactionSPtr->requestHeader();
		ResponseHeader::SPtr responseHeader = serviceTransactionSPtr->responseHeader();
		responseHeader->requestHandle(requestHeader->requestHandle());
		responseHeader->serviceResult(serviceTransactionSPtr->statusCode());

		boost::asio::streambuf sb;
		std::iostream ios(&sb);
		responseHeader->opcUaBinaryEncode(ios);
		serviceTransactionSPtr->opcUaBinaryEncodeResponse(ios);

		SecureChannelTransaction secureChannelTransaction;
		secureChannelTransaction.requestId_ = serviceTransactionSPtr->requestId_;
		if (sessionManagerIf_ != nullptr) sessionManagerIf_->send(serviceTransactionSPtr->nodeTypeResponse(), sb, secureChannelTransaction);

	}

}
