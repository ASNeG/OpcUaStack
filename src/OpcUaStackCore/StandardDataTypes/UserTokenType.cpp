/*
    EnumTypeClass: UserTokenType

    Generated Source Code - please do not change this source code

    EnumTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/UserTokenType.h"

namespace OpcUaStackCore
{
    
    UserTokenType::UserTokenType(void)
    : Object()
    , ExtensionObjectBase()
    , value_(0)
    {
    }
    
    UserTokenType::UserTokenType(Enum enumeration)
    : Object()
    , ExtensionObjectBase()
    , value_(enumeration)
    {
    }
    
    UserTokenType::UserTokenType(UserTokenType& value)
    : Object()
    , ExtensionObjectBase()
    , value_(value.enumeration())
    {
    }
    
    UserTokenType::~UserTokenType(void)
    {
    }
    
    int32_t&
    UserTokenType::value(void)
    {
        return value_;
    }
    
    void
    UserTokenType::enumeration(UserTokenType::Enum enumeration)
    {
        value_ = enumeration;
    }
    
    UserTokenType::Enum
    UserTokenType::enumeration(void)
    {
        return (Enum)value_;
    }
    
    UserTokenType::Enum
    UserTokenType::str2Enum(const std::string& enumerationString)
    {
        if (enumerationString == "Anonymous") return (Enum)0;
        if (enumerationString == "UserName") return (Enum)1;
        if (enumerationString == "Certificate") return (Enum)2;
        if (enumerationString == "IssuedToken") return (Enum)3;
        return (Enum)0;
    }
    
    std::string
    UserTokenType::enum2Str(Enum enumeration)
    {
        if (enumeration == 0) return "Anonymous";
        if (enumeration == 1) return "UserName";
        if (enumeration == 2) return "Certificate";
        if (enumeration == 3) return "IssuedToken";
        return "Unknown";
    }
    
    std::string
    UserTokenType::enum2Str(void)
    {
        return enum2Str((Enum)value_);
    }
    
    std::string
    UserTokenType::toString(void)
    {
        return enum2Str((Enum)value_);
    }
    
    bool
    UserTokenType::exist(const std::string& enumerationString)
    {
        if (enumerationString == "Anonymous") return true;
        if (enumerationString == "UserName") return true;
        if (enumerationString == "Certificate") return true;
        if (enumerationString == "IssuedToken") return true;
        return false;
    }
    
    bool
    UserTokenType::exist(Enum enumeration)
    {
        if (enumeration == 0) return true;
        if (enumeration == 1) return true;
        if (enumeration == 2) return true;
        if (enumeration == 3) return true;
        return false;
    }
    
    bool
    UserTokenType::operator==(const UserTokenType& value) const
    {
        if (value_ != value.value_) return false;
        return true;
    }
    
    bool
    UserTokenType::operator!=(const UserTokenType& value) const
    {
        return !this->operator==(value);
    }
    
    UserTokenType&
    UserTokenType::operator=(const UserTokenType& value)
    {
        value_ = const_cast<UserTokenType&>(value).value();
        return *this;
    }
    
    UserTokenType&
    UserTokenType::operator=(const Enum& value)
    {
        value_ = value;
        return *this;
    }
    
    void
    UserTokenType::copyTo(UserTokenType& value)
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
    UserTokenType::factory(void)
    {
    	return constructSPtr<UserTokenType>();
    }
    
    OpcUaNodeId
    UserTokenType::binaryTypeId(void)
    {
    	return OpcUaNodeId(0, 0);
    }
    
    OpcUaNodeId
    UserTokenType::xmlTypeId(void)
    {
    	return OpcUaNodeId(0, 0);
    }
    
    OpcUaNodeId
    UserTokenType::jsonTypeId(void)
    {
    	return OpcUaNodeId(0, 0);
    }
    
    std::string
    UserTokenType::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    UserTokenType::typeName(void)
    {
    	return "UserTokenType";
    }
    
    OpcUaNodeId
    UserTokenType::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)303,0);
    }
    
    void
    UserTokenType::opcUaBinaryEncode(std::ostream& os) const
    {
        OpcUaNumber::opcUaBinaryEncode(os, value_);
    }
    
    void
    UserTokenType::opcUaBinaryDecode(std::istream& is)
    {
        OpcUaNumber::opcUaBinaryDecode(is, value_);
    }
    
    bool
    UserTokenType::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        if(!XmlNumber::xmlEncode(pt, value_, element))
        {
    	     Log(Error, "UserTokenType json encoder error")
    		     .parameter("Element", element);
            return false;
        }
        return true;
    }
    
    bool
    UserTokenType::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        if(!XmlNumber::xmlEncode(pt, value_)) {
    	     Log(Error, "UserTokenType json encoder error");
            return false;
        }
        return true;
    }
    
    bool
    UserTokenType::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(element);
        if (!tree) {
    	     Log(Error, "UserTokenType json decoder error")
    		     .parameter("Element", element);
            return false;
         }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    UserTokenType::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        if(!XmlNumber::xmlDecode(pt, value_)) {
    	     Log(Error, "UserTokenType json decoder error");
            return false;
        }
        return true;
    }
    
    bool
    UserTokenType::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        if(!JsonNumber::jsonEncode(pt, value_))
        {
    	     Log(Error, "UserTokenType json encoder error")
    		     .parameter("Element", "Value");
           return false;
        }
        return true;
    }
    
    bool
    UserTokenType::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        if(!JsonNumber::jsonDecode(pt, value_)) {
            Log(Error, "UserTokenType decode json error - decode failed");
            return false;
        }
        return true;
    }
    
    void
    UserTokenType::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	UserTokenType* dst = dynamic_cast<UserTokenType*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    UserTokenType::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	UserTokenType* dst = dynamic_cast<UserTokenType*>(&extensionObjectBase);
    	return *this == *dst;
    }
    
    void
    UserTokenType::out(std::ostream& os)
    {
        os << "Value=" << value_;
    }

}
