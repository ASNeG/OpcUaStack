/*
    ObjectTypeClass: ServerCapabilitiesType

    Generated Source Code - please do not change this source code

    ObjectTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_ServerCapabilitiesType_h__
#define __OpcUaStackServer_ServerCapabilitiesType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"
#include "OpcUaStackServer/StandardObjectType/ObjectBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT ServerCapabilitiesType
   : public ObjectBase
   {
     public:
       typedef boost::shared_ptr<ServerCapabilitiesType> SPtr;
       typedef std::vector<ServerCapabilitiesType::SPtr> Vec;
   
       ServerCapabilitiesType(void);
       ServerCapabilitiesType(const ServerCapabilitiesType& value);
       virtual ~ServerCapabilitiesType(void);

        //
        // LocaleId (Array)
        //
        void localeIdArray_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& localeIdArray_Variable(void);
        bool get_LocaleIdArray_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_LocaleIdArray_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void maxArrayLength_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& maxArrayLength_Variable(void);
        bool get_MaxArrayLength_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_MaxArrayLength_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UInt16
        //
        void maxBrowseContinuationPoints_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& maxBrowseContinuationPoints_Variable(void);
        bool get_MaxBrowseContinuationPoints_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_MaxBrowseContinuationPoints_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void maxByteStringLength_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& maxByteStringLength_Variable(void);
        bool get_MaxByteStringLength_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_MaxByteStringLength_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UInt16
        //
        void maxHistoryContinuationPoints_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& maxHistoryContinuationPoints_Variable(void);
        bool get_MaxHistoryContinuationPoints_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_MaxHistoryContinuationPoints_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UInt16
        //
        void maxQueryContinuationPoints_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& maxQueryContinuationPoints_Variable(void);
        bool get_MaxQueryContinuationPoints_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_MaxQueryContinuationPoints_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void maxStringLength_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& maxStringLength_Variable(void);
        bool get_MaxStringLength_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_MaxStringLength_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Duration
        //
        void minSupportedSampleRate_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& minSupportedSampleRate_Variable(void);
        bool get_MinSupportedSampleRate_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_MinSupportedSampleRate_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // String (Array)
        //
        void serverProfileArray_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& serverProfileArray_Variable(void);
        bool get_ServerProfileArray_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ServerProfileArray_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // SignedSoftwareCertificate (Array)
        //
        void softwareCertificates_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& softwareCertificates_Variable(void);
        bool get_SoftwareCertificates_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_SoftwareCertificates_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        virtual void call_RoleSet_AddRole_Method(OpcUaStackCore::ApplicationMethodContext* applicationMethodContext);

        virtual void call_RoleSet_RemoveRole_Method(OpcUaStackCore::ApplicationMethodContext* applicationMethodContext);
    
      private:
        ServerVariable::SPtr localeIdArray_Variable_;
        ServerVariable::SPtr maxArrayLength_Variable_;
        ServerVariable::SPtr maxBrowseContinuationPoints_Variable_;
        ServerVariable::SPtr maxByteStringLength_Variable_;
        ServerVariable::SPtr maxHistoryContinuationPoints_Variable_;
        ServerVariable::SPtr maxQueryContinuationPoints_Variable_;
        ServerVariable::SPtr maxStringLength_Variable_;
        ServerVariable::SPtr minSupportedSampleRate_Variable_;
        ServerVariable::SPtr serverProfileArray_Variable_;
        ServerVariable::SPtr softwareCertificates_Variable_;
        ServerMethod::SPtr roleSet_AddRole_Method_;
        ServerMethod::SPtr roleSet_RemoveRole_Method_;
   
   };

}

#endif
