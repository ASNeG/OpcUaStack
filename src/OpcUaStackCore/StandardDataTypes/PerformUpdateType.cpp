/*
    EnumTypeClass: PerformUpdateType

    Generated Source Code - please do not change this source code

    EnumTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/PerformUpdateType.h"

namespace OpcUaStackCore
{
    
    PerformUpdateType::PerformUpdateType(void)
    : Object()
    , ExtensionObjectBase()
    , value_(0)
    {
    }
    
    PerformUpdateType::PerformUpdateType(Enum enumeration)
    : Object()
    , ExtensionObjectBase()
    , value_(enumeration)
    {
    }
    
    PerformUpdateType::PerformUpdateType(PerformUpdateType& value)
    : Object()
    , ExtensionObjectBase()
    , value_(value.enumeration())
    {
    }
    
    PerformUpdateType::~PerformUpdateType(void)
    {
    }
    
    int32_t&
    PerformUpdateType::value(void)
    {
        return value_;
    }
    
    void
    PerformUpdateType::enumeration(PerformUpdateType::Enum enumeration)
    {
        value_ = enumeration;
    }
    
    PerformUpdateType::Enum
    PerformUpdateType::enumeration(void)
    {
        return (Enum)value_;
    }
    
    PerformUpdateType::Enum
    PerformUpdateType::str2Enum(const std::string& enumerationString)
    {
        if (enumerationString == "Insert") return (Enum)1;
        if (enumerationString == "Replace") return (Enum)2;
        if (enumerationString == "Update") return (Enum)3;
        if (enumerationString == "Remove") return (Enum)4;
        return (Enum)0;
    }
    
    std::string
    PerformUpdateType::enum2Str(Enum enumeration)
    {
        if (enumeration == 1) return "Insert";
        if (enumeration == 2) return "Replace";
        if (enumeration == 3) return "Update";
        if (enumeration == 4) return "Remove";
        return "Unknown";
    }
    
    std::string
    PerformUpdateType::enum2Str(void)
    {
        return enum2Str((Enum)value_);
    }
    
    std::string
    PerformUpdateType::toString(void)
    {
        return enum2Str((Enum)value_);
    }
    
    bool
    PerformUpdateType::exist(const std::string& enumerationString)
    {
        if (enumerationString == "Insert") return true;
        if (enumerationString == "Replace") return true;
        if (enumerationString == "Update") return true;
        if (enumerationString == "Remove") return true;
        return false;
    }
    
    bool
    PerformUpdateType::exist(Enum enumeration)
    {
        if (enumeration == 1) return true;
        if (enumeration == 2) return true;
        if (enumeration == 3) return true;
        if (enumeration == 4) return true;
        return false;
    }
    
    bool
    PerformUpdateType::operator==(const PerformUpdateType& value) const
    {
        if (value_ != value.value_) return false;
        return true;
    }
    
    bool
    PerformUpdateType::operator!=(const PerformUpdateType& value) const
    {
        return !this->operator==(value);
    }
    
    PerformUpdateType&
    PerformUpdateType::operator=(const PerformUpdateType& value)
    {
        value_ = const_cast<PerformUpdateType&>(value).value();
        return *this;
    }
    
    PerformUpdateType&
    PerformUpdateType::operator=(const Enum& value)
    {
        value_ = value;
        return *this;
    }
    
    void
    PerformUpdateType::copyTo(PerformUpdateType& value)
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
    PerformUpdateType::factory(void)
    {
    	return constructSPtr<PerformUpdateType>();
    }
    
    OpcUaNodeId
    PerformUpdateType::binaryTypeId(void)
    {
    	return OpcUaNodeId(0, 0);
    }
    
    OpcUaNodeId
    PerformUpdateType::xmlTypeId(void)
    {
    	return OpcUaNodeId(0, 0);
    }
    
    OpcUaNodeId
    PerformUpdateType::jsonTypeId(void)
    {
    	return OpcUaNodeId(0, 0);
    }
    
    std::string
    PerformUpdateType::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    PerformUpdateType::typeName(void)
    {
    	return "PerformUpdateType";
    }
    
    OpcUaNodeId
    PerformUpdateType::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)11293,0);
    }
    
    void
    PerformUpdateType::opcUaBinaryEncode(std::ostream& os) const
    {
        OpcUaNumber::opcUaBinaryEncode(os, value_);
    }
    
    void
    PerformUpdateType::opcUaBinaryDecode(std::istream& is)
    {
        OpcUaNumber::opcUaBinaryDecode(is, value_);
    }
    
    bool
    PerformUpdateType::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        if(!XmlNumber::xmlEncode(pt, value_, element))
        {
    	     Log(Error, "PerformUpdateType json encoder error")
    		     .parameter("Element", element);
            return false;
        }
        return true;
    }
    
    bool
    PerformUpdateType::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        if(!XmlNumber::xmlEncode(pt, value_)) {
    	     Log(Error, "PerformUpdateType json encoder error");
            return false;
        }
        return true;
    }
    
    bool
    PerformUpdateType::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(element);
        if (!tree) {
    	     Log(Error, "PerformUpdateType json decoder error")
    		     .parameter("Element", element);
            return false;
         }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    PerformUpdateType::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        if(!XmlNumber::xmlDecode(pt, value_)) {
    	     Log(Error, "PerformUpdateType json decoder error");
            return false;
        }
        return true;
    }
    
    bool
    PerformUpdateType::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        if(!JsonNumber::jsonEncode(pt, value_))
        {
    	     Log(Error, "PerformUpdateType json encoder error")
    		     .parameter("Element", "Value");
           return false;
        }
        return true;
    }
    
    bool
    PerformUpdateType::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        if(!JsonNumber::jsonDecode(pt, value_)) {
            Log(Error, "PerformUpdateType decode json error - decode failed");
            return false;
        }
        return true;
    }
    
    void
    PerformUpdateType::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	PerformUpdateType* dst = dynamic_cast<PerformUpdateType*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    PerformUpdateType::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	PerformUpdateType* dst = dynamic_cast<PerformUpdateType*>(&extensionObjectBase);
    	return *this == *dst;
    }
    
    void
    PerformUpdateType::out(std::ostream& os)
    {
        os << "Value=" << value_;
    }

}
