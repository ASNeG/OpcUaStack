#ifndef __OpcUaStackServer_DiscoveryService_h__
#define __OpcUaStackServer_DiscoveryService_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/ServiceSet/EndpointDescription.h"
#include "OpcUaStackServer/ServiceSet/DiscoveryManagerIf.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	class DLLEXPORT DiscoveryService 
	: public ObjectPool<DiscoveryService>
	{
	  public:
		typedef boost::shared_ptr<DiscoveryService> SPtr;

		DiscoveryService(void);
		~DiscoveryService(void);

		void discoveryManagerIf(DiscoveryManagerIf* discoveryManagerIf);
		void endpointDescriptionArray(EndpointDescriptionArray::SPtr endpointDescriptionArray);

		bool message(SecureChannelTransaction::SPtr secureChannelTransaction);

	  private:
		EndpointDescriptionArray::SPtr endpointDescriptionArray_;
		DiscoveryManagerIf* discoveryManagerIf_;

		bool receiveGetEndpointsRequest(SecureChannelTransaction::SPtr secureChannelTransaction);
		bool receiveFindServersRequest(SecureChannelTransaction::SPtr secureChannelTransaction);
		bool receiveRegisterServerRequest(SecureChannelTransaction::SPtr secureChannelTransaction);
	};

}

#endif
