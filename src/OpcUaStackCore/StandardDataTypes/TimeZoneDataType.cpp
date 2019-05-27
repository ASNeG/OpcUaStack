/*
    DataTypeClass: TimeZoneDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/TimeZoneDataType.h"

namespace OpcUaStackCore
{
    
    TimeZoneDataType::TimeZoneDataType(void)
    : Object()
    , ExtensionObjectBase()
    , offset_()
    , daylightSavingInOffset_()
    {
    }
    
    TimeZoneDataType::TimeZoneDataType(const TimeZoneDataType& value)
    : Object()
    , ExtensionObjectBase()
    , offset_()
    , daylightSavingInOffset_()
    {
        const_cast<TimeZoneDataType*>(&value)->copyTo(*this);
    }
    
    TimeZoneDataType::~TimeZoneDataType(void)
    {
    }
    
    OpcUaInt16&
    TimeZoneDataType::offset(void)
    {
        return offset_;
    }
    
    OpcUaBoolean&
    TimeZoneDataType::daylightSavingInOffset(void)
    {
        return daylightSavingInOffset_;
    }
    
    bool
    TimeZoneDataType::operator==(const TimeZoneDataType& value)
    {
        TimeZoneDataType* dst = const_cast<TimeZoneDataType*>(&value);
        if (offset_ != dst->offset()) return false;
        if (daylightSavingInOffset_ != dst->daylightSavingInOffset()) return false;
        return true;
    }
    
    bool
    TimeZoneDataType::operator!=(const TimeZoneDataType& value)
    {
        return !this->operator==(value);
    }
    
    void
    TimeZoneDataType::copyTo(TimeZoneDataType& value)
    {
        value.offset_ = offset_;
        value.daylightSavingInOffset_ = daylightSavingInOffset_;
    }
    
    TimeZoneDataType&
    TimeZoneDataType::operator=(const TimeZoneDataType& value)
    {
        const_cast<TimeZoneDataType*>(&value)->copyTo(*this);
        return *this;
    }
    
    // ------------------------------------------------------------------------
    // ------------------------------------------------------------------------
    //
    // ExtensionObjectBase
    //
    // ------------------------------------------------------------------------
    // ------------------------------------------------------------------------
    
    ExtensionObjectBase::SPtr
    TimeZoneDataType::factory(void)
    {
    	return constructSPtr<TimeZoneDataType>();
    }
    
    std::string
    TimeZoneDataType::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    TimeZoneDataType::typeName(void)
    {
    	return "TimeZoneDataType";
    }
    
    OpcUaNodeId
    TimeZoneDataType::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)8912,0);
    }
    
    OpcUaNodeId
    TimeZoneDataType::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)8917, 0);
    }
    
    OpcUaNodeId
    TimeZoneDataType::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)8913, 0);
    }
    
    OpcUaNodeId
    TimeZoneDataType::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15086, 0);
    }
    
    void
    TimeZoneDataType::opcUaBinaryEncode(std::ostream& os) const
    {
        OpcUaNumber::opcUaBinaryEncode(os,offset_);
        OpcUaNumber::opcUaBinaryEncode(os,daylightSavingInOffset_);
    }
    
    void
    TimeZoneDataType::opcUaBinaryDecode(std::istream& is)
    {
        OpcUaNumber::opcUaBinaryDecode(is,offset_);
        OpcUaNumber::opcUaBinaryDecode(is,daylightSavingInOffset_);
    }
    
    bool
    TimeZoneDataType::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "TimeZoneDataType encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    TimeZoneDataType::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, offset_))
        {
            Log(Error, "TimeZoneDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("Offset", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, daylightSavingInOffset_))
        {
            Log(Error, "TimeZoneDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("DaylightSavingInOffset", elementTree));
    
        return true;
    }
    
    bool
    TimeZoneDataType::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "TimeZoneDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    TimeZoneDataType::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        elementName = xmlns.addPrefix("Offset");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "TimeZoneDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, offset_)) {
            Log(Error, "TimeZoneDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("DaylightSavingInOffset");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "TimeZoneDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, daylightSavingInOffset_)) {
            Log(Error, "TimeZoneDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    bool
    TimeZoneDataType::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, offset_))
        {
    	     Log(Error, "TimeZoneDataType json encoder error")
    		     .parameter("Element", "offset_");
           return false;
        }
        pt.push_back(std::make_pair("Offset", elementTree));
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, daylightSavingInOffset_))
        {
    	     Log(Error, "TimeZoneDataType json encoder error")
    		     .parameter("Element", "daylightSavingInOffset_");
           return false;
        }
        pt.push_back(std::make_pair("DaylightSavingInOffset", elementTree));
    
        return true;
    }
    
    bool
    TimeZoneDataType::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        std::string elementName;
        boost::optional<const boost::property_tree::ptree&> tree;
    
        elementName = "Offset";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "TimeZoneDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, offset_)) {
            Log(Error, "TimeZoneDataType decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "DaylightSavingInOffset";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "TimeZoneDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, daylightSavingInOffset_)) {
            Log(Error, "TimeZoneDataType decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    void
    TimeZoneDataType::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	TimeZoneDataType* dst = dynamic_cast<TimeZoneDataType*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    TimeZoneDataType::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	TimeZoneDataType* dst = dynamic_cast<TimeZoneDataType*>(&extensionObjectBase);
    	return *const_cast<TimeZoneDataType*>(this) == *dst;
    }
    
    void
    TimeZoneDataType::out(std::ostream& os)
    {
        os << "Offset=" << offset_;
        os << ", DaylightSavingInOffset=" << daylightSavingInOffset_;
    }

}
