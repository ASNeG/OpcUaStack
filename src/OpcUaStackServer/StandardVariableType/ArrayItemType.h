/*
    VariableTypeClass: ArrayItemType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 3.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_ArrayItemType_h__
#define __OpcUaStackServer_ArrayItemType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackServer/VariableType/ServerVariables.h"
#include "OpcUaStackServer/StandardVariableType/DataItemType.h"

namespace OpcUaStackServer
{
    
    class DLLEXPORT ArrayItemType
    : public DataItemType
    {
      public:
        typedef boost::shared_ptr<ArrayItemType> SPtr;
    
        ArrayItemType(void);
        virtual ~ArrayItemType(void);
        virtual bool linkInstanceWithModel(const OpcUaNodeId& nodeId);
        
        BaseNodeClass::SPtr instrumentRange(void);
        bool setInstrumentRange(const OpcUaDataValue& dataValue);
        bool getInstrumentRange(OpcUaDataValue& dataValue);
        void setUpdateCallbackInstrumentRange(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr eURange(void);
        bool setEURange(const OpcUaDataValue& dataValue);
        bool getEURange(OpcUaDataValue& dataValue);
        void setUpdateCallbackEURange(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr engineeringUnits(void);
        bool setEngineeringUnits(const OpcUaDataValue& dataValue);
        bool getEngineeringUnits(OpcUaDataValue& dataValue);
        void setUpdateCallbackEngineeringUnits(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr title(void);
        bool setTitle(const OpcUaDataValue& dataValue);
        bool getTitle(OpcUaDataValue& dataValue);
        void setUpdateCallbackTitle(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr axisScaleType(void);
        bool setAxisScaleType(const OpcUaDataValue& dataValue);
        bool getAxisScaleType(OpcUaDataValue& dataValue);
        void setUpdateCallbackAxisScaleType(Callback::SPtr& callback);
        
      private:
        std::string namespaceName_;
        uint16_t namespaceIndex_;
        ServerVariable::SPtr instrumentRange_;
        ServerVariable::SPtr eURange_;
        ServerVariable::SPtr engineeringUnits_;
        ServerVariable::SPtr title_;
        ServerVariable::SPtr axisScaleType_;
    
    };

}

#endif
