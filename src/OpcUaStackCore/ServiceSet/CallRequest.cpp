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
	, requestHeaderSPtr_(constructSPtr<RequestHeader>())
	, callMethodRequestArraySPtr_(constructSPtr<CallMethodRequestArray>())
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
	
	void 
	CallRequest::opcUaBinaryEncode(std::ostream& os) const
	{
		callMethodRequestArraySPtr_->opcUaBinaryEncode(os);
	}
	
	void 
	CallRequest::opcUaBinaryDecode(std::istream& is)
	{
		callMethodRequestArraySPtr_->opcUaBinaryDecode(is);
	}

	bool
	CallRequest::jsonEncode(boost::property_tree::ptree& pt, const std::string& element)
	{
		boost::property_tree::ptree elementTree;
		if (!jsonEncode(elementTree)) {
			Log(Error, "CallRequest json encoder error")
				.parameter("Element", element);
			return false;
		}
		pt.push_back(std::make_pair(element, elementTree));
		return true;
	}

	bool
	CallRequest::jsonEncode(boost::property_tree::ptree& pt)
	{
		// encode method requests
		if (!callMethodRequestArraySPtr_->jsonEncode(pt, "MethodsToCall", "")) {
			Log(Error, "CallRequest json encode error")
				.parameter("Element", "MethodsToCall");
			return false;
		}

		return true;
	}

	bool
	CallRequest::jsonDecode(boost::property_tree::ptree& pt, const std::string& element)
	{
		boost::optional<boost::property_tree::ptree&> tmpTree;

		tmpTree = pt.get_child_optional(element);
		if (!tmpTree) {
			Log(Error, "CallRequest json decoder error")
				.parameter("Element", element);
				return false;
		}
		return jsonDecode(*tmpTree);
	}

	bool
	CallRequest::jsonDecode(boost::property_tree::ptree& pt)
	{
		// decode method requests
		if (!callMethodRequestArraySPtr_->jsonDecode(pt, "MethodsToCall", "")) {
			Log(Error, "CallRequest json decode error")
			    .parameter("Element", "MethodsToCall");
			return false;
		}

		return true;
	}

}
