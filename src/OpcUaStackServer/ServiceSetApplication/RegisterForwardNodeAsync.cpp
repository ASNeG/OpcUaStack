/*
   Copyright 2020 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackServer/ServiceSetApplication/ApplicationServiceTransaction.h"
#include "OpcUaStackServer/ServiceSetApplication/RegisterForwardNodeAsync.h"
#include "OpcUaStackServer/ServiceSetApplication/NodeReferenceApplication.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	RegisterForwardNodeAsync::RegisterForwardNodeAsync(void)
	: nodes_()
	, resultCode_(Success)
	, forwardNodeAsync_()
	, statuses_()
	{
	}

	RegisterForwardNodeAsync::RegisterForwardNodeAsync(const OpcUaNodeId& node)
	: nodes_()
	, resultCode_(Success)
	, forwardNodeAsync_()
	, statuses_()
	{
		nodes_.push_back(node);
	}

	RegisterForwardNodeAsync::RegisterForwardNodeAsync(const std::vector<OpcUaNodeId>& nodes)
	: nodes_(nodes)
	, resultCode_(Success)
	, forwardNodeAsync_()
	, statuses_()
	{
	}

	RegisterForwardNodeAsync::RegisterForwardNodeAsync(std::initializer_list<OpcUaNodeId> nodes)
	: nodes_(nodes)
	, resultCode_(Success)
	, forwardNodeAsync_()
	, statuses_()
	{
	}

	RegisterForwardNodeAsync::~RegisterForwardNodeAsync(void)
	{
	}

	void
	RegisterForwardNodeAsync::addNode(const OpcUaNodeId& node)
	{
		nodes_.push_back(node);
	}

	void
	RegisterForwardNodeAsync::addNodes(const std::vector<OpcUaNodeId>& nodes)
	{
		nodes_.insert(nodes_.end(), nodes.begin(), nodes.end());
	}

	void
	RegisterForwardNodeAsync::node(const OpcUaNodeId& node)
	{
		nodes_.clear();
		nodes_.push_back(node);
	}

	void
	RegisterForwardNodeAsync::nodes(const std::vector<OpcUaNodeId>& nodes)
	{
		nodes_ = nodes;
	}

	std::vector<OpcUaNodeId>&
	RegisterForwardNodeAsync::nodes(void)
	{
		return nodes_;
	}

	void
	RegisterForwardNodeAsync::addApplicationContext(BaseClass::SPtr& applicationContext)
	{
		applicationContextVec_.push_back(applicationContext);
	}

	void
	RegisterForwardNodeAsync::addApplicationContext(std::vector<BaseClass::SPtr>& applicationContextVec)
	{
		applicationContextVec_.insert(
			applicationContextVec_.end(),
			applicationContextVec.begin(),
			applicationContextVec.end()
		);
	}

	void
	RegisterForwardNodeAsync::applicationContext(BaseClass::SPtr& applicationContext)
	{
		applicationContextVec_.clear();
		applicationContextVec_.push_back(applicationContext);
	}

	void
	RegisterForwardNodeAsync::applicationContext(std::vector<BaseClass::SPtr>& applicationContextVec)
	{
		applicationContextVec_ = applicationContextVec;
	}

	std::vector<BaseClass::SPtr>&
	RegisterForwardNodeAsync::applicationContextVec(void)
	{
		return applicationContextVec_;
	}

	OpcUaStackCore::ForwardNodeAsync&
	RegisterForwardNodeAsync::forwardNodeAsync(void)
	{
		return forwardNodeAsync_;
	}

	bool
	RegisterForwardNodeAsync::query(
		ApplicationServiceIf* applicationServiceIf,
		bool checkStatusCodeArray
	)
	{
		if (nodes_.size() == 0) return false;

		resultCode_ = Success;
		statuses_.clear();

		// check parameter
		if (!applicationContextVec_.empty() && applicationContextVec_.size() != nodes_.size()) {
			return false;
		}

		//
		// create request
		//
		auto trx = boost::make_shared<ServiceTransactionRegisterForwardNodeAsync>();
		trx->request()->nodesToRegister()->resize(nodes_.size());
		for (auto node : nodes_) trx->request()->nodesToRegister()->push_back(boost::make_shared<OpcUaNodeId>(node));
		if (!applicationContextVec_.empty()) {
			trx->request()->applicationContextArray()->resize(applicationContextVec_.size());
			for (auto applicationContext : applicationContextVec_) trx->request()->applicationContextArray()->push_back(applicationContext);
		}
		trx->request()->forwardNodeAsync()->updateFrom(forwardNodeAsync_);

		//
		// send query to application service
		//
		applicationServiceIf->sendSync(trx);
		resultCode_ = trx->statusCode();
	  	if (resultCode_ != Success) {
	  		return false;
	  	}

	  	// handle response
	  	bool result = true;
	  	if (checkStatusCodeArray) {
	  		for (uint32_t idx = 0; idx < trx->response()->statusCodeArray()->size(); idx++) {
	  			OpcUaStatusCode statusCode;
	  			trx->response()->statusCodeArray()->get(idx, statusCode);
	  			statuses_.push_back(statusCode);
	  			if (statusCode != Success) {
	  				result = false;
	  			}
	  		}
	  	}

		return result;
	}

	OpcUaStatusCode
	RegisterForwardNodeAsync::resultCode(void)
	{
		return resultCode_;
	}

	std::vector<OpcUaStatusCode>&
	RegisterForwardNodeAsync::statuses(void)
	{
		return statuses_;
	}

}
