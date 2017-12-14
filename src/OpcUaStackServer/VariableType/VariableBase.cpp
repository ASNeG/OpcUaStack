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
#include "OpcUaStackCore/ServiceSetApplication/ApplicationServiceTransaction.h"
#include "OpcUaStackServer/VariableType/VariableBase.h"

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

		// FIXME: todo
		return true;

		Log(Debug, "get node ids");

		ServerVariable::Map::iterator it;
		ServiceTransactionBrowsePathToNodeId::SPtr trx = constructSPtr<ServiceTransactionBrowsePathToNodeId>();
		BrowsePathToNodeIdRequest::SPtr req1 = trx->request();
		BrowsePathToNodeIdResponse::SPtr res1 = trx->response();

		req1->browseNameArray()->resize(serverVariables_.serverVariableMap().size());
		for (it=serverVariables_.serverVariableMap().begin(); it != serverVariables_.serverVariableMap().end(); it++) {
			ServerVariable* serverVariable = it->second;
			BrowseName::SPtr browseName = serverVariable->browseName();
			if (browseName.get() == nullptr) {
				browseName = constructSPtr<BrowseName>();
			}
			browseName->nodeId(nodeId);
			req1->addBrowsePath(browseName);
		}


		applicationServiceIf_->sendSync(trx);
		if (trx->statusCode() != Success) {
			Log(Error, "BrowsePathToNodeIdResponse error")
			    .parameter("StatusCode", OpcUaStatusCodeMap::shortString(trx->statusCode()));
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

		for (uint32_t idx = 0; idx < serverVariables_.serverVariableMap().size(); idx++) {
			;
		}
#if 0
		if (!getNodeIdFromResponse(res, 0, xx)) return false;
#endif

		return true;
	}

	bool
	VariableBase::getNamespaceIndexFromNamespaceName(const std::string& namespaceName, uint32_t& namespaceIndex)
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
	VariableBase::variableType(const OpcUaNodeId& variableType)
	{
		variableType_ = variableType;
	}

	OpcUaNodeId&
	VariableBase::variableType(void)
	{
		return variableType_;
	}

}
