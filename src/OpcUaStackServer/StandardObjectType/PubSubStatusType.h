/*
    ObjectTypeClass: PubSubStatusType

    Generated Source Code - please do not change this source code

    ObjectTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_PubSubStatusType_h__
#define __OpcUaStackServer_PubSubStatusType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"
#include "OpcUaStackServer/StandardObjectType/ObjectBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT PubSubStatusType
   : public ObjectBase
   {
     public:
       typedef boost::shared_ptr<PubSubStatusType> SPtr;
       typedef std::vector<PubSubStatusType::SPtr> Vec;
   
       PubSubStatusType(void);
       PubSubStatusType(const PubSubStatusType& value);
       virtual ~PubSubStatusType(void);

        //
        // PubSubState
        //
        void state_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& state_Variable(void);
        bool get_State_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_State_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        virtual void call_Disable_Method(OpcUaStackCore::ApplicationMethodContext* applicationMethodContext);

        virtual void call_Enable_Method(OpcUaStackCore::ApplicationMethodContext* applicationMethodContext);
    
      private:
        ServerVariable::SPtr state_Variable_;
        ServerMethod::SPtr disable_Method_;
        ServerMethod::SPtr enable_Method_;
   
   };

}

#endif
