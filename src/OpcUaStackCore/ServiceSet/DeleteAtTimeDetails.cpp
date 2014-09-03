#include "OpcUaStackCore/ServiceSet/DeleteAtTimeDetails.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa DeleteAtTimeDetails
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	DeleteAtTimeDetails::DeleteAtTimeDetails(void)
	: ObjectPool<DeleteAtTimeDetails>()
	, nodeId_()
	, reqTimeArraySPtr_(UtcTimeArray::construct())
	{
	}

	DeleteAtTimeDetails::~DeleteAtTimeDetails(void)
	{
	}

	void 
	DeleteAtTimeDetails::nodeId(const OpcUaNodeId& nodeId)
	{
		nodeId_ = nodeId;
	}
	
	OpcUaNodeId& 
	DeleteAtTimeDetails::nodeId(void)
	{
		return nodeId_;
	}

	void 
	DeleteAtTimeDetails::reqTimes(const UtcTimeArray::SPtr reqTimes)
	{
		reqTimeArraySPtr_ = reqTimes;
	}
	
	UtcTimeArray::SPtr 
	DeleteAtTimeDetails::reqTimes(void) const
	{
		return reqTimeArraySPtr_;
	}

	ExtensibleParameterBase::BSPtr 
	DeleteAtTimeDetails::factory(void)
	{
		return DeleteAtTimeDetails::construct();
	}

	void 
	DeleteAtTimeDetails::opcUaBinaryEncode(std::ostream& os) const
	{
		nodeId_.opcUaBinaryEncode(os);
		reqTimeArraySPtr_->opcUaBinaryEncode(os);
	}
	
	void 
	DeleteAtTimeDetails::opcUaBinaryDecode(std::istream& is)
	{
		nodeId_.opcUaBinaryDecode(is);
		reqTimeArraySPtr_->opcUaBinaryDecode(is);
	}
}