/*
   Copyright 2017-2021 Kai Huebl (kai@huebl-sgh.de)

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
#include "OpcUaStackCore/Base/MemoryBuffer.h"
#include "OpcUaStackCore/Base/Utility.h"
#include "OpcUaStackCore/SecureChannel/RequestHeader.h"
#include "OpcUaStackCore/ServiceSet/CreateSessionRequest.h"
#include "OpcUaStackCore/ServiceSet/CreateSessionResponse.h"
#include "OpcUaStackCore/ServiceSet/CloseSessionRequest.h"
#include "OpcUaStackCore/ServiceSet/CloseSessionResponse.h"
#include "OpcUaStackCore/ServiceSet/CancelRequest.h"
#include "OpcUaStackCore/ServiceSet/CancelResponse.h"
#include "OpcUaStackCore/ServiceSet/ActivateSessionResponse.h"
#include "OpcUaStackCore/ServiceSetServerInfo/ServerInfoServiceTransaction.h"
#include "OpcUaStackCore/Application/ApplicationAuthenticationContext.h"
#include "OpcUaStackCore/Application/ApplicationCloseSessionContext.h"
#include "OpcUaStackCore/StandardDataTypes/AnonymousIdentityToken.h"
#include "OpcUaStackCore/StandardDataTypes/UserNameIdentityToken.h"
#include "OpcUaStackCore/StandardDataTypes/IssuedIdentityToken.h"
#include "OpcUaStackCore/StandardDataTypes/X509IdentityToken.h"

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


	Session::Session(
        const std::string& serviceName,
	    IOThread* ioThread,
		MessageBus::SPtr& messageBus,
		boost::shared_ptr<boost::asio::io_service::strand>& strand
    )
	: ServerServiceBase()
	, forwardGlobalSync_()
	, sessionState_(SessionState_Close)
	, sessionId_(getUniqueSessionId())
	, authenticationToken_(getUniqueAuthenticationToken())
	, endpointDescriptionArray_()
	, endpointDescription_()
	, userContext_()
	{
		Log(Info, "session construct")
			.parameter("SessionId", sessionId_)
			.parameter("AuthenticationToken", authenticationToken_);

		// set parameter in server service base
		serviceName_ = serviceName;
		ServerServiceBase::ioThread_ = ioThread;
		strand_ = strand;
		messageBus_ = messageBus;

		// register message bus receiver
		MessageBusMemberConfig messageBusMemberConfig;
		messageBusMemberConfig.strand(strand_);
		messageBusMember_ = messageBus_->registerMember(serviceName_, messageBusMemberConfig);

		// activate receiver
		activateReceiver(
			[this](const MessageBusMember::WPtr& handleFrom, Message::SPtr& message){
				receive(handleFrom, message);
			}
		);
	}

	Session::~Session(void)
	{
		// deactivate receiver
		deactivateReceiver();
		messageBus_->deregisterMember(messageBusMember_);
	}

	void
	Session::createServerNonce(void)
	{
		for (uint32_t idx=0; idx<32; idx++) {
			serverNonce_[idx] = (rand() / 256);
		}
	}

	void
	Session::cryptoManager(CryptoManager::SPtr& cryptoManager)
	{
		cryptoManager_ = cryptoManager;
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
	Session::responseMessageCallback(const ResponseMessageCallback& responseMessageCallback)
	{
		responseMessageCallback_ = responseMessageCallback;
	}

	void
	Session::deleteSessionCallback(const DeleteSessionCallback& deleteSessionCallback)
	{
		deleteSessionCallback_ = deleteSessionCallback;
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
	Session::endpointDescriptionArray(EndpointDescriptionArray::SPtr& endpointDescriptionArray)
	{
		endpointDescriptionArray_ = endpointDescriptionArray;
	}

	void
	Session::endpointDescription(EndpointDescription::SPtr& endpointDescription)
	{
		assert(endpointDescription.get() != nullptr);
		endpointDescription_ = endpointDescription;
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

		OpcUaExtensibleParameter::SPtr parameter = activateSessionRequest.userIdentityToken();
		if (!parameter->exist()) {
			// user identity token is invalid
			Log(Error, "authentication error, because user identity token not exist");
			return BadIdentityTokenInvalid;
		}

		OpcUaNodeId typeId = parameter->parameterTypeId();
		if (typeId == OpcUaNodeId(OpcUaId_AnonymousIdentityToken_Encoding_DefaultBinary)) {
			return authenticationAnonymous(activateSessionRequest, parameter);
		}
		else if (typeId == OpcUaNodeId(OpcUaId_UserNameIdentityToken_Encoding_DefaultBinary)) {
			return authenticationUserName(activateSessionRequest, parameter);
		}
		else if (typeId == OpcUaNodeId(OpcUaId_X509IdentityToken_Encoding_DefaultBinary)) {
			return authenticationX509(activateSessionRequest, parameter);
		}
		else if (typeId == OpcUaNodeId(OpcUaId_IssuedIdentityToken_Encoding_DefaultBinary)) {
			return authenticationIssued(activateSessionRequest, parameter);
		}

		// user identity token is invalid
		Log(Error, "authentication error, because unknown authentication type")
			.parameter("AuthenticationType", typeId);
		return BadIdentityTokenInvalid;
	}

	OpcUaStatusCode
	Session::authenticationCloseSession(void)
	{
		ApplicationCloseSessionContext context;
		context.sessionId_ = sessionId_;
		context.statusCode_ = Success;
		context.userContext_ = userContext_;

		if (forwardGlobalSync_->closeSessionService().isCallback()) {
			forwardGlobalSync_->closeSessionService().callback()(&context);
		}

		userContext_.reset();
		return context.statusCode_;
	}

	OpcUaStatusCode
	Session::authenticationAnonymous(ActivateSessionRequest& activateSessionRequest, OpcUaExtensibleParameter::SPtr& parameter)
	{
		OpcUaStatusCode statusCode;
		Log(Debug, "Session::authenticationAnonymous");

		auto token = parameter->parameter<AnonymousIdentityToken>();

		// The policy id and the policy type are checked. An endpoint must exist
		// for this combination in the server configuration file.
		UserTokenPolicy::SPtr userTokenPolicy;
		statusCode = checkUserTokenPolicy(token->policyId(), UserTokenType::EnumAnonymous, userTokenPolicy);
		if (statusCode != Success) {
			return statusCode;
		}

		Log(Debug, "authentication anonymous")
		    .parameter("PolicyId", token->policyId());

		// create authentication context
		ApplicationAuthenticationContext context;
		context.authenticationType_ = OpcUaId_AnonymousIdentityToken_Encoding_DefaultBinary;
		context.parameter_ = parameter;
		context.sessionId_ = sessionId_;
		context.statusCode_ = Success;
		context.userContext_.reset();

		// call anonymous authentication
		forwardGlobalSync_->authenticationService().callback()(&context);

		if (context.statusCode_ == Success) {
			userContext_ = context.userContext_;
		}
		else {
			Log(Error, "authentication error in application")
				.parameter("StatusCode", OpcUaStatusCodeMap::shortString(context.statusCode_));
		}

		return context.statusCode_;
	}

	OpcUaStatusCode
	Session::authenticationUserName(ActivateSessionRequest& activateSessionRequest, OpcUaExtensibleParameter::SPtr& parameter)
	{
		OpcUaStatusCode statusCode;
		Log(Debug, "Session::authenticationUserName");

		auto token = parameter->parameter<UserNameIdentityToken>();

		// check parameter and password
		if (token->userName().size() == 0) {
			Log(Debug, "user name invalid");
			return BadIdentityTokenInvalid;
		}

		// The policy id and the policy type are checked. An endpoint must exist
		// for this combination in the server configuration file.
		UserTokenPolicy::SPtr userTokenPolicy;
		statusCode = checkUserTokenPolicy(token->policyId(), UserTokenType::EnumUserName, userTokenPolicy);
		if (statusCode != Success) {
			return statusCode;
		}

		Log(Debug, "authentication user name")
		    .parameter("PolicyId", token->policyId())
			.parameter("UserName", token->userName())
			.parameter("SecurityPolicyUri", userTokenPolicy->securityPolicyUri())
			.parameter("EncyptionAlgorithmus", token->encryptionAlgorithm());

		if (token->encryptionAlgorithm() == OpcUaString("")) {
			// we use a plain password

			// create application context
			ApplicationAuthenticationContext context;
			context.authenticationType_ = OpcUaId_UserNameIdentityToken_Encoding_DefaultBinary;
			context.parameter_ = parameter;
			context.sessionId_ = sessionId_;
			context.statusCode_ = Success;
			context.userContext_.reset();

			// call user name authentication
			forwardGlobalSync_->authenticationService().callback()(&context);

			if (context.statusCode_ == Success) {
				userContext_ = context.userContext_;
			}
			else {
				Log(Error, "authentication error in application")
					.parameter("StatusCode", OpcUaStatusCodeMap::shortString(context.statusCode_));
			}

			return context.statusCode_;
		}

		// get cryption base and check cryption alg
		CryptoBase::SPtr cryptoBase = cryptoManager_->get(userTokenPolicy->securityPolicyUri());
		if (cryptoBase.get() == nullptr) {
			Log(Debug, "crypto manager not found")
				.parameter("SecurityPolicyUri", userTokenPolicy->securityPolicyUri());
			return BadIdentityTokenRejected;
		}

		uint32_t encryptionAlg = EnryptionAlgs::uriToEncryptionAlg(token->encryptionAlgorithm());
		if (encryptionAlg == 0) {
			Log(Debug, "encryption alg invalid")
				.parameter("EncryptionAlgorithm", token->encryptionAlgorithm());
			return BadIdentityTokenRejected;;
		}

		// decrypt password
		char* encryptedTextBuf;
		int32_t encryptedTextLen;
		token->password().value((OpcUaByte**)&encryptedTextBuf, &encryptedTextLen);
		if (encryptedTextLen <= 0) {
			Log(Debug, "password format invalid");
			return BadIdentityTokenRejected;;
		}

		char* plainTextBuf;
		uint32_t plainTextLen;
		MemoryBuffer plainText(encryptedTextLen);
		plainTextBuf = plainText.memBuf();
		plainTextLen = plainText.memLen();

		auto privateKey = cryptoManager_->applicationCertificate()->privateKey();
		cryptoBase->isLogging(true);
		statusCode = cryptoBase->asymmetricDecrypt(
			encryptedTextBuf,
			encryptedTextLen,
			*privateKey.get(),
			plainTextBuf,
			&plainTextLen
		);
		if (statusCode != Success) {
			Log(Debug, "decrypt password error")
				.parameter("StatusCode", OpcUaStatusCodeMap::shortString(statusCode));
			return BadIdentityTokenRejected;;
		}

		// check decrypted password and server nonce
		if (memcmp(serverNonce_, &plainTextBuf[plainTextLen-32] , 32) != 0) {
			Log(Debug, "decrypt password server nonce error");
			return BadIdentityTokenRejected;;
		}

		size_t passwordLen = plainTextLen-36;
		if (passwordLen < 0) {
			Log(Debug, "decrypted password length < 0");
			return BadIdentityTokenRejected;;
		}

		token->password().value((const OpcUaByte*)&plainTextBuf[4], passwordLen);

		// create application context
		ApplicationAuthenticationContext context;
		context.authenticationType_ = OpcUaId_UserNameIdentityToken_Encoding_DefaultBinary;
		context.parameter_ = parameter;
		context.sessionId_ = sessionId_;
		context.statusCode_ = Success;
		context.userContext_.reset();

		forwardGlobalSync_->authenticationService().callback()(&context);

		if (context.statusCode_ == Success) {
			userContext_ = context.userContext_;
		}

		return context.statusCode_;
	}

	OpcUaStatusCode
	Session::authenticationX509(ActivateSessionRequest& activateSessionRequest, OpcUaExtensibleParameter::SPtr& parameter)
	{
		OpcUaStatusCode statusCode;
		Log(Debug, "Session::authenticationX509");

		auto token = parameter->parameter<X509IdentityToken>();

		// check parameter and password
		if (token->certificateData().size() == 0) {
			Log(Debug, "token data invalid");
			return BadIdentityTokenInvalid;
		}

		// check token policy
		UserTokenPolicy::SPtr userTokenPolicy;
		statusCode = checkUserTokenPolicy(token->policyId(), UserTokenType::EnumCertificate, userTokenPolicy);
		if (statusCode != Success) {
			return statusCode;
		}

		// get signature data
		auto userTokenSignature = activateSessionRequest.userTokenSignature();
		if (userTokenSignature.get() == nullptr) {
			Log(Debug, "missing user token signature")
				.parameter("PolicyId", token->policyId());
			return BadIdentityTokenInvalid;
		}

		Log(Debug, "authentication x509")
		    .parameter("PolicyId", token->policyId())
			.parameter("CertificateData", token->certificateData())
			.parameter("SecurityPolicyUri", userTokenPolicy->securityPolicyUri())
			.parameter("SignaturAlgorithm", userTokenSignature->algorithm());

		// get cryption base and check cryption alg
		CryptoBase::SPtr cryptoBase = cryptoManager_->get(userTokenPolicy->securityPolicyUri());
		if (cryptoBase.get() == nullptr) {
			Log(Debug, "crypto manager not found")
				.parameter("SecurityPolicyUri", userTokenPolicy->securityPolicyUri());
			return BadIdentityTokenRejected;
		}

		uint32_t signatureAlg = SignatureAlgs::uriToSignatureAlg(userTokenSignature->algorithm());
		if (signatureAlg == 0) {
			Log(Debug, "encryption alg invalid")
				.parameter("SignatureAlgorithm", userTokenSignature->algorithm());
			return BadIdentityTokenRejected;;
		}

		// get public key
		MemoryBuffer certificateText(token->certificateData());
		Certificate certificate;
		if (!certificate.fromDERBuf(certificateText)) {
			Log(Debug, "certificate invalid");
			return BadIdentityTokenRejected;;
		}
		PublicKey publicKey = certificate.publicKey();

		// validate signature
		statusCode = userTokenSignature->verifySignature(
			certificateText,
			publicKey,
			*cryptoBase
		);

		// create application context
		ApplicationAuthenticationContext context;
		context.authenticationType_ = OpcUaId_X509IdentityToken_Encoding_DefaultBinary;
		context.parameter_ = parameter;
		context.sessionId_ = sessionId_;
		context.statusCode_ = Success;
		context.userContext_.reset();

		forwardGlobalSync_->authenticationService().callback()(&context);

		if (context.statusCode_ == Success) {
			userContext_ = context.userContext_;
		}
		else {
			Log(Error, "authentication error in application")
				.parameter("StatusCode", OpcUaStatusCodeMap::shortString(context.statusCode_));
		}

		return context.statusCode_;
	}

	OpcUaStatusCode
	Session::authenticationIssued(ActivateSessionRequest& activateSessionRequest, OpcUaExtensibleParameter::SPtr& parameter)
	{
		OpcUaStatusCode statusCode;
		Log(Debug, "Session::authenticationIssued");

		auto token = parameter->parameter<IssuedIdentityToken>();

		// check parameter and password
		if (token->tokenData().size() == 0) {
			Log(Debug, "token data invalid");
			return BadIdentityTokenInvalid;
		}

		// check token policy
		UserTokenPolicy::SPtr userTokenPolicy;
		statusCode = checkUserTokenPolicy(token->policyId(), UserTokenType::EnumIssuedToken, userTokenPolicy);
		if (statusCode != Success) {
			return statusCode;
		}

		Log(Debug, "authentication issued")
		    .parameter("PolicyId", token->policyId())
			.parameter("TokenData", token->tokenData())
			.parameter("SecurityPolicyUri", userTokenPolicy->securityPolicyUri())
			.parameter("EncyptionAlgorithmus", token->encryptionAlgorithm());

		// get cryption base and check cryption alg
		CryptoBase::SPtr cryptoBase = cryptoManager_->get(userTokenPolicy->securityPolicyUri());
		if (cryptoBase.get() == nullptr) {
			Log(Debug, "crypto manager not found")
				.parameter("SecurityPolicyUri", userTokenPolicy->securityPolicyUri());
			return BadIdentityTokenRejected;
		}
		uint32_t encryptionAlg = EnryptionAlgs::uriToEncryptionAlg(token->encryptionAlgorithm());
		if (encryptionAlg == 0) {
			Log(Debug, "encryption alg invalid")
				.parameter("EncryptionAlgorithm", token->encryptionAlgorithm());
			return BadIdentityTokenRejected;;
		}

		// decrypt token data
		char* encryptedTextBuf;
		int32_t encryptedTextLen;
		token->tokenData().value((OpcUaByte**)&encryptedTextBuf, &encryptedTextLen);
		if (encryptedTextLen <= 0) {
			Log(Debug, "token data format invalid");
			return BadIdentityTokenRejected;;
		}

		char* plainTextBuf;
		uint32_t plainTextLen;
		MemoryBuffer plainText(encryptedTextLen);
		plainTextBuf = plainText.memBuf();
		plainTextLen = plainText.memLen();

		auto privateKey = cryptoManager_->applicationCertificate()->privateKey();

		statusCode = cryptoBase->asymmetricDecrypt(
			encryptedTextBuf,
			encryptedTextLen,
			*privateKey.get(),
			plainTextBuf,
			&plainTextLen
		);
		if (statusCode != Success) {
			Log(Debug, "decrypt token data error");
			return BadIdentityTokenRejected;;
		}

		// check decrypted password and server nonce
		if (memcmp(serverNonce_, &plainTextBuf[plainTextLen-32] , 32) != 0) {
			Log(Debug, "decrypt token data server nonce error");
				return BadIdentityTokenRejected;;
		}
		token->tokenData().value((const OpcUaByte*)&plainTextBuf[4], plainTextLen-36);

		// create application context
		ApplicationAuthenticationContext context;
		context.authenticationType_ = OpcUaId_IssuedIdentityToken_Encoding_DefaultBinary;
		context.parameter_ = parameter;
		context.sessionId_ = sessionId_;
		context.statusCode_ = Success;
		context.userContext_.reset();

		forwardGlobalSync_->authenticationService().callback()(&context);

		if (context.statusCode_ == Success) {
			userContext_ = context.userContext_;
		}
		else {
			Log(Error, "authentication error in application")
				.parameter("StatusCode", OpcUaStatusCodeMap::shortString(context.statusCode_));
		}

		return context.statusCode_;
	}

	OpcUaStatusCode
	Session::checkUserTokenPolicy(
		const std::string& policyId,
		UserTokenType::Enum userIdentityTokenType,
		UserTokenPolicy::SPtr& userTokenPolicy
	)
	{
		if (endpointDescription_.get() == nullptr) {
			Log(Debug, "endpoint description not exist");
			return BadIdentityTokenInvalid;
		}

		if (endpointDescription_->userIdentityTokens().size() == 0) {
			Log(Debug, "user identity token not exist");
			return BadIdentityTokenInvalid;
		}

		// find related identity token
		bool found = false;
		for (uint32_t idx=0; idx<endpointDescription_->userIdentityTokens().size(); idx++) {
			if (!endpointDescription_->userIdentityTokens().get(idx, userTokenPolicy)) {
				continue;
			}

			if (userTokenPolicy->tokenType() != userIdentityTokenType) {
				continue;
			}

			if (userTokenPolicy->policyId() == policyId) {
				found = true;
				break;
			}
		}
		if (!found) {
			Log(Debug, "identity token for policy not found in endpoint")
				.parameter("PolicyId", policyId);
			return BadIdentityTokenInvalid;
		}

		return Success;
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
		RequestHeader::SPtr& requestHeader,
		SecureChannel* secureChannel
	)
	{
		auto secureChannelTransaction = secureChannel->secureChannelTransaction_;
		auto& securitySettings = secureChannel->securitySettings();

		Log(Debug, "receive create session request");
		secureChannelTransaction->responseTypeNodeId_ = OpcUaId_CreateSessionResponse_Encoding_DefaultBinary;

		// check state of session.
		if (sessionState_ != SessionState_Close) {
			Log(Error, "receive create session request in invalid state - delete session")
				.parameter("SessionState", sessionState_);
			createSessionRequestError(requestHeader, secureChannelTransaction, BadInternalError);
			closeAndDeleteSession();
			return;
		}

		// decode create session request
		std::iostream ios(&secureChannelTransaction->is_);
		CreateSessionRequest createSessionRequest;
		if (!createSessionRequest.opcUaBinaryDecode(ios)) {
			Log(Error, "decode create session request error - delete session");
			createSessionRequestError(requestHeader, secureChannelTransaction, BadInvalidArgument);
			closeAndDeleteSession();
			return;
		}

		// create session response
		std::iostream iosres(&secureChannelTransaction->os_);
		CreateSessionResponse createSessionResponse;
		createSessionResponse.responseHeader()->requestHandle(requestHeader->requestHandle());
		createSessionResponse.responseHeader()->serviceResult(Success);
		createSessionResponse.serverNonce((const OpcUaByte*)serverNonce_, 32);

		// check certificate if exist
		if (securitySettings.ownSecurityPolicy() != SecurityPolicy::EnumNone) {
			CertificateChain partnerCertificateChain;

			if (!partnerCertificateChain.fromByteString(createSessionRequest.clientCertificate())) {
				Log(Error, "received client certificate error - delete session");
				createSessionRequestError(requestHeader, secureChannelTransaction, BadSecurityChecksFailed);
				closeAndDeleteSession();
				return;
			}

			// check client certificate
			if (partnerCertificateChain != securitySettings.partnerCertificateChain()) {
				Log(Error, "check client certificate error - delete session");
				createSessionRequestError(requestHeader, secureChannelTransaction, BadSecurityChecksFailed);
				closeAndDeleteSession();
				return;
			}
		}

		createSessionResponse.sessionId().namespaceIndex(1);
		createSessionResponse.sessionId().nodeId(sessionId_);
		createSessionResponse.authenticationToken().namespaceIndex(1);
		createSessionResponse.authenticationToken().nodeId(authenticationToken_);
		createSessionResponse.receivedSessionTimeout(120000);
		createSessionResponse.serverEndpoints(endpointDescriptionArray_);
		createSessionResponse.maxRequestMessageSize(0);

		// added server certificate
		OpcUaByteString certByteString;
		cryptoManager_->applicationCertificate()->certificateChain().toByteString(certByteString);
		createSessionResponse.serverCertificate() = certByteString;

		if (securitySettings.ownSecurityPolicy() != SecurityPolicy::EnumNone) {

			// create server signature
			MemoryBuffer clientCertificate(createSessionRequest.clientCertificate());
			MemoryBuffer clientNonce(createSessionRequest.clientNonce());
			PrivateKey privateKey = *cryptoManager_->applicationCertificate()->privateKey();
			auto statusCode = createSessionResponse.signatureData()->createSignature(
				clientCertificate,
				clientNonce,
				privateKey,
				*secureChannelTransaction->cryptoBase_
			);
			if (statusCode != Success) {
				Log(Error, "create server signature in create session request error")
					.parameter("StatusCode", OpcUaStatusCodeMap::shortString(statusCode));
				createSessionResponse.responseHeader()->serviceResult(BadSecurityChecksFailed);
			}
		}

		// encode create session response
		if (!createSessionResponse.responseHeader()->opcUaBinaryEncode(iosres)) {
			Log(Error, "encode response header error - delete session");
			createSessionRequestError(requestHeader, secureChannelTransaction, BadInternalError);
			closeAndDeleteSession();
			return;
		}
		if (!createSessionResponse.opcUaBinaryEncode(iosres)) {
			Log(Error, "encode create session response error - delete session");
			createSessionRequestError(requestHeader, secureChannelTransaction, BadInternalError);
			closeAndDeleteSession();
			return;
		}

		sessionState_ = SessionState_CreateSessionResponse;

		// send create session response
		auto responseHeader = createSessionResponse.responseHeader();
		responseMessageCallback_(responseHeader, secureChannelTransaction);

		// send session info to server info service
		auto addSessTrx = boost::static_pointer_cast<ServiceTransactionAddSession>(
			transactionManagerSPtr_->getTransaction(OpcUaId_AddSessionRequest_Encoding_DefaultBinary)
		);
		auto req = addSessTrx->request();
		req->sessionId(sessionId_);
		req->sessionName(createSessionRequest.sessionName());
		req->sessionTimeout(120);
		req->startTime(boost::posix_time::microsec_clock::universal_time());
		req->partnerAddress(secureChannel->partner_.address().to_string());
		req->endpointUrl(secureChannel->endpointUrl_);

		messageBus_->messageSend(
			messageBusMember_,
			addSessTrx->memberService(),
			addSessTrx
		);

	}

	void
	Session::createSessionRequestError(
		RequestHeader::SPtr& requestHeader,
		SecureChannelTransaction::SPtr secureChannelTransaction,
		OpcUaStatusCode statusCode
	)
	{
		std::iostream iosres(&secureChannelTransaction->os_);

		// create session response
		CreateSessionResponse createSessionResponse;
		createSessionResponse.responseHeader()->requestHandle(requestHeader->requestHandle());
		createSessionResponse.responseHeader()->serviceResult(statusCode);

		// ancode create session response
		if (!createSessionResponse.responseHeader()->opcUaBinaryEncode(iosres)) {
			Log(Error, "encode response header error - ignore create session response");
			return;
		}
		if (!createSessionResponse.opcUaBinaryEncode(iosres)) {
			Log(Error, "encode create session response error - ignore create session response");
			return;
		}

		// send create session response
		auto responseHeader = createSessionResponse.responseHeader();
		responseMessageCallback_(responseHeader, secureChannelTransaction);
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
		SecureChannel* secureChannel
	)
	{
		auto secureChannelTransaction = secureChannel->secureChannelTransaction_;
		auto& securitySettings = secureChannel->securitySettings();

		OpcUaStatusCode statusCode;

		Log(Debug, "receive activate session request");
		secureChannelTransaction->responseTypeNodeId_ = OpcUaId_ActivateSessionResponse_Encoding_DefaultBinary;

		// FIXME: if authenticationToken in the secureChannelTransaction contains 0 then
		//        the session has a new secure channel


		// decode activate session request
		std::iostream ios(&secureChannelTransaction->is_);
		ActivateSessionRequest activateSessionRequest;
		if (!activateSessionRequest.opcUaBinaryDecode(ios)) {
			Log(Error, "decode create session request error - delete session");
			activateSessionRequestError(requestHeader, secureChannelTransaction, BadInvalidArgument);
			closeAndDeleteSession();
			return;
		}

		// check session state
		if (sessionState_ != SessionState_CreateSessionResponse && sessionState_ != SessionState_Ready) {
			Log(Error, "receive activate session request in invalid state - delete session")
				.parameter("SessionState", sessionState_);
			activateSessionRequestError(requestHeader, secureChannelTransaction, BadIdentityTokenInvalid);
			closeAndDeleteSession();
			return;
		}

		// check client signature
		if (securitySettings.ownSecurityPolicy() != SecurityPolicy::EnumNone) {
			// Create buffer with all server certificates from server certificate chain.
			// We need this buffer to validate the signature in the activate session
			// request.
			OpcUaByteString certByteString;
			cryptoManager_->applicationCertificate()->certificateChain().toByteString(certByteString);
			MemoryBuffer certificate(certByteString);

			// create server nonce
			MemoryBuffer serverNonce(serverNonce_, 32);

			// verify signature
			auto publicKey = securitySettings.partnerCertificateChain().getCertificate()->publicKey();
			statusCode = activateSessionRequest.clientSignature()->verifySignature(
				certificate,				// base to calculate signature
				serverNonce,				// base to calculate signature
				publicKey,					// public client key
				*secureChannelTransaction->cryptoBase_
			);

			if (statusCode != Success) {
				Log(Error, "client signature error - delete session");
				activateSessionRequestError(requestHeader, secureChannelTransaction, BadSecurityChecksFailed);
				closeAndDeleteSession();
				return;
			}
		}

		// check username and password
		statusCode = authentication(activateSessionRequest);
		createServerNonce();

		std::iostream iosres(&secureChannelTransaction->os_);

		// create activate session response
		ActivateSessionResponse activateSessionResponse;
		activateSessionResponse.responseHeader()->requestHandle(requestHeader->requestHandle());
		activateSessionResponse.responseHeader()->serviceResult(statusCode);
		activateSessionResponse.serverNonce((const OpcUaByte*)serverNonce_, 32);

		// encode activate session response
		if (!activateSessionResponse.responseHeader()->opcUaBinaryEncode(iosres)) {
			Log(Error, "encode response header error - delete session");
			activateSessionRequestError(requestHeader, secureChannelTransaction, BadInternalError);
			closeAndDeleteSession();
			return;
		}
		if (!activateSessionResponse.opcUaBinaryEncode(iosres)) {
			Log(Error, "encode activate session response error - delete session");
			activateSessionRequestError(requestHeader, secureChannelTransaction, BadInternalError);
			closeAndDeleteSession();
			return;
		}

		sessionState_ = SessionState_Ready;

		//secureChannelTransaction->authenticationToken_ = authenticationToken_;

		// send activate session response
		auto responseHeader = activateSessionResponse.responseHeader();
		responseMessageCallback_(responseHeader, secureChannelTransaction);

		// send session info to server info service
		auto updSessTrx = boost::static_pointer_cast<ServiceTransactionUpdSession>(
			transactionManagerSPtr_->getTransaction(OpcUaId_UpdSessionRequest_Encoding_DefaultBinary)
		);
		auto req = updSessTrx->request();
		req->sessionId(sessionId_);

		messageBus_->messageSend(
			messageBusMember_,
			updSessTrx->memberService(),
			updSessTrx
		);
	}

	void
	Session::activateSessionRequestError(
		RequestHeader::SPtr& requestHeader,
		SecureChannelTransaction::SPtr secureChannelTransaction,
		OpcUaStatusCode statusCode
	)
	{
		std::iostream iosres(&secureChannelTransaction->os_);

		// create activate session response
		ActivateSessionResponse activateSessionResponse;
		activateSessionResponse.responseHeader()->requestHandle(requestHeader->requestHandle());
		activateSessionResponse.responseHeader()->serviceResult(statusCode);

		// encode activate session response
		if (!activateSessionResponse.responseHeader()->opcUaBinaryEncode(iosres)) {
			Log(Error, "encode response header error - ignore activate session response");
			return;
		}
		if (!activateSessionResponse.opcUaBinaryEncode(iosres)) {
			Log(Error, "encode activate session response error - ignore activate session response");
			return;
		}

		// send activate session response
		auto responseHeader = activateSessionResponse.responseHeader();
		responseMessageCallback_(responseHeader, secureChannelTransaction);
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

		// decode close session request
		std::iostream ios(&secureChannelTransaction->is_);
		CloseSessionRequest closeSessionRequest;
		if (!closeSessionRequest.opcUaBinaryDecode(ios)) {
			Log(Error, "decode close session request error");
		}

		std::iostream iosres(&secureChannelTransaction->os_);

		// create close session response
		CloseSessionResponse closeSessionResponse;
		closeSessionResponse.responseHeader()->requestHandle(requestHeader->requestHandle());
		closeSessionResponse.responseHeader()->serviceResult(Success);

		// encode close session response
		if (!closeSessionResponse.responseHeader()->opcUaBinaryEncode(iosres)) {
			Log(Error, "encode response header error - ignore close session response");
			closeAndDeleteSession();
			return;
		}
		if (!closeSessionResponse.opcUaBinaryEncode(iosres)) {
			Log(Error, "encode close session response error - ignore close session response");
			closeAndDeleteSession();
			return;
		}

		// send close session response
		Log(Debug, "send close session response");
		ResponseHeader::SPtr responseHeader = closeSessionResponse.responseHeader();
		responseMessageCallback_(responseHeader, secureChannelTransaction);
		closeAndDeleteSession();
	}

	void
	Session::closeAndDeleteSession(void)
	{
		// close session
		Log(Debug, "authentication close session");
		authenticationCloseSession();

		// send session info to server info service
		auto delSessTrx = boost::static_pointer_cast<ServiceTransactionDelSession>(
			transactionManagerSPtr_->getTransaction(OpcUaId_DelSessionRequest_Encoding_DefaultBinary)
		);
		auto req = delSessTrx->request();
		req->sessionId(sessionId_);

		messageBus_->messageSend(
			messageBusMember_,
			delSessTrx->memberService(),
			delSessTrx
		);

		// delete session - That must be the last action in the session
		deleteSessionCallback_(authenticationToken_);
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

		// decode cancel request
		std::iostream ios(&secureChannelTransaction->is_);
		CancelRequest cancelRequest;
		if (!cancelRequest.opcUaBinaryDecode(ios)) {
			Log(Error, "decode cancel request error");
		}

		// send response
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

		// create cancel response
		CancelResponse cancelResponse;
		cancelResponse.responseHeader()->requestHandle(requestHeader->requestHandle());
		cancelResponse.responseHeader()->serviceResult(statusCode);

		// encode cancel response
		if (!cancelResponse.responseHeader()->opcUaBinaryEncode(iosres)) {
			Log(Error, "encode response header error - ignore cancel response");
		}
		if (!cancelResponse.opcUaBinaryEncode(iosres)) {
			Log(Error, "encode cancel response error - ignore cancel response");
		}

		// send cancel response
		auto responseHeader = cancelResponse.responseHeader();
		responseMessageCallback_(responseHeader, secureChannelTransaction);
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

			// ignore request - we cannot generate a response
			return;
		}

		// we must check the smart pointer to the transaction manager
		if (transactionManagerSPtr_.get() == nullptr) {
			Log(Error, "transaction manager empty - ignore message request");
			// ignore request - we cannot generate a response
			return;
		}

		// create a new service transaction with the correct type
		auto serviceTransactionSPtr = transactionManagerSPtr_->getTransaction(
			secureChannelTransaction->requestTypeNodeId_
		);
		if (serviceTransactionSPtr.get() == nullptr) {
			Log(Error, "receive invalid message type - ignore message request")
				.parameter("TypeId", secureChannelTransaction->requestTypeNodeId_);
			// ignore request - we cannot generate a response
			return;
		}
		secureChannelTransaction->responseTypeNodeId_ = OpcUaNodeId(serviceTransactionSPtr->nodeTypeResponse().nodeId<uint32_t>());
		serviceTransactionSPtr->sessionId(sessionId_);
		serviceTransactionSPtr->userContext(userContext_);
		Object::SPtr handle = secureChannelTransaction;
		serviceTransactionSPtr->handle(handle);
		// FIXME: serviceTransactionSPtr->channelId(secureChannelTransaction->channelId_);

		// decode service request
		std::iostream ios(&secureChannelTransaction->is_);
		serviceTransactionSPtr->requestHeader(requestHeader);
		if (!serviceTransactionSPtr->opcUaBinaryDecodeRequest(ios)) {
			Log(Error, "decode message request error - ignore message request");
			return;
		}

		serviceTransactionSPtr->requestId_ = secureChannelTransaction->requestId_;
		serviceTransactionSPtr->statusCode(Success);

		Log(Debug, "receive request in session")
			.parameter("TrxId", serviceTransactionSPtr->transactionId())
			.parameter("TypeId", serviceTransactionSPtr->requestName())
			.parameter("RequestId", serviceTransactionSPtr->requestId_);

		// send message request to service component
		messageBus_->messageSend(
			messageBusMember_,							// own message bus member
			serviceTransactionSPtr->memberService(),	// target message bus member
			serviceTransactionSPtr						// service transaction to send
		);
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
	Session::receive(
		const OpcUaStackCore::MessageBusMember::WPtr& handleFrom,
		Message::SPtr& message
	)
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

		// encode message response
		if (!responseHeader->opcUaBinaryEncode(iosres)) {
			Log(Error, "encode response header error - ignore message request");
			return;
		}
		if (!serviceTransactionSPtr->opcUaBinaryEncodeResponse(iosres)) {
			Log(Error, "encode message response error - ignore message request");
			return;
		}

		// send message response
		responseMessageCallback_(responseHeader, secureChannelTransaction);
	}

}
