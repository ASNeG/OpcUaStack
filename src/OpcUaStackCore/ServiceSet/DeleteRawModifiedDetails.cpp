#include "OpcUaStackCore/ServiceSet/DeleteRawModifiedDetails.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa DeleteRawModifiedDetails
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	DeleteRawModifiedDetails::DeleteRawModifiedDetails(void)
	: ObjectPool<DeleteRawModifiedDetails>()
	, nodeId_()
	, isDeleteModified_()
	, startTime_()
	, endTime_()
	{
	}

	DeleteRawModifiedDetails::~DeleteRawModifiedDetails(void)
	{
	}
	
	void 
	DeleteRawModifiedDetails::nodeId(const OpcUaNodeId& nodeId)
	{
		nodeId_ = nodeId;
	}

	OpcUaNodeId& 
	DeleteRawModifiedDetails::nodeId(void)
	{
		return nodeId_;
	}
	
	void 
	DeleteRawModifiedDetails::isDeleteModified(const OpcUaBoolean& isDeleteModified)
	{
		isDeleteModified_ = isDeleteModified;
	}
	
	OpcUaBoolean 
	DeleteRawModifiedDetails::isDeleteModified(void)
	{
		return isDeleteModified_;
	}

	void 
	DeleteRawModifiedDetails::startTime(const UtcTime& startTime)
	{
		startTime_ = startTime;
	}
	
	void 
	DeleteRawModifiedDetails::startTime(const boost::posix_time::ptime& startTime)
	{
		startTime_.dateTime(startTime);
	}
	
	UtcTime& 
	DeleteRawModifiedDetails::startTime(void)
	{
		return startTime_;
	}
	
	void 
	DeleteRawModifiedDetails::endTime(const UtcTime& endTime)
	{
		endTime_ = endTime;
	}

	void 
	DeleteRawModifiedDetails::endTime(const boost::posix_time::ptime& endTime)
	{
		endTime_.dateTime(endTime);
	}
	
	UtcTime& 
	DeleteRawModifiedDetails::endTime(void)
	{
		return endTime_;
	}

	ExtensibleParameterBase::BSPtr 
	DeleteRawModifiedDetails::factory(void)
	{
		return DeleteRawModifiedDetails::construct();
	}

	void 
	DeleteRawModifiedDetails::opcUaBinaryEncode(std::ostream& os) const
	{
		nodeId_.opcUaBinaryEncode(os);
		OpcUaNumber::opcUaBinaryEncode(os, isDeleteModified_);
		startTime_.opcUaBinaryEncode(os);
		endTime_.opcUaBinaryEncode(os);
	}
	
	void 
	DeleteRawModifiedDetails::opcUaBinaryDecode(std::istream& is)
	{
		nodeId_.opcUaBinaryDecode(is);
		OpcUaNumber::opcUaBinaryDecode(is, isDeleteModified_);
		startTime_.opcUaBinaryDecode(is);
		endTime_.opcUaBinaryDecode(is);
	}
}