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

#ifndef __OpUaStackCore_SecureChannelClient_h__
#define __OpUaStackCore_SecureChannelClient_h__

#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include "OpcUaStackCore/SecureChannel/SecureChannelClientConfig.h"
#include "OpcUaStackCore/SecureChannel/SecureChannelClientIf.h"
#include "OpcUaStackCore/SecureChannel/SecureChannelBase.h"

namespace OpcUaStackCore
{

	class DLLEXPORT SecureChannelClient
	: public SecureChannelBase
	{
	  public:
		SecureChannelClient(
			IOThread* ioThread,
			boost::shared_ptr<boost::asio::io_service::strand>& strand
		);
		~SecureChannelClient(void);

		void secureChannelClientIf(SecureChannelClientIf* secureChannelClientIf);
		SecureChannelClientIf* secureChannelClientIf(void);

		SecureChannel* connect(SecureChannelClientConfig::SPtr& secureChannelClientConfig);
		void disconnect(SecureChannel* secureChannel);

		//- SecureChannelBase -------------------------------------------------
		void handleDisconnect(SecureChannel* secureChannel);
		void handleRecvAcknowledge(SecureChannel* secureChannel, AcknowledgeMessage& acknowledge);
		bool findEndpoint(SecureChannel* secureChannel) override;
		void handleRecvOpenSecureChannelResponse(SecureChannel* secureChannel, OpenSecureChannelResponse& openSecureChannelResponse);
		void handleRecvMessageResponse(SecureChannel* secureChannel);
		//- SecureChannelBase -------------------------------------------------

	  private:
		OpcUaStatusCode validateCertificateChain(
			SecureChannel* secureChannel,
			SecureChannelClientConfig::SPtr& secureChannelClientConfig
		);
		void renewSecurityToken(SecureChannel* secureChannel);
		void connect(SecureChannel* secureChannel);
		void connectToServer(SecureChannel* secureChannel);
		void connectComplete(
			const boost::system::error_code& error,
			SecureChannel* secureChannel
		);
		void reconnect(SecureChannel* secureChannel);
		void handleReconnect(SecureChannel* secureChannel);

		IOThread* ioThread_;

		SecureChannelClientIf* secureChannelClientIf_;
		SlotTimerElement::SPtr slotTimerElementRenew_;
		SlotTimerElement::SPtr slotTimerElementReconnect_;

		uint32_t renewTimeout_;
		uint32_t reconnectTimeout_;
	};

}

#endif
