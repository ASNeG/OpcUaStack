/*
    ObjectTypeClass: TransitionType

    Generated Source Code - please do not change this source code

    ObjectTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_TransitionType_h__
#define __OpcUaStackServer_TransitionType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"
#include "OpcUaStackServer/StandardObjectType/ObjectBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT TransitionType
   : public ObjectBase
   {
     public:
       typedef boost::shared_ptr<TransitionType> SPtr;
       typedef std::vector<TransitionType::SPtr> Vec;
   
       TransitionType(void);
       TransitionType(const TransitionType& value);
       virtual ~TransitionType(void);

        //
        // UInt32
        //
        void transitionNumber_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& transitionNumber_Variable(void);
        bool get_TransitionNumber_Variable(OpcUaDataValue& dataValue);
        bool set_TransitionNumber_Variable(const OpcUaDataValue& dataValue);
    
      private:
        ServerVariable::SPtr transitionNumber_Variable_;
   
   };

}

#endif
