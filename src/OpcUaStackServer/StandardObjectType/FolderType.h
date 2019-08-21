/*
    ObjectTypeClass: FolderType

    Generated Source Code - please do not change this source code

    ObjectTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_FolderType_h__
#define __OpcUaStackServer_FolderType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"
#include "OpcUaStackServer/StandardObjectType/ObjectBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT FolderType
   : public ObjectBase
   {
     public:
       typedef boost::shared_ptr<FolderType> SPtr;
       typedef std::vector<FolderType::SPtr> Vec;
   
       FolderType(void);
       FolderType(const FolderType& value);
       virtual ~FolderType(void);
    
      private:
   
   };

}

#endif
