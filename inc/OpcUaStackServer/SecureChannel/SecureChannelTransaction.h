#ifndef __OpcUaStackServer_SecureChannelTransaction_h__
#define __OpcUaStackServer_SecureChannelTransaction_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	class DLLEXPORT SecureChannelTransaction : public ObjectPool<SecureChannelTransaction> 
	{
	  public:
	    SecureChannelTransaction(void);
	    ~SecureChannelTransaction(void);

		uint32_t requestId_;
	};

}

#endif