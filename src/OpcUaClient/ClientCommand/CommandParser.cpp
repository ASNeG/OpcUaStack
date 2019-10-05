
/*
   Copyright 2016-2019 Kai Huebl (kai@huebl-sgh.de)

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

#include <boost/algorithm/string.hpp>
#include <boost/filesystem.hpp>
#include <iostream>
#include <sstream>
#include "OpcUaStackCore/Base/ConfigXml.h"
#include "OpcUaStackCore/Utility/Environment.h"
#include "OpcUaClient/ClientCommand/CommandParser.h"

using namespace OpcUaStackCore;

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
	: actualCommandBase_()
	, session_("OpcUaClient")
	, configFileName_("")
	, config_(nullptr)
	{
	}

	CommandParser::~CommandParser(void)
	{
	}

	bool
	CommandParser::parse(uint32_t argc, char** argv, CommandBase::Vec& commandBaseVec)
	{
		// check number of parameters in command line
		if (argc < 2) {
			errorString("command must have at least one parameter");
			return false;
		}

		// The first parameter can be a configuration file
		uint32_t startPos = 1;
		if (argv[startPos][0] != '-') {
			configFileName_ = argv[1];
			startPos++;

			// check number of parameters in command line
			if (argc < 3) {
				errorString("command must have at least one parameter");
				return false;
			}
		}

		// read configuration file
		if (!readConfigFile()) {
			errorString("read configuration file error");
			return false;
		}

		// check first parameter
		std::string para = argv[startPos];
		boost::algorithm::trim(para);
		if (
		    boost::algorithm::to_upper_copy(para) != "-COMMAND" &&
		    boost::algorithm::to_upper_copy(para) != "-HELP" &&
		    boost::algorithm::to_upper_copy(para) != "-H"
		) {
			errorString("first parameter must be a command or help");
			return false;
		}

		// read all parameters from command line
		bool parseParameter = false;
		for (uint32_t idx=startPos; idx<argc; idx++) {
			std::string para = argv[idx];
			boost::algorithm::trim(para);

			//std::cout << "Para:" << para << std::endl;

			// command parameter
			if (boost::algorithm::to_upper_copy(para) == "-COMMAND") {
				if (!parseCommand(argc, argv, idx)) return false;
				idx++;
				commandBaseVec.push_back(actualCommandBase_);
			}

			// session parameter
			else if (boost::algorithm::to_upper_copy(para) == "-SESSION") {
				if (!parseSession(argc, argv, idx)) return false;
				idx++;
			}

			// help
			else if (boost::algorithm::to_upper_copy(para) == "-HELP" ||
					boost::algorithm::to_upper_copy(para) == "-H") {
				help("");
				exit(1);
			}

			// other parameter
			else {
				if (!this->parseParameter(argc, argv, idx)) return false;
				idx++;
			}
		}

		if (!validateCommand()) return false;

		return true;
	}

	bool
	CommandParser::validateCommand(void)
	{
		if (actualCommandBase_.get() != NULL) {
			if (!actualCommandBase_->validateCommand()) {
				std::stringstream ss;
				ss << "command " << actualCommandBase_->command() << " error: "
				   << actualCommandBase_->errorMessage();
				errorString(ss.str());
				return false;
			}
		}
		return true;
	}

	bool
	CommandParser::parseCommand(uint32_t argc, char** argv, uint32_t idx)
	{
		// The last command was completely read. The parameters are now checked.
		if (!validateCommand()) return false;

		// check number of parameters in command line
		if (idx+1 >= argc) {
			errorString("command parameter requires an additional parameter");
			return false;
		}

		// get parameter value (command name)
		std::string value = argv[idx+1];
		boost::algorithm::trim(value);
		boost::algorithm::to_upper(value);

		// find factory element
		CommandBase::SPtr commandBase;
		commandBase = getCommand(value);
		if (commandBase.get() == NULL) {
			std::stringstream ss;
			ss << "the command " << value << " is unknown";
			errorString(ss.str());
			return false;
		}

		// create new command
		actualCommandBase_ = commandBase->createCommand();
		if (actualCommandBase_.get() == NULL) {
			std::stringstream ss;
			ss << "internal error, because cannot create the command " << value;
			errorString(ss.str());
			return false;
		}

		actualCommandBase_->session(session_);
		actualCommandBase_->command(value);
		return true;
	}

	bool
	CommandParser::parseSession(uint32_t argc, char** argv, uint32_t idx)
	{
		// check number of parameters in command line
		if (idx+1 >= argc) {
			errorString("session parameter requires an additional parameter");
			return false;
		}

		// get parameter value (session name)
		std::string value = argv[idx+1];
		boost::algorithm::trim(value);

		session_ = value;
		actualCommandBase_->session(value);
		return true;
	}

	bool
	CommandParser::parseParameter(uint32_t argc, char** argv, uint32_t idx)
	{
		// get parameter name (command)
		std::string para = argv[idx];
		boost::algorithm::trim(para);
		boost::algorithm::to_upper(para);

		// check number of parameters in command line
		if (idx+1 >= argc) {
			std::stringstream ss;
			ss << "parameter " << para << " requires an additional parameter";
			errorString(ss.str());
			return false;
		}

		// get parameter value (command name)
		std::string value = argv[idx+1];
		boost::algorithm::trim(value);
		boost::algorithm::to_upper(para);

		if (!actualCommandBase_->addParameter(para, value)) {
			std::stringstream ss;
			ss << "cannot add parameter " << para << " in command " << actualCommandBase_->command() << ": " ;
			ss << actualCommandBase_->errorMessage();
			errorString(ss.str());
			return false;
		}
		return true;
	}

	bool
	CommandParser::readConfigFile(void)
	{
		config_ = Config::instance();

		// set configuration alias names
		auto configFileName = configFileName_;
		if (configFileName_.empty()) {
			configFileName = "./";
		}
		std::string configFilePath = boost::filesystem::path(configFileName).parent_path().string();
		Environment::confDir(configFilePath);

		config_->alias("@CONF_DIR@", Environment::confDir());
		config_->alias("@HOSTNAME@", Environment::hostname());

		// check if configuration file name exist
		if (configFileName_.empty()) {
			return true;
		}

		// read configuration file
		ConfigXml configXml;
		if (!configXml.parse(configFileName_, true)) {
			std::stringstream ss;
			ss << "read configuration error: " << configXml.errorMessage();
			errorString(ss.str());
			return false;
		}

		return true;
	}

	void
	CommandParser::help(const std::string& command)
	{
		std::cout
		  << "OpcUaClient [<ConfigFile>] (-help [<CommandName>]) | (-Command <CommandName> [-<ParameterName> <ParameterVariable>]*)*\n"
		  << "\n"
		  << "Commands:\n";

		CommandFactory::iterator it;
		for (it = commandFactory_.begin(); it != commandFactory_.end();  it++) {
			std::cout << std::endl;
			std::cout << it->second->help();
		}

		std::cout << std::endl;
	}

	void
	CommandParser::errorString(const std::string& errorString)
	{
		errorString_ = errorString;
	}

	std::string&
	CommandParser::errorString(void)
	{
		return errorString_;
	}

	std::string
	CommandParser::configFileName(void)
	{
		return configFileName_;
	}

	Config*
	CommandParser::config(void)
	{
		return config_;
	}

}
