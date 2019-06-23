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

#ifndef __OpcUaClient_ClientServiceManager_h__
#define __OpcUaClient_ClientServiceManager_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaClient/ClientService/ClientAccessObject.h"

namespace OpcUaClient
{

	class DLLEXPORT ClientServiceManager
	{
	  public:
		typedef boost::shared_ptr<ClientServiceManager> SPtr;

		ClientServiceManager(void);
		~ClientServiceManager(void);

		ClientAccessObject::SPtr getClientAccessObject(const std::string& clientAccessObjectName);
		ClientAccessObject::SPtr createClientAccessObject(const std::string& clientAccessObjectName);
		ClientAccessObject::SPtr getOrCreateClientAccessObject(const std::string& clientAccessObjectName);

	  private:
		ClientAccessObject::Map clientAccessObjectMap_;
	};

}

#endif

