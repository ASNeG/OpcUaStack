#include "OpcUaStackClient/ServiceSet/ServiceTransaction.h"

namespace OpcUaStackClient
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

}