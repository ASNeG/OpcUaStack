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

#include "OpcUaStackCore/ServiceSet/ReadProcessedDetails.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa ReadProcessedDetails
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	ReadProcessedDetails::ReadProcessedDetails(void)
	: Object()
	, startTime_()
	, endTime_()
	, resampleInterval_()
	, aggregateTypeArraySPtr_(constructSPtr<OpcUaNodeIdArray>())
	, aggregateConfiguration_()
	{
	}

	ReadProcessedDetails::~ReadProcessedDetails(void)
	{
	}
	
	void 
	ReadProcessedDetails::startTime(const UtcTime& startTime)
	{
		startTime_ = startTime;
	}
	
	void 
	ReadProcessedDetails::startTime(const boost::posix_time::ptime& startTime)
	{
		startTime_.dateTime(startTime);
	}
	
	UtcTime& 
	ReadProcessedDetails::startTime(void)
	{
		return startTime_;
	}
	
	void 
	ReadProcessedDetails::endTime(const UtcTime& endTime)
	{
		endTime_ = endTime;
	}

	void 
	ReadProcessedDetails::endTime(const boost::posix_time::ptime& endTime)
	{
		endTime_.dateTime(endTime);
	}
	
	UtcTime& 
	ReadProcessedDetails::endTime(void)
	{
		return endTime_;
	}

	void 
	ReadProcessedDetails::resampleInterval(const OpcUaDouble& resampleInterval)
	{
		resampleInterval_ = resampleInterval;
	}
	
	OpcUaDouble 
	ReadProcessedDetails::resampleInterval(void)
	{
		return resampleInterval_;
	}
	
	void 
	ReadProcessedDetails::aggregateType(const OpcUaNodeIdArray::SPtr aggregateType)
	{
		aggregateTypeArraySPtr_ = aggregateType;
	}
	
	OpcUaNodeIdArray::SPtr 
	ReadProcessedDetails::aggregateType(void) const
	{
		return aggregateTypeArraySPtr_;
	}
	
	void 
	ReadProcessedDetails::aggregateConfiguration(const AggregateConfiguration& aggregateConfiguration)
	{
		aggregateConfiguration_ = aggregateConfiguration;
	}
	
	AggregateConfiguration& 
	ReadProcessedDetails::aggregateConfiguration(void)
	{
		return aggregateConfiguration_;
	}

	ExtensibleParameterBase::SPtr
	ReadProcessedDetails::factory(void)
	{
		return constructSPtr<ReadProcessedDetails>();
	}

	void 
	ReadProcessedDetails::opcUaBinaryEncode(std::ostream& os) const
	{
		startTime_.opcUaBinaryEncode(os);
		endTime_.opcUaBinaryEncode(os);
		OpcUaNumber::opcUaBinaryEncode(os, resampleInterval_);
		aggregateTypeArraySPtr_->opcUaBinaryEncode(os);
		aggregateConfiguration_.opcUaBinaryEncode(os);
	}
	
	void 
	ReadProcessedDetails::opcUaBinaryDecode(std::istream& is)
	{
		startTime_.opcUaBinaryDecode(is);
		endTime_.opcUaBinaryDecode(is);
		OpcUaNumber::opcUaBinaryDecode(is, resampleInterval_);
		aggregateTypeArraySPtr_->opcUaBinaryDecode(is);
		aggregateConfiguration_.opcUaBinaryDecode(is);
	}
}
