
#include "unittest.h"
#include "FilterOperatorHelpers.h"
#include "OpcUaStackCore/Filter/LogicalOpFilterNode.h"

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(LogicalOpFilterNode_)

BOOST_AUTO_TEST_CASE(LogicalOpFilterNode_)
{
	std::cout << "LogicalOpFilterNode_" << std::endl;
}

#define SHOULD_BE_TRUE(op, arg1, arg2) do { \
	std::vector<FilterNode::SPtr> args;							\
	MAKE_TWO_LITERAL_ARGS(args, arg1, arg2);                    \
	LogicalOpFilterNode andOperator(op, args);  \
                                                                \
	OpcUaVariant operatorResult;                                \
	BOOST_REQUIRE(andOperator.evaluate(operatorResult));        \
	BOOST_REQUIRE(operatorResult.get<OpcUaBoolean>());          \
	BOOST_REQUIRE(operatorResult.isNull() == false);            \
} while (0)

#define SHOULD_BE_FALSE(op, arg1, arg2) do { \
	std::vector<FilterNode::SPtr> args;							\
	MAKE_TWO_LITERAL_ARGS(args, arg1, arg2);                    \
	LogicalOpFilterNode andOperator(op, args);  \
                                                                \
	OpcUaVariant operatorResult;                                \
	BOOST_REQUIRE(andOperator.evaluate(operatorResult));        \
	BOOST_REQUIRE(operatorResult.get<OpcUaBoolean>() == false); \
	BOOST_REQUIRE(operatorResult.isNull() == false);            \
} while (0)

#define SHOULD_BE_NULL(op, arg1, arg2) do { \
	std::vector<FilterNode::SPtr> args;							\
	MAKE_TWO_LITERAL_ARGS(args, arg1, arg2);                    \
	LogicalOpFilterNode andOperator(op, args);  \
                                                                \
	OpcUaVariant operatorResult;                                \
	BOOST_REQUIRE(andOperator.evaluate(operatorResult));        \
	BOOST_REQUIRE(operatorResult.isNull() == true);             \
} while (0)

BOOST_AUTO_TEST_CASE(LogicalOpFilterNode_AND_Truth_Table)
{
	SHOULD_BE_TRUE (OpcUaOperator::And, true, true);

	SHOULD_BE_FALSE(OpcUaOperator::And, false, true);
	SHOULD_BE_FALSE(OpcUaOperator::And, true, false);
	SHOULD_BE_FALSE(OpcUaOperator::And, false, false);
	SHOULD_BE_FALSE(OpcUaOperator::And, false, OpcUaString("xxx"));
	SHOULD_BE_FALSE(OpcUaOperator::And, OpcUaString("xxx"), false);

	SHOULD_BE_NULL (OpcUaOperator::And, true, OpcUaString("xxx"));
	SHOULD_BE_NULL (OpcUaOperator::And, OpcUaString("xxx"), true);
	SHOULD_BE_NULL (OpcUaOperator::And, OpcUaString("xxx"), OpcUaString("xxx"));
}

BOOST_AUTO_TEST_CASE(LogicalOpFilterNode_OR_Truth_Table)
{
	SHOULD_BE_TRUE (OpcUaOperator::Or, true, true);
	SHOULD_BE_TRUE (OpcUaOperator::Or, true, false);
	SHOULD_BE_TRUE (OpcUaOperator::Or, false, true);
	SHOULD_BE_TRUE (OpcUaOperator::Or, true, OpcUaString("xxx"));
	SHOULD_BE_TRUE (OpcUaOperator::Or, OpcUaString("xxx"), true);

	SHOULD_BE_FALSE(OpcUaOperator::Or, false, false);

	SHOULD_BE_NULL (OpcUaOperator::Or, false, OpcUaString("xxx"));
	SHOULD_BE_NULL (OpcUaOperator::Or, OpcUaString("xxx"), false);
	SHOULD_BE_NULL (OpcUaOperator::Or, OpcUaString("xxx"), OpcUaString("xxx"));
}

BOOST_AUTO_TEST_CASE(LogicalOpFilterNode_AND_cast)
{
	SHOULD_BE_TRUE (OpcUaOperator::And, OpcUaDouble(1), OpcUaString("true"));
	SHOULD_BE_TRUE (OpcUaOperator::Or, OpcUaDouble(1), OpcUaString("false"));
}

BOOST_AUTO_TEST_CASE(LogicalOpFilterNode_too_much_args)
{
    std::vector<FilterNode::SPtr> args(3);
    LogicalOpFilterNode andOperator(OpcUaOperator::And, args);

	BOOST_REQUIRE(andOperator.status() == OpcUaStatusCode::BadFilterOperandCountMismatch);

	OpcUaVariant operatorResult;
	BOOST_REQUIRE(andOperator.evaluate(operatorResult) == false);
}

BOOST_AUTO_TEST_CASE(LogicalOpFilterNode_too_few_args)
{
    std::vector<FilterNode::SPtr> args(1);
    LogicalOpFilterNode andOperator(OpcUaOperator::And, args);

	BOOST_REQUIRE(andOperator.status() == OpcUaStatusCode::BadFilterOperandCountMismatch);

	OpcUaVariant operatorResult;
	BOOST_REQUIRE(andOperator.evaluate(operatorResult) == false);
}

BOOST_AUTO_TEST_SUITE_END()


