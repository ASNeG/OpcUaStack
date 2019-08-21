/*
    ObjectTypeClass: ReaderGroupTransportType

    Generated Source Code - please do not change this source code

    ObjectTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_ReaderGroupTransportType_h__
#define __OpcUaStackServer_ReaderGroupTransportType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"
#include "OpcUaStackServer/StandardObjectType/ObjectBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT ReaderGroupTransportType
   : public ObjectBase
   {
     public:
       typedef boost::shared_ptr<ReaderGroupTransportType> SPtr;
       typedef std::vector<ReaderGroupTransportType::SPtr> Vec;
   
       ReaderGroupTransportType(void);
       ReaderGroupTransportType(const ReaderGroupTransportType& value);
       virtual ~ReaderGroupTransportType(void);
    
      private:
   
   };

}

#endif
