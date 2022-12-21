/*
    ObjectTypeClass: UadpWriterGroupMessageType

    Generated Source Code - please do not change this source code

    ObjectTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_UadpWriterGroupMessageType_h__
#define __OpcUaStackServer_UadpWriterGroupMessageType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"
#include "OpcUaStackServer/StandardObjectType/ObjectBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT UadpWriterGroupMessageType
   : public ObjectBase
   {
     public:
       typedef boost::shared_ptr<UadpWriterGroupMessageType> SPtr;
       typedef std::vector<UadpWriterGroupMessageType::SPtr> Vec;
   
       UadpWriterGroupMessageType(void);
       UadpWriterGroupMessageType(const UadpWriterGroupMessageType& value);
       virtual ~UadpWriterGroupMessageType(void);

        //
        // DataSetOrderingType
        //
        void dataSetOrdering_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& dataSetOrdering_Variable(void);
        bool get_DataSetOrdering_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_DataSetOrdering_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // VersionTime
        //
        void groupVersion_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& groupVersion_Variable(void);
        bool get_GroupVersion_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_GroupVersion_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UadpNetworkMessageContentMask
        //
        void networkMessageContentMask_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& networkMessageContentMask_Variable(void);
        bool get_NetworkMessageContentMask_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_NetworkMessageContentMask_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Duration
        //
        void publishingOffset_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& publishingOffset_Variable(void);
        bool get_PublishingOffset_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_PublishingOffset_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Duration
        //
        void samplingOffset_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& samplingOffset_Variable(void);
        bool get_SamplingOffset_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_SamplingOffset_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);
    
      private:
        ServerVariable::SPtr dataSetOrdering_Variable_;
        ServerVariable::SPtr groupVersion_Variable_;
        ServerVariable::SPtr networkMessageContentMask_Variable_;
        ServerVariable::SPtr publishingOffset_Variable_;
        ServerVariable::SPtr samplingOffset_Variable_;
   
   };

}

#endif
