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

#ifndef __OpcUaClient_ClientServiceExecute_h__
#define __OpcUaClient_ClientServiceExecute_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaClient/ClientCommand/CommandBase.h"
#include "OpcUaClient/ClientService/ClientServiceBase.h"
#include "OpcUaClient/ClientService/ClientServiceManager.h"

namespace OpcUaClient
{

	class DLLEXPORT ClientServiceExecute
	{
	  public:
		typedef ClientServiceBase::Map ClientServiceFactory;
		static ClientServiceFactory clientServiceFactory_;
		static bool addClientService(uint32_t command, ClientServiceBase::SPtr clientServiceBase);
		static ClientServiceBase::SPtr getClientService(uint32_t command);

		ClientServiceExecute(void);
		~ClientServiceExecute(void);

		bool run(CommandBase::Vec& commandBaseVec);

		void errorString(const std::string& errorString);
		std::string& errorString(void);

	  private:
		std::string errorString_;
		ClientServiceManager clientServiceManager_;
	};

}

#endif

