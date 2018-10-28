/*
    VariableTypeClass: AnalogItemType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 3.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_AnalogItemType_h__
#define __OpcUaStackServer_AnalogItemType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackServer/VariableType/ServerVariables.h"
#include "OpcUaStackServer/StandardVariableType/DataItemType.h"

namespace OpcUaStackServer
{
    
    class DLLEXPORT AnalogItemType
    : public DataItemType
    {
      public:
        typedef boost::shared_ptr<AnalogItemType> SPtr;
    
        AnalogItemType(void);
        virtual ~AnalogItemType(void);
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
        
      private:
        std::string namespaceName_;
        uint16_t namespaceIndex_;
        ServerVariable::SPtr instrumentRange_;
        ServerVariable::SPtr eURange_;
        ServerVariable::SPtr engineeringUnits_;
    
    };

}

#endif
