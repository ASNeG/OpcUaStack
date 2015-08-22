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

	bool
	OpcUaXmlElement::encode(boost::property_tree::ptree& pt) const
	{
		return true;
	}

	bool
	OpcUaXmlElement::decode(boost::property_tree::ptree& pt)
	{
		return true;
	}
}
