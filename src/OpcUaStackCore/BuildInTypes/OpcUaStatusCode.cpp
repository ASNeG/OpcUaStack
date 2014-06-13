#include "OpcUaStackCore/BuildInTypes/OpcUaStatusCode.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaNumber.h"

namespace OpcUaStackCore
{

	void 
	opcUaBinaryEncode(std::ostream& os, const OpcUaStatusCode& value)
	{
		OpcUaStackCore::opcUaBinaryEncode(os, (OpcUaUInt32)value);
	}

	void 
	opcUaBinaryDecode(std::istream& is, OpcUaStatusCode& value)
	{
		OpcUaUInt32 v;
		OpcUaStackCore::opcUaBinaryDecode(is, v);
		value = (OpcUaStatusCode)v;
	}

};