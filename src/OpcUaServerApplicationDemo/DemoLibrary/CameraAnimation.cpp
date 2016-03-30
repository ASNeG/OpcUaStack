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
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackServer/ServiceSetApplication/ApplicationService.h"
#include "OpcUaServerApplicationDemo/DemoLibrary/CameraAnimation.h"

namespace OpcUaServerApplicationDemo
{

	CameraAnimation::CameraAnimation(void)
	: ioThread_(nullptr)
	, applicationServiceIf_(nullptr)
	, namespaceIndex_(0)
	, valueMap_()
	{
	}

	CameraAnimation::~CameraAnimation(void)
	{
	}

	bool
	CameraAnimation::startup(IOThread& ioThread, ApplicationServiceIf& applicationServiceIf)
	{
		ioThread_ = &ioThread;
		applicationServiceIf_ = &applicationServiceIf;

		// read namespace array from opc ua server
		if (!getNamespaceInfo()) {
			return false;
		}

		// create value map
		if (!createValueMap()) {
			return false;
		}

		return true;
	}

	bool
	CameraAnimation::shutdown(void)
	{
		return true;
	}

	bool
	CameraAnimation::getNamespaceInfo(void)
	{
		ServiceTransactionNamespaceInfo::SPtr trx = ServiceTransactionNamespaceInfo::construct();
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
			if (it->second == "http://ASNeG.de/Camera/") {
				namespaceIndex_ = it->first;
				return true;
			}
 		}

		Log(Error, "namespace not found in configuration")
	        .parameter("NamespaceUri", "http://ASNeG.de/Camera/");

		return true;
	}

	bool
	CameraAnimation::createValueMap(void)
	{
		OpcUaNodeId nodeId;
		OpcUaDataValue::SPtr dataValue;

		// SByte ns=1;s=Camera.1
		nodeId.set("Camera.1", namespaceIndex_);
		OpcUaByteString::SPtr byteString = constructSPtr<OpcUaByteString>();
		byteString->value("0123456789");
		dataValue = createDataValue();
		dataValue->variant()->variant(byteString);
		valueMap_.insert(std::make_pair(nodeId, dataValue));
	}

	OpcUaDataValue::SPtr
	CameraAnimation::createDataValue(void)
	{
		OpcUaDataValue::SPtr dataValue;
		dataValue = constructSPtr<OpcUaDataValue>();
		dataValue->statusCode(Success);
		dataValue->sourceTimestamp(OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
		dataValue->serverTimestamp(OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
		return dataValue;
	}

}
