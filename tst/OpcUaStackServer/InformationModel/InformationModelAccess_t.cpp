#include "unittest.h"

#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackServer/AddressSpaceModel/BaseNodeClass.h"
#include "OpcUaStackServer/AddressSpaceModel/ObjectNodeClass.h"
#include "OpcUaStackServer/InformationModel/InformationModelAccess.h"

using namespace OpcUaStackCore;
using namespace OpcUaStackServer;

BOOST_AUTO_TEST_SUITE(InformationModelAccess_)

BOOST_AUTO_TEST_CASE(InformationModelAccess_)
{
	std::cout << "InformationModelAccess_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(InformationModelAccess_getRootNode)
{
	bool success;
	BaseNodeClass::SPtr baseNodeClass;
	InformationModel::SPtr informationModel = InformationModel::construct();
	InformationModelAccess informationModelAccess;
	informationModelAccess.informationModel(informationModel);

	OpcUaNodeId nodeId;
	nodeId.nodeId(OpcUaId_RootFolder);

	// root node does not exist
	success = informationModelAccess.getNode(nodeId, baseNodeClass);
	BOOST_REQUIRE(success == false);

	// add root node to information model
	baseNodeClass = ObjectNodeClass::construct();
	baseNodeClass->setNodeId(nodeId);
	informationModel->insert(baseNodeClass);

	// root node does exist
	success = informationModelAccess.getNode(nodeId, baseNodeClass);
	BOOST_REQUIRE(success == true);
	BOOST_REQUIRE(*baseNodeClass->getNodeId() == nodeId);
}

BOOST_AUTO_TEST_SUITE_END()
