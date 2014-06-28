#include "OpcUaStackCore/BuildInTypes/OpcUaExpandedNodeId.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUaExpandedNodeId
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	OpcUaExpandedNodeId::OpcUaExpandedNodeId(void)
	: ObjectPool<OpcUaExpandedNodeId>()
	, OpcUaNodeIdBase()
	, namespaceUri_()
	, serverIndex_()
	{
	}
	
	OpcUaExpandedNodeId::~OpcUaExpandedNodeId(void)
	{
	}

	void 
	OpcUaExpandedNodeId::namespaceUri(OpcUaString& namespaceUri)
	{
		namespaceUri_ = namespaceUri;
	}

	void
	OpcUaExpandedNodeId::namespaceUri(const std::string& namespaceUri)
	{
		namespaceUri_ = namespaceUri;
	}

	OpcUaString& 
	OpcUaExpandedNodeId::namespaceUri(void)
	{
		return namespaceUri_;
	}
		
	void 
	OpcUaExpandedNodeId::serverIndex(OpcUaUInt32 serverIndex)
	{
		serverIndex_ = serverIndex;
	}
		
	OpcUaUInt32 
	OpcUaExpandedNodeId::serverIndex(void)
	{
		return serverIndex_;
	}

	OpcUaByte 
	OpcUaExpandedNodeId::encodingFlag(void) const
	{
		OpcUaByte expandedEncodingFlag = 0x00;
		if (namespaceUri_.exist()) {
			const_cast<OpcUaExpandedNodeId*>(this)->namespaceIndex(0);
			expandedEncodingFlag |= 0x80;
		}
		if (serverIndex_ != 0) expandedEncodingFlag |= 0x40;
		return expandedEncodingFlag;
	}
	
	void 
	OpcUaExpandedNodeId::encodingFlag(OpcUaByte expandedEncodingFlag)
	{
		expandedEncodingFlag_ = expandedEncodingFlag;
	}

	void 
	OpcUaExpandedNodeId::opcUaBinaryEncode(std::ostream& os) const
	{
		OpcUaNodeIdBase::opcUaBinaryEncode(os);
		if (namespaceUri_.size() > 0) OpcUaStackCore::opcUaBinaryEncode(os, namespaceUri_);
		if (serverIndex_ != 0) OpcUaStackCore::opcUaBinaryEncode(os, serverIndex_);
	}

	void 
	OpcUaExpandedNodeId::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaNodeIdBase::opcUaBinaryDecode(is);
		if ((expandedEncodingFlag_ & 0x80) == 0x80) {
			namespaceIndex(0);
			OpcUaStackCore::opcUaBinaryDecode(is, namespaceUri_);
		}
		if ((expandedEncodingFlag_ & 0x40) == 0x40) OpcUaStackCore::opcUaBinaryDecode(is, serverIndex_);
	}

	void opcUaBinaryEncode(std::ostream& os, const OpcUaExpandedNodeId& value)
	{
		value.opcUaBinaryEncode(os);
	}

	void opcUaBinaryDecode(std::istream& is, OpcUaExpandedNodeId& value)
	{
		value.opcUaBinaryDecode(is);
	}


	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUaExpandedNodeIdArray
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	void opcUaBinaryEncode(std::ostream& os, const OpcUaExpandedNodeIdArray& value)
	{
		value.opcUaBinaryEncode(os);
	}

	void opcUaBinaryEncode(std::ostream& os, const OpcUaExpandedNodeIdArray::SPtr& value)
	{
		value->opcUaBinaryEncode(os);
	}

	void opcUaBinaryDecode(std::istream& is, OpcUaExpandedNodeIdArray& value)
	{
		value.opcUaBinaryDecode(is);
	}

	void opcUaBinaryDecode(std::istream& is, OpcUaExpandedNodeIdArray::SPtr& value)
	{
		value->opcUaBinaryDecode(is);
	}

}
