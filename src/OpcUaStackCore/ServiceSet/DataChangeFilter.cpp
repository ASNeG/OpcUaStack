#include "OpcUaStackCore/ServiceSet/DataChangeFilter.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa DataChangeFilter
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	DataChangeFilter::DataChangeFilter(void)
	: ObjectPool<DataChangeFilter>()
	, trigger_(DataChangeTrigger_Status_Value)
	, deadbandType_(0)
	, deadbandValue_()
	{
	}

	DataChangeFilter::~DataChangeFilter(void)
	{
	}

	void 
	DataChangeFilter::trigger(const DataChangeTrigger trigger)
	{
		trigger_ = trigger;
	}
	
	DataChangeTrigger 
	DataChangeFilter::trigger(void)
	{
		return trigger_;
	}
	
	void 
	DataChangeFilter::deadbandType(const OpcUaUInt32& deadBandType)
	{
		deadbandType_ = deadBandType;
	}
	
	OpcUaUInt32 
	DataChangeFilter::deadbandType(void)
	{
		return deadbandType_;
	}
	
	void 
	DataChangeFilter::deadbandValue(const OpcUaDouble& deadbandValue)
	{
		deadbandValue_ = deadbandValue;
	}

	OpcUaDouble 
	DataChangeFilter::deadbandValue(void)
	{
		return deadbandValue_;
	}

	ExtensibleParameterBase::BSPtr 
	DataChangeFilter::factory(void)
	{
		return DataChangeFilter::construct();
	}

	void 
	DataChangeFilter::opcUaBinaryEncode(std::ostream& os) const
	{
		OpcUaNumber::opcUaBinaryEncode(os, (OpcUaUInt32)trigger_);
		OpcUaNumber::opcUaBinaryEncode(os, deadbandType_);

		if((trigger_ != DataChangeTrigger_Status) && (deadbandType_ != 0))
		{
			OpcUaNumber::opcUaBinaryEncode(os, deadbandValue_);
		}
	}
	
	void 
	DataChangeFilter::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaUInt32 tmp;
		OpcUaNumber::opcUaBinaryDecode(is, tmp);
		trigger_ = (DataChangeTrigger)tmp;
		OpcUaNumber::opcUaBinaryDecode(is, deadbandType_);

		if((trigger_ != DataChangeTrigger_Status) && (deadbandType_ != 0))
		{
			OpcUaNumber::opcUaBinaryDecode(is, deadbandValue_);
		}
	}
}