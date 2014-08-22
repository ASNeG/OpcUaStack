#include "OpcUaStackCore/ServiceSet/SetTriggeringResponse.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa SetTriggeringResponse
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	SetTriggeringResponse::SetTriggeringResponse(void)
	: ObjectPool<SetTriggeringResponse>()
	, responseHeaderSPtr_(ResponseHeader::construct())
	, addResultArraySPtr_(OpcUaStatusCodeArray::construct())
	, addDiagnosticInfoArraySPtr_(OpcUaDiagnosticInfoArray::construct())
	, removeResultArraySPtr_(OpcUaStatusCodeArray::construct())
	, removeDiagnosticInfoArraySPtr_(OpcUaDiagnosticInfoArray::construct())
	{
	}

	SetTriggeringResponse::~SetTriggeringResponse(void)
	{
	}

	void 
	SetTriggeringResponse::responseHeader(const ResponseHeader::SPtr responseHeader)
	{
		responseHeaderSPtr_ = responseHeader;
	}

	ResponseHeader::SPtr 
	SetTriggeringResponse::responseHeader(void) const
	{
		return responseHeaderSPtr_;
	}

	void 
	SetTriggeringResponse::addResults(const OpcUaStatusCodeArray::SPtr results)
	{
		addResultArraySPtr_ = results;
	}
	
	OpcUaStatusCodeArray::SPtr
	SetTriggeringResponse::addResults(void) const
	{
		return addResultArraySPtr_;
	}	
	
	void 
	SetTriggeringResponse::addDiagnosticInfos(const OpcUaDiagnosticInfoArray::SPtr diagnosticInfos)
	{
		addDiagnosticInfoArraySPtr_ = diagnosticInfos;
	}
	
	OpcUaDiagnosticInfoArray::SPtr 
	SetTriggeringResponse::addDiagnosticInfos(void) const
	{
		return addDiagnosticInfoArraySPtr_;
	}

	void 
	SetTriggeringResponse::removeResults(const OpcUaStatusCodeArray::SPtr results)
	{
		removeResultArraySPtr_ = results;
	}
	
	OpcUaStatusCodeArray::SPtr
	SetTriggeringResponse::removeResults(void) const
	{
		return removeResultArraySPtr_;
	}	
	
	void 
	SetTriggeringResponse::removeDiagnosticInfos(const OpcUaDiagnosticInfoArray::SPtr diagnosticInfos)
	{
		removeDiagnosticInfoArraySPtr_ = diagnosticInfos;
	}
	
	OpcUaDiagnosticInfoArray::SPtr 
	SetTriggeringResponse::removeDiagnosticInfos(void) const
	{
		return removeDiagnosticInfoArraySPtr_;
	}

	void 
	SetTriggeringResponse::opcUaBinaryEncode(std::ostream& os) const
	{
		responseHeaderSPtr_->opcUaBinaryEncode(os);
		addResultArraySPtr_->opcUaBinaryEncode(os);
		addDiagnosticInfoArraySPtr_->opcUaBinaryEncode(os);
		removeResultArraySPtr_->opcUaBinaryEncode(os);
		removeDiagnosticInfoArraySPtr_->opcUaBinaryEncode(os);
	}
	
	void 
	SetTriggeringResponse::opcUaBinaryDecode(std::istream& is)
	{
		responseHeaderSPtr_->opcUaBinaryDecode(is);
		addResultArraySPtr_->opcUaBinaryDecode(is);
		addDiagnosticInfoArraySPtr_->opcUaBinaryDecode(is);
		removeResultArraySPtr_->opcUaBinaryDecode(is);
		removeDiagnosticInfoArraySPtr_->opcUaBinaryDecode(is);
	}
}