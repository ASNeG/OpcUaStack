/*
    VariableTypeClass: NamespaceMetadataType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardObjectType/NamespaceMetadataType.h"

namespace OpcUaStackServer
{
    
    /**
     * Provides the metadata for a namespace used by the server.
     */
    NamespaceMetadataType::NamespaceMetadataType(void)
    : ObjectBase()
    , defaultAccessRestrictions_Variable_(boost::make_shared<ServerVariable>("DefaultAccessRestrictions_Variable"))
    , defaultRolePermissions_Variable_(boost::make_shared<ServerVariable>("DefaultRolePermissions_Variable"))
    , defaultUserRolePermissions_Variable_(boost::make_shared<ServerVariable>("DefaultUserRolePermissions_Variable"))
    , isNamespaceSubset_Variable_(boost::make_shared<ServerVariable>("IsNamespaceSubset_Variable"))
    , namespaceFile_OpenCount_Variable_(boost::make_shared<ServerVariable>("NamespaceFile_OpenCount_Variable"))
    , namespaceFile_Size_Variable_(boost::make_shared<ServerVariable>("NamespaceFile_Size_Variable"))
    , namespaceFile_UserWritable_Variable_(boost::make_shared<ServerVariable>("NamespaceFile_UserWritable_Variable"))
    , namespaceFile_Writable_Variable_(boost::make_shared<ServerVariable>("NamespaceFile_Writable_Variable"))
    , namespacePublicationDate_Variable_(boost::make_shared<ServerVariable>("NamespacePublicationDate_Variable"))
    , namespaceUri_Variable_(boost::make_shared<ServerVariable>("NamespaceUri_Variable"))
    , namespaceVersion_Variable_(boost::make_shared<ServerVariable>("NamespaceVersion_Variable"))
    , staticNodeIdTypes_Variable_(boost::make_shared<ServerVariable>("StaticNodeIdTypes_Variable"))
    , staticNumericNodeIdRange_Variable_(boost::make_shared<ServerVariable>("StaticNumericNodeIdRange_Variable"))
    , staticStringNodeIdPattern_Variable_(boost::make_shared<ServerVariable>("StaticStringNodeIdPattern_Variable"))
    , namespaceFile_Close_Method_(boost::make_shared<ServerMethod>("NamespaceFile_Close_Method"))
    , namespaceFile_GetPosition_Method_(boost::make_shared<ServerMethod>("NamespaceFile_GetPosition_Method"))
    , namespaceFile_Open_Method_(boost::make_shared<ServerMethod>("NamespaceFile_Open_Method"))
    , namespaceFile_Read_Method_(boost::make_shared<ServerMethod>("NamespaceFile_Read_Method"))
    , namespaceFile_SetPosition_Method_(boost::make_shared<ServerMethod>("NamespaceFile_SetPosition_Method"))
    , namespaceFile_Write_Method_(boost::make_shared<ServerMethod>("NamespaceFile_Write_Method"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)11616);
        setServerVariable(defaultAccessRestrictions_Variable_);
        setServerVariable(defaultRolePermissions_Variable_);
        setServerVariable(defaultUserRolePermissions_Variable_);
        setServerVariable(isNamespaceSubset_Variable_);
        setServerVariable(namespaceFile_OpenCount_Variable_);
        setServerVariable(namespaceFile_Size_Variable_);
        setServerVariable(namespaceFile_UserWritable_Variable_);
        setServerVariable(namespaceFile_Writable_Variable_);
        setServerVariable(namespacePublicationDate_Variable_);
        setServerVariable(namespaceUri_Variable_);
        setServerVariable(namespaceVersion_Variable_);
        setServerVariable(staticNodeIdTypes_Variable_);
        setServerVariable(staticNumericNodeIdRange_Variable_);
        setServerVariable(staticStringNodeIdPattern_Variable_);
        setServerMethod(namespaceFile_Close_Method_);
        setServerMethod(namespaceFile_GetPosition_Method_);
        setServerMethod(namespaceFile_Open_Method_);
        setServerMethod(namespaceFile_Read_Method_);
        setServerMethod(namespaceFile_SetPosition_Method_);
        setServerMethod(namespaceFile_Write_Method_);
        namespaceFile_Close_Method_->registerMethod(boost::bind(&NamespaceMetadataType::call_NamespaceFile_Close_Method, this, _1));
        namespaceFile_GetPosition_Method_->registerMethod(boost::bind(&NamespaceMetadataType::call_NamespaceFile_GetPosition_Method, this, _1));
        namespaceFile_Open_Method_->registerMethod(boost::bind(&NamespaceMetadataType::call_NamespaceFile_Open_Method, this, _1));
        namespaceFile_Read_Method_->registerMethod(boost::bind(&NamespaceMetadataType::call_NamespaceFile_Read_Method, this, _1));
        namespaceFile_SetPosition_Method_->registerMethod(boost::bind(&NamespaceMetadataType::call_NamespaceFile_SetPosition_Method, this, _1));
        namespaceFile_Write_Method_->registerMethod(boost::bind(&NamespaceMetadataType::call_NamespaceFile_Write_Method, this, _1));
    }
    
    /**
     * Provides the metadata for a namespace used by the server.
     */
    NamespaceMetadataType::NamespaceMetadataType(const NamespaceMetadataType& value)
    : ObjectBase()
    , defaultAccessRestrictions_Variable_(boost::make_shared<ServerVariable>("DefaultAccessRestrictions_Variable"))
    , defaultRolePermissions_Variable_(boost::make_shared<ServerVariable>("DefaultRolePermissions_Variable"))
    , defaultUserRolePermissions_Variable_(boost::make_shared<ServerVariable>("DefaultUserRolePermissions_Variable"))
    , isNamespaceSubset_Variable_(boost::make_shared<ServerVariable>("IsNamespaceSubset_Variable"))
    , namespaceFile_OpenCount_Variable_(boost::make_shared<ServerVariable>("NamespaceFile_OpenCount_Variable"))
    , namespaceFile_Size_Variable_(boost::make_shared<ServerVariable>("NamespaceFile_Size_Variable"))
    , namespaceFile_UserWritable_Variable_(boost::make_shared<ServerVariable>("NamespaceFile_UserWritable_Variable"))
    , namespaceFile_Writable_Variable_(boost::make_shared<ServerVariable>("NamespaceFile_Writable_Variable"))
    , namespacePublicationDate_Variable_(boost::make_shared<ServerVariable>("NamespacePublicationDate_Variable"))
    , namespaceUri_Variable_(boost::make_shared<ServerVariable>("NamespaceUri_Variable"))
    , namespaceVersion_Variable_(boost::make_shared<ServerVariable>("NamespaceVersion_Variable"))
    , staticNodeIdTypes_Variable_(boost::make_shared<ServerVariable>("StaticNodeIdTypes_Variable"))
    , staticNumericNodeIdRange_Variable_(boost::make_shared<ServerVariable>("StaticNumericNodeIdRange_Variable"))
    , staticStringNodeIdPattern_Variable_(boost::make_shared<ServerVariable>("StaticStringNodeIdPattern_Variable"))
    , namespaceFile_Close_Method_(boost::make_shared<ServerMethod>("NamespaceFile_Close_Method"))
    , namespaceFile_GetPosition_Method_(boost::make_shared<ServerMethod>("NamespaceFile_GetPosition_Method"))
    , namespaceFile_Open_Method_(boost::make_shared<ServerMethod>("NamespaceFile_Open_Method"))
    , namespaceFile_Read_Method_(boost::make_shared<ServerMethod>("NamespaceFile_Read_Method"))
    , namespaceFile_SetPosition_Method_(boost::make_shared<ServerMethod>("NamespaceFile_SetPosition_Method"))
    , namespaceFile_Write_Method_(boost::make_shared<ServerMethod>("NamespaceFile_Write_Method"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)11616);
        setServerVariable(defaultAccessRestrictions_Variable_);
        setServerVariable(defaultRolePermissions_Variable_);
        setServerVariable(defaultUserRolePermissions_Variable_);
        setServerVariable(isNamespaceSubset_Variable_);
        setServerVariable(namespaceFile_OpenCount_Variable_);
        setServerVariable(namespaceFile_Size_Variable_);
        setServerVariable(namespaceFile_UserWritable_Variable_);
        setServerVariable(namespaceFile_Writable_Variable_);
        setServerVariable(namespacePublicationDate_Variable_);
        setServerVariable(namespaceUri_Variable_);
        setServerVariable(namespaceVersion_Variable_);
        setServerVariable(staticNodeIdTypes_Variable_);
        setServerVariable(staticNumericNodeIdRange_Variable_);
        setServerVariable(staticStringNodeIdPattern_Variable_);
        setServerMethod(namespaceFile_Close_Method_);
        setServerMethod(namespaceFile_GetPosition_Method_);
        setServerMethod(namespaceFile_Open_Method_);
        setServerMethod(namespaceFile_Read_Method_);
        setServerMethod(namespaceFile_SetPosition_Method_);
        setServerMethod(namespaceFile_Write_Method_);
        namespaceFile_Close_Method_->registerMethod(boost::bind(&NamespaceMetadataType::call_NamespaceFile_Close_Method, this, _1));
        namespaceFile_GetPosition_Method_->registerMethod(boost::bind(&NamespaceMetadataType::call_NamespaceFile_GetPosition_Method, this, _1));
        namespaceFile_Open_Method_->registerMethod(boost::bind(&NamespaceMetadataType::call_NamespaceFile_Open_Method, this, _1));
        namespaceFile_Read_Method_->registerMethod(boost::bind(&NamespaceMetadataType::call_NamespaceFile_Read_Method, this, _1));
        namespaceFile_SetPosition_Method_->registerMethod(boost::bind(&NamespaceMetadataType::call_NamespaceFile_SetPosition_Method, this, _1));
        namespaceFile_Write_Method_->registerMethod(boost::bind(&NamespaceMetadataType::call_NamespaceFile_Write_Method, this, _1));
    }
    
    NamespaceMetadataType::~NamespaceMetadataType(void)
    {
    }

    ServerVariable::SPtr&
    NamespaceMetadataType::defaultAccessRestrictions_Variable(void)
    {
        return defaultAccessRestrictions_Variable_;
    }

    ServerVariable::SPtr&
    NamespaceMetadataType::defaultRolePermissions_Variable(void)
    {
        return defaultRolePermissions_Variable_;
    }

    ServerVariable::SPtr&
    NamespaceMetadataType::defaultUserRolePermissions_Variable(void)
    {
        return defaultUserRolePermissions_Variable_;
    }

    ServerVariable::SPtr&
    NamespaceMetadataType::isNamespaceSubset_Variable(void)
    {
        return isNamespaceSubset_Variable_;
    }

    ServerVariable::SPtr&
    NamespaceMetadataType::namespaceFile_OpenCount_Variable(void)
    {
        return namespaceFile_OpenCount_Variable_;
    }

    ServerVariable::SPtr&
    NamespaceMetadataType::namespaceFile_Size_Variable(void)
    {
        return namespaceFile_Size_Variable_;
    }

    ServerVariable::SPtr&
    NamespaceMetadataType::namespaceFile_UserWritable_Variable(void)
    {
        return namespaceFile_UserWritable_Variable_;
    }

    ServerVariable::SPtr&
    NamespaceMetadataType::namespaceFile_Writable_Variable(void)
    {
        return namespaceFile_Writable_Variable_;
    }

    ServerVariable::SPtr&
    NamespaceMetadataType::namespacePublicationDate_Variable(void)
    {
        return namespacePublicationDate_Variable_;
    }

    ServerVariable::SPtr&
    NamespaceMetadataType::namespaceUri_Variable(void)
    {
        return namespaceUri_Variable_;
    }

    ServerVariable::SPtr&
    NamespaceMetadataType::namespaceVersion_Variable(void)
    {
        return namespaceVersion_Variable_;
    }

    ServerVariable::SPtr&
    NamespaceMetadataType::staticNodeIdTypes_Variable(void)
    {
        return staticNodeIdTypes_Variable_;
    }

    ServerVariable::SPtr&
    NamespaceMetadataType::staticNumericNodeIdRange_Variable(void)
    {
        return staticNumericNodeIdRange_Variable_;
    }

    ServerVariable::SPtr&
    NamespaceMetadataType::staticStringNodeIdPattern_Variable(void)
    {
        return staticStringNodeIdPattern_Variable_;
    }

    void
    NamespaceMetadataType::defaultAccessRestrictions_Variable(ServerVariable::SPtr& serverVariable)
    {
        defaultAccessRestrictions_Variable_ = serverVariable;
    }

    void
    NamespaceMetadataType::defaultRolePermissions_Variable(ServerVariable::SPtr& serverVariable)
    {
        defaultRolePermissions_Variable_ = serverVariable;
    }

    void
    NamespaceMetadataType::defaultUserRolePermissions_Variable(ServerVariable::SPtr& serverVariable)
    {
        defaultUserRolePermissions_Variable_ = serverVariable;
    }

    void
    NamespaceMetadataType::isNamespaceSubset_Variable(ServerVariable::SPtr& serverVariable)
    {
        isNamespaceSubset_Variable_ = serverVariable;
    }

    void
    NamespaceMetadataType::namespaceFile_OpenCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        namespaceFile_OpenCount_Variable_ = serverVariable;
    }

    void
    NamespaceMetadataType::namespaceFile_Size_Variable(ServerVariable::SPtr& serverVariable)
    {
        namespaceFile_Size_Variable_ = serverVariable;
    }

    void
    NamespaceMetadataType::namespaceFile_UserWritable_Variable(ServerVariable::SPtr& serverVariable)
    {
        namespaceFile_UserWritable_Variable_ = serverVariable;
    }

    void
    NamespaceMetadataType::namespaceFile_Writable_Variable(ServerVariable::SPtr& serverVariable)
    {
        namespaceFile_Writable_Variable_ = serverVariable;
    }

    void
    NamespaceMetadataType::namespacePublicationDate_Variable(ServerVariable::SPtr& serverVariable)
    {
        namespacePublicationDate_Variable_ = serverVariable;
    }

    void
    NamespaceMetadataType::namespaceUri_Variable(ServerVariable::SPtr& serverVariable)
    {
        namespaceUri_Variable_ = serverVariable;
    }

    void
    NamespaceMetadataType::namespaceVersion_Variable(ServerVariable::SPtr& serverVariable)
    {
        namespaceVersion_Variable_ = serverVariable;
    }

    void
    NamespaceMetadataType::staticNodeIdTypes_Variable(ServerVariable::SPtr& serverVariable)
    {
        staticNodeIdTypes_Variable_ = serverVariable;
    }

    void
    NamespaceMetadataType::staticNumericNodeIdRange_Variable(ServerVariable::SPtr& serverVariable)
    {
        staticNumericNodeIdRange_Variable_ = serverVariable;
    }

    void
    NamespaceMetadataType::staticStringNodeIdPattern_Variable(ServerVariable::SPtr& serverVariable)
    {
        staticStringNodeIdPattern_Variable_ = serverVariable;
    }

    bool
    NamespaceMetadataType::get_DefaultAccessRestrictions_Variable(OpcUaDataValue& dataValue)
    {
        return defaultAccessRestrictions_Variable_->getDataValue(dataValue);
    }

    bool
    NamespaceMetadataType::get_DefaultRolePermissions_Variable(OpcUaDataValue& dataValue)
    {
        return defaultRolePermissions_Variable_->getDataValue(dataValue);
    }

    bool
    NamespaceMetadataType::get_DefaultUserRolePermissions_Variable(OpcUaDataValue& dataValue)
    {
        return defaultUserRolePermissions_Variable_->getDataValue(dataValue);
    }

    bool
    NamespaceMetadataType::get_IsNamespaceSubset_Variable(OpcUaDataValue& dataValue)
    {
        return isNamespaceSubset_Variable_->getDataValue(dataValue);
    }

    bool
    NamespaceMetadataType::get_NamespaceFile_OpenCount_Variable(OpcUaDataValue& dataValue)
    {
        return namespaceFile_OpenCount_Variable_->getDataValue(dataValue);
    }

    bool
    NamespaceMetadataType::get_NamespaceFile_Size_Variable(OpcUaDataValue& dataValue)
    {
        return namespaceFile_Size_Variable_->getDataValue(dataValue);
    }

    bool
    NamespaceMetadataType::get_NamespaceFile_UserWritable_Variable(OpcUaDataValue& dataValue)
    {
        return namespaceFile_UserWritable_Variable_->getDataValue(dataValue);
    }

    bool
    NamespaceMetadataType::get_NamespaceFile_Writable_Variable(OpcUaDataValue& dataValue)
    {
        return namespaceFile_Writable_Variable_->getDataValue(dataValue);
    }

    bool
    NamespaceMetadataType::get_NamespacePublicationDate_Variable(OpcUaDataValue& dataValue)
    {
        return namespacePublicationDate_Variable_->getDataValue(dataValue);
    }

    bool
    NamespaceMetadataType::get_NamespaceUri_Variable(OpcUaDataValue& dataValue)
    {
        return namespaceUri_Variable_->getDataValue(dataValue);
    }

    bool
    NamespaceMetadataType::get_NamespaceVersion_Variable(OpcUaDataValue& dataValue)
    {
        return namespaceVersion_Variable_->getDataValue(dataValue);
    }

    bool
    NamespaceMetadataType::get_StaticNodeIdTypes_Variable(OpcUaDataValue& dataValue)
    {
        return staticNodeIdTypes_Variable_->getDataValue(dataValue);
    }

    bool
    NamespaceMetadataType::get_StaticNumericNodeIdRange_Variable(OpcUaDataValue& dataValue)
    {
        return staticNumericNodeIdRange_Variable_->getDataValue(dataValue);
    }

    bool
    NamespaceMetadataType::get_StaticStringNodeIdPattern_Variable(OpcUaDataValue& dataValue)
    {
        return staticStringNodeIdPattern_Variable_->getDataValue(dataValue);
    }

    bool
    NamespaceMetadataType::set_DefaultAccessRestrictions_Variable(const OpcUaDataValue& dataValue)
    {
        return defaultAccessRestrictions_Variable_->setDataValue(dataValue);
    }

    bool
    NamespaceMetadataType::set_DefaultRolePermissions_Variable(const OpcUaDataValue& dataValue)
    {
        return defaultRolePermissions_Variable_->setDataValue(dataValue);
    }

    bool
    NamespaceMetadataType::set_DefaultUserRolePermissions_Variable(const OpcUaDataValue& dataValue)
    {
        return defaultUserRolePermissions_Variable_->setDataValue(dataValue);
    }

    bool
    NamespaceMetadataType::set_IsNamespaceSubset_Variable(const OpcUaDataValue& dataValue)
    {
        return isNamespaceSubset_Variable_->setDataValue(dataValue);
    }

    bool
    NamespaceMetadataType::set_NamespaceFile_OpenCount_Variable(const OpcUaDataValue& dataValue)
    {
        return namespaceFile_OpenCount_Variable_->setDataValue(dataValue);
    }

    bool
    NamespaceMetadataType::set_NamespaceFile_Size_Variable(const OpcUaDataValue& dataValue)
    {
        return namespaceFile_Size_Variable_->setDataValue(dataValue);
    }

    bool
    NamespaceMetadataType::set_NamespaceFile_UserWritable_Variable(const OpcUaDataValue& dataValue)
    {
        return namespaceFile_UserWritable_Variable_->setDataValue(dataValue);
    }

    bool
    NamespaceMetadataType::set_NamespaceFile_Writable_Variable(const OpcUaDataValue& dataValue)
    {
        return namespaceFile_Writable_Variable_->setDataValue(dataValue);
    }

    bool
    NamespaceMetadataType::set_NamespacePublicationDate_Variable(const OpcUaDataValue& dataValue)
    {
        return namespacePublicationDate_Variable_->setDataValue(dataValue);
    }

    bool
    NamespaceMetadataType::set_NamespaceUri_Variable(const OpcUaDataValue& dataValue)
    {
        return namespaceUri_Variable_->setDataValue(dataValue);
    }

    bool
    NamespaceMetadataType::set_NamespaceVersion_Variable(const OpcUaDataValue& dataValue)
    {
        return namespaceVersion_Variable_->setDataValue(dataValue);
    }

    bool
    NamespaceMetadataType::set_StaticNodeIdTypes_Variable(const OpcUaDataValue& dataValue)
    {
        return staticNodeIdTypes_Variable_->setDataValue(dataValue);
    }

    bool
    NamespaceMetadataType::set_StaticNumericNodeIdRange_Variable(const OpcUaDataValue& dataValue)
    {
        return staticNumericNodeIdRange_Variable_->setDataValue(dataValue);
    }

    bool
    NamespaceMetadataType::set_StaticStringNodeIdPattern_Variable(const OpcUaDataValue& dataValue)
    {
        return staticStringNodeIdPattern_Variable_->setDataValue(dataValue);
    }

    void
    NamespaceMetadataType::call_NamespaceFile_Close_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

    void
    NamespaceMetadataType::call_NamespaceFile_GetPosition_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

    void
    NamespaceMetadataType::call_NamespaceFile_Open_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

    void
    NamespaceMetadataType::call_NamespaceFile_Read_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

    void
    NamespaceMetadataType::call_NamespaceFile_SetPosition_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

    void
    NamespaceMetadataType::call_NamespaceFile_Write_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

}
