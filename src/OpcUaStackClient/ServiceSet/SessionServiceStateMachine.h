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

using namespace OpcUaStackCore;

namespace OpcUaStackClient
{

	class DLLEXPORT SessionServiceStateIf
	{
	  public:
		typedef std::unique_ptr<SessionServiceStateIf> UPtr;

		SessionServiceStateIf(const std::string& stateName);
		virtual ~SessionServiceStateIf(void);

		std::string stateName(void);

	  private:
		std::string stateName_;
	};

	class DLLEXPORT SessionServiceStateMachine
	{
	  public:
		typedef boost::shared_ptr<SessionServiceStateMachine> SPtr;

		SessionServiceStateMachine(void);
		~SessionServiceStateMachine(void);

	  private:
		SessionServiceStateIf::UPtr state_;
	};

}

#endif
