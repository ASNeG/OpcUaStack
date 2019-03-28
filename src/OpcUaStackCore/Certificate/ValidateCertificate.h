/*
   Copyright der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   ValidateCertificatermationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Kai Huebl (kai@huebl-sgh.de)
 */

#ifndef __OpcUaStackCore_ValidateCertificate_h__
#define __OpcUaStackCore_ValidateCertificate_h__

#include "OpcUaStackCore/BuildInTypes/OpcUaStatusCode.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaByteString.h"
#include "OpcUaStackCore/Certificate/CertificateChain.h"

using namespace OpcUaStackCore;

namespace OpcUaStackCore
{

	class DLLEXPORT ValidateCertificate
	{
	  public:
		ValidateCertificate(void);
		~ValidateCertificate(void);

		OpcUaStatusCode validateCertificate(
			OpcUaByteString& certificateChain
		);

	  private:
		OpcUaStatusCode verifyCertificateStructure(OpcUaByteString& certificateChain);
		OpcUaStatusCode buildCertificateChain(void);
		OpcUaStatusCode validateSignature(void);
		OpcUaStatusCode securityPolicyCheck(void);
		OpcUaStatusCode trustListCheck(void);
		OpcUaStatusCode validityPeriod(void);
		OpcUaStatusCode hostName(void);
		OpcUaStatusCode URI(void);
		OpcUaStatusCode certificateUsage(void);
		OpcUaStatusCode findRevocationList(void);
		OpcUaStatusCode revocationCheck(void);

		CertificateChain CertificateChain_;
	};

}

#endif
