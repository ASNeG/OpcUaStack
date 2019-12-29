/*
    EnumTypeClass: Enumeration

    Generated Source Code - please do not change this source code

    EnumTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

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
    
    Enumeration::Enumeration(Enum enumeration)
    : Object()
    , ExtensionObjectBase()
    , value_(enumeration)
    {
    }
    
    Enumeration::Enumeration(Enumeration& value)
    : Object()
    , ExtensionObjectBase()
    , value_(value.enumeration())
    {
    }
    
    Enumeration::~Enumeration(void)
    {
    }
    
    int32_t&
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
    
    std::string
    Enumeration::enum2Str(void)
    {
        return enum2Str((Enum)value_);
    }
    
    std::string
    Enumeration::toString(void)
    {
        return enum2Str((Enum)value_);
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
    
    Enumeration&
    Enumeration::operator=(const Enumeration& value)
    {
        value_ = const_cast<Enumeration&>(value).value();
        return *this;
    }
    
    Enumeration&
    Enumeration::operator=(const Enum& value)
    {
        value_ = value;
        return *this;
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
    	return boost::make_shared<Enumeration>();
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
    
    std::string
    Enumeration::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    Enumeration::typeName(void)
    {
    	return "Enumeration";
    }
    
    OpcUaNodeId
    Enumeration::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)29,0);
    }
    
    bool
    Enumeration::opcUaBinaryEncode(std::ostream& os) const
    {
        return OpcUaNumber::opcUaBinaryEncode(os, value_);
    }
    
    bool
    Enumeration::opcUaBinaryDecode(std::istream& is)
    {
        return OpcUaNumber::opcUaBinaryDecode(is, value_);
    }

    bool
    Enumeration::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        if(!XmlNumber::xmlEncode(pt, value_, element)) return false;
        return true;
    }
    
    bool
    Enumeration::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        if(!XmlNumber::xmlEncode(pt, value_, "Int32")) return false;
        return true;
    }
    
    bool
    Enumeration::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(element);
        if (!tree) return false;
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    Enumeration::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        if(!XmlNumber::xmlDecode(pt, value_)) return false;
        return true;
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
