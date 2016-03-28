/*
   Copyright 2016 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackCore_PkiRsaCrypt_h__
#define __OpcUaStackCore_PkiRsaCrypt_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Certificate/PkiRsaKey.h"

namespace OpcUaStackCore
{

	class DLLEXPORT PkiRsaCrypt
	: public PkiError
	{
	  public:
		PkiRsaCrypt(void);
		~PkiRsaCrypt(void);

		void padding(int padding);
		int padding(void);
		void pkiRsaKey(PkiRsaKey* pkiRsaKey);
		PkiRsaKey* pkiRsaKey(void);

		bool publicEncrypt(
			const char* data,
			uint32_t dataLen,
			char* encryptedData,
			int32_t& encryptedDataLen
		);

		bool privateDecrypt(
			const char* encryptedData,
			uint32_t encryptedDataLen,
			char* data,
			int32_t& dataLen
		);

	  private:
		int padding_;
		PkiRsaKey* pkiRsaKey_;
	};

}

#endif
