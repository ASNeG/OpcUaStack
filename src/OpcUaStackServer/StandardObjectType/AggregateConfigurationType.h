/*
    ObjectTypeClass: AggregateConfigurationType

    Generated Source Code - please do not change this source code

    ObjectTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_AggregateConfigurationType_h__
#define __OpcUaStackServer_AggregateConfigurationType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"
#include "OpcUaStackServer/StandardObjectType/ObjectBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT AggregateConfigurationType
   : public ObjectBase
   {
     public:
       typedef boost::shared_ptr<AggregateConfigurationType> SPtr;
       typedef std::vector<AggregateConfigurationType::SPtr> Vec;
   
       AggregateConfigurationType(void);
       AggregateConfigurationType(const AggregateConfigurationType& value);
       virtual ~AggregateConfigurationType(void);

        //
        // Byte
        //
        void percentDataBad_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& percentDataBad_Variable(void);
        bool get_PercentDataBad_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_PercentDataBad_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Byte
        //
        void percentDataGood_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& percentDataGood_Variable(void);
        bool get_PercentDataGood_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_PercentDataGood_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Boolean
        //
        void treatUncertainAsBad_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& treatUncertainAsBad_Variable(void);
        bool get_TreatUncertainAsBad_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_TreatUncertainAsBad_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Boolean
        //
        void useSlopedExtrapolation_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& useSlopedExtrapolation_Variable(void);
        bool get_UseSlopedExtrapolation_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_UseSlopedExtrapolation_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);
    
      private:
        ServerVariable::SPtr percentDataBad_Variable_;
        ServerVariable::SPtr percentDataGood_Variable_;
        ServerVariable::SPtr treatUncertainAsBad_Variable_;
        ServerVariable::SPtr useSlopedExtrapolation_Variable_;
   
   };

}

#endif
