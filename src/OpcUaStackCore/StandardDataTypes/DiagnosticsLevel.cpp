/*
    EnumTypeClass: DiagnosticsLevel

    Generated Source Code - please do not change this source code

    EnumTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/DiagnosticsLevel.h"

namespace OpcUaStackCore
{
    
    DiagnosticsLevel::DiagnosticsLevel(void)
    : Object()
    , ExtensionObjectBase()
    , value_(0)
    {
    }
    
    DiagnosticsLevel::DiagnosticsLevel(Enum enumeration)
    : Object()
    , ExtensionObjectBase()
    , value_(enumeration)
    {
    }
    
    DiagnosticsLevel::DiagnosticsLevel(DiagnosticsLevel& value)
    : Object()
    , ExtensionObjectBase()
    , value_(value.enumeration())
    {
    }
    
    DiagnosticsLevel::~DiagnosticsLevel(void)
    {
    }
    
    int32_t&
    DiagnosticsLevel::value(void)
    {
        return value_;
    }
    
    void
    DiagnosticsLevel::enumeration(DiagnosticsLevel::Enum enumeration)
    {
        value_ = enumeration;
    }
    
    DiagnosticsLevel::Enum
    DiagnosticsLevel::enumeration(void)
    {
        return (Enum)value_;
    }
    
    DiagnosticsLevel::Enum
    DiagnosticsLevel::str2Enum(const std::string& enumerationString)
    {
        if (enumerationString == "Basic") return (Enum)0;
        if (enumerationString == "Advanced") return (Enum)1;
        if (enumerationString == "Info") return (Enum)2;
        if (enumerationString == "Log") return (Enum)3;
        if (enumerationString == "Debug") return (Enum)4;
        return (Enum)0;
    }
    
    std::string
    DiagnosticsLevel::enum2Str(Enum enumeration)
    {
        if (enumeration == 0) return "Basic";
        if (enumeration == 1) return "Advanced";
        if (enumeration == 2) return "Info";
        if (enumeration == 3) return "Log";
        if (enumeration == 4) return "Debug";
        return "Unknown";
    }
    
    std::string
    DiagnosticsLevel::enum2Str(void)
    {
        return enum2Str((Enum)value_);
    }
    
    std::string
    DiagnosticsLevel::toString(void)
    {
        return enum2Str((Enum)value_);
    }
    
    bool
    DiagnosticsLevel::exist(const std::string& enumerationString)
    {
        if (enumerationString == "Basic") return true;
        if (enumerationString == "Advanced") return true;
        if (enumerationString == "Info") return true;
        if (enumerationString == "Log") return true;
        if (enumerationString == "Debug") return true;
        return false;
    }
    
    bool
    DiagnosticsLevel::exist(Enum enumeration)
    {
        if (enumeration == 0) return true;
        if (enumeration == 1) return true;
        if (enumeration == 2) return true;
        if (enumeration == 3) return true;
        if (enumeration == 4) return true;
        return false;
    }
    
    bool
    DiagnosticsLevel::operator==(const DiagnosticsLevel& value) const
    {
        if (value_ != value.value_) return false;
        return true;
    }
    
    bool
    DiagnosticsLevel::operator!=(const DiagnosticsLevel& value) const
    {
        return !this->operator==(value);
    }
    
    DiagnosticsLevel&
    DiagnosticsLevel::operator=(const DiagnosticsLevel& value)
    {
        value_ = const_cast<DiagnosticsLevel&>(value).value();
        return *this;
    }
    
    DiagnosticsLevel&
    DiagnosticsLevel::operator=(const Enum& value)
    {
        value_ = value;
        return *this;
    }
    
    void
    DiagnosticsLevel::copyTo(DiagnosticsLevel& value)
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
    DiagnosticsLevel::factory(void)
    {
    	return constructSPtr<DiagnosticsLevel>();
    }
    
    OpcUaNodeId
    DiagnosticsLevel::binaryTypeId(void)
    {
    	return OpcUaNodeId(0, 0);
    }
    
    OpcUaNodeId
    DiagnosticsLevel::xmlTypeId(void)
    {
    	return OpcUaNodeId(0, 0);
    }
    
    OpcUaNodeId
    DiagnosticsLevel::jsonTypeId(void)
    {
    	return OpcUaNodeId(0, 0);
    }
    
    std::string
    DiagnosticsLevel::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    DiagnosticsLevel::typeName(void)
    {
    	return "DiagnosticsLevel";
    }
    
    OpcUaNodeId
    DiagnosticsLevel::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)19723,0);
    }
    
    void
    DiagnosticsLevel::opcUaBinaryEncode(std::ostream& os) const
    {
        OpcUaNumber::opcUaBinaryEncode(os, value_);
    }
    
    void
    DiagnosticsLevel::opcUaBinaryDecode(std::istream& is)
    {
        OpcUaNumber::opcUaBinaryDecode(is, value_);
    }
    
    bool
    DiagnosticsLevel::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        if(!XmlNumber::xmlEncode(pt, value_, element))
        {
    	     Log(Error, "DiagnosticsLevel json encoder error")
    		     .parameter("Element", element);
            return false;
        }
        return true;
    }
    
    bool
    DiagnosticsLevel::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        if(!XmlNumber::xmlEncode(pt, value_)) {
    	     Log(Error, "DiagnosticsLevel json encoder error");
            return false;
        }
        return true;
    }
    
    bool
    DiagnosticsLevel::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(element);
        if (!tree) {
    	     Log(Error, "DiagnosticsLevel json decoder error")
    		     .parameter("Element", element);
            return false;
         }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    DiagnosticsLevel::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        if(!XmlNumber::xmlDecode(pt, value_)) {
    	     Log(Error, "DiagnosticsLevel json decoder error");
            return false;
        }
        return true;
    }
    
    bool
    DiagnosticsLevel::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        if(!JsonNumber::jsonEncode(pt, value_))
        {
    	     Log(Error, "DiagnosticsLevel json encoder error")
    		     .parameter("Element", "Value");
           return false;
        }
        return true;
    }
    
    bool
    DiagnosticsLevel::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        if(!JsonNumber::jsonDecode(pt, value_)) {
            Log(Error, "DiagnosticsLevel decode json error - decode failed");
            return false;
        }
        return true;
    }
    
    void
    DiagnosticsLevel::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	DiagnosticsLevel* dst = dynamic_cast<DiagnosticsLevel*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    DiagnosticsLevel::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	DiagnosticsLevel* dst = dynamic_cast<DiagnosticsLevel*>(&extensionObjectBase);
    	return *this == *dst;
    }
    
    void
    DiagnosticsLevel::out(std::ostream& os)
    {
        os << "Value=" << value_;
    }

}
