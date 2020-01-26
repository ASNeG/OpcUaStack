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
#include "OpcUaStackCore/Utility/AsyncPendingQueueConfig.h"

namespace OpcUaStackCore
{

	AsyncPendingQueueConfig::AsyncPendingQueueConfig(void)
	{
	}

	AsyncPendingQueueConfig::AsyncPendingQueueConfig(AsyncPendingQueueConfig& asyncPendingQueueConfig)
	{
		ioThread_ = asyncPendingQueueConfig.ioThread();
		maxPendingQueueSize_ = asyncPendingQueueConfig.maxPendingQueueSize();
	}

	AsyncPendingQueueConfig::~AsyncPendingQueueConfig(void)
	{
	}

	void
	AsyncPendingQueueConfig::ioThread(IOThread::SPtr& ioThread)
	{
		ioThread_ = ioThread;
	}

	IOThread::SPtr&
	AsyncPendingQueueConfig::ioThread(void)
	{
		return ioThread_;
	}

	void
	AsyncPendingQueueConfig::strand(boost::shared_ptr<boost::asio::io_service::strand> strand)
	{
		strand_ = strand;
	}

	boost::shared_ptr<boost::asio::io_service::strand>&
	AsyncPendingQueueConfig::strand(void)
	{
		return strand_;
	}

	void
	AsyncPendingQueueConfig::maxPendingQueueSize(uint32_t maxPendingQueueSize)
	{
		maxPendingQueueSize_ = maxPendingQueueSize;
	}

	uint32_t
	AsyncPendingQueueConfig::maxPendingQueueSize(void)
	{
		return maxPendingQueueSize_;
	}


}
