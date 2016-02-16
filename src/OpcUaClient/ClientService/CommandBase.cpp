
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

#include "OpcUaClient/ClientService/CommandBase.h"


namespace OpcUaClient
{

	CommandBase::CommandBase(void)
	: cmd_(Cmd_Unknown)
	, session_("Main")
	, errorMessage_()
	, parameterFlags_()
	{
	}

	CommandBase::CommandBase(Cmd cmd)
	: cmd_(cmd)
	, session_("Main")
	{
	}

	CommandBase::~CommandBase(void)
	{
	}

	void
	CommandBase::cmd(const Cmd cmd)
	{
		cmd_ = cmd;
	}

	CommandBase::Cmd
	CommandBase::cmd(void)
	{
		return cmd_;
	}

	void
	CommandBase::command(const std::string& command)
	{
		command_ = command;
	}

	std::string&
	CommandBase::command(void)
	{
		return command_;
	}

	void
	CommandBase::session(const std::string& session)
	{
		session_ = session;
	}

	std::string&
	CommandBase::session(void)
	{
		return session_;
	}

	void
	CommandBase::errorMessage(const std::string& errorMessage)
	{
		errorMessage_ = errorMessage;
	}

	std::string&
	CommandBase::errorMessage(void)
	{
		return errorMessage_;
	}

	ParameterFlags&
	CommandBase::parameterFlags(void)
	{
		return parameterFlags_;
	}

}
