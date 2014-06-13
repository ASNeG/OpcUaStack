#include "OpcUaStackCore/BuildInTypes/OpcUaNodeId.h"

namespace OpcUaStackCore
{

	OpcUaNodeId::OpcUaNodeId(void)
	: ObjectPool<OpcUaNodeId>()
	, OpcUaNodeIdBase()
	{
	}

	OpcUaNodeId::~OpcUaNodeId(void)
	{
	}

	void opcUaBinaryEncode(std::ostream& os, const OpcUaNodeId& value)
	{
		value.opcUaBinaryEncode(os);
	}

	void opcUaBinaryDecode(std::istream& is, OpcUaNodeId& value)
	{
		value.opcUaBinaryDecode(is);
	}

}