#ifndef __OpcUaStackCore_BaseClass_h__
#define __OpcUaStackCore_BaseClass_h__

#include "boost/shared_ptr.hpp"
#include "OpcUaStackCore/Base/os.h"

namespace OpcUaStackCore
{

	class DLLEXPORT BaseClass
	{
	  public:
		typedef boost::shared_ptr<BaseClass> SPtr;

		BaseClass(void) {}
		virtual ~BaseClass(void) {}
	};


}

#endif
