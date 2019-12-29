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

#include "OpcUaStackCore/ServiceSet/CancelRequest.h"

namespace OpcUaStackCore
{

	CancelRequest::CancelRequest(void)
	: requestHeaderSPtr_(boost::make_shared<RequestHeader>())
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
	CancelRequest::requestHandle(const OpcUaIntegerId requestHandle)
	{
		requestHandle_ = requestHandle;
	}

	OpcUaIntegerId
	CancelRequest::requestHandle(void) const
	{
		return requestHandle_;
	}

	bool
	CancelRequest::opcUaBinaryEncode(std::ostream& os) const
	{
		return OpcUaNumber::opcUaBinaryEncode(os, requestHandle_);
	}

	bool
	CancelRequest::opcUaBinaryDecode(std::istream& is)
	{
		return OpcUaNumber::opcUaBinaryDecode(is, requestHandle_);
	}

}
