/*
    DataTypeClass: EventFilter

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/EventFilter.h"

namespace OpcUaStackCore
{
    
    EventFilter::EventFilter(void)
    : MonitoringFilter()
    , selectClauses_()
    , whereClause_()
    {
    }
    
    EventFilter::EventFilter(const EventFilter& value)
    : MonitoringFilter()
    , selectClauses_()
    , whereClause_()
    {
        const_cast<EventFilter*>(&value)->copyTo(*this);
    }
    
    EventFilter::~EventFilter(void)
    {
    }
    
    SimpleAttributeOperandArray&
    EventFilter::selectClauses(void)
    {
        return selectClauses_;
    }
    
    ContentFilter&
    EventFilter::whereClause(void)
    {
        return whereClause_;
    }
    
    bool
    EventFilter::operator==(const EventFilter& value)
    {
        EventFilter* dst = const_cast<EventFilter*>(&value);
        if (selectClauses_ != dst->selectClauses()) return false;
        if (whereClause_ != dst->whereClause()) return false;
        return true;
    }
    
    bool
    EventFilter::operator!=(const EventFilter& value)
    {
        return !this->operator==(value);
    }
    
    void
    EventFilter::copyTo(EventFilter& value)
    {
        selectClauses_.copyTo(value.selectClauses());
        whereClause_.copyTo(value.whereClause());
    }
    
    EventFilter&
    EventFilter::operator=(const EventFilter& value)
    {
        const_cast<EventFilter*>(&value)->copyTo(*this);
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
    EventFilter::factory(void)
    {
    	return constructSPtr<EventFilter>();
    }
    
    std::string
    EventFilter::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    EventFilter::typeName(void)
    {
    	return "EventFilter";
    }
    
    OpcUaNodeId
    EventFilter::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)725,0);
    }
    
    OpcUaNodeId
    EventFilter::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)727, 0);
    }
    
    OpcUaNodeId
    EventFilter::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)726, 0);
    }
    
    OpcUaNodeId
    EventFilter::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15295, 0);
    }
    
    void
    EventFilter::opcUaBinaryEncode(std::ostream& os) const
    {
        MonitoringFilter::opcUaBinaryEncode(os);
        selectClauses_.opcUaBinaryEncode(os);
        whereClause_.opcUaBinaryEncode(os);
    }
    
    void
    EventFilter::opcUaBinaryDecode(std::istream& is)
    {
        MonitoringFilter::opcUaBinaryDecode(is);
        selectClauses_.opcUaBinaryDecode(is);
        whereClause_.opcUaBinaryDecode(is);
    }
    
    bool
    EventFilter::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "EventFilter encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    EventFilter::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!selectClauses_.xmlEncode(elementTree, "SimpleAttributeOperand", xmlns)) {
            Log(Error, "EventFilter encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("SelectClauses", elementTree));
    
        elementTree.clear();
        if (!whereClause_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "EventFilter encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("WhereClause", elementTree));
    
        return true;
    }
    
    bool
    EventFilter::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "EventFilter decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    EventFilter::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        elementName = xmlns.addPrefix("SelectClauses");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "EventFilter decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!selectClauses_.xmlDecode(*tree, "SimpleAttributeOperand", xmlns)) {
            Log(Error, "EventFilter decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("WhereClause");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "EventFilter decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!whereClause_.xmlDecode(*tree, xmlns)) {
            Log(Error, "EventFilter decode xml error - decode failed")
                .parameter("Element", "WhereClause");
            return false;
        }
    
        return true;
    }
    
    bool
    EventFilter::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!selectClauses_.jsonEncode(elementTree, ""))
        {
    	     Log(Error, "EventFilter json encoder error")
    		     .parameter("Element", "selectClauses_");
            return false;
        }
        pt.push_back(std::make_pair("SelectClauses", elementTree));
    
        elementTree.clear();
        if (!whereClause_.jsonEncode(elementTree))
        {
    	     Log(Error, "EventFilter json encoder error")
    		     .parameter("Element", "whereClause_");
            return false;
        }
        pt.push_back(std::make_pair("WhereClause", elementTree));
    
        return true;
    }
    
    bool
    EventFilter::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        std::string elementName;
        boost::optional<const boost::property_tree::ptree&> tree;
    
        elementName = "SelectClauses";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "EventFilter decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!selectClauses_.jsonDecode(*tree, "")) {
            Log(Error, "EventFilter decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "WhereClause";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "EventFilter decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!whereClause_.jsonDecode(*tree)) {
            Log(Error, "EventFilter decode json error - decode failed")
                .parameter("Element", "WhereClause");
            return false;
        }
    
        return true;
    }
    
    void
    EventFilter::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	EventFilter* dst = dynamic_cast<EventFilter*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    EventFilter::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	EventFilter* dst = dynamic_cast<EventFilter*>(&extensionObjectBase);
    	return *const_cast<EventFilter*>(this) == *dst;
    }
    
    void
    EventFilter::out(std::ostream& os)
    {
        os << "SelectClauses="; selectClauses_.out(os);
        os << ", WhereClause="; whereClause_.out(os);
    }

}
