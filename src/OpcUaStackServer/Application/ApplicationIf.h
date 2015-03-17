#ifndef __OpcUaStackServer_ApplicationIf_h__
#define __OpcUaStackServer_ApplicationIf_h__

#include "OpcUaStackCore/Base/os.h"

namespace OpcUaStackServer
{

	class DLLEXPORT ApplicationIf
	{
	  public:
		ApplicationIf(void) {}
		virtual ~ApplicationIf(void) {}

		virtual void startup(void) = 0;
		virtual void shutdown(void) = 0;
	};

}

#endif
