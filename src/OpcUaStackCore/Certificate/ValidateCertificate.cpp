/*
   Copyright 2019-2020 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   ValidateCertificatermationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Kai Huebl (kai@huebl-sgh.de)
 */

#include "OpcUaStackCore/Certificate/ValidateCertificate.h"

namespace OpcUaStackCore
{

	ValidateCertificate::ValidateCertificate(void)
	: certificateChain_()
	, certificateManager_()
	, hostname_("")
	, uri_("")
	{
	}

	ValidateCertificate::~ValidateCertificate(void)
	{
	}

	void
	ValidateCertificate::certificateManager(
		CertificateManager::SPtr& certificateManager
	)
	{
		certificateManager_ = certificateManager;
	}

	void
	ValidateCertificate::hostname(const std::string& hostname)
	{
		hostname_ = hostname;
	}

	void
	ValidateCertificate::uri(const std::string& uri)
	{
		uri_ = uri;
	}

	OpcUaStatusCode
	ValidateCertificate::validateCertificate(
		CertificateChain& certificateChain
	)
	{
		certificateChain_ = certificateChain;
		return validateCertificate();
	}

	OpcUaStatusCode
	ValidateCertificate::validateCertificate(
		OpcUaByteString& certificateChain
	)
	{
		assert(certificateManager_ != nullptr);

		OpcUaStatusCode statusCode;

		// verify certificate structure
		statusCode = verifyCertificateStructure(certificateChain);
		if (statusCode != Success) {
			Log(Error, "verify certificate structure error");
			return statusCode;
		}

		return validateCertificate();
	}

	OpcUaStatusCode
	ValidateCertificate::validateCertificate(void)
	{
		// build certificate chain
		auto statusCode = buildCertificateChain();
		if (statusCode != Success) {
			Log(Error, "build certificate chain error");
			return statusCode;
		}

		// check self signed certificate
		statusCode = validateSelfSigned();
		if (statusCode != Success) {
			Log(Error, "validate self signed error");
			return statusCode;
		}

		// check CA information in certificates
		statusCode = validateCA();
		if (statusCode != Success) {
			Log(Error, "validate ca error");
			return statusCode;
		}

		// validate signature
		statusCode = validateSignature();
		if (statusCode != Success) {
			Log(Error, "validate signature error");
			return statusCode;
		}

		// security policy check
		statusCode = securityPolicyCheck();
		if (statusCode != Success) {
			Log(Error, "security policy check error");
			return statusCode;
		}

		// trust list check
		statusCode = trustListCheck();
		if (statusCode != Success) {
			Log(Error, "trust list check error");
			return statusCode;
		}

		// Validity Period
		statusCode = validityPeriod();
		if (statusCode != Success) {
			Log(Error, "validity period error");
			return statusCode;
		}

		// Host Name
		statusCode = hostName();
		if (statusCode != Success) {
			Log(Error, "host name error")
				.parameter("Hostname", hostname_);
			return statusCode;
		}

		// URI
		statusCode = URI();
		if (statusCode != Success) {
			Log(Error, "uri error")
				.parameter("Uri", uri_);
			return statusCode;
		}

		// Certificate Usage
		statusCode = certificateUsage();
		if (statusCode != Success) {
			Log(Error, "certificate usage error");
			return statusCode;
		}

		// Find RevocationList
		statusCode = findRevocationList();
		if (statusCode != Success) {
			Log(Error, "find revocation list error");
			return statusCode;
		}

		// Revocation Check
		statusCode = revocationCheck();
		if (statusCode != Success) {
			Log(Error, "revocation check error");
			return statusCode;
		}

		return Success;
	}

	OpcUaStatusCode
	ValidateCertificate::verifyCertificateStructure(OpcUaByteString& certificateChain)
	{
		//
		// Certificate Structure:
		// The Certificate structure is verified. This error may not be suppressed.
		// If this check fails on the Server side, the error Bad_SecurityChecksFailed
		// shall be reported back to the Client.
		//

		if (!certificateChain_.fromByteString(certificateChain)) {
			Log(Debug, "certificate chain invalid");
			return BadCertificateInvalid;
		}

		return Success;
	}

	OpcUaStatusCode
	ValidateCertificate::buildCertificateChain(void)
	{
		//
		// Build Certificate Chain:
		// The trust chain for the Certificate is created. An error during the chain
		// creation may not be suppressed. If this check fails on the Server side,
		// the error Bad_SecurityChecksFailed shall be reported back to the Client.
		//

		// check number of certificates in certificate chain
		if (certificateChain_.certificateVec().empty()) {
			Log(Error, "certificate chain empty");
			return BadSecurityChecksFailed;
		}

		// Check certificates in chain. A subject in certificate n must be equal to
		// an issuer in certificate n+1.
		auto size = certificateChain_.certificateVec().size();
		for (auto idx = 1; idx < size; idx++) {

			// get issuer from first certificate
			Identity issuer;
			if (!certificateChain_.certificateVec()[idx-1]->getIssuer(issuer)) {
				Log(Error, "read issuer from certificate error")
					.parameter("Idx", idx);
				return BadSecurityChecksFailed;
			}

			// get subject from second certificate
			Identity subject;
			if (!certificateChain_.certificateVec()[idx]->getSubject(subject)) {
				Log(Error, "read subject from certificate error")
					.parameter("Idx", idx);
				return BadSecurityChecksFailed;
			}

			// issuer and subject must be equal
			if (issuer != subject) {
				Log(Error, "issuer not equal following subject in certificate chain")
					.parameter("Idx", idx);
				issuer.log("Issuer");
				subject.log("Subject");
				return BadSecurityChecksFailed;
			}
		}

		// We are looking for further certificates until the certificate
		// chain is complete
		auto actCertificate = certificateChain_.certificateVec()[size-1];
		do {
			if (actCertificate->isSelfSigned()) {

				// Do several certificates exist?. The last certificate must be a
				// root ca certificate.
				if (certificateChain_.size() > 1) {
					if (!actCertificate->isCaRoot()) {
						return BadSecurityChecksFailed;
					}

				}

				return Success;
			}

			// get issuer from actual certificate
			Identity issuer;
			actCertificate->getIssuer(issuer);

			// search ca certificate from trusted folder
			auto certificate = certificateManager_->getTrustedCertificate(issuer);
			if (certificate.get() != nullptr) {
				certificateChain_.certificateVec().push_back(certificate);
				actCertificate = certificate;
				continue;
			}

			// search issuer certificate in issuer certificate folder
			certificate = certificateManager_->getImCertificate(issuer);
			if (certificate.get() != nullptr) {
				certificateChain_.certificateVec().push_back(certificate);
				actCertificate = certificate;
				continue;
			}

			// no further certificate found
			Log(Debug, "no further issuer certificate found");
			issuer.log("Last issuer");
			return Success;
		} while (BadSecurityChecksFailed);

		return Success;
	}

	OpcUaStatusCode
	ValidateCertificate::validateSelfSigned(void)
	{
		// check number of certificates in certificate chain
		if (certificateChain_.certificateVec().empty()) {
			Log(Error, "certificate chain empty");
			return BadSecurityChecksFailed;
		}

		//
		// Check if the certificate is a self signed certificate. If yes, do
		// no further checks.
		//
		auto selfSigned0 = certificateChain_.certificateVec()[0]->isSelfSigned();
		auto caFlag0 = certificateChain_.certificateVec()[0]->isCaCertificate();
		auto size = certificateChain_.certificateVec().size();
		if (size == 1) {

			// There is only one certificate in certificate chain.

			if (selfSigned0) {

				// The certificate in the certificate chain is a self signed certificate.

				if (caFlag0) {
					// The self signed certificate contains a CA flag. That is not correct.

					Log(Error, "found self signed certificate with ca flag");

					// get subject from first certificate
					Identity subject;
					if (certificateChain_.certificateVec()[0]->getSubject(subject)) {
						subject.log("Subject");
					}

					return BadSecurityChecksFailed;
				}

				// The self signed certificate is correct.
				return Success;
			}
			else {
				// The certificate chain contains only one certificate. The certificate
				// is not a self signed certificate. That is not correct.

				Log(Error, "the only certificate in certificate chain is not a self signed certificate");

				// get subject from first certificate
				Identity subject;
				if (certificateChain_.certificateVec()[0]->getSubject(subject)) {
					subject.log("Subject");
				}

				return BadSecurityChecksFailed;
			}
		}

		return Success;
	}

	OpcUaStatusCode
	ValidateCertificate::validateCA(void)
	{
		// check number of certificates in certificate chain
		if (certificateChain_.certificateVec().empty()) {
			Log(Error, "certificate chain empty");
			return BadSecurityChecksFailed;
		}

		//
		// The first certificate in the certificate chain must not contain the
		// CA flag.
		//
		auto caFlag0 = certificateChain_.certificateVec()[0]->isCaCertificate();
		if (caFlag0) {
			Log(Error, "first certificate in certificate chain contains CA flag");

			// get subject from first certificate
			Identity subject;
			if (certificateChain_.certificateVec()[0]->getSubject(subject)) {
				subject.log("Subject");
			}

			return BadSecurityChecksFailed;
		}

		//
		// With the exception of the first certificate, all certificates in
		// the certificate chain must contain the CA flag.
		//
		auto size = certificateChain_.certificateVec().size();
		for (auto idx = 1; idx < size; idx++) {
			auto caFlag = certificateChain_.certificateVec()[idx]->isCaCertificate();

			if (!caFlag) {
				Log(Error, "certificate in certificate chain do not contain CA flag");

				// get subject from certificate
				Identity subject;
				if (certificateChain_.certificateVec()[idx]->getSubject(subject)) {
					subject.log("Subject");
				}

				return BadSecurityChecksFailed;
			}
		}

		//
		// The last certificate in the certificate must be a root ca certificate
		//
		if (size == 1) {
			// This check is done in function validateSelfSigned
			return Success;
		}
		auto caRoot = certificateChain_.certificateVec()[size-1]->isCaRoot();
		if (!caRoot) {
			Log(Error, "last certificate in certificate chain is not a root ca certificate");

			// get subject from certificate
			Identity subject;
			if (certificateChain_.certificateVec()[size-1]->getSubject(subject)) {
				subject.log("Subject");
			}

			return BadSecurityChecksFailed;
		}

		return Success;
	}

	OpcUaStatusCode
	ValidateCertificate::validateSignature(void)
	{
		//
		// Signature:
		// A Certificate with an invalid signature shall always be rejected.
		// A Certificate signature is invalid if the Issuer Certificate is unknown.
		// A self-signed Certificate is its own issuer. If this check fails on the
		// Server side, the error Bad_SecurityChecksFailed shall be reported back to
		// the Client.
		//

		auto size = certificateChain_.certificateVec().size();
		for (auto idx = 1; idx < size; idx++) {
			auto subjectCertificate = certificateChain_.certificateVec()[idx-1];
			auto issuerCertificate = certificateChain_.certificateVec()[idx];

			if (!subjectCertificate->verifySignature(*issuerCertificate.get())) {
				Log(Error, "verify signature error");

				Identity subject;
				subjectCertificate->getSubject(subject);
				subject.log("Subject");

				Identity issuer;
				subjectCertificate->getIssuer(issuer);
				issuer.log("Issuer");

				return BadCertificateInvalid;
			}
		}

		return Success;
	}

	OpcUaStatusCode
	ValidateCertificate::securityPolicyCheck(void)
	{
		//
		// Security Policy Check:
		// A Certificate signature shall comply with the CertificateSignatureAlgorithm,
		// MinAsymmetricKeyLength and MaxAsymmetricKeyLength requirements for the used
		// SecurityPolicy defined in Part 7. If this check fails on the Server side,
		// the error Bad_SecurityChecksFailed shall be reported back to the Client.
		// This error may be suppressed.
		//

		// FIXME: todo - Bad_CertificatePolicyCheckFailed

		return Success;
	}

	OpcUaStatusCode
	ValidateCertificate::trustListCheck(void)
	{
		bool trust = false;
		bool untrust = false;

		//
		// Trust List Check:
		// If the Application Instance Certificate is not trusted and none of the CA
		// Certificates in the chain is trusted, the result of the Certificate
		// validation shall be Bad_CertificateUntrusted. If this check fails on the
		// Server side, the error Bad_SecurityChecksFailed shall be reported back to
		// the Client.
		//
		// No certificate in the certificate chain may be in a untrust folder.
		//

		for (auto certificate : certificateChain_.certificateVec()) {

			// check certificate trust list location
			if (certificateManager_->isCertificateInTrustedList(certificate)) {
				trust = true;
				continue;
			}

			// check certificate issuer list location
			if (certificateManager_->isCertificateInIssuerList(certificate)) {
				trust = true;
				continue;
			}

			// check certificate reject location and certificate revocation
			// list locations
			if (certificateManager_->isCertificateInRevocationList(certificate)) {
				untrust = true;
				continue;
			}

		}

		if (trust && !untrust) {
			return Success;
		}
		return BadCertificateInvalid;
	}

	OpcUaStatusCode
	ValidateCertificate::validityPeriod(void)
	{
		//
		// Validity Period:
		// The current time shall be after the start of the validity period and before
		// the end. This error may be suppressed.
		//
		auto now = boost::posix_time::microsec_clock::universal_time();
		for (auto certificate : certificateChain_.certificateVec()) {
			CertificateInfo info;
			if (!certificate->getInfo(info)) {
				certificate->log(Error, "get info error");
				return BadCertificateTimeInvalid;
			}

			Identity subject;
			certificate->getSubject(subject);
			if ((info.validFrom() > now) || (info.validTime() < now)) {
				Log(Debug, "certificate period info")
					.parameter("FromTime", info.validFrom())
					.parameter("Time", now)
					.parameter("ToTime", info.validTime());
				return BadCertificateTimeInvalid;
			}
		}

		return Success;
	}

	OpcUaStatusCode
	ValidateCertificate::hostName(void)
	{
		//
		// Host Name:
		// The HostName in the URL used to connect to the Server shall be the same as
		// one of the HostNames specified in the Certificate. This check is skipped
		// for CA Certificates. This check is skipped for Server side validation. This
		// error may be suppressed.
		//
		if (hostname_.empty()) {
			return Success;
		}

		// get info from certificate
		auto certificate = certificateChain_.certificateVec()[0];
		CertificateInfo info;
		if (!certificate->getInfo(info)) {
			certificate->log(Error, "get info error");
			return BadCertificateHostNameInvalid;
		}

		// check dns names
		std::stringstream ss;
		for (auto dnsName : info.dnsNames()) {
			if (dnsName == hostname_) {
				return Success;
			}

			if (!ss.str().empty()) ss << ", ";
			ss << dnsName;
		}

		// check ip addresses
		for (auto ip : info.ipAddresses()) {
			if (ip == hostname_) {
				return Success;
			}

			if (!ss.str().empty()) ss << ", ";
			ss << ip;
		}

		Log(Debug, "hosts and ips")
		    .parameter("List", ss.str());
		return BadCertificateHostNameInvalid;
	}

	OpcUaStatusCode
	ValidateCertificate::URI(void)
	{
		//
		// URI:
		// Application and Software Certificates contain an application or product
		// URI that shall match the URI specified in the ApplicationDescription
		// provided with the Certificate. This check is skipped for CA Certificates.
		// This error may not be suppressed. The gatewayServerUri is used to validate
		// an Application Certificate when connecting to a Gateway Server (see 7.1).
		//

		if (uri_.empty()) {
			return Success;
		}

		// get info from certificate
		auto certificate = certificateChain_.certificateVec()[0];
		CertificateInfo info;
		if (!certificate->getInfo(info)) {
			certificate->log(Error, "get info error");
			return BadCertificateUriInvalid;
		}

		// check uri
		if (info.uri() == uri_) {
			return Success;
		}

		return BadCertificateUriInvalid;
	}

	OpcUaStatusCode
	ValidateCertificate::certificateUsage(void)
	{
		//
		// Certificate Usage:
		// Each Certificate has a set of uses for the Certificate (see Part 6). These
		// uses shall match use requested for the Certificate (i.e. Application,
		// Software or CA). This error may be suppressed unless the Certificate
		// indicates that the usage is mandatory
		//
		// Shall include:
		//   Digital Signature
		//   Non Repudiation
		//   Key Encipherment
		//   Data Encipherment
		//

		// get info from certificate
		auto certificate = certificateChain_.certificateVec()[0];
		CertificateInfo info;
		if (!certificate->getInfo(info)) {
			certificate->log(Error, "get info error");
			return BadCertificateUseNotAllowed;
		}

		// check key usage
		if (info.keyUsage().find("Digital Signature") == std::string::npos) {
			return BadCertificateUseNotAllowed;
		}
		if (info.keyUsage().find("Non Repudiation") == std::string::npos) {
			return BadCertificateUseNotAllowed;
		}
		if (info.keyUsage().find("Key Encipherment") == std::string::npos) {
			return BadCertificateUseNotAllowed;
		}
		if (info.keyUsage().find("Data Encipherment") == std::string::npos) {
			return BadCertificateUseNotAllowed;
		}

		return Success;
	}

	OpcUaStatusCode
	ValidateCertificate::findRevocationList(void)
	{
		//
		// Find Revocation List:
		// Each CA Certificate may have a revocation list. This check fails if this
		// list is not available (i.e. a network interruption prevents the application
		// from accessing the list). No error is reported if the Administrator disables
		// revocation checks for a CA Certificate. This error may be suppressed.
		//


		return Success;
	}

	OpcUaStatusCode
	ValidateCertificate::revocationCheck(void)
	{
		//
		// Revocation Check:
		// The Certificate has been revoked and may not be used. This error may not be
		// suppressed. If this check fails on the Server side, the error
		// Bad_SecurityChecksFailed shall be reported back to the Client.
		//

		for (auto certificate : certificateChain_.certificateVec()) {
			if (certificateManager_->isCertificateInRevocationList(certificate)) {
				return BadCertificateRevoked;
			}
		}

		return Success;
	}

}
