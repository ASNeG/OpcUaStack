/*
   Copyright 2019 Kai Huebl (kai@huebl-sgh.de)

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

		// build certificate chain
		statusCode = buildCertificateChain();
		if (statusCode != Success) {
			Log(Error, "build certificate chain error");
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
			Log(Error, "host name error");
			return statusCode;
		}

		// URI
		statusCode = URI();
		if (statusCode != Success) {
			Log(Error, "uri error");
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

		// check number of certificates in cetificate chain
		if (certificateChain_.certificateVec().empty()) {
			Log(Error, "certificate chain empty");
			return BadSecurityChecksFailed;
		}

		// check certificates in chain
		auto size = certificateChain_.certificateVec().size();
		for (auto idx = 1; idx < size; idx++) {

			// get issuer from first certificate
			Identity issuer;
			if (!certificateChain_.certificateVec()[idx-1]->getIssuer(issuer)) {
				Log(Error, "read issuer from certificate error");
				return BadSecurityChecksFailed;
			}

			// get subject from second certificate
			Identity subject;
			if (!certificateChain_.certificateVec()[idx]->getSubject(subject)) {
				Log(Error, "read subject from certificate error");
				return BadSecurityChecksFailed;
			}

			// issuer and subject must be equal
			if (issuer != subject) {
				Log(Error, "issuer not equal following subject in certificate chain");
				issuer.log("Issuer");
				subject.log("Subject");
				return BadSecurityChecksFailed;
			}
		}

		auto actCertificate = certificateChain_.certificateVec()[size-1];
		do {
			if (actCertificate->isSelfSigned()) {
				return Success;
			}

			// get issuer from actual certificate
			Identity issuer;
			actCertificate->getIssuer(issuer);

			// search next issuer certificate in trusted folder
			auto certificate = certificateManager_->getTrustedCertificate(issuer);
			if (certificate.get() != nullptr) {
				certificateChain_.certificateVec().push_back(certificate);
				actCertificate = certificate;
				continue;
			}

			// search next issuer certificate in CA folder
			certificate = certificateManager_->getCACertificate(issuer);
			if (certificate.get() != nullptr) {
				certificateChain_.certificateVec().push_back(certificate);
				actCertificate = certificate;
				continue;
			}

			// no further certificate found
			Log(Debug, "no further certificate found");
			issuer.log("Last issuer");
			return Success;
		} while (true);

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
		//
		// Trust List Check:
		// If the Application Instance Certificate is not trusted and none of the CA
		// Certificates in the chain is trusted, the result of the Certificate
		// validation shall be Bad_CertificateUntrusted. If this check fails on the
		// Server side, the error Bad_SecurityChecksFailed shall be reported back to
		// the Client.
		//

		for (auto certificate : certificateChain_.certificateVec()) {
			if (certificateManager_->isCertificateInTrustedList(certificate)) {
				return Success;
			}

			if (certificateManager_->isCertificateInIssuerList(certificate)) {
				return Success;
			}
		}

		return Success;
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
			std::cout << subject.commonName() << " xxxx " << info.validFrom() << " xxxx " << now << " xxxx " << info.validTime() << std::endl;
			if (info.validFrom() > now) return BadCertificateTimeInvalid;
			if (info.validTime() < now) return BadCertificateTimeInvalid;
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

		// FIXME: todo - Bad_CertificateHostNameInvalid

		return Success;
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

		// FIXME: todo - Bad_CertificateUriInvalid

		return Success;
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

		// FIXME: todo - Bad_CertificateUseNotAllowed

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

		// FIXME: todo - Bad_CertificateRevocationUnknown

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

		// FIXME: todo - Bad_CertificateRevoked
		return Success;
	}

}
