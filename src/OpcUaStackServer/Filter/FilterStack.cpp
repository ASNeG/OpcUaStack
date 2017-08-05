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

#include "OpcUaStackServer/Filter/FilterStack.h"
#include "OpcUaStackServer/Filter/LiteralFilterNode.h"
#include "OpcUaStackServer/Filter/EqualsFilterNode.h"

namespace OpcUaStackServer
{
    FilterStack::FilterStack()
    {
        OpcUaVariant value;
        value.set<OpcUaBoolean>(true);
        root_ =  constructSPtr<LiteralFilterNode, OpcUaVariant>(value);
    }

    FilterStack::~FilterStack()
    {

    }

    OpcUaStatusCode FilterStack::receive(const ContentFilter& contentFilter, ContentFilterResult& contentFilterResult)
    {
        buildOperatorNode(contentFilter, 0, root_);
        return OpcUaStatusCode::Success;
    }

    OpcUaStatusCode FilterStack::buildOperatorNode(const ContentFilter& contentFilter, int idx, FilterNode::SPtr& node)
    {
        ContentFilterElement::SPtr el;
        contentFilter.elements()->get(idx, el);

        std::vector<FilterNode::SPtr> args;

        for (int idxArg = 0; idxArg < el->filterOperands()->size(); ++idxArg) {
            ExtensibleParameter::SPtr operand;

            el->filterOperands()->get(idxArg, operand);

            uint32_t typeId;
            uint16_t nsIdx;
            operand->parameterTypeId().get(typeId, nsIdx);
            switch (typeId) {
            case OpcUaId_LiteralOperand:
                args.push_back(
                        constructSPtr<LiteralFilterNode, OpcUaVariant>(operand->parameter<LiteralOperand>()->value()));
                break;

            case OpcUaId_ElementOperand:
                FilterNode::SPtr operator_;
                uint32_t operatorIdx = operand->parameter<ElementOperand>()->index();

                buildOperatorNode(contentFilter, operatorIdx, operator_);

                args.push_back(operator_);
                break;
            }


        }

        switch (el->filterOperator()) {
            case BasicFilterOperator_Equals: {
                node = EqualsFilterNode::SPtr(new EqualsFilterNode(args));
                break;
            }
        }

        return OpcUaStatusCode::Success;

    }
    bool FilterStack::process() const
    {
        return root_->evaluate().get<OpcUaBoolean>();
    }
}
