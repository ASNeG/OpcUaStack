/*
   Copyright 2018 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   ServerCertificatermationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Kai Huebl (kai@huebl-sgh.de)
 */

#ifndef __OpcUaStackCore_ServerCertificate_h__
#define __OpcUaStackCore_ServerCertificate_h__

#include <boost/shared_ptr.hpp>
#include <string>
#include "OpcUaStackCore/Base/os.h"

namespace OpcUaStackCore
{

	class DLLEXPORT ServerCertificate
	{
	  public:
		typedef boost::shared_ptr<ServerCertificate> SPtr;

		ServerCertificate(void);
		~ServerCertificate(void);

		bool init(void);
		bool cleanup(void);

		void enable(bool enable);
		bool enable(void);
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
		void rejectListLocation(const std::string& rejectListLocation);
		std::string& rejectListLocation(void);

		void serverCertificateFile(const std::string& serverCertificateFile);
		std::string& serverCertificateFile(void);
		void privateKeyFile(const std::string& privateKeyFile);
		std::string& privateKeyFile(void);

		void commonName(const std::string& commonName);
		std::string& commonName(void);
		void domainComponent(const std::string& domainComponent);
		std::string& domainComponent(void);
		void organization(const std::string& organization);
		std::string& organization(void);
		void organizationUinit(const std::string& organizationUnit);
		std::string& organizationUnit(void);
		void locality(const std::string& locality);
		std::string& locality(void);
		void state(const std::string& state);
		std::string& state(void);
		void country(const std::string& country);
		std::string& country(void);
		void yearsValidFor(uint32_t yearsValidFor);
		uint32_t yearsValidFor(void);
		void keyLength(uint32_t keyLength);
		uint32_t keyLength(void);
		void certificateType(const std::string& certificateType);
		std::string& certificateType(void);
		std::vector<std::string>& ipAddress(void);
		std::vector<std::string>& dnsName(void);

	  private:

		bool enable_;
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
		// The folder where the rejected certificates should be stored
		std::string rejectListLocation_;

		std::string serverCertificateFile_;
		std::string privateKeyFile_;

		// name of the application
		std::string commonName_;
		// hostname of the machine
		std::string domainComponent_;
		// organization using the opc ua server
		std::string organization_;
		// organization unit unsing the opc ua server
		std::string organizationUnit_;
		// name of the location where the opc ua server is running
		std::string locality_;
		// name of the state where the opc ua server is running
		std::string state_;
		// name of the country where the opc ua server is running
		std::string country_;
		// number of years the certificate is valid
		uint32_t yearsValidFor_;
		// Key length in bits of the certificate to create; valid values
        // are 1024 and 2048 for RsaMin, and 2048, 3072 and 4096 for RsaSha256
		uint32_t keyLength_;
		// Defines the algorithm used to sign the certificate. Valid values are
		// RsaMin and RsaSha256. Applications that support the Basic128Rsa15 and
		// Basic256 profiles need a Certificate of type RsaMin. Applications that
		// support the Basic256Sha256 profile need a Certificate of type RsaSha256.
		std::string certificateType_;
		// ip address where the opc ua server is running
		std::vector<std::string> ipAddress_;
		// dns name where the opc ua server is running
		std::vector<std::string> dnsName_;
	};

}

#endif
