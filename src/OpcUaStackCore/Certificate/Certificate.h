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

#include <vector>
#include <string>
#include <openssl/x509.h>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Certificate/OpenSSLError.h"
#include "OpcUaStackCore/Certificate/CertificateEnums.h"
#include "OpcUaStackCore/Certificate/CertificateExtension.h"
#include "OpcUaStackCore/Certificate/Info.h"
#include "OpcUaStackCore/Certificate/Identity.h"
#include "OpcUaStackCore/Certificate/RSAKey.h"

namespace OpcUaStackCore
{

	class DLLEXPORT Certificate
	: public OpenSSLError
	{
	  public:
		Certificate(void);
		Certificate(
			Info& info,
			Identity& subject,
		    RSAKey& rsaKey,
		    bool useCACert = false,
		    SignatureAlgorithm signatureAlgorithm = SignatureAlgorithm_Sha1
		);
		Certificate(
			Info& info,
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
		bool getInfo(Info& info);
		bool getExtension(CertificateExtension& certificateExtension);

		bool toDERFile(const std::string& fileName);
		bool fromDERFile(const std::string& fileName);

		bool isSelfSigned(void) const;

	  private:
		X509 *cert_;
	};

}

#endif
