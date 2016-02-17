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

#include "OpcUaStackCore/ServiceSet/ReadAtTimeDetails.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa ReadAtTimeDetails
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	ReadAtTimeDetails::ReadAtTimeDetails(void)
	: Object()
	, reqTimeArraySPtr_(constructSPtr<UtcTimeArray>())
	{
	}

	ReadAtTimeDetails::~ReadAtTimeDetails(void)
	{
	}

	void 
	ReadAtTimeDetails::reqTimes(const UtcTimeArray::SPtr reqTimes)
	{
		reqTimeArraySPtr_ = reqTimes;
	}
	
	UtcTimeArray::SPtr 
	ReadAtTimeDetails::reqTimes(void) const
	{
		return reqTimeArraySPtr_;
	}

	ExtensibleParameterBase::SPtr
	ReadAtTimeDetails::factory(void)
	{
		return constructSPtr<ReadAtTimeDetails>();
	}

	void 
	ReadAtTimeDetails::opcUaBinaryEncode(std::ostream& os) const
	{
		reqTimeArraySPtr_->opcUaBinaryEncode(os);
	}
	
	void 
	ReadAtTimeDetails::opcUaBinaryDecode(std::istream& is)
	{
		reqTimeArraySPtr_->opcUaBinaryDecode(is);
	}
}
