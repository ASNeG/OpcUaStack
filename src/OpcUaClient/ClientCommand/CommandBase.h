/*
   Copyright 2016-2022 Kai Huebl (kai@huebl-sgh.de)

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

#include <string>
#include <stdint.h>
#include <vector>
#include <map>

#include "OpcUaClient/ClientCommand/ParameterFlags.h"

namespace OpcUaClient
{

	class DLLEXPORT CommandBase
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
			Cmd_Read,
			Cmd_Write,
			Cmd_ReadH,
			Cmd_WriteH,
			Cmd_Delay,
			Cmd_SubscriptionStart,
			Cmd_SubscriptionStop,
			Cmd_MonitorItemStart,
			Cmd_MonitorItemStop,
			Cmd_NodeSetServer,
			Cmd_NodeSetFilter,
			Cmd_Browse,
			Cmd_Function,
			Cmd_BrowsePathToNodeId,
			Cmd_GetEndpoint,
			Cmd_FindServer,
			Cmd_RegisterServer
		} Cmd;

		CommandBase(void);
		CommandBase(Cmd cmd);
		virtual ~CommandBase(void);

		//- CommandBase interface ---------------------------------------------
		virtual SPtr createCommand(void) = 0;
		virtual bool validateCommand(void) = 0;
		virtual bool addParameter(const std::string& parameterName, const std::string& parameterValue) = 0;
		virtual std::string help(void) = 0;
		//- CommandBase interface ---------------------------------------------

		void cmd(const Cmd cmd);
		Cmd cmd(void);
		void command(const std::string& command);
		std::string& command(void);
		void session(const std::string& session);
		std::string& session(void);
		void errorMessage(const std::string& errorMessage);
		std::string& errorMessage(void);
		ParameterFlags& parameterFlags(void);

	  private:
		ParameterFlags parameterFlags_;
		Cmd cmd_;
		std::string command_;
		std::string session_;
		std::string errorMessage_;

	};

}

#endif
