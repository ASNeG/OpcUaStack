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

namespace OpcUaStackServer
{

	class DLLEXPORT ViewService 
	: public ServiceSetBase
	, public OpcUaStackCore::Object
	{
	  public:
		typedef boost::shared_ptr<ViewService> SPtr;

		ViewService(void);
		~ViewService(void);

		//- Component -----------------------------------------------------------------
		void receive(OpcUaStackCore::Message::SPtr message);
		//- Component -----------------------------------------------------------------

	  private:
		void receiveBrowseRequest(OpcUaStackCore::ServiceTransaction::SPtr serviceTransaction);
		void receiveBrowseNextRequest(OpcUaStackCore::ServiceTransaction::SPtr serviceTransaction);
		void receiveTranslateBrowsePathsToNodeIdsRequest(OpcUaStackCore::ServiceTransaction::SPtr serviceTransaction);
		void receiveRegisterNodesRequest(OpcUaStackCore::ServiceTransaction::SPtr serviceTransaction);

		typedef std::vector<OpcUaStackCore::ReferenceDescription::SPtr> ReferenceDescriptionVec;
		OpcUaStackCore::OpcUaStatusCode browseNode(OpcUaStackCore::BrowseDescription::SPtr& browseDescription, ReferenceDescriptionVec& referenceDescriptionVec);
		OpcUaStackCore::OpcUaStatusCode hashSubtype(BaseNodeClass::SPtr baseNodeClass, OpcUaStackCore::BrowseDescription::SPtr browseDescription, uint32_t hopCounter = 25);
		OpcUaStackCore::OpcUaStatusCode checkReferenceType(OpcUaStackCore::OpcUaNodeId& referenceTypeNodeId, OpcUaStackCore::BrowseDescription::SPtr& browseDescription);
		void receiveUnregisterNodesRequest(OpcUaStackCore::ServiceTransaction::SPtr serviceTransaction);
		bool getNodeFromPathElement(OpcUaStackCore::OpcUaNodeId& nodeId, OpcUaStackCore::OpcUaQualifiedName& pathElement);
	};

}

#endif
