#include "unittest.h"
#include "OpcUaStackCore/ComplexDataTypes/ComplexDataTypeParser.h"

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(ComplexDataTypeParser_t)

BOOST_AUTO_TEST_CASE(ComplexDataTypeParser_ComplexDataType)
{
	ComplexDataType::SPtr type;
	ComplexDataTypeParser parser;

	BOOST_REQUIRE(parser.parse("../tst/data/OpcUaComplexDataTypes.xml") == true);

	// BaseEventType
	type = parser.complexDataType("BaseEventType");
	BOOST_REQUIRE(type.get() != nullptr);
	BOOST_REQUIRE(type->name() == "BaseEventType");

	BOOST_REQUIRE(type->index2Name(0) == "EventId");
	BOOST_REQUIRE(type->complexDataTypeItem(0)->itemType() == OpcUaBuildInType_OpcUaByteString);
	BOOST_REQUIRE(type->complexDataTypeItem(0)->mandatory() == true);
	BOOST_REQUIRE(type->index2Name(1) == "EventType");
	BOOST_REQUIRE(type->complexDataTypeItem(1)->itemType() == OpcUaBuildInType_OpcUaNodeId);
	BOOST_REQUIRE(type->complexDataTypeItem(1)->mandatory() == true);
	BOOST_REQUIRE(type->index2Name(6) == "Message");
	BOOST_REQUIRE(type->complexDataTypeItem(6)->itemType() == OpcUaBuildInType_OpcUaLocalizedText);
	BOOST_REQUIRE(type->complexDataTypeItem(6)->mandatory() == true);
}

BOOST_AUTO_TEST_CASE(ComplexDataTypeParser_SuperType)
{
	ComplexDataType::SPtr type;
	ComplexDataTypeParser parser;

	BOOST_REQUIRE(parser.parse("../tst/data/OpcUaComplexDataTypes.xml") == true);

	// BaseEventType
	type = parser.complexDataType("AuditEventType");
	BOOST_REQUIRE(type.get() != nullptr);
	BOOST_REQUIRE(type->name() == "AuditEventType");

	// super type checks
	BOOST_REQUIRE(type->index2Name(0) == "EventId");
	BOOST_REQUIRE(type->complexDataTypeItem(0)->itemType() == OpcUaBuildInType_OpcUaByteString);
	BOOST_REQUIRE(type->complexDataTypeItem(0)->mandatory() == true);
	BOOST_REQUIRE(type->index2Name(1) == "EventType");
	BOOST_REQUIRE(type->complexDataTypeItem(1)->itemType() == OpcUaBuildInType_OpcUaNodeId);
	BOOST_REQUIRE(type->complexDataTypeItem(1)->mandatory() == true);
	BOOST_REQUIRE(type->index2Name(6) == "Message");
	BOOST_REQUIRE(type->complexDataTypeItem(6)->itemType() == OpcUaBuildInType_OpcUaLocalizedText);
	BOOST_REQUIRE(type->complexDataTypeItem(6)->mandatory() == true);

	// type checks
	BOOST_REQUIRE(type->index2Name(8) == "ActionTimeStamp");
	BOOST_REQUIRE(type->complexDataTypeItem(8)->itemType() == OpcUaBuildInType_OpcUaDateTime);
	BOOST_REQUIRE(type->complexDataTypeItem(8)->mandatory() == true);
	BOOST_REQUIRE(type->index2Name(9) == "Status");
	BOOST_REQUIRE(type->complexDataTypeItem(9)->itemType() == OpcUaBuildInType_OpcUaBoolean);
	BOOST_REQUIRE(type->complexDataTypeItem(9)->mandatory() == true);
}

BOOST_AUTO_TEST_SUITE_END()
