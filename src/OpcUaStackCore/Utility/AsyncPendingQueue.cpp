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
#include "OpcUaStackCore/Utility/AsyncPendingQueue.h"

namespace OpcUaStackCore
{

	AsyncPendingQueue::AsyncPendingQueue(AsyncPendingQueueConfig& asyncPendingQueueConfig)
	{
		asyncPendingQueueConfig_ = asyncPendingQueueConfig;
	}

	AsyncPendingQueue::~AsyncPendingQueue(void)
	{
	}

	void
	AsyncPendingQueue::cancel(void)
	{
		// FIXME: todo
	}

	bool
	AsyncPendingQueue::insert(uint32_t key, Object::SPtr object, uint32_t timeoutMSec)
	{
		// FIXME: todo
		return true;
	}

	Object::SPtr
	AsyncPendingQueue::remove(uint32_t key)
	{
		// FIXME: todo
		return nullptr;
	}


	void
	AsyncPendingQueue::asyncTimeout(
		const TimeoutCallback& timeoutCallback
	)
	{
		// FIXME: todo
	}

	void
	AsyncPendingQueue::asyncTimeout(
		const boost::shared_ptr<boost::asio::io_service::strand>& strand,
		const TimeoutCallback& timeoutCallback
	)
	{
		// FIXME: todo
	}

	void
	AsyncPendingQueue::asyncTimeout(
		IOThread::SPtr& ioThread,
		const TimeoutCallback& timeoutCallback
	)
	{
		// FIXME: todo
	}

	void
	AsyncPendingQueue::keys(std::vector<uint32_t>& keys)
	{
		// FIXME: todo
	}

}
