/*
   Copyright 2015-2019 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackServer/AddressSpaceModel/ReferenceItemMap.h"

namespace OpcUaStackServer
{

	ReferenceItemMap::ReferenceItemMap(void)
	{
	}

	ReferenceItemMap::~ReferenceItemMap(void)
	{
	}

	void
	ReferenceItemMap::clear(void)
	{
		referenceItemMultiMap_.clear();
	}

	bool 
	ReferenceItemMap::add(ReferenceType referenceType, ReferenceItem::SPtr referenceItem)
	{
		OpcUaNodeId::SPtr nodeId = ReferenceTypeMap::typeNodeId(referenceType);
		return add(*nodeId, referenceItem);
	}

	bool
	ReferenceItemMap::add(ReferenceType referenceType, bool isForward, OpcUaNodeId& nodeId)
	{
		OpcUaNodeId::SPtr referenceTypeNodeId = ReferenceTypeMap::typeNodeId(referenceType);
		return add(*referenceTypeNodeId, isForward, nodeId);
	}

	bool
	ReferenceItemMap::add(ReferenceType referenceType, bool isForward, std::vector<OpcUaNodeId>& nodes)
	{
		for (auto& node : nodes) {
			if (!add(referenceType, isForward, node)) {
				return false;
			}
		}
		return true;
	}

	bool 
	ReferenceItemMap::add(OpcUaNodeId& referenceTypeNodeId, ReferenceItem::SPtr referenceItem)
	{
		if (referenceItem.get() == nullptr) return false;

		std::pair<ReferenceItemMultiMap::iterator,ReferenceItemMultiMap::iterator> it1;
		ReferenceItemMultiMap::iterator it2;
		it1 = referenceItemMultiMap_.equal_range(referenceTypeNodeId);
		for (it2 = it1.first; it2 != it1.second; it2++) {
			if (*it2->second == *referenceItem) return false;
		}

		referenceItemMultiMap_.insert(std::make_pair(referenceTypeNodeId, referenceItem));
		return true;
	}

	bool
	ReferenceItemMap::add(OpcUaNodeId& referenceTypeNodeId, bool isForward, OpcUaNodeId& nodeId)
	{
		ReferenceItem::SPtr referenceItem;
		referenceItem.reset(new ReferenceItem());
		referenceItem->isForward_ = isForward;
		referenceItem->nodeId_ = nodeId;
		return add(referenceTypeNodeId, referenceItem);
	}

	bool
	ReferenceItemMap::add(OpcUaNodeId& referenceTypeNodeId, bool isForward, std::vector<OpcUaNodeId>& nodes)
	{
		for (auto& node : nodes) {
			if (!add(referenceTypeNodeId, isForward, node)) {
				return false;
			}
		}
		return true;
	}

	bool
	ReferenceItemMap::exist(OpcUaNodeId& referenceTypeNodeId, bool isForward, OpcUaNodeId& nodeId)
	{
		auto it1 = referenceItemMultiMap_.equal_range(referenceTypeNodeId);
		for (auto it2 = it1.first; it2 != it1.second; it2++) {
			auto referenceItem = it2->second;
			if (referenceItem->isForward_ == isForward && referenceItem->nodeId_ == nodeId) return true;
		}
		return false;
	}

	void
	ReferenceItemMap::get(ReferenceType referenceType, std::vector<bool>& isForwards, std::vector<OpcUaNodeId>& nodes)
	{
		OpcUaNodeId::SPtr referenceTypeNodeId = ReferenceTypeMap::typeNodeId(referenceType);
		auto it1 = referenceItemMultiMap_.equal_range(*referenceTypeNodeId);
		for (auto it2 = it1.first; it2 != it1.second; it2++) {
			auto referenceItem = it2->second;
			isForwards.push_back(referenceItem->isForward_);
			nodes.push_back(referenceItem->nodeId_);
		}
	}

	bool
	ReferenceItemMap::getHasTypeDefinition(OpcUaNodeId& node)
	{
		std::vector<bool> isForwards;
		std::vector<OpcUaNodeId> nodes;
		get(ReferenceType_HasTypeDefinition, isForwards, nodes);
		if (nodes.size() != 1) return false;
		node = nodes[0];
		return true;
	}

	bool
	ReferenceItemMap::getHasModellingRule(OpcUaNodeId& node)
	{
		std::vector<bool> isForwards;
		std::vector<OpcUaNodeId> nodes;
		get(ReferenceType_HasModellingRule, isForwards, nodes);
		if (nodes.size() != 1) return false;
		node = nodes[0];
		return true;
	}

	bool
	ReferenceItemMap::remove(OpcUaNodeId& referenceTypeNodeId, ReferenceItem::SPtr referenceItem)
	{
		if (referenceItem.get() == nullptr) return false;

		std::pair<ReferenceItemMultiMap::iterator,ReferenceItemMultiMap::iterator> it1;
		ReferenceItemMultiMap::iterator it2;
		it1 = referenceItemMultiMap_.equal_range(referenceTypeNodeId);
		for (it2 = it1.first; it2 != it1.second; it2++) {
			if (*it2->second == *referenceItem) {
				referenceItemMultiMap_.erase(it2);
				return true;
			}
		}
		return false;
	}

	bool
	ReferenceItemMap::remove(OpcUaNodeId& referenceTypeNodeId, OpcUaNodeId& nodeId)
	{
		std::pair<ReferenceItemMultiMap::iterator,ReferenceItemMultiMap::iterator> it1;
		ReferenceItemMultiMap::iterator it2;
		it1 = referenceItemMultiMap_.equal_range(referenceTypeNodeId);
		for (it2 = it1.first; it2 != it1.second; it2++) {
			if (it2->second->nodeId_ == nodeId) {
				referenceItemMultiMap_.erase(it2);
				return true;
			}
		}
		return false;
	}
		
	ReferenceItemMultiMap& 
	ReferenceItemMap::referenceItemMultiMap(void)
	{
		return referenceItemMultiMap_;
	}

	void
	ReferenceItemMap::copyTo(ReferenceItemMap::SPtr referenceItemMap)
	{
		copyTo(*referenceItemMap);
	}

	void
	ReferenceItemMap::copyTo(ReferenceItemMap& referenceItemMap)
	{
		ReferenceItemMultiMap::iterator it;
		for (it = referenceItemMultiMap_.begin(); it != referenceItemMultiMap_.end(); it++) {
			ReferenceItem::SPtr referenceItem = it->second;
			ReferenceItem::SPtr newReferenceItem = constructSPtr<ReferenceItem>();

			referenceItem->copyTo(newReferenceItem);

			referenceItemMap.referenceItemMultiMap().insert(
				std::make_pair(it->first, newReferenceItem)
			);
		}
	}

}
