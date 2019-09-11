/*
    ObjectTypeClass: PublishedDataSetType

    Generated Source Code - please do not change this source code

    ObjectTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_PublishedDataSetType_h__
#define __OpcUaStackServer_PublishedDataSetType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"
#include "OpcUaStackServer/StandardObjectType/ObjectBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT PublishedDataSetType
   : public ObjectBase
   {
     public:
       typedef boost::shared_ptr<PublishedDataSetType> SPtr;
       typedef std::vector<PublishedDataSetType::SPtr> Vec;
   
       PublishedDataSetType(void);
       PublishedDataSetType(const PublishedDataSetType& value);
       virtual ~PublishedDataSetType(void);

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

        virtual void call_ExtensionFields_AddExtensionField_Method(ApplicationMethodContext* applicationMethodContext);

        virtual void call_ExtensionFields_RemoveExtensionField_Method(ApplicationMethodContext* applicationMethodContext);
    
      private:
        ServerVariable::SPtr configurationVersion_Variable_;
        ServerVariable::SPtr dataSetClassId_Variable_;
        ServerVariable::SPtr dataSetMetaData_Variable_;
        ServerMethod::SPtr extensionFields_AddExtensionField_Method_;
        ServerMethod::SPtr extensionFields_RemoveExtensionField_Method_;
   
   };

}

#endif
