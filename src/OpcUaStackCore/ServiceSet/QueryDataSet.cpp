#include "OpcUaStackCore/ServiceSet/QueryDataSet.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa QueryDataSet
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	QueryDataSet::QueryDataSet(void)
	: ObjectPool<QueryDataSet>()
	, nodeIdSPtr_(OpcUaExpandedNodeId::construct())
	, typeDefinitionNodeSPtr_(OpcUaExpandedNodeId::construct())
	, valueArraySPtr_(OpcUaVariantArray::construct())
	{
	}

	QueryDataSet::~QueryDataSet(void)
	{
	}

	void 
	QueryDataSet::nodeId(const OpcUaExpandedNodeId::SPtr nodeId)
	{
		nodeIdSPtr_ = nodeId;
	}
	
	OpcUaExpandedNodeId::SPtr 
	QueryDataSet::nodeId(void) const
	{
		return nodeIdSPtr_;
	}
	
	void 
	QueryDataSet::typeDefinitionNode(const OpcUaExpandedNodeId::SPtr typeDefinitionNode)
	{
		typeDefinitionNodeSPtr_ = typeDefinitionNode;
	}
	
	OpcUaExpandedNodeId::SPtr 
	QueryDataSet::typeDefinitionNode(void) const
	{
		return typeDefinitionNodeSPtr_;
	}
	
	void 
	QueryDataSet::values(const OpcUaVariantArray::SPtr values)
	{
		valueArraySPtr_ = values;
	}
	
	OpcUaVariantArray::SPtr 
	QueryDataSet::values(void) const
	{
		return valueArraySPtr_;
	}

	void 
	QueryDataSet::opcUaBinaryEncode(std::ostream& os) const
	{
		nodeIdSPtr_->opcUaBinaryEncode(os);
		typeDefinitionNodeSPtr_->opcUaBinaryEncode(os);
		valueArraySPtr_->opcUaBinaryEncode(os);
	}
	
	void 
	QueryDataSet::opcUaBinaryDecode(std::istream& is)
	{
		nodeIdSPtr_->opcUaBinaryDecode(is);
		typeDefinitionNodeSPtr_->opcUaBinaryDecode(is);
		valueArraySPtr_->opcUaBinaryDecode(is);
	}

}