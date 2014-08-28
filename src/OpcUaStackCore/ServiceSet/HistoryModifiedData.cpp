#include "OpcUaStackCore/ServiceSet/HistoryModifiedData.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa HistoryModifiedData
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	HistoryModifiedData::HistoryModifiedData(void)
	: ObjectPool<HistoryModifiedData>()
	, dataValueArraySPtr_(OpcUaDataValueArray::construct())
	, modificationInfoArraySPtr_(ModificationInfoArray::construct())
	{
	}

	HistoryModifiedData::~HistoryModifiedData(void)
	{
	}

	void 
	HistoryModifiedData::dataValues(const OpcUaDataValueArray::SPtr dataValues)
	{
		dataValueArraySPtr_ = dataValues;
	}
	
	OpcUaDataValueArray::SPtr 
	HistoryModifiedData::dataValues(void) const
	{
		return dataValueArraySPtr_;
	}

	void 
	HistoryModifiedData::modificationInfos(const ModificationInfoArray::SPtr modificationInfos)
	{
		modificationInfoArraySPtr_ = modificationInfos;
	}
	
	ModificationInfoArray::SPtr 
	HistoryModifiedData::modificationInfos(void) const
	{
		return modificationInfoArraySPtr_;
	}

	ExtensibleParameterBase::BSPtr 
	HistoryModifiedData::factory(void)
	{
		return HistoryModifiedData::construct();
	}

	void 
	HistoryModifiedData::opcUaBinaryEncode(std::ostream& os) const
	{
		dataValueArraySPtr_->opcUaBinaryEncode(os);
		modificationInfoArraySPtr_->opcUaBinaryEncode(os);
	}
	
	void 
	HistoryModifiedData::opcUaBinaryDecode(std::istream& is)
	{
		dataValueArraySPtr_->opcUaBinaryDecode(is);
		modificationInfoArraySPtr_->opcUaBinaryDecode(is);
	}
}