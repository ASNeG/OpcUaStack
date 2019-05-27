/*
    EnumTypeClass: AxisScaleEnumeration

    Generated Source Code - please do not change this source code

    EnumTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/AxisScaleEnumeration.h"

namespace OpcUaStackCore
{
    
    AxisScaleEnumeration::AxisScaleEnumeration(void)
    : Object()
    , ExtensionObjectBase()
    , value_(0)
    {
    }
    
    AxisScaleEnumeration::AxisScaleEnumeration(Enum enumeration)
    : Object()
    , ExtensionObjectBase()
    , value_(enumeration)
    {
    }
    
    AxisScaleEnumeration::AxisScaleEnumeration(AxisScaleEnumeration& value)
    : Object()
    , ExtensionObjectBase()
    , value_(value.enumeration())
    {
    }
    
    AxisScaleEnumeration::~AxisScaleEnumeration(void)
    {
    }
    
    int32_t&
    AxisScaleEnumeration::value(void)
    {
        return value_;
    }
    
    void
    AxisScaleEnumeration::enumeration(AxisScaleEnumeration::Enum enumeration)
    {
        value_ = enumeration;
    }
    
    AxisScaleEnumeration::Enum
    AxisScaleEnumeration::enumeration(void)
    {
        return (Enum)value_;
    }
    
    AxisScaleEnumeration::Enum
    AxisScaleEnumeration::str2Enum(const std::string& enumerationString)
    {
        if (enumerationString == "Linear") return (Enum)0;
        if (enumerationString == "Log") return (Enum)1;
        if (enumerationString == "Ln") return (Enum)2;
        return (Enum)0;
    }
    
    std::string
    AxisScaleEnumeration::enum2Str(Enum enumeration)
    {
        if (enumeration == 0) return "Linear";
        if (enumeration == 1) return "Log";
        if (enumeration == 2) return "Ln";
        return "Unknown";
    }
    
    std::string
    AxisScaleEnumeration::enum2Str(void)
    {
        return enum2Str((Enum)value_);
    }
    
    std::string
    AxisScaleEnumeration::toString(void)
    {
        return enum2Str((Enum)value_);
    }
    
    bool
    AxisScaleEnumeration::exist(const std::string& enumerationString)
    {
        if (enumerationString == "Linear") return true;
        if (enumerationString == "Log") return true;
        if (enumerationString == "Ln") return true;
        return false;
    }
    
    bool
    AxisScaleEnumeration::exist(Enum enumeration)
    {
        if (enumeration == 0) return true;
        if (enumeration == 1) return true;
        if (enumeration == 2) return true;
        return false;
    }
    
    bool
    AxisScaleEnumeration::operator==(const AxisScaleEnumeration& value) const
    {
        if (value_ != value.value_) return false;
        return true;
    }
    
    bool
    AxisScaleEnumeration::operator!=(const AxisScaleEnumeration& value) const
    {
        return !this->operator==(value);
    }
    
    AxisScaleEnumeration&
    AxisScaleEnumeration::operator=(const AxisScaleEnumeration& value)
    {
        value_ = const_cast<AxisScaleEnumeration&>(value).value();
        return *this;
    }
    
    AxisScaleEnumeration&
    AxisScaleEnumeration::operator=(const Enum& value)
    {
        value_ = value;
        return *this;
    }
    
    void
    AxisScaleEnumeration::copyTo(AxisScaleEnumeration& value)
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
    AxisScaleEnumeration::factory(void)
    {
    	return constructSPtr<AxisScaleEnumeration>();
    }
    
    OpcUaNodeId
    AxisScaleEnumeration::binaryTypeId(void)
    {
    	return OpcUaNodeId(0, 0);
    }
    
    OpcUaNodeId
    AxisScaleEnumeration::xmlTypeId(void)
    {
    	return OpcUaNodeId(0, 0);
    }
    
    OpcUaNodeId
    AxisScaleEnumeration::jsonTypeId(void)
    {
    	return OpcUaNodeId(0, 0);
    }
    
    std::string
    AxisScaleEnumeration::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    AxisScaleEnumeration::typeName(void)
    {
    	return "AxisScaleEnumeration";
    }
    
    OpcUaNodeId
    AxisScaleEnumeration::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)12077,0);
    }
    
    void
    AxisScaleEnumeration::opcUaBinaryEncode(std::ostream& os) const
    {
        OpcUaNumber::opcUaBinaryEncode(os, value_);
    }
    
    void
    AxisScaleEnumeration::opcUaBinaryDecode(std::istream& is)
    {
        OpcUaNumber::opcUaBinaryDecode(is, value_);
    }
    
    bool
    AxisScaleEnumeration::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        if(!XmlNumber::xmlEncode(pt, value_, element))
        {
    	     Log(Error, "AxisScaleEnumeration json encoder error")
    		     .parameter("Element", element);
            return false;
        }
        return true;
    }
    
    bool
    AxisScaleEnumeration::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        if(!XmlNumber::xmlEncode(pt, value_)) {
    	     Log(Error, "AxisScaleEnumeration json encoder error");
            return false;
        }
        return true;
    }
    
    bool
    AxisScaleEnumeration::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(element);
        if (!tree) {
    	     Log(Error, "AxisScaleEnumeration json decoder error")
    		     .parameter("Element", element);
            return false;
         }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    AxisScaleEnumeration::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        if(!XmlNumber::xmlDecode(pt, value_)) {
    	     Log(Error, "AxisScaleEnumeration json decoder error");
            return false;
        }
        return true;
    }
    
    bool
    AxisScaleEnumeration::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        if(!JsonNumber::jsonEncode(pt, value_))
        {
    	     Log(Error, "AxisScaleEnumeration json encoder error")
    		     .parameter("Element", "Value");
           return false;
        }
        return true;
    }
    
    bool
    AxisScaleEnumeration::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        if(!JsonNumber::jsonDecode(pt, value_)) {
            Log(Error, "AxisScaleEnumeration decode json error - decode failed");
            return false;
        }
        return true;
    }
    
    void
    AxisScaleEnumeration::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	AxisScaleEnumeration* dst = dynamic_cast<AxisScaleEnumeration*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    AxisScaleEnumeration::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	AxisScaleEnumeration* dst = dynamic_cast<AxisScaleEnumeration*>(&extensionObjectBase);
    	return *this == *dst;
    }
    
    void
    AxisScaleEnumeration::out(std::ostream& os)
    {
        os << "Value=" << value_;
    }

}
