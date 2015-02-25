#ifndef __OpcUaStackClient_QueryService_h__
#define __OpcUaStackClient_QueryService_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Component/Component.h"
#include "OpcUaStackCore/ServiceSet/QueryServiceTransaction.h"
#include "OpcUaStackClient/ServiceSet/Session.h"

using namespace OpcUaStackCore;

namespace OpcUaStackClient 
{

	class DLLEXPORT QueryServiceIf
	{
	  public:
        virtual void queryServiceQueryFirstResponse(ServiceTransactionQueryFirst::SPtr serviceTransactionQueryFirst) {};
        virtual void queryServiceQueryNextResponse(ServiceTransactionQueryNext::SPtr serviceTransactionQueryNext) {};
	};

	class DLLEXPORT QueryService : public Component
	{
	  public:
		boost::shared_ptr<QueryService> SPtr;

		QueryService(void);
		~QueryService(void);

		void componentSession(Component* componentSession);
		void queryServiceIf(QueryServiceIf* queryServiceIf);

		void sendSync(ServiceTransactionQueryFirst::SPtr serviceTransactionQueryFirst);
		void send(ServiceTransactionQueryFirst::SPtr serviceTransactionQueryFirst);
		void sendSync(ServiceTransactionQueryNext::SPtr serviceTransactionQueryNext);
		void send(ServiceTransactionQueryNext::SPtr serviceTransactionQueryNext);

		//- Component -----------------------------------------------------------------
		void receive(OpcUaNodeId& typeId, Message::SPtr message);
		//- Component -----------------------------------------------------------------

	  private:
		Component* componentSession_;

		QueryServiceIf* queryServiceIf_;
	};

}

#endif
