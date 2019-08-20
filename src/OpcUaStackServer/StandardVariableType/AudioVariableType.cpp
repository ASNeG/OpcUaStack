/*
    VariableTypeClass: AudioVariableType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardVariableType/AudioVariableType.h"

namespace OpcUaStackServer
{
    
    AudioVariableType::AudioVariableType(void)
    : VariableBase()
    , agencyId_Variable_(boost::make_shared<ServerVariable>("AgencyId_Variable"))
    , listId_Variable_(boost::make_shared<ServerVariable>("ListId_Variable"))
    , variable_(boost::make_shared<ServerVariable>("Variable"))
    , versionId_Variable_(boost::make_shared<ServerVariable>("VersionId_Variable"))
    {
        variableTypeNamespaceName("http://opcfoundation.org/UA/");
        variableTypeNodeId((OpcUaUInt32)17986);
        setServerVariable(agencyId_Variable_);
        setServerVariable(listId_Variable_);
        setServerVariable(variable_);
        setServerVariable(versionId_Variable_);
    }
    
    AudioVariableType::AudioVariableType(const AudioVariableType& value)
    : VariableBase()
    , agencyId_Variable_(boost::make_shared<ServerVariable>("AgencyId_Variable"))
    , listId_Variable_(boost::make_shared<ServerVariable>("ListId_Variable"))
    , variable_(boost::make_shared<ServerVariable>("Variable"))
    , versionId_Variable_(boost::make_shared<ServerVariable>("VersionId_Variable"))
    {
        variableTypeNamespaceName("http://opcfoundation.org/UA/");
        variableTypeNodeId((OpcUaUInt32)17986);
        setServerVariable(agencyId_Variable_);
        setServerVariable(listId_Variable_);
        setServerVariable(variable_);
        setServerVariable(versionId_Variable_);
    }
    
    AudioVariableType::~AudioVariableType(void)
    {
    }

    ServerVariable::SPtr&
    AudioVariableType::agencyId_Variable(void)
    {
        return agencyId_Variable_;
    }

    ServerVariable::SPtr&
    AudioVariableType::listId_Variable(void)
    {
        return listId_Variable_;
    }

    ServerVariable::SPtr&
    AudioVariableType::variable(void)
    {
        return variable_;
    }

    ServerVariable::SPtr&
    AudioVariableType::versionId_Variable(void)
    {
        return versionId_Variable_;
    }

    void
    AudioVariableType::agencyId_Variable(ServerVariable::SPtr& serverVariable)
    {
        agencyId_Variable_ = serverVariable;
    }

    void
    AudioVariableType::listId_Variable(ServerVariable::SPtr& serverVariable)
    {
        listId_Variable_ = serverVariable;
    }

    void
    AudioVariableType::variable(ServerVariable::SPtr& serverVariable)
    {
        variable_ = serverVariable;
    }

    void
    AudioVariableType::versionId_Variable(ServerVariable::SPtr& serverVariable)
    {
        versionId_Variable_ = serverVariable;
    }

    bool
    AudioVariableType::get_AgencyId_Variable(OpcUaDataValue& dataValue)
    {
        return agencyId_Variable_->getDataValue(dataValue);
    }

    bool
    AudioVariableType::get_ListId_Variable(OpcUaDataValue& dataValue)
    {
        return listId_Variable_->getDataValue(dataValue);
    }

    bool
    AudioVariableType::get_Variable(OpcUaDataValue& dataValue)
    {
        return variable_->getDataValue(dataValue);
    }

    bool
    AudioVariableType::get_VersionId_Variable(OpcUaDataValue& dataValue)
    {
        return versionId_Variable_->getDataValue(dataValue);
    }

    bool
    AudioVariableType::set_AgencyId_Variable(const OpcUaDataValue& dataValue)
    {
        return agencyId_Variable_->setDataValue(dataValue);
    }

    bool
    AudioVariableType::set_ListId_Variable(const OpcUaDataValue& dataValue)
    {
        return listId_Variable_->setDataValue(dataValue);
    }

    bool
    AudioVariableType::set_Variable(const OpcUaDataValue& dataValue)
    {
        return variable_->setDataValue(dataValue);
    }

    bool
    AudioVariableType::set_VersionId_Variable(const OpcUaDataValue& dataValue)
    {
        return versionId_Variable_->setDataValue(dataValue);
    }

}
