/*
   Copyright 2017-2018 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   Informationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Kai Huebl (kai@huebl-sgh.de)
 */

#include "OpcUaStackServer/ServiceSet/Session.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackCore/Base/Utility.h"
#include "OpcUaStackCore/SecureChannel/RequestHeader.h"
#include "OpcUaStackCore/ServiceSet/CreateSessionRequest.h"
#include "OpcUaStackCore/ServiceSet/CreateSessionResponse.h"
#include "OpcUaStackCore/ServiceSet/CloseSessionRequest.h"
#include "OpcUaStackCore/ServiceSet/CloseSessionResponse.h"
#include "OpcUaStackCore/ServiceSet/CancelRequest.h"
#include "OpcUaStackCore/ServiceSet/CancelResponse.h"
#include "OpcUaStackCore/ServiceSet/ActivateSessionResponse.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer 
{

	boost::mutex Session::mutex_;
	OpcUaUInt32 Session::uniqueSessionId_ = 0;
	OpcUaUInt32 Session::uniqueAuthenticationToken_ = 0;
	
	OpcUaUInt32 
	Session::getUniqueSessionId(void)
	{
		boost::mutex::scoped_lock g(mutex_);
		uniqueSessionId_++;
		return uniqueSessionId_;
	}

	OpcUaUInt32 
	Session::getUniqueAuthenticationToken(void)
	{
		boost::mutex::scoped_lock g(mutex_);
		uniqueAuthenticationToken_++;
		return uniqueAuthenticationToken_;
	}


	Session::Session(void)
	: Component()
	, sessionIf_(nullptr)
	, sessionState_(SessionState_Close)
	, sessionId_(getUniqueSessionId())
	, authenticationToken_(getUniqueAuthenticationToken())
	{
		Log(Info, "session construct")
			.parameter("SessionId", sessionId_)
			.parameter("AuthenticationToken", authenticationToken_);

		std::stringstream sessionName;
		sessionName << "Session_" << sessionId_;
		componentName(sessionName.str());
	}

	Session::~Session(void)
	{
		Log(Info, "session destruct")
			.parameter("SessionId", sessionId_)
			.parameter("AuthenticationToken", authenticationToken_);
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
	Session::sessionIf(SessionIf* sessionIf)
	{
		sessionIf_ = sessionIf;
	}

	OpcUaUInt32 
	Session::sessionId(void)
	{
		return sessionId_;
	}

	OpcUaUInt32 
	Session::authenticationToken(void)
	{
		return authenticationToken_;
	}

	void 
	Session::endpointDescriptionArray(EndpointDescriptionArray::SPtr endpointDescriptionArray)
	{
		endpointDescriptionArray_ = endpointDescriptionArray;
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// create session request
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	void
	Session::createSessionRequest(
		RequestHeader::SPtr requestHeader,
		SecureChannelTransaction::SPtr secureChannelTransaction
	)
	{
		Log(Debug, "receive create session request");
		secureChannelTransaction->responseTypeNodeId_ = OpcUaId_CreateSessionResponse_Encoding_DefaultBinary;

		logComponent();

		if (sessionState_ != SessionState_Close) {
			Log(Error, "receive create session request in invalid state")
				.parameter("SessionState", sessionState_);
			// FIXME: handle error ...
		}

		std::iostream ios(&secureChannelTransaction->is_);
		CreateSessionRequest createSessionRequest;
		createSessionRequest.opcUaBinaryDecode(ios);

		// FIXME: analyse request data

		std::iostream iosres(&secureChannelTransaction->os_);

		CreateSessionResponse createSessionResponse;
		createSessionResponse.responseHeader()->requestHandle(requestHeader->requestHandle());
		createSessionResponse.responseHeader()->serviceResult(Success);

		createSessionResponse.sessionId().namespaceIndex(1);
		createSessionResponse.sessionId().nodeId(sessionId_);
		createSessionResponse.authenticationToken().namespaceIndex(1);
		createSessionResponse.authenticationToken().nodeId(authenticationToken_);
		createSessionResponse.receivedSessionTimeout(120000);
		createSessionResponse.serverEndpoints(endpointDescriptionArray_);
		createSessionResponse.maxRequestMessageSize(0);

		createSessionResponse.responseHeader()->opcUaBinaryEncode(iosres);
		createSessionResponse.opcUaBinaryEncode(iosres);

		sessionState_ = SessionState_CreateSessionResponse;

		if (sessionIf_ != nullptr) {
			ResponseHeader::SPtr responseHeader = createSessionResponse.responseHeader();
			sessionIf_->responseMessage(responseHeader, secureChannelTransaction);
		}
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// activate session request
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	void
	Session::activateSessionRequest(
		RequestHeader::SPtr requestHeader,
		SecureChannelTransaction::SPtr secureChannelTransaction
	)
	{
		Log(Debug, "receive activate session request");
		secureChannelTransaction->responseTypeNodeId_ = OpcUaId_ActivateSessionResponse_Encoding_DefaultBinary;

		// FIXME: if authenticationToken in the secureChannelTransaction contains 0 then
		//        the session has a new sechure channel


		std::iostream ios(&secureChannelTransaction->is_);
		ActivateSessionRequest activateSessionRequest;
		activateSessionRequest.opcUaBinaryDecode(ios);

		if (sessionState_ != SessionState_CreateSessionResponse) {
			Log(Error, "receive activate session request in invalid state")
				.parameter("SessionState", sessionState_);
			activateSessionRequestError(requestHeader, secureChannelTransaction, BadIdentityTokenInvalid);
			return;
		}

		// FIXME: analyse request data

		std::iostream iosres(&secureChannelTransaction->os_);

		ActivateSessionResponse activateSessionResponse;
		activateSessionResponse.responseHeader()->requestHandle(requestHeader->requestHandle());
		activateSessionResponse.responseHeader()->serviceResult(Success);

		activateSessionResponse.responseHeader()->opcUaBinaryEncode(iosres);
		activateSessionResponse.opcUaBinaryEncode(iosres);

		sessionState_ = SessionState_Ready;

		//secureChannelTransaction->authenticationToken_ = authenticationToken_;

		if (sessionIf_ != nullptr) {
			ResponseHeader::SPtr responseHeader = activateSessionResponse.responseHeader();
			sessionIf_->responseMessage(responseHeader, secureChannelTransaction);
		}
	}

	void
	Session::activateSessionRequestError(
		RequestHeader::SPtr& requestHeader,
		SecureChannelTransaction::SPtr secureChannelTransaction,
		OpcUaStatusCode statusCode,
		bool deleteSession
	)
	{
		std::iostream iosres(&secureChannelTransaction->os_);

		ActivateSessionResponse activateSessionResponse;
		activateSessionResponse.responseHeader()->requestHandle(requestHeader->requestHandle());
		activateSessionResponse.responseHeader()->serviceResult(statusCode);

		activateSessionResponse.responseHeader()->opcUaBinaryEncode(iosres);
		activateSessionResponse.opcUaBinaryEncode(iosres);

		if (sessionIf_ != nullptr) {
			ResponseHeader::SPtr responseHeader = activateSessionResponse.responseHeader();
			sessionIf_->responseMessage(responseHeader, secureChannelTransaction);
			if (deleteSession) {
				sessionIf_->deleteSession(authenticationToken_);
			}
		}
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// close session request
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	void
	Session::closeSessionRequest(
		RequestHeader::SPtr requestHeader,
		SecureChannelTransaction::SPtr secureChannelTransaction
	)
	{
		Log(Debug, "receive close session request");
		secureChannelTransaction->responseTypeNodeId_ = OpcUaId_CloseSessionResponse_Encoding_DefaultBinary;

		std::iostream ios(&secureChannelTransaction->is_);
		CloseSessionRequest closeSessionRequest;
		closeSessionRequest.opcUaBinaryDecode(ios);

		std::iostream iosres(&secureChannelTransaction->os_);

		CloseSessionResponse closeSessionResponse;
		closeSessionResponse.responseHeader()->requestHandle(requestHeader->requestHandle());
		closeSessionResponse.responseHeader()->serviceResult(Success);

		closeSessionResponse.responseHeader()->opcUaBinaryEncode(iosres);
		closeSessionResponse.opcUaBinaryEncode(iosres);

		if (sessionIf_ != nullptr) {
			ResponseHeader::SPtr responseHeader = closeSessionResponse.responseHeader();
			sessionIf_->responseMessage(responseHeader, secureChannelTransaction);

			// FIXME: BUG - After deleting the session, the monitored item will send a notification. -> CORE
			//sessionIf_->deleteSession(authenticationToken_);
		}
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// cancel request
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	void
	Session::cancelRequest(
		RequestHeader::SPtr requestHeader,
		SecureChannelTransaction::SPtr secureChannelTransaction
	)
	{
		Log(Debug, "receive cancel request");
		secureChannelTransaction->responseTypeNodeId_ = OpcUaId_CancelResponse_Encoding_DefaultBinary;

		std::iostream ios(&secureChannelTransaction->is_);
		CancelRequest cancelRequest;
		cancelRequest.opcUaBinaryDecode(ios);

		cancelRequestError(requestHeader, secureChannelTransaction, BadNotImplemented);
	}

	void
	Session::cancelRequestError(
		RequestHeader::SPtr& requestHeader,
		SecureChannelTransaction::SPtr secureChannelTransaction,
		OpcUaStatusCode statusCode
	)
	{
		std::iostream iosres(&secureChannelTransaction->os_);

		CancelResponse cancelResponse;
		cancelResponse.responseHeader()->requestHandle(requestHeader->requestHandle());
		cancelResponse.responseHeader()->serviceResult(statusCode);

		cancelResponse.responseHeader()->opcUaBinaryEncode(iosres);
		cancelResponse.opcUaBinaryEncode(iosres);

		if (sessionIf_ != nullptr) {
			ResponseHeader::SPtr responseHeader = cancelResponse.responseHeader();
			sessionIf_->responseMessage(responseHeader, secureChannelTransaction);
		}
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// message request
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	void
	Session::messageRequest(
		RequestHeader::SPtr requestHeader,
		SecureChannelTransaction::SPtr secureChannelTransaction
	)
	{
		Log(Debug, "receive message request");

		if (sessionState_ != SessionState_Ready) {
			Log(Error, "receive message request in invalid state")
				.parameter("SessionState", sessionState_)
				.parameter("TypeId", secureChannelTransaction->requestTypeNodeId_);

			// FIXME: error handling
			return;
		}

		if (transactionManagerSPtr_.get() == nullptr) {
			Log(Error, "transaction manager empty");
			// ignore request - we cannot generate a response
			return;
		}

		ServiceTransaction::SPtr serviceTransactionSPtr = transactionManagerSPtr_->getTransaction(secureChannelTransaction->requestTypeNodeId_);
		if (serviceTransactionSPtr.get() == nullptr) {
			Log(Error, "receive invalid message type")
				.parameter("TypeId", secureChannelTransaction->requestTypeNodeId_);
			// ignore request - we cannot generate a response
			return;
		}
		secureChannelTransaction->responseTypeNodeId_ = OpcUaNodeId(serviceTransactionSPtr->nodeTypeResponse().nodeId<uint32_t>());
		serviceTransactionSPtr->componentSession(this);
		serviceTransactionSPtr->sessionId(sessionId_);
		Object::SPtr handle = secureChannelTransaction;
		serviceTransactionSPtr->handle(handle);
		// FIXME: serviceTransactionSPtr->channelId(secureChannelTransaction->channelId_);

		std::iostream ios(&secureChannelTransaction->is_);
		serviceTransactionSPtr->requestHeader(requestHeader);
		//OpcUaStackCore::dumpHex(sb);
		serviceTransactionSPtr->opcUaBinaryDecodeRequest(ios);
		//OpcUaStackCore::dumpHex(sb);
		serviceTransactionSPtr->requestId_ = secureChannelTransaction->requestId_;
		serviceTransactionSPtr->statusCode(Success);

		Log(Debug, "receive request in session")
			.parameter("TrxId", serviceTransactionSPtr->transactionId())
			.parameter("TypeId", serviceTransactionSPtr->requestName())
			.parameter("RequestId", serviceTransactionSPtr->requestId_);

		serviceTransactionSPtr->componentService()->send(serviceTransactionSPtr);
	}

	void
	Session::messageRequestError(
		SecureChannelTransaction::SPtr secureChannelTransaction,
		OpcUaStatusCode statusCode
	)
	{
		// FIXME: todo
	}

	void
	Session::receive(Message::SPtr message)
	{
		ServiceTransaction::SPtr serviceTransactionSPtr = boost::static_pointer_cast<ServiceTransaction>(message);
		Log(Debug, "receive response in session")
			.parameter("TrxId", serviceTransactionSPtr->transactionId())
			.parameter("TypeId", serviceTransactionSPtr->responseName())
			.parameter("RequestId", serviceTransactionSPtr->requestId_)
			.parameter("StatusCode", OpcUaStatusCodeMap::shortString(serviceTransactionSPtr->statusCode()));

		RequestHeader::SPtr requestHeader = serviceTransactionSPtr->requestHeader();
		ResponseHeader::SPtr responseHeader = serviceTransactionSPtr->responseHeader();
		responseHeader->requestHandle(requestHeader->requestHandle());
		responseHeader->serviceResult(serviceTransactionSPtr->statusCode());

		SecureChannelTransaction::SPtr secureChannelTransaction;
		secureChannelTransaction = boost::static_pointer_cast<SecureChannelTransaction>(serviceTransactionSPtr->handle());

		std::iostream iosres(&secureChannelTransaction->os_);

		responseHeader->opcUaBinaryEncode(iosres);
		serviceTransactionSPtr->opcUaBinaryEncodeResponse(iosres);

		if (sessionIf_ != nullptr) {
			sessionIf_->responseMessage(responseHeader, secureChannelTransaction);
		}
	}

	bool 
	Session::message(SecureChannelTransactionOld::SPtr secureChannelTransaction)
	{
		switch (secureChannelTransaction->requestTypeNodeId_.nodeId<OpcUaStackCore::OpcUaUInt32>())
		{
			case OpcUaId_CreateSessionRequest_Encoding_DefaultBinary:
			{
				Log(Debug, "receive create session request");
				secureChannelTransaction->responseTypeNodeId_.nodeId(OpcUaId_CreateSessionResponse_Encoding_DefaultBinary);
				return receiveCreateSessionRequest(secureChannelTransaction);
				break;
			}
			case OpcUaId_ActivateSessionRequest_Encoding_DefaultBinary:
			{
				Log(Debug, "receive activate session request");
				secureChannelTransaction->responseTypeNodeId_.nodeId(OpcUaId_ActivateSessionResponse_Encoding_DefaultBinary);
				return receiveActivateSessionRequest(secureChannelTransaction);
				break;
			}
			case OpcUaId_CloseSessionRequest_Encoding_DefaultBinary:
			{
				Log(Debug, "receive close session request");
				secureChannelTransaction->responseTypeNodeId_.nodeId(OpcUaId_CloseSessionResponse_Encoding_DefaultBinary);
				return receiveCloseSessionRequest(secureChannelTransaction);
				break;
			}
			case OpcUaId_CancelRequest_Encoding_DefaultBinary:
			{
				Log(Debug, "receive cancel request");
				secureChannelTransaction->responseTypeNodeId_.nodeId(OpcUaId_CancelResponse_Encoding_DefaultBinary);
				return receiveCancelRequest(secureChannelTransaction);
				break;
			}
			default:
			{
				return receiveMessage(secureChannelTransaction);
			}
		}
	}

	bool 
	Session::receiveCreateSessionRequest(SecureChannelTransactionOld::SPtr secureChannelTransaction)
	{
		// FIXME: authenticationToken in secureChannelTransaction must be 0

		if (sessionState_ != SessionState_Close) {
			Log(Error, "receive create session request in invalid state")
				.parameter("SessionState", sessionState_);
			return false;
		}

		std::iostream ios(&secureChannelTransaction->is_);
		CreateSessionRequest createSessionRequest;
		createSessionRequest.opcUaBinaryDecode(ios);

		// FIXME: analyse request data

		std::iostream iosres(&secureChannelTransaction->os_);

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

		createSessionResponse.responseHeader()->opcUaBinaryEncode(iosres);
		createSessionResponse.opcUaBinaryEncode(iosres);

		sessionState_ = SessionState_CreateSessionResponse;

		secureChannelTransaction->authenticationToken_ = authenticationToken_;
		if (sessionManagerIf_ != nullptr) sessionManagerIf_->sessionMessage(secureChannelTransaction);
		return true;
	}
		
	bool 
	Session::receiveActivateSessionRequest(SecureChannelTransactionOld::SPtr secureChannelTransaction)
	{
		// FIXME: if authenticationToken in the secureChannelTransaction contains 0 then 
		//        the session has a new sechure channel


		std::iostream ios(&secureChannelTransaction->is_);
		ActivateSessionRequest activateSessionRequest;
		activateSessionRequest.opcUaBinaryDecode(ios);

		if (sessionState_ != SessionState_CreateSessionResponse) {
			Log(Error, "receive activate session request in invalid state")
				.parameter("SessionState", sessionState_);
			//activateSessionRequestError(activateSessionRequest, secureChannelTransaction, BadIdentityTokenInvalid);
			return true;
		}

		// FIXME: analyse request data

		std::iostream iosres(&secureChannelTransaction->os_);

		ActivateSessionResponse activateSessionResponse;
		activateSessionResponse.responseHeader()->requestHandle(activateSessionRequest.requestHeader()->requestHandle());
		activateSessionResponse.responseHeader()->serviceResult(Success);

		activateSessionResponse.opcUaBinaryEncode(iosres);

		sessionState_ = SessionState_Ready;

		secureChannelTransaction->authenticationToken_ = authenticationToken_;
		if (sessionManagerIf_ != nullptr) sessionManagerIf_->sessionMessage(secureChannelTransaction);
		return true;
	}

	bool 
	Session::receiveCloseSessionRequest(SecureChannelTransactionOld::SPtr secureChannelTransaction)
	{
		std::iostream ios(&secureChannelTransaction->is_);
		CloseSessionRequest closeSessionRequest;
		closeSessionRequest.opcUaBinaryDecode(ios);

		std::iostream iosres(&secureChannelTransaction->os_);

		CloseSessionResponse closeSessionResponse;
		closeSessionResponse.responseHeader()->requestHandle(closeSessionRequest.requestHeader()->requestHandle());
		closeSessionResponse.responseHeader()->serviceResult(Success);

		if (sessionManagerIf_ != nullptr) sessionManagerIf_->sessionMessage(secureChannelTransaction);
		return true;
	}

	bool 
	Session::receiveCancelRequest(SecureChannelTransactionOld::SPtr secureChannelTransaction)
	{
		std::cout << "not implemented..." << std::endl;
		return false;
	}

	bool 
	Session::receiveMessage(SecureChannelTransactionOld::SPtr secureChannelTransaction)
	{
		if (sessionState_ != SessionState_Ready) {
			Log(Error, "receive message request in invalid state")
				.parameter("SessionState", sessionState_)
				.parameter("TypeId", secureChannelTransaction->requestTypeNodeId_);
			return false;
		}

		if (transactionManagerSPtr_.get() == nullptr) {
			Log(Error, "transaction manager empty");
			return false;
		}

		ServiceTransaction::SPtr serviceTransactionSPtr = transactionManagerSPtr_->getTransaction(secureChannelTransaction->requestTypeNodeId_);
		if (serviceTransactionSPtr.get() == nullptr) {
			Log(Error, "receive invalid message type")
				.parameter("TypeId", secureChannelTransaction->requestTypeNodeId_);
			return false;
		}
		serviceTransactionSPtr->componentSession(this);
		serviceTransactionSPtr->sessionId(sessionId_);
		serviceTransactionSPtr->channelId(secureChannelTransaction->channelId_);

		std::iostream ios(&secureChannelTransaction->is_);
		RequestHeader::SPtr requestHeader = serviceTransactionSPtr->requestHeader();
		//OpcUaStackCore::dumpHex(sb);
		requestHeader->opcUaBinaryDecode(ios);
		//OpcUaStackCore::dumpHex(sb);
		serviceTransactionSPtr->opcUaBinaryDecodeRequest(ios);
		//OpcUaStackCore::dumpHex(sb); 
		serviceTransactionSPtr->requestId_ = secureChannelTransaction->requestId_;
		serviceTransactionSPtr->statusCode(Success);

		Log(Debug, "receive request in session")
			.parameter("TrxId", serviceTransactionSPtr->transactionId())
			.parameter("TypeId", serviceTransactionSPtr->requestName())
			.parameter("RequestId", serviceTransactionSPtr->requestId_);

		serviceTransactionSPtr->componentService()->send(serviceTransactionSPtr);
		return true;
	}



}
