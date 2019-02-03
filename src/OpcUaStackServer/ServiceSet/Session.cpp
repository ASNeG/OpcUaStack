/*
   Copyright 2017-2019 Kai Huebl (kai@huebl-sgh.de)

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
#include "OpcUaStackCore/Application/ApplicationAuthenticationContext.h"
#include "OpcUaStackCore/Application/ApplicationCloseSessionContext.h"
#include "OpcUaStackCore/ServiceSet/AnonymousIdentityToken.h"
#include "OpcUaStackCore/ServiceSet/UserNameIdentityToken.h"
#include "OpcUaStackCore/ServiceSet/IssuedIdentityToken.h"
#include "OpcUaStackCore/ServiceSet/X509IdentityToken.h"

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
	, clientCertificate_()
	{
		Log(Info, "session construct")
			.parameter("SessionId", sessionId_)
			.parameter("AuthenticationToken", authenticationToken_);
		componentName("Session");
	}

	Session::~Session(void)
	{
	}

	void
	Session::createServerNonce(void)
	{
		for (uint32_t idx=0; idx<32; idx++) {
			serverNonce_[idx] = (rand() / 256);
		}
	}

	void
	Session::applicationCertificate(ApplicationCertificate::SPtr& applicationCertificate)
	{
		applicationCertificate_ = applicationCertificate;
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
	Session::endpointDescriptionArray(EndpointDescriptionArray::SPtr& endpointDescriptionArray)
	{
		endpointDescriptionArray_ = endpointDescriptionArray;
	}

	void
	Session::endpointDescription(EndpointDescription::SPtr& endpointDescription)
	{
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
	Session::authenticationAnonymous(ActivateSessionRequest& activateSessionRequest, ExtensibleParameter::SPtr& parameter)
	{
		OpcUaStatusCode statusCode;
		Log(Debug, "Session::authenticationAnonymous");

		AnonymousIdentityToken::SPtr token = parameter->parameter<AnonymousIdentityToken>();

		// check token policy
		UserTokenPolicy::SPtr userTokenPolicy;
		statusCode = checkUserTokenPolicy(token->policyId(), UserIdentityTokenType_Anonymous, userTokenPolicy);
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

		return context.statusCode_;
	}

	OpcUaStatusCode
	Session::authenticationUserName(ActivateSessionRequest& activateSessionRequest, ExtensibleParameter::SPtr& parameter)
	{
		OpcUaStatusCode statusCode;
		Log(Debug, "Session::authenticationUserName");

		UserNameIdentityToken::SPtr token = parameter->parameter<UserNameIdentityToken>();

		// check parameter and password
		if (token->userName().size() == 0) {
			Log(Debug, "user name invalid");
			return BadIdentityTokenInvalid;
		}

		// check token policy
		UserTokenPolicy::SPtr userTokenPolicy;
		statusCode = checkUserTokenPolicy(token->policyId(), UserIdentityTokenType_Username, userTokenPolicy);
		if (statusCode != Success) {
			return statusCode;
		}

		Log(Debug, "authentication user name")
		    .parameter("PolicyId", token->policyId())
			.parameter("UserName", token->userName())
			.parameter("SecurityPolicyUri", userTokenPolicy->securityPolicyUri())
			.parameter("EncyptionAlgorithmus", token->encryptionAlgorithm());

		if (token->encryptionAlgorithm() == "") {
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
		token->password((OpcUaByte**)&encryptedTextBuf, &encryptedTextLen);
		if (encryptedTextLen <= 0) {
			Log(Debug, "password format invalid");
			return BadIdentityTokenRejected;;
		}

		char* plainTextBuf;
		uint32_t plainTextLen;
		MemoryBuffer plainText(encryptedTextLen);
		plainTextBuf = plainText.memBuf();
		plainTextLen = plainText.memLen();

		PrivateKey::SPtr privateKey = applicationCertificate_->privateKey();

		statusCode = cryptoBase->asymmetricDecrypt(
			encryptedTextBuf,
			encryptedTextLen,
			*privateKey.get(),
			plainTextBuf,
			&plainTextLen
		);
		if (statusCode != Success) {
			Log(Debug, "decrypt password error");
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

		token->password((const OpcUaByte*)&plainTextBuf[4], passwordLen);

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
	Session::authenticationX509(ActivateSessionRequest& activateSessionRequest, ExtensibleParameter::SPtr& parameter)
	{
		OpcUaStatusCode statusCode;
		Log(Debug, "Session::authenticationX509");

		X509IdentityToken::SPtr token = parameter->parameter<X509IdentityToken>();

		// check parameter and password
		if (token->certificateData().size() == 0) {
			Log(Debug, "token data invalid");
			return BadIdentityTokenInvalid;
		}

		// check token policy
		UserTokenPolicy::SPtr userTokenPolicy;
		statusCode = checkUserTokenPolicy(token->policyId(), UserIdentityTokenType_Certificate, userTokenPolicy);
		if (statusCode != Success) {
			return statusCode;
		}

		// get signature data
		SignatureData::SPtr userTokenSignature = activateSessionRequest.userTokenSignature();
		if (userTokenSignature.get() == nullptr) {
			Log(Debug, "missing user token signature")
				.parameter("PolicyId", token->policyId());
			return BadIdentityTokenInvalid;
		}

		Log(Debug, "authentication x509")
		    .parameter("PolicyId", token->policyId())
			.parameter("CertificateData", token->certificateData())
			.parameter("SecurityPolicyUri", userTokenPolicy->securityPolicyUri());

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

		// FIXME: certificate must be trusted ...

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

		return context.statusCode_;
	}

	OpcUaStatusCode
	Session::authenticationIssued(ActivateSessionRequest& activateSessionRequest, ExtensibleParameter::SPtr& parameter)
	{
		OpcUaStatusCode statusCode;
		Log(Debug, "Session::authenticationIssued");

		IssuedIdentityToken::SPtr token = parameter->parameter<IssuedIdentityToken>();

		// check parameter and password
		if (token->tokenData().size() == 0) {
			Log(Debug, "token data invalid");
			return BadIdentityTokenInvalid;
		}

		// check token policy
		UserTokenPolicy::SPtr userTokenPolicy;
		statusCode = checkUserTokenPolicy(token->policyId(), UserIdentityTokenType_IssuedToken, userTokenPolicy);
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
		token->tokenData((OpcUaByte**)&encryptedTextBuf, &encryptedTextLen);
		if (encryptedTextLen <= 0) {
			Log(Debug, "token data format invalid");
			return BadIdentityTokenRejected;;
		}

		char* plainTextBuf;
		uint32_t plainTextLen;
		MemoryBuffer plainText(encryptedTextLen);
		plainTextBuf = plainText.memBuf();
		plainTextLen = plainText.memLen();

		PrivateKey::SPtr privateKey = applicationCertificate_->privateKey();

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
		token->tokenData((const OpcUaByte*)&plainTextBuf[4], plainTextLen-36);

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

		return context.statusCode_;
	}

	OpcUaStatusCode
	Session::checkUserTokenPolicy(
		const std::string& policyId,
		UserIdentityTokenType userIdentityTokenType,
		UserTokenPolicy::SPtr& userTokenPolicy
	)
	{
		if (endpointDescription_.get() == nullptr) {
			Log(Debug, "endpoint description not exist");
			return BadIdentityTokenInvalid;
		}

		if (endpointDescription_->userIdentityTokens().get() == nullptr) {
			Log(Debug, "user identity token not exist");
			return BadIdentityTokenInvalid;
		}

		// find related identity token
		bool found = false;
		for (uint32_t idx=0; idx<endpointDescription_->userIdentityTokens()->size(); idx++) {
			if (!endpointDescription_->userIdentityTokens()->get(idx, userTokenPolicy)) {
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
		RequestHeader::SPtr requestHeader,
		SecureChannelTransaction::SPtr secureChannelTransaction
	)
	{
		createServerNonce();

		OpcUaStatusCode statusCode;
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

		std::iostream iosres(&secureChannelTransaction->os_);

		CreateSessionResponse createSessionResponse;
		createSessionResponse.responseHeader()->requestHandle(requestHeader->requestHandle());
		createSessionResponse.responseHeader()->serviceResult(serviceResult);

		if (createSessionRequest.clientCertificate().exist()) {
			clientCertificate_.fromDERBuf(
				createSessionRequest.clientCertificate().memBuf(),
				createSessionRequest.clientCertificate().size()
			);
		}

		createSessionResponse.sessionId().namespaceIndex(1);
		createSessionResponse.sessionId().nodeId(sessionId_);
		createSessionResponse.authenticationToken().namespaceIndex(1);
		createSessionResponse.authenticationToken().nodeId(authenticationToken_);
		createSessionResponse.receivedSessionTimeout(120000);
		createSessionResponse.serverEndpoints(endpointDescriptionArray_);
		createSessionResponse.maxRequestMessageSize(0);

		// added server certificate
		createSessionResponse.serverNonce((const OpcUaByte*)serverNonce_, 32);
		applicationCertificate_->certificate()->toDERBuf(createSessionResponse.serverCertificate());

		if (applicationCertificate_.get() != nullptr && secureChannelTransaction->cryptoBase_.get() != nullptr) {

			// create server signature
			MemoryBuffer clientCertificate(createSessionRequest.clientCertificate());
			MemoryBuffer clientNonce(createSessionRequest.clientNonce());
			PrivateKey privateKey = *applicationCertificate_->privateKey();
			statusCode = createSessionResponse.signatureData()->createSignature(
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
		OpcUaStatusCode statusCode;

		Log(Debug, "receive activate session request");
		secureChannelTransaction->responseTypeNodeId_ = OpcUaId_ActivateSessionResponse_Encoding_DefaultBinary;

		// FIXME: if authenticationToken in the secureChannelTransaction contains 0 then
		//        the session has a new secure channel


		std::iostream ios(&secureChannelTransaction->is_);
		ActivateSessionRequest activateSessionRequest;
		activateSessionRequest.opcUaBinaryDecode(ios);

		if (sessionState_ != SessionState_CreateSessionResponse && sessionState_ != SessionState_Ready) {
			Log(Error, "receive activate session request in invalid state")
				.parameter("SessionState", sessionState_);
			activateSessionRequestError(requestHeader, secureChannelTransaction, BadIdentityTokenInvalid);
			return;
		}

		// check client signature
		if (secureChannelTransaction->cryptoBase_.get() != nullptr) {
			// create certificate
			uint32_t derCertSize = applicationCertificate_->certificate()->getDERBufSize();
			MemoryBuffer certificate(derCertSize);
			applicationCertificate_->certificate()->toDERBuf(
				certificate.memBuf(),
				&derCertSize
			);

			// create server nonce
			MemoryBuffer serverNonce(serverNonce_, 32);

			// verify signature
			PublicKey publicKey = clientCertificate_.publicKey();
			statusCode = activateSessionRequest.clientSignature()->verifySignature(
				certificate,
				serverNonce,
				publicKey,
				*secureChannelTransaction->cryptoBase_
			);

			if (statusCode != Success) {
				Log(Error, "client signature error");
				activateSessionRequestError(requestHeader, secureChannelTransaction, BadSecurityChecksFailed);
				return;
			}
		}

		// check username and password
		statusCode = authentication(activateSessionRequest);

		std::iostream iosres(&secureChannelTransaction->os_);

		createServerNonce();
		ActivateSessionResponse activateSessionResponse;
		activateSessionResponse.responseHeader()->requestHandle(requestHeader->requestHandle());
		activateSessionResponse.responseHeader()->serviceResult(statusCode);
		activateSessionResponse.serverNonce((const OpcUaByte*)serverNonce_, 32);

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

		// close session
		authenticationCloseSession();

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

}
