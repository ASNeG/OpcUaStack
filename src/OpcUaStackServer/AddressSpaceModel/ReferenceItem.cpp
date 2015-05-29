#include "OpcUaStackServer/AddressSpaceModel/ReferenceItem.h"


namespace OpcUaStackServer
{

	ReferenceItem::ReferenceItem(void)
	{
	}

	ReferenceItem::~ReferenceItem(void)
	{
	}

	void
	ReferenceItem::copyTo(ReferenceItem::SPtr referenceItem)
	{
		copyTo(*referenceItem);
	}

	void
	ReferenceItem::copyTo(ReferenceItem& referenceItem)
	{
		nodeId_.copyTo(referenceItem.nodeId_);
		referenceItem.isForward_ = isForward_;
	}

	bool 
	ReferenceItem::operator==(const ReferenceItem& referenceItem)
	{
		return nodeId_ == referenceItem.nodeId_ && isForward_ == referenceItem.isForward_;
	}

}
