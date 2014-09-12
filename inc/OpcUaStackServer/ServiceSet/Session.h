#ifndef __OpcUaStackServer_Session_h__
#define __OpcUaStackServer_Session_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackServer/ServiceSet/SessionIf.h"
#include "OpcUaStackCore/ServiceSet/EndpointDescription.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	typedef enum
	{
		SessionState_Close,
		SessionState_ReceiveCreateSessionRequest,
		SessionState_CreateSessionResponse,
	} SessionState;


	class DLLEXPORT Session : public  OpcUaStackCore::ObjectPool<Session>
	{
	  public:
		Session(void);
		~Session(void);

		void sessionSecureChannelIf(SessionSecureChannelIf* sessionSecureChannelIf);
		void sessionId(uint32_t sessionId);
		void authenticationToken(uint32_t authenticationToken);
		bool receive(OpcUaStackCore::OpcUaNodeId& typeId, boost::asio::streambuf& sb);

		void endpointDescriptionArray(EndpointDescriptionArray::SPtr endpointDescriptionArray);

	  private:
		bool receiveCreateSessionRequest(OpcUaStackCore::OpcUaNodeId& typeId, boost::asio::streambuf& sb);
		bool receiveActivateSessionRequest(OpcUaStackCore::OpcUaNodeId& typeId, boost::asio::streambuf& sb);
		bool receiveMessage(OpcUaStackCore::OpcUaNodeId& typeId, boost::asio::streambuf& sb);

		uint32_t sessionId_;
		uint32_t authenticationToken_;
		SessionState sessionState_;
		SessionSecureChannelIf* sessionSecureChannelIf_;
		EndpointDescriptionArray::SPtr endpointDescriptionArray_;
	};

}

#endif