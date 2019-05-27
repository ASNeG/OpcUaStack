/*
    EnumTypeClass: RedundancySupport

    Generated Source Code - please do not change this source code

    EnumTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/RedundancySupport.h"

namespace OpcUaStackCore
{
    
    RedundancySupport::RedundancySupport(void)
    : Object()
    , ExtensionObjectBase()
    , value_(0)
    {
    }
    
    RedundancySupport::RedundancySupport(Enum enumeration)
    : Object()
    , ExtensionObjectBase()
    , value_(enumeration)
    {
    }
    
    RedundancySupport::RedundancySupport(RedundancySupport& value)
    : Object()
    , ExtensionObjectBase()
    , value_(value.enumeration())
    {
    }
    
    RedundancySupport::~RedundancySupport(void)
    {
    }
    
    int32_t&
    RedundancySupport::value(void)
    {
        return value_;
    }
    
    void
    RedundancySupport::enumeration(RedundancySupport::Enum enumeration)
    {
        value_ = enumeration;
    }
    
    RedundancySupport::Enum
    RedundancySupport::enumeration(void)
    {
        return (Enum)value_;
    }
    
    RedundancySupport::Enum
    RedundancySupport::str2Enum(const std::string& enumerationString)
    {
        if (enumerationString == "None") return (Enum)0;
        if (enumerationString == "Cold") return (Enum)1;
        if (enumerationString == "Warm") return (Enum)2;
        if (enumerationString == "Hot") return (Enum)3;
        if (enumerationString == "Transparent") return (Enum)4;
        if (enumerationString == "HotAndMirrored") return (Enum)5;
        return (Enum)0;
    }
    
    std::string
    RedundancySupport::enum2Str(Enum enumeration)
    {
        if (enumeration == 0) return "None";
        if (enumeration == 1) return "Cold";
        if (enumeration == 2) return "Warm";
        if (enumeration == 3) return "Hot";
        if (enumeration == 4) return "Transparent";
        if (enumeration == 5) return "HotAndMirrored";
        return "Unknown";
    }
    
    std::string
    RedundancySupport::enum2Str(void)
    {
        return enum2Str((Enum)value_);
    }
    
    std::string
    RedundancySupport::toString(void)
    {
        return enum2Str((Enum)value_);
    }
    
    bool
    RedundancySupport::exist(const std::string& enumerationString)
    {
        if (enumerationString == "None") return true;
        if (enumerationString == "Cold") return true;
        if (enumerationString == "Warm") return true;
        if (enumerationString == "Hot") return true;
        if (enumerationString == "Transparent") return true;
        if (enumerationString == "HotAndMirrored") return true;
        return false;
    }
    
    bool
    RedundancySupport::exist(Enum enumeration)
    {
        if (enumeration == 0) return true;
        if (enumeration == 1) return true;
        if (enumeration == 2) return true;
        if (enumeration == 3) return true;
        if (enumeration == 4) return true;
        if (enumeration == 5) return true;
        return false;
    }
    
    bool
    RedundancySupport::operator==(const RedundancySupport& value) const
    {
        if (value_ != value.value_) return false;
        return true;
    }
    
    bool
    RedundancySupport::operator!=(const RedundancySupport& value) const
    {
        return !this->operator==(value);
    }
    
    RedundancySupport&
    RedundancySupport::operator=(const RedundancySupport& value)
    {
        value_ = const_cast<RedundancySupport&>(value).value();
        return *this;
    }
    
    RedundancySupport&
    RedundancySupport::operator=(const Enum& value)
    {
        value_ = value;
        return *this;
    }
    
    void
    RedundancySupport::copyTo(RedundancySupport& value)
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
    RedundancySupport::factory(void)
    {
    	return constructSPtr<RedundancySupport>();
    }
    
    OpcUaNodeId
    RedundancySupport::binaryTypeId(void)
    {
    	return OpcUaNodeId(0, 0);
    }
    
    OpcUaNodeId
    RedundancySupport::xmlTypeId(void)
    {
    	return OpcUaNodeId(0, 0);
    }
    
    OpcUaNodeId
    RedundancySupport::jsonTypeId(void)
    {
    	return OpcUaNodeId(0, 0);
    }
    
    std::string
    RedundancySupport::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    RedundancySupport::typeName(void)
    {
    	return "RedundancySupport";
    }
    
    OpcUaNodeId
    RedundancySupport::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)851,0);
    }
    
    void
    RedundancySupport::opcUaBinaryEncode(std::ostream& os) const
    {
        OpcUaNumber::opcUaBinaryEncode(os, value_);
    }
    
    void
    RedundancySupport::opcUaBinaryDecode(std::istream& is)
    {
        OpcUaNumber::opcUaBinaryDecode(is, value_);
    }
    
    bool
    RedundancySupport::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        if(!XmlNumber::xmlEncode(pt, value_, element))
        {
    	     Log(Error, "RedundancySupport json encoder error")
    		     .parameter("Element", element);
            return false;
        }
        return true;
    }
    
    bool
    RedundancySupport::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        if(!XmlNumber::xmlEncode(pt, value_)) {
    	     Log(Error, "RedundancySupport json encoder error");
            return false;
        }
        return true;
    }
    
    bool
    RedundancySupport::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(element);
        if (!tree) {
    	     Log(Error, "RedundancySupport json decoder error")
    		     .parameter("Element", element);
            return false;
         }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    RedundancySupport::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        if(!XmlNumber::xmlDecode(pt, value_)) {
    	     Log(Error, "RedundancySupport json decoder error");
            return false;
        }
        return true;
    }
    
    bool
    RedundancySupport::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        if(!JsonNumber::jsonEncode(pt, value_))
        {
    	     Log(Error, "RedundancySupport json encoder error")
    		     .parameter("Element", "Value");
           return false;
        }
        return true;
    }
    
    bool
    RedundancySupport::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        if(!JsonNumber::jsonDecode(pt, value_)) {
            Log(Error, "RedundancySupport decode json error - decode failed");
            return false;
        }
        return true;
    }
    
    void
    RedundancySupport::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	RedundancySupport* dst = dynamic_cast<RedundancySupport*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    RedundancySupport::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	RedundancySupport* dst = dynamic_cast<RedundancySupport*>(&extensionObjectBase);
    	return *this == *dst;
    }
    
    void
    RedundancySupport::out(std::ostream& os)
    {
        os << "Value=" << value_;
    }

}
