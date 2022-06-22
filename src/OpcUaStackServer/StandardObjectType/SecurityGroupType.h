/*
    ObjectTypeClass: SecurityGroupType

    Generated Source Code - please do not change this source code

    ObjectTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_SecurityGroupType_h__
#define __OpcUaStackServer_SecurityGroupType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"
#include "OpcUaStackServer/StandardObjectType/ObjectBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT SecurityGroupType
   : public ObjectBase
   {
     public:
       typedef boost::shared_ptr<SecurityGroupType> SPtr;
       typedef std::vector<SecurityGroupType::SPtr> Vec;
   
       SecurityGroupType(void);
       SecurityGroupType(const SecurityGroupType& value);
       virtual ~SecurityGroupType(void);

        //
        // Duration
        //
        void keyLifetime_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& keyLifetime_Variable(void);
        bool get_KeyLifetime_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_KeyLifetime_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void maxFutureKeyCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& maxFutureKeyCount_Variable(void);
        bool get_MaxFutureKeyCount_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_MaxFutureKeyCount_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void maxPastKeyCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& maxPastKeyCount_Variable(void);
        bool get_MaxPastKeyCount_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_MaxPastKeyCount_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // String
        //
        void securityGroupId_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& securityGroupId_Variable(void);
        bool get_SecurityGroupId_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_SecurityGroupId_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // String
        //
        void securityPolicyUri_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& securityPolicyUri_Variable(void);
        bool get_SecurityPolicyUri_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_SecurityPolicyUri_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);
    
      private:
        ServerVariable::SPtr keyLifetime_Variable_;
        ServerVariable::SPtr maxFutureKeyCount_Variable_;
        ServerVariable::SPtr maxPastKeyCount_Variable_;
        ServerVariable::SPtr securityGroupId_Variable_;
        ServerVariable::SPtr securityPolicyUri_Variable_;
   
   };

}

#endif
