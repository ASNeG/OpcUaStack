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
#include "OpcUaStackPubSub/NetworkMessageProcessor/NetworkMessageProcessor.h"
#include "OpcUaStackPubSub/NetworkMessage/NetworkMessage.h"

using namespace OpcUaStackCore;

namespace OpcUaStackPubSub
{

	NetworkMessageProcessor::NetworkMessageProcessor(
		const std::string& messageProcessorName,
		const std::string& messageTransportName,
		OpcUaStackCore::IOThread::SPtr& ioThread,
		OpcUaStackCore::MessageBus::SPtr& messageBus
	)
	: ServerServiceBase()
	{
		Log(Info, "Constructor")
			.parameter("ServiceName", serviceName_);

		messageTransportName_ = messageTransportName;

		// set parameter in server service base
		serviceName_ = messageProcessorName;
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
				auto event = boost::static_pointer_cast<Event>(message);
				switch (event->eventType())
				{
					case EventType::NetworkRecvEvent:
					{
						break;
					}
					case EventType::NetworkSendEvent:
					{
						break;
					}
			    };
			}
		);
	}

	NetworkMessageProcessor::~NetworkMessageProcessor(void)
	{
		// deactivate receiver
		deactivateReceiver();
		messageBus_->deregisterMember(messageBusMember_);
	}

	void
	NetworkMessageProcessor::readerGroupId(uint16_t readerGroupId)
	{
		readerGroupId_ = readerGroupId;
	}

	bool
	NetworkMessageProcessor::registerDataSetReader(uint16_t dataSetReaderId, DataSetReaderBase::SPtr& dataSetReader)
	{
		// check if data set reader already exist
		auto it = dataSetReaderMap_.find(dataSetReaderId);
		if (it != dataSetReaderMap_.end()) {
			Log(Error, "register data set writer error, because data set writer id already exist")
				.parameter("ReaderGroupName", serviceName_)
				.parameter("DataSetReaderId", dataSetReaderId);
			return false;
		}
		// add data set writer to map
		dataSetReaderMap_.insert(std::make_pair(dataSetReaderId, dataSetReader));
		return true;
	}

	bool
	NetworkMessageProcessor::registerDataSetReaderSync(uint16_t dataSetReaderId, DataSetReaderBase::SPtr& dataSetReader)
	{
		// check if the call is made within the strand
		if (!strand_->running_in_this_thread()) {
			std::promise<bool> promise;
			std::future<bool> future = promise.get_future();
			strand_->dispatch(
				[this, &promise, dataSetReaderId, dataSetReader](void) mutable {
					bool rc = registerDataSetReader(dataSetReaderId, dataSetReader);
					promise.set_value(rc);
			    }
			);
			future.wait();
			return future.get();
		}

		return registerDataSetReader(dataSetReaderId, dataSetReader);
	}

	bool
	NetworkMessageProcessor::deregisterDataSetReader(uint16_t dataSetReaderId)
	{
		// check if data set writer exist
		auto it = dataSetReaderMap_.find(dataSetReaderId);
		if (it == dataSetReaderMap_.end()) {
			Log(Error, "deregister data set writer error, because data set writer id not exist")
				.parameter("ReaderGroupName", serviceName_)
				.parameter("DataSetReaderId", dataSetReaderId);
			return false;
		}

		dataSetReaderMap_.erase(it);
		return true;
	}

	bool
	NetworkMessageProcessor::startupSync(void)
	{
		// check if the call is made within the strand
		if (!strand_->running_in_this_thread()) {
			std::promise<bool> promise;
			std::future<bool> future = promise.get_future();
			strand_->dispatch(
				[this, &promise](void) mutable {
					bool rc = startup();
					promise.set_value(rc);
			    }
			);
			future.wait();
			return future.get();
		}

		return startup();
	}

	bool
	NetworkMessageProcessor::shutdownSync(void)
	{	
		// check if the call is made within the strand
		if (!strand_->running_in_this_thread()) {
			std::promise<bool> promise;
			std::future<bool> future = promise.get_future();
			strand_->dispatch(
				[this, &promise](void) mutable {
					bool rc = shutdown();
					promise.set_value(rc);
			    }
			);
			future.wait();
			return future.get();
		}

		return shutdown();
	}
	bool
	NetworkMessageProcessor::deregisterDataSetReaderSync(uint16_t dataSetReaderId)
	{
		// check if the call is made within the strand
		if (!strand_->running_in_this_thread()) {
			std::promise<bool> promise;
			std::future<bool> future = promise.get_future();
			strand_->dispatch(
				[this, &promise, dataSetReaderId](void) mutable {
					bool rc = deregisterDataSetReader(dataSetReaderId);
					promise.set_value(rc);
			    }
			);
			future.wait();
			return future.get();
		}

		return deregisterDataSetReaderSync(dataSetReaderId);
	}

	bool
	NetworkMessageProcessor::startup(void)
	{
		// check if the call is made within the strand
		// FIXME: todo
		Log(Info, "Startup").parameter("ServiceName", serviceName_);

		// get reference to message transport bus member
		if (!messageBus_->existMember(messageTransportName_)) {
			Log(Error, "message transport message bus member don't exist")
				.parameter("MessageTransportName", messageTransportName_);
			return false;
		}
		messageTransportBusMember_ = messageBus_->getMember(messageTransportName_);

		return true;
	}

	bool
	NetworkMessageProcessor::shutdown(void)
	{
		// check if the call is made within the strand
		// FIXME: todo

		return true;
	}
}
