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

#include "OpcUaStackCore/Certificate/CertificateStore.h"

namespace OpcUaStackCore
{

	CertificateStore::CertificateStore(void)
	: certificateTrustListLocation_("")
	, certificateRejectListLocation_("")
	, certificateRevocationListLocation_("")
	, issuersCertificatesLocation_("")
	, issuersRevocationListLocation_("")
	, privateKeyLocation_("")
	{
	}

	CertificateStore::~CertificateStore(void)
	{
	}

	bool
	CertificateStore::init(void)
	{
		// FIXME: todo
		return true;
	}

	bool
	CertificateStore::cleanup(void)
	{
		// FIXME: todo
		return true;
	}

	void
	CertificateStore::certificateTrustListLocation(const std::string& certificateTrustListLocation)
	{
		certificateTrustListLocation_ = certificateTrustListLocation;
	}

	std::string&
	CertificateStore::certificateTrustListLocation(void)
	{
		return certificateTrustListLocation_;
	}

	void
	CertificateStore::certificateRejectListLocation(const std::string& certificateRejectListLocation)
	{
		certificateRejectListLocation_ = certificateRejectListLocation;
	}

	std::string&
	CertificateStore::certificateRejectListLocation(void)
	{
		return certificateRejectListLocation_;
	}

	void
	CertificateStore::certificateRevocationListLocation(const std::string& certificateRevocationListLocation)
	{
		certificateRevocationListLocation_ = certificateRevocationListLocation;
	}

	std::string&
	CertificateStore::certificateRevocationListLocation(void)
	{
		return certificateRevocationListLocation_;
	}

	void
	CertificateStore::issuersCertificatesLocation(const std::string& issuersCertificatesLocation)
	{
		issuersCertificatesLocation_ = issuersCertificatesLocation;
	}

	std::string&
	CertificateStore::issuersCertificatesLocation(void)
	{
		return issuersCertificatesLocation_;
	}

	void
	CertificateStore::issuersRevocationListLocation(const std::string& issuersRevocationListLocation)
	{
		issuersRevocationListLocation_ = issuersRevocationListLocation;
	}

	std::string&
	CertificateStore::issuersRevocationListLocation(void)
	{
		return issuersRevocationListLocation_;
	}

	void
	CertificateStore::privateKeyLocation(const std::string& privateKeyLocation)
	{
		privateKeyLocation_ = privateKeyLocation;
	}

	std::string&
	CertificateStore::privateKeyLocation(void)
	{
		return privateKeyLocation_;
	}

}
