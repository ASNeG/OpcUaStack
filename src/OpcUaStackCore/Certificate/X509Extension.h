/*
   Copyright 2018-2023 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   X509Extensionrmationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Kai Huebl (kai@huebl-sgh.de)
 */

#ifndef __OpcUaStackCore_X509Extension_h__
#define __OpcUaStackCore_X509Extension_h__

#include <openssl/x509.h>
#include <openssl/x509v3.h>
#include "OpcUaStackCore/Certificate/OpenSSLError.h"
#include "OpcUaStackCore/Certificate/UserExtension.h"

namespace OpcUaStackCore
{

	class DLLEXPORT X509Extension
	: public OpenSSLError
	{
	  public:
		X509Extension(bool useCACert = false);
		~X509Extension(void);

		void clear(void);
		void basicConstraints(const std::string& basicConstraints);
		std::string& basicConstraints(void);
		void nsComment(const std::string& nsComment);
		std::string& nsComment(void);
		void subjectKeyIdentifier(const std::string& subjectKeyIdentifier);
		std::string& subjectKeyIdentifier(void);
		void authorityKeyIdentifier(const std::string& authorityKeyIdentifier);
		std::string& authorityKeyIdentifier(void);
		void keyUsage(const std::string& keyUsage);
		std::string& keyUsage(void);
		void extendedKeyUsage(const std::string& extendedKeyUsage);
		std::string& extendedKeyUsage(void);
		void subjectAltName(const std::string& subjectAltName);
		std::string& subjectAltName(void);

		// Encode/Decode certificate
		bool encode(X509 *cert, X509V3_CTX& ctx);
		bool decode(X509 *cert);

		// Encode/Decode CSR request
		bool encode(X509_REQ *req, STACK_OF(X509_EXTENSION)* exts);
		bool decode(X509_REQ *req);

		void logContent(const std::string& message);

	  private:
		bool encode(
			X509 *cert,
			X509V3_CTX& ctx,
			const std::string& key,
			const std::string& value
		);
		bool decode(
			X509 *cert,
			int32_t key,
			std::string& value,
			bool mandatory = true
		);

		bool encode(
			STACK_OF(X509_EXTENSION)* exts,
			const std::string& key,
			const std::string& value
		);
		bool decode(
			STACK_OF(X509_EXTENSION)* exts,
			int32_t key,
			std::string& value,
			bool mandatory = true
		);

		bool useCACert_;
		std::string basicConstraints_;
		std::string nsComment_;
		std::string subjectKeyIdentifier_;
		std::string authorityKeyIdentifier_;
		std::string keyUsage_;
		std::string extendedKeyUsage_;
		std::string subjectAltName_;

	};

}

#endif
