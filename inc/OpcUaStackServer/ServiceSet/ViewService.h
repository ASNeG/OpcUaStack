#ifndef __OpcUaStackServer_ViewService_h__
#define __OpcUaStackServer_ViewService_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/ServiceSet/ServiceTransactionIf.h"
#include "OpcUaStackCore/ServiceSet/ViewServiceTransaction.h"
#include "OpcUaStackServer/ServiceSet/ServiceSetBase.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	class DLLEXPORT ViewService 
	: public ServiceSetBase
	, public ServiceTransactionIf
	, public ObjectPool<ViewService>
	{
	  public:
		ViewService(void);
		~ViewService(void);

		//- ServiceTransactionIf ------------------------------------------------------
		void receive(OpcUaNodeId& typeId, ServiceTransaction::SPtr serviceTransaction);
		//- ServiceTransactionIf ------------------------------------------------------

	  private:
		void receiveBrowseRequest(OpcUaNodeId& typeId, ServiceTransaction::SPtr serviceTransaction);
		void receiveBrowseNextRequest(OpcUaNodeId& typeId, ServiceTransaction::SPtr serviceTransaction);
		void receiveTranslateBrowsePathsToNodeIdsRequest(OpcUaNodeId& typeId, ServiceTransaction::SPtr serviceTransaction);
		void receiveRegisterNodesRequest(OpcUaNodeId& typeId, ServiceTransaction::SPtr serviceTransaction);
		void receiveUnregisterNodesRequest(OpcUaNodeId& typeId, ServiceTransaction::SPtr serviceTransaction);

		typedef std::vector<ReferenceDescription::SPtr> ReferenceDescriptionVec;
		OpcUaStatusCode browseNode(BrowseDescription::SPtr browseDescription, ReferenceDescriptionVec& referenceDescriptionVec);
	};

}

#endif