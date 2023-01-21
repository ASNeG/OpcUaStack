/*
   Copyright 2015-2023 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   Informationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Kai Huebl (kai@huebl-sgh.de), Aleksey Timin (atimin@gmail.com)
 */

#include <boost/make_shared.hpp>
#include <numeric>
#include "OpcUaStackServer/AddressSpaceModel/ReferenceItemMap.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	ReferenceItemMap::ReferenceItemMap(void)
	: referenceItemMultiMap_()
	{
	}

	ReferenceItemMap::~ReferenceItemMap(void)
	{
		clear();
	}

	void
	ReferenceItemMap::clear(void)
	{
		referenceItemMultiMap_.clear();
	}

	bool 
	ReferenceItemMap::add(ReferenceType referenceType, ReferenceItem::SPtr& referenceItem)
	{
		auto referenceTypeNodeId = ReferenceTypeMap::typeNodeId(referenceType);
		return add(*referenceTypeNodeId, referenceItem);
	}

	bool
	ReferenceItemMap::add(ReferenceType referenceType, bool isForward, const OpcUaNodeId& nodeId)
	{
		auto referenceTypeNodeId = ReferenceTypeMap::typeNodeId(referenceType);
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
	ReferenceItemMap::add(const OpcUaNodeId& referenceTypeNodeId, ReferenceItem::SPtr& referenceItem)
	{
		if (!referenceItem) {
			return false;
		}

		referenceItem->typeId_ = referenceTypeNodeId;
		auto result = referenceItemMultiMap_[referenceTypeNodeId].insert(std::make_pair(referenceItem->nodeId_, referenceItem));

		return result.second;
	}

	bool
	ReferenceItemMap::add(const OpcUaNodeId& referenceTypeNodeId, bool isForward, const OpcUaNodeId& nodeId)
	{
		auto referenceItem = boost::make_shared<ReferenceItem>(
			referenceTypeNodeId, isForward, nodeId
		);
		return add(referenceTypeNodeId, referenceItem);
	}

	bool
	ReferenceItemMap::add(const OpcUaNodeId& referenceTypeNodeId, bool isForward, std::vector<OpcUaNodeId>& nodes)
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
		auto it1 = equal_range(referenceTypeNodeId);
		for (auto it2 = it1.first; it2 != it1.second; it2++) {
			auto referenceItem = it2->second;
			if (referenceItem->isForward_ == isForward && referenceItem->nodeId_ == nodeId) {
				return true;
			}
		}
		return false;
	}

	void
	ReferenceItemMap::get(ReferenceType referenceType, std::vector<bool>& isForwards, std::vector<OpcUaNodeId>& nodes)
	{
		auto referenceTypeNodeId = ReferenceTypeMap::typeNodeId(referenceType);
		auto it1 = equal_range(*referenceTypeNodeId);
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
	ReferenceItemMap::remove(const OpcUaNodeId& referenceTypeNodeId, ReferenceItem::SPtr& referenceItem)
	{
		if (!referenceItem) return false;
		return remove(referenceTypeNodeId, referenceItem->nodeId_);
	}

	bool
	ReferenceItemMap::remove(const OpcUaNodeId& referenceTypeNodeId, const OpcUaNodeId& nodeId)
	{
		// Remove references from reference item table
		size_t result = referenceItemMultiMap_[referenceTypeNodeId].erase(nodeId);

		// Check number of elements in reference item table
		if (referenceItemMultiMap_[referenceTypeNodeId].size() == 0) {
			referenceItemMultiMap_.erase(referenceTypeNodeId);
		}

		return result == 1;
	}

	bool
	ReferenceItemMap::remove(
		const OpcUaStackCore::OpcUaNodeId& referenceTypeNodeId,
		bool isForward,
		const OpcUaStackCore::OpcUaNodeId& nodeId
	)
	{
		bool remove = false;

 		// Get reference item table
		auto referenceItemTable = referenceItemMultiMap_.find(referenceTypeNodeId);
		if (referenceItemTable == referenceItemMultiMap_.end()) return true;

		// Remove references
		auto it = referenceItemTable->second.begin();
		while (it != referenceItemTable->second.end()) {
			auto referenceItem = it->second;

			if (referenceItem->isForward_ == isForward && referenceItem->nodeId_ == nodeId) {
				remove = true;
				it = referenceItemTable->second.erase(it);
			}
			else {
				++it;
			}
		}

		// Check number of elements in reference item table
		if (referenceItemTable->second.size() == 0) {
			referenceItemMultiMap_.erase(referenceItemTable);
		}

		return remove;
	}

	void
	ReferenceItemMap::copyTo(ReferenceItemMap::SPtr& referenceItemMap) const
	{
		copyTo(*referenceItemMap);
	}

	void
	ReferenceItemMap::copyTo(ReferenceItemMap& referenceItemMap) const
	{
		for (const auto& referenceItem : *this) {
			auto newReferenceItem = boost::make_shared<ReferenceItem>();
			referenceItem->copyTo(newReferenceItem);

			referenceItemMap.referenceItemMultiMap_[referenceItem->typeId_].insert(
				std::make_pair(referenceItem->nodeId_, newReferenceItem)
			);
		}
	}

	ReferenceItemMap::const_iterator
	ReferenceItemMap::begin() const
	{
		ReferenceItemMap::const_iterator it;
		it.refTypeIt_ = referenceItemMultiMap_.cbegin();
		it.refTypeEnd_ = referenceItemMultiMap_.cend();

		if (it.refTypeIt_ != it.refTypeEnd_) {
			it.refItemIt_ = it.refTypeIt_->second.cbegin();
			it.refItemEnd_ = it.refTypeIt_->second.cend();
		}

		return it;
	}


	ReferenceItemMap::const_iterator
	ReferenceItemMap::end() const
	{
		ReferenceItemMap::const_iterator it;
		it.refTypeIt_ = referenceItemMultiMap_.cend();
		it.refTypeEnd_ = referenceItemMultiMap_.cend();

		return it;
	}

	bool
	ReferenceItemMap::erase(const_iterator& it)
	{
		auto referenceTypeNode = it.refTypeIt_->first;
		auto referenceItem = it.refItemIt_->second;
		++it;
		return remove(referenceTypeNode, referenceItem);
	}

	std::pair<ReferenceItemTable::const_iterator, ReferenceItemTable::const_iterator>
	ReferenceItemMap::equal_range(const OpcUaNodeId& referenceTypeNodeId) const
	{
		ReferenceItemTable::const_iterator it1;
		ReferenceItemTable::const_iterator it2;

		auto refTypeIt = referenceItemMultiMap_.find(referenceTypeNodeId);
		if (refTypeIt != referenceItemMultiMap_.end()) {
			it1 = refTypeIt->second.begin();
			it2 = refTypeIt->second.end();
		}

		return std::make_pair(it1, it2);
	}

	size_t
	ReferenceItemMap::size() const {
		return std::accumulate(
			referenceItemMultiMap_.begin(), referenceItemMultiMap_.end(), 0,
			[](size_t accum, const ReferenceItemMultiMap::value_type& table) {
				return accum + table.second.size();
			}
		);
	}

	ReferenceItemMap::const_iterator::const_iterator()
	{
	}

	ReferenceItemMap::const_iterator::const_iterator(const const_iterator& other)
	{
		this->refTypeIt_ = other.refTypeIt_;
		this->refTypeEnd_ = other.refTypeEnd_;
		this->refItemIt_ = other.refItemIt_;
		this->refItemEnd_ = other.refItemEnd_;
	}

	ReferenceItemMap::const_iterator::~const_iterator()
	{

	}

	ReferenceItemMap::const_iterator&
	ReferenceItemMap::const_iterator::operator=(const const_iterator& other)
	{
		this->refTypeIt_ = other.refTypeIt_;
		this->refTypeEnd_ = other.refTypeEnd_;
		this->refItemIt_ = other.refItemIt_;
		this->refItemEnd_ = other.refItemEnd_;
		return *this;
	}

	ReferenceItemMap::const_iterator&
	ReferenceItemMap::const_iterator::operator++()
	{
		refItemIt_++;
		if (refItemIt_ == refItemEnd_) {
			refTypeIt_++;
			if (refTypeIt_ != refTypeEnd_) {
				refItemIt_ = refTypeIt_->second.begin();
				refItemEnd_ = refTypeIt_->second.end();
			}
		}

		return *this;
	}

	const ReferenceItem::SPtr
	ReferenceItemMap::const_iterator::operator*() const
	{
		assert(refTypeIt_ != refTypeEnd_);
		assert(refItemIt_ != refItemEnd_);
		assert(refItemIt_->second->typeId_ == refTypeIt_->first);

		return refItemIt_->second;
	}

	bool
	ReferenceItemMap::const_iterator::operator==(const const_iterator& other)
	{
		if (this->refTypeIt_ == other.refTypeIt_
			&& this->refTypeEnd_ == other.refTypeEnd_) {

			if (this->refTypeIt_ != this->refTypeEnd_) {
				return this->refItemIt_ == other.refItemIt_
						&& this->refItemEnd_ == other.refItemEnd_;
			}

			return true;
		}

		return false;
	}

	bool
	ReferenceItemMap::const_iterator::operator!=(const const_iterator& other)
	{
		return !this->operator == (other);
	}

}
