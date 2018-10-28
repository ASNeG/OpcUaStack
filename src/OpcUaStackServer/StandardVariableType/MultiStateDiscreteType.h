/*
    VariableTypeClass: MultiStateDiscreteType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 3.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_MultiStateDiscreteType_h__
#define __OpcUaStackServer_MultiStateDiscreteType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackServer/VariableType/ServerVariables.h"
#include "OpcUaStackServer/StandardVariableType/DiscreteItemType.h"

namespace OpcUaStackServer
{
    
    class DLLEXPORT MultiStateDiscreteType
    : public DiscreteItemType
    {
      public:
        typedef boost::shared_ptr<MultiStateDiscreteType> SPtr;
    
        MultiStateDiscreteType(void);
        virtual ~MultiStateDiscreteType(void);
        virtual bool linkInstanceWithModel(const OpcUaNodeId& nodeId);
        
        BaseNodeClass::SPtr enumStrings(void);
        bool setEnumStrings(const OpcUaDataValue& dataValue);
        bool getEnumStrings(OpcUaDataValue& dataValue);
        void setUpdateCallbackEnumStrings(Callback::SPtr& callback);
        
      private:
        std::string namespaceName_;
        uint16_t namespaceIndex_;
        ServerVariable::SPtr enumStrings_;
    
    };

}

#endif
