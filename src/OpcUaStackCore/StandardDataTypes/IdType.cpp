/*
    EnumTypeClass: IdType

    Generated Source Code - please do not change this source code

    EnumTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/IdType.h"

namespace OpcUaStackCore
{
    
    IdType::IdType(void)
    : Object()
    , ExtensionObjectBase()
    , value_(0)
    {
    }
    
    IdType::IdType(Enum enumeration)
    : Object()
    , ExtensionObjectBase()
    , value_(enumeration)
    {
    }
    
    IdType::IdType(IdType& value)
    : Object()
    , ExtensionObjectBase()
    , value_(value.enumeration())
    {
    }
    
    IdType::~IdType(void)
    {
    }
    
    int32_t&
    IdType::value(void)
    {
        return value_;
    }
    
    void
    IdType::enumeration(IdType::Enum enumeration)
    {
        value_ = enumeration;
    }
    
    IdType::Enum
    IdType::enumeration(void)
    {
        return (Enum)value_;
    }
    
    IdType::Enum
    IdType::str2Enum(const std::string& enumerationString)
    {
        if (enumerationString == "Numeric") return (Enum)0;
        if (enumerationString == "String") return (Enum)1;
        if (enumerationString == "Guid") return (Enum)2;
        if (enumerationString == "Opaque") return (Enum)3;
        return (Enum)0;
    }
    
    std::string
    IdType::enum2Str(Enum enumeration)
    {
        if (enumeration == 0) return "Numeric";
        if (enumeration == 1) return "String";
        if (enumeration == 2) return "Guid";
        if (enumeration == 3) return "Opaque";
        return "Unknown";
    }
    
    std::string
    IdType::enum2Str(void)
    {
        return enum2Str((Enum)value_);
    }
    
    std::string
    IdType::toString(void)
    {
        return enum2Str((Enum)value_);
    }
    
    bool
    IdType::exist(const std::string& enumerationString)
    {
        if (enumerationString == "Numeric") return true;
        if (enumerationString == "String") return true;
        if (enumerationString == "Guid") return true;
        if (enumerationString == "Opaque") return true;
        return false;
    }
    
    bool
    IdType::exist(Enum enumeration)
    {
        if (enumeration == 0) return true;
        if (enumeration == 1) return true;
        if (enumeration == 2) return true;
        if (enumeration == 3) return true;
        return false;
    }
    
    bool
    IdType::operator==(const IdType& value) const
    {
        if (value_ != value.value_) return false;
        return true;
    }
    
    bool
    IdType::operator!=(const IdType& value) const
    {
        return !this->operator==(value);
    }
    
    IdType&
    IdType::operator=(const IdType& value)
    {
        value_ = const_cast<IdType&>(value).value();
        return *this;
    }
    
    IdType&
    IdType::operator=(const Enum& value)
    {
        value_ = value;
        return *this;
    }
    
    void
    IdType::copyTo(IdType& value)
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
    IdType::factory(void)
    {
    	return constructSPtr<IdType>();
    }
    
    OpcUaNodeId
    IdType::binaryTypeId(void)
    {
    	return OpcUaNodeId(0, 0);
    }
    
    OpcUaNodeId
    IdType::xmlTypeId(void)
    {
    	return OpcUaNodeId(0, 0);
    }
    
    OpcUaNodeId
    IdType::jsonTypeId(void)
    {
    	return OpcUaNodeId(0, 0);
    }
    
    std::string
    IdType::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    IdType::typeName(void)
    {
    	return "IdType";
    }
    
    OpcUaNodeId
    IdType::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)256,0);
    }
    
    void
    IdType::opcUaBinaryEncode(std::ostream& os) const
    {
        OpcUaNumber::opcUaBinaryEncode(os, value_);
    }
    
    void
    IdType::opcUaBinaryDecode(std::istream& is)
    {
        OpcUaNumber::opcUaBinaryDecode(is, value_);
    }
    
    bool
    IdType::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        if(!XmlNumber::xmlEncode(pt, value_, element))
        {
    	     Log(Error, "IdType json encoder error")
    		     .parameter("Element", element);
            return false;
        }
        return true;
    }
    
    bool
    IdType::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        if(!XmlNumber::xmlEncode(pt, value_)) {
    	     Log(Error, "IdType json encoder error");
            return false;
        }
        return true;
    }
    
    bool
    IdType::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(element);
        if (!tree) {
    	     Log(Error, "IdType json decoder error")
    		     .parameter("Element", element);
            return false;
         }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    IdType::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        if(!XmlNumber::xmlDecode(pt, value_)) {
    	     Log(Error, "IdType json decoder error");
            return false;
        }
        return true;
    }
    
    bool
    IdType::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        if(!JsonNumber::jsonEncode(pt, value_))
        {
    	     Log(Error, "IdType json encoder error")
    		     .parameter("Element", "Value");
           return false;
        }
        return true;
    }
    
    bool
    IdType::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        if(!JsonNumber::jsonDecode(pt, value_)) {
            Log(Error, "IdType decode json error - decode failed");
            return false;
        }
        return true;
    }
    
    void
    IdType::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	IdType* dst = dynamic_cast<IdType*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    IdType::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	IdType* dst = dynamic_cast<IdType*>(&extensionObjectBase);
    	return *this == *dst;
    }
    
    void
    IdType::out(std::ostream& os)
    {
        os << "Value=" << value_;
    }

}
