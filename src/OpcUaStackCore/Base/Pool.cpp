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

#include "OpcUaStackCore/Base/Pool.h"

namespace OpcUaStackCore
{

	PoolBase::PoolBase(uint32_t entrySize, uint32_t startEntries, uint32_t growEntries, uint32_t maxEntries)
	: entrySize_(entrySize < sizeof(PoolListEntry) ? sizeof(PoolListEntry) : entrySize)
	, poolListEntry_(nullptr)
	, bufferListEntry_(nullptr)
	, buffer_(nullptr)
	, bufferLen_(0)
	, bufferPos_(0)
	, maxEntries_(maxEntries)
	, startEntries_(startEntries+1)
	, growEntries_(growEntries+1)
	, actEntries_(0)
	{
		createNewBuffer(startEntries_);
	}

	PoolBase::~PoolBase(void)
	{
		while (bufferListEntry_ != nullptr) {
			BufferListEntry* bufferListEntry = bufferListEntry_;
			bufferListEntry_ = bufferListEntry_->poolListEntry_;
			delete [] bufferListEntry;
		}
	}

	uint32_t
	PoolBase::actEntries(void)
	{
		return actEntries_;
	}

	char*
	PoolBase::allocateMemory(void)
	{
		if (poolListEntry_ != nullptr) {
			char *memory = (char*)poolListEntry_;
			poolListEntry_ = poolListEntry_->poolListEntry_;
			return memory;
		}

		if (bufferLen_ == bufferPos_) {
			createNewBuffer(growEntries_);
		}

		if (bufferLen_ == bufferPos_) return nullptr;

		char* memory = &buffer_[bufferPos_];
		bufferPos_ += entrySize_;
		return memory;
	}

	void
	PoolBase::freeMemory(char* memory)
	{
		PoolListEntry *poolListEntry = (PoolListEntry*)memory;
		poolListEntry->poolListEntry_ = poolListEntry_;
		poolListEntry_ = poolListEntry;
	}

	void
	PoolBase::createNewBuffer(uint32_t growEntries)
	{
		if (maxEntries_ != 0 && maxEntries_ > actEntries_) return;

		actEntries_ += growEntries;
		bufferLen_ = entrySize_ * growEntries;
		buffer_ = new char[bufferLen_];
		bufferPos_ = entrySize_;

		BufferListEntry* bufferListEntry = (BufferListEntry*)buffer_;
		bufferListEntry->poolListEntry_ = bufferListEntry_;
		bufferListEntry_ = bufferListEntry;
	}

}


