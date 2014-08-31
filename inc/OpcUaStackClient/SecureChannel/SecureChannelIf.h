#ifndef __OpcUaStackClient_SecureChannelIf_h__
#define __OpcUaStackClient_SecureChannelIf_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"

using namespace OpcUaStackCore;

namespace OpcUaStackClient
{

	class DLLEXPORT SecureChannelIf
	{
	  public:
		virtual void connect(void) = 0;
		virtual void disconnect(void) = 0;
		virtual void receive(OpcUaNodeId& nodeId, boost::asio::streambuf& is) = 0;
	};

}

#endif