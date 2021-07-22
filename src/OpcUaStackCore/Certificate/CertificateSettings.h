/*
   Copyright 2019-2021 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   CertificateSettingsrmationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Kai Huebl (kai@huebl-sgh.de)
 */

#ifndef __OpcUaStackCore_CertificateSettings_h__
#define __OpcUaStackCore_CertificateSettings_h__

#include <vector>
#include <string>
#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"

namespace OpcUaStackCore
{

	class DLLEXPORT CertificateSettings
	{
	  public:
		typedef boost::shared_ptr<CertificateSettings> SPtr;

		CertificateSettings(void);
		~CertificateSettings(void);

		void enable(bool enable);
		bool enable(void);
		void generateCertificate(bool generateCertificate);
		bool generateCertificate(void);
		void serverUri(const std::string& serverUri);
		std::string& serverUri(void);
		void serverName(const std::string& serverName);
		std::string& serverName(void);
		void commonName(const std::string& commonName);
		std::string& commonName(void);
		void domainComponent(const std::string& domainComponent);
		std::string& domainComponent(void);
		void organization(const std::string& organization);
		std::string& organization(void);
		void organizationUnit(const std::string& organizationUnit);
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
		void email(const std::string& email);
		std::string& email(void);

	  private:
		bool enable_;
		bool generateCertificate_;
		std::string serverUri_;
		std::string serverName_;
		std::string commonName_;						//!< name of the application
		std::string domainComponent_;					//!< hostname of the machine
		std::string organization_;						//!< organization using the opc ua server
		std::string organizationUnit_;					//!< organization unit unsing the opc ua server
		std::string locality_;							//!< name of the location where the opc ua server is running
		std::string state_;								//!< name of the state where the opc ua server is running
		std::string country_;							//!< name of the country where the opc ua server is running
		uint32_t yearsValidFor_;						//!< number of years the certificate is valid
		uint32_t keyLength_;							//!< Key length in bits of the certificate to create; valid
														//!< values are 1024 and 2048 for RsaMin, and 2048, 3072 and
														//!< 4096 for RsaSha256
		std::string certificateType_;					//!< Defines the algorithm used to sign the certificate. Valid
														//!< values are RsaMin and RsaSha256. Applications that support
														//!< the Basic128Rsa15 and Basic256 profiles need a Certificate
														//!< of type RsaMin. Applications that support the Basic256Sha256
														//!< profile need a Certificate of type RsaSha256.
		std::vector<std::string> ipAddress_;			//!< ip address where the opc ua server is running
		std::vector<std::string> dnsName_;				//!< dns name where the opc ua server is running
		std::string email_;								//!< email of the application owner
	};

}

#endif
