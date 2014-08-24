#ifndef _OpcUaStackClient_SessionConfig_h__
#define _OpcUaStackClient_SessionConfig_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackClient/ServiceSet/Session.h"

namespace OpcUaStackClient
{

	class DLLEXPORT SessionConfig
	{
	  public:
		static bool initial(Session::SPtr sessionSPtr, const std::string& configPrefix);
	};

}

#endif