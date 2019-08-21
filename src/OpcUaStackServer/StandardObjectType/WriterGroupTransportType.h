/*
    ObjectTypeClass: WriterGroupTransportType

    Generated Source Code - please do not change this source code

    ObjectTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_WriterGroupTransportType_h__
#define __OpcUaStackServer_WriterGroupTransportType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"
#include "OpcUaStackServer/StandardObjectType/ObjectBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT WriterGroupTransportType
   : public ObjectBase
   {
     public:
       typedef boost::shared_ptr<WriterGroupTransportType> SPtr;
       typedef std::vector<WriterGroupTransportType::SPtr> Vec;
   
       WriterGroupTransportType(void);
       WriterGroupTransportType(const WriterGroupTransportType& value);
       virtual ~WriterGroupTransportType(void);
    
      private:
   
   };

}

#endif
