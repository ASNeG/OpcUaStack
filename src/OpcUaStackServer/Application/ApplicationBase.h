#ifndef __OpcUaStackServer_ApplicationBase_h__
#define __OpcUaStackServer_ApplicationBase_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Component/Component.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	class DLLEXPORT ApplicationBase
	: public Component
	{
	  public:
		ApplicationBase(void);
		virtual ~ApplicationBase(void);

		virtual bool init(void) { return true; }
		virtual bool shutdown(void) { return true; }

	  protected:
	};

}

#endif
