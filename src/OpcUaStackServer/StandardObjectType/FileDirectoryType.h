/*
    ObjectTypeClass: FileDirectoryType

    Generated Source Code - please do not change this source code

    ObjectTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_FileDirectoryType_h__
#define __OpcUaStackServer_FileDirectoryType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"
#include "OpcUaStackServer/StandardObjectType/ObjectBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT FileDirectoryType
   : public ObjectBase
   {
     public:
       typedef boost::shared_ptr<FileDirectoryType> SPtr;
       typedef std::vector<FileDirectoryType::SPtr> Vec;
   
       FileDirectoryType(void);
       FileDirectoryType(const FileDirectoryType& value);
       virtual ~FileDirectoryType(void);

        virtual void call_CreateDirectory_Method(ApplicationMethodContext* applicationMethodContext);

        virtual void call_CreateFile_Method(ApplicationMethodContext* applicationMethodContext);

        virtual void call_Delete_Method(ApplicationMethodContext* applicationMethodContext);

        virtual void call_MoveOrCopy_Method(ApplicationMethodContext* applicationMethodContext);
    
      private:
        ServerMethod::SPtr createDirectory_Method_;
        ServerMethod::SPtr createFile_Method_;
        ServerMethod::SPtr delete_Method_;
        ServerMethod::SPtr moveOrCopy_Method_;
   
   };

}

#endif
