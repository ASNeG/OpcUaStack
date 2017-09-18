/*
   Copyright 2015-2017 Kai Huebl (kai@huebl-sgh.de)

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

	class DLLEXPORT PoolListEntry
	{
	  public:
		PoolListEntry(void);
		~PoolListEntry(void);

		char *getMemory(void);
		static PoolListEntry* MemoryToPoolListEntry(char* memory);

		inline bool empty(void);

		inline void add(PoolListEntry* poolListEntry);
		inline void addAfter(PoolListEntry* poolListEntry);
		inline void addBefor(PoolListEntry* poolListEntry);

		inline PoolListEntry* del(void);
		inline PoolListEntry* delBefor(void);
		inline PoolListEntry* delAfter(void);

		PoolListEntry* next_;
		PoolListEntry* last_;
	};


	typedef PoolListEntry BufferListEntry;

	class DLLEXPORT PoolList
	: public PoolListEntry
	{
	  public:
		PoolList(void);
		~PoolList(void);

		uint32_t size(void);

		bool empty(void);

		void addLast(PoolListEntry* poolListEntry);
		void addFirst(PoolListEntry* poolListEntry);

		PoolListEntry* del(PoolListEntry* poolListEntry);
		PoolListEntry* delFirst(void);
		PoolListEntry* delLast(void);

		PoolListEntry* garbageCollector(void);
		PoolListEntry* garbageCollectorNext(void);

		void log(std::ostream& os);

	  private:
		PoolListEntry* garbageCollector_;
		uint32_t size_;
	};


	class DLLEXPORT PoolBase
	{
	  public:
		PoolBase(
			uint32_t entrySize,
			uint32_t startEntries,
			uint32_t growEntries,
			uint32_t maxUsedEntries,
			uint32_t maxFreeEntries
		);
		virtual ~PoolBase(void);

		PoolListEntry* allocate();
		void free(PoolListEntry* poolListEntry);

		uint32_t usedEntries(void);
		uint32_t freeEntries(void);

		virtual void memoryConstructHandler(char* memory) {}
		virtual void memoryDestructHandler(char* memory) {}
		virtual bool garbageCollector(void) { return false; }

	  private:
		bool grow(uint32_t growEntries);

		uint32_t entrySize_;
		uint32_t sharedPointerSize_;
		uint32_t startEntries_;
		uint32_t growEntries_;
		uint32_t maxUsedEntries_;
		uint32_t maxFreeEntries_;
		uint32_t freeEntries_;
		uint32_t usedEntries_;
		PoolList freePoolList_;
	};

}

#endif
