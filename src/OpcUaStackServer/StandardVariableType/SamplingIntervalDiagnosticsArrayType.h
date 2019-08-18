/*
    VariableTypeClass: SamplingIntervalDiagnosticsArrayType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_SamplingIntervalDiagnosticsArrayType_h__
#define __OpcUaStackServer_SamplingIntervalDiagnosticsArrayType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{
   
   class DLLEXPORT SamplingIntervalDiagnosticsArrayType
   : public VariableBase
   {
     public:
       typedef boost::shared_ptr<SamplingIntervalDiagnosticsArrayType> SPtr;
       typedef std::vector<SamplingIntervalDiagnosticsArrayType::SPtr> Vec;
   
       SamplingIntervalDiagnosticsArrayType(void);
       SamplingIntervalDiagnosticsArrayType(const SamplingIntervalDiagnosticsArrayType& value);
       virtual ~SamplingIntervalDiagnosticsArrayType(void);

        //
        // UInt32
        //
        void samplingIntervalDiagnostics_DisabledMonitoredItemsSamplingCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& samplingIntervalDiagnostics_DisabledMonitoredItemsSamplingCount_Variable(void);
        bool get_SamplingIntervalDiagnostics_DisabledMonitoredItemsSamplingCount_Variable(OpcUaDataValue& dataValue);
        bool set_SamplingIntervalDiagnostics_DisabledMonitoredItemsSamplingCount_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void samplingIntervalDiagnostics_MaxSampledMonitoredItemsCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& samplingIntervalDiagnostics_MaxSampledMonitoredItemsCount_Variable(void);
        bool get_SamplingIntervalDiagnostics_MaxSampledMonitoredItemsCount_Variable(OpcUaDataValue& dataValue);
        bool set_SamplingIntervalDiagnostics_MaxSampledMonitoredItemsCount_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void samplingIntervalDiagnostics_SampledMonitoredItemsCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& samplingIntervalDiagnostics_SampledMonitoredItemsCount_Variable(void);
        bool get_SamplingIntervalDiagnostics_SampledMonitoredItemsCount_Variable(OpcUaDataValue& dataValue);
        bool set_SamplingIntervalDiagnostics_SampledMonitoredItemsCount_Variable(const OpcUaDataValue& dataValue);

        //
        // Duration
        //
        void samplingIntervalDiagnostics_SamplingInterval_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& samplingIntervalDiagnostics_SamplingInterval_Variable(void);
        bool get_SamplingIntervalDiagnostics_SamplingInterval_Variable(OpcUaDataValue& dataValue);
        bool set_SamplingIntervalDiagnostics_SamplingInterval_Variable(const OpcUaDataValue& dataValue);

        //
        // SamplingIntervalDiagnosticsDataType
        //
        void samplingIntervalDiagnostics_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& samplingIntervalDiagnostics_Variable(void);
        bool get_SamplingIntervalDiagnostics_Variable(OpcUaDataValue& dataValue);
        bool set_SamplingIntervalDiagnostics_Variable(const OpcUaDataValue& dataValue);

        //
        // SamplingIntervalDiagnosticsDataType (Array)
        //
        void variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& variable(void);
        bool get_Variable(OpcUaDataValue& dataValue);
        bool set_Variable(const OpcUaDataValue& dataValue);
    
      private:
        ServerVariable::SPtr samplingIntervalDiagnostics_DisabledMonitoredItemsSamplingCount_Variable_;
        ServerVariable::SPtr samplingIntervalDiagnostics_MaxSampledMonitoredItemsCount_Variable_;
        ServerVariable::SPtr samplingIntervalDiagnostics_SampledMonitoredItemsCount_Variable_;
        ServerVariable::SPtr samplingIntervalDiagnostics_SamplingInterval_Variable_;
        ServerVariable::SPtr samplingIntervalDiagnostics_Variable_;
        ServerVariable::SPtr variable_;
   
   };

}

#endif
