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

	template<typename OBJ, uint32_t START_ENTRIES=32, uint32_t GROW_ENTRIES=32, uint32_t MAX_ENTRIES=0>
	class Pool
	: public PoolBase
	{
	  public:
		Pool(void)
		: PoolBase(sizeof(OBJ), START_ENTRIES, GROW_ENTRIES, MAX_ENTRIES)
		{
		}

		virtual ~Pool(void)
		{
		}

		OBJ* construct(void)
		{
			char *memory = nullptr; //allocateMemory();
			if (memory == nullptr) return nullptr;
			return new (memory) OBJ();
		}

		inline void construct(typename OBJ::SPtr& sptr)
		{
			sptr = boost::shared_ptr<OBJ>(
				construct(),
				boost::bind(&Pool<OBJ>::destroy, this, _1)
			);
		}

		inline void destroy(OBJ* obj)
		{
			obj->~OBJ();
			//freeMemory((char*)obj);
		}

	  private:
	};

}

#endif
