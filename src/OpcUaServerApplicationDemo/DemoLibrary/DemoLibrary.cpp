/*
   Copyright 2015 Kai Huebl (kai@huebl-sgh.de)

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
#include "OpcUaServerApplicationDemo/DemoLibrary/DemoLibrary.h"
#include "OpcUaStackServer/ServiceSetApplication/ApplicationService.h"
#include "OpcUaStackServer/ServiceSetApplication/NodeReferenceApplication.h"
#include <iostream>

namespace OpcUaServerApplicationDemo
{

	DemoLibrary::DemoLibrary(void)
	: ApplicationIf()
	, namespaceIndex_(0)
	, loopTime_()
	, readCallback_(boost::bind(&DemoLibrary::readValue, this, _1))
	, readLoopTimeCallback_(boost::bind(&DemoLibrary::readLoopTimeValue, this, _1))
	, writeCallback_(boost::bind(&DemoLibrary::writeValue, this, _1))
	, writeLoopTimeCallback_(boost::bind(&DemoLibrary::writeLoopTimeValue, this, _1))
	, valueMap_()
	, ioService_()
	, slotTimer_()
	, slotTimerElement_()
	{
		loopTime_ = createDataValue();
		loopTime_->variant()->variant((uint32_t)0);

		std::cout << "DemoLibrary::construct" << std::endl;
	}

	DemoLibrary::~DemoLibrary(void)
	{
		std::cout << "DemoLibrary::destruct" << std::endl;
	}

	bool
	DemoLibrary::startup(void)
	{
		std::cout << "DemoLibrary::startup" << std::endl;

		// read namespace info from server service
		if (!getNamespaceInfo()) {
			return false;
		}

		// create value map
		if (!createValueMap()) {
			return false;
		}

		// register read and write callbacks
		if (!registerCallbacks()) {
			return false;
		}

		// register loop time callbacks
		if (!registerLoopTimeCallbacks()) {
			return false;
		}

		// create node references
		if (!createNodeReferences()) {
			return false;
		}

		ioService_.start();
		slotTimer_.startSlotTimerLoop(&ioService_);

		startTimerLoop();

		return true;
	}

	bool
	DemoLibrary::shutdown(void)
	{
		std::cout << "DemoLibrary::shutdown" << std::endl;

		slotTimer_.stopSlotTimerLoop();
		ioService_.stop();

		return true;
	}

	bool
	DemoLibrary::getNamespaceInfo(void)
	{
		ServiceTransactionNamespaceInfo::SPtr trx = ServiceTransactionNamespaceInfo::construct();
		NamespaceInfoRequest::SPtr req = trx->request();
		NamespaceInfoResponse::SPtr res = trx->response();

		service().sendSync(trx);
		if (trx->statusCode() != Success) {
			std::cout << "NamespaceInfoResponse error" << std::endl;
			return false;
		}

		NamespaceInfoResponse::Index2NamespaceMap::iterator it;
		for (
		    it = res->index2NamespaceMap().begin();
			it != res->index2NamespaceMap().end();
			it++
		)
		{
			std::cout << "Index=" << it->first << " Namespace=" << it->second << std::endl;
			if (it->second == "http://yourorganisation.org/Test-Server-Lib/") {
				namespaceIndex_ = it->first;
			}
 		}

		return true;
	}

	OpcUaDataValue::SPtr
	DemoLibrary::createDataValue(void)
	{
		OpcUaDataValue::SPtr dataValue;
		dataValue = constructSPtr<OpcUaDataValue>();
		dataValue->statusCode(Success);
		dataValue->sourceTimestamp(OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
		dataValue->serverTimestamp(OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
		return dataValue;
	}

	bool
	DemoLibrary::createValueMap(void)
	{
		OpcUaNodeId nodeId;
		OpcUaDataValue::SPtr dataValue;

		// SByte
		nodeId.set(200, namespaceIndex_);
		OpcUaSByte sByte(11);
		dataValue = createDataValue();
		dataValue->variant()->variant(sByte);
		valueMap_.insert(std::make_pair(nodeId, dataValue));

		// SByteByteArray
		nodeId.set(201, namespaceIndex_);
		dataValue = createDataValue();
		for (uint32_t pos=0; pos<3;pos++) dataValue->variant()->pushBack((OpcUaSByte)pos);
		valueMap_.insert(std::make_pair(nodeId, dataValue));

		// Byte
		nodeId.set(202, namespaceIndex_);
		OpcUaByte byte(32);
		dataValue = createDataValue();
		dataValue->variant()->variant(byte);
		valueMap_.insert(std::make_pair(nodeId, dataValue));

		// ByteByteArray
		nodeId.set(203, namespaceIndex_);
		dataValue = createDataValue();
		for (uint32_t pos=0; pos<3;pos++) dataValue->variant()->pushBack((OpcUaByte)pos);
		valueMap_.insert(std::make_pair(nodeId, dataValue));

		// Int16
		nodeId.set(204, namespaceIndex_);
		OpcUaInt16 int16(25);
		dataValue = createDataValue();
		dataValue->variant()->variant(int16);
		valueMap_.insert(std::make_pair(nodeId, dataValue));

		// Int16Array
		nodeId.set(205, namespaceIndex_);
		dataValue = createDataValue();
		for (uint32_t pos=0; pos<3;pos++) dataValue->variant()->pushBack((OpcUaInt16)(pos*2));
		valueMap_.insert(std::make_pair(nodeId, dataValue));

		// UInt16
		nodeId.set(206, namespaceIndex_);
		OpcUaUInt16 uint16(50);
		dataValue = createDataValue();
		dataValue->variant()->variant(uint16);
		valueMap_.insert(std::make_pair(nodeId, dataValue));

		// UInt16Array
		nodeId.set(207, namespaceIndex_);
		dataValue = createDataValue();
		for (uint32_t pos=0; pos<3;pos++) dataValue->variant()->pushBack((OpcUaUInt16)(pos*3));
		valueMap_.insert(std::make_pair(nodeId, dataValue));

		// Int32
		nodeId.set(208, namespaceIndex_);
		OpcUaInt32 int32(180);
		dataValue = createDataValue();
		dataValue->variant()->variant(int32);
		valueMap_.insert(std::make_pair(nodeId, dataValue));

		// Int32Array
		nodeId.set(209, namespaceIndex_);
		dataValue = createDataValue();
		for (uint32_t pos=0; pos<3;pos++) dataValue->variant()->pushBack((OpcUaInt32)(pos*4));
		valueMap_.insert(std::make_pair(nodeId, dataValue));

		// UInt32
		nodeId.set(210, namespaceIndex_);
		OpcUaUInt32 uint32(180);
		dataValue = createDataValue();
		dataValue->variant()->variant(uint32);
		valueMap_.insert(std::make_pair(nodeId, dataValue));

		// UInt32Array
		nodeId.set(211, namespaceIndex_);
		dataValue = createDataValue();
		for (uint32_t pos=0; pos<3;pos++) dataValue->variant()->pushBack((OpcUaUInt32)(pos*5));
		valueMap_.insert(std::make_pair(nodeId, dataValue));

		// Int64
		nodeId.set(212, namespaceIndex_);
		OpcUaInt64 int64(0);
		dataValue = createDataValue();
		dataValue->variant()->variant(int64);
		valueMap_.insert(std::make_pair(nodeId, dataValue));

		// Int64Array
		nodeId.set(213, namespaceIndex_);
		dataValue = createDataValue();
		for (uint32_t pos=0; pos<3;pos++) dataValue->variant()->pushBack((OpcUaInt64)(pos*6));
		valueMap_.insert(std::make_pair(nodeId, dataValue));

		// UInt64
		nodeId.set(214, namespaceIndex_);
		OpcUaUInt64 uint64(1500);
		dataValue = createDataValue();
		dataValue->variant()->variant(uint64);
		valueMap_.insert(std::make_pair(nodeId, dataValue));

		// UInt64Array
		nodeId.set(215, namespaceIndex_);
		dataValue = createDataValue();
		for (uint32_t pos=0; pos<3;pos++) dataValue->variant()->pushBack((OpcUaUInt64)(pos*5));
		valueMap_.insert(std::make_pair(nodeId, dataValue));

		// Float
		nodeId.set(216, namespaceIndex_);
		OpcUaFloat floats(500);
		dataValue = createDataValue();
		dataValue->variant()->variant(floats);
		valueMap_.insert(std::make_pair(nodeId, dataValue));

		// FloatArray
		nodeId.set(217, namespaceIndex_);
		dataValue = createDataValue();
		for (uint32_t pos=0; pos<3;pos++) dataValue->variant()->pushBack((OpcUaFloat)(pos*6.7));
		valueMap_.insert(std::make_pair(nodeId, dataValue));

		// Double
		nodeId.set(218, namespaceIndex_);
		OpcUaDouble doubles(500);
		dataValue = createDataValue();
		dataValue->variant()->variant(doubles);
		valueMap_.insert(std::make_pair(nodeId, dataValue));

		// DoubleArray
		nodeId.set(219, namespaceIndex_);
		dataValue = createDataValue();
		for (uint32_t pos=0; pos<3;pos++) dataValue->variant()->pushBack((OpcUaDouble)(pos*7.23));
		valueMap_.insert(std::make_pair(nodeId, dataValue));

		// Boolean
		nodeId.set(220, namespaceIndex_);
		OpcUaBoolean boolean(true);
		dataValue = createDataValue();
		dataValue->variant()->variant(boolean);
		valueMap_.insert(std::make_pair(nodeId, dataValue));

		// DoubleArray
		nodeId.set(221, namespaceIndex_);
		dataValue = createDataValue();
		for (uint32_t pos=0; pos<3;pos++) dataValue->variant()->pushBack((OpcUaBoolean)false);
		valueMap_.insert(std::make_pair(nodeId, dataValue));

		// String
		nodeId.set(222, namespaceIndex_);
		OpcUaString::SPtr str = constructSPtr<OpcUaString>();
		dataValue->variant()->variant(str);
		valueMap_.insert(std::make_pair(nodeId, dataValue));

		// StringArray
		nodeId.set(223, namespaceIndex_);
		dataValue = createDataValue();
		for (uint32_t pos=0; pos<3;pos++) {
			OpcUaString::SPtr str = constructSPtr<OpcUaString>();
			str->value("string");
			dataValue->variant()->pushBack(str);
		}
		valueMap_.insert(std::make_pair(nodeId, dataValue));

		// ByteString
		nodeId.set(224, namespaceIndex_);
		OpcUaByteString::SPtr bstr = constructSPtr<OpcUaByteString>();
		bstr->value("string");
		dataValue = createDataValue();
		dataValue->variant()->variant(bstr);
		valueMap_.insert(std::make_pair(nodeId, dataValue));

		// ByteStringArray
		nodeId.set(225, namespaceIndex_);
		dataValue = createDataValue();
		for (uint32_t pos=0; pos<3;pos++) {
			OpcUaByteString::SPtr bstr = constructSPtr<OpcUaByteString>();
			bstr->value("string");
			dataValue->variant()->pushBack(bstr);
		}
		valueMap_.insert(std::make_pair(nodeId, dataValue));

		// LocalizedText
		nodeId.set(226, namespaceIndex_);
		OpcUaLocalizedText::SPtr ltext = constructSPtr<OpcUaLocalizedText>();
		ltext->set("de", "text");
		dataValue = createDataValue();
		dataValue->variant()->variant(ltext);
		valueMap_.insert(std::make_pair(nodeId, dataValue));

		// LocalizedTextArray
		nodeId.set(227, namespaceIndex_);
		dataValue = createDataValue();
		for (uint32_t pos=0; pos<3;pos++) {
			OpcUaLocalizedText::SPtr bstr = constructSPtr<OpcUaLocalizedText>();
			ltext->set("de", "text");
			dataValue->variant()->pushBack(ltext);
		}
		valueMap_.insert(std::make_pair(nodeId, dataValue));

		// DateTime
		nodeId.set(228, namespaceIndex_);
		OpcUaDateTime dateTime(boost::posix_time::microsec_clock::universal_time());
		dataValue = createDataValue();
		dataValue->variant()->variant(dateTime);
		valueMap_.insert(std::make_pair(nodeId, dataValue));

		// DateTimeArray
		nodeId.set(229, namespaceIndex_);
		dataValue = createDataValue();
		for (uint32_t pos=0; pos<3;pos++) {
			OpcUaDateTime dateTime(boost::posix_time::microsec_clock::universal_time());
			dataValue->variant()->pushBack(dateTime);
		}
		valueMap_.insert(std::make_pair(nodeId, dataValue));

		// GUID
		nodeId.set(230, namespaceIndex_);
		OpcUaGuid::SPtr guid = constructSPtr<OpcUaGuid>();
		*guid = "12345678-9ABC-DEF0-1234-56789ABCDEF0";
		dataValue = createDataValue();
		dataValue->variant()->variant(guid);
		valueMap_.insert(std::make_pair(nodeId, dataValue));

		// LocalizedTextArray
		nodeId.set(231, namespaceIndex_);
		dataValue = createDataValue();
		for (uint32_t pos=0; pos<3;pos++) {
			OpcUaGuid::SPtr guid = constructSPtr<OpcUaGuid>();
			*guid = "12345678-9ABC-DEF0-1234-56789ABCDEF0";
			dataValue->variant()->pushBack(guid);
		}
		valueMap_.insert(std::make_pair(nodeId, dataValue));

		// NodeId
		nodeId.set(232, namespaceIndex_);
		OpcUaNodeId::SPtr nodeIdValue = constructSPtr<OpcUaNodeId>();
		nodeIdValue->set(1,1);
		dataValue = createDataValue();
		dataValue->variant()->variant(nodeIdValue);
		valueMap_.insert(std::make_pair(nodeId, dataValue));

		// nodeIdArray
		nodeId.set(233, namespaceIndex_);
		dataValue = createDataValue();
		for (uint32_t pos=0; pos<3;pos++) {
			OpcUaNodeId::SPtr nodeIdValue = constructSPtr<OpcUaNodeId>();
			nodeIdValue->set(pos, 1);
			dataValue->variant()->pushBack(nodeIdValue);
		}
		valueMap_.insert(std::make_pair(nodeId, dataValue));

		// QualifiedName
		nodeId.set(234, namespaceIndex_);
		OpcUaQualifiedName::SPtr qualifiedName = constructSPtr<OpcUaQualifiedName>();
		qualifiedName->set("Name", 1);
		dataValue = createDataValue();
		dataValue->variant()->variant(qualifiedName);
		valueMap_.insert(std::make_pair(nodeId, dataValue));

		// QualifiedName
		nodeId.set(235, namespaceIndex_);
		dataValue = createDataValue();
		for (uint32_t pos=0; pos<3;pos++) {
			OpcUaQualifiedName::SPtr qualifiedName = constructSPtr<OpcUaQualifiedName>();
			qualifiedName->set("Name", pos);
			dataValue->variant()->pushBack(qualifiedName);
		}
		valueMap_.insert(std::make_pair(nodeId, dataValue));

		return true;
	}

	bool
	DemoLibrary::registerCallbacks(void)
	{
	  	ServiceTransactionRegisterForward::SPtr trx = ServiceTransactionRegisterForward::construct();
	  	RegisterForwardRequest::SPtr req = trx->request();
	  	RegisterForwardResponse::SPtr res = trx->response();

	  	req->forwardInfoSync()->setReadCallback(readCallback_);
	  	req->forwardInfoSync()->setWriteCallback(writeCallback_);
	  	req->nodesToRegister()->resize(valueMap_.size());

	  	uint32_t pos = 0;
	  	ValueMap::iterator it;
	  	for (it = valueMap_.begin(); it != valueMap_.end(); it++) {
	  		OpcUaNodeId::SPtr nodeId = constructSPtr<OpcUaNodeId>();
	  		*nodeId = it->first;

	  		req->nodesToRegister()->set(pos, nodeId);
	  		pos++;
	  	}

	  	service().sendSync(trx);
	  	if (trx->statusCode() != Success) {
	  		std::cout << "response error" << std::endl;
	  		return false;
	  	}

	  	for (pos = 0; pos < res->statusCodeArray()->size(); pos++) {
	  		OpcUaStatusCode statusCode;
	  		res->statusCodeArray()->get(pos, statusCode);
	  		if (statusCode != Success) {
	  			std::cout << "register value error" << std::endl;
	  			return false;
	  		}
	  	}

	    return true;
	}

	bool
	DemoLibrary::registerLoopTimeCallbacks(void)
	{
	  	OpcUaNodeId::SPtr nodeId = constructSPtr<OpcUaNodeId>();
	  	nodeId->set(3, namespaceIndex_);

	  	ServiceTransactionRegisterForward::SPtr trx = ServiceTransactionRegisterForward::construct();
	  	RegisterForwardRequest::SPtr req = trx->request();
	  	RegisterForwardResponse::SPtr res = trx->response();

	  	req->forwardInfoSync()->setReadCallback(readLoopTimeCallback_);
	  	req->forwardInfoSync()->setWriteCallback(writeLoopTimeCallback_);
	  	req->nodesToRegister()->resize(1);
	  	req->nodesToRegister()->set(0, nodeId);

	  	service().sendSync(trx);
	  	if (trx->statusCode() != Success) {
	  		std::cout << "response error" << std::endl;
	  	  	return false;
	  	}

	  	OpcUaStatusCode statusCode;
	  	res->statusCodeArray()->get(0, statusCode);
	  	if (statusCode != Success) {
	  	  	std::cout << "register value error" << std::endl;
	  	  	return false;
	  	}

	  	return true;
	}

	bool
	DemoLibrary::createNodeReferences(void)
	{
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

	  	service().sendSync(trx);
	  	if (trx->statusCode() != Success) {
	  		std::cout << "response error" << std::endl;
	  		return false;
	  	}

	  	for (pos = 0; pos < res->nodeReferenceArray()->size(); pos++) {
	  		NodeReference::SPtr nodeReference;
	  		res->nodeReferenceArray()->get(pos, nodeReference);
	  		if (nodeReference->statusCode() != Success) {
	  			std::cout << "node reference error" << std::endl;
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

	void
	DemoLibrary::readValue(ApplicationReadContext* applicationReadContext)
	{
	    //std::cout << "read value ..." << applicationReadContext->nodeId_ << std::endl;

	    ValueMap::iterator it;
	    it = valueMap_.find(applicationReadContext->nodeId_);
	    if (it == valueMap_.end()) {
	    	applicationReadContext->statusCode_ = BadInternalError;
	    	return;
	    }
	    applicationReadContext->statusCode_ = Success;
	    it->second->copyTo(applicationReadContext->dataValue_);
	}

	void
	DemoLibrary::readLoopTimeValue(ApplicationReadContext* applicationReadContext)
	{
		//std::cout << "read loop time value ..." << applicationReadContext->nodeId_ << std::endl;

		applicationReadContext->statusCode_ = Success;
		loopTime_->copyTo(applicationReadContext->dataValue_);
	}

	void
	DemoLibrary::writeValue(ApplicationWriteContext* applicationWriteContext)
	{
		//std::cout << "write value ..." << applicationWriteContext->nodeId_  << std::endl;

		ValueMap::iterator it;
		it = valueMap_.find(applicationWriteContext->nodeId_);
		if (it == valueMap_.end()) {
			applicationWriteContext->statusCode_ = BadInternalError;
			return;
		}
		applicationWriteContext->statusCode_ = Success;
		applicationWriteContext->dataValue_.copyTo(*it->second);
	}

	void
	DemoLibrary::writeLoopTimeValue(ApplicationWriteContext* applicationWriteContext)
	{
		//std::cout << "write loop time value ..." << applicationWriteContext->nodeId_  << std::endl;

		uint32_t timerInterval_ = applicationWriteContext->dataValue_.variant()->variant<OpcUaUInt32>();

		if (timerInterval_ < 100) {
			timerInterval_ = 100;
			applicationWriteContext->dataValue_.variant()->variant(timerInterval_);
		}

		applicationWriteContext->statusCode_ = Success;
		applicationWriteContext->dataValue_.copyTo(*loopTime_);

		if (slotTimerElement_.get() != nullptr) {
			slotTimer_.stop(slotTimerElement_);
			slotTimerElement_.reset();
		}
		if (timerInterval_ == 0) return;

		slotTimerElement_ = constructSPtr<SlotTimerElement>();
		slotTimerElement_->callback().reset(boost::bind(&DemoLibrary::timerLoop, this));
		slotTimerElement_->expireTime(boost::posix_time::microsec_clock::local_time(), timerInterval_);
		slotTimer_.start(slotTimerElement_);
	}

	void
	DemoLibrary::startTimerLoop(void)
	{
		// TimerInterval
		OpcUaUInt32 loopTime(1111);
		loopTime_->variant()->variant(loopTime);

		slotTimerElement_ = constructSPtr<SlotTimerElement>();
		slotTimerElement_->callback().reset(boost::bind(&DemoLibrary::timerLoop, this));
		slotTimerElement_->expireTime(boost::posix_time::microsec_clock::local_time(), 1111);
		slotTimer_.start(slotTimerElement_);
	}

	void
	DemoLibrary::timerLoop(void)
	{
	  	ValueMap::iterator it1;
	  	for (it1 = valueMap_.begin(); it1 != valueMap_.end(); it1++) {

	  		OpcUaNodeId::SPtr nodeId = constructSPtr<OpcUaNodeId>();
	  		OpcUaDataValue::SPtr dataValue = it1->second;
	  		*nodeId = it1->first;

	  		//std::cout << "update " << *nodeId << std::endl;

	  		BaseNodeClassWMap::iterator it2;
	  		it2 = baseNodeClassWMap_.find(*nodeId);
	  		if (it2 == baseNodeClassWMap_.end()) {
	  			std::cout << "baseNodeClass not exist: " << *nodeId << std::endl;
	  			continue;
	  		}
	  		BaseNodeClass::WPtr baseNodeClassWPtr = it2->second;
	  		BaseNodeClass::SPtr baseNodeClass = baseNodeClassWPtr.lock();
	  		if (baseNodeClass.get() == nullptr) {
	  			std::cout << "baseNodeClass is deleted: " << *nodeId << std::endl;
	  			continue;
	  		}

	  		if (dataValue->variant()->isArray()) {
	  			updateArray(*nodeId, dataValue, baseNodeClass);
	  		}
	  		else {
	  			updateSingle(*nodeId, dataValue, baseNodeClass);
	  		}
	  	}
	}

	int32_t sign(void)
	{
		if ((rand() % 2) == 1) return -1;
		return 1;
	}

	double percent(void)
	{
		return ((rand() % 5) / 100.0);
	}

	void
	DemoLibrary::updateSingle(const OpcUaNodeId& nodeId, const OpcUaDataValue::SPtr dataValue, const BaseNodeClass::SPtr baseNodeClass)
	{
		switch (dataValue->variant()->variantType())
		{
			case OpcUaBuildInType_OpcUaSByte:
			{
				OpcUaSByte sByte = dataValue->variant()->get<OpcUaSByte>();
				sByte++;
				dataValue->variant()->set(sByte);
				break;
			}
			case OpcUaBuildInType_OpcUaByte: // 0 - 64
			{
				OpcUaByte byte = dataValue->variant()->get<OpcUaByte>();
				byte += (64 * percent() * sign());
			    if (byte < 0) byte = 0;
			    if (byte > 64) byte = 64;
				dataValue->variant()->set(byte);
				break;
			}
			case OpcUaBuildInType_OpcUaInt16: // -50 - 100
			{
				OpcUaInt16 int16 = dataValue->variant()->get<OpcUaInt16>();
				int16 += (150 * percent() * sign());
				if (int16 < -50) int16 = -50;
				if (int16 > 100) int16 = 100;
				dataValue->variant()->set(int16);
				break;
			}
			case OpcUaBuildInType_OpcUaUInt16: // 0 - 100
			{
				OpcUaUInt16 uint16 = dataValue->variant()->get<OpcUaUInt16>();
				uint16 += (100 * percent() * sign());
				if (uint16 < 0) uint16 = 0;
				if (uint16 > 100) uint16 = 100;
				dataValue->variant()->set(uint16);
				break;
			}
			case OpcUaBuildInType_OpcUaInt32: // 0 - 360
			{
				OpcUaInt32 int32 = dataValue->variant()->get<OpcUaInt32>();
				int32 += (360 * percent() * sign());
				if (int32 < 0) int32 = 0;
				if (int32 > 360) int32 = 360;
				dataValue->variant()->set(int32);
				break;
			}
			case OpcUaBuildInType_OpcUaUInt32: // 0 - 360
			{
				OpcUaUInt32 uint32 = dataValue->variant()->get<OpcUaUInt32>();
				uint32 += (360 * percent() * sign());
				if (uint32 < 0) uint32 = 0;
				if (uint32 > 360) uint32 = 360;
				dataValue->variant()->set(uint32);
				break;
			}
			case OpcUaBuildInType_OpcUaInt64: // -1000 - 1000
			{
				OpcUaInt64 int64 = dataValue->variant()->get<OpcUaInt64>();
				int64 += (2000 * percent() * sign());
				if (int64 < -1000) int64 = 1000;
				if (int64 > 1000) int64 = 1000;
				dataValue->variant()->set(int64);
				break;
			}
			case OpcUaBuildInType_OpcUaUInt64: // 0 -3000
			{
				OpcUaUInt64 uint64 = dataValue->variant()->get<OpcUaUInt64>();
				uint64 += (3000 * percent() * sign());
				if (uint64 < 0) uint64 = 0;
				if (uint64 > 3000) uint64 = 3000;
				dataValue->variant()->set(uint64);
				break;
			}
			case OpcUaBuildInType_OpcUaFloat: // 0 - 1000
			{
				OpcUaFloat floats = dataValue->variant()->get<OpcUaFloat>();
				floats += (1000 * percent() * sign());
				if (floats < 0) floats = 0;
				if (floats > 1000) floats = 1000;
				dataValue->variant()->set(floats);
				break;
			}
			case OpcUaBuildInType_OpcUaDouble: // 0 - 1000
			{
				OpcUaDouble doubles = dataValue->variant()->get<OpcUaDouble>();
				doubles += (1000 * percent() * sign());
				if (doubles < 0) doubles = 0;
				if (doubles > 1000) doubles = 1000;
				dataValue->variant()->set(doubles);
				break;
			}
			case OpcUaBuildInType_OpcUaBoolean:
			{
				OpcUaBoolean boolean = dataValue->variant()->get<OpcUaBoolean>();
				if (boolean) boolean = false;
				else boolean = true;
				dataValue->variant()->set(boolean);
				break;
			}
			case OpcUaBuildInType_OpcUaString:
			{
				OpcUaString::SPtr str = dataValue->variant()->getSPtr<OpcUaString>();
				std::stringstream ss;
				ss << "String" << rand();
				str->value(ss.str());
				dataValue->variant()->set(str);
				break;
			}
			case OpcUaBuildInType_OpcUaByteString:
			{
				OpcUaByteString::SPtr bstr = dataValue->variant()->getSPtr<OpcUaByteString>();
				std::stringstream ss;
				ss << "String" << rand();
				bstr->value(ss.str());
				dataValue->variant()->set(bstr);
				break;
			}
			case OpcUaBuildInType_OpcUaLocalizedText:
			{
				OpcUaLocalizedText::SPtr ltext = dataValue->variant()->getSPtr<OpcUaLocalizedText>();
				std::stringstream ss;
				ss << "String" << rand();
				ltext->set("de", ss.str());
				dataValue->variant()->set(ltext);
				break;
			}
			case OpcUaBuildInType_OpcUaDateTime:
			{
				OpcUaDateTime dateTime(boost::posix_time::microsec_clock::universal_time());
				dataValue->variant()->set(dateTime);
				break;
			}
			case OpcUaBuildInType_OpcUaGuid:
			{
				OpcUaGuid::SPtr guid = dataValue->variant()->getSPtr<OpcUaGuid>();
				guid->data1(guid->data1()+1);
				dataValue->variant()->set(guid);
				break;
			}
			case OpcUaBuildInType_OpcUaNodeId:
			{
				OpcUaNodeId::SPtr nodeIdValue = dataValue->variant()->getSPtr<OpcUaNodeId>();
				nodeIdValue->set(rand(),1);
				dataValue->variant()->set(nodeIdValue);
				break;
			}
			case OpcUaBuildInType_OpcUaQualifiedName:
			{
				OpcUaQualifiedName::SPtr qualifiedName = dataValue->variant()->getSPtr<OpcUaQualifiedName>();
				qualifiedName->set("Name", rand());
				dataValue->variant()->set(qualifiedName);
				break;
			}
			default:
			{
				std::cout << "data type unknown in update single" << std::endl;
				return;
			}
		}

		OpcUaDateTime dateTime(boost::posix_time::microsec_clock::universal_time());
		dataValue->serverTimestamp(dateTime);
		dataValue->sourceTimestamp(dateTime);
		dataValue->statusCode(Success);
		baseNodeClass->setValue(*dataValue);
	}

	void
	DemoLibrary::updateArray(const OpcUaNodeId& nodeId, const OpcUaDataValue::SPtr dataValue, const BaseNodeClass::SPtr baseNodeClass)
	{
		switch (dataValue->variant()->variantType())
		{
			case OpcUaBuildInType_OpcUaSByte:
			{
				for (uint32_t pos = 0; pos < dataValue->variant()->variant().size(); pos++) {
					OpcUaSByte sByte = dataValue->variant()->get<OpcUaSByte>(pos);
					sByte++;
					dataValue->variant()->set(pos, sByte);
				}
				break;
			}
			case OpcUaBuildInType_OpcUaByte:
			{
				for (uint32_t pos = 0; pos < dataValue->variant()->variant().size(); pos++) {
					OpcUaByte byte = dataValue->variant()->get<OpcUaByte>(pos);
					byte++;
					dataValue->variant()->set(pos, byte);
				}
				break;
			}
			case OpcUaBuildInType_OpcUaInt16:
			{
				for (uint32_t pos = 0; pos < dataValue->variant()->variant().size(); pos++) {
					OpcUaInt16 int16 = dataValue->variant()->get<OpcUaInt16>(pos);
					int16++;
					dataValue->variant()->set(pos, int16);
				}
				break;
			}
			case OpcUaBuildInType_OpcUaUInt16:
			{
				for (uint32_t pos = 0; pos < dataValue->variant()->variant().size(); pos++) {
					OpcUaUInt16 uint16 = dataValue->variant()->get<OpcUaUInt16>(pos);
					uint16++;
					dataValue->variant()->set(pos, uint16);
				}
				break;
			}
			case OpcUaBuildInType_OpcUaInt32:
			{
				for (uint32_t pos = 0; pos < dataValue->variant()->variant().size(); pos++) {
					OpcUaInt32 int32 = dataValue->variant()->get<OpcUaInt32>(pos);
					int32++;
					dataValue->variant()->set(pos, int32);
				}
				break;
			}
			case OpcUaBuildInType_OpcUaUInt32:
			{
				for (uint32_t pos = 0; pos < dataValue->variant()->variant().size(); pos++) {
					OpcUaUInt32 uint32 = dataValue->variant()->get<OpcUaUInt32>(pos);
					uint32++;
					dataValue->variant()->set(pos, uint32);
				}
				break;
			}
			case OpcUaBuildInType_OpcUaInt64:
			{
				for (uint32_t pos = 0; pos < dataValue->variant()->variant().size(); pos++) {
					OpcUaInt64 int64 = dataValue->variant()->get<OpcUaInt64>(pos);
					int64++;
					dataValue->variant()->set(pos, int64);
				}
				break;
			}
			case OpcUaBuildInType_OpcUaUInt64:
			{
				for (uint32_t pos = 0; pos < dataValue->variant()->variant().size(); pos++) {
					OpcUaUInt64 uint64 = dataValue->variant()->get<OpcUaUInt64>(pos);
					uint64++;
					dataValue->variant()->set(pos, uint64);
				}
				break;
			}
			case OpcUaBuildInType_OpcUaFloat:
			{
				for (uint32_t pos = 0; pos < dataValue->variant()->variant().size(); pos++) {
					OpcUaFloat floats = dataValue->variant()->get<OpcUaFloat>(pos);
					floats += 3.354;
					dataValue->variant()->set(pos, floats);
				}
				break;
			}
			case OpcUaBuildInType_OpcUaDouble:
			{
				for (uint32_t pos = 0; pos < dataValue->variant()->variant().size(); pos++) {
					OpcUaDouble doubles = dataValue->variant()->get<OpcUaDouble>(pos);
					doubles += 33.354;
					dataValue->variant()->set(pos, doubles);
				}
				break;
			}
			case OpcUaBuildInType_OpcUaBoolean:
			{
				for (uint32_t pos = 0; pos < dataValue->variant()->variant().size(); pos++) {
					OpcUaBoolean boolean = dataValue->variant()->get<OpcUaBoolean>(pos);
					if (boolean) boolean = false;
					else boolean = true;
					dataValue->variant()->set(pos, boolean);
				}
				break;
			}
			case OpcUaBuildInType_OpcUaString:
			{
				for (uint32_t pos = 0; pos < dataValue->variant()->variant().size(); pos++) {
					OpcUaString::SPtr str = dataValue->variant()->getSPtr<OpcUaString>(pos);
					std::stringstream ss;
					ss << "String" << rand();
					str->value(ss.str());
					dataValue->variant()->set(pos, str);
				}
				break;
			}
			case OpcUaBuildInType_OpcUaByteString:
			{
				for (uint32_t pos = 0; pos < dataValue->variant()->variant().size(); pos++) {
					OpcUaByteString::SPtr bstr = dataValue->variant()->getSPtr<OpcUaByteString>(pos);
					std::stringstream ss;
					ss << "String" << rand();
					bstr->value(ss.str());
					dataValue->variant()->set(pos, bstr);
				}
				break;
			}
			case OpcUaBuildInType_OpcUaLocalizedText:
			{
				for (uint32_t pos = 0; pos < dataValue->variant()->variant().size(); pos++) {
					OpcUaLocalizedText::SPtr ltext = dataValue->variant()->getSPtr<OpcUaLocalizedText>(pos);
					std::stringstream ss;
					ss << "String" << rand();
					ltext->set("de", ss.str());
					dataValue->variant()->set(pos, ltext);
				}
				break;
			}
			case OpcUaBuildInType_OpcUaDateTime:
			{
				for (uint32_t pos = 0; pos < dataValue->variant()->variant().size(); pos++) {
					OpcUaDateTime dateTime(boost::posix_time::microsec_clock::universal_time());
					dataValue->variant()->set(pos, dateTime);
				}
				break;
			}
			case OpcUaBuildInType_OpcUaGuid:
			{
				for (uint32_t pos = 0; pos < dataValue->variant()->variant().size(); pos++) {
					OpcUaGuid::SPtr guid = dataValue->variant()->getSPtr<OpcUaGuid>(pos);
					guid->data1(guid->data1()+1);
					dataValue->variant()->set(pos, guid);
				}
				break;
			}
			case OpcUaBuildInType_OpcUaNodeId:
			{
				for (uint32_t pos = 0; pos < dataValue->variant()->variant().size(); pos++) {
					OpcUaNodeId::SPtr nodeIdValue = dataValue->variant()->getSPtr<OpcUaNodeId>(pos);
					nodeIdValue->set(rand(), 1);
					dataValue->variant()->set(pos, nodeIdValue);
				}
				break;
			}
			case OpcUaBuildInType_OpcUaQualifiedName:
			{
				for (uint32_t pos = 0; pos < dataValue->variant()->variant().size(); pos++) {
					OpcUaQualifiedName::SPtr qualifiedName = dataValue->variant()->getSPtr<OpcUaQualifiedName>(pos);
					qualifiedName->set("Name", rand());
					dataValue->variant()->set(pos, qualifiedName);
				}
				break;
			}
			default:
			{
				std::cout << "data type unknown in update array" << std::endl;
				return;
			}
		}


		OpcUaDateTime dateTime(boost::posix_time::microsec_clock::universal_time());
		dataValue->serverTimestamp(dateTime);
		dataValue->sourceTimestamp(dateTime);
		dataValue->statusCode(Success);
		baseNodeClass->setValue(*dataValue);
	}

}

extern "C" DLLEXPORT void  init(ApplicationIf** applicationIf) {
    *applicationIf = new OpcUaServerApplicationDemo::DemoLibrary();
}

