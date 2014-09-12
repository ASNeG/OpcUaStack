#ifndef __OpcUaStackServer_Session_h__
#define __OpcUaStackServer_Session_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackServer/ServiceSet/SessionIf.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	typedef enum
	{
		SessionState_Close,
	} SessionState;


	class DLLEXPORT Session : public  OpcUaStackCore::ObjectPool<Session>
	{
	  public:
		Session(void);
		~Session(void);

		void sessionSecureChannelIf(SessionSecureChannelIf* sessionSecureChannelIf);
		bool receive(OpcUaStackCore::OpcUaNodeId& typeId, boost::asio::streambuf& sb);

	  private:
		bool receiveCreateSessionRequest(OpcUaStackCore::OpcUaNodeId& typeId, boost::asio::streambuf& sb);
		bool receiveActivateSessionRequest(OpcUaStackCore::OpcUaNodeId& typeId, boost::asio::streambuf& sb);
		bool receiveMessage(OpcUaStackCore::OpcUaNodeId& typeId, boost::asio::streambuf& sb);

		SessionState sessionState_;
		SessionSecureChannelIf* sessionSecureChannelIf_;
	};

}

#endif