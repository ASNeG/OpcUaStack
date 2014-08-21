#ifndef __OpcUaStackCore_SecureChannelClientConfig_h__
#define __OpcUaStackCore_SecureChannelClientConfig_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/Config.h"
#include "OpcUaStackCore/SecureChannel/SecureChannelClient.h"

namespace OpcUaStackCore
{

	class DLLEXPORT SecureChannelClientConfig
	{
	  public:
		static bool initial(SecureChannelClient::SPtr secureChannelClientSPtr, const std::string& configPrefix);
	};

}

#endif