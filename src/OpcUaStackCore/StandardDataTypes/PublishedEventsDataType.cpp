/*
    DataTypeClass: PublishedEventsDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/PublishedEventsDataType.h"

namespace OpcUaStackCore
{
    
    PublishedEventsDataType::PublishedEventsDataType(void)
    : PublishedDataSetSourceDataType()
    , eventNotifier_()
    , selectedFields_()
    , filter_()
    {
    }
    
    PublishedEventsDataType::PublishedEventsDataType(const PublishedEventsDataType& value)
    : PublishedDataSetSourceDataType()
    , eventNotifier_()
    , selectedFields_()
    , filter_()
    {
        const_cast<PublishedEventsDataType*>(&value)->copyTo(*this);
    }
    
    PublishedEventsDataType::~PublishedEventsDataType(void)
    {
    }
    
    OpcUaNodeId&
    PublishedEventsDataType::eventNotifier(void)
    {
        return eventNotifier_;
    }
    
    SimpleAttributeOperandArray&
    PublishedEventsDataType::selectedFields(void)
    {
        return selectedFields_;
    }
    
    ContentFilter&
    PublishedEventsDataType::filter(void)
    {
        return filter_;
    }
    
    bool
    PublishedEventsDataType::operator==(const PublishedEventsDataType& value)
    {
        PublishedEventsDataType* dst = const_cast<PublishedEventsDataType*>(&value);
        if (eventNotifier_ != dst->eventNotifier()) return false;
        if (selectedFields_ != dst->selectedFields()) return false;
        if (filter_ != dst->filter()) return false;
        return true;
    }
    
    bool
    PublishedEventsDataType::operator!=(const PublishedEventsDataType& value)
    {
        return !this->operator==(value);
    }
    
    void
    PublishedEventsDataType::copyTo(PublishedEventsDataType& value)
    {
        eventNotifier_.copyTo(value.eventNotifier());
        selectedFields_.copyTo(value.selectedFields());
        filter_.copyTo(value.filter());
    }
    
    PublishedEventsDataType&
    PublishedEventsDataType::operator=(const PublishedEventsDataType& value)
    {
        const_cast<PublishedEventsDataType*>(&value)->copyTo(*this);
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
    PublishedEventsDataType::factory(void)
    {
    	return constructSPtr<PublishedEventsDataType>();
    }
    
    std::string
    PublishedEventsDataType::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    PublishedEventsDataType::typeName(void)
    {
    	return "PublishedEventsDataType";
    }
    
    OpcUaNodeId
    PublishedEventsDataType::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15582,0);
    }
    
    OpcUaNodeId
    PublishedEventsDataType::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15681, 0);
    }
    
    OpcUaNodeId
    PublishedEventsDataType::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15954, 0);
    }
    
    OpcUaNodeId
    PublishedEventsDataType::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)16155, 0);
    }
    
    void
    PublishedEventsDataType::opcUaBinaryEncode(std::ostream& os) const
    {
        PublishedDataSetSourceDataType::opcUaBinaryEncode(os);
        eventNotifier_.opcUaBinaryEncode(os);
        selectedFields_.opcUaBinaryEncode(os);
        filter_.opcUaBinaryEncode(os);
    }
    
    void
    PublishedEventsDataType::opcUaBinaryDecode(std::istream& is)
    {
        PublishedDataSetSourceDataType::opcUaBinaryDecode(is);
        eventNotifier_.opcUaBinaryDecode(is);
        selectedFields_.opcUaBinaryDecode(is);
        filter_.opcUaBinaryDecode(is);
    }
    
    bool
    PublishedEventsDataType::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "PublishedEventsDataType encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    PublishedEventsDataType::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!eventNotifier_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "PublishedEventsDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("EventNotifier", elementTree));
    
        elementTree.clear();
        if (!selectedFields_.xmlEncode(elementTree, "SimpleAttributeOperand", xmlns)) {
            Log(Error, "PublishedEventsDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("SelectedFields", elementTree));
    
        elementTree.clear();
        if (!filter_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "PublishedEventsDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("Filter", elementTree));
    
        return true;
    }
    
    bool
    PublishedEventsDataType::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "PublishedEventsDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    PublishedEventsDataType::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        elementName = xmlns.addPrefix("EventNotifier");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "PublishedEventsDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!eventNotifier_.xmlDecode(*tree, xmlns)) {
            Log(Error, "PublishedEventsDataType decode xml error - decode failed")
                .parameter("Element", "EventNotifier");
            return false;
        }
    
        elementName = xmlns.addPrefix("SelectedFields");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "PublishedEventsDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!selectedFields_.xmlDecode(*tree, "SimpleAttributeOperand", xmlns)) {
            Log(Error, "PublishedEventsDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("Filter");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "PublishedEventsDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!filter_.xmlDecode(*tree, xmlns)) {
            Log(Error, "PublishedEventsDataType decode xml error - decode failed")
                .parameter("Element", "Filter");
            return false;
        }
    
        return true;
    }
    
    bool
    PublishedEventsDataType::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!eventNotifier_.jsonEncode(elementTree))
        {
    	     Log(Error, "PublishedEventsDataType json encoder error")
    		     .parameter("Element", "eventNotifier_");
            return false;
        }
        pt.push_back(std::make_pair("EventNotifier", elementTree));
    
        elementTree.clear();
        if (!selectedFields_.jsonEncode(elementTree, ""))
        {
    	     Log(Error, "PublishedEventsDataType json encoder error")
    		     .parameter("Element", "selectedFields_");
            return false;
        }
        pt.push_back(std::make_pair("SelectedFields", elementTree));
    
        elementTree.clear();
        if (!filter_.jsonEncode(elementTree))
        {
    	     Log(Error, "PublishedEventsDataType json encoder error")
    		     .parameter("Element", "filter_");
            return false;
        }
        pt.push_back(std::make_pair("Filter", elementTree));
    
        return true;
    }
    
    bool
    PublishedEventsDataType::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        std::string elementName;
        boost::optional<const boost::property_tree::ptree&> tree;
    
        elementName = "EventNotifier";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "PublishedEventsDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!eventNotifier_.jsonDecode(*tree)) {
            Log(Error, "PublishedEventsDataType decode json error - decode failed")
                .parameter("Element", "EventNotifier");
            return false;
        }
    
        elementName = "SelectedFields";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "PublishedEventsDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!selectedFields_.jsonDecode(*tree, "")) {
            Log(Error, "PublishedEventsDataType decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "Filter";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "PublishedEventsDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!filter_.jsonDecode(*tree)) {
            Log(Error, "PublishedEventsDataType decode json error - decode failed")
                .parameter("Element", "Filter");
            return false;
        }
    
        return true;
    }
    
    void
    PublishedEventsDataType::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	PublishedEventsDataType* dst = dynamic_cast<PublishedEventsDataType*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    PublishedEventsDataType::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	PublishedEventsDataType* dst = dynamic_cast<PublishedEventsDataType*>(&extensionObjectBase);
    	return *const_cast<PublishedEventsDataType*>(this) == *dst;
    }
    
    void
    PublishedEventsDataType::out(std::ostream& os)
    {
        os << "EventNotifier="; eventNotifier_.out(os);
        os << ", SelectedFields="; selectedFields_.out(os);
        os << ", Filter="; filter_.out(os);
    }

}
