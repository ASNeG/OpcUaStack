#ifndef __OpcUaStackServer_DiscoveryService_h__
#define __OpcUaStackServer_DiscoveryService_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/ServiceSet/EndpointDescription.h"
#include "OpcUaStackServer/ServiceSet/SessionIf.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	class DLLEXPORT DiscoveryService : public ObjectPool<DiscoveryService>
	{
	  public:
		DiscoveryService(void);
		~DiscoveryService(void);

		void sessionSecureChannelIf(SessionSecureChannelIf* sessionSecureChannelIf);

		void endpointDescriptionArray(EndpointDescriptionArray::SPtr endpointDescriptionArray);

		bool receiveGetEndpointsRequest(OpcUaStackCore::OpcUaNodeId& typeId, boost::asio::streambuf& sb, SecureChannelTransaction& secureChannelTransaction);

	  private:
		EndpointDescriptionArray::SPtr endpointDescriptionArray_;
		SessionSecureChannelIf* sessionSecureChannelIf_;
	};

}

#endif