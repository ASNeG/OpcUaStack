#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackServer/InformationModel/Merge.h"


using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	Merge::Merge(void)
	: informationModel_()
	{
	}

	Merge::Merge(InformationModel::SPtr informationModel)
	: informationModel_(informationModel)
	{
	}

	Merge::~Merge(void)
	{
	}

	void
	Merge::informationModel(InformationModel::SPtr informationModel)
	{
		informationModel_ = informationModel;
	}

	bool
	Merge::add(InformationModel::SPtr informationModel, uint16_t namespaceIndex, MergeIf* mergeIf, uint32_t step)
	{
		bool success = true;
		uint32_t actCount = 0;
		uint32_t maxCount = informationModel->informationModelMap().size();

		InformationModelMap::iterator it;
		for (
			it = informationModel->informationModelMap().begin();
			it != informationModel->informationModelMap().end();
			it++
		) {
			if (mergeIf != NULL && actCount % step == 0) mergeIf->handleMerge(maxCount, actCount);
			actCount++;

			if (namespaceIndex != it->first.namespaceIndex()) continue;
			BaseNodeClass::SPtr baseNodeClass = it->second->clone();

			if (!informationModel_->insert(baseNodeClass)) {
				Log(Error, "node id already exist in information model")
					.parameter("NodeId", baseNodeClass->nodeId().data());
				success = false;
			}

			//OpcUaNodeId = baseNodeClass->getParent();
		}
		return success;
	}

}
