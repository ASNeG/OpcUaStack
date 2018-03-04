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

#ifndef __OpcUaStackCore_CryptoBase_h__
#define __OpcUaStackCore_CryptoBase_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"

namespace OpcUaStackCore
{

	class DLLEXPORT CryptoBase
	{
	  public:
		boost::shared_ptr<CryptoBase> SPtr;

		CryptoBase(void);
		virtual ~CryptoBase(void);

		void securityPolicy(const std::string& securityPolicy);
		std::string& securityPolicy(void);

		void symmetricKeyLen(int32_t symmetricKeyLen);
		int32_t symmetricKeyLen(void);
		void minimumAsymmetricKeyLen(uint32_t minimumAsymmetricKeyLen);
		uint32_t minimumAsymmetricKeyLen(void);
		void maximumAsymmetricKeyLen(uint32_t maximumAsymmetricKeyLen);
		uint32_t maximumAsymmetricKeyLen(void);
		void derivedEncryptionKeyLen(uint32_t derivedEncryptionKeyLen);
		uint32_t derivedEncryptionKeyLen(void);
		void derivedSignatureKeyLen(uint32_t derivedSignatureKeyLen);
		uint32_t derivedSignatureKeyLen(void);
		void signatureDataLen(uint32_t signatureDataLen);
		uint32_t signatureDataLen(void);
		void asymmetricSignatureAlgorithmId(uint32_t asymmetricSignatureAlgorithmId);
		uint32_t asymmetricSignatureAlgorithmId(void);
		void asymmetricEncryptionAlgorithmId(uint32_t asymmetricEncryptionAlgorithmId);
		uint32_t asymmetricEncryptionAlgorithmId(void);
		void symmetricSignatureAlgorithmId(uint32_t symmetricSignatureAlgorithmId);
		uint32_t symmetricSignatureAlgorithmId(void);
		void symmetricEncryptionAlgorithmId(uint32_t symmetricEncryptionAlgorithmId);
		uint32_t symmetricEncryptionAlgorithmId(void);

	  private:
		std::string securityPolicy_;

		int32_t symmetricKeyLen_;
		uint32_t minimumAsymmetricKeyLen_;
		uint32_t maximumAsymmetricKeyLen_;
		uint32_t derivedEncryptionKeyLen_;
		uint32_t derivedSignatureKeyLen_;
		uint32_t signatureDataLen_;
		uint32_t asymmetricSignatureAlgorithmId_;
		uint32_t asymmetricEncryptionAlgorithmId_;
		uint32_t symmetricSignatureAlgorithmId_;
		uint32_t symmetricEncryptionAlgorithmId_;

	};

}

#endif
