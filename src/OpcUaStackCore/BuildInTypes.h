#pragma once
#ifndef __OpcUaStackCore__BuildInTypes_h__
#define __OpcUaStackCore__BuildInTypes_h__

#include <iostream>

namespace OpcUaStackCore
{

	typedef bool OpcUaBool;
	bool opcUaBoolBinaryEncode(std::ostream& os, OpcUaBool& value);
	bool opcUaBoolBinaryDecode(std::istream& is, OpcUaBool& value);

}

#endif