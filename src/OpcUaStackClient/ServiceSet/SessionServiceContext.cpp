/*
   Copyright 2019 Kai Huebl (kai@huebl-sgh.de)

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
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackCore/ServiceSet/CloseSessionRequest.h"
#include "OpcUaStackCore/ServiceSet/CreateSessionRequest.h"
#include "OpcUaStackCore/ServiceSet/ActivateSessionRequest.h"
#include "OpcUaStackCore/ServiceSet/GetEndpointsRequest.h"
#include "OpcUaStackCore/ServiceSet/CancelRequest.h"
#include "OpcUaStackCore/StandardDataTypes/AnonymousIdentityToken.h"
#include "OpcUaStackCore/Certificate/ValidateCertificate.h"
#include "OpcUaStackClient/ServiceSet/SessionServiceContext.h"

namespace OpcUaStackClient
{

	uint32_t SessionServiceContext::gId_ = 1;

	SessionServiceContext::SessionServiceContext(IOThread* ioThread)
	: id_(gId_++)
	, secureChannelClientConfig_()
	, secureChannelClient_(ioThread)
	, secureChannel_(nullptr)

	, sessionService_(nullptr)
	, sessionMode_(SessionMode::SecureChannelAndSession)
	, sessionConfig_()
	, sessionServiceChangeHandler_()

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
		slotTimerElement_->callback().reset(boost::bind(&SessionService::reconnectTimeout, sessionService_));
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
		createSessionRequest.clientDescription(sessionConfig_->applicationDescription_);
		createSessionRequest.endpointUrl(secureChannelClientConfig_->endpointUrl());
		createSessionRequest.sessionName(sessionConfig_->sessionName_);
		createSessionRequest.clientNonce((OpcUaStackCore::OpcUaByte*)"\000", 1);
		createSessionRequest.requestSessionTimeout(sessionConfig_->sessionTimeout_);
		createSessionRequest.maxResponseMessageSize(sessionConfig_->maxResponseMessageSize_);

		// added client certificate chain and client nonce to create session request
		if (!securitySettings.ownCertificateChain().empty()) {
			for (uint32_t idx=0; idx<32; idx++) {
				clientNonce_[idx] = (rand() / 256);
			}
			createSessionRequest.clientNonce((const OpcUaByte*)clientNonce_, 32);
			securitySettings.ownCertificateChain().toByteString(createSessionRequest.clientCertificate());
		}

		// send create session request
		createSessionRequest.requestHeader()->opcUaBinaryEncode(ios);
		createSessionRequest.opcUaBinaryEncode(ios);

		Log(Debug, "session send CreateSessionRequest")
		    .parameter("SessId", id_)
		    .parameter("RequestId", trx->requestId_)
		    .parameter("SessionName", sessionConfig_->sessionName_);
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

		auto trx = constructSPtr<SecureChannelTransaction>();
		trx->requestTypeNodeId_.nodeId(OpcUaId_ActivateSessionRequest_Encoding_DefaultBinary);
		trx->requestId_ = ++requestId_;
		std::iostream ios(&trx->os_);

		OpcUaString::SPtr localeIdSPtr = constructSPtr<OpcUaString>();
		*localeIdSPtr = "en";

		ActivateSessionRequest activateSessionRequest;
		activateSessionRequest.requestHeader()->requestHandle(++requestHandle_);
		activateSessionRequest.requestHeader()->sessionAuthenticationToken() = authenticationToken_;
		activateSessionRequest.localeIds()->resize(1);
		activateSessionRequest.localeIds()->push_back(localeIdSPtr);

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

		// user identity token
		activateSessionRequest.userIdentityToken()->parameterTypeId().nodeId(OpcUaId_AnonymousIdentityToken_Encoding_DefaultBinary);
		auto anonymousIdentityToken = activateSessionRequest.userIdentityToken()->parameter<AnonymousIdentityToken>();
		anonymousIdentityToken->policyId() = sessionConfig_->policyId();
		activateSessionRequest.requestHeader()->opcUaBinaryEncode(ios);
		activateSessionRequest.opcUaBinaryEncode(ios);

		Log(Debug, "session send ActivateSessionRequest")
		 	.parameter("SessId", id_)
			.parameter("RequestId", trx->requestId_)
		    .parameter("SessionName", sessionConfig_->sessionName_)
		    .parameter("AuthenticationToken", authenticationToken_);
		secureChannelClient_.asyncWriteMessageRequest(secureChannel, trx);
		return Success;
	}

	OpcUaStatusCode
	SessionServiceContext::sendGetEndpointsRequest(
			SecureChannel* secureChannel
	)
	{
		auto trx = constructSPtr<SecureChannelTransaction>();
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
		auto trx = constructSPtr<SecureChannelTransaction>();
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
			.parameter("SessionName", sessionConfig_->sessionName_)
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
		auto trx = constructSPtr<SecureChannelTransaction>();
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
		    .parameter("SessionName", sessionConfig_->sessionName_)
		    .parameter("AuthenticationToken", authenticationToken_);
		secureChannelClient_.asyncWriteMessageRequest(secureChannel_, trx);

		return Success;
	}

	void
	SessionServiceContext::setSessionServiceMode(void)
	{
		secureChannelClientConfig_ = secureChannelClientConfigBackup_;
		sessionServiceMode_ = SessionServiceMode::Normal;

		// we need the discovery url to send the get endpoint request to
		// the opc ua server.
		if (secureChannelClientConfig_->discoveryUrl().empty()) {
			Log(Debug, "set session service mode")
				.parameter("SessId", id_)
				.parameter("SessServiceMode", "Normal")
				.parameter("CacheSize", endpointDescriptionCache_.size());
			return;
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
			if (endpointDescription.get() != nullptr) {
				// we found a endpoint description

				Log(Debug, "set session service mode")
					.parameter("SessId", id_)
					.parameter("SessServiceMode", "UseCache")
					.parameter("CacheSize", endpointDescriptionCache_.size());

				sessionServiceMode_ = SessionServiceMode::UseCache;
				secureChannelClientConfig_ = boost::make_shared<SecureChannelClientConfig>(*secureChannelClientConfigBackup_.get());
				secureChannelClientConfig_->endpointUrl(endpointDescription->endpointUrl());
				secureChannelClientConfig_->applicationUri(endpointDescription->server().applicationUri());
				secureChannelClientConfig_->securityMode(endpointDescription->securityMode().enumeration());
				secureChannelClientConfig_->securityPolicy(SecurityPolicy::str2Enum(endpointDescription->securityPolicyUri().toStdString()));
				return;
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

			return endpointDescription;
		}

		return nullptr;
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

}
