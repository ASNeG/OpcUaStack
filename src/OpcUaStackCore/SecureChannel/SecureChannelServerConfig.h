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

#ifndef __OpUaStackCore_SecureChannelServerConfig_h__
#define __OpUaStackCore_SecureChannelServerConfig_h__

#include "OpcUaStackCore/SecureChannel/SecureChannelConfig.h"
#include "OpcUaStackCore/StandardDataTypes/EndpointDescription.h"
#include "OpcUaStackCore/Certificate/ApplicationCertificate.h"
#include "OpcUaStackCore/Certificate/CryptoManager.h"

namespace OpcUaStackCore
{

	class DLLEXPORT SecureChannelServerConfig
	: public SecureChannelConfig
	{
	  public:
		typedef boost::shared_ptr<SecureChannelServerConfig> SPtr;

		SecureChannelServerConfig(void);
		~SecureChannelServerConfig(void);

		void endpointDescriptionArray(EndpointDescriptionArray::SPtr& endpointDescriptionArray);
		EndpointDescriptionArray::SPtr& endpointDescriptionArray(void);
		void endpointDescription(EndpointDescription::SPtr& endpointDescription);
		EndpointDescription::SPtr& endpointDescription(void);
		void endpointUrl(const std::string& endpointUrl);
		std::string& endpointUrl(void);
		void cryptoManager(CryptoManager::SPtr& cryptoManager);
		CryptoManager::SPtr& cryptoManager(void);

		void secureChannelLog(bool secureChannelLog);
		bool secureChannelLog(void);

	  private:
		CryptoManager::SPtr cryptoManager_;

		EndpointDescriptionArray::SPtr endpointDescriptionArray_;
		EndpointDescription::SPtr endpointDescription_;
		std::string endpointUrl_;

		bool secureChannelLog_;
	};

}

#endif
