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
#ifndef __OpcUaStackClient_SessionServiceStateMachine_h__
#define __OpcUaStackClient_SessionServiceStateMachine_h__

#include <memory>
#include "OpcUaStackClient/ServiceSet/SessionServiceStateIf.h"
#include "OpcUaStackClient/ServiceSet/SessionServiceStateId.h"

namespace OpcUaStackClient
{

	class SessionServiceContext;

	class DLLEXPORT SessionServiceStateMachine
	{
	  public:
		typedef boost::shared_ptr<SessionServiceStateMachine> SPtr;
		typedef std::function<void (SessionServiceStateId state)> UpdateCallback;

		SessionServiceStateMachine(void);
		~SessionServiceStateMachine(void);

		void setSessionServiceName(const std::string& sessionServiceName);
		void setCtx(SessionServiceContext* ctx);
		bool setStateId(SessionServiceStateId stateId);
		void setUpdateCallback(UpdateCallback updateCallback);
		bool event(std::function<SessionServiceStateId(SessionServiceStateIf*)> event);
		SessionServiceStateId stateId(void);

	  private:
		void logChangeState(const std::string& oldStateName);

		SessionServiceContext* ctx_;
		UpdateCallback updateCallback_;
		std::string sessionServiceName_;
		SessionServiceStateIf::UPtr state_;
	};

}

#endif
