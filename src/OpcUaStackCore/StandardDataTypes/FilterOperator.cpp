/*
    EnumTypeClass: FilterOperator

    Generated Source Code - please do not change this source code

    EnumTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/FilterOperator.h"

namespace OpcUaStackCore
{
    
    FilterOperator::FilterOperator(void)
    : Object()
    , ExtensionObjectBase()
    , value_(0)
    {
    }
    
    FilterOperator::FilterOperator(Enum enumeration)
    : Object()
    , ExtensionObjectBase()
    , value_(enumeration)
    {
    }
    
    FilterOperator::FilterOperator(FilterOperator& value)
    : Object()
    , ExtensionObjectBase()
    , value_(value.enumeration())
    {
    }
    
    FilterOperator::~FilterOperator(void)
    {
    }
    
    int32_t&
    FilterOperator::value(void)
    {
        return value_;
    }
    
    void
    FilterOperator::enumeration(FilterOperator::Enum enumeration)
    {
        value_ = enumeration;
    }
    
    FilterOperator::Enum
    FilterOperator::enumeration(void)
    {
        return (Enum)value_;
    }
    
    FilterOperator::Enum
    FilterOperator::str2Enum(const std::string& enumerationString)
    {
        if (enumerationString == "Equals") return (Enum)0;
        if (enumerationString == "IsNull") return (Enum)1;
        if (enumerationString == "GreaterThan") return (Enum)2;
        if (enumerationString == "LessThan") return (Enum)3;
        if (enumerationString == "GreaterThanOrEqual") return (Enum)4;
        if (enumerationString == "LessThanOrEqual") return (Enum)5;
        if (enumerationString == "Like") return (Enum)6;
        if (enumerationString == "Not") return (Enum)7;
        if (enumerationString == "Between") return (Enum)8;
        if (enumerationString == "InList") return (Enum)9;
        if (enumerationString == "And") return (Enum)10;
        if (enumerationString == "Or") return (Enum)11;
        if (enumerationString == "Cast") return (Enum)12;
        if (enumerationString == "InView") return (Enum)13;
        if (enumerationString == "OfType") return (Enum)14;
        if (enumerationString == "RelatedTo") return (Enum)15;
        if (enumerationString == "BitwiseAnd") return (Enum)16;
        if (enumerationString == "BitwiseOr") return (Enum)17;
        return (Enum)0;
    }
    
    std::string
    FilterOperator::enum2Str(Enum enumeration)
    {
        if (enumeration == 0) return "Equals";
        if (enumeration == 1) return "IsNull";
        if (enumeration == 2) return "GreaterThan";
        if (enumeration == 3) return "LessThan";
        if (enumeration == 4) return "GreaterThanOrEqual";
        if (enumeration == 5) return "LessThanOrEqual";
        if (enumeration == 6) return "Like";
        if (enumeration == 7) return "Not";
        if (enumeration == 8) return "Between";
        if (enumeration == 9) return "InList";
        if (enumeration == 10) return "And";
        if (enumeration == 11) return "Or";
        if (enumeration == 12) return "Cast";
        if (enumeration == 13) return "InView";
        if (enumeration == 14) return "OfType";
        if (enumeration == 15) return "RelatedTo";
        if (enumeration == 16) return "BitwiseAnd";
        if (enumeration == 17) return "BitwiseOr";
        return "Unknown";
    }
    
    std::string
    FilterOperator::enum2Str(void)
    {
        return enum2Str((Enum)value_);
    }
    
    std::string
    FilterOperator::toString(void)
    {
        return enum2Str((Enum)value_);
    }
    
    bool
    FilterOperator::exist(const std::string& enumerationString)
    {
        if (enumerationString == "Equals") return true;
        if (enumerationString == "IsNull") return true;
        if (enumerationString == "GreaterThan") return true;
        if (enumerationString == "LessThan") return true;
        if (enumerationString == "GreaterThanOrEqual") return true;
        if (enumerationString == "LessThanOrEqual") return true;
        if (enumerationString == "Like") return true;
        if (enumerationString == "Not") return true;
        if (enumerationString == "Between") return true;
        if (enumerationString == "InList") return true;
        if (enumerationString == "And") return true;
        if (enumerationString == "Or") return true;
        if (enumerationString == "Cast") return true;
        if (enumerationString == "InView") return true;
        if (enumerationString == "OfType") return true;
        if (enumerationString == "RelatedTo") return true;
        if (enumerationString == "BitwiseAnd") return true;
        if (enumerationString == "BitwiseOr") return true;
        return false;
    }
    
    bool
    FilterOperator::exist(Enum enumeration)
    {
        if (enumeration == 0) return true;
        if (enumeration == 1) return true;
        if (enumeration == 2) return true;
        if (enumeration == 3) return true;
        if (enumeration == 4) return true;
        if (enumeration == 5) return true;
        if (enumeration == 6) return true;
        if (enumeration == 7) return true;
        if (enumeration == 8) return true;
        if (enumeration == 9) return true;
        if (enumeration == 10) return true;
        if (enumeration == 11) return true;
        if (enumeration == 12) return true;
        if (enumeration == 13) return true;
        if (enumeration == 14) return true;
        if (enumeration == 15) return true;
        if (enumeration == 16) return true;
        if (enumeration == 17) return true;
        return false;
    }
    
    bool
    FilterOperator::operator==(const FilterOperator& value) const
    {
        if (value_ != value.value_) return false;
        return true;
    }
    
    bool
    FilterOperator::operator!=(const FilterOperator& value) const
    {
        return !this->operator==(value);
    }
    
    FilterOperator&
    FilterOperator::operator=(const FilterOperator& value)
    {
        value_ = const_cast<FilterOperator&>(value).value();
        return *this;
    }
    
    FilterOperator&
    FilterOperator::operator=(const Enum& value)
    {
        value_ = value;
        return *this;
    }
    
    void
    FilterOperator::copyTo(FilterOperator& value)
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
    FilterOperator::factory(void)
    {
    	return constructSPtr<FilterOperator>();
    }
    
    OpcUaNodeId
    FilterOperator::binaryTypeId(void)
    {
    	return OpcUaNodeId(0, 0);
    }
    
    OpcUaNodeId
    FilterOperator::xmlTypeId(void)
    {
    	return OpcUaNodeId(0, 0);
    }
    
    OpcUaNodeId
    FilterOperator::jsonTypeId(void)
    {
    	return OpcUaNodeId(0, 0);
    }
    
    std::string
    FilterOperator::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    FilterOperator::typeName(void)
    {
    	return "FilterOperator";
    }
    
    OpcUaNodeId
    FilterOperator::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)576,0);
    }
    
    void
    FilterOperator::opcUaBinaryEncode(std::ostream& os) const
    {
        OpcUaNumber::opcUaBinaryEncode(os, value_);
    }
    
    void
    FilterOperator::opcUaBinaryDecode(std::istream& is)
    {
        OpcUaNumber::opcUaBinaryDecode(is, value_);
    }
    
    bool
    FilterOperator::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        if(!XmlNumber::xmlEncode(pt, value_, element))
        {
    	     Log(Error, "FilterOperator json encoder error")
    		     .parameter("Element", element);
            return false;
        }
        return true;
    }
    
    bool
    FilterOperator::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        if(!XmlNumber::xmlEncode(pt, value_)) {
    	     Log(Error, "FilterOperator json encoder error");
            return false;
        }
        return true;
    }
    
    bool
    FilterOperator::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(element);
        if (!tree) {
    	     Log(Error, "FilterOperator json decoder error")
    		     .parameter("Element", element);
            return false;
         }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    FilterOperator::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        if(!XmlNumber::xmlDecode(pt, value_)) {
    	     Log(Error, "FilterOperator json decoder error");
            return false;
        }
        return true;
    }
    
    bool
    FilterOperator::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        if(!JsonNumber::jsonEncode(pt, value_))
        {
    	     Log(Error, "FilterOperator json encoder error")
    		     .parameter("Element", "Value");
           return false;
        }
        return true;
    }
    
    bool
    FilterOperator::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        if(!JsonNumber::jsonDecode(pt, value_)) {
            Log(Error, "FilterOperator decode json error - decode failed");
            return false;
        }
        return true;
    }
    
    void
    FilterOperator::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	FilterOperator* dst = dynamic_cast<FilterOperator*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    FilterOperator::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	FilterOperator* dst = dynamic_cast<FilterOperator*>(&extensionObjectBase);
    	return *this == *dst;
    }
    
    void
    FilterOperator::out(std::ostream& os)
    {
        os << "Value=" << value_;
    }

}
