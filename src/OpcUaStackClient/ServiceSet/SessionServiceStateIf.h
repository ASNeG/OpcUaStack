/*
   Copyright 2019 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Component/Message.h"
#include "OpcUaStackCore/SecureChannel/SecureChannel.h"
#include "OpcUaStackClient/ServiceSet/SessionServiceStateId.h"

using namespace OpcUaStackCore;

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
		virtual SessionServiceStateId handleConnect(SecureChannel* secureChannel) = 0;
		virtual SessionServiceStateId handleDisconnect(SecureChannel* secureChannel) = 0;
		virtual SessionServiceStateId recvCreateSessionResponse(
			SecureChannel* secureChannel,
			const ResponseHeader::SPtr& responseHeader
		) = 0;
		virtual SessionServiceStateId recvActivateSessionResponse(
			SecureChannel* secureChannel,
			const ResponseHeader::SPtr& responseHeader
		) = 0;
		virtual SessionServiceStateId recvGetEndpointsResponse(
			SecureChannel* secureChannel,
			const ResponseHeader::SPtr& responseHeader
		) = 0;
		virtual SessionServiceStateId recvCloseSessionResponse(
			SecureChannel* secureChannel,
			const ResponseHeader::SPtr& responseHeader
		) = 0;
		virtual SessionServiceStateId recvMessageResponse(
			SecureChannel* secureChannel,
			const ResponseHeader::SPtr& responseHeader
		) = 0;

		//
		// event to send a message to a opc ua server
		//
		virtual SessionServiceStateId sendMessageRequest(Message::SPtr message) = 0;

		//
		// internal events
		//
		virtual SessionServiceStateId sessionTimeout(void) = 0;
		virtual SessionServiceStateId reconnectTimeout(void) = 0;
		virtual SessionServiceStateId pendingQueueTimeout(const Object::SPtr& object) = 0;

	  protected:
		SessionServiceContext* ctx_;

	  private:
		std::string stateName_;
		SessionServiceStateId stateId_;
	};

}

#endif
