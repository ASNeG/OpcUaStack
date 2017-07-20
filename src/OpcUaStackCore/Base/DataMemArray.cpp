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
	class DataMemoryArrayFreeSlot
	{
	  public:
		char eye_[4]; // FREE

		uint32_t size_;
		uint32_t posLastFreeSlot_;
		uint32_t posNextFreeSlot_;
	};

	class DataMemoryArrayUsedSlot
	{
		char eye_[4]; // USED

		uint32_t size_;
		uint32_t padding_;
	};

	class DataMemArrayHeader
	{
	  public:
		char eye_[4]; // HEAD

		uint32_t maxMemorySize_;
		uint32_t expandMemorySize_;

		uint32_t actMemorySize_;
		uint32_t actArraySize_;

		uint32_t posFirstFreeSlot_;
		uint32_t posLastFreeSlot_;
	};

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
	DataMemArray::arraySize(void)
	{
		if (dataMemArrayHeader_ == nullptr) {
			return 0;
		}
		return dataMemArrayHeader_->actArraySize_;
	}

	bool
	DataMemArray::arrayResize(uint32_t arraySize)
	{
		if (dataMemArrayHeader_ == nullptr) {

			//
			//check minimal used memory size
			//
			uint32_t startMemorySize = startMemorySize_;
			uint32_t minMemoryBufferSize = calcMinMemoryBufferSize(arraySize);
			if (maxMemorySize_ != 0 && minMemoryBufferSize > maxMemorySize_) {
				if (debug_) {
					Log(Debug, "array resize error - max memory exceeded")
						.parameter("Id", this)
						.parameter("ArraySize", arraySize)
						.parameter("MaxMemorySize", maxMemorySize_)
						.parameter("UsedMemorySize", minMemoryBufferSize);
				}
				return false;
			}

			//
			// calculate size of new memory buffer
			//
			while (minMemoryBufferSize > startMemorySize) {
				if (expandMemorySize_ != 0) {
					startMemorySize += expandMemorySize_;
				}
				else {
					startMemorySize += 1000;
				}
			}

			//
			// create new memory buffer
			//
			if (!createMemoryBuffer(startMemorySize)) {
				return false;
			}

			//
			// resize array size
			//
			if (!resizeMemArray(arraySize)) {
				return false;
			}
		}

		// FIXME: todo

		return true;
	}

	bool
	DataMemArray::set(uint32_t idx, const char* buf, uint32_t bufLen)
	{
		if (dataMemArrayHeader_ == nullptr) {
			return false;
		}

		//
		// get memory buffer
		//
		char* memBuf = (char*)dataMemArrayHeader_;
		uint32_t memSize = dataMemArrayHeader_->actMemorySize_;

		// FIXME: todo
		return true;
	}

	bool
	DataMemArray::get(uint32_t idx, char**buf, uint32_t& bufLen)
	{
		if (dataMemArrayHeader_ == nullptr) {
			return false;
		}

		//
		// get memory buffer
		//
		char* memBuf = (char*)dataMemArrayHeader_;
		uint32_t memSize = dataMemArrayHeader_->actMemorySize_;

		// FIXME: todo
		return true;
	}

	bool
	DataMemArray::exist(uint32_t idx)
	{
		if (dataMemArrayHeader_ == nullptr) {
			return false;
		}

		//
		// get memory buffer
		//
		char* memBuf = (char*)dataMemArrayHeader_;
		uint32_t memSize = dataMemArrayHeader_->actMemorySize_;

		//
		// check index
		//
		if (idx >= dataMemArrayHeader_->actArraySize_) {
			return false;
		}

		//
		// read array element
		//
		uint32_t offset = (idx+1) * sizeof(uint32_t);
		uint32_t* arrayElement = (uint32_t*)memBuf[memSize-offset];

		if (*arrayElement == 0) {
			return false;
		}
		return true;
	}

	void
	DataMemArray::setMemoryBuf(char* memBuf, uint32_t memLen)
	{
		// FIXME: todo
	}

	void
	DataMemArray::getMemoryBuf(char** memBuf, uint32_t* memLen)
	{
		// FIXME: todo
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// private function
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	bool
	DataMemArray::createMemoryBuffer(uint32_t startMemorySize)
	{
		if (debug_) {
			Log(Debug, "create memory buffer")
				.parameter("Id", this)
				.parameter("StartMemorySize", startMemorySize);
		}

		//
		// allocate memory
		//
		char* mem = new char[startMemorySize];
		if (mem == nullptr) {
			if (debug_) {
				Log(Debug, "create memory buffer error")
					.parameter("Id", this);
			}
			return false;
		}
		dataMemArrayHeader_ = (DataMemArrayHeader*)mem;

		//
		// create header element
		//
		dataMemArrayHeader_->eye_[0] = 'H';
		dataMemArrayHeader_->eye_[1] = 'E';
		dataMemArrayHeader_->eye_[2] = 'A';
		dataMemArrayHeader_->eye_[3] = 'D';
		dataMemArrayHeader_->maxMemorySize_ = maxMemorySize_;
		dataMemArrayHeader_->expandMemorySize_ = expandMemorySize_;

		dataMemArrayHeader_->actMemorySize_ = startMemorySize;
		dataMemArrayHeader_->actArraySize_ = 0;

		dataMemArrayHeader_->posFirstFreeSlot_ = sizeof(DataMemArrayHeader);
		dataMemArrayHeader_->posLastFreeSlot_ = sizeof(DataMemArrayHeader);

		//
		// create free element
		//
		DataMemoryArrayFreeSlot* freeSlot = (DataMemoryArrayFreeSlot*)&mem[sizeof(DataMemArrayHeader)];
		freeSlot->eye_[0] = 'F';
		freeSlot->eye_[1] = 'R';
		freeSlot->eye_[2] = 'E';
		freeSlot->eye_[3] = 'E';
		freeSlot->size_ = startMemorySize_ - sizeof(DataMemArrayHeader);
		freeSlot->posLastFreeSlot_ = sizeof(DataMemArrayHeader);
		freeSlot->posNextFreeSlot_ = sizeof(DataMemArrayHeader);

		return true;
	}

	bool
	DataMemArray::resizeMemArray(uint32_t arraySize)
	{
		if (arraySize == dataMemArrayHeader_->actArraySize_) {
			if (debug_) {
				Log(Debug, "source and target array size are equal")
					.parameter("Id", this);
			}
			return true;
		}

		//
		// get memory buffer
		//
		char* memBuf = (char*)dataMemArrayHeader_;
		uint32_t memSize = dataMemArrayHeader_->actMemorySize_;

		//
		// get last free slot
		//
		DataMemoryArrayFreeSlot* lastFreeSlot = (DataMemoryArrayFreeSlot*)&memBuf[dataMemArrayHeader_->posLastFreeSlot_];

		//
		// init array
		//
		if (arraySize > dataMemArrayHeader_->actArraySize_) {
			uint32_t actSize = dataMemArrayHeader_->actArraySize_ * sizeof(uint32_t);
			uint32_t usedSize = (arraySize - dataMemArrayHeader_->actArraySize_) * sizeof(uint32_t);
			uint32_t newSize = actSize + usedSize;

			if (debug_) {
				Log(Debug, "create new array elements")
					.parameter("Id", this)
					.parameter("OldArraySize", dataMemArrayHeader_->actArraySize_)
					.parameter("NewArraySize", arraySize)
					.parameter("NewMemSize", usedSize);
			}

			lastFreeSlot->size_ -= usedSize;
			memset(&memBuf[memSize-newSize], 0x00, usedSize);
		}
		else {
			uint32_t actSize = dataMemArrayHeader_->actArraySize_ * sizeof(uint32_t);
			uint32_t freeSize = (arraySize - dataMemArrayHeader_->actArraySize_) * sizeof(uint32_t);
			uint32_t newSize = actSize - freeSize;

			if (debug_) {
				Log(Debug, "create new array elements")
					.parameter("Id", this)
					.parameter("OldArraySize", dataMemArrayHeader_->actArraySize_)
					.parameter("NewArraySize", arraySize)
					.parameter("FreeMemSize", freeSize);
			}

			// FIXME: free elements ...
			lastFreeSlot->size_ += freeSize;
		}
		dataMemArrayHeader_->actArraySize_ = arraySize;

		return true;
	}

	uint32_t
	DataMemArray::calcMinMemoryBufferSize(uint32_t arraySize)
	{
		uint32_t size =
			sizeof(DataMemArrayHeader) + 		// header
			sizeof(DataMemoryArrayFreeSlot) +	// free slot
			arraySize * sizeof(uint32_t) +		// array
			1;									// minimum free
		return size;
	}
}
