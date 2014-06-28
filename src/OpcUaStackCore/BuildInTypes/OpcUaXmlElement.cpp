#include "OpcUaStackCore/BuildInTypes/OpcUaXmlElement.h"

namespace OpcUaStackCore
{

	// ---------------------------------------------------------------------------
	// ---------------------------------------------------------------------------
	//
	// OpcUaXmlElement
	//
	// ---------------------------------------------------------------------------
	// ---------------------------------------------------------------------------
	OpcUaXmlElement::OpcUaXmlElement(void)
	: ObjectPool<OpcUaXmlElement>()
	{
	}

	OpcUaXmlElement::~OpcUaXmlElement(void)
	{
	}

	void 
	OpcUaXmlElement::opcUaBinaryEncode(std::ostream& os) const
	{
	}

	void 
	OpcUaXmlElement::opcUaBinaryDecode(std::istream& is)
	{
	}

	void 
	opcUaBinaryEncode(std::ostream& os, const OpcUaXmlElement& value)
	{
	}

	void 
	opcUaBinaryDecode(std::istream& is, OpcUaXmlElement& value)
	{
	}


	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUaXmlElementArray
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	void opcUaBinaryEncode(std::ostream& os, const OpcUaXmlElementArray& value)
	{
		value.opcUaBinaryEncode(os);
	}

	void opcUaBinaryEncode(std::ostream& os, const OpcUaXmlElementArray::SPtr& value)
	{
		value->opcUaBinaryEncode(os);
	}

	void opcUaBinaryDecode(std::istream& is, OpcUaXmlElementArray& value)
	{
		value.opcUaBinaryDecode(is);
	}

	void opcUaBinaryDecode(std::istream& is, OpcUaXmlElementArray::SPtr& value)
	{
		value->opcUaBinaryDecode(is);
	}

}