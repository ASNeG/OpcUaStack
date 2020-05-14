/*
   Copyright 2020 Kai Huebl (kai@huebl-sgh.de)

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
#include <OpcUaStackCore/MessageBus/MessageBusMemberConfig.h>

namespace OpcUaStackCore
{

	MessageBusMemberConfig::MessageBusMemberConfig(void)
	{
	}

	MessageBusMemberConfig::MessageBusMemberConfig(MessageBusMemberConfig& messageBusMemberConfig)
	{
		maxReceiveQueueSize_ = messageBusMemberConfig.maxReceiveQueueSize();
		ioThread_ = messageBusMemberConfig.ioThread();
		strand_ = messageBusMemberConfig.strand();

	}

	MessageBusMemberConfig::~MessageBusMemberConfig(void)
	{
	}

	void
	MessageBusMemberConfig::maxReceiveQueueSize(uint32_t maxReceiveQueueSize)
	{
		maxReceiveQueueSize_ = maxReceiveQueueSize;
	}

	uint32_t
	MessageBusMemberConfig::maxReceiveQueueSize(void)
	{
		return maxReceiveQueueSize_;
	}

	void
	MessageBusMemberConfig::ioThread(IOThread::SPtr& ioThread)
	{
		ioThread_ = ioThread;
	}

	IOThread::SPtr& MessageBusMemberConfig::ioThread(void)
	{
		return ioThread_;
	}

	void
	MessageBusMemberConfig::strand(const boost::shared_ptr<boost::asio::io_service::strand>& strand)
	{
		strand_ = strand;
	}

	boost::shared_ptr<boost::asio::io_service::strand>&
	MessageBusMemberConfig::strand(void)
	{
		return strand_;
	}

}
