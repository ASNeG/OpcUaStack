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

#include "OpcUaStackCore/ServiceSet/DeleteSubscriptionsRequest.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa DeleteSubscriptionsRequest
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	DeleteSubscriptionsRequest::DeleteSubscriptionsRequest(void)
	: Object()
	, subscriptionIdArraySPtr_(boost::make_shared<OpcUaUInt32Array>())
	{
	}

	DeleteSubscriptionsRequest::~DeleteSubscriptionsRequest(void)
	{
	}
	
	void 
	DeleteSubscriptionsRequest::subscriptionIds(const OpcUaUInt32Array::SPtr subscriptionIds)
	{
		subscriptionIdArraySPtr_ = subscriptionIds;
	}
	
	OpcUaUInt32Array::SPtr 
	DeleteSubscriptionsRequest::subscriptionIds(void) const
	{
		return subscriptionIdArraySPtr_;
	}

	bool
	DeleteSubscriptionsRequest::opcUaBinaryEncode(std::ostream& os) const
	{
		return subscriptionIdArraySPtr_->opcUaBinaryEncode(os);
	}
	
	bool
	DeleteSubscriptionsRequest::opcUaBinaryDecode(std::istream& is)
	{
		return subscriptionIdArraySPtr_->opcUaBinaryDecode(is);
	}

	bool
	DeleteSubscriptionsRequest::jsonEncodeImpl(boost::property_tree::ptree& pt) const
	{
		return jsonArraySPtrEncode(pt, subscriptionIdArraySPtr_, "SubscriptionIds");
	}

	bool
	DeleteSubscriptionsRequest::jsonDecodeImpl(const boost::property_tree::ptree& pt)
	{
		return jsonArraySPtrDecode(pt, subscriptionIdArraySPtr_, "SubscriptionIds");
	}

}
