#ifndef OPCUASTACKCORE_FILTER_FILTEROPERATORHELPERS_H_
#define OPCUASTACKCORE_FILTER_FILTEROPERATORHELPERS_H_


#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"

#include "OpcUaStackCore/ServiceSet/AttributeOperand.h"
#include "OpcUaStackCore/ServiceSet/SimpleAttributeOperand.h"
#include "OpcUaStackCore/ServiceSet/ContentFilterElement.h"
#include "OpcUaStackCore/ServiceSet/ElementOperand.h"
#include "OpcUaStackCore/ServiceSet/EventFilter.h"
#include "OpcUaStackCore/ServiceSet/EventFilterResult.h"
#include "OpcUaStackCore/ServiceSet/LiteralOperand.h"

#include "OpcUaStackCore/Filter/LiteralFilterNode.h"

#include "OpcUaStackCore/Filter/FilterStack.h"

using namespace OpcUaStackCore;

class MockAttribute : public AttributeIf {
public:
    virtual bool getAttribute(
               OpcUaNodeId& typeId,
               OpcUaString& alias,
               RelativePath::SPtr& relativePath,
               OpcUaUInt32 attributeId,
               OpcUaString& numericRange,
               OpcUaVariant& value
           )
    {
        calledTypeId_ = typeId;
        calledAlias_ = alias;
        calledBrowsePath_ = relativePath;
        calledAttributeId_ = attributeId;
        calledNumericRange_ = numericRange;

        value = expectedValue_;

        return expectedResult_;
    }

    OpcUaNodeId calledTypeId_;
    OpcUaString calledAlias_;
    RelativePath::SPtr calledBrowsePath_;
    OpcUaUInt32 calledAttributeId_;
    OpcUaString calledNumericRange_;

    OpcUaVariant expectedValue_;
    OpcUaBoolean expectedResult_;

};

class MockSimpleAttribute : public SimpleAttributeIf {
public:
    virtual bool getAttribute(
        OpcUaNodeId& typeId,
        std::list<OpcUaQualifiedName::SPtr>& browsePath,
        OpcUaUInt32 attributeId,
        OpcUaString& numericRange,
        OpcUaVariant& value
    )
    {
        calledtypeId_ = typeId;
        calledBrowsePath_ = browsePath;
        calledAttributeId_ = attributeId;
        calledNumericRange_ = numericRange;

        value = expectedValue_;

        return expectedResult_;
    }

    OpcUaNodeId calledtypeId_;
    std::list<OpcUaQualifiedName::SPtr> calledBrowsePath_;
    OpcUaUInt32 calledAttributeId_;
    OpcUaString calledNumericRange_;

    OpcUaVariant expectedValue_;
    OpcUaBoolean expectedResult_;
};

template<typename T1, typename T2>
static ContentFilterElement::SPtr makeOperatorWith2LitteralOperands(BasicFilterOperator op, T1 arg1, T2 arg2)
{
    ContentFilterElement::SPtr eqElement = constructSPtr<ContentFilterElement>();

    ExtensibleParameter::SPtr arg1_ = constructSPtr<ExtensibleParameter>();
    arg1_->registerFactoryElement<LiteralOperand>((OpcUaUInt32)OpcUaId_LiteralOperand);
    arg1_->parameterTypeId().set((OpcUaUInt32)OpcUaId_LiteralOperand);
    arg1_->parameter<LiteralOperand>()->value().setValue(arg1);

    ExtensibleParameter::SPtr arg2_ = constructSPtr<ExtensibleParameter>();
    arg2_->registerFactoryElement<LiteralOperand>((OpcUaUInt32)OpcUaId_LiteralOperand);
    arg2_->parameterTypeId().set((OpcUaUInt32)OpcUaId_LiteralOperand);
    arg2_->parameter<LiteralOperand>()->value().setValue(arg2);

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
    arg2_->parameter<ElementOperand>()->index(idx2);

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

template<typename T>
static ContentFilterElement::SPtr makeOperatorWithAttributeAndLiteralOperands(BasicFilterOperator op, AttributeOperand arg1, T arg2)
{
    ContentFilterElement::SPtr eqElement = constructSPtr<ContentFilterElement>();

    ExtensibleParameter::SPtr arg1_ = constructSPtr<ExtensibleParameter>();
    arg1_->registerFactoryElement<AttributeOperand>((OpcUaUInt32)OpcUaId_AttributeOperand);
    arg1_->parameterTypeId().set((OpcUaUInt32)OpcUaId_AttributeOperand);
    AttributeOperand::SPtr attr = arg1_->parameter<AttributeOperand>();
    *attr = arg1;

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


template<typename T>
static ContentFilterElement::SPtr makeOperatorWithSimpleAttributeAndLiteralOperands(BasicFilterOperator op, SimpleAttributeOperand arg1, T arg2)
{
    ContentFilterElement::SPtr eqElement = constructSPtr<ContentFilterElement>();

    ExtensibleParameter::SPtr arg1_ = constructSPtr<ExtensibleParameter>();
    arg1_->registerFactoryElement<SimpleAttributeOperand>((OpcUaUInt32)OpcUaId_SimpleAttributeOperand);
    arg1_->parameterTypeId().set((OpcUaUInt32)OpcUaId_SimpleAttributeOperand);
    SimpleAttributeOperand::SPtr attr = arg1_->parameter<SimpleAttributeOperand>();
    *attr = arg1;

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
#define MAKE_ONE_LITERAL_ARG(args, arg1) do {\
	OpcUaVariant value;																\
	value.setValue(arg1);                                                           \
	args.push_back(constructSPtr<LiteralFilterNode, OpcUaVariant>(value));          \
} while(0)

#define MAKE_TWO_LITERAL_ARGS(args, arg1, arg2) do {\
	OpcUaVariant value;																\
	value.setValue(arg1);                                                           \
	args.push_back(constructSPtr<LiteralFilterNode, OpcUaVariant>(value));          \
                                                                                    \
	value.setValue(arg2);                                                           \
	args.push_back(constructSPtr<LiteralFilterNode, OpcUaVariant>(value));          \
} while(0)

#define MAKE_THREE_LITERAL_ARGS(args, arg1, arg2, arg3) do {\
	OpcUaVariant value;																\
	value.setValue(arg1);                                                           \
	args.push_back(constructSPtr<LiteralFilterNode, OpcUaVariant>(value));          \
                                                                                    \
	value.setValue(arg2);                                                           \
	args.push_back(constructSPtr<LiteralFilterNode, OpcUaVariant>(value));          \
                                                                                    \
	value.setValue(arg3);                                                           \
	args.push_back(constructSPtr<LiteralFilterNode, OpcUaVariant>(value));          \
} while(0)

#define MAKE_FOUR_LITERAL_ARGS(args, arg1, arg2, arg3, arg4) do {\
	OpcUaVariant value;																\
	value.setValue(arg1);                                                           \
	args.push_back(constructSPtr<LiteralFilterNode, OpcUaVariant>(value));          \
                                                                                    \
	value.setValue(arg2);                                                           \
	args.push_back(constructSPtr<LiteralFilterNode, OpcUaVariant>(value));          \
                                                                                    \
	value.setValue(arg3);                                                           \
	args.push_back(constructSPtr<LiteralFilterNode, OpcUaVariant>(value));          \
																					\
	value.setValue(arg4);                                                           \
	args.push_back(constructSPtr<LiteralFilterNode, OpcUaVariant>(value));          \
} while(0)

#endif /* OPCUASTACKSERVER_SERVICESET_FILTEROPERATORHELPERS_H_ */
