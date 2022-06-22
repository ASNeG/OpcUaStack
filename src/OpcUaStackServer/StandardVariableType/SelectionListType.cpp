/*
    VariableTypeClass: SelectionListType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardVariableType/SelectionListType.h"
using namespace OpcUaStackCore;

namespace OpcUaStackServer
{
    
    SelectionListType::SelectionListType(void)
    : VariableBase()
    , restrictToList_Variable_(boost::make_shared<ServerVariable>("RestrictToList_Variable"))
    , selectionDescriptions_Variable_(boost::make_shared<ServerVariable>("SelectionDescriptions_Variable"))
    , selections_Variable_(boost::make_shared<ServerVariable>("Selections_Variable"))
    , variable_(boost::make_shared<ServerVariable>("Variable"))
    {
        variableTypeNamespaceName("http://opcfoundation.org/UA/");
        variableTypeNodeId((OpcUaUInt32)16309);
        setServerVariable(restrictToList_Variable_);
        setServerVariable(selectionDescriptions_Variable_);
        setServerVariable(selections_Variable_);
        setServerVariable(variable_);
    }
    
    SelectionListType::SelectionListType(const SelectionListType& value)
    : VariableBase()
    , restrictToList_Variable_(boost::make_shared<ServerVariable>("RestrictToList_Variable"))
    , selectionDescriptions_Variable_(boost::make_shared<ServerVariable>("SelectionDescriptions_Variable"))
    , selections_Variable_(boost::make_shared<ServerVariable>("Selections_Variable"))
    , variable_(boost::make_shared<ServerVariable>("Variable"))
    {
        variableTypeNamespaceName("http://opcfoundation.org/UA/");
        variableTypeNodeId((OpcUaUInt32)16309);
        setServerVariable(restrictToList_Variable_);
        setServerVariable(selectionDescriptions_Variable_);
        setServerVariable(selections_Variable_);
        setServerVariable(variable_);
    }
    
    SelectionListType::~SelectionListType(void)
    {
    }

    ServerVariable::SPtr&
    SelectionListType::restrictToList_Variable(void)
    {
        return restrictToList_Variable_;
    }

    ServerVariable::SPtr&
    SelectionListType::selectionDescriptions_Variable(void)
    {
        return selectionDescriptions_Variable_;
    }

    ServerVariable::SPtr&
    SelectionListType::selections_Variable(void)
    {
        return selections_Variable_;
    }

    ServerVariable::SPtr&
    SelectionListType::variable(void)
    {
        return variable_;
    }

    void
    SelectionListType::restrictToList_Variable(ServerVariable::SPtr& serverVariable)
    {
        restrictToList_Variable_ = serverVariable;
    }

    void
    SelectionListType::selectionDescriptions_Variable(ServerVariable::SPtr& serverVariable)
    {
        selectionDescriptions_Variable_ = serverVariable;
    }

    void
    SelectionListType::selections_Variable(ServerVariable::SPtr& serverVariable)
    {
        selections_Variable_ = serverVariable;
    }

    void
    SelectionListType::variable(ServerVariable::SPtr& serverVariable)
    {
        variable_ = serverVariable;
    }

    bool
    SelectionListType::get_RestrictToList_Variable(OpcUaDataValue& dataValue)
    {
        return restrictToList_Variable_->getDataValue(dataValue);
    }

    bool
    SelectionListType::get_SelectionDescriptions_Variable(OpcUaDataValue& dataValue)
    {
        return selectionDescriptions_Variable_->getDataValue(dataValue);
    }

    bool
    SelectionListType::get_Selections_Variable(OpcUaDataValue& dataValue)
    {
        return selections_Variable_->getDataValue(dataValue);
    }

    bool
    SelectionListType::get_Variable(OpcUaDataValue& dataValue)
    {
        return variable_->getDataValue(dataValue);
    }

    bool
    SelectionListType::set_RestrictToList_Variable(const OpcUaDataValue& dataValue)
    {
        return restrictToList_Variable_->setDataValue(dataValue);
    }

    bool
    SelectionListType::set_SelectionDescriptions_Variable(const OpcUaDataValue& dataValue)
    {
        return selectionDescriptions_Variable_->setDataValue(dataValue);
    }

    bool
    SelectionListType::set_Selections_Variable(const OpcUaDataValue& dataValue)
    {
        return selections_Variable_->setDataValue(dataValue);
    }

    bool
    SelectionListType::set_Variable(const OpcUaDataValue& dataValue)
    {
        return variable_->setDataValue(dataValue);
    }

}
