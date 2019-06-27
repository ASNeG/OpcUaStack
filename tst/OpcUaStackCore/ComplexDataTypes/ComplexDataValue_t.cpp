#include "unittest.h"
#include "OpcUaStackCore/ComplexDataTypes/ComplexDataValue.h"

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(ComplexDataValue_t)


BOOST_AUTO_TEST_CASE(ComplexDataValue_ComplexDataTypeItem)
{
	ComplexDataTypeItem::Vec myComplexDataTypeVec;
	ComplexDataTypeItem::SPtr value;
	value = constructSPtr<ComplexDataTypeItem>("Field1", OpcUaBuildInType_OpcUaBoolean);
	myComplexDataTypeVec.push_back(value);
	value = constructSPtr<ComplexDataTypeItem>("Field2", OpcUaBuildInType_OpcUaDouble);
	myComplexDataTypeVec.push_back(value);
	value = constructSPtr<ComplexDataTypeItem>("Field3", OpcUaBuildInType_OpcUaInt32);
	myComplexDataTypeVec.push_back(value);
	value = constructSPtr<ComplexDataTypeItem>("Field4", OpcUaBuildInType_OpcUaString);
	myComplexDataTypeVec.push_back(value);
	value = constructSPtr<ComplexDataTypeItem>("Field5", OpcUaBuildInType_OpcUaNodeId);
	myComplexDataTypeVec.push_back(value);
	value = constructSPtr<ComplexDataTypeItem>("Field5", OpcUaBuildInType_OpcUaDateTime);
	myComplexDataTypeVec.push_back(value);

	BOOST_REQUIRE(myComplexDataTypeVec[3]->itemName() == "Field4");
	BOOST_REQUIRE(myComplexDataTypeVec[3]->itemType() == OpcUaBuildInType_OpcUaString);
}

BOOST_AUTO_TEST_CASE(ComplexDataValue_create_ComplexDataType)
{
	// create complex data type description
	ComplexDataTypeItem::Vec myComplexDataTypeVec;
	ComplexDataTypeItem::SPtr value;
	value = constructSPtr<ComplexDataTypeItem>("Field1", OpcUaBuildInType_OpcUaBoolean);
	myComplexDataTypeVec.push_back(value);
	value = constructSPtr<ComplexDataTypeItem>("Field2", OpcUaBuildInType_OpcUaDouble);
	myComplexDataTypeVec.push_back(value);
	value = constructSPtr<ComplexDataTypeItem>("Field3", OpcUaBuildInType_OpcUaInt32);
	myComplexDataTypeVec.push_back(value);
	value = constructSPtr<ComplexDataTypeItem>("Field4", OpcUaBuildInType_OpcUaString);
	myComplexDataTypeVec.push_back(value);
	value = constructSPtr<ComplexDataTypeItem>("Field5", OpcUaBuildInType_OpcUaNodeId);
	myComplexDataTypeVec.push_back(value);
	value = constructSPtr<ComplexDataTypeItem>("Field6", OpcUaBuildInType_OpcUaDateTime);
	myComplexDataTypeVec.push_back(value);

	// create complex data type
	ComplexDataType::SPtr myComplexDataType = constructSPtr<ComplexDataType>();
	myComplexDataType->name("MyComplexDataType");
	myComplexDataType->complexDataTypeItemVec(myComplexDataTypeVec);
	myComplexDataType->binaryTypeId(OpcUaNodeId("MyComplexType", 1));

	BOOST_REQUIRE(myComplexDataType->size() == 6);

	BOOST_REQUIRE(myComplexDataType->index2Name(0) == "Field1");
	BOOST_REQUIRE(myComplexDataType->index2Name(1) == "Field2");
	BOOST_REQUIRE(myComplexDataType->index2Name(5) == "Field6");
	BOOST_REQUIRE(myComplexDataType->index2Name(5555) == "");

	BOOST_REQUIRE(myComplexDataType->name2Index("Field1") == 0);
	BOOST_REQUIRE(myComplexDataType->name2Index("Field2") == 1);
	BOOST_REQUIRE(myComplexDataType->name2Index("Field6") == 5);
	BOOST_REQUIRE(myComplexDataType->name2Index("Unknown") == -1);
}

BOOST_AUTO_TEST_CASE(ComplexDataValue_create_ComplexDataValue)
{
	// create complex data type description
	ComplexDataTypeItem::Vec myComplexDataTypeVec;
	ComplexDataTypeItem::SPtr value;
	value = constructSPtr<ComplexDataTypeItem>("Field1", OpcUaBuildInType_OpcUaBoolean);
	myComplexDataTypeVec.push_back(value);
	value = constructSPtr<ComplexDataTypeItem>("Field2", OpcUaBuildInType_OpcUaDouble);
	myComplexDataTypeVec.push_back(value);
	value = constructSPtr<ComplexDataTypeItem>("Field3", OpcUaBuildInType_OpcUaInt32);
	myComplexDataTypeVec.push_back(value);
	value = constructSPtr<ComplexDataTypeItem>("Field4", OpcUaBuildInType_OpcUaString);
	myComplexDataTypeVec.push_back(value);
	value = constructSPtr<ComplexDataTypeItem>("Field5", OpcUaBuildInType_OpcUaNodeId);
	myComplexDataTypeVec.push_back(value);
	value = constructSPtr<ComplexDataTypeItem>("Field6", OpcUaBuildInType_OpcUaDateTime);
	myComplexDataTypeVec.push_back(value);

	// create complex data type
	ComplexDataType::SPtr myComplexDataType = constructSPtr<ComplexDataType>();
	myComplexDataType->name("MyComplexDataType");
	myComplexDataType->complexDataTypeItemVec(myComplexDataTypeVec);
	myComplexDataType->binaryTypeId(OpcUaNodeId("MyComplexType", 1));

	// create complex data type value
	ComplexDataValue myComplexDataValue(myComplexDataType);

	BOOST_REQUIRE(myComplexDataType->size() == 6);

	BOOST_REQUIRE(myComplexDataValue.index2Name(0) == "Field1");
	BOOST_REQUIRE(myComplexDataValue.index2Name(1) == "Field2");
	BOOST_REQUIRE(myComplexDataValue.index2Name(5) == "Field6");
	BOOST_REQUIRE(myComplexDataValue.index2Name(5555) == "");

	BOOST_REQUIRE(myComplexDataValue.name2Index("Field1") == 0);
	BOOST_REQUIRE(myComplexDataValue.name2Index("Field2") == 1);
	BOOST_REQUIRE(myComplexDataValue.name2Index("Field6") == 5);
	BOOST_REQUIRE(myComplexDataValue.name2Index("Unknown") == -1);
}

BOOST_AUTO_TEST_CASE(ComplexDataValue_setValue_getValue)
{
	boost::posix_time::ptime now = boost::posix_time::microsec_clock::universal_time();

	// create complex data type description
	ComplexDataTypeItem::Vec myComplexDataTypeVec;
	ComplexDataTypeItem::SPtr value;
	value = constructSPtr<ComplexDataTypeItem>("Field1", OpcUaBuildInType_OpcUaBoolean);
	myComplexDataTypeVec.push_back(value);
	value = constructSPtr<ComplexDataTypeItem>("Field2", OpcUaBuildInType_OpcUaDouble);
	myComplexDataTypeVec.push_back(value);
	value = constructSPtr<ComplexDataTypeItem>("Field3", OpcUaBuildInType_OpcUaInt32);
	myComplexDataTypeVec.push_back(value);
	value = constructSPtr<ComplexDataTypeItem>("Field4", OpcUaBuildInType_OpcUaString);
	myComplexDataTypeVec.push_back(value);
	value = constructSPtr<ComplexDataTypeItem>("Field5", OpcUaBuildInType_OpcUaNodeId);
	myComplexDataTypeVec.push_back(value);
	value = constructSPtr<ComplexDataTypeItem>("Field6", OpcUaBuildInType_OpcUaDateTime);
	myComplexDataTypeVec.push_back(value);

	// create complex data type
	ComplexDataType::SPtr myComplexDataType = constructSPtr<ComplexDataType>();
	myComplexDataType->name("MyComplexDataType");
	myComplexDataType->complexDataTypeItemVec(myComplexDataTypeVec);
	myComplexDataType->binaryTypeId(OpcUaNodeId("MyComplexType", 1));

	// create complex data type value
	ComplexDataValue myComplexDataValue(myComplexDataType);

	// set and get values
	OpcUaVariant::SPtr variant;
	variant = myComplexDataValue.getValue("Field1");
	variant->variant(OpcUaBoolean(true));
	variant = myComplexDataValue.getValue("Field2");
    variant->variant(OpcUaDouble(1.2345));
    variant = myComplexDataValue.getValue("Field3");
    variant->variant(OpcUaInt32(12345));

    OpcUaString::SPtr str = constructSPtr<OpcUaString>("StringValue");
    variant = myComplexDataValue.getValue(3);
    variant->variant(str);
    OpcUaNodeId::SPtr nodeId = constructSPtr<OpcUaNodeId>(OpcUaNodeId("NodeId",1));
    variant = myComplexDataValue.getValue(4);
    variant->variant(nodeId);
    variant = myComplexDataValue.getValue(5);
    variant->variant(OpcUaDateTime(now));

    BOOST_REQUIRE(myComplexDataValue.getValue(0)->get<OpcUaBoolean>() == true);
    BOOST_REQUIRE(myComplexDataValue.getValue(1)->get<OpcUaDouble>() == 1.2345);
    BOOST_REQUIRE(myComplexDataValue.getValue(2)->get<OpcUaInt32>() == 12345);
    BOOST_REQUIRE(myComplexDataValue.getValue("Field4")->getSPtr<OpcUaString>()->value() == "StringValue");
    BOOST_REQUIRE(myComplexDataValue.getValue("Field5")->getSPtr<OpcUaNodeId>()->namespaceIndex() == 1);
    OpcUaDateTime dt = myComplexDataValue.getValue("Field6")->get<OpcUaDateTime>();
    BOOST_REQUIRE(dt == OpcUaDateTime(now));

	myComplexDataValue.out(std::cout);
}

BOOST_AUTO_TEST_CASE(ComplexDataValue_encode_decode)
{
	boost::posix_time::ptime now = boost::posix_time::microsec_clock::universal_time();

	// create complex data type description
	ComplexDataTypeItem::Vec myComplexDataTypeVec;
	ComplexDataTypeItem::SPtr value;
	value = constructSPtr<ComplexDataTypeItem>("Field1", OpcUaBuildInType_OpcUaBoolean);
	myComplexDataTypeVec.push_back(value);
	value = constructSPtr<ComplexDataTypeItem>("Field2", OpcUaBuildInType_OpcUaDouble);
	myComplexDataTypeVec.push_back(value);
	value = constructSPtr<ComplexDataTypeItem>("Field3", OpcUaBuildInType_OpcUaInt32);
	myComplexDataTypeVec.push_back(value);
	value = constructSPtr<ComplexDataTypeItem>("Field4", OpcUaBuildInType_OpcUaString);
	myComplexDataTypeVec.push_back(value);
	value = constructSPtr<ComplexDataTypeItem>("Field5", OpcUaBuildInType_OpcUaNodeId);
	myComplexDataTypeVec.push_back(value);
	value = constructSPtr<ComplexDataTypeItem>("Field6", OpcUaBuildInType_OpcUaDateTime);
	myComplexDataTypeVec.push_back(value);

	// create complex data type
	ComplexDataType::SPtr myComplexDataType = constructSPtr<ComplexDataType>();
	myComplexDataType->name("MyComplexDataType");
	myComplexDataType->complexDataTypeItemVec(myComplexDataTypeVec);
	myComplexDataType->binaryTypeId(OpcUaNodeId("MyComplexType", 1));

	// create complex data type value
	ComplexDataValue myComplexDataValue1(myComplexDataType);
	ComplexDataValue myComplexDataValue2(myComplexDataType);

	// set values
	OpcUaVariant::SPtr variant;
	variant = myComplexDataValue1.getValue("Field1");
	variant->variant(OpcUaBoolean(true));
	variant = myComplexDataValue1.getValue("Field2");
    variant->variant(OpcUaDouble(1.2345));
    variant = myComplexDataValue1.getValue("Field3");
    variant->variant(OpcUaInt32(12345));

    OpcUaString::SPtr str = constructSPtr<OpcUaString>("StringValue");
    variant = myComplexDataValue1.getValue(3);
    variant->variant(str);
    OpcUaNodeId::SPtr nodeId = constructSPtr<OpcUaNodeId>(OpcUaNodeId("NodeId",1));
    variant = myComplexDataValue1.getValue(4);
    variant->variant(nodeId);
    variant = myComplexDataValue1.getValue(5);
    variant->variant(OpcUaDateTime(now));

    // encode and decode values
    std::stringstream ss;
    myComplexDataValue1.opcUaBinaryEncode(ss);
    myComplexDataValue2.opcUaBinaryDecode(ss);

    // check values
    BOOST_REQUIRE(myComplexDataValue2.getValue(0)->get<OpcUaBoolean>() == true);
    BOOST_REQUIRE(myComplexDataValue2.getValue(1)->get<OpcUaDouble>() == 1.2345);
    BOOST_REQUIRE(myComplexDataValue2.getValue(2)->get<OpcUaInt32>() == 12345);
    BOOST_REQUIRE(myComplexDataValue2.getValue("Field4")->getSPtr<OpcUaString>()->value() == "StringValue");
    BOOST_REQUIRE(myComplexDataValue2.getValue("Field5")->getSPtr<OpcUaNodeId>()->namespaceIndex() == 1);
    OpcUaDateTime dt = myComplexDataValue2.getValue("Field6")->get<OpcUaDateTime>();
    BOOST_REQUIRE(dt == OpcUaDateTime(now));

	myComplexDataValue2.out(std::cout);
}

BOOST_AUTO_TEST_CASE(ComplexDataValue_copyTo)
{
	boost::posix_time::ptime now = boost::posix_time::microsec_clock::universal_time();

	// create complex data type description
	ComplexDataTypeItem::Vec myComplexDataTypeVec;
	ComplexDataTypeItem::SPtr value;
	value = constructSPtr<ComplexDataTypeItem>("Field1", OpcUaBuildInType_OpcUaBoolean);
	myComplexDataTypeVec.push_back(value);
	value = constructSPtr<ComplexDataTypeItem>("Field2", OpcUaBuildInType_OpcUaDouble);
	myComplexDataTypeVec.push_back(value);
	value = constructSPtr<ComplexDataTypeItem>("Field3", OpcUaBuildInType_OpcUaInt32);
	myComplexDataTypeVec.push_back(value);
	value = constructSPtr<ComplexDataTypeItem>("Field4", OpcUaBuildInType_OpcUaString);
	myComplexDataTypeVec.push_back(value);
	value = constructSPtr<ComplexDataTypeItem>("Field5", OpcUaBuildInType_OpcUaNodeId);
	myComplexDataTypeVec.push_back(value);
	value = constructSPtr<ComplexDataTypeItem>("Field6", OpcUaBuildInType_OpcUaDateTime);
	myComplexDataTypeVec.push_back(value);

	// create complex data type
	ComplexDataType::SPtr myComplexDataType = constructSPtr<ComplexDataType>();
	myComplexDataType->name("MyComplexDataType");
	myComplexDataType->complexDataTypeItemVec(myComplexDataTypeVec);
	myComplexDataType->binaryTypeId(OpcUaNodeId("MyComplexType", 1));

	// create complex data type value
	ComplexDataValue myComplexDataValue1(myComplexDataType);
	ComplexDataValue myComplexDataValue2(myComplexDataType);

	// set values
	OpcUaVariant::SPtr variant;
	variant = myComplexDataValue1.getValue("Field1");
	variant->variant(OpcUaBoolean(true));
	variant = myComplexDataValue1.getValue("Field2");
    variant->variant(OpcUaDouble(1.2345));
    variant = myComplexDataValue1.getValue("Field3");
    variant->variant(OpcUaInt32(12345));

    OpcUaString::SPtr str = constructSPtr<OpcUaString>("StringValue");
    variant = myComplexDataValue1.getValue(3);
    variant->variant(str);
    OpcUaNodeId::SPtr nodeId = constructSPtr<OpcUaNodeId>(OpcUaNodeId("NodeId",1));
    variant = myComplexDataValue1.getValue(4);
    variant->variant(nodeId);
    variant = myComplexDataValue1.getValue(5);
    variant->variant(OpcUaDateTime(now));

    // copy operator
    myComplexDataValue1.copyTo(myComplexDataValue2);

    // check values
    BOOST_REQUIRE(myComplexDataValue2.getValue(0)->get<OpcUaBoolean>() == true);
    BOOST_REQUIRE(myComplexDataValue2.getValue(1)->get<OpcUaDouble>() == 1.2345);
    BOOST_REQUIRE(myComplexDataValue2.getValue(2)->get<OpcUaInt32>() == 12345);
    BOOST_REQUIRE(myComplexDataValue2.getValue("Field4")->getSPtr<OpcUaString>()->value() == "StringValue");
    BOOST_REQUIRE(myComplexDataValue2.getValue("Field5")->getSPtr<OpcUaNodeId>()->namespaceIndex() == 1);
    OpcUaDateTime dt = myComplexDataValue2.getValue("Field6")->get<OpcUaDateTime>();
    BOOST_REQUIRE(dt == OpcUaDateTime(now));

	myComplexDataValue2.out(std::cout);
}

BOOST_AUTO_TEST_CASE(ComplexDataValue_equal)
{
	boost::posix_time::ptime now = boost::posix_time::microsec_clock::universal_time();

	// create complex data type description
	ComplexDataTypeItem::Vec myComplexDataTypeVec;
	ComplexDataTypeItem::SPtr value;
	value = constructSPtr<ComplexDataTypeItem>("Field1", OpcUaBuildInType_OpcUaBoolean);
	myComplexDataTypeVec.push_back(value);
	value = constructSPtr<ComplexDataTypeItem>("Field2", OpcUaBuildInType_OpcUaDouble);
	myComplexDataTypeVec.push_back(value);
	value = constructSPtr<ComplexDataTypeItem>("Field3", OpcUaBuildInType_OpcUaInt32);
	myComplexDataTypeVec.push_back(value);
	value = constructSPtr<ComplexDataTypeItem>("Field4", OpcUaBuildInType_OpcUaString);
	myComplexDataTypeVec.push_back(value);
	value = constructSPtr<ComplexDataTypeItem>("Field5", OpcUaBuildInType_OpcUaNodeId);
	myComplexDataTypeVec.push_back(value);
	value = constructSPtr<ComplexDataTypeItem>("Field6", OpcUaBuildInType_OpcUaDateTime);
	myComplexDataTypeVec.push_back(value);

	// create complex data type
	ComplexDataType::SPtr myComplexDataType = constructSPtr<ComplexDataType>();
	myComplexDataType->name("MyComplexDataType");
	myComplexDataType->complexDataTypeItemVec(myComplexDataTypeVec);
	myComplexDataType->binaryTypeId(OpcUaNodeId("MyComplexType", 1));

	// create complex data type value
	ComplexDataValue myComplexDataValue1(myComplexDataType);
	ComplexDataValue myComplexDataValue2(myComplexDataType);

	// set values
	OpcUaVariant::SPtr variant;
	variant = myComplexDataValue1.getValue("Field1");
	variant->variant(OpcUaBoolean(true));
	variant = myComplexDataValue1.getValue("Field2");
    variant->variant(OpcUaDouble(1.2345));
    variant = myComplexDataValue1.getValue("Field3");
    variant->variant(OpcUaInt32(12345));

    OpcUaString::SPtr str = constructSPtr<OpcUaString>("StringValue");
    variant = myComplexDataValue1.getValue(3);
    variant->variant(str);
    OpcUaNodeId::SPtr nodeId = constructSPtr<OpcUaNodeId>(OpcUaNodeId("NodeId",1));
    variant = myComplexDataValue1.getValue(4);
    variant->variant(nodeId);
    variant = myComplexDataValue1.getValue(5);
    variant->variant(OpcUaDateTime(now));

    // copy operator
    myComplexDataValue1.copyTo(myComplexDataValue2);

    // check values
    BOOST_REQUIRE(myComplexDataValue1 == myComplexDataValue2);

    myComplexDataValue1.getValue("Field1")->variant(OpcUaBoolean(false));

    BOOST_REQUIRE(!(myComplexDataValue1 == myComplexDataValue2));

	myComplexDataValue2.out(std::cout);
}

BOOST_AUTO_TEST_SUITE_END()
