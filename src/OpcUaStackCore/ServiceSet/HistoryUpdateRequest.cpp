#include "OpcUaStackCore/ServiceSet/HistoryUpdateRequest.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa HistoryUpdateRequest
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	HistoryUpdateRequest::HistoryUpdateRequest(void)
	: ObjectPool<HistoryUpdateRequest>()
	, requestHeaderSPtr_(RequestHeader::construct())
	, historyUpdateDetailsSPtr_(ExtensibleParameter::construct())
	{
	}

	HistoryUpdateRequest::~HistoryUpdateRequest(void)
	{
	}

	void 
	HistoryUpdateRequest::requestHeader(const RequestHeader::SPtr requestHeaderSPtr)
	{
		requestHeaderSPtr_ = requestHeaderSPtr;
	}

	RequestHeader::SPtr 
	HistoryUpdateRequest::requestHeader(void) const
	{
		return requestHeaderSPtr_;
	}

	void 
	HistoryUpdateRequest::historyUpdateDetails(const ExtensibleParameter::SPtr historyUpdateDetails)
	{
		historyUpdateDetailsSPtr_ = historyUpdateDetails;
	}
	
	ExtensibleParameter::SPtr 
	HistoryUpdateRequest::historyUpdateDetails(void) const
	{
		return historyUpdateDetailsSPtr_;
	}

	void 
	HistoryUpdateRequest::opcUaBinaryEncode(std::ostream& os) const
	{
		requestHeaderSPtr_->opcUaBinaryEncode(os);
		historyUpdateDetailsSPtr_->opcUaBinaryEncode(os);
	}
	
	void 
	HistoryUpdateRequest::opcUaBinaryDecode(std::istream& is)
	{
		requestHeaderSPtr_->opcUaBinaryDecode(is);
		historyUpdateDetailsSPtr_->opcUaBinaryDecode(is);
	}

}