#ifndef __OpcUaStackCore_ApplicationWriteContext_h__
#define __OpcUaStackCore_ApplicationWriteContext_h__

#include "OpcUaStackCore/BuildInTypes/OpcUaNodeId.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaDataValue.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaStatusCode.h"

namespace OpcUaStackCore
{

	class ApplicationWriteContext
	{
	  public:
		OpcUaNodeId nodeId_;
		uint32_t attributeId_;
		OpcUaDataValue dataValue_;
		OpcUaStatusCode statusCode_;
	};

}

#endif
