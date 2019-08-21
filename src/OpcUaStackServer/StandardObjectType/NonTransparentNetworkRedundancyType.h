/*
    ObjectTypeClass: NonTransparentNetworkRedundancyType

    Generated Source Code - please do not change this source code

    ObjectTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_NonTransparentNetworkRedundancyType_h__
#define __OpcUaStackServer_NonTransparentNetworkRedundancyType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"
#include "OpcUaStackServer/StandardObjectType/ObjectBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT NonTransparentNetworkRedundancyType
   : public ObjectBase
   {
     public:
       typedef boost::shared_ptr<NonTransparentNetworkRedundancyType> SPtr;
       typedef std::vector<NonTransparentNetworkRedundancyType::SPtr> Vec;
   
       NonTransparentNetworkRedundancyType(void);
       NonTransparentNetworkRedundancyType(const NonTransparentNetworkRedundancyType& value);
       virtual ~NonTransparentNetworkRedundancyType(void);

        //
        // RedundancySupport
        //
        void redundancySupport_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& redundancySupport_Variable(void);
        bool get_RedundancySupport_Variable(OpcUaDataValue& dataValue);
        bool set_RedundancySupport_Variable(const OpcUaDataValue& dataValue);

        //
        // NetworkGroupDataType (Array)
        //
        void serverNetworkGroups_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& serverNetworkGroups_Variable(void);
        bool get_ServerNetworkGroups_Variable(OpcUaDataValue& dataValue);
        bool set_ServerNetworkGroups_Variable(const OpcUaDataValue& dataValue);

        //
        // String (Array)
        //
        void serverUriArray_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& serverUriArray_Variable(void);
        bool get_ServerUriArray_Variable(OpcUaDataValue& dataValue);
        bool set_ServerUriArray_Variable(const OpcUaDataValue& dataValue);
    
      private:
        ServerVariable::SPtr redundancySupport_Variable_;
        ServerVariable::SPtr serverNetworkGroups_Variable_;
        ServerVariable::SPtr serverUriArray_Variable_;
   
   };

}

#endif
