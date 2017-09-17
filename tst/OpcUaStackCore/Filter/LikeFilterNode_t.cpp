#include "unittest.h"
#include "OpcUaStackCore/Filter/LikeFilterNode.h"
#include "OpcUaStackCore/Filter/LiteralFilterNode.h"

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(LikeFilterNode_)

BOOST_AUTO_TEST_CASE(LikeFilterNode_)
{
	std::cout << "LikeFilterNode_" << std::endl;
}

BOOST_AUTO_TEST_CASE(LikeFilterNode_xxx_like_xxx)
{
    std::vector<FilterNode::SPtr> args;

    OpcUaVariant str, pattern;
    str.setValue(OpcUaString("xxx"));
    pattern.setValue(OpcUaString("xxx"));

    args.push_back(constructSPtr<LiteralFilterNode, OpcUaVariant>(str));
    args.push_back(constructSPtr<LiteralFilterNode, OpcUaVariant>(pattern));


    LikeFilterNode likeOperator(args);


	BOOST_REQUIRE(likeOperator.status() == OpcUaStatusCode::Success);

	OpcUaVariant operatorResult;
	BOOST_REQUIRE(likeOperator.evaluate(operatorResult));
	BOOST_REQUIRE(operatorResult.get<OpcUaBoolean>() == true);
}

BOOST_AUTO_TEST_CASE(LikeFilterNode_match1)
{
    std::vector<FilterNode::SPtr> args;

    OpcUaVariant str, pattern;
    str.setValue(OpcUaString("maintain"));
    pattern.setValue(OpcUaString("main%"));

    args.push_back(constructSPtr<LiteralFilterNode, OpcUaVariant>(str));
    args.push_back(constructSPtr<LiteralFilterNode, OpcUaVariant>(pattern));

    LikeFilterNode likeOperator(args);

	OpcUaVariant operatorResult;
	BOOST_REQUIRE(likeOperator.evaluate(operatorResult));
	BOOST_REQUIRE(operatorResult.get<OpcUaBoolean>() == true);
}

BOOST_AUTO_TEST_CASE(LikeFilterNode_match1_)
{
    std::vector<FilterNode::SPtr> args;

    OpcUaVariant str, pattern;
    str.setValue(OpcUaString("maintain"));
    pattern.setValue(OpcUaString("mais%"));

    args.push_back(constructSPtr<LiteralFilterNode, OpcUaVariant>(str));
    args.push_back(constructSPtr<LiteralFilterNode, OpcUaVariant>(pattern));

    LikeFilterNode likeOperator(args);

	OpcUaVariant operatorResult;
	BOOST_REQUIRE(likeOperator.evaluate(operatorResult));
	BOOST_REQUIRE(operatorResult.get<OpcUaBoolean>() == false);
}

BOOST_AUTO_TEST_CASE(LikeFilterNode_match2)
{
    std::vector<FilterNode::SPtr> args;

    OpcUaVariant str, pattern;
    str.setValue(OpcUaString("maintain"));
    pattern.setValue(OpcUaString("%intain"));

    args.push_back(constructSPtr<LiteralFilterNode, OpcUaVariant>(str));
    args.push_back(constructSPtr<LiteralFilterNode, OpcUaVariant>(pattern));

    LikeFilterNode likeOperator(args);

	OpcUaVariant operatorResult;
	BOOST_REQUIRE(likeOperator.evaluate(operatorResult));
	BOOST_REQUIRE(operatorResult.get<OpcUaBoolean>() == true);
}

BOOST_AUTO_TEST_CASE(LikeFilterNode_match2_)
{
    std::vector<FilterNode::SPtr> args;

    OpcUaVariant str, pattern;
    str.setValue(OpcUaString("maintain"));
    pattern.setValue(OpcUaString("%Zntain"));

    args.push_back(constructSPtr<LiteralFilterNode, OpcUaVariant>(str));
    args.push_back(constructSPtr<LiteralFilterNode, OpcUaVariant>(pattern));

    LikeFilterNode likeOperator(args);

	OpcUaVariant operatorResult;
	BOOST_REQUIRE(likeOperator.evaluate(operatorResult));
	BOOST_REQUIRE(operatorResult.get<OpcUaBoolean>() == false);
}

BOOST_AUTO_TEST_CASE(LikeFilterNode_match3)
{
    std::vector<FilterNode::SPtr> args;

    OpcUaVariant str, pattern;
    str.setValue(OpcUaString("maintain"));
    pattern.setValue(OpcUaString("%int%"));

    args.push_back(constructSPtr<LiteralFilterNode, OpcUaVariant>(str));
    args.push_back(constructSPtr<LiteralFilterNode, OpcUaVariant>(pattern));

    LikeFilterNode likeOperator(args);

	OpcUaVariant operatorResult;
	BOOST_REQUIRE(likeOperator.evaluate(operatorResult));
	BOOST_REQUIRE(operatorResult.get<OpcUaBoolean>() == true);
}

BOOST_AUTO_TEST_CASE(LikeFilterNode_match3_)
{
    std::vector<FilterNode::SPtr> args;

    OpcUaVariant str, pattern;
    str.setValue(OpcUaString("maintain"));
    pattern.setValue(OpcUaString("%iNt%"));

    args.push_back(constructSPtr<LiteralFilterNode, OpcUaVariant>(str));
    args.push_back(constructSPtr<LiteralFilterNode, OpcUaVariant>(pattern));

    LikeFilterNode likeOperator(args);

	OpcUaVariant operatorResult;
	BOOST_REQUIRE(likeOperator.evaluate(operatorResult));
	BOOST_REQUIRE(operatorResult.get<OpcUaBoolean>() == false);
}

BOOST_AUTO_TEST_CASE(LikeFilterNode_use_conversion)
{
    std::vector<FilterNode::SPtr> args;

    OpcUaVariant str, pattern;
    str.setValue(OpcUaInt32(1));
    pattern.setValue(OpcUaBoolean(true));

    args.push_back(constructSPtr<LiteralFilterNode, OpcUaVariant>(str));
    args.push_back(constructSPtr<LiteralFilterNode, OpcUaVariant>(pattern));

    LikeFilterNode likeOperator(args);

	OpcUaVariant operatorResult;
	BOOST_REQUIRE(likeOperator.evaluate(operatorResult));
	BOOST_REQUIRE(operatorResult.get<OpcUaBoolean>() == true);
}

BOOST_AUTO_TEST_CASE(LikeFilterNode_bad_conversion1)
{
    std::vector<FilterNode::SPtr> args;

    OpcUaVariant str, pattern;
    str.setValue(OpcUaStatusCode(1));
    pattern.setValue(OpcUaBoolean(true));

    args.push_back(constructSPtr<LiteralFilterNode, OpcUaVariant>(str));
    args.push_back(constructSPtr<LiteralFilterNode, OpcUaVariant>(pattern));


    LikeFilterNode likeOperator(args);

	OpcUaVariant operatorResult;
	BOOST_REQUIRE(!likeOperator.evaluate(operatorResult));
}

BOOST_AUTO_TEST_CASE(LikeFilterNode_bad_conversion2)
{
    std::vector<FilterNode::SPtr> args;

    OpcUaVariant str, pattern;
    str.setValue(OpcUaBoolean(true));
    pattern.setValue(OpcUaStatusCode(1));

    args.push_back(constructSPtr<LiteralFilterNode, OpcUaVariant>(str));
    args.push_back(constructSPtr<LiteralFilterNode, OpcUaVariant>(pattern));


    LikeFilterNode likeOperator(args);

	OpcUaVariant operatorResult;
	BOOST_REQUIRE(!likeOperator.evaluate(operatorResult));
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

