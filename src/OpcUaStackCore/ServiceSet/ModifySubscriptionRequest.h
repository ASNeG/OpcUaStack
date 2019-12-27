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

#ifndef __OpcUaStackCore_ModifySubscriptionRequest_h__
#define __OpcUaStackCore_ModifySubscriptionRequest_h__

#include <stdint.h>
#include "OpcUaStackCore/BuildInTypes/OpcUaNumber.h"

namespace OpcUaStackCore
{

	class DLLEXPORT ModifySubscriptionRequest
	: public Object
	{
	  public:
		typedef boost::shared_ptr<ModifySubscriptionRequest> SPtr;

		ModifySubscriptionRequest(void);
		virtual ~ModifySubscriptionRequest(void);

		void subscriptionId(const OpcUaUInt32& subscriptionId);
		OpcUaUInt32 subscriptionId(void) const;
		void requestedPublishingInterval(const OpcUaDouble& requestedPublishingInterval);
		OpcUaDouble requestedPublishingInterval(void) const;
		void requestedLifetimeCount(const OpcUaUInt32& requestedLifetimeCount);
		OpcUaUInt32 requestedLifetimeCount(void) const;
		void requestedMaxKeepAliveCount(const OpcUaUInt32& requestedMaxKeepAliveCount);
		OpcUaUInt32 requestedMaxKeepAliveCount(void) const;
		void maxNotificationsPerPublish(const OpcUaUInt32& maxNotificationsPerPublish);
		OpcUaUInt32 maxNotificationsPerPublish(void) const;
		void priority(const OpcUaByte& priority);
		OpcUaByte priority(void) const;

		bool opcUaBinaryEncode(std::ostream& os) const;
		bool opcUaBinaryDecode(std::istream& is);

	  private:
		OpcUaUInt32 subscriptionId_;
		OpcUaDouble requestedPublishingInterval_;
		OpcUaUInt32 requestedLifetimeCount_;
		OpcUaUInt32 requestedMaxKeepAliveCount_;
		OpcUaUInt32 maxNotificationsPerPublish_;
		OpcUaByte priority_;
	};

}

#endif
