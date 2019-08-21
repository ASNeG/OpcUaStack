/*
    ObjectTypeClass: NamespaceMetadataType

    Generated Source Code - please do not change this source code

    ObjectTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_NamespaceMetadataType_h__
#define __OpcUaStackServer_NamespaceMetadataType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"
#include "OpcUaStackServer/StandardObjectType/ObjectBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT NamespaceMetadataType
   : public ObjectBase
   {
     public:
       typedef boost::shared_ptr<NamespaceMetadataType> SPtr;
       typedef std::vector<NamespaceMetadataType::SPtr> Vec;
   
       NamespaceMetadataType(void);
       NamespaceMetadataType(const NamespaceMetadataType& value);
       virtual ~NamespaceMetadataType(void);

        //
        // UInt16
        //
        void defaultAccessRestrictions_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& defaultAccessRestrictions_Variable(void);
        bool get_DefaultAccessRestrictions_Variable(OpcUaDataValue& dataValue);
        bool set_DefaultAccessRestrictions_Variable(const OpcUaDataValue& dataValue);

        //
        // RolePermissionType (Array)
        //
        void defaultRolePermissions_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& defaultRolePermissions_Variable(void);
        bool get_DefaultRolePermissions_Variable(OpcUaDataValue& dataValue);
        bool set_DefaultRolePermissions_Variable(const OpcUaDataValue& dataValue);

        //
        // RolePermissionType (Array)
        //
        void defaultUserRolePermissions_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& defaultUserRolePermissions_Variable(void);
        bool get_DefaultUserRolePermissions_Variable(OpcUaDataValue& dataValue);
        bool set_DefaultUserRolePermissions_Variable(const OpcUaDataValue& dataValue);

        //
        // Boolean
        //
        void isNamespaceSubset_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& isNamespaceSubset_Variable(void);
        bool get_IsNamespaceSubset_Variable(OpcUaDataValue& dataValue);
        bool set_IsNamespaceSubset_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt16
        //
        void namespaceFile_OpenCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& namespaceFile_OpenCount_Variable(void);
        bool get_NamespaceFile_OpenCount_Variable(OpcUaDataValue& dataValue);
        bool set_NamespaceFile_OpenCount_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt64
        //
        void namespaceFile_Size_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& namespaceFile_Size_Variable(void);
        bool get_NamespaceFile_Size_Variable(OpcUaDataValue& dataValue);
        bool set_NamespaceFile_Size_Variable(const OpcUaDataValue& dataValue);

        //
        // Boolean
        //
        void namespaceFile_UserWritable_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& namespaceFile_UserWritable_Variable(void);
        bool get_NamespaceFile_UserWritable_Variable(OpcUaDataValue& dataValue);
        bool set_NamespaceFile_UserWritable_Variable(const OpcUaDataValue& dataValue);

        //
        // Boolean
        //
        void namespaceFile_Writable_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& namespaceFile_Writable_Variable(void);
        bool get_NamespaceFile_Writable_Variable(OpcUaDataValue& dataValue);
        bool set_NamespaceFile_Writable_Variable(const OpcUaDataValue& dataValue);

        //
        // DateTime
        //
        void namespacePublicationDate_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& namespacePublicationDate_Variable(void);
        bool get_NamespacePublicationDate_Variable(OpcUaDataValue& dataValue);
        bool set_NamespacePublicationDate_Variable(const OpcUaDataValue& dataValue);

        //
        // String
        //
        void namespaceUri_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& namespaceUri_Variable(void);
        bool get_NamespaceUri_Variable(OpcUaDataValue& dataValue);
        bool set_NamespaceUri_Variable(const OpcUaDataValue& dataValue);

        //
        // String
        //
        void namespaceVersion_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& namespaceVersion_Variable(void);
        bool get_NamespaceVersion_Variable(OpcUaDataValue& dataValue);
        bool set_NamespaceVersion_Variable(const OpcUaDataValue& dataValue);

        //
        // IdType (Array)
        //
        void staticNodeIdTypes_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& staticNodeIdTypes_Variable(void);
        bool get_StaticNodeIdTypes_Variable(OpcUaDataValue& dataValue);
        bool set_StaticNodeIdTypes_Variable(const OpcUaDataValue& dataValue);

        //
        // NumericRange (Array)
        //
        void staticNumericNodeIdRange_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& staticNumericNodeIdRange_Variable(void);
        bool get_StaticNumericNodeIdRange_Variable(OpcUaDataValue& dataValue);
        bool set_StaticNumericNodeIdRange_Variable(const OpcUaDataValue& dataValue);

        //
        // String
        //
        void staticStringNodeIdPattern_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& staticStringNodeIdPattern_Variable(void);
        bool get_StaticStringNodeIdPattern_Variable(OpcUaDataValue& dataValue);
        bool set_StaticStringNodeIdPattern_Variable(const OpcUaDataValue& dataValue);

        virtual void call_NamespaceFile_Close_Method(ApplicationMethodContext* applicationMethodContext);

        virtual void call_NamespaceFile_GetPosition_Method(ApplicationMethodContext* applicationMethodContext);

        virtual void call_NamespaceFile_Open_Method(ApplicationMethodContext* applicationMethodContext);

        virtual void call_NamespaceFile_Read_Method(ApplicationMethodContext* applicationMethodContext);

        virtual void call_NamespaceFile_SetPosition_Method(ApplicationMethodContext* applicationMethodContext);

        virtual void call_NamespaceFile_Write_Method(ApplicationMethodContext* applicationMethodContext);
    
      private:
        ServerVariable::SPtr defaultAccessRestrictions_Variable_;
        ServerVariable::SPtr defaultRolePermissions_Variable_;
        ServerVariable::SPtr defaultUserRolePermissions_Variable_;
        ServerVariable::SPtr isNamespaceSubset_Variable_;
        ServerVariable::SPtr namespaceFile_OpenCount_Variable_;
        ServerVariable::SPtr namespaceFile_Size_Variable_;
        ServerVariable::SPtr namespaceFile_UserWritable_Variable_;
        ServerVariable::SPtr namespaceFile_Writable_Variable_;
        ServerVariable::SPtr namespacePublicationDate_Variable_;
        ServerVariable::SPtr namespaceUri_Variable_;
        ServerVariable::SPtr namespaceVersion_Variable_;
        ServerVariable::SPtr staticNodeIdTypes_Variable_;
        ServerVariable::SPtr staticNumericNodeIdRange_Variable_;
        ServerVariable::SPtr staticStringNodeIdPattern_Variable_;
        ServerMethod::SPtr namespaceFile_Close_Method_;
        ServerMethod::SPtr namespaceFile_GetPosition_Method_;
        ServerMethod::SPtr namespaceFile_Open_Method_;
        ServerMethod::SPtr namespaceFile_Read_Method_;
        ServerMethod::SPtr namespaceFile_SetPosition_Method_;
        ServerMethod::SPtr namespaceFile_Write_Method_;
   
   };

}

#endif
