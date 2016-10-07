#include "unittest.h"
#include "OpcUaStackCore/Core/Core.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaExtensionObject.h"
#include "OpcUaStackCore/StandardDataTypes/BuildInfo.h"

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(BuildInfo_)

BOOST_AUTO_TEST_CASE(BuildInfo_)
{
	std::cout << "BuildInfo_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(BuildInfo_encode_decode)
{
	BuildInfo value1;
	BuildInfo value2;
	OpcUaDateTime now(boost::posix_time::microsec_clock::local_time());

	value1.productUri() = "ProductUri";
	value1.manufacturerName() = "ManufacturerName";
	value1.productName() = "ProductName";
	value1.softwareVersion() = "SoftwareVersion";
	value1.buildNumber() = "BuildNumber";
	value1.buildDate() = now;

	std::stringstream ss;
	value1.opcUaBinaryEncode(ss);
	value2.opcUaBinaryDecode(ss);

	BOOST_REQUIRE(value2.productUri().value() == "ProductUri");
	BOOST_REQUIRE(value2.manufacturerName().value() == "ManufacturerName");
	BOOST_REQUIRE(value2.productName().value() == "ProductName");
	BOOST_REQUIRE(value2.softwareVersion().value() == "SoftwareVersion");
	BOOST_REQUIRE(value2.buildNumber().value() == "BuildNumber");
	BOOST_REQUIRE(value2.buildDate() == now);
}

BOOST_AUTO_TEST_CASE(BuildInfo_ExtensionObject)
{
	Core core;
	core.init();

	OpcUaExtensionObject value1;
	OpcUaExtensionObject value2;
	OpcUaDateTime now(boost::posix_time::microsec_clock::local_time());

	OpcUaNodeId typeId;
	typeId.set(OpcUaId_BuildInfo_Encoding_DefaultBinary);
	value1.typeId(typeId);
	value1.parameter<BuildInfo>()->productUri() = "ProductUri";
	value1.parameter<BuildInfo>()->manufacturerName() = "ManufacturerName";
	value1.parameter<BuildInfo>()->productName() = "ProductName";
	value1.parameter<BuildInfo>()->softwareVersion() = "SoftwareVersion";
	value1.parameter<BuildInfo>()->buildNumber() = "BuildNumber";
	value1.parameter<BuildInfo>()->buildDate() = now;

	std::stringstream ss;
	value1.opcUaBinaryEncode(ss);
	value2.opcUaBinaryDecode(ss);

	BOOST_REQUIRE(value2.parameter<BuildInfo>()->productUri().value() == "ProductUri");
	BOOST_REQUIRE(value2.parameter<BuildInfo>()->manufacturerName().value() == "ManufacturerName");
	BOOST_REQUIRE(value2.parameter<BuildInfo>()->productName().value() == "ProductName");
	BOOST_REQUIRE(value2.parameter<BuildInfo>()->softwareVersion().value() == "SoftwareVersion");
	BOOST_REQUIRE(value2.parameter<BuildInfo>()->buildNumber().value() == "BuildNumber");
	BOOST_REQUIRE(value2.parameter<BuildInfo>()->buildDate() == now);
}

BOOST_AUTO_TEST_CASE(BuildInfo_ExtensionObject_copyTo)
{
	Core core;
	core.init();

	OpcUaExtensionObject value1;
	OpcUaExtensionObject value2;
	OpcUaDateTime now(boost::posix_time::microsec_clock::local_time());

	OpcUaNodeId typeId;
	typeId.set(OpcUaId_BuildInfo_Encoding_DefaultBinary);
	value1.typeId(typeId);
	value1.parameter<BuildInfo>()->productUri() = "ProductUri";
	value1.parameter<BuildInfo>()->manufacturerName() = "ManufacturerName";
	value1.parameter<BuildInfo>()->productName() = "ProductName";
	value1.parameter<BuildInfo>()->softwareVersion() = "SoftwareVersion";
	value1.parameter<BuildInfo>()->buildNumber() = "BuildNumber";
	value1.parameter<BuildInfo>()->buildDate() = now;

	value1.copyTo(value2);

	BOOST_REQUIRE(value2.parameter<BuildInfo>()->productUri().value() == "ProductUri");
	BOOST_REQUIRE(value2.parameter<BuildInfo>()->manufacturerName().value() == "ManufacturerName");
	BOOST_REQUIRE(value2.parameter<BuildInfo>()->productName().value() == "ProductName");
	BOOST_REQUIRE(value2.parameter<BuildInfo>()->softwareVersion().value() == "SoftwareVersion");
	BOOST_REQUIRE(value2.parameter<BuildInfo>()->buildNumber().value() == "BuildNumber");
	BOOST_REQUIRE(value2.parameter<BuildInfo>()->buildDate() == now);
}


BOOST_AUTO_TEST_SUITE_END()
