/*
    DataTypeClass: UpdateEventDetails

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/UpdateEventDetails.h"

namespace OpcUaStackCore
{
    
    UpdateEventDetails::UpdateEventDetails(void)
    : HistoryUpdateDetails()
    , performInsertReplace_()
    , filter_()
    , eventData_()
    {
    }
    
    UpdateEventDetails::~UpdateEventDetails(void)
    {
    }
    
    PerformUpdateType&
    UpdateEventDetails::performInsertReplace(void)
    {
        return performInsertReplace_;
    }
    
    EventFilter&
    UpdateEventDetails::filter(void)
    {
        return filter_;
    }
    
    HistoryEventFieldListArray&
    UpdateEventDetails::eventData(void)
    {
        return eventData_;
    }
    
    bool
    UpdateEventDetails::operator==(const UpdateEventDetails& value)
    {
        UpdateEventDetails* dst = const_cast<UpdateEventDetails*>(&value);
        if (performInsertReplace_ != dst->performInsertReplace()) return false;
        if (filter_ != dst->filter()) return false;
        if (eventData_ != dst->eventData()) return false;
        return true;
    }
    
    bool
    UpdateEventDetails::operator!=(const UpdateEventDetails& value)
    {
        return !this->operator==(value);
    }
    
    void
    UpdateEventDetails::copyTo(UpdateEventDetails& value)
    {
        performInsertReplace_.copyTo(value.performInsertReplace());
        filter_.copyTo(value.filter());
        eventData_.copyTo(value.eventData());
    }
    
    UpdateEventDetails&
    UpdateEventDetails::operator=(const UpdateEventDetails& value)
    {
        const_cast<UpdateEventDetails*>(&value)->copyTo(*this);
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
    UpdateEventDetails::factory(void)
    {
    	return constructSPtr<UpdateEventDetails>();
    }
    
    std::string
    UpdateEventDetails::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    UpdateEventDetails::typeName(void)
    {
    	return "UpdateEventDetails";
    }
    
    OpcUaNodeId
    UpdateEventDetails::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)683,0);
    }
    
    OpcUaNodeId
    UpdateEventDetails::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)685, 0);
    }
    
    OpcUaNodeId
    UpdateEventDetails::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)684, 0);
    }
    
    OpcUaNodeId
    UpdateEventDetails::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15282, 0);
    }
    
    void
    UpdateEventDetails::opcUaBinaryEncode(std::ostream& os) const
    {
        HistoryUpdateDetails::opcUaBinaryEncode(os);
        performInsertReplace_.opcUaBinaryEncode(os);
        filter_.opcUaBinaryEncode(os);
        eventData_.opcUaBinaryEncode(os);
    }
    
    void
    UpdateEventDetails::opcUaBinaryDecode(std::istream& is)
    {
        HistoryUpdateDetails::opcUaBinaryDecode(is);
        performInsertReplace_.opcUaBinaryDecode(is);
        filter_.opcUaBinaryDecode(is);
        eventData_.opcUaBinaryDecode(is);
    }
    
    bool
    UpdateEventDetails::encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const
    {
    }
    
    bool
    UpdateEventDetails::decode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
    }
    
    bool
    UpdateEventDetails::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    UpdateEventDetails::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!performInsertReplace_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("PerformInsertReplace", elementTree));
    
        elementTree.clear();
        if (!filter_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("Filter", elementTree));
    
        elementTree.clear();
        if (!eventData_.xmlEncode(elementTree, "HistoryEventFieldList", xmlns)) return false;
        pt.push_back(std::make_pair("EventData", elementTree));
    
        return true;
    }
    
    bool
    UpdateEventDetails::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(element);
        if (!tree) return false;
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    UpdateEventDetails::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree;
    
        tree = pt.get_child_optional("PerformInsertReplace");
        if (!tree) return false;
        if (!performInsertReplace_.xmlDecode(*tree, xmlns)) return false;
    
        tree = pt.get_child_optional("Filter");
        if (!tree) return false;
        if (!filter_.xmlDecode(*tree, xmlns)) return false;
    
        tree = pt.get_child_optional("EventData");
        if (!tree) return false;
        if (!eventData_.xmlDecode(*tree, "HistoryEventFieldList", xmlns)) return false;
    
        return true;
    }
    
    bool
    UpdateEventDetails::jsonEncode(boost::property_tree::ptree& pt, const std::string& element)
    {
        return true;
    }
    
    bool
    UpdateEventDetails::jsonEncode(boost::property_tree::ptree& pt)
    {
        return true;
    }
    
    bool
    UpdateEventDetails::jsonDecode(boost::property_tree::ptree& pt, const std::string& element)
    {
    }
    
    bool
    UpdateEventDetails::jsonDecode(boost::property_tree::ptree& pt)
    {
    }
    
    void
    UpdateEventDetails::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	UpdateEventDetails* dst = dynamic_cast<UpdateEventDetails*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    UpdateEventDetails::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	UpdateEventDetails* dst = dynamic_cast<UpdateEventDetails*>(&extensionObjectBase);
    	return *const_cast<UpdateEventDetails*>(this) == *dst;
    }
    
    void
    UpdateEventDetails::out(std::ostream& os)
    {
        os << "PerformInsertReplace="; performInsertReplace_.out(os);
        os << ", Filter="; filter_.out(os);
        os << ", EventData="; eventData_.out(os);
    }

}