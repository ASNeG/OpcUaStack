/*
    EnumTypeClass: OverrideValueHandling

    Generated Source Code - please do not change this source code

    EnumTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/OverrideValueHandling.h"

namespace OpcUaStackCore
{
    
    OverrideValueHandling::OverrideValueHandling(void)
    : Object()
    , ExtensionObjectBase()
    , value_(0)
    {
    }
    
    OverrideValueHandling::OverrideValueHandling(Enum enumeration)
    : Object()
    , ExtensionObjectBase()
    , value_(enumeration)
    {
    }
    
    OverrideValueHandling::~OverrideValueHandling(void)
    {
    }
    
    uint32_t&
    OverrideValueHandling::value(void)
    {
        return value_;
    }
    
    void
    OverrideValueHandling::enumeration(OverrideValueHandling::Enum enumeration)
    {
        value_ = enumeration;
    }
    
    OverrideValueHandling::Enum
    OverrideValueHandling::enumeration(void)
    {
        return (Enum)value_;
    }
    
    OverrideValueHandling::Enum
    OverrideValueHandling::str2Enum(const std::string& enumerationString)
    {
        if (enumerationString == "Disabled") return (Enum)0;
        if (enumerationString == "LastUseableValue") return (Enum)1;
        if (enumerationString == "OverrideValue") return (Enum)2;
        return (Enum)0;
    }
    
    std::string
    OverrideValueHandling::enum2Str(Enum enumeration)
    {
        if (enumeration == 0) return "Disabled";
        if (enumeration == 1) return "LastUseableValue";
        if (enumeration == 2) return "OverrideValue";
        return "Unknown";
    }
    
    bool
    OverrideValueHandling::exist(const std::string& enumerationString)
    {
        if (enumerationString == "Disabled") return true;
        if (enumerationString == "LastUseableValue") return true;
        if (enumerationString == "OverrideValue") return true;
        return false;
    }
    
    bool
    OverrideValueHandling::exist(Enum enumeration)
    {
        if (enumeration == 0) return true;
        if (enumeration == 1) return true;
        if (enumeration == 2) return true;
        return false;
    }
    
    bool
    OverrideValueHandling::operator==(const OverrideValueHandling& value) const
    {
        if (value_ != value.value_) return false;
        return true;
    }
    
    bool
    OverrideValueHandling::operator!=(const OverrideValueHandling& value) const
    {
        return !this->operator==(value);
    }
    
    void
    OverrideValueHandling::copyTo(OverrideValueHandling& value)
    {
        value.value_ = value_;
    }
    
    // ------------------------------------------------------------------------
    // ------------------------------------------------------------------------
    //
    // ExtensionObjectBase
    //
    // ------------------------------------------------------------------------
    // ------------------------------------------------------------------------
    
    ExtensionObjectBase::SPtr
    OverrideValueHandling::factory(void)
    {
    	return constructSPtr<OverrideValueHandling>();
    }
    
    OpcUaNodeId
    OverrideValueHandling::binaryTypeId(void)
    {
    	return OpcUaNodeId(0, 0);
    }
    
    OpcUaNodeId
    OverrideValueHandling::xmlTypeId(void)
    {
    	return OpcUaNodeId(0, 0);
    }
    
    void
    OverrideValueHandling::opcUaBinaryEncode(std::ostream& os) const
    {
        OpcUaNumber::opcUaBinaryEncode(os, value_);
    }
    
    void
    OverrideValueHandling::opcUaBinaryDecode(std::istream& is)
    {
        OpcUaNumber::opcUaBinaryDecode(is, value_);
    }
    
    bool
    OverrideValueHandling::encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const
    {
    }
    
    bool
    OverrideValueHandling::decode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
    }
    
    bool
    OverrideValueHandling::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
    }
    
    bool
    OverrideValueHandling::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
    }
    
    bool
    OverrideValueHandling::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
    }
    
    void
    OverrideValueHandling::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	OverrideValueHandling* dst = dynamic_cast<OverrideValueHandling*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    OverrideValueHandling::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	OverrideValueHandling* dst = dynamic_cast<OverrideValueHandling*>(&extensionObjectBase);
    	return *this == *dst;
    }
    
    void
    OverrideValueHandling::out(std::ostream& os)
    {
        os << "Value=" << value_;
    }

}
