#ifndef __OpcUaStackServer_SessionConfig_h__
#define __OpcUaStackServer_SessionConfig_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/Config.h"
#include "OpcUaStackServer/ServiceSet/Session.h"

namespace OpcUaStackServer
{

	class DLLEXPORT SessionConfig
	{
	  public:
		static bool initial(Session::SPtr sessionSPtr, const std::string& configPrefix, Config* config = nullptr);
		static bool endpointDescriptions(Session::SPtr sessionSPtr, const std::string& configPrefix, Config* config, const std::string& configurationFileName);
		static bool userTokenPolicy(EndpointDescription::SPtr endpointDescription, const std::string& configPrefix, Config* config, const std::string& configurationFileName);
	};

}

#endif