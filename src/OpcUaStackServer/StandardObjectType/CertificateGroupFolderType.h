/*
    ObjectTypeClass: CertificateGroupFolderType

    Generated Source Code - please do not change this source code

    ObjectTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_CertificateGroupFolderType_h__
#define __OpcUaStackServer_CertificateGroupFolderType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"
#include "OpcUaStackServer/StandardObjectType/ObjectBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT CertificateGroupFolderType
   : public ObjectBase
   {
     public:
       typedef boost::shared_ptr<CertificateGroupFolderType> SPtr;
       typedef std::vector<CertificateGroupFolderType::SPtr> Vec;
   
       CertificateGroupFolderType(void);
       CertificateGroupFolderType(const CertificateGroupFolderType& value);
       virtual ~CertificateGroupFolderType(void);

        //
        // NodeId (Array)
        //
        void defaultApplicationGroup_CertificateTypes_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& defaultApplicationGroup_CertificateTypes_Variable(void);
        bool get_DefaultApplicationGroup_CertificateTypes_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_DefaultApplicationGroup_CertificateTypes_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UtcTime
        //
        void defaultApplicationGroup_TrustList_LastUpdateTime_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& defaultApplicationGroup_TrustList_LastUpdateTime_Variable(void);
        bool get_DefaultApplicationGroup_TrustList_LastUpdateTime_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_DefaultApplicationGroup_TrustList_LastUpdateTime_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UInt16
        //
        void defaultApplicationGroup_TrustList_OpenCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& defaultApplicationGroup_TrustList_OpenCount_Variable(void);
        bool get_DefaultApplicationGroup_TrustList_OpenCount_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_DefaultApplicationGroup_TrustList_OpenCount_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UInt64
        //
        void defaultApplicationGroup_TrustList_Size_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& defaultApplicationGroup_TrustList_Size_Variable(void);
        bool get_DefaultApplicationGroup_TrustList_Size_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_DefaultApplicationGroup_TrustList_Size_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Boolean
        //
        void defaultApplicationGroup_TrustList_UserWritable_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& defaultApplicationGroup_TrustList_UserWritable_Variable(void);
        bool get_DefaultApplicationGroup_TrustList_UserWritable_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_DefaultApplicationGroup_TrustList_UserWritable_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Boolean
        //
        void defaultApplicationGroup_TrustList_Writable_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& defaultApplicationGroup_TrustList_Writable_Variable(void);
        bool get_DefaultApplicationGroup_TrustList_Writable_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_DefaultApplicationGroup_TrustList_Writable_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // NodeId (Array)
        //
        void defaultHttpsGroup_CertificateTypes_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& defaultHttpsGroup_CertificateTypes_Variable(void);
        bool get_DefaultHttpsGroup_CertificateTypes_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_DefaultHttpsGroup_CertificateTypes_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UtcTime
        //
        void defaultHttpsGroup_TrustList_LastUpdateTime_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& defaultHttpsGroup_TrustList_LastUpdateTime_Variable(void);
        bool get_DefaultHttpsGroup_TrustList_LastUpdateTime_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_DefaultHttpsGroup_TrustList_LastUpdateTime_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UInt16
        //
        void defaultHttpsGroup_TrustList_OpenCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& defaultHttpsGroup_TrustList_OpenCount_Variable(void);
        bool get_DefaultHttpsGroup_TrustList_OpenCount_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_DefaultHttpsGroup_TrustList_OpenCount_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UInt64
        //
        void defaultHttpsGroup_TrustList_Size_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& defaultHttpsGroup_TrustList_Size_Variable(void);
        bool get_DefaultHttpsGroup_TrustList_Size_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_DefaultHttpsGroup_TrustList_Size_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Boolean
        //
        void defaultHttpsGroup_TrustList_UserWritable_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& defaultHttpsGroup_TrustList_UserWritable_Variable(void);
        bool get_DefaultHttpsGroup_TrustList_UserWritable_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_DefaultHttpsGroup_TrustList_UserWritable_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Boolean
        //
        void defaultHttpsGroup_TrustList_Writable_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& defaultHttpsGroup_TrustList_Writable_Variable(void);
        bool get_DefaultHttpsGroup_TrustList_Writable_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_DefaultHttpsGroup_TrustList_Writable_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // NodeId (Array)
        //
        void defaultUserTokenGroup_CertificateTypes_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& defaultUserTokenGroup_CertificateTypes_Variable(void);
        bool get_DefaultUserTokenGroup_CertificateTypes_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_DefaultUserTokenGroup_CertificateTypes_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UtcTime
        //
        void defaultUserTokenGroup_TrustList_LastUpdateTime_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& defaultUserTokenGroup_TrustList_LastUpdateTime_Variable(void);
        bool get_DefaultUserTokenGroup_TrustList_LastUpdateTime_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_DefaultUserTokenGroup_TrustList_LastUpdateTime_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UInt16
        //
        void defaultUserTokenGroup_TrustList_OpenCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& defaultUserTokenGroup_TrustList_OpenCount_Variable(void);
        bool get_DefaultUserTokenGroup_TrustList_OpenCount_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_DefaultUserTokenGroup_TrustList_OpenCount_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UInt64
        //
        void defaultUserTokenGroup_TrustList_Size_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& defaultUserTokenGroup_TrustList_Size_Variable(void);
        bool get_DefaultUserTokenGroup_TrustList_Size_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_DefaultUserTokenGroup_TrustList_Size_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Boolean
        //
        void defaultUserTokenGroup_TrustList_UserWritable_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& defaultUserTokenGroup_TrustList_UserWritable_Variable(void);
        bool get_DefaultUserTokenGroup_TrustList_UserWritable_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_DefaultUserTokenGroup_TrustList_UserWritable_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Boolean
        //
        void defaultUserTokenGroup_TrustList_Writable_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& defaultUserTokenGroup_TrustList_Writable_Variable(void);
        bool get_DefaultUserTokenGroup_TrustList_Writable_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_DefaultUserTokenGroup_TrustList_Writable_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        virtual void call_DefaultApplicationGroup_TrustList_Close_Method(OpcUaStackCore::ApplicationMethodContext* applicationMethodContext);

        virtual void call_DefaultApplicationGroup_TrustList_GetPosition_Method(OpcUaStackCore::ApplicationMethodContext* applicationMethodContext);

        virtual void call_DefaultApplicationGroup_TrustList_OpenWithMasks_Method(OpcUaStackCore::ApplicationMethodContext* applicationMethodContext);

        virtual void call_DefaultApplicationGroup_TrustList_Open_Method(OpcUaStackCore::ApplicationMethodContext* applicationMethodContext);

        virtual void call_DefaultApplicationGroup_TrustList_Read_Method(OpcUaStackCore::ApplicationMethodContext* applicationMethodContext);

        virtual void call_DefaultApplicationGroup_TrustList_SetPosition_Method(OpcUaStackCore::ApplicationMethodContext* applicationMethodContext);

        virtual void call_DefaultApplicationGroup_TrustList_Write_Method(OpcUaStackCore::ApplicationMethodContext* applicationMethodContext);

        virtual void call_DefaultHttpsGroup_TrustList_Close_Method(OpcUaStackCore::ApplicationMethodContext* applicationMethodContext);

        virtual void call_DefaultHttpsGroup_TrustList_GetPosition_Method(OpcUaStackCore::ApplicationMethodContext* applicationMethodContext);

        virtual void call_DefaultHttpsGroup_TrustList_OpenWithMasks_Method(OpcUaStackCore::ApplicationMethodContext* applicationMethodContext);

        virtual void call_DefaultHttpsGroup_TrustList_Open_Method(OpcUaStackCore::ApplicationMethodContext* applicationMethodContext);

        virtual void call_DefaultHttpsGroup_TrustList_Read_Method(OpcUaStackCore::ApplicationMethodContext* applicationMethodContext);

        virtual void call_DefaultHttpsGroup_TrustList_SetPosition_Method(OpcUaStackCore::ApplicationMethodContext* applicationMethodContext);

        virtual void call_DefaultHttpsGroup_TrustList_Write_Method(OpcUaStackCore::ApplicationMethodContext* applicationMethodContext);

        virtual void call_DefaultUserTokenGroup_TrustList_Close_Method(OpcUaStackCore::ApplicationMethodContext* applicationMethodContext);

        virtual void call_DefaultUserTokenGroup_TrustList_GetPosition_Method(OpcUaStackCore::ApplicationMethodContext* applicationMethodContext);

        virtual void call_DefaultUserTokenGroup_TrustList_OpenWithMasks_Method(OpcUaStackCore::ApplicationMethodContext* applicationMethodContext);

        virtual void call_DefaultUserTokenGroup_TrustList_Open_Method(OpcUaStackCore::ApplicationMethodContext* applicationMethodContext);

        virtual void call_DefaultUserTokenGroup_TrustList_Read_Method(OpcUaStackCore::ApplicationMethodContext* applicationMethodContext);

        virtual void call_DefaultUserTokenGroup_TrustList_SetPosition_Method(OpcUaStackCore::ApplicationMethodContext* applicationMethodContext);

        virtual void call_DefaultUserTokenGroup_TrustList_Write_Method(OpcUaStackCore::ApplicationMethodContext* applicationMethodContext);
    
      private:
        ServerVariable::SPtr defaultApplicationGroup_CertificateTypes_Variable_;
        ServerVariable::SPtr defaultApplicationGroup_TrustList_LastUpdateTime_Variable_;
        ServerVariable::SPtr defaultApplicationGroup_TrustList_OpenCount_Variable_;
        ServerVariable::SPtr defaultApplicationGroup_TrustList_Size_Variable_;
        ServerVariable::SPtr defaultApplicationGroup_TrustList_UserWritable_Variable_;
        ServerVariable::SPtr defaultApplicationGroup_TrustList_Writable_Variable_;
        ServerVariable::SPtr defaultHttpsGroup_CertificateTypes_Variable_;
        ServerVariable::SPtr defaultHttpsGroup_TrustList_LastUpdateTime_Variable_;
        ServerVariable::SPtr defaultHttpsGroup_TrustList_OpenCount_Variable_;
        ServerVariable::SPtr defaultHttpsGroup_TrustList_Size_Variable_;
        ServerVariable::SPtr defaultHttpsGroup_TrustList_UserWritable_Variable_;
        ServerVariable::SPtr defaultHttpsGroup_TrustList_Writable_Variable_;
        ServerVariable::SPtr defaultUserTokenGroup_CertificateTypes_Variable_;
        ServerVariable::SPtr defaultUserTokenGroup_TrustList_LastUpdateTime_Variable_;
        ServerVariable::SPtr defaultUserTokenGroup_TrustList_OpenCount_Variable_;
        ServerVariable::SPtr defaultUserTokenGroup_TrustList_Size_Variable_;
        ServerVariable::SPtr defaultUserTokenGroup_TrustList_UserWritable_Variable_;
        ServerVariable::SPtr defaultUserTokenGroup_TrustList_Writable_Variable_;
        ServerMethod::SPtr defaultApplicationGroup_TrustList_Close_Method_;
        ServerMethod::SPtr defaultApplicationGroup_TrustList_GetPosition_Method_;
        ServerMethod::SPtr defaultApplicationGroup_TrustList_OpenWithMasks_Method_;
        ServerMethod::SPtr defaultApplicationGroup_TrustList_Open_Method_;
        ServerMethod::SPtr defaultApplicationGroup_TrustList_Read_Method_;
        ServerMethod::SPtr defaultApplicationGroup_TrustList_SetPosition_Method_;
        ServerMethod::SPtr defaultApplicationGroup_TrustList_Write_Method_;
        ServerMethod::SPtr defaultHttpsGroup_TrustList_Close_Method_;
        ServerMethod::SPtr defaultHttpsGroup_TrustList_GetPosition_Method_;
        ServerMethod::SPtr defaultHttpsGroup_TrustList_OpenWithMasks_Method_;
        ServerMethod::SPtr defaultHttpsGroup_TrustList_Open_Method_;
        ServerMethod::SPtr defaultHttpsGroup_TrustList_Read_Method_;
        ServerMethod::SPtr defaultHttpsGroup_TrustList_SetPosition_Method_;
        ServerMethod::SPtr defaultHttpsGroup_TrustList_Write_Method_;
        ServerMethod::SPtr defaultUserTokenGroup_TrustList_Close_Method_;
        ServerMethod::SPtr defaultUserTokenGroup_TrustList_GetPosition_Method_;
        ServerMethod::SPtr defaultUserTokenGroup_TrustList_OpenWithMasks_Method_;
        ServerMethod::SPtr defaultUserTokenGroup_TrustList_Open_Method_;
        ServerMethod::SPtr defaultUserTokenGroup_TrustList_Read_Method_;
        ServerMethod::SPtr defaultUserTokenGroup_TrustList_SetPosition_Method_;
        ServerMethod::SPtr defaultUserTokenGroup_TrustList_Write_Method_;
   
   };

}

#endif
