/*
   Copyright 2016 Kai Huebl (kai@huebl-sgh.de)

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
#include "OpcUaStackClient/ServiceSet/AttributeServiceNode.h"

using namespace OpcUaStackCore;

namespace OpcUaStackClient
{

	AttributeServiceNode::AttributeServiceNode(void)
	: AttributeServiceIf()
	, attributeServiceBrowseIf_(nullptr)
	, attributeService_()
	, maxNodesInBrowse_(20)
	, nodeIdVec_()
	, direction_(BrowseDirection_Both)
	, recursive_(false)
	, referenceDescriptionVecVec_()
	, continuationPointVec_()
	, nodeIdToReadSet_()
	, nodeIdProcessedSet_()
	{
	}

	AttributeServiceNode::~AttributeServiceNode(void)
	{
	}

	void
	AttributeServiceNode::maxNodesInBrowse(uint32_t maxNodesInBrowse)
	{
		maxNodesInBrowse_ = maxNodesInBrowse;
	}

	void
	AttributeServiceNode::attributeService(AttributeService::SPtr& attributeService)
	{
		attributeService_ = attributeService;
		attributeService_->attributeServiceIf(this);
	}

	void
	AttributeServiceNode::nodeIdVec(OpcUaNodeId::Vec& nodeIdVec)
	{
		nodeIdVec_ = nodeIdVec;
	}

	void
	AttributeServiceNode::direction(BrowseDirectionEnum direction)
	{
		direction_ = direction;
	}

	void
	AttributeServiceNode::recursive(bool recursive)
	{
		recursive_ = recursive;
	}

	void
	AttributeServiceNode::attributeServiceBrowseIf(AttributeServiceNodeIf* attributeServiceBrowseIf)
	{
		attributeServiceBrowseIf_ = attributeServiceBrowseIf;
	}

	void
	AttributeServiceNode::asyncRead(void)
	{
		ServiceTransactionBrowse::SPtr trx = constructSPtr<ServiceTransactionBrowse>();
		BrowseRequest::SPtr req = trx->request();

		req->nodesToBrowse()->resize(nodeIdVec_.size());

		for (uint32_t pos = 0; pos < nodeIdVec_.size(); pos++) {
			BrowseDescription::SPtr browseDescription = constructSPtr<BrowseDescription>();
			browseDescription->nodeId(nodeIdVec_[pos]);
			browseDescription->browseDirection(direction_);
			browseDescription->nodeClassMask(0xFFFFFFFF);
			browseDescription->resultMask(0xFFFFFFFF);
			req->nodesToBrowse()->push_back(browseDescription);
		}

		attributeService_->asyncSend(trx);
	}

    void
    AttributeServiceNode::attributeServiceBrowseResponse(ServiceTransactionBrowse::SPtr serviceTransactionBrowse)
    {
    	OpcUaStatusCode statusCode;
    	BrowseResponse::SPtr res = serviceTransactionBrowse->response();
    	BrowseRequest::SPtr req = serviceTransactionBrowse->request();

    	// check response
    	statusCode = serviceTransactionBrowse->responseHeader()->serviceResult();
    	if (statusCode != Success) {
    		Log(Error, "browse response error")
    			.parameter("StatusCode", OpcUaStatusCodeMap::longString(statusCode));
    		done(statusCode);
    		return;
    	}

    	// check browse results
    	if (res->results()->size() != nodeIdVec_.size()) {
    		Log(Error, "result array size in browse response error")
    			.parameter("ArraySize", res->results()->size());
    		done(BadCommunicationError);
    		return;
    	}

		OpcUaNodeId::Vec tmpNodeIdVec;
		std::vector<ReferenceDescription::Vec> tmpReferenceDescriptionVecVec;
		std::vector<std::string> tmpContinuationPointVec;

    	for (uint32_t pos = 0; pos < nodeIdVec_.size(); pos++)
    	{
    		ReferenceDescription::Vec referenceDescriptionVec;

    		// check response data
    		BrowseResult::SPtr browseResult;
    		res->results()->get(pos, browseResult);
    		statusCode = browseResult->statusCode();
    		if (statusCode != Success) {
    			this->browseResult(statusCode, nodeIdVec_[pos], referenceDescriptionVec);
    			continue;
    		}

    		// process browse response
    		ReferenceDescriptionArray::SPtr references = browseResult->references();

    		// no reference available
    		if (references->size() == 0) {
    			this->browseResult(Success, nodeIdVec_[pos], referenceDescriptionVec);
    			continue;
    		}

    		// browse next references
    		for (uint32_t idx = 0; idx < references->size(); idx++) {
    			ReferenceDescription::SPtr referenceDescription;
    			references->get(idx, referenceDescription);
    			referenceDescriptionVec.push_back(referenceDescription);
    		}

    		// check continuation point
    		if (browseResult->continuationPoint().exist()) {
        		tmpNodeIdVec.push_back(nodeIdVec_[pos]);
        		tmpReferenceDescriptionVecVec.push_back(referenceDescriptionVec);
        		tmpContinuationPointVec.push_back(browseResult->continuationPoint().toHexString());
    			continue;
    		}

    		this->browseResult(Success, nodeIdVec_[pos], referenceDescriptionVec);
    	}

    	// browse next
    	if (!tmpNodeIdVec.empty()) {
    		nodeIdVec_ = tmpNodeIdVec;
    		referenceDescriptionVecVec_ = tmpReferenceDescriptionVecVec;
    		continuationPointVec_ = tmpContinuationPointVec;
    		asyncReadNext();
    		return;
    	}

		done(Success);
    }

    void
    AttributeServiceNode::asyncReadNext(void)
    {
    	ServiceTransactionBrowseNext::SPtr trx = constructSPtr<ServiceTransactionBrowseNext>();
		BrowseNextRequest::SPtr req = trx->request();

		req->continuationPoints()->resize(continuationPointVec_.size());

		for (uint32_t pos = 0; pos < continuationPointVec_.size(); pos++) {
			OpcUaByteString::SPtr continuationPoint = constructSPtr<OpcUaByteString>();
			continuationPoint->fromHexString(continuationPointVec_[pos]);
			req->continuationPoints()->set(pos, continuationPoint);
		}

		attributeService_->asyncSend(trx);
    }

    void
    AttributeServiceNode::attributeServiceBrowseNextResponse(
    	ServiceTransactionBrowseNext::SPtr serviceTransactionBrowseNext
    )
    {
    	OpcUaStatusCode statusCode;
    	BrowseNextResponse::SPtr res = serviceTransactionBrowseNext->response();
    	BrowseNextRequest::SPtr req = serviceTransactionBrowseNext->request();

    	// check response
    	statusCode = serviceTransactionBrowseNext->responseHeader()->serviceResult();
    	if (statusCode != Success) {
    		Log(Error, "browse next response error")
    			.parameter("StatusCode", OpcUaStatusCodeMap::longString(statusCode));
    		done(statusCode);
    		return;
    	}

    	// check browse results
    	if (res->results()->size() != nodeIdVec_.size()) {
    		Log(Error, "result array size in browse next response error")
    			.parameter("ArraySize", res->results()->size());
    		done(BadCommunicationError);
    		return;
    	}

		OpcUaNodeId::Vec tmpNodeIdVec;
		std::vector<ReferenceDescription::Vec> tmpReferenceDescriptionVecVec;
		std::vector<std::string> tmpContinuationPointVec;

    	for (uint32_t pos = 0; pos < nodeIdVec_.size(); pos++)
    	{

    		// check response data
    		BrowseResult::SPtr browseResult;
    		res->results()->get(pos, browseResult);
    		statusCode = browseResult->statusCode();
    		if (statusCode != Success) {
           		this->browseResult(statusCode, nodeIdVec_[pos], referenceDescriptionVecVec_[pos]);
            	continue;
    		}

      		// process browse response
        	ReferenceDescriptionArray::SPtr references = browseResult->references();

        	// no reference available
        	if (references->size() == 0) {
        		this->browseResult(Success, nodeIdVec_[pos], referenceDescriptionVecVec_[pos]);
        		continue;
        	}

        	// browse next references
        	ReferenceDescription::Vec referenceDescriptionVec;
        	for (uint32_t idx = 0; idx < references->size(); idx++) {
        		ReferenceDescription::SPtr referenceDescription;
        		references->get(idx, referenceDescription);
        		referenceDescriptionVec.push_back(referenceDescription);
        	}

        	// check continuation point
        	if (browseResult->continuationPoint().exist()) {
            	tmpNodeIdVec.push_back(nodeIdVec_[pos]);
            	tmpReferenceDescriptionVecVec.push_back(referenceDescriptionVec);
            	tmpContinuationPointVec.push_back(browseResult->continuationPoint().toHexString());
        		continue;
        	}

        	ReferenceDescription::Vec::iterator it;
        	for (it = referenceDescriptionVec.begin(); it != referenceDescriptionVec.end(); it++) {
        		referenceDescriptionVecVec_[pos].push_back(*it);
        	}
        	this->browseResult(Success, nodeIdVec_[pos], referenceDescriptionVecVec_[pos]);
    	}

    	// browse next
    	if (!tmpNodeIdVec.empty()) {
    		nodeIdVec_ = tmpNodeIdVec;
    		referenceDescriptionVecVec_ = tmpReferenceDescriptionVecVec;
    		continuationPointVec_ = tmpContinuationPointVec;
    		asyncReadNext();
    		return;
    	}

		done(Success);
    }

	void
	AttributeServiceNode::done(OpcUaStatusCode statusCode)
	{
		if (statusCode != Success && attributeServiceBrowseIf_ != nullptr) {
			attributeServiceBrowseIf_->done(statusCode);
		}

		if (recursive_ && nodeIdToReadSet_.size() != 0) {
			nodeIdVec_.clear();
			std::set<OpcUaNodeId>::iterator it;
			for (it = nodeIdToReadSet_.begin(); it != nodeIdToReadSet_.end(); it++) {
				if (nodeIdVec_.size() >= maxNodesInBrowse_) break;

				OpcUaNodeId tmp = *it;
				OpcUaNodeId::SPtr nodeId = constructSPtr<OpcUaNodeId>();
				nodeId->copyFrom(tmp);
				nodeIdVec_.push_back(nodeId);
			}

			asyncRead();
			return;
		}

		if (attributeServiceBrowseIf_ != nullptr) {
			attributeServiceBrowseIf_->done(statusCode);
		}
	}

	void
	AttributeServiceNode::browseResult(
		OpcUaStatusCode statusCode,
		OpcUaNodeId::SPtr& nodeId,
		ReferenceDescription::Vec& referenceDescriptionVec
	)
	{
		if (recursive_) {
			nodeIdToReadSet_.erase(*nodeId);
			nodeIdProcessedSet_.insert(*nodeId);

			ReferenceDescription::Vec::iterator it;
			for (it = referenceDescriptionVec.begin(); it != referenceDescriptionVec.end(); it++) {
				OpcUaNodeId refNodeId;
				refNodeId.nodeIdValue((*it)->expandedNodeId()->nodeIdValue());
				refNodeId.namespaceIndex((*it)->expandedNodeId()->namespaceIndex());

				if (nodeIdProcessedSet_.find(refNodeId) != nodeIdProcessedSet_.end()) {
					continue;
				}

				nodeIdToReadSet_.insert(refNodeId);
			}
		}

		// process browse result
		if (attributeServiceBrowseIf_ != nullptr) {
			attributeServiceBrowseIf_->browseResult(statusCode, nodeId, referenceDescriptionVec);
		}
	}

}
