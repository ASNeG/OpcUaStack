#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackCore/Base/Config.h"
#include "OpcUaStackServer/ServiceSet/SessionConfig.h"
#include "OpcUaStackServer/ServiceSet/EndpointDescriptionConfig.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	bool 
	SessionConfig::initial(Session::SPtr sessionSPtr, const std::string& configPrefix, Config* config)
	{
		if (config == nullptr) config = Config::instance();

		boost::optional<Config> childConfig = config->getChild(configPrefix);
		if (!childConfig) {
			Log(Error, "session server configuration not found")
				.parameter("ConfigurationFileName", config->configFileName())
				.parameter("ParameterPath", configPrefix);
			return false;
		}


		// -------------------------------------------------------------------------
		// -------------------------------------------------------------------------
		//
		// create session
		//
		// --------------------------------------------------------------------------
		//
		// EndpointDescription - mandatory
		//
		// --------------------------------------------------------------------------
		// --------------------------------------------------------------------------
		EndpointDescriptionArray::SPtr endpointDescriptionArray = EndpointDescriptionArray::construct();

		if (!EndpointDescriptionConfig::endpointDescriptions(endpointDescriptionArray, configPrefix, config, config->configFileName())) {
			return false;
		}

		sessionSPtr->endpointDescriptionArray(endpointDescriptionArray);

		return true;
	}
}