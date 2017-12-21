/*
    VariableTypeClass: SamplingIntervalDiagnosticsType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 3.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_SamplingIntervalDiagnosticsType_h__
#define __OpcUaStackServer_SamplingIntervalDiagnosticsType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackServer/VariableType/ServerVariables.h"
#include "OpcUaStackServer/StandardVariableType/BaseDataVariableType.h"

namespace OpcUaStackServer
{
    
    class DLLEXPORT SamplingIntervalDiagnosticsType
    : public BaseDataVariableType
    {
      public:
        typedef boost::shared_ptr<SamplingIntervalDiagnosticsType> SPtr;
    
        SamplingIntervalDiagnosticsType(void);
        virtual ~SamplingIntervalDiagnosticsType(void);
        virtual bool linkInstanceWithModel(const OpcUaNodeId& nodeId);
        
        BaseNodeClass::SPtr samplingInterval(void);
        bool setSamplingInterval(const OpcUaDataValue& dataValue);
        bool getSamplingInterval(OpcUaDataValue& dataValue);
        void setUpdateCallbackSamplingInterval(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr sampledMonitoredItemsCount(void);
        bool setSampledMonitoredItemsCount(const OpcUaDataValue& dataValue);
        bool getSampledMonitoredItemsCount(OpcUaDataValue& dataValue);
        void setUpdateCallbackSampledMonitoredItemsCount(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr maxSampledMonitoredItemsCount(void);
        bool setMaxSampledMonitoredItemsCount(const OpcUaDataValue& dataValue);
        bool getMaxSampledMonitoredItemsCount(OpcUaDataValue& dataValue);
        void setUpdateCallbackMaxSampledMonitoredItemsCount(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr disabledMonitoredItemsSamplingCount(void);
        bool setDisabledMonitoredItemsSamplingCount(const OpcUaDataValue& dataValue);
        bool getDisabledMonitoredItemsSamplingCount(OpcUaDataValue& dataValue);
        void setUpdateCallbackDisabledMonitoredItemsSamplingCount(Callback::SPtr& callback);
        
      private:
        std::string namespaceName_;
        uint16_t namespaceIndex_;
        ServerVariable::SPtr samplingInterval_;
        ServerVariable::SPtr sampledMonitoredItemsCount_;
        ServerVariable::SPtr maxSampledMonitoredItemsCount_;
        ServerVariable::SPtr disabledMonitoredItemsSamplingCount_;
    
    };

}

#endif
