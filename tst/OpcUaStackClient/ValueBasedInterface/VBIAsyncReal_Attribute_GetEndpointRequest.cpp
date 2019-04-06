#include "unittest.h"
#include "OpcUaStackCore/Utility/Environment.h"
#include "OpcUaStackClient/CryptoManagerTest.h"
#include "OpcUaStackClient/ValueBasedInterface/VBIClient.h"

using namespace OpcUaStackCore;
using namespace OpcUaStackClient;

BOOST_AUTO_TEST_SUITE(VBIAsyncReal_Attribute_GetEndpointRequest_)

struct GValueFixture {
	GValueFixture(void)
    : cond_()
	, sessionState_(SessionServiceStateId::None)
	, statusCode_(Success)
    {}
    ~GValueFixture(void)
    {}

    Condition cond_;
    SessionServiceStateId sessionState_;
    OpcUaStatusCode statusCode_;
};

BOOST_AUTO_TEST_CASE(VBIAsyncReal_Attribute_GetEndpointRequest_)
{
	std::cout << "VBIAsyncReal_Attribute_GetEndpointRequest_t" << std::endl;
}

#ifdef REAL_SERVER
BOOST_FIXTURE_TEST_CASE(VBIAsyncReal_Attribute_GetEndpointRequest, GValueFixture)
{
	VBIClient client;

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
	//
	// To enable security, fields applicationUri, securityMode and security policy
	// must be specified.
	//
	std::string applicationUri = std::string("urn:") + CryptoManagerTest::getServerHostName() + std::string(":ASNeG:ASNeG-Demo");
	ConnectContext connectContext;
	connectContext.discoveryUrl_ = REAL_SERVER_URI;						// use get endpoint request to find endpoint url
	connectContext.sessionName_ = REAL_SESSION_NAME;
	connectContext.applicationUri_ = applicationUri;					// needed to detect right certificate
	connectContext.securityMode_ = MessageSecurityMode::EnumSignAndEncrypt;	// security mode
	connectContext.securityPolicy_ = SecurityPolicy::EnumBasic128Rsa15;		// security policy
	connectContext.cryptoManager_ = CryptoManagerTest::getInstance();
	connectContext.secureChannelLog_ = true;
	cond_.initEvent();
	client.asyncConnect(connectContext);
	BOOST_REQUIRE(cond_.waitForEvent(3000) == true);
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
	BOOST_REQUIRE(cond_.waitForEvent(3000) == true);
	BOOST_REQUIRE(statusCode_ == Success);

	// disconnect session
	cond_.initEvent();
	client.asyncDisconnect();
	BOOST_REQUIRE(cond_.waitForEvent(3000) == true);
	BOOST_REQUIRE(sessionState_ == SessionServiceStateId::Disconnected);
}

BOOST_FIXTURE_TEST_CASE(VBIAsyncReal_Attribute_GetEndpointRequest_write, GValueFixture)
{
	VBIClient client;

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
	//
	// To enable security, fields applicationUri, securityMode and security policy
	// must be specified.
	//
	std::string applicationUri = std::string("urn:") + CryptoManagerTest::getServerHostName() + std::string(":ASNeG:ASNeG-Demo");
	ConnectContext connectContext;
	connectContext.discoveryUrl_ = REAL_SERVER_URI;						// use get endpoint request to find endpoint url
	connectContext.sessionName_ = REAL_SESSION_NAME;
	connectContext.applicationUri_ = applicationUri;					// needed to detect right certificate
	connectContext.securityMode_ = MessageSecurityMode::EnumSignAndEncrypt;// security mode
	connectContext.securityPolicy_ = SecurityPolicy::EnumBasic128Rsa15;	   // security policy
	connectContext.cryptoManager_ = CryptoManagerTest::getInstance();;
	connectContext.secureChannelLog_ = true;
	cond_.initEvent();
	client.asyncConnect(connectContext);
	BOOST_REQUIRE(cond_.waitForEvent(3000) == true);
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
	BOOST_REQUIRE(cond_.waitForEvent(3000) == true);
	BOOST_REQUIRE(statusCode_ == Success);

	// disconnect session
	cond_.initEvent();
	client.asyncDisconnect();
	BOOST_REQUIRE(cond_.waitForEvent(3000) == true);
	BOOST_REQUIRE(sessionState_ == SessionServiceStateId::Disconnected);
}
#endif

BOOST_AUTO_TEST_SUITE_END()
