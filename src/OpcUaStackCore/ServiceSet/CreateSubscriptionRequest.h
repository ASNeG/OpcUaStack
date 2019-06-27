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

#ifndef __OpcUaStackCore_CreateSubscriptionRequest_h__
#define __OpcUaStackCore_CreateSubscriptionRequest_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/SecureChannel/RequestHeader.h"

namespace OpcUaStackCore
{

	class DLLEXPORT CreateSubscriptionRequest
	: public  Object
	{
	  public:
		typedef boost::shared_ptr<CreateSubscriptionRequest> SPtr;

		CreateSubscriptionRequest(void);
		virtual ~CreateSubscriptionRequest(void);

		void requestedPublishingInterval(const OpcUaDouble& requestedPublishingInterval);
		OpcUaDouble requestedPublishingInterval(void) const;
		void requestedLifetimeCount(const OpcUaUInt32& requestedLifetimeCount);
		OpcUaUInt32 requestedLifetimeCount(void) const;
		void requestedMaxKeepAliveCount(const OpcUaUInt32& requestedMaxKeepAliveCount);
		OpcUaUInt32 requestedMaxKeepAliveCount(void) const;
		void maxNotificationsPerPublish(const OpcUaUInt32& maxNotificationsPerPublish);
		OpcUaUInt32 maxNotificationsPerPublish(void) const;
		void publishingEnabled(const OpcUaBoolean& publishingEnabled);
		OpcUaBoolean publishingEnabled(void) const;
		void priority(const OpcUaByte& priority);
		OpcUaByte priority(void) const;

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		OpcUaDouble requestedPublishingInterval_;
		OpcUaUInt32 requestedLifetimeCount_;
		OpcUaUInt32 requestedMaxKeepAliveCount_;
		OpcUaUInt32 maxNotificationsPerPublish_;
		OpcUaBoolean publishingEnabled_;
		OpcUaByte priority_;
	};

}

#endif
