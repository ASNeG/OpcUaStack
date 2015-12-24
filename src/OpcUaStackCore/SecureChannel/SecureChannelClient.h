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

#ifndef __OpUaStackCore_SecureChannelClient_h__
#define __OpUaStackCore_SecureChannelClient_h__

#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include "OpcUaStackCore/SecureChannel/SecureChannelConfig.h"
#include "OpcUaStackCore/SecureChannel/SecureChannelClientIf.h"
#include "OpcUaStackCore/SecureChannel/SecureChannelBase.h"

namespace OpcUaStackCore
{

	class SecureChannelClientConfig
	: public SecureChannelConfig
	{
	  public:
		typedef boost::shared_ptr<SecureChannelClientConfig> SPtr;

		SecureChannelClientConfig(void);
		~SecureChannelClientConfig(void);

		void endpointUrl(const std::string& endpointUrl);
		std::string& endpointUrl(void);
		void connectTimeout(uint32_t connectTimeout);
		uint32_t connectTimeout(void);

	  private:
		std::string endpointUrl_;
		uint32_t connectTimeout_;
	};


	class SecureChannelClient
	: public SecureChannelBase
	{
	  public:
		SecureChannelClient(IOService* ioService);
		~SecureChannelClient(void);

		void secureChannelClientIf(SecureChannelClientIf* secureChannelClientIf);
		SecureChannelClientIf* secureChannelClientIf(void);

		bool connect(SecureChannelClientConfig::SPtr secureChannelClientConfig);

		//- SecureChannelBase -------------------------------------------------
		void handleDisconnect(SecureChannel* secureChannel);
		void handleReadAcknowledge(SecureChannel* secureChannel, AcknowledgeMessage& acknowledge);
		//- SecureChannelBase -------------------------------------------------

	  private:
		void connect(SecureChannel* secureChannel);
		void resolveComplete(
			const boost::system::error_code& error,
			boost::asio::ip::tcp::resolver::iterator endpointIterator,
			SecureChannel* secureChannel
		);
		void connectComplete(
			const boost::system::error_code& error,
			SecureChannel* secureChannel
		);

		IOService* ioService_;
		boost::asio::ip::tcp::resolver resolver_;
		SecureChannelClientIf* secureChannelClientIf_;
	};

}

#endif
