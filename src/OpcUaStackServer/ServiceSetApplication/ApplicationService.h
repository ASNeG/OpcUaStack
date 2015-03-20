#ifndef __OpcUaStackServer_ApplicationService_h__
#define __OpcUaStackServer_ApplicationService_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackServer/ServiceSet/ServiceSetBase.h"
#include "OpcUaStackCore/ServiceSet/ServiceTransactionIf.h"
#include "OpcUaStackCore/ServiceSetApplication/ApplicationServiceTransaction.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	class DLLEXPORT ApplicationService
	: public ServiceSetBase
	, public ObjectPool<ApplicationService>
	{
	  public:
		typedef boost::shared_ptr<ApplicationService> SPtr;

		ApplicationService(void);
		~ApplicationService(void);

		//- Component -----------------------------------------------------------------
		void receive(Message::SPtr message);
		//- Component -----------------------------------------------------------------

	  private:
		void receiveRegisterForwardRequest(ServiceTransaction::SPtr serviceTransaction);
	};

}

#endif
