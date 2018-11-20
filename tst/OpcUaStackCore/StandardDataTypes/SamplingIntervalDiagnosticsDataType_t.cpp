#include "unittest.h"
#include "OpcUaStackCore/Core/Core.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaExtensionObject.h"
#include "OpcUaStackCore/StandardDataTypes/SamplingIntervalDiagnosticsDataType.h"

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(SamplingIntervalDiagnosticsDataType_)

BOOST_AUTO_TEST_CASE(SamplingIntervalDiagnosticsDataType_)
{
	std::cout << "SamplingIntervalDiagnosticsDataType_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(SamplingIntervalDiagnosticsDataType_encode_decode)
{
	SamplingIntervalDiagnosticsDataType value1;
	SamplingIntervalDiagnosticsDataType value2;

	value1.samplingInterval() = 1;
	value1.monitoredItemCount() = 2;
	value1.maxMonitoredItemCount() = 3;
	value1.disabledMonitoredItemCount() = 4;

	std::stringstream ss;
	value1.opcUaBinaryEncode(ss);
	value2.opcUaBinaryDecode(ss);

	BOOST_REQUIRE(value2.samplingInterval() == 1);
	BOOST_REQUIRE(value2.monitoredItemCount() == 2);
	BOOST_REQUIRE(value2.maxMonitoredItemCount() == 3);
	BOOST_REQUIRE(value2.disabledMonitoredItemCount() == 4);
}

BOOST_AUTO_TEST_CASE(SamplingIntervalDiagnosticsDataType_ExtensionObject)
{
	Core core;
	core.init();

	OpcUaExtensionObject value1;
	OpcUaExtensionObject value2;

	OpcUaNodeId typeId;
	typeId.set(OpcUaId_SamplingIntervalDiagnosticsDataType_Encoding_DefaultBinary);
	value1.typeId(typeId);
	value1.parameter<SamplingIntervalDiagnosticsDataType>()->samplingInterval() = 1;
	value1.parameter<SamplingIntervalDiagnosticsDataType>()->monitoredItemCount() =  2;
	value1.parameter<SamplingIntervalDiagnosticsDataType>()->maxMonitoredItemCount() = 3;
	value1.parameter<SamplingIntervalDiagnosticsDataType>()->disabledMonitoredItemCount() = 4;

	std::stringstream ss;
	value1.opcUaBinaryEncode(ss);
	value2.opcUaBinaryDecode(ss);

	BOOST_REQUIRE(value2.parameter<SamplingIntervalDiagnosticsDataType>()->samplingInterval() == 1);
	BOOST_REQUIRE(value2.parameter<SamplingIntervalDiagnosticsDataType>()->monitoredItemCount() == 2);
	BOOST_REQUIRE(value2.parameter<SamplingIntervalDiagnosticsDataType>()->maxMonitoredItemCount() == 3);
	BOOST_REQUIRE(value2.parameter<SamplingIntervalDiagnosticsDataType>()->disabledMonitoredItemCount() == 4);
}

BOOST_AUTO_TEST_CASE(SamplingIntervalDiagnosticsDataType_ExtensionObject_copyTo)
{
	Core core;
	core.init();

	OpcUaExtensionObject value1;
	OpcUaExtensionObject value2;

	OpcUaNodeId typeId;
	typeId.set(OpcUaId_SamplingIntervalDiagnosticsDataType_Encoding_DefaultBinary);
	value1.typeId(typeId);
	value1.parameter<SamplingIntervalDiagnosticsDataType>()->samplingInterval() = 1;
	value1.parameter<SamplingIntervalDiagnosticsDataType>()->monitoredItemCount() = 2;
	value1.parameter<SamplingIntervalDiagnosticsDataType>()->maxMonitoredItemCount() = 3;
	value1.parameter<SamplingIntervalDiagnosticsDataType>()->disabledMonitoredItemCount() = 4;

	value1.copyTo(value2);

	BOOST_REQUIRE(value2.parameter<SamplingIntervalDiagnosticsDataType>()->samplingInterval() == 1);
	BOOST_REQUIRE(value2.parameter<SamplingIntervalDiagnosticsDataType>()->monitoredItemCount() == 2);
	BOOST_REQUIRE(value2.parameter<SamplingIntervalDiagnosticsDataType>()->maxMonitoredItemCount() == 3);
	BOOST_REQUIRE(value2.parameter<SamplingIntervalDiagnosticsDataType>()->disabledMonitoredItemCount() == 4);
}


BOOST_AUTO_TEST_SUITE_END()



