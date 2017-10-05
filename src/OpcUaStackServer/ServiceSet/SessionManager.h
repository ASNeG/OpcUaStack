/*
   Copyright 2017 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackServer_SessionManager_h__
#define __OpcUaStackServer_SessionManager_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/Config.h"
#include "OpcUaStackCore/Base/Url.h"
#include "OpcUaStackCore/Base/ConditionProcess.h"
#include "OpcUaStackCore/Utility/IOThread.h"
#include "OpcUaStackCore/SecureChannel/SecureChannelServer.h"
#include "OpcUaStackServer/ServiceSet/EndpointDescriptionConfig.h"
#include "OpcUaStackServer/ServiceSet/DiscoveryService.h"
#include "OpcUaStackServer/ServiceSet/TransactionManager.h"
#include "OpcUaStackServer/ServiceSet/ChannelSessionHandleMap.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	class DLLEXPORT SessionManager
	: public SecureChannelServerIf
	, public DiscoveryManagerIf
	{
	  public:
		typedef boost::shared_ptr<SessionManager> SPtr;

		SessionManager(void);
		virtual ~SessionManager(void);

		void discoveryService(DiscoveryService::SPtr& discoveryService);
		void transactionManager(TransactionManager::SPtr transactionManagerSPtr);
		void ioThread(IOThread* ioThread);
		void endpointDescriptionArray(EndpointDescriptionArray::SPtr& endpointDescriptionArray);
		void config(Config* config);

		bool startup(void);
		bool shutdown(void);

		//- SecureChannelServerIf ---------------------------------------------
		virtual void handleConnect(SecureChannel* secureChannel);
		virtual void handleDisconnect(SecureChannel* secureChannel);
		virtual void handleMessageRequest(SecureChannel* secureChannel);

		virtual void handleEndpointOpen(void);
		virtual void handleEndpointClose(void);
		//- SecureChannelServerIf ---------------------------------------------

		//- DiscoveryManagerIf ------------------------------------------------
		void discoveryMessage(SecureChannelTransactionOld::SPtr secureChannelTransaction);
		//- DiscoveryManagerIf ------------------------------------------------

	  private:
		bool getSecureChannelServerConfig(
			SecureChannelServerConfig::SPtr& secureChannelServerConfig,
			EndpointDescription::SPtr& endpointDescription
		);

		IOThread* ioThread_;
		Config* config_;
		EndpointDescriptionArray::SPtr endpointDescriptionArray_;

		ConditionProcess secureChannelServerShutdown_;
		SecureChannelServerConfig::SPtr secureChannelServerConfig_;
		SecureChannelServer::SPtr secureChannelServer_;

		DiscoveryService::SPtr discoveryService_;
		TransactionManager::SPtr transactionManagerSPtr_;

		ChannelSessionHandleMap channelSessionHandleMap_;
	};

}

#endif
