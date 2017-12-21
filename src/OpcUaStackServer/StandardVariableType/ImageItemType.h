/*
    VariableTypeClass: ImageItemType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 3.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_ImageItemType_h__
#define __OpcUaStackServer_ImageItemType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackServer/VariableType/ServerVariables.h"
#include "OpcUaStackServer/StandardVariableType/ArrayItemType.h"

namespace OpcUaStackServer
{
    
    class DLLEXPORT ImageItemType
    : public ArrayItemType
    {
      public:
        typedef boost::shared_ptr<ImageItemType> SPtr;
    
        ImageItemType(void);
        virtual ~ImageItemType(void);
        virtual bool linkInstanceWithModel(const OpcUaNodeId& nodeId);
        
        BaseNodeClass::SPtr xAxisDefinition(void);
        bool setXAxisDefinition(const OpcUaDataValue& dataValue);
        bool getXAxisDefinition(OpcUaDataValue& dataValue);
        void setUpdateCallbackXAxisDefinition(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr yAxisDefinition(void);
        bool setYAxisDefinition(const OpcUaDataValue& dataValue);
        bool getYAxisDefinition(OpcUaDataValue& dataValue);
        void setUpdateCallbackYAxisDefinition(Callback::SPtr& callback);
        
      private:
        std::string namespaceName_;
        uint16_t namespaceIndex_;
        ServerVariable::SPtr xAxisDefinition_;
        ServerVariable::SPtr yAxisDefinition_;
    
    };

}

#endif
