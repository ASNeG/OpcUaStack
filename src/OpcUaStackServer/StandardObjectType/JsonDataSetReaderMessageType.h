/*
    ObjectTypeClass: JsonDataSetReaderMessageType

    Generated Source Code - please do not change this source code

    ObjectTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_JsonDataSetReaderMessageType_h__
#define __OpcUaStackServer_JsonDataSetReaderMessageType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"
#include "OpcUaStackServer/StandardObjectType/ObjectBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT JsonDataSetReaderMessageType
   : public ObjectBase
   {
     public:
       typedef boost::shared_ptr<JsonDataSetReaderMessageType> SPtr;
       typedef std::vector<JsonDataSetReaderMessageType::SPtr> Vec;
   
       JsonDataSetReaderMessageType(void);
       JsonDataSetReaderMessageType(const JsonDataSetReaderMessageType& value);
       virtual ~JsonDataSetReaderMessageType(void);

        //
        // JsonDataSetMessageContentMask
        //
        void dataSetMessageContentMask_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& dataSetMessageContentMask_Variable(void);
        bool get_DataSetMessageContentMask_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_DataSetMessageContentMask_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // JsonNetworkMessageContentMask
        //
        void networkMessageContentMask_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& networkMessageContentMask_Variable(void);
        bool get_NetworkMessageContentMask_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_NetworkMessageContentMask_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);
    
      private:
        ServerVariable::SPtr dataSetMessageContentMask_Variable_;
        ServerVariable::SPtr networkMessageContentMask_Variable_;
   
   };

}

#endif
