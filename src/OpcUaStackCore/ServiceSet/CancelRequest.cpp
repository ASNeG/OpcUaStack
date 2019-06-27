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

#include "OpcUaStackCore/ServiceSet/CancelRequest.h"

namespace OpcUaStackCore
{

	CancelRequest::CancelRequest(void)
	: requestHeaderSPtr_(constructSPtr<RequestHeader>())
	, requestHandle_()
	{
	}

	CancelRequest::~CancelRequest(void)
	{
	}

	void 
	CancelRequest::requestHeader(const RequestHeader::SPtr requestHeaderSPtr)
	{
		requestHeaderSPtr_ = requestHeaderSPtr;
	}

	RequestHeader::SPtr
	CancelRequest::requestHeader(void) const
	{
		return requestHeaderSPtr_;
	}

	void 
	CancelRequest::requestHandle(const IntegerId requestHandle)
	{
		requestHandle_ = requestHandle;
	}

	IntegerId 
	CancelRequest::requestHandle(void) const
	{
		return requestHandle_;
	}

	void 
	CancelRequest::opcUaBinaryEncode(std::ostream& os) const
	{
		//requestHeaderSPtr_->opcUaBinaryEncode(os);
		OpcUaNumber::opcUaBinaryEncode(os, requestHandle_);
	}

	void 
	CancelRequest::opcUaBinaryDecode(std::istream& is)
	{
		//requestHeaderSPtr_->opcUaBinaryDecode(is);
		OpcUaNumber::opcUaBinaryDecode(is, requestHandle_);
	}

}
