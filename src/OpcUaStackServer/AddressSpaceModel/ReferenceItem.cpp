#include "OpcUaStackServer/AddressSpaceModel/ReferenceItem.h"


namespace OpcUaStackServer
{

	ReferenceItem::ReferenceItem(void)
	{
	}

	ReferenceItem::~ReferenceItem(void)
	{
	}

	bool 
	ReferenceItem::operator==(const ReferenceItem& referenceItem)
	{
		return nodeId_ == referenceItem.nodeId_ && isForward_ == referenceItem.isForward_;
	}

}
