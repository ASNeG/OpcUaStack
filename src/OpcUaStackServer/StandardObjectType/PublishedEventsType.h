/*
    ObjectTypeClass: PublishedEventsType

    Generated Source Code - please do not change this source code

    ObjectTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_PublishedEventsType_h__
#define __OpcUaStackServer_PublishedEventsType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"
#include "OpcUaStackServer/StandardObjectType/ObjectBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT PublishedEventsType
   : public ObjectBase
   {
     public:
       typedef boost::shared_ptr<PublishedEventsType> SPtr;
       typedef std::vector<PublishedEventsType::SPtr> Vec;
   
       PublishedEventsType(void);
       PublishedEventsType(const PublishedEventsType& value);
       virtual ~PublishedEventsType(void);

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
        // NodeId
        //
        void eventNotifier_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& eventNotifier_Variable(void);
        bool get_EventNotifier_Variable(OpcUaDataValue& dataValue);
        bool set_EventNotifier_Variable(const OpcUaDataValue& dataValue);

        //
        // ContentFilter
        //
        void filter_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& filter_Variable(void);
        bool get_Filter_Variable(OpcUaDataValue& dataValue);
        bool set_Filter_Variable(const OpcUaDataValue& dataValue);

        //
        // SimpleAttributeOperand (Array)
        //
        void selectedFields_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& selectedFields_Variable(void);
        bool get_SelectedFields_Variable(OpcUaDataValue& dataValue);
        bool set_SelectedFields_Variable(const OpcUaDataValue& dataValue);

        virtual void call_ExtensionFields_AddExtensionField_Method(ApplicationMethodContext* applicationMethodContext);

        virtual void call_ExtensionFields_RemoveExtensionField_Method(ApplicationMethodContext* applicationMethodContext);

        virtual void call_ModifyFieldSelection_Method(ApplicationMethodContext* applicationMethodContext);
    
      private:
        ServerVariable::SPtr configurationVersion_Variable_;
        ServerVariable::SPtr dataSetClassId_Variable_;
        ServerVariable::SPtr dataSetMetaData_Variable_;
        ServerVariable::SPtr eventNotifier_Variable_;
        ServerVariable::SPtr filter_Variable_;
        ServerVariable::SPtr selectedFields_Variable_;
        ServerMethod::SPtr extensionFields_AddExtensionField_Method_;
        ServerMethod::SPtr extensionFields_RemoveExtensionField_Method_;
        ServerMethod::SPtr modifyFieldSelection_Method_;
   
   };

}

#endif
