/*
   Copyright 2017 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackPubSub/Network/NetworkMessageCreator.h"

namespace OpcUaStackPubSub
{

	NetworkMessageCreator::NetworkMessageCreator(void)
	: ioThread_()
	, slotTimerElement_()
	, dataSetWriters_()
	, networkSender_()
	, publishInterval_(1000)
	{
	}

	NetworkMessageCreator::~NetworkMessageCreator(void)
	{
	}

	void
	NetworkMessageCreator::publishInterval(uint32_t publishInterval)
	{
		publishInterval_ = publishInterval;
	}

	void
	NetworkMessageCreator::ioThread(IOThread::SPtr& ioThread)
	{
		ioThread_ = ioThread;
	}

	bool
	NetworkMessageCreator::startup(void)
	{
		if (ioThread_.get() == nullptr) {
			return false;
		}

		// start publish timer loop
		slotTimerElement_ = constructSPtr<SlotTimerElement>();
		slotTimerElement_->callback().reset(boost::bind(&NetworkMessageCreator::publish, this));
		slotTimerElement_->expireTime(boost::posix_time::microsec_clock::local_time(), publishInterval_);
		ioThread_->slotTimer()->start(slotTimerElement_);

		return true;
	}

	bool
	NetworkMessageCreator::shutdown(void)
	{
		// stop publish timer loop
		ioThread_->slotTimer()->stop(slotTimerElement_);
		slotTimerElement_.reset();

		return true;
	}

	bool
	NetworkMessageCreator::deregisterDataSetWriterIf(uint32_t writerId)
	{
		// FIXME: todo
		return true;
	}

	bool
	NetworkMessageCreator::registerDataSetWriterIf(const DataSetWriterIf::SPtr& writerIf)
	{
		dataSetWriters_.push_back(writerIf);
		return true;
	}

	void
	NetworkMessageCreator::networkSenderIf(const NetworkSenderIf::SPtr& senderIf)
	{
		networkSender_ =  senderIf;
	}

	NetworkSenderIf::SPtr
	NetworkMessageCreator::networkSenderIf()
	{
		return networkSender_;
	}

	bool
	NetworkMessageCreator::publish()
	{

		// handle keyFrameCount
		// handle keepAliveTime

		return false;
	}

}


