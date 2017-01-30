/*
   Copyright 2015-2017 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackServer_Server_h__
#define __OpcUaStackServer_Server_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/IOService.h"
#include "OpcUaStackCore/Core/Core.h"
#include "OpcUaStackServer/InformationModel/InformationModel.h"
#include "OpcUaStackServer/ServiceSet/SessionManagerOld.h"
#include "OpcUaStackServer/ServiceManager/ServiceManager.h"
#include "OpcUaStackServer/Application/ApplicationManager.h"
#include "OpcUaStackServer/Server/ServerStatusDataType.h"

namespace OpcUaStackServer
{

	class DLLEXPORT Server 
	: public OpcUaStackCore::Core
	{
	  public:
	    Server(void);
	    ~Server(void);

		bool init(void);
		bool shutdown(void);
		bool start(void);
		void stop(void);

		InformationModel::SPtr getInformationModel(void);
		IOService* ioService(void);
		ApplicationManager& applicationManager(void);
		ServiceManager& serviceManager(void);

	  private:
		bool readInformationModel(void);
		bool writeInformationModel(const std::string& nodeSetFileName, std::vector<std::string>& namespaceUris);
		bool initInformationModel(void);
		bool shutdownInformationModel(void);
		bool initService(void);
		bool shutdownService(void);
		bool initSession(void);
		bool shutdownSession(void);

		IOService ioService_;
		InformationModel::SPtr informationModel_;
		SessionManagerOld sessionManager_;
		ServiceManager serviceManager_;
		ApplicationManager applicationManager_;

		ServerStatusDataType serverStatusDataType_;
	};

}

#endif
