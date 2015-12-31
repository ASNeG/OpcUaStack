#include "unittest.h"
#include "OpcUaStackClient/ServiceSet/ServiceSetManager.h"

using namespace OpcUaStackClient;

#ifdef REAL_SERVER

BOOST_AUTO_TEST_SUITE(ServiceSetManagerAsyncReal_)

BOOST_AUTO_TEST_CASE(ServiceSetManagerAsyncReal_)
{
	std::cout << "ServiceSetManagerAsyncReal_t" << std::endl;
}


// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
//
// unittests secure channel
//
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
BOOST_AUTO_TEST_CASE(ServiceSetManagerAsyncReal_secureChannel_connect_disconnect)
{
	ServiceSetManager serviceSetManager;
	SessionIfTestHandler sessionIfTestHandler;
	SessionServiceConfig sessionServiceConfig;

	// set secure channel configuration
	sessionServiceConfig.mode_ = Session::M_SecureChannel;
	sessionServiceConfig.sessionIf_ = &sessionIfTestHandler;
	sessionServiceConfig.secureChannelClient_->endpointUrl(REAL_SERVER_URI);

	// create session
	Session::SPtr session = serviceSetManager.createSession(sessionServiceConfig);
	BOOST_REQUIRE(session.get() != nullptr);

	// connect secure channel
	sessionIfTestHandler.sessionStateUpdate_.condition(1,0);
	session->asyncConnect();
	BOOST_REQUIRE(sessionIfTestHandler.sessionStateUpdate_.waitForCondition(1000) == true);
	BOOST_REQUIRE(sessionIfTestHandler.sessionState_ == SS_Connect);

	// disconnect secure channel
	sessionIfTestHandler.sessionStateUpdate_.condition(1,0);
	session->asyncDisconnect();
	BOOST_REQUIRE(sessionIfTestHandler.sessionStateUpdate_.waitForCondition(1000) == true);
	BOOST_REQUIRE(sessionIfTestHandler.sessionState_ == SS_Disconnect);
}


// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
//
// xx
//
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------

BOOST_AUTO_TEST_SUITE_END()

#endif
