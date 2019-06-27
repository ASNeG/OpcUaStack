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
	, attributeServiceNodeIf_(nullptr)
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
	AttributeServiceNode::attributeServiceNodeIf(AttributeServiceNodeIf* attributeServiceNodeIf)
	{
		attributeServiceNodeIf_ = attributeServiceNodeIf;
	}

	void
	AttributeServiceNode::nodeId(OpcUaNodeId& nodeId)
	{
		nodeId_ = nodeId;
	}

	void
	AttributeServiceNode::attributeIds(
		const AttributeId& attributeId1
	)
	{
		attributeIdVec_.clear();
		attributeIdVec_.push_back(attributeId1);
	}

	void
	AttributeServiceNode::attributeIds(
		const AttributeId& attributeId1,
		const AttributeId& attributeId2
	)
	{
		attributeIdVec_.clear();
		attributeIdVec_.push_back(attributeId1);
		attributeIdVec_.push_back(attributeId2);
	}

	void
	AttributeServiceNode::attributeIds(
		const AttributeId& attributeId1,
		const AttributeId& attributeId2,
		const AttributeId& attributeId3
	)
	{
		attributeIdVec_.clear();
		attributeIdVec_.push_back(attributeId1);
		attributeIdVec_.push_back(attributeId2);
		attributeIdVec_.push_back(attributeId3);
	}

	void
	AttributeServiceNode::attributeIds(
		const AttributeId& attributeId1,
		const AttributeId& attributeId2,
		const AttributeId& attributeId3,
		const AttributeId& attributeId4
	)
	{
		attributeIdVec_.clear();
		attributeIdVec_.push_back(attributeId1);
		attributeIdVec_.push_back(attributeId2);
		attributeIdVec_.push_back(attributeId3);
		attributeIdVec_.push_back(attributeId4);
	}

	void
	AttributeServiceNode::attributeIds(
		const AttributeId& attributeId1,
		const AttributeId& attributeId2,
		const AttributeId& attributeId3,
		const AttributeId& attributeId4,
		const AttributeId& attributeId5
	)
	{
		attributeIdVec_.clear();
		attributeIdVec_.push_back(attributeId1);
		attributeIdVec_.push_back(attributeId2);
		attributeIdVec_.push_back(attributeId3);
		attributeIdVec_.push_back(attributeId4);
		attributeIdVec_.push_back(attributeId5);
	}

	void
	AttributeServiceNode::attributeIds(NodeClassType nodeClassType)
	{
		attributeIdVec_.clear();

		// set common attributes
		attributeIdVec_.push_back(AttributeId_BrowseName);
		attributeIdVec_.push_back(AttributeId_DisplayName);
		attributeIdVec_.push_back(AttributeId_Description);
		attributeIdVec_.push_back(AttributeId_WriteMask);
		attributeIdVec_.push_back(AttributeId_UserWriteMask);

		// set node class specific attributes
		switch (nodeClassType)
		{
			case NodeClassType_Object:
			{
				attributeIdVec_.push_back(AttributeId_EventNotifier);
				break;
			}
			case NodeClassType_Variable:
			{
				attributeIdVec_.push_back(AttributeId_AccessLevel);
				attributeIdVec_.push_back(AttributeId_ArrayDimensions);
				attributeIdVec_.push_back(AttributeId_DataType);
				attributeIdVec_.push_back(AttributeId_Historizing);
				attributeIdVec_.push_back(AttributeId_MinimumSamplingInterval);
				attributeIdVec_.push_back(AttributeId_UserAccessLevel);
				//attributeIdVec_.push_back(AttributeId_Value);
				attributeIdVec_.push_back(AttributeId_ValueRank);
				break;
			}
			case NodeClassType_Method:
			{
				attributeIdVec_.push_back(AttributeId_Executable);
				attributeIdVec_.push_back(AttributeId_UserExecutable);
				break;
			}
			case NodeClassType_ObjectType:
			{
				attributeIdVec_.push_back(AttributeId_IsAbstract);
				break;
			}
			case NodeClassType_VariableType:
			{
				attributeIdVec_.push_back(AttributeId_ArrayDimensions);
				attributeIdVec_.push_back(AttributeId_DataType);
				attributeIdVec_.push_back(AttributeId_IsAbstract);
				attributeIdVec_.push_back(AttributeId_Value);
				attributeIdVec_.push_back(AttributeId_ValueRank);
				break;
			}
			case NodeClassType_ReferenceType:
			{
				attributeIdVec_.push_back(AttributeId_InverseName);
				attributeIdVec_.push_back(AttributeId_IsAbstract);
				attributeIdVec_.push_back(AttributeId_Symmetric);
				break;
			}
			case NodeClassType_DataType:
			{
				attributeIdVec_.push_back(AttributeId_IsAbstract);
				break;
			}
			case NodeClassType_View:
			{
				attributeIdVec_.push_back(AttributeId_ContainsNoLoops);
				attributeIdVec_.push_back(AttributeId_EventNotifier);
				break;
			}
			default:
			{
				OpcUaStatusCode statusCode = BadInvalidArgument;
		    	Log(Error, "node class error in read node request")
		    		.parameter("StatusCode", OpcUaStatusCodeMap::longString(statusCode))
		    		.parameter("NodeClass", nodeClassType);
		    	attributeServiceNodeIf_->attributeServiceNodeDone(statusCode);
		    	return;
			}
		}
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
			ReadValueId::SPtr readValueIdSPtr = constructSPtr<ReadValueId>();
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
	    	attributeServiceNodeIf_->attributeServiceNodeDone(statusCode);
	    	return;
	    }

    	// check read results
    	if (res->dataValueArray()->size() != attributeIdVec_.size()) {
    		Log(Error, "result array size in read node response error")
    			.parameter("ArraySize", res->dataValueArray()->size());
    		attributeServiceNodeIf_->attributeServiceNodeDone(BadCommunicationError);
    		return;
    	}

    	// read attributes
    	for (uint32_t pos = 0; pos < attributeIdVec_.size(); pos++)
    	{
    		OpcUaDataValue::SPtr dataValue;
    		res->dataValueArray()->get(pos, dataValue);
    		attributeServiceNodeIf_->attributeServiceNodeResult(attributeIdVec_[pos], dataValue);
    	}

    	attributeServiceNodeIf_->attributeServiceNodeDone(Success);
	}

}
