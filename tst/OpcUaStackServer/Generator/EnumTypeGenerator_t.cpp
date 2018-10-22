#include "unittest.h"
#include "OpcUaStackCore/Base/ConfigXml.h"
#include "OpcUaStackServer/Generator/EnumTypeGenerator.h"
#include "OpcUaStackServer/NodeSet/NodeSetXmlParser.h"
#include "OpcUaStackServer/InformationModel/InformationModelNodeSet.h"

using namespace OpcUaStackServer;

BOOST_AUTO_TEST_SUITE(EnumTypeGenerator_)

BOOST_AUTO_TEST_CASE(EnumTypeGenerator_)
{
	std::cout << "EnumTypeGenerator_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(EnumTypeGenerator_construct_destruct)
{
	bool success;
	EnumTypeGenerator variableTypeGenerator;
}

BOOST_AUTO_TEST_CASE(EnumTypeGenerator_xx)
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


	// generate enum type source code
	{
		EnumTypeGenerator enumTypeGenerator;
		enumTypeGenerator.informationModel(informationModel);
		BOOST_REQUIRE(enumTypeGenerator.generate(OpcUaNodeId(307)) == true);

		std::string sourceContent = enumTypeGenerator.sourceContent();
		std::string headerContent = enumTypeGenerator.headerContent();

		std::cout << std::endl;
		std::cout << headerContent << std::endl;
		std::cout << std::endl;
		std::cout << sourceContent << std::endl;
		std::cout << std::endl;
	}


}

BOOST_AUTO_TEST_SUITE_END()
