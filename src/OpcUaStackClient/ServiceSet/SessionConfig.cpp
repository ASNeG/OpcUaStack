#include "OpcUaStackClient/ServiceSet/SessionConfig.h"
#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackCore/Base/Config.h"

using namespace OpcUaStackCore;

namespace OpcUaStackClient
{

	bool 
	SessionConfig::initial(Session::SPtr sessionSPtr, const std::string& configPrefix, Config* config)
	{
		uint32_t uint32Value;
		std::string stringValue;

		if (config == nullptr) config = Config::instance();
		std::string configurationFileName = config->getValue("Global.ConfigurationFileName", "Unknown");

		boost::optional<Config> childConfig = config->getChild(configPrefix);
		if (!childConfig) {
			Log(Error, "session client configuration not found")
				.parameter("ConfigurationFileName", configurationFileName)
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
		// EndpointUrl (mandatory)
		// SessionName (mandatory)
		// RequestedSessionTimeout (optional)
		// MaxResponseMessageSize (optional)
		//
		// --------------------------------------------------------------------------
		// --------------------------------------------------------------------------
		CreateSessionParameter& createSessionParameter = sessionSPtr->createSessionParameter();
		if (childConfig->getConfigParameter("EndpointUrl", stringValue) == false) {
			Log(Error, "mandatory parameter not found in configuration")
				.parameter("ConfigurationFileName", configurationFileName)
				.parameter("ParameterPath", configPrefix)
				.parameter("ParameterName", "EndpointUrl");
			return false;
		}
		createSessionParameter.endpointUrl_ = stringValue;

		if (childConfig->getConfigParameter("SessionName", stringValue) == false) {
			Log(Error, "mandatory parameter not found in configuration")
				.parameter("ConfigurationFileName", configurationFileName)
				.parameter("ParameterPath", configPrefix)
				.parameter("ParameterName", "SessionName");
			return false;
		}
		createSessionParameter.sessionName_ = stringValue;

		childConfig->getConfigParameter("RequestedSessiontimeout", uint32Value, "120000");
		createSessionParameter.requestedSessionTimeout_ = uint32Value;

		childConfig->getConfigParameter("MaxResponseMessageSize", uint32Value, "0");
		createSessionParameter.maxResponseMessageSize_ = uint32Value;
	
		// --------------------------------------------------------------------
		// --------------------------------------------------------------------
		//
		// application description
		//
		// --------------------------------------------------------------------
		// 
		// ApplicationDescription.ApplicationUri (mandatory)
		// ApplicationDescription.ProductUri (mandatory)
		// ApplicationDescription.ApplicationName.Locale (mandatory)
		// ApplicationDescription.ApplicationName.Text (mandatory)
		//
		// --------------------------------------------------------------------
		// --------------------------------------------------------------------
		ApplicationDescription::SPtr applicationDescriptionSPtr = sessionSPtr->applicationDescription();

		if (childConfig->getConfigParameter("ApplicationDescription.ApplicationUri", stringValue) == false) {
			Log(Error, "mandatory parameter not found in configuration")
				.parameter("ConfigurationFileName", configurationFileName)
				.parameter("ParameterPath", configPrefix)
				.parameter("ParameterName", "ApplicationDescription.ApplicationUri");
			return false;
		}
		applicationDescriptionSPtr->applicationUri(stringValue);

		if (childConfig->getConfigParameter("ApplicationDescription.ProductUri", stringValue) == false) {
			Log(Error, "mandatory parameter not found in configuration")
				.parameter("ConfigurationFileName", configurationFileName)
				.parameter("ParameterPath", configPrefix)
				.parameter("ParameterName", "ApplicationDescription.ProductUri");
			return false;
		}
		applicationDescriptionSPtr->productUri(stringValue);

		std::string applicationNameLocale;
		std::string applicationNameText;

		if (childConfig->getConfigParameter("ApplicationDescription.ApplicationName.Locale", applicationNameLocale) == false) {
			Log(Error, "mandatory parameter not found in configuration")
				.parameter("ConfigurationFileName", configurationFileName)
				.parameter("ParameterPath", configPrefix)
				.parameter("ParameterName", "ApplicationDescription.ApplicationName.Locale");
			return false;
		}

		if (childConfig->getConfigParameter("ApplicationDescription.ApplicationName.Text", applicationNameText) == false) {
			Log(Error, "mandatory parameter not found in configuration")
				.parameter("ConfigurationFileName", configurationFileName)
				.parameter("ParameterPath", configPrefix)
				.parameter("ParameterName", "ApplicationDescription.ApplicationName.Text");
			return false;
		}

		applicationDescriptionSPtr->applicationName().set(applicationNameLocale, applicationNameText);

		applicationDescriptionSPtr->applicationType(ApplicationType_Client);

		return true;
	}

}