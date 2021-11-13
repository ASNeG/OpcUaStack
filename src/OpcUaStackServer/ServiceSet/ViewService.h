/*
   Copyright 2015-2020 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   Informationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Kai Huebl (kai@huebl-sgh.de)
          Upendar Reddy Sama (upendarreddysama3@gmail.com)
 */

#ifndef __OpcUaStackServer_ViewService_h__
#define __OpcUaStackServer_ViewService_h__

#include "OpcUaStackCore/ServiceSet/ViewServiceTransaction.h"
#include "OpcUaStackServer/ServiceSet/ServiceSetBase.h"
#include "OpcUaStackServer/ServiceSet/ServerServiceBase.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaByteString.h"
#include "OpcUaStackCore/ServiceSet/ContinuationPointManager.h"

namespace OpcUaStackServer
{
    typedef enum
    {
        Browse_ReferenceType,
        Browse_IsForward,
        Browse_NodeClass,
        Browse_BrowseName,
        Browse_DisplayName,
        Browse_TypeDefinition
    } BrowseResultMask;

	class DLLEXPORT ViewService 
	: public ServiceSetBase
	, public OpcUaStackCore::Object
	, public OpcUaStackServer::ServerServiceBase
	{
	  public:
		typedef boost::shared_ptr<ViewService> SPtr;
      
		ViewService(
			const std::string& serviceName,
			OpcUaStackCore::IOThread::SPtr& ioThread,
			OpcUaStackCore::MessageBus::SPtr& messageBus,
			OpcUaStackCore::ContinuationPointManager::SPtr& continuationPointManager_
		);
		~ViewService(void);

	  private:
        OpcUaStackCore::ContinuationPoint::SPtr continuationPoint_ = nullptr;
        OpcUaStackCore::ContinuationPointManager::SPtr continuationPointManger_ = nullptr;
		uint32_t sessionId_;

		void receive(
			const OpcUaStackCore::MessageBusMember::WPtr& handleFrom,
			OpcUaStackCore::Message::SPtr& message
		);
		void sendAnswer(OpcUaStackCore::ServiceTransaction::SPtr& serviceTransaction);
		void receiveBrowseRequest(OpcUaStackCore::ServiceTransaction::SPtr serviceTransaction);
		void receiveBrowseNextRequest(OpcUaStackCore::ServiceTransaction::SPtr serviceTransaction);
		void receiveTranslateBrowsePathsToNodeIdsRequest(OpcUaStackCore::ServiceTransaction::SPtr serviceTransaction);
		void receiveRegisterNodesRequest(OpcUaStackCore::ServiceTransaction::SPtr serviceTransaction);

		typedef std::vector<OpcUaStackCore::ReferenceDescription::SPtr> ReferenceDescriptionVec;
		OpcUaStackCore::OpcUaStatusCode browseNode(
                                       OpcUaStackCore::BrowseDescription::SPtr& browseDescription,
                                       ReferenceDescriptionVec& referenceDescriptionVec,
                                       const OpcUaStackCore::OpcUaUInt32 requestedMaxReferencesPerNode
        ); 
		OpcUaStackCore::OpcUaStatusCode hashSubtype(BaseNodeClass::SPtr baseNodeClass, OpcUaStackCore::BrowseDescription::SPtr browseDescription, uint32_t hopCounter = 25);
		OpcUaStackCore::OpcUaStatusCode checkReferenceType(OpcUaStackCore::OpcUaNodeId& referenceTypeNodeId, OpcUaStackCore::BrowseDescription::SPtr& browseDescription);
		void receiveUnregisterNodesRequest(OpcUaStackCore::ServiceTransaction::SPtr serviceTransaction);
		bool getNodeFromPathElement(OpcUaStackCore::OpcUaNodeId& nodeId, OpcUaStackCore::OpcUaQualifiedName& pathElement);
	};

}

#endif
