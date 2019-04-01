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
	{
	}

	ValidateCertificate::~ValidateCertificate(void)
	{
	}

	OpcUaStatusCode
	ValidateCertificate::validateCertificate(
		OpcUaByteString& certificateChain
	)
	{
		OpcUaStatusCode statusCode;

		// verify certificate structure
		statusCode = verifyCertificateStructure(certificateChain);
		if (statusCode != Success) {
			return statusCode;
		}

		// build certificate chain
		statusCode = buildCertificateChain();
		if (statusCode != Success) {
			return statusCode;
		}

		// validate signature
		statusCode = validateSignature();
		if (statusCode != Success) {
			return statusCode;
		}

		// security policy check
		statusCode = securityPolicyCheck();
		if (statusCode != Success) {
			return statusCode;
		}

		// trust list check
		statusCode = trustListCheck();
		if (statusCode != Success) {
			return statusCode;
		}

		// Validity Period
		statusCode = validityPeriod();
		if (statusCode != Success) {
			return statusCode;
		}

		// Host Name
		statusCode = hostName();
		if (statusCode != Success) {
			return statusCode;
		}

		// URI
		statusCode = URI();
		if (statusCode != Success) {
			return statusCode;
		}

		// Certificate Usage
		statusCode = certificateUsage();
		if (statusCode != Success) {
			return statusCode;
		}

		// Find RevocationList
		statusCode = findRevocationList();
		if (statusCode != Success) {
			return statusCode;
		}

		// Revocation Check
		statusCode = revocationCheck();
		if (statusCode != Success) {
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

		if (!CertificateChain_.fromByteString(certificateChain)) {
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


		// FIXME: todo

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

		// FIXME: todo - BadCertificateInvalid

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

		// FIXME: todo - Bad_CertificateUntrusted

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

		// FIXME: todo - Bad_CertificateTimeInvalid

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
