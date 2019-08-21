/*
    ObjectTypeClass: DataSetWriterMessageType

    Generated Source Code - please do not change this source code

    ObjectTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_DataSetWriterMessageType_h__
#define __OpcUaStackServer_DataSetWriterMessageType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"
#include "OpcUaStackServer/StandardObjectType/ObjectBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT DataSetWriterMessageType
   : public ObjectBase
   {
     public:
       typedef boost::shared_ptr<DataSetWriterMessageType> SPtr;
       typedef std::vector<DataSetWriterMessageType::SPtr> Vec;
   
       DataSetWriterMessageType(void);
       DataSetWriterMessageType(const DataSetWriterMessageType& value);
       virtual ~DataSetWriterMessageType(void);
    
      private:
   
   };

}

#endif
