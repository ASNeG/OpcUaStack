/*
   Copyright 2015-2019 Kai Huebl (kai@huebl-sgh.de)

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
#include "OpcUaStackCore/Certificate/CryptoManager.h"
#include "OpcUaStackCore/Certificate/CertificateChain.h"
#include "OpcUaStackCore/StandardDataTypes/MessageSecurityMode.h"

namespace OpcUaStackCore
{

	class DLLEXPORT SecureChannelClientConfig
	: public SecureChannelConfig
	{
	  public:
		typedef boost::shared_ptr<SecureChannelClientConfig> SPtr;

		SecureChannelClientConfig(void);
		SecureChannelClientConfig(const SecureChannelClientConfig& secureChannelClientConfig);
		~SecureChannelClientConfig(void);

		void endpointUrl(const std::string& endpointUrl);
		std::string& endpointUrl(void);
		void discoveryUrl(const std::string& discoveryUrl);
		std::string& discoveryUrl(void);
		void applicationUri(const std::string& applicationUri);
		std::string& applicationUri(void);
		void securityMode(MessageSecurityMode::Enum securityMode);
		MessageSecurityMode::Enum securityMode(void);
		void securityPolicy(SecurityPolicy::Enum securityPolicy);
		SecurityPolicy::Enum securityPolicy(void);
		void connectTimeout(uint32_t connectTimeout);
		uint32_t connectTimeout(void);
		void renewTimeout(uint32_t renewTimeout);
		uint32_t renewTimeout(void);
		void reconnectTimeout(uint32_t reconnectTimeout);
		uint32_t reconnectTimeout(void);
		void cryptoManager(CryptoManager::SPtr& cryptoManager);
		CryptoManager::SPtr& cryptoManager(void);
		void certificateChain(CertificateChain& certificateChain);
		CertificateChain& certificateChain(void);

		void secureChannelLog(bool secureChannelLog);
		bool secureChannelLog(void);

	  private:
		std::string endpointUrl_;			// opc ua server endpoint url
		std::string discoveryUrl_;			// opc ua server discovery url
		std::string applicationUri_;		// application uri
		MessageSecurityMode::Enum securityMode_;// security mode
		SecurityPolicy::Enum securityPolicy_;	// security policy

		CryptoManager::SPtr cryptoManager_;
		CertificateChain certificateChain_;

		uint32_t connectTimeout_;
		uint32_t renewTimeout_;
		uint32_t reconnectTimeout_;

		bool secureChannelLog_;
	};

}

#endif
