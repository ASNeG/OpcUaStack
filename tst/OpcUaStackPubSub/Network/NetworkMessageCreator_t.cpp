#include "unittest.h"

#include "OpcUaStackPubSub/Network/NetworkMessageCreator.h"
#include "OpcUaStackPubSub/DataSetMessage/KeepAliveMessage.h"


using namespace OpcUaStackCore;
using namespace OpcUaStackPubSub;

class MockDataSetWriter : public DataSetWriterIf
{
public:
	typedef boost::shared_ptr<MockDataSetWriter> SPtr;

	MockDataSetWriter(DataSetMessage::SPtr dataSetMessageToPublish, bool publishResult)
	: dataSetMessageToPublish_(dataSetMessageToPublish)
	, publishResult_(publishResult)
	{

	}

	bool
	publishTimeout(DataSetMessage::SPtr& dataSetMessage, uint32_t publishInterval)
	{
		dataSetMessage = dataSetMessageToPublish_;
		return publishResult_;
	}

	DataSetMessage::SPtr dataSetMessageToPublish_;
	bool publishResult_;

};

class MockNetworkSender : public NetworkSenderIf
{
public:
	typedef boost::shared_ptr<MockNetworkSender> SPtr;

	MockNetworkSender(bool sendResult)
	: sendResult_(sendResult)
	{

	}

	bool
	send(const NetworkMessage& message)
	{
		sentMessage_ = message;
		return sendResult_;
	}

	NetworkMessage sentMessage_;
	bool sendResult_;
};

class TestedNetworkMessageCreator : public NetworkMessageCreator
{
public:
	bool
	mockPublish()
	{
		return NetworkMessageCreator::publish();
	}
};

struct NetworkMessageCreatorFixtures
{
	NetworkMessageCreatorFixtures()
	{
		dataSetMessage1 = constructSPtr<KeepAliveMessage>();
		writer1 = constructSPtr<MockDataSetWriter>(dataSetMessage1, true);
		writer1->writerId(1);

		dataSetMessage2 = constructSPtr<KeepAliveMessage>();
		writer2 = constructSPtr<MockDataSetWriter>(dataSetMessage2, true);
		writer2->writerId(2);

		creator.registerDataSetWriterIf(writer1);
		creator.registerDataSetWriterIf(writer2);

		sender = constructSPtr<MockNetworkSender>(true);
		creator.networkSenderIf(sender);

		OpcUaVariant::SPtr publisherId = constructSPtr<OpcUaVariant>();
		publisherId->variant(OpcUaByte(1000));
		creator.publisherId(publisherId);
	}

	KeepAliveMessage::SPtr dataSetMessage1;
	MockDataSetWriter::SPtr writer1;

	KeepAliveMessage::SPtr dataSetMessage2;
	MockDataSetWriter::SPtr writer2;

	MockNetworkSender::SPtr sender;

	TestedNetworkMessageCreator creator;
};

BOOST_AUTO_TEST_SUITE(NetworkMessageCreator_)

BOOST_AUTO_TEST_CASE(NetworkMessageCreator_)
{
	std::cout << "NetworkMessageCreator_t" << std::endl;
}

BOOST_FIXTURE_TEST_CASE(NetworkMessageCreator_registation, NetworkMessageCreatorFixtures)
{
	MockDataSetWriter::SPtr writer3;
	writer3 = constructSPtr<MockDataSetWriter>(dataSetMessage2, true);
	writer3->writerId(3);

	BOOST_REQUIRE(creator.registerDataSetWriterIf(writer3) == true);
	BOOST_REQUIRE_EQUAL(3, creator.dataSetWriterIfMap().size());

	BOOST_REQUIRE(creator.registerDataSetWriterIf(writer3) == false);
	BOOST_REQUIRE_EQUAL(3, creator.dataSetWriterIfMap().size());
}

BOOST_FIXTURE_TEST_CASE(NetworkMessageCreator_deregistation, NetworkMessageCreatorFixtures)
{
	BOOST_REQUIRE(creator.deregisterDataSetWriterIf(writer1->writerId()));
	BOOST_REQUIRE_EQUAL(1, creator.dataSetWriterIfMap().size());

	BOOST_REQUIRE(creator.deregisterDataSetWriterIf(writer1->writerId()) == false);
	BOOST_REQUIRE_EQUAL(1, creator.dataSetWriterIfMap().size());
}


BOOST_FIXTURE_TEST_CASE(NetworkMessageCreator_publish_datasets_from_2_writers, NetworkMessageCreatorFixtures)
{
	DataSetPayload::SPtr payload = constructSPtr<DataSetPayload>();
	payload->dataSetMessages()->resize(2);
	payload->dataSetMessages()->push_back(dataSetMessage1);
	payload->dataSetMessages()->push_back(dataSetMessage2);
	payload->count(2);

	BOOST_REQUIRE(creator.mockPublish());
	BOOST_REQUIRE(*sender->sentMessage_.dataSetPayload() == *payload);
}

BOOST_FIXTURE_TEST_CASE(NetworkMessageCreator_publish_datasets_from_1_writer, NetworkMessageCreatorFixtures)
{
	writer2->publishResult_ = false;

	DataSetPayload::SPtr payload = constructSPtr<DataSetPayload>();
	payload->dataSetMessages()->resize(1);
	payload->dataSetMessages()->push_back(dataSetMessage1);
	payload->count(1);

	BOOST_REQUIRE(creator.mockPublish());
	BOOST_REQUIRE(*sender->sentMessage_.dataSetPayload() == *payload);
}

BOOST_FIXTURE_TEST_CASE(NetworkMessageCreator_publish_pass_keepAlive1, NetworkMessageCreatorFixtures)
{
	creator.keepAliveTime(2000);

	BOOST_REQUIRE_EQUAL(2000, writer1->keepAliveTime());
	BOOST_REQUIRE_EQUAL(2000, writer2->keepAliveTime());
}

BOOST_FIXTURE_TEST_CASE(NetworkMessageCreator_publish_pass_keepAlive2, NetworkMessageCreatorFixtures)
{
	creator.keepAliveTime(2000);

	DataSetWriterIf::SPtr writer = constructSPtr<MockDataSetWriter>(nullptr, false);
	creator.registerDataSetWriterIf(writer);

	BOOST_REQUIRE_EQUAL(2000, writer->keepAliveTime());
}

BOOST_FIXTURE_TEST_CASE(NetworkMessageCreator_publisherIdEnable, NetworkMessageCreatorFixtures)
{
	creator.publisherIdEnabled(true);

	BOOST_REQUIRE(creator.mockPublish());
	BOOST_REQUIRE(sender->sentMessage_.networkMessageHeader()->publisherIdEnabled());
	BOOST_REQUIRE_EQUAL(sender->sentMessage_.networkMessageHeader()->publisherId()->get<OpcUaByte>(),
			creator.publisherId()->get<OpcUaByte>());
}

BOOST_FIXTURE_TEST_CASE(NetworkMessageCreator_dataSetWriterIdEnabled, NetworkMessageCreatorFixtures)
{
	creator.dataSetWriterIdEnabled(true);

	BOOST_REQUIRE(creator.mockPublish());
	BOOST_REQUIRE(sender->sentMessage_.networkMessageHeader()->dataSetWriterIdEnabled());
}

BOOST_FIXTURE_TEST_CASE(NetworkMessageCreator_dataSetArrayEnabled, NetworkMessageCreatorFixtures)
{
	creator.dataSetArrayEnabled(true);

	BOOST_REQUIRE(creator.mockPublish());
	BOOST_REQUIRE(sender->sentMessage_.networkMessageHeader()->dataSetArrayEnabled());
	BOOST_REQUIRE(sender->sentMessage_.dataSetPayloadHeader()->dataSetArrayEnabled());
	BOOST_REQUIRE(sender->sentMessage_.dataSetPayload()->dataSetArrayEnabled());
}

BOOST_FIXTURE_TEST_CASE(NetworkMessageCreator_timestampEnabled, NetworkMessageCreatorFixtures)
{
	creator.timestampEnabled(true);

	BOOST_REQUIRE(creator.mockPublish());
	BOOST_REQUIRE(sender->sentMessage_.networkMessageHeader()->timestampEnabled());
}

BOOST_FIXTURE_TEST_CASE(NetworkMessageCreator_picosecondsEnabled, NetworkMessageCreatorFixtures)
{
	creator.picosecondsEnabled(true);

	BOOST_REQUIRE(creator.mockPublish());
	BOOST_REQUIRE(sender->sentMessage_.networkMessageHeader()->picoSecondsEnabled());
}

BOOST_FIXTURE_TEST_CASE(NetworkMessageCreator_dataSetClassIdEnabled, NetworkMessageCreatorFixtures)
{
	creator.dataSetClassIdEnabled(true);

	BOOST_REQUIRE(creator.mockPublish());
	BOOST_REQUIRE(sender->sentMessage_.networkMessageHeader()->dataSetClassIdEnabled());
}

BOOST_FIXTURE_TEST_CASE(NetworkMessageCreator_promotedFieldsEnabled, NetworkMessageCreatorFixtures)
{
	creator.promotedFieldsEnabled(true);

	BOOST_REQUIRE(creator.mockPublish());
	BOOST_REQUIRE(sender->sentMessage_.networkMessageHeader()->promotedFieldsEnabled());
}

BOOST_AUTO_TEST_SUITE_END()

