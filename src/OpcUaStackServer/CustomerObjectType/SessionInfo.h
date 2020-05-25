/*
    ObjectTypeClass: SessionInfo

    Generated Source Code - please do not change this source code

    ObjectTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_SessionInfo_h__
#define __OpcUaStackServer_SessionInfo_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"
#include "OpcUaStackServer/StandardObjectType/ObjectBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT SessionInfo
   : public ObjectBase
   {
     public:
       typedef boost::shared_ptr<SessionInfo> SPtr;
       typedef std::vector<SessionInfo::SPtr> Vec;
   
       SessionInfo(void);
       SessionInfo(const SessionInfo& value);
       virtual ~SessionInfo(void);

        //
        // UInt32
        //
        void id_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& id_Variable(void);
        bool get_Id_Variable(OpcUaDataValue& dataValue);
        bool set_Id_Variable(const OpcUaDataValue& dataValue);

        //
        // DateTime
        //
        void timeout_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& timeout_Variable(void);
        bool get_Timeout_Variable(OpcUaDataValue& dataValue);
        bool set_Timeout_Variable(const OpcUaDataValue& dataValue);
    
      private:
        ServerVariable::SPtr id_Variable_;
        ServerVariable::SPtr timeout_Variable_;
   
   };

}

#endif
