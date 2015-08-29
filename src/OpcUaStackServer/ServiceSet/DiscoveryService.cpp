/*
   Copyright 2015 Kai Huebl (kai@huebl-sgh.de)

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
#include "OpcUaStackCore/ServiceSet/GetEndpointsRequest.h"
#include "OpcUaStackCore/ServiceSet/GetEndpointsResponse.h"
#include "OpcUaStackServer/ServiceSet/DiscoveryService.h"


namespace OpcUaStackServer
{

	DiscoveryService::DiscoveryService(void)
	: discoveryManagerIf_(nullptr)
	{
	}

	DiscoveryService::~DiscoveryService(void)
	{
	}

	void 
	DiscoveryService::discoveryManagerIf(DiscoveryManagerIf* discoveryManagerIf)
	{
		discoveryManagerIf_ = discoveryManagerIf;
	}

	void 
	DiscoveryService::endpointDescriptionArray(EndpointDescriptionArray::SPtr endpointDescriptionArray)
	{
		endpointDescriptionArray_ = endpointDescriptionArray;
	}

	bool 
	DiscoveryService::message(SecureChannelTransaction::SPtr secureChannelTransaction)
	{
		switch(secureChannelTransaction->requestTypeNodeId_.nodeId<OpcUaUInt32>())
		{
			case OpcUaId_GetEndpointsRequest_Encoding_DefaultBinary:
			{
				Log(Debug, "receive get endpoints request");
				secureChannelTransaction->responseTypeNodeId_.nodeId(OpcUaId_GetEndpointsResponse_Encoding_DefaultBinary);
				return receiveGetEndpointsRequest(secureChannelTransaction);
			}
			default:
			{
				Log(Error, "Discovery service receives unknown message type")
					.parameter("MessageType", secureChannelTransaction->requestTypeNodeId_.nodeId<OpcUaUInt32>());
			}
		}
		return false;
	}

	bool 
	DiscoveryService::receiveGetEndpointsRequest(SecureChannelTransaction::SPtr secureChannelTransaction)
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
	DiscoveryService::receiveFindServersRequest(SecureChannelTransaction::SPtr secureChannelTransaction)
	{
		// FIXME:
		return false;
	}

	bool 
	DiscoveryService::receiveRegisterServerRequest(SecureChannelTransaction::SPtr secureChannelTransaction)
	{
		// FIXME:
		return false;
	}

}
