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

#include <iostream>
#include "OpcUaStackCore/Base/PoolBase.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	//  PoolListEntry
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	PoolListEntry::PoolListEntry(void)
	: next_(this)
	, last_(this)
	{
	}

	PoolListEntry::~PoolListEntry(void)
	{
		if (next_ == this && last_ == this) return;
		next_->last_ = last_;
		last_->next_ = next_;
		next_ = this;
		last_ = this;
	}

	char*
	PoolListEntry::getMemory(void)
	{
		return ((char*)this) + sizeof(PoolListEntry);
	}

	PoolListEntry*
	PoolListEntry::MemoryToPoolListEntry(char* memory)
	{
		return (PoolListEntry*)(memory - sizeof(PoolListEntry));
	}

	bool
	PoolListEntry::empty(void)
	{
		return next_ == last_;
	}

	void
	PoolListEntry::add(PoolListEntry* poolListEntry)
	{
		poolListEntry->next_ = next_;
		poolListEntry->last_ = this;
		next_->last_ = poolListEntry;
		next_ = poolListEntry;
	}

	void
	PoolListEntry::addAfter(PoolListEntry* poolListEntry)
	{
		add(poolListEntry);
	}

	void
	PoolListEntry::addBefor(PoolListEntry* poolListEntry)
	{
		last_->addAfter(poolListEntry);
	}

	PoolListEntry*
	PoolListEntry::del(void)
	{
		if (next_ == this && last_ == this) return this;
		next_->last_ = last_;
		last_->next_ = next_;
		next_ = this;
		last_ = this;
		return this;
	}

	PoolListEntry*
	PoolListEntry::delBefor(void)
	{
		return last_->del();
	}

	PoolListEntry*
	PoolListEntry::delAfter(void)
	{
		return next_->del();
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// PoolList
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	PoolList::PoolList(void)
	: PoolListEntry()
	, size_(0)
	, garbageCollector_(this)
	{
	}

	PoolList::~PoolList(void)
	{
	}

	uint32_t
	PoolList::size(void)
	{
		return size_;
	}

	bool
	PoolList::empty(void)
	{
		return PoolListEntry::empty();
	}

	void
	PoolList::addFirst(PoolListEntry* poolListEntry)
	{
		if (PoolListEntry::empty()) garbageCollector_ = poolListEntry;
		size_++;
		next_->add(poolListEntry);
	}

	void
	PoolList::addLast(PoolListEntry* poolListEntry)
	{
		if (PoolListEntry::empty()) garbageCollector_ = poolListEntry;
		size_++;
		last_->add(poolListEntry);
	}

	PoolListEntry*
	PoolList::del(PoolListEntry* poolListEntry)
	{
		if (garbageCollector_ == poolListEntry) garbageCollectorNext();
		if (garbageCollector_ == poolListEntry) garbageCollector_ = this;
		size_--;
		return poolListEntry->del();
	}

	PoolListEntry*
	PoolList::delFirst(void)
	{
		if (garbageCollector_ == next_) garbageCollectorNext();
		if (garbageCollector_ == next_) garbageCollector_ = this;
		size_--;
		return next_->del();
	}

	PoolListEntry*
	PoolList::delLast(void)
	{
		if (garbageCollector_ == last_) garbageCollectorNext();
		if (garbageCollector_ == last_) garbageCollector_ = this;
		size_--;
		return last_->del();
	}

	PoolListEntry*
	PoolList::garbageCollector(void)
	{
		if (PoolListEntry::empty()) return nullptr;
		return garbageCollector_;
	}

	PoolListEntry*
	PoolList::garbageCollectorNext(void)
	{
		if (PoolListEntry::empty()) return nullptr;
		if (garbageCollector_->next_ == this) {
			garbageCollector_ = garbageCollector_->next_->next_;
		}
		else {
			garbageCollector_ = garbageCollector_->next_;
		}
		return garbageCollector_;
	}

	void
	PoolList::log(std::ostream& os)
	{
		PoolListEntry* poolListEntry = this->next_;
		while (poolListEntry != this) {
			os << " " << poolListEntry;
			poolListEntry = poolListEntry->next_;
		}
		os << std::endl;
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// PoolBase
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	PoolBase::PoolBase(
		uint32_t entrySize,
		uint32_t startEntries,
		uint32_t growEntries,
		uint32_t maxUsedEntries,
		uint32_t maxFreeEntries
	)
	: entrySize_(entrySize)
	, startEntries_(startEntries)
	, growEntries_(growEntries)
	, maxUsedEntries_(maxUsedEntries)
	, maxFreeEntries_(maxFreeEntries)
	, usedEntries_(0)
	, freeEntries_(0)
	, freePoolList_()
	{
		if (startEntries_ == 0) startEntries_ = 1;
		if (growEntries_ == 0) growEntries_ = 1;
		if (maxFreeEntries_ != 0 && startEntries_ > maxFreeEntries_ ) maxFreeEntries_ = startEntries_;

		entrySize_ += sizeof(PoolListEntry);

		grow(startEntries_);
	}

	PoolBase::~PoolBase(void)
	{
		while (!freePoolList_.empty()) {
			PoolListEntry* poolListEntry = freePoolList_.delFirst();
			memoryDestructHandler(poolListEntry->getMemory());
			delete (char*)poolListEntry;
		}
		freeEntries_ = 0;
	}

	uint32_t
	PoolBase::freeEntries(void)
	{
		return freeEntries_;
	}

	uint32_t
	PoolBase::usedEntries(void)
	{
		return usedEntries_;
	}

	PoolListEntry*
	PoolBase::allocate(void)
	{
		if (freePoolList_.empty()) garbageCollector();
		if (freePoolList_.empty() && !grow(growEntries_)) return nullptr;
		freeEntries_++;
		usedEntries_++;
		return freePoolList_.delFirst();
	}

	void
	PoolBase::free(PoolListEntry* poolListEntry)
	{
		usedEntries_--;
		if (maxFreeEntries_ != 0 && freeEntries_ >= maxFreeEntries_) {
			memoryDestructHandler(poolListEntry->getMemory());
			delete (char*)poolListEntry;
			return;
		}

		freePoolList_.addLast(new (poolListEntry) PoolListEntry);
		freeEntries_++;
	}

	bool
	PoolBase::grow(uint32_t growEntries)
	{
		if (maxUsedEntries_ != 0 && usedEntries_ >= maxUsedEntries_) return false;
		for (uint32_t idx=0; idx<growEntries; idx++) {
			char* memory = new char[entrySize_];
			PoolListEntry* poolListEntry = new (memory) PoolListEntry();

			memoryConstructHandler(poolListEntry->getMemory());

			freePoolList_.addLast(poolListEntry);
		}
		freeEntries_ += growEntries;
		return true;
	}

}


