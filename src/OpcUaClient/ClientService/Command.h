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

#ifndef __OpcUaClient_Command_h__
#define __OpcUaClient_Command_h__

#include <boost/shared_ptr.hpp>
#include <vector>
#include <stdint.h>
#include <sstream>

namespace OpcUaClient
{

	class Command
	{
	  public:
		typedef boost::shared_ptr<Command> SPtr;
		typedef std::vector<Command::SPtr> Vec;

		typedef enum
		{
			Cmd_Unknown,
			Cmd_Connect,
			Cmd_Disconnect,
		} Cmd;

		Command(void);
		~Command(void);

		static std::stringstream errorString_;
		static Command::SPtr actualCommand_;
		static std::string actualSession_;
		static bool parse(uint32_t argc, char** argv, Command::Vec& commandVec);
		static bool parseCommand(uint32_t argc, char** argv, uint32_t idx);
		static bool parseSession(uint32_t argc, char** argv, uint32_t idx);

		void cmd(const Cmd cmd);
		Cmd cmd(void);
		void session(const std::string& session);
		std::string& session(void);

	  private:
		Cmd cmd_;
		std::string session_;
	};

}

#endif
