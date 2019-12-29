/*
   Copyright 2015-2019 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackCore_SignatureData_h__
#define __OpcUaStackCore_SignatureData_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/MemoryBuffer.h"
#include "OpcUaStackCore/Certificate/PrivateKey.h"
#include "OpcUaStackCore/Certificate/CryptoBase.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaString.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaByteString.h"

namespace OpcUaStackCore
{

	class DLLEXPORT SignatureData
	: public  Object
	{
	  public:
		typedef boost::shared_ptr<SignatureData> SPtr;

		SignatureData(void);
		virtual ~SignatureData(void);

		OpcUaStatusCode createSignature(
			MemoryBuffer& certificate,
			MemoryBuffer& nonce,
			PrivateKey& privateKey,
			CryptoBase& cryptoBase
		);

		OpcUaStatusCode createSignature(
			MemoryBuffer& certificate,
			PrivateKey& privateKey,
			CryptoBase& cryptoBase
		);

		OpcUaStatusCode verifySignature(
			MemoryBuffer& certificate,
			MemoryBuffer& nonce,
			PublicKey& publicKey,
			CryptoBase& cryptoBase
		);

		OpcUaStatusCode verifySignature(
			MemoryBuffer& certificate,
			PublicKey& publicKey,
			CryptoBase& cryptoBase
		);

		void signature(const OpcUaByte* buf, OpcUaInt32 bufLen);
		void signature(OpcUaByte** buf, OpcUaInt32* bufLen) const;
		OpcUaByteString signature(void);
		void algorithm(const std::string& algorithm);
		std::string algorithm(void) const;

		bool opcUaBinaryEncode(std::ostream& os) const;
		bool opcUaBinaryDecode(std::istream& is);

	  private:
		OpcUaByteString signature_;
		OpcUaString algorithm_;
		
	};
}

#endif
