/*
    EnumTypeClass: OpenFileMode

    Generated Source Code - please do not change this source code

    EnumTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/OpenFileMode.h"

namespace OpcUaStackCore
{
    
    OpenFileMode::OpenFileMode(void)
    : Object()
    , ExtensionObjectBase()
    , value_(0)
    {
    }
    
    OpenFileMode::OpenFileMode(Enum enumeration)
    : Object()
    , ExtensionObjectBase()
    , value_(enumeration)
    {
    }
    
    OpenFileMode::OpenFileMode(OpenFileMode& value)
    : Object()
    , ExtensionObjectBase()
    , value_(value.enumeration())
    {
    }
    
    OpenFileMode::~OpenFileMode(void)
    {
    }
    
    int32_t&
    OpenFileMode::value(void)
    {
        return value_;
    }
    
    void
    OpenFileMode::enumeration(OpenFileMode::Enum enumeration)
    {
        value_ = enumeration;
    }
    
    OpenFileMode::Enum
    OpenFileMode::enumeration(void)
    {
        return (Enum)value_;
    }
    
    OpenFileMode::Enum
    OpenFileMode::str2Enum(const std::string& enumerationString)
    {
        if (enumerationString == "Read") return (Enum)1;
        if (enumerationString == "Write") return (Enum)2;
        if (enumerationString == "EraseExisting") return (Enum)4;
        if (enumerationString == "Append") return (Enum)8;
        return (Enum)0;
    }
    
    std::string
    OpenFileMode::enum2Str(Enum enumeration)
    {
        if (enumeration == 1) return "Read";
        if (enumeration == 2) return "Write";
        if (enumeration == 4) return "EraseExisting";
        if (enumeration == 8) return "Append";
        return "Unknown";
    }
    
    std::string
    OpenFileMode::enum2Str(void)
    {
        return enum2Str((Enum)value_);
    }
    
    std::string
    OpenFileMode::toString(void)
    {
        return enum2Str((Enum)value_);
    }
    
    bool
    OpenFileMode::exist(const std::string& enumerationString)
    {
        if (enumerationString == "Read") return true;
        if (enumerationString == "Write") return true;
        if (enumerationString == "EraseExisting") return true;
        if (enumerationString == "Append") return true;
        return false;
    }
    
    bool
    OpenFileMode::exist(Enum enumeration)
    {
        if (enumeration == 1) return true;
        if (enumeration == 2) return true;
        if (enumeration == 4) return true;
        if (enumeration == 8) return true;
        return false;
    }
    
    bool
    OpenFileMode::operator==(const OpenFileMode& value) const
    {
        if (value_ != value.value_) return false;
        return true;
    }
    
    bool
    OpenFileMode::operator!=(const OpenFileMode& value) const
    {
        return !this->operator==(value);
    }
    
    OpenFileMode&
    OpenFileMode::operator=(const OpenFileMode& value)
    {
        value_ = const_cast<OpenFileMode&>(value).value();
        return *this;
    }
    
    OpenFileMode&
    OpenFileMode::operator=(const Enum& value)
    {
        value_ = value;
        return *this;
    }
    
    void
    OpenFileMode::copyTo(OpenFileMode& value)
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
    OpenFileMode::factory(void)
    {
    	return constructSPtr<OpenFileMode>();
    }
    
    OpcUaNodeId
    OpenFileMode::binaryTypeId(void)
    {
    	return OpcUaNodeId(0, 0);
    }
    
    OpcUaNodeId
    OpenFileMode::xmlTypeId(void)
    {
    	return OpcUaNodeId(0, 0);
    }
    
    OpcUaNodeId
    OpenFileMode::jsonTypeId(void)
    {
    	return OpcUaNodeId(0, 0);
    }
    
    std::string
    OpenFileMode::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    OpenFileMode::typeName(void)
    {
    	return "OpenFileMode";
    }
    
    OpcUaNodeId
    OpenFileMode::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)11939,0);
    }
    
    void
    OpenFileMode::opcUaBinaryEncode(std::ostream& os) const
    {
        OpcUaNumber::opcUaBinaryEncode(os, value_);
    }
    
    void
    OpenFileMode::opcUaBinaryDecode(std::istream& is)
    {
        OpcUaNumber::opcUaBinaryDecode(is, value_);
    }
    
    bool
    OpenFileMode::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        if(!XmlNumber::xmlEncode(pt, value_, element))
        {
    	     Log(Error, "OpenFileMode json encoder error")
    		     .parameter("Element", element);
            return false;
        }
        return true;
    }
    
    bool
    OpenFileMode::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        if(!XmlNumber::xmlEncode(pt, value_)) {
    	     Log(Error, "OpenFileMode json encoder error");
            return false;
        }
        return true;
    }
    
    bool
    OpenFileMode::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(element);
        if (!tree) {
    	     Log(Error, "OpenFileMode json decoder error")
    		     .parameter("Element", element);
            return false;
         }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    OpenFileMode::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        if(!XmlNumber::xmlDecode(pt, value_)) {
    	     Log(Error, "OpenFileMode json decoder error");
            return false;
        }
        return true;
    }
    
    bool
    OpenFileMode::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        if(!JsonNumber::jsonEncode(pt, value_))
        {
    	     Log(Error, "OpenFileMode json encoder error")
    		     .parameter("Element", "Value");
           return false;
        }
        return true;
    }
    
    bool
    OpenFileMode::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        if(!JsonNumber::jsonDecode(pt, value_)) {
            Log(Error, "OpenFileMode decode json error - decode failed");
            return false;
        }
        return true;
    }
    
    void
    OpenFileMode::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	OpenFileMode* dst = dynamic_cast<OpenFileMode*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    OpenFileMode::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	OpenFileMode* dst = dynamic_cast<OpenFileMode*>(&extensionObjectBase);
    	return *this == *dst;
    }
    
    void
    OpenFileMode::out(std::ostream& os)
    {
        os << "Value=" << value_;
    }

}
