#include "unittest.h"
#include "OpcUaStackClient/CryptoManagerTest.h"
#include "OpcUaStackClient/ValueBasedInterface/VBIClient.h"

using namespace OpcUaStackClient;

#ifdef REAL_SERVER

BOOST_AUTO_TEST_SUITE(VBISyncReal_Session_)

BOOST_AUTO_TEST_CASE(VBISyncReal_Session_)
{
	std::cout << "VBISyncReal_Session_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(VBISyncReal_Session_session_connect_disconnect)
{
	OpcUaStatusCode statusCode;
	VBIClient client;


	//
	// init certificate and crypto manager
	//
	CryptoManager::SPtr cryptoManager = CryptoManagerTest::getInstance();
	BOOST_REQUIRE(cryptoManager.get() != nullptr);

	// connect session
	ConnectContext connectContext;
	connectContext.endpointUrl_ = REAL_SERVER_URI;
	connectContext.sessionName_ = REAL_SESSION_NAME;
	connectContext.cryptoManager_ = cryptoManager;
	connectContext.secureChannelLog_ = true;
	BOOST_REQUIRE(client.syncConnect(connectContext) == Success);

	// disconnect session
	BOOST_REQUIRE(client.syncDisconnect() == Success);
}

BOOST_AUTO_TEST_CASE(VBISyncReal_Session_session_connect_disconnect_two_times)
{
	OpcUaStatusCode statusCode;
	VBIClient client;


	//
	// init certificate and crypto manager
	//
	CryptoManager::SPtr cryptoManager = CryptoManagerTest::getInstance();
	BOOST_REQUIRE(cryptoManager.get() != nullptr);

	// connect session
	ConnectContext connectContext;
	connectContext.endpointUrl_ = REAL_SERVER_URI;
	connectContext.sessionName_ = REAL_SESSION_NAME;
	connectContext.cryptoManager_ = cryptoManager;
	connectContext.secureChannelLog_ = true;
	BOOST_REQUIRE(client.syncConnect(connectContext) == Success);

	// disconnect session
	BOOST_REQUIRE(client.syncDisconnect() == Success);

	// connect session
	BOOST_REQUIRE(client.syncConnect(connectContext) == Success);

	// disconnect session
	BOOST_REQUIRE(client.syncDisconnect() == Success);
}


BOOST_AUTO_TEST_SUITE_END()

#endif
