#include "unittest.h"
#include <boost/make_shared.hpp>
#include "OpcUaStackCore/Filter/LikeFilterNode.h"
#include "OpcUaStackCore/Filter/LiteralFilterNode.h"

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(LikeFilterNode_)

BOOST_AUTO_TEST_CASE(LikeFilterNode_)
{
	std::cout << "LikeFilterNode_" << std::endl;
}

#define SHOULD_MATCH(string, pattern) do {\
	std::vector<FilterNode::SPtr> args; \
	OpcUaVariant str, pat; \
	str.setValue(OpcUaString(string)); \
	pat.setValue(OpcUaString(pattern)); \
	args.push_back(boost::make_shared<LiteralFilterNode>(str)); \
	args.push_back(boost::make_shared<LiteralFilterNode>(pat)); \
	LikeFilterNode likeOperator(args); \
	BOOST_REQUIRE(likeOperator.status() == OpcUaStatusCode::Success); \
	OpcUaVariant operatorResult; \
	BOOST_REQUIRE(likeOperator.evaluate(operatorResult)); \
	BOOST_REQUIRE(operatorResult.get<OpcUaBoolean>() == true); \
} while(0);

#define SHOULD_NOT_MATCH(string, pattern) do {\
	std::vector<FilterNode::SPtr> args; \
	OpcUaVariant str, pat; \
	str.setValue(OpcUaString(string)); \
	pat.setValue(OpcUaString(pattern)); \
	args.push_back(boost::make_shared<LiteralFilterNode>(str)); \
	args.push_back(boost::make_shared<LiteralFilterNode>(pat)); \
	LikeFilterNode likeOperator(args); \
	BOOST_REQUIRE(likeOperator.status() == OpcUaStatusCode::Success); \
	OpcUaVariant operatorResult; \
	BOOST_REQUIRE(likeOperator.evaluate(operatorResult)); \
	BOOST_REQUIRE(operatorResult.get<OpcUaBoolean>() == false); \
} while(0);


BOOST_AUTO_TEST_CASE(LikeFilterNode_xxx_like_xxx)
{
	SHOULD_MATCH("xxx", "xxx");
}

BOOST_AUTO_TEST_CASE(LikeFilterNode_match_str)
{
	SHOULD_MATCH("maintain", "main%");
	SHOULD_NOT_MATCH("maintain", "mais%");

	SHOULD_MATCH("maintain", "%intain");
	SHOULD_NOT_MATCH("maintain", "%Zntain");

	SHOULD_MATCH("maintain", "%int%");
	SHOULD_NOT_MATCH("maintain", "%iNt%");
}


BOOST_AUTO_TEST_CASE(LikeFilterNode_match_chr)
{
	SHOULD_MATCH("maintain", "m_intain");
	SHOULD_NOT_MATCH("maintain", "m_inTain");
}


BOOST_AUTO_TEST_CASE(LikeFilterNode_match_chr_and_str)
{
	SHOULD_MATCH("maintain", "m_int%");
	SHOULD_NOT_MATCH("maintain", "m_1nt%");
}

BOOST_AUTO_TEST_CASE(LikeFilterNode_match_escape)
{
	SHOULD_MATCH("10 %", "10 \\%");
	SHOULD_MATCH("abc_", "abc\\_");
	SHOULD_MATCH("abc[]", "abc\\[\\]");
	SHOULD_MATCH("abc^", "abc[\\^]");
	SHOULD_MATCH("abc\\", "abc\\\\");

	SHOULD_NOT_MATCH("10 % 3", "10 \\%");
}

BOOST_AUTO_TEST_CASE(LikeFilterNode_match_list)
{
	SHOULD_MATCH("abc1", "abc[1]");
	SHOULD_NOT_MATCH("abc1", "abc[2]");

	SHOULD_MATCH("abc1N", "abc[1]N");
	SHOULD_NOT_MATCH("abc1#", "abc[1]N");

	SHOULD_MATCH("abc1", "abc[13]");
	SHOULD_MATCH("abc3", "abc[13]");
	SHOULD_NOT_MATCH("abc2", "abc[13]");

	SHOULD_MATCH("abc1", "abc[13-9A]");
	SHOULD_MATCH("abc3", "abc[13-9A]");
	SHOULD_MATCH("abc5", "abc[13-9A]");
	SHOULD_MATCH("abc9", "abc[13-9A]");
	SHOULD_MATCH("abcA", "abc[13-9A]");

	SHOULD_NOT_MATCH("abc2", "abc[13-9A]");

	SHOULD_MATCH("abc-", "abc[13\\-9A]");
}

BOOST_AUTO_TEST_CASE(LikeFilterNode_not_match_list)
{
	SHOULD_MATCH("abc1", "abc[^2]");
	SHOULD_NOT_MATCH("abc2", "abc[^2]");

	SHOULD_MATCH("abc2", "abc[^13]");
	SHOULD_NOT_MATCH("abc1", "abc[^13]");
	SHOULD_NOT_MATCH("abc3", "abc[^13]");

	SHOULD_MATCH("abcB", "abc[^13-9A]");
	SHOULD_NOT_MATCH("abc5", "abc[^13-9A]");
}

BOOST_AUTO_TEST_CASE(LikeFilterNode_use_conversion)
{
    std::vector<FilterNode::SPtr> args;

    OpcUaVariant str, pattern;
    str.setValue(OpcUaInt32(1));
    pattern.setValue(OpcUaBoolean(true));

    args.push_back(boost::make_shared<LiteralFilterNode>(str));
    args.push_back(boost::make_shared<LiteralFilterNode>(pattern));

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

    args.push_back(boost::make_shared<LiteralFilterNode>(str));
    args.push_back(boost::make_shared<LiteralFilterNode>(pattern));


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

    args.push_back(boost::make_shared<LiteralFilterNode>(str));
    args.push_back(boost::make_shared<LiteralFilterNode>(pattern));


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

