/*
    ObjectTypeClass: JsonWriterGroupMessageType

    Generated Source Code - please do not change this source code

    ObjectTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_JsonWriterGroupMessageType_h__
#define __OpcUaStackServer_JsonWriterGroupMessageType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"
#include "OpcUaStackServer/StandardObjectType/ObjectBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT JsonWriterGroupMessageType
   : public ObjectBase
   {
     public:
       typedef boost::shared_ptr<JsonWriterGroupMessageType> SPtr;
       typedef std::vector<JsonWriterGroupMessageType::SPtr> Vec;
   
       JsonWriterGroupMessageType(void);
       JsonWriterGroupMessageType(const JsonWriterGroupMessageType& value);
       virtual ~JsonWriterGroupMessageType(void);

        //
        // JsonNetworkMessageContentMask
        //
        void networkMessageContentMask_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& networkMessageContentMask_Variable(void);
        bool get_NetworkMessageContentMask_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_NetworkMessageContentMask_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);
    
      private:
        ServerVariable::SPtr networkMessageContentMask_Variable_;
   
   };

}

#endif
