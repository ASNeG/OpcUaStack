/*
    ObjectTypeClass: WriterGroupMessageType

    Generated Source Code - please do not change this source code

    ObjectTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_WriterGroupMessageType_h__
#define __OpcUaStackServer_WriterGroupMessageType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"
#include "OpcUaStackServer/StandardObjectType/ObjectBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT WriterGroupMessageType
   : public ObjectBase
   {
     public:
       typedef boost::shared_ptr<WriterGroupMessageType> SPtr;
       typedef std::vector<WriterGroupMessageType::SPtr> Vec;
   
       WriterGroupMessageType(void);
       WriterGroupMessageType(const WriterGroupMessageType& value);
       virtual ~WriterGroupMessageType(void);
    
      private:
   
   };

}

#endif
