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

	template<typename OBJ, typename P1, typename P2>
	  typename OBJ::SPtr constructSPtr(const P1& p1, const P2& p2) {
		return typename OBJ::SPtr(new OBJ(p1, p2));
	  }

	template<typename OBJ, typename P1, typename P2, typename P3>
	  typename OBJ::SPtr constructSPtr(P1& p1, P2& p2, P3& p3) {
		return typename OBJ::SPtr(new OBJ(p1, p2, p3));
	  }

	template<typename OBJ, typename P1, typename P2, typename P3>
	  typename OBJ::SPtr constructSPtr(const P1& p1, const P2& p2, const P3& p3) {
		return typename OBJ::SPtr(new OBJ(p1, p2, p3));
	  }

	template<typename OBJ, typename P1, typename P2, typename P3, typename P4>
	  typename OBJ::SPtr constructSPtr(P1& p1, P2& p2, P3& p3, P4& p4) {
		return typename OBJ::SPtr(new OBJ(p1, p2, p3, p4));
	  }

	template<typename OBJ, typename P1, typename P2, typename P3, typename P4>
	  typename OBJ::SPtr constructSPtr(const P1& p1, const P2& p2, const P3& p3, const P4& p4) {
		return typename OBJ::SPtr(new OBJ(p1, p2, p3, p4));
	  }

	template<typename OBJ, typename P1, typename P2, typename P3, typename P4, typename P5>
	  typename OBJ::SPtr constructSPtr(P1& p1, P2& p2, P3& p3, P4& p4, P5& p5) {
		return typename OBJ::SPtr(new OBJ(p1, p2, p3, p4, p5));
	  }

	template<typename OBJ, typename P1, typename P2, typename P3, typename P4, typename P5>
	  typename OBJ::SPtr constructSPtr(const P1& p1, const P2& p2, const P3& p3, const P4& p4, const P5& p5) {
		return typename OBJ::SPtr(new OBJ(p1, p2, p3, p4, p5));
	  }

	template<typename OBJ, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
	  typename OBJ::SPtr constructSPtr(const P1& p1, const P2& p2, const P3& p3, const P4& p4, const P5& p5, const P6& p6) {
		return typename OBJ::SPtr(new OBJ(p1, p2, p3, p4, p5, p6));
	  }

}

#endif
