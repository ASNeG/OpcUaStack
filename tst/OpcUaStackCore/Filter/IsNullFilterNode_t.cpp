
#include "unittest.h"
#include "FilterOperatorHelpers.h"
#include "OpcUaStackCore/Filter/AttributeFilterNode.h"
#include "OpcUaStackCore/Filter/IsNullFilterNode.h"

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(IsNullFilterNode_)

BOOST_AUTO_TEST_CASE(IsNullFilterNode_)
{
	std::cout << "IsNullFilterNode_" << std::endl;
}

BOOST_AUTO_TEST_CASE(IsNullFilterNode_true1)
{
	MockAttribute mockAttrIf;
	mockAttrIf.expectedResult_ = false; // attribute's value can't be get

    AttributeFilterNode::SPtr simpleAttributeNode(new AttributeFilterNode());
    simpleAttributeNode->attributeIf(&mockAttrIf);

    std::vector<FilterNode::SPtr> args;
    args.push_back(simpleAttributeNode);
    IsNullFilterNode isNullOperator(args);

    OpcUaVariant operatorResult;
	BOOST_REQUIRE(isNullOperator.evaluate(operatorResult));
    BOOST_REQUIRE(operatorResult.get<OpcUaBoolean>());
}

BOOST_AUTO_TEST_CASE(IsNullFilterNode_true2)
{
	MockAttribute mockAttrIf;
	mockAttrIf.expectedResult_ = true; // attribute value can be get
	mockAttrIf.expectedValue_ = OpcUaVariant(); // null value

    AttributeFilterNode::SPtr simpleAttributeNode(new AttributeFilterNode());
    simpleAttributeNode->attributeIf(&mockAttrIf);

    std::vector<FilterNode::SPtr> args;
    args.push_back(simpleAttributeNode);
    IsNullFilterNode isNullOperator(args);

    OpcUaVariant operatorResult;
	BOOST_REQUIRE(isNullOperator.evaluate(operatorResult));
    BOOST_REQUIRE(operatorResult.get<OpcUaBoolean>());
}

BOOST_AUTO_TEST_CASE(IsNullFilterNode_false)
{
	MockAttribute mockAttrIf;
	mockAttrIf.expectedResult_ = true; // attribute's value can't be get
	OpcUaVariant value;
	value.variant(1);
	mockAttrIf.expectedValue_ = value; // not null value

    AttributeFilterNode::SPtr simpleAttributeNode(new AttributeFilterNode());
    simpleAttributeNode->attributeIf(&mockAttrIf);

    std::vector<FilterNode::SPtr> args;
    args.push_back(simpleAttributeNode);
    IsNullFilterNode isNullOperator(args);

    OpcUaVariant operatorResult;
	BOOST_REQUIRE(isNullOperator.evaluate(operatorResult));
    BOOST_REQUIRE(operatorResult.get<OpcUaBoolean>() == false);
}

BOOST_AUTO_TEST_CASE(IsNullFilterNode_too_much_args)
{
    std::vector<FilterNode::SPtr> args(2);
    IsNullFilterNode isNullOperator(args);

	BOOST_REQUIRE(isNullOperator.status() == OpcUaStatusCode::BadFilterOperandCountMismatch);

	OpcUaVariant operatorResult;
	BOOST_REQUIRE(isNullOperator.evaluate(operatorResult) == false);
}

BOOST_AUTO_TEST_CASE(IsNullFilterNode_too_few_args)
{
    std::vector<FilterNode::SPtr> args(0);
    IsNullFilterNode isNullOperator(args);

	BOOST_REQUIRE(isNullOperator.status() == OpcUaStatusCode::BadFilterOperandCountMismatch);

	OpcUaVariant operatorResult;
	BOOST_REQUIRE(isNullOperator.evaluate(operatorResult) == false);
}

BOOST_AUTO_TEST_SUITE_END()

