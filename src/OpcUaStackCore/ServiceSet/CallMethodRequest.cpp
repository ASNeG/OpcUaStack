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
	, objectIdSPtr_(boost::make_shared<OpcUaNodeId>())
	, methodIdSPtr_(boost::make_shared<OpcUaNodeId>())
	, inputArgumentArraySPtr_(boost::make_shared<OpcUaVariantArray>())
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

	bool
	CallMethodRequest::opcUaBinaryEncode(std::ostream& os) const
	{
		bool rc = true;

		rc &= objectIdSPtr_->opcUaBinaryEncode(os);
		rc &= methodIdSPtr_->opcUaBinaryEncode(os);
		rc &= inputArgumentArraySPtr_->opcUaBinaryEncode(os);

		return rc;
	}
	
	bool
	CallMethodRequest::opcUaBinaryDecode(std::istream& is)
	{
		bool rc = true;

		rc &= objectIdSPtr_->opcUaBinaryDecode(is);
		rc &= methodIdSPtr_->opcUaBinaryDecode(is);
		rc &= inputArgumentArraySPtr_->opcUaBinaryDecode(is);

		return rc;
	}

	bool
	CallMethodRequest::jsonEncodeImpl(boost::property_tree::ptree &pt) const
	{
		bool rc = true;
		rc = rc & jsonObjectSPtrEncode(pt, objectIdSPtr_, "ObjectId");
        rc = rc & jsonObjectSPtrEncode(pt, methodIdSPtr_, "MethodId");
        rc = rc & jsonArraySPtrEncode(pt, inputArgumentArraySPtr_, "InputArguments", true);
		return rc;
	}

	bool
	CallMethodRequest::jsonDecodeImpl(const boost::property_tree::ptree &pt)
	{
		bool rc = true;
		rc = rc & jsonObjectSPtrDecode(pt, objectIdSPtr_, "ObjectId");
		rc = rc & jsonObjectSPtrDecode(pt, methodIdSPtr_, "MethodId");
		rc = rc & jsonArraySPtrDecode(pt, inputArgumentArraySPtr_, "InputArguments", true);
		return rc;
	}
}
