/*
    ObjectTypeClass: PublishedDataItemsType

    Generated Source Code - please do not change this source code

    ObjectTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_PublishedDataItemsType_h__
#define __OpcUaStackServer_PublishedDataItemsType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"
#include "OpcUaStackServer/StandardObjectType/ObjectBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT PublishedDataItemsType
   : public ObjectBase
   {
     public:
       typedef boost::shared_ptr<PublishedDataItemsType> SPtr;
       typedef std::vector<PublishedDataItemsType::SPtr> Vec;
   
       PublishedDataItemsType(void);
       PublishedDataItemsType(const PublishedDataItemsType& value);
       virtual ~PublishedDataItemsType(void);

        //
        // ConfigurationVersionDataType
        //
        void configurationVersion_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& configurationVersion_Variable(void);
        bool get_ConfigurationVersion_Variable(OpcUaDataValue& dataValue);
        bool set_ConfigurationVersion_Variable(const OpcUaDataValue& dataValue);

        //
        // Guid
        //
        void dataSetClassId_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& dataSetClassId_Variable(void);
        bool get_DataSetClassId_Variable(OpcUaDataValue& dataValue);
        bool set_DataSetClassId_Variable(const OpcUaDataValue& dataValue);

        //
        // DataSetMetaDataType
        //
        void dataSetMetaData_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& dataSetMetaData_Variable(void);
        bool get_DataSetMetaData_Variable(OpcUaDataValue& dataValue);
        bool set_DataSetMetaData_Variable(const OpcUaDataValue& dataValue);

        //
        // PublishedVariableDataType (Array)
        //
        void publishedData_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& publishedData_Variable(void);
        bool get_PublishedData_Variable(OpcUaDataValue& dataValue);
        bool set_PublishedData_Variable(const OpcUaDataValue& dataValue);

        virtual void call_AddVariables_Method(ApplicationMethodContext* applicationMethodContext);

        virtual void call_ExtensionFields_AddExtensionField_Method(ApplicationMethodContext* applicationMethodContext);

        virtual void call_ExtensionFields_RemoveExtensionField_Method(ApplicationMethodContext* applicationMethodContext);

        virtual void call_RemoveVariables_Method(ApplicationMethodContext* applicationMethodContext);
    
      private:
        ServerVariable::SPtr configurationVersion_Variable_;
        ServerVariable::SPtr dataSetClassId_Variable_;
        ServerVariable::SPtr dataSetMetaData_Variable_;
        ServerVariable::SPtr publishedData_Variable_;
        ServerMethod::SPtr addVariables_Method_;
        ServerMethod::SPtr extensionFields_AddExtensionField_Method_;
        ServerMethod::SPtr extensionFields_RemoveExtensionField_Method_;
        ServerMethod::SPtr removeVariables_Method_;
   
   };

}

#endif
