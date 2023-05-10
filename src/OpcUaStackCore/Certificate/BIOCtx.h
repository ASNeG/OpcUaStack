/*
   Copyright 2023 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   BIOCtxrmationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Kai Huebl (kai@huebl-sgh.de)
 */

#ifndef __OpcUaStackCore_BIOCtx_h__
#define __OpcUaStackCore_BIOCtx_h__

#include <openssl/pem.h>

#include "OpcUaStackCore/Base/MemoryBuffer.h"

namespace OpcUaStackCore
{

	class DLLEXPORT BIOCtx
	{
	  public:
		BIOCtx(void);
		BIOCtx(MemoryBuffer& memoryBuffer);
		~BIOCtx(void);

		bool getMemoryBuffer(MemoryBuffer& memoryBuffer);
		bool setMemoryBuffer(MemoryBuffer& memoryBuffer);
		BIO* bio(void);

	  private:
		BIO* bio_ = nullptr;

	};

}

#endif
