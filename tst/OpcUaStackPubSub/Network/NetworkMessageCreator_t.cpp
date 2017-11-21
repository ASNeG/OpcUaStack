#include "unittest.h"

#include "OpcUaStackPubSub/Network/NetworkMessageCreator.h"


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

BOOST_AUTO_TEST_SUITE(NetworkMessageCreator_)

BOOST_AUTO_TEST_CASE(NetworkMessageCreator_)
{
	std::cout << "NetworkMessageCreator_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(NetworkMessageCreator_publish_datasets_from_2_writers)
{
	DataSetMessage::SPtr dataSetMessage1 = constructSPtr<DataSetMessage>();
	DataSetWriterIf::SPtr writer1 = constructSPtr<MockDataSetWriter>(dataSetMessage1, true);

	DataSetMessage::SPtr dataSetMessage2 = constructSPtr<DataSetMessage>();
	DataSetWriterIf::SPtr writer2 = constructSPtr<MockDataSetWriter>(dataSetMessage2, true);

	MockNetworkSender::SPtr sender = constructSPtr<MockNetworkSender>(true);

	TestedNetworkMessageCreator creator;

	creator.registerDataSetWriterIf(writer1);
	creator.registerDataSetWriterIf(writer2);

	creator.networkSenderIf(sender);

	NetworkMessage netMessage;
	DataSetPayload::SPtr payload = netMessage.dataSetPayload();
	payload->dataSetMessages()->resize(2);
	payload->dataSetMessages()->push_back(dataSetMessage1);
	payload->dataSetMessages()->push_back(dataSetMessage2);
	payload->count(2);

	BOOST_REQUIRE(creator.mockPublish());

	BOOST_REQUIRE(sender->sentMessage_ == netMessage);
}

BOOST_AUTO_TEST_SUITE_END()

