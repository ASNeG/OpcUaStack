#include "OpcUaStackServer/ServiceSet/Session.h"
#include "OpcUaStackCore/BuildInTypes/OPcUaIdentifier.h"

namespace OpcUaStackServer
{

	Session::Session(void)
	: sessionState_(SessionState_Close)
	{
	}

	Session::~Session(void)
	{
	}

	void 
	Session::sessionSecureChannelIf(SessionSecureChannelIf* sessionSecureChannelIf)
	{
		sessionSecureChannelIf_ = sessionSecureChannelIf;
	}

	bool 
	Session::receive(OpcUaStackCore::OpcUaNodeId& typeId, boost::asio::streambuf& sb)
	{
		switch (typeId.nodeId<OpcUaStackCore::OpcUaUInt32>())
		{
			case OpcUaId_CreateSessionRequest_Encoding_DefaultBinary:
			{
				return receiveCreateSessionRequest(typeId, sb);
				break;
			}
			case OpcUaId_ActivateSessionRequest_Encoding_DefaultBinary:
			{
				return receiveActivateSessionRequest(typeId, sb);
				break;
			}
			default:
			{
				return receiveMessage(typeId, sb);
			}
		}
	}

	bool 
	Session::receiveCreateSessionRequest(OpcUaStackCore::OpcUaNodeId& typeId, boost::asio::streambuf& sb)
	{
		return false;
	}
		
	bool 
	Session::receiveActivateSessionRequest(OpcUaStackCore::OpcUaNodeId& typeId, boost::asio::streambuf& sb)
	{
		return false;
	}

	bool 
	Session::receiveMessage(OpcUaStackCore::OpcUaNodeId& typeId, boost::asio::streambuf& sb)
	{
		return false;
	}

}