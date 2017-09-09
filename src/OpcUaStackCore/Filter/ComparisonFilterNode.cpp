/*
   Copyright 2017 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   Informationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Aleksey Timin (timin-ayu@nefteavtomatika.ru)
 */


#include <OpcUaStackCore/Filter/ComparisonFilterNode.h>
#include "OpcUaStackCore/BuildInTypes/OpcUaTypeConversion.h"


namespace OpcUaStackCore
{

    ComparisonFilterNode::ComparisonFilterNode(OpcUaOperator op, const std::vector<FilterNode::SPtr>& args)
    {
    	operator_ = op;

    	switch(operator_) {
    	case OpcUaOperator::Equals:
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
    		status_ = OpcUaStatusCode::BadFilterOperandInvalid;
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
    		OpcUaVariant::SPtr v1 = constructSPtr<OpcUaVariant>();
            if (!arg1_->evaluate(*v1)) {
            	return false;
            }

            OpcUaVariant::SPtr v2 = constructSPtr<OpcUaVariant>();
            if (!arg2_->evaluate(*v2)) {
            	return false;
            }

    		OpcUaTypeConversion converter;
    		// Convert variable with greater precedence rank
    		if (converter.precedenceRank(v1->variantType()) < converter.precedenceRank(v2->variantType())) {
    			v1.swap(v2);
    		}
    	    char conveType = converter.conversionType(v1->variantType(), v2->variantType());

    	    switch (conveType)
    	    {
    	    case '-':
    	    {
    	    	return compare(v1, v2, value);
    	    }
    	    case 'I':
    	    {
    	    	if (converter.conversion(v1, v2->variantType(), v1)) {
    	    		return compare(v1, v2, value);
    	    	} else {
    	    		value.set<OpcUaBoolean>(false); // see the description in table 115 of part 4
    	    	}


    	    	break;
    	    }
    	    default:
    	    	value.set<OpcUaBoolean>(false); // see the description in table 115 of part 4
    	    }

			return true;
		}

		return false;
    }

    bool ComparisonFilterNode::compare(OpcUaVariant::SPtr lhs, OpcUaVariant::SPtr rhs, OpcUaVariant& result)
	{
    	switch (operator_) {
		case OpcUaOperator::Equals:
		{
			result.set<OpcUaBoolean>(*lhs == *rhs);
			return true;
		}

		}

    	return false;

	}
}
