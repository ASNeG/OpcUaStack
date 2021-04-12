/*
   Copyright 2017-2021 Kai Huebl (kai@huebl-sgh.de)

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


#include <boost/make_shared.hpp>
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaTypeConversion.h"

#include "OpcUaStackCore/StandardDataTypes/LiteralOperand.h"
#include "OpcUaStackCore/StandardDataTypes/ElementOperand.h"
#include "OpcUaStackCore/StandardDataTypes/AttributeOperand.h"
#include "OpcUaStackCore/StandardDataTypes/ContentFilterElement.h"

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
        root_ =  boost::make_shared<LiteralFilterNode>(OpcUaVariant((OpcUaBoolean)true));
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
	FilterStack::receive(ContentFilter& contentFilter, ContentFilterResult& contentFilterResult)
    {
    	contentFilterResult.elementResults().resize(contentFilter.elements().size());
    	for (uint32_t idx=0; idx<contentFilter.elements().size(); idx++) {
    		buildOperatorNode(contentFilter, contentFilterResult, idx, root_);
    	}

        // check if all statuses are success
        for (int i = 0; i < contentFilterResult.elementResults().size(); ++i) {
        	ContentFilterElementResult::SPtr elementResult;
        	contentFilterResult.elementResults().get(i, elementResult);
        	assert(elementResult.get() != nullptr);

        	if (elementResult->statusCode().enumeration() != OpcUaStatusCode::Success)
        		return false;

        	for (int j = 0; j < elementResult->operandStatusCodes().size(); ++j) {
        		OpcUaStatus::SPtr operandStatus;
        		elementResult->operandStatusCodes().get(j, operandStatus);

        		if (operandStatus->enumeration() != OpcUaStatusCode::Success)
        			return false;
        	}
        }

        return true;
    }

    bool
	FilterStack::buildOperatorNode(ContentFilter& contentFilter, ContentFilterResult& contentFilterResult,  int idx, FilterNode::SPtr& node)
    {

    	OpcUaStatusCode operatorStatus = OpcUaStatusCode::Success;

    	bool hasOperandError = false;

        ContentFilterElement::SPtr el;
        contentFilter.elements().get(idx, el);

    	auto operandStatuses = boost::make_shared<OpcUaStatusCodeArray>();
    	operandStatuses->resize(el->filterOperands().size());

        std::vector<FilterNode::SPtr> args;
        for (int idxArg = 0; idxArg < el->filterOperands().size(); ++idxArg) {
            OpcUaExtensibleParameter::SPtr operand;

            el->filterOperands().get(idxArg, operand);

            uint32_t typeId;
            uint16_t nsIdx;
            operand->parameterTypeId().get(typeId, nsIdx);
            switch (typeId)
            {
            	case OpcUaId_LiteralOperand:
            	case OpcUaId_LiteralOperand_Encoding_DefaultBinary:
            	case OpcUaId_LiteralOperand_Encoding_DefaultXml:
            	{
            		OpcUaVariant value = operand->parameter<LiteralOperand>()->value();
            		args.push_back(boost::make_shared<LiteralFilterNode>(value));

            		operandStatuses->push_back(OpcUaStatusCode::Success);
            		break;
            	}
            	case OpcUaId_ElementOperand:
            	case OpcUaId_ElementOperand_Encoding_DefaultBinary:
            	case OpcUaId_ElementOperand_Encoding_DefaultXml:
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
            	case OpcUaId_AttributeOperand_Encoding_DefaultBinary:
            	case OpcUaId_AttributeOperand_Encoding_DefaultXml:
            	{
            	    AttributeOperand::SPtr attributeOperand = operand->parameter<AttributeOperand>();
            	    AttributeFilterNode::SPtr attributeNode(new AttributeFilterNode(
            	            attributeOperand->nodeId(),
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
            	case OpcUaId_SimpleAttributeOperand_Encoding_DefaultBinary:
            	case OpcUaId_SimpleAttributeOperand_Encoding_DefaultXml:
            	{
            	    SimpleAttributeOperand::SPtr simpleAttributeOperand = operand->parameter<SimpleAttributeOperand>();
            	    SimpleAttributeFilterNode::SPtr simpleAttributeNode(new SimpleAttributeFilterNode(
            	            simpleAttributeOperand->typeId(),
            	            simpleAttributeOperand->browsePath(),
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

        ContentFilterElementResult::SPtr elementResult = boost::make_shared<ContentFilterElementResult>();

        if (!hasOperandError) {
			switch (el->filterOperator().enumeration()) {
				case FilterOperator::EnumIsNull:
				{
					node = IsNullFilterNode::SPtr(new IsNullFilterNode(args));
					operatorStatus = node->status();
					break;
				}
				case FilterOperator::EnumEquals:
				case FilterOperator::EnumGreaterThan:
				case FilterOperator::EnumLessThan:
				case FilterOperator::EnumGreaterThanOrEqual:
				case FilterOperator::EnumLessThanOrEqual:
				{
					node = ComparisonFilterNode::SPtr(new ComparisonFilterNode(el->filterOperator().enumeration(), args));
					operatorStatus = node->status();
					break;
				}
				case FilterOperator::EnumLike:
				{
					node = LikeFilterNode::SPtr(new LikeFilterNode(args));
					operatorStatus = node->status();
					break;
				}
				case FilterOperator::EnumNot:
				{
					node = NotFilterNode::SPtr(new NotFilterNode(args));
					operatorStatus = node->status();
					break;
				}
				case FilterOperator::EnumBetween:
				{
					node = BetweenFilterNode::SPtr(new BetweenFilterNode(args));
					operatorStatus = node->status();
					break;
				}
				case FilterOperator::EnumInList:
				{
					node = InListFilterNode::SPtr(new InListFilterNode(args));
					operatorStatus = node->status();
					break;
				}
				case FilterOperator::EnumAnd:
				{
					node = LogicalOpFilterNode::SPtr(new LogicalOpFilterNode(OpcUaOperator::And, args));
					operatorStatus = node->status();
					break;
				}
				case FilterOperator::EnumOr:
				{
					node = LogicalOpFilterNode::SPtr(new LogicalOpFilterNode(OpcUaOperator::Or, args));
					operatorStatus = node->status();
					break;
				}
				case FilterOperator::EnumCast:
				{
					node = CastFilterNode::SPtr(new CastFilterNode(args));
					operatorStatus = node->status();
					break;
				}
				case FilterOperator::EnumBitwiseAnd:
				{
					node = BitwiseOpFilterNode::SPtr(new BitwiseOpFilterNode(OpcUaOperator::BitwiseAnd, args));
					operatorStatus = node->status();
					break;
				}
				case FilterOperator::EnumBitwiseOr:
				{
					node = BitwiseOpFilterNode::SPtr(new BitwiseOpFilterNode(OpcUaOperator::BitwiseOr, args));
					operatorStatus = node->status();
					break;
				}
				default:
				{
					Log(Error, "filter operator is not supported")
						.parameter("FilterOperator", (uint32_t)el->filterOperator().enumeration());
					operatorStatus = OpcUaStatusCode::BadFilterOperatorUnsupported;
					break;
				}
			}
        } else { // hasOperandError == true
        	elementResult->operandStatusCodes().resize(operandStatuses->size());
        	for (uint32_t j = 0; j < operandStatuses->size(); j++) {
        		OpcUaStatusCode statusCode;
        		operandStatuses->get(j, statusCode);
        		OpcUaStatus::SPtr status = boost::make_shared<OpcUaStatus>();
        		status->enumeration(statusCode);
        		elementResult->operandStatusCodes().push_back(status);
        	}
        	operatorStatus = OpcUaStatusCode::BadFilterOperandInvalid;
        }


        elementResult->statusCode().enumeration(operatorStatus);
        contentFilterResult.elementResults().set(idx, elementResult);

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

