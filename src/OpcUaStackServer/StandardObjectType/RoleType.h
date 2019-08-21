/*
    ObjectTypeClass: RoleType

    Generated Source Code - please do not change this source code

    ObjectTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_RoleType_h__
#define __OpcUaStackServer_RoleType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"
#include "OpcUaStackServer/StandardObjectType/ObjectBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT RoleType
   : public ObjectBase
   {
     public:
       typedef boost::shared_ptr<RoleType> SPtr;
       typedef std::vector<RoleType::SPtr> Vec;
   
       RoleType(void);
       RoleType(const RoleType& value);
       virtual ~RoleType(void);

        //
        // Boolean
        //
        void applicationsExclude_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& applicationsExclude_Variable(void);
        bool get_ApplicationsExclude_Variable(OpcUaDataValue& dataValue);
        bool set_ApplicationsExclude_Variable(const OpcUaDataValue& dataValue);

        //
        // String (Array)
        //
        void applications_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& applications_Variable(void);
        bool get_Applications_Variable(OpcUaDataValue& dataValue);
        bool set_Applications_Variable(const OpcUaDataValue& dataValue);

        //
        // Boolean
        //
        void endpointsExclude_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& endpointsExclude_Variable(void);
        bool get_EndpointsExclude_Variable(OpcUaDataValue& dataValue);
        bool set_EndpointsExclude_Variable(const OpcUaDataValue& dataValue);

        //
        // EndpointType (Array)
        //
        void endpoints_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& endpoints_Variable(void);
        bool get_Endpoints_Variable(OpcUaDataValue& dataValue);
        bool set_Endpoints_Variable(const OpcUaDataValue& dataValue);

        //
        // IdentityMappingRuleType (Array)
        //
        void identities_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& identities_Variable(void);
        bool get_Identities_Variable(OpcUaDataValue& dataValue);
        bool set_Identities_Variable(const OpcUaDataValue& dataValue);

        virtual void call_AddApplication_Method(ApplicationMethodContext* applicationMethodContext);

        virtual void call_AddEndpoint_Method(ApplicationMethodContext* applicationMethodContext);

        virtual void call_AddIdentity_Method(ApplicationMethodContext* applicationMethodContext);

        virtual void call_RemoveApplication_Method(ApplicationMethodContext* applicationMethodContext);

        virtual void call_RemoveEndpoint_Method(ApplicationMethodContext* applicationMethodContext);

        virtual void call_RemoveIdentity_Method(ApplicationMethodContext* applicationMethodContext);
    
      private:
        ServerVariable::SPtr applicationsExclude_Variable_;
        ServerVariable::SPtr applications_Variable_;
        ServerVariable::SPtr endpointsExclude_Variable_;
        ServerVariable::SPtr endpoints_Variable_;
        ServerVariable::SPtr identities_Variable_;
        ServerMethod::SPtr addApplication_Method_;
        ServerMethod::SPtr addEndpoint_Method_;
        ServerMethod::SPtr addIdentity_Method_;
        ServerMethod::SPtr removeApplication_Method_;
        ServerMethod::SPtr removeEndpoint_Method_;
        ServerMethod::SPtr removeIdentity_Method_;
   
   };

}

#endif
