/*
    VariableTypeClass: DataTypeDictionaryType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 3.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_DataTypeDictionaryType_h__
#define __OpcUaStackServer_DataTypeDictionaryType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackServer/VariableType/ServerVariables.h"
#include "OpcUaStackServer/StandardVariableType/BaseDataVariableType.h"

namespace OpcUaStackServer
{
    
    class DLLEXPORT DataTypeDictionaryType
    : public BaseDataVariableType
    {
      public:
        typedef boost::shared_ptr<DataTypeDictionaryType> SPtr;
    
        DataTypeDictionaryType(void);
        virtual ~DataTypeDictionaryType(void);
        virtual bool linkInstanceWithModel(const OpcUaNodeId& nodeId);
        
        BaseNodeClass::SPtr dataTypeVersion(void);
        bool setDataTypeVersion(const OpcUaDataValue& dataValue);
        bool getDataTypeVersion(OpcUaDataValue& dataValue);
        void setUpdateCallbackDataTypeVersion(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr namespaceUri(void);
        bool setNamespaceUri(const OpcUaDataValue& dataValue);
        bool getNamespaceUri(OpcUaDataValue& dataValue);
        void setUpdateCallbackNamespaceUri(Callback::SPtr& callback);
        
      private:
        std::string namespaceName_;
        uint16_t namespaceIndex_;
        ServerVariable::SPtr dataTypeVersion_;
        ServerVariable::SPtr namespaceUri_;
    
    };

}

#endif
