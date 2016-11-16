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

#ifndef __OpcUaStackCore_CreateSubscriptionResponse_h__
#define __OpcUaStackCore_CreateSubscriptionResponse_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/SecureChannel/ResponseHeader.h"

namespace OpcUaStackCore
{

	class DLLEXPORT CreateSubscriptionResponse
	: public  Object
	{
	  public:
		typedef boost::shared_ptr<CreateSubscriptionResponse> SPtr;

		CreateSubscriptionResponse(void);
		virtual ~CreateSubscriptionResponse(void);

		void subscriptionId(const OpcUaUInt32& subscriptionId);
		OpcUaUInt32 subscriptionId(void) const;
		void revisedPublishingInterval(const OpcUaDouble& revisedPublishingInterval);
		OpcUaDouble revisedPublishingInterval(void) const;
		void revisedLifetimeCount(const OpcUaUInt32& revisedLifetimeCount);
		OpcUaUInt32 revisedLifetimeCount(void) const;
		void revisedMaxKeepAliveCount(const OpcUaUInt32& revisedMaxKeepAliveCount);
		OpcUaUInt32 revisedMaxKeepAliveCount(void) const;

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		OpcUaUInt32 subscriptionId_;
		OpcUaDouble revisedPublishingInterval_;
		OpcUaUInt32 revisedLifetimeCount_;
		OpcUaUInt32 revisedMaxKeepAliveCount_;
	};

}

#endif
