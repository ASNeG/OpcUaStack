/*
   Copyright 2015-2019 Kai Huebl (kai@huebl-sgh.de)

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
#ifndef __OpcUaStackClient_SessionConfig_h__
#define __OpcUaStackClient_SessionConfig_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/ServiceSet/ApplicationDescription.h"

using namespace OpcUaStackCore;

namespace OpcUaStackClient
{

	class DLLEXPORT SessionConfig
	{
	  public:
		typedef boost::shared_ptr<SessionConfig> SPtr;

		SessionConfig(void);
		~SessionConfig(void);

		void applicationDescription(ApplicationDescription::SPtr& applicationDescription);
		ApplicationDescription::SPtr& applicationDescription(void);
		void sessionName(const std::string& sessionName);
		std::string& sessionName(void);
		void requestTimeout(uint32_t requestTimeout);
		uint32_t requestTimeout(void);
		void sessionTimeout(uint32_t sessionTimeout);
		uint32_t sessionTimeout(void);
		void reconnectTimeout(uint32_t sessionTimeout);
		uint32_t reconnectTimeout(void);
		void maxResponseMessageSize(uint32_t maxResponseMessageSize);
		uint32_t maxResponseMessageSize(void);
		void policyId(const std::string& policyId);
		std::string& policyId(void);

	  //private:
		ApplicationDescription::SPtr applicationDescription_;
		std::string sessionName_;
		uint32_t requestTimeout_;
		uint32_t sessionTimeout_;
		uint32_t reconnectTimeout_;
		uint32_t maxResponseMessageSize_;
		std::string policyId_;

	};

}

#endif
