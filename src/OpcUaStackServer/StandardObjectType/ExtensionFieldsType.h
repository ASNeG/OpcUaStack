/*
    ObjectTypeClass: ExtensionFieldsType

    Generated Source Code - please do not change this source code

    ObjectTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_ExtensionFieldsType_h__
#define __OpcUaStackServer_ExtensionFieldsType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"
#include "OpcUaStackServer/StandardObjectType/ObjectBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT ExtensionFieldsType
   : public ObjectBase
   {
     public:
       typedef boost::shared_ptr<ExtensionFieldsType> SPtr;
       typedef std::vector<ExtensionFieldsType::SPtr> Vec;
   
       ExtensionFieldsType(void);
       ExtensionFieldsType(const ExtensionFieldsType& value);
       virtual ~ExtensionFieldsType(void);

        virtual void call_AddExtensionField_Method(OpcUaStackCore::ApplicationMethodContext* applicationMethodContext);

        virtual void call_RemoveExtensionField_Method(OpcUaStackCore::ApplicationMethodContext* applicationMethodContext);
    
      private:
        ServerMethod::SPtr addExtensionField_Method_;
        ServerMethod::SPtr removeExtensionField_Method_;
   
   };

}

#endif
