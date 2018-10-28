/*
   Copyright 2017 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackServer/VariableType/VariableBase.h"
#include "OpcUaStackServer/ServiceSetApplication/NodeReferenceApplication.h"

namespace OpcUaStackServer
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// class VariableBase
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	VariableBase::VariableBase(void)
	: serverVariables_()
	, applicationServiceIf_(nullptr)
	, namespaceName_("")
	, writeCallback_(boost::bind(&VariableBase::writeValue, this, _1))
	{
	}

	VariableBase::~VariableBase(void)
	{
	}

	void
	VariableBase::applicationServiceIf(ApplicationServiceIf* applicationServiceIf)
	{
		applicationServiceIf_ = applicationServiceIf;
	}

	ServerVariables&
	VariableBase::serverVariables(void)
	{
		return serverVariables_;
	}

	bool
	VariableBase::linkInstanceWithModel(const OpcUaNodeId& nodeId)
	{
		if (applicationServiceIf_ == nullptr) {
			Log(Error, "application service interface error in class VariableBase");
			return false;
		}

		// --------------------------------------------------------------------
		// --------------------------------------------------------------------
		//
		// get node ids from opc ua information model
		//
		// --------------------------------------------------------------------
		// --------------------------------------------------------------------
		Log(Debug, "get node ids");

		ServerVariable::Map::iterator it;
		ServiceTransactionBrowsePathToNodeId::SPtr trx1 = constructSPtr<ServiceTransactionBrowsePathToNodeId>();
		BrowsePathToNodeIdRequest::SPtr req1 = trx1->request();
		BrowsePathToNodeIdResponse::SPtr res1 = trx1->response();

		req1->browseNameArray()->resize(serverVariables_.serverVariableMap().size());
		for (it=serverVariables_.serverVariableMap().begin(); it != serverVariables_.serverVariableMap().end(); it++) {
			ServerVariable::SPtr serverVariable = it->second;
			BrowseName::SPtr browseName = serverVariable->browseName();
			if (browseName.get() == nullptr) {
				browseName = constructSPtr<BrowseName>();
			}
			browseName->nodeId(nodeId);
			req1->addBrowsePath(browseName);
		}


		applicationServiceIf_->sendSync(trx1);
		if (trx1->statusCode() != Success) {
			Log(Error, "BrowsePathToNodeIdResponse error")
			    .parameter("StatusCode", OpcUaStatusCodeMap::shortString(trx1->statusCode()));
			return false;
		}
		if (res1->nodeIdResults().get() == nullptr) {
			Log(Error, "BrowsePathToNodeIdResponse error");
			return false;
		}
		if (res1->nodeIdResults()->size() != req1->browseNameArray()->size()) {
			Log(Error, "BrowsePathToNodeIdResponse size error");
			return false;
		}

		// --------------------------------------------------------------------
		// --------------------------------------------------------------------
		//
		// get node references from opc ua information model a
		//
		// --------------------------------------------------------------------
		// --------------------------------------------------------------------
		Log(Debug, "get references");

		ServiceTransactionGetNodeReference::SPtr trx2 = constructSPtr<ServiceTransactionGetNodeReference>();
		GetNodeReferenceRequest::SPtr req2 = trx2->request();
		GetNodeReferenceResponse::SPtr res2 = trx2->response();

		req2->nodes()->resize(serverVariables_.serverVariableMap().size());
		for (uint32_t idx = 0; idx < serverVariables_.serverVariableMap().size(); idx++) {
			OpcUaNodeId::SPtr resNodeId = constructSPtr<OpcUaNodeId>();
			if (!getNodeIdFromResponse(res1, idx, resNodeId)) return false;
			req2->nodes()->push_back(resNodeId);
		}

	  	applicationServiceIf_->sendSync(trx2);
	  	if (trx2->statusCode() != Success) {
	  		Log(Error, "GetNodeReference error")
	  		    .parameter("StatusCode", OpcUaStatusCodeMap::shortString(trx2->statusCode()));
	  		return false;
	  	}
		if (res2->nodeReferenceArray().get() == nullptr) {
			Log(Error, "GetNodeReference error");
			return false;
		}
		if (res2->nodeReferenceArray()->size() != req2->nodes()->size()) {
			Log(Error, "GetNodeReference size error");
			return false;
		}

		uint32_t idx = 0;
		for (it=serverVariables_.serverVariableMap().begin(); it != serverVariables_.serverVariableMap().end(); it++) {
			BaseNodeClass::WPtr ref;
			ServerVariable::SPtr serverVariable = it->second;

			if (!getRefFromResponse(res2, idx, ref)) return false;
			serverVariable->baseNode(ref);

			idx++;
		}

		// --------------------------------------------------------------------
		// --------------------------------------------------------------------
		//
		// register write callbacks
		//
		// --------------------------------------------------------------------
		// --------------------------------------------------------------------
		Log(Debug, "register write callbacks");

	  	ServiceTransactionRegisterForwardNode::SPtr trx3 = constructSPtr<ServiceTransactionRegisterForwardNode>();
	  	RegisterForwardNodeRequest::SPtr req3 = trx3->request();
	  	RegisterForwardNodeResponse::SPtr res3 = trx3->response();

	  	req3->forwardNodeSync()->writeService().setCallback(writeCallback_);
	  	req3->nodesToRegister(req2->nodes());
		req3->applicationContextArray()->resize(serverVariables_.serverVariableMap().size());
		for (it=serverVariables_.serverVariableMap().begin(); it != serverVariables_.serverVariableMap().end(); it++) {
			BaseClass::SPtr serverVariable = it->second;
			req3->applicationContextArray()->push_back(serverVariable);
		}

	  	applicationServiceIf_->sendSync(trx3);
	  	if (trx3->statusCode() != Success) {
	  		std::cout << "response error" << std::endl;
	  		return false;
	  	}

	  	for (uint32_t pos = 0; pos < res3->statusCodeArray()->size(); pos++) {
	  		OpcUaStatusCode statusCode;
	  		res3->statusCodeArray()->get(pos, statusCode);
	  		if (statusCode != Success) {
	  			std::cout << "register value error" << std::endl;
	  			return false;
	  		}
	  	}

		return true;
	}

	bool
	VariableBase::createAndLinkInstanceWithModel(
		const std::string& name,
		const OpcUaNodeId& parentNodeId,
		const OpcUaNodeId& nodeId,
		const OpcUaLocalizedText& displayName,
		const OpcUaQualifiedName& browseName,
		const OpcUaNodeId& referenceNodeId
	)
	{
		Log(Debug, "create new node")
			.parameter("TypeNodeId", variableType_);

		// get namespace index
		uint16_t namespaceIndex;
		getNamespaceIndexFromNamespaceName(namespaceName_, namespaceIndex);
		variableType_.namespaceIndex(namespaceIndex);

		// --------------------------------------------------------------------
		// --------------------------------------------------------------------
		//
		// create node instance
		//
		// --------------------------------------------------------------------
		// --------------------------------------------------------------------
		ServiceTransactionCreateNodeInstance::SPtr trx = constructSPtr<ServiceTransactionCreateNodeInstance>();
		CreateNodeInstanceRequest::SPtr req = trx->request();
		CreateNodeInstanceResponse::SPtr res = trx->response();

		req->name() = name;
		req->nodeClassType() = NodeClassType_Variable;
		req->parentNodeId() = parentNodeId;
		req->nodeId() = nodeId;
		req->displayName() = displayName;
		req->browseName() = browseName;
		req->referenceNodeId() = referenceNodeId;
		req->typeNodeId() = variableType_;

	  	applicationServiceIf_->sendSync(trx);
	  	if (trx->statusCode() != Success) {
	  		Log(Error, "GetNodeReference error")
	  		    .parameter("StatusCode", OpcUaStatusCodeMap::shortString(trx->statusCode()));
	  		return false;
	  	}

		return linkInstanceWithModel(nodeId);
	}

	bool
	VariableBase::getNamespaceIndexFromNamespaceName(const std::string& namespaceName, uint16_t& namespaceIndex)
	{
		if (applicationServiceIf_ == nullptr) {
			Log(Error, "application service interface error in class VariableBase");
			return false;
		}

		ServiceTransactionNamespaceInfo::SPtr trx = constructSPtr<ServiceTransactionNamespaceInfo>();
		NamespaceInfoRequest::SPtr req = trx->request();
		NamespaceInfoResponse::SPtr res = trx->response();

		applicationServiceIf_->sendSync(trx);
		if (trx->statusCode() != Success) {
			Log(Error, "NamespaceInfoResponse error")
			    .parameter("StatusCode", OpcUaStatusCodeMap::shortString(trx->statusCode()));
			return false;
		}

		NamespaceInfoResponse::Index2NamespaceMap::iterator it;
		for (
		    it = res->index2NamespaceMap().begin();
			it != res->index2NamespaceMap().end();
			it++
		)
		{
			if (it->second == namespaceName) {
				namespaceIndex = it->first;
				return true;
			}
 		}

		Log(Error, "namespace not found in opc ua information model")
	        .parameter("NamespaceUri", namespaceName);

		return false;
	}

	void
	VariableBase::variableTypeNamespace(const std::string& namespaceName)
	{
		namespaceName_ = namespaceName;
	}

	void
	VariableBase::variableType(const OpcUaNodeId& variableType)
	{
		variableType_ = variableType;
	}

	OpcUaNodeId&
	VariableBase::variableType(void)
	{
		return variableType_;
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// private functions
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	bool
	VariableBase::getNodeIdFromResponse(BrowsePathToNodeIdResponse::SPtr& res, uint32_t idx, OpcUaNodeId::SPtr& nodeId)
	{
		NodeIdResult::SPtr nodeIdResult;
		if (!res->nodeIdResults()->get(idx, nodeIdResult)) {
			Log(Error, "node id result not exist in response")
				.parameter("Idx", idx);
			return false;
		}

		if (nodeIdResult->statusCode() != Success) {
			Log(Error, "node id result error in response")
				.parameter("StatusCode", OpcUaStatusCodeMap::shortString(nodeIdResult->statusCode()))
				.parameter("Idx", idx);
			return false;
		}

		nodeId = constructSPtr<OpcUaNodeId>();
		*nodeId = nodeIdResult->nodeId();
		return true;
	}

	bool
	VariableBase::getRefFromResponse(GetNodeReferenceResponse::SPtr& res, uint32_t idx, BaseNodeClass::WPtr& ref)
	{
		NodeReference::SPtr nodeReference;
		if (!res->nodeReferenceArray()->get(idx, nodeReference)) {
			Log(Error, "reference result not exist in response")
				.parameter("Idx", idx);
			return false;
		}

		if (nodeReference->statusCode() != Success) {
			Log(Error, "reference error in response")
				.parameter("StatusCode", OpcUaStatusCodeMap::shortString(nodeReference->statusCode()))
				.parameter("Idx", idx);
			return false;
		}

  		NodeReferenceApplication::SPtr nodeReferenceApplication;
  		nodeReferenceApplication = boost::static_pointer_cast<NodeReferenceApplication>(nodeReference);
  		ref = nodeReferenceApplication->baseNodeClass();

		return true;
	}

	void
	VariableBase::writeValue(ApplicationWriteContext* applicationWriteContext)
	{
		applicationWriteContext->statusCode_ = Success;

		BaseClass::SPtr baseClass = applicationWriteContext->applicationContext_;
		if (baseClass.get() == nullptr) return;

		ServerVariable::SPtr serverVariable = boost::static_pointer_cast<ServerVariable>(baseClass);
		serverVariable->writeValue(applicationWriteContext);
	}

}
