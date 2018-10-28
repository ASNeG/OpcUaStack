/*
    VariableTypeClass: DataTypeDescriptionType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 3.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_DataTypeDescriptionType_h__
#define __OpcUaStackServer_DataTypeDescriptionType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackServer/VariableType/ServerVariables.h"
#include "OpcUaStackServer/StandardVariableType/BaseDataVariableType.h"

namespace OpcUaStackServer
{
    
    class DLLEXPORT DataTypeDescriptionType
    : public BaseDataVariableType
    {
      public:
        typedef boost::shared_ptr<DataTypeDescriptionType> SPtr;
    
        DataTypeDescriptionType(void);
        virtual ~DataTypeDescriptionType(void);
        virtual bool linkInstanceWithModel(const OpcUaNodeId& nodeId);
        
        BaseNodeClass::SPtr dataTypeVersion(void);
        bool setDataTypeVersion(const OpcUaDataValue& dataValue);
        bool getDataTypeVersion(OpcUaDataValue& dataValue);
        void setUpdateCallbackDataTypeVersion(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr dictionaryFragment(void);
        bool setDictionaryFragment(const OpcUaDataValue& dataValue);
        bool getDictionaryFragment(OpcUaDataValue& dataValue);
        void setUpdateCallbackDictionaryFragment(Callback::SPtr& callback);
        
      private:
        std::string namespaceName_;
        uint16_t namespaceIndex_;
        ServerVariable::SPtr dataTypeVersion_;
        ServerVariable::SPtr dictionaryFragment_;
    
    };

}

#endif
