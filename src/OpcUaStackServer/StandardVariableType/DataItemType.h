/*
    VariableTypeClass: DataItemType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 3.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_DataItemType_h__
#define __OpcUaStackServer_DataItemType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackServer/VariableType/ServerVariables.h"
#include "OpcUaStackServer/StandardVariableType/BaseDataVariableType.h"

namespace OpcUaStackServer
{
    
    class DLLEXPORT DataItemType
    : public BaseDataVariableType
    {
      public:
        typedef boost::shared_ptr<DataItemType> SPtr;
    
        DataItemType(void);
        virtual ~DataItemType(void);
        virtual bool linkInstanceWithModel(const OpcUaNodeId& nodeId);
        
        BaseNodeClass::SPtr definition(void);
        bool setDefinition(const OpcUaDataValue& dataValue);
        bool getDefinition(OpcUaDataValue& dataValue);
        void setUpdateCallbackDefinition(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr valuePrecision(void);
        bool setValuePrecision(const OpcUaDataValue& dataValue);
        bool getValuePrecision(OpcUaDataValue& dataValue);
        void setUpdateCallbackValuePrecision(Callback::SPtr& callback);
        
      private:
        std::string namespaceName_;
        uint16_t namespaceIndex_;
        ServerVariable::SPtr definition_;
        ServerVariable::SPtr valuePrecision_;
    
    };

}

#endif
