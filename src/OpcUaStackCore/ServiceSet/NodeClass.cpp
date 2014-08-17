#include "OpcUaStackCore/ServiceSet/NodeClass.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// MethodAttributes
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	NodeClass::NodeClass(void)
		: nodeClassType_(NodeClassType_Unspecified)
	{
	}

	NodeClass::~NodeClass(void)
	{
	}

	 NodeClassType
     NodeClass::nodeClassType(void) const
	 {
		 return nodeClassType_;
	 }

	void
	NodeClass::nodeClassType(
		const NodeClassType nodeClassType)
	{
		nodeClassType_ = nodeClassType;		
	}
		
	void 
	NodeClass::opcUaBinaryEncode(
		std::ostream& os) const
	{
		OpcUaNumber::opcUaBinaryEncode(os, (OpcUaUInt32)nodeClassType_);
	}
	
	void 
	NodeClass::opcUaBinaryDecode(
		std::istream& is)
	{
		OpcUaUInt32 nodeClassType;
		OpcUaNumber::opcUaBinaryDecode(is, nodeClassType);
		nodeClassType_ = (NodeClassType)nodeClassType;
	}

}