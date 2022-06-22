/*
    ObjectTypeClass: ModellingRuleType

    Generated Source Code - please do not change this source code

    ObjectTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_ModellingRuleType_h__
#define __OpcUaStackServer_ModellingRuleType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"
#include "OpcUaStackServer/StandardObjectType/ObjectBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT ModellingRuleType
   : public ObjectBase
   {
     public:
       typedef boost::shared_ptr<ModellingRuleType> SPtr;
       typedef std::vector<ModellingRuleType::SPtr> Vec;
   
       ModellingRuleType(void);
       ModellingRuleType(const ModellingRuleType& value);
       virtual ~ModellingRuleType(void);

        //
        // NamingRuleType
        //
        void namingRule_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& namingRule_Variable(void);
        bool get_NamingRule_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_NamingRule_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);
    
      private:
        ServerVariable::SPtr namingRule_Variable_;
   
   };

}

#endif
