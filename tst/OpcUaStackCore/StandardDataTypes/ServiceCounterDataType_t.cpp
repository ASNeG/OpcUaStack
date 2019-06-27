#include "unittest.h"
#include "OpcUaStackCore/Core/Core.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaExtensionObject.h"
#include "OpcUaStackCore/StandardDataTypes/ServiceCounterDataType.h"

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(ServiceCounterDataType_)

BOOST_AUTO_TEST_CASE(ServiceCounterDataType_)
{
	std::cout << "ServiceCounterDataType_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(ServiceCounterDataType_encode_decode)
{
	ServiceCounterDataType value1;
	ServiceCounterDataType value2;

	value1.totalCount(1);
	value1.errorCount(2);

	std::stringstream ss;
	value1.opcUaBinaryEncode(ss);
	value2.opcUaBinaryDecode(ss);

	BOOST_REQUIRE(value2.totalCount() == 1);
	BOOST_REQUIRE(value2.errorCount() == 2);
}

BOOST_AUTO_TEST_CASE(ServiceCounterDataType_ExtensionObject)
{
	Core core;
	core.init();

	OpcUaExtensionObject value1;
	OpcUaExtensionObject value2;

	OpcUaNodeId typeId;
	typeId.set(OpcUaId_ServiceCounterDataType_Encoding_DefaultBinary);
	value1.typeId(typeId);
	value1.parameter<ServiceCounterDataType>()->totalCount(1);
	value1.parameter<ServiceCounterDataType>()->errorCount(2);

	std::stringstream ss;
	value1.opcUaBinaryEncode(ss);
	value2.opcUaBinaryDecode(ss);

	BOOST_REQUIRE(value2.parameter<ServiceCounterDataType>()->totalCount() == 1);
	BOOST_REQUIRE(value2.parameter<ServiceCounterDataType>()->errorCount() == 2);
}

BOOST_AUTO_TEST_CASE(ServiceCounterDataType_ExtensionObject_copyTo)
{
	Core core;
	core.init();

	OpcUaExtensionObject value1;
	OpcUaExtensionObject value2;

	OpcUaNodeId typeId;
	typeId.set(OpcUaId_ServiceCounterDataType_Encoding_DefaultBinary);
	value1.typeId(typeId);
	value1.parameter<ServiceCounterDataType>()->totalCount(1);
	value1.parameter<ServiceCounterDataType>()->errorCount(2);

	value1.copyTo(value2);

	BOOST_REQUIRE(value2.parameter<ServiceCounterDataType>()->totalCount() == 1);
	BOOST_REQUIRE(value2.parameter<ServiceCounterDataType>()->errorCount() == 2);
}


BOOST_AUTO_TEST_SUITE_END()


