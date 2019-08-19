#include "unittest.h"
#include "OpcUaStackClient/CryptoManagerTest.h"
#include "OpcUaStackClient/ValueBasedInterface/VBIClient.h"

using namespace OpcUaStackCore;
using namespace OpcUaStackClient;

BOOST_AUTO_TEST_SUITE(VBIAsyncReal_Attribute_)

struct GValueFixture {
	GValueFixture(void)
    : cond_()
	, sessionState_(SessionServiceStateId::None)
	, statusCode_(Success)
	, dataValue_()
    {}
    ~GValueFixture(void)
    {}

    Condition cond_;
    SessionServiceStateId sessionState_;
    OpcUaStatusCode statusCode_;
    OpcUaDataValue::Vec dataValue_;
};

BOOST_AUTO_TEST_CASE(VBIAsyncReal_Attribute_)
{
	std::cout << "VBIAsyncReal_Attribute_t" << std::endl;
}

#ifdef REAL_SERVER
BOOST_FIXTURE_TEST_CASE(VBIAsyncReal_Attribute_read, GValueFixture)
{
	VBIClient client;

	//
	// init certificate and crypto manager
	//
	CryptoManager::SPtr cryptoManager = CryptoManagerTest::getInstance();
	BOOST_REQUIRE(cryptoManager.get() != nullptr);

	// set session change callback
	client.setSessionChangeHandler(
		[this] (SessionBase& session, SessionServiceStateId sessionState) {
			if (sessionState == SessionServiceStateId::Established ||
				sessionState == SessionServiceStateId::Disconnected) {
				sessionState_ = sessionState;
				cond_.sendEvent();
			}
		}
	);

	// connect session
	ConnectContext connectContext;
	connectContext.endpointUrl_ = REAL_SERVER_URI;
	connectContext.sessionName_ = REAL_SESSION_NAME;
	connectContext.cryptoManager_ = cryptoManager;
	connectContext.secureChannelLog_ = true;
	cond_.initEvent();
	client.asyncConnect(connectContext);
	BOOST_REQUIRE(cond_.waitForEvent(1000) == true);
	BOOST_REQUIRE(sessionState_ == SessionServiceStateId::Established);

	// read
	OpcUaNodeId nodeId;
	nodeId.set((OpcUaInt32)2259);
	cond_.initEvent();
	client.asyncRead(
		nodeId,
		[this](OpcUaStatusCode statusCode, OpcUaNodeId& nodeId, OpcUaDataValue& dataValue) {
			statusCode_ = statusCode;
			cond_.sendEvent();
		}
	);
	BOOST_REQUIRE(cond_.waitForEvent(1000) == true);
	BOOST_REQUIRE(statusCode_ == Success);

	// disconnect session
	cond_.initEvent();
	client.asyncDisconnect();
	BOOST_REQUIRE(cond_.waitForEvent(1000) == true);
	BOOST_REQUIRE(sessionState_ == SessionServiceStateId::Disconnected);
}

BOOST_FIXTURE_TEST_CASE(VBIAsyncReal_Attribute_write, GValueFixture)
{
	VBIClient client;


	//
	// get crypto manager
	//
	CryptoManager::SPtr cryptoManager = CryptoManagerTest::getInstance();
	BOOST_REQUIRE(cryptoManager.get() != nullptr);

	// set session change callback
	client.setSessionChangeHandler(
		[this] (SessionBase& session, SessionServiceStateId sessionState) {
			if (sessionState == SessionServiceStateId::Established ||
				sessionState == SessionServiceStateId::Disconnected) {
				sessionState_ = sessionState;
				cond_.sendEvent();
			}
		}
	);

	// connect session
	ConnectContext connectContext;
	connectContext.endpointUrl_ = REAL_SERVER_URI;
	connectContext.sessionName_ = REAL_SESSION_NAME;
	connectContext.cryptoManager_ = cryptoManager;
	connectContext.secureChannelLog_ = true;
	cond_.initEvent();
	client.asyncConnect(connectContext);
	BOOST_REQUIRE(cond_.waitForEvent(1000) == true);
	BOOST_REQUIRE(sessionState_ == SessionServiceStateId::Established);

	// write
	OpcUaNodeId nodeId;
	OpcUaDataValue dataValue;
	dataValue.variant()->set((OpcUaBoolean)1);
	nodeId.set(220, 2);
	cond_.initEvent();
	client.asyncWrite(
		nodeId,
		dataValue,
		[this](OpcUaStatusCode statusCode, OpcUaNodeId& nodeId) {
			statusCode_ = statusCode;
			cond_.sendEvent();
		}
	);
	BOOST_REQUIRE(cond_.waitForEvent(1000) == true);
	BOOST_REQUIRE(statusCode_ == Success);

	// disconnect session
	cond_.initEvent();
	client.asyncDisconnect();
	BOOST_REQUIRE(cond_.waitForEvent(1000) == true);
	BOOST_REQUIRE(sessionState_ == SessionServiceStateId::Disconnected);
}

BOOST_FIXTURE_TEST_CASE(VBIAsyncReal_Attribute_historyRead_10, GValueFixture)
{
	VBIClient client;

	//
	// init certificate and crypto manager
	//
	CryptoManager::SPtr cryptoManager = CryptoManagerTest::getInstance();
	BOOST_REQUIRE(cryptoManager.get() != nullptr);

	// set session change callback
	client.setSessionChangeHandler(
		[this] (SessionBase& session, SessionServiceStateId sessionState) {
			if (sessionState == SessionServiceStateId::Established ||
				sessionState == SessionServiceStateId::Disconnected) {
				sessionState_ = sessionState;
				cond_.sendEvent();
			}
		}
	);

	// connect session
	ConnectContext connectContext;
	connectContext.endpointUrl_ = REAL_SERVER_URI;
	connectContext.sessionName_ = REAL_SESSION_NAME;
	connectContext.cryptoManager_ = cryptoManager;
	connectContext.secureChannelLog_ = true;
	cond_.initEvent();
	client.asyncConnect(connectContext);
	BOOST_REQUIRE(cond_.waitForEvent(1000) == true);
	BOOST_REQUIRE(sessionState_ == SessionServiceStateId::Established);

	client.defaultHistoryReadContext().maxNumResultValuesPerNode_ = 10;
	client.defaultHistoryReadContext().maxNumResultValuesPerRequest_ = 5;

	// history read
	cond_.initEvent();
	client.asyncHistoryRead(
		OpcUaNodeId("DoubleValue", 12),
		boost::posix_time::microsec_clock::local_time(),
		boost::posix_time::microsec_clock::local_time(),
		[this](OpcUaStatusCode statusCode, OpcUaDataValue::Vec& dataValue) {
			statusCode_ = statusCode;
			dataValue_ = dataValue;
			cond_.sendEvent();
		}
	);
	BOOST_REQUIRE(cond_.waitForEvent(1000) == true);
	BOOST_REQUIRE(statusCode_ == Success);
	BOOST_REQUIRE(dataValue_.size() == 10);

	// disconnect session
	cond_.initEvent();
	client.asyncDisconnect();
	BOOST_REQUIRE(cond_.waitForEvent(1000) == true);
	BOOST_REQUIRE(sessionState_ == SessionServiceStateId::Disconnected);
}

BOOST_FIXTURE_TEST_CASE(VBIAsyncReal_Attribute_historyRead_8, GValueFixture)
{
	VBIClient client;

	//
	// init certificate and crypto manager
	//
	CryptoManager::SPtr cryptoManager = CryptoManagerTest::getInstance();
	BOOST_REQUIRE(cryptoManager.get() != nullptr);

	// set session change callback
	client.setSessionChangeHandler(
		[this] (SessionBase& session, SessionServiceStateId sessionState) {
			if (sessionState == SessionServiceStateId::Established ||
				sessionState == SessionServiceStateId::Disconnected) {
				sessionState_ = sessionState;
				cond_.sendEvent();
			}
		}
	);

	// connect session
	ConnectContext connectContext;
	connectContext.endpointUrl_ = REAL_SERVER_URI;
	connectContext.sessionName_ = REAL_SESSION_NAME;
	connectContext.cryptoManager_ = cryptoManager;
	connectContext.secureChannelLog_ = true;
	cond_.initEvent();
	client.asyncConnect(connectContext);
	BOOST_REQUIRE(cond_.waitForEvent(1000) == true);
	BOOST_REQUIRE(sessionState_ == SessionServiceStateId::Established);

	client.defaultHistoryReadContext().maxNumResultValuesPerNode_ = 8;
	client.defaultHistoryReadContext().maxNumResultValuesPerRequest_ = 5;

	// history read
	cond_.initEvent();
	client.asyncHistoryRead(
		OpcUaNodeId("DoubleValue", 12),
		boost::posix_time::microsec_clock::local_time(),
		boost::posix_time::microsec_clock::local_time(),
		[this](OpcUaStatusCode statusCode, OpcUaDataValue::Vec& dataValue) {
			statusCode_ = statusCode;
			dataValue_ = dataValue;
			cond_.sendEvent();
		}
	);
	BOOST_REQUIRE(cond_.waitForEvent(1000) == true);
	BOOST_REQUIRE(statusCode_ == Success);
	BOOST_REQUIRE(dataValue_.size() == 8);

	// disconnect session
	cond_.initEvent();
	client.asyncDisconnect();
	BOOST_REQUIRE(cond_.waitForEvent(1000) == true);
	BOOST_REQUIRE(sessionState_ == SessionServiceStateId::Disconnected);
}

#endif

BOOST_AUTO_TEST_SUITE_END()
