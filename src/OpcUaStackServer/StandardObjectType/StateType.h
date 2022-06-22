/*
    ObjectTypeClass: StateType

    Generated Source Code - please do not change this source code

    ObjectTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_StateType_h__
#define __OpcUaStackServer_StateType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"
#include "OpcUaStackServer/StandardObjectType/ObjectBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT StateType
   : public ObjectBase
   {
     public:
       typedef boost::shared_ptr<StateType> SPtr;
       typedef std::vector<StateType::SPtr> Vec;
   
       StateType(void);
       StateType(const StateType& value);
       virtual ~StateType(void);

        //
        // UInt32
        //
        void stateNumber_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& stateNumber_Variable(void);
        bool get_StateNumber_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_StateNumber_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);
    
      private:
        ServerVariable::SPtr stateNumber_Variable_;
   
   };

}

#endif
