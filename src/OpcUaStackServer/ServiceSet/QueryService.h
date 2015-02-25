#ifndef __OpcUaStackServer_QueryService_h__
#define __OpcUaStackServer_QueryService_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/ServiceSet/QueryServiceTransaction.h"
#include "OpcUaStackServer/ServiceSet/ServiceSetBase.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	class DLLEXPORT QueryService 
	: public ServiceSetBase
	, public ObjectPool<QueryService>
	{
	  public:
		typedef boost::shared_ptr<QueryService> SPtr;

		QueryService(void);
		~QueryService(void);

		//- Component -----------------------------------------------------------------
		void receive(OpcUaNodeId& typeId, Message::SPtr message);
		//- Component -----------------------------------------------------------------

	  private:
		void receiveQueryFirstRequest(OpcUaNodeId& typeId, ServiceTransaction::SPtr serviceTransaction);
		void receiveQueryNextRequest(OpcUaNodeId& typeId, ServiceTransaction::SPtr serviceTransaction);
	};

}

#endif