/*
   Copyright 2015 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   Informationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Kai Huebl (kai@huebl-sgh.de)
 */

#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackClient/ServiceSet/QueryService.h"

using namespace OpcUaStackCore;

namespace OpcUaStackClient
{

	QueryService::QueryService(IOThread* ioThread)
	: componentSession_(nullptr)
	, queryServiceIf_(nullptr)
	{
		Component::ioThread(ioThread);
	}

	QueryService::~QueryService(void)
	{
	}

	void
	QueryService::setConfiguration(
		Component* componentSession,
		QueryServiceIf* queryServiceIf
	)
	{
		this->componentSession(componentSession);
		queryServiceIf_ = queryServiceIf;
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
	QueryService::syncSend(ServiceTransactionQueryFirst::SPtr serviceTransactionQueryFirst)
	{
		serviceTransactionQueryFirst->sync(true);
		serviceTransactionQueryFirst->conditionBool().conditionInit();
		asyncSend(serviceTransactionQueryFirst);
		serviceTransactionQueryFirst->conditionBool().waitForCondition();
	}

	void 
	QueryService::asyncSend(ServiceTransactionQueryFirst::SPtr serviceTransactionQueryFirst)
	{
		serviceTransactionQueryFirst->componentService(this);
		componentSession_->sendAsync(serviceTransactionQueryFirst);
	}

	void
	QueryService::syncSend(ServiceTransactionQueryNext::SPtr serviceTransactionQueryNext)
	{
		serviceTransactionQueryNext->sync(true);
		serviceTransactionQueryNext->conditionBool().conditionInit();
		asyncSend(serviceTransactionQueryNext);
		serviceTransactionQueryNext->conditionBool().waitForCondition();
	}

	void
	QueryService::asyncSend(ServiceTransactionQueryNext::SPtr serviceTransactionQueryNext)
	{
		serviceTransactionQueryNext->componentService(this);
		componentSession_->sendAsync(serviceTransactionQueryNext);
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
