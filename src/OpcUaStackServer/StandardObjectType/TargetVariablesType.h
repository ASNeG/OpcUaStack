/*
    ObjectTypeClass: TargetVariablesType

    Generated Source Code - please do not change this source code

    ObjectTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_TargetVariablesType_h__
#define __OpcUaStackServer_TargetVariablesType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"
#include "OpcUaStackServer/StandardObjectType/ObjectBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT TargetVariablesType
   : public ObjectBase
   {
     public:
       typedef boost::shared_ptr<TargetVariablesType> SPtr;
       typedef std::vector<TargetVariablesType::SPtr> Vec;
   
       TargetVariablesType(void);
       TargetVariablesType(const TargetVariablesType& value);
       virtual ~TargetVariablesType(void);

        //
        // DataSetMetaDataType
        //
        void dataSetMetaData_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& dataSetMetaData_Variable(void);
        bool get_DataSetMetaData_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_DataSetMetaData_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Duration
        //
        void messageReceiveTimeout_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& messageReceiveTimeout_Variable(void);
        bool get_MessageReceiveTimeout_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_MessageReceiveTimeout_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // FieldTargetDataType (Array)
        //
        void targetVariables_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& targetVariables_Variable(void);
        bool get_TargetVariables_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_TargetVariables_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        virtual void call_AddTargetVariables_Method(OpcUaStackCore::ApplicationMethodContext* applicationMethodContext);

        virtual void call_RemoveTargetVariables_Method(OpcUaStackCore::ApplicationMethodContext* applicationMethodContext);
    
      private:
        ServerVariable::SPtr dataSetMetaData_Variable_;
        ServerVariable::SPtr messageReceiveTimeout_Variable_;
        ServerVariable::SPtr targetVariables_Variable_;
        ServerMethod::SPtr addTargetVariables_Method_;
        ServerMethod::SPtr removeTargetVariables_Method_;
   
   };

}

#endif
