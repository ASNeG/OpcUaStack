/*
   Copyright 2018 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackCore/ServiceSetApplication/ApplicationServiceTransaction.h"
#include "OpcUaStackServer/ServiceSetApplication/GetNodeReference.h"

namespace OpcUaStackServer
{

	GetNodeReference::GetNodeReference(void)
	: nodes_()
	{
	}

	GetNodeReference::GetNodeReference(const OpcUaNodeId& node)
	: nodes_()
	{
		nodes_.push_back(node);
	}

	GetNodeReference::GetNodeReference(const std::vector<OpcUaNodeId>& nodes)
	: nodes_(nodes)
	{
	}

	GetNodeReference::~GetNodeReference(void)
	{
	}

	void
	GetNodeReference::addNode(const OpcUaNodeId& node)
	{
		nodes_.push_back(node);
	}

	void
	GetNodeReference::addNodes(const std::vector<OpcUaNodeId>& nodes)
	{
		nodes_.insert(nodes_.end(), nodes.begin(), nodes.end());
	}

	void
	GetNodeReference::node(const OpcUaNodeId& node)
	{
		nodes_.clear();
		nodes_.push_back(node);
	}

	void
	GetNodeReference::nodes(const std::vector<OpcUaNodeId>& nodes)
	{
		nodes_ = nodes;
	}

	std::vector<OpcUaNodeId>&
	GetNodeReference::nodes(void)
	{
		return nodes_;
	}

	bool
	GetNodeReference::query(ApplicationServiceIf* applicationServiceIf)
	{
		if (nodes_.size() == 0) return false;

		// create request
		auto trx = constructSPtr<ServiceTransactionGetNodeReference>();
		trx->request()->nodes()->resize(nodes_.size());
		for (auto node : nodes_) trx->request()->nodes()->push_back(constructSPtr<OpcUaNodeId>(node));

		// send query to application service
		applicationServiceIf->sendSync(trx);
	  	if (trx->statusCode() != Success) return false;

	  	// handle response


		return true;
	}

}
