/*
    EnumTypeClass: ApplicationType

    Generated Source Code - please do not change this source code

    EnumTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/ApplicationType.h"

namespace OpcUaStackCore
{
    
    ApplicationType::ApplicationType(void)
    : Object()
    , ExtensionObjectBase()
    , value_(0)
    {
    }
    
    ApplicationType::~ApplicationType(void)
    {
    }
    
    uint32_t&
    ApplicationType::value(void)
    {
        return value_;
    }
    
    void
    ApplicationType::enumeration(ApplicationType::Enum enumeration)
    {
        value_ = enumeration;
    }
    
    ApplicationType::Enum
    ApplicationType::enumeration(void)
    {
        return (Enum)value_;
    }
    
    ApplicationType::Enum
    ApplicationType::str2Enum(const std::string& enumerationString)
    {
        if (enumerationString == "Server") return (Enum)0;
        if (enumerationString == "Client") return (Enum)1;
        if (enumerationString == "ClientAndServer") return (Enum)2;
        if (enumerationString == "DiscoveryServer") return (Enum)3;
        return (Enum)0;
    }
    
    std::string
    ApplicationType::enum2Str(Enum enumeration)
    {
        if (enumeration == 0) return "Server";
        if (enumeration == 1) return "Client";
        if (enumeration == 2) return "ClientAndServer";
        if (enumeration == 3) return "DiscoveryServer";
        return "Unknown";
    }
    
    bool
    ApplicationType::exist(const std::string& enumerationString)
    {
        if (enumerationString == "Server") return true;
        if (enumerationString == "Client") return true;
        if (enumerationString == "ClientAndServer") return true;
        if (enumerationString == "DiscoveryServer") return true;
        return false;
    }
    
    bool
    ApplicationType::exist(Enum enumeration)
    {
        if (enumeration == 0) return true;
        if (enumeration == 1) return true;
        if (enumeration == 2) return true;
        if (enumeration == 3) return true;
        return false;
    }
    
    bool
    ApplicationType::operator==(const ApplicationType& value) const
    {
        if (value_ != value.value_) return false;
        return true;
    }
    
    void
    ApplicationType::copyTo(ApplicationType& value)
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
    ApplicationType::factory(void)
    {
    	return constructSPtr<ApplicationType>();
    }
    
    OpcUaNodeId
    ApplicationType::binaryTypeId(void)
    {
    	return OpcUaNodeId(0, 0);
    }
    
    OpcUaNodeId
    ApplicationType::xmlTypeId(void)
    {
    	return OpcUaNodeId(0, 0);
    }
    
    void
    ApplicationType::opcUaBinaryEncode(std::ostream& os) const
    {
        OpcUaNumber::opcUaBinaryEncode(os, value_);
    }
    
    void
    ApplicationType::opcUaBinaryDecode(std::istream& is)
    {
        OpcUaNumber::opcUaBinaryDecode(is, value_);
    }
    
    bool
    ApplicationType::encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const
    {
    }
    
    bool
    ApplicationType::decode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
    }
    
    bool
    ApplicationType::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
    }
    
    bool
    ApplicationType::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
    }
    
    bool
    ApplicationType::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
    }
    
    void
    ApplicationType::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	ApplicationType* dst = dynamic_cast<ApplicationType*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    ApplicationType::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	ApplicationType* dst = dynamic_cast<ApplicationType*>(&extensionObjectBase);
    	return *this == *dst;
    }
    
    void
    ApplicationType::out(std::ostream& os)
    {
        os << "Value=" << value_;
    }

}
