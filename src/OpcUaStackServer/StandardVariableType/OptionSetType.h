/*
    VariableTypeClass: OptionSetType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 3.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_OptionSetType_h__
#define __OpcUaStackServer_OptionSetType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackServer/VariableType/ServerVariables.h"
#include "OpcUaStackServer/StandardVariableType/BaseDataVariableType.h"

namespace OpcUaStackServer
{
    
    class DLLEXPORT OptionSetType
    : public BaseDataVariableType
    {
      public:
        typedef boost::shared_ptr<OptionSetType> SPtr;
    
        OptionSetType(void);
        virtual ~OptionSetType(void);
        virtual bool linkInstanceWithModel(const OpcUaNodeId& nodeId);
        
        BaseNodeClass::SPtr optionSetValues(void);
        bool setOptionSetValues(const OpcUaDataValue& dataValue);
        bool getOptionSetValues(OpcUaDataValue& dataValue);
        void setUpdateCallbackOptionSetValues(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr bitMask(void);
        bool setBitMask(const OpcUaDataValue& dataValue);
        bool getBitMask(OpcUaDataValue& dataValue);
        void setUpdateCallbackBitMask(Callback::SPtr& callback);
        
      private:
        std::string namespaceName_;
        uint16_t namespaceIndex_;
        ServerVariable::SPtr optionSetValues_;
        ServerVariable::SPtr bitMask_;
    
    };

}

#endif
