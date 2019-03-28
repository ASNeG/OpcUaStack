#include "unittest.h"
#include "OpcUaStackClient/CryptoManagerTest.h"
#include "OpcUaStackClient/ValueBasedInterface/VBIClient.h"

using namespace OpcUaStackClient;

#ifdef REAL_SERVER

BOOST_AUTO_TEST_SUITE(VBISyncReal_Attribute_)

BOOST_AUTO_TEST_CASE(VBISyncReal_Attribute_)
{
	std::cout << "VBISyncReal_Attribute_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(VBISyncReal_Attribute_read)
{
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

	// read
	OpcUaNodeId nodeId;
	OpcUaDataValue dataValue;
	nodeId.set((OpcUaInt32)2259);
	BOOST_REQUIRE(client.syncRead(nodeId, dataValue) == Success);
	dataValue.out(std::cout);

	// disconnect session
	BOOST_REQUIRE(client.syncDisconnect() == Success);
}

BOOST_AUTO_TEST_CASE(VBISyncReal_Attribute_write)
{
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

	// write
	OpcUaNodeId nodeId;
	OpcUaDataValue dataValue;
	dataValue.variant()->set((OpcUaBoolean)1);
	nodeId.set(220, 2);
	BOOST_REQUIRE(client.syncWrite(nodeId, dataValue) == Success);

	// disconnect session
	BOOST_REQUIRE(client.syncDisconnect() == Success);
}

BOOST_AUTO_TEST_CASE(VBISyncReal_Attribute_historyRead_10)
{
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

	client.defaultHistoryReadContext().maxNumResultValuesPerNode_ = 10;
	client.defaultHistoryReadContext().maxNumResultValuesPerRequest_ = 5;

	// history read
	OpcUaDataValue::Vec dataValueVec;
	auto statusCode = client.syncHistoryRead(
		OpcUaNodeId("DoubleValue", 12),
		boost::posix_time::microsec_clock::local_time(),
		boost::posix_time::microsec_clock::local_time(),
		dataValueVec
	);
	BOOST_REQUIRE(statusCode == Success);
	BOOST_REQUIRE(dataValueVec.size() == 10);

	// disconnect session
	BOOST_REQUIRE(client.syncDisconnect() == Success);
}

BOOST_AUTO_TEST_CASE(VBISyncReal_Attribute_historyRead_8)
{
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

	client.defaultHistoryReadContext().maxNumResultValuesPerNode_ = 8;
	client.defaultHistoryReadContext().maxNumResultValuesPerRequest_ = 5;

	// history read
	OpcUaDataValue::Vec dataValueVec;
	auto statusCode = client.syncHistoryRead(
		OpcUaNodeId("DoubleValue", 12),
		boost::posix_time::microsec_clock::local_time(),
		boost::posix_time::microsec_clock::local_time(),
		dataValueVec
	);
	BOOST_REQUIRE(statusCode == Success);
	BOOST_REQUIRE(dataValueVec.size() == 8);

	// disconnect session
	BOOST_REQUIRE(client.syncDisconnect() == Success);
}

BOOST_AUTO_TEST_SUITE_END()

#endif
