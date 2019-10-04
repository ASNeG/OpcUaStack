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

#ifndef __OpcUaClient_CommandParser_h__
#define __OpcUaClient_CommandParser_h__

#include "OpcUaStackCore/Base/Config.h"
#include "OpcUaClient/ClientCommand/CommandBase.h"

namespace OpcUaClient
{

	class DLLEXPORT CommandParser
	{
	  public:
		typedef CommandBase::Map CommandFactory;
		static CommandFactory commandFactory_;
		static bool addCommand(const std::string& commandName, CommandBase::SPtr commandBase);
		static CommandBase::SPtr getCommand(const std::string& commandName);

		CommandParser(void);
		~CommandParser(void);

		bool parse(uint32_t argc, char** argv, CommandBase::Vec& commandBaseVec);
		void errorString(const std::string& errorString);
		std::string& errorString(void);
		std::string configFileName(void);
		OpcUaStackCore::Config* config(void);

	  private:
		bool validateCommand(void);
		bool parseCommand(uint32_t argc, char** argv, uint32_t idx);
		bool parseSession(uint32_t argc, char** argv, uint32_t idx);
		bool parseParameter(uint32_t argc, char** argv, uint32_t idx);
		bool readConfigFile(void);
		void help(const std::string& command);

		std::string errorString_;
		CommandBase::SPtr actualCommandBase_;
		std::string session_;
		std::string configFileName_;
		OpcUaStackCore::Config* config_;

	};

}

#endif
