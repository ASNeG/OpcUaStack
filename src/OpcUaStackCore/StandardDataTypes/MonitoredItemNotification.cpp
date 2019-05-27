/*
    DataTypeClass: MonitoredItemNotification

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

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
    	return constructSPtr<MonitoredItemNotification>();
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
    
    void
    MonitoredItemNotification::opcUaBinaryEncode(std::ostream& os) const
    {
        OpcUaNumber::opcUaBinaryEncode(os,clientHandle_);
        value_.opcUaBinaryEncode(os);
    }
    
    void
    MonitoredItemNotification::opcUaBinaryDecode(std::istream& is)
    {
        OpcUaNumber::opcUaBinaryDecode(is,clientHandle_);
        value_.opcUaBinaryDecode(is);
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
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, clientHandle_))
        {
    	     Log(Error, "MonitoredItemNotification json encoder error")
    		     .parameter("Element", "clientHandle_");
           return false;
        }
        pt.push_back(std::make_pair("ClientHandle", elementTree));
    
        elementTree.clear();
        if (!value_.jsonEncode(elementTree))
        {
    	     Log(Error, "MonitoredItemNotification json encoder error")
    		     .parameter("Element", "value_");
            return false;
        }
        pt.push_back(std::make_pair("Value", elementTree));
    
        return true;
    }
    
    bool
    MonitoredItemNotification::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        std::string elementName;
        boost::optional<const boost::property_tree::ptree&> tree;
    
        elementName = "ClientHandle";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "MonitoredItemNotification decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, clientHandle_)) {
            Log(Error, "MonitoredItemNotification decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "Value";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "MonitoredItemNotification decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!value_.jsonDecode(*tree)) {
            Log(Error, "MonitoredItemNotification decode json error - decode failed")
                .parameter("Element", "Value");
            return false;
        }
    
        return true;
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
