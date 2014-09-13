#include "OpcUaStackCore/ServiceSet/ServiceTransaction.h"

namespace OpcUaStackCore
{

	uint32_t ServiceTransaction::uniqueTransactionId_ = 0;
	boost::mutex ServiceTransaction::mutex_;

	uint32_t 
	ServiceTransaction::getUniqueTransactionId(void)
	{
		uint32_t transactionId;
		mutex_.lock();
		transactionId = uniqueTransactionId_;
		uniqueTransactionId_++;
		mutex_.unlock();
		return transactionId;
	}

	ServiceTransaction::ServiceTransaction(OpcUaUInt32 nodeTypeRequest, OpcUaUInt32 nodeTypeResponse)
	: requestHeader_()
	, responseHeader_()
	{
		nodeTypeRequest_.set(nodeTypeRequest);
		nodeTypeResponse_.set(nodeTypeResponse);
		transactionId_ = getUniqueTransactionId();
	}
	
	ServiceTransaction::~ServiceTransaction(void)
	{
	}

	uint32_t 
	ServiceTransaction::transactionId(void)
	{
		return transactionId_;
	}

	void 
	ServiceTransaction::requestHeader(RequestHeader::SPtr requestHeader)
	{
		requestHeader_ = requestHeader;
	}

	RequestHeader::SPtr 
	ServiceTransaction::requestHeader(void)
	{
		if (requestHeader_.get() == nullptr) {
			requestHeader_ = RequestHeader::construct();
		}
		return requestHeader_;
	}

	void 
	ServiceTransaction::responseHeader(ResponseHeader::SPtr responseHeader)
	{
		responseHeader_ = responseHeader;
	}

	ResponseHeader::SPtr 
	ServiceTransaction::responseHeader(void)
	{
		if (responseHeader_.get() == nullptr) {
			responseHeader_ = ResponseHeader::construct();
		}
		return responseHeader_;
	}

	OpcUaNodeId& 
	ServiceTransaction::nodeTypeRequest(void)
	{
		return nodeTypeRequest_;
	}

	OpcUaNodeId&
	ServiceTransaction::nodeTypeResponse(void)
	{
		return nodeTypeResponse_;
	}

	ServiceTransactionIf* 
	ServiceTransaction::serviceTransactionIfService(void)
	{
		return serviceTransactionIfService_;
	}

	void 
	ServiceTransaction::serviceTransactionIfService(ServiceTransactionIf* serviceTransactionIfService)
	{
		serviceTransactionIfService_ = serviceTransactionIfService;
	}
	
	ServiceTransactionIf* 
	ServiceTransaction::serviceTransactionIfSession(void)
	{
		return serviceTransactionIfSession_;
	}

	void 
	ServiceTransaction::serviceTransactionIfSession(ServiceTransactionIf* serviceTransactionIfSession)
	{
		serviceTransactionIfSession_ = serviceTransactionIfSession;
	}

}