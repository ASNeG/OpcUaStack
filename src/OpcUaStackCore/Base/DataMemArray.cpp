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
	DataMemArray::DataMemArray(void)
	: dataMemArrayHeader_(nullptr)
	, startMemorySizeDefault_(10000)
	, maxMemorySizeDefault_(1000000)
	, expandMemorySizeDefault_(10000)
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
	DataMemArray::startMemorySizeDefault(uint32_t startMemorySizeDefault)
	{
		startMemorySizeDefault_ = startMemorySizeDefault;
	}

	void
	DataMemArray::maxMemorySizeDefault(uint32_t maxMemorySizeDefault)
	{
		maxMemorySizeDefault_ = maxMemorySizeDefault;
	}

	void
	DataMemArray::expandMemorySizeDefault(uint32_t expandMemorySizeDefault)
	{
		expandMemorySizeDefault_ = expandMemorySizeDefault;
	}

	uint32_t
	DataMemArray::arraySize(void)
	{
		return 0;
	}

	bool
	DataMemArray::arrayResize(uint32_t numberElements)
	{
		// FIXME: todo
		return true;
	}

	bool
	DataMemArray::set(uint32_t idx, const char* buf, uint32_t bufLen)
	{
		// FIXME: todo
		return true;
	}

	bool
	DataMemArray::get(uint32_t idx, char**buf, uint32_t& bufLen)
	{
		// FIXME: todo
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

}
