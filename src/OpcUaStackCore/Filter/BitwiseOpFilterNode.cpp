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


#include "OpcUaStackCore/Filter/BitwiseOpFilterNode.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaTypeConversion.h"


namespace OpcUaStackCore
{

    BitwiseOpFilterNode::BitwiseOpFilterNode(OpcUaOperator op, const std::vector<FilterNode::SPtr>& args)
    {
    	operator_ = op;

    	switch(operator_) {
    	case OpcUaOperator::BitwiseAnd:
    	case OpcUaOperator::BitwiseOr:
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

    BitwiseOpFilterNode::~BitwiseOpFilterNode()
    {

    }

    OpcUaStatusCode&
	BitwiseOpFilterNode::status()
    {
    	return status_;
    }

    std::vector<OpcUaStatusCode>&
	BitwiseOpFilterNode::operandStatuses()
    {
    	return operandStatuses_;
    }

    OpcUaBuildInType
	BitwiseOpFilterNode::findBiggestIntegerType(const OpcUaVariant& value1, const OpcUaVariant& value2)
    {

	OpcUaTypeConversion converter;

		OpcUaBuildInType mostPrecedenceType =
				(converter.precedenceRank(value1.variantType())
						< converter.precedenceRank(value2.variantType())) ?
						value1.variantType() : value2.variantType();

		switch (mostPrecedenceType) {
		case OpcUaBuildInType_OpcUaDouble:
		case OpcUaBuildInType_OpcUaFloat:
			mostPrecedenceType = OpcUaBuildInType_OpcUaInt64;
			break;
		case OpcUaBuildInType_OpcUaInt64:
		case OpcUaBuildInType_OpcUaUInt64:
		case OpcUaBuildInType_OpcUaInt32:
		case OpcUaBuildInType_OpcUaUInt32:
			break;
		case OpcUaBuildInType_OpcUaStatusCode:
			mostPrecedenceType = OpcUaBuildInType_OpcUaInt32;
			break;
		case OpcUaBuildInType_OpcUaInt16:
		case OpcUaBuildInType_OpcUaUInt16:
		case OpcUaBuildInType_OpcUaSByte:
		case OpcUaBuildInType_OpcUaByte:
			break;
		case OpcUaBuildInType_OpcUaBoolean:
			mostPrecedenceType = OpcUaBuildInType_OpcUaByte;
			break;
		default:
			mostPrecedenceType = OpcUaBuildInType_OpcUaInt64;
			break;
		}
		return mostPrecedenceType;
    }

    bool
	BitwiseOpFilterNode::evaluate(OpcUaVariant& value)
    {
    	if (status_ == OpcUaStatusCode::Success) {
    		OpcUaVariant value1, value2;

    		if (!arg1_->evaluate(value1)) {
    			return false;
    		}

    		if (!arg2_->evaluate(value2)) {
    			return false;
    		}

    		OpcUaTypeConversion converter;
    		OpcUaBuildInType mostPrecedenceType = findBiggestIntegerType(value1, value2);

    		OpcUaVariant tmpVariant;
    		tmpVariant.copyFrom(value1);
    		if (!converter.conversion(tmpVariant, OpcUaBuildInType_OpcUaInt64, value1)) {
    			return false;
    		}

    		tmpVariant.copyFrom(value2);
    		if (!converter.conversion(tmpVariant, OpcUaBuildInType_OpcUaInt64, value2)) {
    			return false;
    		}

        	switch(operator_) {
        	case OpcUaOperator::BitwiseAnd:
        	{
        		tmpVariant.setValue(value1.get<OpcUaInt64>() & value2.get<OpcUaInt64>());
        		break;
        	}
        	case OpcUaOperator::BitwiseOr:
        	{
				tmpVariant.setValue(value1.get<OpcUaInt64>() | value2.get<OpcUaInt64>());
				break;
			}
        	default: return false;
        	}

    		if (!converter.conversion(tmpVariant, mostPrecedenceType, value)) {
    			return false;
    		}

			return true;
		}

		return false;
	}


}
