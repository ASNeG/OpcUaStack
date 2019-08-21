/*
    VariableTypeClass: ExtensionFieldsType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardObjectType/ExtensionFieldsType.h"

namespace OpcUaStackServer
{
    
    ExtensionFieldsType::ExtensionFieldsType(void)
    : ObjectBase()
    , addExtensionField_Method_(boost::make_shared<ServerMethod>("AddExtensionField_Method"))
    , removeExtensionField_Method_(boost::make_shared<ServerMethod>("RemoveExtensionField_Method"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)15489);
        setServerMethod(addExtensionField_Method_);
        setServerMethod(removeExtensionField_Method_);
        addExtensionField_Method_->registerMethod(boost::bind(&ExtensionFieldsType::call_AddExtensionField_Method, this, _1));
        removeExtensionField_Method_->registerMethod(boost::bind(&ExtensionFieldsType::call_RemoveExtensionField_Method, this, _1));
    }
    
    ExtensionFieldsType::ExtensionFieldsType(const ExtensionFieldsType& value)
    : ObjectBase()
    , addExtensionField_Method_(boost::make_shared<ServerMethod>("AddExtensionField_Method"))
    , removeExtensionField_Method_(boost::make_shared<ServerMethod>("RemoveExtensionField_Method"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)15489);
        setServerMethod(addExtensionField_Method_);
        setServerMethod(removeExtensionField_Method_);
        addExtensionField_Method_->registerMethod(boost::bind(&ExtensionFieldsType::call_AddExtensionField_Method, this, _1));
        removeExtensionField_Method_->registerMethod(boost::bind(&ExtensionFieldsType::call_RemoveExtensionField_Method, this, _1));
    }
    
    ExtensionFieldsType::~ExtensionFieldsType(void)
    {
    }

    void
    ExtensionFieldsType::call_AddExtensionField_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

    void
    ExtensionFieldsType::call_RemoveExtensionField_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

}
