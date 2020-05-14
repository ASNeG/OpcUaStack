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
#ifndef __OpcUaStackClient_SessionServiceStateIf_h__
#define __OpcUaStackClient_SessionServiceStateIf_h__

#include <OpcUaStackCore/MessageBus/Message.h>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/SecureChannel/SecureChannel.h"
#include "OpcUaStackClient/ServiceSet/SessionServiceStateId.h"

namespace OpcUaStackClient
{

	class SessionServiceContext;

	class DLLEXPORT SessionServiceStateIf
	{
	  public:
		typedef std::unique_ptr<SessionServiceStateIf> UPtr;

		SessionServiceStateIf(void) = delete;
		SessionServiceStateIf(const std::string& stateName, SessionServiceStateId stateId);
		virtual ~SessionServiceStateIf(void);

		void setCtx(SessionServiceContext* ctx);
		std::string stateName(void);
		SessionServiceStateId stateId(void);

		//
		// events from user interface
		//
		virtual SessionServiceStateId asyncConnect(void) = 0;
		virtual SessionServiceStateId asyncDisconnect(bool deleteSubscriptions) = 0;
		virtual SessionServiceStateId asyncCancel(uint32_t requestHandle) = 0;

		//
		// events from secure channel server
		//
		virtual SessionServiceStateId handleConnect(OpcUaStackCore::SecureChannel* secureChannel) = 0;
		virtual SessionServiceStateId handleDisconnect(OpcUaStackCore::SecureChannel* secureChannel) = 0;
		virtual SessionServiceStateId recvCreateSessionResponse(
			OpcUaStackCore::SecureChannel* secureChannel,
			const OpcUaStackCore::ResponseHeader::SPtr& responseHeader
		) = 0;
		virtual SessionServiceStateId recvActivateSessionResponse(
			OpcUaStackCore::SecureChannel* secureChannel,
			const OpcUaStackCore::ResponseHeader::SPtr& responseHeader
		) = 0;
		virtual SessionServiceStateId recvGetEndpointsResponse(
			OpcUaStackCore::SecureChannel* secureChannel,
			const OpcUaStackCore::ResponseHeader::SPtr& responseHeader
		) = 0;
		virtual SessionServiceStateId recvCloseSessionResponse(
			OpcUaStackCore::SecureChannel* secureChannel,
			const OpcUaStackCore::ResponseHeader::SPtr& responseHeader
		) = 0;
		virtual SessionServiceStateId recvMessageResponse(
			OpcUaStackCore::SecureChannel* secureChannel,
			const OpcUaStackCore::ResponseHeader::SPtr& responseHeader
		) = 0;

		//
		// event to send a message to a opc ua server
		//
		virtual SessionServiceStateId sendMessageRequest(OpcUaStackCore::Message::SPtr message) = 0;

		//
		// internal events
		//
		virtual SessionServiceStateId reconnectTimeout(void) = 0;
		virtual SessionServiceStateId pendingQueueTimeout(const OpcUaStackCore::Object::SPtr& object) = 0;

	  protected:
		SessionServiceContext* ctx_;

	  private:
		std::string stateName_;
		SessionServiceStateId stateId_;
	};

}

#endif
