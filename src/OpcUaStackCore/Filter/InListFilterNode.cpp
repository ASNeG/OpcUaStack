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

#include "OpcUaStackCore/BuildInTypes/OpcUaTypeConversion.h"
#include "OpcUaStackCore/Filter/InListFilterNode.h"

namespace OpcUaStackCore
{
    InListFilterNode::InListFilterNode(const std::vector<FilterNode::SPtr>& args)
    {
        status_ = OpcUaStatusCode::Success;
        operandStatuses_ = std::vector<OpcUaStatusCode>();

        if (args.size() > 1) {
        	arg_ = args[0];
        	list_.insert(list_.begin(), args.begin()+1, args.end());
        }
        else {
        	status_ = OpcUaStatusCode::BadFilterOperandCountMismatch;
        }
    }

    InListFilterNode::~InListFilterNode()
    {

    }

    OpcUaStatusCode&
	InListFilterNode::status()
    {
    	return status_;
    }

    std::vector<OpcUaStatusCode>&
	InListFilterNode::operandStatuses()
    {
    	return operandStatuses_;
    }

    bool
	InListFilterNode::evaluate(OpcUaVariant& value)
    {
    	if (status_ == OpcUaStatusCode::Success) {
    		OpcUaBoolean result = false;

    		OpcUaVariant::SPtr argValue = constructSPtr<OpcUaVariant>();
    		if (arg_->evaluate(*argValue)) {
    			OpcUaTypeConversion converter;
    			std::list<OpcUaVariant::SPtr> evaluatedOperands;

				// Find the most ranked type and evaluate all operands
				OpcUaBuildInType mostPrecedenceType = argValue->variantType();
				for (std::list<FilterNode::SPtr>::iterator it = list_.begin(); it != list_.end(); it++) {
					OpcUaVariant::SPtr operandResult = constructSPtr<OpcUaVariant>();

					// if an operand doesn't evaluate don't check it
					if (!(*it)->evaluate(*operandResult)) {
						break;
					}

					evaluatedOperands.push_back(operandResult);

					mostPrecedenceType = converter.precedenceRank(mostPrecedenceType) <
							converter.precedenceRank(operandResult->variantType()) ? mostPrecedenceType : operandResult->variantType();
				}

				OpcUaVariant::SPtr tmpVariant = constructSPtr<OpcUaVariant>();
				argValue->copyTo(*tmpVariant);
				if (converter.conversion(tmpVariant, mostPrecedenceType, argValue)) {

					// Find in the list
					for (std::list<OpcUaVariant::SPtr>::iterator it = evaluatedOperands.begin(); it != evaluatedOperands.end(); it++) {

						(*it)->copyTo(*tmpVariant);
						if (converter.conversion(tmpVariant, mostPrecedenceType, *it)) {

							if ((*(*it) == *argValue)) {
								result = true;
								break;
							}
						}
					}
				}
    		}

    		value.set<OpcUaBoolean>(result);
    		return true;
    	}

		return false;
    }
}
