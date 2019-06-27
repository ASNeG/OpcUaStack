#include "unittest.h"
#include "OpcUaStackClient/CryptoManagerTest.h"
#include "OpcUaStackClient/ServiceSet/ServiceSetManager.h"

using namespace OpcUaStackClient;

#if 0
#ifdef REAL_SERVER

BOOST_AUTO_TEST_SUITE(ServiceSetManagerAsyncReal_UserAuthentication_)

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

BOOST_AUTO_TEST_CASE(ServiceSetManagerAsyncReal_UserAuthentication_)
{
	std::cout << "ServiceSetManagerAsyncReal_UserAuthentication_t" << std::endl;
}

BOOST_FIXTURE_TEST_CASE(ServiceSetManagerAsyncReal_UserAuthentication_user_auth_anonymous, GValueFixture)
{
	ServiceSetManager serviceSetManager;

	//
	// init certificate and crypto manager
	//
	auto cryptoManager = CryptoManagerTest::getInstance();
	BOOST_REQUIRE(cryptoManager.get() != nullptr);

	// set secure channel configuration
	std::string applicationUri = std::string("urn:") + CryptoManagerTest::getServerHostName() + std::string(":ASNeG:ASNeG-Demo");
	SessionServiceConfig sessionServiceConfig;
	sessionServiceConfig.secureChannelClient_->endpointUrl(REAL_SERVER_URI);
	sessionServiceConfig.secureChannelClient_->applicationUri(applicationUri);
	sessionServiceConfig.secureChannelClient_->cryptoManager(cryptoManager);
	sessionServiceConfig.secureChannelClient_->securityMode(MessageSecurityMode::EnumSignAndEncrypt);
	sessionServiceConfig.secureChannelClient_->securityPolicy(SecurityPolicy::EnumBasic128Rsa15);
	sessionServiceConfig.session_->sessionName(REAL_SESSION_NAME);
	sessionServiceConfig.session_->authenticationAnonymous("anonymous");
	sessionServiceConfig.sessionServiceChangeHandler_ =
		[this] (SessionBase& session, SessionServiceStateId sessionState) {
			if (sessionState == SessionServiceStateId::Established ||
				sessionState == SessionServiceStateId::Disconnected) {
				sessionState_ = sessionState;
				cond_.sendEvent();
			}
		};

	// create session
	SessionService::SPtr sessionService;
	sessionService = serviceSetManager.sessionService(sessionServiceConfig);
	BOOST_REQUIRE(sessionService.get() != nullptr);

	// connect session
	cond_.condition(1,0);
	sessionService->asyncConnect();
	BOOST_REQUIRE(cond_.waitForCondition(1000) == true);
	BOOST_REQUIRE(sessionState_ == SessionServiceStateId::Established);

	// disconnect session
	cond_.condition(1,0);
	sessionService->asyncDisconnect();
	BOOST_REQUIRE(cond_.waitForCondition(1000) == true);
	BOOST_REQUIRE(sessionState_ == SessionServiceStateId::Disconnected);
}

//
// user name authentication with plain password
//
BOOST_FIXTURE_TEST_CASE(ServiceSetManagerAsyncReal_UserAuthentication_user_auth_user_name_none, GValueFixture)
{
	ServiceSetManager serviceSetManager;

	//
	// init certificate and crypto manager
	//
	auto cryptoManager = CryptoManagerTest::getInstance();
	BOOST_REQUIRE(cryptoManager.get() != nullptr);

	// set secure channel configuration
	std::string applicationUri = std::string("urn:") + CryptoManagerTest::getServerHostName() + std::string(":ASNeG:ASNeG-Demo");
	SessionServiceConfig sessionServiceConfig;
	sessionServiceConfig.secureChannelClient_->endpointUrl(REAL_SERVER_URI);
	sessionServiceConfig.secureChannelClient_->applicationUri(applicationUri);
	sessionServiceConfig.secureChannelClient_->cryptoManager(cryptoManager);
	sessionServiceConfig.secureChannelClient_->securityMode(MessageSecurityMode::EnumSignAndEncrypt);
	sessionServiceConfig.secureChannelClient_->securityPolicy(SecurityPolicy::EnumBasic128Rsa15);
	sessionServiceConfig.session_->sessionName(REAL_SESSION_NAME);
	sessionServiceConfig.session_->authenticationUserName(
		"OpcUaStack2",
		"user1",
		"password1",
		"",
		""
	);
	sessionServiceConfig.sessionServiceChangeHandler_ =
		[this] (SessionBase& session, SessionServiceStateId sessionState) {
			if (sessionState == SessionServiceStateId::Established ||
				sessionState == SessionServiceStateId::Disconnected) {
				sessionState_ = sessionState;
				cond_.sendEvent();
			}
		};

	// create session
	SessionService::SPtr sessionService;
	sessionService = serviceSetManager.sessionService(sessionServiceConfig);
	BOOST_REQUIRE(sessionService.get() != nullptr);

	// connect session
	cond_.condition(1,0);
	sessionService->asyncConnect();
	BOOST_REQUIRE(cond_.waitForCondition(1000) == true);
	BOOST_REQUIRE(sessionState_ == SessionServiceStateId::Established);

	// disconnect session
	cond_.condition(1,0);
	sessionService->asyncDisconnect();
	BOOST_REQUIRE(cond_.waitForCondition(1000) == true);
	BOOST_REQUIRE(sessionState_ == SessionServiceStateId::Disconnected);
}

//
// user name authentication with encrypted password (Basic256)
//
BOOST_FIXTURE_TEST_CASE(ServiceSetManagerAsyncReal_UserAuthentication_user_auth_user_name_basic256, GValueFixture)
{
	ServiceSetManager serviceSetManager;

	//
	// init certificate and crypto manager
	//
	auto cryptoManager = CryptoManagerTest::getInstance();
	BOOST_REQUIRE(cryptoManager.get() != nullptr);

	// set secure channel configuration
	std::string applicationUri = std::string("urn:") + CryptoManagerTest::getServerHostName() + std::string(":ASNeG:ASNeG-Demo");
	SessionServiceConfig sessionServiceConfig;
	sessionServiceConfig.secureChannelClient_->endpointUrl(REAL_SERVER_URI);
	sessionServiceConfig.secureChannelClient_->applicationUri(applicationUri);
	sessionServiceConfig.secureChannelClient_->cryptoManager(cryptoManager);
	sessionServiceConfig.secureChannelClient_->securityMode(MessageSecurityMode::EnumSignAndEncrypt);
	sessionServiceConfig.secureChannelClient_->securityPolicy(SecurityPolicy::EnumBasic256);
	sessionServiceConfig.session_->sessionName(REAL_SESSION_NAME);
	sessionServiceConfig.session_->authenticationUserName(
		"OpcUaStack2",
		"user1",
		"password1",
		"http://opcfoundation.org/UA/SecurityPolicy#Basic256"
	);
	sessionServiceConfig.sessionServiceChangeHandler_ =
		[this] (SessionBase& session, SessionServiceStateId sessionState) {
			if (sessionState == SessionServiceStateId::Established ||
				sessionState == SessionServiceStateId::Disconnected) {
				sessionState_ = sessionState;
				cond_.sendEvent();
			}
		};

	// create session
	SessionService::SPtr sessionService;
	sessionService = serviceSetManager.sessionService(sessionServiceConfig);
	BOOST_REQUIRE(sessionService.get() != nullptr);

	// connect session
	cond_.condition(1,0);
	sessionService->asyncConnect();
	BOOST_REQUIRE(cond_.waitForCondition(1000) == true);
	BOOST_REQUIRE(sessionState_ == SessionServiceStateId::Established);

	// disconnect session
	cond_.condition(1,0);
	sessionService->asyncDisconnect();
	BOOST_REQUIRE(cond_.waitForCondition(1000) == true);
	BOOST_REQUIRE(sessionState_ == SessionServiceStateId::Disconnected);
}

//
// user name authentication with encrypted password (Basic128Rsa15)
//
BOOST_FIXTURE_TEST_CASE(ServiceSetManagerAsyncReal_UserAuthentication_user_auth_user_name_basic128rsa15, GValueFixture)
{
	ServiceSetManager serviceSetManager;

	//
	// init certificate and crypto manager
	//
	auto cryptoManager = CryptoManagerTest::getInstance();
	BOOST_REQUIRE(cryptoManager.get() != nullptr);

	// set secure channel configuration
	std::string applicationUri = std::string("urn:") + CryptoManagerTest::getServerHostName() + std::string(":ASNeG:ASNeG-Demo");
	SessionServiceConfig sessionServiceConfig;
	sessionServiceConfig.secureChannelClient_->endpointUrl(REAL_SERVER_URI);
	sessionServiceConfig.secureChannelClient_->applicationUri(applicationUri);
	sessionServiceConfig.secureChannelClient_->cryptoManager(cryptoManager);
	sessionServiceConfig.secureChannelClient_->securityMode(MessageSecurityMode::EnumSignAndEncrypt);
	sessionServiceConfig.secureChannelClient_->securityPolicy(SecurityPolicy::EnumBasic256);
	sessionServiceConfig.session_->sessionName(REAL_SESSION_NAME);
	sessionServiceConfig.session_->authenticationUserName(
		"OpcUaStack3",
		"user1",
		"password1",
		"http://opcfoundation.org/UA/SecurityPolicy#Basic128Rsa15"
	);
	sessionServiceConfig.sessionServiceChangeHandler_ =
		[this] (SessionBase& session, SessionServiceStateId sessionState) {
			if (sessionState == SessionServiceStateId::Established ||
				sessionState == SessionServiceStateId::Disconnected) {
				sessionState_ = sessionState;
				cond_.sendEvent();
			}
		};

	// create session
	SessionService::SPtr sessionService;
	sessionService = serviceSetManager.sessionService(sessionServiceConfig);
	BOOST_REQUIRE(sessionService.get() != nullptr);

	// connect session
	cond_.condition(1,0);
	sessionService->asyncConnect();
	BOOST_REQUIRE(cond_.waitForCondition(1000) == true);
	BOOST_REQUIRE(sessionState_ == SessionServiceStateId::Established);

	// disconnect session
	cond_.condition(1,0);
	sessionService->asyncDisconnect();
	BOOST_REQUIRE(cond_.waitForCondition(1000) == true);
	BOOST_REQUIRE(sessionState_ == SessionServiceStateId::Disconnected);
}

//
// x509 authentication with certificate (Basic256)
//
BOOST_FIXTURE_TEST_CASE(ServiceSetManagerAsyncReal_UserAuthentication_user_auth_certificate_basic256, GValueFixture)
{
	ServiceSetManager serviceSetManager;

	//
	// init certificate and crypto manager
	//
	auto cryptoManager = CryptoManagerTest::getInstance();
	BOOST_REQUIRE(cryptoManager.get() != nullptr);

	// set secure channel configuration
	auto certificate = cryptoManager->applicationCertificate()->certificateChain().getCertificate();
	auto privateKey = cryptoManager->applicationCertificate()->privateKey();

	std::string applicationUri = std::string("urn:") + CryptoManagerTest::getServerHostName() + std::string(":ASNeG:ASNeG-Demo");
	SessionServiceConfig sessionServiceConfig;
	sessionServiceConfig.secureChannelClient_->endpointUrl(REAL_SERVER_URI);
	sessionServiceConfig.secureChannelClient_->applicationUri(applicationUri);
	sessionServiceConfig.secureChannelClient_->cryptoManager(cryptoManager);
	sessionServiceConfig.secureChannelClient_->securityMode(MessageSecurityMode::EnumSignAndEncrypt);
	sessionServiceConfig.secureChannelClient_->securityPolicy(SecurityPolicy::EnumBasic256);
	sessionServiceConfig.session_->sessionName(REAL_SESSION_NAME);
	sessionServiceConfig.session_->authenticationX509(
		"OpcUaStack6",
		certificate,
		privateKey,
		"http://opcfoundation.org/UA/SecurityPolicy#Basic256"
	);
	sessionServiceConfig.sessionServiceChangeHandler_ =
		[this] (SessionBase& session, SessionServiceStateId sessionState) {
			if (sessionState == SessionServiceStateId::Established ||
				sessionState == SessionServiceStateId::Disconnected) {
				sessionState_ = sessionState;
				cond_.sendEvent();
			}
		};

	// create session
	SessionService::SPtr sessionService;
	sessionService = serviceSetManager.sessionService(sessionServiceConfig);
	BOOST_REQUIRE(sessionService.get() != nullptr);

	// connect session
	cond_.condition(1,0);
	sessionService->asyncConnect();
	BOOST_REQUIRE(cond_.waitForCondition(1000) == true);
	BOOST_REQUIRE(sessionState_ == SessionServiceStateId::Established);

	// disconnect session
	cond_.condition(1,0);
	sessionService->asyncDisconnect();
	BOOST_REQUIRE(cond_.waitForCondition(1000) == true);
	BOOST_REQUIRE(sessionState_ == SessionServiceStateId::Disconnected);
}

//
// x509 authentication with certificate (Basic128Rsa15)
//
BOOST_FIXTURE_TEST_CASE(ServiceSetManagerAsyncReal_UserAuthentication_user_auth_certificate_basic128rsa15, GValueFixture)
{
	ServiceSetManager serviceSetManager;

	//
	// init certificate and crypto manager
	//
	auto cryptoManager = CryptoManagerTest::getInstance();
	BOOST_REQUIRE(cryptoManager.get() != nullptr);

	// set secure channel configuration
	auto certificate = cryptoManager->applicationCertificate()->certificateChain().getCertificate();
	auto privateKey = cryptoManager->applicationCertificate()->privateKey();

	std::string applicationUri = std::string("urn:") + CryptoManagerTest::getServerHostName() + std::string(":ASNeG:ASNeG-Demo");
	SessionServiceConfig sessionServiceConfig;
	sessionServiceConfig.secureChannelClient_->endpointUrl(REAL_SERVER_URI);
	sessionServiceConfig.secureChannelClient_->applicationUri(applicationUri);
	sessionServiceConfig.secureChannelClient_->cryptoManager(cryptoManager);
	sessionServiceConfig.secureChannelClient_->securityMode(MessageSecurityMode::EnumSignAndEncrypt);
	sessionServiceConfig.secureChannelClient_->securityPolicy(SecurityPolicy::EnumBasic256);
	sessionServiceConfig.session_->sessionName(REAL_SESSION_NAME);
	sessionServiceConfig.session_->authenticationX509(
		"OpcUaStack7",
		certificate,
		privateKey,
		"http://opcfoundation.org/UA/SecurityPolicy#Basic128Rsa15"
	);
	sessionServiceConfig.sessionServiceChangeHandler_ =
		[this] (SessionBase& session, SessionServiceStateId sessionState) {
			if (sessionState == SessionServiceStateId::Established ||
				sessionState == SessionServiceStateId::Disconnected) {
				sessionState_ = sessionState;
				cond_.sendEvent();
			}
		};

	// create session
	SessionService::SPtr sessionService;
	sessionService = serviceSetManager.sessionService(sessionServiceConfig);
	BOOST_REQUIRE(sessionService.get() != nullptr);

	// connect session
	cond_.condition(1,0);
	sessionService->asyncConnect();
	BOOST_REQUIRE(cond_.waitForCondition(1000) == true);
	BOOST_REQUIRE(sessionState_ == SessionServiceStateId::Established);

	// disconnect session
	cond_.condition(1,0);
	sessionService->asyncDisconnect();
	BOOST_REQUIRE(cond_.waitForCondition(1000) == true);
	BOOST_REQUIRE(sessionState_ == SessionServiceStateId::Disconnected);
}

//
// issued authentication with encrypted password (Basic256)
//
BOOST_FIXTURE_TEST_CASE(ServiceSetManagerAsyncReal_UserAuthentication_user_auth_issued_basic256, GValueFixture)
{
	ServiceSetManager serviceSetManager;

	//
	// init certificate and crypto manager
	//
	auto cryptoManager = CryptoManagerTest::getInstance();
	BOOST_REQUIRE(cryptoManager.get() != nullptr);

	// set secure channel configuration
	std::string applicationUri = std::string("urn:") + CryptoManagerTest::getServerHostName() + std::string(":ASNeG:ASNeG-Demo");
	SessionServiceConfig sessionServiceConfig;
	sessionServiceConfig.secureChannelClient_->endpointUrl(REAL_SERVER_URI);
	sessionServiceConfig.secureChannelClient_->applicationUri(applicationUri);
	sessionServiceConfig.secureChannelClient_->cryptoManager(cryptoManager);
	sessionServiceConfig.secureChannelClient_->securityMode(MessageSecurityMode::EnumSignAndEncrypt);
	sessionServiceConfig.secureChannelClient_->securityPolicy(SecurityPolicy::EnumBasic256);
	sessionServiceConfig.session_->sessionName(REAL_SESSION_NAME);
	sessionServiceConfig.session_->authenticationIssued(
		"OpcUaStack4",
		"Token Data",
		"http://opcfoundation.org/UA/SecurityPolicy#Basic256"
	);
	sessionServiceConfig.sessionServiceChangeHandler_ =
		[this] (SessionBase& session, SessionServiceStateId sessionState) {
			if (sessionState == SessionServiceStateId::Established ||
				sessionState == SessionServiceStateId::Disconnected) {
				sessionState_ = sessionState;
				cond_.sendEvent();
			}
		};

	// create session
	SessionService::SPtr sessionService;
	sessionService = serviceSetManager.sessionService(sessionServiceConfig);
	BOOST_REQUIRE(sessionService.get() != nullptr);

	// connect session
	cond_.condition(1,0);
	sessionService->asyncConnect();
	BOOST_REQUIRE(cond_.waitForCondition(1000) == true);
	BOOST_REQUIRE(sessionState_ == SessionServiceStateId::Established);

	// disconnect session
	cond_.condition(1,0);
	sessionService->asyncDisconnect();
	BOOST_REQUIRE(cond_.waitForCondition(1000) == true);
	BOOST_REQUIRE(sessionState_ == SessionServiceStateId::Disconnected);
}

//
// issued authentication with encrypted password (Basic128Rsa15)
//
BOOST_FIXTURE_TEST_CASE(ServiceSetManagerAsyncReal_UserAuthentication_user_auth_issued_basic128rsa15, GValueFixture)
{
	ServiceSetManager serviceSetManager;

	//
	// init certificate and crypto manager
	//
	auto cryptoManager = CryptoManagerTest::getInstance();
	BOOST_REQUIRE(cryptoManager.get() != nullptr);

	// set secure channel configuration
	std::string applicationUri = std::string("urn:") + CryptoManagerTest::getServerHostName() + std::string(":ASNeG:ASNeG-Demo");
	SessionServiceConfig sessionServiceConfig;
	sessionServiceConfig.secureChannelClient_->endpointUrl(REAL_SERVER_URI);
	sessionServiceConfig.secureChannelClient_->applicationUri(applicationUri);
	sessionServiceConfig.secureChannelClient_->cryptoManager(cryptoManager);
	sessionServiceConfig.secureChannelClient_->securityMode(MessageSecurityMode::EnumSignAndEncrypt);
	sessionServiceConfig.secureChannelClient_->securityPolicy(SecurityPolicy::EnumBasic256);
	sessionServiceConfig.session_->sessionName(REAL_SESSION_NAME);
	sessionServiceConfig.session_->authenticationIssued(
		"OpcUaStack5",
		"Token Data",
		"http://opcfoundation.org/UA/SecurityPolicy#Basic128Rsa15"
	);
	sessionServiceConfig.sessionServiceChangeHandler_ =
		[this] (SessionBase& session, SessionServiceStateId sessionState) {
			if (sessionState == SessionServiceStateId::Established ||
				sessionState == SessionServiceStateId::Disconnected) {
				sessionState_ = sessionState;
				cond_.sendEvent();
			}
		};

	// create session
	SessionService::SPtr sessionService;
	sessionService = serviceSetManager.sessionService(sessionServiceConfig);
	BOOST_REQUIRE(sessionService.get() != nullptr);

	// connect session
	cond_.condition(1,0);
	sessionService->asyncConnect();
	BOOST_REQUIRE(cond_.waitForCondition(1000) == true);
	BOOST_REQUIRE(sessionState_ == SessionServiceStateId::Established);

	// disconnect session
	cond_.condition(1,0);
	sessionService->asyncDisconnect();
	BOOST_REQUIRE(cond_.waitForCondition(1000) == true);
	BOOST_REQUIRE(sessionState_ == SessionServiceStateId::Disconnected);
}

BOOST_FIXTURE_TEST_CASE(ServiceSetManagerAsyncReal_UserAuthenticationGetEndpoint_user_auth_anonymous, GValueFixture)
{
	ServiceSetManager serviceSetManager;

	//
	// init certificate and crypto manager
	//
	auto cryptoManager = CryptoManagerTest::getInstance();
	BOOST_REQUIRE(cryptoManager.get() != nullptr);

	// set secure channel configuration
	std::string applicationUri = std::string("urn:") + CryptoManagerTest::getServerHostName() + std::string(":ASNeG:ASNeG-Demo");
	SessionServiceConfig sessionServiceConfig;
	sessionServiceConfig.secureChannelClient_->discoveryUrl(REAL_SERVER_URI);
	sessionServiceConfig.secureChannelClient_->applicationUri(applicationUri);
	sessionServiceConfig.secureChannelClient_->cryptoManager(cryptoManager);
	sessionServiceConfig.secureChannelClient_->securityMode(MessageSecurityMode::EnumSignAndEncrypt);
	sessionServiceConfig.secureChannelClient_->securityPolicy(SecurityPolicy::EnumBasic128Rsa15);
	sessionServiceConfig.session_->sessionName(REAL_SESSION_NAME);
	sessionServiceConfig.session_->authenticationAnonymous();
	sessionServiceConfig.sessionServiceChangeHandler_ =
		[this] (SessionBase& session, SessionServiceStateId sessionState) {
			if (sessionState == SessionServiceStateId::Established ||
				sessionState == SessionServiceStateId::Disconnected) {
				sessionState_ = sessionState;
				cond_.sendEvent();
			}
		};

	// create session
	SessionService::SPtr sessionService;
	sessionService = serviceSetManager.sessionService(sessionServiceConfig);
	BOOST_REQUIRE(sessionService.get() != nullptr);

	// connect session
	cond_.condition(1,0);
	sessionService->asyncConnect();
	BOOST_REQUIRE(cond_.waitForCondition(1000) == true);
	BOOST_REQUIRE(sessionState_ == SessionServiceStateId::Established);

	// disconnect session
	cond_.condition(1,0);
	sessionService->asyncDisconnect();
	BOOST_REQUIRE(cond_.waitForCondition(1000) == true);
	BOOST_REQUIRE(sessionState_ == SessionServiceStateId::Disconnected);
}

//
// user name authentication with plain password
//
BOOST_FIXTURE_TEST_CASE(ServiceSetManagerAsyncReal_UserAuthenticationGetEndpoint_user_auth_user_name_none, GValueFixture)
{
	ServiceSetManager serviceSetManager;

	//
	// init certificate and crypto manager
	//
	auto cryptoManager = CryptoManagerTest::getInstance();
	BOOST_REQUIRE(cryptoManager.get() != nullptr);

	// set secure channel configuration
	std::string applicationUri = std::string("urn:") + CryptoManagerTest::getServerHostName() + std::string(":ASNeG:ASNeG-Demo");
	SessionServiceConfig sessionServiceConfig;
	sessionServiceConfig.secureChannelClient_->discoveryUrl(REAL_SERVER_URI);
	sessionServiceConfig.secureChannelClient_->applicationUri(applicationUri);
	sessionServiceConfig.secureChannelClient_->cryptoManager(cryptoManager);
	sessionServiceConfig.secureChannelClient_->securityMode(MessageSecurityMode::EnumSignAndEncrypt);
	sessionServiceConfig.secureChannelClient_->securityPolicy(SecurityPolicy::EnumBasic128Rsa15);
	sessionServiceConfig.session_->sessionName(REAL_SESSION_NAME);
	sessionServiceConfig.session_->authenticationUserName(
		"user1",
		"password1",
		"http://opcfoundation.org/UA/SecurityPolicy#None"
	);
	sessionServiceConfig.sessionServiceChangeHandler_ =
		[this] (SessionBase& session, SessionServiceStateId sessionState) {
			if (sessionState == SessionServiceStateId::Established ||
				sessionState == SessionServiceStateId::Disconnected) {
				sessionState_ = sessionState;
				cond_.sendEvent();
			}
		};

	// create session
	SessionService::SPtr sessionService;
	sessionService = serviceSetManager.sessionService(sessionServiceConfig);
	BOOST_REQUIRE(sessionService.get() != nullptr);

	// connect session
	cond_.condition(1,0);
	sessionService->asyncConnect();
	BOOST_REQUIRE(cond_.waitForCondition(1000) == true);
	BOOST_REQUIRE(sessionState_ == SessionServiceStateId::Established);

	// disconnect session
	cond_.condition(1,0);
	sessionService->asyncDisconnect();
	BOOST_REQUIRE(cond_.waitForCondition(1000) == true);
	BOOST_REQUIRE(sessionState_ == SessionServiceStateId::Disconnected);
}

//
// user name authentication with encrypted password (Basic256)
//
BOOST_FIXTURE_TEST_CASE(ServiceSetManagerAsyncReal_UserAuthenticationGetEndpoint_user_auth_user_name_basic256, GValueFixture)
{
	ServiceSetManager serviceSetManager;

	//
	// init certificate and crypto manager
	//
	auto cryptoManager = CryptoManagerTest::getInstance();
	BOOST_REQUIRE(cryptoManager.get() != nullptr);

	// set secure channel configuration
	std::string applicationUri = std::string("urn:") + CryptoManagerTest::getServerHostName() + std::string(":ASNeG:ASNeG-Demo");
	SessionServiceConfig sessionServiceConfig;
	sessionServiceConfig.secureChannelClient_->discoveryUrl(REAL_SERVER_URI);
	sessionServiceConfig.secureChannelClient_->applicationUri(applicationUri);
	sessionServiceConfig.secureChannelClient_->cryptoManager(cryptoManager);
	sessionServiceConfig.secureChannelClient_->securityMode(MessageSecurityMode::EnumSignAndEncrypt);
	sessionServiceConfig.secureChannelClient_->securityPolicy(SecurityPolicy::EnumBasic256);
	sessionServiceConfig.session_->sessionName(REAL_SESSION_NAME);
	sessionServiceConfig.session_->authenticationUserName(
		"user1",
		"password1",
		"http://opcfoundation.org/UA/SecurityPolicy#Basic256"
	);
	sessionServiceConfig.sessionServiceChangeHandler_ =
		[this] (SessionBase& session, SessionServiceStateId sessionState) {
			if (sessionState == SessionServiceStateId::Established ||
				sessionState == SessionServiceStateId::Disconnected) {
				sessionState_ = sessionState;
				cond_.sendEvent();
			}
		};

	// create session
	SessionService::SPtr sessionService;
	sessionService = serviceSetManager.sessionService(sessionServiceConfig);
	BOOST_REQUIRE(sessionService.get() != nullptr);

	// connect session
	cond_.condition(1,0);
	sessionService->asyncConnect();
	BOOST_REQUIRE(cond_.waitForCondition(1000) == true);
	BOOST_REQUIRE(sessionState_ == SessionServiceStateId::Established);

	// disconnect session
	cond_.condition(1,0);
	sessionService->asyncDisconnect();
	BOOST_REQUIRE(cond_.waitForCondition(1000) == true);
	BOOST_REQUIRE(sessionState_ == SessionServiceStateId::Disconnected);
}

//
// user name authentication with encrypted password (Basic128Rsa15)
//
BOOST_FIXTURE_TEST_CASE(ServiceSetManagerAsyncReal_UserAuthenticationGetEndpoint_user_auth_user_name_basic128rsa15, GValueFixture)
{
	ServiceSetManager serviceSetManager;

	//
	// init certificate and crypto manager
	//
	auto cryptoManager = CryptoManagerTest::getInstance();
	BOOST_REQUIRE(cryptoManager.get() != nullptr);

	// set secure channel configuration
	std::string applicationUri = std::string("urn:") + CryptoManagerTest::getServerHostName() + std::string(":ASNeG:ASNeG-Demo");
	SessionServiceConfig sessionServiceConfig;
	sessionServiceConfig.secureChannelClient_->discoveryUrl(REAL_SERVER_URI);
	sessionServiceConfig.secureChannelClient_->applicationUri(applicationUri);
	sessionServiceConfig.secureChannelClient_->cryptoManager(cryptoManager);
	sessionServiceConfig.secureChannelClient_->securityMode(MessageSecurityMode::EnumSignAndEncrypt);
	sessionServiceConfig.secureChannelClient_->securityPolicy(SecurityPolicy::EnumBasic256);
	sessionServiceConfig.session_->sessionName(REAL_SESSION_NAME);
	sessionServiceConfig.session_->authenticationUserName(
		"user1",
		"password1",
		"http://opcfoundation.org/UA/SecurityPolicy#Basic128Rsa15"
	);
	sessionServiceConfig.sessionServiceChangeHandler_ =
		[this] (SessionBase& session, SessionServiceStateId sessionState) {
			if (sessionState == SessionServiceStateId::Established ||
				sessionState == SessionServiceStateId::Disconnected) {
				sessionState_ = sessionState;
				cond_.sendEvent();
			}
		};

	// create session
	SessionService::SPtr sessionService;
	sessionService = serviceSetManager.sessionService(sessionServiceConfig);
	BOOST_REQUIRE(sessionService.get() != nullptr);

	// connect session
	cond_.condition(1,0);
	sessionService->asyncConnect();
	BOOST_REQUIRE(cond_.waitForCondition(1000) == true);
	BOOST_REQUIRE(sessionState_ == SessionServiceStateId::Established);

	// disconnect session
	cond_.condition(1,0);
	sessionService->asyncDisconnect();
	BOOST_REQUIRE(cond_.waitForCondition(1000) == true);
	BOOST_REQUIRE(sessionState_ == SessionServiceStateId::Disconnected);
}

//
// x509 authentication with certificate (Basic256)
//
BOOST_FIXTURE_TEST_CASE(ServiceSetManagerAsyncReal_UserAuthenticationGetEndpoint_user_auth_certificate_basic256, GValueFixture)
{
	ServiceSetManager serviceSetManager;

	//
	// init certificate and crypto manager
	//
	auto cryptoManager = CryptoManagerTest::getInstance();
	BOOST_REQUIRE(cryptoManager.get() != nullptr);

	// set secure channel configuration
	auto certificate = cryptoManager->applicationCertificate()->certificateChain().getCertificate();
	auto privateKey = cryptoManager->applicationCertificate()->privateKey();

	std::string applicationUri = std::string("urn:") + CryptoManagerTest::getServerHostName() + std::string(":ASNeG:ASNeG-Demo");
	SessionServiceConfig sessionServiceConfig;
	sessionServiceConfig.secureChannelClient_->discoveryUrl(REAL_SERVER_URI);
	sessionServiceConfig.secureChannelClient_->applicationUri(applicationUri);
	sessionServiceConfig.secureChannelClient_->cryptoManager(cryptoManager);
	sessionServiceConfig.secureChannelClient_->securityMode(MessageSecurityMode::EnumSignAndEncrypt);
	sessionServiceConfig.secureChannelClient_->securityPolicy(SecurityPolicy::EnumBasic256);
	sessionServiceConfig.session_->sessionName(REAL_SESSION_NAME);
	sessionServiceConfig.session_->authenticationX509(
		certificate,
		privateKey,
		"http://opcfoundation.org/UA/SecurityPolicy#Basic256"
	);
	sessionServiceConfig.sessionServiceChangeHandler_ =
		[this] (SessionBase& session, SessionServiceStateId sessionState) {
			if (sessionState == SessionServiceStateId::Established ||
				sessionState == SessionServiceStateId::Disconnected) {
				sessionState_ = sessionState;
				cond_.sendEvent();
			}
		};

	// create session
	SessionService::SPtr sessionService;
	sessionService = serviceSetManager.sessionService(sessionServiceConfig);
	BOOST_REQUIRE(sessionService.get() != nullptr);

	// connect session
	cond_.condition(1,0);
	sessionService->asyncConnect();
	BOOST_REQUIRE(cond_.waitForCondition(1000) == true);
	BOOST_REQUIRE(sessionState_ == SessionServiceStateId::Established);

	// disconnect session
	cond_.condition(1,0);
	sessionService->asyncDisconnect();
	BOOST_REQUIRE(cond_.waitForCondition(1000) == true);
	BOOST_REQUIRE(sessionState_ == SessionServiceStateId::Disconnected);
}

//
// x509 authentication with certificate (Basic128Rsa15)
//
BOOST_FIXTURE_TEST_CASE(ServiceSetManagerAsyncReal_UserAuthenticationGetEndpoint_user_auth_certificate_basic128rsa15, GValueFixture)
{
	ServiceSetManager serviceSetManager;

	//
	// init certificate and crypto manager
	//
	auto cryptoManager = CryptoManagerTest::getInstance();
	BOOST_REQUIRE(cryptoManager.get() != nullptr);

	// set secure channel configuration
	auto certificate = cryptoManager->applicationCertificate()->certificateChain().getCertificate();
	auto privateKey = cryptoManager->applicationCertificate()->privateKey();

	std::string applicationUri = std::string("urn:") + CryptoManagerTest::getServerHostName() + std::string(":ASNeG:ASNeG-Demo");
	SessionServiceConfig sessionServiceConfig;
	sessionServiceConfig.secureChannelClient_->discoveryUrl(REAL_SERVER_URI);
	sessionServiceConfig.secureChannelClient_->applicationUri(applicationUri);
	sessionServiceConfig.secureChannelClient_->cryptoManager(cryptoManager);
	sessionServiceConfig.secureChannelClient_->securityMode(MessageSecurityMode::EnumSignAndEncrypt);
	sessionServiceConfig.secureChannelClient_->securityPolicy(SecurityPolicy::EnumBasic256);
	sessionServiceConfig.session_->sessionName(REAL_SESSION_NAME);
	sessionServiceConfig.session_->authenticationX509(
		certificate,
		privateKey,
		"http://opcfoundation.org/UA/SecurityPolicy#Basic128Rsa15"
	);
	sessionServiceConfig.sessionServiceChangeHandler_ =
		[this] (SessionBase& session, SessionServiceStateId sessionState) {
			if (sessionState == SessionServiceStateId::Established ||
				sessionState == SessionServiceStateId::Disconnected) {
				sessionState_ = sessionState;
				cond_.sendEvent();
			}
		};

	// create session
	SessionService::SPtr sessionService;
	sessionService = serviceSetManager.sessionService(sessionServiceConfig);
	BOOST_REQUIRE(sessionService.get() != nullptr);

	// connect session
	cond_.condition(1,0);
	sessionService->asyncConnect();
	BOOST_REQUIRE(cond_.waitForCondition(1000) == true);
	BOOST_REQUIRE(sessionState_ == SessionServiceStateId::Established);

	// disconnect session
	cond_.condition(1,0);
	sessionService->asyncDisconnect();
	BOOST_REQUIRE(cond_.waitForCondition(1000) == true);
	BOOST_REQUIRE(sessionState_ == SessionServiceStateId::Disconnected);
}

//
// issued authentication with encrypted password (Basic256)
//
BOOST_FIXTURE_TEST_CASE(ServiceSetManagerAsyncReal_UserAuthenticationGetEndpoint_user_auth_issued_basic256, GValueFixture)
{
	ServiceSetManager serviceSetManager;

	//
	// init certificate and crypto manager
	//
	auto cryptoManager = CryptoManagerTest::getInstance();
	BOOST_REQUIRE(cryptoManager.get() != nullptr);

	// set secure channel configuration
	std::string applicationUri = std::string("urn:") + CryptoManagerTest::getServerHostName() + std::string(":ASNeG:ASNeG-Demo");
	SessionServiceConfig sessionServiceConfig;
	sessionServiceConfig.secureChannelClient_->discoveryUrl(REAL_SERVER_URI);
	sessionServiceConfig.secureChannelClient_->applicationUri(applicationUri);
	sessionServiceConfig.secureChannelClient_->cryptoManager(cryptoManager);
	sessionServiceConfig.secureChannelClient_->securityMode(MessageSecurityMode::EnumSignAndEncrypt);
	sessionServiceConfig.secureChannelClient_->securityPolicy(SecurityPolicy::EnumBasic256);
	sessionServiceConfig.session_->sessionName(REAL_SESSION_NAME);
	sessionServiceConfig.session_->authenticationIssued(
		"Token Data",
		"http://opcfoundation.org/UA/SecurityPolicy#Basic256"
	);
	sessionServiceConfig.sessionServiceChangeHandler_ =
		[this] (SessionBase& session, SessionServiceStateId sessionState) {
			if (sessionState == SessionServiceStateId::Established ||
				sessionState == SessionServiceStateId::Disconnected) {
				sessionState_ = sessionState;
				cond_.sendEvent();
			}
		};

	// create session
	SessionService::SPtr sessionService;
	sessionService = serviceSetManager.sessionService(sessionServiceConfig);
	BOOST_REQUIRE(sessionService.get() != nullptr);

	// connect session
	cond_.condition(1,0);
	sessionService->asyncConnect();
	BOOST_REQUIRE(cond_.waitForCondition(1000) == true);
	BOOST_REQUIRE(sessionState_ == SessionServiceStateId::Established);

	// disconnect session
	cond_.condition(1,0);
	sessionService->asyncDisconnect();
	BOOST_REQUIRE(cond_.waitForCondition(1000) == true);
	BOOST_REQUIRE(sessionState_ == SessionServiceStateId::Disconnected);
}

//
// issued authentication with encrypted password (Basic128Rsa15)
//
BOOST_FIXTURE_TEST_CASE(ServiceSetManagerAsyncReal_UserAuthenticationGetEndpoint_user_auth_issued_basic128rsa15, GValueFixture)
{
	ServiceSetManager serviceSetManager;

	//
	// init certificate and crypto manager
	//
	auto cryptoManager = CryptoManagerTest::getInstance();
	BOOST_REQUIRE(cryptoManager.get() != nullptr);

	// set secure channel configuration
	std::string applicationUri = std::string("urn:") + CryptoManagerTest::getServerHostName() + std::string(":ASNeG:ASNeG-Demo");
	SessionServiceConfig sessionServiceConfig;
	sessionServiceConfig.secureChannelClient_->discoveryUrl(REAL_SERVER_URI);
	sessionServiceConfig.secureChannelClient_->applicationUri(applicationUri);
	sessionServiceConfig.secureChannelClient_->cryptoManager(cryptoManager);
	sessionServiceConfig.secureChannelClient_->securityMode(MessageSecurityMode::EnumSignAndEncrypt);
	sessionServiceConfig.secureChannelClient_->securityPolicy(SecurityPolicy::EnumBasic256);
	sessionServiceConfig.session_->sessionName(REAL_SESSION_NAME);
	sessionServiceConfig.session_->authenticationIssued(
		"Token Data",
		"http://opcfoundation.org/UA/SecurityPolicy#Basic128Rsa15"
	);
	sessionServiceConfig.sessionServiceChangeHandler_ =
		[this] (SessionBase& session, SessionServiceStateId sessionState) {
			if (sessionState == SessionServiceStateId::Established ||
				sessionState == SessionServiceStateId::Disconnected) {
				sessionState_ = sessionState;
				cond_.sendEvent();
			}
		};

	// create session
	SessionService::SPtr sessionService;
	sessionService = serviceSetManager.sessionService(sessionServiceConfig);
	BOOST_REQUIRE(sessionService.get() != nullptr);

	// connect session
	cond_.condition(1,0);
	sessionService->asyncConnect();
	BOOST_REQUIRE(cond_.waitForCondition(1000) == true);
	BOOST_REQUIRE(sessionState_ == SessionServiceStateId::Established);

	// disconnect session
	cond_.condition(1,0);
	sessionService->asyncDisconnect();
	BOOST_REQUIRE(cond_.waitForCondition(1000) == true);
	BOOST_REQUIRE(sessionState_ == SessionServiceStateId::Disconnected);
}

BOOST_AUTO_TEST_SUITE_END()

#endif
#endif
