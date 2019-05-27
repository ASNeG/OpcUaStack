/*
    EnumTypeClass: PubSubState

    Generated Source Code - please do not change this source code

    EnumTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/PubSubState.h"

namespace OpcUaStackCore
{
    
    PubSubState::PubSubState(void)
    : Object()
    , ExtensionObjectBase()
    , value_(0)
    {
    }
    
    PubSubState::PubSubState(Enum enumeration)
    : Object()
    , ExtensionObjectBase()
    , value_(enumeration)
    {
    }
    
    PubSubState::PubSubState(PubSubState& value)
    : Object()
    , ExtensionObjectBase()
    , value_(value.enumeration())
    {
    }
    
    PubSubState::~PubSubState(void)
    {
    }
    
    int32_t&
    PubSubState::value(void)
    {
        return value_;
    }
    
    void
    PubSubState::enumeration(PubSubState::Enum enumeration)
    {
        value_ = enumeration;
    }
    
    PubSubState::Enum
    PubSubState::enumeration(void)
    {
        return (Enum)value_;
    }
    
    PubSubState::Enum
    PubSubState::str2Enum(const std::string& enumerationString)
    {
        if (enumerationString == "Disabled") return (Enum)0;
        if (enumerationString == "Paused") return (Enum)1;
        if (enumerationString == "Operational") return (Enum)2;
        if (enumerationString == "Error") return (Enum)3;
        return (Enum)0;
    }
    
    std::string
    PubSubState::enum2Str(Enum enumeration)
    {
        if (enumeration == 0) return "Disabled";
        if (enumeration == 1) return "Paused";
        if (enumeration == 2) return "Operational";
        if (enumeration == 3) return "Error";
        return "Unknown";
    }
    
    std::string
    PubSubState::enum2Str(void)
    {
        return enum2Str((Enum)value_);
    }
    
    std::string
    PubSubState::toString(void)
    {
        return enum2Str((Enum)value_);
    }
    
    bool
    PubSubState::exist(const std::string& enumerationString)
    {
        if (enumerationString == "Disabled") return true;
        if (enumerationString == "Paused") return true;
        if (enumerationString == "Operational") return true;
        if (enumerationString == "Error") return true;
        return false;
    }
    
    bool
    PubSubState::exist(Enum enumeration)
    {
        if (enumeration == 0) return true;
        if (enumeration == 1) return true;
        if (enumeration == 2) return true;
        if (enumeration == 3) return true;
        return false;
    }
    
    bool
    PubSubState::operator==(const PubSubState& value) const
    {
        if (value_ != value.value_) return false;
        return true;
    }
    
    bool
    PubSubState::operator!=(const PubSubState& value) const
    {
        return !this->operator==(value);
    }
    
    PubSubState&
    PubSubState::operator=(const PubSubState& value)
    {
        value_ = const_cast<PubSubState&>(value).value();
        return *this;
    }
    
    PubSubState&
    PubSubState::operator=(const Enum& value)
    {
        value_ = value;
        return *this;
    }
    
    void
    PubSubState::copyTo(PubSubState& value)
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
    PubSubState::factory(void)
    {
    	return constructSPtr<PubSubState>();
    }
    
    OpcUaNodeId
    PubSubState::binaryTypeId(void)
    {
    	return OpcUaNodeId(0, 0);
    }
    
    OpcUaNodeId
    PubSubState::xmlTypeId(void)
    {
    	return OpcUaNodeId(0, 0);
    }
    
    OpcUaNodeId
    PubSubState::jsonTypeId(void)
    {
    	return OpcUaNodeId(0, 0);
    }
    
    std::string
    PubSubState::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    PubSubState::typeName(void)
    {
    	return "PubSubState";
    }
    
    OpcUaNodeId
    PubSubState::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)14647,0);
    }
    
    void
    PubSubState::opcUaBinaryEncode(std::ostream& os) const
    {
        OpcUaNumber::opcUaBinaryEncode(os, value_);
    }
    
    void
    PubSubState::opcUaBinaryDecode(std::istream& is)
    {
        OpcUaNumber::opcUaBinaryDecode(is, value_);
    }
    
    bool
    PubSubState::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        if(!XmlNumber::xmlEncode(pt, value_, element))
        {
    	     Log(Error, "PubSubState json encoder error")
    		     .parameter("Element", element);
            return false;
        }
        return true;
    }
    
    bool
    PubSubState::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        if(!XmlNumber::xmlEncode(pt, value_)) {
    	     Log(Error, "PubSubState json encoder error");
            return false;
        }
        return true;
    }
    
    bool
    PubSubState::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(element);
        if (!tree) {
    	     Log(Error, "PubSubState json decoder error")
    		     .parameter("Element", element);
            return false;
         }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    PubSubState::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        if(!XmlNumber::xmlDecode(pt, value_)) {
    	     Log(Error, "PubSubState json decoder error");
            return false;
        }
        return true;
    }
    
    bool
    PubSubState::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        if(!JsonNumber::jsonEncode(pt, value_))
        {
    	     Log(Error, "PubSubState json encoder error")
    		     .parameter("Element", "Value");
           return false;
        }
        return true;
    }
    
    bool
    PubSubState::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        if(!JsonNumber::jsonDecode(pt, value_)) {
            Log(Error, "PubSubState decode json error - decode failed");
            return false;
        }
        return true;
    }
    
    void
    PubSubState::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	PubSubState* dst = dynamic_cast<PubSubState*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    PubSubState::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	PubSubState* dst = dynamic_cast<PubSubState*>(&extensionObjectBase);
    	return *this == *dst;
    }
    
    void
    PubSubState::out(std::ostream& os)
    {
        os << "Value=" << value_;
    }

}
