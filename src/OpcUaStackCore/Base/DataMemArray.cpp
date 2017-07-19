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

	DataMemArray::DataMemArray(void)
	: startMemorySize_(100000)
	, maxMemorySize_(0)
	, expandMemorySize(100000);
	, memBuf_(nullptr)
	, memLen_(0)
	, arraySize_(0)
	{
	}

	DataMemArray::~DataMemArray(void)
	{
		clear();
	}

	void
	DataMemArray::startMemorySize(uint32_t startMemorySize)
	{
		startMemorySize_ = startMemorySize;
	}

	uint32_t
	DataMemArray::startMemorySize(void)
	{
		return startMemorySize_;
	}

	void
	DataMemArray::maxMemorySize(uint32_t maxMemorySize)
	{
		maxMemorySize_ = maxMemorySize;
	}

	uint32_t
	DataMemArray::maxMemorySize(void)
	{
		return maxMemorySize_;
	}

	void
	DataMemArray::expandMemorySize(uint32_t expandMemorySize)
	{
		expandedMemorySize_ = expandedMemorySize;
	}

	uint32_t
	DataMemArray::expandMemorySize(void)
	{
		return expandedMemorySize_;
	}

	uint32_t
	DataMemArray::actMemorySize(void)
	{
		return memLen_;
	}

	uint32_t
	DataMemArray::arraySize(void)
	{
		return arraySize_;
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
	DataMemArray::clear()
	{
		// FIXME: todo
	}

}
