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
	: requestTimeout_(0)
	, requestHeader_()
	, responseHeader_()
	, sync_(false)
	, conditionBool_()
	{
		nodeTypeRequest_.set(nodeTypeRequest);
		nodeTypeResponse_.set(nodeTypeResponse);
		transactionId_ = getUniqueTransactionId();
	}
	
	ServiceTransaction::~ServiceTransaction(void)
	{
	}

	void 
	ServiceTransaction::channelId(OpcUaUInt32 channelId)
	{
		channelId_ = channelId;
	}
		
	OpcUaUInt32 
	ServiceTransaction::channelId(void)
	{
		return channelId_;
	}

	void 
	ServiceTransaction::sessionId(uint32_t sessionId)
	{
		sessionId_ = sessionId;
	}

	OpcUaUInt32 
	ServiceTransaction::sessionId(void)
	{
		return sessionId_;
	}

	OpcUaUInt32 
	ServiceTransaction::transactionId(void)
	{
		return transactionId_;
	}

	void 
	ServiceTransaction::sync(bool sync)
	{
		sync_ = sync;
	}

	bool 
	ServiceTransaction::sync(void)
	{
		return sync_;
	}

	ConditionBool&
	ServiceTransaction::conditionBool(void)
	{
		return conditionBool_;
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

	Component*
	ServiceTransaction::componentService(void)
	{
		return componentService_;
	}

	void 
	ServiceTransaction::componentService(Component* componentService)
	{
		componentService_ = componentService;
	}
	
	Component*
	ServiceTransaction::componentSession(void)
	{
		return componentSession_;
	}

	void 
	ServiceTransaction::componentSession(Component* componentSession)
	{
		componentSession_ = componentSession;
	}

	void 
	ServiceTransaction::statusCode(OpcUaStatusCode statusCode)
	{
		statusCode_ = statusCode;
	}
		
	OpcUaStatusCode 
	ServiceTransaction::statusCode(void)
	{
		return statusCode_;
	}

	void
	ServiceTransaction::requestTimeout(uint32_t requestTimeout)
	{
		requestTimeout_ = requestTimeout;
	}

	void
	ServiceTransaction::calcRequestTimeout(uint32_t& requestTimeout)
	{
		if (requestTimeout_ != 0) requestTimeout = requestTimeout_;
	}

}
