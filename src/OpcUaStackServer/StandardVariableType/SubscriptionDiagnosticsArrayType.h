/*
    VariableTypeClass: SubscriptionDiagnosticsArrayType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_SubscriptionDiagnosticsArrayType_h__
#define __OpcUaStackServer_SubscriptionDiagnosticsArrayType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackServer/VariableType/VariableBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT SubscriptionDiagnosticsArrayType
   : public VariableBase
   {
     public:
       typedef boost::shared_ptr<SubscriptionDiagnosticsArrayType> SPtr;
       typedef std::vector<SubscriptionDiagnosticsArrayType::SPtr> Vec;
   
       SubscriptionDiagnosticsArrayType(void);
       SubscriptionDiagnosticsArrayType(const SubscriptionDiagnosticsArrayType& value);
       virtual ~SubscriptionDiagnosticsArrayType(void);

        void variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& variable(void);
        bool get_Variable(OpcUaDataValue& dataValue);
        bool set_Variable(const OpcUaDataValue& dataValue);
    
      private:
        ServerVariable::SPtr variable_;
   
   };

}

#endif
