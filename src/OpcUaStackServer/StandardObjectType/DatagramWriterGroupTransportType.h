/*
    ObjectTypeClass: DatagramWriterGroupTransportType

    Generated Source Code - please do not change this source code

    ObjectTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_DatagramWriterGroupTransportType_h__
#define __OpcUaStackServer_DatagramWriterGroupTransportType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"
#include "OpcUaStackServer/StandardObjectType/ObjectBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT DatagramWriterGroupTransportType
   : public ObjectBase
   {
     public:
       typedef boost::shared_ptr<DatagramWriterGroupTransportType> SPtr;
       typedef std::vector<DatagramWriterGroupTransportType::SPtr> Vec;
   
       DatagramWriterGroupTransportType(void);
       DatagramWriterGroupTransportType(const DatagramWriterGroupTransportType& value);
       virtual ~DatagramWriterGroupTransportType(void);

        //
        // Byte
        //
        void messageRepeatCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& messageRepeatCount_Variable(void);
        bool get_MessageRepeatCount_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_MessageRepeatCount_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Duration
        //
        void messageRepeatDelay_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& messageRepeatDelay_Variable(void);
        bool get_MessageRepeatDelay_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_MessageRepeatDelay_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);
    
      private:
        ServerVariable::SPtr messageRepeatCount_Variable_;
        ServerVariable::SPtr messageRepeatDelay_Variable_;
   
   };

}

#endif
