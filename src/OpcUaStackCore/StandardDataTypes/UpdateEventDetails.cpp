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
    
    UpdateEventDetails::UpdateEventDetails(const UpdateEventDetails& value)
    : HistoryUpdateDetails()
    , performInsertReplace_()
    , filter_()
    , eventData_()
    {
        const_cast<UpdateEventDetails*>(&value)->copyTo(*this);
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
    UpdateEventDetails::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "UpdateEventDetails encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    UpdateEventDetails::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!performInsertReplace_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "UpdateEventDetails encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("PerformInsertReplace", elementTree));
    
        elementTree.clear();
        if (!filter_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "UpdateEventDetails encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("Filter", elementTree));
    
        elementTree.clear();
        if (!eventData_.xmlEncode(elementTree, "HistoryEventFieldList", xmlns)) {
            Log(Error, "UpdateEventDetails encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("EventData", elementTree));
    
        return true;
    }
    
    bool
    UpdateEventDetails::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "UpdateEventDetails decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    UpdateEventDetails::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        elementName = xmlns.addPrefix("PerformInsertReplace");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "UpdateEventDetails decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!performInsertReplace_.xmlDecode(*tree, xmlns)) {
            Log(Error, "UpdateEventDetails decode xml error - decode failed")
                .parameter("Element", "PerformInsertReplace");
            return false;
        }
    
        elementName = xmlns.addPrefix("Filter");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "UpdateEventDetails decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!filter_.xmlDecode(*tree, xmlns)) {
            Log(Error, "UpdateEventDetails decode xml error - decode failed")
                .parameter("Element", "Filter");
            return false;
        }
    
        elementName = xmlns.addPrefix("EventData");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "UpdateEventDetails decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!eventData_.xmlDecode(*tree, "HistoryEventFieldList", xmlns)) {
            Log(Error, "UpdateEventDetails decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    bool
    UpdateEventDetails::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!performInsertReplace_.jsonEncode(elementTree))
        {
    	     Log(Error, "UpdateEventDetails json encoder error")
    		     .parameter("Element", "performInsertReplace_");
            return false;
        }
        pt.push_back(std::make_pair("PerformInsertReplace", elementTree));
    
        elementTree.clear();
        if (!filter_.jsonEncode(elementTree))
        {
    	     Log(Error, "UpdateEventDetails json encoder error")
    		     .parameter("Element", "filter_");
            return false;
        }
        pt.push_back(std::make_pair("Filter", elementTree));
    
        elementTree.clear();
        if (!eventData_.jsonEncode(elementTree, ""))
        {
    	     Log(Error, "UpdateEventDetails json encoder error")
    		     .parameter("Element", "eventData_");
            return false;
        }
        pt.push_back(std::make_pair("EventData", elementTree));
    
        return true;
    }
    
    bool
    UpdateEventDetails::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        std::string elementName;
        boost::optional<const boost::property_tree::ptree&> tree;
    
        elementName = "PerformInsertReplace";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "UpdateEventDetails decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!performInsertReplace_.jsonDecode(*tree)) {
            Log(Error, "UpdateEventDetails decode json error - decode failed")
                .parameter("Element", "PerformInsertReplace");
            return false;
        }
    
        elementName = "Filter";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "UpdateEventDetails decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!filter_.jsonDecode(*tree)) {
            Log(Error, "UpdateEventDetails decode json error - decode failed")
                .parameter("Element", "Filter");
            return false;
        }
    
        elementName = "EventData";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "UpdateEventDetails decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!eventData_.jsonDecode(*tree, "")) {
            Log(Error, "UpdateEventDetails decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
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
