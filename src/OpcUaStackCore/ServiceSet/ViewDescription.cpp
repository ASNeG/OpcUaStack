#include "OpcUaStackCore/ServiceSet/ViewDescription.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa ViewDescription
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	ViewDescription::ViewDescription(void)
	: ObjectPool<ViewDescription>()
	, viewIdSPtr_(OpcUaNodeId::construct())
	, timestamp_()
	, viewVersion_()
	{
	}

	ViewDescription::~ViewDescription(void)
	{
	}

	void 
	ViewDescription::viewId(const OpcUaNodeId::SPtr viewId)
	{
		viewIdSPtr_ = viewId;
	}
	
	OpcUaNodeId::SPtr 
	ViewDescription::viewId(void)
	{
		return viewIdSPtr_;
	}
	
	void 
	ViewDescription::timestamp(const UtcTime& timestamp)
	{
		timestamp_ = timestamp;
	}
	
	void 
	ViewDescription::timestamp(const boost::posix_time::ptime& timestamp)
	{
		timestamp_.dateTime(timestamp);
	}
	
	UtcTime& 
	ViewDescription::timestamp(void)
	{
		return timestamp_;
	}
	
	void 
	ViewDescription::viewVersion(const OpcUaUInt32& viewVersion)
	{
		viewVersion_ = viewVersion;
	}
	
	OpcUaUInt32 
	ViewDescription::viewVersion(void)
	{
		return viewVersion_;
	}

	void 
	ViewDescription::opcUaBinaryEncode(std::ostream& os) const
	{
		viewIdSPtr_->opcUaBinaryEncode(os);
		timestamp_.opcUaBinaryEncode(os);
		OpcUaNumber::opcUaBinaryEncode(os, viewVersion_);
	}
	
	void 
	ViewDescription::opcUaBinaryDecode(std::istream& is)
	{
		viewIdSPtr_->opcUaBinaryDecode(is);
		timestamp_.opcUaBinaryDecode(is);
		OpcUaNumber::opcUaBinaryDecode(is, viewVersion_);
	}

}