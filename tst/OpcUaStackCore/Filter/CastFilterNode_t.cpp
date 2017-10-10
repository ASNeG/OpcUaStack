
#include "unittest.h"
#include "FilterOperatorHelpers.h"
#include "OpcUaStackCore/Filter/CastFilterNode.h"

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(CastFilterNode_)

BOOST_AUTO_TEST_CASE(CastFilterNode_)
{
	std::cout << "CastFilterNode_" << std::endl;
}

BOOST_AUTO_TEST_CASE(CastFilterNode_cast)
{
    std::vector<FilterNode::SPtr> args;
    MAKE_TWO_LITERAL_ARGS(args, OpcUaDouble(30.5), OpcUaNodeId(OpcUaId_String, 0));


    CastFilterNode castOperator(args);

	OpcUaVariant operatorResult;
	BOOST_REQUIRE(castOperator.evaluate(operatorResult));
	BOOST_REQUIRE_EQUAL(OpcUaString("30.5"), *operatorResult.getSPtr<OpcUaString>());
}

BOOST_AUTO_TEST_CASE(CastFilterNode_cast_)
{
    std::vector<FilterNode::SPtr> args;
    MAKE_TWO_LITERAL_ARGS(args, OpcUaString("xxx"), OpcUaNodeId(OpcUaId_UInt64, 0));


    CastFilterNode castOperator(args);

	OpcUaVariant operatorResult;
	BOOST_REQUIRE(castOperator.evaluate(operatorResult));
	BOOST_REQUIRE(operatorResult.isNull());
}


BOOST_AUTO_TEST_CASE(CastFilterNode_too_much_args)
{
    std::vector<FilterNode::SPtr> args(3);
    CastFilterNode castOperator(args);

	BOOST_REQUIRE(castOperator.status() == OpcUaStatusCode::BadFilterOperandCountMismatch);

	OpcUaVariant operatorResult;
	BOOST_REQUIRE(castOperator.evaluate(operatorResult) == false);
}

BOOST_AUTO_TEST_CASE(CastFilterNode_too_few_args)
{
    std::vector<FilterNode::SPtr> args(1);
    CastFilterNode castOperator(args);

	BOOST_REQUIRE(castOperator.status() == OpcUaStatusCode::BadFilterOperandCountMismatch);

	OpcUaVariant operatorResult;
	BOOST_REQUIRE(castOperator.evaluate(operatorResult) == false);
}

BOOST_AUTO_TEST_SUITE_END()


