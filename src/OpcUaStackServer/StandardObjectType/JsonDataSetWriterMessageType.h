/*
    ObjectTypeClass: JsonDataSetWriterMessageType

    Generated Source Code - please do not change this source code

    ObjectTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_JsonDataSetWriterMessageType_h__
#define __OpcUaStackServer_JsonDataSetWriterMessageType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"
#include "OpcUaStackServer/StandardObjectType/ObjectBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT JsonDataSetWriterMessageType
   : public ObjectBase
   {
     public:
       typedef boost::shared_ptr<JsonDataSetWriterMessageType> SPtr;
       typedef std::vector<JsonDataSetWriterMessageType::SPtr> Vec;
   
       JsonDataSetWriterMessageType(void);
       JsonDataSetWriterMessageType(const JsonDataSetWriterMessageType& value);
       virtual ~JsonDataSetWriterMessageType(void);

        //
        // JsonDataSetMessageContentMask
        //
        void dataSetMessageContentMask_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& dataSetMessageContentMask_Variable(void);
        bool get_DataSetMessageContentMask_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_DataSetMessageContentMask_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);
    
      private:
        ServerVariable::SPtr dataSetMessageContentMask_Variable_;
   
   };

}

#endif
