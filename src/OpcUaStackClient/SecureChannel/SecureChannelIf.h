#ifndef __OpcUaStackClient_SecureChannelIf_h__
#define __OpcUaStackClient_SecureChannelIf_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackClient/SecureChannel/SecureChannelTransaction.h"

using namespace OpcUaStackCore;

namespace OpcUaStackClient
{

	class DLLEXPORT SecureChannelIf
	{
	  public:
		virtual void connect(void) = 0;
		virtual void disconnect(void) = 0;
		virtual bool receive(SecureChannelTransaction::SPtr secureChannelTransaction) = 0;
	};

}

#endif
