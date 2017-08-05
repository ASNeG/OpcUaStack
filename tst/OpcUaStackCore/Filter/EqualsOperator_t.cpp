#include "unittest.h"
#include "FilterOperatorHelpers.h"

using namespace OpcUaStackServer;

BOOST_AUTO_TEST_SUITE(EqualsOperator_)

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

    BOOST_REQUIRE(!stack.process());
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

    BOOST_REQUIRE(stack.process());
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

    BOOST_REQUIRE(stack.receive(filter, result) == OpcUaStatusCode::Success);

    ContentFilterElementResult::SPtr elementResult;
    result.elementResults()->get(0, elementResult);
    BOOST_REQUIRE_EQUAL(elementResult->statusCode(), OpcUaStatusCode::BadFilterOperandCountMismatch);

    BOOST_REQUIRE_NO_THROW(stack.process());
}

BOOST_AUTO_TEST_CASE(EqualsOperator_too_much)
{
    FilterStack stack;

    ContentFilterElement::SPtr eqElement = makeOperatorWith2LitteralOperands<OpcUaUInt32,OpcUaUInt32>(
            BasicFilterOperator::BasicFilterOperator_Equals, 100, 100);
    eqElement->filterOperands()->resize(3);


    ContentFilter filter;
    filter.elements()->push_back(eqElement);

    ContentFilterResult result;

    BOOST_REQUIRE(stack.receive(filter, result) == OpcUaStatusCode::Success);

    ContentFilterElementResult::SPtr elementResult;
    result.elementResults()->get(0, elementResult);
    BOOST_REQUIRE_EQUAL(elementResult->statusCode(), OpcUaStatusCode::BadFilterOperandCountMismatch);

    BOOST_REQUIRE_NO_THROW(stack.process());
}

BOOST_AUTO_TEST_SUITE_END()
