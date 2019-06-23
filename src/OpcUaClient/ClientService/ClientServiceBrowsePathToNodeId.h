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

#ifndef __OpcUaClient_ClientServiceBrowsePathToNodeId_h__
#define __OpcUaClient_ClientServiceBrowsePathToNodeId_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaClient/ClientService/ClientServiceBase.h"
#include "OpcUaClient/ClientService/ClientServiceManager.h"

namespace OpcUaClient
{

	class DLLEXPORT ClientServiceBrowsePathToNodeId
	: public ClientServiceBase
	{
	  public:
		typedef boost::shared_ptr<ClientServiceBrowsePathToNodeId> SPtr;

		ClientServiceBrowsePathToNodeId(void);
		virtual ~ClientServiceBrowsePathToNodeId(void);

		//- ClientServiceBrowsePathToNodeId interface ---------------------------------------
		virtual ClientServiceBase::SPtr createClientService(void);
		virtual bool run(ClientServiceManager& clientServiceManager, CommandBase::SPtr& commandBase);
		//- ClientServiceBrowsePathToNodeId interface ---------------------------------------

      private:

	};

}

#endif

