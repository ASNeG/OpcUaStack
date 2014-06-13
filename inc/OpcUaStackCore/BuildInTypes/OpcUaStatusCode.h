#ifndef __OpcUaStackCore_OpcUaStatusCode_h__
#define __OpcUaStackCore_OpcUaStatusCode_h__

#include <iostream>
#include "OpcUaStackCore/Base/os.h"

namespace OpcUaStackCore
{

	typedef enum {
		x = 0
	} OpcUaStatusCode;

	DLLEXPORT  void opcUaBinaryEncode(std::ostream& os, const OpcUaStatusCode& value);
	DLLEXPORT  void opcUaBinaryDecode(std::istream& is, OpcUaStatusCode& value);

};

#endif