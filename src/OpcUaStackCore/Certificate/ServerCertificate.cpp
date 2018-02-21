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

#include <OpcUaStackCore/Certificate/ServerCertificate.h>

namespace OpcUaStackCore
{

	ServerCertificate::ServerCertificate(void)
	: certificateTrustListLocation_("")
	, certificateRejectListLocation_("")
	, certificateRevocationListLocation_("")
	, issuersCertificatesLocation_("")
	, issuersRevocationListLocation_("")
	, privateKeyLocation_("")
	{
	}

	ServerCertificate::~ServerCertificate(void)
	{
	}

	bool
	ServerCertificate::init(void)
	{
		// FIXME: todo
		return true;
	}

	bool
	ServerCertificate::cleanup(void)
	{
		// FIXME: todo
		return true;
	}

	void
	ServerCertificate::certificateTrustListLocation(const std::string& certificateTrustListLocation)
	{
		certificateTrustListLocation_ = certificateTrustListLocation;
	}

	std::string&
	ServerCertificate::certificateTrustListLocation(void)
	{
		return certificateTrustListLocation_;
	}

	void
	ServerCertificate::certificateRejectListLocation(const std::string& certificateRejectListLocation)
	{
		certificateRejectListLocation_ = certificateRejectListLocation;
	}

	std::string&
	ServerCertificate::certificateRejectListLocation(void)
	{
		return certificateRejectListLocation_;
	}

	void
	ServerCertificate::certificateRevocationListLocation(const std::string& certificateRevocationListLocation)
	{
		certificateRevocationListLocation_ = certificateRevocationListLocation;
	}

	std::string&
	ServerCertificate::certificateRevocationListLocation(void)
	{
		return certificateRevocationListLocation_;
	}

	void
	ServerCertificate::issuersCertificatesLocation(const std::string& issuersCertificatesLocation)
	{
		issuersCertificatesLocation_ = issuersCertificatesLocation;
	}

	std::string&
	ServerCertificate::issuersCertificatesLocation(void)
	{
		return issuersCertificatesLocation_;
	}

	void
	ServerCertificate::issuersRevocationListLocation(const std::string& issuersRevocationListLocation)
	{
		issuersRevocationListLocation_ = issuersRevocationListLocation;
	}

	std::string&
	ServerCertificate::issuersRevocationListLocation(void)
	{
		return issuersRevocationListLocation_;
	}

	void
	ServerCertificate::privateKeyLocation(const std::string& privateKeyLocation)
	{
		privateKeyLocation_ = privateKeyLocation;
	}

	std::string&
	ServerCertificate::privateKeyLocation(void)
	{
		return privateKeyLocation_;
	}

}
