#ifndef __OpcUaStackCore_SecureChannelServerConfig_h__
#define __OpcUaStackCore_SecureChannelServerConfig_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/Config.h"
#include "OpcUaStackCore/SecureChannel/SecureChannelServer.h"

namespace OpcUaStackCore
{

	class DLLEXPORT SecureChannelServerConfig
	{
	  public:
		static bool initial(SecureChannelServer::SPtr secureChannelServerSPtr, const std::string& configPrefix);
	};

}

#endif