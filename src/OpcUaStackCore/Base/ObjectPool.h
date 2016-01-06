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

#ifndef __OpcUaStackCore_ObjectPool_h__
#define __OpcUaStackCore_ObjectPool_h__

#include "boost/shared_ptr.hpp"
#include "OpcUaStackCore/Base/Object.h"
#include "OpcUaStackCore/Base/os.h"

namespace OpcUaStackCore
{

	template<typename OBJ>
	class DLLEXPORT ObjectPoolX
	{
	  public:
	};

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// pointer
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	template<typename OBJ>
	  OBJ* construct(void) {
		return new OBJ();
	  }

	template<typename OBJ, typename P1>
	  OBJ* construct(P1& p1) {
		return new OBJ(p1);
	  }

	template<typename OBJ, typename P1>
	  OBJ* construct(const P1& p1) {
		return new OBJ(p1);
	  }

	template<typename OBJ, typename P1>
	  OBJ* construct(P1* p1) {
		return new OBJ(p1);
	  }

	template<typename OBJ, typename P1>
	  OBJ* construct(const P1* p1) {
		return new OBJ(p1);
	  }


	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// smart pointer
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	template<typename OBJ>
	  typename OBJ::SPtr constructSPtr(void) {
		return typename OBJ::SPtr(new OBJ());
	  }

	template<typename OBJ, typename P1>
	  typename OBJ::SPtr constructSPtr(P1& p1) {
		return typename OBJ::SPtr(new OBJ(p1));
	  }

	template<typename OBJ, typename P1>
	  typename OBJ::SPtr constructSPtr(const P1& p1) {
		return typename OBJ::SPtr(new OBJ(p1));
	  }

	template<typename OBJ, typename P1>
	  typename OBJ::SPtr constructSPtr(P1* p1) {
		return typename OBJ::SPtr(new OBJ(p1));
	  }

	template<typename OBJ, typename P1>
	  typename OBJ::SPtr constructSPtr(const P1* p1) {
		return typename OBJ::SPtr(new OBJ(p1));
	  }



#if 1
	////////////////////////////////////////////
	////////////////////////////////////////////
	template<typename OBJ>
	class DLLEXPORT ObjectPool
	: public Object
	{
	  public:
		static boost::shared_ptr<OBJ> construct(void) {
			return boost::shared_ptr<OBJ>(new OBJ());
		}

		template<typename T>
		  static boost::shared_ptr<OBJ> construct(T& p) {
			  return boost::shared_ptr<OBJ>(new OBJ(p));
		  }

		template<typename T1, typename T2>
		  static boost::shared_ptr<OBJ> construct(T1& p1, T2& p2) {
			  return boost::shared_ptr<OBJ>(new OBJ(p1, p2));
		  }

		template<typename T1, typename T2, typename T3>
		  static boost::shared_ptr<OBJ> construct(T1& p1, T2& p2, T3& p3) {
			  return boost::shared_ptr<OBJ>(new OBJ(p1, p2, p3));
		  }

		template<typename T>
		  static boost::shared_ptr<OBJ> construct(const T& p) {
			  return boost::shared_ptr<OBJ>(new OBJ(p));
		  }

		template<typename T1, typename T2>
		  static boost::shared_ptr<OBJ> construct(const T1& p1, const T2& p2) {
			  return boost::shared_ptr<OBJ>(new OBJ(p1,p2));
		  }

		template<typename T1, typename T2, typename T3>
		  static boost::shared_ptr<OBJ> construct(const T1& p1, const T2& p2, const T3& p3) {
			  return boost::shared_ptr<OBJ>(new OBJ(p1,p2, p3));
		  }

		boost::shared_ptr<OBJ> constructMember(void) {
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

	template<typename OBJ>
	class DLLEXPORT ObjectPool1
	: public Object
	{
	  public:
		static boost::shared_ptr<OBJ> construct1(void) {
			return boost::shared_ptr<OBJ>(new OBJ());
		}

		template<typename T>
		  static boost::shared_ptr<OBJ> construct1(T& p) {
			  return boost::shared_ptr<OBJ>(new OBJ(p));
		  }

		template<typename T1, typename T2>
		  static boost::shared_ptr<OBJ> construct1(T1& p1, T2& p2) {
			  return boost::shared_ptr<OBJ>(new OBJ(p1, p2));
		  }

		template<typename T1, typename T2, typename T3>
		  static boost::shared_ptr<OBJ> construct1(T1& p1, T2& p2, T3& p3) {
			  return boost::shared_ptr<OBJ>(new OBJ(p1, p2, p3));
		  }

		template<typename T>
		  static boost::shared_ptr<OBJ> construct1(const T& p) {
			  return boost::shared_ptr<OBJ>(new OBJ(p));
		  }

		template<typename T1, typename T2>
		  static boost::shared_ptr<OBJ> construct1(const T1& p1, const T2& p2) {
			  return boost::shared_ptr<OBJ>(new OBJ(p1,p2));
		  }

		template<typename T1, typename T2, typename T3>
		  static boost::shared_ptr<OBJ> construct1(const T1& p1, const T2& p2, const T3& p3) {
			  return boost::shared_ptr<OBJ>(new OBJ(p1,p2, p3));
		  }

		boost::shared_ptr<OBJ> constructMember1(void) {
			return boost::shared_ptr<OBJ>(new OBJ());
		}

		static void destruct1(OBJ* obj) {
			delete obj;
		}

		void destructMember1(OBJ* obj) {
			delete obj;
		}

		static void destruct1(SPtr objSPtr) {
		}

		ObjectPool1(void)
		: Object()
		{
		}

		virtual ~ObjectPool1(void)
		{
		}
	};
#endif

}

#endif
