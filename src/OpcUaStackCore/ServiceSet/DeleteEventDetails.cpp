#include "OpcUaStackCore/ServiceSet/DeleteEventDetails.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa DeleteEventDetails
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	DeleteEventDetails::DeleteEventDetails(void)
	: ObjectPool<DeleteEventDetails>()
	, nodeId_()
	, eventIdArraySPtr_(OpcUaByteStringArray::construct())
	{
	}

	DeleteEventDetails::~DeleteEventDetails(void)
	{
	}

	void 
	DeleteEventDetails::nodeId(const OpcUaNodeId& nodeId)
	{
		nodeId_ = nodeId;
	}
	
	OpcUaNodeId& 
	DeleteEventDetails::nodeId(void)
	{
		return nodeId_;
	}

	void 
	DeleteEventDetails::eventId(const OpcUaByteStringArray::SPtr eventId)
	{
		eventIdArraySPtr_ = eventId;
	}
	
	OpcUaByteStringArray::SPtr 
	DeleteEventDetails::eventId(void) const
	{
		return eventIdArraySPtr_;
	}

	ExtensibleParameterBase::BSPtr 
	DeleteEventDetails::factory(void)
	{
		return DeleteEventDetails::construct();
	}

	void 
	DeleteEventDetails::opcUaBinaryEncode(std::ostream& os) const
	{
		nodeId_.opcUaBinaryEncode(os);
		eventIdArraySPtr_->opcUaBinaryEncode(os);
	}
	
	void 
	DeleteEventDetails::opcUaBinaryDecode(std::istream& is)
	{
		nodeId_.opcUaBinaryDecode(is);
		eventIdArraySPtr_->opcUaBinaryDecode(is);
	}
}