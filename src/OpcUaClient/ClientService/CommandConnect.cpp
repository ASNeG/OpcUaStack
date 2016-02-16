
/*
   Copyright 2016 Kai Huebl (kai@huebl-sgh.de)

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

#include <sstream>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaClient/ClientService/CommandConnect.h"

using namespace OpcUaStackCore;

namespace OpcUaClient
{

	CommandConnect::CommandConnect(void)
	: CommandBase(CommandBase::Cmd_Connect)
	, endpointUrl_("opc.tcp://127.0.0.1:4841")
	{
	}

	CommandConnect::~CommandConnect(void)
	{
	}

	CommandBase::SPtr
	CommandConnect::createCommand(void)
	{
		CommandBase::SPtr commandBase = constructSPtr<CommandConnect>();
		return commandBase;
	}

	bool
	CommandConnect::validateCommand(void)
	{
		return true;
	}

	bool
	CommandConnect::addParameter(const std::string& parameterName, const std::string& parameterValue)
	{
		if (parameterName == "-ENDPOINTURL") endpointUrl_ = parameterValue;
		else {
			std::stringstream ss;
			ss << "invalid parameter " << parameterName;
			errorMessage(ss.str());
			return false;
		}
		return true;
	}

	std::string&
	CommandConnect::endpointUrl(void)
	{
		return endpointUrl_;
	}

}
