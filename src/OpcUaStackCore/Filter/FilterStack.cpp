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


#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaTypeConversion.h"

#include "OpcUaStackCore/ServiceSet/LiteralOperand.h"
#include "OpcUaStackCore/ServiceSet/ElementOperand.h"
#include "OpcUaStackCore/ServiceSet/AttributeOperand.h"

#include "OpcUaStackCore/Filter/FilterStack.h"
#include "OpcUaStackCore/Filter/AttributeFilterNode.h"
#include "OpcUaStackCore/Filter/SimpleAttributeFilterNode.h"
#include "OpcUaStackCore/Filter/LiteralFilterNode.h"

#include "OpcUaStackCore/Filter/ComparisonFilterNode.h"
#include "OpcUaStackCore/Filter/IsNullFilterNode.h"
#include "OpcUaStackCore/Filter/LikeFilterNode.h"
#include "OpcUaStackCore/Filter/NotFilterNode.h"
#include "OpcUaStackCore/Filter/BetweenFilterNode.h"
#include "OpcUaStackCore/Filter/InListFilterNode.h"
#include "OpcUaStackCore/Filter/LogicalOpFilterNode.h"
#include "OpcUaStackCore/Filter/CastFilterNode.h"
#include "OpcUaStackCore/Filter/BitwiseOpFilterNode.h"

namespace OpcUaStackCore
{

    FilterStack::FilterStack()
    : root_()
    , attributeIf_(nullptr)
    , simpleAttributeIf_(nullptr)
    {
        OpcUaVariant value;
        value.set<OpcUaBoolean>(true);
        root_ =  constructSPtr<LiteralFilterNode, OpcUaVariant>(value);
    }

    FilterStack::~FilterStack()
    {

    }

    void
	FilterStack::attributeIf(AttributeIf* attributeIf)
    {
    	attributeIf_ = attributeIf;
    }

    void
	FilterStack::simpleAttributeIf(SimpleAttributeIf* simpleAttributeIf)
    {
    	simpleAttributeIf_ = simpleAttributeIf;
    }

    bool
	FilterStack::receive(const ContentFilter& contentFilter, ContentFilterResult& contentFilterResult)
    {
    	contentFilterResult.elementResults()->resize(contentFilter.elements()->size());
        buildOperatorNode(contentFilter, contentFilterResult, 0, root_);

        // check if all statuses are success
        for (int i = 0; i < contentFilterResult.elementResults()->size(); ++i) {
        	ContentFilterElementResult::SPtr elementResult;
        	contentFilterResult.elementResults()->get(i, elementResult);

        	if (elementResult->statusCode() != OpcUaStatusCode::Success)
        		return false;

        	for (int j = 0; j < elementResult->operandStatusCodes()->size(); ++j) {
        		OpcUaStatusCode operandStatus;
        		elementResult->operandStatusCodes()->get(j, operandStatus);

        		if (operandStatus != OpcUaStatusCode::Success)
        			return false;
        	}
        }

        return true;
    }

    bool
	FilterStack::buildOperatorNode(const ContentFilter& contentFilter, ContentFilterResult& contentFilterResult,  int idx, FilterNode::SPtr& node)
    {

    	OpcUaStatusCode operatorStatus = OpcUaStatusCode::Success;

    	bool hasOperandError = false;

        ContentFilterElement::SPtr el;
        contentFilter.elements()->get(idx, el);

    	OpcUaStatusCodeArray::SPtr operandStatuses = constructSPtr<OpcUaStatusCodeArray>();
    	operandStatuses->resize(el->filterOperands()->size());

        std::vector<FilterNode::SPtr> args;
        for (int idxArg = 0; idxArg < el->filterOperands()->size(); ++idxArg) {
            ExtensibleParameter::SPtr operand;

            el->filterOperands()->get(idxArg, operand);

            uint32_t typeId;
            uint16_t nsIdx;
            operand->parameterTypeId().get(typeId, nsIdx);
            switch (typeId)
            {
            	case OpcUaId_LiteralOperand:
            	{
            		args.push_back(
                        constructSPtr<LiteralFilterNode, OpcUaVariant>(operand->parameter<LiteralOperand>()->value()));

            		operandStatuses->push_back(OpcUaStatusCode::Success);
            		break;
            	}
            	case OpcUaId_ElementOperand:
            	{
            		FilterNode::SPtr operatorNode;
            		uint32_t operatorIdx = operand->parameter<ElementOperand>()->index();

            		if (operatorIdx > idx) {

						if (buildOperatorNode(contentFilter, contentFilterResult, operatorIdx, operatorNode)) {
							operandStatuses->push_back(OpcUaStatusCode::Success);
						} else {
							operandStatuses->push_back(OpcUaStatusCode::BadFilterOperandInvalid);
							hasOperandError = true;
						}

						args.push_back(operatorNode);
            		} else {
            			operandStatuses->push_back(OpcUaStatusCode::BadFilterElementInvalid);
            			hasOperandError = true;
            		}
            		break;
            	}
            	case OpcUaId_AttributeOperand:
            	{
            	    AttributeOperand::SPtr attributeOperand = operand->parameter<AttributeOperand>();
            	    AttributeFilterNode::SPtr attributeNode(new AttributeFilterNode(
            	            *attributeOperand->nodeId(),
            	            attributeOperand->alias(),
            	            attributeOperand->browsePath(),
            	            attributeOperand->attributeId(),
            	            attributeOperand->indexRange()));

            	    attributeNode->attributeIf(attributeIf_);

            	    args.push_back(attributeNode);
            	    operandStatuses->push_back(OpcUaStatusCode::Success);
            		break;
            	}
            	case OpcUaId_SimpleAttributeOperand:
            	{
            	    SimpleAttributeOperand::SPtr simpleAttributeOperand = operand->parameter<SimpleAttributeOperand>();
            	    SimpleAttributeFilterNode::SPtr simpleAttributeNode(new SimpleAttributeFilterNode(
            	            simpleAttributeOperand->typeId(),
            	            *simpleAttributeOperand->browsePath(),
            	            simpleAttributeOperand->attributeId(),
            	            simpleAttributeOperand->indexRange()));

            	    simpleAttributeNode->simpleAttributeIf(simpleAttributeIf_);

            	    args.push_back(simpleAttributeNode);
            	    operandStatuses->push_back(OpcUaStatusCode::Success);
            		break;
            	}
            	default:
            	{
            		Log(Error, "unknown filter operand found")
            			.parameter("FilterOperand", operand->parameterTypeId());
            		operandStatuses->push_back(OpcUaStatusCode::BadTypeMismatch);
            		hasOperandError = true;
            		break;
            	}
        	}

        }

        ContentFilterElementResult::SPtr elementResult = constructSPtr<ContentFilterElementResult>();

        if (!hasOperandError) {
			switch (el->filterOperator()) {
				case BasicFilterOperator_IsNull:
				{
					node = IsNullFilterNode::SPtr(new IsNullFilterNode(args));
					operatorStatus = node->status();
					break;
				}
				case BasicFilterOperator_Equals:
				case BasicFilterOperator_GreaterThan:
				case BasicFilterOperator_LessThan:
				case BasicFilterOperator_GreaterThanOrEqual:
				case BasicFilterOperator_LessThanOrEqual:
				{
					node = ComparisonFilterNode::SPtr(new ComparisonFilterNode((OpcUaOperator)el->filterOperator(), args));
					operatorStatus = node->status();
					break;
				}
				case BasicFilterOperator_Like:
				{
					node = LikeFilterNode::SPtr(new LikeFilterNode(args));
					operatorStatus = node->status();
					break;
				}
				case BasicFilterOperator_Not:
				{
					node = NotFilterNode::SPtr(new NotFilterNode(args));
					operatorStatus = node->status();
					break;
				}
				case BasicFilterOperator_Between:
				{
					node = BetweenFilterNode::SPtr(new BetweenFilterNode(args));
					operatorStatus = node->status();
					break;
				}
				case BasicFilterOperator_InList:
				{
					node = InListFilterNode::SPtr(new InListFilterNode(args));
					operatorStatus = node->status();
					break;
				}
				case BasicFilterOperator_And:
				{
					node = LogicalOpFilterNode::SPtr(new LogicalOpFilterNode(OpcUaOperator::And, args));
					operatorStatus = node->status();
					break;
				}
				case BasicFilterOperator_Or:
				{
					node = LogicalOpFilterNode::SPtr(new LogicalOpFilterNode(OpcUaOperator::Or, args));
					operatorStatus = node->status();
					break;
				}
				case BasicFilterOperator_Cast:
				{
					node = CastFilterNode::SPtr(new CastFilterNode(args));
					operatorStatus = node->status();
					break;
				}
				case BasicFilterOperator_BitwiseAnd:
				{
					node = BitwiseOpFilterNode::SPtr(new BitwiseOpFilterNode(OpcUaOperator::BitwiseAnd, args));
					operatorStatus = node->status();
					break;
				}
				case BasicFilterOperator_BitwiseOr:
				{
					node = BitwiseOpFilterNode::SPtr(new BitwiseOpFilterNode(OpcUaOperator::BitwiseOr, args));
					operatorStatus = node->status();
					break;
				}
				default:
				{
					Log(Error, "filter operator is not supported")
											.parameter("FilterOperator", (uint32_t)el->filterOperator());
					operatorStatus = OpcUaStatusCode::BadFilterOperatorUnsupported;
					break;
				}
			}
        } else { // hasOperandError == true
        	elementResult->operandStatusCodes(operandStatuses);
        	operatorStatus = OpcUaStatusCode::BadFilterOperandInvalid;
        }


        elementResult->statusCode(operatorStatus);
        contentFilterResult.elementResults()->set(idx, elementResult);

        return operatorStatus == OpcUaStatusCode::Success;
    }

    bool
	FilterStack::process(bool& filterResult) const
    {
    	OpcUaVariant value;
    	if (!root_->evaluate(value)) {
    		return false;
    	}

    	OpcUaVariant boolValue;
    	OpcUaTypeConversion converter;
    	if (!converter.conversion(value, OpcUaBuildInType_OpcUaBoolean, boolValue)) {
    		return false;
    	}

		if (!boolValue.getValue(filterResult)) {
			return false;
		}

    	return true;
    }
}

