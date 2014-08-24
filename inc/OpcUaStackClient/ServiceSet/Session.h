#ifndef __OpcUaStackClient_Session_h__
#define __OpcUaStackClient_Session_h__

#include <stdint.h>
#include <string>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/ServiceSet/ApplicationDescription.h"
#include "OpcUaStackCore/ServiceSet/CreateSessionResponse.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackClient/ServiceSet/SessionIf.h"

namespace OpcUaStackClient
{

	typedef enum
	{
		SessionState_Close,
		SessionState_SendCreateSession,
		SessionState_ReceiveCreateSession,
	} SessionState;

	class CreateSessionParameter
	{
	  public:
		std::string endpointUrl_;
		std::string sessionName_;
		uint32_t requestedSessionTimeout_;
		uint32_t maxResponseMessageSize_;
	};

	class DLLEXPORT Session : public  OpcUaStackCore::ObjectPool<Session>
	{
	  public:
		Session(void);
		~Session(void);

		void createSession(void);
		void activateSession(void);

		OpcUaStackCore::ApplicationDescription::SPtr applicationDescription(void);
		void sessionSecureChannelIf(SessionSecureChannelIf* sessionSecureChannelIf);

		void receiveMessage(OpcUaStackCore::OpcUaNodeId& typeId, boost::asio::streambuf& sb);
		CreateSessionParameter& createSessionParameter(void);

 	  private:
		  void receiveSessionCreateResponse(boost::asio::streambuf& sb);

		  SessionState sessionState_;
		  uint32_t requestHandle_;
		  OpcUaStackCore::ApplicationDescription::SPtr applicatinDescriptionSPtr_;
		  CreateSessionParameter createSessionParameter_;
		  SessionSecureChannelIf *sessionSecureChannelIf_;
		  OpcUaStackCore::CreateSessionResponse::SPtr createSessionResponseSPtr_;
	};

};

#endif