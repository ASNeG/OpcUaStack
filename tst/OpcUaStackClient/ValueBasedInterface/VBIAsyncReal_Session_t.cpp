#include "unittest.h"
#include "OpcUaStackClient/CryptoManagerTest.h"
#include "OpcUaStackClient/ValueBasedInterface/VBIClient.h"
#include "OpcUaStackClient/ValueBasedInterface/VBIClientHandlerTest.h"

using namespace OpcUaStackClient;

#ifdef REAL_SERVER

BOOST_AUTO_TEST_SUITE(VBIAsyncReal_Session_)

struct GValueFixture {
	GValueFixture(void)
    : cond_()
	, sessionState_(SessionServiceStateId::None)
    {}
    ~GValueFixture(void)
    {}

    Condition cond_;
    SessionServiceStateId sessionState_;
};

BOOST_AUTO_TEST_CASE(VBIAsyncReal_Session_)
{
	std::cout << "VBIAsyncReal_Session_t" << std::endl;
}

BOOST_FIXTURE_TEST_CASE(VBIAsyncReal_Session_session_connect_disconnect, GValueFixture)
{
	VBIClientHandlerTest vbiClientHandlerTest;
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
	cond_.condition(1,0);
	client.asyncConnect(connectContext);
	BOOST_REQUIRE(cond_.waitForCondition(1000) == true);
	BOOST_REQUIRE(sessionState_ == SessionServiceStateId::Established);

	// disconnect session
	cond_.condition(1,0);
	client.asyncDisconnect();
	BOOST_REQUIRE(cond_.waitForCondition(1000) == true);
	BOOST_REQUIRE(sessionState_ == SessionServiceStateId::Disconnected);
}

BOOST_FIXTURE_TEST_CASE(VBIAsyncReal_Session_session_connect_disconnect_two_times, GValueFixture)
{
	VBIClientHandlerTest vbiClientHandlerTest;
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
	cond_.condition(1,0);
	client.asyncConnect(connectContext);
	BOOST_REQUIRE(cond_.waitForCondition(1000) == true);
	BOOST_REQUIRE(sessionState_ == SessionServiceStateId::Established);

	// disconnect session
	cond_.condition(1,0);
	client.asyncDisconnect();
	BOOST_REQUIRE(cond_.waitForCondition(1000) == true);
	BOOST_REQUIRE(sessionState_ == SessionServiceStateId::Disconnected);

	// connect session
	cond_.condition(1,0);
	client.asyncConnect(connectContext);
	BOOST_REQUIRE(cond_.waitForCondition(1000) == true);
	BOOST_REQUIRE(sessionState_ == SessionServiceStateId::Established);

	// disconnect session
	cond_.condition(1,0);
	client.asyncDisconnect();
	BOOST_REQUIRE(cond_.waitForCondition(1000) == true);
	BOOST_REQUIRE(sessionState_ == SessionServiceStateId::Disconnected);
}


BOOST_AUTO_TEST_SUITE_END()

#endif
