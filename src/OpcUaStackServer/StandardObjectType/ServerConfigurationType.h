/*
    ObjectTypeClass: ServerConfigurationType

    Generated Source Code - please do not change this source code

    ObjectTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_ServerConfigurationType_h__
#define __OpcUaStackServer_ServerConfigurationType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"
#include "OpcUaStackServer/StandardObjectType/ObjectBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT ServerConfigurationType
   : public ObjectBase
   {
     public:
       typedef boost::shared_ptr<ServerConfigurationType> SPtr;
       typedef std::vector<ServerConfigurationType::SPtr> Vec;
   
       ServerConfigurationType(void);
       ServerConfigurationType(const ServerConfigurationType& value);
       virtual ~ServerConfigurationType(void);

        //
        // NodeId (Array)
        //
        void certificateGroups_DefaultApplicationGroup_CertificateTypes_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& certificateGroups_DefaultApplicationGroup_CertificateTypes_Variable(void);
        bool get_CertificateGroups_DefaultApplicationGroup_CertificateTypes_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_CertificateGroups_DefaultApplicationGroup_CertificateTypes_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UtcTime
        //
        void certificateGroups_DefaultApplicationGroup_TrustList_LastUpdateTime_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& certificateGroups_DefaultApplicationGroup_TrustList_LastUpdateTime_Variable(void);
        bool get_CertificateGroups_DefaultApplicationGroup_TrustList_LastUpdateTime_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_CertificateGroups_DefaultApplicationGroup_TrustList_LastUpdateTime_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UInt16
        //
        void certificateGroups_DefaultApplicationGroup_TrustList_OpenCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& certificateGroups_DefaultApplicationGroup_TrustList_OpenCount_Variable(void);
        bool get_CertificateGroups_DefaultApplicationGroup_TrustList_OpenCount_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_CertificateGroups_DefaultApplicationGroup_TrustList_OpenCount_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UInt64
        //
        void certificateGroups_DefaultApplicationGroup_TrustList_Size_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& certificateGroups_DefaultApplicationGroup_TrustList_Size_Variable(void);
        bool get_CertificateGroups_DefaultApplicationGroup_TrustList_Size_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_CertificateGroups_DefaultApplicationGroup_TrustList_Size_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Boolean
        //
        void certificateGroups_DefaultApplicationGroup_TrustList_UserWritable_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& certificateGroups_DefaultApplicationGroup_TrustList_UserWritable_Variable(void);
        bool get_CertificateGroups_DefaultApplicationGroup_TrustList_UserWritable_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_CertificateGroups_DefaultApplicationGroup_TrustList_UserWritable_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Boolean
        //
        void certificateGroups_DefaultApplicationGroup_TrustList_Writable_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& certificateGroups_DefaultApplicationGroup_TrustList_Writable_Variable(void);
        bool get_CertificateGroups_DefaultApplicationGroup_TrustList_Writable_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_CertificateGroups_DefaultApplicationGroup_TrustList_Writable_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void maxTrustListSize_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& maxTrustListSize_Variable(void);
        bool get_MaxTrustListSize_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_MaxTrustListSize_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Boolean
        //
        void multicastDnsEnabled_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& multicastDnsEnabled_Variable(void);
        bool get_MulticastDnsEnabled_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_MulticastDnsEnabled_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // String (Array)
        //
        void serverCapabilities_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& serverCapabilities_Variable(void);
        bool get_ServerCapabilities_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ServerCapabilities_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // String (Array)
        //
        void supportedPrivateKeyFormats_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& supportedPrivateKeyFormats_Variable(void);
        bool get_SupportedPrivateKeyFormats_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_SupportedPrivateKeyFormats_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        virtual void call_ApplyChanges_Method(OpcUaStackCore::ApplicationMethodContext* applicationMethodContext);

        virtual void call_CertificateGroups_DefaultApplicationGroup_TrustList_Close_Method(OpcUaStackCore::ApplicationMethodContext* applicationMethodContext);

        virtual void call_CertificateGroups_DefaultApplicationGroup_TrustList_GetPosition_Method(OpcUaStackCore::ApplicationMethodContext* applicationMethodContext);

        virtual void call_CertificateGroups_DefaultApplicationGroup_TrustList_OpenWithMasks_Method(OpcUaStackCore::ApplicationMethodContext* applicationMethodContext);

        virtual void call_CertificateGroups_DefaultApplicationGroup_TrustList_Open_Method(OpcUaStackCore::ApplicationMethodContext* applicationMethodContext);

        virtual void call_CertificateGroups_DefaultApplicationGroup_TrustList_Read_Method(OpcUaStackCore::ApplicationMethodContext* applicationMethodContext);

        virtual void call_CertificateGroups_DefaultApplicationGroup_TrustList_SetPosition_Method(OpcUaStackCore::ApplicationMethodContext* applicationMethodContext);

        virtual void call_CertificateGroups_DefaultApplicationGroup_TrustList_Write_Method(OpcUaStackCore::ApplicationMethodContext* applicationMethodContext);

        virtual void call_CreateSigningRequest_Method(OpcUaStackCore::ApplicationMethodContext* applicationMethodContext);

        virtual void call_GetRejectedList_Method(OpcUaStackCore::ApplicationMethodContext* applicationMethodContext);

        virtual void call_UpdateCertificate_Method(OpcUaStackCore::ApplicationMethodContext* applicationMethodContext);
    
      private:
        ServerVariable::SPtr certificateGroups_DefaultApplicationGroup_CertificateTypes_Variable_;
        ServerVariable::SPtr certificateGroups_DefaultApplicationGroup_TrustList_LastUpdateTime_Variable_;
        ServerVariable::SPtr certificateGroups_DefaultApplicationGroup_TrustList_OpenCount_Variable_;
        ServerVariable::SPtr certificateGroups_DefaultApplicationGroup_TrustList_Size_Variable_;
        ServerVariable::SPtr certificateGroups_DefaultApplicationGroup_TrustList_UserWritable_Variable_;
        ServerVariable::SPtr certificateGroups_DefaultApplicationGroup_TrustList_Writable_Variable_;
        ServerVariable::SPtr maxTrustListSize_Variable_;
        ServerVariable::SPtr multicastDnsEnabled_Variable_;
        ServerVariable::SPtr serverCapabilities_Variable_;
        ServerVariable::SPtr supportedPrivateKeyFormats_Variable_;
        ServerMethod::SPtr applyChanges_Method_;
        ServerMethod::SPtr certificateGroups_DefaultApplicationGroup_TrustList_Close_Method_;
        ServerMethod::SPtr certificateGroups_DefaultApplicationGroup_TrustList_GetPosition_Method_;
        ServerMethod::SPtr certificateGroups_DefaultApplicationGroup_TrustList_OpenWithMasks_Method_;
        ServerMethod::SPtr certificateGroups_DefaultApplicationGroup_TrustList_Open_Method_;
        ServerMethod::SPtr certificateGroups_DefaultApplicationGroup_TrustList_Read_Method_;
        ServerMethod::SPtr certificateGroups_DefaultApplicationGroup_TrustList_SetPosition_Method_;
        ServerMethod::SPtr certificateGroups_DefaultApplicationGroup_TrustList_Write_Method_;
        ServerMethod::SPtr createSigningRequest_Method_;
        ServerMethod::SPtr getRejectedList_Method_;
        ServerMethod::SPtr updateCertificate_Method_;
   
   };

}

#endif
