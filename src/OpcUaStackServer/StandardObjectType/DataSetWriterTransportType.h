/*
    ObjectTypeClass: DataSetWriterTransportType

    Generated Source Code - please do not change this source code

    ObjectTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_DataSetWriterTransportType_h__
#define __OpcUaStackServer_DataSetWriterTransportType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"
#include "OpcUaStackServer/StandardObjectType/ObjectBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT DataSetWriterTransportType
   : public ObjectBase
   {
     public:
       typedef boost::shared_ptr<DataSetWriterTransportType> SPtr;
       typedef std::vector<DataSetWriterTransportType::SPtr> Vec;
   
       DataSetWriterTransportType(void);
       DataSetWriterTransportType(const DataSetWriterTransportType& value);
       virtual ~DataSetWriterTransportType(void);
    
      private:
   
   };

}

#endif
