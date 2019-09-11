/*
    ObjectTypeClass: CertificateGroupType

    Generated Source Code - please do not change this source code

    ObjectTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_CertificateGroupType_h__
#define __OpcUaStackServer_CertificateGroupType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"
#include "OpcUaStackServer/StandardObjectType/ObjectBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT CertificateGroupType
   : public ObjectBase
   {
     public:
       typedef boost::shared_ptr<CertificateGroupType> SPtr;
       typedef std::vector<CertificateGroupType::SPtr> Vec;
   
       CertificateGroupType(void);
       CertificateGroupType(const CertificateGroupType& value);
       virtual ~CertificateGroupType(void);

        //
        // NodeId (Array)
        //
        void certificateTypes_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& certificateTypes_Variable(void);
        bool get_CertificateTypes_Variable(OpcUaDataValue& dataValue);
        bool set_CertificateTypes_Variable(const OpcUaDataValue& dataValue);

        //
        // UtcTime
        //
        void trustList_LastUpdateTime_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& trustList_LastUpdateTime_Variable(void);
        bool get_TrustList_LastUpdateTime_Variable(OpcUaDataValue& dataValue);
        bool set_TrustList_LastUpdateTime_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt16
        //
        void trustList_OpenCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& trustList_OpenCount_Variable(void);
        bool get_TrustList_OpenCount_Variable(OpcUaDataValue& dataValue);
        bool set_TrustList_OpenCount_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt64
        //
        void trustList_Size_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& trustList_Size_Variable(void);
        bool get_TrustList_Size_Variable(OpcUaDataValue& dataValue);
        bool set_TrustList_Size_Variable(const OpcUaDataValue& dataValue);

        //
        // Boolean
        //
        void trustList_UserWritable_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& trustList_UserWritable_Variable(void);
        bool get_TrustList_UserWritable_Variable(OpcUaDataValue& dataValue);
        bool set_TrustList_UserWritable_Variable(const OpcUaDataValue& dataValue);

        //
        // Boolean
        //
        void trustList_Writable_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& trustList_Writable_Variable(void);
        bool get_TrustList_Writable_Variable(OpcUaDataValue& dataValue);
        bool set_TrustList_Writable_Variable(const OpcUaDataValue& dataValue);

        virtual void call_TrustList_Close_Method(ApplicationMethodContext* applicationMethodContext);

        virtual void call_TrustList_GetPosition_Method(ApplicationMethodContext* applicationMethodContext);

        virtual void call_TrustList_OpenWithMasks_Method(ApplicationMethodContext* applicationMethodContext);

        virtual void call_TrustList_Open_Method(ApplicationMethodContext* applicationMethodContext);

        virtual void call_TrustList_Read_Method(ApplicationMethodContext* applicationMethodContext);

        virtual void call_TrustList_SetPosition_Method(ApplicationMethodContext* applicationMethodContext);

        virtual void call_TrustList_Write_Method(ApplicationMethodContext* applicationMethodContext);
    
      private:
        ServerVariable::SPtr certificateTypes_Variable_;
        ServerVariable::SPtr trustList_LastUpdateTime_Variable_;
        ServerVariable::SPtr trustList_OpenCount_Variable_;
        ServerVariable::SPtr trustList_Size_Variable_;
        ServerVariable::SPtr trustList_UserWritable_Variable_;
        ServerVariable::SPtr trustList_Writable_Variable_;
        ServerMethod::SPtr trustList_Close_Method_;
        ServerMethod::SPtr trustList_GetPosition_Method_;
        ServerMethod::SPtr trustList_OpenWithMasks_Method_;
        ServerMethod::SPtr trustList_Open_Method_;
        ServerMethod::SPtr trustList_Read_Method_;
        ServerMethod::SPtr trustList_SetPosition_Method_;
        ServerMethod::SPtr trustList_Write_Method_;
   
   };

}

#endif
