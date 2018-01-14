/*
    VariableTypeClass: ServerStatusType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 3.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_ServerStatusType_h__
#define __OpcUaStackServer_ServerStatusType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackServer/VariableType/ServerVariables.h"
#include "OpcUaStackServer/StandardVariableType/BaseDataVariableType.h"

namespace OpcUaStackServer
{
    
    class DLLEXPORT ServerStatusType
    : public BaseDataVariableType
    {
      public:
        typedef boost::shared_ptr<ServerStatusType> SPtr;
    
        ServerStatusType(void);
        virtual ~ServerStatusType(void);
        virtual bool linkInstanceWithModel(const OpcUaNodeId& nodeId);
        
        BaseNodeClass::SPtr startTime(void);
        bool setStartTime(const OpcUaDataValue& dataValue);
        bool getStartTime(OpcUaDataValue& dataValue);
        void setUpdateCallbackStartTime(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr currentTime(void);
        bool setCurrentTime(const OpcUaDataValue& dataValue);
        bool getCurrentTime(OpcUaDataValue& dataValue);
        void setUpdateCallbackCurrentTime(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr state(void);
        bool setState(const OpcUaDataValue& dataValue);
        bool getState(OpcUaDataValue& dataValue);
        void setUpdateCallbackState(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr buildInfo(void);
        bool setBuildInfo(const OpcUaDataValue& dataValue);
        bool getBuildInfo(OpcUaDataValue& dataValue);
        void setUpdateCallbackBuildInfo(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr buildInfo_ProductUri(void);
        bool setProductUri(const OpcUaDataValue& dataValue);
        bool getProductUri(OpcUaDataValue& dataValue);
        void setUpdateCallbackProductUri(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr buildInfo_ManufacturerName(void);
        bool setManufacturerName(const OpcUaDataValue& dataValue);
        bool getManufacturerName(OpcUaDataValue& dataValue);
        void setUpdateCallbackManufacturerName(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr buildInfo_ProductName(void);
        bool setProductName(const OpcUaDataValue& dataValue);
        bool getProductName(OpcUaDataValue& dataValue);
        void setUpdateCallbackProductName(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr buildInfo_SoftwareVersion(void);
        bool setSoftwareVersion(const OpcUaDataValue& dataValue);
        bool getSoftwareVersion(OpcUaDataValue& dataValue);
        void setUpdateCallbackSoftwareVersion(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr buildInfo_BuildNumber(void);
        bool setBuildNumber(const OpcUaDataValue& dataValue);
        bool getBuildNumber(OpcUaDataValue& dataValue);
        void setUpdateCallbackBuildNumber(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr buildInfo_BuildDate(void);
        bool setBuildDate(const OpcUaDataValue& dataValue);
        bool getBuildDate(OpcUaDataValue& dataValue);
        void setUpdateCallbackBuildDate(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr secondsTillShutdown(void);
        bool setSecondsTillShutdown(const OpcUaDataValue& dataValue);
        bool getSecondsTillShutdown(OpcUaDataValue& dataValue);
        void setUpdateCallbackSecondsTillShutdown(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr shutdownReason(void);
        bool setShutdownReason(const OpcUaDataValue& dataValue);
        bool getShutdownReason(OpcUaDataValue& dataValue);
        void setUpdateCallbackShutdownReason(Callback::SPtr& callback);
        
      private:
        std::string namespaceName_;
        uint16_t namespaceIndex_;
        ServerVariable::SPtr startTime_;
        ServerVariable::SPtr currentTime_;
        ServerVariable::SPtr state_;
        ServerVariable::SPtr buildInfo_;
        ServerVariable::SPtr buildInfo_ProductUri_;
        ServerVariable::SPtr buildInfo_ManufacturerName_;
        ServerVariable::SPtr buildInfo_ProductName_;
        ServerVariable::SPtr buildInfo_SoftwareVersion_;
        ServerVariable::SPtr buildInfo_BuildNumber_;
        ServerVariable::SPtr buildInfo_BuildDate_;
        ServerVariable::SPtr secondsTillShutdown_;
        ServerVariable::SPtr shutdownReason_;
    
    };

}

#endif
