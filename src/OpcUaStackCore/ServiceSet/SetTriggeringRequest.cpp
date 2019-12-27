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

#include "OpcUaStackCore/ServiceSet/SetTriggeringRequest.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa SetTriggeringRequest
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	SetTriggeringRequest::SetTriggeringRequest(void)
	: Object()
	, subscriptionId_()
	, triggeringItemId_()
	, linksToAddArraySPtr_(boost::make_shared<OpcUaUInt32Array>())
	, linksToRemoveArraySPtr_(boost::make_shared<OpcUaUInt32Array>())
	{
	}

	SetTriggeringRequest::~SetTriggeringRequest(void)
	{
	}
	
	void 
	SetTriggeringRequest::subscriptionId(const OpcUaUInt32& subscriptionId)
	{
		subscriptionId_ = subscriptionId;
	}
	
	OpcUaUInt32
	SetTriggeringRequest::subscriptionId(void) const
	{
		return subscriptionId_;
	}
	
	void 
	SetTriggeringRequest::triggeringItemId(const OpcUaUInt32& triggeringItemId)
	{
		triggeringItemId_ = triggeringItemId;
	}
	
	OpcUaUInt32 
	SetTriggeringRequest::triggeringItemId(void) const
	{
		return triggeringItemId_;
	}
	
	void 
	SetTriggeringRequest::linksToAdd(const OpcUaUInt32Array::SPtr linksToAdd)
	{
		linksToAddArraySPtr_ = linksToAdd;
	}
	
	OpcUaUInt32Array::SPtr 
	SetTriggeringRequest::linksToAdd(void) const
	{
		return linksToAddArraySPtr_;
	}
	
	void 
	SetTriggeringRequest::linksToRemove(const OpcUaUInt32Array::SPtr linksToRemove)
	{
		linksToRemoveArraySPtr_ = linksToRemove;
	}
	
	OpcUaUInt32Array::SPtr 
	SetTriggeringRequest::linksToRemove(void) const
	{
		return linksToRemoveArraySPtr_;
	}
	
	bool
	SetTriggeringRequest::opcUaBinaryEncode(std::ostream& os) const
	{
		bool rc = true;

		rc &= OpcUaNumber::opcUaBinaryEncode(os, subscriptionId_);
		rc &= OpcUaNumber::opcUaBinaryEncode(os, triggeringItemId_);
		rc &= linksToAddArraySPtr_->opcUaBinaryEncode(os);
		rc &= linksToRemoveArraySPtr_->opcUaBinaryEncode(os);

		return rc;
	}
	
	bool
	SetTriggeringRequest::opcUaBinaryDecode(std::istream& is)
	{
		bool rc = true;

		rc &= OpcUaNumber::opcUaBinaryDecode(is, subscriptionId_);
		rc &= OpcUaNumber::opcUaBinaryDecode(is, triggeringItemId_);
		rc &= linksToAddArraySPtr_->opcUaBinaryDecode(is);
		rc &= linksToRemoveArraySPtr_->opcUaBinaryDecode(is);

		return rc;
	}
}
