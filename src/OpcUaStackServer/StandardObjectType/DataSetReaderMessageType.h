/*
    ObjectTypeClass: DataSetReaderMessageType

    Generated Source Code - please do not change this source code

    ObjectTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_DataSetReaderMessageType_h__
#define __OpcUaStackServer_DataSetReaderMessageType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"
#include "OpcUaStackServer/StandardObjectType/ObjectBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT DataSetReaderMessageType
   : public ObjectBase
   {
     public:
       typedef boost::shared_ptr<DataSetReaderMessageType> SPtr;
       typedef std::vector<DataSetReaderMessageType::SPtr> Vec;
   
       DataSetReaderMessageType(void);
       DataSetReaderMessageType(const DataSetReaderMessageType& value);
       virtual ~DataSetReaderMessageType(void);
    
      private:
   
   };

}

#endif
