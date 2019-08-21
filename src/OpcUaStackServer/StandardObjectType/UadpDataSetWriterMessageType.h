/*
    ObjectTypeClass: UadpDataSetWriterMessageType

    Generated Source Code - please do not change this source code

    ObjectTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_UadpDataSetWriterMessageType_h__
#define __OpcUaStackServer_UadpDataSetWriterMessageType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"
#include "OpcUaStackServer/StandardObjectType/ObjectBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT UadpDataSetWriterMessageType
   : public ObjectBase
   {
     public:
       typedef boost::shared_ptr<UadpDataSetWriterMessageType> SPtr;
       typedef std::vector<UadpDataSetWriterMessageType::SPtr> Vec;
   
       UadpDataSetWriterMessageType(void);
       UadpDataSetWriterMessageType(const UadpDataSetWriterMessageType& value);
       virtual ~UadpDataSetWriterMessageType(void);

        //
        // UInt16
        //
        void configuredSize_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& configuredSize_Variable(void);
        bool get_ConfiguredSize_Variable(OpcUaDataValue& dataValue);
        bool set_ConfiguredSize_Variable(const OpcUaDataValue& dataValue);

        //
        // UadpDataSetMessageContentMask
        //
        void dataSetMessageContentMask_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& dataSetMessageContentMask_Variable(void);
        bool get_DataSetMessageContentMask_Variable(OpcUaDataValue& dataValue);
        bool set_DataSetMessageContentMask_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt16
        //
        void dataSetOffset_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& dataSetOffset_Variable(void);
        bool get_DataSetOffset_Variable(OpcUaDataValue& dataValue);
        bool set_DataSetOffset_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt16
        //
        void networkMessageNumber_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& networkMessageNumber_Variable(void);
        bool get_NetworkMessageNumber_Variable(OpcUaDataValue& dataValue);
        bool set_NetworkMessageNumber_Variable(const OpcUaDataValue& dataValue);
    
      private:
        ServerVariable::SPtr configuredSize_Variable_;
        ServerVariable::SPtr dataSetMessageContentMask_Variable_;
        ServerVariable::SPtr dataSetOffset_Variable_;
        ServerVariable::SPtr networkMessageNumber_Variable_;
   
   };

}

#endif
