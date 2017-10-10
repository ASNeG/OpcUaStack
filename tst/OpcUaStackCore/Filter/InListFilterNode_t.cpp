#include "unittest.h"
#include "FilterOperatorHelpers.h"
#include "OpcUaStackCore/Filter/LiteralFilterNode.h"
#include "OpcUaStackCore/Filter/InListFilterNode.h"

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(InListFilterNode_)

BOOST_AUTO_TEST_CASE(InListFilterNode_)
{
	std::cout << "InListFilterNode_" << std::endl;
}

BOOST_AUTO_TEST_CASE(InListFilterNode_20_in_20_10_30)
{
	std::vector<FilterNode::SPtr> args;
	MAKE_FOUR_LITERAL_ARGS(args, 20, 20, 10, 30);

	InListFilterNode inListOperator(args);

	OpcUaVariant operatorResult;
	BOOST_REQUIRE(inListOperator.evaluate(operatorResult));
	BOOST_REQUIRE(operatorResult.get<OpcUaBoolean>());
}

BOOST_AUTO_TEST_CASE(InListFilterNode_10_in_20_10_30)
{
	std::vector<FilterNode::SPtr> args;
	MAKE_FOUR_LITERAL_ARGS(args, 10, 20, 10, 30);

	InListFilterNode inListOperator(args);

	OpcUaVariant operatorResult;
	BOOST_REQUIRE(inListOperator.evaluate(operatorResult));
	BOOST_REQUIRE(operatorResult.get<OpcUaBoolean>());
}

BOOST_AUTO_TEST_CASE(InListFilterNode_30_in_20_10_30)
{
	std::vector<FilterNode::SPtr> args;
	MAKE_FOUR_LITERAL_ARGS(args, 30, 20, 10, 30);

	InListFilterNode inListOperator(args);

	OpcUaVariant operatorResult;
	BOOST_REQUIRE(inListOperator.evaluate(operatorResult));
	BOOST_REQUIRE(operatorResult.get<OpcUaBoolean>());
}

BOOST_AUTO_TEST_CASE(InListFilterNode_9_not_in_20_10_30)
{
	std::vector<FilterNode::SPtr> args;
	MAKE_FOUR_LITERAL_ARGS(args, 9, 20, 10, 30);

	InListFilterNode inListOperator(args);

	OpcUaVariant operatorResult;
	BOOST_REQUIRE(inListOperator.evaluate(operatorResult));
	BOOST_REQUIRE(operatorResult.get<OpcUaBoolean>() == false);
}

BOOST_AUTO_TEST_CASE(InListFilterNode_cast1)
{
	std::vector<FilterNode::SPtr> args;
	MAKE_FOUR_LITERAL_ARGS(args, 10, false, OpcUaString("10"), 30);

	InListFilterNode inListOperator(args);

	OpcUaVariant operatorResult;
	BOOST_REQUIRE(inListOperator.evaluate(operatorResult));
	BOOST_REQUIRE(operatorResult.get<OpcUaBoolean>());
}

BOOST_AUTO_TEST_CASE(InListFilterNode_cast2)
{
	std::vector<FilterNode::SPtr> args;
	MAKE_FOUR_LITERAL_ARGS(args, 30, false, OpcUaString("xxx"), 30);

	InListFilterNode inListOperator(args);

	OpcUaVariant operatorResult;
	BOOST_REQUIRE(inListOperator.evaluate(operatorResult));
	BOOST_REQUIRE(operatorResult.get<OpcUaBoolean>());
}

BOOST_AUTO_TEST_CASE(InListFilterNode_too_few_args)
{
    std::vector<FilterNode::SPtr> args(1);
    InListFilterNode inListOperator(args);

	BOOST_REQUIRE(inListOperator.status() == OpcUaStatusCode::BadFilterOperandCountMismatch);

	OpcUaVariant operatorResult;
	BOOST_REQUIRE(inListOperator.evaluate(operatorResult) == false);
}

BOOST_AUTO_TEST_SUITE_END()
