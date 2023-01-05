/*
   Copyright 2023 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   Informationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Kai Huebl (kai@huebl-sgh.de), Aleksey Timin (atimin@gmail.com)
 */

#ifndef __OpcUaStackCore_CSR_h__
#define __OpcUaStackCore_CSR_h__

#include <boost/shared_ptr.hpp>

#include <openssl/x509.h>

#include "OpcUaStackCore/Base/MemoryBuffer.h"
#include "OpcUaStackCore/Certificate/OpenSSLError.h"
#include "OpcUaStackCore/Certificate/Identity.h"
#include "OpcUaStackCore/Certificate/PublicKey.h"
#include "OpcUaStackCore/Certificate/PrivateKey.h"
#include "OpcUaStackCore/Certificate/CertificateInfo.h"
#include "OpcUaStackCore/Certificate/UserExtension.h"

namespace OpcUaStackCore
{

	class DLLEXPORT CSR
	: public OpenSSLError
	{
	  public:
		typedef boost::shared_ptr<CSR> SPtr;

		CSR(void);
		~CSR(void);

		bool createCSR(
			Identity& subject,
			CertificateInfo& info,
			PublicKey& publicKey,
			PrivateKey& privateKey,
			UserExtension::Vec* userExtensionVec = nullptr
		);

		bool getSubject(Identity& subject);
		bool getInfo(CertificateInfo& info);
		bool getPublicKey(PublicKey& publicKey);
		bool getUserExtension(UserExtension::SPtr& userExtension);

		bool toDERBuf(MemoryBuffer& derBuf);
		bool fromDERBuf(MemoryBuffer& derBuf);

		bool validateSignature(PublicKey& publicKey);

	  private:
		X509_REQ* req_ = nullptr;
	};

}

#endif
