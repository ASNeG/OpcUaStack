#include "unittest.h"
#include "FilterOperatorHelpers.h"

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(IsNullFilterNode_)

BOOST_AUTO_TEST_CASE(IsNullFilterNode_)
{
	std::cout << "IsNullFilterNode_" << std::endl;
}

BOOST_AUTO_TEST_CASE(IsNullFilterNode_true)
{
    FilterStack stack;

    ContentFilterElement::SPtr eqElement = constructSPtr<ContentFilterElement>();

	MockAttribute mockAttrIf;
	stack.attributeIf(&mockAttrIf);
	mockAttrIf.expectedResult_ = false; // attribute's value can't be get

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
    BOOST_REQUIRE(filterResult);
}

BOOST_AUTO_TEST_CASE(IsNullFilterNode_false)
{
    FilterStack stack;

    ContentFilterElement::SPtr eqElement = constructSPtr<ContentFilterElement>();

	MockAttribute mockAttrIf;
	stack.attributeIf(&mockAttrIf);
	mockAttrIf.expectedResult_ = true; // attribute's value can be get

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

BOOST_AUTO_TEST_CASE(IsNullFilterNode_too_much_args)
{
    FilterStack stack;

    ContentFilterElement::SPtr eqElement = makeOperatorWith2LitteralOperands<OpcUaUInt32,OpcUaUInt32>(
            BasicFilterOperator::BasicFilterOperator_IsNull, 100, 100);
    eqElement->filterOperands()->resize(2);


    ContentFilter filter;
    filter.elements()->push_back(eqElement);

    ContentFilterResult result;

    BOOST_REQUIRE(stack.receive(filter, result) == false);

    ContentFilterElementResult::SPtr elementResult;
    result.elementResults()->get(0, elementResult);
    BOOST_REQUIRE_EQUAL(elementResult->statusCode(), OpcUaStatusCode::BadFilterOperandCountMismatch);

    bool retVal;
    BOOST_REQUIRE(!stack.process(retVal));
}

BOOST_AUTO_TEST_SUITE_END()

