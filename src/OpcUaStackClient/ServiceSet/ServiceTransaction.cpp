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

	ServiceTransaction::ServiceTransaction(void)
	{
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

}