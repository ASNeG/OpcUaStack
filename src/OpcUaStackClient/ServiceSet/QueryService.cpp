#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackClient/ServiceSet/QueryService.h"

using namespace OpcUaStackCore;

namespace OpcUaStackClient
{

	QueryService::QueryService(void)
	: componentSession_(nullptr)
	, queryServiceIf_(nullptr)
	{
	}

	QueryService::~QueryService(void)
	{
	}

	void 
	QueryService::componentSession(Component* componentSession)
	{
		componentSession_ = componentSession;
	}

	void 
	QueryService::queryServiceIf(QueryServiceIf* queryServiceIf)
	{
		queryServiceIf_ = queryServiceIf;
	}

	void 
	QueryService::sendSync(ServiceTransactionQueryFirst::SPtr serviceTransactionQueryFirst)
	{
		serviceTransactionQueryFirst->sync(true);
		serviceTransactionQueryFirst->conditionBool().conditionInit();
		send(serviceTransactionQueryFirst);
		serviceTransactionQueryFirst->conditionBool().waitForCondition();
	}

	void 
	QueryService::send(ServiceTransactionQueryFirst::SPtr serviceTransactionQueryFirst)
	{
		serviceTransactionQueryFirst->componentService(this);
		componentSession_->send(serviceTransactionQueryFirst);
	}

	void
	QueryService::sendSync(ServiceTransactionQueryNext::SPtr serviceTransactionQueryNext)
	{
		serviceTransactionQueryNext->sync(true);
		serviceTransactionQueryNext->conditionBool().conditionInit();
		send(serviceTransactionQueryNext);
		serviceTransactionQueryNext->conditionBool().waitForCondition();
	}

	void
	QueryService::send(ServiceTransactionQueryNext::SPtr serviceTransactionQueryNext)
	{
		serviceTransactionQueryNext->componentService(this);
		componentSession_->send(serviceTransactionQueryNext);
	}


	void 
	QueryService::receive(Message::SPtr message)
	{
		ServiceTransaction::SPtr serviceTransaction = boost::static_pointer_cast<ServiceTransaction>(message);
		
		// check if transaction is synchron
		if (serviceTransaction->sync()) {
			serviceTransaction->conditionBool().conditionTrue();
			return;
		}
		
		switch (serviceTransaction->nodeTypeResponse().nodeId<uint32_t>())
		{
			case OpcUaId_QueryFirstResponse_Encoding_DefaultBinary:
			{
				if (queryServiceIf_ != nullptr) {
					queryServiceIf_->queryServiceQueryFirstResponse(
						boost::static_pointer_cast<ServiceTransactionQueryFirst>(serviceTransaction)
					);
				}
				break;
			}

			case OpcUaId_QueryNextResponse_Encoding_DefaultBinary:
			{
				if (queryServiceIf_ != nullptr) {
					queryServiceIf_->queryServiceQueryNextResponse(
						boost::static_pointer_cast<ServiceTransactionQueryNext>(serviceTransaction)
					);
				}
				break;
			}

			default:
				Log(Error, "call service received unknown message type")
					.parameter("TypeId", serviceTransaction->nodeTypeRequest());
		}
	}

}
