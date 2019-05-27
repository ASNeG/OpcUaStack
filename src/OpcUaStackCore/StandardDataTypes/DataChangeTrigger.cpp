/*
    EnumTypeClass: DataChangeTrigger

    Generated Source Code - please do not change this source code

    EnumTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/DataChangeTrigger.h"

namespace OpcUaStackCore
{
    
    DataChangeTrigger::DataChangeTrigger(void)
    : Object()
    , ExtensionObjectBase()
    , value_(0)
    {
    }
    
    DataChangeTrigger::DataChangeTrigger(Enum enumeration)
    : Object()
    , ExtensionObjectBase()
    , value_(enumeration)
    {
    }
    
    DataChangeTrigger::DataChangeTrigger(DataChangeTrigger& value)
    : Object()
    , ExtensionObjectBase()
    , value_(value.enumeration())
    {
    }
    
    DataChangeTrigger::~DataChangeTrigger(void)
    {
    }
    
    int32_t&
    DataChangeTrigger::value(void)
    {
        return value_;
    }
    
    void
    DataChangeTrigger::enumeration(DataChangeTrigger::Enum enumeration)
    {
        value_ = enumeration;
    }
    
    DataChangeTrigger::Enum
    DataChangeTrigger::enumeration(void)
    {
        return (Enum)value_;
    }
    
    DataChangeTrigger::Enum
    DataChangeTrigger::str2Enum(const std::string& enumerationString)
    {
        if (enumerationString == "Status") return (Enum)0;
        if (enumerationString == "StatusValue") return (Enum)1;
        if (enumerationString == "StatusValueTimestamp") return (Enum)2;
        return (Enum)0;
    }
    
    std::string
    DataChangeTrigger::enum2Str(Enum enumeration)
    {
        if (enumeration == 0) return "Status";
        if (enumeration == 1) return "StatusValue";
        if (enumeration == 2) return "StatusValueTimestamp";
        return "Unknown";
    }
    
    std::string
    DataChangeTrigger::enum2Str(void)
    {
        return enum2Str((Enum)value_);
    }
    
    std::string
    DataChangeTrigger::toString(void)
    {
        return enum2Str((Enum)value_);
    }
    
    bool
    DataChangeTrigger::exist(const std::string& enumerationString)
    {
        if (enumerationString == "Status") return true;
        if (enumerationString == "StatusValue") return true;
        if (enumerationString == "StatusValueTimestamp") return true;
        return false;
    }
    
    bool
    DataChangeTrigger::exist(Enum enumeration)
    {
        if (enumeration == 0) return true;
        if (enumeration == 1) return true;
        if (enumeration == 2) return true;
        return false;
    }
    
    bool
    DataChangeTrigger::operator==(const DataChangeTrigger& value) const
    {
        if (value_ != value.value_) return false;
        return true;
    }
    
    bool
    DataChangeTrigger::operator!=(const DataChangeTrigger& value) const
    {
        return !this->operator==(value);
    }
    
    DataChangeTrigger&
    DataChangeTrigger::operator=(const DataChangeTrigger& value)
    {
        value_ = const_cast<DataChangeTrigger&>(value).value();
        return *this;
    }
    
    DataChangeTrigger&
    DataChangeTrigger::operator=(const Enum& value)
    {
        value_ = value;
        return *this;
    }
    
    void
    DataChangeTrigger::copyTo(DataChangeTrigger& value)
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
    DataChangeTrigger::factory(void)
    {
    	return constructSPtr<DataChangeTrigger>();
    }
    
    OpcUaNodeId
    DataChangeTrigger::binaryTypeId(void)
    {
    	return OpcUaNodeId(0, 0);
    }
    
    OpcUaNodeId
    DataChangeTrigger::xmlTypeId(void)
    {
    	return OpcUaNodeId(0, 0);
    }
    
    OpcUaNodeId
    DataChangeTrigger::jsonTypeId(void)
    {
    	return OpcUaNodeId(0, 0);
    }
    
    std::string
    DataChangeTrigger::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    DataChangeTrigger::typeName(void)
    {
    	return "DataChangeTrigger";
    }
    
    OpcUaNodeId
    DataChangeTrigger::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)717,0);
    }
    
    void
    DataChangeTrigger::opcUaBinaryEncode(std::ostream& os) const
    {
        OpcUaNumber::opcUaBinaryEncode(os, value_);
    }
    
    void
    DataChangeTrigger::opcUaBinaryDecode(std::istream& is)
    {
        OpcUaNumber::opcUaBinaryDecode(is, value_);
    }
    
    bool
    DataChangeTrigger::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        if(!XmlNumber::xmlEncode(pt, value_, element))
        {
    	     Log(Error, "DataChangeTrigger json encoder error")
    		     .parameter("Element", element);
            return false;
        }
        return true;
    }
    
    bool
    DataChangeTrigger::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        if(!XmlNumber::xmlEncode(pt, value_)) {
    	     Log(Error, "DataChangeTrigger json encoder error");
            return false;
        }
        return true;
    }
    
    bool
    DataChangeTrigger::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(element);
        if (!tree) {
    	     Log(Error, "DataChangeTrigger json decoder error")
    		     .parameter("Element", element);
            return false;
         }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    DataChangeTrigger::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        if(!XmlNumber::xmlDecode(pt, value_)) {
    	     Log(Error, "DataChangeTrigger json decoder error");
            return false;
        }
        return true;
    }
    
    bool
    DataChangeTrigger::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        if(!JsonNumber::jsonEncode(pt, value_))
        {
    	     Log(Error, "DataChangeTrigger json encoder error")
    		     .parameter("Element", "Value");
           return false;
        }
        return true;
    }
    
    bool
    DataChangeTrigger::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        if(!JsonNumber::jsonDecode(pt, value_)) {
            Log(Error, "DataChangeTrigger decode json error - decode failed");
            return false;
        }
        return true;
    }
    
    void
    DataChangeTrigger::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	DataChangeTrigger* dst = dynamic_cast<DataChangeTrigger*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    DataChangeTrigger::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	DataChangeTrigger* dst = dynamic_cast<DataChangeTrigger*>(&extensionObjectBase);
    	return *this == *dst;
    }
    
    void
    DataChangeTrigger::out(std::ostream& os)
    {
        os << "Value=" << value_;
    }

}
