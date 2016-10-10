/*
   Copyright 2015 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   Informationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Kai Huebl (kai@huebl-sgh.de)
 */

#include "OpcUaStackServer/ServiceSet/EndpointDescriptionConfig.h"
#include "OpcUaStackCore/Base/Log.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{
	bool 
	EndpointDescriptionConfig::endpointDescriptions(EndpointDescriptionArray::SPtr endpointDescriptionArray, const std::string& configPrefix, Config* childConfig, const std::string& configurationFileName)
	{
		bool rc;
		std::string stringValue;
		uint32_t uint32Value;

		boost::optional<Config> config = childConfig->getChild("OpcUaServer.Endpoints");
		if (!config) {
			Log(Error, "mandatory parameter not found in configuration")
				.parameter("ConfigurationFileName", childConfig->configFileName())
				.parameter("ParameterPath", "OpcUaServer")
				.parameter("ParameterName", "Endpoints");
			return false;
		}

		std::vector<Config>::iterator it;
		std::vector<Config> endpointDescriptionVec;
		config->getChilds("EndpointDescription", endpointDescriptionVec);
		if (endpointDescriptionVec.size() == 0) {
			Log(Error, "mandatory parameter not found in configuration")
				.parameter("ConfigurationFileName", configurationFileName)
				.parameter("ParameterPath", configPrefix)
				.parameter("ParameterName", "EndpointDescription");
			return false;
		}

		// -------------------------------------------------------------------------
		// -------------------------------------------------------------------------
		//
		// EndpointDescription
		//
		// --------------------------------------------------------------------------
		//
		// EndpointUrl - mandatory
		// ApplicationUri - mandatory
		// ProductUri - mandatory
		// ApplicationName - mandatory
		// GatewayServerUri - optional
		// DiscoveryProfileUri - optional
		// DiscoveryUrl - optional - list
		// SecurityPolicyUri - mandatory 
		//		[
		//			http://opcfoundation.org/UA/SecurityPolicy#None
		//		]
		// TransportProfileUri - mandatory
		// SecurityLevel - mandatory
		//
		// --------------------------------------------------------------------------
		// --------------------------------------------------------------------------

		uint32_t idx = 0;
		endpointDescriptionArray->resize(endpointDescriptionVec.size());
		for (it = endpointDescriptionVec.begin(); it != endpointDescriptionVec.end(); it++) {
		    Config* config = &*it; 

			EndpointDescription::SPtr endpointDescription = constructSPtr<EndpointDescription>();
			endpointDescriptionArray->set(idx, endpointDescription);
			idx++;

			if (config->getConfigParameter("EndpointUrl", stringValue) == false) {
				Log(Error, "mandatory parameter not found in configuration")
					.parameter("ConfigurationFileName", configurationFileName)
					.parameter("ParameterPath", configPrefix + std::string(".EndpointDescription"))
					.parameter("ParameterName", "EndpointUrl");
				return false;
			}
			endpointDescription->endpointUrl(stringValue);

			if (config->getConfigParameter("ApplicationUri", stringValue) == false) {
				Log(Error, "mandatory parameter not found in configuration")
					.parameter("ConfigurationFileName", configurationFileName)
					.parameter("ParameterPath", configPrefix + std::string(".EndpointDescription"))
					.parameter("ParameterName", "ApplicationUri");
				return false;
			}
			endpointDescription->applicationDescription()->applicationUri(stringValue);

			if (config->getConfigParameter("ProductUri", stringValue) == false) {
				Log(Error, "mandatory parameter not found in configuration")
					.parameter("ConfigurationFileName", configurationFileName)
					.parameter("ParameterPath", configPrefix + std::string(".EndpointDescription"))
					.parameter("ParameterName", "ProductUri");
				return false;
			}
			endpointDescription->applicationDescription()->productUri(stringValue);

			if (config->getConfigParameter("ApplicationName", stringValue) == false) {
				Log(Error, "mandatory parameter not found in configuration")
					.parameter("ConfigurationFileName", configurationFileName)
					.parameter("ParameterPath", configPrefix + std::string(".EndpointDescription"))
					.parameter("ParameterName", "ApplicationName");
				return false;
			}
			endpointDescription->applicationDescription()->applicationName().text(stringValue);

			endpointDescription->applicationDescription()->applicationType(ApplicationType_Server);

			if (config->getConfigParameter("GatewayServerUri", stringValue) == true) {
				endpointDescription->applicationDescription()->gatewayServerUri(stringValue);
			}

			if (config->getConfigParameter("DiscoveryProfileUri", stringValue) == true) {
				endpointDescription->applicationDescription()->discoveryProfileUri(stringValue);
			}

			std::vector<std::string> discoveryUrls;
			config->getValues("DiscoveryUrl", discoveryUrls);
			if (discoveryUrls.size() == 0) {
				Log(Error, "mandatory parameter not found in configuration")
					.parameter("ConfigurationFileName", configurationFileName)
					.parameter("ParameterPath", configPrefix + std::string(".EndpointDescription"))
					.parameter("ParameterName", "DiscoveryUrl");
				return false;
			}
			endpointDescription->applicationDescription()->discoveryUrls()->resize(discoveryUrls.size());
			for (std::vector<std::string>::iterator it = discoveryUrls.begin(); it != discoveryUrls.end(); it++) {
				OpcUaString::SPtr url = constructSPtr<OpcUaString>();
				*url = *it;
				endpointDescription->applicationDescription()->discoveryUrls()->push_back(url);
			}

			if (config->getConfigParameter("SecurityPolicyUri", stringValue) == false) {
				Log(Error, "mandatory parameter not found in configuration")
					.parameter("ConfigurationFileName", configurationFileName)
					.parameter("ParameterPath", configPrefix + std::string(".EndpointDescription"))
					.parameter("ParameterName", "SecurityPolicyUri");
				return false;
			}
			if (stringValue == "http://opcfoundation.org/UA/SecurityPolicy#None") {
				endpointDescription->messageSecurityMode(MessageSecurityMode_None);
				endpointDescription->securityPolicyUri(stringValue);
			}
			else {
				Log(Error, "invalid parameter in configuration")
					.parameter("ConfigurationFileName", configurationFileName)
					.parameter("ParameterPath", configPrefix + std::string(".EndpointDescription"))
					.parameter("ParameterName", "SecurityPolicyUri")
					.parameter("ParameterValue", stringValue);
				return false;
			}

			if (config->getConfigParameter("TransportProfileUri", stringValue) == false) {
				Log(Error, "mandatory parameter not found in configuration")
					.parameter("ConfigurationFileName", configurationFileName)
					.parameter("ParameterPath", configPrefix + std::string(".EndpointDescription"))
					.parameter("ParameterName", "TransportProfileUri");
				return false;
			}
			endpointDescription->transportProfileUri(stringValue);

			if (config->getConfigParameter("SecurityLevel", uint32Value) == false) {
				Log(Error, "mandatory parameter not found in configuration")
					.parameter("ConfigurationFileName", configurationFileName)
					.parameter("ParameterPath", configPrefix + std::string(".EndpointDescription"))
					.parameter("ParameterName", "SecurityLevel");
				return false;
			}
			endpointDescription->securityLevel(uint32Value);
			
			rc = userTokenPolicy(endpointDescription, configPrefix + std::string(".EndpointDescription"), config, configurationFileName);
			if (!rc) return false;
		}

		return true;
	}

	bool 
	EndpointDescriptionConfig::userTokenPolicy(EndpointDescription::SPtr endpointDescription, const std::string& configPrefix, Config* config, const std::string& configurationFileName)
	{
		// -------------------------------------------------------------------------
		// -------------------------------------------------------------------------
		//
		// UserTokenPolicy
		//
		// --------------------------------------------------------------------------
		// TokenType - mandatory
		// PolicyId - mandatory
		//		[
		//			Anonymous
		//		]
		// --------------------------------------------------------------------------
		// --------------------------------------------------------------------------
		std::string stringValue;

		std::vector<Config>::iterator it;
		std::vector<Config> userTokenPolicyVec;
		
		config->getChilds("UserTokenPolicy", userTokenPolicyVec);
		if (userTokenPolicyVec.size() == 0) {
			Log(Error, "mandatory parameter not found in configuration")
				.parameter("ConfigurationFileName", configurationFileName)
				.parameter("ParameterPath", configPrefix)
				.parameter("ParameterName", "UserTokenPolicy");
			return false;
		}

		uint32_t idx = 0;
		UserTokenPolicyArray::SPtr userTokenPolicyArray = constructSPtr<UserTokenPolicyArray>();
		userTokenPolicyArray->resize(userTokenPolicyVec.size());
		for (it = userTokenPolicyVec.begin(); it != userTokenPolicyVec.end(); it++) {
			UserTokenPolicy::SPtr userTokenPolicy = constructSPtr<UserTokenPolicy>();
			userTokenPolicyArray->set(idx, userTokenPolicy);
			idx++;

			if (it->getConfigParameter("PolicyId", stringValue) == false) {
				Log(Error, "mandatory parameter not found in configuration")
					.parameter("ConfigurationFileName", configurationFileName)
					.parameter("ParameterPath", configPrefix + std::string(".UserTokenPolicy"))
					.parameter("ParameterName", "PolicyId");
				return false;
			}
			userTokenPolicy->policyId(stringValue);

			if (it->getConfigParameter("TokenType", stringValue) == false) {
				Log(Error, "mandatory parameter not found in configuration")
					.parameter("ConfigurationFileName", configurationFileName)
					.parameter("ParameterPath", configPrefix + std::string(".UserTokenPolicy"))
					.parameter("ParameterName", "TokenType");
				return false;
			}
			if (stringValue == "Anonymous") {
				userTokenPolicy->tokenType(UserIdentityTokenType_Anonymous);
			}
			else {
				Log(Error, "invalid parameter in configuration")
					.parameter("ConfigurationFileName", configurationFileName)
					.parameter("ParameterPath", configPrefix + std::string(".UserTokenPolicy"))
					.parameter("ParameterName", "TokenType")
					.parameter("ParameterValue", stringValue);
				return false;
			}
			
		}

		endpointDescription->userIdentityTokens(userTokenPolicyArray);
		return true;
	}

}
