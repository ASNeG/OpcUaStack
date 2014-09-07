#ifndef __OpcUaStackClient_AttributeService_h__
#define __OpcUaStackClient_AttributeService_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackClient/ServiceSet/Session.h"
#include "OpcUaStackClient/ServiceSet/ServiceTransactionRead.h"
#include "OpcuaStackClient/ServiceSet/ServiceSetIf.h"

namespace OpcUaStackClient
{

	class DLLEXPORT AttributeService : public ServiceSetIf
	{
	  public:
		AttributeService(void);
		~AttributeService(void);

		void session(Session::SPtr session);

		void send(boost::shared_ptr<ServiceTransactionRead> serviceTransactionRead);

		//- ServiceSetIf ------------------------------------------------------
		void serviceSetIf(OpcUaNodeId& typeId, ServiceTransaction::SPtr serviceTransaction);
		//- ServiceSetIf ------------------------------------------------------

	  private:
		Session::SPtr session_;
	};

}

#endif