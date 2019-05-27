/*
    EnumTypeClass: ExceptionDeviationFormat

    Generated Source Code - please do not change this source code

    EnumTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/ExceptionDeviationFormat.h"

namespace OpcUaStackCore
{
    
    ExceptionDeviationFormat::ExceptionDeviationFormat(void)
    : Object()
    , ExtensionObjectBase()
    , value_(0)
    {
    }
    
    ExceptionDeviationFormat::ExceptionDeviationFormat(Enum enumeration)
    : Object()
    , ExtensionObjectBase()
    , value_(enumeration)
    {
    }
    
    ExceptionDeviationFormat::ExceptionDeviationFormat(ExceptionDeviationFormat& value)
    : Object()
    , ExtensionObjectBase()
    , value_(value.enumeration())
    {
    }
    
    ExceptionDeviationFormat::~ExceptionDeviationFormat(void)
    {
    }
    
    int32_t&
    ExceptionDeviationFormat::value(void)
    {
        return value_;
    }
    
    void
    ExceptionDeviationFormat::enumeration(ExceptionDeviationFormat::Enum enumeration)
    {
        value_ = enumeration;
    }
    
    ExceptionDeviationFormat::Enum
    ExceptionDeviationFormat::enumeration(void)
    {
        return (Enum)value_;
    }
    
    ExceptionDeviationFormat::Enum
    ExceptionDeviationFormat::str2Enum(const std::string& enumerationString)
    {
        if (enumerationString == "AbsoluteValue") return (Enum)0;
        if (enumerationString == "PercentOfValue") return (Enum)1;
        if (enumerationString == "PercentOfRange") return (Enum)2;
        if (enumerationString == "PercentOfEURange") return (Enum)3;
        if (enumerationString == "Unknown") return (Enum)4;
        return (Enum)0;
    }
    
    std::string
    ExceptionDeviationFormat::enum2Str(Enum enumeration)
    {
        if (enumeration == 0) return "AbsoluteValue";
        if (enumeration == 1) return "PercentOfValue";
        if (enumeration == 2) return "PercentOfRange";
        if (enumeration == 3) return "PercentOfEURange";
        if (enumeration == 4) return "Unknown";
        return "Unknown";
    }
    
    std::string
    ExceptionDeviationFormat::enum2Str(void)
    {
        return enum2Str((Enum)value_);
    }
    
    std::string
    ExceptionDeviationFormat::toString(void)
    {
        return enum2Str((Enum)value_);
    }
    
    bool
    ExceptionDeviationFormat::exist(const std::string& enumerationString)
    {
        if (enumerationString == "AbsoluteValue") return true;
        if (enumerationString == "PercentOfValue") return true;
        if (enumerationString == "PercentOfRange") return true;
        if (enumerationString == "PercentOfEURange") return true;
        if (enumerationString == "Unknown") return true;
        return false;
    }
    
    bool
    ExceptionDeviationFormat::exist(Enum enumeration)
    {
        if (enumeration == 0) return true;
        if (enumeration == 1) return true;
        if (enumeration == 2) return true;
        if (enumeration == 3) return true;
        if (enumeration == 4) return true;
        return false;
    }
    
    bool
    ExceptionDeviationFormat::operator==(const ExceptionDeviationFormat& value) const
    {
        if (value_ != value.value_) return false;
        return true;
    }
    
    bool
    ExceptionDeviationFormat::operator!=(const ExceptionDeviationFormat& value) const
    {
        return !this->operator==(value);
    }
    
    ExceptionDeviationFormat&
    ExceptionDeviationFormat::operator=(const ExceptionDeviationFormat& value)
    {
        value_ = const_cast<ExceptionDeviationFormat&>(value).value();
        return *this;
    }
    
    ExceptionDeviationFormat&
    ExceptionDeviationFormat::operator=(const Enum& value)
    {
        value_ = value;
        return *this;
    }
    
    void
    ExceptionDeviationFormat::copyTo(ExceptionDeviationFormat& value)
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
    ExceptionDeviationFormat::factory(void)
    {
    	return constructSPtr<ExceptionDeviationFormat>();
    }
    
    OpcUaNodeId
    ExceptionDeviationFormat::binaryTypeId(void)
    {
    	return OpcUaNodeId(0, 0);
    }
    
    OpcUaNodeId
    ExceptionDeviationFormat::xmlTypeId(void)
    {
    	return OpcUaNodeId(0, 0);
    }
    
    OpcUaNodeId
    ExceptionDeviationFormat::jsonTypeId(void)
    {
    	return OpcUaNodeId(0, 0);
    }
    
    std::string
    ExceptionDeviationFormat::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    ExceptionDeviationFormat::typeName(void)
    {
    	return "ExceptionDeviationFormat";
    }
    
    OpcUaNodeId
    ExceptionDeviationFormat::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)890,0);
    }
    
    void
    ExceptionDeviationFormat::opcUaBinaryEncode(std::ostream& os) const
    {
        OpcUaNumber::opcUaBinaryEncode(os, value_);
    }
    
    void
    ExceptionDeviationFormat::opcUaBinaryDecode(std::istream& is)
    {
        OpcUaNumber::opcUaBinaryDecode(is, value_);
    }
    
    bool
    ExceptionDeviationFormat::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        if(!XmlNumber::xmlEncode(pt, value_, element))
        {
    	     Log(Error, "ExceptionDeviationFormat json encoder error")
    		     .parameter("Element", element);
            return false;
        }
        return true;
    }
    
    bool
    ExceptionDeviationFormat::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        if(!XmlNumber::xmlEncode(pt, value_)) {
    	     Log(Error, "ExceptionDeviationFormat json encoder error");
            return false;
        }
        return true;
    }
    
    bool
    ExceptionDeviationFormat::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(element);
        if (!tree) {
    	     Log(Error, "ExceptionDeviationFormat json decoder error")
    		     .parameter("Element", element);
            return false;
         }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    ExceptionDeviationFormat::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        if(!XmlNumber::xmlDecode(pt, value_)) {
    	     Log(Error, "ExceptionDeviationFormat json decoder error");
            return false;
        }
        return true;
    }
    
    bool
    ExceptionDeviationFormat::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        if(!JsonNumber::jsonEncode(pt, value_))
        {
    	     Log(Error, "ExceptionDeviationFormat json encoder error")
    		     .parameter("Element", "Value");
           return false;
        }
        return true;
    }
    
    bool
    ExceptionDeviationFormat::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        if(!JsonNumber::jsonDecode(pt, value_)) {
            Log(Error, "ExceptionDeviationFormat decode json error - decode failed");
            return false;
        }
        return true;
    }
    
    void
    ExceptionDeviationFormat::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	ExceptionDeviationFormat* dst = dynamic_cast<ExceptionDeviationFormat*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    ExceptionDeviationFormat::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	ExceptionDeviationFormat* dst = dynamic_cast<ExceptionDeviationFormat*>(&extensionObjectBase);
    	return *this == *dst;
    }
    
    void
    ExceptionDeviationFormat::out(std::ostream& os)
    {
        os << "Value=" << value_;
    }

}
