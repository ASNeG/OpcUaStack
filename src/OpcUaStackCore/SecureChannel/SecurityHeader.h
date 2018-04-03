/*
   Copyright 2015 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackCore_SecurityHeader_h__
#define __OpcUaStackCore_SecurityHeader_h__

#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaByteString.h"
#include "OpcUaStackCore/Certificate/CertificateChain.h"

namespace OpcUaStackCore
{

	class DLLEXPORT SecurityHeader
	: public  Object
	{
	  public:
		typedef boost::shared_ptr<SecurityHeader> SPtr;

		SecurityHeader(void);
		virtual ~SecurityHeader(void);

		void securityPolicyUri(OpcUaByte **buf, OpcUaInt32* bufLen) const;
		void securityPolicyUri(OpcUaByte *buf, OpcUaInt32 bufLen);
		OpcUaByteString& securityPolicyUri(void);
		void senderCertificate(OpcUaByte **buf, OpcUaInt32* bufLen) const;
		void senderCertificate(OpcUaByte *buf, OpcUaInt32 bufLen);
		OpcUaByteString& senderCertificate(void);
		void receiverCertificateThumbprint(OpcUaByte *buf, OpcUaInt32 bufLen);
		void receiverCertificateThumbprint(OpcUaByte **buf, OpcUaInt32* bufLen) const;
		void receiverCertificateThumbprint(OpcUaByteString& receiverCertificateThumbprint);
		OpcUaByteString& receiverCertificateThumbprint(void);
		CertificateChain& certificateChain(void);

		bool isEncryptionEnabled(void);
		bool isSignatureEnabled(void);

		bool opcUaBinaryEncode(std::ostream& os) const;
		bool opcUaBinaryDecode(std::istream& is);

	  private:
		OpcUaByteString securityPolicyUri_;
		OpcUaByteString senderCertificate_;
		OpcUaByteString receiverCertificateThumbprint_;
		CertificateChain certificateChain_;
	};

}

#endif
