#ifndef __OpcUaStackServer_SecureChannelMap_h__
#define __OpcUaStackServer_SecureChannelMap_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaNumber.h"
#include "OpcUaStackServer/SecureChannel/SecureChannelServer.h"
#include <map>

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	typedef enum {
		SecureChannelState_Init,
		SecureChannelState_Connect
	} SecureChannelState;


	class DLLEXPORT SecureChannelElement : public ObjectPool<SecureChannelElement>
	{
	  public:
		typedef boost::shared_ptr<SecureChannelElement> SPtr;

		OpcUaUInt32 channelId_;
		SecureChannelState secureChannelState_;
		SecureChannelServer::SPtr secureChannelServer_;
	};


	class DLLEXPORT SecureChannelMap
	{
	  public:
		typedef std::map<OpcUaInt32, SecureChannelElement::SPtr> SecureChannelElementMap;

		SecureChannelMap(void);
		~SecureChannelMap(void);

		uint32_t size(void);
		bool insert(OpcUaInt32 channelId, SecureChannelServer::SPtr secureChannelServer);
		bool connect(OpcUaInt32 channelId);
		bool disconnect(OpcUaInt32 channelId);

		SecureChannelServer::SPtr get(OpcUaUInt32 channelId);

	  private:
		SecureChannelElement::SPtr secureChannelElement(OpcUaInt32 channelId);

		SecureChannelElementMap secureChannelElementMap_;
	};

}

#endif