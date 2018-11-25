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
    StatusChangeNotification::encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const
    {
    }
    
    bool
    StatusChangeNotification::decode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
    }
    
    bool
    StatusChangeNotification::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    StatusChangeNotification::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!status_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("Status", elementTree));
    
        elementTree.clear();
        if (!diagnosticInfo_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("DiagnosticInfo", elementTree));
    
        return true;
    }
    
    bool
    StatusChangeNotification::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(element);
        if (!tree) return false;
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    StatusChangeNotification::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree;
    
        tree = pt.get_child_optional("Status");
        if (!tree) return false;
        if (!status_.xmlDecode(*tree, xmlns)) return false;
    
        tree = pt.get_child_optional("DiagnosticInfo");
        if (!tree) return false;
        if (!diagnosticInfo_.xmlDecode(*tree, xmlns)) return false;
    
        return true;
    }
    
    bool
    StatusChangeNotification::jsonEncode(boost::property_tree::ptree& pt, const std::string& element)
    {
        return true;
    }
    
    bool
    StatusChangeNotification::jsonEncode(boost::property_tree::ptree& pt)
    {
        return true;
    }
    
    bool
    StatusChangeNotification::jsonDecode(boost::property_tree::ptree& pt, const std::string& element)
    {
    }
    
    bool
    StatusChangeNotification::jsonDecode(boost::property_tree::ptree& pt)
    {
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
