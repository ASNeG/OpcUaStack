#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackCore/ServiceSet/ViewServiceTransaction.h"
#include "OpcUaStackServer/ServiceSet/ViewService.h"
#include "OpcUaStackServer/AddressSpaceModel/AttributeAccess.h"


namespace OpcUaStackServer
{

	ViewService::ViewService(void)
	{
	}

	ViewService::~ViewService(void)
	{
	}

	void 
	ViewService::receive(OpcUaNodeId& typeId, ServiceTransaction::SPtr serviceTransaction)
	{
		switch (serviceTransaction->nodeTypeRequest().nodeId<uint32_t>()) 
		{
			case OpcUaId_BrowseRequest_Encoding_DefaultBinary:
				receiveBrowseRequest(typeId, serviceTransaction);
				break;
			case OpcUaId_BrowseNextRequest_Encoding_DefaultBinary:
				receiveBrowseNextRequest(typeId, serviceTransaction);
				break;
			case OpcUaId_TranslateBrowsePathsToNodeIdsRequest_Encoding_DefaultBinary:
				receiveTranslateBrowsePathsToNodeIdsRequest(typeId, serviceTransaction);
				break;
			case OpcUaId_RegisterNodesRequest_Encoding_DefaultBinary:
				receiveRegisterNodesRequest(typeId, serviceTransaction);
				break;
			case OpcUaId_UnregisterNodesRequest_Encoding_DefaultBinary:
				receiveUnregisterNodesRequest(typeId, serviceTransaction);
				break;
			default:
				serviceTransaction->statusCode(BadInternalError);
				serviceTransaction->serviceTransactionIfSession()->receive(typeId, serviceTransaction);
		}
	}

	void 
	ViewService::receiveBrowseRequest(OpcUaNodeId& typeId, ServiceTransaction::SPtr serviceTransaction)
	{
		ServiceTransactionBrowse::SPtr trx = boost::static_pointer_cast<ServiceTransactionBrowse>(serviceTransaction);
		BrowseRequest::SPtr browseRequest = trx->request();
		BrowseResponse::SPtr browseResponse = trx->response();


		uint32_t nodes = browseRequest->nodesToBrowse()->size();
		Log(Debug, "attribute service browse request")
			.parameter("Trx", serviceTransaction->transactionId())
			.parameter("NumberNodes", nodes);

		BrowseResultArray::SPtr browseResultArray = BrowseResultArray::construct();
		browseResponse->results(browseResultArray);
		browseResultArray->resize(nodes);

		for (uint32_t idx = 0; idx < nodes; idx++) {
			BrowseDescription::SPtr browseDescription;
			browseRequest->nodesToBrowse()->get(idx, browseDescription);

			BrowseResult::SPtr browseResult = BrowseResult::construct();
			browseResultArray->set(idx, browseResult);

			ReferenceDescriptionVec::iterator it;
			ReferenceDescriptionVec referenceDescriptionVec;
			OpcUaStatusCode statusCode = browseReferences(browseDescription, referenceDescriptionVec); 
			browseResult->statusCode(statusCode);

			ReferenceDescriptionArray::SPtr referenceDescriptionArray = ReferenceDescriptionArray::construct();
			referenceDescriptionArray->resize(referenceDescriptionVec.size());
			for (it = referenceDescriptionVec.begin(); it != referenceDescriptionVec.end(); it++) {
				referenceDescriptionArray->push_back(*it);
			}

			Log(Debug, "attribute service browse request")
				.parameter("Trx", serviceTransaction->transactionId())
				.parameter("NodeId", *browseDescription->nodeId())
				.parameter("References", referenceDescriptionVec.size())
				.parameter("StatusCode", OpcUaStatusCodeMap::shortString(statusCode));
		}

		serviceTransaction->statusCode(Success);
		serviceTransaction->serviceTransactionIfSession()->receive(typeId, serviceTransaction);
	}

	void 
	ViewService::receiveBrowseNextRequest(OpcUaNodeId& typeId, ServiceTransaction::SPtr serviceTransaction)
	{
		// FIXME:
		serviceTransaction->statusCode(BadInternalError);
		serviceTransaction->serviceTransactionIfSession()->receive(typeId, serviceTransaction);
	}

	void 
	ViewService::receiveTranslateBrowsePathsToNodeIdsRequest(OpcUaNodeId& typeId, ServiceTransaction::SPtr serviceTransaction)
	{
		// FIXME:
		serviceTransaction->statusCode(BadInternalError);
		serviceTransaction->serviceTransactionIfSession()->receive(typeId, serviceTransaction);
	}

	void 
	ViewService::receiveRegisterNodesRequest(OpcUaNodeId& typeId, ServiceTransaction::SPtr serviceTransaction)
	{
		// FIXME:
		serviceTransaction->statusCode(BadInternalError);
		serviceTransaction->serviceTransactionIfSession()->receive(typeId, serviceTransaction);
	}

	void 
	ViewService::receiveUnregisterNodesRequest(OpcUaNodeId& typeId, ServiceTransaction::SPtr serviceTransaction)
	{
		// FIXME:
		serviceTransaction->statusCode(BadInternalError);
		serviceTransaction->serviceTransactionIfSession()->receive(typeId, serviceTransaction);
	}

	
	OpcUaStatusCode
	ViewService::browseReferences(BrowseDescription::SPtr browseDescription, ReferenceDescriptionVec& referenceDescriptionVec)
	{
		OpcUaStatusCode statusCode;

		BaseNodeClass::SPtr baseNodeClass = informationModel_->find(*browseDescription->nodeId());
		if (baseNodeClass.get() == nullptr) {
			return BadNodeIdUnknown;
		}

		statusCode = browseNode(browseDescription, referenceDescriptionVec, baseNodeClass, ReferenceType_HasComponent);
		if (statusCode != Success) return statusCode;
		
		statusCode = browseNode(browseDescription, referenceDescriptionVec, baseNodeClass, ReferenceType_HasProperty);
		if (statusCode != Success) return statusCode;

		statusCode = browseNode(browseDescription, referenceDescriptionVec, baseNodeClass, ReferenceType_HasModellingRule);
		if (statusCode != Success) return statusCode;

		statusCode = browseNode(browseDescription, referenceDescriptionVec, baseNodeClass, ReferenceType_HasTypeDefinition);
		if (statusCode != Success) return statusCode;

		statusCode = browseNode(browseDescription, referenceDescriptionVec, baseNodeClass, ReferenceType_HasModelParent);
		if (statusCode != Success) return statusCode;

		statusCode = browseNode(browseDescription, referenceDescriptionVec, baseNodeClass, ReferenceType_HasEventSource);
		if (statusCode != Success) return statusCode;

		statusCode = browseNode(browseDescription, referenceDescriptionVec, baseNodeClass, ReferenceType_HasEventSource);
		if (statusCode != Success) return statusCode;

		statusCode = browseNode(browseDescription, referenceDescriptionVec, baseNodeClass, ReferenceType_HasNotifier);
		if (statusCode != Success) return statusCode;

		statusCode = browseNode(browseDescription, referenceDescriptionVec, baseNodeClass, ReferenceType_Organizes);
		if (statusCode != Success) return statusCode;

		statusCode = browseNode(browseDescription, referenceDescriptionVec, baseNodeClass, ReferenceType_HasDescription);
		if (statusCode != Success) return statusCode;

		statusCode = browseNode(browseDescription, referenceDescriptionVec, baseNodeClass, ReferenceType_HasEncoding);
		if (statusCode != Success) return statusCode;

		statusCode = browseNode(browseDescription, referenceDescriptionVec, baseNodeClass, ReferenceType_HasSubtype);
		if (statusCode != Success) return statusCode;

		statusCode = browseNode(browseDescription, referenceDescriptionVec, baseNodeClass, ReferenceType_NodeId);
		if (statusCode != Success) return statusCode;

		statusCode = browseNode(browseDescription, referenceDescriptionVec, baseNodeClass, ReferenceType_HasModelParameter);
		if (statusCode != Success) return statusCode;

		statusCode = browseNode(browseDescription, referenceDescriptionVec, baseNodeClass, ReferenceType_GenerateEvents);
		if (statusCode != Success) return statusCode;

		statusCode = browseNode(browseDescription, referenceDescriptionVec, baseNodeClass, ReferenceType_AlwaysGeneratesEvent);
		if (statusCode != Success) return statusCode;

		statusCode = browseNode(browseDescription, referenceDescriptionVec, baseNodeClass, ReferenceType_HierarchicalReferences);
		if (statusCode != Success) return statusCode;

		return Success;
	}

	OpcUaStatusCode 
	ViewService::browseNode(BrowseDescription::SPtr browseDescription, ReferenceDescriptionVec& referenceDescriptionVec, BaseNodeClass::SPtr baseNodeClass, ReferenceType referenceType)
	{
		ReferenceItemList::iterator it;
		ReferenceList referenceList;

		referenceList.referenceItemList_.clear();
		baseNodeClass->getReference(referenceList, referenceType);
		for (it = referenceList.referenceItemList_.begin(); it != referenceList.referenceItemList_.end(); it++) {
			ReferenceItem::SPtr referenceItem = *it;

			BaseNodeClass::SPtr baseNodeClassTarget = informationModel_->find(referenceItem->nodeId_);
			if (baseNodeClassTarget.get() == nullptr) {
				std::cout << "nicht gefunden..." << *it << std::endl;
				continue;
			}

			ReferenceDescription::SPtr referenceDescription = ReferenceDescription::construct();
			referenceDescriptionVec.push_back(referenceDescription);

			OpcUaExpandedNodeId::SPtr targetNodeId = OpcUaExpandedNodeId::construct();
			baseNodeClass->nodeId().data().copyTo(*targetNodeId);

			referenceItem->referenceTypeId_.copyTo(*referenceDescription->referenceTypeId());
			referenceDescription->isForward(referenceItem->isForward_);  
			referenceDescription->nodeId(targetNodeId);
			referenceDescription->displayName(baseNodeClass->displayName().data());
			referenceDescription->browseName(baseNodeClass->browseName().data());
			referenceDescription->nodeClass(baseNodeClass->nodeClass().data());
			
		}

		return Success;
	}

	
#if 0
		OpcUaExpandedNodeId::SPtr typeDefinitionSPtr_;
#endif

#if 0
	typedef enum {
		NodeClassType_Unspecified = 0,
		NodeClassType_Object = 1,
		NodeClassType_Variable = 2,
		NodeClassType_Method = 4,
		NodeClassType_ObjectType = 8,
		NodeClassType_VariableType = 16,
		NodeClassType_ReferenceType = 32,
		NodeClassType_DataType = 64,
		NodeClassType_View = 128,
	} NodeClassType;

		typedef enum
	{
		NodeClass_Object = 1,
		NodeClass_Variable = 2,
		NodeClass_Method = 4,
		NodeClass_ObjectType = 8,
		NodeClass_VariableType = 16,
		NodeClass_ReferenceType = 32,
		NodeClass_DataType = 64,
		NodeClass_View = 128
	} NodeClass;
#endif


}