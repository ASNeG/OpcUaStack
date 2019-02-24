#include "unittest.h"
#include <chrono>
#include "OpcUaStackServer/AddressSpaceModel/ObjectNodeClass.h"
#include "OpcUaStackServer/InformationModel/InformationModel.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"

using namespace OpcUaStackServer;
using namespace OpcUaStackCore;
using namespace std::chrono;

BOOST_AUTO_TEST_SUITE(BenchMarks_t)

BOOST_AUTO_TEST_CASE(BenchMarks_t)
{
	std::cout << "BenchMarks_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(BenchMarks_Insert_StringNodeId_1000)
{
	const int ITERATION_COUNT = 5000;

	std::vector<BaseNodeClass::SPtr> nodeSample;
	std::hash<std::string> hashStdString;
	for (int i = 0; i < ITERATION_COUNT; ++i) {
		OpcUaNodeId nodeId(std::to_string(hashStdString(std::to_string(i))), 2); // use hash from string to avoid sorting sample
		BaseNodeClass::SPtr node = constructSPtr<ObjectNodeClass>();
		node->setNodeId(nodeId);

		nodeSample.push_back(node);
	}

	InformationModel model;
	BaseNodeClass::SPtr root = constructSPtr<ObjectNodeClass>();
	OpcUaNodeId id("root");
	root->setNodeId(id);
	model.insert(root);

	auto insertToInformationModel = [&](BaseNodeClass::SPtr node) {
		assert(model.insert(node));

		root->referenceItemMap().add(ReferenceType_Organizes, true, node->getNodeId().get());
		node->referenceItemMap().add(ReferenceType_Organizes, false, root->getNodeId().get());
	};

	auto startTime = system_clock::now();
	std::for_each(nodeSample.begin(), nodeSample.end(), insertToInformationModel);
	auto stopTime = system_clock::now();

	std::cout << "Inserting of " << ITERATION_COUNT << " nodes takes " <<  duration_cast<milliseconds>(stopTime - startTime).count() << " ms.";

}

BOOST_AUTO_TEST_SUITE_END()
