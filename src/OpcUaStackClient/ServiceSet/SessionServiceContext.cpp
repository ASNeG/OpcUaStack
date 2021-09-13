/*
   Copyright 2019-2021 Kai Huebl (kai@huebl-sgh.de)

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

#include <boost/make_shared.hpp>
#include "OpcUaStackCore/Base/Utility.h"
#include "OpcUaStackCore/BuildInTypes/ByteOrder.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackCore/ServiceSet/CloseSessionRequest.h"
#include "OpcUaStackCore/ServiceSet/CreateSessionRequest.h"
#include "OpcUaStackCore/ServiceSet/GetEndpointsRequest.h"
#include "OpcUaStackCore/ServiceSet/CancelRequest.h"
#include "OpcUaStackCore/StandardDataTypes/AnonymousIdentityToken.h"
#include "OpcUaStackCore/StandardDataTypes/UserNameIdentityToken.h"
#include "OpcUaStackCore/StandardDataTypes/X509IdentityToken.h"
#include "OpcUaStackCore/StandardDataTypes/IssuedIdentityToken.h"
#include "OpcUaStackCore/Certificate/ValidateCertificate.h"
#include "OpcUaStackClient/ServiceSet/SessionServiceContext.h"

using namespace OpcUaStackCore;

namespace OpcUaStackClient
{

	uint32_t SessionServiceContext::gId_ = 1;

	SessionServiceContext::SessionServiceContext(
		IOThread* ioThread,
		MessageBus::SPtr& messageBus,
		boost::shared_ptr<boost::asio::io_service::strand>& strand
	)
	: id_(gId_++)
	, secureChannelClientConfig_()
	, secureChannelClient_(ioThread, strand)
	, secureChannel_(nullptr)

	, sessionService_(nullptr)
	, sessionMode_(SessionMode::SecureChannelAndSession)
	, sessionConfig_()
	, sessionServiceChangeHandler_()

	, messageBus_(messageBus)
	, ioThread_(ioThread)
	, slotTimerElement_()

	, sessionTimeout_(0)
	, maxResponseMessageSize_(0)
	, authenticationToken_()
	, serverNonce_()
	, requestId_(0)
	, requestHandle_(0)
	, sessionServiceMode_(SessionServiceMode::Normal)
	, endpointDescriptionCache_(EndpointDescriptionCache::instance())
	, secureChannelClientConfigBackup_()
	{
	}

	SessionServiceContext::~SessionServiceContext(void)
	{
	}

	bool
	SessionServiceContext::startReconnectTimer(void)
	{
		if (sessionConfig_->reconnectTimeout() == 0) {
			return false;
		}

		Log(Debug, "start reconnect timer")
			.parameter("SessId", id_)
			.parameter("Timeout", sessionConfig_->reconnectTimeout());

		slotTimerElement_->expireFromNow(sessionConfig_->reconnectTimeout());
		slotTimerElement_->timeoutCallback(
			strand_,
			[this](void) {
				sessionService_->reconnectTimeout();
		    }
	    );
		ioThread_->slotTimer()->start(slotTimerElement_);

		return true;
	}

	void
	SessionServiceContext::stopReconnectTimer(void)
	{
		if (slotTimerElement_->isRunning()) {
			Log(Debug, "stop reconnect timer")
				.parameter("SessId", id_);

			ioThread_->slotTimer()->stop(slotTimerElement_);
		}
	}

	OpcUaStatusCode
	SessionServiceContext::sendCreateSessionRequest(SecureChannel* secureChannel)
	{
		auto& securitySettings = secureChannel->securitySettings_;

		// create secure channel transaction
		auto trx = boost::make_shared<SecureChannelTransaction>();
		trx->requestTypeNodeId_.nodeId(OpcUaId_CreateSessionRequest_Encoding_DefaultBinary);
		trx->requestId_ = ++requestId_;
		std::iostream ios(&trx->os_);

		// create session request
		CreateSessionRequest createSessionRequest;
		createSessionRequest.requestHeader()->requestHandle(++requestHandle_);
		createSessionRequest.clientDescription(sessionConfig_->applicationDescription());
		createSessionRequest.endpointUrl(secureChannelClientConfig_->endpointUrl());
		createSessionRequest.sessionName(sessionConfig_->sessionName());
		createSessionRequest.requestSessionTimeout(sessionConfig_->sessionTimeout());
		createSessionRequest.maxResponseMessageSize(sessionConfig_->maxResponseMessageSize());

		// added client nonce to create session request
		for (uint32_t idx=0; idx<32; idx++) {
			clientNonce_[idx] = (rand() / 256);
		}
		createSessionRequest.clientNonce((const OpcUaByte*)clientNonce_, 32);

		// added client certificate chain to create session request
		if (securitySettings.ownSecurityPolicy() != SecurityPolicy::EnumNone) {
			securitySettings.ownCertificateChain().toByteString(createSessionRequest.clientCertificate());
		}

		// send create session request
		createSessionRequest.requestHeader()->opcUaBinaryEncode(ios);
		createSessionRequest.opcUaBinaryEncode(ios);

		Log(Debug, "session send CreateSessionRequest")
		    .parameter("SessId", id_)
		    .parameter("RequestId", trx->requestId_)
		    .parameter("SessionName", sessionConfig_->sessionName());

		secureChannelClient_.asyncWriteMessageRequest(
			secureChannel_,
			trx
		);

		return Success;
	}

	OpcUaStatusCode
	SessionServiceContext::sendActivateSessionRequest(SecureChannel* secureChannel)
	{
		auto& securitySettings = secureChannel->securitySettings_;

		auto trx = boost::make_shared<SecureChannelTransaction>();
		trx->requestTypeNodeId_.nodeId(OpcUaId_ActivateSessionRequest_Encoding_DefaultBinary);
		trx->requestId_ = ++requestId_;
		std::iostream ios(&trx->os_);

		OpcUaString::SPtr localeIdSPtr = boost::make_shared<OpcUaString>();
		*localeIdSPtr = "en";

		ActivateSessionRequest activateSessionRequest;
		activateSessionRequest.requestHeader()->requestHandle(++requestHandle_);
		activateSessionRequest.requestHeader()->sessionAuthenticationToken() = authenticationToken_;
		activateSessionRequest.localeIds()->resize(1);
		activateSessionRequest.localeIds()->push_back(localeIdSPtr);

		// create user identity token
		auto statusCode = authentication(activateSessionRequest);
		if (statusCode != Success) {
			Log(Error, "create user identity token error")
				.parameter("SessId", id_);
			return statusCode;
		}

		// create client signature
		auto certificate = securitySettings.ownCertificateChain().getCertificate();
		auto partnerCertificate = securitySettings.partnerCertificateChain().getCertificate();
		if (certificate.get() != nullptr) {
			uint32_t derCertSize = partnerCertificate->getDERBufSize();
			MemoryBuffer serverCertificate(derCertSize);
			partnerCertificate->toDERBuf(
				serverCertificate.memBuf(),
				&derCertSize
			);
			PrivateKey::SPtr privateKey =  secureChannelClientConfig_->cryptoManager()->applicationCertificate()->privateKey();

			MemoryBuffer serverNonce((const char*)serverNonce_.memBuf(), (uint32_t)serverNonce_.size());

			OpcUaStatusCode statusCode = activateSessionRequest.clientSignature()->createSignature(
				serverCertificate,
				serverNonce,
				*privateKey,
				*securitySettings.cryptoBase()
			);
			if (statusCode != Success) {
				Log(Error, "create client signature error")
					.parameter("SessId", id_);
				return statusCode;
			}
		}

		// encode activate session request
		activateSessionRequest.requestHeader()->opcUaBinaryEncode(ios);
		activateSessionRequest.opcUaBinaryEncode(ios);

		Log(Debug, "session send ActivateSessionRequest")
		 	.parameter("SessId", id_)
			.parameter("RequestId", trx->requestId_)
		    .parameter("SessionName", sessionConfig_->sessionName())
		    .parameter("AuthenticationToken", authenticationToken_);
		secureChannelClient_.asyncWriteMessageRequest(secureChannel, trx);
		return Success;
	}

	OpcUaStatusCode
	SessionServiceContext::sendGetEndpointsRequest(
			SecureChannel* secureChannel
	)
	{
		auto trx = boost::make_shared<SecureChannelTransaction>();
		trx->requestTypeNodeId_.nodeId(OpcUaId_GetEndpointsRequest_Encoding_DefaultBinary);
		trx->requestId_ = ++requestId_;
		std::iostream ios(&trx->os_);

		GetEndpointsRequest getEndpointsRequest;
		getEndpointsRequest.requestHeader()->requestHandle(++requestHandle_);

		Log(Debug, "session send GetEndpointsRequest")
		 	.parameter("SessId", id_)
			.parameter("RequestId", trx->requestId_);
		secureChannelClient_.asyncWriteMessageRequest(secureChannel, trx);
		return Success;
	}

	OpcUaStatusCode
	SessionServiceContext::sendCloseSessionRequest(
		SecureChannel* secureChannel,
		bool deleteSubscriptions
	)
	{
		auto trx = boost::make_shared<SecureChannelTransaction>();
		trx->requestTypeNodeId_.nodeId(OpcUaId_CloseSessionRequest_Encoding_DefaultBinary);
		trx->requestId_ = ++requestId_;
		std::iostream ios(&trx->os_);

		// create close session request
		CloseSessionRequest closeSessionRequest;
		closeSessionRequest.requestHeader()->requestHandle(++requestHandle_);
		closeSessionRequest.requestHeader()->sessionAuthenticationToken() = authenticationToken_;
		closeSessionRequest.deleteSubscriptions(deleteSubscriptions);

		closeSessionRequest.requestHeader()->opcUaBinaryEncode(ios);
		closeSessionRequest.opcUaBinaryEncode(ios);

		Log(Debug, "session send CloseSessionRequest")
			.parameter("SessId", id_)
			.parameter("RequestId", trx->requestId_)
			.parameter("SessionName", sessionConfig_->sessionName())
			.parameter("AuthenticationToken", authenticationToken_);
		secureChannelClient_.asyncWriteMessageRequest(secureChannel_, trx);
		return Success;
	}

	OpcUaStatusCode
	SessionServiceContext::sendCancelRequest(
		SecureChannel* secureChannel,
		uint32_t requestHandle
	)
	{
		auto trx = boost::make_shared<SecureChannelTransaction>();
		trx->requestTypeNodeId_.nodeId(OpcUaId_CloseSessionRequest_Encoding_DefaultBinary);
		trx->requestId_ = ++requestId_;
		std::iostream ios(&trx->os_);

		CancelRequest cancelRequest;
		cancelRequest.requestHeader()->requestHandle(++requestHandle_);
		cancelRequest.requestHeader()->sessionAuthenticationToken() = authenticationToken_;
		cancelRequest.requestHandle(requestHandle);

		Log(Debug, "session send CancelRequest")
			.parameter("SessId", id_)
		    .parameter("RequestId", trx->requestId_)
		    .parameter("SessionName", sessionConfig_->sessionName())
		    .parameter("AuthenticationToken", authenticationToken_);
		secureChannelClient_.asyncWriteMessageRequest(secureChannel_, trx);

		return Success;
	}

	bool
	SessionServiceContext::setSessionServiceMode(void)
	{
		secureChannelClientConfig_ = secureChannelClientConfigBackup_;
		sessionServiceMode_ = SessionServiceMode::Normal;

		// we need the discovery url to send the get endpoint request to
		// the opc ua server. In the other case, a connection can be opened
		// directly to the endpoint url.
		if (secureChannelClientConfig_->discoveryUrl().empty()) {
			Log(Debug, "set session service mode")
				.parameter("SessId", id_)
				.parameter("SessServiceMode", "Normal")
				.parameter("CacheSize", endpointDescriptionCache_.size());
			return true;
		}

		// Now it is checked if we can use a cache entry
		auto endpointDescriptions = endpointDescriptionCache_.getEndpointDescription(
			secureChannelClientConfig_->discoveryUrl()
		);
		if (endpointDescriptions.get() != nullptr) {
			// we found an endpoint description array in the endpoint description cache

			auto endpointDescription = selectEndpointDescriptionFromCache(
				endpointDescriptions
			);
			if (endpointDescription.get() == nullptr) {
				// An endpoint description was not found.
				return false;
			}
			else {
				// we found a endpoint description

				Log(Debug, "set session service mode")
					.parameter("SessId", id_)
					.parameter("SessServiceMode", "UseCache")
					.parameter("CacheSize", endpointDescriptionCache_.size())
					.parameter("Certs", endpointDescription->serverCertificate().size());

				sessionServiceMode_ = SessionServiceMode::UseCache;
				secureChannelClientConfig_ = boost::make_shared<SecureChannelClientConfig>(*secureChannelClientConfigBackup_.get());
				secureChannelClientConfig_->endpointUrl(endpointDescription->endpointUrl());
				secureChannelClientConfig_->applicationUri(endpointDescription->server().applicationUri());
				secureChannelClientConfig_->securityMode(endpointDescription->securityMode().enumeration());
				secureChannelClientConfig_->securityPolicy(SecurityPolicy::str2Enum(endpointDescription->securityPolicyUri().toStdString()));

				// get partner certificate form endpoint description if exists
				if (endpointDescription->serverCertificate().size() > 0) {
					CertificateChain certificateChain;
					if (!certificateChain.fromByteString(endpointDescription->serverCertificate())) {
						Log(Debug, "server certificate in endpoint description error");
					}
					else {
						secureChannelClientConfig_->certificateChain(certificateChain);
					}
				}

				return true;
			}
		}

		//
		// Before establishing a communication connection, the endpoints are queried by the
		// server with the Get Endpoint Request.
		//
		// - The Get Endpoint Request is sent without encryption.
		// - The target for the Get Endpoint Request is the Discovery Url.
		//
		Log(Debug, "set session service mode")
			.parameter("SessId", id_)
			.parameter("SessServiceMode", "GetEndpoint")
			.parameter("CacheSize", endpointDescriptionCache_.size());

		sessionServiceMode_ = SessionServiceMode::GetEndpoint;
		secureChannelClientConfig_ = boost::make_shared<SecureChannelClientConfig>(*secureChannelClientConfigBackup_.get());
		secureChannelClientConfig_->endpointUrl(secureChannelClientConfig_->discoveryUrl());
		secureChannelClientConfig_->securityMode(MessageSecurityMode::EnumNone);
		secureChannelClientConfig_->securityPolicy(SecurityPolicy::EnumNone);

		return true;
	}

	SessionServiceMode
	SessionServiceContext::sessionServiceMode(void)
	{
		return sessionServiceMode_;
	}

	EndpointDescription::SPtr
	SessionServiceContext::selectEndpointDescriptionFromCache(
		EndpointDescriptionArray::SPtr& endpointDescriptions
	)
	{
		for (auto idx = 0; idx < endpointDescriptions->size(); idx++) {
			EndpointDescription::SPtr endpointDescription;
			endpointDescriptions->get(idx, endpointDescription);

			// check security mode
			if (secureChannelClientConfigBackup_->securityMode() != endpointDescription->securityMode().enumeration()) {
				continue;
			}

			// check security policy
			if (secureChannelClientConfigBackup_->securityPolicy() != SecurityPolicy::str2Enum(endpointDescription->securityPolicyUri())) {
				continue;
			}

			// check user identity token
			if (!selectUserIdentityTokenFromCache(endpointDescription)) {
				continue;
			}

			MessageSecurityMode messageSecurityMode(secureChannelClientConfigBackup_->securityMode());
			SecurityPolicy securityPolicy(secureChannelClientConfigBackup_->securityPolicy());

			Log(Debug, "use cache entry")
			    .parameter("EndpointUrl", endpointDescription->endpointUrl())
				.parameter("SecurityMode", messageSecurityMode.enum2Str())
				.parameter("SecurityPolicy", securityPolicy.enum2Str())
				.parameter("PolicyId", sessionConfig_->userAuthentication()->policyId());
			return endpointDescription;
		}

		return nullptr;
	}

	bool
	SessionServiceContext::selectUserIdentityTokenFromCache(
		EndpointDescription::SPtr& endpointDescription
	)
	{
		for (uint32_t idx = 0; idx < endpointDescription->userIdentityTokens().size(); idx++) {
			UserTokenPolicy::SPtr userTokenPolicy;
			endpointDescription->userIdentityTokens().get(idx, userTokenPolicy);

			switch (sessionConfig_->userAuthentication()->userAuthenticationType())
			{
				case UserAuthenticationType::Anonymous:
				{
					auto userToken = boost::static_pointer_cast<AnonymousAuthentication>(sessionConfig_->userAuthentication());
					if (userTokenPolicy->tokenType() == UserTokenType::EnumAnonymous) {
						userToken->policyId() = userTokenPolicy->policyId().toStdString();
						return true;
					}
					break;
				}
				case UserAuthenticationType::UserName:
				{
					if (userTokenPolicy->tokenType() == UserTokenType::EnumUserName) {
						auto userToken = boost::static_pointer_cast<UserNameAuthentication>(sessionConfig_->userAuthentication());
						if (userTokenPolicy->securityPolicyUri() == userToken->securityPolicyUri()) {
							userToken->policyId() = userTokenPolicy->policyId().toStdString();
							return true;
						}
					}
					break;
				}
				case UserAuthenticationType::X509:
				{
					if (userTokenPolicy->tokenType() == UserTokenType::EnumCertificate) {
						auto userToken = boost::static_pointer_cast<X509Authentication>(sessionConfig_->userAuthentication());
						if (userTokenPolicy->securityPolicyUri() == userToken->securityPolicyUri()) {
							userToken->policyId() = userTokenPolicy->policyId().toStdString();
							return true;
						}
					}
					break;
				}
				case UserAuthenticationType::Issued:
				{
					if (userTokenPolicy->tokenType() == UserTokenType::EnumIssuedToken) {
						auto userToken = boost::static_pointer_cast<IssuedAuthentication>(sessionConfig_->userAuthentication());
						if (userTokenPolicy->securityPolicyUri() == userToken->securityPolicyUri()) {
							userToken->policyId() = userTokenPolicy->policyId().toStdString();
							return true;
						}
					}
					break;
				}
			}
		}

		return false;
	}

	bool
	SessionServiceContext::checkEndpoint(EndpointDescription::SPtr& endpoint)
	{
		// compare application uri
		if (endpoint->server().applicationUri() != secureChannelClientConfig_->applicationUri()) {
			return false;
		}

		// compare security mode
		if (endpoint->securityMode().enumeration() != secureChannelClientConfig_->securityMode()) {
			return false;
		}

		// compare security policy uri
		auto securityPolicy = secureChannelClientConfig_->cryptoManager()->securityPolicy(endpoint->securityPolicyUri());
		if (securityPolicy != secureChannelClientConfig_->securityPolicy()) {
			return false;
		}

		return true;
	}

	OpcUaStatusCode
	SessionServiceContext::authentication(
		ActivateSessionRequest& activateSessionRequest)
	{
		auto securityPolicyUri = SecurityPolicy::enum2Str(secureChannelClientConfig_->securityPolicy());

		auto userAuthentication = sessionConfig_->userAuthentication();
		if (userAuthentication.get() == nullptr) {
			return authenticationAnonymous(
				activateSessionRequest,
				securityPolicyUri,
				"Anonymous"
			);
		}

		switch (userAuthentication->userAuthenticationType())
		{
			case UserAuthenticationType::Anonymous:
			{
				return authenticationAnonymous(
					activateSessionRequest,
					securityPolicyUri,
					userAuthentication->policyId()
				);
				break;
			}
			case UserAuthenticationType::UserName:
			{
				auto userNameAuthentication = boost::static_pointer_cast<UserNameAuthentication>(userAuthentication);
				return authenticationUserName(
					activateSessionRequest,
					userNameAuthentication->securityPolicyUri(),
					userAuthentication->policyId(),
					userNameAuthentication->userName(),
					userNameAuthentication->password(),
					userNameAuthentication->encryptionAlgorithm()
				);
				break;
			}
			case UserAuthenticationType::X509:
			{
				auto x509Authentication = boost::static_pointer_cast<X509Authentication>(userAuthentication);
				return authenticationX509(
					activateSessionRequest,
					x509Authentication->securityPolicyUri(),
					userAuthentication->policyId(),
					*x509Authentication->certificate().get(),
					*x509Authentication->privateKey().get()
				);
				break;
			}
			case UserAuthenticationType::Issued:
			{
				auto issuedAuthentication = boost::static_pointer_cast<IssuedAuthentication>(userAuthentication);
				return authenticationIssued(
					activateSessionRequest,
					issuedAuthentication->securityPolicyUri(),
					userAuthentication->policyId(),
					issuedAuthentication->tokenData(),
					issuedAuthentication->encryptionAlgorithm()
				);
				break;
			}
		}

		return Success;
	}

	OpcUaStatusCode
	SessionServiceContext::authenticationAnonymous(
		ActivateSessionRequest& activateSessionRequest,
		const std::string& securityPolicyUri,
		const std::string& policyId
	)
	{
		Log(Debug, "authentication anonymous")
			.parameter("SecurityPolicyUri", securityPolicyUri)
		    .parameter("PolicyId", policyId);

		// create anonymous identity token
		activateSessionRequest.userIdentityToken()->parameterTypeId().nodeId(OpcUaId_AnonymousIdentityToken_Encoding_DefaultBinary);
		auto userIdentityToken = activateSessionRequest.userIdentityToken()->parameter<AnonymousIdentityToken>();
		userIdentityToken->policyId() = OpcUaString(policyId);

		return Success;
	}

	OpcUaStatusCode
	SessionServiceContext::authenticationUserName(
		ActivateSessionRequest& activateSessionRequest,
		const std::string& securityPolicyUri,
		const std::string& policyId,
		const std::string& userName,
		const std::string& password,
		const std::string& encryptionAlgorithm
	)
	{
		Log(Debug, "authentication user name")
			.parameter("SecurityPolicyUri", securityPolicyUri)
		    .parameter("PolicyId", policyId)
			.parameter("UserName", userName)
			.parameter("EncyptionAlgorithmus", encryptionAlgorithm);

		// create user name identity token
		activateSessionRequest.userIdentityToken()->parameterTypeId().nodeId(OpcUaId_UserNameIdentityToken_Encoding_DefaultBinary);
		auto userIdentityToken = activateSessionRequest.userIdentityToken()->parameter<UserNameIdentityToken>();
		userIdentityToken->policyId() = OpcUaString(policyId);
		userIdentityToken->userName() = OpcUaString(userName);
		userIdentityToken->password() = OpcUaByteString(password);
		userIdentityToken->encryptionAlgorithm() = OpcUaString(encryptionAlgorithm);

		if (userIdentityToken->encryptionAlgorithm() == OpcUaString("")) {
			// we use a plain password
			return Success;
		}

		// get cryption base and check cryption alg
		auto cryptoBase = secureChannelClientConfig_->cryptoManager()->get(securityPolicyUri);
		if (cryptoBase.get() == nullptr) {
			Log(Debug, "crypto manager not found")
				.parameter("SecurityPolicyUri", securityPolicyUri);
			return BadIdentityTokenRejected;
		}
		auto securityPolicy = secureChannelClientConfig_->cryptoManager()->securityPolicy(securityPolicyUri);
		if (securityPolicy == SecurityPolicy::EnumNone) {
			// we use a plain password

			userIdentityToken->encryptionAlgorithm() = "";
			return Success;
		}

		uint32_t encryptionAlg = EnryptionAlgs::uriToEncryptionAlg(encryptionAlgorithm);
		if (encryptionAlg == 0) {
			Log(Debug, "encryption alg invalid")
				.parameter("EncryptionAlgorithm", encryptionAlgorithm);
			return BadIdentityTokenRejected;;
		}

		// get public key from communication partner
		auto& securitySettings = secureChannel_->securitySettings_;
		if (securitySettings.partnerCertificateChain().empty()) {
			Log(Debug, "partner certificate empty");
			return BadIdentityTokenRejected;
		}
		auto publicKey = securitySettings.partnerCertificateChain().getCertificate()->publicKey();

		// create plain password buffer
		MemoryBuffer plainText(password.size() + 36);
		ByteOrder<uint32_t>::opcUaBinaryEncodeNumber(plainText.memBuf(), plainText.memLen()-sizeof(uint32_t));
		memcpy(plainText.memBuf() + 4, password.c_str(), password.length());
		memcpy(plainText.memBuf() + 4 + password.length(), securitySettings.partnerNonce().memBuf(), 32);

		// get asymmetric key length
		uint32_t asymmetricKeyLen = 0;
		cryptoBase->asymmetricKeyLen(publicKey, &asymmetricKeyLen);
		asymmetricKeyLen /= 8;

		// get plain and encrypted block lengths
		uint32_t plainTextBlockSize = 0;
		uint32_t cryptTextBlockSize = 0;
		cryptoBase->getAsymmetricEncryptionBlockSize(publicKey, &plainTextBlockSize, &cryptTextBlockSize);

		// calculate encrypted text length
		uint32_t plainTextLen = plainText.memLen();
		uint32_t rest = plainText.memLen() % plainTextBlockSize;
		if (rest > 0) {
			plainTextLen += (plainTextBlockSize - rest);
		}
		uint32_t encryptedTextLen = plainTextLen / plainTextBlockSize * cryptTextBlockSize;

		// encrypt password
		MemoryBuffer encryptedText(encryptedTextLen);
		cryptoBase->isLogging(true);
		auto statusCode = cryptoBase->asymmetricEncrypt(
			plainText.memBuf(),
			plainText.memLen(),
			publicKey,
			encryptedText.memBuf(),
			&encryptedTextLen
		);
		if (statusCode != Success) {
			Log(Debug, "encrypt password error")
				.parameter("StatusCode", OpcUaStatusCodeMap::shortString(statusCode));
			return BadIdentityTokenRejected;
		}

		// set password
		userIdentityToken->password().value(encryptedText.memBuf(), encryptedText.memLen());

		return Success;
	}

	OpcUaStatusCode
	SessionServiceContext::authenticationX509(
		ActivateSessionRequest& activateSessionRequest,
		const std::string& securityPolicyUri,
		const std::string& policyId,
		Certificate& certificate,
		PrivateKey& privateKey
	)
	{
		Log(Debug, "authentication X509")
		    .parameter("SecurityPolicyUri", securityPolicyUri)
		    .parameter("PolicyId", policyId);

		// get cryption base and check cryption alg
		auto cryptoBase = secureChannelClientConfig_->cryptoManager()->get(securityPolicyUri);
		if (cryptoBase.get() == nullptr) {
			Log(Debug, "crypto manager not found")
				.parameter("SecurityPolicyUri", securityPolicyUri);
			return BadIdentityTokenRejected;
		}

		// added certificate to x509 identity token
		OpcUaByteString certificateText;
		if (!certificate.toDERBuf(certificateText)) {
			Log(Debug, "create certificate data error" );
			return BadIdentityTokenRejected;
		}

		// create x509 identity token
		activateSessionRequest.userIdentityToken()->parameterTypeId().nodeId(OpcUaId_X509IdentityToken_Encoding_DefaultBinary);
		auto x509IdentityToken = activateSessionRequest.userIdentityToken()->parameter<X509IdentityToken>();
		x509IdentityToken->policyId() = OpcUaString(policyId);
		x509IdentityToken->certificateData() = certificateText;

		// create signature
		MemoryBuffer certificateBuf(certificateText);
		auto signatureData = activateSessionRequest.userTokenSignature();
		auto statusCode = signatureData->createSignature(
			certificateBuf,
			privateKey,
			*cryptoBase
		);
		if (statusCode != Success) {
			Log(Debug, "create signature error")
				.parameter("SecurityPolicyUri", securityPolicyUri)
				.parameter("StatusCode", OpcUaStatusCodeMap::shortString(statusCode));
			return BadIdentityTokenRejected;
		}

		return Success;
	}

	OpcUaStatusCode
	SessionServiceContext::authenticationIssued(
		ActivateSessionRequest& activateSessionRequest,
		const std::string& securityPolicyUri,
		const std::string& policyId,
		const std::string& tokenData,
		const std::string& encryptionAlgorithm
	)
	{
		Log(Debug, "authentication issued")
		    .parameter("SecurityPolicyUri", securityPolicyUri)
		    .parameter("PolicyId", policyId)
			.parameter("EncyptionAlgorithmus", encryptionAlgorithm);

		// create issued identity token
		activateSessionRequest.userIdentityToken()->parameterTypeId().nodeId(OpcUaId_IssuedIdentityToken_Encoding_DefaultBinary);
		auto issuedIdentityToken = activateSessionRequest.userIdentityToken()->parameter<IssuedIdentityToken>();
		issuedIdentityToken->policyId() = OpcUaString(policyId);
		issuedIdentityToken->tokenData() = OpcUaString(tokenData);
		issuedIdentityToken->encryptionAlgorithm() = OpcUaString(encryptionAlgorithm);

		if (issuedIdentityToken->encryptionAlgorithm() == OpcUaString("")) {
			// we use a plain password
			return Success;
		}

		// get cryption base and check cryption alg
		auto cryptoBase = secureChannelClientConfig_->cryptoManager()->get(securityPolicyUri);
		if (cryptoBase.get() == nullptr) {
			Log(Debug, "crypto manager not found")
				.parameter("SecurityPolicyUri", securityPolicyUri);
			return BadIdentityTokenRejected;
		}
		auto securityPolicy = secureChannelClientConfig_->cryptoManager()->securityPolicy(securityPolicyUri);
		if (securityPolicy == SecurityPolicy::EnumNone) {
			// we use plain token data
			return Success;
		}

		uint32_t encryptionAlg = EnryptionAlgs::uriToEncryptionAlg(encryptionAlgorithm);
		if (encryptionAlg == 0) {
			Log(Debug, "encryption alg invalid")
				.parameter("EncryptionAlgorithm", encryptionAlgorithm);
			return BadIdentityTokenRejected;;
		}

		// get public key from communication partner
		auto& securitySettings = secureChannel_->securitySettings_;
		if (securitySettings.partnerCertificateChain().empty()) {
			Log(Debug, "partner certificate empty");
			return BadIdentityTokenRejected;
		}
		auto publicKey = securitySettings.partnerCertificateChain().getCertificate()->publicKey();

		// create plain password buffer
		MemoryBuffer plainText(tokenData.size() + 36);
		ByteOrder<uint32_t>::opcUaBinaryEncodeNumber(plainText.memBuf(), plainText.memLen()-sizeof(uint32_t));
		memcpy(plainText.memBuf() + 4, tokenData.c_str(), tokenData.length());
		memcpy(plainText.memBuf() + 4 + tokenData.length(), securitySettings.partnerNonce().memBuf(), 32);

		// get asymmetric key length
		uint32_t asymmetricKeyLen = 0;
		cryptoBase->asymmetricKeyLen(publicKey, &asymmetricKeyLen);
		asymmetricKeyLen /= 8;

		// get plain and encrypted block lengths
		uint32_t plainTextBlockSize = 0;
		uint32_t cryptTextBlockSize = 0;
		cryptoBase->getAsymmetricEncryptionBlockSize(publicKey, &plainTextBlockSize, &cryptTextBlockSize);

		// calculate encrypted text length
		uint32_t plainTextLen = plainText.memLen();
		uint32_t rest = plainText.memLen() % plainTextBlockSize;
		if (rest > 0) {
			plainTextLen += (plainTextBlockSize - rest);
		}
		uint32_t encryptedTextLen = plainTextLen / plainTextBlockSize * cryptTextBlockSize;

		// encrypt password
		MemoryBuffer encryptedText(encryptedTextLen);
		auto statusCode = cryptoBase->asymmetricEncrypt(
			plainText.memBuf(),
			plainText.memLen(),
			publicKey,
			encryptedText.memBuf(),
			&encryptedTextLen
		);
		if (statusCode != Success) {
			Log(Debug, "encrypt password error")
				.parameter("StatusCode", OpcUaStatusCodeMap::shortString(statusCode));
			return BadIdentityTokenRejected;
		}

		// set password
		issuedIdentityToken->tokenData().value(encryptedText.memBuf(), encryptedText.memLen());

		return Success;
	}

	void
	SessionServiceContext::sendResponseToService(
		MessageBusMember::WPtr& target,
		const Message::SPtr& message
	)
	{
		messageBus_->messageSend(messageBusMember_, target, message);
	}

}
