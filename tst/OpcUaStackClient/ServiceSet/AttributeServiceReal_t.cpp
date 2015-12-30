#include "unittest.h"
#include "OpcUaStackCore/Base/Condition.h"
#include "OpcUaStackCore/Core/Core.h"
#include "OpcUaStackClient/ServiceSet/Session.h"
#include "OpcUaStackClient/ServiceSet/AttributeService.h"

#ifdef REAL_SERVER

using namespace OpcUaStackCore;
using namespace OpcUaStackClient;

class AttributeRealTest
: public SessionIf
{
  public:
	SessionState sessionState_;

	Condition sessionStateUpdate_;
	void sessionStateUpdate(SessionBase& session, SessionState sessionState)
	{
		std::cout << "handleConnect client" << std::endl;
		sessionState_ = sessionState;
		sessionStateUpdate_.conditionValueDec();
	}
};

class AttributeRealServiceHandler
: public AttributeServiceIf
{
   public:
	virtual ~AttributeRealServiceHandler(void) {}

	 Condition attributeServiceReadResponseCondition_;
	 ServiceTransactionRead::SPtr serviceTransactionRead_;
     void attributeServiceReadResponse(ServiceTransactionRead::SPtr serviceTransactionRead) {
		 serviceTransactionRead_ = serviceTransactionRead;
		 attributeServiceReadResponseCondition_.conditionValueDec();
	 };

     Condition attributeServiceWriteResponseCondition_;
     ServiceTransactionWrite::SPtr serviceTransactionWrite_;
	 void attributeServiceWriteResponse(ServiceTransactionWrite::SPtr serviceTransactionWrite) {
		 serviceTransactionWrite_ = serviceTransactionWrite;
		 attributeServiceWriteResponseCondition_.conditionValueDec();
	 };

};


BOOST_AUTO_TEST_SUITE(AttributeReal_)

BOOST_AUTO_TEST_CASE(AttributeReal_)
{
	std::cout << "AttributeReal_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(AttributeReal_async_read)
{
	Core core;
	core.init();

	IOThread ioThread1;
	IOThread ioThread2;
	ioThread1.startup();
	ioThread2.startup();

	// set secure channel configuration
	SecureChannelClientConfig::SPtr secureChannelClientConfig = construct<SecureChannelClientConfig>();
	secureChannelClientConfig->endpointUrl(REAL_SERVER_URI);
	secureChannelClientConfig->debug(false);
	secureChannelClientConfig->debugHeader(false);

	// set session configuration
	SessionConfig::SPtr sessionConfig = construct<SessionConfig>();
	sessionConfig->sessionName_ = "urn:127.0.0.1:ASNeG.de:ASNeG-Client";
	sessionConfig->applicationDescription_->applicationUri("urn:127.0.0.1:ASNeG.de:ASNeG-Client");
	sessionConfig->applicationDescription_->productUri("urn:ASNeG.de:ASNeG-Client");
	sessionConfig->applicationDescription_->applicationName().set("en", "ASNeG-Client");

	// init session
	AttributeRealTest attributeRealTest;
	Session session(&ioThread1);
	session.sessionIf(&attributeRealTest);

	// connect session
	attributeRealTest.sessionStateUpdate_.condition(1,0);
	session.asyncConnect(sessionConfig, secureChannelClientConfig);
	BOOST_REQUIRE(attributeRealTest.sessionStateUpdate_.waitForCondition(1000) == true);
	BOOST_REQUIRE(attributeRealTest.sessionState_ == SS_Connect);

	// init attribute service

	AttributeRealServiceHandler attributeRealServiceHandler;
	AttributeService attributeService;
	attributeService.ioThread(&ioThread2);
	attributeService.attributeServiceIf(&attributeRealServiceHandler);
	attributeService.componentSession(session.component());

	// read value
	ServiceTransactionRead::SPtr readTrx = ServiceTransactionRead::construct();
	ReadRequest::SPtr req = readTrx->request();
	req->maxAge(0);
	req->timestampsToReturn(2);

	ReadValueId::SPtr readValueIdSPtr = ReadValueId::construct();
	readValueIdSPtr->nodeId((OpcUaInt16)0, (OpcUaInt32)2259);
	readValueIdSPtr->attributeId((OpcUaInt32) 13);
	readValueIdSPtr->dataEncoding().namespaceIndex((OpcUaInt16) 0);

	req->readValueIdArray()->set(readValueIdSPtr);

	attributeRealServiceHandler.attributeServiceReadResponseCondition_.condition(1, 0);
	attributeService.send(readTrx);
	BOOST_REQUIRE(attributeRealServiceHandler.attributeServiceReadResponseCondition_.waitForCondition(1000) == true);

	BOOST_REQUIRE(attributeRealServiceHandler.serviceTransactionRead_->responseHeader()->serviceResult() == 0);
	ReadResponse::SPtr readResponse = attributeRealServiceHandler.serviceTransactionRead_->response();
	BOOST_REQUIRE(readResponse->dataValueArray()->size() == 1);

	OpcUaDataValue::SPtr dataValue;
	readResponse->dataValueArray()->get(0, dataValue);
	OpcUaVariant::SPtr variant = dataValue->variant();

	// disconnect session
	attributeRealTest.sessionStateUpdate_.condition(1,0);
	session.asyncDisconnect();
	BOOST_REQUIRE(attributeRealTest.sessionStateUpdate_.waitForCondition(1000) == true);
	BOOST_REQUIRE(attributeRealTest.sessionState_ == SS_Disconnect);

	ioThread1.shutdown();
	ioThread2.shutdown();
}

BOOST_AUTO_TEST_CASE(AttributeReal_sync_read)
{
	Core core;
	core.init();

	IOThread ioThread1;
	IOThread ioThread2;
	ioThread1.startup();
	ioThread2.startup();

	// set secure channel configuration
	SecureChannelClientConfig::SPtr secureChannelClientConfig = construct<SecureChannelClientConfig>();
	secureChannelClientConfig->endpointUrl(REAL_SERVER_URI);
	secureChannelClientConfig->debug(false);
	secureChannelClientConfig->debugHeader(false);

	// set session configuration
	SessionConfig::SPtr sessionConfig = construct<SessionConfig>();
	sessionConfig->sessionName_ = "urn:127.0.0.1:ASNeG.de:ASNeG-Client";
	sessionConfig->applicationDescription_->applicationUri("urn:127.0.0.1:ASNeG.de:ASNeG-Client");
	sessionConfig->applicationDescription_->productUri("urn:ASNeG.de:ASNeG-Client");
	sessionConfig->applicationDescription_->applicationName().set("en", "ASNeG-Client");

	// init session
	AttributeRealTest attributeRealTest;
	Session session(&ioThread1);
	session.sessionIf(&attributeRealTest);

	// connect session
	attributeRealTest.sessionStateUpdate_.condition(1,0);
	session.asyncConnect(sessionConfig, secureChannelClientConfig);
	BOOST_REQUIRE(attributeRealTest.sessionStateUpdate_.waitForCondition(1000) == true);
	BOOST_REQUIRE(attributeRealTest.sessionState_ == SS_Connect);

	// init attribute service
	AttributeRealServiceHandler attributeRealServiceHandler;
	AttributeService attributeService;
	attributeService.ioThread(&ioThread2);
	attributeService.attributeServiceIf(&attributeRealServiceHandler);
	attributeService.componentSession(session.component());

	// read value
	ServiceTransactionRead::SPtr readTrx = ServiceTransactionRead::construct();
	ReadRequest::SPtr req = readTrx->request();
	req->maxAge(0);
	req->timestampsToReturn(2);

	ReadValueId::SPtr readValueIdSPtr = ReadValueId::construct();
	readValueIdSPtr->nodeId((OpcUaInt16)0, (OpcUaInt32)2259);
	readValueIdSPtr->attributeId((OpcUaInt32) 13);
	readValueIdSPtr->dataEncoding().namespaceIndex((OpcUaInt16) 0);

	req->readValueIdArray()->set(readValueIdSPtr);

	attributeService.sendSync(readTrx);

	BOOST_REQUIRE(readTrx->responseHeader()->serviceResult() == 0);
	ReadResponse::SPtr readResponse = readTrx->response();
	BOOST_REQUIRE(readResponse->dataValueArray()->size() == 1);

	OpcUaDataValue::SPtr dataValue;
	readResponse->dataValueArray()->get(0, dataValue);
	OpcUaVariant::SPtr variant = dataValue->variant();

	// disconnect session
	attributeRealTest.sessionStateUpdate_.condition(1,0);
	session.asyncDisconnect();
	BOOST_REQUIRE(attributeRealTest.sessionStateUpdate_.waitForCondition(1000) == true);
	BOOST_REQUIRE(attributeRealTest.sessionState_ == SS_Disconnect);

	ioThread1.shutdown();
	ioThread2.shutdown();
}

BOOST_AUTO_TEST_SUITE_END()

#endif
