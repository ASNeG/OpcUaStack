/*
   Copyright 2015 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackClient_SessionIf_h__
#define __OpcUaStackClient_SessionIf_h__

#include "boost/asio.hpp"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/Base/Condition.h"
#include "OpcUaStackClient/ServiceSet/SessionBase.h"

using namespace OpcUaStackCore;

namespace OpcUaStackClient
{

	typedef enum {
		SS_Disconnect,
		SS_Connect,
		SS_Reactivate
	} SessionState;

	class DLLEXPORT SessionServiceIf
	{
	  public:
		virtual ~SessionServiceIf(void) {}

		virtual void sessionStateUpdate(SessionBase& session, SessionState sessionState) = 0;
	};

	class DLLEXPORT SessionIfTestHandler
	: public SessionServiceIf
	{
	  public:
		SessionIfTestHandler(void);
		virtual ~SessionIfTestHandler(void);

		SessionState sessionState_;
		Condition sessionStateUpdate_;
		void sessionStateUpdate(SessionBase& session, SessionState sessionState);
	};

}

#endif
