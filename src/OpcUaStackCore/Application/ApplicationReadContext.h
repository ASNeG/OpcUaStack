#ifndef __OpcUaStackCore_ApplicationReadContext_h__
#define __OpcUaStackCore_ApplicationReadContext_h__

#include "OpcUaStackCore/BuildInTypes/OpcUaNodeId.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaDataValue.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaStatusCode.h"

namespace OpcUaStackCore
{

	class ApplicationReadContext
	{
	  public:
		OpcUaNodeId nodeId_;
		uint32_t attributeId_;
		OpcUaDataValue dataValue_;
		OpcUaStatusCode statusCode_;
	};

}

#endif
