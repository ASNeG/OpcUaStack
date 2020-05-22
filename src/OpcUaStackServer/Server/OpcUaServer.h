/*
   Copyright 2015-2020 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackServer_OpcUaServer_h__
#define __OpcUaStackServer_OpcUaServer_h__

#include <OpcUaStackCore/Certificate/ApplicationCertificate.h>
#include "OpcUaStackCore/Utility/IOThread.h"
#include "OpcUaStackCore/MessageBus/MessageBus.h"
#include "OpcUaStackCore/Core/Core.h"
#include "OpcUaStackServer/InformationModel/InformationModel.h"
#include "OpcUaStackServer/ServiceSet/SessionManager.h"
#include "OpcUaStackServer/ServiceManager/ServiceManager.h"
#include "OpcUaStackServer/Application/ApplicationManager.h"
#include "OpcUaStackServer/Server/ServerStatusDataType.h"
#include "OpcUaStackServer/Server/ServerInfo.h"

namespace OpcUaStackServer
{

	class DLLEXPORT OpcUaServer
	: public OpcUaStackCore::Core
	{
	  public:
	    OpcUaServer(void);
	    ~OpcUaServer(void);

		bool startup(void);
		bool shutdown(void);
		bool start(void);
		void stop(void);

		InformationModel::SPtr getInformationModel(void);
		OpcUaStackCore::IOThread::SPtr ioThread(void);
		OpcUaStackCore::MessageBus::SPtr messageBus(void);
		ApplicationManager& applicationManager(void);
		ServiceManager& serviceManager(void);
		OpcUaStackCore::CryptoManager::SPtr& cryptoManager(void);

	  private:
		bool readInformationModel(void);
		bool writeInformationModel(const std::string& nodeSetFileName, std::vector<std::string>& namespaceUris);
		bool initInformationModel(void);
		bool shutdownInformationModel(void);
		bool initOpcUaServer(void);
		bool initCrypto(void);
		bool initServiceManager(void);
		bool shutdownServiceManager(void);
		bool initSessionManager(void);
		bool shutdownSessionManager(void);
		bool initApplication(void);

		OpcUaStackCore::EndpointDescriptionSet::SPtr endpointDescriptionSet_;

		OpcUaStackCore::IOThread::SPtr ioThread_ = nullptr;
		OpcUaStackCore::MessageBus::SPtr messageBus_ = nullptr;
		OpcUaStackCore::CryptoManager::SPtr cryptoManager_ = nullptr;

		ServiceManager serviceManager_;
		InformationModel::SPtr informationModel_;
		SessionManager sessionManager_;
		ApplicationManager applicationManager_;
		ServerInfo serverInfo_;

		ServerStatusDataType serverStatusDataType_;
	};

}

#endif
