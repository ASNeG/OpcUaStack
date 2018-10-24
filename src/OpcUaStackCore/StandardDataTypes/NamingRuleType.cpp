/*
    EnumTypeClass: NamingRuleType

    Generated Source Code - please do not change this source code

    EnumTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/NamingRuleType.h"

namespace OpcUaStackCore
{
    
    NamingRuleType::NamingRuleType(void)
    : Object()
    , ExtensionObjectBase()
    , value_(0)
    {
    }
    
    NamingRuleType::~NamingRuleType(void)
    {
    }
    
    uint32_t&
    NamingRuleType::value(void)
    {
        return value_;
    }
    
    void
    NamingRuleType::enumeration(NamingRuleType::Enum enumeration)
    {
        value_ = enumeration;
    }
    
    NamingRuleType::Enum
    NamingRuleType::enumeration(void)
    {
        return (Enum)value_;
    }
    
    NamingRuleType::Enum
    NamingRuleType::str2Enum(const std::string& enumerationString)
    {
        if (enumerationString == "Mandatory") return (Enum)1;
        if (enumerationString == "Optional") return (Enum)2;
        if (enumerationString == "Constraint") return (Enum)3;
        return (Enum)0;
    }
    
    std::string
    NamingRuleType::enum2Str(Enum enumeration)
    {
        if (enumeration == 1) return "Mandatory";
        if (enumeration == 2) return "Optional";
        if (enumeration == 3) return "Constraint";
        return "Unknown";
    }
    
    bool
    NamingRuleType::exist(const std::string& enumerationString)
    {
        if (enumerationString == "Mandatory") return true;
        if (enumerationString == "Optional") return true;
        if (enumerationString == "Constraint") return true;
        return false;
    }
    
    bool
    NamingRuleType::exist(Enum enumeration)
    {
        if (enumeration == 1) return true;
        if (enumeration == 2) return true;
        if (enumeration == 3) return true;
        return false;
    }
    
    bool
    NamingRuleType::operator==(const NamingRuleType& value) const
    {
        if (value_ != value.value_) return false;
        return true;
    }
    
    bool
    NamingRuleType::operator!=(const NamingRuleType& value) const
    {
        return !this->operator==(value);
    }
    
    void
    NamingRuleType::copyTo(NamingRuleType& value)
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
    NamingRuleType::factory(void)
    {
    	return constructSPtr<NamingRuleType>();
    }
    
    OpcUaNodeId
    NamingRuleType::binaryTypeId(void)
    {
    	return OpcUaNodeId(0, 0);
    }
    
    OpcUaNodeId
    NamingRuleType::xmlTypeId(void)
    {
    	return OpcUaNodeId(0, 0);
    }
    
    void
    NamingRuleType::opcUaBinaryEncode(std::ostream& os) const
    {
        OpcUaNumber::opcUaBinaryEncode(os, value_);
    }
    
    void
    NamingRuleType::opcUaBinaryDecode(std::istream& is)
    {
        OpcUaNumber::opcUaBinaryDecode(is, value_);
    }
    
    bool
    NamingRuleType::encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const
    {
    }
    
    bool
    NamingRuleType::decode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
    }
    
    bool
    NamingRuleType::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
    }
    
    bool
    NamingRuleType::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
    }
    
    bool
    NamingRuleType::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
    }
    
    void
    NamingRuleType::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	NamingRuleType* dst = dynamic_cast<NamingRuleType*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    NamingRuleType::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	NamingRuleType* dst = dynamic_cast<NamingRuleType*>(&extensionObjectBase);
    	return *this == *dst;
    }
    
    void
    NamingRuleType::out(std::ostream& os)
    {
        os << "Value=" << value_;
    }

}
