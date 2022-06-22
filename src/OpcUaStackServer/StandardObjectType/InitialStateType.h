/*
    ObjectTypeClass: InitialStateType

    Generated Source Code - please do not change this source code

    ObjectTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_InitialStateType_h__
#define __OpcUaStackServer_InitialStateType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"
#include "OpcUaStackServer/StandardObjectType/ObjectBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT InitialStateType
   : public ObjectBase
   {
     public:
       typedef boost::shared_ptr<InitialStateType> SPtr;
       typedef std::vector<InitialStateType::SPtr> Vec;
   
       InitialStateType(void);
       InitialStateType(const InitialStateType& value);
       virtual ~InitialStateType(void);

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
