/*
    ObjectTypeClass: ServerRedundancyType

    Generated Source Code - please do not change this source code

    ObjectTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_ServerRedundancyType_h__
#define __OpcUaStackServer_ServerRedundancyType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"
#include "OpcUaStackServer/StandardObjectType/ObjectBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT ServerRedundancyType
   : public ObjectBase
   {
     public:
       typedef boost::shared_ptr<ServerRedundancyType> SPtr;
       typedef std::vector<ServerRedundancyType::SPtr> Vec;
   
       ServerRedundancyType(void);
       ServerRedundancyType(const ServerRedundancyType& value);
       virtual ~ServerRedundancyType(void);

        //
        // RedundancySupport
        //
        void redundancySupport_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& redundancySupport_Variable(void);
        bool get_RedundancySupport_Variable(OpcUaDataValue& dataValue);
        bool set_RedundancySupport_Variable(const OpcUaDataValue& dataValue);
    
      private:
        ServerVariable::SPtr redundancySupport_Variable_;
   
   };

}

#endif
