#include "unittest.h"
#include "OpcUaStackCore/Base/Config.h"
#include "OpcUaStackCore/Base/IOService.h"
#include "OpcUaStackCore/Base/Utility.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackClient/Client/Client.h"
#include "OpcUaStackClient/ServiceSet/SessionTestHandler.h"
#include "OpcUaStackClient/ServiceSet/AttributeService.h"
#include <boost/asio/error.hpp>

using namespace OpcUaStackCore;
using namespace OpcUaStackClient;

class AttributeServiceHandler 
: public AttributeServiceIf
{
   public:
     void attributeServiceReadResponse(ServiceTransactionRead::SPtr serviceTransactionRead) {
		 serviceTransactionRead_ = serviceTransactionRead;
		 attributeServiceReadResponseCondition_.conditionValueDec();
	 };
	 void attributeServiceWriteResponse(ServiceTransactionWrite::SPtr serviceTransactionWrite) {
		 serviceTransactionWrite_ = serviceTransactionWrite;
		 attributeServiceWriteResponseCondition_.conditionValueDec();
	 };

	 ServiceTransactionRead::SPtr serviceTransactionRead_;
	 ServiceTransactionWrite::SPtr serviceTransactionWrite_;
	 Condition attributeServiceReadResponseCondition_;
	 Condition attributeServiceWriteResponseCondition_;
};

BOOST_AUTO_TEST_SUITE(Session_)

BOOST_AUTO_TEST_CASE(Session_)
{
	std::cout << "Session_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(Session_open)
{
	AttributeServiceHandler attributeServiceHandler;
	SessionTestHandler sessionTestHandler;

	Client client;
	client.init();
	client.start();
	
	AttributeService attributeService;
	attributeService.attributeServiceIf(&attributeServiceHandler);

	Config sessionConfig; 
	sessionConfig.setValue("TestConfig.EndpointUrl", "opc.tcp://127.0.0.1:4841");
	sessionConfig.setValue("TestConfig.SessionName", "urn:127.0.0.1:Company:MyAppl");
	sessionConfig.setValue("TestConfig.ApplicationDescription.ApplicationUri", "urn:127.0.0.1:Company:MyAppl");
	sessionConfig.setValue("TestConfig.ApplicationDescription.ProductUri", "urn:Company:MyAppl");
	sessionConfig.setValue("TestConfig.ApplicationDescription.ApplicationName.Locale", "en");
	sessionConfig.setValue("TestConfig.ApplicationDescription.ApplicationName.Text", "MyAppl");

	Config secureChannelConfig;
	secureChannelConfig.setValue("TestConfig.EndpointUrl", "opc.tcp://127.0.0.1:4841");
	secureChannelConfig.setValue("TestConfig.SecurityPolicyUri", "http://opcfoundation.org/UA/SecurityPolicy#None");

	Session::SPtr session = client.sessionManager().getNewSession(
		"TestConfig", sessionConfig,
		"TestConfig", secureChannelConfig,
		&sessionTestHandler
	);
	attributeService.componentSession(session->component());

	// createSession
	sessionTestHandler.createSessionCompleteCondition_.condition(1, 0);
	session->createSession();
	BOOST_REQUIRE(sessionTestHandler.createSessionCompleteCondition_.waitForCondition(1000) == true);

	// activateSession
	sessionTestHandler.activateSessionCompleteCondition_.condition(1, 0);
	session->activateSession();
	BOOST_REQUIRE(sessionTestHandler.activateSessionCompleteCondition_.waitForCondition(1000) == true);

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// attribute service read
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	// send read request
	ServiceTransactionRead::SPtr readTrx = ServiceTransactionRead::construct();
	ReadRequest::SPtr req = readTrx->request();
	req->maxAge(0);
	req->timestampsToReturn(2);

	ReadValueId::SPtr readValueIdSPtr = ReadValueId::construct();
	readValueIdSPtr->nodeId((OpcUaInt16)0, (OpcUaInt32)2255);
	readValueIdSPtr->attributeId((OpcUaInt32) 13);
	readValueIdSPtr->dataEncoding().namespaceIndex((OpcUaInt16) 0);

	req->readValueIdArray()->set(readValueIdSPtr);

	attributeServiceHandler.attributeServiceReadResponseCondition_.condition(1, 0);
	attributeService.send(readTrx);
	BOOST_REQUIRE(attributeServiceHandler.attributeServiceReadResponseCondition_.waitForCondition(1000) == true);

	std::cout << "ResultCode=" << attributeServiceHandler.serviceTransactionRead_->responseHeader()->serviceResult() << std::endl;
	ReadResponse::SPtr readResponse = attributeServiceHandler.serviceTransactionRead_->response();
	std::cout << "Size=" << readResponse->dataValueArray()->size() << std::endl;
	
	OpcUaDataValue::SPtr dataValue;
	readResponse->dataValueArray()->get(0, dataValue);
	OpcUaVariant::SPtr variant = dataValue->variant();

	std::cout << "StatusCode=" << (uint32_t)dataValue->statusCode() << std::endl; // 0
	std::cout << "ValueType=" << variant->variantType() << std::endl; //12
	std::cout << "ValueArrayLen=" << variant->arrayLength() << std::endl; // 5
	for (int32_t idx=0; idx < variant->arrayLength(); idx++) {
		std::cout << variant->variant()[idx].variantSPtr<OpcUaString>()->value() << std::endl;
	}

	//IOService::secSleep(1000);
	client.stop();
	client.cleanup();
}

BOOST_AUTO_TEST_SUITE_END()