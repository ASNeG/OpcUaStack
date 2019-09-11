/*
    ObjectTypeClass: AlarmGroupType

    Generated Source Code - please do not change this source code

    ObjectTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_AlarmGroupType_h__
#define __OpcUaStackServer_AlarmGroupType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"
#include "OpcUaStackServer/StandardObjectType/ObjectBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT AlarmGroupType
   : public ObjectBase
   {
     public:
       typedef boost::shared_ptr<AlarmGroupType> SPtr;
       typedef std::vector<AlarmGroupType::SPtr> Vec;
   
       AlarmGroupType(void);
       AlarmGroupType(const AlarmGroupType& value);
       virtual ~AlarmGroupType(void);
    
      private:
   
   };

}

#endif
