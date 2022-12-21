/*
    ObjectTypeClass: DataSetFolderType

    Generated Source Code - please do not change this source code

    ObjectTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_DataSetFolderType_h__
#define __OpcUaStackServer_DataSetFolderType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"
#include "OpcUaStackServer/StandardObjectType/ObjectBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT DataSetFolderType
   : public ObjectBase
   {
     public:
       typedef boost::shared_ptr<DataSetFolderType> SPtr;
       typedef std::vector<DataSetFolderType::SPtr> Vec;
   
       DataSetFolderType(void);
       DataSetFolderType(const DataSetFolderType& value);
       virtual ~DataSetFolderType(void);

        virtual void call_AddDataSetFolder_Method(OpcUaStackCore::ApplicationMethodContext* applicationMethodContext);

        virtual void call_AddPublishedDataItemsTemplate_Method(OpcUaStackCore::ApplicationMethodContext* applicationMethodContext);

        virtual void call_AddPublishedDataItems_Method(OpcUaStackCore::ApplicationMethodContext* applicationMethodContext);

        virtual void call_AddPublishedEventsTemplate_Method(OpcUaStackCore::ApplicationMethodContext* applicationMethodContext);

        virtual void call_AddPublishedEvents_Method(OpcUaStackCore::ApplicationMethodContext* applicationMethodContext);

        virtual void call_RemoveDataSetFolder_Method(OpcUaStackCore::ApplicationMethodContext* applicationMethodContext);

        virtual void call_RemovePublishedDataSet_Method(OpcUaStackCore::ApplicationMethodContext* applicationMethodContext);
    
      private:
        ServerMethod::SPtr addDataSetFolder_Method_;
        ServerMethod::SPtr addPublishedDataItemsTemplate_Method_;
        ServerMethod::SPtr addPublishedDataItems_Method_;
        ServerMethod::SPtr addPublishedEventsTemplate_Method_;
        ServerMethod::SPtr addPublishedEvents_Method_;
        ServerMethod::SPtr removeDataSetFolder_Method_;
        ServerMethod::SPtr removePublishedDataSet_Method_;
   
   };

}

#endif
