/*
    VariableTypeClass: SamplingIntervalDiagnosticsType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_SamplingIntervalDiagnosticsType_h__
#define __OpcUaStackServer_SamplingIntervalDiagnosticsType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT SamplingIntervalDiagnosticsType
   : public VariableBase
   {
     public:
       typedef boost::shared_ptr<SamplingIntervalDiagnosticsType> SPtr;
       typedef std::vector<SamplingIntervalDiagnosticsType::SPtr> Vec;
   
       SamplingIntervalDiagnosticsType(void);
       SamplingIntervalDiagnosticsType(const SamplingIntervalDiagnosticsType& value);
       virtual ~SamplingIntervalDiagnosticsType(void);

        //
        // UInt32
        //
        void disabledMonitoredItemsSamplingCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& disabledMonitoredItemsSamplingCount_Variable(void);
        bool get_DisabledMonitoredItemsSamplingCount_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_DisabledMonitoredItemsSamplingCount_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void maxSampledMonitoredItemsCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& maxSampledMonitoredItemsCount_Variable(void);
        bool get_MaxSampledMonitoredItemsCount_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_MaxSampledMonitoredItemsCount_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void sampledMonitoredItemsCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& sampledMonitoredItemsCount_Variable(void);
        bool get_SampledMonitoredItemsCount_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_SampledMonitoredItemsCount_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Duration
        //
        void samplingInterval_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& samplingInterval_Variable(void);
        bool get_SamplingInterval_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_SamplingInterval_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // SamplingIntervalDiagnosticsDataType (Array)
        //
        void variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& variable(void);
        bool get_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);
    
      private:
        ServerVariable::SPtr disabledMonitoredItemsSamplingCount_Variable_;
        ServerVariable::SPtr maxSampledMonitoredItemsCount_Variable_;
        ServerVariable::SPtr sampledMonitoredItemsCount_Variable_;
        ServerVariable::SPtr samplingInterval_Variable_;
        ServerVariable::SPtr variable_;
   
   };

}

#endif
