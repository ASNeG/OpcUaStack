/*
   Copyright 2015-2017 Kai Huebl (kai@huebl-sgh.de)

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
	: Object()
	, trigger_(DCT_StatusValue)
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

	ExtensibleParameterBase::SPtr
	DataChangeFilter::factory(void)
	{
		return constructSPtr<DataChangeFilter>();
	}

	void 
	DataChangeFilter::opcUaBinaryEncode(std::ostream& os) const
	{
		OpcUaNumber::opcUaBinaryEncode(os, (OpcUaUInt32)trigger_);
		OpcUaNumber::opcUaBinaryEncode(os, deadbandType_);

		if((trigger_ != DCT_Status) && (deadbandType_ != 0))
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

		if((trigger_ != DCT_Status) && (deadbandType_ != 0))
		{
			OpcUaNumber::opcUaBinaryDecode(is, deadbandValue_);
		}
	}
}
