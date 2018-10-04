/*
   Copyright 2018 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   Informationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Aleksey Timin (atimin@gmail.com)
 */

#include <OpcUaStackPubSub/PubSubModel/PubSubState.h>

namespace OpcUaStackPubSub
{

	PubSubState::PubSubState(void)
	: state_(Disabled)
	{
	}

	PubSubState::~PubSubState(void)
	{
	}

	PubSubState::State
	PubSubState::state(void)
	{
		return state_;
	}

	void
	PubSubState::parent(
		const PubSubState::SPtr& parent
	)
	{
		// FIXME: todo
	}

	PubSubState::State
	PubSubState::enable(void)
	{
		switch (state_)
		{
			case Disabled:
				if (parentState() != Operational) {
					state_ = Paused;
				}
				else {
					state_ = Operational;
				}
				break;
			case Paused:
				break;
			case Operational:
				break;
			case Error:
				break;
			default:
				break;
		}
		return state_;
	}

	PubSubState::State
	PubSubState::disable(void)
	{
		switch (state_)
		{
			case Disabled:
				break;
			case Paused:
				state_ = Disabled;
				break;
			case Operational:
				state_ = Disabled;
				break;
			case Error:
				state_ = Disabled;
				break;
			default:
				break;
		}
		return state_;
	}

	PubSubState::State
	PubSubState::errorOn(void)
	{
		switch (state_)
		{
			case Disabled:
				break;
			case Paused:
				break;
			case Operational:
				state_ = Error;
				break;
			case Error:
				break;
			default:
				break;
		}
		return state_;
	}

	PubSubState::State
	PubSubState::errorOff(void)
	{
		switch (state_)
		{
			case Disabled:
				break;
			case Paused:
				break;
			case Operational:
				break;
			case Error:
				state_ = Operational;
				break;
			default:
				break;
		}
		return state_;
	}

	PubSubState::State
	PubSubState::parentChangedToDisableOrPaused(void)
	{
		switch (state_)
		{
			case Disabled:
				break;
			case Paused:
				break;
			case Operational:
				state_ = Paused;
				break;
			case Error:
				state_ = Paused;
				break;
			default:
				break;
		}
		return state_;
	}

	PubSubState::State
	PubSubState::parentChangedToOperational(void)
	{
		switch (state_)
		{
			case Disabled:
				break;
			case Paused:
				state_ = Operational;
				break;
			case Operational:
				break;
			case Error:
				break;
			default:
				break;
		}
		return state_;
	}

	PubSubState::State
	PubSubState::parentState(void)
	{
		if (!parent_) {
			return Operational;
		}
		return parent_->state();
	}

}
