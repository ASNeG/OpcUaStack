#ifndef __OpcUaStackClient_MethodService_h__
#define __OpcUaStackClient_MethodService_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Component/Component.h"
#include "OpcUaStackCore/ServiceSet/MethodServiceTransaction.h"
#include "OpcUaStackClient/ServiceSet/Session.h"

using namespace OpcUaStackCore;

namespace OpcUaStackClient 
{

	class DLLEXPORT MethodServiceIf
	{
	  public:
		virtual ~MethodServiceIf(void) {}

        virtual void methodServiceCallResponse(ServiceTransactionCall::SPtr serviceTransactionCall) {};
	};

	class DLLEXPORT MethodService
	: public Component
	{
	  public:
		boost::shared_ptr<MethodService> SPtr;

		MethodService(void);
		~MethodService(void);

		void componentSession(Component* componentSession);
		void methodServiceIf(MethodServiceIf* methodServiceIf);

		void sendSync(ServiceTransactionCall::SPtr serviceTransactionRead);
		void send(ServiceTransactionCall::SPtr serviceTransactionRead);

		//- Component -----------------------------------------------------------------
		void receive(OpcUaNodeId& typeId, Message::SPtr message);
		//- Component -----------------------------------------------------------------

	  private:
		Component* componentSession_;

		MethodServiceIf* methodServiceIf_;
	};

}

#endif
