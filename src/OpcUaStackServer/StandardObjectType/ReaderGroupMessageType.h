/*
    ObjectTypeClass: ReaderGroupMessageType

    Generated Source Code - please do not change this source code

    ObjectTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_ReaderGroupMessageType_h__
#define __OpcUaStackServer_ReaderGroupMessageType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"
#include "OpcUaStackServer/StandardObjectType/ObjectBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT ReaderGroupMessageType
   : public ObjectBase
   {
     public:
       typedef boost::shared_ptr<ReaderGroupMessageType> SPtr;
       typedef std::vector<ReaderGroupMessageType::SPtr> Vec;
   
       ReaderGroupMessageType(void);
       ReaderGroupMessageType(const ReaderGroupMessageType& value);
       virtual ~ReaderGroupMessageType(void);
    
      private:
   
   };

}

#endif
