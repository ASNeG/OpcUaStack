/*
   Copyright 2016-2019 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaClient_ClientServiceNodeSetServer_h__
#define __OpcUaClient_ClientServiceNodeSetServer_h__

#include <future>
#include <boost/shared_ptr.hpp>
#include "OpcUaStackClient/ServiceSet/ViewServiceBrowse.h"
#include "OpcUaStackClient/ServiceSet/AttributeServiceNode.h"
#include "OpcUaStackServer/AddressSpaceModel/BaseNodeClass.h"
#include "OpcUaStackServer/InformationModel/InformationModel.h"
#include "OpcUaStackServer/NodeSet/NodeSetNamespace.h"
#include "OpcUaClient/ClientService/ClientServiceBase.h"
#include "OpcUaClient/ClientService/ClientServiceManager.h"

namespace OpcUaClient
{

	class DLLEXPORT ClientServiceNodeSetServer
	: public ClientServiceBase
	, public OpcUaStackClient::ViewServiceBrowseIf
	, public OpcUaStackClient::AttributeServiceNodeIf
	{
	  public:
		typedef boost::shared_ptr<ClientServiceNodeSetServer> SPtr;

		typedef enum {
			S_Init,
			S_ReadNamespaceArray,
			S_Browse,
			S_CheckReferences,
			S_WriteNodeSet
		} State;

		ClientServiceNodeSetServer(void);
		virtual ~ClientServiceNodeSetServer(void);

		//- ClientServiceNodeSet interface ------------------------------------
		virtual ClientServiceBase::SPtr createClientService(void);
		virtual bool run(ClientServiceManager& clientServiceManager, CommandBase::SPtr& commandBase);
		//- ClientServiceNodeSet interface ------------------------------------

		//- ViewServiceBrowseIf -----------------------------------------------
		virtual void viewServiceBrowseDone(
			OpcUaStackCore::OpcUaStatusCode statusCode
		);
		virtual void viewServiceBrowseResult(
			OpcUaStackCore::OpcUaStatusCode statusCode,
			OpcUaStackCore::OpcUaNodeId::SPtr& nodeId,
			OpcUaStackCore::ReferenceDescription::Vec& referenceDescriptionVec
		);
		//- ViewServiceBrowseIf -----------------------------------------------

		//- AttributeServiceNodeIf --------------------------------------------
		virtual void attributeServiceNodeDone(
			OpcUaStackCore::OpcUaStatusCode statusCode
		);
		virtual void attributeServiceNodeResult(
			OpcUaStackCore::AttributeId attributeId,
			OpcUaStackCore::OpcUaDataValue::SPtr& dataValue
		);
		//- AttributeServiceNodeId --------------------------------------------

      private:
		OpcUaStackCore::OpcUaStatusCode readNodeAttributes(
			OpcUaStackCore::OpcUaNodeId::SPtr& nodeId,
			OpcUaStackCore::NodeClass::Enum nodeClassType
		);
		OpcUaStackCore::OpcUaStatusCode readNamespaceArray(void);
		void handleNamespaceArray(
			OpcUaStackCore::OpcUaDataValue::SPtr& dataValue
		);
		bool createRootNode(
			OpcUaStackCore::OpcUaNodeId& rootNodeId
		);

		State state_;
		OpcUaStackCore::OpcUaNodeId readNodeId_;
		std::promise<bool> browseCompleted_;
		std::promise<bool> readCompleted_;
		OpcUaStackClient::AttributeService::SPtr attributeService_;
		OpcUaStackServer::BaseNodeClass::SPtr baseNodeClass_;
		OpcUaStackServer::InformationModel::SPtr informationModel_;
		OpcUaStackServer::NodeSetNamespace nodeSetNamespace_;

		OpcUaStackCore::OpcUaStatusCode browseStatusCode_;
		OpcUaStackCore::OpcUaStatusCode readStatusCode_;
		OpcUaStackCore::OpcUaStatusCode readNamespaceArrayStatusCode_;
	};

}

#endif

