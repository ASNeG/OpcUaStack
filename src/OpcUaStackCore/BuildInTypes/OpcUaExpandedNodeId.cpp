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
	OpcUaExpandedNodeId::out(std::ostream& os) const
	{
		os << *(OpcUaNodeIdBase*)this;
		if (namespaceUri_.size() > 0) os << ",nu=" << namespaceUri_;
		if (serverIndex_ != 0) os << ",si" << serverIndex_;
	}

	void 
	OpcUaExpandedNodeId::copyTo(OpcUaExpandedNodeId& opcUaExpandedNodeId)
	{
		OpcUaNodeIdBase::copyTo(opcUaExpandedNodeId);
		if (namespaceUri_.size() > 0) opcUaExpandedNodeId.namespaceUri(namespaceUri_);
		if (serverIndex_ != 0) opcUaExpandedNodeId.serverIndex(serverIndex_);
	}
	bool 
	OpcUaExpandedNodeId::operator!=(const OpcUaExpandedNodeId& opcUaExpandedNodeId) const
	{
		return !operator==(opcUaExpandedNodeId);
	}

	bool 
	OpcUaExpandedNodeId::operator==(const OpcUaExpandedNodeId& opcUaExpandedNodeId) const
	{
		return
			namespaceUri_ == const_cast<OpcUaExpandedNodeId*>(&opcUaExpandedNodeId)->namespaceUri() &&
			serverIndex_ == const_cast<OpcUaExpandedNodeId*>(&opcUaExpandedNodeId)->serverIndex() &&
			OpcUaNodeIdBase::operator==(opcUaExpandedNodeId);
	}

	void 
	OpcUaExpandedNodeId::opcUaBinaryEncode(std::ostream& os) const
	{
		OpcUaNodeIdBase::opcUaBinaryEncode(os);
		if (namespaceUri_.size() > 0) namespaceUri_.opcUaBinaryEncode(os);
		if (serverIndex_ != 0) OpcUaNumber::opcUaBinaryEncode(os, serverIndex_);
	}

	void 
	OpcUaExpandedNodeId::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaNodeIdBase::opcUaBinaryDecode(is);
		if ((expandedEncodingFlag_ & 0x80) == 0x80) {
			namespaceIndex(0);
			namespaceUri_.opcUaBinaryDecode(is);
		}
		if ((expandedEncodingFlag_ & 0x40) == 0x40) OpcUaNumber::opcUaBinaryDecode(is, serverIndex_);
	}

}
