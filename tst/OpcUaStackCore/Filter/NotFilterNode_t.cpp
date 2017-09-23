#include "unittest.h"
#include "FilterOperatorHelpers.h"
#include "OpcUaStackCore/Filter/NotFilterNode.h"

#include "OpcUaStackCore/Filter/LiteralFilterNode.h"

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(NotFilterNode_)

BOOST_AUTO_TEST_CASE(NotFilterNode_)
{
	std::cout << "NotFilterNode_" << std::endl;
}

BOOST_AUTO_TEST_CASE(NotFilterNode_false)
{
	OpcUaVariant value;
	std::vector<FilterNode::SPtr> args;

	value.set<OpcUaBoolean>(false);
	args.push_back(constructSPtr<LiteralFilterNode, OpcUaVariant>(value));

    NotFilterNode notOperator(args);

	OpcUaVariant operatorResult;
	BOOST_REQUIRE(notOperator.evaluate(operatorResult));
	BOOST_REQUIRE(operatorResult.get<OpcUaBoolean>());
}

BOOST_AUTO_TEST_CASE(NotFilterNode_true)
{
	OpcUaVariant value;
	std::vector<FilterNode::SPtr> args;

	value.set<OpcUaBoolean>(true);
	args.push_back(constructSPtr<LiteralFilterNode, OpcUaVariant>(value));

    NotFilterNode notOperator(args);

	OpcUaVariant operatorResult;
	BOOST_REQUIRE(notOperator.evaluate(operatorResult));
	BOOST_REQUIRE(operatorResult.get<OpcUaBoolean>() == false);
}

BOOST_AUTO_TEST_CASE(NotFilterNode_cast)
{
	OpcUaVariant value;
	std::vector<FilterNode::SPtr> args;

	value.setValue(OpcUaString("false"));
	args.push_back(constructSPtr<LiteralFilterNode, OpcUaVariant>(value));

    NotFilterNode notOperator(args);

	OpcUaVariant operatorResult;
	BOOST_REQUIRE(notOperator.evaluate(operatorResult));
	BOOST_REQUIRE(operatorResult.get<OpcUaBoolean>() == true);
}

BOOST_AUTO_TEST_CASE(NotFilterNode_null)
{
	OpcUaVariant value;
	std::vector<FilterNode::SPtr> args;

	value.setValue(OpcUaString("xxx"));
	args.push_back(constructSPtr<LiteralFilterNode, OpcUaVariant>(value));

    NotFilterNode notOperator(args);

	OpcUaVariant operatorResult;
	BOOST_REQUIRE(!notOperator.evaluate(operatorResult));
	BOOST_REQUIRE(operatorResult.isNull());
}


BOOST_AUTO_TEST_CASE(NotFilterNode_too_much_args)
{
    std::vector<FilterNode::SPtr> args(2);
    NotFilterNode notOperator(args);

	BOOST_REQUIRE(notOperator.status() == OpcUaStatusCode::BadFilterOperandCountMismatch);

	OpcUaVariant operatorResult;
	BOOST_REQUIRE(notOperator.evaluate(operatorResult) == false);
}

BOOST_AUTO_TEST_CASE(NotFilterNode_too_few_args)
{
    std::vector<FilterNode::SPtr> args(0);
    NotFilterNode notOperator(args);

	BOOST_REQUIRE(notOperator.status() == OpcUaStatusCode::BadFilterOperandCountMismatch);

	OpcUaVariant operatorResult;
	BOOST_REQUIRE(notOperator.evaluate(operatorResult) == false);
}

BOOST_AUTO_TEST_SUITE_END()
