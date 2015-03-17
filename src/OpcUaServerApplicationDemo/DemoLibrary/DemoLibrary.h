#ifndef __OpcUaServerApplicationDemo_DemoLibrary_h__
#define __OpcUaServerApplicationDemo_DemoLibrary_h__

#include "OpcUaStackServer/Application/ApplicationIf.h"

using namespace OpcUaStackServer;

namespace OpcUaServerApplicationDemo
{

	class DemoLibrary
	: public ApplicationIf
	{
	  public:
		DemoLibrary(void);
		virtual ~DemoLibrary(void);

		//- ApplicationIf -----------------------------------------------------
		virtual void startup(void);
		virtual void shutdown(void);
		//- ApplicationIf -----------------------------------------------------
	};

}

#endif
