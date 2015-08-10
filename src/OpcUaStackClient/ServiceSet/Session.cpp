#include "OpcUaStackCore/ServiceSet/CreateSessionRequest.h"
#include "OpcUaStackCore/ServiceSet/ActivateSessionRequest.h"
#include "OpcUaStackCore/ServiceSet/AnonymousIdentityToken.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackCore/Base/Utility.h"
#include "OpcUaStackClient/ServiceSet/Session.h"

using namespace OpcUaStackCore;

namespace OpcUaStackClient
{

	Session::Session(IOService& ioService)
	: sessionId_()
	, communicationState_(CS_Disconnect)
	, requestTimeout_(3000)
	, reconnectTimeout_(3000)
	, reactivateTimeout_(8000)
	, pendingQueue_(ioService)
	, requestHandle_(0)
	, applicatinDescriptionSPtr_(OpcUaStackCore::ApplicationDescription::construct())
	, createSessionParameter_()
	, sessionManagerIf_(nullptr)
	, sessionIf_(nullptr)
	, createSessionResponseSPtr_(OpcUaStackCore::CreateSessionResponse::construct())
	, activateSessionResponseSPtr_(OpcUaStackCore::ActivateSessionResponse::construct())
	, timer_(Timer::construct(ioService))
	{
		// init pending queue callback
		pendingQueue_.timeoutCallback().reset(
			boost::bind(&Session::pendingQueueTimeout, this, _1)
		);

		// set timer callback
		timer_->callback().reset(
			boost::bind(&Session::timeout, this)
		);
	}

	Session::~Session(void)
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
	Session::sessionIf(SessionIf *sessionIf)
	{
		sessionIf_ = sessionIf;
	}

	void
	Session::sessionManagerIf(SessionManagerIf* sessionManagerIf)
	{
		sessionManagerIf_ = sessionManagerIf;
	}

	bool 
	Session::registerService(OpcUaNodeId& typeId, Component* component)
	{
		ServiceSetMap::iterator it;
		it = serviceSetMap_.find(typeId);
		if (it != serviceSetMap_.end()) {
			Log(Error, "cannot insert type id into service set map, because type id already exist")
				.parameter("TypeId", typeId)
				.parameter("ComponentName", component->componentName());
			return false;
		}

		serviceSetMap_.insert(std::make_pair(typeId, component));

		return true;
	}

	bool 
	Session::deregisterService(OpcUaNodeId& typeId)
	{
		ServiceSetMap::iterator it;
		it = serviceSetMap_.find(typeId);
		if (it == serviceSetMap_.end()) {
			Log(Error, "cannot remove type id into service map, because type id not exist")
				.parameter("TypeId", typeId);
			return false;
		}

		serviceSetMap_.erase(it);

		return true;
	}

	void
	Session::open(void)
	{
		if (sessionManagerIf_ != nullptr) sessionManagerIf_->connectToSecureChannel();
	}

	void
	Session::close(void)
	{
	}


	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// This receive function is used to send a message to a server by a
	// service.
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	void 
	Session::receive(Message::SPtr message)
	{
		ServiceTransaction::SPtr serviceTransaction = boost::static_pointer_cast<ServiceTransaction>(message);

		Log(Debug, "send request in session")
			.parameter("TrxId", serviceTransaction->transactionId())
			.parameter("NodeType", serviceTransaction->nodeTypeRequest())
			.parameter("RequestHandle", serviceTransaction->transactionId());

		if (communicationState_ == CS_Disconnect) {
			serviceTransaction->statusCode(BadSessionClosed);
			Component* componentService = serviceTransaction->componentService();
			componentService->send(serviceTransaction);
			return;
		}

		SecureChannelTransaction::SPtr secureChannelTransaction = SecureChannelTransaction::construct();
		std::iostream ios(&secureChannelTransaction->os_);

		RequestHeader::SPtr requestHeader = serviceTransaction->requestHeader();
		requestHeader->requestHandle(serviceTransaction->transactionId());
		requestHeader->sessionAuthenticationToken() = createSessionResponseSPtr_->authenticationToken();
		requestHeader->opcUaBinaryEncode(ios);
		serviceTransaction->opcUaBinaryEncodeRequest(ios);

		uint32_t requestTimeout = requestTimeout_;
		serviceTransaction->calcRequestTimeout(requestTimeout);

		pendingQueue_.insert(
			serviceTransaction->transactionId(),
			serviceTransaction,
			requestTimeout
		);

		if (sessionManagerIf_ != nullptr) {
			secureChannelTransaction->requestTypeNodeId_ = serviceTransaction->nodeTypeRequest();
			sessionManagerIf_->send(secureChannelTransaction);
		}
	}

	void
	Session::pendingQueueTimeout(Object::SPtr object)
	{
		ServiceTransaction::SPtr serviceTransaction = boost::static_pointer_cast<ServiceTransaction>(object);

		Log(Debug, "receive response timeout in session")
			.parameter("TrxId", serviceTransaction->transactionId())
			.parameter("NodeType", serviceTransaction->nodeTypeResponse())
			.parameter("RequestHandle", serviceTransaction->transactionId());

		serviceTransaction->statusCode(BadTimeout);
		Component* componentService = serviceTransaction->componentService();
		componentService->send(serviceTransaction);
	}

	void
	Session::pendingQueueClose(void)
	{
		std::vector<uint32_t>::iterator it;
		std::vector<uint32_t> keys;
		pendingQueue_.keys(keys);

		for (it = keys.begin(); it != keys.end(); it++) {
			Object::SPtr objectSPtr = pendingQueue_.remove(*it);
			if (objectSPtr.get() == nullptr) return;

			ServiceTransaction::SPtr serviceTransaction = boost::static_pointer_cast<ServiceTransaction>(objectSPtr);
			serviceTransaction->statusCode(BadSessionClosed);
			Component* componentService = serviceTransaction->componentService();
			componentService->send(serviceTransaction);
		}
	}

	bool
	Session::receiveMessage(SecureChannelTransaction::SPtr secureChannelTransaction)
	{
		if (sessionIf_ == nullptr) {
			Log(Error, "interface sessionIf is empty")
				.parameter("EndpointUrl", createSessionParameter_.endpointUrl_)
				.parameter("SessionName", createSessionParameter_.sessionName_)
				.parameter("CommunicationState", communicationState_);
			return false;
		}

		// FIXME: check communication state

		std::iostream ios(&secureChannelTransaction->is_);
		ResponseHeader::SPtr responseHeader = ResponseHeader::construct();
		responseHeader->opcUaBinaryDecode(ios);

		Object::SPtr objectSPtr = pendingQueue_.remove(responseHeader->requestHandle());
		if (objectSPtr.get() == nullptr) {
			Log(Error, "element in pending queue not exist")
				.parameter("EndpointUrl", createSessionParameter_.endpointUrl_)
				.parameter("SessionName", createSessionParameter_.sessionName_)
				.parameter("TypeId", secureChannelTransaction->responseTypeNodeId_)
				.parameter("RequestHandle", responseHeader->requestHandle());
			char c; while (ios.get(c));
			return true;
		}

		ServiceTransaction::SPtr serviceTransaction = boost::static_pointer_cast<ServiceTransaction>(objectSPtr);
		serviceTransaction->opcUaBinaryDecodeResponse(ios);
		serviceTransaction->responseHeader(responseHeader);
		serviceTransaction->statusCode(responseHeader->serviceResult());

		Log(Debug, "receive response in session")
			.parameter("TrxId", serviceTransaction->transactionId())
			.parameter("NodeType", serviceTransaction->nodeTypeResponse())
			.parameter("ServiceResult", OpcUaStatusCodeMap::shortString(serviceTransaction->responseHeader()->serviceResult()));

		Component* componentService = serviceTransaction->componentService();
		if (componentService != nullptr) {
			componentService->send(serviceTransaction);
			return true;
		}

		ServiceSetMap::iterator it;
		it = serviceSetMap_.find(secureChannelTransaction->responseTypeNodeId_);
		if (it == serviceSetMap_.end()) {
			Log(Error, "type id not exist in service map")
				.parameter("EndpointUrl", createSessionParameter_.endpointUrl_)
				.parameter("SessionName", createSessionParameter_.sessionName_)
				.parameter("TypeId", secureChannelTransaction->responseTypeNodeId_);
			char c; while (ios.get(c));
			return true;
		}

		componentService = it->second;
		componentService->send(serviceTransaction);
		return true;
	}


	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// sender functions
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	void
	Session::sendCreateSessionRequest(void)
	{
		SecureChannelTransaction::SPtr secureChannelTransaction = SecureChannelTransaction::construct();
		std::iostream ios(&secureChannelTransaction->os_);

		OpcUaStackCore::CreateSessionRequest::SPtr createSessionRequestSPtr = OpcUaStackCore::CreateSessionRequest::construct();
		createSessionRequestSPtr->requestHeader()->requestHandle(++requestHandle_);
		createSessionRequestSPtr->clientDescription(applicatinDescriptionSPtr_);
		createSessionRequestSPtr->endpointUrl(createSessionParameter_.endpointUrl_);
		createSessionRequestSPtr->sessionName(createSessionParameter_.sessionName_);
		createSessionRequestSPtr->clientNonce((OpcUaStackCore::OpcUaByte*)"\000", 1);
		createSessionRequestSPtr->requestSessionTimeout(createSessionParameter_.requestedSessionTimeout_);
		createSessionRequestSPtr->maxResponseMessageSize(createSessionParameter_.maxResponseMessageSize_);
		createSessionRequestSPtr->opcUaBinaryEncode(ios);

		startTimer(requestTimeout_);
		secureChannelTransaction->requestTypeNodeId_.nodeId(OpcUaId_CreateSessionRequest_Encoding_DefaultBinary);
		if (sessionManagerIf_ != nullptr) sessionManagerIf_->send(secureChannelTransaction);
	}

	void
	Session::sendActivateSessionRequest(void)
	{
		SecureChannelTransaction::SPtr secureChannelTransaction = SecureChannelTransaction::construct();
		std::iostream ios(&secureChannelTransaction->os_);

		OpcUaStackCore::ActivateSessionRequest::SPtr activateSessionRequestSPtr = OpcUaStackCore::ActivateSessionRequest::construct();
		activateSessionRequestSPtr->requestHeader()->requestHandle(++requestHandle_);
		activateSessionRequestSPtr->requestHeader()->sessionAuthenticationToken() = createSessionResponseSPtr_->authenticationToken();

		OpcUaString::SPtr localeIdSPtr = OpcUaString::construct();
		*localeIdSPtr = "en";
		activateSessionRequestSPtr->localeIds()->resize(1);
		activateSessionRequestSPtr->localeIds()->push_back(localeIdSPtr);

		// user identity token
		activateSessionRequestSPtr->userIdentityToken()->parameterTypeId().nodeId(OpcUaId_AnonymousIdentityToken_Encoding_DefaultBinary);
		AnonymousIdentityToken::SPtr anonymousIdentityToken = activateSessionRequestSPtr->userIdentityToken()->parameter<AnonymousIdentityToken>();
		anonymousIdentityToken->policyId("Anonymous_Policy");
		activateSessionRequestSPtr->opcUaBinaryEncode(ios);

		startTimer(requestTimeout_);
		secureChannelTransaction->requestTypeNodeId_.nodeId(OpcUaId_ActivateSessionRequest_Encoding_DefaultBinary);
		if (sessionManagerIf_ != nullptr) sessionManagerIf_->send(secureChannelTransaction);
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// handle messages from secure channel
	//
	// handleSecureChannelConnect - a new secure channel is connected
	// handleSecureChannelDisconnect - a existing secure channel is disconnected
	// receive - a message is received from a server
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	void 
	Session::handleSecureChannelConnect(void)
	{
		Log(Debug, "receive secure channel connect")
			.parameter("EndpointUrl", createSessionParameter_.endpointUrl_)
			.parameter("SessionName", createSessionParameter_.sessionName_)
			.parameter("CommubnicationState", communicationState_);

		switch (communicationState_)
		{
			case CS_Reactivate:
			{
				stopTimer();
				communicationState_ = CS_ActivateReconnect;
				sendActivateSessionRequest();
				break;
			}
			case CS_Disconnect:
			{
				communicationState_ = CS_Create;
				sendCreateSessionRequest();
				break;
			}
			default:
			{
				Log(Error, "receive secure channel connect in invalid state")
					.parameter("EndpointUrl", createSessionParameter_.endpointUrl_)
					.parameter("SessionName", createSessionParameter_.sessionName_)
					.parameter("CommubnicationState", communicationState_);

				// reconnect after timeout
				communicationState_ = CS_ReconnectAfterTimeout;
				sessionClose();
				sessionReconnectAfterTimeout();
			}
		}
	}

	void 
	Session::handleSecureChannelDisconnect(void)
	{
		Log(Info, "session close")
			.parameter("SessionId", sessionId_)
			.parameter("EndpointUrl", createSessionParameter_.endpointUrl_)
			.parameter("SessionName", createSessionParameter_.sessionName_);

		switch (communicationState_)
		{
			case CS_Create:
			case CS_Activate:
				stopTimer();
				communicationState_ = CS_Disconnect;
				sessionClose();
				break;
			case CS_Connect:
				communicationState_ = CS_Reactivate;
				startTimer(reactivateTimeout_);
				sessionReactivate();
				break;
			case CS_ReconnectAfterTimeout:
				communicationState_ = CS_Disconnect;
				break;
			case CS_ActivateReconnect:
				communicationState_ = CS_Reactivate;
				break;
			default:
				Log(Error, "receive secure channel connect in invalid state")
					.parameter("EndpointUrl", createSessionParameter_.endpointUrl_)
					.parameter("SessionName", createSessionParameter_.sessionName_)
					.parameter("CommubnicationState", communicationState_);
				communicationState_ = CS_Disconnect;
				break;
		}
	}

	bool 
	Session::receive(SecureChannelTransaction::SPtr secureChannelTransaction)
	{
		// receive message from secure channel

		switch (secureChannelTransaction->responseTypeNodeId_.nodeId<OpcUaStackCore::OpcUaUInt32>())
		{
			case OpcUaId_CreateSessionResponse_Encoding_DefaultBinary:
			{
				Log(Debug, "receive create session response");
				return receiveCreateSessionResponse(secureChannelTransaction);
				break;
			}
			case OpcUaId_ActivateSessionResponse_Encoding_DefaultBinary:
			{
				Log(Debug, "receive activate session response");
				return receiveActivateSessionResponse(secureChannelTransaction);
				break;
			}
			case OpcUaId_ServiceFault_Encoding_DefaultBinary:
			{
				Log(Debug, "receive service fault");
				return receiveServiceFault(secureChannelTransaction);
				break;
			}
			default:
			{
				return receiveMessage(secureChannelTransaction);
			}
		}

	}

	bool
	Session::receiveCreateSessionResponse(SecureChannelTransaction::SPtr secureChannelTransaction)
	{
		stopTimer();

		std::iostream ios(&secureChannelTransaction->is_);
		createSessionResponseSPtr_->opcUaBinaryDecode(ios);

		switch (communicationState_)
		{
			case CS_Create:
			{
				// check result of create session resonse
				if (createSessionResponseSPtr_->responseHeader()->serviceResult() != Success) {
					Log(Error, "error in receive create session response")
						.parameter("EndpointUrl", createSessionParameter_.endpointUrl_)
						.parameter("SessionName", createSessionParameter_.sessionName_)
						.parameter("CommubnicationState", communicationState_);

					// reconnect after timeout
					communicationState_ = CS_ReconnectAfterTimeout;
					sessionClose();
					sessionReconnectAfterTimeout();
					break;
				}

				sessionId_ = createSessionResponseSPtr_->sessionId();
				communicationState_ = CS_Activate;
				sendActivateSessionRequest();
				break;
			}
			default:
			{
				Log(Error, "receive create session response in invalid state")
					.parameter("EndpointUrl", createSessionParameter_.endpointUrl_)
					.parameter("SessionName", createSessionParameter_.sessionName_)
					.parameter("CommubnicationState", communicationState_);

				// reconnect after timeout
				communicationState_ = CS_ReconnectAfterTimeout;
				sessionClose();
				sessionReconnectAfterTimeout();
				break;

			}
		}
		return true;
	}

	bool 
	Session::receiveActivateSessionResponse(SecureChannelTransaction::SPtr secureChannelTransaction)
	{
		stopTimer();

		std::iostream ios(&secureChannelTransaction->is_);
		activateSessionResponseSPtr_->opcUaBinaryDecode(ios);

		switch (communicationState_)
		{
			case CS_ActivateReconnect:
			{
				OpcUaStatusCode statusCode = activateSessionResponseSPtr_->responseHeader()->serviceResult();
				if (statusCode == Success) {
					communicationState_ = CS_Connect;
					sessionOpen();
					break;
				}

				// session error;
				Log(Error, "receive activate session response with error (reconnect)")
					.parameter("EndpointUrl", createSessionParameter_.endpointUrl_)
					.parameter("SessionName", createSessionParameter_.sessionName_)
					.parameter("CommubnicationState", communicationState_)
					.parameter("StatusCode", OpcUaStatusCodeMap::shortString(statusCode));

				// open a new session
				sessionClose();
				communicationState_ = CS_Create;
				sendCreateSessionRequest();
				break;
			}
			case CS_Activate:
			{
				// check result of activate session resonse
				if (activateSessionResponseSPtr_->responseHeader()->serviceResult() != Success) {
					Log(Error, "error in receive activate session response")
						.parameter("EndpointUrl", createSessionParameter_.endpointUrl_)
						.parameter("SessionName", createSessionParameter_.sessionName_)
						.parameter("CommubnicationState", communicationState_);

					// reconnect after timeout
					communicationState_ = CS_ReconnectAfterTimeout;
					sessionClose();
					sessionReconnectAfterTimeout();
					break;
				}

				communicationState_ = CS_Connect;
				sessionOpen();
				break;
			}
			default:
			{
				Log(Error, "receive activate session response in invalid state")
					.parameter("EndpointUrl", createSessionParameter_.endpointUrl_)
					.parameter("SessionName", createSessionParameter_.sessionName_)
					.parameter("CommubnicationState", communicationState_);

				// reconnect after timeout
				communicationState_ = CS_ReconnectAfterTimeout;
				sessionClose();
				sessionReconnectAfterTimeout();
				break;
			}
		}
		return true;
	}

	bool 
	Session::receiveServiceFault(SecureChannelTransaction::SPtr secureChannelTransaction)
	{
		// FIXME: timer could be running ...

		std::iostream ios(&secureChannelTransaction->is_);
		ResponseHeader::SPtr responseHeader = ResponseHeader::construct();
		responseHeader->opcUaBinaryDecode(ios);

		Log(Error, "received Service Fault")
			.parameter("ServiceResult", OpcUaStatusCodeMap::longString(responseHeader->serviceResult()));
	
		// reconnect after timeout
		communicationState_ = CS_ReconnectAfterTimeout;
		sessionClose();
		sessionReconnectAfterTimeout();

		return false;
	}

	void
	Session::sessionReconnectAfterTimeout(void)
	{
		startTimer(reconnectTimeout_);
	}

	void
	Session::sessionOpen(void)
	{
		Log(Info, "session open")
			.parameter("SessionId", sessionId_)
			.parameter("EndpointUrl", createSessionParameter_.endpointUrl_)
			.parameter("SessionName", createSessionParameter_.sessionName_);

		sessionIf_->sessionStateUpdate(SS_Connect);
	}

	void
	Session::sessionClose(void)
	{
		Log(Info, "session close")
			.parameter("SessionId", sessionId_)
			.parameter("EndpointUrl", createSessionParameter_.endpointUrl_)
			.parameter("SessionName", createSessionParameter_.sessionName_);

		sessionIf_->sessionStateUpdate(SS_Disconnect);
		pendingQueueClose();
	}

	void
	Session::sessionReactivate(void)
	{
	    Log(Info, "session reactivate")
			.parameter("SessionId", sessionId_)
			.parameter("EndpointUrl", createSessionParameter_.endpointUrl_)
			.parameter("SessionName", createSessionParameter_.sessionName_);

	    sessionIf_->sessionStateUpdate(SS_Reactivate);
	}

	void
	Session::startTimer(uint32_t timeout)
	{
		timer_->start(timeout);
	}

	void
	Session::stopTimer(void)
	{
		timer_->stop(timer_);
	}

	void
	Session::timeout(void)
	{
		Log(Debug, "timeout")
			.parameter("SessionId", sessionId_)
			.parameter("EndpointUrl", createSessionParameter_.endpointUrl_)
			.parameter("SessionName", createSessionParameter_.sessionName_)
			.parameter("CommunicationState", communicationState_);

		switch (communicationState_)
		{
			case CS_Create:
			case CS_Activate:
				communicationState_ = CS_ReconnectAfterTimeout;
				sessionClose();
				sessionReconnectAfterTimeout();
				break;
			case CS_ReconnectAfterTimeout:
				communicationState_ = CS_Create;
				sendCreateSessionRequest();
				break;
			case CS_Reactivate:
				communicationState_ = CS_Disconnect;
				sessionClose();
				break;
			case CS_Disconnect:
			case CS_Connect:
			case CS_ActivateReconnect:
				Log(Error, "receive timeout in invalid state")
					.parameter("EndpointUrl", createSessionParameter_.endpointUrl_)
					.parameter("SessionName", createSessionParameter_.sessionName_)
					.parameter("CommubnicationState", communicationState_);
				break;
		}
	}
}
