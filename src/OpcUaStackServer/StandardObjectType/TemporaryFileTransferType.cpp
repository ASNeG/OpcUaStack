/*
    VariableTypeClass: TemporaryFileTransferType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardObjectType/TemporaryFileTransferType.h"
using namespace OpcUaStackCore;

namespace OpcUaStackServer
{
    
    TemporaryFileTransferType::TemporaryFileTransferType(void)
    : ObjectBase()
    , clientProcessingTimeout_Variable_(boost::make_shared<ServerVariable>("ClientProcessingTimeout_Variable"))
    , closeAndCommit_Method_(boost::make_shared<ServerMethod>("CloseAndCommit_Method"))
    , generateFileForRead_Method_(boost::make_shared<ServerMethod>("GenerateFileForRead_Method"))
    , generateFileForWrite_Method_(boost::make_shared<ServerMethod>("GenerateFileForWrite_Method"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)15744);
        setServerVariable(clientProcessingTimeout_Variable_);
        setServerMethod(closeAndCommit_Method_);
        setServerMethod(generateFileForRead_Method_);
        setServerMethod(generateFileForWrite_Method_);
        closeAndCommit_Method_->registerMethod(boost::bind(&TemporaryFileTransferType::call_CloseAndCommit_Method, this, boost::placeholders::_1));
        generateFileForRead_Method_->registerMethod(boost::bind(&TemporaryFileTransferType::call_GenerateFileForRead_Method, this, boost::placeholders::_1));
        generateFileForWrite_Method_->registerMethod(boost::bind(&TemporaryFileTransferType::call_GenerateFileForWrite_Method, this, boost::placeholders::_1));
    }
    
    TemporaryFileTransferType::TemporaryFileTransferType(const TemporaryFileTransferType& value)
    : ObjectBase()
    , clientProcessingTimeout_Variable_(boost::make_shared<ServerVariable>("ClientProcessingTimeout_Variable"))
    , closeAndCommit_Method_(boost::make_shared<ServerMethod>("CloseAndCommit_Method"))
    , generateFileForRead_Method_(boost::make_shared<ServerMethod>("GenerateFileForRead_Method"))
    , generateFileForWrite_Method_(boost::make_shared<ServerMethod>("GenerateFileForWrite_Method"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)15744);
        setServerVariable(clientProcessingTimeout_Variable_);
        setServerMethod(closeAndCommit_Method_);
        setServerMethod(generateFileForRead_Method_);
        setServerMethod(generateFileForWrite_Method_);
        closeAndCommit_Method_->registerMethod(boost::bind(&TemporaryFileTransferType::call_CloseAndCommit_Method, this, boost::placeholders::_1));
        generateFileForRead_Method_->registerMethod(boost::bind(&TemporaryFileTransferType::call_GenerateFileForRead_Method, this, boost::placeholders::_1));
        generateFileForWrite_Method_->registerMethod(boost::bind(&TemporaryFileTransferType::call_GenerateFileForWrite_Method, this, boost::placeholders::_1));
    }
    
    TemporaryFileTransferType::~TemporaryFileTransferType(void)
    {
    }

    ServerVariable::SPtr&
    TemporaryFileTransferType::clientProcessingTimeout_Variable(void)
    {
        return clientProcessingTimeout_Variable_;
    }

    void
    TemporaryFileTransferType::clientProcessingTimeout_Variable(ServerVariable::SPtr& serverVariable)
    {
        clientProcessingTimeout_Variable_ = serverVariable;
    }

    bool
    TemporaryFileTransferType::get_ClientProcessingTimeout_Variable(OpcUaDataValue& dataValue)
    {
        return clientProcessingTimeout_Variable_->getDataValue(dataValue);
    }

    bool
    TemporaryFileTransferType::set_ClientProcessingTimeout_Variable(const OpcUaDataValue& dataValue)
    {
        return clientProcessingTimeout_Variable_->setDataValue(dataValue);
    }

    void
    TemporaryFileTransferType::call_CloseAndCommit_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

    void
    TemporaryFileTransferType::call_GenerateFileForRead_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

    void
    TemporaryFileTransferType::call_GenerateFileForWrite_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

}
