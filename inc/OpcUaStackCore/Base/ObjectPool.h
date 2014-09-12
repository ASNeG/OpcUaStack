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

		template<typename T>
		  static SPtr construct(T& p) {
			  return boost::shared_ptr<OBJ>(new OBJ(p));
		  }

		template<typename T1, typename T2>
		  static SPtr construct(T1& p1, T2& p2) {
			  return boost::shared_ptr<OBJ>(new OBJ(p1, p2));
		  }

		template<typename T1, typename T2, typename T3>
		  static SPtr construct(T1& p1, T2& p2, T3& p3) {
			  return boost::shared_ptr<OBJ>(new OBJ(p1, p2, p3));
		  }

		template<typename T>
		  static SPtr construct(const T& p) {
			  return boost::shared_ptr<OBJ>(new OBJ(p));
		  }

		template<typename T1, typename T2>
		  static SPtr construct(const T1& p1, const T2& p2) {
			  return boost::shared_ptr<OBJ>(new OBJ(p1,p2));
		  }

		template<typename T1, typename T2, typename T3>
		  static SPtr construct(const T1& p1, const T2& p2, const T3& p3) {
			  return boost::shared_ptr<OBJ>(new OBJ(p1,p2, p3));
		  }

		SPtr constructMember(void) {
			return boost::shared_ptr<OBJ>(new OBJ());
		}

		static void destruct(OBJ* obj) {
			delete obj;
		}

		void destructMember(OBJ* obj) {
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

}

#endif