/*
    ObjectTypeClass: NonTransparentRedundancyType

    Generated Source Code - please do not change this source code

    ObjectTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_NonTransparentRedundancyType_h__
#define __OpcUaStackServer_NonTransparentRedundancyType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"
#include "OpcUaStackServer/StandardObjectType/ObjectBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT NonTransparentRedundancyType
   : public ObjectBase
   {
     public:
       typedef boost::shared_ptr<NonTransparentRedundancyType> SPtr;
       typedef std::vector<NonTransparentRedundancyType::SPtr> Vec;
   
       NonTransparentRedundancyType(void);
       NonTransparentRedundancyType(const NonTransparentRedundancyType& value);
       virtual ~NonTransparentRedundancyType(void);

        //
        // RedundancySupport
        //
        void redundancySupport_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& redundancySupport_Variable(void);
        bool get_RedundancySupport_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_RedundancySupport_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // String (Array)
        //
        void serverUriArray_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& serverUriArray_Variable(void);
        bool get_ServerUriArray_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ServerUriArray_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);
    
      private:
        ServerVariable::SPtr redundancySupport_Variable_;
        ServerVariable::SPtr serverUriArray_Variable_;
   
   };

}

#endif
