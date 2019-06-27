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

#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackCore/Base/Config.h"
#include "OpcUaStackServer/ServiceSet/SessionConfig.h"
#include "OpcUaStackServer/ServiceSet/EndpointDescriptionConfig.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

#if 0
	bool 
	SessionConfig::initial(SessionOld::SPtr sessionSPtr, const std::string& configPrefix, Config* config)
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
		EndpointDescriptionArray::SPtr endpointDescriptionArray = constructSPtr<EndpointDescriptionArray>();

		if (!EndpointDescriptionConfig::endpointDescriptions(endpointDescriptionArray, configPrefix, config, config->configFileName())) {
			return false;
		}

		sessionSPtr->endpointDescriptionArray(endpointDescriptionArray);

		return true;
	}
#endif
}
