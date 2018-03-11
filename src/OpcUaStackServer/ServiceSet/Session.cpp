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
#include "OpcUaStackCore/Application/ApplicationAuthenticationContext.h"
#include "OpcUaStackCore/ServiceSet/UserNameIdentityToken.h"

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
	, forwardGlobalSync_()
	, sessionIf_(nullptr)
	, sessionState_(SessionState_Close)
	, sessionId_(getUniqueSessionId())
	, authenticationToken_(getUniqueAuthenticationToken())
	, applicationCertificate_()
	, endpointDescriptionArray_()
	, endpointDescription_()
	, userContext_()
	{
		Log(Info, "session construct")
			.parameter("SessionId", sessionId_)
			.parameter("AuthenticationToken", authenticationToken_);
		componentName("Session");

		// create new server nonce
		for (uint32_t idx=0; idx<32; idx++) {
			serverNonce_[idx] = (rand() / 256);
		}
	}

	Session::~Session(void)
	{
		Log(Info, "session destruct")
			.parameter("SessionId", sessionId_)
			.parameter("AuthenticationToken", authenticationToken_);
	}

	void
	Session::applicationCertificate(ApplicationCertificate::SPtr& applicationCertificate)
	{
		applicationCertificate_ = applicationCertificate;
	}

	void 
	Session::transactionManager(TransactionManager::SPtr transactionManagerSPtr)
	{
		transactionManagerSPtr_ = transactionManagerSPtr;
	}

	void
	Session::forwardGlobalSync(ForwardGlobalSync::SPtr& forwardGlobalSync)
	{
		forwardGlobalSync_ = forwardGlobalSync;
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
	// authentication
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	OpcUaStatusCode
	Session::authentication(ActivateSessionRequest& activateSessionRequest)
	{
		userContext_.reset();

		if (forwardGlobalSync_.get() == nullptr) {
			// no authentication is activated
			return Success;
		}
		if (!forwardGlobalSync_->authenticationService().isCallback()) {
			// no authentication is activated
			return Success;
		}

		if (activateSessionRequest.userIdentityToken().get() == nullptr) {
			// user identity token is invalid
			Log(Error, "authentication error, because user identity token is invalid");
			return BadIdentityTokenInvalid;
		}

		else {
			ExtensibleParameter::SPtr parameter = activateSessionRequest.userIdentityToken();
			if (!parameter->exist()) {
				// user identity token is invalid
				Log(Error, "authentication error, because user identity token not exist");
				return BadIdentityTokenInvalid;
			}
			else {
				OpcUaNodeId typeId = parameter->parameterTypeId();
				if (typeId == OpcUaNodeId(OpcUaId_AnonymousIdentityToken_Encoding_DefaultBinary)) {
					return authenticationAnonymous(activateSessionRequest, parameter);
				}
				else if (typeId == OpcUaNodeId(OpcUaId_UserNameIdentityToken_Encoding_DefaultBinary)) {
					return authenticationUserName(activateSessionRequest, parameter);
				}
				else if (typeId == OpcUaId_X509IdentityToken_Encoding_DefaultBinary) {
					return authenticationX509(activateSessionRequest, parameter);
				}
				else if (typeId == OpcUaId_IssuedIdentityToken_Encoding_DefaultBinary) {
					return authenticationIssued(activateSessionRequest, parameter);
				}
				else {
					// user identity token is invalid
					Log(Error, "authentication error, because unknown authentication type")
					    .parameter("AuthenticationType", typeId);
					return BadIdentityTokenInvalid;
				}
			}
		}

		return Success;
	}

	OpcUaStatusCode
	Session::authenticationAnonymous(ActivateSessionRequest& activateSessionRequest, ExtensibleParameter::SPtr& parameter)
	{
		ApplicationAuthenticationContext context;
		context.authenticationType_ = OpcUaId_AnonymousIdentityToken_Encoding_DefaultBinary;
		context.parameter_ = parameter;
		context.statusCode_ = Success;
		context.userContext_.reset();

		forwardGlobalSync_->authenticationService().callback()(&context);

		if (context.statusCode_ == Success) {
			userContext_ = context.userContext_;
		}

		return context.statusCode_;
	}

	OpcUaStatusCode
	Session::authenticationUserName(ActivateSessionRequest& activateSessionRequest, ExtensibleParameter::SPtr& parameter)
	{
		UserNameIdentityToken::SPtr token = parameter->parameter<UserNameIdentityToken>();

		// check parameter and password
		if (token->userName().size() == 0 || token->passwordLen() == 0) {
			return BadIdentityTokenInvalid;
		}
		if (endpointDescription_.get() == nullptr) {
			return BadIdentityTokenInvalid;
		}
		if (endpointDescription_->userIdentityTokens().get() == nullptr) {
			return BadIdentityTokenInvalid;
		}

		// find related identity token
		bool found = true;
		UserTokenPolicy::SPtr userTokenPolicy;
		for (uint32_t idx=0; idx<endpointDescription_->userIdentityTokens()->size(); idx++) {
			if (!endpointDescription_->userIdentityTokens()->get(idx, userTokenPolicy)) {
				continue;
			}

			if (userTokenPolicy->tokenType() != UserIdentityTokenType_Username) {
				continue;
			}

			if (userTokenPolicy->policyId() == token->policyId()) {
				found = true;
				break;
			}
		}
		if (!found) {
			return BadIdentityTokenInvalid;
		}

		Log(Debug, "authentication user name")
		    .parameter("PolicyId", token->policyId())
			.parameter("UserName", token->userName())
			.parameter("SecurityPolicyUri", userTokenPolicy->securityPolicyUri())
			.parameter("EncyptionAlgorithmus", token->encryptionAlgorithm());

		// FIXME: decrypt

		// create application context
		ApplicationAuthenticationContext context;
		context.authenticationType_ = OpcUaId_UserNameIdentityToken_Encoding_DefaultBinary;
		context.parameter_ = parameter;
		context.statusCode_ = Success;
		context.userContext_.reset();

		forwardGlobalSync_->authenticationService().callback()(&context);

		if (context.statusCode_ == Success) {
			userContext_ = context.userContext_;
		}

		return context.statusCode_;
	}

	OpcUaStatusCode
	Session::authenticationX509(ActivateSessionRequest& activateSessionRequest, ExtensibleParameter::SPtr& parameter)
	{
		Log(Error, "authentication error, because x509 authentication not implemented");
		return BadIdentityTokenInvalid;
	}
	OpcUaStatusCode
	Session::authenticationIssued(ActivateSessionRequest& activateSessionRequest, ExtensibleParameter::SPtr& parameter)
	{
		Log(Error, "authentication error, because issued authentication not implemented");
		return BadIdentityTokenInvalid;
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
		OpcUaStatusCode serviceResult = Success;

		Log(Debug, "receive create session request");
		secureChannelTransaction->responseTypeNodeId_ = OpcUaId_CreateSessionResponse_Encoding_DefaultBinary;

		if (sessionState_ != SessionState_Close) {
			Log(Error, "receive create session request in invalid state")
				.parameter("SessionState", sessionState_);
			// FIXME: handle error ...
		}

		std::iostream ios(&secureChannelTransaction->is_);
		CreateSessionRequest createSessionRequest;
		createSessionRequest.opcUaBinaryDecode(ios);

		// find related endpoint description
		bool found = false;
		for (uint32_t idx=0; idx<endpointDescriptionArray_->size(); idx++) {
			if (!endpointDescriptionArray_->get(idx, endpointDescription_)) continue;
			if (createSessionRequest.endpointUrl() == endpointDescription_->endpointUrl()) {
				found = true;
				break;
			}
		}
		if (!found) {
			serviceResult = BadServerUriInvalid;
		}

		std::iostream iosres(&secureChannelTransaction->os_);

		CreateSessionResponse createSessionResponse;
		createSessionResponse.responseHeader()->requestHandle(requestHeader->requestHandle());
		createSessionResponse.responseHeader()->serviceResult(serviceResult);

		createSessionResponse.sessionId().namespaceIndex(1);
		createSessionResponse.sessionId().nodeId(sessionId_);
		createSessionResponse.authenticationToken().namespaceIndex(1);
		createSessionResponse.authenticationToken().nodeId(authenticationToken_);
		createSessionResponse.receivedSessionTimeout(120000);
		createSessionResponse.serverEndpoints(endpointDescriptionArray_);
		createSessionResponse.maxRequestMessageSize(0);
		createSessionResponse.serverNonce((const OpcUaByte*)serverNonce_, 32);

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
		//        the session has a new secure channel


		std::iostream ios(&secureChannelTransaction->is_);
		ActivateSessionRequest activateSessionRequest;
		activateSessionRequest.opcUaBinaryDecode(ios);

		if (sessionState_ != SessionState_CreateSessionResponse) {
			Log(Error, "receive activate session request in invalid state")
				.parameter("SessionState", sessionState_);
			activateSessionRequestError(requestHeader, secureChannelTransaction, BadIdentityTokenInvalid);
			return;
		}

		// check username and password
		OpcUaStatusCode statusCode;
		statusCode = authentication(activateSessionRequest);

		std::iostream iosres(&secureChannelTransaction->os_);

		ActivateSessionResponse activateSessionResponse;
		activateSessionResponse.responseHeader()->requestHandle(requestHeader->requestHandle());
		activateSessionResponse.responseHeader()->serviceResult(statusCode);

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
		serviceTransactionSPtr->userContext(userContext_);
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

		OpcUaStatusCode serviceResult = Success;

		if (sessionState_ != SessionState_Close) {
			Log(Error, "receive create session request in invalid state")
				.parameter("SessionState", sessionState_);
			return false;
		}

		std::iostream ios(&secureChannelTransaction->is_);
		CreateSessionRequest createSessionRequest;
		createSessionRequest.opcUaBinaryDecode(ios);

		// find related endpoint description
		bool found = false;
		for (uint32_t idx=0; idx<endpointDescriptionArray_->size(); idx++) {
			if (!endpointDescriptionArray_->get(idx, endpointDescription_)) continue;
			if (createSessionRequest.endpointUrl() == endpointDescription_->endpointUrl()) {
				found = true;
				break;
			}
		}
		if (!found) {
			serviceResult = BadServerUriInvalid;
		}
		std::cout << "..." << serviceResult << std::endl;

		std::iostream iosres(&secureChannelTransaction->os_);

		CreateSessionResponse createSessionResponse;
		createSessionResponse.responseHeader()->requestHandle(createSessionRequest.requestHeader()->requestHandle());
		createSessionResponse.responseHeader()->serviceResult(serviceResult);

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
