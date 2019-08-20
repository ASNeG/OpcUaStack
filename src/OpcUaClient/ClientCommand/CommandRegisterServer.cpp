
/*
   Copyright 2017 Kai Huebl (kai@huebl-sgh.de)

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

#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string.hpp>
#include <sstream>

#include "OpcUaClient/ClientCommand/CommandRegisterServer.h"

using namespace OpcUaStackCore;

namespace OpcUaClient
{

	CommandRegisterServer::CommandRegisterServer(void)
	: CommandBase(CommandBase::Cmd_RegisterServer)
	, serverUri_("")
	, productUri_("")
	, discoveryUrls_()
	, serverNames_()
	, serverType_("Server")
	, gatewayServerUri_("")
	, semaphoreFilePath_("")
	, isOnline_(true)
	{
	}

	CommandRegisterServer::~CommandRegisterServer(void)
	{
	}

	CommandBase::SPtr
	CommandRegisterServer::createCommand(void)
	{
		CommandBase::SPtr commandBase = boost::make_shared<CommandRegisterServer>();
		return commandBase;
	}

	bool
	CommandRegisterServer::validateCommand(void)
	{
		if (serverUri_.empty()) {
			std::stringstream ss;
			ss << "need server uri parameter";
			errorMessage(ss.str());
			return false;
		}

		if (productUri_.empty()) {
			std::stringstream ss;
			ss << "need product uri parameter";
			errorMessage(ss.str());
			return false;
		}

		if (discoveryUrls_.empty()) {
			std::stringstream ss;
			ss << "need discovery url parameter";
			errorMessage(ss.str());
			return false;
		}

		if (serverNames_.empty()) {
			std::stringstream ss;
			ss << "need server name parameter";
			errorMessage(ss.str());
			return false;
		}

		return true;
	}

	bool
	CommandRegisterServer::addParameter(const std::string& parameterName, const std::string& parameterValue)
	{
		if (parameterName == "-SERVERURI") {
			serverUri_ = parameterValue;
		}
		else if (parameterName == "-PRODUCTURI") {
			productUri_ = parameterValue;
		}
		else if (parameterName == "-DISCOVERYURL") {
			discoveryUrls_.push_back(parameterValue);
		}
		else if (parameterName == "-SERVERNAME") {
			serverNames_.push_back(parameterValue);
		}
		else if (parameterName == "-SERVERTYPE") {
			serverType_ = boost::algorithm::to_upper_copy(parameterValue);
			if (serverType_ != "CLIENT" && serverType_ != "SERVER" && serverType_ != "CLIENTSERVER") {
				std::stringstream ss;
				ss << "invalid server type parameter";
				errorMessage(ss.str());
				return false;
			}
		}
		else if (parameterName == "-GATEWAYSERVERURI") {
			gatewayServerUri_ = parameterValue;
		}
		else if (parameterName == "-SEMPAHOREFILEPATH") {
			semaphoreFilePath_ = parameterValue;
		}
		else if (parameterName == "-ISONLINE") {
			if (parameterValue == "0") {
				isOnline_ = false;
			}
		}
		else {
			std::stringstream ss;
			ss << "invalid parameter " << parameterName;
			errorMessage(ss.str());
			return false;
		}
		return true;
	}

	std::string
	CommandRegisterServer::help(void)
	{
		std::stringstream ss;
		ss << "  -RegisterServer: register application description on opc ua discovery server\n"
		   << "    -ServerUri (1): server uri\n"
		   << "    -ProductUri (1): product uri\n"
		   << "    -DiscoveryUrl (1..N): discovery url\n"
		   << "    -ServerName (1..N): server name\n"
		   << "    -ServerType (0..1): server type [Client, Server, ClientServer]\n"
		   << "    -GatewayServerUri (0..1): gateway server uri\n"
		   << "    -SemaphoreFilePath (0..1): semaphore file path\n"
		   << "    -IsOnline (0..1): online flag [0,1]\n";
		return ss.str();
	}

	std::string
	CommandRegisterServer::serverUri(void)
	{
		return serverUri_;
	}

	std::string
	CommandRegisterServer::productUri(void)
	{
		return productUri_;
	}

	std::vector<std::string>&
	CommandRegisterServer::discoveryUrls(void)
	{
		return discoveryUrls_;
	}

	std::vector<std::string>&
	CommandRegisterServer::serverNames(void)
	{
		return serverNames_;
	}

	std::string
	CommandRegisterServer::serverType(void)
	{
		return serverType_;
	}

	std::string
	CommandRegisterServer::gatewayServerUri(void)
	{
		return gatewayServerUri_;
	}

	std::string
	CommandRegisterServer::semaphoreFilePath(void)
	{
		return semaphoreFilePath_;
	}

	bool
	CommandRegisterServer::isOnline(void)
	{
		return isOnline_;
	}

}
