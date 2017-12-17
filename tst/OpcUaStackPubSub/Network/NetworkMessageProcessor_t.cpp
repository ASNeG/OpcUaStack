#include "unittest.h"

#include <iostream>
#include <boost/asio.hpp>

#include "OpcUaStackPubSub/Network/NetworkMessageProcessor.h"
#include "OpcUaStackPubSub/DataSetMessage/KeepAliveMessage.h"

using namespace OpcUaStackCore;
using namespace OpcUaStackPubSub;

class MockDataSetReader : public DataSetReaderIf
{
public:
	typedef boost::shared_ptr<MockDataSetReader> SPtr;

	MockDataSetReader()
	: receivedDataSetMessage_(nullptr)
	, receiveResult_(false)
	, receiveTimeoutInterval_(0)
	{

	};

	bool
	receiveDataSetMessage(const DataSetMessage::SPtr& dataSetMessage)
	{
		receivedDataSetMessage_ = dataSetMessage;
		return receiveResult_;
	}

	bool
	checkTimeout(uint32_t timeoutInterval)
	{
		receiveTimeoutInterval_ = timeoutInterval;
		return true;
	}

	bool receiveResult_;
	DataSetMessage::SPtr receivedDataSetMessage_;
	uint32_t receiveTimeoutInterval_;
};

class MockNetworkMessageProcessor : public NetworkMessageProcessor {
public:
	bool timeoutHandle()
	{
		return NetworkMessageProcessor::timeoutHandle();
	}

};

struct NetworkMessageProcessorFixtures
{
	NetworkMessageProcessorFixtures()
	{
		readerPub1Id1N1 = constructSPtr<MockDataSetReader>();
		readerPub1Id1N2 = constructSPtr<MockDataSetReader>();
		readerPub1Id2N1 = constructSPtr<MockDataSetReader>();
		readerPub2Id1N1 = constructSPtr<MockDataSetReader>();

		readerPub1Id1N1->publisherId()->setValue(OpcUaUInt16(1));
		readerPub1Id1N2->publisherId()->setValue(OpcUaUInt16(1));
		readerPub1Id2N1->publisherId()->setValue(OpcUaUInt16(1));
		readerPub2Id1N1->publisherId()->setValue(OpcUaUInt16(2));

		readerPub1Id1N1->writerId(1);
		readerPub1Id1N2->writerId(1);
		readerPub1Id2N1->writerId(2);
		readerPub2Id1N1->writerId(1);

		processor.registerDataSetReaderIf(readerPub1Id1N1);
		processor.registerDataSetReaderIf(readerPub1Id1N2);
		processor.registerDataSetReaderIf(readerPub1Id2N1);
		processor.registerDataSetReaderIf(readerPub2Id1N1);
	}

	MockNetworkMessageProcessor processor;

	MockDataSetReader::SPtr readerPub1Id1N1;
	MockDataSetReader::SPtr readerPub1Id1N2;
	MockDataSetReader::SPtr readerPub1Id2N1;
	MockDataSetReader::SPtr readerPub2Id1N1;
};


BOOST_AUTO_TEST_SUITE(NetworkMessageProcessor_)

BOOST_AUTO_TEST_CASE(NetworkMessageProcessor_)
{
	std::cout << "NetworkMessageProcessor_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(NetworkMessageProcessor_registration)
{
	NetworkMessageProcessor processor;

	MockDataSetReader::SPtr reader1 = constructSPtr<MockDataSetReader>();
	reader1->publisherId()->setValue(OpcUaUInt32(1));
	reader1->writerId(1);

	BOOST_REQUIRE(processor.registerDataSetReaderIf(reader1));
	BOOST_REQUIRE(processor.registerDataSetReaderIf(reader1) == false);
}

BOOST_AUTO_TEST_CASE(NetworkMessageProcessor_deregistration)
{
	NetworkMessageProcessor processor;

	MockDataSetReader::SPtr reader1 = constructSPtr<MockDataSetReader>();
	reader1->publisherId()->setValue(OpcUaUInt32(1));
	reader1->writerId(1);
	processor.registerDataSetReaderIf(reader1);

	BOOST_REQUIRE(processor.deregisterDataSetReaderIf(reader1));
	BOOST_REQUIRE(processor.deregisterDataSetReaderIf(reader1) == false);
}

BOOST_FIXTURE_TEST_CASE(NetworkMessageProcessor_filter1, NetworkMessageProcessorFixtures)
{
	NetworkMessage networkMessage;

	networkMessage.networkMessageHeader()->publisherIdEnabled(true);
	OpcUaVariant publisherId  = *readerPub1Id1N1->publisherId();
	networkMessage.networkMessageHeader()->publisherId()->copyFrom(publisherId);

	KeepAliveMessage::SPtr dataSetMessage = constructSPtr<KeepAliveMessage>();

	DataSetPayloadHeader::SPtr dataSetPayloadHeader = networkMessage.dataSetPayloadHeader();
	dataSetPayloadHeader->dataSetWriterIds()->resize(1);
	dataSetPayloadHeader->dataSetWriterIds()->push_back(1);

	DataSetPayload::SPtr dataSetPayload= networkMessage.dataSetPayload();
	dataSetPayload->dataSetMessages()->resize(1);
	dataSetPayload->dataSetMessages()->push_back(dataSetMessage);

	BOOST_REQUIRE(processor.receive(networkMessage));

	BOOST_REQUIRE(readerPub1Id1N1->receivedDataSetMessage_ == dataSetMessage);
	BOOST_REQUIRE(readerPub1Id1N2->receivedDataSetMessage_ == dataSetMessage);
	BOOST_REQUIRE(readerPub1Id2N1->receivedDataSetMessage_ == nullptr);
	BOOST_REQUIRE(readerPub2Id1N1->receivedDataSetMessage_ == nullptr);

}

BOOST_FIXTURE_TEST_CASE(NetworkMessageProcessor_timeoutHandle, NetworkMessageProcessorFixtures)
{
	processor.timeoutHandle();

	BOOST_REQUIRE_EQUAL(NetworkMessageProcessor::TimeoutHandleInterval, readerPub1Id1N1->receiveTimeoutInterval_);
	BOOST_REQUIRE_EQUAL(NetworkMessageProcessor::TimeoutHandleInterval, readerPub1Id1N2->receiveTimeoutInterval_);
	BOOST_REQUIRE_EQUAL(NetworkMessageProcessor::TimeoutHandleInterval, readerPub1Id2N1->receiveTimeoutInterval_);
	BOOST_REQUIRE_EQUAL(NetworkMessageProcessor::TimeoutHandleInterval, readerPub2Id1N1->receiveTimeoutInterval_);
}

BOOST_AUTO_TEST_SUITE_END()


