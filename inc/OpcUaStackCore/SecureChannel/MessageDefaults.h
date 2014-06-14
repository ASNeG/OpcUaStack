#ifndef __OpcUaStackCore_MessageDefaults_h__
#define __OpcUaStackCore_MessageDefaults_h__

#include "OpcUaStackCore/BuildInTypes/OpcUaNumber.h"

namespace OpcUaStackCore
{

	class MessageDefaults
	{
	  public:
		static const OpcUaUInt32 protocolVersionDefault_;
		static const OpcUaUInt32 receivedBufferSizeDefault_;
		static const OpcUaUInt32 sendBufferSizeDefault_;
		static const OpcUaUInt32 maxMessageSizeDefault_;
		static const OpcUaUInt32 maxChunkCountDefault_;
	};

}

#endif