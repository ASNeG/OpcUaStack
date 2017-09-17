#include "unittest.h"
#include "OpcUaStackCore/Filter/LikeFilterNode.h"
#include "OpcUaStackCore/Filter/LiteralFilterNode.h"

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(LikeFilterNode_)

BOOST_AUTO_TEST_CASE(LikeFilterNode_)
{
	std::cout << "LikeFilterNode_" << std::endl;
}

BOOST_AUTO_TEST_CASE(LikeFilterNode_string_eqluas_patern)
{
    std::vector<FilterNode::SPtr> args;

    OpcUaVariant str, patern;
    str.setValue(OpcUaString("string"));
    patern.setValue(OpcUaString("string"));

    args.push_back(constructSPtr<LiteralFilterNode, OpcUaVariant>(str));
    args.push_back(constructSPtr<LiteralFilterNode, OpcUaVariant>(patern));


    LikeFilterNode likeOperator(args);


	BOOST_REQUIRE(likeOperator.status() == OpcUaStatusCode::Success);

	OpcUaVariant operatorResult;
	BOOST_REQUIRE(likeOperator.evaluate(operatorResult));
}

BOOST_AUTO_TEST_CASE(LikeFilterNode_too_much_args)
{
    std::vector<FilterNode::SPtr> args(3);
    LikeFilterNode likeOperator(args);

	BOOST_REQUIRE(likeOperator.status() == OpcUaStatusCode::BadFilterOperandCountMismatch);

	OpcUaVariant operatorResult;
	BOOST_REQUIRE(likeOperator.evaluate(operatorResult) == false);
}

BOOST_AUTO_TEST_CASE(LikeFilterNode_too_few_args)
{
    std::vector<FilterNode::SPtr> args(1);
    LikeFilterNode likeOperator(args);

	BOOST_REQUIRE(likeOperator.status() == OpcUaStatusCode::BadFilterOperandCountMismatch);

	OpcUaVariant operatorResult;
	BOOST_REQUIRE(likeOperator.evaluate(operatorResult) == false);
}

BOOST_AUTO_TEST_SUITE_END()

