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

#include "OpcUaStackServer/ServiceSet/FilterStack.h"

#include "OpcUaStackServer/ServiceSet/LiteralFilterNode.h"
#include "OpcUaStackServer/ServiceSet/EqualsFilterNode.h"

#include "OpcUaStackCore/ServiceSet/LiteralOperand.h"


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

    OpcUaStatusCode FilterStack::receive(const ContentFilter& contentFilter, ContentFilterResult::SPtr contentilterResult)
    {
        //TODO: should work for many elements recursively
        ContentFilterElement::SPtr el;
        contentFilter.elements()->get(0, el);

        switch (el->filterOperator()) {
        case BasicFilterOperator_Equals: {

            //TODO: check args
            ExtensibleParameter::SPtr op1;
            el->filterOperands()->get(0, op1);
            FilterNode::SPtr arg1 = constructSPtr<LiteralFilterNode, OpcUaVariant>(op1->parameter<LiteralOperand>()->value());


            ExtensibleParameter::SPtr op2;
            el->filterOperands()->get(1, op2);
            FilterNode::SPtr arg2 = constructSPtr<LiteralFilterNode, OpcUaVariant>(op2->parameter<LiteralOperand>()->value());


            root_ = EqualsFilterNode::SPtr(new EqualsFilterNode(arg1, arg2));
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
