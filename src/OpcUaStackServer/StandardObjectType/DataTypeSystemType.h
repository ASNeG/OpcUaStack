/*
    ObjectTypeClass: DataTypeSystemType

    Generated Source Code - please do not change this source code

    ObjectTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_DataTypeSystemType_h__
#define __OpcUaStackServer_DataTypeSystemType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"
#include "OpcUaStackServer/StandardObjectType/ObjectBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT DataTypeSystemType
   : public ObjectBase
   {
     public:
       typedef boost::shared_ptr<DataTypeSystemType> SPtr;
       typedef std::vector<DataTypeSystemType::SPtr> Vec;
   
       DataTypeSystemType(void);
       DataTypeSystemType(const DataTypeSystemType& value);
       virtual ~DataTypeSystemType(void);
    
      private:
   
   };

}

#endif
