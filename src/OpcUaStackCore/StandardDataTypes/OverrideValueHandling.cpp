/*
    EnumTypeClass: OverrideValueHandling

    Generated Source Code - please do not change this source code

    EnumTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

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
    
    OverrideValueHandling::OverrideValueHandling(OverrideValueHandling& value)
    : Object()
    , ExtensionObjectBase()
    , value_(value.enumeration())
    {
    }
    
    OverrideValueHandling::~OverrideValueHandling(void)
    {
    }
    
    int32_t&
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
    
    std::string
    OverrideValueHandling::enum2Str(void)
    {
        return enum2Str((Enum)value_);
    }
    
    std::string
    OverrideValueHandling::toString(void)
    {
        return enum2Str((Enum)value_);
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
    
    OverrideValueHandling&
    OverrideValueHandling::operator=(const OverrideValueHandling& value)
    {
        value_ = const_cast<OverrideValueHandling&>(value).value();
        return *this;
    }
    
    OverrideValueHandling&
    OverrideValueHandling::operator=(const Enum& value)
    {
        value_ = value;
        return *this;
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
    
    OpcUaNodeId
    OverrideValueHandling::jsonTypeId(void)
    {
    	return OpcUaNodeId(0, 0);
    }
    
    std::string
    OverrideValueHandling::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    OverrideValueHandling::typeName(void)
    {
    	return "OverrideValueHandling";
    }
    
    OpcUaNodeId
    OverrideValueHandling::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15874,0);
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
    OverrideValueHandling::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        if(!XmlNumber::xmlEncode(pt, value_, element))
        {
    	     Log(Error, "OverrideValueHandling json encoder error")
    		     .parameter("Element", element);
            return false;
        }
        return true;
    }
    
    bool
    OverrideValueHandling::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        if(!XmlNumber::xmlEncode(pt, value_)) {
    	     Log(Error, "OverrideValueHandling json encoder error");
            return false;
        }
        return true;
    }
    
    bool
    OverrideValueHandling::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(element);
        if (!tree) {
    	     Log(Error, "OverrideValueHandling json decoder error")
    		     .parameter("Element", element);
            return false;
         }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    OverrideValueHandling::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        if(!XmlNumber::xmlDecode(pt, value_)) {
    	     Log(Error, "OverrideValueHandling json decoder error");
            return false;
        }
        return true;
    }
    
    bool
    OverrideValueHandling::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        if(!JsonNumber::jsonEncode(pt, value_))
        {
    	     Log(Error, "OverrideValueHandling json encoder error")
    		     .parameter("Element", "Value");
           return false;
        }
        return true;
    }
    
    bool
    OverrideValueHandling::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        if(!JsonNumber::jsonDecode(pt, value_)) {
            Log(Error, "OverrideValueHandling decode json error - decode failed");
            return false;
        }
        return true;
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
