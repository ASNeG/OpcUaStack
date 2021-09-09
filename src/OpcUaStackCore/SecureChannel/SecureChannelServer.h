/*
   Copyright 2015-2021 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf modbusTCPMaster://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   Informationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Kai Huebl (kai@huebl-sgh.de)

 */

#ifndef __OpUaStackCore_SecureChannelServer_h__
#define __OpUaStackCore_SecureChannelServer_h__

#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <map>
#include <OpcUaStackCore/Network/TCPAcceptor.h>
#include "OpcUaStackCore/SecureChannel/SecureChannelServerConfig.h"
#include "OpcUaStackCore/SecureChannel/SecureChannelServerIf.h"
#include "OpcUaStackCore/SecureChannel/SecureChannelBase.h"

namespace OpcUaStackCore
{

	class DLLEXPORT SecureChannelServer
	: public SecureChannelBase
	{
	  public:
		typedef boost::shared_ptr<SecureChannelServer> SPtr;
		typedef std::map<std::string, SecureChannelServer::SPtr> Map;

		SecureChannelServer(IOThread* ioThread);
		~SecureChannelServer(void);

		void strand(boost::shared_ptr<boost::asio::io_service::strand>& strand);
		void secureChannelServerIf(SecureChannelServerIf* secureChannelServerIf);
		SecureChannelServerIf* secureChannelServerIf(void);

		bool accept(SecureChannelServerConfig::SPtr& secureChannelServerConfig);
		void disconnect(void);
		void disconnect(SecureChannel* secureChannel);
		void sendResponse(SecureChannel* secureChannel, SecureChannelTransaction::SPtr& secureChannelTransaction);

		//- SecureChannelBase -------------------------------------------------
		void handleDisconnect(SecureChannel* secureChannel);
		void handleRecvHello(SecureChannel* secureChannel, HelloMessage& hello);
		bool findEndpoint(SecureChannel* secureChannel) override;
		void handleRecvOpenSecureChannelRequest(SecureChannel* secureChannel, OpcUaUInt32 channelId, OpenSecureChannelRequest& openSecureChannelRequest);
		void handleRecvCloseSecureChannelRequest(SecureChannel* secureChannel, uint32_t channelId);
		void handleRecvMessageRequest(SecureChannel* secureChannel);
		//- SecureChannelBase -------------------------------------------------

	  private:
		void sendOpenSecureChannelResponseError(OpenSecureChannelResponse::SPtr& openSecureChannelResponse);

		void accept(SecureChannel* secureChannel);
		void resolveComplete(
			const boost::system::error_code& error,
			boost::asio::ip::tcp::resolver::iterator endpointIterator,
			SecureChannel* secureChannel
		);
		void acceptComplete(
			const boost::system::error_code& error,
			SecureChannel* secureChannel
		);

		std::string endpointUrl_;
		IOThread* ioThread_;
		boost::asio::ip::tcp::resolver resolver_;
		SecureChannelServerIf* secureChannelServerIf_;
		TCPAcceptor* tcpAcceptor_;

		Object::SPtr handle_;
	};

}

#endif
