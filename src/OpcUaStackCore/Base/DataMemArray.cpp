/*
   Copyright 2017 Kai Huebl (kai@huebl-sgh.de)

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

#include <cstring>
#include <iostream>
#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackCore/Base/DataMemArray.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// DataMemArrayHeader
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	DataMemArrayHeader::DataMemArrayHeader(void)
	{
	}

	DataMemArrayHeader::~DataMemArrayHeader(void)
	{
	}


	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// DataMemArraySlot
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	DataMemArraySlot::DataMemArraySlot(void)
	{
	}

	DataMemArraySlot::~DataMemArraySlot(void)
	{
	}

	DataMemArraySlot*
	DataMemArraySlot::last(void)
	{
		// FIXME: todo
		return nullptr;
	}

	DataMemArraySlot*
	DataMemArraySlot::next(void)
	{
		// FIXME: todo
		return nullptr;
	}

	uint32_t
	DataMemArraySlot::dataSize(void)
	{
		// FIXME: todo
		return 0;
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// DataMemArray
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	uint32_t DataMemArray::minMemorySize_ = 1000;

	DataMemArray::DataMemArray(void)
	: debug_(true)
	, dataMemArrayHeader_(nullptr)
	, startMemorySize_(10000)
	, maxMemorySize_(1000000)
	, expandMemorySize_(10000)
	{
	}

	DataMemArray::~DataMemArray(void)
	{
		if (dataMemArrayHeader_ != nullptr) {
			char* mem = (char*)dataMemArrayHeader_;
			delete [] mem;
			dataMemArrayHeader_ = nullptr;
		}
	}

	void
	DataMemArray::startMemorySize(uint32_t startMemorySize)
	{
		if (startMemorySize < minMemorySize_) {
			startMemorySize_ = minMemorySize_;
		}
		else {
			startMemorySize_ = startMemorySize;
		}
	}

	uint32_t
	DataMemArray::startMemorySize(void)
	{
		return startMemorySize_;
	}

	void
	DataMemArray::maxMemorySize(uint32_t maxMemorySize)
	{
		if (dataMemArrayHeader_ == nullptr) {
			if (maxMemorySize < startMemorySize_) {
				maxMemorySize_ = startMemorySize_;
				expandMemorySize_ = 0;
			}
			else {
				maxMemorySize_ = maxMemorySize;
			}
		}
		else {
			if (maxMemorySize < dataMemArrayHeader_->actArraySize_) {
				dataMemArrayHeader_->maxMemorySize_ = dataMemArrayHeader_->actArraySize_;
			}
			else {
				dataMemArrayHeader_->maxMemorySize_ = maxMemorySize;
			}
		}
	}

	uint32_t
	DataMemArray::maxMemorySize(void)
	{
		if (dataMemArrayHeader_ == nullptr) {
			return maxMemorySize_;
		}
		else {
			return dataMemArrayHeader_->maxMemorySize_;
		}
	}

	void
	DataMemArray::expandMemorySize(uint32_t expandMemorySize)
	{
		if (dataMemArrayHeader_ == nullptr) {
			expandMemorySize_ = expandMemorySize;
		}
		else {
			dataMemArrayHeader_->expandMemorySize_ = expandMemorySize;
		}
	}

	uint32_t
	DataMemArray::expandMemorySize(void)
	{
		return expandMemorySize_;
	}

	uint32_t
	DataMemArray::size(void)
	{
		if (dataMemArrayHeader_ == nullptr) {
			return 0;
		}
		return dataMemArrayHeader_->actArraySize_;
	}

	bool
	DataMemArray::resize(uint32_t arraySize)
	{
		if (dataMemArrayHeader_ == nullptr) {

			if (!createNewMemory(arraySize)) return false;

			return true;
		}

		// FIXME: todo

		return true;
	}

	bool
	DataMemArray::set(uint32_t idx, const char* buf, uint32_t bufLen)
	{
		return true;
	}

	bool
	DataMemArray::get(uint32_t idx, char**buf, uint32_t& bufLen)
	{
		// FIXME: todo
		return true;
	}

	bool
	DataMemArray::exist(uint32_t idx)
	{
		return true;
	}

	bool
	DataMemArray::setMemoryBuf(char* memBuf, uint32_t memLen)
	{
		// FIXME: todo
		return true;
	}

	bool
	DataMemArray::getMemoryBuf(char** memBuf, uint32_t* memLen)
	{
		// FIXME: todo
		return true;
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// private function
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	uint32_t
	DataMemArray::ptrToPos(char* ptr)
	{
		if (dataMemArrayHeader_ == nullptr) return 0;
		return (ptr - (char*)dataMemArrayHeader_);
	}

	bool
	DataMemArray::createNewMemory(uint32_t arraySize)
	{
		//
		// calculate used buffer size
		//
		// HEAD  B-Slot  F-Slot  E-Slot  Array
		//
		uint32_t usedMemorySize = sizeof(DataMemArrayHeader) +
			3*(sizeof(DataMemArraySlot) + sizeof(uint32_t)) +
			arraySize * sizeof(char*) +
			minMemorySize_;

		//
		// check max memory size
		//
		if (maxMemorySize_ != 0 && usedMemorySize > maxMemorySize_) {
			Log(Error, "allocate memory error - used memory size is bigger then max memory size")
				.parameter("Id", this)
				.parameter("UsedMemorySize", usedMemorySize)
				.parameter("MaxMemorySize", maxMemorySize_);
			return false;
		}

		//
		// calculate actual memory size
		//
		uint32_t actMemorySize = startMemorySize_;
		while (usedMemorySize > actMemorySize) actMemorySize += expandMemorySize_;
		uint32_t dataSize = actMemorySize -
			sizeof(DataMemArrayHeader) -
			(3*(sizeof(DataMemArrayHeader) + sizeof(uint32_t))) -
			(arraySize * sizeof(uint32_t));

		//
		// allocate memory and create management structures
		//
		if (debug_) {
			Log(Debug, "create new memory")
				.parameter("Id", this)
				.parameter("ArraySize", arraySize)
				.parameter("MemorySize", actMemorySize)
				.parameter("DataSize", dataSize);
		}

		char* mem = new char[actMemorySize];
		memset(mem, 0x0, actMemorySize);

		// create header
		dataMemArrayHeader_ = (DataMemArrayHeader*)mem;
		dataMemArrayHeader_->eye_[0] = 'H';
		dataMemArrayHeader_->eye_[1] = 'E';
		dataMemArrayHeader_->eye_[2] = 'A';
		dataMemArrayHeader_->eye_[3] = 'D';
		dataMemArrayHeader_->maxMemorySize_ = maxMemorySize_;
		dataMemArrayHeader_->expandMemorySize_ = expandMemorySize_;
		dataMemArrayHeader_->actMemorySize_ = actMemorySize;
		dataMemArrayHeader_->actArraySize_ = arraySize;

		// create start slot
		mem += sizeof(DataMemArrayHeader);
		createNewSlot(mem, 'S', 0);

		// create free slot
		mem += sizeof(DataMemArraySlot) + sizeof(uint32_t);
		createNewSlot(mem, 'F', dataSize);
		freeSlotMap_.insert(std::make_pair(ptrToPos(mem), (DataMemArraySlot*)mem));

		// create end slot
		mem += sizeof(DataMemArraySlot) + sizeof(uint32_t) + dataSize;
		createNewSlot(mem, 'E', 0);

		return true;
	}

	void
	DataMemArray::createNewSlot(char* mem, char type, uint32_t size)
	{
		// create header
		DataMemArraySlot* dataMemArraySlot;
		dataMemArraySlot = (DataMemArraySlot*)mem;
		dataMemArraySlot->eye_[0] = 'S';
		dataMemArraySlot->eye_[1] = 'L';
		dataMemArraySlot->eye_[2] = 'O';
		dataMemArraySlot->eye_[3] = 'T';
		dataMemArraySlot->type_ = type;
		dataMemArraySlot->size_ = size;

		uint32_t* sizeTag = (uint32_t*)(mem + sizeof(DataMemArraySlot) + sizeof(uint32_t));
		*sizeTag = size;
	}

}
