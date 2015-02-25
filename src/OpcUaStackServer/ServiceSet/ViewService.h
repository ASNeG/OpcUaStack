#ifndef __OpcUaStackServer_ViewService_h__
#define __OpcUaStackServer_ViewService_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/ServiceSet/ViewServiceTransaction.h"
#include "OpcUaStackServer/ServiceSet/ServiceSetBase.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	class DLLEXPORT ViewService 
	: public ServiceSetBase
	, public ObjectPool<ViewService>
	{
	  public:
		typedef boost::shared_ptr<ViewService> SPtr;

		ViewService(void);
		~ViewService(void);

		//- Component -----------------------------------------------------------------
		void receive(OpcUaNodeId& typeId, Message::SPtr message);
		//- Component -----------------------------------------------------------------

	  private:
		void receiveBrowseRequest(OpcUaNodeId& typeId, ServiceTransaction::SPtr serviceTransaction);
		void receiveBrowseNextRequest(OpcUaNodeId& typeId, ServiceTransaction::SPtr serviceTransaction);
		void receiveTranslateBrowsePathsToNodeIdsRequest(OpcUaNodeId& typeId, ServiceTransaction::SPtr serviceTransaction);
		void receiveRegisterNodesRequest(OpcUaNodeId& typeId, ServiceTransaction::SPtr serviceTransaction);
		void receiveUnregisterNodesRequest(OpcUaNodeId& typeId, ServiceTransaction::SPtr serviceTransaction);

		typedef std::vector<ReferenceDescription::SPtr> ReferenceDescriptionVec;
		OpcUaStatusCode browseNode(BrowseDescription::SPtr browseDescription, ReferenceDescriptionVec& referenceDescriptionVec);
		OpcUaStatusCode hashSubtype(BaseNodeClass::SPtr baseNodeClass, BrowseDescription::SPtr browseDescription, uint32_t hopCounter = 25);
		OpcUaStatusCode checkReferenceType(OpcUaNodeId& referenceTypeNodeId, BrowseDescription::SPtr browseDescription);
	};

}

#endif