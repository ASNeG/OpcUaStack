/*
    EnumTypeClass: NamingRuleType

    Generated Source Code - please do not change this source code

    EnumTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

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
    
    NamingRuleType::NamingRuleType(Enum enumeration)
    : Object()
    , ExtensionObjectBase()
    , value_(enumeration)
    {
    }
    
    NamingRuleType::NamingRuleType(NamingRuleType& value)
    : Object()
    , ExtensionObjectBase()
    , value_(value.enumeration())
    {
    }
    
    NamingRuleType::~NamingRuleType(void)
    {
    }
    
    int32_t&
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
    
    std::string
    NamingRuleType::enum2Str(void)
    {
        return enum2Str((Enum)value_);
    }
    
    std::string
    NamingRuleType::toString(void)
    {
        return enum2Str((Enum)value_);
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
    
    NamingRuleType&
    NamingRuleType::operator=(const NamingRuleType& value)
    {
        value_ = const_cast<NamingRuleType&>(value).value();
        return *this;
    }
    
    NamingRuleType&
    NamingRuleType::operator=(const Enum& value)
    {
        value_ = value;
        return *this;
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
    
    OpcUaNodeId
    NamingRuleType::jsonTypeId(void)
    {
    	return OpcUaNodeId(0, 0);
    }
    
    std::string
    NamingRuleType::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    NamingRuleType::typeName(void)
    {
    	return "NamingRuleType";
    }
    
    OpcUaNodeId
    NamingRuleType::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)120,0);
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
    NamingRuleType::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        if(!XmlNumber::xmlEncode(pt, value_, element))
        {
    	     Log(Error, "NamingRuleType json encoder error")
    		     .parameter("Element", element);
            return false;
        }
        return true;
    }
    
    bool
    NamingRuleType::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        if(!XmlNumber::xmlEncode(pt, value_)) {
    	     Log(Error, "NamingRuleType json encoder error");
            return false;
        }
        return true;
    }
    
    bool
    NamingRuleType::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(element);
        if (!tree) {
    	     Log(Error, "NamingRuleType json decoder error")
    		     .parameter("Element", element);
            return false;
         }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    NamingRuleType::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        if(!XmlNumber::xmlDecode(pt, value_)) {
    	     Log(Error, "NamingRuleType json decoder error");
            return false;
        }
        return true;
    }
    
    bool
    NamingRuleType::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        if(!JsonNumber::jsonEncode(pt, value_))
        {
    	     Log(Error, "NamingRuleType json encoder error")
    		     .parameter("Element", "Value");
           return false;
        }
        return true;
    }
    
    bool
    NamingRuleType::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        if(!JsonNumber::jsonDecode(pt, value_)) {
            Log(Error, "NamingRuleType decode json error - decode failed");
            return false;
        }
        return true;
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
