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

#include "OpcUaStackCore/ServiceSet/ReadRawModifiedDetails.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa ReadRawModifiedDetails
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	ReadRawModifiedDetails::ReadRawModifiedDetails(void)
	: Object()
	, isReadModified_(false)
	, startTime_()
	, endTime_()
	, numValuesPerNode_(0)
	, returnBoolean_(true)
	{
	}

	ReadRawModifiedDetails::~ReadRawModifiedDetails(void)
	{
	}

	void 
	ReadRawModifiedDetails::isReadModified(const OpcUaBoolean& isReadModified)
	{
		isReadModified_ = isReadModified;
	}
	
	OpcUaBoolean 
	ReadRawModifiedDetails::isReadModified(void)
	{
		return isReadModified_;
	}
	
	void 
	ReadRawModifiedDetails::startTime(const UtcTime& startTime)
	{
		startTime_ = startTime;
	}
	
	void 
	ReadRawModifiedDetails::startTime(const boost::posix_time::ptime& startTime)
	{
		startTime_.dateTime(startTime);
	}
	
	UtcTime& 
	ReadRawModifiedDetails::startTime(void)
	{
		return startTime_;
	}
	
	void 
	ReadRawModifiedDetails::endTime(const UtcTime& endTime)
	{
		endTime_ = endTime;
	}

	void 
	ReadRawModifiedDetails::endTime(const boost::posix_time::ptime& endTime)
	{
		endTime_.dateTime(endTime);
	}
	
	UtcTime& 
	ReadRawModifiedDetails::endTime(void)
	{
		return endTime_;
	}

		void 
	ReadRawModifiedDetails::numValuesPerNode(const OpcUaUInt32& numValuesPerNode)
	{
		numValuesPerNode_ = numValuesPerNode;
	}
	
	OpcUaUInt32 
	ReadRawModifiedDetails::numValuesPerNode(void) const
	{
		return numValuesPerNode_;
	}

	void 
	ReadRawModifiedDetails::returnBoolean(const OpcUaBoolean& returnBoolean)
	{
		returnBoolean_ = returnBoolean;
	}
		
	OpcUaBoolean 
	ReadRawModifiedDetails::returnBoolean(void)
	{
		return returnBoolean_;
	}

	ExtensibleParameterBase::SPtr
	ReadRawModifiedDetails::factory(void)
	{
		return constructSPtr<ReadRawModifiedDetails>();
	}

	void 
	ReadRawModifiedDetails::opcUaBinaryEncode(std::ostream& os) const
	{
		OpcUaNumber::opcUaBinaryEncode(os, isReadModified_);
		startTime_.opcUaBinaryEncode(os);
		endTime_.opcUaBinaryEncode(os);
		OpcUaNumber::opcUaBinaryEncode(os, numValuesPerNode_);
		OpcUaNumber::opcUaBinaryEncode(os, returnBoolean_);
	}
	
	void 
	ReadRawModifiedDetails::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaNumber::opcUaBinaryDecode(is, isReadModified_);
		startTime_.opcUaBinaryDecode(is);
		endTime_.opcUaBinaryDecode(is);
		OpcUaNumber::opcUaBinaryDecode(is, numValuesPerNode_);
		OpcUaNumber::opcUaBinaryDecode(is, returnBoolean_);
	}
}
