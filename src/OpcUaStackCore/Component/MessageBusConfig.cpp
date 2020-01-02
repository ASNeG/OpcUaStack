/*
   Copyright 2019 Kai Huebl (kai@huebl-sgh.de)

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

#include <boost/make_shared.hpp>
#include "OpcUaStackCore/Component/MessageBusConfig.h"

namespace OpcUaStackCore
{

	MessageBusConfig::MessageBusConfig(void)
	{
	}

	MessageBusConfig::MessageBusConfig(MessageBusConfig& messageBusConfig)
	{
		ioThread_ = messageBusConfig.ioThread();
	}

	MessageBusConfig::~MessageBusConfig(void)
	{
	}

	void
	MessageBusConfig::ioThread(IOThread::SPtr& ioThread)
	{
		ioThread_ = ioThread;
	}

	IOThread::SPtr&
	MessageBusConfig::ioThread(void)
	{
		return ioThread_;
	}

	void
	MessageBusConfig::maxReceiveQueueSize(uint32_t maxReceiveQueueSize)
	{
		maxReceiveQueueSize_ = maxReceiveQueueSize;
	}

	uint32_t
	MessageBusConfig::maxReceiveQueueSize(void)
	{
		return maxReceiveQueueSize_;
	}

	uint32_t
	MessageBusConfig::calcMaxReceiveQueueSize(uint32_t maxReceiveQueueSize)
	{
		if (maxReceiveQueueSize_ == 0) return maxReceiveQueueSize;
		else if (maxReceiveQueueSize == 0) return maxReceiveQueueSize_;
		else if (maxReceiveQueueSize_ > maxReceiveQueueSize) return maxReceiveQueueSize;
		else return maxReceiveQueueSize_;
	}

}
