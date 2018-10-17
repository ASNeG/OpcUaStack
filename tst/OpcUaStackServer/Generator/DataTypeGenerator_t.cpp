#include "unittest.h"
#include "OpcUaStackCore/Base/ConfigXml.h"
#include "OpcUaStackServer/Generator/DataTypeGenerator.h"
#include "OpcUaStackServer/NodeSet/NodeSetXmlParser.h"
#include "OpcUaStackServer/InformationModel/InformationModelNodeSet.h"

using namespace OpcUaStackServer;

BOOST_AUTO_TEST_SUITE(DataTypeGenerator_)

BOOST_AUTO_TEST_CASE(DataTypeGenerator_)
{
	std::cout << "DataTypeGenerator_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(DataTypeGenerator_construct_destruct)
{
	bool success;
	DataTypeGenerator variableTypeGenerator;
}

BOOST_AUTO_TEST_CASE(DataTypeGenerator_xx)
{
	bool success;

	// read opc ua nodeset
	ConfigXml configXml;
    success = configXml.parse("../tst/data/Opc.Ua.NodeSet2.xml");
    if (!success) {
    	std::cout << configXml.errorMessage() << std::endl;
    }
    BOOST_REQUIRE(success == true);

    NodeSetXmlParser nodeSetXmlParser;
    success = nodeSetXmlParser.decode(configXml.ptree());
    BOOST_REQUIRE(success == true);

    NodeSetNamespace& nodeSetNamespace = nodeSetXmlParser.nodeSetNamespace();
    NamespaceVec& namespaceVec = nodeSetNamespace.localNamespaceVec();
    NamespaceVec::iterator it;

	InformationModel::SPtr informationModel = constructSPtr<InformationModel>();
	success = InformationModelNodeSet::initial(informationModel, nodeSetXmlParser);
	BOOST_REQUIRE(success == true);

	informationModel->checkForwardReferences();


	// generate data type source
	OpcUaNodeId dataTypeNodeId(22);
	DataTypeGenerator variableTypeGenerator;
	variableTypeGenerator.informationModel(informationModel);
	variableTypeGenerator.dataType(dataTypeNodeId);
	BOOST_REQUIRE(variableTypeGenerator.generate() == true);

	std::string sourceContent = variableTypeGenerator.sourceContent();
	std::string headerContent = variableTypeGenerator.headerContent();

	std::cout << std::endl;
	std::cout << headerContent << std::endl;
	std::cout << std::endl;
	std::cout << sourceContent << std::endl;
	std::cout << std::endl;

}

BOOST_AUTO_TEST_SUITE_END()
