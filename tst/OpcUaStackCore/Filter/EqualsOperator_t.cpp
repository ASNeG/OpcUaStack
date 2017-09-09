#include "unittest.h"
#include "OpcUaStackCore/Filter/LiteralFilterNode.h"
#include "OpcUaStackCore/Filter/EqualsFilterNode.h"

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(EqualsOperator_)

BOOST_AUTO_TEST_CASE(EqualsOperator_)
{
	std::cout << "EqualsOperator_" << std::endl;
}

BOOST_AUTO_TEST_CASE(EqualsOperator_100_not_equals_120)
{
	OpcUaVariant value;
	std::vector<FilterNode::SPtr> args;

	value.set<OpcUaUInt32>(100);
	args.push_back(constructSPtr<LiteralFilterNode, OpcUaVariant>(value));

	value.set<OpcUaUInt32>(120);
	args.push_back(constructSPtr<LiteralFilterNode, OpcUaVariant>(value));


    EqualsFilterNode equalsOperator(args);

    OpcUaVariant operatorResult;
	BOOST_REQUIRE(equalsOperator.evaluate(operatorResult));
    BOOST_REQUIRE(operatorResult.get<OpcUaBoolean>() == false);
}

BOOST_AUTO_TEST_CASE(EqualsOperator_100_equals_100)
{
	OpcUaVariant value;
	std::vector<FilterNode::SPtr> args;

	value.set<OpcUaUInt32>(100);
	args.push_back(constructSPtr<LiteralFilterNode, OpcUaVariant>(value));

	value.set<OpcUaUInt32>(100);
	args.push_back(constructSPtr<LiteralFilterNode, OpcUaVariant>(value));


    EqualsFilterNode equalsOperator(args);

    OpcUaVariant operatorResult;
	BOOST_REQUIRE(equalsOperator.evaluate(operatorResult));
    BOOST_REQUIRE(operatorResult.get<OpcUaBoolean>());
}

BOOST_AUTO_TEST_CASE(EqualsOperator_too_few_args)
{
    std::vector<FilterNode::SPtr> args(0);
    EqualsFilterNode equalsOperator(args);

	BOOST_REQUIRE(equalsOperator.status() == OpcUaStatusCode::BadFilterOperandCountMismatch);

	OpcUaVariant operatorResult;
	BOOST_REQUIRE(equalsOperator.evaluate(operatorResult) == false);
}

BOOST_AUTO_TEST_CASE(EqualsOperator_too_much_args)
{
    std::vector<FilterNode::SPtr> args(3);
    EqualsFilterNode equalsOperator(args);

	BOOST_REQUIRE(equalsOperator.status() == OpcUaStatusCode::BadFilterOperandCountMismatch);

	OpcUaVariant operatorResult;
	BOOST_REQUIRE(equalsOperator.evaluate(operatorResult) == false);
}

BOOST_AUTO_TEST_CASE(EqualsOperator_1_equals_true)
{
	OpcUaVariant value;
	std::vector<FilterNode::SPtr> args;

	value.set<OpcUaUInt32>(1);
	args.push_back(constructSPtr<LiteralFilterNode, OpcUaVariant>(value));

	value.set<OpcUaBoolean>(true);
	args.push_back(constructSPtr<LiteralFilterNode, OpcUaVariant>(value));


    EqualsFilterNode equalsOperator(args);

    OpcUaVariant operatorResult;
	BOOST_REQUIRE(equalsOperator.evaluate(operatorResult));
    BOOST_REQUIRE(operatorResult.get<OpcUaBoolean>());
}

BOOST_AUTO_TEST_CASE(EqualsOperator_true_equals_1)
{
	OpcUaVariant value;
	std::vector<FilterNode::SPtr> args;

	value.set<OpcUaBoolean>(true);
	args.push_back(constructSPtr<LiteralFilterNode, OpcUaVariant>(value));

	value.set<OpcUaUInt32>(1);
	args.push_back(constructSPtr<LiteralFilterNode, OpcUaVariant>(value));


    EqualsFilterNode equalsOperator(args);

    OpcUaVariant operatorResult;
	BOOST_REQUIRE(equalsOperator.evaluate(operatorResult));
    BOOST_REQUIRE(operatorResult.get<OpcUaBoolean>());
}

BOOST_AUTO_TEST_CASE(EqualsOperator_implicit_cast_fail)
{
	OpcUaVariant value;
	std::vector<FilterNode::SPtr> args;

	value.set<OpcUaBoolean>(true);
	args.push_back(constructSPtr<LiteralFilterNode, OpcUaVariant>(value));

	value.set<OpcUaDateTime>(OpcUaDateTime());
	args.push_back(constructSPtr<LiteralFilterNode, OpcUaVariant>(value));


    EqualsFilterNode equalsOperator(args);

    OpcUaVariant operatorResult;
	BOOST_REQUIRE(equalsOperator.evaluate(operatorResult));
    BOOST_REQUIRE(operatorResult.get<OpcUaBoolean>() == false);
}

BOOST_AUTO_TEST_SUITE_END()

