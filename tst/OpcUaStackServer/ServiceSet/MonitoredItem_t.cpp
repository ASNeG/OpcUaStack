#include "unittest.h"

#include "OpcUaStackServer/ServiceSet/MonitorItem.h"
#include "OpcUaStackServer/AddressSpaceModel/VariableNodeClass.h"
#include "OpcUaStackServer/AddressSpaceModel/ObjectNodeClass.h"

using namespace OpcUaStackCore;
using namespace OpcUaStackServer;

BOOST_AUTO_TEST_SUITE(MonitoredItem_)

BOOST_AUTO_TEST_CASE(MonitoredItem_)
{
	std::cout << "MonitoredItem_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(MonitoredItem_minimalSamplingInterval)
{
    MonitoredItemCreateRequest::SPtr monitoredItemCreateRequest = boost::make_shared<MonitoredItemCreateRequest>();
    monitoredItemCreateRequest->requestedParameters().samplingInterval(100);

    BaseNodeClass::SPtr valueNode = boost::make_shared<VariableNodeClass>();

    OpcUaDouble minValue = 200;
    valueNode->setMinimumSamplingInterval(minValue);

    MonitorItem item;
    item.receive(valueNode, monitoredItemCreateRequest);

    BOOST_REQUIRE_EQUAL(200, item.samplingInterval());
}

BOOST_AUTO_TEST_CASE(MonitoredItem_minimalSamplingIntervalNull)
{
    MonitoredItemCreateRequest::SPtr monitoredItemCreateRequest = boost::make_shared<MonitoredItemCreateRequest>();
    monitoredItemCreateRequest->requestedParameters().samplingInterval(100);

    BaseNodeClass::SPtr valueNode = boost::make_shared<VariableNodeClass>();

    MonitorItem item;
    item.receive(valueNode, monitoredItemCreateRequest);

    BOOST_REQUIRE_EQUAL(100, item.samplingInterval());
}

BOOST_AUTO_TEST_CASE(MonitoredItem_minimalSamplingIntervalNotExist)
{
    MonitoredItemCreateRequest::SPtr monitoredItemCreateRequest = boost::make_shared<MonitoredItemCreateRequest>();
    monitoredItemCreateRequest->requestedParameters().samplingInterval(100);

    BaseNodeClass::SPtr valueNode = boost::make_shared<ObjectNodeClass>();

    MonitorItem item;
    item.receive(valueNode, monitoredItemCreateRequest);

    BOOST_REQUIRE_EQUAL(100, item.samplingInterval());
}

BOOST_AUTO_TEST_SUITE_END()


