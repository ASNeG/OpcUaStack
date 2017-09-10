#include <OpcUaStackCore/Filter/ComparisonFilterNode.h>
#include "unittest.h"
#include "OpcUaStackCore/Filter/LiteralFilterNode.h"

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(ComparisonFilterNode_)

BOOST_AUTO_TEST_CASE(ComparisonFilterNode_)
{
	std::cout << "ComparisonFilterNode_" << std::endl;
}

BOOST_AUTO_TEST_CASE(ComparisonFilterNode_100_not_equals_120)
{
	OpcUaVariant value;
	std::vector<FilterNode::SPtr> args;

	value.set<OpcUaUInt32>(100);
	args.push_back(constructSPtr<LiteralFilterNode, OpcUaVariant>(value));

	value.set<OpcUaUInt32>(120);
	args.push_back(constructSPtr<LiteralFilterNode, OpcUaVariant>(value));


    ComparisonFilterNode equalsOperator(OpcUaOperator::Equals, args);

    OpcUaVariant operatorResult;
	BOOST_REQUIRE(equalsOperator.evaluate(operatorResult));
    BOOST_REQUIRE(operatorResult.get<OpcUaBoolean>() == false);
}

BOOST_AUTO_TEST_CASE(ComparisonFilterNode_100_equals_100)
{
	OpcUaVariant value;
	std::vector<FilterNode::SPtr> args;

	value.set<OpcUaUInt32>(100);
	args.push_back(constructSPtr<LiteralFilterNode, OpcUaVariant>(value));

	value.set<OpcUaUInt32>(100);
	args.push_back(constructSPtr<LiteralFilterNode, OpcUaVariant>(value));


    ComparisonFilterNode equalsOperator(OpcUaOperator::Equals, args);

    OpcUaVariant operatorResult;
	BOOST_REQUIRE(equalsOperator.evaluate(operatorResult));
    BOOST_REQUIRE(operatorResult.get<OpcUaBoolean>());
}

BOOST_AUTO_TEST_CASE(ComparisonFilterNode_120_greater_than_100)
{
	OpcUaVariant value;
	std::vector<FilterNode::SPtr> args;

	value.set<OpcUaUInt32>(120);
	args.push_back(constructSPtr<LiteralFilterNode, OpcUaVariant>(value));

	value.set<OpcUaUInt32>(100);
	args.push_back(constructSPtr<LiteralFilterNode, OpcUaVariant>(value));


    ComparisonFilterNode greaterThanOperator(OpcUaOperator::GreaterThan, args);

    OpcUaVariant operatorResult;
	BOOST_REQUIRE(greaterThanOperator.evaluate(operatorResult));
    BOOST_REQUIRE(operatorResult.get<OpcUaBoolean>());
}

BOOST_AUTO_TEST_CASE(ComparisonFilterNode_100_not_greater_than_120)
{
	OpcUaVariant value;
	std::vector<FilterNode::SPtr> args;

	value.set<OpcUaUInt32>(100);
	args.push_back(constructSPtr<LiteralFilterNode, OpcUaVariant>(value));

	value.set<OpcUaUInt32>(120);
	args.push_back(constructSPtr<LiteralFilterNode, OpcUaVariant>(value));


    ComparisonFilterNode greaterThanOperator(OpcUaOperator::GreaterThan, args);

    OpcUaVariant operatorResult;
	BOOST_REQUIRE(greaterThanOperator.evaluate(operatorResult));
    BOOST_REQUIRE(operatorResult.get<OpcUaBoolean>() == false);
}

BOOST_AUTO_TEST_CASE(ComparisonFilterNode_100_not_greater_than_100)
{
	OpcUaVariant value;
	std::vector<FilterNode::SPtr> args;

	value.set<OpcUaUInt32>(100);
	args.push_back(constructSPtr<LiteralFilterNode, OpcUaVariant>(value));

	value.set<OpcUaUInt32>(100);
	args.push_back(constructSPtr<LiteralFilterNode, OpcUaVariant>(value));


    ComparisonFilterNode greaterThanOperator(OpcUaOperator::GreaterThan, args);

    OpcUaVariant operatorResult;
	BOOST_REQUIRE(greaterThanOperator.evaluate(operatorResult));
    BOOST_REQUIRE(operatorResult.get<OpcUaBoolean>() == false);
}

BOOST_AUTO_TEST_CASE(ComparisonFilterNode_too_few_args)
{
    std::vector<FilterNode::SPtr> args(0);
    ComparisonFilterNode equalsOperator(OpcUaOperator::Equals, args);

	BOOST_REQUIRE(equalsOperator.status() == OpcUaStatusCode::BadFilterOperandCountMismatch);

	OpcUaVariant operatorResult;
	BOOST_REQUIRE(equalsOperator.evaluate(operatorResult) == false);
}

BOOST_AUTO_TEST_CASE(ComparisonFilterNode_too_much_args)
{
    std::vector<FilterNode::SPtr> args(3);
    ComparisonFilterNode equalsOperator(OpcUaOperator::Equals, args);

	BOOST_REQUIRE(equalsOperator.status() == OpcUaStatusCode::BadFilterOperandCountMismatch);

	OpcUaVariant operatorResult;
	BOOST_REQUIRE(equalsOperator.evaluate(operatorResult) == false);
}

BOOST_AUTO_TEST_CASE(ComparisonFilterNode_1_equals_true)
{
	OpcUaVariant value;
	std::vector<FilterNode::SPtr> args;

	value.set<OpcUaUInt32>(1);
	args.push_back(constructSPtr<LiteralFilterNode, OpcUaVariant>(value));

	value.set<OpcUaBoolean>(true);
	args.push_back(constructSPtr<LiteralFilterNode, OpcUaVariant>(value));


    ComparisonFilterNode equalsOperator(OpcUaOperator::Equals, args);

    OpcUaVariant operatorResult;
	BOOST_REQUIRE(equalsOperator.evaluate(operatorResult));
    BOOST_REQUIRE(operatorResult.get<OpcUaBoolean>());
}

BOOST_AUTO_TEST_CASE(ComparisonFilterNode_true_equals_1)
{
	OpcUaVariant value;
	std::vector<FilterNode::SPtr> args;

	value.set<OpcUaBoolean>(true);
	args.push_back(constructSPtr<LiteralFilterNode, OpcUaVariant>(value));

	value.set<OpcUaUInt32>(1);
	args.push_back(constructSPtr<LiteralFilterNode, OpcUaVariant>(value));


    ComparisonFilterNode equalsOperator(OpcUaOperator::Equals, args);

    OpcUaVariant operatorResult;
	BOOST_REQUIRE(equalsOperator.evaluate(operatorResult));
    BOOST_REQUIRE(operatorResult.get<OpcUaBoolean>());
}

BOOST_AUTO_TEST_CASE(ComparisonFilterNode_implicit_cast_fail)
{
	OpcUaVariant value;
	std::vector<FilterNode::SPtr> args;

	value.set<OpcUaBoolean>(true);
	args.push_back(constructSPtr<LiteralFilterNode, OpcUaVariant>(value));

	value.set<OpcUaDateTime>(OpcUaDateTime());
	args.push_back(constructSPtr<LiteralFilterNode, OpcUaVariant>(value));


    ComparisonFilterNode equalsOperator(OpcUaOperator::Equals, args);

    OpcUaVariant operatorResult;
	BOOST_REQUIRE(equalsOperator.evaluate(operatorResult));
    BOOST_REQUIRE(operatorResult.get<OpcUaBoolean>() == false);
}

BOOST_AUTO_TEST_SUITE_END()

