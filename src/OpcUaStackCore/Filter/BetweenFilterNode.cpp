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


#include "OpcUaStackCore/Filter/BetweenFilterNode.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaTypeConversion.h"

namespace OpcUaStackCore
{
	BetweenFilterNode::BetweenFilterNode(const std::vector<FilterNode::SPtr>& args)
    {
        status_ = OpcUaStatusCode::Success;
        operandStatuses_ = std::vector<OpcUaStatusCode>();

        if (args.size() == 3) {
        	arg1_ = args[0];
        	arg2_ = args[1];
        	arg3_ = args[2];
        }
        else {
        	status_ = OpcUaStatusCode::BadFilterOperandCountMismatch;
        }
    }

	BetweenFilterNode::~BetweenFilterNode()
    {

    }

    OpcUaStatusCode&
	BetweenFilterNode::status()
    {
    	return status_;
    }

    std::vector<OpcUaStatusCode>&
	BetweenFilterNode::operandStatuses()
    {
    	return operandStatuses_;
    }

    bool
	BetweenFilterNode::evaluate(OpcUaVariant& value)
    {
    	if (status_ == OpcUaStatusCode::Success) {
    		OpcUaVariant::SPtr operand = constructSPtr<OpcUaVariant>();
    		OpcUaVariant::SPtr min = constructSPtr<OpcUaVariant>();
    		OpcUaVariant::SPtr max = constructSPtr<OpcUaVariant>();


    		arg1_->evaluate(*operand);
    		arg2_->evaluate(*min);
    		arg3_->evaluate(*max);

    		OpcUaTypeConversion converter;
    		OpcUaBuildInType mostPrecedenceType = converter.precedenceRank(operand->variantType()) <
    		 	 converter.precedenceRank(min->variantType()) ? operand->variantType() : min->variantType();

    		mostPrecedenceType = converter.precedenceRank(mostPrecedenceType) <
    		    		 	 converter.precedenceRank(max->variantType()) ? mostPrecedenceType : max->variantType();

    		OpcUaVariant::SPtr tmpVariant = constructSPtr<OpcUaVariant>();
    		operand->copyTo(*tmpVariant);
    		if (!converter.conversion(tmpVariant, mostPrecedenceType, operand)) {
    			value.set<OpcUaBoolean>(false);
    			return true;
    		}

    		min->copyTo(*tmpVariant);
    		if (!converter.conversion(tmpVariant, mostPrecedenceType, min)) {
    			value.set<OpcUaBoolean>(false);
    			return true;
    		}

    		max->copyTo(*tmpVariant);
    		if (!converter.conversion(tmpVariant, mostPrecedenceType, max)) {
    			value.set<OpcUaBoolean>(false);
    			return true;
    		}


    		value.set<OpcUaBoolean>((operand->variant()[0] >= min->variant()[0])
    				&& (operand->variant()[0] <= max->variant()[0]));
    		return true;
    	}

		return false;
    }
}
