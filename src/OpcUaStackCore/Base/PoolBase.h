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

#ifndef __OpcUaStackCore_PoolBase_h__
#define __OpcUaStackCore_PoolBase_h__

#include <stdint.h>
#include "boost/shared_ptr.hpp"
#include "boost/bind.hpp"
#include "OpcUaStackCore/Base/os.h"

namespace OpcUaStackCore
{

	class PoolListEntry
	{
	  public:
		PoolListEntry* next_;
	};

	typedef PoolListEntry BufferListEntry;


	class DLLEXPORT PoolBase
	{
	  public:
		PoolBase(uint32_t entrySize, uint32_t startEntries, uint32_t growEntries, uint32_t maxEntries);
		virtual ~PoolBase(void);

		char* allocateMemory();
		void freeMemory(char* memory);

		uint32_t actEntries(void);

	  public:
		void createNewBuffer(uint32_t growEntries);

		uint32_t entrySize_;
		PoolListEntry* poolListEntry_;
		BufferListEntry* bufferListEntry_;

		uint32_t maxEntries_;
		uint32_t startEntries_;
		uint32_t growEntries_;
		uint32_t actEntries_;

		char* buffer_;
		uint32_t bufferLen_;
		uint32_t bufferPos_;
	};

}

#endif
