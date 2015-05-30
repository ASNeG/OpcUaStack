#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackServer/InformationModel/InformationModelAccess.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	InformationModelAccess::InformationModelAccess(void)
	: informationModel_()
	{
	}

	InformationModelAccess::InformationModelAccess(InformationModel::SPtr informationModel)
	{
		informationModel_ = informationModel;
	}

	InformationModelAccess::~InformationModelAccess(void)
	{
	}

	void
	InformationModelAccess::informationModel(InformationModel::SPtr informationModel)
	{
		informationModel_ = informationModel;
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// type functions
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	bool
	InformationModelAccess::getType(BaseNodeClass::SPtr baseNodeClass, BaseNodeClass::SPtr& typeBaseNodeClass)
	{
		std::pair<ReferenceItemMultiMap::iterator,ReferenceItemMultiMap::iterator> it;
		it = baseNodeClass->referenceItemMap().referenceItemMultiMap().equal_range(*ReferenceTypeMap::hasTypeDefinitionTypeNodeId());
		if (it.first == it.second) {
			Log(Warning, "HasTypeDefinition reference not exist in node")
				.parameter("NodeId", baseNodeClass->nodeId());
			return false;
		}

		ReferenceItemMultiMap::iterator itl;
		for (itl = it.first; itl != it.second; itl++) {
			ReferenceItem::SPtr referenceItem  = itl->second;

			if (!referenceItem->isForward_) continue;

			typeBaseNodeClass = informationModel_->find(referenceItem->nodeId_);
			if (typeBaseNodeClass.get() == nullptr) {
				Log(Warning, "type node not found in information model")
					.parameter("SourceNode", "")
					.parameter("TypeNode", "");
				return false;
			}
		}

		Log(Warning, "HasTypeDefinition forward reference not exist in node")
			.parameter("NodeId", baseNodeClass->nodeId());

		return true;
	}

	bool
	InformationModelAccess::getType(BaseNodeClass::SPtr baseNodeClass, OpcUaNodeId& typeNodeId)
	{
		std::pair<ReferenceItemMultiMap::iterator,ReferenceItemMultiMap::iterator> it;
		it = baseNodeClass->referenceItemMap().referenceItemMultiMap().equal_range(*ReferenceTypeMap::hasTypeDefinitionTypeNodeId());
		if (it.first == it.second) {
			Log(Warning, "HasTypeDefinition reference not exist in node")
				.parameter("NodeId", baseNodeClass->nodeId());
			return false;
		}

		ReferenceItemMultiMap::iterator itl;
		for (itl = it.first; itl != it.second; itl++) {
			ReferenceItem::SPtr referenceItem  = itl->second;

			if (!referenceItem->isForward_) continue;
			referenceItem->nodeId_.copyTo(typeNodeId);
			return true;
		}

		Log(Warning, "HasTypeDefinition forward reference not exist in node")
			.parameter("NodeId", baseNodeClass->nodeId());

		return true;
	}

	bool
	InformationModelAccess::getSubType(BaseNodeClass::SPtr baseNodeClass, BaseNodeClass::SPtr& subTypeBaseNodeClass)
	{
		std::pair<ReferenceItemMultiMap::iterator,ReferenceItemMultiMap::iterator> it;
		it = baseNodeClass->referenceItemMap().referenceItemMultiMap().equal_range(*ReferenceTypeMap::hasSubtypeTypeNodeId());
		if (it.first == it.second) {
			Log(Warning, "HasSubTypeDefinition reference not exist in node")
				.parameter("NodeId", baseNodeClass->nodeId());
			return false;
		}

		ReferenceItemMultiMap::iterator itl;
		for (itl = it.first; itl != it.second; itl++) {
			ReferenceItem::SPtr referenceItem  = itl->second;

			if (referenceItem->isForward_) continue;

			subTypeBaseNodeClass = informationModel_->find(referenceItem->nodeId_);
			if (subTypeBaseNodeClass.get() == nullptr) {
				Log(Warning, "sub type node not found in information model")
					.parameter("SourceNode", "")
					.parameter("SubTypeNode", "");
				return false;
			}
		}

		Log(Warning, "HasSubTypeDefinition backward reference not exist in node")
			.parameter("NodeId", baseNodeClass->nodeId());

		return true;
	}

	bool
	InformationModelAccess::getSubType(BaseNodeClass::SPtr baseNodeClass, OpcUaNodeId& subTypeNodeId)
	{
		std::pair<ReferenceItemMultiMap::iterator,ReferenceItemMultiMap::iterator> it;
		it = baseNodeClass->referenceItemMap().referenceItemMultiMap().equal_range(*ReferenceTypeMap::hasSubtypeTypeNodeId());
		if (it.first == it.second) {
			Log(Warning, "HasSubTypeDefinition reference not exist in node")
				.parameter("NodeId", baseNodeClass->nodeId());
			return false;
		}

		ReferenceItemMultiMap::iterator itl;
		for (itl = it.first; itl != it.second; itl++) {
			ReferenceItem::SPtr referenceItem  = itl->second;

			if (referenceItem->isForward_) continue;
			referenceItem->nodeId_.copyTo(subTypeNodeId);
			return true;
		}

		Log(Warning, "HasSubTypeDefinition backward reference not exist in node")
			.parameter("NodeId", baseNodeClass->nodeId());
		return true;
	}

}

