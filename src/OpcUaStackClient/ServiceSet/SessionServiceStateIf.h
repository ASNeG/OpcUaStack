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
#ifndef __OpcUaStackClient_SessionServiceStateIf_h__
#define __OpcUaStackClient_SessionServiceStateIf_h__

#include "OpcUaStackClient/ServiceSet/SessionServiceContext.h"

using namespace OpcUaStackCore;

namespace OpcUaStackClient
{

	enum class DLLEXPORT SessionServiceStateId
	{
		None,
		Disconnected
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

		SessionServiceStateIf(void) = delete;
		SessionServiceStateIf(const std::string& stateName, SessionServiceStateId stateId);
		virtual ~SessionServiceStateIf(void);

		void setCtx(SessionServiceContext* ctx);
		std::string stateName(void);
		SessionServiceStateId stateId(void);

		virtual SessionServiceStateId asyncConnect(void) = 0;
		virtual SessionServiceStateId asyncDisconnect(bool deleteSubscriptions) = 0;

	  protected:
		SessionServiceContext* ctx_;

	  private:
		std::string stateName_;
		SessionServiceStateId stateId_;
	};

}

#endif
