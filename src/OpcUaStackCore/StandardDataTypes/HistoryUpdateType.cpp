/*
    EnumTypeClass: HistoryUpdateType

    Generated Source Code - please do not change this source code

    EnumTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/HistoryUpdateType.h"

namespace OpcUaStackCore
{
    
    HistoryUpdateType::HistoryUpdateType(void)
    : Object()
    , ExtensionObjectBase()
    , value_(0)
    {
    }
    
    HistoryUpdateType::HistoryUpdateType(Enum enumeration)
    : Object()
    , ExtensionObjectBase()
    , value_(enumeration)
    {
    }
    
    HistoryUpdateType::HistoryUpdateType(HistoryUpdateType& value)
    : Object()
    , ExtensionObjectBase()
    , value_(value.enumeration())
    {
    }
    
    HistoryUpdateType::~HistoryUpdateType(void)
    {
    }
    
    int32_t&
    HistoryUpdateType::value(void)
    {
        return value_;
    }
    
    void
    HistoryUpdateType::enumeration(HistoryUpdateType::Enum enumeration)
    {
        value_ = enumeration;
    }
    
    HistoryUpdateType::Enum
    HistoryUpdateType::enumeration(void)
    {
        return (Enum)value_;
    }
    
    HistoryUpdateType::Enum
    HistoryUpdateType::str2Enum(const std::string& enumerationString)
    {
        if (enumerationString == "Insert") return (Enum)1;
        if (enumerationString == "Replace") return (Enum)2;
        if (enumerationString == "Update") return (Enum)3;
        if (enumerationString == "Delete") return (Enum)4;
        return (Enum)0;
    }
    
    std::string
    HistoryUpdateType::enum2Str(Enum enumeration)
    {
        if (enumeration == 1) return "Insert";
        if (enumeration == 2) return "Replace";
        if (enumeration == 3) return "Update";
        if (enumeration == 4) return "Delete";
        return "Unknown";
    }
    
    std::string
    HistoryUpdateType::enum2Str(void)
    {
        return enum2Str((Enum)value_);
    }
    
    std::string
    HistoryUpdateType::toString(void)
    {
        return enum2Str((Enum)value_);
    }
    
    bool
    HistoryUpdateType::exist(const std::string& enumerationString)
    {
        if (enumerationString == "Insert") return true;
        if (enumerationString == "Replace") return true;
        if (enumerationString == "Update") return true;
        if (enumerationString == "Delete") return true;
        return false;
    }
    
    bool
    HistoryUpdateType::exist(Enum enumeration)
    {
        if (enumeration == 1) return true;
        if (enumeration == 2) return true;
        if (enumeration == 3) return true;
        if (enumeration == 4) return true;
        return false;
    }
    
    bool
    HistoryUpdateType::operator==(const HistoryUpdateType& value) const
    {
        if (value_ != value.value_) return false;
        return true;
    }
    
    bool
    HistoryUpdateType::operator!=(const HistoryUpdateType& value) const
    {
        return !this->operator==(value);
    }
    
    HistoryUpdateType&
    HistoryUpdateType::operator=(const HistoryUpdateType& value)
    {
        value_ = const_cast<HistoryUpdateType&>(value).value();
        return *this;
    }
    
    HistoryUpdateType&
    HistoryUpdateType::operator=(const Enum& value)
    {
        value_ = value;
        return *this;
    }
    
    void
    HistoryUpdateType::copyTo(HistoryUpdateType& value)
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
    HistoryUpdateType::factory(void)
    {
    	return constructSPtr<HistoryUpdateType>();
    }
    
    OpcUaNodeId
    HistoryUpdateType::binaryTypeId(void)
    {
    	return OpcUaNodeId(0, 0);
    }
    
    OpcUaNodeId
    HistoryUpdateType::xmlTypeId(void)
    {
    	return OpcUaNodeId(0, 0);
    }
    
    OpcUaNodeId
    HistoryUpdateType::jsonTypeId(void)
    {
    	return OpcUaNodeId(0, 0);
    }
    
    std::string
    HistoryUpdateType::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    HistoryUpdateType::typeName(void)
    {
    	return "HistoryUpdateType";
    }
    
    OpcUaNodeId
    HistoryUpdateType::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)11234,0);
    }
    
    void
    HistoryUpdateType::opcUaBinaryEncode(std::ostream& os) const
    {
        OpcUaNumber::opcUaBinaryEncode(os, value_);
    }
    
    void
    HistoryUpdateType::opcUaBinaryDecode(std::istream& is)
    {
        OpcUaNumber::opcUaBinaryDecode(is, value_);
    }
    
    bool
    HistoryUpdateType::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        if(!XmlNumber::xmlEncode(pt, value_, element))
        {
    	     Log(Error, "HistoryUpdateType json encoder error")
    		     .parameter("Element", element);
            return false;
        }
        return true;
    }
    
    bool
    HistoryUpdateType::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        if(!XmlNumber::xmlEncode(pt, value_)) {
    	     Log(Error, "HistoryUpdateType json encoder error");
            return false;
        }
        return true;
    }
    
    bool
    HistoryUpdateType::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(element);
        if (!tree) {
    	     Log(Error, "HistoryUpdateType json decoder error")
    		     .parameter("Element", element);
            return false;
         }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    HistoryUpdateType::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        if(!XmlNumber::xmlDecode(pt, value_)) {
    	     Log(Error, "HistoryUpdateType json decoder error");
            return false;
        }
        return true;
    }
    
    bool
    HistoryUpdateType::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        if(!JsonNumber::jsonEncode(pt, value_))
        {
    	     Log(Error, "HistoryUpdateType json encoder error")
    		     .parameter("Element", "Value");
           return false;
        }
        return true;
    }
    
    bool
    HistoryUpdateType::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        if(!JsonNumber::jsonDecode(pt, value_)) {
            Log(Error, "HistoryUpdateType decode json error - decode failed");
            return false;
        }
        return true;
    }
    
    void
    HistoryUpdateType::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	HistoryUpdateType* dst = dynamic_cast<HistoryUpdateType*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    HistoryUpdateType::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	HistoryUpdateType* dst = dynamic_cast<HistoryUpdateType*>(&extensionObjectBase);
    	return *this == *dst;
    }
    
    void
    HistoryUpdateType::out(std::ostream& os)
    {
        os << "Value=" << value_;
    }

}
