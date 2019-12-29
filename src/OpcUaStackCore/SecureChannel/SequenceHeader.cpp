/*
   Copyright 2015-2019 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackCore/SecureChannel/SequenceHeader.h"

namespace OpcUaStackCore
{

	SequenceHeader::SequenceHeader(void)
	: sequenceNumber_(0)
	, requestId_(0)
	{
	}
		
	SequenceHeader::~SequenceHeader(void)
	{
	}

	void 
	SequenceHeader::sequenceNumber(const OpcUaUInt32& sequenceNumber)
	{
		sequenceNumber_ = sequenceNumber;
	}
		
	OpcUaUInt32  
	SequenceHeader::sequenceNumber(void) const
	{
		return sequenceNumber_;
	}

	void
	SequenceHeader::incSequenceNumber(void)
	{
		sequenceNumber_++;
	}
		
	void  
	SequenceHeader::requestId(const OpcUaUInt32& requestId)
	{
		requestId_ = requestId;
	}
		
	OpcUaUInt32  
	SequenceHeader::requestId(void) const
	{
		return requestId_;
	}

	void
	SequenceHeader::incRequestId(void)
	{
		requestId_++;
	}

	bool
	SequenceHeader::opcUaBinaryEncode(std::ostream& os) const
	{
		bool rc = true;

		rc &= OpcUaNumber::opcUaBinaryEncode(os, sequenceNumber_);
		rc &= OpcUaNumber::opcUaBinaryEncode(os, requestId_);

		return rc;
	}

	bool
	SequenceHeader::opcUaBinaryDecode(std::istream& is)
	{
		bool rc = true;

		rc &= OpcUaNumber::opcUaBinaryDecode(is, sequenceNumber_);
		rc &= OpcUaNumber::opcUaBinaryDecode(is, requestId_);

		return rc;
	}

}
