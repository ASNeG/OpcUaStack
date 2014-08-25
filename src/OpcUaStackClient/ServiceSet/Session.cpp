#include "OpcUaStackClient/ServiceSet/Session.h"
#include "OpcUaStackCore/ServiceSet/CreateSessionRequest.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"

namespace OpcUaStackClient
{

	Session::Session(void)
	: sessionState_(SessionState_Close)
	, requestHandle_(0)
	, applicatinDescriptionSPtr_(OpcUaStackCore::ApplicationDescription::construct())
	, createSessionParameter_()
	, sessionSecureChannelIf_(nullptr)
	, createSessionResponseSPtr_(OpcUaStackCore::CreateSessionResponse::construct())
	{
	}

	Session::~Session(void)
	{
	}

	void 
	Session::receiveMessage(OpcUaStackCore::OpcUaNodeId& typeId, boost::asio::streambuf& sb)
	{
		switch (typeId.nodeId<OpcUaStackCore::OpcUaUInt32>())
		{
			case OpcUaId_CreateSessionResponse_Encoding_DefaultBinary:
			{
				receiveSessionCreateResponse(sb);
				break;
			}
		}
	}

	void 
	Session::createSession(void)
	{
		boost::asio::streambuf sb;
		std::iostream ios(&sb);

		OpcUaStackCore::CreateSessionRequest::SPtr createSessionRequestSPtr = OpcUaStackCore::CreateSessionRequest::construct();
		createSessionRequestSPtr->requestHeader()->requestHandle(++requestHandle_);
		createSessionRequestSPtr->clientDescription(applicatinDescriptionSPtr_);
		createSessionRequestSPtr->endpointUrl(createSessionParameter_.endpointUrl_);
		createSessionRequestSPtr->sessionName(createSessionParameter_.sessionName_);
		createSessionRequestSPtr->clientNonce((OpcUaStackCore::OpcUaByte*)"\000", 1);
		createSessionRequestSPtr->requestSessionTimeout(createSessionParameter_.requestedSessionTimeout_);
		createSessionRequestSPtr->maxResponseMessageSize(createSessionParameter_.maxResponseMessageSize_);
		createSessionRequestSPtr->opcUaBinaryEncode(ios);

		sessionState_ = SessionState_SendCreateSession;
		if (sessionSecureChannelIf_ != nullptr) sessionSecureChannelIf_->createSessionRequest(sb);
	}

	void 
	Session::receiveSessionCreateResponse(boost::asio::streambuf& sb)
	{
		std::iostream ios(&sb);
		createSessionResponseSPtr_->opcUaBinaryDecode(ios);
		sessionState_ = SessionState_ReceiveCreateSession;
	}
		
	void 
	Session::activateSession(void)
	{
	}

	OpcUaStackCore::ApplicationDescription::SPtr 
	Session::applicationDescription(void)
	{
		return applicatinDescriptionSPtr_;
	}

	CreateSessionParameter& 
	Session::createSessionParameter(void)
	{
		return createSessionParameter_;
	}

	void 
	Session::sessionSecureChannelIf(SessionSecureChannelIf* sessionSecureChannelIf)
	{
		sessionSecureChannelIf_ = sessionSecureChannelIf;
	}

}
