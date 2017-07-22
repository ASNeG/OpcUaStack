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

}
