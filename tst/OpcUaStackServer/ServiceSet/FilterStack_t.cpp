#include "unittest.h"

#include "OpcUaStackServer/ServiceSet/FilterStack.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackCore/ServiceSet/LiteralOperand.h"
#include "OpcUaStackCore/ServiceSet/ElementOperand.h"

using namespace OpcUaStackServer;

BOOST_AUTO_TEST_SUITE(FilterStack_)

BOOST_AUTO_TEST_CASE(FilterStack_returns_True_if_empty)
{
    FilterStack stack;

    BOOST_REQUIRE(stack.process());
}


BOOST_AUTO_TEST_CASE(FilterStack_Equals)
{
    FilterStack stack;

    ContentFilter filter;
    ContentFilterElement::SPtr eqElement = constructSPtr<ContentFilterElement>();

    ExtensibleParameter::SPtr arg1 = constructSPtr<ExtensibleParameter>();
    arg1->registerFactoryElement<LiteralOperand>((OpcUaUInt32)OpcUaId_LiteralOperand);
    arg1->parameterTypeId().set((OpcUaUInt32)OpcUaId_LiteralOperand);
    arg1->parameter<LiteralOperand>()->value().set<OpcUaUInt32>(100);

    ExtensibleParameter::SPtr arg2 = constructSPtr<ExtensibleParameter>();
    arg2->registerFactoryElement<LiteralOperand>((OpcUaUInt32)OpcUaId_LiteralOperand);
    arg2->parameterTypeId().set((OpcUaUInt32)OpcUaId_LiteralOperand);
    arg2->parameter<LiteralOperand>()->value().set<OpcUaUInt32>(120);

    eqElement->filterOperator(BasicFilterOperator::BasicFilterOperator_Equals);
    eqElement->filterOperands()->resize(2);
    eqElement->filterOperands()->push_back(arg1);
    eqElement->filterOperands()->push_back(arg2);

    filter.elements()->push_back(eqElement);

    stack.receive(filter, nullptr);

    BOOST_REQUIRE(!stack.process());
}


BOOST_AUTO_TEST_SUITE_END()
