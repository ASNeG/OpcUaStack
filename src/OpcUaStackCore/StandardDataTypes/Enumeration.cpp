/*
    EnumTypeClass: Enumeration

    Generated Source Code - please do not change this source code

    EnumTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/Enumeration.h"

namespace OpcUaStackCore
{
    
    Enumeration::Enumeration(void)
    : Object()
    , ExtensionObjectBase()
    , value_(0)
    {
    }
    
    Enumeration::~Enumeration(void)
    {
    }
    
    uint32_t&
    Enumeration::value(void)
    {
        return value_;
    }
    
    void
    Enumeration::enumeration(Enumeration::Enum enumeration)
    {
        value_ = enumeration;
    }
    
    Enumeration::Enum
    Enumeration::enumeration(void)
    {
        return (Enum)value_;
    }
    
    Enumeration::Enum
    Enumeration::str2Enum(const std::string& enumerationString)
    {
        return (Enum)0;
    }
    
    std::string
    Enumeration::enum2Str(Enum enumeration)
    {
        return "Unknown";
    }
    
    bool
    Enumeration::exist(const std::string& enumerationString)
    {
        return false;
    }
    
    bool
    Enumeration::exist(Enum enumeration)
    {
        return false;
    }
    
    bool
    Enumeration::operator==(const Enumeration& value) const
    {
        if (value_ != value.value_) return false;
        return true;
    }
    
    bool
    Enumeration::operator!=(const Enumeration& value) const
    {
        return !this->operator==(value);
    }
    
    void
    Enumeration::copyTo(Enumeration& value)
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
    Enumeration::factory(void)
    {
    	return constructSPtr<Enumeration>();
    }
    
    OpcUaNodeId
    Enumeration::binaryTypeId(void)
    {
    	return OpcUaNodeId(0, 0);
    }
    
    OpcUaNodeId
    Enumeration::xmlTypeId(void)
    {
    	return OpcUaNodeId(0, 0);
    }
    
    void
    Enumeration::opcUaBinaryEncode(std::ostream& os) const
    {
        OpcUaNumber::opcUaBinaryEncode(os, value_);
    }
    
    void
    Enumeration::opcUaBinaryDecode(std::istream& is)
    {
        OpcUaNumber::opcUaBinaryDecode(is, value_);
    }
    
    bool
    Enumeration::encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const
    {
    }
    
    bool
    Enumeration::decode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
    }
    
    bool
    Enumeration::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
    }
    
    bool
    Enumeration::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
    }
    
    bool
    Enumeration::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
    }
    
    void
    Enumeration::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	Enumeration* dst = dynamic_cast<Enumeration*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    Enumeration::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	Enumeration* dst = dynamic_cast<Enumeration*>(&extensionObjectBase);
    	return *this == *dst;
    }
    
    void
    Enumeration::out(std::ostream& os)
    {
        os << "Value=" << value_;
    }

}
