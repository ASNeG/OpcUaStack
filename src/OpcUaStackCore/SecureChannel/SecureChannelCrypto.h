/*
   Copyright 2018 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackCore_SecureChannelCrypto_h__
#define __OpcUaStackCore_SecureChannelCrypto_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Certificate/CryptoManager.h"
#include "OpcUaStackCore/Certificate/ApplicationCertificate.h"
#include "OpcUaStackCore/SecureChannel/SecureChannel.h"

namespace OpcUaStackCore
{

	class DLLEXPORT SecureChannelCrypto
	{
	  public:
		SecureChannelCrypto(void);
		virtual ~SecureChannelCrypto(void);

		void cryptoManager(CryptoManager::SPtr& cryptoManager);
		CryptoManager::SPtr& cryptoManager(void);
		void applicationCertificate(ApplicationCertificate::SPtr& applicationCertificate);
		ApplicationCertificate::SPtr& applicationCertificate(void);

		//
		// open secure channel request
		//
		OpcUaStatusCode secureReceivedOpenSecureChannelRequest(
			SecureChannel* secureChannel
		);
		OpcUaStatusCode decryptReceivedOpenSecureChannel(
			SecureChannel* secureChannel
		);
		OpcUaStatusCode verifyReceivedOpenSecureChannel(
			SecureChannel* secureChannel
		);

	  private:
		CryptoManager::SPtr cryptoManager_;
		ApplicationCertificate::SPtr applicationCertificate_;

	};

}

#endif
