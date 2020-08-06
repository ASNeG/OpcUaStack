/*
   Copyright 2019 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   CertificateManagerrmationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Kai Huebl (kai@huebl-sgh.de)
 */

#ifndef __OpcUaStackCore_CertificateManager_h__
#define __OpcUaStackCore_CertificateManager_h__

#include "OpcUaStackCore/Certificate/Certificate.h"
#include "OpcUaStackCore/Certificate/PrivateKey.h"
#include "OpcUaStackCore/Certificate/CertificateSettings.h"
#include "OpcUaStackCore/Certificate/CertificateChain.h"

namespace OpcUaStackCore
{

	class DLLEXPORT CertificateManager
	{
	  public:
		typedef boost::shared_ptr<CertificateManager> SPtr;

		CertificateManager(void);
		~CertificateManager(void);

		bool init(void);

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

		void ownCertificateFile(const std::string& ownCertificateFile);
		std::string& ownCertificateFile(void);
		void ownPrivateKeyFile(const std::string& ownPrivateKeyFile);
		std::string& ownPrivateKeyFile(void);

		bool existOwnCertificate(void);
		bool removeOwnCertificate(void);
		Certificate::SPtr readOwnCertificate(void);
		bool writeOwnCertificate(Certificate::SPtr& certificate);
		bool writeOwnCertificate(Certificate& certificate);
		bool existOwnPrivateKey(void);
		bool removeOwnPrivateKey(void);
		PrivateKey::SPtr readOwnPrivateKey(void);
		bool writeOwnPrivateKey(PrivateKey::SPtr& privateKey);
		bool writeOwnPrivateKey(PrivateKey& privateKey);

		CertificateSettings& certificateSettings(void);

		bool writePartnerCertificate(const std::string& fileName, Certificate& certificate);
		bool isPartnerCertificateTrusted(CertificateChain& partnerCertificateChain);
		bool isPartnerCertificateTrusted(const std::string& applicationUri, CertificateChain& partnerCertificateChain);

		bool existCertificate(const std::string& fileName);
		bool removeCertificate(const std::string& fileName);
		Certificate::SPtr readCertificate(const std::string& fileName);
		bool writeCertificate(const std::string& fileName, Certificate::SPtr& certificate);
		bool writeCertificate(const std::string& fileName, Certificate& certificate);

		Certificate::SPtr getTrustedCertificate(Identity& issuer);
		Certificate::SPtr getCACertificate(Identity& issuer);
		bool isCertificateInTrustedList(Certificate::SPtr& certificate);
		bool isCertificateInIssuerList(Certificate::SPtr& certificate);
		bool isCertificateInRevocationList(Certificate::SPtr& certificate);

	  private:
		Certificate::SPtr getCertificate(const std::string& directory, Identity& issuer);
		bool checkAndCreateDirectory(const std::string& directory);
		bool setReadOnly(const std::string& directory);

		std::string certificateTrustListLocation_;		//!< The folder where certificates of trusted applications
														//!< and trusted CAs should be stored
		std::string certificateRejectListLocation_;		//!< The folder where certificates of rejected applications
														//!< should be stored
		std::string certificateRevocationListLocation_;	//!< The folder where revocation lists for trusted CAs
														//!< should be stored
		std::string issuersCertificatesLocation_;		//!< The folder where issuer certificates are stored. Issuer
														//!< certificates are CA certificates necessary for the
														//!< verification of the full trust chain of CA certificates
														//!< in the trust list
		std::string issuersRevocationListLocation_;		//!< The folder where revocation lists for issuer CAs should
														//!< be stored


		std::string ownCertificateFile_;
		std::string ownPrivateKeyFile_;

		CertificateSettings certificateSettings_;
	};

}

#endif
