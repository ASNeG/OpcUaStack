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
	, nodeId_()
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
	ViewServiceBrowse::nodeId(OpcUaNodeId& nodeId)
	{
		nodeId_ = constructSPtr<OpcUaNodeId>();
		nodeId_->copyFrom(nodeId);
	}

	void
	ViewServiceBrowse::nodeId(OpcUaNodeId::SPtr& nodeId)
	{
		nodeId_ = nodeId;
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

		req->nodesToBrowse()->resize(1);
		BrowseDescription::SPtr browseDescription = constructSPtr<BrowseDescription>();
		browseDescription->nodeId(nodeId_);
		browseDescription->browseDirection(BrowseDirection_Both);
		browseDescription->nodeClassMask(0xFFFFFFFF);
		browseDescription->resultMask(0xFFFFFFFF);
		req->nodesToBrowse()->push_back(browseDescription);

		viewService_->asyncSend(trx);
	}

    void
    ViewServiceBrowse::viewServiceBrowseResponse(ServiceTransactionBrowse::SPtr serviceTransactionBrowse)
    {
    	std::cout << "browse response..." << std::endl;

    	OpcUaStatusCode statusCode;
    	BrowseResponse::SPtr res = serviceTransactionBrowse->response();
    	BrowseRequest::SPtr req = serviceTransactionBrowse->request();

    	// check response
    	statusCode = serviceTransactionBrowse->responseHeader()->serviceResult();
    	if (statusCode != Success) {
    		Log(Error, "browse response error")
    			.parameter("NodeId", nodeId_->toString())
    			.parameter("StatusCode", OpcUaStatusCodeMap::longString(statusCode));
    		viewServiceBrowseIf_->done(statusCode);
    		return;
    	}

    	// check browse results
    	if (res->results()->size() != 1) {
    		Log(Error, "result array size in browse response error")
				.parameter("NodeId", nodeId_->toString())
    			.parameter("ArraySize", res->results()->size());
    		viewServiceBrowseIf_->done(BadCommunicationError);
    		return;
    	}

		// check response data
		BrowseResult::SPtr browseResult;
		res->results()->get(0, browseResult);
		statusCode = browseResult->statusCode();
		if (statusCode != Success) {
			Log(Error, "result node in browse response error")
				.parameter("NodeId", nodeId_->toString())
				.parameter("StatusCode", OpcUaStatusCodeMap::longString(statusCode));
			viewServiceBrowseIf_->done(statusCode);
			return;
		}

		// process browse response
		ReferenceDescriptionArray::SPtr references = browseResult->references();
		viewServiceBrowseIf_->browseResult(nodeId_, references);

		if (references->size() == 0) {
			viewServiceBrowseIf_->done(Success);
			return;
		}

		// browse next references
		for (uint32_t idx = 0; idx < references->size(); idx++) {
			ReferenceDescription::SPtr referenceDescription;
			references->get(idx, referenceDescription);
		}

		// check continuation point
		if (browseResult->continuationPoint().exist()) {
			asyncBrowseNext(browseResult->continuationPoint());
			return;
		}

		viewServiceBrowseIf_->done(Success);
    }

    void
    ViewServiceBrowse::asyncBrowseNext(OpcUaByteString& continuationPoint)
    {
    	ServiceTransactionBrowseNext::SPtr trx = constructSPtr<ServiceTransactionBrowseNext>();
		BrowseNextRequest::SPtr req = trx->request();

		OpcUaByteString::SPtr cp = constructSPtr<OpcUaByteString>();
		continuationPoint.copyTo(*cp);
		req->continuationPoints()->resize(1);
		req->continuationPoints()->set(0, cp);

		viewService_->asyncSend(trx);
    }

    void
    ViewServiceBrowse::viewServiceBrowseNextResponse(ServiceTransactionBrowseNext::SPtr serviceTransactionBrowseNext)
    {
    	std::cout << "browse next response..." << std::endl;

    	OpcUaStatusCode statusCode;
    	BrowseNextResponse::SPtr res = serviceTransactionBrowseNext->response();
    	BrowseNextRequest::SPtr req = serviceTransactionBrowseNext->request();

    	// check response
    	statusCode = serviceTransactionBrowseNext->responseHeader()->serviceResult();
    	if (statusCode != Success) {
    		Log(Error, "browse next response error")
    			.parameter("NodeId", nodeId_->toString())
    			.parameter("StatusCode", OpcUaStatusCodeMap::longString(statusCode));
    		viewServiceBrowseIf_->done(statusCode);
    		return;
    	}

    	// check browse results
    	if (res->results()->size() != 1) {
    		Log(Error, "result array size in browse next response error")
				.parameter("NodeId", nodeId_->toString())
    			.parameter("ArraySize", res->results()->size());
    		viewServiceBrowseIf_->done(BadCommunicationError);
    		return;
    	}

		// check response data
		BrowseResult::SPtr browseResult;
		res->results()->get(0, browseResult);
		statusCode = browseResult->statusCode();
		if (statusCode != Success) {
			Log(Error, "result node in browse next response error")
				.parameter("NodeId", nodeId_->toString())
				.parameter("StatusCode", OpcUaStatusCodeMap::longString(statusCode));
			viewServiceBrowseIf_->done(statusCode);
			return;
		}

		// process browse response
		ReferenceDescriptionArray::SPtr references = browseResult->references();
		viewServiceBrowseIf_->browseNextResult(nodeId_, references);

		if (references->size() == 0) {
			viewServiceBrowseIf_->done(Success);
			return;
		}

		// browse next references
		for (uint32_t idx = 0; idx < references->size(); idx++) {
			ReferenceDescription::SPtr referenceDescription;
			references->get(idx, referenceDescription);
		}

		// check continuation point
		if (browseResult->continuationPoint().exist()) {
			asyncBrowseNext(browseResult->continuationPoint());
			return;
		}

		viewServiceBrowseIf_->done(Success);
    }

}
