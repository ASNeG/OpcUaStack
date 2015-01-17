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

	// configuration session
	Config sessionConfig; 
	sessionConfig.setValue("NodeSetClientReaderConfig.EndpointUrl", "opc.tcp://127.0.0.1:4841");
	sessionConfig.setValue("NodeSetClientReaderConfig.SessionName", "urn:127.0.0.1:Company:MyAppl");
	sessionConfig.setValue("NodeSetClientReaderConfig.ApplicationDescription.ApplicationUri", "urn:127.0.0.1:Company:MyAppl");
	sessionConfig.setValue("NodeSetClientReaderConfig.ApplicationDescription.ProductUri", "urn:Company:MyAppl");
	sessionConfig.setValue("NodeSetClientReaderConfig.ApplicationDescription.ApplicationName.Locale", "en");
	sessionConfig.setValue("NodeSetClientReaderConfig.ApplicationDescription.ApplicationName.Text", "MyAppl");

	// configuration secure channel
	Config secureChannelConfig;
	secureChannelConfig.setValue("NodeSetClientReaderConfig.EndpointUrl", "opc.tcp://127.0.0.1:4841");
	secureChannelConfig.setValue("NodeSetClientReaderConfig.SecurityPolicyUri", "http://opcfoundation.org/UA/SecurityPolicy#None");

	// read node set from opc ua server
	NodeSetClientReader nodeSetClientReader;
	rc = nodeSetClientReader.readNodes(
		"NodeSetClientReaderConfig", sessionConfig,
		"NodeSetClientReaderConfig", secureChannelConfig
	);
	BOOST_REQUIRE(rc == true);

	// display namespace uris from opc ua server
	NamespaceVec::iterator it;
	NodeSetNamespace& nodeSetNamespace = nodeSetClientReader.nodeSetNamespace();
	NamespaceVec& namespaceVec = nodeSetNamespace.localNamespaceVec();
	for (it = namespaceVec.begin(); it != namespaceVec.end(); it++) {
		std::cout << "NamespaceUri=" << *it << ", NamespaceIndex=" << nodeSetNamespace.mapToGlobalNamespaceIndex(*it) << std::endl;
	}
}

BOOST_AUTO_TEST_SUITE_END()