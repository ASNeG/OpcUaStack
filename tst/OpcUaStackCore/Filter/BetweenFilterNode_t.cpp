#include "unittest.h"
#include "FilterOperatorHelpers.h"

#include "OpcUaStackCore/Filter/LiteralFilterNode.h"
#include "OpcUaStackCore/Filter/BetweenFilterNode.h"

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(BetweenFilterNode_)

BOOST_AUTO_TEST_CASE(BetweenFilterNode_)
{
	std::cout << "BetweenFilterNode_" << std::endl;
}

#define MAKE_THREE_LITERAL_ARGS(args, arg1, arg2, arg3) do {\
	OpcUaVariant value;																\
	value.setValue(arg1);                                                           \
	args.push_back(constructSPtr<LiteralFilterNode, OpcUaVariant>(value));          \
                                                                                    \
	value.setValue(arg2);                                                           \
	args.push_back(constructSPtr<LiteralFilterNode, OpcUaVariant>(value));          \
                                                                                    \
	value.setValue(arg3);                                                           \
	args.push_back(constructSPtr<LiteralFilterNode, OpcUaVariant>(value));          \
} while(0)

BOOST_AUTO_TEST_CASE(BetweenFilterNode_100_between_50_and_120)
{
	std::vector<FilterNode::SPtr> args;
	MAKE_THREE_LITERAL_ARGS(args, 100, 50, 120);
    BetweenFilterNode betweenOperator(args);

	OpcUaVariant operatorResult;
	BOOST_REQUIRE(betweenOperator.evaluate(operatorResult));
	BOOST_REQUIRE(operatorResult.get<OpcUaBoolean>());
}

BOOST_AUTO_TEST_CASE(BetweenFilterNode_50_between_50_and_120)
{
	std::vector<FilterNode::SPtr> args;
	MAKE_THREE_LITERAL_ARGS(args, 50, 50, 120);
    BetweenFilterNode betweenOperator(args);

	OpcUaVariant operatorResult;
	BOOST_REQUIRE(betweenOperator.evaluate(operatorResult));
	BOOST_REQUIRE(operatorResult.get<OpcUaBoolean>());
}

BOOST_AUTO_TEST_CASE(BetweenFilterNode_120_between_50_and_120)
{
	std::vector<FilterNode::SPtr> args;
	MAKE_THREE_LITERAL_ARGS(args, 120, 50, 120);
    BetweenFilterNode betweenOperator(args);

	OpcUaVariant operatorResult;
	BOOST_REQUIRE(betweenOperator.evaluate(operatorResult));
	BOOST_REQUIRE(operatorResult.get<OpcUaBoolean>());
}

BOOST_AUTO_TEST_CASE(BetweenFilterNode_20_not_between_50_and_120)
{
	std::vector<FilterNode::SPtr> args;
	MAKE_THREE_LITERAL_ARGS(args, 20, 50, 120);
    BetweenFilterNode betweenOperator(args);

	OpcUaVariant operatorResult;
	BOOST_REQUIRE(betweenOperator.evaluate(operatorResult));
	BOOST_REQUIRE(operatorResult.get<OpcUaBoolean>() == false);
}

BOOST_AUTO_TEST_CASE(BetweenFilterNode_140_not_between_50_and_120)
{
	std::vector<FilterNode::SPtr> args;
	MAKE_THREE_LITERAL_ARGS(args, 20, 50, 120);
    BetweenFilterNode betweenOperator(args);

	OpcUaVariant operatorResult;
	BOOST_REQUIRE(betweenOperator.evaluate(operatorResult));
	BOOST_REQUIRE(operatorResult.get<OpcUaBoolean>() == false);
}

BOOST_AUTO_TEST_CASE(BetweenFilterNode_cast1)
{
	std::vector<FilterNode::SPtr> args;
	MAKE_THREE_LITERAL_ARGS(args, 70, (OpcUaDouble)50, 120);
    BetweenFilterNode betweenOperator(args);

	OpcUaVariant operatorResult;
	BOOST_REQUIRE(betweenOperator.evaluate(operatorResult));
	BOOST_REQUIRE(operatorResult.get<OpcUaBoolean>());
}

BOOST_AUTO_TEST_CASE(BetweenFilterNode_cast2)
{
	std::vector<FilterNode::SPtr> args;
	MAKE_THREE_LITERAL_ARGS(args, true, (OpcUaDouble)0, OpcUaString("20.0"));
    BetweenFilterNode betweenOperator(args);

	OpcUaVariant operatorResult;
	BOOST_REQUIRE(betweenOperator.evaluate(operatorResult));
	BOOST_REQUIRE(operatorResult.get<OpcUaBoolean>());
}

BOOST_AUTO_TEST_CASE(BetweenFilterNode_cast3)
{
	std::vector<FilterNode::SPtr> args;
	MAKE_THREE_LITERAL_ARGS(args, true, (OpcUaDouble)0, OpcUaString("xxx"));
    BetweenFilterNode betweenOperator(args);

	OpcUaVariant operatorResult;
	BOOST_REQUIRE(betweenOperator.evaluate(operatorResult));
	BOOST_REQUIRE(operatorResult.get<OpcUaBoolean>() == false);
}

BOOST_AUTO_TEST_CASE(BetweenFilterNode_too_much_args)
{
    std::vector<FilterNode::SPtr> args(4);
    BetweenFilterNode betweenOperator(args);

	BOOST_REQUIRE(betweenOperator.status() == OpcUaStatusCode::BadFilterOperandCountMismatch);

	OpcUaVariant operatorResult;
	BOOST_REQUIRE(betweenOperator.evaluate(operatorResult) == false);
}

BOOST_AUTO_TEST_CASE(BetweenFilterNode_too_few_args)
{
    std::vector<FilterNode::SPtr> args(2);
    BetweenFilterNode betweenOperator(args);

	BOOST_REQUIRE(betweenOperator.status() == OpcUaStatusCode::BadFilterOperandCountMismatch);

	OpcUaVariant operatorResult;
	BOOST_REQUIRE(betweenOperator.evaluate(operatorResult) == false);
}

BOOST_AUTO_TEST_SUITE_END()
