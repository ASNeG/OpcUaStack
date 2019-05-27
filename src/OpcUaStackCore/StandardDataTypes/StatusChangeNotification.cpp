/*
    DataTypeClass: StatusChangeNotification

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/StatusChangeNotification.h"

namespace OpcUaStackCore
{
    
    StatusChangeNotification::StatusChangeNotification(void)
    : NotificationData()
    , status_()
    , diagnosticInfo_()
    {
    }
    
    StatusChangeNotification::StatusChangeNotification(const StatusChangeNotification& value)
    : NotificationData()
    , status_()
    , diagnosticInfo_()
    {
        const_cast<StatusChangeNotification*>(&value)->copyTo(*this);
    }
    
    StatusChangeNotification::~StatusChangeNotification(void)
    {
    }
    
    OpcUaStatus&
    StatusChangeNotification::status(void)
    {
        return status_;
    }
    
    OpcUaDiagnosticInfo&
    StatusChangeNotification::diagnosticInfo(void)
    {
        return diagnosticInfo_;
    }
    
    bool
    StatusChangeNotification::operator==(const StatusChangeNotification& value)
    {
        StatusChangeNotification* dst = const_cast<StatusChangeNotification*>(&value);
        if (status_ != dst->status()) return false;
        if (diagnosticInfo_ != dst->diagnosticInfo()) return false;
        return true;
    }
    
    bool
    StatusChangeNotification::operator!=(const StatusChangeNotification& value)
    {
        return !this->operator==(value);
    }
    
    void
    StatusChangeNotification::copyTo(StatusChangeNotification& value)
    {
        status_.copyTo(value.status());
        diagnosticInfo_.copyTo(value.diagnosticInfo());
    }
    
    StatusChangeNotification&
    StatusChangeNotification::operator=(const StatusChangeNotification& value)
    {
        const_cast<StatusChangeNotification*>(&value)->copyTo(*this);
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
    StatusChangeNotification::factory(void)
    {
    	return constructSPtr<StatusChangeNotification>();
    }
    
    std::string
    StatusChangeNotification::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    StatusChangeNotification::typeName(void)
    {
    	return "StatusChangeNotification";
    }
    
    OpcUaNodeId
    StatusChangeNotification::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)818,0);
    }
    
    OpcUaNodeId
    StatusChangeNotification::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)820, 0);
    }
    
    OpcUaNodeId
    StatusChangeNotification::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)819, 0);
    }
    
    OpcUaNodeId
    StatusChangeNotification::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15350, 0);
    }
    
    void
    StatusChangeNotification::opcUaBinaryEncode(std::ostream& os) const
    {
        NotificationData::opcUaBinaryEncode(os);
        status_.opcUaBinaryEncode(os);
        diagnosticInfo_.opcUaBinaryEncode(os);
    }
    
    void
    StatusChangeNotification::opcUaBinaryDecode(std::istream& is)
    {
        NotificationData::opcUaBinaryDecode(is);
        status_.opcUaBinaryDecode(is);
        diagnosticInfo_.opcUaBinaryDecode(is);
    }
    
    bool
    StatusChangeNotification::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "StatusChangeNotification encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    StatusChangeNotification::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!status_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "StatusChangeNotification encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("Status", elementTree));
    
        elementTree.clear();
        if (!diagnosticInfo_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "StatusChangeNotification encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("DiagnosticInfo", elementTree));
    
        return true;
    }
    
    bool
    StatusChangeNotification::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "StatusChangeNotification decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    StatusChangeNotification::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        elementName = xmlns.addPrefix("Status");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "StatusChangeNotification decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!status_.xmlDecode(*tree, xmlns)) {
            Log(Error, "StatusChangeNotification decode xml error - decode failed")
                .parameter("Element", "Status");
            return false;
        }
    
        elementName = xmlns.addPrefix("DiagnosticInfo");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "StatusChangeNotification decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!diagnosticInfo_.xmlDecode(*tree, xmlns)) {
            Log(Error, "StatusChangeNotification decode xml error - decode failed")
                .parameter("Element", "DiagnosticInfo");
            return false;
        }
    
        return true;
    }
    
    bool
    StatusChangeNotification::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!status_.jsonEncode(elementTree))
        {
    	     Log(Error, "StatusChangeNotification json encoder error")
    		     .parameter("Element", "status_");
            return false;
        }
        pt.push_back(std::make_pair("Status", elementTree));
    
        elementTree.clear();
        if (!diagnosticInfo_.jsonEncode(elementTree))
        {
    	     Log(Error, "StatusChangeNotification json encoder error")
    		     .parameter("Element", "diagnosticInfo_");
            return false;
        }
        pt.push_back(std::make_pair("DiagnosticInfo", elementTree));
    
        return true;
    }
    
    bool
    StatusChangeNotification::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        std::string elementName;
        boost::optional<const boost::property_tree::ptree&> tree;
    
        elementName = "Status";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "StatusChangeNotification decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!status_.jsonDecode(*tree)) {
            Log(Error, "StatusChangeNotification decode json error - decode failed")
                .parameter("Element", "Status");
            return false;
        }
    
        elementName = "DiagnosticInfo";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "StatusChangeNotification decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!diagnosticInfo_.jsonDecode(*tree)) {
            Log(Error, "StatusChangeNotification decode json error - decode failed")
                .parameter("Element", "DiagnosticInfo");
            return false;
        }
    
        return true;
    }
    
    void
    StatusChangeNotification::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	StatusChangeNotification* dst = dynamic_cast<StatusChangeNotification*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    StatusChangeNotification::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	StatusChangeNotification* dst = dynamic_cast<StatusChangeNotification*>(&extensionObjectBase);
    	return *const_cast<StatusChangeNotification*>(this) == *dst;
    }
    
    void
    StatusChangeNotification::out(std::ostream& os)
    {
        os << "Status="; status_.out(os);
        os << ", DiagnosticInfo="; diagnosticInfo_.out(os);
    }

}
