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

#ifndef __OpcUaStackCore_CryptoOpenSSLNONE_h__
#define __OpcUaStackCore_CryptoOpenSSLNONE_h__

#include <OpcUaStackCore/Certificate/CryptoBase.h>
#include "OpcUaStackCore/Base/os.h"

namespace OpcUaStackCore
{

	class DLLEXPORT CryptoOpenSSLNONE
	: public CryptoBase
	{
	  public:
		CryptoOpenSSLNONE(void);
		virtual ~CryptoOpenSSLNONE(void);

		virtual OpcUaStatusCode asymmetricDecrypt(
		    char*       	encryptedTextBuf,
			uint32_t		encryptedTextLen,
			PrivateKey&		privateKey,
			char*       	plainTextBuf,
			uint32_t*		plainTextLen
		);

	};

}

#endif
