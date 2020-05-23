/*
   Copyright 2015-2020 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackCore/SecureChannel/RequestHeader.h"
#include "OpcUaStackCore/SecureChannel/ResponseHeader.h"
#include "OpcUaStackCore/ServiceSet/DiscoveryServiceTransaction.h"
#include "OpcUaStackCore/ServiceSet/GetEndpointsRequest.h"
#include "OpcUaStackCore/ServiceSet/GetEndpointsResponse.h"
#include "OpcUaStackCore/Application/ApplicationRegisterServerContext.h"
#include "OpcUaStackCore/Application/ApplicationFindServerContext.h"
#include "OpcUaStackServer/ServiceSet/DiscoveryService.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	DiscoveryService::DiscoveryService(
		const std::string& serviceName,
		IOThread::SPtr& ioThread,
		MessageBus::SPtr& messageBus)
	: ServerServiceBase()
	, cryptoManager_(nullptr)
	, endpointDescriptionArray_()
	{
		// set parameter in server service base
		serviceName_ = serviceName;
		ServerServiceBase::ioThread_ = ioThread.get();
		strand_ = ioThread->createStrand();
		messageBus_ = messageBus;

		// register message bus receiver
		MessageBusMemberConfig messageBusMemberConfig;
		messageBusMemberConfig.strand(strand_);
		messageBusMember_ = messageBus_->registerMember(serviceName_, messageBusMemberConfig);

		// activate receiver
		activateReceiver(
			[this](const OpcUaStackCore::MessageBusMember::WPtr& handleFrom, Message::SPtr& message){
				// nothing to do
			}
		);
	}

	DiscoveryService::~DiscoveryService(void)
	{
		// deactivate receiver
		deactivateReceiver();
		messageBus_->deregisterMember(messageBusMember_);
	}

	void 
	DiscoveryService::endpointDescriptionSet(EndpointDescriptionSet::SPtr& endpointDescriptionSet)
	{
		Log(Debug, "endpointDescriptionSet");

		assert(endpointDescriptionSet.get() != nullptr);

		endpointDescriptionArray_ = boost::make_shared<EndpointDescriptionArray>();
		endpointDescriptionSet->getEndpoints(endpointDescriptionArray_);
	}

	void
	DiscoveryService::cryptoManager(CryptoManager::SPtr& cryptoManager)
	{
		Log(Debug, "applicationCertificate");

		assert(cryptoManager.get() != nullptr);

		cryptoManager_ = cryptoManager;
		auto applicationCertificate = cryptoManager->applicationCertificate();

		if (!applicationCertificate->enable()) {
			return;
		}

		OpcUaByteString certByteString;
		if (!applicationCertificate->certificateChain().toByteString(certByteString)) {
			return;
		}

		for (uint32_t idx = 0; idx < endpointDescriptionArray_->size(); idx++) {
			EndpointDescription::SPtr endpointDescription;
			endpointDescriptionArray_->get(idx, endpointDescription);

			//if (!endpointDescription->needSecurity()) {
			//	continue;
			//}

			endpointDescription->serverCertificate() = certByteString;
		}
	}

	void
	DiscoveryService::getEndpointRequest(
		RequestHeader::SPtr& requestHeader,
		SecureChannelTransaction::SPtr secureChannelTransaction
	)
	{
		assert(requestHeader.get() != nullptr);
		assert(secureChannelTransaction.get() != nullptr);
		assert(endpointDescriptionArray_.get() != nullptr);

		Log(Debug, "receive get endpoint request request")
		    .parameter("AvailableNumberEndpoints", endpointDescriptionArray_->size());

		secureChannelTransaction->responseTypeNodeId_ = OpcUaId_GetEndpointsResponse_Encoding_DefaultBinary;

		std::iostream is(&secureChannelTransaction->is_);
		GetEndpointsRequest getEndpointsRequest;

		getEndpointsRequest.opcUaBinaryDecode(is);

		// FIXME: analyse request data

		std::iostream os(&secureChannelTransaction->os_);

		ResponseHeader responseHeader;
		GetEndpointsResponse getEndpointsResponse;

		responseHeader.requestHandle(requestHeader->requestHandle());
		responseHeader.serviceResult(Success);
		getEndpointsResponse.endpoints(endpointDescriptionArray_);

		responseHeader.opcUaBinaryEncode(os);
		getEndpointsResponse.opcUaBinaryEncode(os);
	}

	void
	DiscoveryService::registerServerRequest(
		RequestHeader::SPtr requestHeader,
		SecureChannelTransaction::SPtr secureChannelTransaction
	)
	{
		Log(Debug, "receive register server request request");
		secureChannelTransaction->responseTypeNodeId_ = OpcUaId_RegisterServerResponse_Encoding_DefaultBinary;

		std::iostream is(&secureChannelTransaction->is_);
		RegisterServerRequest registerServerRequest;

		registerServerRequest.opcUaBinaryDecode(is);

		// FIXME: analyse request data

		std::iostream os(&secureChannelTransaction->os_);

		ResponseHeader responseHeader;
		RegisterServerResponse registerServerResponse;

		responseHeader.requestHandle(requestHeader->requestHandle());

		// check forward callback functions
		ApplicationRegisterServerContext ctx;
		ctx.statusCode_ = BadNotSupported;
		if (forwardGlobalSync()->registerServerService().isCallback()) {

			// forward register server request
			ctx.applicationContext_ = forwardGlobalSync()->registerServerService().applicationContext();
			registerServerRequest.server().copyTo(ctx.server_);
			forwardGlobalSync()->registerServerService().callback()(&ctx);
		}
		responseHeader.serviceResult(ctx.statusCode_);

		responseHeader.opcUaBinaryEncode(os);
		registerServerResponse.opcUaBinaryEncode(os);
	}

	void
	DiscoveryService::findServersRequest(
		RequestHeader::SPtr requestHeader,
		SecureChannelTransaction::SPtr secureChannelTransaction
	)
	{
		Log(Debug, "receive find servers request");
		secureChannelTransaction->responseTypeNodeId_ = OpcUaId_FindServersResponse_Encoding_DefaultBinary;

		std::iostream is(&secureChannelTransaction->is_);
		FindServersRequest findServersRequest;

		findServersRequest.opcUaBinaryDecode(is);

		// FIXME: analyse request data

		std::iostream os(&secureChannelTransaction->os_);

		ResponseHeader responseHeader;
		FindServersResponse findServersResponse;

		responseHeader.requestHandle(requestHeader->requestHandle());

		// check forward callback functions
		ApplicationFindServerContext ctx;
		ctx.statusCode_ = BadNotSupported;
		if (forwardGlobalSync()->findServersService().isCallback()) {

			// forward find server request
			ctx.applicationContext_ = forwardGlobalSync()->findServersService().applicationContext();
			findServersRequest.endpointUrl().copyTo(ctx.endpointUrl_);
			ctx.localeIdArraySPtr_ = findServersRequest.localeIds();
			ctx.serverUriArraySPtr_ = findServersRequest.serverUris();
			forwardGlobalSync()->findServersService().callback()(&ctx);
		}

		responseHeader.serviceResult(ctx.statusCode_);
		if (ctx.statusCode_ == Success) {
			if (ctx.servers_->size() == 0) {
				ctx.statusCode_ = BadNotSupported;
			}
			else {
				findServersResponse.servers(ctx.servers_);
			}
		}

		responseHeader.opcUaBinaryEncode(os);
		findServersResponse.opcUaBinaryEncode(os);
	}

}
