#include "unittest.h"
#include "boost/asio.hpp"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/Base/Utility.h"
#include "OpcUaStackCore/ServiceSet/DataChangeFilter.h"
#include "OpcUaStackCore/ServiceSet/EventFilter.h"
#include "OpcUaStackCore/ServiceSet/EventFilterResult.h"
#include "OpcUaStackCore/ServiceSet/AggregateFilterResult.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackCore/ServiceSet/ElementOperand.h"

#include <streambuf>
#include <iostream>

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(Filter_)

BOOST_AUTO_TEST_CASE(Filter_DataChange)
{
	std::cout << "DataChangeFilter_t" << std::endl;

	boost::asio::streambuf sb;
	std::iostream ios(&sb);

	DataChangeFilter filter1, filter2;

	// encode
	filter1.trigger(DCT_StatusValue);
	filter1.deadbandType((OpcUaUInt32)1);
	filter1.deadbandValue((OpcUaDouble)123);
	filter1.opcUaBinaryEncode(ios);

	// decode
	filter2.opcUaBinaryDecode(ios);
	BOOST_REQUIRE(filter2.trigger() == DCT_StatusValue);
	BOOST_REQUIRE(filter2.deadbandType() == 1);
	BOOST_REQUIRE(filter2.deadbandValue() == 123);
}

BOOST_AUTO_TEST_CASE(Filter_Event)
{
	std::cout << "EventFilter_t" << std::endl;

	boost::asio::streambuf sb;
	std::iostream ios(&sb);

	OpcUaString string;
	OpcUaNodeId typeId;
	OpcUaQualifiedName::SPtr qualifiedNameSPtr;
	ElementOperand::SPtr elementOperandSPtr;
	SimpleAttributeOperand::SPtr simpleAttributeOperandSPtr;
	ContentFilterElement::SPtr contentFilterElementSPtr;
	ExtensibleParameter::SPtr filterOperandSPtr;
	EventFilter filter1, filter2;

	// encode
	typeId.namespaceIndex(123);
	typeId.nodeId((OpcUaUInt32)321);

	string = "ABC";
	qualifiedNameSPtr = constructSPtr<OpcUaQualifiedName>();
	qualifiedNameSPtr->namespaceIndex(123),
	qualifiedNameSPtr->name(string);

	simpleAttributeOperandSPtr = constructSPtr<SimpleAttributeOperand>();
	simpleAttributeOperandSPtr->typeId(typeId);
	simpleAttributeOperandSPtr->browsePath()->set(qualifiedNameSPtr);
	simpleAttributeOperandSPtr->attributeId((OpcUaUInt32)123);
	simpleAttributeOperandSPtr->indexRange("1:2");

	filterOperandSPtr = constructSPtr<ExtensibleParameter>();
	BOOST_REQUIRE(filterOperandSPtr->registerFactoryElement<ElementOperand>((OpcUaUInt32)OpcUaId_OpcUa_XmlSchema_ElementOperand) == true);
	filterOperandSPtr->parameterTypeId().set((OpcUaUInt32)OpcUaId_OpcUa_XmlSchema_ElementOperand);
	elementOperandSPtr = filterOperandSPtr->parameter<ElementOperand>();
	elementOperandSPtr->index((OpcUaUInt32)123);

	contentFilterElementSPtr = constructSPtr<ContentFilterElement>();
	contentFilterElementSPtr->filterOperator(BasicFilterOperator_And);
	contentFilterElementSPtr->filterOperands()->set(filterOperandSPtr);

	filter1.selectClauses()->set(simpleAttributeOperandSPtr);
	filter1.whereClause().elements()->set(contentFilterElementSPtr);
	filter1.opcUaBinaryEncode(ios);

	// decode
	filter2.opcUaBinaryDecode(ios);
	
	BOOST_REQUIRE(filter2.selectClauses()->size() == 1);
	filter2.selectClauses()->get(simpleAttributeOperandSPtr);

	BOOST_REQUIRE(simpleAttributeOperandSPtr->typeId() == OpcUaNodeId(321, 123));
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

BOOST_AUTO_TEST_CASE(Filter_EventResult)
{
	std::cout << "EventFilterResult_t" << std::endl;

	boost::asio::streambuf sb;
	std::iostream ios(&sb);

	ContentFilterElementResult::SPtr elementResultSPtr;
	OpcUaStatusCode statusCode1, statusCode2;
	EventFilterResult eventFilterResult1, eventFilterResult2;

	// encode
	eventFilterResult1.selectClauseResults()->set((OpcUaStatusCode)Success);
	
	elementResultSPtr = constructSPtr<ContentFilterElementResult>();
	elementResultSPtr->statusCode((OpcUaStatusCode)Success);
	elementResultSPtr->operandStatusCodes()->set((OpcUaStatusCode)Success);
	eventFilterResult1.whereClauseResult().elementResults()->set(elementResultSPtr);
	
	eventFilterResult1.opcUaBinaryEncode(ios);

	// decode
	eventFilterResult2.opcUaBinaryDecode(ios);
	BOOST_REQUIRE(eventFilterResult2.selectClauseResults()->size() == 1);
	eventFilterResult2.selectClauseResults()->get(statusCode1);
	BOOST_REQUIRE(statusCode1 == Success);

	BOOST_REQUIRE(eventFilterResult2.whereClauseResult().elementResults()->size() == 1);
	elementResultSPtr = constructSPtr<ContentFilterElementResult>();
	eventFilterResult2.whereClauseResult().elementResults()->get(elementResultSPtr);
	BOOST_REQUIRE(elementResultSPtr->statusCode() == Success);

	BOOST_REQUIRE(elementResultSPtr->operandStatusCodes()->size() == 1);
	elementResultSPtr->operandStatusCodes()->get(statusCode2);
	BOOST_REQUIRE(statusCode2 == Success);
}

BOOST_AUTO_TEST_CASE(Filter_Aggregate)
{
//  TODO
//	std::cout << "AggregateFilter_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(Filter_AggregateResult)
{
	std::cout << "AggregateFilterResult_t" << std::endl;

	boost::asio::streambuf sb;
	std::iostream ios(&sb);

	AggregateFilterResult filter1, filter2; 
	boost::posix_time::ptime ptime = boost::posix_time::from_iso_string("16010101T000000.000000000");
	
	// encode
	filter1.revisedStartTime(ptime);
	filter1.revisedProcessingInterval((OpcUaDouble)123);
	filter1.opcUaBinaryEncode(ios);

	// decode
	filter2.opcUaBinaryDecode(ios);
	BOOST_REQUIRE(filter2.revisedStartTime().dateTime() == ptime);
	BOOST_REQUIRE(filter2.revisedProcessingInterval() == 123);
}

BOOST_AUTO_TEST_SUITE_END()
