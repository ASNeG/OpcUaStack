/*
    ObjectTypeClass: SubscribedDataSetType

    Generated Source Code - please do not change this source code

    ObjectTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_SubscribedDataSetType_h__
#define __OpcUaStackServer_SubscribedDataSetType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"
#include "OpcUaStackServer/StandardObjectType/ObjectBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT SubscribedDataSetType
   : public ObjectBase
   {
     public:
       typedef boost::shared_ptr<SubscribedDataSetType> SPtr;
       typedef std::vector<SubscribedDataSetType::SPtr> Vec;
   
       SubscribedDataSetType(void);
       SubscribedDataSetType(const SubscribedDataSetType& value);
       virtual ~SubscribedDataSetType(void);

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
    
      private:
        ServerVariable::SPtr dataSetMetaData_Variable_;
        ServerVariable::SPtr messageReceiveTimeout_Variable_;
   
   };

}

#endif
