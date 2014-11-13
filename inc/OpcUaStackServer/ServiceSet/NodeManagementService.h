#ifndef __OpcUaStackServer_NodeManagementService_h__
#define __OpcUaStackServer_NodeManagementService_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/ServiceSet/ServiceTransactionIf.h"
#include "OpcUaStackCore/ServiceSet/NodeManagementServiceTransaction.h"
#include "OpcUaStackServer/ServiceSet/ServiceSetBase.h"
#include "OpcUaStackServer/AddressSpaceModel/BaseNodeClass.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	class DLLEXPORT NodeManagementService 
	: public ServiceSetBase
	, public ObjectPool<NodeManagementService>
	{
	  public:
		typedef boost::shared_ptr<NodeManagementService> SPtr;

		NodeManagementService(void);
		~NodeManagementService(void);

		//- Component -----------------------------------------------------------------
		void receive(OpcUaNodeId& typeId, Message::SPtr message);
		//- Component -----------------------------------------------------------------

	  private:
		void receiveAddNodesRequest(OpcUaNodeId& typeId, ServiceTransaction::SPtr serviceTransaction);
		void receiveAddReferencesRequest(OpcUaNodeId& typeId, ServiceTransaction::SPtr serviceTransaction);
		void receiveDeleteNodesRequest(OpcUaNodeId& typeId, ServiceTransaction::SPtr serviceTransaction);
		void receiveDeleteReferencesRequest(OpcUaNodeId& typeId, ServiceTransaction::SPtr serviceTransaction);

		OpcUaStatusCode addNode(uint32_t, BaseNodeClass::SPtr baseNodeClass);
		OpcUaStatusCode addNode(uint32_t pos, AddNodesItem::SPtr addNodesItem, AddNodesResult::SPtr addNodesResult);
		OpcUaStatusCode addBaseNodeClass(uint32_t pos, BaseNodeClass::SPtr baseNodeClass, AddNodesItem::SPtr addNodesItem, AddNodesResult::SPtr addNodesResult);
		OpcUaStatusCode addNodeObject(uint32_t pos, AddNodesItem::SPtr addNodesItem, AddNodesResult::SPtr addNodesResult);
	};

}

#endif