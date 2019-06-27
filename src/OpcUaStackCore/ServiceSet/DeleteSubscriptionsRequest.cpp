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
	, subscriptionIdArraySPtr_(constructSPtr<OpcUaUInt32Array>())
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

	void 
	DeleteSubscriptionsRequest::opcUaBinaryEncode(std::ostream& os) const
	{
		subscriptionIdArraySPtr_->opcUaBinaryEncode(os);
	}
	
	void 
	DeleteSubscriptionsRequest::opcUaBinaryDecode(std::istream& is)
	{
		subscriptionIdArraySPtr_->opcUaBinaryDecode(is);
	}
}
