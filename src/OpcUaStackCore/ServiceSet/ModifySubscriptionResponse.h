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

#ifndef __OpcUaStackCore_ModifySubscriptionResponse_h__
#define __OpcUaStackCore_ModifySubscriptionResponse_h__

#include <stdint.h>
#include "OpcUaStackCore/BuildInTypes/OpcUaNumber.h"

namespace OpcUaStackCore
{

	class DLLEXPORT ModifySubscriptionResponse
	: public  Object
	{
	  public:
		typedef boost::shared_ptr<ModifySubscriptionResponse> SPtr;

		ModifySubscriptionResponse(void);
		virtual ~ModifySubscriptionResponse(void);

		void revisedPublishingInterval(const OpcUaDouble& revisedPublishingInterval);
		OpcUaDouble revisedPublishingInterval(void) const;
		void revisedLifetimeCount(const OpcUaUInt32& revisedLifetimeCount);
		OpcUaUInt32 revisedLifetimeCount(void) const;
		void revisedMaxKeepAliveCount(const OpcUaUInt32& revisedMaxKeepAliveCount);
		OpcUaUInt32 revisedMaxKeepAliveCount(void) const;

		bool opcUaBinaryEncode(std::ostream& os) const;
		bool opcUaBinaryDecode(std::istream& is);

	  private:
		OpcUaDouble revisedPublishingInterval_;
		OpcUaUInt32 revisedLifetimeCount_;
		OpcUaUInt32 revisedMaxKeepAliveCount_;
	};

}

#endif
