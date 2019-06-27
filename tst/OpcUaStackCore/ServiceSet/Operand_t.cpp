#include "unittest.h"
#include "boost/asio.hpp"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/Base/Utility.h"
#include "OpcUaStackCore/StandardDataTypes/ElementOperand.h"
#include "OpcUaStackCore/StandardDataTypes/LiteralOperand.h"
#include "OpcUaStackCore/StandardDataTypes/AttributeOperand.h"
#include "OpcUaStackCore/StandardDataTypes/SimpleAttributeOperand.h"

#include <streambuf>
#include <iostream>

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(Operand_)

BOOST_AUTO_TEST_CASE(Operand_Element)
{
	std::cout << "ElementOperand_t" << std::endl;

	boost::asio::streambuf sb;
	std::iostream ios(&sb);

	ElementOperand elementOperand1, elementOperand2;
	
	// encode
	elementOperand1.index() = ((OpcUaUInt32)123);
	elementOperand1.opcUaBinaryEncode(ios);

	// decode
	elementOperand2.opcUaBinaryDecode(ios);
	BOOST_REQUIRE(elementOperand2.index() == 123);
}

BOOST_AUTO_TEST_CASE(Operand_Literal)
{
	std::cout << "LiteralOperand_t" << std::endl;

	boost::asio::streambuf sb;
	std::iostream ios(&sb);

	OpcUaVariant variant;
	LiteralOperand literalOperand1, literalOperand2;
	
	// encode
	variant.variant((OpcUaUInt32)123);

	literalOperand1.value() = variant;
	literalOperand1.opcUaBinaryEncode(ios);

	// decode
	literalOperand2.opcUaBinaryDecode(ios);
	BOOST_REQUIRE(literalOperand2.value().variant<OpcUaUInt32>() == 123);
}

BOOST_AUTO_TEST_CASE(Operand_SimpleAttribute)
{
	std::cout << "SimpleAttributeOperand_t" << std::endl;

	boost::asio::streambuf sb;
	std::iostream ios(&sb);

	OpcUaString string;
	OpcUaNodeId::SPtr typeId;
	OpcUaQualifiedName::SPtr qualifiedNameSPtr;
	SimpleAttributeOperand simpleAttributeOperand1, simpleAttributeOperand2;
	
	// encode
	qualifiedNameSPtr = constructSPtr<OpcUaQualifiedName>();
	string.value("ABC");
	qualifiedNameSPtr->name(string);
	qualifiedNameSPtr->namespaceIndex(12);

	simpleAttributeOperand1.typeDefinitionId() = OpcUaNodeId((OpcUaUInt32)11, 123);
	simpleAttributeOperand1.browsePath().set(qualifiedNameSPtr);
	simpleAttributeOperand1.attributeId() = ((OpcUaUInt32)123);
	simpleAttributeOperand1.indexRange().value("1:2");
	simpleAttributeOperand1.opcUaBinaryEncode(ios);

	// decode
	simpleAttributeOperand2.opcUaBinaryDecode(ios);

	BOOST_REQUIRE(simpleAttributeOperand2.typeDefinitionId().namespaceIndex() == 123);
	BOOST_REQUIRE(simpleAttributeOperand2.typeDefinitionId().nodeId<OpcUaUInt32>() == 11);

	BOOST_REQUIRE(simpleAttributeOperand2.browsePath().size() == 1);
	simpleAttributeOperand2.browsePath().get(qualifiedNameSPtr);
	BOOST_REQUIRE(qualifiedNameSPtr->name().value() == "ABC");
	BOOST_REQUIRE(qualifiedNameSPtr->namespaceIndex() == 12);

	BOOST_REQUIRE(simpleAttributeOperand2.attributeId() == 123);
	BOOST_REQUIRE(simpleAttributeOperand2.indexRange().value() == "1:2");
}

BOOST_AUTO_TEST_CASE(Operand_Attribute)
{
	std::cout << "AttributeOperand_t" << std::endl;

	boost::asio::streambuf sb;
	std::iostream ios(&sb);

	OpcUaQualifiedName qualifiedName;
	OpcUaNodeId nodeId;
	RelativePathElement::SPtr relativePathElementSPtr;
	AttributeOperand attributeOperand1, attributeOperand2;
	
	// encode
	qualifiedName = "ABC";
	qualifiedName.namespaceIndex(12);

	attributeOperand1.nodeId().namespaceIndex(123);
	attributeOperand1.nodeId().nodeId((OpcUaUInt32)11);

	relativePathElementSPtr = constructSPtr<RelativePathElement>();
	relativePathElementSPtr->referenceTypeId() = attributeOperand1.nodeId();
	relativePathElementSPtr->isInverse() = false;
	relativePathElementSPtr->includeSubtypes() = false;
	relativePathElementSPtr->targetName() = qualifiedName;
	attributeOperand1.browsePath().elements().set(relativePathElementSPtr);

	attributeOperand1.attributeId() = 123;
	attributeOperand1.indexRange().value("1:2");

	attributeOperand1.opcUaBinaryEncode(ios);

	// decode
	attributeOperand2.opcUaBinaryDecode(ios);
	
	BOOST_REQUIRE(attributeOperand2.nodeId().namespaceIndex() == 123);
	BOOST_REQUIRE(attributeOperand2.nodeId().nodeId<OpcUaUInt32>() == 11);
	
	BOOST_REQUIRE(attributeOperand2.browsePath().elements().size() == 1);
	attributeOperand2.browsePath().elements().get(relativePathElementSPtr);
	BOOST_REQUIRE(relativePathElementSPtr->referenceTypeId().namespaceIndex() == 123);
	BOOST_REQUIRE(relativePathElementSPtr->referenceTypeId().nodeId<OpcUaUInt32>() == 11);
	BOOST_REQUIRE(relativePathElementSPtr->isInverse() == false);
	BOOST_REQUIRE(relativePathElementSPtr->includeSubtypes() == false);
	BOOST_REQUIRE(relativePathElementSPtr->targetName().name().value() == "ABC");

	BOOST_REQUIRE(attributeOperand2.attributeId() == 123);
	BOOST_REQUIRE(attributeOperand2.indexRange().value() == "1:2");
}

BOOST_AUTO_TEST_SUITE_END()
