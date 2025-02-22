#include "unittest.h"

#include "OpcUaStackServer/ServiceSet/MonitorManager.h"
#include "OpcUaStackServer/AddressSpaceModel/VariableNodeClass.h"
#include "OpcUaStackCore/Application/ApplicationMonitoredItemStartContext.h"
#include "OpcUaStackCore/Application/ApplicationMonitoredItemStopContext.h"

using namespace OpcUaStackCore;
using namespace OpcUaStackServer;


struct InitMonitorManager {
    InitMonitorManager() : mm()
    , informationModel(boost::make_shared<InformationModel>())
    , ioThread(boost::make_shared<IOThread>())
    , createMonitoredItemTransaction(boost::make_shared<ServiceTransactionCreateMonitoredItems>())
    , startMonitoredItemCallCount(0)
    , stopMonitoredItemCallCount(0)
    {

		mm.informationModel(informationModel);

		ioThread = boost::make_shared<IOThread>();
		ioThread->slotTimer(boost::make_shared<SlotTimer>());
		mm.ioThread(ioThread.get());

		nodeToMonitor = boost::make_shared<VariableNodeClass>();
		OpcUaNodeId nodeToMonitorId(0, 0);
		nodeToMonitor->setNodeId(nodeToMonitorId);
		OpcUaDataValue value(0);
		nodeToMonitor->setValue(value);

		sync = boost::make_shared<ForwardNodeSync>();
		auto startMonitoredItemCallback = [this](ApplicationMonitoredItemStartContext* context) {
			startMonitored(context);
		};
		auto stopMonitoredItemCallback = [this](ApplicationMonitoredItemStopContext* context) {
			stopMonitored(context);
		};
		sync->monitoredItemStartService().setCallback(startMonitoredItemCallback);
		sync->monitoredItemStopService().setCallback(stopMonitoredItemCallback);

		nodeToMonitor->forwardNodeSync(sync);

		informationModel->insert(nodeToMonitor);

		auto monitoredItemCreateRequest = boost::make_shared<MonitoredItemCreateRequest>();

		ReadValueId readValueId;
		readValueId.nodeId(0, 0);
		readValueId.attributeId(AttributeId_Value);
		monitoredItemCreateRequest->itemToMonitor(readValueId);


		auto itemsToCreate = boost::make_shared<MonitoredItemCreateRequestArray>();
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

		auto ids = boost::make_shared<OpcUaUInt32Array>();
		ids->resize(1);
		ids->push_back(result->monitoredItemId());

	    auto deleteMonitoredItemTransaction = boost::make_shared<ServiceTransactionDeleteMonitoredItems>();
		deleteMonitoredItemTransaction->request()->monitoredItemIds(ids);

		return deleteMonitoredItemTransaction;
	}

    ~InitMonitorManager() { }

	MonitorManager mm;
	InformationModel::SPtr informationModel;
	IOThread::SPtr ioThread;
    ForwardNodeSync::SPtr sync;
    VariableNodeClass::SPtr nodeToMonitor;

	ServiceTransactionCreateMonitoredItems::SPtr createMonitoredItemTransaction;

	size_t startMonitoredItemCallCount;
	size_t stopMonitoredItemCallCount;

};


BOOST_FIXTURE_TEST_SUITE(MonitorManager_, InitMonitorManager)

BOOST_AUTO_TEST_CASE(MonitorManager_)
{
	std::cout << "MonitorManager_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(MonitorManager_CallStartMonitoredItemCallback)
{
	BOOST_REQUIRE_EQUAL(OpcUaStatusCode::Success, mm.receive(createMonitoredItemTransaction));

	MonitoredItemCreateResult::SPtr result;
	createMonitoredItemTransaction->response()->results()->get(0, result);

	BOOST_REQUIRE_EQUAL(OpcUaStatusCode::Success, result->statusCode().enumeration());
	BOOST_REQUIRE_EQUAL(1, startMonitoredItemCallCount);
}

BOOST_AUTO_TEST_CASE(MonitorManager_CallStartMonitoredItemCallbackOnlyOnce)
{
	BOOST_REQUIRE_EQUAL(OpcUaStatusCode::Success, mm.receive(createMonitoredItemTransaction));
	BOOST_REQUIRE_EQUAL(OpcUaStatusCode::Success, mm.receive(createMonitoredItemTransaction));

	MonitoredItemCreateResult::SPtr result;
	createMonitoredItemTransaction->response()->results()->get(0, result);

	BOOST_REQUIRE_EQUAL(OpcUaStatusCode::Success, result->statusCode().enumeration());
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

BOOST_AUTO_TEST_CASE(MonitorManager_StartMonitoredItemWithoutCallback)
{
    sync->monitoredItemStartService().unsetCallback();
    BOOST_REQUIRE_EQUAL(OpcUaStatusCode::Success, mm.receive(createMonitoredItemTransaction));

    MonitoredItemCreateResult::SPtr result;
    createMonitoredItemTransaction->response()->results()->get(0, result);

    BOOST_REQUIRE_EQUAL(OpcUaStatusCode::Success, result->statusCode().enumeration());
    BOOST_REQUIRE_EQUAL(1, mm.monitoredItemIds().size());
}

BOOST_AUTO_TEST_CASE(MonitorManager_StopMonitoredItemWithoutCallback)
{
    BOOST_REQUIRE_EQUAL(OpcUaStatusCode::Success, mm.receive(createMonitoredItemTransaction));

    auto deleteMonitoredItemTransaction =
            makeDeleteMonitredItemTransaction(createMonitoredItemTransaction->response());

    sync->monitoredItemStopService().unsetCallback();
    BOOST_REQUIRE_EQUAL(OpcUaStatusCode::Success, mm.receive(deleteMonitoredItemTransaction));

    OpcUaStatusCode status;
    deleteMonitoredItemTransaction->response()->results()->get(0, status);

    BOOST_REQUIRE_EQUAL(OpcUaStatusCode::Success, status);
    BOOST_REQUIRE_EQUAL(0, mm.monitoredItemIds().size());
}

BOOST_AUTO_TEST_CASE(MonitorManager_StartStopMonitoringWithoutSync)
{
    nodeToMonitor->forwardNodeSync(nullptr);
    BOOST_REQUIRE_EQUAL(OpcUaStatusCode::Success, mm.receive(createMonitoredItemTransaction));
    BOOST_REQUIRE_EQUAL(1, mm.monitoredItemIds().size());

    auto deleteMonitoredItemTransaction =
            makeDeleteMonitredItemTransaction(createMonitoredItemTransaction->response());

    BOOST_REQUIRE_EQUAL(OpcUaStatusCode::Success, mm.receive(deleteMonitoredItemTransaction));
    BOOST_REQUIRE_EQUAL(0, mm.monitoredItemIds().size());
}

BOOST_AUTO_TEST_SUITE_END()


