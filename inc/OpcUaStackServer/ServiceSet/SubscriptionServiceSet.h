#ifndef __OpcUaStackServer_SubscriptionServiceSet_h__
#define __OpcUaStackServer_SubscriptionServiceSet_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/ServiceSet/ServiceTransactionIf.h"

namespace OpcUaStackServer
{

	class DLLEXPORT SubscriptionServiceSet : public ServiceTransactionIf
	{
	  public:
		SubscriptionServiceSet(void);
		~SubscriptionServiceSet(void);

		//- ServiceTransactionIf ------------------------------------------------------
		void receive(OpcUaNodeId& typeId, ServiceTransaction::SPtr serviceTransaction);
		//- ServiceTransactionIf ------------------------------------------------------

	  private:
	};

}

#endif