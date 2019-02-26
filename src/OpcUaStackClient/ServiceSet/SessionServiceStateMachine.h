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

	enum class DLLEXPORT SessionServiceStateId
	{
		None,
		Initial
	};

	template<typename T>
	std::ostream& operator<<(typename std::enable_if<std::is_enum<T>::value, std::ostream>::type& stream, const T& e)
	{
	    return stream << static_cast<typename std::underlying_type<T>::type>(e);
	}

	class DLLEXPORT SessionServiceStateIf
	{
	  public:
		typedef std::unique_ptr<SessionServiceStateIf> UPtr;

		//SessionServiceStateIf(void) delete;
		SessionServiceStateIf(const std::string& stateName, SessionServiceStateId stateId);
		virtual ~SessionServiceStateIf(void);

		std::string stateName(void);
		SessionServiceStateId stateId(void);

	  private:
		std::string stateName_;
		SessionServiceStateId stateId_;
	};


	class DLLEXPORT SessionServiceStateInitial
	: public SessionServiceStateIf
	{
	  public:
		SessionServiceStateInitial(void);
		~SessionServiceStateInitial(void);
	};

	class DLLEXPORT SessionServiceStateMachine
	{
	  public:
		typedef boost::shared_ptr<SessionServiceStateMachine> SPtr;

		SessionServiceStateMachine(void);
		~SessionServiceStateMachine(void);

		bool setStateId(SessionServiceStateId stateId);
		bool event(std::function<SessionServiceStateId(SessionServiceStateIf*)> event);

	  private:
		void logChangeState(const std::string& oldStateName);

		std::string sessionServiceName_;
		SessionServiceStateIf::UPtr state_;
	};

}

#endif
