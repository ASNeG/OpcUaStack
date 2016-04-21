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

#ifndef __OpcUaStackCore_Base64_h__
#define __OpcUaStackCore_Base64_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/os.h"

namespace OpcUaStackCore
{

	class DLLEXPORT Base64
	{
	  public:
		Base64(void);
		~Base64(void);

		static bool encode(const char*asciiBuf, uint32_t asciiLen, char* base64Buf, uint32_t& base64Len);
		static bool decode(void);

	  private:

	};

}

#endif
