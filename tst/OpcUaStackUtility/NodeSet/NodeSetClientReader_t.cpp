#include "unittest.h"

#include "OpcUaStackCore/Core/FileLogger.h"
#include "OpcUaStackCore/Base/ConfigXml.h"
#include "OpcUaStackServer/InformationModel/InformationModelNodeSet.h"
#include "OpcUaStackServer/NodeSet/NodeSetXmlParser.h"
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

BOOST_AUTO_TEST_CASE(NodeSetClientReader_readXml_readXml_readClient_)
{
	bool rc;
	FileLogger fileLogger;
	OpcUaStackCore::Log::logIf(&fileLogger);
	NamespaceVec::iterator it;

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// read from xml file
	// namespace: http://opcfoundation.org/UA/
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	ConfigXml configXmlRead1;
	rc = configXmlRead1.read("../tst/data/Opc.Ua.NodeSet.xml");
	BOOST_REQUIRE(rc == true);

	NodeSetXmlParser nodeSetXmlParserRead1;
	rc = nodeSetXmlParserRead1.decode(configXmlRead1.ptree());
	BOOST_REQUIRE(rc == true);

	InformationModel::SPtr informationModelRead1 = InformationModel::construct();
	rc = InformationModelNodeSet::initial(informationModelRead1, nodeSetXmlParserRead1);
	BOOST_REQUIRE(rc == true);

	informationModelRead1->checkForwardReferences();

	NodeSetNamespace& nodeSetNamespaceRead1 = nodeSetXmlParserRead1.nodeSetNamespace();
	NamespaceVec& namespaceVecRead1 = nodeSetNamespaceRead1.localNamespaceVec();
	std::cout << "Read1:" << std::endl;
	for (it = namespaceVecRead1.begin(); it != namespaceVecRead1.end(); it++) {
		std::cout << "NamespaceUri=" << *it << ", NamespaceIndex=" << nodeSetNamespaceRead1.mapToGlobalNamespaceIndex(*it) << std::endl;
	}



	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// read from xml file
	// namespace: http://yourorganisation.org/Opc.Ua.Raspberry/
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	ConfigXml configXmlRead2;
	rc = configXmlRead2.read("../tst/data/Opc.Ua.NodeSetRaspberry.xml");
	BOOST_REQUIRE(rc == true);

	NodeSetXmlParser nodeSetXmlParserRead2;
	rc = nodeSetXmlParserRead2.decode(configXmlRead2.ptree());
	BOOST_REQUIRE(rc == true);

	InformationModel::SPtr informationModelRead2 = InformationModel::construct();
	rc = InformationModelNodeSet::initial(informationModelRead2, nodeSetXmlParserRead2);
	BOOST_REQUIRE(rc == true);

	informationModelRead2->checkForwardReferences();

	NodeSetNamespace& nodeSetNamespaceRead2 = nodeSetXmlParserRead2.nodeSetNamespace();
	NamespaceVec& namespaceVecRead2 = nodeSetNamespaceRead2.localNamespaceVec();
	std::cout << "Read2:" << std::endl;
	for (it = namespaceVecRead2.begin(); it != namespaceVecRead2.end(); it++) {
		std::cout << "NamespaceUri=" << *it << ", NamespaceIndex=" << nodeSetNamespaceRead2.mapToGlobalNamespaceIndex(*it) << std::endl;
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// read from xml file
	// namespace: http://opcfoundation.org/UA/
	// namespace: http://yourorganisation.org/Test-Server/
	// namespace: http://yourorganisation.org/Opc.Ua.Raspberry/
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	// configuration session
	Config sessionConfig;

	//sessionConfig.setValue("NodeSetClientReaderConfig.EndpointUrl", "opc.tcp://10.43.1.133:4841");
	//sessionConfig.setValue("NodeSetClientReaderConfig.EndpointUrl", "opc.tcp://10.49.143.162:4880");
	sessionConfig.setValue("NodeSetClientReaderConfig.EndpointUrl", "opc.tcp://127.0.0.1:8888");
	sessionConfig.setValue("NodeSetClientReaderConfig.SessionName", "urn:127.0.0.1:Company:MyAppl");
	sessionConfig.setValue("NodeSetClientReaderConfig.ApplicationDescription.ApplicationUri", "urn:127.0.0.1:Company:MyAppl");
	sessionConfig.setValue("NodeSetClientReaderConfig.ApplicationDescription.ProductUri", "urn:Company:MyAppl");
	sessionConfig.setValue("NodeSetClientReaderConfig.ApplicationDescription.ApplicationName.Locale", "en");
	sessionConfig.setValue("NodeSetClientReaderConfig.ApplicationDescription.ApplicationName.Text", "MyAppl");

	// configuration secure channel
	Config secureChannelConfig;
	//secureChannelConfig.setValue("NodeSetClientReaderConfig.EndpointUrl", "opc.tcp://10.43.1.133:4841");
	//secureChannelConfig.setValue("NodeSetClientReaderConfig.EndpointUrl", "opc.tcp://10.49.143.162:4880");
	secureChannelConfig.setValue("NodeSetClientReaderConfig.EndpointUrl", "opc.tcp://127.0.0.1:8888");
	secureChannelConfig.setValue("NodeSetClientReaderConfig.SecurityPolicyUri", "http://opcfoundation.org/UA/SecurityPolicy#None");

	// set start node
	OpcUaNodeId startNodeId;
	startNodeId.set(84, 0);

	// read node set from opc ua server
	NodeSetClientReader nodeSetClientReader;
	rc = nodeSetClientReader.readNodes(
		"NodeSetClientReaderConfig", sessionConfig,
		"NodeSetClientReaderConfig", secureChannelConfig,
		startNodeId
	);
	BOOST_REQUIRE(rc == true);

	InformationModel::SPtr informationModelRead3 = InformationModel::construct();
	rc = InformationModelNodeSet::initial(informationModelRead3, nodeSetClientReader);
	BOOST_REQUIRE(rc == true);

	informationModelRead3->checkForwardReferences();

	NodeSetNamespace& nodeSetNamespaceRead3 = nodeSetClientReader.nodeSetNamespace();
	NamespaceVec& namespaceVecRead3 = nodeSetNamespaceRead3.localNamespaceVec();
	std::cout << "Read3:" << std::endl;
	for (it = namespaceVecRead3.begin(); it != namespaceVecRead3.end(); it++) {
		std::cout << "NamespaceUri=" << *it << ", NamespaceIndex=" << nodeSetNamespaceRead3.mapToGlobalNamespaceIndex(*it) << std::endl;
	}


	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// get all global namespaces
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	NodeSetNamespace& nodeSetNamespace = nodeSetClientReader.nodeSetNamespace();
	NamespaceVec& namespaceVec = nodeSetNamespace.globalNamespaceVec();
	std::cout << "All:" << std::endl;
	for (it = namespaceVec.begin(); it != namespaceVec.end(); it++) {
		std::cout << "NamespaceUri=" << *it << ", NamespaceIndex=" << nodeSetNamespace.mapToGlobalNamespaceIndex(*it) << std::endl;
	}


	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// check namespace
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
#if 0
	uint32_t counter = 0;
	InformationModelMap::iterator itm;
	for (
		itm = informationModelRead3->informationModelMap().begin();
		itm != informationModelRead3->informationModelMap().end();
		itm++
	)
	{
		counter++;
		//if (counter == 10) break;

		BaseNodeClass::SPtr baseNodeClassSPtr = itm->second;
		OpcUaNodeId& nodeId = baseNodeClassSPtr->nodeId().data();
		std::cout << nodeId << std::endl;
	}
#endif
}

BOOST_AUTO_TEST_CASE(NodeSetClientReader_readClient_writeFile)
{
	//while (1) {
	bool rc;

	FileLogger fileLogger;
	OpcUaStackCore::Log::logIf(&fileLogger);


	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// read information model from OpcUaServer
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------


	// configuration session
	Config sessionConfig; 
	//sessionConfig.setValue("NodeSetClientReaderConfig.EndpointUrl", "opc.tcp://10.43.1.133:4841");
	//sessionConfig.setValue("NodeSetClientReaderConfig.EndpointUrl", "opc.tcp://10.49.143.162:4880");
	sessionConfig.setValue("NodeSetClientReaderConfig.EndpointUrl", "opc.tcp://127.0.0.1:8888");
	sessionConfig.setValue("NodeSetClientReaderConfig.SessionName", "urn:127.0.0.1:Company:MyAppl");
	sessionConfig.setValue("NodeSetClientReaderConfig.ApplicationDescription.ApplicationUri", "urn:127.0.0.1:Company:MyAppl");
	sessionConfig.setValue("NodeSetClientReaderConfig.ApplicationDescription.ProductUri", "urn:Company:MyAppl");
	sessionConfig.setValue("NodeSetClientReaderConfig.ApplicationDescription.ApplicationName.Locale", "en");
	sessionConfig.setValue("NodeSetClientReaderConfig.ApplicationDescription.ApplicationName.Text", "MyAppl");

	// configuration secure channel
	Config secureChannelConfig;
	//secureChannelConfig.setValue("NodeSetClientReaderConfig.EndpointUrl", "opc.tcp://10.43.1.133:4841");
	//secureChannelConfig.setValue("NodeSetClientReaderConfig.EndpointUrl", "opc.tcp://10.49.143.162:4880");
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


	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// write information model to file
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------


	// write nodes from node set into information model
	InformationModel::SPtr informationModelWrite = InformationModel::construct();
	rc = InformationModelNodeSet::initial(informationModelWrite, nodeSetClientReader);
	BOOST_REQUIRE(rc == true);

	informationModelWrite->checkForwardReferences();

	
	// write nodes from information model into node set file
	NodeSetXmlParser nodeSetXmlParserWrite;
	rc = InformationModelNodeSet::initial(nodeSetXmlParserWrite, informationModelWrite, namespaceVec);
	BOOST_REQUIRE(rc == true);

	ConfigXml configXmlWrite;
	rc = nodeSetXmlParserWrite.encode(configXmlWrite.ptree());
	BOOST_REQUIRE(rc == true);

	rc = configXmlWrite.write("test-nodeset.xml");
	BOOST_REQUIRE(rc == true);


	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// read information model from file
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	ConfigXml configXmlRead;
	rc = configXmlRead.parse("test-nodeset.xml");
	BOOST_REQUIRE(rc == true);


	NodeSetXmlParser nodeSetXmlParserRead;
	rc = nodeSetXmlParserRead.decode(configXmlRead.ptree());
	BOOST_REQUIRE(rc == true);

	InformationModel::SPtr informationModelRead = InformationModel::construct();
	rc = InformationModelNodeSet::initial(informationModelRead, nodeSetXmlParserRead);
	BOOST_REQUIRE(rc == true);

	std::cout << "objects=" << nodeSetXmlParserRead.objectNodeClassVec().size() << std::endl;
	std::cout << "variables=" << nodeSetXmlParserRead.variableNodeClassVec().size() << std::endl;
	std::cout << "methods=" << nodeSetXmlParserRead.methodNodeClassVec().size() << std::endl;
	std::cout << "objectTypes=" << nodeSetXmlParserRead.objectTypeNodeClassVec().size() << std::endl;
	std::cout << "variableTypes=" << nodeSetXmlParserRead.variableTypeNodeClassVec().size() << std::endl;
	std::cout << "referenceTypes=" << nodeSetXmlParserRead.referenceTypeNodeClassVec().size() << std::endl;
	std::cout << "dataTypes=" << nodeSetXmlParserRead.dataTypeNodeClassVec().size() << std::endl;
	std::cout << "views=" << nodeSetXmlParserRead.viewNodeClassVec().size() << std::endl;

//}

}

BOOST_AUTO_TEST_SUITE_END()
