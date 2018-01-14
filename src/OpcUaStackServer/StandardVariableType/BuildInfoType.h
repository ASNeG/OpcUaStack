/*
    VariableTypeClass: BuildInfoType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 3.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_BuildInfoType_h__
#define __OpcUaStackServer_BuildInfoType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackServer/VariableType/ServerVariables.h"
#include "OpcUaStackServer/StandardVariableType/BaseDataVariableType.h"

namespace OpcUaStackServer
{
    
    class DLLEXPORT BuildInfoType
    : public BaseDataVariableType
    {
      public:
        typedef boost::shared_ptr<BuildInfoType> SPtr;
    
        BuildInfoType(void);
        virtual ~BuildInfoType(void);
        virtual bool linkInstanceWithModel(const OpcUaNodeId& nodeId);
        
        BaseNodeClass::SPtr productUri(void);
        bool setProductUri(const OpcUaDataValue& dataValue);
        bool getProductUri(OpcUaDataValue& dataValue);
        void setUpdateCallbackProductUri(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr manufacturerName(void);
        bool setManufacturerName(const OpcUaDataValue& dataValue);
        bool getManufacturerName(OpcUaDataValue& dataValue);
        void setUpdateCallbackManufacturerName(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr productName(void);
        bool setProductName(const OpcUaDataValue& dataValue);
        bool getProductName(OpcUaDataValue& dataValue);
        void setUpdateCallbackProductName(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr softwareVersion(void);
        bool setSoftwareVersion(const OpcUaDataValue& dataValue);
        bool getSoftwareVersion(OpcUaDataValue& dataValue);
        void setUpdateCallbackSoftwareVersion(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr buildNumber(void);
        bool setBuildNumber(const OpcUaDataValue& dataValue);
        bool getBuildNumber(OpcUaDataValue& dataValue);
        void setUpdateCallbackBuildNumber(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr buildDate(void);
        bool setBuildDate(const OpcUaDataValue& dataValue);
        bool getBuildDate(OpcUaDataValue& dataValue);
        void setUpdateCallbackBuildDate(Callback::SPtr& callback);
        
      private:
        std::string namespaceName_;
        uint16_t namespaceIndex_;
        ServerVariable::SPtr productUri_;
        ServerVariable::SPtr manufacturerName_;
        ServerVariable::SPtr productName_;
        ServerVariable::SPtr softwareVersion_;
        ServerVariable::SPtr buildNumber_;
        ServerVariable::SPtr buildDate_;
    
    };

}

#endif
