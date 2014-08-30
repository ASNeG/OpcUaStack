#include "unittest.h"
#include "OpcUaStackCore/Base/Config.h"
#include "OpcUaStackCore/Base/IOService.h"
#include "OpcUaStackClient/ServiceSet/Session.h"
#include "OpcUaStackClient/ServiceSet/SessionConfig.h"

#include <boost/asio/error.hpp>
#include "SessionTestHandler.h"

using namespace OpcUaStackCore;
using namespace OpcUaStackClient;

BOOST_AUTO_TEST_SUITE(Session_)

BOOST_AUTO_TEST_CASE(Session_)
{
	std::cout << "Session_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(Session_open)
{
	SessionTestHandler sessionTestHandler;
	IOService ioService;
	ioService.start(1);

	Config config; 
	config.setValue("TestConfig.EndpointUrl", "opc.tcp://127.0.0.1:4841");
	config.setValue("TestConfig.SessionName", "urn:127.0.0.1:Company:MyAppl");
	config.setValue("TestConfig.ApplicationDescription.ApplicationUri", "urn:127.0.0.1:Company:MyAppl");
	config.setValue("TestConfig.ApplicationDescription.ProductUri", "urn:Company:MyAppl");
	config.setValue("TestConfig.ApplicationDescription.ApplicationName.Locale", "en");
	config.setValue("TestConfig.ApplicationDescription.ApplicationName.Text", "MyAppl");

	Session::SPtr session = Session::construct();
	SessionConfig::initial(session, "TestConfig", &config);
	session->sessionIf(&sessionTestHandler);
	session->createSession();

	IOService::msecSleep(2000);

	Config::destroy();
	ioService.stop();
}

BOOST_AUTO_TEST_SUITE_END()