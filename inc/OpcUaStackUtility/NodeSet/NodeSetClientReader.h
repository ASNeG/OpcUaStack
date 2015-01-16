#ifndef __OpcUaStackUtility_NodeSetClientReader_h__
#define __OpcUaStackUtility_NodeSetClientReader_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/Config.h"
#include "OpcUaStackServer/NodeSet/NodeSetBaseParser.h"
#include "OpcUaStackServer/NodeSet/NodeSetNamespace.h"

using namespace OpcUaStackServer;

namespace OpcUaStackUtility
{

	class DLLEXPORT NodeSetClientReader : public NodeSetBaseParser
	{
	  public:
		NodeSetClientReader(void);
		~NodeSetClientReader(void);

		bool readNodes(void);

		NodeSetNamespace& nodeSetNamespace(void);

	  private:
		
		NodeSetNamespace nodeSetNamespace_;
	};

}

#endif