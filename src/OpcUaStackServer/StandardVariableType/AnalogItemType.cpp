/*
    VariableTypeClass: AnalogItemType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardVariableType/AnalogItemType.h"

namespace OpcUaStackServer
{
    
    AnalogItemType::AnalogItemType(void)
    : VariableBase()
    , definition_Variable_(constructSPtr<ServerVariable>("Definition_Variable"))
    , eURange_Variable_(constructSPtr<ServerVariable>("EURange_Variable"))
    , engineeringUnits_Variable_(constructSPtr<ServerVariable>("EngineeringUnits_Variable"))
    , instrumentRange_Variable_(constructSPtr<ServerVariable>("InstrumentRange_Variable"))
    , valuePrecision_Variable_(constructSPtr<ServerVariable>("ValuePrecision_Variable"))
    , variable_(constructSPtr<ServerVariable>("Variable"))
    {
    }
    
    AnalogItemType::AnalogItemType(const AnalogItemType& value)
    : VariableBase()
    {
    }
    
    AnalogItemType::~AnalogItemType(void)
    {
    }

}
