/*
   Copyright 2018 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackCore_CryptoRSA_h__
#define __OpcUaStackCore_CryptoRSA_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Certificate/OpenSSLError.h"
#include "OpcUaStackCore/Certificate/PublicKey.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaStatusCode.h"

namespace OpcUaStackCore
{

	class DLLEXPORT CryptoRSA
	: public OpenSSLError
	{
	  public:
		CryptoRSA(void);
		~CryptoRSA(void);

		OpcUaStatusCode publicEncrypt(
		    char*      plainTextBuf,	 // [in]  plain text to encrypt
		    uint32_t   plainTextLen,   	 // [in]  length of plain text to encrypt
		    PublicKey* publicKey,		 // [in]  public key used to encrypt the plain text
		    int16_t    padding,          // [in]  paddin scheme used for filling empty bytes after encryption
		    char*      encryptedTextBuf, // [out] encrypted text
		    int32_t*   encryptedTextLen  // [out] length of the encryped text
		);

	};
}

#endif
