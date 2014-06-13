#ifndef __OpcUaStackCore_Object_h__
#define __OpcUaStackCore_Object_h__

#include "boost/shared_ptr.hpp"
#include "OpcUaStackCore/Base/os.h"

namespace OpcUaStackCore
{

	class DLLEXPORT Object
	{
	  public:
		typedef boost::shared_ptr<Object> SPtr;

		Object(void) {}
		virtual ~Object(void) {}
	};


}

#endif