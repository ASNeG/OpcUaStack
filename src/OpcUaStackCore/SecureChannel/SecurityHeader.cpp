/*
   Copyright 2015-2021 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   Informationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Kai Huebl (kai@huebl-sgh.de)
 */

#include "OpcUaStackCore/SecureChannel/SecurityHeader.h"

namespace OpcUaStackCore
{

	bool
	SecurityHeader::opcUaBinaryEncode(
		std::ostream& os,
		const OpcUaByteString& securityPolicyUri,
		CertificateChain& certificateChain,
		OpcUaByteString& receiverCertificateThumbprint
	)
	{
		bool rc = true;

		// encode security header
		rc &= securityPolicyUri.opcUaBinaryEncode(os);
		rc &= certificateChain.opcUaBinaryEncode(os);
		rc &= receiverCertificateThumbprint.opcUaBinaryEncode(os);

		return rc;
	}

	bool
	SecurityHeader::opcUaBinaryDecode(
		std::istream& is,
		OpcUaByteString& securityPolicyUri,
		CertificateChain& certificateChain,
		OpcUaByteString& receiverCertificateThumbprint
	)
	{
		bool rc = true;

		// decode
		rc &= securityPolicyUri.opcUaBinaryDecode(is);
		rc &= certificateChain.opcUaBinaryDecode(is);
		rc &= receiverCertificateThumbprint.opcUaBinaryDecode(is);

		return rc;
	}

}	
