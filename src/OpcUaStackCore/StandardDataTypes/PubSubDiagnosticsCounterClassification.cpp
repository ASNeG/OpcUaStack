/*
    EnumTypeClass: PubSubDiagnosticsCounterClassification

    Generated Source Code - please do not change this source code

    EnumTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

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
    
    PubSubDiagnosticsCounterClassification::PubSubDiagnosticsCounterClassification(PubSubDiagnosticsCounterClassification& value)
    : Object()
    , ExtensionObjectBase()
    , value_(value.enumeration())
    {
    }
    
    PubSubDiagnosticsCounterClassification::~PubSubDiagnosticsCounterClassification(void)
    {
    }
    
    int32_t&
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
    
    std::string
    PubSubDiagnosticsCounterClassification::enum2Str(void)
    {
        return enum2Str((Enum)value_);
    }
    
    std::string
    PubSubDiagnosticsCounterClassification::toString(void)
    {
        return enum2Str((Enum)value_);
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
    
    PubSubDiagnosticsCounterClassification&
    PubSubDiagnosticsCounterClassification::operator=(const PubSubDiagnosticsCounterClassification& value)
    {
        value_ = const_cast<PubSubDiagnosticsCounterClassification&>(value).value();
        return *this;
    }
    
    PubSubDiagnosticsCounterClassification&
    PubSubDiagnosticsCounterClassification::operator=(const Enum& value)
    {
        value_ = value;
        return *this;
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
    
    OpcUaNodeId
    PubSubDiagnosticsCounterClassification::jsonTypeId(void)
    {
    	return OpcUaNodeId(0, 0);
    }
    
    std::string
    PubSubDiagnosticsCounterClassification::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    PubSubDiagnosticsCounterClassification::typeName(void)
    {
    	return "PubSubDiagnosticsCounterClassification";
    }
    
    OpcUaNodeId
    PubSubDiagnosticsCounterClassification::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)19730,0);
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
    PubSubDiagnosticsCounterClassification::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        if(!XmlNumber::xmlEncode(pt, value_, element))
        {
    	     Log(Error, "PubSubDiagnosticsCounterClassification json encoder error")
    		     .parameter("Element", element);
            return false;
        }
        return true;
    }
    
    bool
    PubSubDiagnosticsCounterClassification::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        if(!XmlNumber::xmlEncode(pt, value_)) {
    	     Log(Error, "PubSubDiagnosticsCounterClassification json encoder error");
            return false;
        }
        return true;
    }
    
    bool
    PubSubDiagnosticsCounterClassification::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(element);
        if (!tree) {
    	     Log(Error, "PubSubDiagnosticsCounterClassification json decoder error")
    		     .parameter("Element", element);
            return false;
         }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    PubSubDiagnosticsCounterClassification::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        if(!XmlNumber::xmlDecode(pt, value_)) {
    	     Log(Error, "PubSubDiagnosticsCounterClassification json decoder error");
            return false;
        }
        return true;
    }
    
    bool
    PubSubDiagnosticsCounterClassification::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        if(!JsonNumber::jsonEncode(pt, value_))
        {
    	     Log(Error, "PubSubDiagnosticsCounterClassification json encoder error")
    		     .parameter("Element", "Value");
           return false;
        }
        return true;
    }
    
    bool
    PubSubDiagnosticsCounterClassification::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        if(!JsonNumber::jsonDecode(pt, value_)) {
            Log(Error, "PubSubDiagnosticsCounterClassification decode json error - decode failed");
            return false;
        }
        return true;
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
