/*
    ObjectTypeClass: DataTypeEncodingType

    Generated Source Code - please do not change this source code

    ObjectTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_DataTypeEncodingType_h__
#define __OpcUaStackServer_DataTypeEncodingType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"
#include "OpcUaStackServer/StandardObjectType/ObjectBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT DataTypeEncodingType
   : public ObjectBase
   {
     public:
       typedef boost::shared_ptr<DataTypeEncodingType> SPtr;
       typedef std::vector<DataTypeEncodingType::SPtr> Vec;
   
       DataTypeEncodingType(void);
       DataTypeEncodingType(const DataTypeEncodingType& value);
       virtual ~DataTypeEncodingType(void);
    
      private:
   
   };

}

#endif
