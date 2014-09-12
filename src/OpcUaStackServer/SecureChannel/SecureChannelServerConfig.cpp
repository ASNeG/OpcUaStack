#include "OpcUaStackServer/SecureChannel/SecureChannelServerConfig.h"
#include "OpcUaStackCore/Base/Log.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	bool 
	SecureChannelServerConfig::initial(SecureChannelServer::SPtr secureChannelServerSPtr, const std::string& configPrefix, Config* config)
	{
		uint32_t uint32Value;
		std::string stringValue;

		if (config == nullptr) config = Config::instance();
		std::string configurationFileName = config->getValue("Global.ConfigurationFileName", "Unknown");

		boost::optional<Config> childConfig = config->getChild(configPrefix);
		if (!childConfig) {
			Log(Error, "secure channel server configuration not found")
				.parameter("ConfigurationFileName", configurationFileName)
				.parameter("ParameterPath", configPrefix);
			return false;
		}

		ChannelDataBase::SPtr channelDataBasePtr = secureChannelServerSPtr->channelDataBase();

		// -------------------------------------------------------------------------
		// -------------------------------------------------------------------------
		//
		// general channel parameter
		//
		// --------------------------------------------------------------------------
		//
		// ProtocolVersion (optional) 
		// ReceivedBufferSize (optional)
		// SendBufferSize (optional)
		// MaxMessageSize (optional)
		// MaxChunkCount (optional)
		// EndpointUrl (mandatory)
		//
		// --------------------------------------------------------------------------
		// --------------------------------------------------------------------------
		childConfig->getConfigParameter("ProtocolVersion", uint32Value, "0");
		channelDataBasePtr->protocolVersion(uint32Value);

		childConfig->getConfigParameter("ReceivedBufferSize", uint32Value, "65536");
		channelDataBasePtr->receivedBufferSize(uint32Value);

		childConfig->getConfigParameter("SendBufferSize", uint32Value, "65536");
		channelDataBasePtr->sendBufferSize(uint32Value);

		childConfig->getConfigParameter("MaxMessageSize", uint32Value, "16777216");
		channelDataBasePtr->maxMessageSize(uint32Value);
		
		childConfig->getConfigParameter("MaxChunkCount", uint32Value, "5000");
		channelDataBasePtr->maxChunkCount(uint32Value);
		
		if (childConfig->getConfigParameter("EndpointUrl", stringValue) == false) {
			Log(Error, "mandatory parameter not found in configuration")
				.parameter("ConfigurationFileName", configurationFileName)
				.parameter("ParameterPath", configPrefix)
				.parameter("ParameterName", "EndpointUrl");
			return false;
		}
		channelDataBasePtr->endpointUrl(stringValue);

		return true;
	}

}