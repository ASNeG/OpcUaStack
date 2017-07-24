/*
   Copyright 2015-2017 Kai Huebl (kai@huebl-sgh.de)

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
#include "OpcUaStackServer/ServiceSet/EventManager.h"

namespace OpcUaStackServer
{

	EventManager::EventManager(void)
	: ioService_(nullptr)
	{
	}

	EventManager::~EventManager(void)
	{
	}

	void 
	EventManager::ioService(IOService* ioService)
	{
		ioService_ = ioService;
	}

	void 
	EventManager::subscriptionId(uint32_t subscriptionId)
	{
		subscriptionId_ = subscriptionId;
	}
		
	uint32_t 
	EventManager::subscriptionId(void)
	{
		return subscriptionId_;
	}

	void 
	EventManager::informationModel(InformationModel::SPtr informationModel)
	{
		informationModel_ = informationModel;
	}

	OpcUaStatusCode 
	EventManager::receive(ServiceTransactionCreateMonitoredItems::SPtr trx)
	{
		// FIXME: todo
		return Success;
	}

	OpcUaStatusCode 
	EventManager::receive(ServiceTransactionDeleteMonitoredItems::SPtr trx)
	{
		// FIXME: todo
		return Success;
	}

}
