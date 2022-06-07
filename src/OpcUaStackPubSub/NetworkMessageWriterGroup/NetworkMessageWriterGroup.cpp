/*
   Copyright 2022 Kai Huebl (kai@huebl-sgh.de)

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
#include "OpcUaStackPubSub/NetworkMessageWriterGroup/NetworkMessageWriterGroup.h"

using namespace OpcUaStackCore;

namespace OpcUaStackPubSub
{

	NetworkMessageWriterGroup::NetworkMessageWriterGroup(
		const std::string& writerGroupName,
		const std::string& messageTransportName,
		OpcUaStackCore::IOThread::SPtr& ioThread,
		OpcUaStackCore::MessageBus::SPtr& messageBus
	)
	: ServerServiceBase()
	{
		messageTransportName_ = messageTransportName;

		// set parameter in server service base
		serviceName_ = writerGroupName;
		ServerServiceBase::ioThread_ = ioThread.get();
		strand_ = ioThread->createStrand();
		messageBus_ = messageBus;

		// register message bus receiver
		MessageBusMemberConfig messageBusMemberConfig;
		messageBusMemberConfig.strand(strand_);
		messageBusMember_ = messageBus_->registerMember(serviceName_, messageBusMemberConfig);

		// activate receiver
		activateReceiver(
			[this](const MessageBusMember::WPtr& handleFrom, Message::SPtr& message) {
				// receive message from internal message bus

				// FIXME: todo
			}
		);
	}

	NetworkMessageWriterGroup::~NetworkMessageWriterGroup(void)
	{
		// deactivate receiver
		deactivateReceiver();
		messageBus_->deregisterMember(messageBusMember_);
	}

	void
	NetworkMessageWriterGroup::writerGroupId(uint16_t writerGroupId)
	{
		writerGroupId_ = writerGroupId;
	}

	bool
	NetworkMessageWriterGroup::registerDataSetWriter(uint16_t dataSetWriterId, DataSetWriterBase::SPtr& dataSetWriter)
	{
		// check if data set writer already exist
		auto it = dataSetWriterMap_.find(dataSetWriterId);
		if (it != dataSetWriterMap_.end()) {
			Log(Error, "register data set writer error, because data set writer id already exist")
				.parameter("WriterGroupName", serviceName_)
				.parameter("DataSetWriterId", dataSetWriterId);
			return false;
		}

		// add data set writer to map
		dataSetWriterMap_.insert(std::make_pair(dataSetWriterId, dataSetWriter));
		return true;
	}

	bool
	NetworkMessageWriterGroup::registerDataSetWriterSync(uint16_t dataSetWriterId, DataSetWriterBase::SPtr& dataSetWriter)
	{
		// check if the call is made within the strand
		if (!strand_->running_in_this_thread()) {
			std::promise<bool> promise;
			std::future<bool> future = promise.get_future();
			strand_->dispatch(
				[this, &promise, dataSetWriterId, dataSetWriter](void) mutable {
					bool rc = registerDataSetWriter(dataSetWriterId, dataSetWriter);
					promise.set_value(rc);
			    }
			);
			future.wait();
			return future.get();
		}

		return registerDataSetWriter(dataSetWriterId, dataSetWriter);
	}

	bool
	NetworkMessageWriterGroup::deregisterDataSetWriter(uint16_t dataSetWriterId)
	{
		// check if data set writer exist
		auto it = dataSetWriterMap_.find(dataSetWriterId);
		if (it == dataSetWriterMap_.end()) {
			Log(Error, "deregister data set writer error, because data set writer id not exist")
				.parameter("WriterGroupName", serviceName_)
				.parameter("DataSetWriterId", dataSetWriterId);
			return false;
		}

		dataSetWriterMap_.erase(it);
		return true;
	}

	bool
	NetworkMessageWriterGroup::deregisterDataSetWriterSync(uint16_t dataSetWriterId)
	{
		// check if the call is made within the strand
		if (!strand_->running_in_this_thread()) {
			std::promise<bool> promise;
			std::future<bool> future = promise.get_future();
			strand_->dispatch(
				[this, &promise, dataSetWriterId](void) mutable {
					bool rc = deregisterDataSetWriter(dataSetWriterId);
					promise.set_value(rc);
			    }
			);
			future.wait();
			return future.get();
		}

		return deregisterDataSetWriterSync(dataSetWriterId);
	}

	bool
	NetworkMessageWriterGroup::startupSync(void)
	{
		// check if the call is made within the strand
		// FIXME: todo

		// get reference to message transport bus member
		if (!messageBus_->existMember(messageTransportName_)) {
			Log(Error, "message transport message bus member don't exist")
				.parameter("MessageTransportName", messageTransportName_);
			return false;
		}
		messageTransportBusMember_ = messageBus_->getMember(messageTransportName_);

		// start publish loop
		// FIXME: todo

		// FIXME: todo
		return true;
	}

	bool
	NetworkMessageWriterGroup::shutdownSync(void)
	{
		// check if the call is made within the strand
		// FIXME: todo

		// stop publish loop
		// FIXME: todo

		// FIXME: todo
		return true;
	}

	void
	NetworkMessageWriterGroup::publishLoop(void)
	{
		boost::asio::streambuf payloadHeader;
		boost::asio::streambuf dataSetMessagesSize;
		boost::asio::streambuf dataSetMessagesData;

		// get datasets from data set writer
		for (auto it : dataSetWriterMap_) {
			auto dataSetWriter = it.second;
			uint16_t size;

			// write data set message to message data stream
			dataSetWriter->encodeDataSet(dataSetMessagesSize, size);

			// write size to message size stream
			// FIXME: todo

			// write writer id to writer id stream
			// FIXME: todo
		}

		// create network message
		// FIXME: todo

		// send network message to message transport module
	}

}
