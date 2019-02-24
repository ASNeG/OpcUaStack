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
	ReferenceItemMap::add(ReferenceType referenceType, bool isForward, const OpcUaNodeId& nodeId)
	{
		OpcUaNodeId::SPtr referenceTypeNodeId = ReferenceTypeMap::typeNodeId(referenceType);
		return add(*referenceTypeNodeId, isForward, nodeId);
	}

	bool 
	ReferenceItemMap::add(const OpcUaNodeId& referenceTypeNodeId, ReferenceItem::SPtr referenceItem)
	{
		if (referenceItem.get() == nullptr) return false;

		referenceItem->typeId_ = referenceTypeNodeId;
		std::pair<ReferenceItemTable::const_iterator, bool> result = referenceItemMultiMap_[referenceTypeNodeId]
																					  .insert(std::make_pair(referenceItem->nodeId_, referenceItem));

		std::cout << "Add type " << referenceTypeNodeId.toString() << "\n";
		return result.second;
	}

	bool
	ReferenceItemMap::add(const OpcUaNodeId& referenceTypeNodeId, bool isForward, const OpcUaNodeId& nodeId)
	{
		ReferenceItem::SPtr referenceItem;
		referenceItem.reset(new ReferenceItem());
		referenceItem->isForward_ = isForward;
		referenceItem->nodeId_ = nodeId;
		return add(referenceTypeNodeId, referenceItem);
	}

	bool
	ReferenceItemMap::remove(const OpcUaNodeId& referenceTypeNodeId, ReferenceItem::SPtr referenceItem)
	{
		if (referenceItem.get() == nullptr) return false;
		return remove(referenceTypeNodeId, referenceItem->nodeId_);
	}

	bool
	ReferenceItemMap::remove(const OpcUaNodeId& referenceTypeNodeId, const OpcUaNodeId& nodeId)
	{
		return referenceItemMultiMap_[referenceTypeNodeId].erase(nodeId);
	}
		
//	ReferenceItemMultiMap&
//	ReferenceItemMap::referenceItemMultiMap(void)
//	{
//		return referenceItemMultiMap_;
//	}

	void
	ReferenceItemMap::copyTo(ReferenceItemMap::SPtr referenceItemMap) const
	{
		copyTo(*referenceItemMap);
	}

	void
	ReferenceItemMap::copyTo(ReferenceItemMap& referenceItemMap) const
	{
		for (const auto& referenceItem : *this) {

				ReferenceItem::SPtr newReferenceItem = constructSPtr<ReferenceItem>();

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
		it.refTypeIt = referenceItemMultiMap_.cbegin();
		it.refTypeEnd = referenceItemMultiMap_.cend();

		if (it.refTypeIt != it.refTypeEnd) {
			it.refItemIt = it.refTypeIt->second.cbegin();
			it.refItemEnd = it.refTypeIt->second.cend();
		}

		return it;
	}


	ReferenceItemMap::const_iterator
	ReferenceItemMap::end() const
	{
		ReferenceItemMap::const_iterator it;
		it.refTypeIt = referenceItemMultiMap_.cend();
		it.refTypeEnd = referenceItemMultiMap_.cend();

		return it;
	}

	bool
	ReferenceItemMap::erase(const_iterator it)
	{
		return referenceItemMultiMap_.find(it.refTypeIt->first)->second.erase(it.refItemIt->first);
	}

	std::pair<ReferenceItemMap::const_iterator, ReferenceItemMap::const_iterator>
	ReferenceItemMap::equal_range(const OpcUaNodeId& referenceTypeNodeId) const
	{
		ReferenceItemMap::const_iterator it1 = end();
		ReferenceItemMap::const_iterator it2 = end();

		auto refTypeIt = referenceItemMultiMap_.find(referenceTypeNodeId);
		if (refTypeIt != referenceItemMultiMap_.end()) {
			it1.refItemIt = refTypeIt->second.begin();
			it1.refItemEnd = refTypeIt->second.end();
			it1.refTypeIt = refTypeIt;

			it2 = it1;
			it2.refItemIt = it1.refItemEnd;
		}

		return std::make_pair(it1, it2);
	}

	size_t
	ReferenceItemMap::size() const {
		return referenceItemMultiMap_.size();
	}

	ReferenceItemMap::const_iterator::const_iterator()
	{
	}

	ReferenceItemMap::const_iterator::const_iterator(const const_iterator& other)
	{
		this->refTypeIt = other.refTypeIt;
		this->refTypeEnd = other.refTypeEnd;
		this->refItemIt = other.refItemIt;
		this->refItemEnd = other.refItemEnd;
	}

	ReferenceItemMap::const_iterator::~const_iterator()
	{

	}

	ReferenceItemMap::const_iterator&
	ReferenceItemMap::const_iterator::operator=(const const_iterator& other)
	{
		this->refTypeIt = other.refTypeIt;
		this->refTypeEnd = other.refTypeEnd;
		this->refItemIt = other.refItemIt;
		this->refItemEnd = other.refItemEnd;
		return *this;
	}

	ReferenceItemMap::const_iterator&
	ReferenceItemMap::const_iterator::operator++()
	{
		refItemIt++;
		if (refItemIt == refItemEnd) {
			refTypeIt++;
			if (refTypeIt != refTypeEnd) {
				refItemIt = refTypeIt->second.begin();
				refItemEnd = refTypeIt->second.end();
			}
		}

		return *this;
	}

	const ReferenceItem::SPtr
	ReferenceItemMap::const_iterator::operator*() const
	{
		assert(refTypeIt != refTypeEnd);
		assert(refItemIt != refItemEnd);
		assert(refItemIt->second->typeId_ == refTypeIt->first);

		return refItemIt->second;
	}

	bool
	ReferenceItemMap::const_iterator::operator==(const const_iterator& other)
	{
		if (this->refTypeIt == other.refTypeIt
			&& this->refTypeEnd == other.refTypeEnd) {

			if (this->refItemIt != this->refItemEnd) {
				return this->refItemIt == other.refItemIt
						&& this->refItemEnd == other.refItemEnd;
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
