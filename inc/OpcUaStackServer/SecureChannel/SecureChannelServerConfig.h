#ifndef __OpcUaStackServer_SecureChannelServerConfig_h__
#define __OpcUaStackServer_SecureChannelServerConfig_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/Config.h"
#include "OpcUaStackServer/SecureChannel/SecureChannelServer.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	class DLLEXPORT SecureChannelServerConfig
	{
	  public:
		static bool initial(SecureChannelServer::SPtr secureChannelServerSPtr, const std::string& configPrefix);
	};

}

#endif