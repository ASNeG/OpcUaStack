/*
    EnumTypeClass: SessionState

    Generated Source Code - please do not change this source code

    EnumTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/CustomerDataTypes/SessionState.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{
    
    SessionState::SessionState(void)
    : Object()
    , ExtensionObjectBase()
    , value_(0)
    {
    }
    
    SessionState::SessionState(Enum enumeration)
    : Object()
    , ExtensionObjectBase()
    , value_(enumeration)
    {
    }
    
    SessionState::SessionState(SessionState& value)
    : Object()
    , ExtensionObjectBase()
    , value_(value.enumeration())
    {
    }
    
    SessionState::~SessionState(void)
    {
    }
    
    int32_t&
    SessionState::value(void)
    {
        return value_;
    }
    
    void
    SessionState::enumeration(SessionState::Enum enumeration)
    {
        value_ = enumeration;
    }
    
    SessionState::Enum
    SessionState::enumeration(void)
    {
        return (Enum)value_;
    }
    
    SessionState::Enum
    SessionState::str2Enum(const std::string& enumerationString)
    {
        if (enumerationString == "Create") return (Enum)0;
        if (enumerationString == "Active") return (Enum)1;
        if (enumerationString == "Close") return (Enum)2;
        return (Enum)0;
    }
    
    std::string
    SessionState::enum2Str(Enum enumeration)
    {
        if (enumeration == 0) return "Create";
        if (enumeration == 1) return "Active";
        if (enumeration == 2) return "Close";
        return "Unknown";
    }
    
    std::string
    SessionState::enum2Str(void)
    {
        return enum2Str((Enum)value_);
    }
    
    std::string
    SessionState::toString(void)
    {
        return enum2Str((Enum)value_);
    }
    
    bool
    SessionState::exist(const std::string& enumerationString)
    {
        if (enumerationString == "Create") return true;
        if (enumerationString == "Active") return true;
        if (enumerationString == "Close") return true;
        return false;
    }
    
    bool
    SessionState::exist(Enum enumeration)
    {
        if (enumeration == 0) return true;
        if (enumeration == 1) return true;
        if (enumeration == 2) return true;
        return false;
    }
    
    bool
    SessionState::operator==(const SessionState& value) const
    {
        if (value_ != value.value_) return false;
        return true;
    }
    
    bool
    SessionState::operator!=(const SessionState& value) const
    {
        return !this->operator==(value);
    }
    
    SessionState&
    SessionState::operator=(const SessionState& value)
    {
        value_ = const_cast<SessionState&>(value).value();
        return *this;
    }
    
    SessionState&
    SessionState::operator=(const Enum& value)
    {
        value_ = value;
        return *this;
    }
    
    void
    SessionState::copyTo(SessionState& value)
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
    SessionState::factory(void)
    {
    	return boost::make_shared<SessionState>();
    }
    
    OpcUaNodeId
    SessionState::binaryTypeId(void)
    {
    	return OpcUaNodeId(0, 0);
    }
    
    OpcUaNodeId
    SessionState::xmlTypeId(void)
    {
    	return OpcUaNodeId(0, 0);
    }
    
    OpcUaNodeId
    SessionState::jsonTypeId(void)
    {
    	return OpcUaNodeId(0, 0);
    }
    
    std::string
    SessionState::namespaceName(void)
    {
    	return "OpcUaStackServer";
    }
    
    std::string
    SessionState::typeName(void)
    {
    	return "SessionState";
    }
    
    OpcUaNodeId
    SessionState::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)3002,1);
    }
    
    bool
    SessionState::opcUaBinaryEncode(std::ostream& os) const
    {
        return OpcUaNumber::opcUaBinaryEncode(os, value_);
    }
    
    bool
    SessionState::opcUaBinaryDecode(std::istream& is)
    {
        return OpcUaNumber::opcUaBinaryDecode(is, value_);
    }
    
    bool
    SessionState::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        if(!XmlNumber::xmlEncode(pt, value_, element))
        {
    	     Log(Error, "SessionState json encoder error")
    		     .parameter("Element", element);
            return false;
        }
        return true;
    }
    
    bool
    SessionState::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        if(!XmlNumber::xmlEncode(pt, value_)) {
    	     Log(Error, "SessionState json encoder error");
            return false;
        }
        return true;
    }
    
    bool
    SessionState::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(element);
        if (!tree) {
    	     Log(Error, "SessionState json decoder error")
    		     .parameter("Element", element);
            return false;
         }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    SessionState::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        if(!XmlNumber::xmlDecode(pt, value_)) {
    	     Log(Error, "SessionState json decoder error");
            return false;
        }
        return true;
    }
    
    bool
    SessionState::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        return jsonNumberEncode(pt, value_);
    }
    
    bool
    SessionState::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        return jsonNumberDecode(pt, value_);
    }
    
    void
    SessionState::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	SessionState* dst = dynamic_cast<SessionState*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    SessionState::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	SessionState* dst = dynamic_cast<SessionState*>(&extensionObjectBase);
    	return *this == *dst;
    }
    
    void
    SessionState::out(std::ostream& os)
    {
        os << "Value=" << value_;
    }

}
