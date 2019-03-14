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


#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackClient/ServiceSet/SessionServiceStateMachine.h"
#include "OpcUaStackClient/ServiceSet/SessionServiceStateDisconnected.h"
#include "OpcUaStackClient/ServiceSet/SessionServiceStateConnecting.h"
#include "OpcUaStackClient/ServiceSet/SessionServiceStateCreateSession.h"
#include "OpcUaStackClient/ServiceSet/SessionServiceStateActivateSession.h"
#include "OpcUaStackClient/ServiceSet/SessionServiceStateEstablished.h"
#include "OpcUaStackClient/ServiceSet/SessionServiceStateDisconnecting.h"
#include "OpcUaStackClient/ServiceSet/SessionServiceStateError.h"
#include "OpcUaStackClient/ServiceSet/SessionServiceStateGetEndpoint.h"
#include "OpcUaStackClient/ServiceSet/SessionServiceStateReconnecting.h"

using namespace OpcUaStackCore;

namespace OpcUaStackClient
{

	SessionServiceStateMachine::SessionServiceStateMachine(void)
	: ctx_(nullptr)
	, sessionServiceName_("")
	, state_()
	, updateCallback_()
	{
	}

	SessionServiceStateMachine::~SessionServiceStateMachine(void)
	{
	}

	void
	SessionServiceStateMachine::setSessionServiceName(const std::string& sessionServiceName)
	{
		sessionServiceName_ = sessionServiceName;
	}

	void
	SessionServiceStateMachine::setCtx(SessionServiceContext* ctx)
	{
		ctx_ = ctx;
	}

	bool
	SessionServiceStateMachine::setStateId(SessionServiceStateId stateId)
	{
		auto oldStateId = SessionServiceStateId::None;
		std::string oldStateName = "None";
		if (state_) {
			oldStateId = state_->stateId();

			// check if state has changed
			if (oldStateId == stateId) {
				return true;
			}

			oldStateName = state_->stateName();
		}

		switch (stateId)
		{
			case SessionServiceStateId::Disconnected:
			{
				state_.reset(new SessionServiceStateDisconnected());
				break;
			}
			case SessionServiceStateId::Connecting:
			{
				state_.reset(new SessionServiceStateConnecting());
				break;
			}
			case SessionServiceStateId::CreateSession:
			{
				state_.reset(new SessionServiceStateCreateSession());
				break;
			}
			case SessionServiceStateId::ActivateSession:
			{
				state_.reset(new SessionServiceStateActivateSession());
				break;
			}
			case SessionServiceStateId::Established:
			{
				state_.reset(new SessionServiceStateEstablished());
				break;
			}
			case SessionServiceStateId::Disconnecting:
			{
				state_.reset(new SessionServiceStateDisconnecting());
				break;
			}
			case SessionServiceStateId::Error:
			{
				state_.reset(new SessionServiceStateError());
				break;
			}
			case SessionServiceStateId::GetEndpoint:
			{
				state_.reset(new SessionServiceStateGetEndpoint());
				break;
			}
			case SessionServiceStateId::Reconnecting:
			{
				state_.reset(new SessionServiceStateReconnecting());
				break;
			}
			default:
			{
				Log(Error, "set state id failed, because unknown state")
				    .parameter("SessionServiceName", sessionServiceName_)
					.parameter("StateId", stateId);
				return false;
			}
		}
		state_->setCtx(ctx_);
		if (stateId != oldStateId) {
			logChangeState(oldStateName);
			if (updateCallback_) {
				updateCallback_(stateId);
			}
			else {
				Log(Warning, "update callback not available");
			}
		}
		return true;
	}

	void
	SessionServiceStateMachine::setUpdateCallback(UpdateCallback updateCallback)
	{
		updateCallback_ = updateCallback;
	}

	SessionServiceStateId
	SessionServiceStateMachine::stateId(void)
	{
		if (!state_) {
			return SessionServiceStateId::None;
		}
		return state_->stateId();
	}

	bool
	SessionServiceStateMachine::event(std::function<SessionServiceStateId(SessionServiceStateIf*)> event)
	{
		// check state
		if (!state_) {
			Log(Error, "call event function failed in session service state machine, because state is null")
				.parameter("SessionServiceName", sessionServiceName_);
			return false;
		}

		// call event function
		SessionServiceStateId stateId = event(state_.get());
		if (stateId != state_->stateId()) {
			return setStateId(stateId);
		}

		return true;
	}

	void
	SessionServiceStateMachine::logChangeState(const std::string& oldStateName)
	{
		Log(Debug, "change state in session service")
			.parameter("SessionServiceName", sessionServiceName_)
			.parameter("OldState", oldStateName)
			.parameter("NewSate", state_->stateName());
	}

}
