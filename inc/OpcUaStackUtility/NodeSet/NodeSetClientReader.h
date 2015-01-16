#ifndef __OpcUaStackUtility_NodeSetClientReader_h__
#define __OpcUaStackUtility_NodeSetClientReader_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackServer/NodeSet/NodeSetBaseParser.h"
#include "OpcUaStackServer/NodeSet/NodeSetNamespace.h"

using namespace OpcUaStackServer;

using OpcUaStackUtility
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