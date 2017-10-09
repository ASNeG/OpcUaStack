/*
   Copyright 2015-2017 Kai Huebl (kai@huebl-sgh.de)

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


namespace OpcUaStackServer
{

	DiscoveryService::DiscoveryService(void)
	: discoveryIf_(nullptr)
	{
	}

	DiscoveryService::~DiscoveryService(void)
	{
	}

	void 
	DiscoveryService::discoveryIf(DiscoveryIf* discoveryIf)
	{
		discoveryIf_ = discoveryIf;
	}

	void 
	DiscoveryService::endpointDescriptionArray(EndpointDescriptionArray::SPtr endpointDescriptionArray)
	{
		endpointDescriptionArray_ = endpointDescriptionArray;
	}

	void
	DiscoveryService::getEndpointRequest(
		RequestHeader::SPtr requestHeader,
		SecureChannelTransaction::SPtr secureChannelTransaction
	)
	{
		Log(Debug, "receive get endpoint request request");
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

		if (discoveryIf_ != nullptr) {
			ResponseHeader::SPtr responseHeader = getEndpointsResponse.responseHeader();
			discoveryIf_->discoveryResponseMessage(responseHeader, secureChannelTransaction);
		}
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

		if (discoveryIf_ != nullptr) {
			ResponseHeader::SPtr responseHeader = registerServerResponse.responseHeader();
			discoveryIf_->discoveryResponseMessage(responseHeader, secureChannelTransaction);
		}
	}

	void
	DiscoveryService::findServersRequest(
		RequestHeader::SPtr requestHeader,
		SecureChannelTransaction::SPtr secureChannelTransaction
	)
	{
		Log(Debug, "receive find servers request request");
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
			findServersResponse.servers(ctx.servers_);
		}

		responseHeader.opcUaBinaryEncode(os);
		findServersResponse.opcUaBinaryEncode(os);

		if (discoveryIf_ != nullptr) {
			ResponseHeader::SPtr responseHeader = findServersResponse.responseHeader();
			discoveryIf_->discoveryResponseMessage(responseHeader, secureChannelTransaction);
		}
	}


	void
	DiscoveryService::receive(Message::SPtr message)
	{
#if 0
		ServiceTransaction::SPtr serviceTransaction = boost::static_pointer_cast<ServiceTransaction>(message);
		switch (serviceTransaction->nodeTypeRequest().nodeId<uint32_t>())
		{
			case OpcUaId_RegisterServerRequest_Encoding_DefaultBinary:
				receiveRegisterServerRequest(serviceTransaction);
				break;
			default:
			{
				Log(Error, "discovery service received unknown message type")
					.parameter("TypeId", serviceTransaction->nodeTypeRequest());

				serviceTransaction->statusCode(BadInternalError);
				serviceTransaction->componentSession()->send(serviceTransaction);
				break;
			}
		}
#endif
	}

#if 0
	bool 
	DiscoveryService::receiveGetEndpointsRequest(SecureChannelTransactionOld::SPtr secureChannelTransaction)
	{
		std::iostream is(&secureChannelTransaction->is_);
		RequestHeader requestHeader;
		GetEndpointsRequest getEndpointsRequest;

		requestHeader.opcUaBinaryDecode(is);
		getEndpointsRequest.opcUaBinaryDecode(is);

		// FIXME: analyse request data

		std::iostream os(&secureChannelTransaction->os_);

		ResponseHeader responseHeader;
		GetEndpointsResponse getEndpointsResponse;

		responseHeader.requestHandle(requestHeader.requestHandle());
		responseHeader.serviceResult(Success);
		getEndpointsResponse.endpoints(endpointDescriptionArray_);

		responseHeader.opcUaBinaryEncode(os);
		getEndpointsResponse.opcUaBinaryEncode(os);
	
		if (discoveryManagerIf_ != nullptr) discoveryManagerIf_->discoveryMessage(secureChannelTransaction);
		return true;
	}

	bool 
	DiscoveryService::receiveFindServersRequest(SecureChannelTransactionOld::SPtr secureChannelTransaction)
	{
		std::iostream is(&secureChannelTransaction->is_);
		RequestHeader requestHeader;
		FindServersRequest findServersRequest;

		requestHeader.opcUaBinaryDecode(is);
		findServersRequest.opcUaBinaryDecode(is);

		// FIXME: analyse request data

		std::iostream os(&secureChannelTransaction->os_);

		ResponseHeader responseHeader;
		FindServersResponse findServersResponse;

		responseHeader.requestHandle(requestHeader.requestHandle());

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
			findServersResponse.servers(ctx.servers_);
		}

		responseHeader.opcUaBinaryEncode(os);
		findServersResponse.opcUaBinaryEncode(os);

		if (discoveryManagerIf_ != nullptr) discoveryManagerIf_->discoveryMessage(secureChannelTransaction);
		return true;
	}

	bool
	DiscoveryService::receiveRegisterServerRequest(SecureChannelTransactionOld::SPtr secureChannelTransaction)
	{
		std::iostream is(&secureChannelTransaction->is_);
		RequestHeader requestHeader;
		RegisterServerRequest registerServerRequest;

		requestHeader.opcUaBinaryDecode(is);
		registerServerRequest.opcUaBinaryDecode(is);

		// FIXME: analyse request data

		std::iostream os(&secureChannelTransaction->os_);

		ResponseHeader responseHeader;
		RegisterServerResponse registerServerResponse;

		responseHeader.requestHandle(requestHeader.requestHandle());

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

		if (discoveryManagerIf_ != nullptr) discoveryManagerIf_->discoveryMessage(secureChannelTransaction);
		return true;
	}

	void
	DiscoveryService::receiveRegisterServerRequest(ServiceTransaction::SPtr serviceTransaction)
	{
		ServiceTransactionRegisterServer::SPtr trx = boost::static_pointer_cast<ServiceTransactionRegisterServer>(serviceTransaction);

		RegisterServerRequest::SPtr registerServerRequest = trx->request();
		RegisterServerResponse::SPtr registerServerResponse = trx->response();

		Log(Debug, "discovery service register server request")
			.parameter("Trx", serviceTransaction->transactionId());

		// check forward callback functions
		ApplicationRegisterServerContext ctx;
		ctx.statusCode_ = BadNotSupported;
		OpcUaStatusCode statusCode = BadNotSupported;
		if (forwardGlobalSync()->registerServerService().isCallback()) {

			// forward register server request
			ctx.applicationContext_ = forwardGlobalSync()->registerServerService().applicationContext();
			registerServerRequest->server().copyTo(ctx.server_);
			forwardGlobalSync()->registerServerService().callback()(&ctx);
		}

		trx->statusCode(ctx.statusCode_);
		trx->componentSession()->send(serviceTransaction);
	}
#endif

}
