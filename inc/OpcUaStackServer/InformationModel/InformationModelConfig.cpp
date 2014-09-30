#include "OpcUaStackServer/InformationModel/InformationModelConfig.h"
#include "OpcUaStackCore/Base/Log.h"

namespace OpcUaStackServer
{

	bool 
	InformationModelConfig::initial(InformationModel::SPtr informationModelSPtr, const std::string& configPrefix, Config* config)
	{

		uint32_t uint32Value;
		std::string stringValue;

		if (config == nullptr) config = Config::instance();
		std::string configurationFileName = config->getValue("Global.ConfigurationFileName", "Unknown");

		boost::optional<Config> childConfig = config->getChild(configPrefix);
		if (!childConfig) {
			Log(Error, "information model configuration not found")
				.parameter("ConfigurationFileName", configurationFileName)
				.parameter("ParameterPath", configPrefix);
			return false;
		}

		// --------------------------------------------------------------------
		// --------------------------------------------------------------------
		//
		// ... 
		//
		// --------------------------------------------------------------------
		// --------------------------------------------------------------------

		return true;
	}

}