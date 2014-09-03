#include "OpcUaStackCore/ServiceSet/HistoryData.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa HistoryData
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	HistoryData::HistoryData(void)
	: ObjectPool<HistoryData>()
	, dataValueArraySPtr_(OpcUaDataValueArray::construct())
	{
	}

	HistoryData::~HistoryData(void)
	{
	}

	void 
	HistoryData::dataValues(const OpcUaDataValueArray::SPtr dataValues)
	{
		dataValueArraySPtr_ = dataValues;
	}
	
	OpcUaDataValueArray::SPtr 
	HistoryData::dataValues(void) const
	{
		return dataValueArraySPtr_;
	}

	ExtensibleParameterBase::BSPtr 
	HistoryData::factory(void)
	{
		return HistoryData::construct();
	}

	void 
	HistoryData::opcUaBinaryEncode(std::ostream& os) const
	{
		dataValueArraySPtr_->opcUaBinaryEncode(os);
	}
	
	void 
	HistoryData::opcUaBinaryDecode(std::istream& is)
	{
		dataValueArraySPtr_->opcUaBinaryDecode(is);
	}
}