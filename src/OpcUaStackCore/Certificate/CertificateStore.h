/*
   Copyright 2018 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   CertificateStorermationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Kai Huebl (kai@huebl-sgh.de)
 */

#ifndef __OpcUaStackCore_CertificateStore_h__
#define __OpcUaStackCore_CertificateStore_h__

#include <string>
#include "OpcUaStackCore/Base/os.h"

namespace OpcUaStackCore
{

	class DLLEXPORT CertificateStore
	{
	  public:
		CertificateStore(void);
		~CertificateStore(void);

		bool init(void);
		bool cleanup(void);

		void certificateTrustListLocation(const std::string& certificateTrustListLocation);
		std::string& certificateTrustListLocation(void);
		void certificateRejectListLocation(const std::string& certificateRejectListLocation);
		std::string& certificateRejectListLocation(void);
		void certificateRevocationListLocation(const std::string& certificateRevocationListLocation);
		std::string& certificateRevocationListLocation(void);
		void issuersCertificatesLocation(const std::string& issuersCertificatesLocation);
		std::string& issuersCertificatesLocation(void);
		void issuersRevocationListLocation(const std::string& issuersRevocationListLocation);
		std::string& issuersRevocationListLocation(void);
		void privateKeyLocation(const std::string& privateKeyLocation);
		std::string& privateKeyLocation(void);

	  private:

		// The folder where certificates of trusted applications and trusted CAs should be stored
		std::string certificateTrustListLocation_;
		// The folder where certificates of rejected applications should be stored
		std::string certificateRejectListLocation_;
		// The folder where revocation lists for trusted CAs should be stored
		std::string certificateRevocationListLocation_;
		// The folder where issuer certificates are stored. Issuer certificates are CA certificates
		// necessary for the verification of the full trust chain of CA certificates in the trust list
		std::string issuersCertificatesLocation_;
		// The folder where revocation lists for issuer CAs should be stored
		std::string issuersRevocationListLocation_;
		// The folder where the private key should be stored
		std::string privateKeyLocation_;

	};

}

#endif
