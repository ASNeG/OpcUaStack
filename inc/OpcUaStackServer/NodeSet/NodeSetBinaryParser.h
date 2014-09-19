#ifndef __OpcUaStackServer_NodeSetBinaryParser_h__
#define __OpcUaStackServer_NodeSetBinaryParser_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackServer/NodeSet/NodeSetBaseParser.h"

namespace OpcUaStackServer
{

	class DLLEXPORT NodeSetBinaryParser : public NodeSetBaseParser
	{
	  public:
		NodeSetBinaryParser(void);
		~NodeSetBinaryParser(void);
	};

}

#endif