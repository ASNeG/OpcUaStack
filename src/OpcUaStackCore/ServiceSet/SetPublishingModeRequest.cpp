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

#include "OpcUaStackCore/ServiceSet/SetPublishingModeRequest.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa SetPublishingModeRequest
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	SetPublishingModeRequest::SetPublishingModeRequest(void)
	: Object()
	, publishingEnabled_()
	, subscriptionIdArraySPtr_(boost::make_shared<OpcUaUInt32Array>())
	{
	}

	SetPublishingModeRequest::~SetPublishingModeRequest(void)
	{
	}

	void 
	SetPublishingModeRequest::publishingEnabled(const OpcUaBoolean& publishingEnabled)
	{
		publishingEnabled_ = publishingEnabled;
	}

	OpcUaBoolean 
	SetPublishingModeRequest::publishingEnabled(void) const
	{
		return publishingEnabled_;
	}
	
	void 
	SetPublishingModeRequest::subscriptionIds(const OpcUaUInt32Array::SPtr subscriptionIds)
	{
		subscriptionIdArraySPtr_ = subscriptionIds;
	}
	
	OpcUaUInt32Array::SPtr 
	SetPublishingModeRequest::subscriptionIds(void) const
	{
		return subscriptionIdArraySPtr_;
	}

	bool
	SetPublishingModeRequest::opcUaBinaryEncode(std::ostream& os) const
	{
		bool rc = true;

		rc &= OpcUaNumber::opcUaBinaryEncode(os, publishingEnabled_);
		rc &= subscriptionIdArraySPtr_->opcUaBinaryEncode(os);

		return rc;
	}
	
	bool
	SetPublishingModeRequest::opcUaBinaryDecode(std::istream& is)
	{
		bool rc = true;

		rc &= OpcUaNumber::opcUaBinaryDecode(is, publishingEnabled_);
		rc &= subscriptionIdArraySPtr_->opcUaBinaryDecode(is);

		return rc;
	}
}
