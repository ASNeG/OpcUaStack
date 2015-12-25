/*
   Copyright 2015 Kai Huebl (kai@huebl-sgh.de)

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
#include "OpcUaStackCore/SecureChannel/SecureChannelServerConfig.h"
#include "OpcUaStackCore/SecureChannel/SecureChannelServerIf.h"
#include "OpcUaStackCore/SecureChannel/SecureChannelBase.h"
#include "OpcUaStackCore/TCPChannel/TCPAcceptor.h"

namespace OpcUaStackCore
{

	class SecureChannelServer
	: public SecureChannelBase
	{
	  public:
		SecureChannelServer(IOService* ioService);
		~SecureChannelServer(void);

		void secureChannelServerIf(SecureChannelServerIf* secureChannelServerIf);
		SecureChannelServerIf* secureChannelServerIf(void);

		void accept(SecureChannelServerConfig::SPtr secureChannelServerConfig);
		void disconnect(SecureChannel* secureChannel);

		//- SecureChannelBase -------------------------------------------------
		void handleDisconnect(SecureChannel* secureChannel);
		void handleReadHello(SecureChannel* secureChannel, AcknowledgeMessage& acknowledge);
		void handleReadOpenSecureChannelRequest(SecureChannel* secureChannel, OpenSecureChannelRequest& openSecureChannelRequest);
		void handleReadMessageRequest(SecureChannel* secureChannel);
		//- SecureChannelBase -------------------------------------------------

	  private:
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

		IOService* ioService_;
		boost::asio::ip::tcp::resolver resolver_;
		SecureChannelServerIf* secureChannelServerIf_;
		TCPAcceptor* tcpAcceptor_;
	};

}

#endif
