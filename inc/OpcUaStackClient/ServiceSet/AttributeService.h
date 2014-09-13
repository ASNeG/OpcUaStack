#ifndef __OpcUaStackClient_AttributeService_h__
#define __OpcUaStackClient_AttributeService_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/ServiceSet/ServiceTransactionIf.h"
#include "OpcUaStackClient/ServiceSet/Session.h"
#include "OpcUaStackClient/ServiceSet/ServiceTransactionRead.h"

namespace OpcUaStackClient
{

	class DLLEXPORT AttributeService : public ServiceTransactionIf
	{
	  public:
		AttributeService(void);
		~AttributeService(void);

		void session(Session::SPtr session);

		void send(boost::shared_ptr<ServiceTransactionRead> serviceTransactionRead);

		//- ServiceTransactionIf ------------------------------------------------------
		void receive(OpcUaNodeId& typeId, ServiceTransaction::SPtr serviceTransaction);
		//- ServiceTransactionIf ------------------------------------------------------

	  private:
		Session::SPtr session_;
	};

}

#endif
