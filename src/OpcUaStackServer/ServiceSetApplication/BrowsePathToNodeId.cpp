/*
   Copyright 2018-2019 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackServer/ServiceSetApplication/BrowsePathToNodeId.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	BrowsePathToNodeId::BrowsePathToNodeId(void)
	: browseNames_()
	, resultCode_(Success)
	, statuses_()
	, nodes_()
	{
	}

	BrowsePathToNodeId::BrowsePathToNodeId(std::vector<BrowseName::SPtr>& browseNames)
	: browseNames_(browseNames)
	, resultCode_(Success)
	, statuses_()
	, nodes_()
	{
	}

	BrowsePathToNodeId::BrowsePathToNodeId(std::initializer_list<BrowseName::SPtr> browseNames)
	: browseNames_(browseNames)
	, resultCode_(Success)
	, statuses_()
	, nodes_()
	{
	}

	BrowsePathToNodeId::BrowsePathToNodeId(std::initializer_list<BrowseName> browseNames)
	: browseNames_()
	, resultCode_(Success)
	, statuses_()
	, nodes_()
	{
		for (auto& browseName : browseNames) browseNames_.push_back(boost::make_shared<BrowseName>(browseName));
	}

	BrowsePathToNodeId::~BrowsePathToNodeId(void)
	{
	}

	void
	BrowsePathToNodeId::addBrowseName(const BrowseName::SPtr& browseName)
	{
		browseNames_.push_back(browseName);
	}

	void
	BrowsePathToNodeId::addBrowseName(
		const OpcUaNodeId& nodeId,
		const OpcUaQualifiedName& pathElement
	)
	{
		browseNames_.push_back(boost::make_shared<BrowseName>(nodeId, pathElement));
	}

	void
	BrowsePathToNodeId::addBrowseName(
		const OpcUaNodeId& nodeId,
		const OpcUaQualifiedName& pathElement1,
		const OpcUaQualifiedName& pathElement2
	)
	{
		browseNames_.push_back(boost::make_shared<BrowseName>(nodeId, pathElement1, pathElement2));
	}

	void
	BrowsePathToNodeId::addBrowseName(
		const OpcUaNodeId& nodeId,
		const OpcUaQualifiedName& pathElement1,
		const OpcUaQualifiedName& pathElement2,
		const OpcUaQualifiedName& pathElement3
	)
	{
		browseNames_.push_back(boost::make_shared<BrowseName>(nodeId, pathElement1, pathElement2, pathElement3));
	}

	void
	BrowsePathToNodeId::addBrowseName(
		const OpcUaNodeId& nodeId,
		const OpcUaQualifiedName& pathElement1,
		const OpcUaQualifiedName& pathElement2,
		const OpcUaQualifiedName& pathElement3,
		const OpcUaQualifiedName& pathElement4
	)
	{
		browseNames_.push_back(boost::make_shared<BrowseName>(nodeId, pathElement1, pathElement2, pathElement3, pathElement4));
	}

	void
	BrowsePathToNodeId::addBrowseName(
		const OpcUaNodeId& nodeId,
		const OpcUaQualifiedName& pathElement1,
		const OpcUaQualifiedName& pathElement2,
		const OpcUaQualifiedName& pathElement3,
		const OpcUaQualifiedName& pathElement4,
		const OpcUaQualifiedName& pathElement5
	)
	{
		browseNames_.push_back(boost::make_shared<BrowseName>(nodeId, pathElement1, pathElement2, pathElement3, pathElement4, pathElement5));
	}

	bool
	BrowsePathToNodeId::query(ApplicationServiceIf* applicationServiceIf,bool checkStatusCodeArray)
	{
		// create request
		auto trx = boost::make_shared<ServiceTransactionBrowsePathToNodeId>();
		trx->request()->browseNameArray()->resize(browseNames_.size());
		for (auto& browseName : browseNames_) trx->request()->browseNameArray()->push_back(browseName);

		// send query to application service
		applicationServiceIf->sendSync(trx);
		resultCode_ = trx->statusCode();
	  	if (resultCode_ != Success) return false;

	  	// handle response
	  	bool result = true;
	  	for (uint32_t idx = 0; idx < trx->response()->nodeIdResults()->size(); idx++) {
	  		NodeIdResult::SPtr nodeIdResult;
	  		trx->response()->nodeIdResults()->get(idx, nodeIdResult);
	  		nodes_.push_back(nodeIdResult->nodeId());
	  		statuses_.push_back(nodeIdResult->statusCode());

	  		if (checkStatusCodeArray && nodeIdResult->statusCode() != Success) {
	  			result = false;
	  		}
	  	}

		return result;
	}

	OpcUaStatusCode
	BrowsePathToNodeId::resultCode(void)
	{
		return resultCode_;
	}

	std::vector<OpcUaStatusCode>&
	BrowsePathToNodeId::statuses(void)
	{
		return statuses_;
	}

	std::vector<OpcUaNodeId>&
	BrowsePathToNodeId::nodes(void)
	{
		return nodes_;
	}

}
