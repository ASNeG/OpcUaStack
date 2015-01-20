#include "unittest.h"

#include "OpcUaStackCore/Core/FileLogger.h"
#include "OpcUaStackCore/Base/ConfigXml.h"
#include "OpcUaStackServer/InformationModel/InformationModelNodeSet.h"
#include "OpcUaStackServer/nodeSet/NodeSetXmlParser.h"
#include "OpcUaStackUtility/NodeSet/NodeSetClientReader.h"

using namespace OpcUaStackCore;
//using namespace OpcUaStackClient;
using namespace OpcUaStackServer;
using namespace OpcUaStackUtility;

BOOST_AUTO_TEST_SUITE(NodeSetClientReadeR_)

BOOST_AUTO_TEST_CASE(Session_)
{
	std::cout << "NodeSetClientReader_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(NodeSetClientReader_read)
{
	bool rc;

	FileLogger fileLogger;
	OpcUaStackCore::Log::logIf(&fileLogger);

	// configuration session
	Config sessionConfig; 
	//sessionConfig.setValue("NodeSetClientReaderConfig.EndpointUrl", "opc.tcp://10.49.143.147:4880");
	sessionConfig.setValue("NodeSetClientReaderConfig.EndpointUrl", "opc.tcp://127.0.0.1:8888");
	sessionConfig.setValue("NodeSetClientReaderConfig.SessionName", "urn:127.0.0.1:Company:MyAppl");
	sessionConfig.setValue("NodeSetClientReaderConfig.ApplicationDescription.ApplicationUri", "urn:127.0.0.1:Company:MyAppl");
	sessionConfig.setValue("NodeSetClientReaderConfig.ApplicationDescription.ProductUri", "urn:Company:MyAppl");
	sessionConfig.setValue("NodeSetClientReaderConfig.ApplicationDescription.ApplicationName.Locale", "en");
	sessionConfig.setValue("NodeSetClientReaderConfig.ApplicationDescription.ApplicationName.Text", "MyAppl");

	// configuration secure channel
	Config secureChannelConfig;
	//secureChannelConfig.setValue("NodeSetClientReaderConfig.EndpointUrl", "opc.tcp://10.49.143.147:4880");
	secureChannelConfig.setValue("NodeSetClientReaderConfig.EndpointUrl", "opc.tcp://127.0.0.1:8888");
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

	std::cout << "objects=" << nodeSetClientReader.objectNodeClassVec().size() << std::endl;
	std::cout << "variables=" << nodeSetClientReader.variableNodeClassVec().size() << std::endl;
	std::cout << "methods=" << nodeSetClientReader.methodNodeClassVec().size() << std::endl;
	std::cout << "objectTypes=" << nodeSetClientReader.objectTypeNodeClassVec().size() << std::endl;
	std::cout << "variableTypes=" << nodeSetClientReader.variableTypeNodeClassVec().size() << std::endl;
	std::cout << "referenceTypes=" << nodeSetClientReader.referenceTypeNodeClassVec().size() << std::endl;
	std::cout << "dataTypes=" << nodeSetClientReader.dataTypeNodeClassVec().size() << std::endl;
	std::cout << "views=" << nodeSetClientReader.viewNodeClassVec().size() << std::endl;


	// write nodes from node set into information model
	InformationModel::SPtr informationModel = InformationModel::construct();
	rc = InformationModelNodeSet::initial(informationModel, nodeSetClientReader);
	BOOST_REQUIRE(rc == true);

	
	// write nodes from information model into node set file
	NodeSetXmlParser nodeSetXmlParser;
	rc = InformationModelNodeSet::initial(nodeSetXmlParser, informationModel, namespaceVec);
	BOOST_REQUIRE(rc == true);

	ConfigXml configXml;
	rc = nodeSetXmlParser.encode(configXml.ptree());
	BOOST_REQUIRE(rc == true);

	rc = configXml.write("test-nodeset.xml");
	BOOST_REQUIRE(rc == true);

}

BOOST_AUTO_TEST_SUITE_END()