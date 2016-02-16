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

#ifndef __OpcUaClient_CommandBase_h__
#define __OpcUaClient_CommandBase_h__

#include <boost/shared_ptr.hpp>
#include <stdint.h>
#include <vector>
#include <map>

namespace OpcUaClient
{

	class CommandBase
	{
	  public:
		typedef boost::shared_ptr<CommandBase> SPtr;
		typedef std::vector<CommandBase::SPtr> Vec;
		typedef std::map<std::string, CommandBase::SPtr> Map;
		typedef enum
		{
			Cmd_Unknown,
			Cmd_Connect,
			Cmd_Disconnect,
		} Cmd;

		CommandBase(void);
		CommandBase(Cmd cmd);
		virtual ~CommandBase(void);

		//- CommandBase interface ---------------------------------------------
		virtual SPtr createCommand(void) = 0;
		virtual bool validateCommand(void) = 0;
		virtual bool addParameter(uint32_t argc, char** argv, uint32_t idx) = 0;
		//- CommandBase interface ---------------------------------------------

		void cmd(const Cmd cmd);
		Cmd cmd(void);
		void session(const std::string& session);
		std::string& session(void);
		void errorMessage(const std::string& errorMessage);
		std::string& errorMessage(void);

	  private:
		Cmd cmd_;
		std::string session_;
		std::string errorMessage_;

	};

}

#endif
