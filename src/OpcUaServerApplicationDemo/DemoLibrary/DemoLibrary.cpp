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
		if (trx->responseHeader()->serviceResult() != Success) {
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
		dataValue = OpcUaDataValue::construct();
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
		OpcUaByte byte(11);
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
		OpcUaInt16 int16(11);
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
		OpcUaUInt16 uint16(11);
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
		OpcUaInt32 int32(11);
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
		OpcUaUInt32 uint32(11);
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
		OpcUaInt64 int64(11);
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
		OpcUaUInt64 uint64(11);
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
		OpcUaFloat floats(11);
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
		OpcUaDouble doubles(11);
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

		return true;
	}

#if 0
	  <UAVariable NodeId="ns=1;i=222" BrowseName="1:String" DataType="i=12">
	    <DisplayName>StringValue</DisplayName>
	    <Description>String test value</Description>
	    <References>
	      <Reference ReferenceType="HasTypeDefinition">i=2138</Reference>
	      <Reference ReferenceType="HasComponent" IsForward="false">ns=1;i=2</Reference>
	    </References>
		<Value>
	      <uax:String>string</uax:String>
	    </Value>
	  </UAVariable>

	  <UAVariable NodeId="ns=1;i=223" BrowseName="1:StringArray" DataType="i=12" ValueRank="1" ArrayDimensions="3">
	    <DisplayName>StringArrayValue</DisplayName>
	    <Description>String array test value</Description>
	    <References>
	      <Reference ReferenceType="HasTypeDefinition">i=2138</Reference>
	      <Reference ReferenceType="HasComponent" IsForward="false">ns=1;i=2</Reference>
	    </References>
		<Value>
	      <uax:ListOfString>
	        <uax:String>string1</uax:String>
	        <uax:String>string2</uax:String>
	        <uax:String>string3</uax:String>
	      </uax:ListOfString>
	    </Value>
	  </UAVariable>

	  <UAVariable NodeId="ns=1;i=224" BrowseName="1:ByteString" DataType="i=15">
	    <DisplayName>ByteStringValue</DisplayName>
	    <Description>ByteString test value</Description>
	    <References>
	      <Reference ReferenceType="HasTypeDefinition">i=2138</Reference>
	      <Reference ReferenceType="HasComponent" IsForward="false">ns=1;i=2</Reference>
	    </References>
		<Value>
	      <uax:ByteString>bytestring</uax:ByteString>
	    </Value>
	  </UAVariable>

	  <UAVariable NodeId="ns=1;i=225" BrowseName="1:ByteStringArray" DataType="i=15" ValueRank="1" ArrayDimensions="3">
	    <DisplayName>ByteStringArrayValue</DisplayName>
	    <Description>ByteString array test value</Description>
	    <References>
	      <Reference ReferenceType="HasTypeDefinition">i=2138</Reference>
	      <Reference ReferenceType="HasComponent" IsForward="false">ns=1;i=2</Reference>
	    </References>
		<Value>
	      <uax:ListOfByteString>
	        <uax:ByteString>bytestring1</uax:ByteString>
	        <uax:ByteString>bytestring2</uax:ByteString>
	        <uax:ByteString>bytestring3</uax:ByteString>
	      </uax:ListOfByteString>
	    </Value>
	  </UAVariable>

	  <UAVariable NodeId="ns=1;i=226" BrowseName="1:LocalizedText" DataType="i=21">
	    <DisplayName>LocalizedTextValue</DisplayName>
	    <Description>LocalizedText test value</Description>
	    <References>
	      <Reference ReferenceType="HasTypeDefinition">i=2138</Reference>
	      <Reference ReferenceType="HasComponent" IsForward="false">ns=1;i=2</Reference>
	    </References>
		<Value>
	      <uax:LocalizedText>
		    <Locale>de</Locale>
			<Text>LocalizedText</Text>
		  </uax:LocalizedText>
	    </Value>
	  </UAVariable>

	  <UAVariable NodeId="ns=1;i=227" BrowseName="1:LocalizedTextArray" DataType="i=21" ValueRank="1" ArrayDimensions="3">
	    <DisplayName>LocalizedTextArrayValue</DisplayName>
	    <Description>LocalizedText array test value</Description>
	    <References>
	      <Reference ReferenceType="HasTypeDefinition">i=2138</Reference>
	      <Reference ReferenceType="HasComponent" IsForward="false">ns=1;i=2</Reference>
	    </References>
		<Value>
	      <uax:ListOfLocalizedText>
	        <uax:LocalizedText>
		      <uax:Locale>de</uax:Locale>
			  <uax:Text>LocalizedText1</uax:Text>
		    </uax:LocalizedText>
		    <uax:LocalizedText>
		      <uax:Locale>de</uax:Locale>
			  <uax:Text>LocalizedText2</uax:Text>
		    </uax:LocalizedText>
		    <uax:LocalizedText>
		      <uax:Locale>de</uax:Locale>
			  <uax:Text>LocalizedText3</uax:Text>
		    </uax:LocalizedText>
	      </uax:ListLocalizedText>
	    </Value>
	  </UAVariable>

	  <UAVariable NodeId="ns=1;i=228" BrowseName="1:DateTime" DataType="i=13">
	    <DisplayName>DateTimeValue</DisplayName>
	    <Description>DateTime test value</Description>
	    <References>
	      <Reference ReferenceType="HasTypeDefinition">i=2138</Reference>
	      <Reference ReferenceType="HasComponent" IsForward="false">ns=1;i=2</Reference>
	    </References>
		<Value>
	      <uax:DateTime>2015-01-01T01:01:00Z</uax:DateTime>
	    </Value>
	  </UAVariable>

	  <UAVariable NodeId="ns=1;i=229" BrowseName="1:DateTimeArray" DataType="i=13" ValueRank="1" ArrayDimensions="3">
	    <DisplayName>DateTimeValueArray</DisplayName>
	    <Description>DateTime array test value</Description>
	    <References>
	      <Reference ReferenceType="HasTypeDefinition">i=2138</Reference>
	      <Reference ReferenceType="HasComponent" IsForward="false">ns=1;i=2</Reference>
	    </References>
		<Value>
	      <uax:ListOfDateTime>
	        <uax:DateTime>2015-01-01T01:01:00Z</uax:DateTime>
	        <uax:DateTime>2015-01-01T01:02:00Z</uax:DateTime>
	        <uax:DateTime>2015-01-01T01:03:00Z</uax:DateTime>
	      </uax:ListOfDateTime>
	    </Value>
	  </UAVariable>

	  <UAVariable NodeId="ns=1;i=230" BrowseName="1:Guid" DataType="i=14">
	    <DisplayName>GuidValue</DisplayName>
	    <Description>Guid test value</Description>
	    <References>
	      <Reference ReferenceType="HasTypeDefinition">i=2138</Reference>
	      <Reference ReferenceType="HasComponent" IsForward="false">ns=1;i=2</Reference>
	    </References>
		<Value>
	      <uax:Guid><uax:String>00000001-0001-0001-0001-000000000001</uax:String></uax:Guid>
	    </Value>
	  </UAVariable>

	  <UAVariable NodeId="ns=1;i=231" BrowseName="1:GuidArray" DataType="i=14" ValueRank="1" ArrayDimensions="3">
	    <DisplayName>GuidValueArray</DisplayName>
	    <Description>Guid array test value</Description>
	    <References>
	      <Reference ReferenceType="HasTypeDefinition">i=2138</Reference>
	      <Reference ReferenceType="HasComponent" IsForward="false">ns=1;i=2</Reference>
	    </References>
		<Value>
	      <uax:ListOfGuid>
	        <uax:Guid><uax:String>00000001-0001-0001-0001-000000000001</uax:String></uax:Guid>
			<uax:Guid><uax:String>00000001-0001-0001-0001-000000000002</uax:String></uax:Guid>
			<uax:Guid><uax:String>00000001-0001-0001-0001-000000000003</uax:String></uax:Guid>
	      </uax:ListOfGuid>
	    </Value>
	  </UAVariable>

	  <UAVariable NodeId="ns=1;i=232" BrowseName="1:NodeId" DataType="i=17">
	    <DisplayName>NodeIdValue</DisplayName>
	    <Description>NodeId test value</Description>
	    <References>
	      <Reference ReferenceType="HasTypeDefinition">i=2138</Reference>
	      <Reference ReferenceType="HasComponent" IsForward="false">ns=1;i=2</Reference>
	    </References>
		<Value>
	      <uax:NodeId><uax:Identifier>ns=1;s=String</uax:Identifier></uax:NodeId>
	    </Value>
	  </UAVariable>

	  <UAVariable NodeId="ns=1;i=233" BrowseName="1:NodeIdArray" DataType="i=17" ValueRank="1" ArrayDimensions="3">
	    <DisplayName>NodeIdValueArray</DisplayName>
	    <Description>NodeId array test value</Description>
	    <References>
	      <Reference ReferenceType="HasTypeDefinition">i=2138</Reference>
	      <Reference ReferenceType="HasComponent" IsForward="false">ns=1;i=2</Reference>
	    </References>
		<Value>
	      <uax:ListOfNodeId>
	        <uax:NodeId><uax:Identifier>ns=1;s=String1</uax:Identifier></uax:NodeId>
			<uax:NodeId><uax:Identifier>ns=1;i=1234</uax:Identifier></uax:NodeId>
			<uax:NodeId><uax:Identifier>ns=1;s=00000001-0001-0001-0001-000000000001</uax:Identifier></uax:NodeId>
	      </uax:ListOfNodeId>
	    </Value>
	  </UAVariable>

	  <UAVariable NodeId="ns=1;i=234" BrowseName="1:QualifiedName" DataType="i=20">
	    <DisplayName>QualifiedNameValue</DisplayName>
	    <Description>QualifiedName test value</Description>
	    <References>
	      <Reference ReferenceType="HasTypeDefinition">i=2138</Reference>
	      <Reference ReferenceType="HasComponent" IsForward="false">ns=1;i=2</Reference>
	    </References>
		<Value>
		  <uax:QualifiedName>
	        <uax:NamespaceIndex>0</uax:NamespaceIndex>
	        <uax:Name>QualifiedName</uax:Name>
	      </uax:QualifiedName>
	    </Value>
	  </UAVariable>

	  <UAVariable NodeId="ns=1;i=235" BrowseName="1:QualifiedNameArray" DataType="i=20" ValueRank="1" ArrayDimensions="3">
	    <DisplayName Locale="de">QualifiedNameValueArray</DisplayName>
	    <Description Locale="de">QualifiedName array test value</Description>
	    <References>
	      <Reference ReferenceType="HasTypeDefinition">i=2138</Reference>
	      <Reference ReferenceType="HasComponent" IsForward="false">ns=1;i=2</Reference>
	    </References>
		<Value>
	      <uax:ListOfQualifiedName>
		  <uax:QualifiedName>
	        <uax:NamespaceIndex>1</uax:NamespaceIndex>
	        <uax:Name>QualifiedName1</uax:Name>
	      </uax:QualifiedName>
		  <uax:QualifiedName>
	        <uax:NamespaceIndex>1</uax:NamespaceIndex>
	        <uax:Name>QualifiedName2</uax:Name>
	      </uax:QualifiedName>
		  <uax:QualifiedName>
	        <uax:NamespaceIndex>1</uax:NamespaceIndex>
	        <uax:Name>QualifiedName3</uax:Name>
	      </uax:QualifiedName>
	      </uax:ListOfQualifiedName>
	    </Value>
	  </UAVariable>


#endif



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
	  		OpcUaNodeId::SPtr nodeId = OpcUaNodeId::construct();
	  		*nodeId = it->first;

	  		req->nodesToRegister()->set(pos, nodeId);
	  		pos++;
	  	}

	  	service().sendSync(trx);
	  	if (trx->responseHeader()->serviceResult() != Success) {
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
	  	OpcUaNodeId::SPtr nodeId = OpcUaNodeId::construct();
	  	nodeId->set(3, namespaceIndex_);

	  	ServiceTransactionRegisterForward::SPtr trx = ServiceTransactionRegisterForward::construct();
	  	RegisterForwardRequest::SPtr req = trx->request();
	  	RegisterForwardResponse::SPtr res = trx->response();

	  	req->forwardInfoSync()->setReadCallback(readLoopTimeCallback_);
	  	req->forwardInfoSync()->setWriteCallback(writeLoopTimeCallback_);
	  	req->nodesToRegister()->resize(1);
	  	req->nodesToRegister()->set(0, nodeId);

	  	service().sendSync(trx);
	  	if (trx->responseHeader()->serviceResult() != Success) {
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
	  		OpcUaNodeId::SPtr nodeId = OpcUaNodeId::construct();
	  		*nodeId = it->first;

	  		req->nodes()->set(pos, nodeId);
	  		pos++;
	  	}

	  	service().sendSync(trx);
	  	if (trx->responseHeader()->serviceResult() != Success) {
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
	    std::cout << "read value ..." << applicationReadContext->nodeId_ << std::endl;

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
		std::cout << "read loop time value ..." << applicationReadContext->nodeId_ << std::endl;

		applicationReadContext->statusCode_ = Success;
		loopTime_->copyTo(applicationReadContext->dataValue_);
	}

	void
	DemoLibrary::writeValue(ApplicationWriteContext* applicationWriteContext)
	{
		std::cout << "write value ..." << applicationWriteContext->nodeId_  << std::endl;

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
		std::cout << "write loop time value ..." << applicationWriteContext->nodeId_  << std::endl;

		uint32_t timerInterval_ = applicationWriteContext->dataValue_.variant()->variant<OpcUaUInt32>();

		applicationWriteContext->statusCode_ = Success;
		applicationWriteContext->dataValue_.copyTo(*loopTime_);

		if (slotTimerElement_.get() != nullptr) {
			slotTimer_.stop(slotTimerElement_);
			slotTimerElement_.reset();
		}
		if (timerInterval_ == 0) return;

		slotTimerElement_ = SlotTimerElement::construct();
		slotTimerElement_->callback().reset(boost::bind(&DemoLibrary::timerLoop, this));
		slotTimerElement_->expireTime(boost::posix_time::microsec_clock::local_time(), timerInterval_);
		slotTimer_.start(slotTimerElement_);
	}

	void
	DemoLibrary::timerLoop(void)
	{
	  	ValueMap::iterator it1;
	  	for (it1 = valueMap_.begin(); it1 != valueMap_.end(); it1++) {

	  		OpcUaNodeId::SPtr nodeId = OpcUaNodeId::construct();
	  		OpcUaDataValue::SPtr dataValue = it1->second;
	  		*nodeId = it1->first;

	  		std::cout << "update " << *nodeId << std::endl;

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

		std::cout << "timer..." << std::endl;
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
			case OpcUaBuildInType_OpcUaByte:
			{
				OpcUaByte byte = dataValue->variant()->get<OpcUaByte>();
				byte++;
				dataValue->variant()->set(byte);
				break;
			}
			case OpcUaBuildInType_OpcUaInt16:
			{
				OpcUaInt16 int16 = dataValue->variant()->get<OpcUaInt16>();
				int16++;
				dataValue->variant()->set(int16);
				break;
			}
			case OpcUaBuildInType_OpcUaUInt16:
			{
				OpcUaUInt16 uint16 = dataValue->variant()->get<OpcUaUInt16>();
				uint16++;
				dataValue->variant()->set(uint16);
				break;
			}
			case OpcUaBuildInType_OpcUaInt32:
			{
				OpcUaInt32 int32 = dataValue->variant()->get<OpcUaInt32>();
				int32++;
				dataValue->variant()->set(int32);
				break;
			}
			case OpcUaBuildInType_OpcUaUInt32:
			{
				OpcUaUInt32 uint32 = dataValue->variant()->get<OpcUaUInt32>();
				uint32++;
				dataValue->variant()->set(uint32);
				break;
			}
			case OpcUaBuildInType_OpcUaInt64:
			{
				OpcUaInt64 int64 = dataValue->variant()->get<OpcUaInt64>();
				int64++;
				dataValue->variant()->set(int64);
				break;
			}
			case OpcUaBuildInType_OpcUaUInt64:
			{
				OpcUaUInt64 uint64 = dataValue->variant()->get<OpcUaUInt64>();
				uint64++;
				dataValue->variant()->set(uint64);
				break;
			}
			case OpcUaBuildInType_OpcUaFloat:
			{
				OpcUaFloat floats = dataValue->variant()->get<OpcUaFloat>();
				floats += 1.1234;
				dataValue->variant()->set(floats);
				break;
			}
			case OpcUaBuildInType_OpcUaDouble:
			{
				OpcUaDouble doubles = dataValue->variant()->get<OpcUaDouble>();
				doubles += 232.324;
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

