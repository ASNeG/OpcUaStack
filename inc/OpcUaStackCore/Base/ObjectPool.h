#ifndef __OpcUaStackCore_ObjectPool_h__
#define __OpcUaStackCore_ObjectPool_h__

#include "boost/shared_ptr.hpp"
#include "OpcUaStackCore/Base/Object.h"
#include "OpcUaStackCore/Base/os.h"

namespace OpcUaStackCore
{

	template<typename OBJ>
	class DLLEXPORT ObjectPool : public Object
	{
	  public:
		typedef boost::shared_ptr<OBJ> SPtr;

		static SPtr construct(void) {
			return boost::shared_ptr<OBJ>(new OBJ());
		}

		static void destruct(OBJ* obj) {
			delete obj;
		}

		static void destruct(SPtr objSPtr) {
		}

		ObjectPool(void) 
		: Object()
		{
		}

		virtual ~ObjectPool(void) 
		{
		}
	};

};

#endif