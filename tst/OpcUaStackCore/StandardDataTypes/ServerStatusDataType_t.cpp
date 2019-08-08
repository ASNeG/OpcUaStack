#include "unittest.h"
#include "OpcUaStackCore/Core/Core.h"
#include "OpcUaStackCore/Base/ConfigXml.h"
#include "OpcUaStackCore/Base/ConfigJson.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaExtensionObject.h"
#include "OpcUaStackCore/StandardDataTypes/ServerStatusDataType.h"

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(ServerStatusDataType_)

BOOST_AUTO_TEST_CASE(ServerStatusDataType_)
{
	std::cout << "ServerStatusDataType_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(ServerStatusDataType_encode_decode_bin)
{
	ServerStatusDataType value1;
	ServerStatusDataType value2;
	OpcUaDateTime now(boost::posix_time::microsec_clock::local_time());

	value1.startTime() = now;
	value1.currentTime() = now;
	value1.state() = ServerState::EnumShutdown;
	value1.secondsTillShutdown() = 123;
	value1.shutdownReason().set("de", "maintain");
	value1.buildInfo().productUri() = "ProductUri";
	value1.buildInfo().manufacturerName() = "ManufacturerName";
	value1.buildInfo().productName() = "ProductName";
	value1.buildInfo().softwareVersion() = "SoftwareVersion";
	value1.buildInfo().buildNumber() = "BuildNumber";
	value1.buildInfo().buildDate() = now;

	std::stringstream ss;
	value1.opcUaBinaryEncode(ss);
	value2.opcUaBinaryDecode(ss);

	BOOST_REQUIRE(value2.startTime() == now);
	BOOST_REQUIRE(value2.currentTime() == now);
	BOOST_REQUIRE(value2.state() == ServerState::EnumShutdown);
	BOOST_REQUIRE(value2.secondsTillShutdown() == 123);
	BOOST_REQUIRE(value2.shutdownReason() == OpcUaLocalizedText("de", "maintain"));
	BOOST_REQUIRE(value2.buildInfo().productUri().value() == "ProductUri");
	BOOST_REQUIRE(value2.buildInfo().manufacturerName().value() == "ManufacturerName");
	BOOST_REQUIRE(value2.buildInfo().productName().value() == "ProductName");
	BOOST_REQUIRE(value2.buildInfo().softwareVersion().value() == "SoftwareVersion");
	BOOST_REQUIRE(value2.buildInfo().buildNumber().value() == "BuildNumber");
	BOOST_REQUIRE(value2.buildInfo().buildDate() == now);
}

BOOST_AUTO_TEST_CASE(ServerStatusDataType_encode_decode_xml)
{
	ServerStatusDataType value1;
	ServerStatusDataType value2;
	OpcUaDateTime now(boost::posix_time::microsec_clock::local_time());

	value1.startTime() = now;
	value1.currentTime() = now;
	value1.state() = ServerState::EnumShutdown;
	value1.secondsTillShutdown() = 123;
	value1.shutdownReason().set("de", "maintain");
	value1.buildInfo().productUri() = "ProductUri";
	value1.buildInfo().manufacturerName() = "ManufacturerName";
	value1.buildInfo().productName() = "ProductName";
	value1.buildInfo().softwareVersion() = "SoftwareVersion";
	value1.buildInfo().buildNumber() = "BuildNumber";
	value1.buildInfo().buildDate() = now;

	Xmlns xmlns;
	boost::property_tree::ptree pt;
	value1.xmlEncode(pt, xmlns);

	ConfigXml xml;
	xml.ptree(pt);
	xml.write(std::cout);
	std::cout << std::endl;

	value2.xmlDecode(pt, xmlns);

	BOOST_REQUIRE(value2.startTime().toISO8601() == value1.startTime().toISO8601());
	BOOST_REQUIRE(value2.currentTime().toISO8601() == value1.currentTime().toISO8601());
	BOOST_REQUIRE(value2.state() == ServerState::EnumShutdown);
	BOOST_REQUIRE(value2.secondsTillShutdown() == 123);
	BOOST_REQUIRE(value2.shutdownReason() == OpcUaLocalizedText("de", "maintain"));
	BOOST_REQUIRE(value2.buildInfo().productUri().value() == "ProductUri");
	BOOST_REQUIRE(value2.buildInfo().manufacturerName().value() == "ManufacturerName");
	BOOST_REQUIRE(value2.buildInfo().productName().value() == "ProductName");
	BOOST_REQUIRE(value2.buildInfo().softwareVersion().value() == "SoftwareVersion");
	BOOST_REQUIRE(value2.buildInfo().buildNumber().value() == "BuildNumber");
	BOOST_REQUIRE(value2.buildInfo().buildDate().toISO8601() == value1.buildInfo().buildDate().toISO8601());
}

BOOST_AUTO_TEST_CASE(ServerStatusDataType_encode_decode_json)
{
	ServerStatusDataType value1;
	ServerStatusDataType value2;
	OpcUaDateTime now(boost::posix_time::microsec_clock::local_time());

	value1.startTime() = now;
	value1.currentTime() = now;
	value1.state() = ServerState::EnumShutdown;
	value1.secondsTillShutdown() = 123;
	value1.shutdownReason().set("de", "maintain");
	value1.buildInfo().productUri() = "ProductUri";
	value1.buildInfo().manufacturerName() = "ManufacturerName";
	value1.buildInfo().productName() = "ProductName";
	value1.buildInfo().softwareVersion() = "SoftwareVersion";
	value1.buildInfo().buildNumber() = "BuildNumber";
	value1.buildInfo().buildDate() = now;

	boost::property_tree::ptree pt;
	value1.jsonEncode(pt);

	ConfigJson json;
	json.ptree(pt);
	json.write(std::cout);
	std::cout << std::endl;

	value2.jsonDecode(pt);

	BOOST_REQUIRE(value2.startTime().toISO8601() == value1.startTime().toISO8601());
	BOOST_REQUIRE(value2.currentTime().toISO8601() == value1.currentTime().toISO8601());
	BOOST_REQUIRE(value2.state() == ServerState::EnumShutdown);
	BOOST_REQUIRE(value2.secondsTillShutdown() == 123);
	BOOST_REQUIRE(value2.shutdownReason() == OpcUaLocalizedText("de", "maintain"));
	BOOST_REQUIRE(value2.buildInfo().productUri().value() == "ProductUri");
	BOOST_REQUIRE(value2.buildInfo().manufacturerName().value() == "ManufacturerName");
	BOOST_REQUIRE(value2.buildInfo().productName().value() == "ProductName");
	BOOST_REQUIRE(value2.buildInfo().softwareVersion().value() == "SoftwareVersion");
	BOOST_REQUIRE(value2.buildInfo().buildNumber().value() == "BuildNumber");
	BOOST_REQUIRE(value2.buildInfo().buildDate().toISO8601() == value1.buildInfo().buildDate().toISO8601());
}


BOOST_AUTO_TEST_CASE(ServerStatusDataType_ExtensionObject)
{
	Core core;
	core.init();

	OpcUaExtensionObject value1;
	OpcUaExtensionObject value2;
	OpcUaDateTime now(boost::posix_time::microsec_clock::local_time());

	OpcUaNodeId typeId;
	typeId.set(OpcUaId_ServerStatusDataType_Encoding_DefaultBinary);
	value1.typeId(typeId);
	value1.parameter<ServerStatusDataType>()->startTime() = now;
	value1.parameter<ServerStatusDataType>()->currentTime() = now;
	value1.parameter<ServerStatusDataType>()->state() = ServerState::EnumRunning;
	value1.parameter<ServerStatusDataType>()->secondsTillShutdown() = 123;
	value1.parameter<ServerStatusDataType>()->shutdownReason().set("de", "maintain");
	value1.parameter<ServerStatusDataType>()->buildInfo().productUri() = "ProductUri";
	value1.parameter<ServerStatusDataType>()->buildInfo().manufacturerName() = "ManufacturerName";
	value1.parameter<ServerStatusDataType>()->buildInfo().productName() = "ProductName";
	value1.parameter<ServerStatusDataType>()->buildInfo().softwareVersion() = "SoftwareVersion";
	value1.parameter<ServerStatusDataType>()->buildInfo().buildNumber() = "BuildNumber";
	value1.parameter<ServerStatusDataType>()->buildInfo().buildDate() = now;

	std::stringstream ss;
	value1.opcUaBinaryEncode(ss);
	value2.opcUaBinaryDecode(ss);

	BOOST_REQUIRE(value2.parameter<ServerStatusDataType>()->startTime() == now);
	BOOST_REQUIRE(value2.parameter<ServerStatusDataType>()->currentTime() == now);
	BOOST_REQUIRE(value2.parameter<ServerStatusDataType>()->state() == ServerState::EnumRunning);
	BOOST_REQUIRE(value2.parameter<ServerStatusDataType>()->secondsTillShutdown() == 123);
	BOOST_REQUIRE(value2.parameter<ServerStatusDataType>()->shutdownReason() == OpcUaLocalizedText("de", "maintain"));
	BOOST_REQUIRE(value2.parameter<ServerStatusDataType>()->buildInfo().productUri().value() == "ProductUri");
	BOOST_REQUIRE(value2.parameter<ServerStatusDataType>()->buildInfo().manufacturerName().value() == "ManufacturerName");
	BOOST_REQUIRE(value2.parameter<ServerStatusDataType>()->buildInfo().productName().value() == "ProductName");
	BOOST_REQUIRE(value2.parameter<ServerStatusDataType>()->buildInfo().softwareVersion().value() == "SoftwareVersion");
	BOOST_REQUIRE(value2.parameter<ServerStatusDataType>()->buildInfo().buildNumber().value() == "BuildNumber");
	BOOST_REQUIRE(value2.parameter<ServerStatusDataType>()->buildInfo().buildDate() == now);
}

BOOST_AUTO_TEST_CASE(ServerStatusDataType_ExtensionObject_copyTo)
{
	Core core;
	core.init();

	OpcUaExtensionObject value1;
	OpcUaExtensionObject value2;
	OpcUaDateTime now(boost::posix_time::microsec_clock::local_time());

	OpcUaNodeId typeId;
	typeId.set(OpcUaId_ServerStatusDataType_Encoding_DefaultBinary);
	value1.typeId(typeId);
	value1.parameter<ServerStatusDataType>()->startTime() = now;
	value1.parameter<ServerStatusDataType>()->currentTime() = now;
	value1.parameter<ServerStatusDataType>()->state() = ServerState::EnumRunning;
	value1.parameter<ServerStatusDataType>()->secondsTillShutdown() = 123;
	value1.parameter<ServerStatusDataType>()->shutdownReason().set("de", "maintain");
	value1.parameter<ServerStatusDataType>()->buildInfo().productUri() = "ProductUri";
	value1.parameter<ServerStatusDataType>()->buildInfo().manufacturerName() = "ManufacturerName";
	value1.parameter<ServerStatusDataType>()->buildInfo().productName() = "ProductName";
	value1.parameter<ServerStatusDataType>()->buildInfo().softwareVersion() = "SoftwareVersion";
	value1.parameter<ServerStatusDataType>()->buildInfo().buildNumber() = "BuildNumber";
	value1.parameter<ServerStatusDataType>()->buildInfo().buildDate() = now;

	value1.copyTo(value2);

	BOOST_REQUIRE(value2.parameter<ServerStatusDataType>()->startTime() == now);
	BOOST_REQUIRE(value2.parameter<ServerStatusDataType>()->currentTime() == now);
	BOOST_REQUIRE(value2.parameter<ServerStatusDataType>()->state() == ServerState::EnumRunning);
	BOOST_REQUIRE(value2.parameter<ServerStatusDataType>()->secondsTillShutdown() == 123);
	BOOST_REQUIRE(value2.parameter<ServerStatusDataType>()->shutdownReason() == OpcUaLocalizedText("de", "maintain"));
	BOOST_REQUIRE(value2.parameter<ServerStatusDataType>()->buildInfo().productUri().value() == "ProductUri");
	BOOST_REQUIRE(value2.parameter<ServerStatusDataType>()->buildInfo().manufacturerName().value() == "ManufacturerName");
	BOOST_REQUIRE(value2.parameter<ServerStatusDataType>()->buildInfo().productName().value() == "ProductName");
	BOOST_REQUIRE(value2.parameter<ServerStatusDataType>()->buildInfo().softwareVersion().value() == "SoftwareVersion");
	BOOST_REQUIRE(value2.parameter<ServerStatusDataType>()->buildInfo().buildNumber().value() == "BuildNumber");
	BOOST_REQUIRE(value2.parameter<ServerStatusDataType>()->buildInfo().buildDate() == now);
}


BOOST_AUTO_TEST_SUITE_END()
