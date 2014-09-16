#ifndef __OpcUaStackServer_EndpointDescriptionConfig_h__
#define __OpcUaStackServer_EndpointDescriptionConfig_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/Config.h"
#include "OpcUaStackCore/ServiceSet/EndpointDescription.h"
#include <string>

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	class DLLEXPORT EndpointDescriptionConfig
	{
	  public:
		static bool endpointDescriptions(EndpointDescriptionArray::SPtr endpointDescriptionArray, const std::string& configPrefix, Config* childConfig, const std::string& configurationFileName);
		static bool userTokenPolicy(EndpointDescription::SPtr endpointDescription, const std::string& configPrefix, Config* config, const std::string& configurationFileName);
	};

}

#endif