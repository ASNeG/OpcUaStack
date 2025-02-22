/*
   Copyright 2018-2023 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   Certificatermationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Kai Huebl (kai@huebl-sgh.de), Aleksey Timin (atimin@gmail.com)
 */

#ifndef __OpcUaStackCore_Certificate_h__
#define __OpcUaStackCore_Certificate_h__

#include <boost/shared_ptr.hpp>

#include <vector>
#include <string>
#include <list>

#include <openssl/x509.h>

#include "OpcUaStackCore/Base/MemoryBuffer.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaByteString.h"
#include "OpcUaStackCore/Certificate/BIOCtx.h"
#include "OpcUaStackCore/Certificate/CertificateInfo.h"
#include "OpcUaStackCore/Certificate/OpenSSLError.h"
#include "OpcUaStackCore/Certificate/CertificateEnums.h"
#include "OpcUaStackCore/Certificate/Identity.h"
#include "OpcUaStackCore/Certificate/RSAKey.h"
#include "OpcUaStackCore/Certificate/CertificateInfo.h"
#include "OpcUaStackCore/Certificate/UserExtension.h"
#include "X509Extension.h"

namespace OpcUaStackCore
{

	class DLLEXPORT Certificate
	: public OpenSSLError
	{
	  public:
		typedef boost::shared_ptr<Certificate> SPtr;
		typedef std::list<Certificate::SPtr> List;
		typedef std::vector<Certificate::SPtr> Vec;

		Certificate(void);
		Certificate(
			CertificateInfo& info,
			Identity& subject,
		    RSAKey& rsaKey,
			UserExtension::Vec* userExtensionVec = nullptr,
		    bool useCACert = false,
		    SignatureAlgorithm signatureAlgorithm = SignatureAlgorithm_Sha1
		);
		Certificate(
			CertificateInfo& info,
			Identity& subject,
			PublicKey& subjectPublicKey,
			Certificate&  issuerCertificate,
			PrivateKey& issuerPrivateKey,
			UserExtension::Vec* userExtensionVec = nullptr,
		    bool useCACert = false,
		    SignatureAlgorithm signatureAlgorithm = SignatureAlgorithm_Sha1
		);
		~Certificate(void);

		bool createCertificate( // create self signed certificate
			CertificateInfo& info,
			Identity& subject,
			RSAKey& rsaKey,
			UserExtension::Vec* userExtensionVec = nullptr,
			bool useCACert = false,
			SignatureAlgorithm signatureAlgorithm = SignatureAlgorithm_Sha1
		);
		bool createCertificate( // create self signed certificate
			CertificateInfo& info,
			Identity& subject,
			PublicKey& publicKey,
			PrivateKey& privateKey,
			UserExtension::Vec* userExtensionVec = nullptr,
			bool useCACert = false,
			SignatureAlgorithm signatureAlgorithm = SignatureAlgorithm_Sha1
		);
		bool createCertificate(
			CertificateInfo& info,
			Identity& subject,
			PublicKey& subjectPublicKey,
			Certificate&  issuerCertificate,
			PrivateKey& issuerPrivateKey,
			UserExtension::Vec* userExtensionVec = nullptr,
			bool useCACert = false,
			SignatureAlgorithm signatureAlgorithm = SignatureAlgorithm_Sha1
		);

		bool isCaCertificate(void);
		bool isCaRoot(void);
		bool isIntermediateCertificate(void);
		bool isApplCertificate(void);

		X509* getX509(void);
		bool getSubject(Identity& subject);
		bool getIssuer(Identity& issuer);
		bool getInfo(CertificateInfo& info);
		bool getExtension(X509Extension& x509Extension);
		bool getUserExtension(UserExtension::SPtr& userExtension);

		OpcUaByteString thumbPrint(void);
		bool thumbPrint(char* buf, uint32_t* bufLen);
		bool toDERFile(const std::string& fileName);
		bool fromDERFile(const std::string& fileName);
		bool toDERBufLen(uint32_t* bufLen);
		bool toDERBuf(char* buf, uint32_t* bufLen);
		bool toDERBuf(OpcUaByteString& derBuf);
		bool toDERBuf(MemoryBuffer& derBuf);
		bool fromDERBuf(char* buf, uint32_t bufLen);
		bool fromDERBuf(MemoryBuffer& derBuf);

		bool toPEMBuf(MemoryBuffer& pemBuf);
		bool toPEMBuf(BIOCtx& bioCtx);
		bool fromPEMBuf(MemoryBuffer& pemBuf);
		bool fromPEMBuf(BIOCtx& bioCtx, bool logging = true);

		bool isIssuerFrom(Certificate&  certificate);

		uint32_t getDERBufSize(void);
		PublicKey publicKey(void);

		bool isSelfSigned(void) const;
		bool verifySignature(Certificate& issuerCertificate) const;
		bool operator!=(const Certificate& rhs) const;
		bool operator==(const Certificate& rhs) const;

	  private:
		X509 *cert_;
	};

}

#endif
