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

#include "OpcUaStackCore/ServiceSet/CallMethodRequest.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa CallMethodRequest
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	CallMethodRequest::CallMethodRequest(void)
	: Object()
	, objectIdSPtr_(constructSPtr<OpcUaNodeId>())
	, methodIdSPtr_(constructSPtr<OpcUaNodeId>())
	, inputArgumentArraySPtr_(constructSPtr<OpcUaVariantArray>())
	{
	}

	CallMethodRequest::~CallMethodRequest(void)
	{
	}

	void 
	CallMethodRequest::objectId(const OpcUaNodeId::SPtr objectId)
	{
		objectIdSPtr_ = objectId;
	}
	
	OpcUaNodeId::SPtr 
	CallMethodRequest::objectId(void) const
	{
		return objectIdSPtr_;
	}
	
	void 
	CallMethodRequest::methodId(const OpcUaNodeId::SPtr methodId)
	{
		methodIdSPtr_ = methodId;
	}
	
	OpcUaNodeId::SPtr 
	CallMethodRequest::methodId(void) const
	{
		return methodIdSPtr_;
	}
	
	void 
	CallMethodRequest::inputArguments(const OpcUaVariantArray::SPtr inputArguments)
	{
		inputArgumentArraySPtr_ = inputArguments;
	}
	
	OpcUaVariantArray::SPtr 
	CallMethodRequest::inputArguments(void) const
	{
		return inputArgumentArraySPtr_;
	}

	void
	CallMethodRequest::copyTo(CallMethodRequest& callMethodRequest)
	{
		objectIdSPtr_->copyTo(*callMethodRequest.objectId().get());
		methodIdSPtr_->copyTo(*callMethodRequest.methodId().get());
		inputArgumentArraySPtr_->copyTo(*callMethodRequest.inputArguments().get());
	}

	void 
	CallMethodRequest::opcUaBinaryEncode(std::ostream& os) const
	{
		objectIdSPtr_->opcUaBinaryEncode(os);
		methodIdSPtr_->opcUaBinaryEncode(os);
		inputArgumentArraySPtr_->opcUaBinaryEncode(os);
	}
	
	void 
	CallMethodRequest::opcUaBinaryDecode(std::istream& is)
	{
		objectIdSPtr_->opcUaBinaryDecode(is);
		methodIdSPtr_->opcUaBinaryDecode(is);
		inputArgumentArraySPtr_->opcUaBinaryDecode(is);
	}

	bool
	CallMethodRequest::jsonEncode(boost::property_tree::ptree& pt, const std::string& element)
	{
		boost::property_tree::ptree elementTree;
		if (!jsonEncode(elementTree)) {
			Log(Error, "CallMethodRequest json encoder error")
				.parameter("Element", element);
			return false;
		}
		pt.push_back(std::make_pair(element, elementTree));
		return true;
	}

	bool
	CallMethodRequest::jsonEncode(boost::property_tree::ptree& pt)
	{
		// encode object id
		if (!objectIdSPtr_->jsonEncode(pt, "ObjectId")) {
			Log(Error, "CallMethodRequest json encode error")
			    .parameter("Element", "ObjectId");
			return false;
		}

		// encode method id
		if (!methodIdSPtr_->jsonEncode(pt, "MethodId")) {
			Log(Error, "CallMethodRequest json encode error")
			    .parameter("Element", "MethodId");
			return false;
		}

		// encode input argument array
		if (inputArgumentArraySPtr_->size() != 0) {
			if (!inputArgumentArraySPtr_->jsonEncode(pt, "InputArguments", "")) {
				Log(Error, "CallMethodRequest json encode error")
					.parameter("Element", "InputArguments");
				return false;
			}
		}

		return true;
	}

	bool
	CallMethodRequest::jsonDecode(boost::property_tree::ptree& pt, const std::string& element)
	{
		boost::optional<boost::property_tree::ptree&> tmpTree;

		tmpTree = pt.get_child_optional(element);
		if (!tmpTree) {
			Log(Error, "CallMethodRequest json decoder error")
				.parameter("Element", element);
				return false;
		}
		return jsonDecode(*tmpTree);
	}

	bool
	CallMethodRequest::jsonDecode(boost::property_tree::ptree& pt)
	{
		boost::optional<boost::property_tree::ptree&> tmpTree;

		// decode object id
		if (!objectIdSPtr_->jsonDecode(pt, "ObjectId")) {
			Log(Error, "CallMethodRequest json decode error")
			    .parameter("Element", "ObjectId");
			return false;
		}

		// decode method id
		if (!methodIdSPtr_->jsonDecode(pt, "MethodId")) {
			Log(Error, "CallMethodRequest json decode error")
			    .parameter("Element", "MethodId");
			return false;
		}

		// decode input argument array
		tmpTree = pt.get_child_optional("InputArguments");
		if (tmpTree) {
			if (!inputArgumentArraySPtr_->jsonDecode(pt, "InputArguments", "")) {
				Log(Error, "CallMethodRequest json decode error")
			    	.parameter("Element", "InputArguments");
				return false;
			}
		}

		return true;
	}
}
