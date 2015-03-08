#ifndef __OpcUaStackServer_AttributeService_h__
#define __OpcUaStackServer_AttributeService_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackServer/ServiceSet/ServiceSetBase.h"
#include "OpcUaStackCore/ServiceSet/ServiceTransactionIf.h"
#include "OpcUaStackCore/ServiceSet/AttributeServiceTransaction.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	class DLLEXPORT AttributeService 
	: public ServiceSetBase
	, public ObjectPool<AttributeService>
	{
	  public:
		typedef boost::shared_ptr<AttributeService> SPtr;

		AttributeService(void);
		~AttributeService(void);

		//- Component -----------------------------------------------------------------
		void receive(Message::SPtr message);
		//- Component -----------------------------------------------------------------

	  private:
		void receiveReadRequest(ServiceTransaction::SPtr serviceTransaction);
		void receiveWriteRequest(ServiceTransaction::SPtr serviceTransaction);
		void receiveHistoryReadRequest(ServiceTransaction::SPtr serviceTransaction);
		void receiveHistoryUpdateRequest(ServiceTransaction::SPtr serviceTransaction);
	};

}

#endif
