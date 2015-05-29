#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackClient/ServiceAccess/NamespaceArray.h"
#include "OpcUaStackClient/ServiceSet/AttributeService.h"

namespace OpcUaStackClient
{

	NamespaceArray::NamespaceArray(void)
	: namespaceVec_()
	, session_()
	{
	}

	NamespaceArray::NamespaceArray(Session::SPtr session)
	: namespaceVec_()
	, session_(session)
	{
	}

	NamespaceArray::~NamespaceArray(void)
	{
	}

	void
	NamespaceArray::session(Session::SPtr session)
	{
		session_ = session;
	}
	bool
	NamespaceArray::readSync(void)
	{
		namespaceVec_.clear();
		AttributeService attributeService;
		attributeService.componentSession(session_->component());

		//
		// read namespace array
		//
		ServiceTransactionRead::SPtr readTrx = ServiceTransactionRead::construct();

		ReadValueId::SPtr readValueIdSPtr = ReadValueId::construct();
		readValueIdSPtr->nodeId((OpcUaInt16)0, (OpcUaInt32)2255);
		readValueIdSPtr->attributeId((OpcUaInt32) 13);
		readValueIdSPtr->dataEncoding().namespaceIndex((OpcUaInt16) 0);

		ReadRequest::SPtr req = readTrx->request();
		req->maxAge(0);
		req->timestampsToReturn(2);
		req->readValueIdArray()->set(readValueIdSPtr);

		attributeService.sendSync(readTrx);

		//
		// check response
		//
		if (readTrx->responseHeader()->serviceResult() != Success) {
			Log(Error, "read namespace array response error")
				.parameter("NodeId", readValueIdSPtr->nodeId())
				.parameter("AttributeId", readValueIdSPtr->attributeId())
				.parameter("ResultCode", OpcUaStatusCodeMap::longString(readTrx->responseHeader()->serviceResult()));
			return false;
		}
		if (readTrx->response()->dataValueArray()->size() != 1) {
			Log(Error, "read namespace array array size error")
				.parameter("NodeId", readValueIdSPtr->nodeId())
				.parameter("AttributeId", readValueIdSPtr->attributeId())
				.parameter("ArraySize", readTrx->response()->dataValueArray()->size());
			return false;
		}

		//
		// check data value
		//
		OpcUaDataValue::SPtr dataValue;
		readTrx->response()->dataValueArray()->get(0, dataValue);
		OpcUaVariant::SPtr variant = dataValue->variant();
		if (dataValue->statusCode() != Success) {
			Log(Error, "read namespace array data value error")
				.parameter("NodeId", readValueIdSPtr->nodeId())
				.parameter("AttributeId", readValueIdSPtr->attributeId())
				.parameter("StatusCode", OpcUaStatusCodeMap::longString(dataValue->statusCode()));
		}

		if (variant->arrayLength() == 0) {
			Log(Error, "read namespace array data value array length error")
				.parameter("NodeId", readValueIdSPtr->nodeId())
				.parameter("AttributeId", readValueIdSPtr->attributeId())
				.parameter("ValueArrayLen", variant->arrayLength());
		}

		//
		// add namespace array from data value into node set namespace array
		//
		for (int32_t idx=0; idx < variant->arrayLength(); idx++) {
			namespaceVec_.push_back(variant->variant()[idx].variantSPtr<OpcUaString>()->value());
		}

		return true;
	}

	std::vector<std::string>&
	NamespaceArray::namespaceVec(void)
	{
		return namespaceVec_;
	}

}
