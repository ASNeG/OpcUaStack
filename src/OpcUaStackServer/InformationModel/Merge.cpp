/*
   Copyright 2015 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   Informationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Kai Huebl (kai@huebl-sgh.de)
 */

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
