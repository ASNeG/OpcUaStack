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

		// FIXME: todo

		return Success;
	}

	OpcUaStatusCode
	ValidateCertificate::verifyCertificateStructure(OpcUaByteString& certificateChain)
	{

		if (!CertificateChain_.fromByteString(certificateChain)) {
			return BadCertificateInvalid;
		}

		return Success;
	}

}
