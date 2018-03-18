/*
   Copyright 2018 Kai Huebl (kai@huebl-sgh.de)

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

#include <OpcUaStackServer/Server/ServerInfo.h>
#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackCore/Base/ConfigXml.h"


using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	ServerInfo::ServerInfo(void)
	{
	}

	ServerInfo::~ServerInfo(void)
	{
	}

	bool
	ServerInfo::parse(Config* cfg, const std::string& prefix)
	{
		// get server uri
		if (!cfg->getConfigParameter(prefix + ".ServerUri", serverUri_)) {
			Log(Error, "parameter not found in configuration file")
				.parameter("Parameter", prefix + ".ServerUri")
				.parameter("ConfigFileName", cfg->configFileName());
			return false;
		}

		// get server name
		if (!cfg->getConfigParameter(prefix + ".ServerName", serverName_)) {
			Log(Error, "parameter not found in configuration file")
				.parameter("Parameter", prefix + ".ServerName")
				.parameter("ConfigFileName", cfg->configFileName());
			return false;
		}

		return true;
	}

    void
	ServerInfo::serverUri(const std::string& serverUri)
    {
    	serverUri_ = serverUri;
    }

    std::string&
	ServerInfo::serverUri(void)
    {
    	return serverUri_;
    }

    void
	ServerInfo::serverName(const std::string& serverName)
    {
    	serverName_ = serverName;
    }

    std::string&
	ServerInfo::serverName(void)
    {
    	return serverName_;
    }

}
