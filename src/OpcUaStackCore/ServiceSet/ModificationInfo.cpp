#include "OpcUaStackCore/ServiceSet/ModificationInfo.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa ModificationInfo
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	ModificationInfo::ModificationInfo(void)
	: ObjectPool<ModificationInfo>()
	, username_()
	, modificationTime_()
	, updateType_()
	{
	}

	ModificationInfo::~ModificationInfo(void)
	{
	}

	void 
	ModificationInfo::username(const OpcUaString& username)
	{
		username_ = username;
	}
	
	void 
	ModificationInfo::username(const std::string& username)
	{
		username_.value(username);
	}
	
	OpcUaString& 
	ModificationInfo::username(void)
	{
		return username_;
	}
	
	void 
	ModificationInfo::modificationTime(const UtcTime& modificationTime)
	{
		modificationTime_ = modificationTime;
	}
	
	void 
	ModificationInfo::modificationTime(const boost::posix_time::ptime& modificationTime)
	{
		modificationTime_.dateTime(modificationTime);
	}
	
	UtcTime& 
	ModificationInfo::modificationTime(void)
	{
		return modificationTime_;
	}
	
	void 
	ModificationInfo::updateType(const HistoryUpdateMode updateType)
	{
		updateType_ = updateType;
	}
	
	HistoryUpdateMode 
	ModificationInfo::updateType(void)
	{
		return updateType_;
	}

	void 
	ModificationInfo::opcUaBinaryEncode(std::ostream& os) const
	{
		username_.opcUaBinaryEncode(os);
		modificationTime_.opcUaBinaryEncode(os);
		OpcUaNumber::opcUaBinaryEncode(os, (OpcUaUInt32)updateType_);
	}
	
	void 
	ModificationInfo::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaUInt32 tmp;
		username_.opcUaBinaryDecode(is);
		modificationTime_.opcUaBinaryDecode(is);
		OpcUaNumber::opcUaBinaryDecode(is, tmp);
		updateType_ = (HistoryUpdateMode)tmp;
	}
}