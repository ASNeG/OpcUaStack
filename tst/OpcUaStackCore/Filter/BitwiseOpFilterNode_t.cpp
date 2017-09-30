
#include "unittest.h"
#include "FilterOperatorHelpers.h"
#include "OpcUaStackCore/Filter/BitwiseOpFilterNode.h"

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(BitwiseOpFilterNode_)

BOOST_AUTO_TEST_CASE(BitwiseOpFilterNode_)
{
	std::cout << "BitwiseOpFilterNode_" << std::endl;
}

BOOST_AUTO_TEST_CASE(BitwiseOpFilterNode_BitwiseAnd)
{
    std::vector<FilterNode::SPtr> args;
    MAKE_TWO_LITERAL_ARGS(args, OpcUaInt32(0x10F0), OpcUaInt32(0x00F0));
    BitwiseOpFilterNode bitwiseAndOperator(OpcUaOperator::BitwiseAnd, args);

	OpcUaVariant operatorResult;
	BOOST_REQUIRE(bitwiseAndOperator.evaluate(operatorResult));
	BOOST_REQUIRE_EQUAL(0x00F0, operatorResult.get<OpcUaInt32>());
}

BOOST_AUTO_TEST_CASE(BitwiseOpFilterNode_BitwiseOr)
{
    std::vector<FilterNode::SPtr> args;
    MAKE_TWO_LITERAL_ARGS(args, OpcUaInt32(0x10F0), OpcUaInt32(0x00F0));
    BitwiseOpFilterNode bitwiseAndOperator(OpcUaOperator::BitwiseOr, args);

	OpcUaVariant operatorResult;
	BOOST_REQUIRE(bitwiseAndOperator.evaluate(operatorResult));
	BOOST_REQUIRE_EQUAL(0x10F0, operatorResult.get<OpcUaInt32>());
}


BOOST_AUTO_TEST_CASE(BitwiseOpFilterNode_cast1)
{
    std::vector<FilterNode::SPtr> args;
    MAKE_TWO_LITERAL_ARGS(args, OpcUaInt32(0x10F0), OpcUaUInt64(0x00F0));
    BitwiseOpFilterNode bitwiseAndOperator(OpcUaOperator::BitwiseAnd, args);

	OpcUaVariant operatorResult;
	BOOST_REQUIRE(bitwiseAndOperator.evaluate(operatorResult));
	BOOST_REQUIRE_EQUAL(0x00F0, operatorResult.get<OpcUaUInt64>());
}

BOOST_AUTO_TEST_CASE(BitwiseOpFilterNode_cast2)
{
    std::vector<FilterNode::SPtr> args;
    MAKE_TWO_LITERAL_ARGS(args, OpcUaDouble(0x10F0), OpcUaString("240"));
    BitwiseOpFilterNode bitwiseAndOperator(OpcUaOperator::BitwiseAnd, args);

	OpcUaVariant operatorResult;
	BOOST_REQUIRE(bitwiseAndOperator.evaluate(operatorResult));
	BOOST_REQUIRE_EQUAL(0x00F0, operatorResult.get<OpcUaInt64>());
}

BOOST_AUTO_TEST_CASE(BitwiseOpFilterNode_cast3)
{
    std::vector<FilterNode::SPtr> args;
    MAKE_TWO_LITERAL_ARGS(args, OpcUaBoolean(true), OpcUaSByte(0xF1));
    BitwiseOpFilterNode bitwiseAndOperator(OpcUaOperator::BitwiseAnd, args);

	OpcUaVariant operatorResult;
	BOOST_REQUIRE(bitwiseAndOperator.evaluate(operatorResult));
	BOOST_REQUIRE_EQUAL(1, operatorResult.get<OpcUaSByte>());
}

BOOST_AUTO_TEST_CASE(BitwiseOpFilterNode_too_much_args)
{
    std::vector<FilterNode::SPtr> args(3);
    BitwiseOpFilterNode bitwiseAndOperator(OpcUaOperator::BitwiseAnd, args);

	BOOST_REQUIRE(bitwiseAndOperator.status() == OpcUaStatusCode::BadFilterOperandCountMismatch);

	OpcUaVariant operatorResult;
	BOOST_REQUIRE(bitwiseAndOperator.evaluate(operatorResult) == false);
}

BOOST_AUTO_TEST_CASE(BitwiseOpFilterNode_too_few_args)
{
    std::vector<FilterNode::SPtr> args(1);
    BitwiseOpFilterNode bitwiseAndOperator(OpcUaOperator::BitwiseAnd, args);

	BOOST_REQUIRE(bitwiseAndOperator.status() == OpcUaStatusCode::BadFilterOperandCountMismatch);

	OpcUaVariant operatorResult;
	BOOST_REQUIRE(bitwiseAndOperator.evaluate(operatorResult) == false);
}

BOOST_AUTO_TEST_SUITE_END()


