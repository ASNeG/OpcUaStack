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

#include "OpcUaStackCore/ServiceSet/CallRequest.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa CallRequest
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	CallRequest::CallRequest(void)
	: Object()
	, requestHeaderSPtr_(boost::make_shared<RequestHeader>())
	, callMethodRequestArraySPtr_(boost::make_shared<CallMethodRequestArray>())
	{
	}

	CallRequest::~CallRequest(void)
	{
	}

	void 
	CallRequest::requestHeader(const RequestHeader::SPtr requestHeader)
	{
		requestHeaderSPtr_ = requestHeader;
	}

	RequestHeader::SPtr 
	CallRequest::requestHeader(void) const
	{
		return requestHeaderSPtr_;
	}

	void 
	CallRequest::methodsToCall(const CallMethodRequestArray::SPtr methodsToCall)
	{
		callMethodRequestArraySPtr_ = methodsToCall;
	}
	
	CallMethodRequestArray::SPtr 
	CallRequest::methodsToCall(void) const
	{
		return callMethodRequestArraySPtr_;
	}
	
	bool
	CallRequest::opcUaBinaryEncode(std::ostream& os) const
	{
		return callMethodRequestArraySPtr_->opcUaBinaryEncode(os);
	}
	
	bool
	CallRequest::opcUaBinaryDecode(std::istream& is)
	{
		return callMethodRequestArraySPtr_->opcUaBinaryDecode(is);
	}

	bool
	CallRequest::jsonEncodeImpl(boost::property_tree::ptree &pt) const
	{
		return jsonArraySPtrEncode(pt, callMethodRequestArraySPtr_, "MethodsToCall");
	}

	bool
	CallRequest::jsonDecodeImpl(const boost::property_tree::ptree &pt)
	{
		return jsonArraySPtrDecode(pt, callMethodRequestArraySPtr_, "MethodsToCall");
	}

}
