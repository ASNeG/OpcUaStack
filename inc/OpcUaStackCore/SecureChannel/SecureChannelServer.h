#ifndef __OpcUaStackCore_SecureChannelServer_h__
#define __OpcUaStackCore_SecureChannelServer_h__

#include "OpcUaStackCore/SecureChannel/SecureChannel.h"

namespace OpcUaStackCore
{

	class SecureChannelServer : public SecureChannel
	{
	  public:
		SecureChannelServer(void);
		~SecureChannelServer(void);
	};

}

#endif