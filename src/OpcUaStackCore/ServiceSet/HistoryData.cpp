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
	: Object()
	, dataValueArraySPtr_(constructSPtr<OpcUaDataValueArray>())
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

	ExtensibleParameterBase::SPtr
	HistoryData::factory(void)
	{
		return constructSPtr<HistoryData>();
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
