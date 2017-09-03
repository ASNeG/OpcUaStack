#include "unittest.h"
#include "FilterOperatorHelpers.h"

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(EqualsOperator_)

BOOST_AUTO_TEST_CASE(EqualsOperator_)
{
	std::cout << "EqualsOperator_" << std::endl;
}

BOOST_AUTO_TEST_CASE(EqualsOperator_returns_false)
{
	// 100 == 120 -> false
    FilterStack stack;

    ContentFilterElement::SPtr eqElement = makeOperatorWith2LitteralOperands<OpcUaUInt32,OpcUaUInt32>(
            BasicFilterOperator::BasicFilterOperator_Equals, 100, 120);


    ContentFilter filter;
    filter.elements()->push_back(eqElement);


    ContentFilterResult result;

    BOOST_REQUIRE(stack.receive(filter, result) == OpcUaStatusCode::Success);

    ContentFilterElementResult::SPtr elementResult;
    result.elementResults()->get(0, elementResult);
    BOOST_REQUIRE_EQUAL(elementResult->statusCode(), OpcUaStatusCode::Success);

    bool retVal;
    BOOST_REQUIRE(stack.process(retVal));
    BOOST_REQUIRE(!retVal);
}

BOOST_AUTO_TEST_CASE(EqualsOperator_returns_true)
{
	// 100 == 100 -> true
    FilterStack stack;

    ContentFilterElement::SPtr eqElement = makeOperatorWith2LitteralOperands<OpcUaUInt32,OpcUaUInt32>(
            BasicFilterOperator::BasicFilterOperator_Equals, 100, 100);


    ContentFilter filter;
    filter.elements()->push_back(eqElement);

    ContentFilterResult result;

    BOOST_REQUIRE(stack.receive(filter, result) == OpcUaStatusCode::Success);

    ContentFilterElementResult::SPtr elementResult;
    result.elementResults()->get(0, elementResult);
    BOOST_REQUIRE_EQUAL(elementResult->statusCode(), OpcUaStatusCode::Success);

    bool retVal;
    BOOST_REQUIRE(stack.process(retVal));
    BOOST_REQUIRE(retVal);
}

BOOST_AUTO_TEST_CASE(EqualsOperator_too_few_args)
{
    FilterStack stack;

    ContentFilterElement::SPtr eqElement = makeOperatorWith2LitteralOperands<OpcUaUInt32,OpcUaUInt32>(
            BasicFilterOperator::BasicFilterOperator_Equals, 100, 100);
    eqElement->filterOperands()->resize(1);


    ContentFilter filter;
    filter.elements()->push_back(eqElement);

    ContentFilterResult result;

    BOOST_REQUIRE(stack.receive(filter, result) == OpcUaStatusCode::BadFilterOperandCountMismatch);

    ContentFilterElementResult::SPtr elementResult;
    result.elementResults()->get(0, elementResult);
    BOOST_REQUIRE_EQUAL(elementResult->statusCode(), OpcUaStatusCode::BadFilterOperandCountMismatch);

    bool retVal;
    BOOST_REQUIRE(!stack.process(retVal));
}

BOOST_AUTO_TEST_CASE(EqualsOperator_too_much_args)
{
    FilterStack stack;

    ContentFilterElement::SPtr eqElement = makeOperatorWith2LitteralOperands<OpcUaUInt32,OpcUaUInt32>(
            BasicFilterOperator::BasicFilterOperator_Equals, 100, 100);
    eqElement->filterOperands()->resize(3);


    ContentFilter filter;
    filter.elements()->push_back(eqElement);

    ContentFilterResult result;

    BOOST_REQUIRE(stack.receive(filter, result) == OpcUaStatusCode::BadFilterOperandCountMismatch);

    ContentFilterElementResult::SPtr elementResult;
    result.elementResults()->get(0, elementResult);
    BOOST_REQUIRE_EQUAL(elementResult->statusCode(), OpcUaStatusCode::BadFilterOperandCountMismatch);

    bool retVal;
    BOOST_REQUIRE(!stack.process(retVal));
}

BOOST_AUTO_TEST_CASE(EqualsOperator_implicit_cast1)
{
    FilterStack stack;

    ContentFilterElement::SPtr eqElement = makeOperatorWith2LitteralOperands<OpcUaBoolean,OpcUaUInt32>(
            BasicFilterOperator::BasicFilterOperator_Equals, true, 1);


    ContentFilter filter;
    filter.elements()->push_back(eqElement);

    ContentFilterResult result;

    BOOST_REQUIRE(stack.receive(filter, result) == OpcUaStatusCode::Success);

    ContentFilterElementResult::SPtr elementResult;
    result.elementResults()->get(0, elementResult);
    BOOST_REQUIRE_EQUAL(elementResult->statusCode(), OpcUaStatusCode::Success);

    bool retVal;
    BOOST_REQUIRE(stack.process(retVal));
    BOOST_REQUIRE(retVal);
}

BOOST_AUTO_TEST_CASE(EqualsOperator_implicit_cast2)
{
    FilterStack stack;

    ContentFilterElement::SPtr eqElement = makeOperatorWith2LitteralOperands<OpcUaUInt32, OpcUaBoolean>(
            BasicFilterOperator::BasicFilterOperator_Equals, 1, true);


    ContentFilter filter;
    filter.elements()->push_back(eqElement);

    ContentFilterResult result;

    BOOST_REQUIRE(stack.receive(filter, result) == OpcUaStatusCode::Success);

    ContentFilterElementResult::SPtr elementResult;
    result.elementResults()->get(0, elementResult);
    BOOST_REQUIRE_EQUAL(elementResult->statusCode(), OpcUaStatusCode::Success);

    bool retVal;
    BOOST_REQUIRE(stack.process(retVal));
    BOOST_REQUIRE(retVal);
}

BOOST_AUTO_TEST_CASE(EqualsOperator_implicit_cast_fail)
{
    FilterStack stack;

    ContentFilterElement::SPtr eqElement = makeOperatorWith2LitteralOperands<OpcUaUInt32, OpcUaDateTime>(
            BasicFilterOperator::BasicFilterOperator_Equals, 1, OpcUaDateTime());


    ContentFilter filter;
    filter.elements()->push_back(eqElement);

    ContentFilterResult result;

    BOOST_REQUIRE(stack.receive(filter, result) == OpcUaStatusCode::Success);

    ContentFilterElementResult::SPtr elementResult;
    result.elementResults()->get(0, elementResult);
    BOOST_REQUIRE_EQUAL(elementResult->statusCode(), OpcUaStatusCode::Success);

    bool retVal;
    BOOST_REQUIRE(stack.process(retVal));
    BOOST_REQUIRE(retVal == false);
}

BOOST_AUTO_TEST_SUITE_END()

