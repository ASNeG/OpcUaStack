#include "unittest.h"
#include "OpcUaStackCore/ComplexDataTypes/ComplexDataValue.h"

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(ComplexDataValue_t)


BOOST_AUTO_TEST_CASE(ComplexDataValue_ComplexDataTypeItem)
{
	ComplexDataTypeItem::Vec myComplexDataTypeVec;

	myComplexDataTypeVec.push_back(ComplexDataTypeItem("Field1", OpcUaBuildInType_OpcUaBoolean));
	myComplexDataTypeVec.push_back(ComplexDataTypeItem("Field2", OpcUaBuildInType_OpcUaDouble));
	myComplexDataTypeVec.push_back(ComplexDataTypeItem("Field3", OpcUaBuildInType_OpcUaInt32));
	myComplexDataTypeVec.push_back(ComplexDataTypeItem("Field4", OpcUaBuildInType_OpcUaString));
	myComplexDataTypeVec.push_back(ComplexDataTypeItem("Field5", OpcUaBuildInType_OpcUaDataValue));
	myComplexDataTypeVec.push_back(ComplexDataTypeItem("Field5", OpcUaBuildInType_OpcUaDateTime));

	BOOST_REQUIRE(myComplexDataTypeVec[3].itemName() == "Field4");
	BOOST_REQUIRE(myComplexDataTypeVec[3].itemType() == OpcUaBuildInType_OpcUaString);
}

BOOST_AUTO_TEST_CASE(ComplexDataValue_create_ComplexDataType)
{
	// create complex data type description
	ComplexDataTypeItem::Vec myComplexDataTypeVec;
	myComplexDataTypeVec.push_back(ComplexDataTypeItem("Field1", OpcUaBuildInType_OpcUaBoolean));
	myComplexDataTypeVec.push_back(ComplexDataTypeItem("Field2", OpcUaBuildInType_OpcUaDouble));
	myComplexDataTypeVec.push_back(ComplexDataTypeItem("Field3", OpcUaBuildInType_OpcUaInt32));
	myComplexDataTypeVec.push_back(ComplexDataTypeItem("Field4", OpcUaBuildInType_OpcUaString));
	myComplexDataTypeVec.push_back(ComplexDataTypeItem("Field5", OpcUaBuildInType_OpcUaDataValue));
	myComplexDataTypeVec.push_back(ComplexDataTypeItem("Field6", OpcUaBuildInType_OpcUaDateTime));

	// create complex data type
	ComplexDataType::SPtr myComplexDataType = constructSPtr<ComplexDataType>();
	myComplexDataType->name("MyComplexDataType");
	myComplexDataType->complexDataTypeItemVec(myComplexDataTypeVec);

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
	myComplexDataTypeVec.push_back(ComplexDataTypeItem("Field1", OpcUaBuildInType_OpcUaBoolean));
	myComplexDataTypeVec.push_back(ComplexDataTypeItem("Field2", OpcUaBuildInType_OpcUaDouble));
	myComplexDataTypeVec.push_back(ComplexDataTypeItem("Field3", OpcUaBuildInType_OpcUaInt32));
	myComplexDataTypeVec.push_back(ComplexDataTypeItem("Field4", OpcUaBuildInType_OpcUaString));
	myComplexDataTypeVec.push_back(ComplexDataTypeItem("Field5", OpcUaBuildInType_OpcUaDataValue));
	myComplexDataTypeVec.push_back(ComplexDataTypeItem("Field6", OpcUaBuildInType_OpcUaDateTime));

	// create complex data type
	ComplexDataType::SPtr myComplexDataType = constructSPtr<ComplexDataType>();
	myComplexDataType->name("MyComplexDataType");
	myComplexDataType->complexDataTypeItemVec(myComplexDataTypeVec);

	// create complex data type value
	ComplexDataValue myComplexDataValue(myComplexDataType);
	//BOOST_REQUIRE(myComplexDataValue.index2Name(0) == "Field1");

	//BOOST_REQUIRE(myComplexDataType->size() == 6);

	BOOST_REQUIRE(myComplexDataValue.index2Name(0) == "Field1");
	BOOST_REQUIRE(myComplexDataValue.index2Name(1) == "Field2");
	BOOST_REQUIRE(myComplexDataValue.index2Name(5) == "Field6");
	BOOST_REQUIRE(myComplexDataValue.index2Name(5555) == "");

	BOOST_REQUIRE(myComplexDataValue.name2Index("Field1") == 0);
	BOOST_REQUIRE(myComplexDataValue.name2Index("Field2") == 1);
	BOOST_REQUIRE(myComplexDataValue.name2Index("Field6") == 5);
	BOOST_REQUIRE(myComplexDataValue.name2Index("Unknown") == -1);
}

#if 0
//- ExtensionObjectBase -----------------------------------------------
virtual ExtensionObjectBase::SPtr factory(void);
virtual OpcUaNodeId binaryTypeId(void);
virtual OpcUaNodeId xmlTypeId(void);
virtual void opcUaBinaryEncode(std::ostream& os) const;
virtual void opcUaBinaryDecode(std::istream& is);
virtual bool encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const;
virtual bool decode(boost::property_tree::ptree& pt, Xmlns& xmlns);
virtual void copyTo(ExtensionObjectBase& extensionObjectBase);
virtual bool equal(ExtensionObjectBase& extensionObjectBase) const;
virtual void out(std::ostream& os);
//- ExtensionObjectBase -----------------------------------------------

void copyTo(ComplexDataValue& complexDataValue);
bool operator==(const ComplexDataValue& complexDataValue) const;
void complexDataType(ComplexDataType::SPtr& complexDataType);
int32_t name2Index(const std::string& name);
std::string index2Name(uint32_t index);
OpcUaVariant::SPtr& getValue(const std::string& itemName);
OpcUaVariant::SPtr& getValue(uint32_t itemIndex);
#endif


BOOST_AUTO_TEST_SUITE_END()
