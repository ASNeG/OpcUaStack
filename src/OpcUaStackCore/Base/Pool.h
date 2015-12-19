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
			sizeof(OBJ) + (USE_SHARED_PTR ? 0 : sizeof(boost::shared_ptr<OBJ>)),
			START_ENTRIES,
			GROW_ENTRIES,
			MAX_USEDENTRIES,
			MAX_FREEENTRIES
		)
		, usedPoolList_()
		, garbageCollectorEntry_(&usedPoolList_)
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

			usedPoolList_.add(poolListEntry);
			return new (poolListEntry->getMemory()) OBJ();
		}

		inline typename OBJ::SPtr& constructSPtr(void)
		{
			if (!USE_SHARED_PTR) {
				typename OBJ::SPtr sptr;
				return sptr;
			}

			PoolListEntry* poolListEntry = allocate();
			if (poolListEntry == nullptr) {
				typename OBJ::SPtr sptr;
				return sptr;
			}

			usedPoolList_.addLast(poolListEntry);
			char* memory = poolListEntry->getMemory();
			typename OBJ::SPtr* sptr = (typename OBJ::SPtr*)memory;

			memory += sizeof(OBJ::SPtr);
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
			typename OBJ::SPtr* sptr = (typename OBJ::SPtr*)memory;
			OBJ* obj = (OBJ*)(memory + sizeof(typename OBJ::SPtr));
			sptr->reset(obj);
		}

		virtual void memoryDestructHandler(char* memory)
		{
			if (!USE_SHARED_PTR) return;
			typename OBJ::SPtr* sptr = (typename OBJ::SPtr*)memory;
			sptr->reset();
		}

		virtual void garbageCollector(void)
		{
			if (!USE_SHARED_PTR) return;
			garbageCollectorLoop(GARBAGE_COLLECTOR_LOOP_COUNT);
		}

		void garbageCollectorLoop(uint32_t maxEntries, bool findFirst = false)
		{
			if (maxEntries < usedEntries_) maxEntries = usedEntries_;
			for (uint32_t idx=0; idx<maxEntries; idx++) {
				if (garbageCollectorEntry_ == &usedPoolList_) {
					garbageCollectorEntry_ = garbageCollectorEntry_->next_;
				}

				char* memory = garbageCollectorEntry_->getMemory();
				typename OBJ::SPtr* sptr = (typename OBJ::SPtr*)memory;
				if (sptr->unique()) {
					PoolListEntry* poolListEntry = garbageCollectorEntry_;
					garbageCollectorEntry_ = garbageCollectorEntry_->next_;

					usedPoolList_.del(poolListEntry);
					free(poolListEntry);

					if (findFirst) return;
				}
				else {
					garbageCollectorEntry_ = garbageCollectorEntry_->next_;
				}
			}
		}

	  private:
		PoolListEntry* garbageCollectorEntry_;
		PoolList usedPoolList_;
	};

}

#endif
