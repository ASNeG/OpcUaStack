/*
    EnumTypeClass: NodeAttributesMask

    Generated Source Code - please do not change this source code

    EnumTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/NodeAttributesMask.h"

namespace OpcUaStackCore
{
    
    NodeAttributesMask::NodeAttributesMask(void)
    : Object()
    , ExtensionObjectBase()
    , value_(0)
    {
    }
    
    NodeAttributesMask::NodeAttributesMask(Enum enumeration)
    : Object()
    , ExtensionObjectBase()
    , value_(enumeration)
    {
    }
    
    NodeAttributesMask::NodeAttributesMask(NodeAttributesMask& value)
    : Object()
    , ExtensionObjectBase()
    , value_(value.enumeration())
    {
    }
    
    NodeAttributesMask::~NodeAttributesMask(void)
    {
    }
    
    int32_t&
    NodeAttributesMask::value(void)
    {
        return value_;
    }
    
    void
    NodeAttributesMask::enumeration(NodeAttributesMask::Enum enumeration)
    {
        value_ = enumeration;
    }
    
    NodeAttributesMask::Enum
    NodeAttributesMask::enumeration(void)
    {
        return (Enum)value_;
    }
    
    NodeAttributesMask::Enum
    NodeAttributesMask::str2Enum(const std::string& enumerationString)
    {
        if (enumerationString == "None") return (Enum)0;
        if (enumerationString == "AccessLevel") return (Enum)1;
        if (enumerationString == "ArrayDimensions") return (Enum)2;
        if (enumerationString == "BrowseName") return (Enum)4;
        if (enumerationString == "ContainsNoLoops") return (Enum)8;
        if (enumerationString == "DataType") return (Enum)16;
        if (enumerationString == "Description") return (Enum)32;
        if (enumerationString == "DisplayName") return (Enum)64;
        if (enumerationString == "EventNotifier") return (Enum)128;
        if (enumerationString == "Executable") return (Enum)256;
        if (enumerationString == "Historizing") return (Enum)512;
        if (enumerationString == "InverseName") return (Enum)1024;
        if (enumerationString == "IsAbstract") return (Enum)2048;
        if (enumerationString == "MinimumSamplingInterval") return (Enum)4096;
        if (enumerationString == "NodeClass") return (Enum)8192;
        if (enumerationString == "NodeId") return (Enum)16384;
        if (enumerationString == "Symmetric") return (Enum)32768;
        if (enumerationString == "UserAccessLevel") return (Enum)65536;
        if (enumerationString == "UserExecutable") return (Enum)131072;
        if (enumerationString == "UserWriteMask") return (Enum)262144;
        if (enumerationString == "ValueRank") return (Enum)524288;
        if (enumerationString == "WriteMask") return (Enum)1048576;
        if (enumerationString == "Value") return (Enum)2097152;
        if (enumerationString == "DataTypeDefinition") return (Enum)4194304;
        if (enumerationString == "RolePermissions") return (Enum)8388608;
        if (enumerationString == "AccessRestrictions") return (Enum)16777216;
        if (enumerationString == "All") return (Enum)33554431;
        if (enumerationString == "BaseNode") return (Enum)26501220;
        if (enumerationString == "Object") return (Enum)26501348;
        if (enumerationString == "ObjectType") return (Enum)26503268;
        if (enumerationString == "Variable") return (Enum)26571383;
        if (enumerationString == "VariableType") return (Enum)28600438;
        if (enumerationString == "Method") return (Enum)26632548;
        if (enumerationString == "ReferenceType") return (Enum)26537060;
        if (enumerationString == "View") return (Enum)26501356;
        return (Enum)0;
    }
    
    std::string
    NodeAttributesMask::enum2Str(Enum enumeration)
    {
        if (enumeration == 0) return "None";
        if (enumeration == 1) return "AccessLevel";
        if (enumeration == 2) return "ArrayDimensions";
        if (enumeration == 4) return "BrowseName";
        if (enumeration == 8) return "ContainsNoLoops";
        if (enumeration == 16) return "DataType";
        if (enumeration == 32) return "Description";
        if (enumeration == 64) return "DisplayName";
        if (enumeration == 128) return "EventNotifier";
        if (enumeration == 256) return "Executable";
        if (enumeration == 512) return "Historizing";
        if (enumeration == 1024) return "InverseName";
        if (enumeration == 2048) return "IsAbstract";
        if (enumeration == 4096) return "MinimumSamplingInterval";
        if (enumeration == 8192) return "NodeClass";
        if (enumeration == 16384) return "NodeId";
        if (enumeration == 32768) return "Symmetric";
        if (enumeration == 65536) return "UserAccessLevel";
        if (enumeration == 131072) return "UserExecutable";
        if (enumeration == 262144) return "UserWriteMask";
        if (enumeration == 524288) return "ValueRank";
        if (enumeration == 1048576) return "WriteMask";
        if (enumeration == 2097152) return "Value";
        if (enumeration == 4194304) return "DataTypeDefinition";
        if (enumeration == 8388608) return "RolePermissions";
        if (enumeration == 16777216) return "AccessRestrictions";
        if (enumeration == 33554431) return "All";
        if (enumeration == 26501220) return "BaseNode";
        if (enumeration == 26501348) return "Object";
        if (enumeration == 26503268) return "ObjectType";
        if (enumeration == 26571383) return "Variable";
        if (enumeration == 28600438) return "VariableType";
        if (enumeration == 26632548) return "Method";
        if (enumeration == 26537060) return "ReferenceType";
        if (enumeration == 26501356) return "View";
        return "Unknown";
    }
    
    std::string
    NodeAttributesMask::enum2Str(void)
    {
        return enum2Str((Enum)value_);
    }
    
    std::string
    NodeAttributesMask::toString(void)
    {
        return enum2Str((Enum)value_);
    }
    
    bool
    NodeAttributesMask::exist(const std::string& enumerationString)
    {
        if (enumerationString == "None") return true;
        if (enumerationString == "AccessLevel") return true;
        if (enumerationString == "ArrayDimensions") return true;
        if (enumerationString == "BrowseName") return true;
        if (enumerationString == "ContainsNoLoops") return true;
        if (enumerationString == "DataType") return true;
        if (enumerationString == "Description") return true;
        if (enumerationString == "DisplayName") return true;
        if (enumerationString == "EventNotifier") return true;
        if (enumerationString == "Executable") return true;
        if (enumerationString == "Historizing") return true;
        if (enumerationString == "InverseName") return true;
        if (enumerationString == "IsAbstract") return true;
        if (enumerationString == "MinimumSamplingInterval") return true;
        if (enumerationString == "NodeClass") return true;
        if (enumerationString == "NodeId") return true;
        if (enumerationString == "Symmetric") return true;
        if (enumerationString == "UserAccessLevel") return true;
        if (enumerationString == "UserExecutable") return true;
        if (enumerationString == "UserWriteMask") return true;
        if (enumerationString == "ValueRank") return true;
        if (enumerationString == "WriteMask") return true;
        if (enumerationString == "Value") return true;
        if (enumerationString == "DataTypeDefinition") return true;
        if (enumerationString == "RolePermissions") return true;
        if (enumerationString == "AccessRestrictions") return true;
        if (enumerationString == "All") return true;
        if (enumerationString == "BaseNode") return true;
        if (enumerationString == "Object") return true;
        if (enumerationString == "ObjectType") return true;
        if (enumerationString == "Variable") return true;
        if (enumerationString == "VariableType") return true;
        if (enumerationString == "Method") return true;
        if (enumerationString == "ReferenceType") return true;
        if (enumerationString == "View") return true;
        return false;
    }
    
    bool
    NodeAttributesMask::exist(Enum enumeration)
    {
        if (enumeration == 0) return true;
        if (enumeration == 1) return true;
        if (enumeration == 2) return true;
        if (enumeration == 4) return true;
        if (enumeration == 8) return true;
        if (enumeration == 16) return true;
        if (enumeration == 32) return true;
        if (enumeration == 64) return true;
        if (enumeration == 128) return true;
        if (enumeration == 256) return true;
        if (enumeration == 512) return true;
        if (enumeration == 1024) return true;
        if (enumeration == 2048) return true;
        if (enumeration == 4096) return true;
        if (enumeration == 8192) return true;
        if (enumeration == 16384) return true;
        if (enumeration == 32768) return true;
        if (enumeration == 65536) return true;
        if (enumeration == 131072) return true;
        if (enumeration == 262144) return true;
        if (enumeration == 524288) return true;
        if (enumeration == 1048576) return true;
        if (enumeration == 2097152) return true;
        if (enumeration == 4194304) return true;
        if (enumeration == 8388608) return true;
        if (enumeration == 16777216) return true;
        if (enumeration == 33554431) return true;
        if (enumeration == 26501220) return true;
        if (enumeration == 26501348) return true;
        if (enumeration == 26503268) return true;
        if (enumeration == 26571383) return true;
        if (enumeration == 28600438) return true;
        if (enumeration == 26632548) return true;
        if (enumeration == 26537060) return true;
        if (enumeration == 26501356) return true;
        return false;
    }
    
    bool
    NodeAttributesMask::operator==(const NodeAttributesMask& value) const
    {
        if (value_ != value.value_) return false;
        return true;
    }
    
    bool
    NodeAttributesMask::operator!=(const NodeAttributesMask& value) const
    {
        return !this->operator==(value);
    }
    
    NodeAttributesMask&
    NodeAttributesMask::operator=(const NodeAttributesMask& value)
    {
        value_ = const_cast<NodeAttributesMask&>(value).value();
        return *this;
    }
    
    NodeAttributesMask&
    NodeAttributesMask::operator=(const Enum& value)
    {
        value_ = value;
        return *this;
    }
    
    void
    NodeAttributesMask::copyTo(NodeAttributesMask& value)
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
    NodeAttributesMask::factory(void)
    {
    	return constructSPtr<NodeAttributesMask>();
    }
    
    OpcUaNodeId
    NodeAttributesMask::binaryTypeId(void)
    {
    	return OpcUaNodeId(0, 0);
    }
    
    OpcUaNodeId
    NodeAttributesMask::xmlTypeId(void)
    {
    	return OpcUaNodeId(0, 0);
    }
    
    OpcUaNodeId
    NodeAttributesMask::jsonTypeId(void)
    {
    	return OpcUaNodeId(0, 0);
    }
    
    std::string
    NodeAttributesMask::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    NodeAttributesMask::typeName(void)
    {
    	return "NodeAttributesMask";
    }
    
    OpcUaNodeId
    NodeAttributesMask::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)348,0);
    }
    
    void
    NodeAttributesMask::opcUaBinaryEncode(std::ostream& os) const
    {
        OpcUaNumber::opcUaBinaryEncode(os, value_);
    }
    
    void
    NodeAttributesMask::opcUaBinaryDecode(std::istream& is)
    {
        OpcUaNumber::opcUaBinaryDecode(is, value_);
    }
    
    bool
    NodeAttributesMask::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        if(!XmlNumber::xmlEncode(pt, value_, element))
        {
    	     Log(Error, "NodeAttributesMask json encoder error")
    		     .parameter("Element", element);
            return false;
        }
        return true;
    }
    
    bool
    NodeAttributesMask::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        if(!XmlNumber::xmlEncode(pt, value_)) {
    	     Log(Error, "NodeAttributesMask json encoder error");
            return false;
        }
        return true;
    }
    
    bool
    NodeAttributesMask::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(element);
        if (!tree) {
    	     Log(Error, "NodeAttributesMask json decoder error")
    		     .parameter("Element", element);
            return false;
         }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    NodeAttributesMask::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        if(!XmlNumber::xmlDecode(pt, value_)) {
    	     Log(Error, "NodeAttributesMask json decoder error");
            return false;
        }
        return true;
    }
    
    bool
    NodeAttributesMask::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        if(!JsonNumber::jsonEncode(pt, value_))
        {
    	     Log(Error, "NodeAttributesMask json encoder error")
    		     .parameter("Element", "Value");
           return false;
        }
        return true;
    }
    
    bool
    NodeAttributesMask::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        if(!JsonNumber::jsonDecode(pt, value_)) {
            Log(Error, "NodeAttributesMask decode json error - decode failed");
            return false;
        }
        return true;
    }
    
    void
    NodeAttributesMask::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	NodeAttributesMask* dst = dynamic_cast<NodeAttributesMask*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    NodeAttributesMask::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	NodeAttributesMask* dst = dynamic_cast<NodeAttributesMask*>(&extensionObjectBase);
    	return *this == *dst;
    }
    
    void
    NodeAttributesMask::out(std::ostream& os)
    {
        os << "Value=" << value_;
    }

}
