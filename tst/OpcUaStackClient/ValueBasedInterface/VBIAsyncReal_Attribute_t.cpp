#include "unittest.h"
#include "OpcUaStackClient/CryptoManagerTest.h"
#include "OpcUaStackClient/ValueBasedInterface/VBIClient.h"

using namespace OpcUaStackCore;
using namespace OpcUaStackClient;

BOOST_AUTO_TEST_SUITE(VBIAsyncReal_Attribute_)

class TestData
{
  public:
    Condition cond_;
	SessionServiceStateId sessionState_ = SessionServiceStateId::None;
	OpcUaStatusCode statusCode_;
	OpcUaDataValue::Vec dataValue_;
};

BOOST_AUTO_TEST_CASE(VBIAsyncReal_Attribute_)
{
	std::cout << "VBIAsyncReal_Attribute_t" << std::endl;
}

#ifdef REAL_SERVER
BOOST_AUTO_TEST_CASE(VBIAsyncReal_Attribute_read)
{
	TestData testData;
	VBIClient client;

	//
	// init certificate and crypto manager
	//
	CryptoManager::SPtr cryptoManager = CryptoManagerTest::getInstance();
	BOOST_REQUIRE(cryptoManager.get() != nullptr);

	// set session change callback
	client.setSessionChangeHandler(
		[this, &testData] (SessionBase& session, SessionServiceStateId sessionState) {
			if (sessionState == SessionServiceStateId::Established ||
				sessionState == SessionServiceStateId::Disconnected) {
				testData.sessionState_ = sessionState;
				testData.cond_.sendEvent();
			}
		}
	);

	// connect session
	ConnectContext connectContext;
	connectContext.endpointUrl_ = REAL_SERVER_URI;
	connectContext.sessionName_ = REAL_SESSION_NAME;
	connectContext.cryptoManager_ = cryptoManager;
	connectContext.secureChannelLog_ = true;
	testData.cond_.initEvent();
	client.asyncConnect(connectContext);
	BOOST_REQUIRE(testData.cond_.waitForEvent(1000) == true);
	BOOST_REQUIRE(testData.sessionState_ == SessionServiceStateId::Established);

	// read
	OpcUaNodeId nodeId;
	nodeId.set((OpcUaInt32)2259);
	testData.cond_.initEvent();
	client.asyncRead(
		nodeId,
		[this, &testData](OpcUaStatusCode statusCode, OpcUaNodeId& nodeId, OpcUaDataValue& dataValue) {
			testData.statusCode_ = statusCode;
			testData.cond_.sendEvent();
		}
	);
	BOOST_REQUIRE(testData.cond_.waitForEvent(1000) == true);
	BOOST_REQUIRE(testData.statusCode_ == Success);

	// disconnect session
	testData.cond_.initEvent();
	client.asyncDisconnect();
	BOOST_REQUIRE(testData.cond_.waitForEvent(1000) == true);
	BOOST_REQUIRE(testData.sessionState_ == SessionServiceStateId::Disconnected);
}

BOOST_AUTO_TEST_CASE(VBIAsyncReal_Attribute_write)
{
	TestData testData;
	VBIClient client;


	//
	// get crypto manager
	//
	CryptoManager::SPtr cryptoManager = CryptoManagerTest::getInstance();
	BOOST_REQUIRE(cryptoManager.get() != nullptr);

	// set session change callback
	client.setSessionChangeHandler(
		[this, &testData] (SessionBase& session, SessionServiceStateId sessionState) {
			if (sessionState == SessionServiceStateId::Established ||
				sessionState == SessionServiceStateId::Disconnected) {
				testData.sessionState_ = sessionState;
				testData.cond_.sendEvent();
			}
		}
	);

	// connect session
	ConnectContext connectContext;
	connectContext.endpointUrl_ = REAL_SERVER_URI;
	connectContext.sessionName_ = REAL_SESSION_NAME;
	connectContext.cryptoManager_ = cryptoManager;
	connectContext.secureChannelLog_ = true;
	testData.cond_.initEvent();
	client.asyncConnect(connectContext);
	BOOST_REQUIRE(testData.cond_.waitForEvent(1000) == true);
	BOOST_REQUIRE(testData.sessionState_ == SessionServiceStateId::Established);

	// write
	OpcUaNodeId nodeId;
	OpcUaDataValue dataValue;
	dataValue.variant()->set((OpcUaBoolean)1);
	nodeId.set(220, 2);
	testData.cond_.initEvent();
	client.asyncWrite(
		nodeId,
		dataValue,
		[this, &testData](OpcUaStatusCode statusCode, OpcUaNodeId& nodeId) {
			testData.statusCode_ = statusCode;
			testData.cond_.sendEvent();
		}
	);
	BOOST_REQUIRE(testData.cond_.waitForEvent(1000) == true);
	BOOST_REQUIRE(testData.statusCode_ == Success);

	// disconnect session
	testData.cond_.initEvent();
	client.asyncDisconnect();
	BOOST_REQUIRE(testData.cond_.waitForEvent(1000) == true);
	BOOST_REQUIRE(testData.sessionState_ == SessionServiceStateId::Disconnected);
}

BOOST_AUTO_TEST_CASE(VBIAsyncReal_Attribute_historyRead_10)
{
	TestData testData;
	VBIClient client;

	//
	// init certificate and crypto manager
	//
	CryptoManager::SPtr cryptoManager = CryptoManagerTest::getInstance();
	BOOST_REQUIRE(cryptoManager.get() != nullptr);

	// set session change callback
	client.setSessionChangeHandler(
		[this, &testData] (SessionBase& session, SessionServiceStateId sessionState) {
			if (sessionState == SessionServiceStateId::Established ||
				sessionState == SessionServiceStateId::Disconnected) {
				testData.sessionState_ = sessionState;
				testData.cond_.sendEvent();
			}
		}
	);

	// connect session
	ConnectContext connectContext;
	connectContext.endpointUrl_ = REAL_SERVER_URI;
	connectContext.sessionName_ = REAL_SESSION_NAME;
	connectContext.cryptoManager_ = cryptoManager;
	connectContext.secureChannelLog_ = true;
	testData.cond_.initEvent();
	client.asyncConnect(connectContext);
	BOOST_REQUIRE(testData.cond_.waitForEvent(1000) == true);
	BOOST_REQUIRE(testData.sessionState_ == SessionServiceStateId::Established);

	client.defaultHistoryReadContext().maxNumResultValuesPerNode_ = 10;
	client.defaultHistoryReadContext().maxNumResultValuesPerRequest_ = 5;

	// history read
	testData.cond_.initEvent();
	client.asyncHistoryRead(
		OpcUaNodeId("DoubleValue", 12),
		boost::posix_time::microsec_clock::local_time(),
		boost::posix_time::microsec_clock::local_time(),
		[this, &testData](OpcUaStatusCode statusCode, OpcUaDataValue::Vec& dataValue) {
			testData.statusCode_ = statusCode;
			testData.dataValue_ = dataValue;
			testData.cond_.sendEvent();
		}
	);
	BOOST_REQUIRE(testData.cond_.waitForEvent(1000) == true);
	BOOST_REQUIRE(testData.statusCode_ == Success);
	BOOST_REQUIRE(testData.dataValue_.size() == 10);

	// disconnect session
	testData.cond_.initEvent();
	client.asyncDisconnect();
	BOOST_REQUIRE(testData.cond_.waitForEvent(1000) == true);
	BOOST_REQUIRE(testData.sessionState_ == SessionServiceStateId::Disconnected);
}

BOOST_AUTO_TEST_CASE(VBIAsyncReal_Attribute_historyRead_8)
{
	TestData testData;
	VBIClient client;

	//
	// init certificate and crypto manager
	//
	CryptoManager::SPtr cryptoManager = CryptoManagerTest::getInstance();
	BOOST_REQUIRE(cryptoManager.get() != nullptr);

	// set session change callback
	client.setSessionChangeHandler(
		[this, &testData] (SessionBase& session, SessionServiceStateId sessionState) {
			if (sessionState == SessionServiceStateId::Established ||
				sessionState == SessionServiceStateId::Disconnected) {
				testData.sessionState_ = sessionState;
				testData.cond_.sendEvent();
			}
		}
	);

	// connect session
	ConnectContext connectContext;
	connectContext.endpointUrl_ = REAL_SERVER_URI;
	connectContext.sessionName_ = REAL_SESSION_NAME;
	connectContext.cryptoManager_ = cryptoManager;
	connectContext.secureChannelLog_ = true;
	testData.cond_.initEvent();
	client.asyncConnect(connectContext);
	BOOST_REQUIRE(testData.cond_.waitForEvent(1000) == true);
	BOOST_REQUIRE(testData.sessionState_ == SessionServiceStateId::Established);

	client.defaultHistoryReadContext().maxNumResultValuesPerNode_ = 8;
	client.defaultHistoryReadContext().maxNumResultValuesPerRequest_ = 5;

	// history read
	testData.cond_.initEvent();
	client.asyncHistoryRead(
		OpcUaNodeId("DoubleValue", 12),
		boost::posix_time::microsec_clock::local_time(),
		boost::posix_time::microsec_clock::local_time(),
		[this, &testData](OpcUaStatusCode statusCode, OpcUaDataValue::Vec& dataValue) {
		    testData.statusCode_ = statusCode;
		    testData.dataValue_ = dataValue;
		    testData.cond_.sendEvent();
		}
	);
	BOOST_REQUIRE(testData.cond_.waitForEvent(1000) == true);
	BOOST_REQUIRE(testData.statusCode_ == Success);
	BOOST_REQUIRE(testData.dataValue_.size() == 8);

	// disconnect session
	testData.cond_.initEvent();
	client.asyncDisconnect();
	BOOST_REQUIRE(testData.cond_.waitForEvent(1000) == true);
	BOOST_REQUIRE(testData.sessionState_ == SessionServiceStateId::Disconnected);
}

#endif

BOOST_AUTO_TEST_SUITE_END()
