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

#include "OpcUaStackCore/ServiceSet/ReadRequest.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa ReadRequest
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	ReadRequest::ReadRequest(void)
	: Object()
	, maxAge_()
	, timestampsToReturn_()
	, readValueIdArraySPtr_(constructSPtr<ReadValueIdArray>())
	{
	}

	ReadRequest::~ReadRequest(void)
	{
	}

	void 
	ReadRequest::maxAge(const OpcUaDouble& maxAge)
	{
		maxAge_ = maxAge;
	}
	
	OpcUaDouble 
	ReadRequest::maxAge(void) const
	{
		return maxAge_;
	}
	
	void 
	ReadRequest::timestampsToReturn(const OpcUaInt32& timestampsToReturn)
	{
		timestampsToReturn_ = timestampsToReturn;
	}
	
	OpcUaInt32 
	ReadRequest::timestampsToReturn(void) const
	{
		return timestampsToReturn_;
	}
	
	void 
	ReadRequest::readValueIdArray(const ReadValueIdArray::SPtr readValueIdArraySPtr)
	{
		readValueIdArraySPtr_ = readValueIdArraySPtr;
	}
	
	ReadValueIdArray::SPtr 
	ReadRequest::readValueIdArray(void) const
	{
		return readValueIdArraySPtr_;
	}

	bool
	ReadRequest::opcUaBinaryEncode(std::ostream& os) const
	{
		OpcUaNumber::opcUaBinaryEncode(os, maxAge_);
		OpcUaNumber::opcUaBinaryEncode(os, timestampsToReturn_);
		readValueIdArraySPtr_->opcUaBinaryEncode(os);
		return true;
	}
	
	bool 
	ReadRequest::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaNumber::opcUaBinaryDecode(is, maxAge_);
		OpcUaNumber::opcUaBinaryDecode(is, timestampsToReturn_);
		readValueIdArraySPtr_->opcUaBinaryDecode(is);
		return true;
	}

}
