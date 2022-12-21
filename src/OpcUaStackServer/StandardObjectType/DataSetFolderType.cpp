/*
    VariableTypeClass: DataSetFolderType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardObjectType/DataSetFolderType.h"
using namespace OpcUaStackCore;

namespace OpcUaStackServer
{
    
    DataSetFolderType::DataSetFolderType(void)
    : ObjectBase()
    , addDataSetFolder_Method_(boost::make_shared<ServerMethod>("AddDataSetFolder_Method"))
    , addPublishedDataItemsTemplate_Method_(boost::make_shared<ServerMethod>("AddPublishedDataItemsTemplate_Method"))
    , addPublishedDataItems_Method_(boost::make_shared<ServerMethod>("AddPublishedDataItems_Method"))
    , addPublishedEventsTemplate_Method_(boost::make_shared<ServerMethod>("AddPublishedEventsTemplate_Method"))
    , addPublishedEvents_Method_(boost::make_shared<ServerMethod>("AddPublishedEvents_Method"))
    , removeDataSetFolder_Method_(boost::make_shared<ServerMethod>("RemoveDataSetFolder_Method"))
    , removePublishedDataSet_Method_(boost::make_shared<ServerMethod>("RemovePublishedDataSet_Method"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)14477);
        setServerMethod(addDataSetFolder_Method_);
        setServerMethod(addPublishedDataItemsTemplate_Method_);
        setServerMethod(addPublishedDataItems_Method_);
        setServerMethod(addPublishedEventsTemplate_Method_);
        setServerMethod(addPublishedEvents_Method_);
        setServerMethod(removeDataSetFolder_Method_);
        setServerMethod(removePublishedDataSet_Method_);
        addDataSetFolder_Method_->registerMethod(boost::bind(&DataSetFolderType::call_AddDataSetFolder_Method, this, boost::placeholders::_1));
        addPublishedDataItemsTemplate_Method_->registerMethod(boost::bind(&DataSetFolderType::call_AddPublishedDataItemsTemplate_Method, this, boost::placeholders::_1));
        addPublishedDataItems_Method_->registerMethod(boost::bind(&DataSetFolderType::call_AddPublishedDataItems_Method, this, boost::placeholders::_1));
        addPublishedEventsTemplate_Method_->registerMethod(boost::bind(&DataSetFolderType::call_AddPublishedEventsTemplate_Method, this, boost::placeholders::_1));
        addPublishedEvents_Method_->registerMethod(boost::bind(&DataSetFolderType::call_AddPublishedEvents_Method, this, boost::placeholders::_1));
        removeDataSetFolder_Method_->registerMethod(boost::bind(&DataSetFolderType::call_RemoveDataSetFolder_Method, this, boost::placeholders::_1));
        removePublishedDataSet_Method_->registerMethod(boost::bind(&DataSetFolderType::call_RemovePublishedDataSet_Method, this, boost::placeholders::_1));
    }
    
    DataSetFolderType::DataSetFolderType(const DataSetFolderType& value)
    : ObjectBase()
    , addDataSetFolder_Method_(boost::make_shared<ServerMethod>("AddDataSetFolder_Method"))
    , addPublishedDataItemsTemplate_Method_(boost::make_shared<ServerMethod>("AddPublishedDataItemsTemplate_Method"))
    , addPublishedDataItems_Method_(boost::make_shared<ServerMethod>("AddPublishedDataItems_Method"))
    , addPublishedEventsTemplate_Method_(boost::make_shared<ServerMethod>("AddPublishedEventsTemplate_Method"))
    , addPublishedEvents_Method_(boost::make_shared<ServerMethod>("AddPublishedEvents_Method"))
    , removeDataSetFolder_Method_(boost::make_shared<ServerMethod>("RemoveDataSetFolder_Method"))
    , removePublishedDataSet_Method_(boost::make_shared<ServerMethod>("RemovePublishedDataSet_Method"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)14477);
        setServerMethod(addDataSetFolder_Method_);
        setServerMethod(addPublishedDataItemsTemplate_Method_);
        setServerMethod(addPublishedDataItems_Method_);
        setServerMethod(addPublishedEventsTemplate_Method_);
        setServerMethod(addPublishedEvents_Method_);
        setServerMethod(removeDataSetFolder_Method_);
        setServerMethod(removePublishedDataSet_Method_);
        addDataSetFolder_Method_->registerMethod(boost::bind(&DataSetFolderType::call_AddDataSetFolder_Method, this, boost::placeholders::_1));
        addPublishedDataItemsTemplate_Method_->registerMethod(boost::bind(&DataSetFolderType::call_AddPublishedDataItemsTemplate_Method, this, boost::placeholders::_1));
        addPublishedDataItems_Method_->registerMethod(boost::bind(&DataSetFolderType::call_AddPublishedDataItems_Method, this, boost::placeholders::_1));
        addPublishedEventsTemplate_Method_->registerMethod(boost::bind(&DataSetFolderType::call_AddPublishedEventsTemplate_Method, this, boost::placeholders::_1));
        addPublishedEvents_Method_->registerMethod(boost::bind(&DataSetFolderType::call_AddPublishedEvents_Method, this, boost::placeholders::_1));
        removeDataSetFolder_Method_->registerMethod(boost::bind(&DataSetFolderType::call_RemoveDataSetFolder_Method, this, boost::placeholders::_1));
        removePublishedDataSet_Method_->registerMethod(boost::bind(&DataSetFolderType::call_RemovePublishedDataSet_Method, this, boost::placeholders::_1));
    }
    
    DataSetFolderType::~DataSetFolderType(void)
    {
    }

    void
    DataSetFolderType::call_AddDataSetFolder_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

    void
    DataSetFolderType::call_AddPublishedDataItemsTemplate_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

    void
    DataSetFolderType::call_AddPublishedDataItems_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

    void
    DataSetFolderType::call_AddPublishedEventsTemplate_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

    void
    DataSetFolderType::call_AddPublishedEvents_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

    void
    DataSetFolderType::call_RemoveDataSetFolder_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

    void
    DataSetFolderType::call_RemovePublishedDataSet_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

}
