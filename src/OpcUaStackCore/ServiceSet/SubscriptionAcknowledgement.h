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

#ifndef __OpcUaStackCore_SubscriptionAcknowledgement_h__
#define __OpcUaStackCore_SubscriptionAcknowledgement_h__

#include <stdint.h>
#include "OpcUaStackCore/BuildInTypes/OpcUaNumber.h"

namespace OpcUaStackCore
{

	class DLLEXPORT SubscriptionAcknowledgement
	: public  Object
	{
	  public:
		typedef boost::shared_ptr<SubscriptionAcknowledgement> SPtr;

		SubscriptionAcknowledgement(void);
		virtual ~SubscriptionAcknowledgement(void);

		void subscriptionId(const OpcUaUInt32& subscriptionId);
		OpcUaUInt32 subscriptionId(void) const;
		void sequenceNumber(const OpcUaUInt32& sequenceNumber);
		OpcUaUInt32 sequenceNumber(void) const;
		
		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		OpcUaUInt32 subscriptionId_;
		OpcUaUInt32 sequenceNumber_;

	};

	class DLLEXPORT SubscriptionAcknowledgementArray
	: public OpcUaArray<SubscriptionAcknowledgement::SPtr, SPtrTypeCoder<SubscriptionAcknowledgement> >
	, public Object
	{
	  public:
		typedef boost::shared_ptr<SubscriptionAcknowledgementArray> SPtr;
	};

}

#endif
