#include "unittest.h"

#include "OpcUaStackCore/ServiceSet/AttributeServiceTransaction.h"
#include "OpcUaStackCore/StandardDataTypes/ReadRawModifiedDetails.h"
#include "OpcUaStackCore/Application/ApplicationHReadContext.h"
#include "OpcUaStackCore/Core/Core.h"
#include "OpcUaStackServer/ServiceSet/AttributeService.h"
#include "OpcUaStackServer/AddressSpaceModel/VariableNodeClass.h"

using namespace OpcUaStackCore;
using namespace OpcUaStackServer;

class MockComponent
		: public Component
{
public:
	void receive(Message::SPtr message) override {

	}
};

struct AttributeServiceFixture
{

	AttributeServiceFixture()
	: core_()
	, transaction_(boost::make_shared<ServiceTransactionHistoryRead>())
	, mockComponent_()
	{
		auto ioThread = boost::make_shared<IOThread>();
		auto messageBus = boost::make_shared<MessageBus>();
		service_ = boost::make_shared<AttributeService>("ServiceName",  ioThread, messageBus);

		core_.init();


		auto nodeId1 = boost::make_shared<OpcUaNodeId>(1,1);
		auto node1 = boost::make_shared<VariableNodeClass>();

		auto informationModel = boost::make_shared<InformationModel>();


		auto sync = boost::make_shared<ForwardNodeSync>();
		sync->readHService().setCallback(boost::bind(&AttributeServiceFixture::mockCallback, this, _1));

		node1->forwardNodeSync(sync);
		node1->setNodeId(*nodeId1);

		BOOST_REQUIRE(informationModel->insert(node1));

		transaction_->componentService(&mockComponent_);

		auto nodesToRead = boost::make_shared<HistoryReadValueIdArray>();

		auto nodeToRead = boost::make_shared<HistoryReadValueId>();
		nodeToRead->nodeId(nodeId1);

		nodesToRead->resize(1);
		nodesToRead->push_back(nodeToRead);

		transaction_->request()->nodesToRead(nodesToRead);
		transaction_->componentSession(&mockComponent_);

		auto details = boost::make_shared<OpcUaExtensibleParameter>();
		auto readDetails = boost::make_shared<ReadRawModifiedDetails>();

		details->parameterTypeId().set(OpcUaId_ReadRawModifiedDetails_Encoding_DefaultBinary);
		details->parameter<ReadRawModifiedDetails>().swap(readDetails);

		transaction_->request()->historyReadDetails(details);

		service_->informationModel(informationModel);
	}

	~AttributeServiceFixture()
	{
		core_.cleanup();
	}

	void
	mockCallback(ApplicationHReadContext *ctx)
	{
		ctx->statusCode_ = expectedStatus_;
		ctx->dataValueArray_ = boost::make_shared<OpcUaDataValueArray>();
	}

	Core core_;
	AttributeService::SPtr service_ = nullptr;
	ServiceTransactionHistoryRead::SPtr transaction_;
	MockComponent mockComponent_;
	OpcUaStatusCode expectedStatus_;
};

BOOST_FIXTURE_TEST_SUITE(AttributeService_t, AttributeServiceFixture)

BOOST_AUTO_TEST_CASE(AttributeService_)
{
	std::cout << "AttributeService_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(AttributeService_readHistorySuccessResultStatus)
{

	expectedStatus_ = OpcUaStatusCode::Success;
	service_->receive(transaction_);

	auto result = boost::make_shared<HistoryReadResult>();
	transaction_->response()->results()->get(0, result);
	BOOST_REQUIRE_EQUAL(OpcUaStatusCode::Success, result->statusCode());
}

BOOST_AUTO_TEST_CASE(AttributeService_readHistoryNoDataResultStatus)
{

	expectedStatus_ = OpcUaStatusCode::GoodNoData;
	service_->receive(transaction_);

	auto result = boost::make_shared<HistoryReadResult>();
	transaction_->response()->results()->get(0, result);
	BOOST_REQUIRE_EQUAL(OpcUaStatusCode::GoodNoData, result->statusCode());
}



BOOST_AUTO_TEST_SUITE_END()


