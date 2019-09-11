/*
    ObjectTypeClass: HistoricalDataConfigurationType

    Generated Source Code - please do not change this source code

    ObjectTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_HistoricalDataConfigurationType_h__
#define __OpcUaStackServer_HistoricalDataConfigurationType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"
#include "OpcUaStackServer/StandardObjectType/ObjectBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT HistoricalDataConfigurationType
   : public ObjectBase
   {
     public:
       typedef boost::shared_ptr<HistoricalDataConfigurationType> SPtr;
       typedef std::vector<HistoricalDataConfigurationType::SPtr> Vec;
   
       HistoricalDataConfigurationType(void);
       HistoricalDataConfigurationType(const HistoricalDataConfigurationType& value);
       virtual ~HistoricalDataConfigurationType(void);

        //
        // Byte
        //
        void aggregateConfiguration_PercentDataBad_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& aggregateConfiguration_PercentDataBad_Variable(void);
        bool get_AggregateConfiguration_PercentDataBad_Variable(OpcUaDataValue& dataValue);
        bool set_AggregateConfiguration_PercentDataBad_Variable(const OpcUaDataValue& dataValue);

        //
        // Byte
        //
        void aggregateConfiguration_PercentDataGood_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& aggregateConfiguration_PercentDataGood_Variable(void);
        bool get_AggregateConfiguration_PercentDataGood_Variable(OpcUaDataValue& dataValue);
        bool set_AggregateConfiguration_PercentDataGood_Variable(const OpcUaDataValue& dataValue);

        //
        // Boolean
        //
        void aggregateConfiguration_TreatUncertainAsBad_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& aggregateConfiguration_TreatUncertainAsBad_Variable(void);
        bool get_AggregateConfiguration_TreatUncertainAsBad_Variable(OpcUaDataValue& dataValue);
        bool set_AggregateConfiguration_TreatUncertainAsBad_Variable(const OpcUaDataValue& dataValue);

        //
        // Boolean
        //
        void aggregateConfiguration_UseSlopedExtrapolation_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& aggregateConfiguration_UseSlopedExtrapolation_Variable(void);
        bool get_AggregateConfiguration_UseSlopedExtrapolation_Variable(OpcUaDataValue& dataValue);
        bool set_AggregateConfiguration_UseSlopedExtrapolation_Variable(const OpcUaDataValue& dataValue);

        //
        // String
        //
        void definition_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& definition_Variable(void);
        bool get_Definition_Variable(OpcUaDataValue& dataValue);
        bool set_Definition_Variable(const OpcUaDataValue& dataValue);

        //
        // ExceptionDeviationFormat
        //
        void exceptionDeviationFormat_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& exceptionDeviationFormat_Variable(void);
        bool get_ExceptionDeviationFormat_Variable(OpcUaDataValue& dataValue);
        bool set_ExceptionDeviationFormat_Variable(const OpcUaDataValue& dataValue);

        //
        // Double
        //
        void exceptionDeviation_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& exceptionDeviation_Variable(void);
        bool get_ExceptionDeviation_Variable(OpcUaDataValue& dataValue);
        bool set_ExceptionDeviation_Variable(const OpcUaDataValue& dataValue);

        //
        // Duration
        //
        void maxTimeInterval_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& maxTimeInterval_Variable(void);
        bool get_MaxTimeInterval_Variable(OpcUaDataValue& dataValue);
        bool set_MaxTimeInterval_Variable(const OpcUaDataValue& dataValue);

        //
        // Duration
        //
        void minTimeInterval_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& minTimeInterval_Variable(void);
        bool get_MinTimeInterval_Variable(OpcUaDataValue& dataValue);
        bool set_MinTimeInterval_Variable(const OpcUaDataValue& dataValue);

        //
        // UtcTime
        //
        void startOfArchive_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& startOfArchive_Variable(void);
        bool get_StartOfArchive_Variable(OpcUaDataValue& dataValue);
        bool set_StartOfArchive_Variable(const OpcUaDataValue& dataValue);

        //
        // UtcTime
        //
        void startOfOnlineArchive_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& startOfOnlineArchive_Variable(void);
        bool get_StartOfOnlineArchive_Variable(OpcUaDataValue& dataValue);
        bool set_StartOfOnlineArchive_Variable(const OpcUaDataValue& dataValue);

        //
        // Boolean
        //
        void stepped_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& stepped_Variable(void);
        bool get_Stepped_Variable(OpcUaDataValue& dataValue);
        bool set_Stepped_Variable(const OpcUaDataValue& dataValue);
    
      private:
        ServerVariable::SPtr aggregateConfiguration_PercentDataBad_Variable_;
        ServerVariable::SPtr aggregateConfiguration_PercentDataGood_Variable_;
        ServerVariable::SPtr aggregateConfiguration_TreatUncertainAsBad_Variable_;
        ServerVariable::SPtr aggregateConfiguration_UseSlopedExtrapolation_Variable_;
        ServerVariable::SPtr definition_Variable_;
        ServerVariable::SPtr exceptionDeviationFormat_Variable_;
        ServerVariable::SPtr exceptionDeviation_Variable_;
        ServerVariable::SPtr maxTimeInterval_Variable_;
        ServerVariable::SPtr minTimeInterval_Variable_;
        ServerVariable::SPtr startOfArchive_Variable_;
        ServerVariable::SPtr startOfOnlineArchive_Variable_;
        ServerVariable::SPtr stepped_Variable_;
   
   };

}

#endif
