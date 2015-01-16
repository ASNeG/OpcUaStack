#include "OpcUaStackUtility/NodeSet/NodeSetClientReader.h"

namespace OpcUaStackUtility
{

	NodeSetClientReader::NodeSetClientReader(void)
	: nodeSetNamespace_()
	{
	}

	NodeSetClientReader::~NodeSetClientReader(void)
	{
	}

	bool 
	NodeSetClientReader::readNodes(void)
	{
		return true;
	}

	NodeSetNamespace& 
	NodeSetClientReader::nodeSetNamespace(void)
	{
		return nodeSetClientReader_;
	}

}