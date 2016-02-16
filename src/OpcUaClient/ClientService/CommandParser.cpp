
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

#include "OpcUaClient/ClientService/CommandParser.h"


namespace OpcUaClient
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// CommandParser - static
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	CommandParser::CommandFactory CommandParser::commandFactory_;

	bool
	CommandParser::addCommand(const std::string& commandName, CommandBase::SPtr commandBase)
	{
		CommandFactory::iterator it;
		it = commandFactory_.find(commandName);
		if (it != commandFactory_.end()) return false;
		commandFactory_.insert(std::make_pair(commandName, commandBase));
		return true;
	}

	CommandBase::SPtr
	CommandParser::getCommand(const std::string& commandName)
	{
		CommandFactory::iterator it;
		it = commandFactory_.find(commandName);
		if (it != commandFactory_.end()) return it->second;
		CommandBase::SPtr commandBase;
		return commandBase;
	}


	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// CommandParser
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	CommandParser::CommandParser(void)
	{
	}

	CommandParser::~CommandParser(void)
	{
	}

	bool
	CommandParser::parse(uint32_t argc, char** argv, CommandBase::Vec& commandVec)
	{
		// FIXME: todo
		return true;
	}

	bool
	CommandParser::parseCommand(uint32_t argc, char** argv, uint32_t idx)
	{
		// FIXME: todo
		return true;
	}

	bool
	CommandParser::parseSession(uint32_t argc, char** argv, uint32_t idx)
	{
		// FIXME: todo
		return true;
	}

}
