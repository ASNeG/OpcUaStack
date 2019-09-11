/*
    ObjectTypeClass: DataSetReaderTransportType

    Generated Source Code - please do not change this source code

    ObjectTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_DataSetReaderTransportType_h__
#define __OpcUaStackServer_DataSetReaderTransportType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"
#include "OpcUaStackServer/StandardObjectType/ObjectBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT DataSetReaderTransportType
   : public ObjectBase
   {
     public:
       typedef boost::shared_ptr<DataSetReaderTransportType> SPtr;
       typedef std::vector<DataSetReaderTransportType::SPtr> Vec;
   
       DataSetReaderTransportType(void);
       DataSetReaderTransportType(const DataSetReaderTransportType& value);
       virtual ~DataSetReaderTransportType(void);
    
      private:
   
   };

}

#endif
