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
}