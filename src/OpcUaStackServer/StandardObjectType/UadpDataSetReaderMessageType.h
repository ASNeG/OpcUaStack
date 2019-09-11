/*
    ObjectTypeClass: UadpDataSetReaderMessageType

    Generated Source Code - please do not change this source code

    ObjectTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_UadpDataSetReaderMessageType_h__
#define __OpcUaStackServer_UadpDataSetReaderMessageType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"
#include "OpcUaStackServer/StandardObjectType/ObjectBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT UadpDataSetReaderMessageType
   : public ObjectBase
   {
     public:
       typedef boost::shared_ptr<UadpDataSetReaderMessageType> SPtr;
       typedef std::vector<UadpDataSetReaderMessageType::SPtr> Vec;
   
       UadpDataSetReaderMessageType(void);
       UadpDataSetReaderMessageType(const UadpDataSetReaderMessageType& value);
       virtual ~UadpDataSetReaderMessageType(void);

        //
        // Guid
        //
        void dataSetClassId_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& dataSetClassId_Variable(void);
        bool get_DataSetClassId_Variable(OpcUaDataValue& dataValue);
        bool set_DataSetClassId_Variable(const OpcUaDataValue& dataValue);

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
        // DataSetOrderingType
        //
        void dataSetOrdering_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& dataSetOrdering_Variable(void);
        bool get_DataSetOrdering_Variable(OpcUaDataValue& dataValue);
        bool set_DataSetOrdering_Variable(const OpcUaDataValue& dataValue);

        //
        // VersionTime
        //
        void groupVersion_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& groupVersion_Variable(void);
        bool get_GroupVersion_Variable(OpcUaDataValue& dataValue);
        bool set_GroupVersion_Variable(const OpcUaDataValue& dataValue);

        //
        // UadpNetworkMessageContentMask
        //
        void networkMessageContentMask_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& networkMessageContentMask_Variable(void);
        bool get_NetworkMessageContentMask_Variable(OpcUaDataValue& dataValue);
        bool set_NetworkMessageContentMask_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt16
        //
        void networkMessageNumber_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& networkMessageNumber_Variable(void);
        bool get_NetworkMessageNumber_Variable(OpcUaDataValue& dataValue);
        bool set_NetworkMessageNumber_Variable(const OpcUaDataValue& dataValue);

        //
        // Duration
        //
        void processingOffset_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& processingOffset_Variable(void);
        bool get_ProcessingOffset_Variable(OpcUaDataValue& dataValue);
        bool set_ProcessingOffset_Variable(const OpcUaDataValue& dataValue);

        //
        // Duration
        //
        void publishingInterval_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& publishingInterval_Variable(void);
        bool get_PublishingInterval_Variable(OpcUaDataValue& dataValue);
        bool set_PublishingInterval_Variable(const OpcUaDataValue& dataValue);

        //
        // Duration
        //
        void receiveOffset_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& receiveOffset_Variable(void);
        bool get_ReceiveOffset_Variable(OpcUaDataValue& dataValue);
        bool set_ReceiveOffset_Variable(const OpcUaDataValue& dataValue);
    
      private:
        ServerVariable::SPtr dataSetClassId_Variable_;
        ServerVariable::SPtr dataSetMessageContentMask_Variable_;
        ServerVariable::SPtr dataSetOffset_Variable_;
        ServerVariable::SPtr dataSetOrdering_Variable_;
        ServerVariable::SPtr groupVersion_Variable_;
        ServerVariable::SPtr networkMessageContentMask_Variable_;
        ServerVariable::SPtr networkMessageNumber_Variable_;
        ServerVariable::SPtr processingOffset_Variable_;
        ServerVariable::SPtr publishingInterval_Variable_;
        ServerVariable::SPtr receiveOffset_Variable_;
   
   };

}

#endif
