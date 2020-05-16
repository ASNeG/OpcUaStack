/*
   Copyright 2017-2020 Kai Huebl (kai@huebl-sgh.de)

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
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/Config.h"
#include "OpcUaStackCore/Base/Url.h"
#include "OpcUaStackCore/Certificate/ApplicationCertificate.h"
#include "OpcUaStackCore/Certificate/CryptoManager.h"
#include "OpcUaStackCore/Utility/IOThread.h"
#include "OpcUaStackCore/SecureChannel/SecureChannelServer.h"
#include "OpcUaStackCore/MessageBus/MessageBus.h"
#include "OpcUaStackServer/ServiceSet/EndpointDescriptionConfig.h"
#include "OpcUaStackServer/ServiceSet/TransactionManager.h"
#include "OpcUaStackServer/ServiceSet/ChannelSessionHandleMap.h"
#include "OpcUaStackServer/ServiceSet/SessionIf.h"

namespace OpcUaStackServer
{

	class DLLEXPORT SessionManager
	: public OpcUaStackCore::SecureChannelServerIf
	, public SessionIf
	{
	  public:
		using SPtr = boost::shared_ptr<SessionManager>;
		using DiscoveryRequestCallback = std::function<
			void
			(
				OpcUaStackCore::RequestHeader::SPtr& requestHeader,
				OpcUaStackCore::SecureChannelTransaction::SPtr secureChannelTransaction
			)
		>;

		SessionManager(void);
		virtual ~SessionManager(void);

		void getEndpointRequestCallback(const DiscoveryRequestCallback& getEndpointRequestCallback);
		void findServersRequestCallback(const DiscoveryRequestCallback& findServerRequestCallback);
		void registerServerRequestCallback(const DiscoveryRequestCallback& registerServerRequestCallback);

		void cryptoManager(OpcUaStackCore::CryptoManager::SPtr& cryptoManager);
		void transactionManager(TransactionManager::SPtr transactionManagerSPtr);
		void ioThread(OpcUaStackCore::IOThread* ioThread);
		void messageBus(OpcUaStackCore::MessageBus::SPtr& messageBus);
		void endpointDescriptionSet(OpcUaStackCore::EndpointDescriptionSet::SPtr& endpointDescriptionSet);
		void config(OpcUaStackCore::Config* config);
		void forwardGlobalSync(OpcUaStackCore::ForwardGlobalSync::SPtr& forwardGlobalSync);

		bool startup(void);
		bool shutdown(void);

		//- SecureChannelServerIf ---------------------------------------------
		virtual void handleConnect(OpcUaStackCore::SecureChannel* secureChannel);
		virtual void handleDisconnect(OpcUaStackCore::SecureChannel* secureChannel);
		virtual void handleMessageRequest(OpcUaStackCore::SecureChannel* secureChannel);

		virtual void handleEndpointOpen(const std::string& endpointUrl);
		virtual void handleEndpointClose(const std::string& endpointUrl);
		//- SecureChannelServerIf ---------------------------------------------

		//- SessionIf ---------------------------------------------------------
		virtual void responseMessage(
			OpcUaStackCore::ResponseHeader::SPtr& responseHeader,
			OpcUaStackCore::SecureChannelTransaction::SPtr& secureChannelTransaction
		);
		virtual void deleteSession(
			uint32_t authenticationToken
		);
		//- SessionIf ---------------------------------------------------------

	  private:
		void createSessionRequest(
			OpcUaStackCore::SecureChannel* secureChannel,
			OpcUaStackCore::RequestHeader::SPtr requestHeader
		);

		void activateSessionRequest(
			OpcUaStackCore::SecureChannel* secureChannel,
			OpcUaStackCore::RequestHeader::SPtr requestHeader
		);
		void errorActivateSessionRequest(
			OpcUaStackCore::SecureChannel* secureChannel,
			OpcUaStackCore::RequestHeader::SPtr requestHeader,
			OpcUaStackCore::OpcUaStatusCode statusCode
		);

		void closeSessionRequest(
			OpcUaStackCore::SecureChannel* secureChannel,
			OpcUaStackCore::RequestHeader::SPtr requestHeader
		);
		void errorCloseSessionRequest(
			OpcUaStackCore::SecureChannel* secureChannel,
			OpcUaStackCore::RequestHeader::SPtr requestHeader,
			OpcUaStackCore::OpcUaStatusCode statusCode
		);

		void cancelRequest(
			OpcUaStackCore::SecureChannel* secureChannel,
			OpcUaStackCore::RequestHeader::SPtr requestHeader
		);
		void errorCancelRequest(
			OpcUaStackCore::SecureChannel* secureChannel,
			OpcUaStackCore::RequestHeader::SPtr requestHeader,
			OpcUaStackCore::OpcUaStatusCode statusCode
		);

		void messageRequest(
			OpcUaStackCore::SecureChannel* secureChannel,
			OpcUaStackCore::RequestHeader::SPtr requestHeader
		);
		void errorMessageRequest(
			OpcUaStackCore::SecureChannel* secureChannel,
			OpcUaStackCore::RequestHeader::SPtr requestHeader,
			OpcUaStackCore::OpcUaStatusCode statusCode
		);

		void getEndpointsRequest(
			OpcUaStackCore::SecureChannel* secureChannel,
			OpcUaStackCore::RequestHeader::SPtr requestHeader
		);

		void findServersRequest(
			OpcUaStackCore::SecureChannel* secureChannel,
			OpcUaStackCore::RequestHeader::SPtr requestHeader
		);

		void registerServerRequest(
			OpcUaStackCore::SecureChannel* secureChannel,
			OpcUaStackCore::RequestHeader::SPtr requestHeader
		);

		void discoveryResponseMessage(
			OpcUaStackCore::SecureChannelTransaction::SPtr& secureChannelTransaction
		);

		boost::shared_ptr<boost::asio::io_service::strand> strand_ = nullptr;
		OpcUaStackCore::IOThread* ioThread_ = nullptr;
		OpcUaStackCore::MessageBus::SPtr messageBus_ = nullptr;
		OpcUaStackCore::CryptoManager::SPtr cryptoManager_ = nullptr;

		DiscoveryRequestCallback getEndpointRequestCallback_;
		DiscoveryRequestCallback findServersRequestCallback_;
		DiscoveryRequestCallback registerServerRequestCallback_;

		OpcUaStackCore::Config* config_;
		OpcUaStackCore::EndpointDescriptionSet::SPtr endpointDescriptionSet_;

		bool shutdownFlag_;
		std::promise<bool> shutdownComplete_;
		OpcUaStackCore::SecureChannelServer::Map secureChannelServerMap_;
		OpcUaStackCore::ForwardGlobalSync::SPtr forwardGlobalSync_;

		TransactionManager::SPtr transactionManagerSPtr_;

		ChannelSessionHandleMap channelSessionHandleMap_;
	};

}

#endif
