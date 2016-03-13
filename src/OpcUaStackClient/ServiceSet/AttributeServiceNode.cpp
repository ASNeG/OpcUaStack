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
	, nodeId_()
	, attributeIdVec_()
	{
	}

	AttributeServiceNode::~AttributeServiceNode(void)
	{
	}

	void
	AttributeServiceNode::attributeService(AttributeService::SPtr& attributeService)
	{
		attributeService_ = attributeService;
		attributeService_->attributeServiceIf(this);
	}

	void
	AttributeServiceNode::attributeServiceBrowseIf(AttributeServiceNodeIf* attributeServiceBrowseIf)
	{
		attributeServiceBrowseIf_ = attributeServiceBrowseIf;
	}

	void
	AttributeServiceNode::nodeId(OpcUaNodeId& nodeId)
	{
		nodeId_ = nodeId;
	}

	void
	AttributeServiceNode::attributeIds(
		AttributeId& attributeId1
	)
	{
		attributeIdVec_.push_back(attributeId1);
	}

	void
	AttributeServiceNode::attributeIds(
		AttributeId& attributeId1,
		AttributeId& attributeId2
	)
	{
		attributeIdVec_.push_back(attributeId1);
		attributeIdVec_.push_back(attributeId2);
	}

	void
	AttributeServiceNode::attributeIds(
		AttributeId& attributeId1,
		AttributeId& attributeId2,
		AttributeId& attributeId3
	)
	{
		attributeIdVec_.push_back(attributeId1);
		attributeIdVec_.push_back(attributeId2);
		attributeIdVec_.push_back(attributeId3);
	}

	void
	AttributeServiceNode::attributeIds(
		AttributeId& attributeId1,
		AttributeId& attributeId2,
		AttributeId& attributeId3,
		AttributeId& attributeId4
	)
	{
		attributeIdVec_.push_back(attributeId1);
		attributeIdVec_.push_back(attributeId2);
		attributeIdVec_.push_back(attributeId3);
		attributeIdVec_.push_back(attributeId4);
	}

	void
	AttributeServiceNode::attributeIds(
		AttributeId& attributeId1,
		AttributeId& attributeId2,
		AttributeId& attributeId3,
		AttributeId& attributeId4,
		AttributeId& attributeId5
	)
	{
		attributeIdVec_.push_back(attributeId1);
		attributeIdVec_.push_back(attributeId2);
		attributeIdVec_.push_back(attributeId3);
		attributeIdVec_.push_back(attributeId4);
		attributeIdVec_.push_back(attributeId5);
	}

	void
	AttributeServiceNode::asyncReadNode(void)
	{
		AttributeServiceIfTestHandler attributeServiceIfTestHandler;

		// create read transaction
		ServiceTransactionRead::SPtr trx = constructSPtr<ServiceTransactionRead>();
		ReadRequest::SPtr req = trx->request();

		// create read request
		req->readValueIdArray()->resize(attributeIdVec_.size());
		std::vector<AttributeId>::iterator it;
		for (it = attributeIdVec_.begin(); it != attributeIdVec_.end(); it++) {
			ReadValueId::SPtr readValueIdSPtr = ReadValueId::construct();
			readValueIdSPtr->nodeId()->copyFrom(nodeId_);
			readValueIdSPtr->attributeId((OpcUaInt32)*it);
			readValueIdSPtr->dataEncoding().namespaceIndex((OpcUaInt16) 0);
			req->readValueIdArray()->push_back(readValueIdSPtr);
		}

		// send read request
		attributeService_->asyncSend(trx);
	}

	void
	AttributeServiceNode::attributeServiceReadResponse(ServiceTransactionRead::SPtr serviceTransactionRead)
	{
	   	OpcUaStatusCode statusCode;
	    ReadResponse::SPtr res = serviceTransactionRead->response();

	    // check response
	    statusCode = serviceTransactionRead->responseHeader()->serviceResult();
	    if (statusCode != Success) {
	    	Log(Error, "read node response error")
	    		.parameter("StatusCode", OpcUaStatusCodeMap::longString(statusCode));
	    	attributeServiceBrowseIf_->done(statusCode);
	    	return;
	    }

    	// check read results
    	if (res->dataValueArray()->size() != attributeIdVec_.size()) {
    		Log(Error, "result array size in read node response error")
    			.parameter("ArraySize", res->dataValueArray()->size());
    		attributeServiceBrowseIf_->done(BadCommunicationError);
    		return;
    	}

    	// read attributes
    	for (uint32_t pos = 0; pos < attributeIdVec_.size(); pos++)
    	{
    		OpcUaDataValue::SPtr dataValue;
    		res->dataValueArray()->get(pos, dataValue);
    		attributeServiceBrowseIf_->readResult(dataValue);
    	}

    	attributeServiceBrowseIf_->done(Success);
	}

}
