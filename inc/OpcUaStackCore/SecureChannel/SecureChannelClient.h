#ifndef __OpcUaStackCore_SecureChannelClient_h__
#define __OpcUaStackCore_SecureChannelClient_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/SecureChannel/SecureChannel.h"

namespace OpcUaStackCore
{

	class DLLEXPORT SecureChannelClient : public SecureChannel
	{
	  public:
		SecureChannelClient(void);
		~SecureChannelClient(void);
	};

}

#endif