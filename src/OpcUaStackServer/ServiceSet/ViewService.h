/*
   Copyright 2015-2019 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   Informationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Kai Huebl (kai@huebl-sgh.de)
 */

#ifndef __OpcUaStackServer_ViewService_h__
#define __OpcUaStackServer_ViewService_h__

#include "OpcUaStackCore/ServiceSet/ViewServiceTransaction.h"
#include "OpcUaStackServer/ServiceSet/ServiceSetBase.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	class DLLEXPORT ViewService 
	: public ServiceSetBase
	, public Object
	{
	  public:
		typedef boost::shared_ptr<ViewService> SPtr;

		ViewService(void);
		~ViewService(void);

		//- Component -----------------------------------------------------------------
		void receive(Message::SPtr message);
		//- Component -----------------------------------------------------------------

	  private:
		void receiveBrowseRequest(ServiceTransaction::SPtr serviceTransaction);
		void receiveBrowseNextRequest(ServiceTransaction::SPtr serviceTransaction);
		void receiveTranslateBrowsePathsToNodeIdsRequest(ServiceTransaction::SPtr serviceTransaction);
		void receiveRegisterNodesRequest(ServiceTransaction::SPtr serviceTransaction);

		typedef std::vector<ReferenceDescription::SPtr> ReferenceDescriptionVec;
		OpcUaStatusCode browseNode(BrowseDescription::SPtr& browseDescription, ReferenceDescriptionVec& referenceDescriptionVec);
		OpcUaStatusCode hashSubtype(BaseNodeClass::SPtr baseNodeClass, BrowseDescription::SPtr browseDescription, uint32_t hopCounter = 25);
		OpcUaStatusCode checkReferenceType(OpcUaNodeId& referenceTypeNodeId, BrowseDescription::SPtr& browseDescription);
		void receiveUnregisterNodesRequest(ServiceTransaction::SPtr serviceTransaction);
		bool getNodeFromPathElement(OpcUaNodeId& nodeId, OpcUaQualifiedName& pathElement);
	};

}

#endif
