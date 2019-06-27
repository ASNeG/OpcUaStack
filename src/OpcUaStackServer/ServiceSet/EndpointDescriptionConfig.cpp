/*
   Copyright 2015-2018 Kai Huebl (kai@huebl-sgh.de)

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
	EndpointDescriptionConfig::endpointDescriptions(
		EndpointDescriptionSet::SPtr endpointDescriptionSet,
		const std::string& configPrefix, Config* childConfig,
		const std::string& configurationFileName
	)
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

		for (it = endpointDescriptionVec.begin(); it != endpointDescriptionVec.end(); it++) {
		    Config* config = &*it; 

			EndpointDescription::SPtr endpointDescription = constructSPtr<EndpointDescription>();

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

			endpointDescription->applicationDescription()->applicationType(AT_Server);

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
			
			// parse user token policy
			rc = userTokenPolicy(
				endpointDescription,
				configPrefix + std::string(".EndpointDescription"),
				config,
				configurationFileName
			);
			if (!rc) return false;

			// parse security setting
			EndpointDescription::Vec endpointDescriptionVec0;
			rc = securitySetting(
				endpointDescription,
				configPrefix + std::string(".EndpointDescription"),
				config,
				configurationFileName,
				endpointDescriptionVec0
			);
			if (!rc) return false;

			EndpointDescription::Vec::iterator it;
			for (it = endpointDescriptionVec0.begin(); it != endpointDescriptionVec0.end(); it++) {
				EndpointDescription::SPtr endpointDescriptionTmp = *it;
				endpointDescriptionSet->addEndpoint(
					endpointDescriptionTmp->endpointUrl(),
					endpointDescriptionTmp
				);
			}
		}

		return true;
	}

	bool
	EndpointDescriptionConfig::securitySetting(
		EndpointDescription::SPtr endpointDescription,
		const std::string& configPrefix,
		Config* config,
		const std::string& configurationFileName,
		EndpointDescription::Vec& endpointDescriptionVec
	)
	{
		if (config->exist("SecurityPolicyUri")) {
			//
			// use Security Policy element for security
			//

			std::string stringValue;

			if (config->getConfigParameter("SecurityPolicyUri", stringValue) == false) {
				Log(Error, "mandatory parameter not found in configuration")
					.parameter("ConfigurationFileName", configurationFileName)
					.parameter("ParameterPath", configPrefix)
					.parameter("ParameterName", "SecurityPolicyUri");
				return false;
			}
			if (stringValue == "http://opcfoundation.org/UA/SecurityPolicy#None") {
				endpointDescription->messageSecurityMode(SM_None);
				endpointDescription->securityPolicyUri(stringValue);
			}
			else {
				Log(Error, "invalid parameter in configuration")
					.parameter("ConfigurationFileName", configurationFileName)
					.parameter("ParameterPath", configPrefix)
					.parameter("ParameterName", "SecurityPolicyUri")
					.parameter("ParameterValue", stringValue);
				return false;
			}

			endpointDescriptionVec.push_back(endpointDescription);

			return true;
		}

		//
		// use SecuritySetting element for security
		//
		std::vector<Config> configVec;
		config->getChilds("SecuritySetting", configVec);
		if (configVec.size() == 0) {
			Log(Error, "mandatory parameter not found in configuration")
				.parameter("ConfigurationFileName", configurationFileName)
				.parameter("ParameterPath", configPrefix)
				.parameter("ParameterName", "SecuritySetting");
			return false;
		}

		std::vector<Config>::iterator it;
		for (it = configVec.begin(); it != configVec.end(); it++) {
			EndpointDescription::SPtr endpointDescriptionTmp = constructSPtr<EndpointDescription>(*endpointDescription.get());
			std::string stringValue;

			// get security policy mode
			if ((*it).getConfigParameter("SecurityPolicyUri", stringValue) == false) {
				Log(Error, "mandatory parameter not found in configuration")
					.parameter("ConfigurationFileName", configurationFileName)
					.parameter("ParameterPath", configPrefix + std::string(".SecuritySetting"))
					.parameter("ParameterName", "SecurityPolicyUri");
				return false;
			}
			endpointDescriptionTmp->securityPolicyUri(stringValue);
			if (stringValue != "http://opcfoundation.org/UA/SecurityPolicy#None" &&
				stringValue != "http://opcfoundation.org/UA/SecurityPolicy#Basic128Rsa15" &&
				stringValue != "http://opcfoundation.org/UA/SecurityPolicy#Basic256" &&
				stringValue != "http://opcfoundation.org/UA/SecurityPolicy#Basic256Sha256"
			) {
				Log(Error, "invalid parameter in configuration")
					.parameter("ConfigurationFileName", configurationFileName)
					.parameter("ParameterPath", configPrefix + std::string(".SecuritySetting"))
					.parameter("ParameterName", "SecurityPolicyUri")
					.parameter("ParameterValue", stringValue);
				return false;
			}

			// get message security mode
			if ((*it).getConfigParameter("MessageSecurityMode", stringValue) == false) {
				Log(Error, "mandatory parameter not found in configuration")
					.parameter("ConfigurationFileName", configurationFileName)
					.parameter("ParameterPath", configPrefix + std::string(".SecuritySetting"))
					.parameter("ParameterName", "MessageSecurityMode");
				return false;
			}
			if (stringValue == "None") {
				endpointDescriptionTmp->messageSecurityMode(SM_None);

				if (endpointDescriptionTmp->securityPolicyUri() != "http://opcfoundation.org/UA/SecurityPolicy#None") {
					Log(Error, "invalid parameter in configuration")
						.parameter("ConfigurationFileName", configurationFileName)
						.parameter("ParameterPath", configPrefix + std::string(".SecuritySetting"))
						.parameter("ParameterName", "MessageSecurityMode")
						.parameter("ParameterValue", stringValue);
					return false;
				}
			}
			else if (stringValue == "Sign") {
				endpointDescriptionTmp->messageSecurityMode(SM_Sign);
			}
			else if (stringValue == "SignAndEncrypt") {
				endpointDescriptionTmp->messageSecurityMode(SM_SignAndEncrypt);
			}
			else {
				Log(Error, "invalid parameter in configuration")
					.parameter("ConfigurationFileName", configurationFileName)
					.parameter("ParameterPath", configPrefix + std::string(".SecuritySetting"))
					.parameter("ParameterName", "MessageSecurityMode")
					.parameter("ParameterValue", stringValue);
				return false;
			}

			endpointDescriptionVec.push_back(endpointDescriptionTmp);
		}

		return true;
	}

	bool 
	EndpointDescriptionConfig::userTokenPolicy(
		EndpointDescription::SPtr endpointDescription,
		const std::string& configPrefix,
		Config* config,
		const std::string& configurationFileName
	)
	{
		// -------------------------------------------------------------------------
		// -------------------------------------------------------------------------
		//
		// UserTokenPolicy
		//
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

			// get security policy uri
			it->getConfigParameter("SecurityPolicyUri", stringValue);
			userTokenPolicy->securityPolicyUri(stringValue);

			// get policy id
			if (it->getConfigParameter("PolicyId", stringValue) == false) {
				Log(Error, "mandatory parameter not found in configuration")
					.parameter("ConfigurationFileName", configurationFileName)
					.parameter("ParameterPath", configPrefix + std::string(".UserTokenPolicy"))
					.parameter("ParameterName", "PolicyId");
				return false;
			}
			userTokenPolicy->policyId(stringValue);

			// get token type
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
			else if (stringValue == "Username") {
				userTokenPolicy->tokenType(UserIdentityTokenType_Username);
			}
			else if (stringValue == "Certificate") {
				userTokenPolicy->tokenType(UserIdentityTokenType_Certificate);
			}
			else if (stringValue == "IssuedToken") {
				userTokenPolicy->tokenType(UserIdentityTokenType_IssuedToken);
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
