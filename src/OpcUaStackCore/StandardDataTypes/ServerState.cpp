/*
    EnumTypeClass: ServerState

    Generated Source Code - please do not change this source code

    EnumTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/ServerState.h"

namespace OpcUaStackCore
{
    
    ServerState::ServerState(void)
    : Object()
    , ExtensionObjectBase()
    , value_(0)
    {
    }
    
    ServerState::ServerState(Enum enumeration)
    : Object()
    , ExtensionObjectBase()
    , value_(enumeration)
    {
    }
    
    ServerState::ServerState(ServerState& value)
    : Object()
    , ExtensionObjectBase()
    , value_(value.enumeration())
    {
    }
    
    ServerState::~ServerState(void)
    {
    }
    
    int32_t&
    ServerState::value(void)
    {
        return value_;
    }
    
    void
    ServerState::enumeration(ServerState::Enum enumeration)
    {
        value_ = enumeration;
    }
    
    ServerState::Enum
    ServerState::enumeration(void)
    {
        return (Enum)value_;
    }
    
    ServerState::Enum
    ServerState::str2Enum(const std::string& enumerationString)
    {
        if (enumerationString == "Running") return (Enum)0;
        if (enumerationString == "Failed") return (Enum)1;
        if (enumerationString == "NoConfiguration") return (Enum)2;
        if (enumerationString == "Suspended") return (Enum)3;
        if (enumerationString == "Shutdown") return (Enum)4;
        if (enumerationString == "Test") return (Enum)5;
        if (enumerationString == "CommunicationFault") return (Enum)6;
        if (enumerationString == "Unknown") return (Enum)7;
        return (Enum)0;
    }
    
    std::string
    ServerState::enum2Str(Enum enumeration)
    {
        if (enumeration == 0) return "Running";
        if (enumeration == 1) return "Failed";
        if (enumeration == 2) return "NoConfiguration";
        if (enumeration == 3) return "Suspended";
        if (enumeration == 4) return "Shutdown";
        if (enumeration == 5) return "Test";
        if (enumeration == 6) return "CommunicationFault";
        if (enumeration == 7) return "Unknown";
        return "Unknown";
    }
    
    std::string
    ServerState::enum2Str(void)
    {
        return enum2Str((Enum)value_);
    }
    
    std::string
    ServerState::toString(void)
    {
        return enum2Str((Enum)value_);
    }
    
    bool
    ServerState::exist(const std::string& enumerationString)
    {
        if (enumerationString == "Running") return true;
        if (enumerationString == "Failed") return true;
        if (enumerationString == "NoConfiguration") return true;
        if (enumerationString == "Suspended") return true;
        if (enumerationString == "Shutdown") return true;
        if (enumerationString == "Test") return true;
        if (enumerationString == "CommunicationFault") return true;
        if (enumerationString == "Unknown") return true;
        return false;
    }
    
    bool
    ServerState::exist(Enum enumeration)
    {
        if (enumeration == 0) return true;
        if (enumeration == 1) return true;
        if (enumeration == 2) return true;
        if (enumeration == 3) return true;
        if (enumeration == 4) return true;
        if (enumeration == 5) return true;
        if (enumeration == 6) return true;
        if (enumeration == 7) return true;
        return false;
    }
    
    bool
    ServerState::operator==(const ServerState& value) const
    {
        if (value_ != value.value_) return false;
        return true;
    }
    
    bool
    ServerState::operator!=(const ServerState& value) const
    {
        return !this->operator==(value);
    }
    
    ServerState&
    ServerState::operator=(const ServerState& value)
    {
        value_ = const_cast<ServerState&>(value).value();
        return *this;
    }
    
    ServerState&
    ServerState::operator=(const Enum& value)
    {
        value_ = value;
        return *this;
    }
    
    void
    ServerState::copyTo(ServerState& value)
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
    ServerState::factory(void)
    {
    	return constructSPtr<ServerState>();
    }
    
    OpcUaNodeId
    ServerState::binaryTypeId(void)
    {
    	return OpcUaNodeId(0, 0);
    }
    
    OpcUaNodeId
    ServerState::xmlTypeId(void)
    {
    	return OpcUaNodeId(0, 0);
    }
    
    OpcUaNodeId
    ServerState::jsonTypeId(void)
    {
    	return OpcUaNodeId(0, 0);
    }
    
    std::string
    ServerState::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    ServerState::typeName(void)
    {
    	return "ServerState";
    }
    
    OpcUaNodeId
    ServerState::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)852,0);
    }
    
    void
    ServerState::opcUaBinaryEncode(std::ostream& os) const
    {
        OpcUaNumber::opcUaBinaryEncode(os, value_);
    }
    
    void
    ServerState::opcUaBinaryDecode(std::istream& is)
    {
        OpcUaNumber::opcUaBinaryDecode(is, value_);
    }
    
    bool
    ServerState::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        if(!XmlNumber::xmlEncode(pt, value_, element))
        {
    	     Log(Error, "ServerState json encoder error")
    		     .parameter("Element", element);
            return false;
        }
        return true;
    }
    
    bool
    ServerState::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        if(!XmlNumber::xmlEncode(pt, value_)) {
    	     Log(Error, "ServerState json encoder error");
            return false;
        }
        return true;
    }
    
    bool
    ServerState::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(element);
        if (!tree) {
    	     Log(Error, "ServerState json decoder error")
    		     .parameter("Element", element);
            return false;
         }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    ServerState::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        if(!XmlNumber::xmlDecode(pt, value_)) {
    	     Log(Error, "ServerState json decoder error");
            return false;
        }
        return true;
    }
    
    bool
    ServerState::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        if(!JsonNumber::jsonEncode(pt, value_))
        {
    	     Log(Error, "ServerState json encoder error")
    		     .parameter("Element", "Value");
           return false;
        }
        return true;
    }
    
    bool
    ServerState::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        if(!JsonNumber::jsonDecode(pt, value_)) {
            Log(Error, "ServerState decode json error - decode failed");
            return false;
        }
        return true;
    }
    
    void
    ServerState::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	ServerState* dst = dynamic_cast<ServerState*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    ServerState::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	ServerState* dst = dynamic_cast<ServerState*>(&extensionObjectBase);
    	return *this == *dst;
    }
    
    void
    ServerState::out(std::ostream& os)
    {
        os << "Value=" << value_;
    }

}
