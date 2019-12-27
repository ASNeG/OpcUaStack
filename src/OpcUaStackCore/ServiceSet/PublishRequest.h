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

#ifndef __OpcUaStackCore_PublishRequest_h__
#define __OpcUaStackCore_PublishRequest_h__

#include <stdint.h>
#include "OpcUaStackCore/ServiceSet/SubscriptionAcknowledgement.h"

namespace OpcUaStackCore
{

	class DLLEXPORT PublishRequest
	: public  Object
	{
	  public:
		typedef boost::shared_ptr<PublishRequest> SPtr;

		PublishRequest(void);
		virtual ~PublishRequest(void);

		void subscriptionAcknowledgements(const SubscriptionAcknowledgementArray::SPtr subscriptionAcknowledgements);
		SubscriptionAcknowledgementArray::SPtr subscriptionAcknowledgements(void) const;

		bool opcUaBinaryEncode(std::ostream& os) const;
		bool opcUaBinaryDecode(std::istream& is);

	  private:
		SubscriptionAcknowledgementArray::SPtr subscriptionAcknowledgementArraySPtr_;
	};

}

#endif
