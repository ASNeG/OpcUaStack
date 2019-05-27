/*
    DataTypeClass: DataChangeNotification

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/DataChangeNotification.h"

namespace OpcUaStackCore
{
    
    DataChangeNotification::DataChangeNotification(void)
    : NotificationData()
    , monitoredItems_()
    , diagnosticInfos_()
    {
    }
    
    DataChangeNotification::DataChangeNotification(const DataChangeNotification& value)
    : NotificationData()
    , monitoredItems_()
    , diagnosticInfos_()
    {
        const_cast<DataChangeNotification*>(&value)->copyTo(*this);
    }
    
    DataChangeNotification::~DataChangeNotification(void)
    {
    }
    
    MonitoredItemNotificationArray&
    DataChangeNotification::monitoredItems(void)
    {
        return monitoredItems_;
    }
    
    OpcUaDiagnosticInfoArray&
    DataChangeNotification::diagnosticInfos(void)
    {
        return diagnosticInfos_;
    }
    
    bool
    DataChangeNotification::operator==(const DataChangeNotification& value)
    {
        DataChangeNotification* dst = const_cast<DataChangeNotification*>(&value);
        if (monitoredItems_ != dst->monitoredItems()) return false;
        if (diagnosticInfos_ != dst->diagnosticInfos()) return false;
        return true;
    }
    
    bool
    DataChangeNotification::operator!=(const DataChangeNotification& value)
    {
        return !this->operator==(value);
    }
    
    void
    DataChangeNotification::copyTo(DataChangeNotification& value)
    {
        monitoredItems_.copyTo(value.monitoredItems());
        diagnosticInfos_.copyTo(value.diagnosticInfos());
    }
    
    DataChangeNotification&
    DataChangeNotification::operator=(const DataChangeNotification& value)
    {
        const_cast<DataChangeNotification*>(&value)->copyTo(*this);
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
    DataChangeNotification::factory(void)
    {
    	return constructSPtr<DataChangeNotification>();
    }
    
    std::string
    DataChangeNotification::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    DataChangeNotification::typeName(void)
    {
    	return "DataChangeNotification";
    }
    
    OpcUaNodeId
    DataChangeNotification::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)809,0);
    }
    
    OpcUaNodeId
    DataChangeNotification::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)811, 0);
    }
    
    OpcUaNodeId
    DataChangeNotification::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)810, 0);
    }
    
    OpcUaNodeId
    DataChangeNotification::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15345, 0);
    }
    
    void
    DataChangeNotification::opcUaBinaryEncode(std::ostream& os) const
    {
        NotificationData::opcUaBinaryEncode(os);
        monitoredItems_.opcUaBinaryEncode(os);
        diagnosticInfos_.opcUaBinaryEncode(os);
    }
    
    void
    DataChangeNotification::opcUaBinaryDecode(std::istream& is)
    {
        NotificationData::opcUaBinaryDecode(is);
        monitoredItems_.opcUaBinaryDecode(is);
        diagnosticInfos_.opcUaBinaryDecode(is);
    }
    
    bool
    DataChangeNotification::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "DataChangeNotification encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    DataChangeNotification::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!monitoredItems_.xmlEncode(elementTree, "MonitoredItemNotification", xmlns)) {
            Log(Error, "DataChangeNotification encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("MonitoredItems", elementTree));
    
        elementTree.clear();
        if (!diagnosticInfos_.xmlEncode(elementTree, "DiagnosticInfo", xmlns)) {
            Log(Error, "DataChangeNotification encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("DiagnosticInfos", elementTree));
    
        return true;
    }
    
    bool
    DataChangeNotification::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "DataChangeNotification decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    DataChangeNotification::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        elementName = xmlns.addPrefix("MonitoredItems");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "DataChangeNotification decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!monitoredItems_.xmlDecode(*tree, "MonitoredItemNotification", xmlns)) {
            Log(Error, "DataChangeNotification decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("DiagnosticInfos");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "DataChangeNotification decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!diagnosticInfos_.xmlDecode(*tree, "DiagnosticInfo", xmlns)) {
            Log(Error, "DataChangeNotification decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    bool
    DataChangeNotification::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!monitoredItems_.jsonEncode(elementTree, ""))
        {
    	     Log(Error, "DataChangeNotification json encoder error")
    		     .parameter("Element", "monitoredItems_");
            return false;
        }
        pt.push_back(std::make_pair("MonitoredItems", elementTree));
    
        elementTree.clear();
        if (!diagnosticInfos_.jsonEncode(elementTree, ""))
        {
    	     Log(Error, "DataChangeNotification json encoder error")
    		     .parameter("Element", "diagnosticInfos_");
            return false;
        }
        pt.push_back(std::make_pair("DiagnosticInfos", elementTree));
    
        return true;
    }
    
    bool
    DataChangeNotification::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        std::string elementName;
        boost::optional<const boost::property_tree::ptree&> tree;
    
        elementName = "MonitoredItems";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "DataChangeNotification decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!monitoredItems_.jsonDecode(*tree, "")) {
            Log(Error, "DataChangeNotification decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "DiagnosticInfos";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "DataChangeNotification decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!diagnosticInfos_.jsonDecode(*tree, "")) {
            Log(Error, "DataChangeNotification decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    void
    DataChangeNotification::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	DataChangeNotification* dst = dynamic_cast<DataChangeNotification*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    DataChangeNotification::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	DataChangeNotification* dst = dynamic_cast<DataChangeNotification*>(&extensionObjectBase);
    	return *const_cast<DataChangeNotification*>(this) == *dst;
    }
    
    void
    DataChangeNotification::out(std::ostream& os)
    {
        os << "MonitoredItems="; monitoredItems_.out(os);
        os << ", DiagnosticInfos="; diagnosticInfos_.out(os);
    }

}
