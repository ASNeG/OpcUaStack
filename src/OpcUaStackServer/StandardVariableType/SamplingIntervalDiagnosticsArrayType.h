/*
    VariableTypeClass: SamplingIntervalDiagnosticsArrayType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_SamplingIntervalDiagnosticsArrayType_h__
#define __OpcUaStackServer_SamplingIntervalDiagnosticsArrayType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackServer/StandardVariableType/VariableBase.h"

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
        // SamplingIntervalDiagnosticsDataType (Array)
        //
        void variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& variable(void);
        bool get_Variable(OpcUaDataValue& dataValue);
        bool set_Variable(const OpcUaDataValue& dataValue);
    
      private:
        ServerVariable::SPtr variable_;
   
   };

}

#endif
