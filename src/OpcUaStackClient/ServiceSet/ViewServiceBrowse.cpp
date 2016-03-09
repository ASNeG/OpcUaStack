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
#include "OpcUaStackClient/ServiceSet/ViewServiceBrowse.h"

using namespace OpcUaStackCore;

namespace OpcUaStackClient
{

	ViewServiceBrowse::ViewServiceBrowse(void)
	: ViewServiceIf()
	, viewServiceBrowseIf_(nullptr)
	, viewService_()
	, nodeIdVec_()
	, direction_(BrowseDirection_Both)
	, recursive_(false)
	, referenceDescriptionVecVec_()
	, continuationPointVec_()
	{
	}

	ViewServiceBrowse::~ViewServiceBrowse(void)
	{
	}

	void
	ViewServiceBrowse::viewService(ViewService::SPtr& viewService)
	{
		viewService_ = viewService;
		viewService_->viewServiceIf(this);
	}

	void
	ViewServiceBrowse::nodeIdVec(OpcUaNodeId::Vec& nodeIdVec)
	{
		nodeIdVec_ = nodeIdVec;
	}

	void
	ViewServiceBrowse::direction(BrowseDirectionEnum direction)
	{
		direction_ = direction;
	}

	void
	ViewServiceBrowse::recursive(bool recursive)
	{
		recursive_ = recursive;
	}

	void
	ViewServiceBrowse::viewServiceBrowseIf(ViewServiceBrowseIf* viewServiceBrowseIf)
	{
		viewServiceBrowseIf_ = viewServiceBrowseIf;
	}

	void
	ViewServiceBrowse::asyncBrowse(void)
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

		viewService_->asyncSend(trx);
	}

    void
    ViewServiceBrowse::viewServiceBrowseResponse(ServiceTransactionBrowse::SPtr serviceTransactionBrowse)
    {
    	OpcUaStatusCode statusCode;
    	BrowseResponse::SPtr res = serviceTransactionBrowse->response();
    	BrowseRequest::SPtr req = serviceTransactionBrowse->request();

    	// check response
    	statusCode = serviceTransactionBrowse->responseHeader()->serviceResult();
    	if (statusCode != Success) {
    		Log(Error, "browse response error")
    			.parameter("StatusCode", OpcUaStatusCodeMap::longString(statusCode));
    		viewServiceBrowseIf_->done(statusCode);
    		return;
    	}

    	// check browse results
    	if (res->results()->size() != nodeIdVec_.size()) {
    		Log(Error, "result array size in browse response error")
    			.parameter("ArraySize", res->results()->size());
    		viewServiceBrowseIf_->done(BadCommunicationError);
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
    			Log(Error, "result node in browse response error")
					.parameter("NodeId", nodeIdVec_[pos]->toString())
					.parameter("StatusCode", OpcUaStatusCodeMap::longString(statusCode));
    			viewServiceBrowseIf_->done(statusCode);
    			return;
    		}

    		// process browse response
    		ReferenceDescription::Vec referenceDescriptionVec;
    		ReferenceDescriptionArray::SPtr references = browseResult->references();

    		// no reference available
    		if (references->size() == 0) {
    			viewServiceBrowseIf_->browseResult(nodeIdVec_[pos], referenceDescriptionVec);
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

    		viewServiceBrowseIf_->browseResult(nodeIdVec_[pos], referenceDescriptionVec);
    	}

    	// browse next
    	if (!tmpNodeIdVec.empty()) {
    		nodeIdVec_ = tmpNodeIdVec;
    		referenceDescriptionVecVec_ = tmpReferenceDescriptionVecVec;
    		continuationPointVec_ = tmpContinuationPointVec;
    		asyncBrowseNext();
    		return;
    	}

		viewServiceBrowseIf_->done(Success);
    }

    void
    ViewServiceBrowse::asyncBrowseNext(void)
    {
    	ServiceTransactionBrowseNext::SPtr trx = constructSPtr<ServiceTransactionBrowseNext>();
		BrowseNextRequest::SPtr req = trx->request();

		req->continuationPoints()->resize(continuationPointVec_.size());

		for (uint32_t pos = 0; pos < continuationPointVec_.size(); pos++) {
			OpcUaByteString::SPtr continuationPoint = constructSPtr<OpcUaByteString>();
			continuationPoint->fromHexString(continuationPointVec_[pos]);
			req->continuationPoints()->set(pos, continuationPoint);
		}

		viewService_->asyncSend(trx);
    }

    void
    ViewServiceBrowse::viewServiceBrowseNextResponse(ServiceTransactionBrowseNext::SPtr serviceTransactionBrowseNext)
    {
    	OpcUaStatusCode statusCode;
    	BrowseNextResponse::SPtr res = serviceTransactionBrowseNext->response();
    	BrowseNextRequest::SPtr req = serviceTransactionBrowseNext->request();

    	// check response
    	statusCode = serviceTransactionBrowseNext->responseHeader()->serviceResult();
    	if (statusCode != Success) {
    		Log(Error, "browse next response error")
    			.parameter("StatusCode", OpcUaStatusCodeMap::longString(statusCode));
    		viewServiceBrowseIf_->done(statusCode);
    		return;
    	}

    	// check browse results
    	if (res->results()->size() != nodeIdVec_.size()) {
    		Log(Error, "result array size in browse next response error")
    			.parameter("ArraySize", res->results()->size());
    		viewServiceBrowseIf_->done(BadCommunicationError);
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
    			Log(Error, "result node in browse next response error")
					.parameter("NodeId", nodeIdVec_[pos]->toString())
					.parameter("StatusCode", OpcUaStatusCodeMap::longString(statusCode));
    			viewServiceBrowseIf_->done(statusCode);
    			return;
    		}

      		// process browse response
        	ReferenceDescriptionArray::SPtr references = browseResult->references();

        	// no reference available
        	if (references->size() == 0) {
        		viewServiceBrowseIf_->browseResult(nodeIdVec_[pos], referenceDescriptionVecVec_[pos]);
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
        	viewServiceBrowseIf_->browseResult(nodeIdVec_[pos], referenceDescriptionVecVec_[pos]);
    	}

    	// browse next
    	if (!tmpNodeIdVec.empty()) {
    		nodeIdVec_ = tmpNodeIdVec;
    		referenceDescriptionVecVec_ = tmpReferenceDescriptionVecVec;
    		continuationPointVec_ = tmpContinuationPointVec;
    		asyncBrowseNext();
    		return;
    	}

		viewServiceBrowseIf_->done(Success);
    }

}
