/*
   Copyright 2015-2018 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf modbusTCPMaster://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   Informationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Kai Huebl (kai@huebl-sgh.de)

 */

#ifndef __OpUaStackCore_SecureChannelClientConfig_h__
#define __OpUaStackCore_SecureChannelClientConfig_h__

#include "OpcUaStackCore/SecureChannel/SecureChannelConfig.h"
#include "OpcUaStackCore/Certificate/ApplicationCertificate.h"
#include "OpcUaStackCore/Certificate/CryptoManager.h"

namespace OpcUaStackCore
{

	class DLLEXPORT SecureChannelClientConfig
	: public SecureChannelConfig
	{
	  public:
		typedef boost::shared_ptr<SecureChannelClientConfig> SPtr;

		SecureChannelClientConfig(void);
		~SecureChannelClientConfig(void);

		void endpointUrl(const std::string& endpointUrl);
		std::string& endpointUrl(void);
		void securityMode(SecurityMode securityMode);
		SecurityMode securityMode(void);
		void securityPolicy(SecurityPolicy securityPolicy);
		SecurityPolicy securityPolicy(void);
		void connectTimeout(uint32_t connectTimeout);
		uint32_t connectTimeout(void);
		void renewTimeout(uint32_t renewTimeout);
		uint32_t renewTimeout(void);
		void reconnectTimeout(uint32_t reconnectTimeout);
		uint32_t reconnectTimeout(void);
		void applicationCertificate(ApplicationCertificate::SPtr& applicationCertificate);
		ApplicationCertificate::SPtr& applicationCertificate(void);
		void cryptoManager(CryptoManager::SPtr& cryptoManager);
		CryptoManager::SPtr& cryptoManager(void);

		void secureChannelLog(bool secureChannelLog);
		bool secureChannelLog(void);

	  private:
		std::string endpointUrl_;
		SecurityMode securityMode_;
		SecurityPolicy securityPolicy_;

		ApplicationCertificate::SPtr applicationCertificate_;
		CryptoManager::SPtr cryptoManager_;

		uint32_t connectTimeout_;
		uint32_t renewTimeout_;
		uint32_t reconnectTimeout_;

		bool secureChannelLog_;
	};

}

#endif
