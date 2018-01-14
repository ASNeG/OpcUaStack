/*
    VariableTypeClass: MultiStateValueDiscreteType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 3.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_MultiStateValueDiscreteType_h__
#define __OpcUaStackServer_MultiStateValueDiscreteType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackServer/VariableType/ServerVariables.h"
#include "OpcUaStackServer/StandardVariableType/DiscreteItemType.h"

namespace OpcUaStackServer
{
    
    class DLLEXPORT MultiStateValueDiscreteType
    : public DiscreteItemType
    {
      public:
        typedef boost::shared_ptr<MultiStateValueDiscreteType> SPtr;
    
        MultiStateValueDiscreteType(void);
        virtual ~MultiStateValueDiscreteType(void);
        virtual bool linkInstanceWithModel(const OpcUaNodeId& nodeId);
        
        BaseNodeClass::SPtr enumValues(void);
        bool setEnumValues(const OpcUaDataValue& dataValue);
        bool getEnumValues(OpcUaDataValue& dataValue);
        void setUpdateCallbackEnumValues(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr valueAsText(void);
        bool setValueAsText(const OpcUaDataValue& dataValue);
        bool getValueAsText(OpcUaDataValue& dataValue);
        void setUpdateCallbackValueAsText(Callback::SPtr& callback);
        
      private:
        std::string namespaceName_;
        uint16_t namespaceIndex_;
        ServerVariable::SPtr enumValues_;
        ServerVariable::SPtr valueAsText_;
    
    };

}

#endif
