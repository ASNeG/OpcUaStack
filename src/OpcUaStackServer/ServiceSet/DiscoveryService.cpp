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
	DiscoveryService::message(boost::asio::streambuf& sb, SecureChannelTransaction& secureChannelTransaction)
	{
		switch(secureChannelTransaction.requestTypeNodeId_.nodeId<OpcUaUInt32>())
		{
			case OpcUaId_GetEndpointsRequest_Encoding_DefaultBinary:
			{
				Log(Debug, "receive get endpoints request");
				secureChannelTransaction.responseTypeNodeId_.nodeId(OpcUaId_GetEndpointsResponse_Encoding_DefaultBinary);
				return receiveGetEndpointsRequest(sb, secureChannelTransaction);
			}
			default:
			{
				Log(Error, "Discovery service receives unknown message type")
					.parameter("MessageType", secureChannelTransaction.requestTypeNodeId_.nodeId<OpcUaUInt32>());
			}
		}
		return false;
	}

	bool 
	DiscoveryService::receiveGetEndpointsRequest(boost::asio::streambuf& sb, SecureChannelTransaction& secureChannelTransaction)
	{
		std::iostream is(&sb);
		RequestHeader requestHeader;
		GetEndpointsRequest getEndpointsRequest;

		requestHeader.opcUaBinaryDecode(is);
		getEndpointsRequest.opcUaBinaryDecode(is);

		// FIXME: analyse request data

		boost::asio::streambuf sbo;
		std::iostream os(&sbo);

		ResponseHeader responseHeader;
		GetEndpointsResponse getEndpointsResponse;

		responseHeader.requestHandle(requestHeader.requestHandle());
		responseHeader.serviceResult(Success);
		getEndpointsResponse.endpoints(endpointDescriptionArray_);

		responseHeader.opcUaBinaryEncode(os);
		getEndpointsResponse.opcUaBinaryEncode(os);
	
		if (discoveryManagerIf_ != nullptr) discoveryManagerIf_->discoveryMessage(sbo, secureChannelTransaction);
		return true;
	}

	bool 
	DiscoveryService::receiveFindServersRequest(boost::asio::streambuf& sb, SecureChannelTransaction& secureChannelTransaction)
	{
		// FIXME:
		return false;
	}

	bool 
	DiscoveryService::receiveRegisterServerRequest(boost::asio::streambuf& sb, SecureChannelTransaction& secureChannelTransaction)
	{
		// FIXME:
		return false;
	}

}