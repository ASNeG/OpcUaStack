#include "OpcUaStackCore/ServiceSet/HistoryReadValueId.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa HistoryReadValueId
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	HistoryReadValueId::HistoryReadValueId(void)
	: ObjectPool<HistoryReadValueId>()
	, nodeIdSPtr_(OpcUaNodeId::construct())
	, indexRange_()
	, dataEncoding_()
	, continuationPoint_()
	{
	}

	HistoryReadValueId::~HistoryReadValueId(void)
	{
	}

	void 
	HistoryReadValueId::nodeId(const OpcUaNodeId::SPtr nodeId)
	{
		nodeIdSPtr_ = nodeId;
	}

	OpcUaNodeId::SPtr
	HistoryReadValueId::nodeId(void)
	{
		return nodeIdSPtr_;
	}

	void 
	HistoryReadValueId::indexRange(const OpcUaString& indexRange)
	{
		indexRange_ = indexRange;
	}

	std::string 
	HistoryReadValueId::indexRange(void) const
	{
		return indexRange_.value();
	}
	
	void 
	HistoryReadValueId::dataEncoding(const OpcUaQualifiedName& dataEncoding)
	{
		dataEncoding_ = dataEncoding;
	}
	
	OpcUaQualifiedName&
	HistoryReadValueId::dataEncoding(void)
	{
		return dataEncoding_;
	}

	void 
	HistoryReadValueId::continuationPoint(const OpcUaByteString& continuationPoint)
	{
		continuationPoint_ = continuationPoint;
	}
	
	OpcUaByteString& 
	HistoryReadValueId::continuationPoint(void)
	{
		return continuationPoint_;
	}

	void 
	HistoryReadValueId::nodeId(const OpcUaInt16& namespaceIndex, const OpcUaInt32& identifier)
	{
		nodeIdSPtr_->namespaceIndex(namespaceIndex);
		nodeIdSPtr_->nodeId(identifier);
	}
	
	void 
	HistoryReadValueId::indexRange(const std::string& value)
	{
		indexRange_.value(value);
	}

	void 
	HistoryReadValueId::dataEncoding(const OpcUaInt16& namespaceIndex, const std::string& name)
	{
		dataEncoding_ = namespaceIndex;
		dataEncoding_ = name;
	}

	void 
	HistoryReadValueId::dataEncoding(const std::string& name)
	{
		dataEncoding_ = name;
	}

	void 
	HistoryReadValueId::opcUaBinaryEncode(std::ostream& os) const
	{
		nodeIdSPtr_->opcUaBinaryEncode(os);
		indexRange_.opcUaBinaryEncode(os);
		dataEncoding_.opcUaBinaryEncode(os);
		continuationPoint_.opcUaBinaryEncode(os);
	}
	
	void 
	HistoryReadValueId::opcUaBinaryDecode(std::istream& is)
	{
		nodeIdSPtr_->opcUaBinaryDecode(is);
		indexRange_.opcUaBinaryDecode(is);
		dataEncoding_.opcUaBinaryDecode(is);
		continuationPoint_.opcUaBinaryDecode(is);
	}

}