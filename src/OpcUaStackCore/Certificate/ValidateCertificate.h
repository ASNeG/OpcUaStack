/*
   Copyright 2017-2019 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   Informationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.


 */

#ifndef __OpcUaStackCore_ValidateCertificate_h__
#define __OpcUaStackCore_ValidateCertificate_h__

#include "OpcUaStackCore/BuildInTypes/OpcUaStatusCode.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaByteString.h"
#include "OpcUaStackCore/Certificate/CertificateChain.h"
#include "OpcUaStackCore/Certificate/CertificateManager.h"

namespace OpcUaStackCore
{

	class DLLEXPORT ValidateCertificate
	{
	  public:
		ValidateCertificate(void);
		~ValidateCertificate(void);

		void certificateManager(CertificateManager::SPtr& certificateManager);
		void hostname(const std::string& hostname);
		void uri(const std::string& uri);

		OpcUaStatusCode validateCertificate(
			OpcUaByteString& certificateChain
		);
		OpcUaStatusCode validateCertificate(
			CertificateChain& certificateChain
		);

	  private:
		OpcUaStatusCode validateCertificate(void);
		OpcUaStatusCode verifyCertificateStructure(OpcUaByteString& certificateChain);
		OpcUaStatusCode buildCertificateChain(void);
		OpcUaStatusCode validateSelfSigned(void);
		OpcUaStatusCode validateCA(void);
		OpcUaStatusCode validateSignature(void);
		OpcUaStatusCode securityPolicyCheck(void);
		OpcUaStatusCode trustListCheck(void);
		OpcUaStatusCode validityPeriod(void);
		OpcUaStatusCode hostName(void);
		OpcUaStatusCode URI(void);
		OpcUaStatusCode certificateUsage(void);
		OpcUaStatusCode findRevocationList(void);
		OpcUaStatusCode revocationCheck(void);

		CertificateChain certificateChain_;
		CertificateManager::SPtr certificateManager_;
		std::string hostname_;
		std::string uri_;
	};

}

#endif
