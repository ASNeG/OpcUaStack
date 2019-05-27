/*
    EnumTypeClass: IdentityCriteriaType

    Generated Source Code - please do not change this source code

    EnumTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/IdentityCriteriaType.h"

namespace OpcUaStackCore
{
    
    IdentityCriteriaType::IdentityCriteriaType(void)
    : Object()
    , ExtensionObjectBase()
    , value_(0)
    {
    }
    
    IdentityCriteriaType::IdentityCriteriaType(Enum enumeration)
    : Object()
    , ExtensionObjectBase()
    , value_(enumeration)
    {
    }
    
    IdentityCriteriaType::IdentityCriteriaType(IdentityCriteriaType& value)
    : Object()
    , ExtensionObjectBase()
    , value_(value.enumeration())
    {
    }
    
    IdentityCriteriaType::~IdentityCriteriaType(void)
    {
    }
    
    int32_t&
    IdentityCriteriaType::value(void)
    {
        return value_;
    }
    
    void
    IdentityCriteriaType::enumeration(IdentityCriteriaType::Enum enumeration)
    {
        value_ = enumeration;
    }
    
    IdentityCriteriaType::Enum
    IdentityCriteriaType::enumeration(void)
    {
        return (Enum)value_;
    }
    
    IdentityCriteriaType::Enum
    IdentityCriteriaType::str2Enum(const std::string& enumerationString)
    {
        if (enumerationString == "UserName") return (Enum)1;
        if (enumerationString == "Thumbprint") return (Enum)2;
        if (enumerationString == "Role") return (Enum)3;
        if (enumerationString == "GroupId") return (Enum)4;
        if (enumerationString == "Anonymous") return (Enum)5;
        if (enumerationString == "AuthenticatedUser") return (Enum)6;
        return (Enum)0;
    }
    
    std::string
    IdentityCriteriaType::enum2Str(Enum enumeration)
    {
        if (enumeration == 1) return "UserName";
        if (enumeration == 2) return "Thumbprint";
        if (enumeration == 3) return "Role";
        if (enumeration == 4) return "GroupId";
        if (enumeration == 5) return "Anonymous";
        if (enumeration == 6) return "AuthenticatedUser";
        return "Unknown";
    }
    
    std::string
    IdentityCriteriaType::enum2Str(void)
    {
        return enum2Str((Enum)value_);
    }
    
    std::string
    IdentityCriteriaType::toString(void)
    {
        return enum2Str((Enum)value_);
    }
    
    bool
    IdentityCriteriaType::exist(const std::string& enumerationString)
    {
        if (enumerationString == "UserName") return true;
        if (enumerationString == "Thumbprint") return true;
        if (enumerationString == "Role") return true;
        if (enumerationString == "GroupId") return true;
        if (enumerationString == "Anonymous") return true;
        if (enumerationString == "AuthenticatedUser") return true;
        return false;
    }
    
    bool
    IdentityCriteriaType::exist(Enum enumeration)
    {
        if (enumeration == 1) return true;
        if (enumeration == 2) return true;
        if (enumeration == 3) return true;
        if (enumeration == 4) return true;
        if (enumeration == 5) return true;
        if (enumeration == 6) return true;
        return false;
    }
    
    bool
    IdentityCriteriaType::operator==(const IdentityCriteriaType& value) const
    {
        if (value_ != value.value_) return false;
        return true;
    }
    
    bool
    IdentityCriteriaType::operator!=(const IdentityCriteriaType& value) const
    {
        return !this->operator==(value);
    }
    
    IdentityCriteriaType&
    IdentityCriteriaType::operator=(const IdentityCriteriaType& value)
    {
        value_ = const_cast<IdentityCriteriaType&>(value).value();
        return *this;
    }
    
    IdentityCriteriaType&
    IdentityCriteriaType::operator=(const Enum& value)
    {
        value_ = value;
        return *this;
    }
    
    void
    IdentityCriteriaType::copyTo(IdentityCriteriaType& value)
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
    IdentityCriteriaType::factory(void)
    {
    	return constructSPtr<IdentityCriteriaType>();
    }
    
    OpcUaNodeId
    IdentityCriteriaType::binaryTypeId(void)
    {
    	return OpcUaNodeId(0, 0);
    }
    
    OpcUaNodeId
    IdentityCriteriaType::xmlTypeId(void)
    {
    	return OpcUaNodeId(0, 0);
    }
    
    OpcUaNodeId
    IdentityCriteriaType::jsonTypeId(void)
    {
    	return OpcUaNodeId(0, 0);
    }
    
    std::string
    IdentityCriteriaType::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    IdentityCriteriaType::typeName(void)
    {
    	return "IdentityCriteriaType";
    }
    
    OpcUaNodeId
    IdentityCriteriaType::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15632,0);
    }
    
    void
    IdentityCriteriaType::opcUaBinaryEncode(std::ostream& os) const
    {
        OpcUaNumber::opcUaBinaryEncode(os, value_);
    }
    
    void
    IdentityCriteriaType::opcUaBinaryDecode(std::istream& is)
    {
        OpcUaNumber::opcUaBinaryDecode(is, value_);
    }
    
    bool
    IdentityCriteriaType::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        if(!XmlNumber::xmlEncode(pt, value_, element))
        {
    	     Log(Error, "IdentityCriteriaType json encoder error")
    		     .parameter("Element", element);
            return false;
        }
        return true;
    }
    
    bool
    IdentityCriteriaType::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        if(!XmlNumber::xmlEncode(pt, value_)) {
    	     Log(Error, "IdentityCriteriaType json encoder error");
            return false;
        }
        return true;
    }
    
    bool
    IdentityCriteriaType::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(element);
        if (!tree) {
    	     Log(Error, "IdentityCriteriaType json decoder error")
    		     .parameter("Element", element);
            return false;
         }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    IdentityCriteriaType::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        if(!XmlNumber::xmlDecode(pt, value_)) {
    	     Log(Error, "IdentityCriteriaType json decoder error");
            return false;
        }
        return true;
    }
    
    bool
    IdentityCriteriaType::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        if(!JsonNumber::jsonEncode(pt, value_))
        {
    	     Log(Error, "IdentityCriteriaType json encoder error")
    		     .parameter("Element", "Value");
           return false;
        }
        return true;
    }
    
    bool
    IdentityCriteriaType::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        if(!JsonNumber::jsonDecode(pt, value_)) {
            Log(Error, "IdentityCriteriaType decode json error - decode failed");
            return false;
        }
        return true;
    }
    
    void
    IdentityCriteriaType::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	IdentityCriteriaType* dst = dynamic_cast<IdentityCriteriaType*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    IdentityCriteriaType::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	IdentityCriteriaType* dst = dynamic_cast<IdentityCriteriaType*>(&extensionObjectBase);
    	return *this == *dst;
    }
    
    void
    IdentityCriteriaType::out(std::ostream& os)
    {
        os << "Value=" << value_;
    }

}
