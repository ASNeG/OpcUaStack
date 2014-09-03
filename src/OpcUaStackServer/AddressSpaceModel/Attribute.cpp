#include "OpcUaStackServer/AddressSpaceModel/Attribute.h"

namespace OpcUaStackServer
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// Attribute
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	Attribute::Attribute(void)
	{
	}

	Attribute::~Attribute(void)
	{
	}

	std::string 
	Attribute::description(void)
	{
		return name();
	}

}