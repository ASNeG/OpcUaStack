#include "unittest.h"

#include "OpcUaStackUtility/NodeSet/NodeSetClientReader.h"

//using namespace OpcUaStackCore;
//using namespace OpcUaStackClient;
//using namespace OpcUaStackServer;
using namespace OpcUaStackUtility;

BOOST_AUTO_TEST_SUITE(NodeSetClientReadeR_)

BOOST_AUTO_TEST_CASE(Session_)
{
	std::cout << "NodeSetClientReader_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(NodeSetClientReader_read)
{
	bool rc;

	Config sessionConfig; 
	sessionConfig.setValue("NodeSetClientReaderConfig.EndpointUrl", "opc.tcp://127.0.0.1:4841");
	sessionConfig.setValue("NodeSetClientReaderConfig.SessionName", "urn:127.0.0.1:Company:MyAppl");
	sessionConfig.setValue("NodeSetClientReaderConfig.ApplicationDescription.ApplicationUri", "urn:127.0.0.1:Company:MyAppl");
	sessionConfig.setValue("NodeSetClientReaderConfig.ApplicationDescription.ProductUri", "urn:Company:MyAppl");
	sessionConfig.setValue("NodeSetClientReaderConfig.ApplicationDescription.ApplicationName.Locale", "en");
	sessionConfig.setValue("NodeSetClientReaderConfig.ApplicationDescription.ApplicationName.Text", "MyAppl");

	Config secureChannelConfig;
	secureChannelConfig.setValue("NodeSetClientReaderConfig.EndpointUrl", "opc.tcp://127.0.0.1:4841");
	secureChannelConfig.setValue("NodeSetClientReaderConfig.SecurityPolicyUri", "http://opcfoundation.org/UA/SecurityPolicy#None");

	// read node set from server
	NodeSetClientReader nodeSetClientReader;
	rc = nodeSetClientReader.readNodes(
		"NodeSetClientReaderConfig", sessionConfig,
		"NodeSetClientReaderConfig", secureChannelConfig
	);
	BOOST_REQUIRE(rc == true);
}

BOOST_AUTO_TEST_SUITE_END()