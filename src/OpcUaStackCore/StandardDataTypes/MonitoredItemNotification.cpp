/*
    DataTypeClass: MonitoredItemNotification

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/MonitoredItemNotification.h"

namespace OpcUaStackCore
{
    
    MonitoredItemNotification::MonitoredItemNotification(void)
    : Object()
    , ExtensionObjectBase()
    , clientHandle_()
    , value_()
    {
    }
    
    MonitoredItemNotification::MonitoredItemNotification(const MonitoredItemNotification& value)
    : Object()
    , ExtensionObjectBase()
    , clientHandle_()
    , value_()
    {
        const_cast<MonitoredItemNotification*>(&value)->copyTo(*this);
    }
    
    MonitoredItemNotification::~MonitoredItemNotification(void)
    {
    }
    
    OpcUaIntegerId&
    MonitoredItemNotification::clientHandle(void)
    {
        return clientHandle_;
    }
    
    OpcUaDataValue&
    MonitoredItemNotification::value(void)
    {
        return value_;
    }
    
    bool
    MonitoredItemNotification::operator==(const MonitoredItemNotification& value)
    {
        MonitoredItemNotification* dst = const_cast<MonitoredItemNotification*>(&value);
        if (clientHandle_ != dst->clientHandle()) return false;
        if (value_ != dst->value()) return false;
        return true;
    }
    
    bool
    MonitoredItemNotification::operator!=(const MonitoredItemNotification& value)
    {
        return !this->operator==(value);
    }
    
    void
    MonitoredItemNotification::copyTo(MonitoredItemNotification& value)
    {
        value.clientHandle_ = clientHandle_;
        value_.copyTo(value.value());
    }
    
    MonitoredItemNotification&
    MonitoredItemNotification::operator=(const MonitoredItemNotification& value)
    {
        const_cast<MonitoredItemNotification*>(&value)->copyTo(*this);
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
    MonitoredItemNotification::factory(void)
    {
    	return boost::make_shared<MonitoredItemNotification>();
    }
    
    std::string
    MonitoredItemNotification::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    MonitoredItemNotification::typeName(void)
    {
    	return "MonitoredItemNotification";
    }
    
    OpcUaNodeId
    MonitoredItemNotification::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)806,0);
    }
    
    OpcUaNodeId
    MonitoredItemNotification::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)808, 0);
    }
    
    OpcUaNodeId
    MonitoredItemNotification::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)807, 0);
    }
    
    OpcUaNodeId
    MonitoredItemNotification::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15346, 0);
    }
    
    bool
    MonitoredItemNotification::opcUaBinaryEncode(std::ostream& os) const
    {
        bool rc = true;
    
        rc &= OpcUaNumber::opcUaBinaryEncode(os,clientHandle_);
        rc &= value_.opcUaBinaryEncode(os);
        return rc;
    }
    
    bool
    MonitoredItemNotification::opcUaBinaryDecode(std::istream& is)
    {
        bool rc = true;
    
        rc &= OpcUaNumber::opcUaBinaryDecode(is,clientHandle_);
        rc &= value_.opcUaBinaryDecode(is);
        return rc;
    }
    
    bool
    MonitoredItemNotification::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "MonitoredItemNotification encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    MonitoredItemNotification::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, clientHandle_))
        {
            Log(Error, "MonitoredItemNotification encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("ClientHandle", elementTree));
    
        elementTree.clear();
        if (!value_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "MonitoredItemNotification encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("Value", elementTree));
    
        return true;
    }
    
    bool
    MonitoredItemNotification::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "MonitoredItemNotification decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    MonitoredItemNotification::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        elementName = xmlns.addPrefix("ClientHandle");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "MonitoredItemNotification decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, clientHandle_)) {
            Log(Error, "MonitoredItemNotification decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("Value");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "MonitoredItemNotification decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!value_.xmlDecode(*tree, xmlns)) {
            Log(Error, "MonitoredItemNotification decode xml error - decode failed")
                .parameter("Element", "Value");
            return false;
        }
    
        return true;
    }
    
    bool
    MonitoredItemNotification::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        bool rc = true;
    
        rc = rc & jsonNumberEncode(pt, clientHandle_, "ClientHandle");
        rc = rc & jsonObjectEncode(pt, value_, "Value", true);
    
        return rc;
    }
    
    bool
    MonitoredItemNotification::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        bool rc = true;
    
        rc = rc & jsonNumberDecode(pt, clientHandle_, "ClientHandle");
        rc = rc & jsonObjectDecode(pt, value_, "Value", true);
    
        return rc;
    }
    
    void
    MonitoredItemNotification::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	MonitoredItemNotification* dst = dynamic_cast<MonitoredItemNotification*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    MonitoredItemNotification::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	MonitoredItemNotification* dst = dynamic_cast<MonitoredItemNotification*>(&extensionObjectBase);
    	return *const_cast<MonitoredItemNotification*>(this) == *dst;
    }
    
    void
    MonitoredItemNotification::out(std::ostream& os)
    {
        os << "ClientHandle=" << clientHandle_;
        os << ", Value="; value_.out(os);
    }

}
