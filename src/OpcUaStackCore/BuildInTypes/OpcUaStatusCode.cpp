#include "OpcUaStackCore/BuildInTypes/OpcUaStatusCode.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaNumber.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUaStatusCode
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
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


	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUaStatusCodeArray
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	void opcUaBinaryEncode(std::ostream& os, const OpcUaStatusCodeArray& value)
	{
		value.opcUaBinaryEncode(os);
	}

	void opcUaBinaryEncode(std::ostream& os, const OpcUaStatusCodeArray::SPtr& value)
	{
		value->opcUaBinaryEncode(os);
	}

	void opcUaBinaryDecode(std::istream& is, OpcUaStatusCodeArray& value)
	{
		value.opcUaBinaryDecode(is);
	}

	void opcUaBinaryDecode(std::istream& is, OpcUaStatusCodeArray::SPtr& value)
	{
		value->opcUaBinaryDecode(is);
	}

};