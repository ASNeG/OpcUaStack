#include "unittest.h"
#include "FilterOperatorHelpers.h"

#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackCore/ServiceSet/LiteralOperand.h"
#include "OpcUaStackCore/ServiceSet/ElementOperand.h"
#include "OpcUaStackCore/Filter/FilterStack.h"

using namespace OpcUaStackCore;

#define SHOULD_PROCESS_FALSE(stack, filter) do {									\
	ContentFilterResult result;														\
	BOOST_REQUIRE(stack.receive(filter, result));                                   \
	ContentFilterElementResult::SPtr elementResult;                                 \
	result.elementResults()->get(0, elementResult);                                 \
	BOOST_REQUIRE_EQUAL(elementResult->statusCode(), OpcUaStatusCode::Success);     \
	bool filterResult;                                                              \
	BOOST_REQUIRE(stack.process(filterResult));                                     \
	BOOST_REQUIRE(filterResult == false);                                           \
} while(0)


BOOST_AUTO_TEST_SUITE(FilterStack_)

BOOST_AUTO_TEST_CASE(FilterStack_)
{
	std::cout << "FilterStack_" << std::endl;
}

BOOST_AUTO_TEST_CASE(FilterStack_returns_True_if_empty)
{
    FilterStack stack;

    bool filterResult;
    BOOST_REQUIRE(stack.process(filterResult));
    BOOST_REQUIRE(filterResult == true);
}


BOOST_AUTO_TEST_CASE(FilterStack_FilterOperatorUnsupported)
{
    FilterStack stack;
    const int UNSUPPORTED_OPERATOR_ID = 1000;

    ContentFilterElement::SPtr eqElement = makeOperatorWith2LitteralOperands<OpcUaUInt32,OpcUaUInt32>(
               (BasicFilterOperator)UNSUPPORTED_OPERATOR_ID, 100, 120);

    ContentFilter filter;
    filter.elements()->push_back(eqElement);

    ContentFilterResult result;
    BOOST_REQUIRE(stack.receive(filter, result) == false);

    ContentFilterElementResult::SPtr elementResult;
    result.elementResults()->get(0, elementResult);
    BOOST_REQUIRE_EQUAL(elementResult->statusCode(), OpcUaStatusCode::BadFilterOperatorUnsupported);
}

BOOST_AUTO_TEST_CASE(FilterStack_BadFilterOperandCountMismatch)
{
    FilterStack stack;
    const int INVALID_OPERATOR_ID = 1000;

    ContentFilterElement::SPtr eqElement = makeOperatorWith2LitteralOperands<OpcUaUInt32,OpcUaUInt32>(
               BasicFilterOperator::BasicFilterOperator_Equals, 100, 120);

    ContentFilter filter;
    eqElement->filterOperands()->resize(3);
    filter.elements()->push_back(eqElement);

    ContentFilterResult result;
    BOOST_REQUIRE(stack.receive(filter, result) == false);

    ContentFilterElementResult::SPtr elementResult;
    result.elementResults()->get(0, elementResult);
    BOOST_REQUIRE_EQUAL(elementResult->statusCode(), OpcUaStatusCode::BadFilterOperandCountMismatch);
}

BOOST_AUTO_TEST_CASE(FilterStack_2_level_tree)
{
    // (10 == 10) == (20 == 20) => true
    FilterStack stack;

    ContentFilterElement::SPtr eqElement1 = makeOperatorWith2ElementOperands(
            BasicFilterOperator::BasicFilterOperator_Equals, 1, 2);

    ContentFilterElement::SPtr eqElement2 = makeOperatorWith2LitteralOperands<OpcUaUInt32,OpcUaUInt32>(
            BasicFilterOperator::BasicFilterOperator_Equals, 10, 10);

    ContentFilterElement::SPtr eqElement3 = makeOperatorWith2LitteralOperands<OpcUaUInt32,OpcUaUInt32>(
            BasicFilterOperator::BasicFilterOperator_Equals, 20, 20);

    ContentFilter filter;
    filter.elements()->resize(3);
    filter.elements()->push_back(eqElement1);
    filter.elements()->push_back(eqElement2);
    filter.elements()->push_back(eqElement3);

    ContentFilterResult result;

    BOOST_REQUIRE(stack.receive(filter, result));

    ContentFilterElementResult::SPtr elementResult;

    result.elementResults()->get(0, elementResult);
    BOOST_REQUIRE_EQUAL(elementResult->statusCode(), OpcUaStatusCode::Success);
    result.elementResults()->get(1, elementResult);
    BOOST_REQUIRE_EQUAL(elementResult->statusCode(), OpcUaStatusCode::Success);
    result.elementResults()->get(2, elementResult);
    BOOST_REQUIRE_EQUAL(elementResult->statusCode(), OpcUaStatusCode::Success);

    bool filterResult;
    BOOST_REQUIRE(stack.process(filterResult));
    BOOST_REQUIRE(filterResult == true);
}

BOOST_AUTO_TEST_CASE(FilterStack_2_level_half_tree)
{
    // 10  == (20 == 30) => false
    FilterStack stack;

    ContentFilterElement::SPtr eqElement1 = makeOperatorWithElementAndLiteralOperands<OpcUaUInt32>(
            BasicFilterOperator::BasicFilterOperator_Equals, 1, 10);

    ContentFilterElement::SPtr eqElement2 = makeOperatorWith2LitteralOperands<OpcUaUInt32,OpcUaUInt32>(
            BasicFilterOperator::BasicFilterOperator_Equals, 20, 30);

    ContentFilter filter;
    filter.elements()->resize(2);
    filter.elements()->push_back(eqElement1);
    filter.elements()->push_back(eqElement2);


    ContentFilterResult result;

    BOOST_REQUIRE(stack.receive(filter, result));

    ContentFilterElementResult::SPtr elementResult;

    result.elementResults()->get(0, elementResult);
    BOOST_REQUIRE_EQUAL(elementResult->statusCode(), OpcUaStatusCode::Success);
    result.elementResults()->get(1, elementResult);
    BOOST_REQUIRE_EQUAL(elementResult->statusCode(), OpcUaStatusCode::Success);

    bool filterResult;
    BOOST_REQUIRE(stack.process(filterResult));
    BOOST_REQUIRE(filterResult == false);
}

BOOST_AUTO_TEST_CASE(FilterStack_attribute_operand)
{
    // "someAttribute=10" == 10 => true
    FilterStack stack;
    MockAttribute mockAttrIf;

    stack.attributeIf(&mockAttrIf);

    AttributeOperand someAttribute;

    someAttribute.nodeId(constructSPtr<OpcUaNodeId>("someAttribute"));
    someAttribute.alias("alias");

    RelativePathElement::SPtr tagname = constructSPtr<RelativePathElement>();
    tagname->targetName(OpcUaQualifiedName("someAttibute"));
    someAttribute.browsePath().elements()->set(tagname);

    someAttribute.attributeId(199);
    someAttribute.indexRange("someRange");

    ContentFilterElement::SPtr eqElement1 = makeOperatorWithAttributeAndLiteralOperands<OpcUaUInt32>(
            BasicFilterOperator::BasicFilterOperator_Equals, someAttribute, 10);

    ContentFilter filter;
    ContentFilterResult result;

    filter.elements()->resize(1);
    filter.elements()->push_back(eqElement1);

    BOOST_REQUIRE(stack.receive(filter, result));

    mockAttrIf.expectedValue_.set<OpcUaUInt32>(10);
    mockAttrIf.expectedResult_ = true;

    bool filterResult;
    BOOST_REQUIRE(stack.process(filterResult));
    BOOST_REQUIRE(filterResult == true);

    BOOST_REQUIRE_EQUAL(*someAttribute.nodeId(), mockAttrIf.calledTypeId_);
    BOOST_REQUIRE_EQUAL(someAttribute.alias(), mockAttrIf.calledAlias_);

    RelativePathElement::SPtr expectedPathElement, actualPathElement;
    someAttribute.browsePath().elements()->get(expectedPathElement);
    mockAttrIf.calledBrowsePath_->elements()->get(actualPathElement);
    BOOST_REQUIRE_EQUAL(expectedPathElement, actualPathElement);

    BOOST_REQUIRE_EQUAL(someAttribute.attributeId(), mockAttrIf.calledAttributeId_);
    BOOST_REQUIRE_EQUAL(someAttribute.indexRange(), mockAttrIf.calledNumericRange_);

    // "someAttribute=11" == 10 => false
    mockAttrIf.expectedValue_.set<OpcUaUInt32>(11);

    BOOST_REQUIRE(stack.process(filterResult));
    BOOST_REQUIRE(filterResult == false);
}

BOOST_AUTO_TEST_CASE(FilterStack_simple_attribute_operand)
{
    // "someAttribute=10" == 10 => true
    FilterStack stack;
    MockSimpleAttribute mockAttrIf;

    stack.simpleAttributeIf(&mockAttrIf);

    SimpleAttributeOperand someAttribute;

    someAttribute.typeId(OpcUaId_BaseEventType_EventId);

    OpcUaQualifiedName::SPtr tagname = constructSPtr<OpcUaQualifiedName>("someAttibute");
    someAttribute.browsePath()->set(0, tagname);

    someAttribute.attributeId(199);
    someAttribute.indexRange("someRange");

    ContentFilterElement::SPtr eqElement1 = makeOperatorWithSimpleAttributeAndLiteralOperands<OpcUaUInt32>(
          BasicFilterOperator::BasicFilterOperator_Equals, someAttribute, 10);

    ContentFilter filter;
    ContentFilterResult result;

    filter.elements()->resize(1);
    filter.elements()->push_back(eqElement1);

    BOOST_REQUIRE(stack.receive(filter, result));

    mockAttrIf.expectedValue_.set<OpcUaUInt32>(10);
    mockAttrIf.expectedResult_ = true;

    bool filterResult;
    BOOST_REQUIRE(stack.process(filterResult));
    BOOST_REQUIRE(filterResult == true);

    BOOST_REQUIRE_EQUAL(someAttribute.typeId(), mockAttrIf.calledtypeId_);

    OpcUaQualifiedName::SPtr expectedPathElement, actualPathElement;
    someAttribute.browsePath()->get(expectedPathElement);
    actualPathElement = mockAttrIf.calledBrowsePath_.front();
    BOOST_REQUIRE_EQUAL(expectedPathElement, actualPathElement);

    BOOST_REQUIRE_EQUAL(someAttribute.attributeId(), mockAttrIf.calledAttributeId_);
    BOOST_REQUIRE_EQUAL(someAttribute.indexRange(), mockAttrIf.calledNumericRange_);

    // "someAttribute=11" == 10 => false
    mockAttrIf.expectedValue_.set<OpcUaUInt32>(11);

    BOOST_REQUIRE(stack.process(filterResult));
    BOOST_REQUIRE(filterResult == false);
}

BOOST_AUTO_TEST_CASE(FilterStack_loop)
{
    FilterStack stack;

    ContentFilterElement::SPtr eqElement1 = makeOperatorWith2ElementOperands(
            BasicFilterOperator::BasicFilterOperator_Equals, 1, 2);

    ContentFilterElement::SPtr eqElement2 = makeOperatorWith2LitteralOperands<OpcUaUInt32,OpcUaUInt32>(
            BasicFilterOperator::BasicFilterOperator_Equals, 10, 10);

    ContentFilterElement::SPtr eqElement3 =  makeOperatorWith2ElementOperands(
                BasicFilterOperator::BasicFilterOperator_Equals, 0, 1); // make loop

    ContentFilter filter;
    filter.elements()->resize(3);
    filter.elements()->push_back(eqElement1);
    filter.elements()->push_back(eqElement2);
    filter.elements()->push_back(eqElement3);

    ContentFilterResult result;

    BOOST_REQUIRE(stack.receive(filter, result) == false);

    ContentFilterElementResult::SPtr elementResult;

    // First operator result
    result.elementResults()->get(0, elementResult);
    BOOST_REQUIRE_EQUAL(elementResult->statusCode(), OpcUaStatusCode::BadFilterOperandInvalid);

    OpcUaStatusCode operandStatus;
    elementResult->operandStatusCodes()->get(0, operandStatus);
    BOOST_REQUIRE_EQUAL(operandStatus, OpcUaStatusCode::Success);

    elementResult->operandStatusCodes()->get(1, operandStatus);
    BOOST_REQUIRE_EQUAL(operandStatus, OpcUaStatusCode::BadFilterOperandInvalid);

    // Second operator result
    result.elementResults()->get(1, elementResult);
	BOOST_REQUIRE_EQUAL(elementResult->statusCode(), OpcUaStatusCode::Success);
	BOOST_REQUIRE_EQUAL(elementResult->operandStatusCodes()->size(), 0);


	// Third operator result
	result.elementResults()->get(2, elementResult);
	BOOST_REQUIRE_EQUAL(elementResult->statusCode(), OpcUaStatusCode::BadFilterOperandInvalid);

	elementResult->operandStatusCodes()->get(0, operandStatus);
	BOOST_REQUIRE_EQUAL(operandStatus, OpcUaStatusCode::BadFilterElementInvalid);

	elementResult->operandStatusCodes()->get(1, operandStatus);
	BOOST_REQUIRE_EQUAL(operandStatus, OpcUaStatusCode::BadFilterElementInvalid);

}

BOOST_AUTO_TEST_CASE(IsNullFilterNode_supports_IsNullOperator)
{
    FilterStack stack;

    ContentFilterElement::SPtr eqElement = constructSPtr<ContentFilterElement>();

	MockAttribute mockAttrIf;
	stack.attributeIf(&mockAttrIf);
	mockAttrIf.expectedResult_ = true; // attribute's value can be get
	mockAttrIf.expectedValue_.set<OpcUaUInt16>(5);

    ExtensibleParameter::SPtr arg = constructSPtr<ExtensibleParameter>();
	arg->registerFactoryElement<AttributeOperand>((OpcUaUInt32)OpcUaId_AttributeOperand);
	arg->parameterTypeId().set((OpcUaUInt32)OpcUaId_AttributeOperand);
	AttributeOperand::SPtr attr = arg->parameter<AttributeOperand>();

	AttributeOperand nullAttribute;
	*attr = nullAttribute;


    eqElement->filterOperator(BasicFilterOperator::BasicFilterOperator_IsNull);
    eqElement->filterOperands()->resize(1);
    eqElement->filterOperands()->push_back(arg);

    ContentFilter filter;
    filter.elements()->push_back(eqElement);

    ContentFilterResult result;

    BOOST_REQUIRE(stack.receive(filter, result));

    ContentFilterElementResult::SPtr elementResult;
    result.elementResults()->get(0, elementResult);
    BOOST_REQUIRE_EQUAL(elementResult->statusCode(), OpcUaStatusCode::Success);

    bool filterResult;
    BOOST_REQUIRE(stack.process(filterResult));
    BOOST_REQUIRE(filterResult == false);
}



BOOST_AUTO_TEST_CASE(FilterStack_supports_GreaterThan)
{
    FilterStack stack;
    ContentFilterElement::SPtr eqElement1 = makeOperatorWith2LitteralOperands<OpcUaFloat,OpcUaFloat>(
            BasicFilterOperator::BasicFilterOperator_GreaterThan, 10.0, 20.0);

    ContentFilter filter;
    filter.elements()->resize(1);
    filter.elements()->push_back(eqElement1);

	SHOULD_PROCESS_FALSE(stack, filter);
}


BOOST_AUTO_TEST_CASE(FilterStack_supports_LessThan)
{
    FilterStack stack;
    ContentFilterElement::SPtr eqElement1 = makeOperatorWith2LitteralOperands<OpcUaFloat,OpcUaFloat>(
            BasicFilterOperator::BasicFilterOperator_LessThan, 20.0, 10.0);

    ContentFilter filter;
    filter.elements()->resize(1);
    filter.elements()->push_back(eqElement1);

    SHOULD_PROCESS_FALSE(stack, filter);
}

BOOST_AUTO_TEST_CASE(FilterStack_supports_GreateThanOrEqual)
{
    FilterStack stack;
    ContentFilterElement::SPtr eqElement1 = makeOperatorWith2LitteralOperands<OpcUaFloat,OpcUaFloat>(
            BasicFilterOperator::BasicFilterOperator_GreaterThanOrEqual, 10.0, 20.0);

    ContentFilter filter;
    filter.elements()->resize(1);
    filter.elements()->push_back(eqElement1);

    SHOULD_PROCESS_FALSE(stack, filter);
}

BOOST_AUTO_TEST_CASE(FilterStack_supports_LessThanOrEqual)
{
    FilterStack stack;
    ContentFilterElement::SPtr eqElement1 = makeOperatorWith2LitteralOperands<OpcUaFloat,OpcUaFloat>(
            BasicFilterOperator::BasicFilterOperator_LessThanOrEqual, 20.0, 10.0);

    ContentFilter filter;
    filter.elements()->resize(1);
    filter.elements()->push_back(eqElement1);

    SHOULD_PROCESS_FALSE(stack, filter);
}

BOOST_AUTO_TEST_CASE(FilterStack_supports_LikeOperator)
{
    // "xxx" like not "yyy"
    FilterStack stack;
    ContentFilterElement::SPtr eqElement1 = makeOperatorWith2LitteralOperands<OpcUaString,OpcUaString>(
            BasicFilterOperator::BasicFilterOperator_Like, OpcUaString("xxx"), OpcUaString("yyy"));

    ContentFilter filter;
    filter.elements()->resize(1);
    filter.elements()->push_back(eqElement1);

    SHOULD_PROCESS_FALSE(stack, filter);
}

BOOST_AUTO_TEST_CASE(IsNullFilterNode_supports_NotOperator)
{
    FilterStack stack;

    ContentFilterElement::SPtr eqElement = constructSPtr<ContentFilterElement>();

	MockAttribute mockAttrIf;
	stack.attributeIf(&mockAttrIf);
	mockAttrIf.expectedResult_ = true;
	mockAttrIf.expectedValue_.set<OpcUaUInt16>(5);

    ExtensibleParameter::SPtr arg = constructSPtr<ExtensibleParameter>();
	arg->registerFactoryElement<AttributeOperand>((OpcUaUInt32)OpcUaId_AttributeOperand);
	arg->parameterTypeId().set((OpcUaUInt32)OpcUaId_AttributeOperand);
	AttributeOperand::SPtr attr = arg->parameter<AttributeOperand>();

	AttributeOperand nullAttribute;
	*attr = nullAttribute;


    eqElement->filterOperator(BasicFilterOperator::BasicFilterOperator_Not);
    eqElement->filterOperands()->resize(1);
    eqElement->filterOperands()->push_back(arg);

    ContentFilter filter;
    filter.elements()->push_back(eqElement);

    SHOULD_PROCESS_FALSE(stack, filter);
}

BOOST_AUTO_TEST_CASE(FilterStack_supports_BetweenOperator)
{
    FilterStack stack;
	ContentFilterElement::SPtr eqElement = constructSPtr<ContentFilterElement>();

	ExtensibleParameter::SPtr arg1_ = constructSPtr<ExtensibleParameter>();
	arg1_->registerFactoryElement<LiteralOperand>((OpcUaUInt32)OpcUaId_LiteralOperand);
	arg1_->parameterTypeId().set((OpcUaUInt32)OpcUaId_LiteralOperand);
	arg1_->parameter<LiteralOperand>()->value().setValue(10);

	ExtensibleParameter::SPtr arg2_ = constructSPtr<ExtensibleParameter>();
	arg2_->registerFactoryElement<LiteralOperand>((OpcUaUInt32)OpcUaId_LiteralOperand);
	arg2_->parameterTypeId().set((OpcUaUInt32)OpcUaId_LiteralOperand);
	arg2_->parameter<LiteralOperand>()->value().setValue(20);

	ExtensibleParameter::SPtr arg3_ = constructSPtr<ExtensibleParameter>();
	arg3_->registerFactoryElement<LiteralOperand>((OpcUaUInt32)OpcUaId_LiteralOperand);
	arg3_->parameterTypeId().set((OpcUaUInt32)OpcUaId_LiteralOperand);
	arg3_->parameter<LiteralOperand>()->value().setValue(30);

	eqElement->filterOperator(BasicFilterOperator::BasicFilterOperator_Between);
	eqElement->filterOperands()->resize(3);
	eqElement->filterOperands()->push_back(arg1_);
	eqElement->filterOperands()->push_back(arg2_);
	eqElement->filterOperands()->push_back(arg3_);

    ContentFilter filter;
    filter.elements()->resize(1);
    filter.elements()->push_back(eqElement);

    SHOULD_PROCESS_FALSE(stack, filter);
}


BOOST_AUTO_TEST_CASE(FilterStack_supports_InListOperator)
{
    FilterStack stack;
	ContentFilterElement::SPtr eqElement = constructSPtr<ContentFilterElement>();

	ExtensibleParameter::SPtr arg1_ = constructSPtr<ExtensibleParameter>();
	arg1_->registerFactoryElement<LiteralOperand>((OpcUaUInt32)OpcUaId_LiteralOperand);
	arg1_->parameterTypeId().set((OpcUaUInt32)OpcUaId_LiteralOperand);
	arg1_->parameter<LiteralOperand>()->value().setValue(10);

	ExtensibleParameter::SPtr arg2_ = constructSPtr<ExtensibleParameter>();
	arg2_->registerFactoryElement<LiteralOperand>((OpcUaUInt32)OpcUaId_LiteralOperand);
	arg2_->parameterTypeId().set((OpcUaUInt32)OpcUaId_LiteralOperand);
	arg2_->parameter<LiteralOperand>()->value().setValue(20);

	ExtensibleParameter::SPtr arg3_ = constructSPtr<ExtensibleParameter>();
	arg3_->registerFactoryElement<LiteralOperand>((OpcUaUInt32)OpcUaId_LiteralOperand);
	arg3_->parameterTypeId().set((OpcUaUInt32)OpcUaId_LiteralOperand);
	arg3_->parameter<LiteralOperand>()->value().setValue(30);

	eqElement->filterOperator(BasicFilterOperator::BasicFilterOperator_InList);
	eqElement->filterOperands()->resize(3);
	eqElement->filterOperands()->push_back(arg1_);
	eqElement->filterOperands()->push_back(arg2_);
	eqElement->filterOperands()->push_back(arg3_);

    ContentFilter filter;
    filter.elements()->resize(1);
    filter.elements()->push_back(eqElement);

    SHOULD_PROCESS_FALSE(stack, filter);
}

BOOST_AUTO_TEST_CASE(FilterStack_supports_And)
{
    FilterStack stack;
    ContentFilterElement::SPtr eqElement1 = makeOperatorWith2LitteralOperands<OpcUaBoolean,OpcUaBoolean>(
            BasicFilterOperator::BasicFilterOperator_And, true, false);

    ContentFilter filter;
    filter.elements()->resize(1);
    filter.elements()->push_back(eqElement1);

    SHOULD_PROCESS_FALSE(stack, filter);
}

BOOST_AUTO_TEST_CASE(FilterStack_supports_Or)
{
    FilterStack stack;
    ContentFilterElement::SPtr eqElement1 = makeOperatorWith2LitteralOperands<OpcUaBoolean,OpcUaBoolean>(
            BasicFilterOperator::BasicFilterOperator_Or, false, false);

    ContentFilter filter;
    filter.elements()->resize(1);
    filter.elements()->push_back(eqElement1);

    SHOULD_PROCESS_FALSE(stack, filter);
}

BOOST_AUTO_TEST_CASE(FilterStack_supports_Cast)
{
    FilterStack stack;
    ContentFilterElement::SPtr eqElement1 = makeOperatorWith2LitteralOperands<OpcUaString, OpcUaNodeId>(
            BasicFilterOperator::BasicFilterOperator_Cast, OpcUaString("0"), OpcUaNodeId(OpcUaId_UInt16, 0));

    ContentFilter filter;
    filter.elements()->resize(1);
    filter.elements()->push_back(eqElement1);

    SHOULD_PROCESS_FALSE(stack, filter);
}

BOOST_AUTO_TEST_CASE(FilterStack_supports_BitwiseAnd)
{
    FilterStack stack;
    ContentFilterElement::SPtr eqElement1 = makeOperatorWith2LitteralOperands<OpcUaInt16, OpcUaUInt32>(
            BasicFilterOperator::BasicFilterOperator_BitwiseAnd, OpcUaInt16(0x0011), OpcUaUInt32(0x000));

    ContentFilter filter;
    filter.elements()->resize(1);
    filter.elements()->push_back(eqElement1);

    SHOULD_PROCESS_FALSE(stack, filter);
}

BOOST_AUTO_TEST_CASE(FilterStack_supports_BitwiseOr)
{
    FilterStack stack;
    ContentFilterElement::SPtr eqElement1 = makeOperatorWith2LitteralOperands<OpcUaInt16, OpcUaUInt32>(
            BasicFilterOperator::BasicFilterOperator_BitwiseOr, OpcUaInt16(0x0000), OpcUaUInt32(0x000));

    ContentFilter filter;
    filter.elements()->resize(1);
    filter.elements()->push_back(eqElement1);

    SHOULD_PROCESS_FALSE(stack, filter);
}

BOOST_AUTO_TEST_SUITE_END()

