/*
   Copyright 2019-2020 Kai Huebl (kai@huebl-sgh.de)

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
#ifndef __OpcUaStackClient_SessionServiceStateEstablished_h__
#define __OpcUaStackClient_SessionServiceStateEstablished_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackClient/ServiceSet/SessionServiceStateIf.h"

namespace OpcUaStackClient
{

	class DLLEXPORT SessionServiceStateEstablished
	: public SessionServiceStateIf
	{
	  public:
		SessionServiceStateEstablished(void);
		~SessionServiceStateEstablished(void);

		virtual SessionServiceStateId asyncConnect(void) override;
		virtual SessionServiceStateId asyncDisconnect(bool deleteSubscriptions) override;
		virtual SessionServiceStateId asyncCancel(uint32_t requestHandle) override;

		virtual SessionServiceStateId handleConnect(OpcUaStackCore::SecureChannel* secureChannel) override;
		virtual SessionServiceStateId handleDisconnect(OpcUaStackCore::SecureChannel* secureChannel) override;
		virtual SessionServiceStateId recvCreateSessionResponse(
			OpcUaStackCore::SecureChannel* secureChannel,
			const OpcUaStackCore::ResponseHeader::SPtr& responseHeader
		) override;
		virtual SessionServiceStateId recvActivateSessionResponse(
			OpcUaStackCore::SecureChannel* secureChannel,
			const OpcUaStackCore::ResponseHeader::SPtr& responseHeader
		) override;
		virtual SessionServiceStateId recvGetEndpointsResponse(
			OpcUaStackCore::SecureChannel* secureChannel,
			const OpcUaStackCore::ResponseHeader::SPtr& responseHeader
		) override;
		virtual SessionServiceStateId recvCloseSessionResponse(
			OpcUaStackCore::SecureChannel* secureChannel,
			const OpcUaStackCore::ResponseHeader::SPtr& responseHeader
		) override;
		virtual SessionServiceStateId recvMessageResponse(
			OpcUaStackCore::SecureChannel* secureChannel,
			const OpcUaStackCore::ResponseHeader::SPtr& responseHeader
		) override;

		virtual SessionServiceStateId sendMessageRequest(OpcUaStackCore::Message::SPtr message) override;

		virtual SessionServiceStateId reconnectTimeout(void) override;
		virtual SessionServiceStateId pendingQueueTimeout(const OpcUaStackCore::Object::SPtr& object) override;

	  private:
		void removeAllRequestsFromPendingQueue(void);
	};

}

#endif
