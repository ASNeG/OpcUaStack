#include "unittest.h"
#include "OpcUaStackClient/ValueBasedInterface/VBIClient.h"
#include "OpcUaStackClient/ValueBasedInterface/VBIClientHandlerTest.h"

using namespace OpcUaStackClient;

#ifdef REAL_SERVER

BOOST_AUTO_TEST_SUITE(VBIAsyncReal_Session_)

BOOST_AUTO_TEST_CASE(VBIAsyncReal_Session_)
{
	std::cout << "VBIAsyncReal_Session_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(VBIAsyncReal_Session_session_connect_disconnect)
{
	VBIClientHandlerTest vbiClientHandlerTest;
	VBIClient client;

	// connect session
	ConnectContext connectContext;
	connectContext.endpointUrl_ = REAL_SERVER_URI;
	connectContext.sessionName_ = REAL_SESSION_NAME;
	vbiClientHandlerTest.sessionStateUpdate_.condition(1,0);
	client.asyncConnect(
		boost::bind(&VBIClientHandlerTest::sessionStateUpdate, &vbiClientHandlerTest, (uint32_t)1234, _1, _2),
		connectContext
	);
	BOOST_REQUIRE(vbiClientHandlerTest.sessionStateUpdate_.waitForCondition(1000) == true);
	BOOST_REQUIRE(vbiClientHandlerTest.sessionState_ == SS_Connect);
	BOOST_REQUIRE(vbiClientHandlerTest.clientHandle_ == 1234);

	// disconnect session
	vbiClientHandlerTest.sessionStateUpdate_.condition(1,0);
	client.asyncDisconnect();
	BOOST_REQUIRE(vbiClientHandlerTest.sessionStateUpdate_.waitForCondition(1000) == true);
	BOOST_REQUIRE(vbiClientHandlerTest.sessionState_ == SS_Disconnect);
	BOOST_REQUIRE(vbiClientHandlerTest.clientHandle_ == 1234);
}

BOOST_AUTO_TEST_CASE(VBIAsyncReal_Session_session_connect_disconnect_two_times)
{
	VBIClientHandlerTest vbiClientHandlerTest;
	VBIClient client;

	// connect session
	ConnectContext connectContext;
	connectContext.endpointUrl_ = REAL_SERVER_URI;
	connectContext.sessionName_ = REAL_SESSION_NAME;
	vbiClientHandlerTest.sessionStateUpdate_.condition(1,0);
	client.asyncConnect(
		boost::bind(&VBIClientHandlerTest::sessionStateUpdate, &vbiClientHandlerTest, (uint32_t)1234, _1, _2),
		connectContext
	);
	BOOST_REQUIRE(vbiClientHandlerTest.sessionStateUpdate_.waitForCondition(1000) == true);
	BOOST_REQUIRE(vbiClientHandlerTest.sessionState_ == SS_Connect);
	BOOST_REQUIRE(vbiClientHandlerTest.clientHandle_ == 1234);

	// disconnect session
	vbiClientHandlerTest.sessionStateUpdate_.condition(1,0);
	client.asyncDisconnect();
	BOOST_REQUIRE(vbiClientHandlerTest.sessionStateUpdate_.waitForCondition(1000) == true);
	BOOST_REQUIRE(vbiClientHandlerTest.sessionState_ == SS_Disconnect);
	BOOST_REQUIRE(vbiClientHandlerTest.clientHandle_ == 1234);

	// connect session
	vbiClientHandlerTest.sessionStateUpdate_.condition(1,0);
	client.asyncConnect(
		boost::bind(&VBIClientHandlerTest::sessionStateUpdate, &vbiClientHandlerTest, (uint32_t)1234, _1, _2),
		connectContext
	);
	BOOST_REQUIRE(vbiClientHandlerTest.sessionStateUpdate_.waitForCondition(1000) == true);
	BOOST_REQUIRE(vbiClientHandlerTest.sessionState_ == SS_Connect);
	BOOST_REQUIRE(vbiClientHandlerTest.clientHandle_ == 1234);

	// disconnect session
	vbiClientHandlerTest.sessionStateUpdate_.condition(1,0);
	client.asyncDisconnect();
	BOOST_REQUIRE(vbiClientHandlerTest.sessionStateUpdate_.waitForCondition(1000) == true);
	BOOST_REQUIRE(vbiClientHandlerTest.sessionState_ == SS_Disconnect);
	BOOST_REQUIRE(vbiClientHandlerTest.clientHandle_ == 1234);
}


BOOST_AUTO_TEST_SUITE_END()

#endif
