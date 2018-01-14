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

   Autor: Kai Huebl (kai@huebl-sgh.de), Aleksey Timin (atimin@gmail.com)
 */

#include "OpcUaStackPubSub/Network/NetworkMessageProcessor.h"
#include <algorithm>

namespace OpcUaStackPubSub
{

	const uint32_t NetworkMessageProcessor::TimeoutHandleInterval = 10;

	NetworkMessageProcessor::NetworkMessageProcessor(void)
	: dataSetReaderIfTree_()
	, ioThread_()
	, slotTimerElement_()
	{
	}

	NetworkMessageProcessor::~NetworkMessageProcessor(void)
	{
	}

	bool
	NetworkMessageProcessor::startup(void)
	{
		if (ioThread_.get() == nullptr) {
			return false;
		}

		// start publish timer loop
		slotTimerElement_ = constructSPtr<SlotTimerElement>();
		slotTimerElement_->callback().reset(boost::bind(&NetworkMessageProcessor::timeoutHandle, this));
		slotTimerElement_->expireTime(boost::posix_time::microsec_clock::local_time(), TimeoutHandleInterval);
		ioThread_->slotTimer()->start(slotTimerElement_);

		return true;
	}

	bool
	NetworkMessageProcessor::shutdown(void)
	{
		// stop publish timer loop
		ioThread_->slotTimer()->stop(slotTimerElement_);
		slotTimerElement_.reset();

		return true;
	}

	bool
	NetworkMessageProcessor::deregisterDataSetReaderIf(const DataSetReaderIf::SPtr& reader)
	{
		DataSetReaderIfTree::iterator dataSetReaderIfSetIt;
		DataSetReaderKey key(*reader);
		dataSetReaderIfSetIt = dataSetReaderIfTree_.find(key);
		if (dataSetReaderIfSetIt == dataSetReaderIfTree_.end()) return false;

		DataSetReaderIf::Set::iterator it = std::find(dataSetReaderIfSetIt->second.begin(),
				dataSetReaderIfSetIt->second.end(),
				reader);
		if (it == dataSetReaderIfSetIt->second.end()) return false;

		dataSetReaderIfSetIt->second.erase(reader);
		return true;
	}

	bool
	NetworkMessageProcessor::registerDataSetReaderIf(const DataSetReaderIf::SPtr& reader)
	{
		DataSetReaderKey key(*reader);
		DataSetReaderIf::Set& dataSetReaderIfSetIt = dataSetReaderIfTree_[key];
		std::pair<DataSetReaderIf::Set::iterator, bool> result = dataSetReaderIfSetIt.insert(reader);

		return result.second;
	}

	bool
	NetworkMessageProcessor::receive(const NetworkMessage& message)
	{
		DataSetReaderKey key;
		message.networkMessageHeader()->publisherId()->copyTo(key.publisherId_);
		size_t messageCount = message.dataSetPayloadHeader()->dataSetWriterIds()->size();

		for (int indx = 0; indx < messageCount; ++indx) {
			message.dataSetPayloadHeader()->dataSetWriterIds()->get(indx, key.writerId_);

			DataSetMessage::SPtr dataSetMessage;
			message.dataSetPayload()->dataSetMessages()->get(indx, dataSetMessage);

			DataSetReaderIfTree::iterator dataSetReaderIfTreeIt = dataSetReaderIfTree_.find(key);
			if (dataSetReaderIfTreeIt == dataSetReaderIfTree_.end()) {
				// FIXME What shell we do when we received data for reader that doesn't exist?
				continue;
			}

			DataSetReaderIf::Set& readers = dataSetReaderIfTreeIt->second;
			for (DataSetReaderIf::Set::iterator it = readers.begin(); it != readers.end(); it++) {
				(*it)->receiveDataSetMessage(dataSetMessage);
			}
		}

		return true;
	}

	bool
	NetworkMessageProcessor::timeoutHandle()
	{
		for (DataSetReaderIfTree::iterator readerSetIt = dataSetReaderIfTree_.begin();
				readerSetIt != dataSetReaderIfTree_.end(); readerSetIt++) {

			DataSetReaderIf::Set& readers = readerSetIt->second;
			for (DataSetReaderIf::Set::iterator it = readers.begin(); it != readers.end(); it++) {
				(*it)->checkTimeout(TimeoutHandleInterval);
			}
		}

		return true;
	}

	NetworkMessageProcessor::DataSetReaderKey::DataSetReaderKey()
	: writerId_(0)
	, publisherId_()
	{
	}

	NetworkMessageProcessor::DataSetReaderKey::DataSetReaderKey(const DataSetReaderIf& readerIf)
	{
		publisherId_ = *readerIf.publisherId();
		writerId_ = readerIf.writerId();
	}

	bool
	NetworkMessageProcessor::DataSetReaderKey::operator<(const DataSetReaderKey& other) const
	{
		OpcUaVariant lhs = publisherId_;
		OpcUaVariant rhs = other.publisherId_;

		if (lhs.variant()[0] != rhs.variant()[0]) {
			return lhs.variant()[0] < rhs.variant()[0];
		} else {
			return writerId_ < other.writerId_;
		}
	}

}
