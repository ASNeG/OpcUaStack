/*
    EnumTypeClass: ApplicationType

    Generated Source Code - please do not change this source code

    EnumTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

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
    
    ApplicationType::ApplicationType(Enum enumeration)
    : Object()
    , ExtensionObjectBase()
    , value_(enumeration)
    {
    }
    
    ApplicationType::ApplicationType(ApplicationType& value)
    : Object()
    , ExtensionObjectBase()
    , value_(value.enumeration())
    {
    }
    
    ApplicationType::~ApplicationType(void)
    {
    }
    
    int32_t&
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
    
    std::string
    ApplicationType::enum2Str(void)
    {
        return enum2Str((Enum)value_);
    }
    
    std::string
    ApplicationType::toString(void)
    {
        return enum2Str((Enum)value_);
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
    
    bool
    ApplicationType::operator!=(const ApplicationType& value) const
    {
        return !this->operator==(value);
    }
    
    ApplicationType&
    ApplicationType::operator=(const ApplicationType& value)
    {
        value_ = const_cast<ApplicationType&>(value).value();
        return *this;
    }
    
    ApplicationType&
    ApplicationType::operator=(const Enum& value)
    {
        value_ = value;
        return *this;
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
    
    OpcUaNodeId
    ApplicationType::jsonTypeId(void)
    {
    	return OpcUaNodeId(0, 0);
    }
    
    std::string
    ApplicationType::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    ApplicationType::typeName(void)
    {
    	return "ApplicationType";
    }
    
    OpcUaNodeId
    ApplicationType::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)307,0);
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
    ApplicationType::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        if(!XmlNumber::xmlEncode(pt, value_, element))
        {
    	     Log(Error, "ApplicationType json encoder error")
    		     .parameter("Element", element);
            return false;
        }
        return true;
    }
    
    bool
    ApplicationType::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        if(!XmlNumber::xmlEncode(pt, value_)) {
    	     Log(Error, "ApplicationType json encoder error");
            return false;
        }
        return true;
    }
    
    bool
    ApplicationType::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(element);
        if (!tree) {
    	     Log(Error, "ApplicationType json decoder error")
    		     .parameter("Element", element);
            return false;
         }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    ApplicationType::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        if(!XmlNumber::xmlDecode(pt, value_)) {
    	     Log(Error, "ApplicationType json decoder error");
            return false;
        }
        return true;
    }
    
    bool
    ApplicationType::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        if(!JsonNumber::jsonEncode(pt, value_))
        {
    	     Log(Error, "ApplicationType json encoder error")
    		     .parameter("Element", "Value");
           return false;
        }
        return true;
    }
    
    bool
    ApplicationType::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        if(!JsonNumber::jsonDecode(pt, value_)) {
            Log(Error, "ApplicationType decode json error - decode failed");
            return false;
        }
        return true;
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
