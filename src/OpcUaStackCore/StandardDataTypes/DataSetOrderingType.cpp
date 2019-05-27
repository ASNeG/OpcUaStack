/*
    EnumTypeClass: DataSetOrderingType

    Generated Source Code - please do not change this source code

    EnumTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/DataSetOrderingType.h"

namespace OpcUaStackCore
{
    
    DataSetOrderingType::DataSetOrderingType(void)
    : Object()
    , ExtensionObjectBase()
    , value_(0)
    {
    }
    
    DataSetOrderingType::DataSetOrderingType(Enum enumeration)
    : Object()
    , ExtensionObjectBase()
    , value_(enumeration)
    {
    }
    
    DataSetOrderingType::DataSetOrderingType(DataSetOrderingType& value)
    : Object()
    , ExtensionObjectBase()
    , value_(value.enumeration())
    {
    }
    
    DataSetOrderingType::~DataSetOrderingType(void)
    {
    }
    
    int32_t&
    DataSetOrderingType::value(void)
    {
        return value_;
    }
    
    void
    DataSetOrderingType::enumeration(DataSetOrderingType::Enum enumeration)
    {
        value_ = enumeration;
    }
    
    DataSetOrderingType::Enum
    DataSetOrderingType::enumeration(void)
    {
        return (Enum)value_;
    }
    
    DataSetOrderingType::Enum
    DataSetOrderingType::str2Enum(const std::string& enumerationString)
    {
        if (enumerationString == "Undefined") return (Enum)0;
        if (enumerationString == "AscendingWriterId") return (Enum)1;
        if (enumerationString == "AscendingWriterIdSingle") return (Enum)2;
        return (Enum)0;
    }
    
    std::string
    DataSetOrderingType::enum2Str(Enum enumeration)
    {
        if (enumeration == 0) return "Undefined";
        if (enumeration == 1) return "AscendingWriterId";
        if (enumeration == 2) return "AscendingWriterIdSingle";
        return "Unknown";
    }
    
    std::string
    DataSetOrderingType::enum2Str(void)
    {
        return enum2Str((Enum)value_);
    }
    
    std::string
    DataSetOrderingType::toString(void)
    {
        return enum2Str((Enum)value_);
    }
    
    bool
    DataSetOrderingType::exist(const std::string& enumerationString)
    {
        if (enumerationString == "Undefined") return true;
        if (enumerationString == "AscendingWriterId") return true;
        if (enumerationString == "AscendingWriterIdSingle") return true;
        return false;
    }
    
    bool
    DataSetOrderingType::exist(Enum enumeration)
    {
        if (enumeration == 0) return true;
        if (enumeration == 1) return true;
        if (enumeration == 2) return true;
        return false;
    }
    
    bool
    DataSetOrderingType::operator==(const DataSetOrderingType& value) const
    {
        if (value_ != value.value_) return false;
        return true;
    }
    
    bool
    DataSetOrderingType::operator!=(const DataSetOrderingType& value) const
    {
        return !this->operator==(value);
    }
    
    DataSetOrderingType&
    DataSetOrderingType::operator=(const DataSetOrderingType& value)
    {
        value_ = const_cast<DataSetOrderingType&>(value).value();
        return *this;
    }
    
    DataSetOrderingType&
    DataSetOrderingType::operator=(const Enum& value)
    {
        value_ = value;
        return *this;
    }
    
    void
    DataSetOrderingType::copyTo(DataSetOrderingType& value)
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
    DataSetOrderingType::factory(void)
    {
    	return constructSPtr<DataSetOrderingType>();
    }
    
    OpcUaNodeId
    DataSetOrderingType::binaryTypeId(void)
    {
    	return OpcUaNodeId(0, 0);
    }
    
    OpcUaNodeId
    DataSetOrderingType::xmlTypeId(void)
    {
    	return OpcUaNodeId(0, 0);
    }
    
    OpcUaNodeId
    DataSetOrderingType::jsonTypeId(void)
    {
    	return OpcUaNodeId(0, 0);
    }
    
    std::string
    DataSetOrderingType::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    DataSetOrderingType::typeName(void)
    {
    	return "DataSetOrderingType";
    }
    
    OpcUaNodeId
    DataSetOrderingType::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)20408,0);
    }
    
    void
    DataSetOrderingType::opcUaBinaryEncode(std::ostream& os) const
    {
        OpcUaNumber::opcUaBinaryEncode(os, value_);
    }
    
    void
    DataSetOrderingType::opcUaBinaryDecode(std::istream& is)
    {
        OpcUaNumber::opcUaBinaryDecode(is, value_);
    }
    
    bool
    DataSetOrderingType::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        if(!XmlNumber::xmlEncode(pt, value_, element))
        {
    	     Log(Error, "DataSetOrderingType json encoder error")
    		     .parameter("Element", element);
            return false;
        }
        return true;
    }
    
    bool
    DataSetOrderingType::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        if(!XmlNumber::xmlEncode(pt, value_)) {
    	     Log(Error, "DataSetOrderingType json encoder error");
            return false;
        }
        return true;
    }
    
    bool
    DataSetOrderingType::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(element);
        if (!tree) {
    	     Log(Error, "DataSetOrderingType json decoder error")
    		     .parameter("Element", element);
            return false;
         }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    DataSetOrderingType::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        if(!XmlNumber::xmlDecode(pt, value_)) {
    	     Log(Error, "DataSetOrderingType json decoder error");
            return false;
        }
        return true;
    }
    
    bool
    DataSetOrderingType::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        if(!JsonNumber::jsonEncode(pt, value_))
        {
    	     Log(Error, "DataSetOrderingType json encoder error")
    		     .parameter("Element", "Value");
           return false;
        }
        return true;
    }
    
    bool
    DataSetOrderingType::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        if(!JsonNumber::jsonDecode(pt, value_)) {
            Log(Error, "DataSetOrderingType decode json error - decode failed");
            return false;
        }
        return true;
    }
    
    void
    DataSetOrderingType::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	DataSetOrderingType* dst = dynamic_cast<DataSetOrderingType*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    DataSetOrderingType::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	DataSetOrderingType* dst = dynamic_cast<DataSetOrderingType*>(&extensionObjectBase);
    	return *this == *dst;
    }
    
    void
    DataSetOrderingType::out(std::ostream& os)
    {
        os << "Value=" << value_;
    }

}
