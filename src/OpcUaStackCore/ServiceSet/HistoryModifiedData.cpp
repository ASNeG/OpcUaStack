/*
   Copyright 2015 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   Informationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Kai Huebl (kai@huebl-sgh.de)
 */

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
	: Object()
	, dataValueArraySPtr_(constructSPtr<OpcUaDataValueArray>())
	, modificationInfoArraySPtr_(constructSPtr<ModificationInfoArray>())
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

	ExtensibleParameterBase::SPtr
	HistoryModifiedData::factory(void)
	{
		return constructSPtr<HistoryModifiedData>();
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
