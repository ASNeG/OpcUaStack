/*
   Copyright 2015-2018 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackCore/Base/Utility.h"
#include "OpcUaStackCore/ServiceSet/ReadEventDetails.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa ReadEventDetails
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	ReadEventDetails::ReadEventDetails(void)
	: Object()
	, ExtensibleParameterBase()
	, numValuesPerNode_()
	, startTime_()
	, endTime_()
	, filterSPtr_(constructSPtr<EventFilter>())
	{
	}

	ReadEventDetails::~ReadEventDetails(void)
	{
	}

	void 
	ReadEventDetails::numValuesPerNode(const OpcUaUInt32& numValuesPerNode)
	{
		numValuesPerNode_ = numValuesPerNode;
	}
	
	OpcUaUInt32 
	ReadEventDetails::numValuesPerNode(void) const
	{
		return numValuesPerNode_;
	}
	
	void 
	ReadEventDetails::startTime(const UtcTime& startTime)
	{
		startTime_ = startTime;
	}
	
	void 
	ReadEventDetails::startTime(const boost::posix_time::ptime& startTime)
	{
		startTime_.dateTime(startTime);
	}
	
	UtcTime& 
	ReadEventDetails::startTime(void)
	{
		return startTime_;
	}
	
	void 
	ReadEventDetails::endTime(const UtcTime& endTime)
	{
		endTime_ = endTime;
	}

	void 
	ReadEventDetails::endTime(const boost::posix_time::ptime& endTime)
	{
		endTime_.dateTime(endTime);
	}
	
	UtcTime& 
	ReadEventDetails::endTime(void)
	{
		return endTime_;
	}

	void 
	ReadEventDetails::filter(const EventFilter::SPtr& filter)
	{
		filterSPtr_ = filter;
	}
	
	EventFilter::SPtr&
	ReadEventDetails::filter(void)
	{
		return filterSPtr_;
	}

	ExtensibleParameterBase::SPtr
	ReadEventDetails::factory(void)
	{
		return constructSPtr<ReadEventDetails>();
	}

	void 
	ReadEventDetails::opcUaBinaryEncode(std::ostream& os) const
	{
		OpcUaNumber::opcUaBinaryEncode(os, numValuesPerNode_);
		startTime_.opcUaBinaryEncode(os);
		endTime_.opcUaBinaryEncode(os);
		filterSPtr_->opcUaBinaryEncode(os);
	}
	
	void 
	ReadEventDetails::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaNumber::opcUaBinaryDecode(is, numValuesPerNode_);
		startTime_.opcUaBinaryDecode(is);
		endTime_.opcUaBinaryDecode(is);
		filterSPtr_->opcUaBinaryDecode(is);
	}
}
