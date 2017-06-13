/*
   Copyright 2015-2017 Kai Huebl (kai@huebl-sgh.de)

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
#include "OpcUaStackServer/InformationModel/InformationModelManager.h"
#include "OpcUaStackServer/AddressSpaceModel/ObjectNodeClass.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	InformationModelManager::InformationModelManager(void)
	: informationModel_()
	{
	}

	InformationModelManager::InformationModelManager(InformationModel::SPtr informationModel)
	{
		informationModel_ = informationModel;
	}

	InformationModelManager::~InformationModelManager(void)
	{
	}

	void
	InformationModelManager::informationModel(InformationModel::SPtr informationModel)
	{
		informationModel_ = informationModel;
	}

	bool
	InformationModelManager::addObjectNode(
		OpcUaNodeId& parentNodeId,
		OpcUaNodeId& nodeId,
		OpcUaLocalizedText& displayName,
		OpcUaQualifiedName& browseName,
		OpcUaNodeId& referenceNodeId,
		OpcUaNodeId& typeNodeId
	)
	{
		// get parent node class
		BaseNodeClass::SPtr parentNodeClass;
		parentNodeClass = informationModel_->find(parentNodeId);
		if (parentNodeClass.get() == nullptr) {
			Log(Error, "parent node id not exist in information model")
				.parameter("ParentNodeId", parentNodeId);
			return false;
		}

		// get type node class
		BaseNodeClass::SPtr typeNodeClass;
		typeNodeClass = informationModel_->find(typeNodeId);
		if (typeNodeClass.get() == nullptr) {
			Log(Error, "type node id not exist in information model")
				.parameter("TypeNodeId", typeNodeId);
			return false;
		}

		// get reference node class
		BaseNodeClass::SPtr referenceNodeClass;
		referenceNodeClass = informationModel_->find(referenceNodeId);
		if (referenceNodeClass.get() == nullptr) {
			Log(Error, "reference node id not exist in information model")
				.parameter("ReferenceNodeId", referenceNodeId);
			return false;
		}

		// create new object node and add the attributes
		ObjectNodeClass::SPtr objectNodeClass = constructSPtr<ObjectNodeClass>();
		objectNodeClass->setNodeId(nodeId);
		objectNodeClass->setBrowseName(browseName);
		objectNodeClass->setDisplayName(displayName);

		OpcUaLocalizedText description;
		typeNodeClass->getDescription(description);
		objectNodeClass->setDescription(description);

		OpcUaUInt32 writeMask;
		typeNodeClass->getWriteMask(writeMask);
		objectNodeClass->setWriteMask(writeMask);

		OpcUaUInt32 userWriteMask;
		typeNodeClass->getWriteMask(userWriteMask);
		objectNodeClass->setWriteMask(userWriteMask);

		OpcUaByte eventNotifier;
		typeNodeClass->getEventNotifier(eventNotifier);
		objectNodeClass->setEventNotifier(eventNotifier);

		return true;
	}

}

