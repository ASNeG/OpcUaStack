/*
   Copyright 2017-2019 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaClient_CommandRegisterServer_h__
#define __OpcUaClient_CommandRegisterServer_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/BuildInTypes/OpcUaNodeId.h"
#include "OpcUaClient/ClientCommand/CommandBase.h"

namespace OpcUaClient
{

	class DLLEXPORT CommandRegisterServer
	: public CommandBase
	{
	  public:
		typedef boost::shared_ptr<CommandRegisterServer> SPtr;

		CommandRegisterServer(void);
		virtual ~CommandRegisterServer(void);

		//- CommandRegisterServer interface ---------------------------------------------
		virtual CommandBase::SPtr createCommand(void);
		virtual bool validateCommand(void);
		virtual bool addParameter(const std::string& parameterName, const std::string& parameterValue);
		virtual std::string help(void);
		//- CommandRegisterServer interface ---------------------------------------------

		std::string serverUri(void);
		std::string productUri(void);
		std::vector<std::string>& discoveryUrls(void);
		std::vector<std::string>& serverNames(void);
		std::string serverType(void);
		std::string gatewayServerUri(void);
		std::string semaphoreFilePath(void);
		bool isOnline(void);

	  private:
		std::string serverUri_;
		std::string productUri_;
		std::vector<std::string> discoveryUrls_;
		std::vector<std::string> serverNames_;
		std::string serverType_;
		std::string gatewayServerUri_;
		std::string semaphoreFilePath_;
		bool isOnline_;

	};

}

#endif
