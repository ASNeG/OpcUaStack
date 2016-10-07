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

#include <boost/filesystem.hpp>
#include <boost/filesystem/fstream.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackCore/Base/ConfigXml.h"
#include "OpcUaStackCore/Utility/Environment.h"
#include "OpcUaStackServer/ServiceSetApplication/ApplicationService.h"
#include "OpcUaStackServer/ServiceSetApplication/NodeReferenceApplication.h"
#include "OpcUaServerApplicationDemo/DemoLibrary/CameraAnimation.h"

namespace OpcUaServerApplicationDemo
{

	CameraAnimation::CameraAnimation(void)
	: ioThread_(nullptr)
	, slotTimerElement_()
	, applicationServiceIf_(nullptr)
	, applicationInfo_(nullptr)
	, namespaceIndex_(0)
	, valueMap_()
	, baseNodeClassWMap_()
	, countPics_(5)
	, sampleTimeout_(1000)
	, byteStringVec_()
	, byteStringVecIdx_(0)
	{
	}

	CameraAnimation::~CameraAnimation(void)
	{
		slotTimerElement_.reset();
	}

	bool
	CameraAnimation::startup(
		IOThread& ioThread,
		ApplicationServiceIf& applicationServiceIf,
		ApplicationInfo* applicationInfo
	)
	{
		Log(Debug, "CameraAnimation::startup");
		
		// FIXME: this modul do not work on winows systems
		return true;

		ioThread_ = &ioThread;
		applicationServiceIf_ = &applicationServiceIf;
		applicationInfo_ = applicationInfo;

		// read namespace array from opc ua server
		if (!getNamespaceInfo()) {
			return false;
		}

		// create value map
		if (!createValueMap()) {
			return false;
		}

		// create node references
		if (!createNodeReferences()) {
			return false;
		}

		if (!loadPics()) {
			return false;
		}

		startSample();

		return true;
	}

	bool
	CameraAnimation::shutdown(void)
	{
		Log(Debug, "CameraAnimation::shutdown");

		// FIXME: this modul do not work on winows systems
		return true;

		stopSample();
		return true;
	}

	bool
	CameraAnimation::getNamespaceInfo(void)
	{
		Log(Debug, "get namespace info");

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

		return false;
	}

	bool
	CameraAnimation::createValueMap(void)
	{
		Log(Debug, "create value map");

		OpcUaNodeId nodeId;
		OpcUaDataValue::SPtr dataValue;

		// SByte ns=1;s=Camera.1
		nodeId.set("Camera.1", namespaceIndex_);
		OpcUaByteString::SPtr byteString = constructSPtr<OpcUaByteString>();
		byteString->value("0123456789");
		dataValue = createDataValue();
		dataValue->variant()->variant(byteString);
		valueMap_.insert(std::make_pair(nodeId, dataValue));
		return true;
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

	bool
	CameraAnimation::createNodeReferences(void)
	{
		Log(Debug, "create node reference");

		ServiceTransactionGetNodeReference::SPtr trx = ServiceTransactionGetNodeReference::construct();
		GetNodeReferenceRequest::SPtr req = trx->request();
		GetNodeReferenceResponse::SPtr res = trx->response();

	  	uint32_t pos = 0;
	  	ValueMap::iterator it;
	  	req->nodes()->resize(valueMap_.size());
	  	for (it = valueMap_.begin(); it != valueMap_.end(); it++) {
	  		OpcUaNodeId::SPtr nodeId = constructSPtr<OpcUaNodeId>();
	  		*nodeId = it->first;

	  		req->nodes()->set(pos, nodeId);
	  		pos++;
	  	}

	  	applicationServiceIf_->sendSync(trx);
	  	if (trx->statusCode() != Success) {
	  		Log(Error, "response get node reference error")
	  			.parameter("StatusCode", OpcUaStatusCodeMap::shortString(trx->statusCode()));
	  		return false;
	  	}

	  	for (pos = 0; pos < res->nodeReferenceArray()->size(); pos++) {
	  		NodeReference::SPtr nodeReference;
	  		res->nodeReferenceArray()->get(pos, nodeReference);
	  		if (nodeReference->statusCode() != Success) {
		  		Log(Error, "response get node reference node error")
		  			.parameter("StatusCode", OpcUaStatusCodeMap::shortString(nodeReference->statusCode()));
	  			return false;
	  		}

	  		OpcUaNodeId::SPtr nodeId;
	  		req->nodes()->get(pos, nodeId);

	  		NodeReferenceApplication::SPtr nodeReferenceApplication;
	  		nodeReferenceApplication = boost::static_pointer_cast<NodeReferenceApplication>(nodeReference);
	  		baseNodeClassWMap_.insert(std::make_pair(*nodeId, nodeReferenceApplication->baseNodeClass()));
	  	}

		return true;
	}

	bool
	CameraAnimation::loadPics(void)
	{
		Config config;
		ConfigXml configXml;

		// read configuration file
		config.alias("@BIN_DIR@", Environment::binDir());
		config.alias("@CONF_DIR@", Environment::confDir());
		config.alias("@LOG_DIR@", Environment::logDir());
		config.alias("@INSTALL_DIR@", Environment::installDir());

		Log(Debug, "load camera model") 
		    .parameter("ConfigFileName", applicationInfo_->configFileName());

		boost::filesystem::path configFileName(applicationInfo_->configFileName());  
		if (configXml.parse(configFileName.string(), &config) == false) {
			Log(Error, "read configuration error")
				.parameter("ConfigFileName", configFileName.string())
				.parameter("Reason", configXml.errorMessage());
			return false;
		}

		// read configuration parameter
		boost::optional<std::string> cameraPath = config.getValue("CameraModel.CameraPath.<xmlattr>.File");
		if (!cameraPath) {
			Log(Error, "camera path do not exist in configuration file")
				.parameter("Variable", "CameraModel.CameraPath.<xmlattr>.File")
				.parameter("ConfigFileName", applicationInfo_->configFileName());
			return false;
		}

		if (!config.getConfigParameter("CameraModel.CameraPath.<xmlattr>.SampleTimeout", sampleTimeout_)) {
			Log(Error, "sample timeout do not exist in configuration file")
				.parameter("Variable", "CameraModel.CameraPath.<xmlattr>.File")
				.parameter("ConfigFileName", applicationInfo_->configFileName());
			return false;
		}

		// read camera pictures
		uint32_t idx = 0;
		bool readNext = true;
		while (readNext)
		{
			std::stringstream file;
			file << "animation" << std::setfill('0') << std::setw(2) << idx << ".gif";

			boost::filesystem::path cameraFile;
			cameraFile = *cameraPath;
			cameraFile /= file.str();

			// check if file exists
			if (!boost::filesystem::exists(cameraFile)) {
				Log(Error, "camera image file not exist")
				    .parameter("ImageFile", cameraFile.c_str());
				readNext = false;
				continue;
			}

			// get file size an reallocate buffer
			uint32_t bufferLen = boost::filesystem::file_size(cameraFile);
			char buffer[1000000];

			// read image file
			try {
				boost::filesystem::path imageFile(cameraFile);
				boost::filesystem::ifstream ifs(imageFile);
				std::istream is(ifs.rdbuf());
				is.read(buffer, bufferLen);
			} catch (...)
			{
				readNext = false;
			}
			if (readNext == false) {
				Log(Error, "camera image file read failed")
				    .parameter("ImageFile", cameraFile.c_str());
				return false;
			}

			OpcUaByteString::SPtr value = constructSPtr<OpcUaByteString>();
			value->value(buffer, bufferLen);
			byteStringVec_.push_back(value);

			idx++;
		}

		if (byteStringVec_.size() == 0) {
			Log(Error, "camera image file not exist");
		    return false;
		}

		Log(Debug, "load camera model done");
		return true;
	}

	void
	CameraAnimation::startSample(void)
	{
		Log(Debug, "start sample");

		slotTimerElement_ = constructSPtr<SlotTimerElement>();
		slotTimerElement_->callback().reset(boost::bind(&CameraAnimation::sample, this));
		slotTimerElement_->expireTime(boost::posix_time::microsec_clock::local_time(), sampleTimeout_);
		ioThread_->slotTimer()->start(slotTimerElement_);
	}

	void
	CameraAnimation::stopSample(void)
	{
		ioThread_->slotTimer()->stop(slotTimerElement_);
	}

	void
	CameraAnimation::sample(void)
	{
		// get reference to base node class
		BaseNodeClass::SPtr baseNodeClass = baseNodeClassWMap_.begin()->second.lock();
		if (baseNodeClass.get() == nullptr) {
			Log(Error, "camera opc ua node no longer exist");
			return;
		}

		if (byteStringVec_.size() == 0) {
			return;
		}

		byteStringVecIdx_++;
		if (byteStringVecIdx_ >= byteStringVec_.size()) {
			byteStringVecIdx_ = 0;
		}

		OpcUaDateTime dateTime(boost::posix_time::microsec_clock::local_time());
		OpcUaDataValue dataValue;
		dataValue.variant()->set(byteStringVec_[byteStringVecIdx_]);
		dataValue.sourceTimestamp(dateTime);
		dataValue.serverTimestamp(dateTime);
		baseNodeClass->setValue(dataValue);
	}

}
