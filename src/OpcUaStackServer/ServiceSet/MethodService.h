#ifndef __OpcUaStackServer_MethodService_h__
#define __OpcUaStackServer_MethodService_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/ServiceSet/MethodServiceTransaction.h"
#include "OpcUaStackServer/ServiceSet/ServiceSetBase.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	class DLLEXPORT MethodService 
	: public ServiceSetBase
	, public ObjectPool<MethodService>
	{
	  public:
		typedef boost::shared_ptr<MethodService> SPtr;

		MethodService(void);
		~MethodService(void);

		//- Component -----------------------------------------------------------------
		void receive(Message::SPtr message);
		//- Component -----------------------------------------------------------------

	  private:
		void receiveCallRequest(ServiceTransaction::SPtr serviceTransaction);
	};

}

#endif
