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

#include "OpcUaStackCore/ServiceSet/AggregateFilterResult.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa AggregateFilterResult
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	AggregateFilterResult::AggregateFilterResult(void)
	: Object()
	, revisedStartTime_()
	, revisedProcessingInterval_()
	{
	}

	AggregateFilterResult::~AggregateFilterResult(void)
	{
	}

	void 
	AggregateFilterResult::revisedStartTime(const UtcTime& time)
	{
		revisedStartTime_ = time;
	}
	
	void 
	AggregateFilterResult::revisedStartTime(const boost::posix_time::ptime& time)
	{
		revisedStartTime_.dateTime(time);
	}
	
	UtcTime 
	AggregateFilterResult::revisedStartTime(void) const
	{
		return revisedStartTime_;
	}
	
	void 
	AggregateFilterResult::revisedProcessingInterval(const OpcUaDouble& revisedProcessingInterval)
	{
		revisedProcessingInterval_ = revisedProcessingInterval;
	}
	
	OpcUaDouble 
	AggregateFilterResult::revisedProcessingInterval(void) const
	{
		return revisedProcessingInterval_;
	}

	ExtensibleParameterBase::SPtr
	AggregateFilterResult::factory(void)
	{
		return constructSPtr<AggregateFilterResult>();
	}

	void 
	AggregateFilterResult::opcUaBinaryEncode(std::ostream& os) const
	{
		revisedStartTime_.opcUaBinaryEncode(os);
		OpcUaNumber::opcUaBinaryEncode(os, revisedProcessingInterval_);
	}
	
	void 
	AggregateFilterResult::opcUaBinaryDecode(std::istream& is)
	{
		revisedStartTime_.opcUaBinaryDecode(is);
		OpcUaNumber::opcUaBinaryDecode(is, revisedProcessingInterval_);
	}
}
