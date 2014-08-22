#ifndef __OpcUaStackCore_SubscriptionAcknowledgement_h__
#define __OpcUaStackCore_SubscriptionAcknowledgement_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaArray.h"

namespace OpcUaStackCore
{

	class DLLEXPORT SubscriptionAcknowledgement : public  ObjectPool<SubscriptionAcknowledgement>
	{
	  public:
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

	class SubscriptionAcknowledgementArray : public OpcUaArray<SubscriptionAcknowledgement::SPtr, SPtrTypeCoder<SubscriptionAcknowledgement> >, public ObjectPool<SubscriptionAcknowledgementArray> {};

}

#endif