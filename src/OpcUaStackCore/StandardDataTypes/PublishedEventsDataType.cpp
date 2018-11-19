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
        eventNotifier_.opcUaBinaryEncode(os);
        selectedFields_.opcUaBinaryEncode(os);
        filter_.opcUaBinaryEncode(os);
    }
    
    void
    PublishedEventsDataType::opcUaBinaryDecode(std::istream& is)
    {
        eventNotifier_.opcUaBinaryDecode(is);
        selectedFields_.opcUaBinaryDecode(is);
        filter_.opcUaBinaryDecode(is);
    }
    
    bool
    PublishedEventsDataType::encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const
    {
    }
    
    bool
    PublishedEventsDataType::decode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
    }
    
    bool
    PublishedEventsDataType::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    PublishedEventsDataType::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!eventNotifier_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("EventNotifier", elementTree));
    
        elementTree.clear();
        if (!selectedFields_.xmlEncode(elementTree, "SimpleAttributeOperand", xmlns)) return false;
        pt.push_back(std::make_pair("SelectedFields", elementTree));
    
        elementTree.clear();
        if (!filter_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("Filter", elementTree));
    
        return true;
    }
    
    bool
    PublishedEventsDataType::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(element);
        if (!tree) return false;
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    PublishedEventsDataType::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree;
    
        tree = pt.get_child_optional("EventNotifier");
        if (!tree) return false;
        if (!eventNotifier_.xmlDecode(*tree, xmlns)) return false;
    
        tree = pt.get_child_optional("SelectedFields");
        if (!tree) return false;
        if (!selectedFields_.xmlDecode(*tree, "SimpleAttributeOperand", xmlns)) return false;
    
        tree = pt.get_child_optional("Filter");
        if (!tree) return false;
        if (!filter_.xmlDecode(*tree, xmlns)) return false;
    
        return true;
    }
    
    bool
    PublishedEventsDataType::jsonEncode(boost::property_tree::ptree& pt, const std::string& element)
    {
        return true;
    }
    
    bool
    PublishedEventsDataType::jsonEncode(boost::property_tree::ptree& pt)
    {
        return true;
    }
    
    bool
    PublishedEventsDataType::jsonDecode(boost::property_tree::ptree& pt, const std::string& element)
    {
    }
    
    bool
    PublishedEventsDataType::jsonDecode(boost::property_tree::ptree& pt)
    {
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
