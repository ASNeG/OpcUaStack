#include "OpcUaStackServer/InformationModel/RootNode.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	RootNode::RootNode(void)
	: informationModel_()
	{
	}

	RootNode::~RootNode(void)
	{
	}

	void 
	RootNode::informationModel(InformationModel::SPtr informationModel)
	{
		informationModel_ = informationModel;
	}

	BaseNodeClass::SPtr 
	RootNode::rootNode(void)
	{
		OpcUaNodeId nodeId;
		nodeId.nodeId(OpcUaId_RootFolder);
		return informationModel_->find(nodeId);
	}

}