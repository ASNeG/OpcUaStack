#ifndef __OpcUaStackServer_TransactionManager_h__
#define __OpcUaStackServer_TransactionManager_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/ServiceSet/ServiceTransaction.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	class DLLEXPORT TransactionManager : public ObjectPool<TransactionManager>
	{
	  public:
		typedef boost::shared_ptr<TransactionManager> SPtr;

		TransactionManager(void);
		~TransactionManager(void);

		bool registerTransaction(ServiceTransaction::SPtr serviceTransactionSPtr);
		ServiceTransaction::SPtr getTransaction(OpcUaNodeId& typeId);

	  private:
		typedef std::map<OpcUaNodeId, ServiceTransaction::SPtr> ServiceTransactionMap;
		ServiceTransactionMap serviceTransactionMap_;
	};

}

#endif