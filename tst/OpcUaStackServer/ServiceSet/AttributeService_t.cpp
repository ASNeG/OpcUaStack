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
	, service_()
	, transaction_(constructSPtr<ServiceTransactionHistoryRead>())
	, mockComponent_()
	{
		core_.init();


		auto nodeId1 = constructSPtr<OpcUaNodeId>(1,1);
		auto node1 = constructSPtr<VariableNodeClass>();

		auto informationModel = constructSPtr<InformationModel>();


		auto sync = constructSPtr<ForwardNodeSync>();
		sync->readHService().setCallback(boost::bind(&AttributeServiceFixture::mockCallback, this, _1));

		node1->forwardNodeSync(sync);
		node1->setNodeId(*nodeId1);

		BOOST_REQUIRE(informationModel->insert(node1));

		transaction_->componentService(&mockComponent_);

		auto nodesToRead = constructSPtr<HistoryReadValueIdArray>();

		auto nodeToRead = constructSPtr<HistoryReadValueId>();
		nodeToRead->nodeId(nodeId1);

		nodesToRead->resize(1);
		nodesToRead->push_back(nodeToRead);

		transaction_->request()->nodesToRead(nodesToRead);
		transaction_->componentSession(&mockComponent_);

		auto details = constructSPtr<OpcUaExtensibleParameter>();
		auto readDetails = constructSPtr<ReadRawModifiedDetails>();

		details->parameterTypeId().set(OpcUaId_ReadRawModifiedDetails_Encoding_DefaultBinary);
		details->parameter<ReadRawModifiedDetails>().swap(readDetails);

		transaction_->request()->historyReadDetails(details);

		service_.informationModel(informationModel);
	}

	~AttributeServiceFixture()
	{
		core_.cleanup();
	}

	void
	mockCallback(ApplicationHReadContext *ctx)
	{
		ctx->statusCode_ = expectedStatus_;
		ctx->dataValueArray_ = constructSPtr<OpcUaDataValueArray>();
	}

	Core core_;
	AttributeService service_;
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
	service_.receive(transaction_);

	auto result = constructSPtr<HistoryReadResult>();
	transaction_->response()->results()->get(0, result);
	BOOST_REQUIRE_EQUAL(OpcUaStatusCode::Success, result->statusCode());
}

BOOST_AUTO_TEST_CASE(AttributeService_readHistoryNoDataResultStatus)
{

	expectedStatus_ = OpcUaStatusCode::GoodNoData;
	service_.receive(transaction_);

	auto result = constructSPtr<HistoryReadResult>();
	transaction_->response()->results()->get(0, result);
	BOOST_REQUIRE_EQUAL(OpcUaStatusCode::GoodNoData, result->statusCode());
}



BOOST_AUTO_TEST_SUITE_END()


