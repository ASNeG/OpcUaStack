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
#include "OpcUaStackClient/ServiceSet/SessionServiceContext.h"

using namespace OpcUaStackCore;

namespace OpcUaStackClient
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// SessionServiceStateIf
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	SessionServiceStateIf::SessionServiceStateIf(const std::string& stateName, SessionServiceStateId stateId)
	: ctx_(nullptr)
	, stateName_("")
	, stateId_(stateId_)
	{
	}

	SessionServiceStateIf::~SessionServiceStateIf(void)
	{
	}

	void
	SessionServiceStateIf::setCtx(SessionServiceContext* ctx)
	{
		ctx_ = ctx;
	}

	std::string
	SessionServiceStateIf::stateName(void)
	{
		return stateName_;
	}

	SessionServiceStateId
	SessionServiceStateIf::stateId(void)
	{
		return stateId_;
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// SessionServiceStateDisconnected
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	SessionServiceStateDisconnected::SessionServiceStateDisconnected(void)
	: SessionServiceStateIf("Disconnected", SessionServiceStateId::Disconnected)
	{
	}

	SessionServiceStateDisconnected::~SessionServiceStateDisconnected(void)
	{
	}

	SessionServiceStateId
	SessionServiceStateDisconnected::asyncConnect(void)
	{
		return SessionServiceStateId::Disconnected;
	}

	SessionServiceStateId
	SessionServiceStateDisconnected::asyncDisconnect(bool deleteSubscriptions)
	{
		return SessionServiceStateId::Disconnected;
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// SessionServiceStateMachine
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	SessionServiceStateMachine::SessionServiceStateMachine(void)
	: ctx_(nullptr)
	, sessionServiceName_("")
	, state_()
	{
	}

	SessionServiceStateMachine::~SessionServiceStateMachine(void)
	{
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
				state_->setCtx(ctx_);
				logChangeState(oldStateName);
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
		return true;
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
