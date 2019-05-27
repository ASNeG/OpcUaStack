/*
    EnumTypeClass: NodeClass

    Generated Source Code - please do not change this source code

    EnumTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/NodeClass.h"

namespace OpcUaStackCore
{
    
    NodeClass::NodeClass(void)
    : Object()
    , ExtensionObjectBase()
    , value_(0)
    {
    }
    
    NodeClass::NodeClass(Enum enumeration)
    : Object()
    , ExtensionObjectBase()
    , value_(enumeration)
    {
    }
    
    NodeClass::NodeClass(NodeClass& value)
    : Object()
    , ExtensionObjectBase()
    , value_(value.enumeration())
    {
    }
    
    NodeClass::~NodeClass(void)
    {
    }
    
    int32_t&
    NodeClass::value(void)
    {
        return value_;
    }
    
    void
    NodeClass::enumeration(NodeClass::Enum enumeration)
    {
        value_ = enumeration;
    }
    
    NodeClass::Enum
    NodeClass::enumeration(void)
    {
        return (Enum)value_;
    }
    
    NodeClass::Enum
    NodeClass::str2Enum(const std::string& enumerationString)
    {
        if (enumerationString == "Unspecified") return (Enum)0;
        if (enumerationString == "Object") return (Enum)1;
        if (enumerationString == "Variable") return (Enum)2;
        if (enumerationString == "Method") return (Enum)4;
        if (enumerationString == "ObjectType") return (Enum)8;
        if (enumerationString == "VariableType") return (Enum)16;
        if (enumerationString == "ReferenceType") return (Enum)32;
        if (enumerationString == "DataType") return (Enum)64;
        if (enumerationString == "View") return (Enum)128;
        return (Enum)0;
    }
    
    std::string
    NodeClass::enum2Str(Enum enumeration)
    {
        if (enumeration == 0) return "Unspecified";
        if (enumeration == 1) return "Object";
        if (enumeration == 2) return "Variable";
        if (enumeration == 4) return "Method";
        if (enumeration == 8) return "ObjectType";
        if (enumeration == 16) return "VariableType";
        if (enumeration == 32) return "ReferenceType";
        if (enumeration == 64) return "DataType";
        if (enumeration == 128) return "View";
        return "Unknown";
    }
    
    std::string
    NodeClass::enum2Str(void)
    {
        return enum2Str((Enum)value_);
    }
    
    std::string
    NodeClass::toString(void)
    {
        return enum2Str((Enum)value_);
    }
    
    bool
    NodeClass::exist(const std::string& enumerationString)
    {
        if (enumerationString == "Unspecified") return true;
        if (enumerationString == "Object") return true;
        if (enumerationString == "Variable") return true;
        if (enumerationString == "Method") return true;
        if (enumerationString == "ObjectType") return true;
        if (enumerationString == "VariableType") return true;
        if (enumerationString == "ReferenceType") return true;
        if (enumerationString == "DataType") return true;
        if (enumerationString == "View") return true;
        return false;
    }
    
    bool
    NodeClass::exist(Enum enumeration)
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
        return false;
    }
    
    bool
    NodeClass::operator==(const NodeClass& value) const
    {
        if (value_ != value.value_) return false;
        return true;
    }
    
    bool
    NodeClass::operator!=(const NodeClass& value) const
    {
        return !this->operator==(value);
    }
    
    NodeClass&
    NodeClass::operator=(const NodeClass& value)
    {
        value_ = const_cast<NodeClass&>(value).value();
        return *this;
    }
    
    NodeClass&
    NodeClass::operator=(const Enum& value)
    {
        value_ = value;
        return *this;
    }
    
    void
    NodeClass::copyTo(NodeClass& value)
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
    NodeClass::factory(void)
    {
    	return constructSPtr<NodeClass>();
    }
    
    OpcUaNodeId
    NodeClass::binaryTypeId(void)
    {
    	return OpcUaNodeId(0, 0);
    }
    
    OpcUaNodeId
    NodeClass::xmlTypeId(void)
    {
    	return OpcUaNodeId(0, 0);
    }
    
    OpcUaNodeId
    NodeClass::jsonTypeId(void)
    {
    	return OpcUaNodeId(0, 0);
    }
    
    std::string
    NodeClass::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    NodeClass::typeName(void)
    {
    	return "NodeClass";
    }
    
    OpcUaNodeId
    NodeClass::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)257,0);
    }
    
    void
    NodeClass::opcUaBinaryEncode(std::ostream& os) const
    {
        OpcUaNumber::opcUaBinaryEncode(os, value_);
    }
    
    void
    NodeClass::opcUaBinaryDecode(std::istream& is)
    {
        OpcUaNumber::opcUaBinaryDecode(is, value_);
    }
    
    bool
    NodeClass::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        if(!XmlNumber::xmlEncode(pt, value_, element))
        {
    	     Log(Error, "NodeClass json encoder error")
    		     .parameter("Element", element);
            return false;
        }
        return true;
    }
    
    bool
    NodeClass::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        if(!XmlNumber::xmlEncode(pt, value_)) {
    	     Log(Error, "NodeClass json encoder error");
            return false;
        }
        return true;
    }
    
    bool
    NodeClass::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(element);
        if (!tree) {
    	     Log(Error, "NodeClass json decoder error")
    		     .parameter("Element", element);
            return false;
         }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    NodeClass::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        if(!XmlNumber::xmlDecode(pt, value_)) {
    	     Log(Error, "NodeClass json decoder error");
            return false;
        }
        return true;
    }
    
    bool
    NodeClass::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        if(!JsonNumber::jsonEncode(pt, value_))
        {
    	     Log(Error, "NodeClass json encoder error")
    		     .parameter("Element", "Value");
           return false;
        }
        return true;
    }
    
    bool
    NodeClass::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        if(!JsonNumber::jsonDecode(pt, value_)) {
            Log(Error, "NodeClass decode json error - decode failed");
            return false;
        }
        return true;
    }
    
    void
    NodeClass::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	NodeClass* dst = dynamic_cast<NodeClass*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    NodeClass::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	NodeClass* dst = dynamic_cast<NodeClass*>(&extensionObjectBase);
    	return *this == *dst;
    }
    
    void
    NodeClass::out(std::ostream& os)
    {
        os << "Value=" << value_;
    }

}
