#ifndef __OpcUaStackServer_SecureChannelManagerIf_h__
#define __OpcUaStackServer_SecureChannelManagerIf_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackServer/SecureChannel/SecureChannelTransaction.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	class DLLEXPORT SecureChannelManagerIf
	{
	  public:
		virtual void connect(OpcUaUInt32 channelId) = 0;
		virtual void disconnect(OpcUaUInt32 channelId) = 0;
		virtual bool receive(OpcUaNodeId& nodeId, boost::asio::streambuf& is, SecureChannelTransaction& secureChannelTransaction) = 0;
	};

}

#endif