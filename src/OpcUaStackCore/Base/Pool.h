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


   Datastruct Pointer:
   - PoolListEntry
   - Object

   Datastruct SmarePointer:
   - PoolListEntry
   - SmartPointer
   - Object


 */

#ifndef __OpcUaStackCore_Pool_h__
#define __OpcUaStackCore_Pool_h__

#include <stdint.h>
#include "boost/shared_ptr.hpp"
#include "boost/bind.hpp"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/PoolBase.h"

namespace OpcUaStackCore
{

	template<
	    typename OBJ,
	    bool USE_SHARED_PTR=false,
	    uint32_t START_ENTRIES=32,
	    uint32_t GROW_ENTRIES=32,
	    uint32_t MAX_USEDENTRIES=0,
	    uint32_t MAX_FREEENTRIES=0,
	    uint32_t GARBAGE_COLLECTOR_LOOP_COUNT=32
	>
	class Pool
	: public PoolBase
	{
	  public:
		Pool(void)
		: PoolBase(
			sizeof(OBJ) + (USE_SHARED_PTR ? 0 : sizeof(typename OBJ::SPtr)),
			START_ENTRIES,
			GROW_ENTRIES,
			MAX_USEDENTRIES,
			MAX_FREEENTRIES
		)
		, usedPoolList_()
	    , nullSPtr_()
		{
		}

		virtual ~Pool(void)
		{
			while (!usedPoolList_.empty()) {
				destroy((OBJ*)usedPoolList_.delFirst()->getMemory());
			}
		}

		inline OBJ* construct(void)
		{
			if (USE_SHARED_PTR) return nullptr;

			PoolListEntry* poolListEntry = allocate();
			if (poolListEntry == nullptr) return nullptr;

			usedPoolList_.addLast(poolListEntry);
			return new (poolListEntry->getMemory()) OBJ();
		}

		inline typename OBJ::SPtr& constructSPtr(void)
		{
			if (!USE_SHARED_PTR) return nullSPtr_;

			PoolListEntry* poolListEntry = allocate();
			if (poolListEntry == nullptr) return nullSPtr_;

			usedPoolList_.addLast(poolListEntry);
			char* memory = poolListEntry->getMemory();
			typename OBJ::SPtr* sptr = (typename OBJ::SPtr*)memory;

			memory += sizeof(typename OBJ::SPtr);
			OBJ* obj = new (memory) OBJ();

			return *sptr;
		}

		inline void destroy(OBJ* obj)
		{
			obj->~OBJ();
			PoolListEntry* poolListEntry = PoolListEntry::MemoryToPoolListEntry((char*)obj);
			usedPoolList_.del(poolListEntry);
			free(poolListEntry);
		}

		virtual void memoryConstructHandler(char* memory)
		{
			if (!USE_SHARED_PTR) return;
			OBJ* obj = (OBJ*)(memory + sizeof(typename OBJ::SPtr));
			typename OBJ::SPtr* sptr = new (memory) typename OBJ::SPtr(obj);
		}

		virtual void memoryDestructHandler(char* memory)
		{
			if (!USE_SHARED_PTR) return;
			typename OBJ::SPtr* sptr = (typename OBJ::SPtr*)memory;
			sptr->reset();
		}

		virtual bool garbageCollector(void)
		{
			if (!USE_SHARED_PTR) return false;
			return garbageCollectorLoop(GARBAGE_COLLECTOR_LOOP_COUNT);
		}

		bool garbageCollectorLoop(uint32_t maxEntries, bool findFirst = false)
		{
			//std::cout << "garbageCollectorLoop" << std::endl;
			if (maxEntries == usedPoolList_.size()) maxEntries = usedPoolList_.size();
			if (maxEntries < usedPoolList_.size()) maxEntries = usedPoolList_.size();
			PoolListEntry* poolListEntry = usedPoolList_.garbageCollector();
			if (poolListEntry == nullptr) return false;

			bool elementsFound = false;
			for (uint32_t idx=0; idx<maxEntries; idx++) {
				char* memory = poolListEntry->getMemory();
				typename OBJ::SPtr* sptr = (typename OBJ::SPtr*)memory;
				if (sptr->unique()) {
					elementsFound = true;

					OBJ* obj = (OBJ*)(memory + sizeof(typename OBJ::SPtr));
					obj->~OBJ();

					usedPoolList_.del(poolListEntry);
					free(poolListEntry);

					if (findFirst) return true;

					poolListEntry = usedPoolList_.garbageCollector();
				}
				else {
					poolListEntry = usedPoolList_.garbageCollectorNext();

				}
				if (poolListEntry == nullptr) return elementsFound;
			}
			return elementsFound;
		}

	  private:
		typename OBJ::SPtr nullSPtr_;
		PoolList usedPoolList_;
	};

}

#endif
