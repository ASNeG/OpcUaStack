#include "unittest.h"
#include "OpcUaStackCore/StandardDataTypes/EventFilter.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaAttributeId.h"
#include "OpcUaStackCore/StandardDataTypes/LiteralOperand.h"
#include "OpcUaStackClient/CryptoManagerTest.h"
#include "OpcUaStackClient/ServiceSet/ServiceSetManager.h"

using namespace OpcUaStackCore;
using namespace OpcUaStackClient;

#ifdef REAL_SERVER

BOOST_AUTO_TEST_SUITE(ServiceSetManagerAsyncReal_EventItem)

struct GValueFixture {
	GValueFixture(void)
    : cond_()
	, sessionState_(SessionServiceStateId::None)
    {}
    ~GValueFixture(void)
    {}

    Condition cond_;
    SessionServiceStateId sessionState_;
};

BOOST_AUTO_TEST_CASE(ServiceSetManagerAsyncReal_EventItem)
{
	std::cout << "ServiceSetManagerAsyncReal_EventItem_t" << std::endl;
}

BOOST_FIXTURE_TEST_CASE(ServiceSetManagerAsyncReal_EventItem_event, GValueFixture)
{
	OpcUaStatusCode statusCode;
	ServiceSetManager serviceSetManager;

	//
	// init certificate and crypto manager
	//
	auto cryptoManager = CryptoManagerTest::getInstance();
	BOOST_REQUIRE(cryptoManager.get() != nullptr);

	// set secure channel configuration
	SessionServiceConfig sessionServiceConfig;
	sessionServiceConfig.secureChannelClient_->endpointUrl(REAL_SERVER_URI);
	sessionServiceConfig.secureChannelClient_->cryptoManager(cryptoManager);
	sessionServiceConfig.session_->sessionName(REAL_SESSION_NAME);
	sessionServiceConfig.sessionServiceChangeHandler_ =
		[this] (SessionBase& session, SessionServiceStateId sessionState) {
			if (sessionState == SessionServiceStateId::Established ||
				sessionState == SessionServiceStateId::Disconnected) {
				sessionState_ = sessionState;
				cond_.sendEvent();
			}
		};

	// create session
	auto sessionService = serviceSetManager.sessionService(sessionServiceConfig);
	BOOST_REQUIRE(sessionService.get() != nullptr);

	// connect secure channel
	cond_.condition(1,0);
	sessionService->asyncConnect();
	BOOST_REQUIRE(cond_.waitForCondition(1000) == true);
	BOOST_REQUIRE(sessionState_ == SessionServiceStateId::Established);

	// create subscription service
	SubscriptionServiceConfig subscriptionServiceConfig;
	subscriptionServiceConfig.subscriptionStateUpdateHandler_ =
		[this](SubscriptionState subscriptionState, uint32_t subscriptionId) {
		};
	subscriptionServiceConfig.dataChangeNotificationHandler_ =
		[this](const MonitoredItemNotification::SPtr& monitoredItem) {
			cond_.sendEvent();
		};

	subscriptionServiceConfig.eventNotificationHandler_ =
		[this](const OpcUaStackCore::EventFieldList::SPtr& eventFieldList) {
			// Here we will receive the event
			// ClientHandle: 2258
			// EventFields:  {i=2041},{8-2E9A27833029F302},{loc=de,txt=BaseEventType: Event message xx}
			//
			std::cout << "==========================" << std::endl;
			std::cout << eventFieldList->clientHandle() << std::endl;
			std::cout << eventFieldList->eventFields() << std::endl;

			if (eventFieldList->clientHandle() != 2258) return;
			if (eventFieldList->eventFields().size() != 3) return;

			cond_.sendEvent();
		};
	SubscriptionService::SPtr subscriptionService;
	subscriptionService = serviceSetManager.subscriptionService(sessionService, subscriptionServiceConfig);

	// create subscription
	auto subCreateTrx = boost::make_shared<ServiceTransactionCreateSubscription>();
	auto subCreateReq = subCreateTrx->request();
	auto subCreateRes = subCreateTrx->response();
	subCreateTrx->resultHandler(
		[this](ServiceTransactionCreateSubscription::SPtr& trx) {
			cond_.sendEvent();
		}
	);
	cond_.initEvent();
	subscriptionService->asyncSend(subCreateTrx);
	BOOST_REQUIRE(cond_.waitForCondition(1000) == true);
	BOOST_REQUIRE(subCreateTrx->responseHeader()->serviceResult() == Success);
	uint32_t subscriptionId = subCreateRes->subscriptionId();

	// create event item service
	MonitoredItemServiceConfig monitoredItemServiceConfig;
	auto monitoredItemService = serviceSetManager.monitoredItemService(sessionService, monitoredItemServiceConfig);

	//
	// create event filter
	//
	OpcUaExtensibleParameter filter;
	filter.parameterTypeId().set((OpcUaUInt32)OpcUaId_EventFilter_Encoding_DefaultBinary);
	auto eventFilter = filter.parameter<EventFilter>();

	// Generate select clause for event filter
	eventFilter->selectClauses().resize(3);

	auto eventTypeAttr = boost::make_shared<SimpleAttributeOperand>();
	eventTypeAttr->typeDefinitionId() = OpcUaNodeId((uint32_t)2041);
	eventTypeAttr->browsePath().set(boost::make_shared<OpcUaQualifiedName>("EventType"));
	eventTypeAttr->attributeId() = ((OpcUaUInt32)AttributeId_Value);
	eventFilter->selectClauses().push_back(eventTypeAttr);

	auto eventIdAttr = boost::make_shared<SimpleAttributeOperand>();
	eventIdAttr->typeDefinitionId() = OpcUaNodeId((uint32_t)2041);
	eventIdAttr->browsePath().set(boost::make_shared<OpcUaQualifiedName>("EventId"));
	eventIdAttr->attributeId() = ((OpcUaUInt32)AttributeId_Value);
	eventFilter->selectClauses().push_back(eventIdAttr);

	auto messageAttr = boost::make_shared<SimpleAttributeOperand>();
	messageAttr->typeDefinitionId() = OpcUaNodeId((uint32_t)2041);
	messageAttr->browsePath().set(boost::make_shared<OpcUaQualifiedName>("Message"));
	messageAttr->attributeId() = ((OpcUaUInt32)AttributeId_Value);
	eventFilter->selectClauses().push_back(messageAttr);

	// Generate where clause for event filter
	auto para1 = boost::make_shared<OpcUaExtensibleParameter>();
	para1->parameterTypeId().set((OpcUaUInt32)OpcUaId_SimpleAttributeOperand);
	auto attr1 = para1->parameter<SimpleAttributeOperand>();
	attr1->typeDefinitionId() = OpcUaNodeId((uint32_t)2041);
	attr1->browsePath().set(boost::make_shared<OpcUaQualifiedName>("EventType", 0));
	attr1->attributeId() = ((OpcUaUInt32)AttributeId_Value);

	auto para2 = boost::make_shared<OpcUaExtensibleParameter>();
	para2->parameterTypeId().set((OpcUaUInt32)OpcUaId_LiteralOperand);
	auto attr2 = para2->parameter<LiteralOperand>();
	attr2->value().setValue(OpcUaNodeId((uint32_t)2041));

	auto contentFilterElement = boost::make_shared<ContentFilterElement>();
	contentFilterElement->filterOperator().enumeration(FilterOperator::Enum::EnumEquals);
	contentFilterElement->filterOperands().resize(2);
	contentFilterElement->filterOperands().push_back(para1);
	contentFilterElement->filterOperands().push_back(para2);
	eventFilter->whereClause().elements().resize(1);

	eventFilter->whereClause().elements().push_back(contentFilterElement);

	// create event item
	auto monCreateTrx = boost::make_shared<ServiceTransactionCreateMonitoredItems>();
	auto monCreateReq = monCreateTrx->request();
	auto monCreateRes = monCreateTrx->response();
	monCreateReq->subscriptionId(subscriptionId);

	auto monitoredItemCreateRequest = boost::make_shared<MonitoredItemCreateRequest>();
	monitoredItemCreateRequest->itemToMonitor().nodeId()->set("Event11",14);
	monitoredItemCreateRequest->requestedParameters().clientHandle(2258);
	monitoredItemCreateRequest->requestedParameters().samplingInterval(500);
	monitoredItemCreateRequest->requestedParameters().filter(filter);
	monitoredItemCreateRequest->requestedParameters().queueSize(5);
	monitoredItemCreateRequest->requestedParameters().discardOldest(true);

	monCreateReq->itemsToCreate()->resize(1);
	monCreateReq->itemsToCreate()->set(0, monitoredItemCreateRequest);
	cond_.initEvent();
	monitoredItemService->syncSend(monCreateTrx);
	BOOST_REQUIRE(monCreateTrx->statusCode() == Success);
	BOOST_REQUIRE(monCreateRes->results()->size() == 1);

	MonitoredItemCreateResult::SPtr createMonResult;
	monCreateRes->results()->get(0, createMonResult);
	BOOST_REQUIRE(createMonResult->statusCode() == Success);
	uint32_t monitoredItemId = createMonResult->monitoredItemId();

	BOOST_REQUIRE(cond_.waitForCondition(5000) == true);


	// delete monitored item
	auto monDeleteTrx = boost::make_shared<ServiceTransactionDeleteMonitoredItems>();
	auto monDeleteReq = monDeleteTrx->request();
	auto monDeleteRes = monDeleteTrx->response();
	monDeleteReq->subscriptionId(subscriptionId);

	monDeleteReq->monitoredItemIds()->resize(1);
	monDeleteReq->monitoredItemIds()->set(0, createMonResult->monitoredItemId());
	monitoredItemService->syncSend(monDeleteTrx);
	BOOST_REQUIRE(monDeleteTrx->statusCode() == Success);


	BOOST_REQUIRE(monDeleteRes->results()->size() == 1);
	monDeleteRes->results()->get(0, statusCode);
	BOOST_REQUIRE(statusCode == Success);

	// delete subscription
	auto subDeleteTrx = boost::make_shared<ServiceTransactionDeleteSubscriptions>();
	auto subDeleteReq = subDeleteTrx->request();
	auto subDeleteRes = subDeleteTrx->response();
	subDeleteReq->subscriptionIds()->resize(1);
	subDeleteReq->subscriptionIds()->set(0, subscriptionId);
	subDeleteTrx->resultHandler(
		[this](ServiceTransactionDeleteSubscriptions::SPtr& trx) {
			cond_.sendEvent();
		}
	);
	cond_.initEvent();
	subscriptionService->asyncSend(subDeleteTrx);
	BOOST_REQUIRE(cond_.waitForCondition(1000) == true);
	BOOST_REQUIRE(subDeleteTrx->responseHeader()->serviceResult() == Success);
	BOOST_REQUIRE(subDeleteRes->results()->size() == 1);
	subDeleteRes->results()->get(0, statusCode);
	BOOST_REQUIRE(statusCode == Success);

	// disconnect secure channel
	cond_.condition(1,0);
	sessionService->asyncDisconnect();
	BOOST_REQUIRE(cond_.waitForCondition(1000) == true);
	BOOST_REQUIRE(sessionState_ == SessionServiceStateId::Disconnected);
}


BOOST_AUTO_TEST_SUITE_END()

#endif
