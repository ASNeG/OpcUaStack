#include "unittest.h"

#include "OpcUaStackServer/ServiceSet/MonitorManager.h"
#include "OpcUaStackServer/AddressSpaceModel/VariableNodeClass.h"
#include "OpcUaStackCore/Application/ApplicationMonitoredItemStartContext.h"

using namespace OpcUaStackServer;


struct F {
    F() : mm()
    , informationModel(constructSPtr<InformationModel>())
    , ioThread(constructSPtr<IOThread>())
    , tran(constructSPtr<ServiceTransactionCreateMonitoredItems>())
    , startMonitoredItemCallCount(0)
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
		sync->monitoredItemStartService().setCallback(startMonitoredItemCallback);
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

		tran->request()->itemsToCreate(itemsToCreate);
    }

	void
	startMonitored(ApplicationMonitoredItemStartContext* context)
	{
		startMonitoredItemCallCount++;
	}

    ~F() { }

	MonitorManager mm;
	InformationModel::SPtr informationModel;
	IOThread::SPtr ioThread;

	ServiceTransactionCreateMonitoredItems::SPtr tran;

	size_t startMonitoredItemCallCount;

};


BOOST_FIXTURE_TEST_SUITE(MonitorManager_, F)

BOOST_AUTO_TEST_CASE(MonitorManager_)
{
	std::cout << "MonitorManager_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(MonitorManager_CallStartMonitoredItemCallback)
{
	BOOST_REQUIRE_EQUAL(OpcUaStatusCode::Success, mm.receive(tran));

	MonitoredItemCreateResult::SPtr result;
	tran->response()->results()->get(0, result);

	BOOST_REQUIRE_EQUAL(OpcUaStatusCode::Success, result->statusCode());
	BOOST_REQUIRE_EQUAL(1, startMonitoredItemCallCount);
}

BOOST_AUTO_TEST_CASE(MonitorManager_CallStartMonitoredItemCallbackOnlyOnce)
{
	BOOST_REQUIRE_EQUAL(OpcUaStatusCode::Success, mm.receive(tran));
	BOOST_REQUIRE_EQUAL(OpcUaStatusCode::Success, mm.receive(tran));

	MonitoredItemCreateResult::SPtr result;
	tran->response()->results()->get(0, result);

	BOOST_REQUIRE_EQUAL(OpcUaStatusCode::Success, result->statusCode());
	BOOST_REQUIRE_EQUAL(1, startMonitoredItemCallCount);
}


BOOST_AUTO_TEST_SUITE_END()


