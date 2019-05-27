/*
    EnumTypeClass: BrokerTransportQualityOfService

    Generated Source Code - please do not change this source code

    EnumTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/BrokerTransportQualityOfService.h"

namespace OpcUaStackCore
{
    
    BrokerTransportQualityOfService::BrokerTransportQualityOfService(void)
    : Object()
    , ExtensionObjectBase()
    , value_(0)
    {
    }
    
    BrokerTransportQualityOfService::BrokerTransportQualityOfService(Enum enumeration)
    : Object()
    , ExtensionObjectBase()
    , value_(enumeration)
    {
    }
    
    BrokerTransportQualityOfService::BrokerTransportQualityOfService(BrokerTransportQualityOfService& value)
    : Object()
    , ExtensionObjectBase()
    , value_(value.enumeration())
    {
    }
    
    BrokerTransportQualityOfService::~BrokerTransportQualityOfService(void)
    {
    }
    
    int32_t&
    BrokerTransportQualityOfService::value(void)
    {
        return value_;
    }
    
    void
    BrokerTransportQualityOfService::enumeration(BrokerTransportQualityOfService::Enum enumeration)
    {
        value_ = enumeration;
    }
    
    BrokerTransportQualityOfService::Enum
    BrokerTransportQualityOfService::enumeration(void)
    {
        return (Enum)value_;
    }
    
    BrokerTransportQualityOfService::Enum
    BrokerTransportQualityOfService::str2Enum(const std::string& enumerationString)
    {
        if (enumerationString == "NotSpecified") return (Enum)0;
        if (enumerationString == "BestEffort") return (Enum)1;
        if (enumerationString == "AtLeastOnce") return (Enum)2;
        if (enumerationString == "AtMostOnce") return (Enum)3;
        if (enumerationString == "ExactlyOnce") return (Enum)4;
        return (Enum)0;
    }
    
    std::string
    BrokerTransportQualityOfService::enum2Str(Enum enumeration)
    {
        if (enumeration == 0) return "NotSpecified";
        if (enumeration == 1) return "BestEffort";
        if (enumeration == 2) return "AtLeastOnce";
        if (enumeration == 3) return "AtMostOnce";
        if (enumeration == 4) return "ExactlyOnce";
        return "Unknown";
    }
    
    std::string
    BrokerTransportQualityOfService::enum2Str(void)
    {
        return enum2Str((Enum)value_);
    }
    
    std::string
    BrokerTransportQualityOfService::toString(void)
    {
        return enum2Str((Enum)value_);
    }
    
    bool
    BrokerTransportQualityOfService::exist(const std::string& enumerationString)
    {
        if (enumerationString == "NotSpecified") return true;
        if (enumerationString == "BestEffort") return true;
        if (enumerationString == "AtLeastOnce") return true;
        if (enumerationString == "AtMostOnce") return true;
        if (enumerationString == "ExactlyOnce") return true;
        return false;
    }
    
    bool
    BrokerTransportQualityOfService::exist(Enum enumeration)
    {
        if (enumeration == 0) return true;
        if (enumeration == 1) return true;
        if (enumeration == 2) return true;
        if (enumeration == 3) return true;
        if (enumeration == 4) return true;
        return false;
    }
    
    bool
    BrokerTransportQualityOfService::operator==(const BrokerTransportQualityOfService& value) const
    {
        if (value_ != value.value_) return false;
        return true;
    }
    
    bool
    BrokerTransportQualityOfService::operator!=(const BrokerTransportQualityOfService& value) const
    {
        return !this->operator==(value);
    }
    
    BrokerTransportQualityOfService&
    BrokerTransportQualityOfService::operator=(const BrokerTransportQualityOfService& value)
    {
        value_ = const_cast<BrokerTransportQualityOfService&>(value).value();
        return *this;
    }
    
    BrokerTransportQualityOfService&
    BrokerTransportQualityOfService::operator=(const Enum& value)
    {
        value_ = value;
        return *this;
    }
    
    void
    BrokerTransportQualityOfService::copyTo(BrokerTransportQualityOfService& value)
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
    BrokerTransportQualityOfService::factory(void)
    {
    	return constructSPtr<BrokerTransportQualityOfService>();
    }
    
    OpcUaNodeId
    BrokerTransportQualityOfService::binaryTypeId(void)
    {
    	return OpcUaNodeId(0, 0);
    }
    
    OpcUaNodeId
    BrokerTransportQualityOfService::xmlTypeId(void)
    {
    	return OpcUaNodeId(0, 0);
    }
    
    OpcUaNodeId
    BrokerTransportQualityOfService::jsonTypeId(void)
    {
    	return OpcUaNodeId(0, 0);
    }
    
    std::string
    BrokerTransportQualityOfService::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    BrokerTransportQualityOfService::typeName(void)
    {
    	return "BrokerTransportQualityOfService";
    }
    
    OpcUaNodeId
    BrokerTransportQualityOfService::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15008,0);
    }
    
    void
    BrokerTransportQualityOfService::opcUaBinaryEncode(std::ostream& os) const
    {
        OpcUaNumber::opcUaBinaryEncode(os, value_);
    }
    
    void
    BrokerTransportQualityOfService::opcUaBinaryDecode(std::istream& is)
    {
        OpcUaNumber::opcUaBinaryDecode(is, value_);
    }
    
    bool
    BrokerTransportQualityOfService::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        if(!XmlNumber::xmlEncode(pt, value_, element))
        {
    	     Log(Error, "BrokerTransportQualityOfService json encoder error")
    		     .parameter("Element", element);
            return false;
        }
        return true;
    }
    
    bool
    BrokerTransportQualityOfService::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        if(!XmlNumber::xmlEncode(pt, value_)) {
    	     Log(Error, "BrokerTransportQualityOfService json encoder error");
            return false;
        }
        return true;
    }
    
    bool
    BrokerTransportQualityOfService::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(element);
        if (!tree) {
    	     Log(Error, "BrokerTransportQualityOfService json decoder error")
    		     .parameter("Element", element);
            return false;
         }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    BrokerTransportQualityOfService::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        if(!XmlNumber::xmlDecode(pt, value_)) {
    	     Log(Error, "BrokerTransportQualityOfService json decoder error");
            return false;
        }
        return true;
    }
    
    bool
    BrokerTransportQualityOfService::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        if(!JsonNumber::jsonEncode(pt, value_))
        {
    	     Log(Error, "BrokerTransportQualityOfService json encoder error")
    		     .parameter("Element", "Value");
           return false;
        }
        return true;
    }
    
    bool
    BrokerTransportQualityOfService::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        if(!JsonNumber::jsonDecode(pt, value_)) {
            Log(Error, "BrokerTransportQualityOfService decode json error - decode failed");
            return false;
        }
        return true;
    }
    
    void
    BrokerTransportQualityOfService::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	BrokerTransportQualityOfService* dst = dynamic_cast<BrokerTransportQualityOfService*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    BrokerTransportQualityOfService::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	BrokerTransportQualityOfService* dst = dynamic_cast<BrokerTransportQualityOfService*>(&extensionObjectBase);
    	return *this == *dst;
    }
    
    void
    BrokerTransportQualityOfService::out(std::ostream& os)
    {
        os << "Value=" << value_;
    }

}
