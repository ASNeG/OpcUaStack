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


#include <OpcUaStackCore/Filter/LogicalOpFilterNode.h>
#include "OpcUaStackCore/BuildInTypes/OpcUaTypeConversion.h"


namespace OpcUaStackCore
{

    LogicalOpFilterNode::LogicalOpFilterNode(OpcUaOperator op, const std::vector<FilterNode::SPtr>& args)
    {
    	operator_ = op;

    	switch(operator_) {
    	case OpcUaOperator::And:
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

    LogicalOpFilterNode::~LogicalOpFilterNode()
    {

    }

    OpcUaStatusCode&
	LogicalOpFilterNode::status()
    {
    	return status_;
    }

    std::vector<OpcUaStatusCode>&
	LogicalOpFilterNode::operandStatuses()
    {
    	return operandStatuses_;
    }

    bool
	LogicalOpFilterNode::evaluate(OpcUaVariant& value)
    {
    	if (status_ == OpcUaStatusCode::Success) {

            LogicalValue result = andTable[toLogicalValue(arg1_)][toLogicalValue(arg2_)];

            if (result == LogicalValue::Null) {
            	value.clear();
            } else {
            	value.setValue(result == LogicalValue::True);
            }

			return true;
		}

		return false;
	}

    LogicalOpFilterNode::LogicalValue
    LogicalOpFilterNode::andTable[3][3] =
    {
    		{ LogicalValue::True, LogicalValue::False, LogicalValue::Null },
			{ LogicalValue::False, LogicalValue::False, LogicalValue::False },
			{ LogicalValue::Null, LogicalValue::False, LogicalValue::Null }
    };

    LogicalOpFilterNode::LogicalValue
	LogicalOpFilterNode::toLogicalValue(FilterNode::SPtr arg)
    {
		LogicalValue lv = LogicalValue::Null;
		OpcUaVariant value;
		if (!arg->evaluate(value)) {
			return lv;
		}

		if (!value.isNull()) {
			OpcUaVariant tmpVariant;
			tmpVariant.copyFrom(value);

			OpcUaTypeConversion converter;
			if (converter.conversion(tmpVariant, OpcUaBuildInType_OpcUaBoolean, value)) {
				lv = value.get<OpcUaBoolean>() ? LogicalValue::True : LogicalValue::False;
			}
    	}

		return lv;
    }

}
