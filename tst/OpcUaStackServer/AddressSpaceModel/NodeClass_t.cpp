#include "unittest.h"
#include "OpcUaStackServer/AddressSpaceModel/VariableNodeClass.h"
#include "OpcUaStackServer/AddressSpaceModel/VariableTypeNodeClass.h"
#include "OpcUaStackServer/AddressSpaceModel/ReferenceTypeNodeClass.h"
#include "OpcUaStackServer/AddressSpaceModel/ViewNodeClass.h"
#include "OpcUaStackServer/AddressSpaceModel/MethodNodeClass.h"

using namespace OpcUaStackCore;
using namespace OpcUaStackServer;

BOOST_AUTO_TEST_SUITE(NodeClass_)

BOOST_AUTO_TEST_CASE(NodeClass_)
{
	std::cout << "NodeClass_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(NodeClass_NodeId)
{
	VariableNodeClass::SPtr variableNodeClass = constructSPtr<VariableNodeClass>();
	OpcUaNodeId nodeId1;
	OpcUaNodeId nodeId2;
	boost::optional<OpcUaNodeId&> nodeId3;

	BOOST_REQUIRE(variableNodeClass->isPartNodeId() == true);
	BOOST_REQUIRE(variableNodeClass->isNullNodeId() == true);
	BOOST_REQUIRE(variableNodeClass->getNodeId(nodeId1) == false);
	nodeId3 = variableNodeClass->getNodeId();
	BOOST_REQUIRE(!nodeId3 == true);

	nodeId1.namespaceIndex(1);
	nodeId1.nodeId(1234);
	BOOST_REQUIRE(variableNodeClass->setNodeId(nodeId1) == true);
	BOOST_REQUIRE(variableNodeClass->isNullNodeId() == false);
	BOOST_REQUIRE(variableNodeClass->getNodeId(nodeId2) == true);
	BOOST_REQUIRE(nodeId1 == nodeId2);
	nodeId3 = variableNodeClass->getNodeId();
	BOOST_REQUIRE(!nodeId3 == false);
	BOOST_REQUIRE(nodeId1 == *nodeId3);

	BOOST_REQUIRE(variableNodeClass->unsetNodeId() == true);
	BOOST_REQUIRE(variableNodeClass->isPartNodeId() == true);
	BOOST_REQUIRE(variableNodeClass->isNullNodeId() == true);
	BOOST_REQUIRE(variableNodeClass->getNodeId(nodeId1) == false);
	nodeId3 = variableNodeClass->getNodeId();
	BOOST_REQUIRE(!nodeId3 == true);
};

BOOST_AUTO_TEST_CASE(NodeClass_NodeClass)
{
	VariableNodeClass::SPtr variableNodeClass = constructSPtr<VariableNodeClass>();
	NodeClass::Enum nodeClass1;
	NodeClass::Enum nodeClass2;
	boost::optional<NodeClass::Enum&> nodeClass3;

	BOOST_REQUIRE(variableNodeClass->unsetNodeClass() == true);
	BOOST_REQUIRE(variableNodeClass->isPartNodeClass() == true);
	BOOST_REQUIRE(variableNodeClass->isNullNodeClass() == true);
	BOOST_REQUIRE(variableNodeClass->getNodeClass(nodeClass1) == false);
	nodeClass3 = variableNodeClass->getNodeClass();
	BOOST_REQUIRE(!nodeClass3 == true);

	nodeClass1 = NodeClass::EnumObject;
	BOOST_REQUIRE(variableNodeClass->setNodeClass(nodeClass1) == true);
	BOOST_REQUIRE(variableNodeClass->isNullNodeClass() == false);
	BOOST_REQUIRE(variableNodeClass->getNodeClass(nodeClass2) == true);
	BOOST_REQUIRE(nodeClass1 == nodeClass2);
	nodeClass3 = variableNodeClass->getNodeClass();
	BOOST_REQUIRE(!nodeClass3 == false);
	BOOST_REQUIRE(nodeClass1 == *nodeClass3);

	BOOST_REQUIRE(variableNodeClass->unsetNodeClass() == true);
	BOOST_REQUIRE(variableNodeClass->isPartNodeClass() == true);
	BOOST_REQUIRE(variableNodeClass->isNullNodeClass() == true);
	BOOST_REQUIRE(variableNodeClass->getNodeClass(nodeClass1) == false);
	nodeClass3 = variableNodeClass->getNodeClass();
	BOOST_REQUIRE(!nodeClass3 == true);
};

BOOST_AUTO_TEST_CASE(NodeClass_BrowseName)
{
	VariableNodeClass::SPtr variableNodeClass = constructSPtr<VariableNodeClass>();
	OpcUaQualifiedName browseName1;
	OpcUaQualifiedName browseName2;
	boost::optional<OpcUaQualifiedName&> browseName3;

	BOOST_REQUIRE(variableNodeClass->isPartBrowseName() == true);
	BOOST_REQUIRE(variableNodeClass->isNullBrowseName() == true);
	BOOST_REQUIRE(variableNodeClass->getBrowseName(browseName1) == false);
	browseName3 = variableNodeClass->getBrowseName();
	BOOST_REQUIRE(!browseName3 == true);

	browseName1.namespaceIndex(1);
	browseName1.name("BrowseName");
	BOOST_REQUIRE(variableNodeClass->setBrowseName(browseName1) == true);
	BOOST_REQUIRE(variableNodeClass->isNullBrowseName() == false);
	BOOST_REQUIRE(variableNodeClass->getBrowseName(browseName2) == true);
	BOOST_REQUIRE(browseName1 == browseName2);
	browseName3 = variableNodeClass->getBrowseName();
	BOOST_REQUIRE(!browseName3 == false);
	BOOST_REQUIRE(browseName1 == *browseName3);

	BOOST_REQUIRE(variableNodeClass->unsetBrowseName() == true);
	BOOST_REQUIRE(variableNodeClass->isPartBrowseName() == true);
	BOOST_REQUIRE(variableNodeClass->isNullBrowseName() == true);
	BOOST_REQUIRE(variableNodeClass->getBrowseName(browseName1) == false);
	browseName3 = variableNodeClass->getBrowseName();
	BOOST_REQUIRE(!browseName3 == true);
};

BOOST_AUTO_TEST_CASE(NodeClass_DisplayName)
{
	VariableNodeClass::SPtr variableNodeClass = constructSPtr<VariableNodeClass>();
	OpcUaLocalizedText displayName1;
	OpcUaLocalizedText displayName2;
	boost::optional<OpcUaLocalizedText&> displayName3;

	BOOST_REQUIRE(variableNodeClass->isPartDisplayName() == true);
	BOOST_REQUIRE(variableNodeClass->isNullDisplayName() == true);
	BOOST_REQUIRE(variableNodeClass->getDisplayName(displayName1) == false);
	displayName3 = variableNodeClass->getDisplayName();
	BOOST_REQUIRE(!displayName3 == true);

	displayName1.locale("de");
	displayName1.text("DisplayName");
	BOOST_REQUIRE(variableNodeClass->setDisplayName(displayName1) == true);
	BOOST_REQUIRE(variableNodeClass->isNullDisplayName() == false);
	BOOST_REQUIRE(variableNodeClass->getDisplayName(displayName2) == true);
	BOOST_REQUIRE(displayName1 == displayName2);
	displayName3 = variableNodeClass->getDisplayName();
	BOOST_REQUIRE(!displayName3 == false);
	BOOST_REQUIRE(displayName1 == *displayName3);

	BOOST_REQUIRE(variableNodeClass->unsetDisplayName() == true);
	BOOST_REQUIRE(variableNodeClass->isPartDisplayName() == true);
	BOOST_REQUIRE(variableNodeClass->isNullDisplayName() == true);
	BOOST_REQUIRE(variableNodeClass->getDisplayName(displayName1) == false);
	displayName3 = variableNodeClass->getDisplayName();
	BOOST_REQUIRE(!displayName3 == true);
};

BOOST_AUTO_TEST_CASE(NodeClass_Description)
{
	VariableNodeClass::SPtr variableNodeClass = constructSPtr<VariableNodeClass>();
	OpcUaLocalizedText description1;
	OpcUaLocalizedText description2;
	boost::optional<OpcUaLocalizedText&> description3;

	BOOST_REQUIRE(variableNodeClass->isPartDescription() == true);
	BOOST_REQUIRE(variableNodeClass->isNullDescription() == true);
	BOOST_REQUIRE(variableNodeClass->getDescription(description1) == false);
	description3 = variableNodeClass->getDescription();
	BOOST_REQUIRE(!description3 == true);

	description1.locale("de");
	description1.text("Description");
	BOOST_REQUIRE(variableNodeClass->setDescription(description1) == true);
	BOOST_REQUIRE(variableNodeClass->isNullDescription() == false);
	BOOST_REQUIRE(variableNodeClass->getDescription(description2) == true);
	BOOST_REQUIRE(description1 == description2);
	description3 = variableNodeClass->getDescription();
	BOOST_REQUIRE(!description3 == false);
	BOOST_REQUIRE(description1 == *description3);

	BOOST_REQUIRE(variableNodeClass->unsetDescription() == true);
	BOOST_REQUIRE(variableNodeClass->isPartDescription() == true);
	BOOST_REQUIRE(variableNodeClass->isNullDescription() == true);
	BOOST_REQUIRE(variableNodeClass->getDescription(description1) == false);
	description3 = variableNodeClass->getDescription();
	BOOST_REQUIRE(!description3 == true);
};

BOOST_AUTO_TEST_CASE(NodeClass_WriteMask)
{
	VariableNodeClass::SPtr variableNodeClass = constructSPtr<VariableNodeClass>();
	OpcUaUInt32 writeMask1;
	OpcUaUInt32 writeMask2;
	boost::optional<OpcUaUInt32&> writeMask3;

	BOOST_REQUIRE(variableNodeClass->isPartWriteMask() == true);
	BOOST_REQUIRE(variableNodeClass->isNullWriteMask() == true);
	BOOST_REQUIRE(variableNodeClass->getWriteMask(writeMask1) == false);
	writeMask3 = variableNodeClass->getWriteMask();
	BOOST_REQUIRE(!writeMask3 == true);

	writeMask1 = 4711;
	BOOST_REQUIRE(variableNodeClass->setWriteMask(writeMask1) == true);
	BOOST_REQUIRE(variableNodeClass->isNullWriteMask() == false);
	BOOST_REQUIRE(variableNodeClass->getWriteMask(writeMask2) == true);
	BOOST_REQUIRE(writeMask1 == writeMask2);
	writeMask3 = variableNodeClass->getWriteMask();
	BOOST_REQUIRE(!writeMask3 == false);
	BOOST_REQUIRE(writeMask1 == *writeMask3);

	BOOST_REQUIRE(variableNodeClass->unsetWriteMask() == true);
	BOOST_REQUIRE(variableNodeClass->isPartWriteMask() == true);
	BOOST_REQUIRE(variableNodeClass->isNullWriteMask() == true);
	BOOST_REQUIRE(variableNodeClass->getWriteMask(writeMask1) == false);
	writeMask3 = variableNodeClass->getWriteMask();
	BOOST_REQUIRE(!writeMask3 == true);
};

BOOST_AUTO_TEST_CASE(NodeClass_UserWriteMask)
{
	VariableNodeClass::SPtr variableNodeClass = constructSPtr<VariableNodeClass>();
	OpcUaUInt32 userWriteMask1;
	OpcUaUInt32 userWriteMask2;
	boost::optional<OpcUaUInt32&> userWriteMask3;

	BOOST_REQUIRE(variableNodeClass->isPartUserWriteMask() == true);
	BOOST_REQUIRE(variableNodeClass->isNullUserWriteMask() == true);
	BOOST_REQUIRE(variableNodeClass->getUserWriteMask(userWriteMask1) == false);
	userWriteMask3 = variableNodeClass->getUserWriteMask();
	BOOST_REQUIRE(!userWriteMask3 == true);

	userWriteMask1 = 4711;
	BOOST_REQUIRE(variableNodeClass->setUserWriteMask(userWriteMask1) == true);
	BOOST_REQUIRE(variableNodeClass->isNullUserWriteMask() == false);
	BOOST_REQUIRE(variableNodeClass->getUserWriteMask(userWriteMask2) == true);
	BOOST_REQUIRE(userWriteMask1 == userWriteMask2);
	userWriteMask3 = variableNodeClass->getUserWriteMask();
	BOOST_REQUIRE(!userWriteMask3 == false);
	BOOST_REQUIRE(userWriteMask1 == *userWriteMask3);

	BOOST_REQUIRE(variableNodeClass->unsetUserWriteMask() == true);
	BOOST_REQUIRE(variableNodeClass->isPartUserWriteMask() == true);
	BOOST_REQUIRE(variableNodeClass->isNullUserWriteMask() == true);
	BOOST_REQUIRE(variableNodeClass->getUserWriteMask(userWriteMask1) == false);
	userWriteMask3 = variableNodeClass->getUserWriteMask();
	BOOST_REQUIRE(!userWriteMask3 == true);
};

BOOST_AUTO_TEST_CASE(NodeClass_IsAbstract)
{
	VariableTypeNodeClass::SPtr variableNodeClass = constructSPtr<VariableTypeNodeClass>();
	OpcUaBoolean isAbstract1;
	OpcUaBoolean isAbstract2;
	boost::optional<OpcUaBoolean&> isAbstract3;

	BOOST_REQUIRE(variableNodeClass->isPartIsAbstract() == true);
	BOOST_REQUIRE(variableNodeClass->isNullIsAbstract() == true);
	BOOST_REQUIRE(variableNodeClass->getIsAbstract(isAbstract1) == false);
	isAbstract3 = variableNodeClass->getIsAbstract();
	BOOST_REQUIRE(!isAbstract3 == true);

	isAbstract1 = 4711;
	BOOST_REQUIRE(variableNodeClass->setIsAbstract(isAbstract1) == true);
	BOOST_REQUIRE(variableNodeClass->isNullIsAbstract() == false);
	BOOST_REQUIRE(variableNodeClass->getIsAbstract(isAbstract2) == true);
	BOOST_REQUIRE(isAbstract1 == isAbstract2);
	isAbstract3 = variableNodeClass->getIsAbstract();
	BOOST_REQUIRE(!isAbstract3 == false);
	BOOST_REQUIRE(isAbstract1 == *isAbstract3);

	BOOST_REQUIRE(variableNodeClass->unsetIsAbstract() == true);
	BOOST_REQUIRE(variableNodeClass->isPartIsAbstract() == true);
	BOOST_REQUIRE(variableNodeClass->isNullIsAbstract() == true);
	BOOST_REQUIRE(variableNodeClass->getIsAbstract(isAbstract1) == false);
	isAbstract3 = variableNodeClass->getIsAbstract();
	BOOST_REQUIRE(!isAbstract3 == true);
};

BOOST_AUTO_TEST_CASE(NodeClass_Symmetric)
{
	ReferenceTypeNodeClass::SPtr referenceTypeNodeClass = constructSPtr<ReferenceTypeNodeClass>();
	OpcUaBoolean symmetric1;
	OpcUaBoolean symmetric2;
	boost::optional<OpcUaBoolean&> symmetric3;

	BOOST_REQUIRE(referenceTypeNodeClass->isPartSymmetric() == true);
	BOOST_REQUIRE(referenceTypeNodeClass->isNullSymmetric() == true);
	BOOST_REQUIRE(referenceTypeNodeClass->getSymmetric(symmetric1) == false);
	symmetric3 = referenceTypeNodeClass->getSymmetric();
	BOOST_REQUIRE(!symmetric3 == true);

	symmetric1 = 4711;
	BOOST_REQUIRE(referenceTypeNodeClass->setSymmetric(symmetric1) == true);
	BOOST_REQUIRE(referenceTypeNodeClass->isNullSymmetric() == false);
	BOOST_REQUIRE(referenceTypeNodeClass->getSymmetric(symmetric2) == true);
	BOOST_REQUIRE(symmetric1 == symmetric2);
	symmetric3 = referenceTypeNodeClass->getSymmetric();
	BOOST_REQUIRE(!symmetric3 == false);
	BOOST_REQUIRE(symmetric1 == *symmetric3);

	BOOST_REQUIRE(referenceTypeNodeClass->unsetSymmetric() == true);
	BOOST_REQUIRE(referenceTypeNodeClass->isPartSymmetric() == true);
	BOOST_REQUIRE(referenceTypeNodeClass->isNullSymmetric() == true);
	BOOST_REQUIRE(referenceTypeNodeClass->getSymmetric(symmetric1) == false);
	symmetric3 = referenceTypeNodeClass->getSymmetric();
	BOOST_REQUIRE(!symmetric3 == true);
};

BOOST_AUTO_TEST_CASE(NodeClass_InverseName)
{
	ReferenceTypeNodeClass::SPtr referenceTypeNodeClass = constructSPtr<ReferenceTypeNodeClass>();
	OpcUaLocalizedText inverseName1;
	OpcUaLocalizedText inverseName2;
	boost::optional<OpcUaLocalizedText&> inverseName3;

	BOOST_REQUIRE(referenceTypeNodeClass->isPartInverseName() == true);
	BOOST_REQUIRE(referenceTypeNodeClass->isNullInverseName() == true);
	BOOST_REQUIRE(referenceTypeNodeClass->getInverseName(inverseName1) == false);
	inverseName3 = referenceTypeNodeClass->getInverseName();
	BOOST_REQUIRE(!inverseName3 == true);

	inverseName1.locale("de");
	inverseName1.text("InverseName");
	BOOST_REQUIRE(referenceTypeNodeClass->setInverseName(inverseName1) == true);
	BOOST_REQUIRE(referenceTypeNodeClass->isNullInverseName() == false);
	BOOST_REQUIRE(referenceTypeNodeClass->getInverseName(inverseName2) == true);
	BOOST_REQUIRE(inverseName1 == inverseName2);
	inverseName3 = referenceTypeNodeClass->getInverseName();
	BOOST_REQUIRE(!inverseName3 == false);
	BOOST_REQUIRE(inverseName1 == *inverseName3);

	BOOST_REQUIRE(referenceTypeNodeClass->unsetInverseName() == true);
	BOOST_REQUIRE(referenceTypeNodeClass->isPartInverseName() == true);
	BOOST_REQUIRE(referenceTypeNodeClass->isNullInverseName() == true);
	BOOST_REQUIRE(referenceTypeNodeClass->getInverseName(inverseName1) == false);
	inverseName3 = referenceTypeNodeClass->getInverseName();
	BOOST_REQUIRE(!inverseName3 == true);
};

BOOST_AUTO_TEST_CASE(NodeClass_ContainsNoLoops)
{
	ViewNodeClass::SPtr viewNodeClass = constructSPtr<ViewNodeClass>();
	OpcUaBoolean containsNoLoops1;
	OpcUaBoolean containsNoLoops2;
	boost::optional<OpcUaBoolean&> containsNoLoops3;

	BOOST_REQUIRE(viewNodeClass->isPartContainsNoLoops() == true);
	BOOST_REQUIRE(viewNodeClass->isNullContainsNoLoops() == true);
	BOOST_REQUIRE(viewNodeClass->getContainsNoLoops(containsNoLoops1) == false);
	containsNoLoops3 = viewNodeClass->getContainsNoLoops();
	BOOST_REQUIRE(!containsNoLoops3 == true);

	containsNoLoops1 = true;
	BOOST_REQUIRE(viewNodeClass->setContainsNoLoops(containsNoLoops1) == true);
	BOOST_REQUIRE(viewNodeClass->isNullContainsNoLoops() == false);
	BOOST_REQUIRE(viewNodeClass->getContainsNoLoops(containsNoLoops2) == true);
	BOOST_REQUIRE(containsNoLoops1 == containsNoLoops2);
	containsNoLoops3 = viewNodeClass->getContainsNoLoops();
	BOOST_REQUIRE(!containsNoLoops3 == false);
	BOOST_REQUIRE(containsNoLoops1 == *containsNoLoops3);

	BOOST_REQUIRE(viewNodeClass->unsetContainsNoLoops() == true);
	BOOST_REQUIRE(viewNodeClass->isPartContainsNoLoops() == true);
	BOOST_REQUIRE(viewNodeClass->isNullContainsNoLoops() == true);
	BOOST_REQUIRE(viewNodeClass->getContainsNoLoops(containsNoLoops1) == false);
	containsNoLoops3 = viewNodeClass->getContainsNoLoops();
	BOOST_REQUIRE(!containsNoLoops3 == true);
};

BOOST_AUTO_TEST_CASE(NodeClass_EventNotifier)
{
	ViewNodeClass::SPtr viewNodeClass = constructSPtr<ViewNodeClass>();
	OpcUaByte eventNotifier1;
	OpcUaByte eventNotifier2;
	boost::optional<OpcUaByte&> eventNotifier3;

	BOOST_REQUIRE(viewNodeClass->isPartEventNotifier() == true);
	BOOST_REQUIRE(viewNodeClass->isNullEventNotifier() == true);
	BOOST_REQUIRE(viewNodeClass->getEventNotifier(eventNotifier1) == false);
	eventNotifier3 = viewNodeClass->getEventNotifier();
	BOOST_REQUIRE(!eventNotifier3 == true);

	eventNotifier1 = 0x03;
	BOOST_REQUIRE(viewNodeClass->setEventNotifier(eventNotifier1) == true);
	BOOST_REQUIRE(viewNodeClass->isNullEventNotifier() == false);
	BOOST_REQUIRE(viewNodeClass->getEventNotifier(eventNotifier2) == true);
	BOOST_REQUIRE(eventNotifier1 == eventNotifier2);
	eventNotifier3 = viewNodeClass->getEventNotifier();
	BOOST_REQUIRE(!eventNotifier3 == false);
	BOOST_REQUIRE(eventNotifier1 == *eventNotifier3);

	BOOST_REQUIRE(viewNodeClass->unsetEventNotifier() == true);
	BOOST_REQUIRE(viewNodeClass->isPartEventNotifier() == true);
	BOOST_REQUIRE(viewNodeClass->isNullEventNotifier() == true);
	BOOST_REQUIRE(viewNodeClass->getEventNotifier(eventNotifier1) == false);
	eventNotifier3 = viewNodeClass->getEventNotifier();
	BOOST_REQUIRE(!eventNotifier3 == true);
};

BOOST_AUTO_TEST_CASE(NodeClass_Value)
{
	VariableNodeClass::SPtr variableNodeClass = constructSPtr<VariableNodeClass>();
	OpcUaDataValue value1;
	OpcUaDataValue value2;
	boost::optional<OpcUaDataValue&> value3;

	BOOST_REQUIRE(variableNodeClass->isPartValue() == true);
	BOOST_REQUIRE(variableNodeClass->isNullValue() == true);
	BOOST_REQUIRE(variableNodeClass->getValue(value1) == false);
	value3 = variableNodeClass->getValue();
	BOOST_REQUIRE(!value3 == true);

	value1.variant()->variant((OpcUaDouble)12.34);
	BOOST_REQUIRE(variableNodeClass->setValue(value1) == true);
	BOOST_REQUIRE(variableNodeClass->isNullValue() == false);
	BOOST_REQUIRE(variableNodeClass->getValue(value2) == true);
	BOOST_REQUIRE(*value1.variant() == *value2.variant());
	value3 = variableNodeClass->getValue();
	BOOST_REQUIRE(!value3 == false);
	BOOST_REQUIRE(*value1.variant() == *(*value3).variant());

	BOOST_REQUIRE(variableNodeClass->unsetValue() == true);
	BOOST_REQUIRE(variableNodeClass->isPartValue() == true);
	BOOST_REQUIRE(variableNodeClass->isNullValue() == true);
	BOOST_REQUIRE(variableNodeClass->getValue(value1) == false);
	value3 = variableNodeClass->getValue();
	BOOST_REQUIRE(!value3 == true);
};

BOOST_AUTO_TEST_CASE(NodeClass_DataType)
{
	VariableNodeClass::SPtr variableNodeClass = constructSPtr<VariableNodeClass>();
	OpcUaNodeId dataType1;
	OpcUaNodeId dataType2;
	boost::optional<OpcUaNodeId&> dataType3;

	BOOST_REQUIRE(variableNodeClass->isPartDataType() == true);
	BOOST_REQUIRE(variableNodeClass->isNullDataType() == true);
	BOOST_REQUIRE(variableNodeClass->getDataType(dataType1) == false);
	dataType3 = variableNodeClass->getDataType();
	BOOST_REQUIRE(!dataType3 == true);

	dataType1.namespaceIndex(123);
	dataType1.nodeId((OpcUaUInt32)123);
	BOOST_REQUIRE(variableNodeClass->setDataType(dataType1) == true);
	BOOST_REQUIRE(variableNodeClass->isNullDataType() == false);
	BOOST_REQUIRE(variableNodeClass->getDataType(dataType2) == true);
	BOOST_REQUIRE(dataType1 == dataType2);
	dataType3 = variableNodeClass->getDataType();
	BOOST_REQUIRE(!dataType3 == false);
	BOOST_REQUIRE(dataType1== *dataType3);

	BOOST_REQUIRE(variableNodeClass->unsetDataType() == true);
	BOOST_REQUIRE(variableNodeClass->isPartDataType() == true);
	BOOST_REQUIRE(variableNodeClass->isNullDataType() == true);
	BOOST_REQUIRE(variableNodeClass->getDataType(dataType1) == false);
	dataType3 = variableNodeClass->getDataType();
	BOOST_REQUIRE(!dataType3 == true);
};

BOOST_AUTO_TEST_CASE(NodeClass_ValueRank)
{
	VariableNodeClass::SPtr variableNodeClass = constructSPtr<VariableNodeClass>();
	OpcUaInt32 valueRank1;
	OpcUaInt32 valueRank2;
	boost::optional<OpcUaInt32&> valueRank3;

	BOOST_REQUIRE(variableNodeClass->isPartValueRank() == true);
	BOOST_REQUIRE(variableNodeClass->isNullValueRank() == true);
	BOOST_REQUIRE(variableNodeClass->getValueRank(valueRank1) == false);
	valueRank3 = variableNodeClass->getValueRank();
	BOOST_REQUIRE(!valueRank3 == true);

	valueRank1 = 123;
	BOOST_REQUIRE(variableNodeClass->setValueRank(valueRank1) == true);
	BOOST_REQUIRE(variableNodeClass->isNullValueRank() == false);
	BOOST_REQUIRE(variableNodeClass->getValueRank(valueRank2) == true);
	BOOST_REQUIRE(valueRank1 == valueRank2);
	valueRank3 = variableNodeClass->getValueRank();
	BOOST_REQUIRE(!valueRank3 == false);
	BOOST_REQUIRE(valueRank1== *valueRank3);

	BOOST_REQUIRE(variableNodeClass->unsetValueRank() == true);
	BOOST_REQUIRE(variableNodeClass->isPartValueRank() == true);
	BOOST_REQUIRE(variableNodeClass->isNullValueRank() == true);
	BOOST_REQUIRE(variableNodeClass->getValueRank(valueRank1) == false);
	valueRank3 = variableNodeClass->getValueRank();
	BOOST_REQUIRE(!valueRank3 == true);
};

BOOST_AUTO_TEST_CASE(NodeClass_ArrayDimensions)
{
	VariableNodeClass::SPtr variableNodeClass = constructSPtr<VariableNodeClass>();
	OpcUaUInt32Array arrayDimensions1;
	OpcUaUInt32Array arrayDimensions2;
	boost::optional<OpcUaUInt32Array&> arrayDimensions3;

	BOOST_REQUIRE(variableNodeClass->isPartArrayDimensions() == true);
	BOOST_REQUIRE(variableNodeClass->isNullArrayDimensions() == true);
	BOOST_REQUIRE(variableNodeClass->getArrayDimensions(arrayDimensions1) == false);
	arrayDimensions3 = variableNodeClass->getArrayDimensions();
	BOOST_REQUIRE(!arrayDimensions3 == true);

	arrayDimensions1.push_back(12);
	arrayDimensions1.push_back(34);
	BOOST_REQUIRE(variableNodeClass->setArrayDimensions(arrayDimensions1) == true);
	BOOST_REQUIRE(variableNodeClass->isNullArrayDimensions() == false);
	BOOST_REQUIRE(variableNodeClass->getArrayDimensions(arrayDimensions2) == true);
	BOOST_REQUIRE(arrayDimensions1 == arrayDimensions2);
	arrayDimensions3 = variableNodeClass->getArrayDimensions();
	BOOST_REQUIRE(!arrayDimensions3 == false);
	BOOST_REQUIRE(arrayDimensions1== *arrayDimensions3);

	BOOST_REQUIRE(variableNodeClass->unsetArrayDimensions() == true);
	BOOST_REQUIRE(variableNodeClass->isPartArrayDimensions() == true);
	BOOST_REQUIRE(variableNodeClass->isNullArrayDimensions() == true);
	BOOST_REQUIRE(variableNodeClass->getArrayDimensions(arrayDimensions1) == false);
	arrayDimensions3 = variableNodeClass->getArrayDimensions();
	BOOST_REQUIRE(!arrayDimensions3 == true);
};

BOOST_AUTO_TEST_CASE(NodeClass_AccessLevel)
{
	VariableNodeClass::SPtr variableNodeClass = constructSPtr<VariableNodeClass>();
	OpcUaByte accessLevel1;
	OpcUaByte accessLevel2;
	boost::optional<OpcUaByte&> accessLevel3;

	BOOST_REQUIRE(variableNodeClass->isPartAccessLevel() == true);
	BOOST_REQUIRE(variableNodeClass->isNullAccessLevel() == true);
	BOOST_REQUIRE(variableNodeClass->getAccessLevel(accessLevel1) == false);
	accessLevel3 = variableNodeClass->getAccessLevel();
	BOOST_REQUIRE(!accessLevel3 == true);

	accessLevel1 = 12;
	BOOST_REQUIRE(variableNodeClass->setAccessLevel(accessLevel1) == true);
	BOOST_REQUIRE(variableNodeClass->isNullAccessLevel() == false);
	BOOST_REQUIRE(variableNodeClass->getAccessLevel(accessLevel2) == true);
	BOOST_REQUIRE(accessLevel1 == accessLevel2);
	accessLevel3 = variableNodeClass->getAccessLevel();
	BOOST_REQUIRE(!accessLevel3 == false);
	BOOST_REQUIRE(accessLevel1== *accessLevel3);

	BOOST_REQUIRE(variableNodeClass->unsetAccessLevel() == true);
	BOOST_REQUIRE(variableNodeClass->isPartAccessLevel() == true);
	BOOST_REQUIRE(variableNodeClass->isNullAccessLevel() == true);
	BOOST_REQUIRE(variableNodeClass->getAccessLevel(accessLevel1) == false);
	accessLevel3 = variableNodeClass->getAccessLevel();
	BOOST_REQUIRE(!accessLevel3 == true);
};

BOOST_AUTO_TEST_CASE(NodeClass_UserAccessLevel)
{
	VariableNodeClass::SPtr variableNodeClass = constructSPtr<VariableNodeClass>();
	OpcUaByte userAccessLevel1;
	OpcUaByte userAccessLevel2;
	boost::optional<OpcUaByte&> userAccessLevel3;

	BOOST_REQUIRE(variableNodeClass->isPartUserAccessLevel() == true);
	BOOST_REQUIRE(variableNodeClass->isNullUserAccessLevel() == true);
	BOOST_REQUIRE(variableNodeClass->getUserAccessLevel(userAccessLevel1) == false);
	userAccessLevel3 = variableNodeClass->getUserAccessLevel();
	BOOST_REQUIRE(!userAccessLevel3 == true);

	userAccessLevel1 = 12;
	BOOST_REQUIRE(variableNodeClass->setUserAccessLevel(userAccessLevel1) == true);
	BOOST_REQUIRE(variableNodeClass->isNullUserAccessLevel() == false);
	BOOST_REQUIRE(variableNodeClass->getUserAccessLevel(userAccessLevel2) == true);
	BOOST_REQUIRE(userAccessLevel1 == userAccessLevel2);
	userAccessLevel3 = variableNodeClass->getUserAccessLevel();
	BOOST_REQUIRE(!userAccessLevel3 == false);
	BOOST_REQUIRE(userAccessLevel1== *userAccessLevel3);

	BOOST_REQUIRE(variableNodeClass->unsetUserAccessLevel() == true);
	BOOST_REQUIRE(variableNodeClass->isPartUserAccessLevel() == true);
	BOOST_REQUIRE(variableNodeClass->isNullUserAccessLevel() == true);
	BOOST_REQUIRE(variableNodeClass->getUserAccessLevel(userAccessLevel1) == false);
	userAccessLevel3 = variableNodeClass->getUserAccessLevel();
	BOOST_REQUIRE(!userAccessLevel3 == true);
};

BOOST_AUTO_TEST_CASE(NodeClass_Historizing)
{
	VariableNodeClass::SPtr variableNodeClass = constructSPtr<VariableNodeClass>();
	OpcUaBoolean historizing1;
	OpcUaBoolean historizing2;
	boost::optional<OpcUaBoolean&> historizing3;

	BOOST_REQUIRE(variableNodeClass->isPartHistorizing() == true);
	BOOST_REQUIRE(variableNodeClass->isNullHistorizing() == true);
	BOOST_REQUIRE(variableNodeClass->getHistorizing(historizing1) == false);
	historizing3 = variableNodeClass->getHistorizing();
	BOOST_REQUIRE(!historizing3 == true);

	historizing1 = false;
	BOOST_REQUIRE(variableNodeClass->setHistorizing(historizing1) == true);
	BOOST_REQUIRE(variableNodeClass->isNullHistorizing() == false);
	BOOST_REQUIRE(variableNodeClass->getHistorizing(historizing2) == true);
	BOOST_REQUIRE(historizing1 == historizing2);
	historizing3 = variableNodeClass->getHistorizing();
	BOOST_REQUIRE(!historizing3 == false);
	BOOST_REQUIRE(historizing1== *historizing3);

	BOOST_REQUIRE(variableNodeClass->unsetHistorizing() == true);
	BOOST_REQUIRE(variableNodeClass->isPartHistorizing() == true);
	BOOST_REQUIRE(variableNodeClass->isNullHistorizing() == true);
	BOOST_REQUIRE(variableNodeClass->getHistorizing(historizing1) == false);
	historizing3 = variableNodeClass->getHistorizing();
	BOOST_REQUIRE(!historizing3 == true);
};

BOOST_AUTO_TEST_CASE(NodeClass_Executable)
{
	MethodNodeClass::SPtr variableNodeClass = constructSPtr<MethodNodeClass>();
	OpcUaBoolean executable1;
	OpcUaBoolean executable2;
	boost::optional<OpcUaBoolean&> executable3;

	BOOST_REQUIRE(variableNodeClass->isPartExecutable() == true);
	BOOST_REQUIRE(variableNodeClass->isNullExecutable() == true);
	BOOST_REQUIRE(variableNodeClass->getExecutable(executable1) == false);
	executable3 = variableNodeClass->getExecutable();
	BOOST_REQUIRE(!executable3 == true);

	executable1 = false;
	BOOST_REQUIRE(variableNodeClass->setExecutable(executable1) == true);
	BOOST_REQUIRE(variableNodeClass->isNullExecutable() == false);
	BOOST_REQUIRE(variableNodeClass->getExecutable(executable2) == true);
	BOOST_REQUIRE(executable1 == executable2);
	executable3 = variableNodeClass->getExecutable();
	BOOST_REQUIRE(!executable3 == false);
	BOOST_REQUIRE(executable1== *executable3);

	BOOST_REQUIRE(variableNodeClass->unsetExecutable() == true);
	BOOST_REQUIRE(variableNodeClass->isPartExecutable() == true);
	BOOST_REQUIRE(variableNodeClass->isNullExecutable() == true);
	BOOST_REQUIRE(variableNodeClass->getExecutable(executable1) == false);
	executable3 = variableNodeClass->getExecutable();
	BOOST_REQUIRE(!executable3 == true);
};

BOOST_AUTO_TEST_CASE(NodeClass_UserExecutable)
{
	MethodNodeClass::SPtr variableNodeClass = constructSPtr<MethodNodeClass>();
	OpcUaBoolean userExecutable1;
	OpcUaBoolean userExecutable2;
	boost::optional<OpcUaBoolean&> userExecutable3;

	BOOST_REQUIRE(variableNodeClass->isPartUserExecutable() == true);
	BOOST_REQUIRE(variableNodeClass->isNullUserExecutable() == true);
	BOOST_REQUIRE(variableNodeClass->getUserExecutable(userExecutable1) == false);
	userExecutable3 = variableNodeClass->getUserExecutable();
	BOOST_REQUIRE(!userExecutable3 == true);

	userExecutable1 = false;
	BOOST_REQUIRE(variableNodeClass->setUserExecutable(userExecutable1) == true);
	BOOST_REQUIRE(variableNodeClass->isNullUserExecutable() == false);
	BOOST_REQUIRE(variableNodeClass->getUserExecutable(userExecutable2) == true);
	BOOST_REQUIRE(userExecutable1 == userExecutable2);
	userExecutable3 = variableNodeClass->getUserExecutable();
	BOOST_REQUIRE(!userExecutable3 == false);
	BOOST_REQUIRE(userExecutable1== *userExecutable3);

	BOOST_REQUIRE(variableNodeClass->unsetUserExecutable() == true);
	BOOST_REQUIRE(variableNodeClass->isPartUserExecutable() == true);
	BOOST_REQUIRE(variableNodeClass->isNullUserExecutable() == true);
	BOOST_REQUIRE(variableNodeClass->getUserExecutable(userExecutable1) == false);
	userExecutable3 = variableNodeClass->getUserExecutable();
	BOOST_REQUIRE(!userExecutable3 == true);
};

BOOST_AUTO_TEST_CASE(NodeClass_MinimumSamplingInterval)
{
	VariableNodeClass::SPtr variableNodeClass = constructSPtr<VariableNodeClass>();
	OpcUaDouble minimumSamplingInterval1;
	OpcUaDouble minimumSamplingInterval2;
	boost::optional<OpcUaDouble&> minimumSamplingInterval3;

	BOOST_REQUIRE(variableNodeClass->isPartMinimumSamplingInterval() == true);
	BOOST_REQUIRE(variableNodeClass->isNullMinimumSamplingInterval() == true);
	BOOST_REQUIRE(variableNodeClass->getMinimumSamplingInterval(minimumSamplingInterval1) == false);
	minimumSamplingInterval3 = variableNodeClass->getMinimumSamplingInterval();
	BOOST_REQUIRE(!minimumSamplingInterval3 == true);

	minimumSamplingInterval1 = 12.23;
	BOOST_REQUIRE(variableNodeClass->setMinimumSamplingInterval(minimumSamplingInterval1) == true);
	BOOST_REQUIRE(variableNodeClass->isNullMinimumSamplingInterval() == false);
	BOOST_REQUIRE(variableNodeClass->getMinimumSamplingInterval(minimumSamplingInterval2) == true);
	BOOST_REQUIRE(minimumSamplingInterval1 == minimumSamplingInterval2);
	minimumSamplingInterval3 = variableNodeClass->getMinimumSamplingInterval();
	BOOST_REQUIRE(!minimumSamplingInterval3 == false);
	BOOST_REQUIRE(minimumSamplingInterval1== *minimumSamplingInterval3);

	BOOST_REQUIRE(variableNodeClass->unsetMinimumSamplingInterval() == true);
	BOOST_REQUIRE(variableNodeClass->isPartMinimumSamplingInterval() == true);
	BOOST_REQUIRE(variableNodeClass->isNullMinimumSamplingInterval() == true);
	BOOST_REQUIRE(variableNodeClass->getMinimumSamplingInterval(minimumSamplingInterval1) == false);
	minimumSamplingInterval3 = variableNodeClass->getMinimumSamplingInterval();
	BOOST_REQUIRE(!minimumSamplingInterval3 == true);
};

BOOST_AUTO_TEST_SUITE_END()
