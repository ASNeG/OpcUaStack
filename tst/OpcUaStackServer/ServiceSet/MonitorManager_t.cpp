#include "unittest.h"

#include "OpcUaStackServer/ServiceSet/MonitorManager.h"
#include "OpcUaStackServer/AddressSpaceModel/VariableNodeClass.h"
#include "OpcUaStackCore/Application/ApplicationMonitoredItemStartContext.h"
#include "OpcUaStackCore/Application/ApplicationMonitoredItemStopContext.h"

using namespace OpcUaStackServer;


struct F {
    F() : mm()
    , informationModel(constructSPtr<InformationModel>())
    , ioThread(constructSPtr<IOThread>())
    , createMonitoredItemTransaction(constructSPtr<ServiceTransactionCreateMonitoredItems>())
    , startMonitoredItemCallCount(0)
    , stopMonitoredItemCallCount(0)
    {

		mm.informationModel(informationModel);

		ioThread = constructSPtr<IOThread>();
		ioThread->slotTimer(constructSPtr<SlotTimer>());
		mm.ioThread(ioThread.get());

		auto nodeToMonitor = constructSPtr<VariableNodeClass>();
		OpcUaNodeId nodeToMonitorId(0, 0);
		nodeToMonitor->setNodeId(nodeToMonitorId);
		OpcUaDataValue value(0);
		nodeToMonitor->setValue(value);

		auto sync = constructSPtr<ForwardNodeSync>();
		auto startMonitoredItemCallback = Callback(boost::bind(&F::startMonitored, this, _1));
		auto stopMonitoredItemCallback = Callback(boost::bind(&F::stopMonitored, this, _1));
		sync->monitoredItemStartService().setCallback(startMonitoredItemCallback);
		sync->monitoredItemStopService().setCallback(stopMonitoredItemCallback);

		nodeToMonitor->forwardNodeSync(sync);

		informationModel->insert(nodeToMonitor);

		auto monitoredItemCreateRequest = constructSPtr<MonitoredItemCreateRequest>();

		ReadValueId readValueId;
		readValueId.nodeId(0, 0);
		readValueId.attributeId(AttributeId_Value);
		monitoredItemCreateRequest->itemToMonitor(readValueId);


		auto itemsToCreate = constructSPtr<MonitoredItemCreateRequestArray>();
		itemsToCreate->resize(1);
		itemsToCreate->push_back(monitoredItemCreateRequest);

		createMonitoredItemTransaction->request()->itemsToCreate(itemsToCreate);
    }

	void
	startMonitored(ApplicationMonitoredItemStartContext* context)
	{
		startMonitoredItemCallCount++;
	}

	void
	stopMonitored(ApplicationMonitoredItemStopContext* context)
	{
		stopMonitoredItemCallCount++;
	}

	ServiceTransactionDeleteMonitoredItems::SPtr makeDeleteMonitredItemTransaction(CreateMonitoredItemsResponse::SPtr response) {
		MonitoredItemCreateResult::SPtr result;
		response->results()->get(0, result);

		auto ids = constructSPtr<OpcUaUInt32Array>();
		ids->resize(1);
		ids->push_back(result->monitoredItemId());

	    auto deleteMonitoredItemTransaction = constructSPtr<ServiceTransactionDeleteMonitoredItems>();
		deleteMonitoredItemTransaction->request()->monitoredItemIds(ids);

		return deleteMonitoredItemTransaction;
	}

    ~F() { }

	MonitorManager mm;
	InformationModel::SPtr informationModel;
	IOThread::SPtr ioThread;

	ServiceTransactionCreateMonitoredItems::SPtr createMonitoredItemTransaction;

	size_t startMonitoredItemCallCount;
	size_t stopMonitoredItemCallCount;

};


BOOST_FIXTURE_TEST_SUITE(MonitorManager_, F)

BOOST_AUTO_TEST_CASE(MonitorManager_)
{
	std::cout << "MonitorManager_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(MonitorManager_CallStartMonitoredItemCallback)
{
	BOOST_REQUIRE_EQUAL(OpcUaStatusCode::Success, mm.receive(createMonitoredItemTransaction));

	MonitoredItemCreateResult::SPtr result;
	createMonitoredItemTransaction->response()->results()->get(0, result);

	BOOST_REQUIRE_EQUAL(OpcUaStatusCode::Success, result->statusCode());
	BOOST_REQUIRE_EQUAL(1, startMonitoredItemCallCount);
}

BOOST_AUTO_TEST_CASE(MonitorManager_CallStartMonitoredItemCallbackOnlyOnce)
{
	BOOST_REQUIRE_EQUAL(OpcUaStatusCode::Success, mm.receive(createMonitoredItemTransaction));
	BOOST_REQUIRE_EQUAL(OpcUaStatusCode::Success, mm.receive(createMonitoredItemTransaction));

	MonitoredItemCreateResult::SPtr result;
	createMonitoredItemTransaction->response()->results()->get(0, result);

	BOOST_REQUIRE_EQUAL(OpcUaStatusCode::Success, result->statusCode());
	BOOST_REQUIRE_EQUAL(1, startMonitoredItemCallCount);
}

BOOST_AUTO_TEST_CASE(MonitorManager_CallStopMonitoredItemCallback)
{
	BOOST_REQUIRE_EQUAL(OpcUaStatusCode::Success, mm.receive(createMonitoredItemTransaction));

	auto deleteMonitoredItemTransaction =
			makeDeleteMonitredItemTransaction(createMonitoredItemTransaction->response());

	BOOST_REQUIRE_EQUAL(OpcUaStatusCode::Success, mm.receive(deleteMonitoredItemTransaction));

	OpcUaStatusCode status;
	deleteMonitoredItemTransaction->response()->results()->get(0, status);

	BOOST_REQUIRE_EQUAL(OpcUaStatusCode::Success, status);
	BOOST_REQUIRE_EQUAL(1, stopMonitoredItemCallCount);
}


BOOST_AUTO_TEST_CASE(MonitorManager_CallStopMonitoredItemCallbackOnlyOnce)
{
	BOOST_REQUIRE_EQUAL(OpcUaStatusCode::Success, mm.receive(createMonitoredItemTransaction));

	auto deleteMonitoredItemTransaction1 =
			makeDeleteMonitredItemTransaction(createMonitoredItemTransaction->response());

	BOOST_REQUIRE_EQUAL(OpcUaStatusCode::Success, mm.receive(createMonitoredItemTransaction));

	auto deleteMonitoredItemTransaction2 =
			makeDeleteMonitredItemTransaction(createMonitoredItemTransaction->response());

	BOOST_REQUIRE_EQUAL(OpcUaStatusCode::Success, mm.receive(deleteMonitoredItemTransaction1));
	BOOST_REQUIRE_EQUAL(OpcUaStatusCode::Success, mm.receive(deleteMonitoredItemTransaction2));

	OpcUaStatusCode status;
	deleteMonitoredItemTransaction2->response()->results()->get(0, status);

	BOOST_REQUIRE_EQUAL(OpcUaStatusCode::Success, status);
	BOOST_REQUIRE_EQUAL(1, stopMonitoredItemCallCount);
}


BOOST_AUTO_TEST_SUITE_END()


