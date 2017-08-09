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
#include "OpcUaStackCore/ServiceSet/LiteralOperand.h"
#include "OpcUaStackCore/ServiceSet/ElementOperand.h"
#include "OpcUaStackCore/ServiceSet/AttributeOperand.h"

#include "OpcUaStackCore/Filter/FilterStack.h"
#include "OpcUaStackCore/Filter/AttributeFilterNode.h"
#include "OpcUaStackCore/Filter/SimpleAttributeFilterNode.h"
#include "OpcUaStackCore/Filter/LiteralFilterNode.h"
#include "OpcUaStackCore/Filter/EqualsFilterNode.h"

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

    OpcUaStatusCode
	FilterStack::receive(const ContentFilter& contentFilter, ContentFilterResult& contentFilterResult)
    {
    	contentFilterResult.elementResults()->resize(contentFilter.elements()->size());
        return buildOperatorNode(contentFilter, contentFilterResult, 0, root_);
    }

    OpcUaStatusCode
	FilterStack::buildOperatorNode(const ContentFilter& contentFilter, ContentFilterResult& contentFilterResult,  int idx, FilterNode::SPtr& node)
    {

    	OpcUaStatusCode elementStatus = OpcUaStatusCode::Success;

        ContentFilterElement::SPtr el;
        contentFilter.elements()->get(idx, el);

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
            		break;
            	}
            	case OpcUaId_ElementOperand:
            	{
            		FilterNode::SPtr operatorNode;
            		uint32_t operatorIdx = operand->parameter<ElementOperand>()->index();

            		//FIXME: Needs checking index to avoid an endless cycle
            		buildOperatorNode(contentFilter, contentFilterResult, operatorIdx, operatorNode);

            		args.push_back(operatorNode);
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
            		break;
            	}
            	default:
            	{
            		Log(Error, "unknown filter operand found")
            			.parameter("FilterOperand", operand->parameterTypeId());
            		return BadTypeMismatch;
            	}
        	}

        }

        switch (el->filterOperator()) {
            case BasicFilterOperator_Equals:
            {
                node = EqualsFilterNode::SPtr(new EqualsFilterNode(args));
                elementStatus = node->status();
                break;
            }

            case BasicFilterOperator_IsNull:
			case BasicFilterOperator_GreaterThan:
			case BasicFilterOperator_LessThan:
			case BasicFilterOperator_GreaterThanOrEqual:
			case BasicFilterOperator_LassThanOrEqual:
			case BasicFilterOperator_Like:
			case BasicFilterOperator_Not:
			case BasicFilterOperator_Between:
			case BasicFilterOperator_InList:
			case BasicFilterOperator_And:
			case BasicFilterOperator_Or:
			case BasicFilterOperator_Cast:
			case BasicFilterOperator_BitwiseAnd:
			case BasicFilterOperator_BitwiseOr:
			{
				Log(Error, "filter operator is not supported")
			        			.parameter("FilterOperator", (uint32_t)el->filterOperator());
				elementStatus = OpcUaStatusCode::BadFilterOperatorUnsupported;
				break;
			}
        	default:
        	{
        		Log(Error, "unknown filter operator found")
        			.parameter("FilterOperator", (uint32_t)el->filterOperator());
        		elementStatus = BadFilterOperatorInvalid;
        	}
        }

        ContentFilterElementResult::SPtr elementResult = constructSPtr<ContentFilterElementResult>();
        elementResult->statusCode(elementStatus);

        contentFilterResult.elementResults()->set(idx, elementResult);

        return elementStatus;

    }

    bool
	FilterStack::process(bool& filterResult) const
    {
    	OpcUaVariant value;
    	if (!root_->evaluate(value)) {
    		return false;
    	}

    	// FIXME: type conversion

    	if (!value.getValue(filterResult)) {
    		return false;
    	}

    	return true;
    }
}
