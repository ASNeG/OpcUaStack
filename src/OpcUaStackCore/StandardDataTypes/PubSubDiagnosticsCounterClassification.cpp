/*
    EnumTypeClass: PubSubDiagnosticsCounterClassification

    Generated Source Code - please do not change this source code

    EnumTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/PubSubDiagnosticsCounterClassification.h"

namespace OpcUaStackCore
{
    
    PubSubDiagnosticsCounterClassification::PubSubDiagnosticsCounterClassification(void)
    : Object()
    , ExtensionObjectBase()
    , value_(0)
    {
    }
    
    PubSubDiagnosticsCounterClassification::PubSubDiagnosticsCounterClassification(Enum enumeration)
    : Object()
    , ExtensionObjectBase()
    , value_(enumeration)
    {
    }
    
    PubSubDiagnosticsCounterClassification::~PubSubDiagnosticsCounterClassification(void)
    {
    }
    
    uint32_t&
    PubSubDiagnosticsCounterClassification::value(void)
    {
        return value_;
    }
    
    void
    PubSubDiagnosticsCounterClassification::enumeration(PubSubDiagnosticsCounterClassification::Enum enumeration)
    {
        value_ = enumeration;
    }
    
    PubSubDiagnosticsCounterClassification::Enum
    PubSubDiagnosticsCounterClassification::enumeration(void)
    {
        return (Enum)value_;
    }
    
    PubSubDiagnosticsCounterClassification::Enum
    PubSubDiagnosticsCounterClassification::str2Enum(const std::string& enumerationString)
    {
        if (enumerationString == "Information") return (Enum)0;
        if (enumerationString == "Error") return (Enum)1;
        return (Enum)0;
    }
    
    std::string
    PubSubDiagnosticsCounterClassification::enum2Str(Enum enumeration)
    {
        if (enumeration == 0) return "Information";
        if (enumeration == 1) return "Error";
        return "Unknown";
    }
    
    bool
    PubSubDiagnosticsCounterClassification::exist(const std::string& enumerationString)
    {
        if (enumerationString == "Information") return true;
        if (enumerationString == "Error") return true;
        return false;
    }
    
    bool
    PubSubDiagnosticsCounterClassification::exist(Enum enumeration)
    {
        if (enumeration == 0) return true;
        if (enumeration == 1) return true;
        return false;
    }
    
    bool
    PubSubDiagnosticsCounterClassification::operator==(const PubSubDiagnosticsCounterClassification& value) const
    {
        if (value_ != value.value_) return false;
        return true;
    }
    
    bool
    PubSubDiagnosticsCounterClassification::operator!=(const PubSubDiagnosticsCounterClassification& value) const
    {
        return !this->operator==(value);
    }
    
    void
    PubSubDiagnosticsCounterClassification::copyTo(PubSubDiagnosticsCounterClassification& value)
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
    PubSubDiagnosticsCounterClassification::factory(void)
    {
    	return constructSPtr<PubSubDiagnosticsCounterClassification>();
    }
    
    OpcUaNodeId
    PubSubDiagnosticsCounterClassification::binaryTypeId(void)
    {
    	return OpcUaNodeId(0, 0);
    }
    
    OpcUaNodeId
    PubSubDiagnosticsCounterClassification::xmlTypeId(void)
    {
    	return OpcUaNodeId(0, 0);
    }
    
    void
    PubSubDiagnosticsCounterClassification::opcUaBinaryEncode(std::ostream& os) const
    {
        OpcUaNumber::opcUaBinaryEncode(os, value_);
    }
    
    void
    PubSubDiagnosticsCounterClassification::opcUaBinaryDecode(std::istream& is)
    {
        OpcUaNumber::opcUaBinaryDecode(is, value_);
    }
    
    bool
    PubSubDiagnosticsCounterClassification::encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const
    {
    }
    
    bool
    PubSubDiagnosticsCounterClassification::decode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
    }
    
    bool
    PubSubDiagnosticsCounterClassification::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
    }
    
    bool
    PubSubDiagnosticsCounterClassification::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
    }
    
    bool
    PubSubDiagnosticsCounterClassification::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
    }
    
    void
    PubSubDiagnosticsCounterClassification::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	PubSubDiagnosticsCounterClassification* dst = dynamic_cast<PubSubDiagnosticsCounterClassification*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    PubSubDiagnosticsCounterClassification::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	PubSubDiagnosticsCounterClassification* dst = dynamic_cast<PubSubDiagnosticsCounterClassification*>(&extensionObjectBase);
    	return *this == *dst;
    }
    
    void
    PubSubDiagnosticsCounterClassification::out(std::ostream& os)
    {
        os << "Value=" << value_;
    }

}
