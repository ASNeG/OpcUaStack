#ifndef OPCUASTACKSERVER_SERVICESET_FILTEROPERATORHELPERS_H_
#define OPCUASTACKSERVER_SERVICESET_FILTEROPERATORHELPERS_H_

#include "OpcUaStackServer/ServiceSet/FilterStack.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackCore/ServiceSet/LiteralOperand.h"
#include "OpcUaStackCore/ServiceSet/ElementOperand.h"

template<typename T1, typename T2>
static ContentFilterElement::SPtr makeOperatorWith2LitteralOperands(BasicFilterOperator op, T1 arg1, T2 arg2)
{
    ContentFilterElement::SPtr eqElement = constructSPtr<ContentFilterElement>();

    ExtensibleParameter::SPtr arg1_ = constructSPtr<ExtensibleParameter>();
    arg1_->registerFactoryElement<LiteralOperand>((OpcUaUInt32)OpcUaId_LiteralOperand);
    arg1_->parameterTypeId().set((OpcUaUInt32)OpcUaId_LiteralOperand);
    arg1_->parameter<LiteralOperand>()->value().set<T1>(arg1);

    ExtensibleParameter::SPtr arg2_ = constructSPtr<ExtensibleParameter>();
    arg2_->registerFactoryElement<LiteralOperand>((OpcUaUInt32)OpcUaId_LiteralOperand);
    arg2_->parameterTypeId().set((OpcUaUInt32)OpcUaId_LiteralOperand);
    arg2_->parameter<LiteralOperand>()->value().set<T2>(arg2);

    eqElement->filterOperator(op);
    eqElement->filterOperands()->resize(2);
    eqElement->filterOperands()->push_back(arg1_);
    eqElement->filterOperands()->push_back(arg2_);

    return eqElement;
}


static ContentFilterElement::SPtr makeOperatorWith2ElementOperands(BasicFilterOperator op, int idx1, int idx2)
{
    ContentFilterElement::SPtr eqElement = constructSPtr<ContentFilterElement>();

    ExtensibleParameter::SPtr arg1_ = constructSPtr<ExtensibleParameter>();
    arg1_->registerFactoryElement<ElementOperand>((OpcUaUInt32)OpcUaId_ElementOperand);
    arg1_->parameterTypeId().set((OpcUaUInt32)OpcUaId_ElementOperand);
    arg1_->parameter<ElementOperand>()->index(idx1);

    ExtensibleParameter::SPtr arg2_ = constructSPtr<ExtensibleParameter>();
    arg2_->registerFactoryElement<ElementOperand>((OpcUaUInt32)OpcUaId_ElementOperand);
    arg2_->parameterTypeId().set((OpcUaUInt32)OpcUaId_ElementOperand);
    arg2_->parameter<ElementOperand>()->index(idx1);

    eqElement->filterOperator(op);
    eqElement->filterOperands()->resize(2);
    eqElement->filterOperands()->push_back(arg1_);
    eqElement->filterOperands()->push_back(arg2_);

    return eqElement;
}

template<typename T>
static ContentFilterElement::SPtr makeOperatorWithElementAndLiteralOperands(BasicFilterOperator op, int idx1, T arg2)
{
    ContentFilterElement::SPtr eqElement = constructSPtr<ContentFilterElement>();

    ExtensibleParameter::SPtr arg1_ = constructSPtr<ExtensibleParameter>();
    arg1_->registerFactoryElement<ElementOperand>((OpcUaUInt32)OpcUaId_ElementOperand);
    arg1_->parameterTypeId().set((OpcUaUInt32)OpcUaId_ElementOperand);
    arg1_->parameter<ElementOperand>()->index(idx1);

    ExtensibleParameter::SPtr arg2_ = constructSPtr<ExtensibleParameter>();
    arg2_->registerFactoryElement<LiteralOperand>((OpcUaUInt32)OpcUaId_LiteralOperand);
    arg2_->parameterTypeId().set((OpcUaUInt32)OpcUaId_LiteralOperand);
    arg2_->parameter<LiteralOperand>()->value().set<T>(arg2);

    eqElement->filterOperator(op);
    eqElement->filterOperands()->resize(2);
    eqElement->filterOperands()->push_back(arg1_);
    eqElement->filterOperands()->push_back(arg2_);

    return eqElement;
}


#endif /* OPCUASTACKSERVER_SERVICESET_FILTEROPERATORHELPERS_H_ */
