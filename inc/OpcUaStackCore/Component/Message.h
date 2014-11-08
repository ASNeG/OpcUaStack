#ifndef __OpcUaStackCore_Message_h__
#define __OpcUaStackCore_Message_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"

namespace OpcUaStackCore
{

	class DLLEXPORT Message
	{
	  public:
		typedef boost::shared_ptr<Message> SPtr;
	};

}

#endif