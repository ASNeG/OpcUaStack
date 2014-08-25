#include "OpcUaStackClient/SecureChannel/SecureChannelClientConfig.h"
#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackCore/Base/Config.h"

using namespace OpcUaStackCore;

namespace OpcUaStackClient
{

	bool 
	SecureChannelClientConfig::initial(SecureChannelClient::SPtr secureChannelClientSPtr, const std::string& configPrefix)
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

		ChannelDataBase::SPtr channelDataBasePtr = secureChannelClientSPtr->channelDataBase();
		SecurityHeader::SPtr securityHeaderSPtr = secureChannelClientSPtr->securityHeader();

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

		// --------------------------------------------------------------------
		// --------------------------------------------------------------------
		//
		// security parameter
		//
		// --------------------------------------------------------------------
		// --------------------------------------------------------------------
		//
		// SecurityPolicyUri (mandatory)
		//
		// --------------------------------------------------------------------
		// --------------------------------------------------------------------
		if (childConfig->getConfigParameter("SecurityPolicyUri", stringValue) == false) {
			Log(Error, "mandatory parameter not found in configuration")
				.parameter("ConfigurationFileName", configurationFileName)
				.parameter("ParameterPath", configPrefix)
				.parameter("ParameterName", "SecurityPolicyUri");
			return false;
		}
		securityHeaderSPtr->securityPolicyUri((OpcUaByte*)stringValue.c_str(), stringValue.length());
		if (stringValue != "http://opcfoundation.org/UA/SecurityPolicy#None") {
			Log(Error, "invalid parameter in configuration")
				.parameter("ConfigurationFileName", configurationFileName)
				.parameter("ParameterPath", configPrefix)
				.parameter("ParameterName", "SecurityPolicyUri")
				.parameter("ParameterValue", stringValue);
			return false;
		}

		return true;
	}

}