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

	SessionServiceStateIf::SessionServiceStateIf(const std::string& stateName, SessionServiceStateId stateId)
	: ctx_(nullptr)
	, stateName_(stateName)
	, stateId_(stateId)
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

}
