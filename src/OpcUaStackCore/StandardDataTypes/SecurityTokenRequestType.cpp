/*
    EnumTypeClass: SecurityTokenRequestType

    Generated Source Code - please do not change this source code

    EnumTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/SecurityTokenRequestType.h"

namespace OpcUaStackCore
{
    
    SecurityTokenRequestType::SecurityTokenRequestType(void)
    : Object()
    , ExtensionObjectBase()
    , value_(0)
    {
    }
    
    SecurityTokenRequestType::SecurityTokenRequestType(Enum enumeration)
    : Object()
    , ExtensionObjectBase()
    , value_(enumeration)
    {
    }
    
    SecurityTokenRequestType::SecurityTokenRequestType(SecurityTokenRequestType& value)
    : Object()
    , ExtensionObjectBase()
    , value_(value.enumeration())
    {
    }
    
    SecurityTokenRequestType::~SecurityTokenRequestType(void)
    {
    }
    
    int32_t&
    SecurityTokenRequestType::value(void)
    {
        return value_;
    }
    
    void
    SecurityTokenRequestType::enumeration(SecurityTokenRequestType::Enum enumeration)
    {
        value_ = enumeration;
    }
    
    SecurityTokenRequestType::Enum
    SecurityTokenRequestType::enumeration(void)
    {
        return (Enum)value_;
    }
    
    SecurityTokenRequestType::Enum
    SecurityTokenRequestType::str2Enum(const std::string& enumerationString)
    {
        if (enumerationString == "Issue") return (Enum)0;
        if (enumerationString == "Renew") return (Enum)1;
        return (Enum)0;
    }
    
    std::string
    SecurityTokenRequestType::enum2Str(Enum enumeration)
    {
        if (enumeration == 0) return "Issue";
        if (enumeration == 1) return "Renew";
        return "Unknown";
    }
    
    std::string
    SecurityTokenRequestType::enum2Str(void)
    {
        return enum2Str((Enum)value_);
    }
    
    std::string
    SecurityTokenRequestType::toString(void)
    {
        return enum2Str((Enum)value_);
    }
    
    bool
    SecurityTokenRequestType::exist(const std::string& enumerationString)
    {
        if (enumerationString == "Issue") return true;
        if (enumerationString == "Renew") return true;
        return false;
    }
    
    bool
    SecurityTokenRequestType::exist(Enum enumeration)
    {
        if (enumeration == 0) return true;
        if (enumeration == 1) return true;
        return false;
    }
    
    bool
    SecurityTokenRequestType::operator==(const SecurityTokenRequestType& value) const
    {
        if (value_ != value.value_) return false;
        return true;
    }
    
    bool
    SecurityTokenRequestType::operator!=(const SecurityTokenRequestType& value) const
    {
        return !this->operator==(value);
    }
    
    SecurityTokenRequestType&
    SecurityTokenRequestType::operator=(const SecurityTokenRequestType& value)
    {
        value_ = const_cast<SecurityTokenRequestType&>(value).value();
        return *this;
    }
    
    SecurityTokenRequestType&
    SecurityTokenRequestType::operator=(const Enum& value)
    {
        value_ = value;
        return *this;
    }
    
    void
    SecurityTokenRequestType::copyTo(SecurityTokenRequestType& value)
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
    SecurityTokenRequestType::factory(void)
    {
    	return constructSPtr<SecurityTokenRequestType>();
    }
    
    OpcUaNodeId
    SecurityTokenRequestType::binaryTypeId(void)
    {
    	return OpcUaNodeId(0, 0);
    }
    
    OpcUaNodeId
    SecurityTokenRequestType::xmlTypeId(void)
    {
    	return OpcUaNodeId(0, 0);
    }
    
    OpcUaNodeId
    SecurityTokenRequestType::jsonTypeId(void)
    {
    	return OpcUaNodeId(0, 0);
    }
    
    std::string
    SecurityTokenRequestType::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    SecurityTokenRequestType::typeName(void)
    {
    	return "SecurityTokenRequestType";
    }
    
    OpcUaNodeId
    SecurityTokenRequestType::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)315,0);
    }
    
    void
    SecurityTokenRequestType::opcUaBinaryEncode(std::ostream& os) const
    {
        OpcUaNumber::opcUaBinaryEncode(os, value_);
    }
    
    void
    SecurityTokenRequestType::opcUaBinaryDecode(std::istream& is)
    {
        OpcUaNumber::opcUaBinaryDecode(is, value_);
    }
    
    bool
    SecurityTokenRequestType::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        if(!XmlNumber::xmlEncode(pt, value_, element))
        {
    	     Log(Error, "SecurityTokenRequestType json encoder error")
    		     .parameter("Element", element);
            return false;
        }
        return true;
    }
    
    bool
    SecurityTokenRequestType::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        if(!XmlNumber::xmlEncode(pt, value_)) {
    	     Log(Error, "SecurityTokenRequestType json encoder error");
            return false;
        }
        return true;
    }
    
    bool
    SecurityTokenRequestType::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(element);
        if (!tree) {
    	     Log(Error, "SecurityTokenRequestType json decoder error")
    		     .parameter("Element", element);
            return false;
         }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    SecurityTokenRequestType::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        if(!XmlNumber::xmlDecode(pt, value_)) {
    	     Log(Error, "SecurityTokenRequestType json decoder error");
            return false;
        }
        return true;
    }
    
    bool
    SecurityTokenRequestType::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        if(!JsonNumber::jsonEncode(pt, value_))
        {
    	     Log(Error, "SecurityTokenRequestType json encoder error")
    		     .parameter("Element", "Value");
           return false;
        }
        return true;
    }
    
    bool
    SecurityTokenRequestType::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        if(!JsonNumber::jsonDecode(pt, value_)) {
            Log(Error, "SecurityTokenRequestType decode json error - decode failed");
            return false;
        }
        return true;
    }
    
    void
    SecurityTokenRequestType::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	SecurityTokenRequestType* dst = dynamic_cast<SecurityTokenRequestType*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    SecurityTokenRequestType::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	SecurityTokenRequestType* dst = dynamic_cast<SecurityTokenRequestType*>(&extensionObjectBase);
    	return *this == *dst;
    }
    
    void
    SecurityTokenRequestType::out(std::ostream& os)
    {
        os << "Value=" << value_;
    }

}
