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

#include "OpcUaStackCore/ServiceSet/ModifySubscriptionResponse.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa ModifySubscriptionResponse
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	ModifySubscriptionResponse::ModifySubscriptionResponse(void)
	: ObjectPool<ModifySubscriptionResponse>()
	, revisedPublishingInterval_()
	, revisedLifetimeCount_()
	, revisedMaxKeepAliveCount_()
	{
	}

	ModifySubscriptionResponse::~ModifySubscriptionResponse(void)
	{
	}

	void 
	ModifySubscriptionResponse::revisedPublishingInterval(const OpcUaDouble& revisedPublishingInterval)
	{
		revisedPublishingInterval_ = revisedPublishingInterval;
	}
	
	OpcUaDouble 
	ModifySubscriptionResponse::revisedPublishingInterval(void) const
	{
		return revisedPublishingInterval_;
	}

	void 
	ModifySubscriptionResponse::revisedLifetimeCount(const OpcUaUInt32& revisedLifetimeCount)
	{
		revisedLifetimeCount_ = revisedLifetimeCount;
	}
	
	OpcUaUInt32 
	ModifySubscriptionResponse::revisedLifetimeCount(void) const
	{
		return revisedLifetimeCount_;
	}
	
	void 
	ModifySubscriptionResponse::revisedMaxKeepAliveCount(const OpcUaUInt32& revisedMaxKeepAliveCount)
	{
		revisedMaxKeepAliveCount_ = revisedMaxKeepAliveCount;
	}
	
	OpcUaUInt32 
	ModifySubscriptionResponse::revisedMaxKeepAliveCount(void) const
	{
		return revisedMaxKeepAliveCount_;
	}

	void 
	ModifySubscriptionResponse::opcUaBinaryEncode(std::ostream& os) const
	{
		OpcUaNumber::opcUaBinaryEncode(os, revisedPublishingInterval_);
		OpcUaNumber::opcUaBinaryEncode(os, revisedLifetimeCount_);
		OpcUaNumber::opcUaBinaryEncode(os, revisedMaxKeepAliveCount_);
	}
	
	void 
	ModifySubscriptionResponse::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaNumber::opcUaBinaryDecode(is, revisedPublishingInterval_);
		OpcUaNumber::opcUaBinaryDecode(is, revisedLifetimeCount_);
		OpcUaNumber::opcUaBinaryDecode(is, revisedMaxKeepAliveCount_);
	}
}
