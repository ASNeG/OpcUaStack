#include "OpcUaStackCore/SecureChannel/SecureChannelClientConfig.h"
#include "OpcUaStackCore/Base/Log.h"

namespace OpcUaStackCore
{

	bool 
	SecureChannelClientConfig::create(SecureChannelClient::SPtr secureChannelClientSPtr, const std::string& configPrefix)
	{
		uint32_t uint32Value;
		std::string stringValue;

		Config* config = Config::instance();
		std::string configurationFileName = config->getValue("Global.ConfigurationFileName", "Unknown");

		boost::optional<Config> childConfig = config->getChild(configPrefix);
		if (!childConfig) {
			Log(Error, "secure channel client configuration not found")
				.parameter("ConfigurationFileName", configurationFileName)
				.parameter("ParameterPath", configPrefix);
			return false;
		}

		//
		// hello message parameter
		//
		// ProtocolVersion (optional) 
		// ReceivedBufferSize (optional)
		// SendBufferSize (optional)
		// MaxMessageSize (optional)
		// MaxChunkCount (optional)
		// EndpointUrl (mandatory)
		//
		HelloMessage::SPtr helloSPtr = secureChannelClientSPtr->helloMessage();

		childConfig->getConfigParameter("ProtocolVersion", uint32Value, "0");
		helloSPtr->protocolVersion(uint32Value);

		childConfig->getConfigParameter("ReceivedBufferSize", uint32Value, "65536");
		helloSPtr->receivedBufferSize(uint32Value);

		childConfig->getConfigParameter("SendBufferSize", uint32Value, "65536");
		helloSPtr->sendBufferSize(uint32Value);

		childConfig->getConfigParameter("MaxMessageSize", uint32Value, "16777216");
		helloSPtr->maxMessageSize(uint32Value);
		
		childConfig->getConfigParameter("MaxChunkCount", uint32Value, "5000");
		helloSPtr->maxChunkCount(uint32Value);
		
		if (childConfig->getConfigParameter("EndpointUrl", stringValue) == false) {
			Log(Error, "mandatory parameter not found in configuration")
				.parameter("ConfigurationFileName", configurationFileName)
				.parameter("ParameterPath", configPrefix)
				.parameter("ParameterName", "EndpointUrl");
			return false;
		}
		helloSPtr->endpointUrl(stringValue);

		return true;
	}

}