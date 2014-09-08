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
	, historyUpdateDetailsSPtr_(ExtensibleParameter::construct())
	{
	}

	HistoryUpdateRequest::~HistoryUpdateRequest(void)
	{
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

	bool 
	HistoryUpdateRequest::opcUaBinaryEncode(std::ostream& os) const
	{
		historyUpdateDetailsSPtr_->opcUaBinaryEncode(os);
		return true;
	}
	
	bool 
	HistoryUpdateRequest::opcUaBinaryDecode(std::istream& is)
	{
		historyUpdateDetailsSPtr_->opcUaBinaryDecode(is);
		return true;
	}

}