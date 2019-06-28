/*
   Copyright 2017-2018 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   Informationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Aleksey Timin (timin-ayu@nefteavtomatika.ru), Kai Huebl (kai@huebl-sgh.de)
 */


#include <OpcUaStackCore/Filter/ComparisonFilterNode.h>
#include "OpcUaStackCore/BuildInTypes/OpcUaTypeConversion.h"


namespace OpcUaStackCore
{

    ComparisonFilterNode::ComparisonFilterNode(FilterOperator::Enum op, const std::vector<FilterNode::SPtr>& args)
    {
    	operator_ = op;

    	switch(operator_) {
    		case FilterOperator::EnumEquals:
    		case FilterOperator::EnumGreaterThan:
    		case FilterOperator::EnumLessThan:
    		case FilterOperator::EnumGreaterThanOrEqual:
    		case FilterOperator::EnumLessThanOrEqual:
    		{
    			status_ = OpcUaStatusCode::Success;
    			operandStatuses_ = std::vector<OpcUaStatusCode>();

    			if (args.size() == 2) {
    				arg1_ = args[0];
    				arg2_ = args[1];
    			}
    			else {
    				status_ = OpcUaStatusCode::BadFilterOperandCountMismatch;
    			}
    			break;
    		}
    		default:
    			status_ = OpcUaStatusCode::BadFilterOperatorInvalid;
    		}
    }

    ComparisonFilterNode::~ComparisonFilterNode()
    {

    }

    OpcUaStatusCode&
	ComparisonFilterNode::status()
    {
    	return status_;
    }

    std::vector<OpcUaStatusCode>&
	ComparisonFilterNode::operandStatuses()
    {
    	return operandStatuses_;
    }

    bool
	ComparisonFilterNode::evaluate(OpcUaVariant& value)
    {
    	if (status_ == OpcUaStatusCode::Success) {
    		OpcUaVariant value1;
            if (!arg1_->evaluate(value1)) {
            	return false;
            }

            OpcUaVariant value2 ;
            if (!arg2_->evaluate(value2)) {
            	return false;
            }

            bool converted = true;

            OpcUaTypeConversion converter;
            // Convert variable with greater precedence rank
            if (converter.precedenceRank(value1.variantType()) > converter.precedenceRank(value2.variantType())) {
                converted = converter.conversion(value1, value2.variantType(), value1);
            } else if (converter.precedenceRank(value1.variantType()) < converter.precedenceRank(value2.variantType())) {
                converted = converter.conversion(value2, value1.variantType(), value2);
            }

            if (converted) {
                return compare(value1, value2, value);
            } else {
                value.set<OpcUaBoolean>(false); // see the description in table 115 of part 4
            }

            return true;
        }

		return false;
    }

    bool ComparisonFilterNode::compare(OpcUaVariant& lhs, OpcUaVariant& rhs, OpcUaVariant& result)
	{
    	// FIXME: doesn't compare arrays
    	switch (operator_) {
			case FilterOperator::EnumEquals:
			{
				result.set<OpcUaBoolean>(lhs.variant()[0] == rhs.variant()[0]);
				return true;
			}
			case FilterOperator::EnumGreaterThan:
			{
				result.set<OpcUaBoolean>(lhs.variant()[0] > rhs.variant()[0]);
				return true;
			}
			case FilterOperator::EnumLessThan:
			{
				result.set<OpcUaBoolean>(lhs.variant()[0] < rhs.variant()[0]);
				return true;
			}
			case FilterOperator::EnumGreaterThanOrEqual:
			{
				result.set<OpcUaBoolean>(lhs.variant()[0] >= rhs.variant()[0]);
				return true;
			}
			case FilterOperator::EnumLessThanOrEqual:
			{
				result.set<OpcUaBoolean>(lhs.variant()[0] <= rhs.variant()[0]);
				return true;
			}
    		default:
    			Log(Error, "Wrong operator").parameter("FilterOperatorId", operator_);
    	}
    	return false;

	}
}
