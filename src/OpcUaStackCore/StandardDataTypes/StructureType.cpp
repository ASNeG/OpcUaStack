/*
    EnumTypeClass: StructureType

    Generated Source Code - please do not change this source code

    EnumTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/StructureType.h"

namespace OpcUaStackCore
{
    
    StructureType::StructureType(void)
    : Object()
    , ExtensionObjectBase()
    , value_(0)
    {
    }
    
    StructureType::StructureType(Enum enumeration)
    : Object()
    , ExtensionObjectBase()
    , value_(enumeration)
    {
    }
    
    StructureType::StructureType(StructureType& value)
    : Object()
    , ExtensionObjectBase()
    , value_(value.enumeration())
    {
    }
    
    StructureType::~StructureType(void)
    {
    }
    
    int32_t&
    StructureType::value(void)
    {
        return value_;
    }
    
    void
    StructureType::enumeration(StructureType::Enum enumeration)
    {
        value_ = enumeration;
    }
    
    StructureType::Enum
    StructureType::enumeration(void)
    {
        return (Enum)value_;
    }
    
    StructureType::Enum
    StructureType::str2Enum(const std::string& enumerationString)
    {
        if (enumerationString == "Structure") return (Enum)0;
        if (enumerationString == "StructureWithOptionalFields") return (Enum)1;
        if (enumerationString == "Union") return (Enum)2;
        return (Enum)0;
    }
    
    std::string
    StructureType::enum2Str(Enum enumeration)
    {
        if (enumeration == 0) return "Structure";
        if (enumeration == 1) return "StructureWithOptionalFields";
        if (enumeration == 2) return "Union";
        return "Unknown";
    }
    
    std::string
    StructureType::enum2Str(void)
    {
        return enum2Str((Enum)value_);
    }
    
    std::string
    StructureType::toString(void)
    {
        return enum2Str((Enum)value_);
    }
    
    bool
    StructureType::exist(const std::string& enumerationString)
    {
        if (enumerationString == "Structure") return true;
        if (enumerationString == "StructureWithOptionalFields") return true;
        if (enumerationString == "Union") return true;
        return false;
    }
    
    bool
    StructureType::exist(Enum enumeration)
    {
        if (enumeration == 0) return true;
        if (enumeration == 1) return true;
        if (enumeration == 2) return true;
        return false;
    }
    
    bool
    StructureType::operator==(const StructureType& value) const
    {
        if (value_ != value.value_) return false;
        return true;
    }
    
    bool
    StructureType::operator!=(const StructureType& value) const
    {
        return !this->operator==(value);
    }
    
    StructureType&
    StructureType::operator=(const StructureType& value)
    {
        value_ = const_cast<StructureType&>(value).value();
        return *this;
    }
    
    StructureType&
    StructureType::operator=(const Enum& value)
    {
        value_ = value;
        return *this;
    }
    
    void
    StructureType::copyTo(StructureType& value)
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
    StructureType::factory(void)
    {
    	return constructSPtr<StructureType>();
    }
    
    OpcUaNodeId
    StructureType::binaryTypeId(void)
    {
    	return OpcUaNodeId(0, 0);
    }
    
    OpcUaNodeId
    StructureType::xmlTypeId(void)
    {
    	return OpcUaNodeId(0, 0);
    }
    
    OpcUaNodeId
    StructureType::jsonTypeId(void)
    {
    	return OpcUaNodeId(0, 0);
    }
    
    std::string
    StructureType::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    StructureType::typeName(void)
    {
    	return "StructureType";
    }
    
    OpcUaNodeId
    StructureType::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)98,0);
    }
    
    void
    StructureType::opcUaBinaryEncode(std::ostream& os) const
    {
        OpcUaNumber::opcUaBinaryEncode(os, value_);
    }
    
    void
    StructureType::opcUaBinaryDecode(std::istream& is)
    {
        OpcUaNumber::opcUaBinaryDecode(is, value_);
    }
    
    bool
    StructureType::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        if(!XmlNumber::xmlEncode(pt, value_, element))
        {
    	     Log(Error, "StructureType json encoder error")
    		     .parameter("Element", element);
            return false;
        }
        return true;
    }
    
    bool
    StructureType::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        if(!XmlNumber::xmlEncode(pt, value_)) {
    	     Log(Error, "StructureType json encoder error");
            return false;
        }
        return true;
    }
    
    bool
    StructureType::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(element);
        if (!tree) {
    	     Log(Error, "StructureType json decoder error")
    		     .parameter("Element", element);
            return false;
         }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    StructureType::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        if(!XmlNumber::xmlDecode(pt, value_)) {
    	     Log(Error, "StructureType json decoder error");
            return false;
        }
        return true;
    }
    
    bool
    StructureType::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        if(!JsonNumber::jsonEncode(pt, value_))
        {
    	     Log(Error, "StructureType json encoder error")
    		     .parameter("Element", "Value");
           return false;
        }
        return true;
    }
    
    bool
    StructureType::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        if(!JsonNumber::jsonDecode(pt, value_)) {
            Log(Error, "StructureType decode json error - decode failed");
            return false;
        }
        return true;
    }
    
    void
    StructureType::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	StructureType* dst = dynamic_cast<StructureType*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    StructureType::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	StructureType* dst = dynamic_cast<StructureType*>(&extensionObjectBase);
    	return *this == *dst;
    }
    
    void
    StructureType::out(std::ostream& os)
    {
        os << "Value=" << value_;
    }

}
