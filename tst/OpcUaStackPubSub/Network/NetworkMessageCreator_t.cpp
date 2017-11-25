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
	publishTimeout(DataSetMessage::SPtr& dataSetMessage)
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

struct Fixtures
{
	Fixtures()
	{
		dataSetMessage1 = constructSPtr<KeepAliveMessage>();
		writer1 = constructSPtr<MockDataSetWriter>(dataSetMessage1, true);

		dataSetMessage2 = constructSPtr<KeepAliveMessage>();
		writer2 = constructSPtr<MockDataSetWriter>(dataSetMessage2, true);

		creator.registerDataSetWriterIf(writer1);
		creator.registerDataSetWriterIf(writer2);

		sender = constructSPtr<MockNetworkSender>(true);
		creator.networkSenderIf(sender);

		OpcUaVariant::SPtr publisherId = constructSPtr<OpcUaVariant>();
		publisherId->variant(OpcUaByte(1000));
		creator.publisherId(publisherId);
	}

	KeepAliveMessage::SPtr dataSetMessage1;
	DataSetWriterIf::SPtr writer1;

	KeepAliveMessage::SPtr dataSetMessage2;
	DataSetWriterIf::SPtr writer2;

	MockNetworkSender::SPtr sender;

	TestedNetworkMessageCreator creator;
};

BOOST_AUTO_TEST_SUITE(NetworkMessageCreator_)

BOOST_AUTO_TEST_CASE(NetworkMessageCreator_)
{
	std::cout << "NetworkMessageCreator_t" << std::endl;
}


BOOST_FIXTURE_TEST_CASE(NetworkMessageCreator_publish_datasets_from_2_writers, Fixtures)
{
	DataSetPayload::SPtr payload = constructSPtr<DataSetPayload>();
	payload->dataSetMessages()->resize(2);
	payload->dataSetMessages()->push_back(dataSetMessage1);
	payload->dataSetMessages()->push_back(dataSetMessage2);
	payload->count(2);

	BOOST_REQUIRE(creator.mockPublish());
	BOOST_REQUIRE(*sender->sentMessage_.dataSetPayload() == *payload);
}

BOOST_FIXTURE_TEST_CASE(NetworkMessageCreator_publish_datasets_from_1_writer, Fixtures)
{
	boost::dynamic_pointer_cast<MockDataSetWriter>(creator.dataSetWriterIfs().back())->publishResult_ = false;

	DataSetPayload::SPtr payload = constructSPtr<DataSetPayload>();
	payload->dataSetMessages()->resize(1);
	payload->dataSetMessages()->push_back(dataSetMessage1);
	payload->count(1);

	BOOST_REQUIRE(creator.mockPublish());
	BOOST_REQUIRE(*sender->sentMessage_.dataSetPayload() == *payload);
}

BOOST_FIXTURE_TEST_CASE(NetworkMessageCreator_publisherIdEnable, Fixtures)
{
	creator.publisherIdEnabled(true);

	BOOST_REQUIRE(creator.mockPublish());
	BOOST_REQUIRE(sender->sentMessage_.networkMessageHeader()->publisherIdEnabled());
	BOOST_REQUIRE_EQUAL(sender->sentMessage_.networkMessageHeader()->publisherId()->get<OpcUaByte>(),
			creator.publisherId()->get<OpcUaByte>());
}

BOOST_FIXTURE_TEST_CASE(NetworkMessageCreator_dataSetWriterIdEnabled, Fixtures)
{
	creator.dataSetWriterIdEnabled(true);

	BOOST_REQUIRE(creator.mockPublish());
	BOOST_REQUIRE(sender->sentMessage_.networkMessageHeader()->dataSetWriterIdEnabled());
	BOOST_REQUIRE(sender->sentMessage_.dataSetPayloadHeader()->dataSetWriterIdEnabled());
}

BOOST_FIXTURE_TEST_CASE(NetworkMessageCreator_dataSetArrayEnabled, Fixtures)
{
	creator.dataSetArrayEnabled(true);

	BOOST_REQUIRE(creator.mockPublish());
	BOOST_REQUIRE(sender->sentMessage_.networkMessageHeader()->dataSetArrayEnabled());
	BOOST_REQUIRE(sender->sentMessage_.dataSetPayloadHeader()->dataSetArrayEnabled());
	BOOST_REQUIRE(sender->sentMessage_.dataSetPayload()->dataSetArrayEnabled());
}

BOOST_FIXTURE_TEST_CASE(NetworkMessageCreator_timestampEnabled, Fixtures)
{
	creator.timestampEnabled(true);

	BOOST_REQUIRE(creator.mockPublish());
	BOOST_REQUIRE(sender->sentMessage_.networkMessageHeader()->timestampEnabled());
}

BOOST_FIXTURE_TEST_CASE(NetworkMessageCreator_picosecondsEnabled, Fixtures)
{
	creator.picosecondsEnabled(true);

	BOOST_REQUIRE(creator.mockPublish());
	BOOST_REQUIRE(sender->sentMessage_.networkMessageHeader()->picoSecondsEnabled());
}

BOOST_FIXTURE_TEST_CASE(NetworkMessageCreator_dataSetClassIdEnabled, Fixtures)
{
	creator.dataSetClassIdEnabled(true);

	BOOST_REQUIRE(creator.mockPublish());
	BOOST_REQUIRE(sender->sentMessage_.networkMessageHeader()->dataSetClassIdEnabled());
}

BOOST_FIXTURE_TEST_CASE(NetworkMessageCreator_promotedFieldsEnabled, Fixtures)
{
	creator.promotedFieldsEnabled(true);

	BOOST_REQUIRE(creator.mockPublish());
	BOOST_REQUIRE(sender->sentMessage_.networkMessageHeader()->promotedFieldsEnabled());
}

BOOST_AUTO_TEST_SUITE_END()

