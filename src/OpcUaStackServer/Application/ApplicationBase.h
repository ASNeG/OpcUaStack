#ifndef __OpcUaStackServer_ApplicationBase_h__
#define __OpcUaStackServer_ApplicationBase_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Component/Component.h"
#include "OpcUaStackServer/Application/ApplicationIf.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	class DLLEXPORT ApplicationBase
	: public Component
	{
	  public:
		ApplicationBase(void);
		virtual ~ApplicationBase(void);

		void applicationIf(ApplicationIf* applicationIf);
		ApplicationIf& applicationIf(void);

		virtual bool init(void) { return true; }
		virtual bool shutdown(void) { return true; }

	  private:
		ApplicationIf* applicationIf_;

	};

}

#endif
