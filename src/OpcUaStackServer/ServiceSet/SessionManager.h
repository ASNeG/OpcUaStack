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

#ifndef __OpcUaStackServer_SessionManager_h__
#define __OpcUaStackServer_SessionManager_h__

#include <future>
#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/Config.h"
#include "OpcUaStackCore/Base/Url.h"
#include "OpcUaStackCore/Certificate/ApplicationCertificate.h"
#include "OpcUaStackCore/Certificate/CryptoManager.h"
#include "OpcUaStackCore/Utility/IOThread.h"
#include "OpcUaStackCore/SecureChannel/SecureChannelServer.h"
#include "OpcUaStackServer/ServiceSet/EndpointDescriptionConfig.h"
#include "OpcUaStackServer/ServiceSet/DiscoveryService.h"
#include "OpcUaStackServer/ServiceSet/TransactionManager.h"
#include "OpcUaStackServer/ServiceSet/ChannelSessionHandleMap.h"
#include "OpcUaStackServer/ServiceSet/SessionIf.h"
#include "OpcUaStackServer/ServiceSet/DiscoveryIf.h"

namespace OpcUaStackServer
{

	class DLLEXPORT SessionManager
	: public SecureChannelServerIf
	, public SessionIf
	, public DiscoveryIf
	{
	  public:
		typedef boost::shared_ptr<SessionManager> SPtr;

		SessionManager(void);
		virtual ~SessionManager(void);

		void discoveryService(DiscoveryService::SPtr& discoveryService);
		void cryptoManager(CryptoManager::SPtr& cryptoManager);
		void transactionManager(TransactionManager::SPtr transactionManagerSPtr);
		void ioThread(IOThread* ioThread);
		void endpointDescriptionSet(EndpointDescriptionSet::SPtr& endpointDescriptionSet);
		void config(Config* config);
		void forwardGlobalSync(ForwardGlobalSync::SPtr& forwardGlobalSync);

		bool startup(void);
		bool shutdown(void);

		//- SecureChannelServerIf ---------------------------------------------
		virtual void handleConnect(SecureChannel* secureChannel);
		virtual void handleDisconnect(SecureChannel* secureChannel);
		virtual void handleMessageRequest(SecureChannel* secureChannel);

		virtual void handleEndpointOpen(const std::string& endpointUrl);
		virtual void handleEndpointClose(const std::string& endpointUrl);
		//- SecureChannelServerIf ---------------------------------------------

		//- SessionIf ---------------------------------------------------------
		virtual void responseMessage(
			ResponseHeader::SPtr& responseHeader,
			SecureChannelTransaction::SPtr& secureChannelTransaction
		);
		virtual void deleteSession(
			uint32_t authenticationToken
		);
		//- SessionIf ---------------------------------------------------------

		//- DiscoveryIf -------------------------------------------------------
		virtual void discoveryResponseMessage(
			ResponseHeader::SPtr& responseHeader,
			SecureChannelTransaction::SPtr& secureChannelTransaction
		);
		//- DiscoveryIf -------------------------------------------------------

	  private:
		void createSessionRequest(
			SecureChannel* secureChannel,
			RequestHeader::SPtr requestHeader
		);

		void activateSessionRequest(
			SecureChannel* secureChannel,
			RequestHeader::SPtr requestHeader
		);
		void errorActivateSessionRequest(
			SecureChannel* secureChannel,
			RequestHeader::SPtr requestHeader,
			OpcUaStatusCode statusCode
		);

		void closeSessionRequest(
			SecureChannel* secureChannel,
			RequestHeader::SPtr requestHeader
		);
		void errorCloseSessionRequest(
			SecureChannel* secureChannel,
			RequestHeader::SPtr requestHeader,
			OpcUaStatusCode statusCode
		);

		void cancelRequest(
			SecureChannel* secureChannel,
			RequestHeader::SPtr requestHeader
		);
		void errorCancelRequest(
			SecureChannel* secureChannel,
			RequestHeader::SPtr requestHeader,
			OpcUaStatusCode statusCode
		);

		void messageRequest(
			SecureChannel* secureChannel,
			RequestHeader::SPtr requestHeader
		);
		void errorMessageRequest(
			SecureChannel* secureChannel,
			RequestHeader::SPtr requestHeader,
			OpcUaStatusCode statusCode
		);

		void getEndpointsRequest(
			SecureChannel* secureChannel,
			RequestHeader::SPtr requestHeader
		);

		void findServersRequest(
			SecureChannel* secureChannel,
			RequestHeader::SPtr requestHeader
		);

		void registerServerRequest(
			SecureChannel* secureChannel,
			RequestHeader::SPtr requestHeader
		);

		IOThread* ioThread_;
		Config* config_;
		EndpointDescriptionSet::SPtr endpointDescriptionSet_;
		CryptoManager::SPtr cryptoManager_;

		bool shutdownFlag_;
		std::promise<bool> shutdownComplete_;
		SecureChannelServer::Map secureChannelServerMap_;
		ForwardGlobalSync::SPtr forwardGlobalSync_;

		DiscoveryService::SPtr discoveryService_;
		TransactionManager::SPtr transactionManagerSPtr_;

		ChannelSessionHandleMap channelSessionHandleMap_;
	};

}

#endif
