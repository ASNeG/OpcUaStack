#include "unittest.h"
#include "boost/asio.hpp"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/Base/Utility.h"
#include "OpcUaStackCore/ServiceSet/DataChangeFilter.h"
#include "OpcUaStackCore/ServiceSet/EventFilter.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackCore/ServiceSet/ElementOperand.h"

#include <streambuf>
#include <iostream>

// TODO: AggregateFilter

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(Filter_)

BOOST_AUTO_TEST_CASE(Filter_DataChange)
{
	std::cout << "DataChangeFilter_t" << std::endl;

	boost::asio::streambuf sb;
	std::iostream ios(&sb);

	DataChangeFilter filter1, filter2;

	// encode
	filter1.trigger(DataChangeTrigger_Status_Value);
	filter1.deadbandType((OpcUaUInt32)1);
	filter1.deadbandValue((OpcUaDouble)123);
	filter1.opcUaBinaryEncode(ios);

	// decode
	filter2.opcUaBinaryDecode(ios);
	BOOST_REQUIRE(filter2.trigger() == DataChangeTrigger_Status_Value);
	BOOST_REQUIRE(filter2.deadbandType() == 1);
	BOOST_REQUIRE(filter2.deadbandValue() == 123);
}

BOOST_AUTO_TEST_CASE(Filter_Event)
{
	std::cout << "EventFilter_t" << std::endl;

	boost::asio::streambuf sb;
	std::iostream ios(&sb);

	OpcUaString string;
	OpcUaNodeId::SPtr typeIdSPtr;
	OpcUaQualifiedName::SPtr qualifiedNameSPtr;
	ElementOperand::SPtr elementOperandSPtr;
	SimpleAttributeOperand::SPtr simpleAttributeOperandSPtr;
	ContentFilterElement::SPtr contentFilterElementSPtr;
	ExtensibleParameter::SPtr filterOperandSPtr;
	EventFilter filter1, filter2;

	// encode
	typeIdSPtr = OpcUaNodeId::construct();
	typeIdSPtr->namespaceIndex(123);
	typeIdSPtr->nodeId((OpcUaUInt32)321);

	string = "ABC";
	qualifiedNameSPtr = OpcUaQualifiedName::construct();
	qualifiedNameSPtr->namespaceIndex(123),
	qualifiedNameSPtr->name(string);

	simpleAttributeOperandSPtr = SimpleAttributeOperand::construct();
	simpleAttributeOperandSPtr->typeId(typeIdSPtr);
	simpleAttributeOperandSPtr->browsePath()->set(qualifiedNameSPtr);
	simpleAttributeOperandSPtr->attributeId((OpcUaUInt32)123);
	simpleAttributeOperandSPtr->indexRange("1:2");

	filterOperandSPtr = ExtensibleParameter::construct();
	BOOST_REQUIRE(filterOperandSPtr->registerFactoryElement<ElementOperand>((OpcUaUInt32)OpcUaId_OpcUa_XmlSchema_ElementOperand) == true);
	filterOperandSPtr->parameterTypeId().set((OpcUaUInt32)OpcUaId_OpcUa_XmlSchema_ElementOperand);
	elementOperandSPtr = filterOperandSPtr->parameter<ElementOperand>();
	elementOperandSPtr->index((OpcUaUInt32)123);

	contentFilterElementSPtr = ContentFilterElement::construct();
	contentFilterElementSPtr->filterOperator(BasicFilterOperator_And);
	contentFilterElementSPtr->filterOperands()->set(filterOperandSPtr);

	filter1.selectClauses()->set(simpleAttributeOperandSPtr);
	filter1.whereClause().elements()->set(contentFilterElementSPtr);
	filter1.opcUaBinaryEncode(ios);

	// decode
	filter2.opcUaBinaryDecode(ios);
	
	BOOST_REQUIRE(filter2.selectClauses()->size() == 1);
	filter2.selectClauses()->get(simpleAttributeOperandSPtr);

	BOOST_REQUIRE(simpleAttributeOperandSPtr->typeId()->namespaceIndex() == 123);
	BOOST_REQUIRE(simpleAttributeOperandSPtr->typeId()->nodeId<OpcUaUInt32>() == 321);
	BOOST_REQUIRE(simpleAttributeOperandSPtr->attributeId() == 123);
	BOOST_REQUIRE(simpleAttributeOperandSPtr->indexRange().value() == "1:2");
	BOOST_REQUIRE(simpleAttributeOperandSPtr->browsePath()->size() == 1);
	simpleAttributeOperandSPtr->browsePath()->get(qualifiedNameSPtr);
	BOOST_REQUIRE(qualifiedNameSPtr->namespaceIndex() == 123);
	BOOST_REQUIRE(qualifiedNameSPtr->name().value() == "ABC");

	BOOST_REQUIRE(filter2.whereClause().elements()->size() == 1);
	filter2.whereClause().elements()->get(contentFilterElementSPtr);
	BOOST_REQUIRE(contentFilterElementSPtr->filterOperator() == BasicFilterOperator_And);
	BOOST_REQUIRE(contentFilterElementSPtr->filterOperands()->size() == 1);
	contentFilterElementSPtr->filterOperands()->get(filterOperandSPtr);
	filterOperandSPtr->parameterTypeId().set((OpcUaUInt32)OpcUaId_OpcUa_XmlSchema_ElementOperand);
	elementOperandSPtr = filterOperandSPtr->parameter<ElementOperand>();
	BOOST_REQUIRE(elementOperandSPtr->index() == 123);
}

BOOST_AUTO_TEST_CASE(Filter_Aggregate)
{
//  TODO
//	std::cout << "AggregateFilter_t" << std::endl;
}

BOOST_AUTO_TEST_SUITE_END()