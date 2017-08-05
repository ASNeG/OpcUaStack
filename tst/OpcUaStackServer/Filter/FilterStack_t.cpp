#include "unittest.h"

#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackCore/ServiceSet/LiteralOperand.h"
#include "OpcUaStackCore/ServiceSet/ElementOperand.h"
#include "OpcUaStackServer/Filter/FilterStack.h"

using namespace OpcUaStackServer;

BOOST_AUTO_TEST_SUITE(FilterStack_)

BOOST_AUTO_TEST_CASE(FilterStack_returns_True_if_empty)
{
    FilterStack stack;

    BOOST_REQUIRE(stack.process());
}

template<typename T1, typename T2>
ContentFilterElement::SPtr makeOperatorWith2LitteralOperands(BasicFilterOperator op, T1 arg1, T2 arg2)
{
    ContentFilterElement::SPtr eqElement = constructSPtr<ContentFilterElement>();

    ExtensibleParameter::SPtr arg1_ = constructSPtr<ExtensibleParameter>();
    arg1_->registerFactoryElement<LiteralOperand>((OpcUaUInt32)OpcUaId_LiteralOperand);
    arg1_->parameterTypeId().set((OpcUaUInt32)OpcUaId_LiteralOperand);
    arg1_->parameter<LiteralOperand>()->value().set<T1>(arg1);

    ExtensibleParameter::SPtr arg2_ = constructSPtr<ExtensibleParameter>();
    arg2_->registerFactoryElement<LiteralOperand>((OpcUaUInt32)OpcUaId_LiteralOperand);
    arg2_->parameterTypeId().set((OpcUaUInt32)OpcUaId_LiteralOperand);
    arg2_->parameter<LiteralOperand>()->value().set<T2>(arg2);

    eqElement->filterOperator(op);
    eqElement->filterOperands()->resize(2);
    eqElement->filterOperands()->push_back(arg1_);
    eqElement->filterOperands()->push_back(arg2_);

    return eqElement;
}


ContentFilterElement::SPtr makeOperatorWith2ElementOperands(BasicFilterOperator op, int idx1, int idx2)
{
    ContentFilterElement::SPtr eqElement = constructSPtr<ContentFilterElement>();

    ExtensibleParameter::SPtr arg1_ = constructSPtr<ExtensibleParameter>();
    arg1_->registerFactoryElement<ElementOperand>((OpcUaUInt32)OpcUaId_ElementOperand);
    arg1_->parameterTypeId().set((OpcUaUInt32)OpcUaId_ElementOperand);
    arg1_->parameter<ElementOperand>()->index(idx1);

    ExtensibleParameter::SPtr arg2_ = constructSPtr<ExtensibleParameter>();
    arg2_->registerFactoryElement<ElementOperand>((OpcUaUInt32)OpcUaId_ElementOperand);
    arg2_->parameterTypeId().set((OpcUaUInt32)OpcUaId_ElementOperand);
    arg2_->parameter<ElementOperand>()->index(idx1);

    eqElement->filterOperator(op);
    eqElement->filterOperands()->resize(2);
    eqElement->filterOperands()->push_back(arg1_);
    eqElement->filterOperands()->push_back(arg2_);

    return eqElement;
}

template<typename T>
ContentFilterElement::SPtr makeOperatorWithElementAndLiteralOperands(BasicFilterOperator op, int idx1, T arg2)
{
    ContentFilterElement::SPtr eqElement = constructSPtr<ContentFilterElement>();

    ExtensibleParameter::SPtr arg1_ = constructSPtr<ExtensibleParameter>();
    arg1_->registerFactoryElement<ElementOperand>((OpcUaUInt32)OpcUaId_ElementOperand);
    arg1_->parameterTypeId().set((OpcUaUInt32)OpcUaId_ElementOperand);
    arg1_->parameter<ElementOperand>()->index(idx1);

    ExtensibleParameter::SPtr arg2_ = constructSPtr<ExtensibleParameter>();
    arg2_->registerFactoryElement<LiteralOperand>((OpcUaUInt32)OpcUaId_LiteralOperand);
    arg2_->parameterTypeId().set((OpcUaUInt32)OpcUaId_LiteralOperand);
    arg2_->parameter<LiteralOperand>()->value().set<T>(arg2);

    eqElement->filterOperator(op);
    eqElement->filterOperands()->resize(2);
    eqElement->filterOperands()->push_back(arg1_);
    eqElement->filterOperands()->push_back(arg2_);

    return eqElement;
}
BOOST_AUTO_TEST_CASE(FilterStack_Equals_returns_false)
{
    FilterStack stack;

    ContentFilterElement::SPtr eqElement = makeOperatorWith2LitteralOperands<OpcUaUInt32,OpcUaUInt32>(
            BasicFilterOperator::BasicFilterOperator_Equals, 100, 120);


    ContentFilter filter;
    filter.elements()->push_back(eqElement);


    ContentFilterResult result;
    stack.receive(filter, result);

    BOOST_REQUIRE(!stack.process());
}



BOOST_AUTO_TEST_CASE(FilterStack_Equals_returns_true)
{
    FilterStack stack;

    ContentFilterElement::SPtr eqElement = makeOperatorWith2LitteralOperands<OpcUaUInt32,OpcUaUInt32>(
            BasicFilterOperator::BasicFilterOperator_Equals, 100, 100);


    ContentFilter filter;
    filter.elements()->push_back(eqElement);

    ContentFilterResult result;
    stack.receive(filter, result);

    BOOST_REQUIRE(stack.process());
}

BOOST_AUTO_TEST_CASE(FilterStack_10_eq_10_eq_20_eq_20_true)
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
    stack.receive(filter, result);

    BOOST_REQUIRE(stack.process());
}

BOOST_AUTO_TEST_CASE(FilterStack_10_eq_20_eq_30_false)
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
    stack.receive(filter, result);

    BOOST_REQUIRE(!stack.process());
}


BOOST_AUTO_TEST_SUITE_END()
