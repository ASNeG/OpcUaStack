/*
   Copyright 2018 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   Certificatermationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Kai Huebl (kai@huebl-sgh.de)
 */

#ifndef __OpcUaStackCore_Certificate_h__
#define __OpcUaStackCore_Certificate_h__

#include <boost/shared_ptr.hpp>

#include <vector>
#include <string>
#include <list>

#include <openssl/x509.h>

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/MemoryBuffer.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaByteString.h"
#include "OpcUaStackCore/Certificate/CertificateInfo.h"
#include "OpcUaStackCore/Certificate/OpenSSLError.h"
#include "OpcUaStackCore/Certificate/CertificateEnums.h"
#include "OpcUaStackCore/Certificate/CertificateExtension.h"
#include "OpcUaStackCore/Certificate/Identity.h"
#include "OpcUaStackCore/Certificate/RSAKey.h"
#include "OpcUaStackCore/Certificate/CertificateInfo.h"

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
		    bool useCACert = false,
		    SignatureAlgorithm signatureAlgorithm = SignatureAlgorithm_Sha1
		);
		Certificate(
			CertificateInfo& info,
			Identity& subject,
			PublicKey& subjectPublicKey,
			Certificate&  issuerCertificate,
			PrivateKey& issuerPrivateKey,
		    bool useCACert = false,
		    SignatureAlgorithm signatureAlgorithm = SignatureAlgorithm_Sha1
		);
		~Certificate(void);

		bool getSubject(Identity& subject);
		bool getIssuer(Identity& issuer);
		bool getInfo(CertificateInfo& info);
		bool getExtension(CertificateExtension& certificateExtension);

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

		uint32_t getDERBufSize(void);
		PublicKey publicKey(void);

		bool isSelfSigned(void) const;

	  private:
		X509 *cert_;
	};

}

#endif
