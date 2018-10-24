/*
    EnumTypeClass: ExceptionDeviationFormat

    Generated Source Code - please do not change this source code

    EnumTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.1

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
    
    ExceptionDeviationFormat::~ExceptionDeviationFormat(void)
    {
    }
    
    uint32_t&
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
    ExceptionDeviationFormat::encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const
    {
    }
    
    bool
    ExceptionDeviationFormat::decode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
    }
    
    bool
    ExceptionDeviationFormat::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
    }
    
    bool
    ExceptionDeviationFormat::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
    }
    
    bool
    ExceptionDeviationFormat::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
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
