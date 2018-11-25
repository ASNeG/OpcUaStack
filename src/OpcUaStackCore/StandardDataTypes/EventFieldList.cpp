/*
    DataTypeClass: EventFieldList

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/EventFieldList.h"

namespace OpcUaStackCore
{
    
    EventFieldList::EventFieldList(void)
    : Object()
    , ExtensionObjectBase()
    , clientHandle_()
    , eventFields_()
    {
    }
    
    EventFieldList::~EventFieldList(void)
    {
    }
    
    OpcUaIntegerId&
    EventFieldList::clientHandle(void)
    {
        return clientHandle_;
    }
    
    OpcUaVariantArray&
    EventFieldList::eventFields(void)
    {
        return eventFields_;
    }
    
    bool
    EventFieldList::operator==(const EventFieldList& value)
    {
        EventFieldList* dst = const_cast<EventFieldList*>(&value);
        if (clientHandle_ != dst->clientHandle()) return false;
        if (eventFields_ != dst->eventFields()) return false;
        return true;
    }
    
    bool
    EventFieldList::operator!=(const EventFieldList& value)
    {
        return !this->operator==(value);
    }
    
    void
    EventFieldList::copyTo(EventFieldList& value)
    {
        value.clientHandle_ = clientHandle_;
        eventFields_.copyTo(value.eventFields());
    }
    
    EventFieldList&
    EventFieldList::operator=(const EventFieldList& value)
    {
        const_cast<EventFieldList*>(&value)->copyTo(*this);
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
    EventFieldList::factory(void)
    {
    	return constructSPtr<EventFieldList>();
    }
    
    std::string
    EventFieldList::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    EventFieldList::typeName(void)
    {
    	return "EventFieldList";
    }
    
    OpcUaNodeId
    EventFieldList::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)917,0);
    }
    
    OpcUaNodeId
    EventFieldList::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)919, 0);
    }
    
    OpcUaNodeId
    EventFieldList::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)918, 0);
    }
    
    OpcUaNodeId
    EventFieldList::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15348, 0);
    }
    
    void
    EventFieldList::opcUaBinaryEncode(std::ostream& os) const
    {
        OpcUaNumber::opcUaBinaryEncode(os,clientHandle_);
        eventFields_.opcUaBinaryEncode(os);
    }
    
    void
    EventFieldList::opcUaBinaryDecode(std::istream& is)
    {
        OpcUaNumber::opcUaBinaryDecode(is,clientHandle_);
        eventFields_.opcUaBinaryDecode(is);
    }
    
    bool
    EventFieldList::encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const
    {
    }
    
    bool
    EventFieldList::decode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
    }
    
    bool
    EventFieldList::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    EventFieldList::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, clientHandle_)) return false;
        pt.push_back(std::make_pair("ClientHandle", elementTree));
    
        elementTree.clear();
        if (!eventFields_.xmlEncode(elementTree, "Variant", xmlns)) return false;
        pt.push_back(std::make_pair("EventFields", elementTree));
    
        return true;
    }
    
    bool
    EventFieldList::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(element);
        if (!tree) return false;
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    EventFieldList::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree;
    
        tree = pt.get_child_optional("ClientHandle");
        if (!tree) return false;
        if(!XmlNumber::xmlDecode(*tree, clientHandle_)) return false;
    
        tree = pt.get_child_optional("EventFields");
        if (!tree) return false;
        if (!eventFields_.xmlDecode(*tree, "Variant", xmlns)) return false;
    
        return true;
    }
    
    bool
    EventFieldList::jsonEncode(boost::property_tree::ptree& pt, const std::string& element)
    {
        return true;
    }
    
    bool
    EventFieldList::jsonEncode(boost::property_tree::ptree& pt)
    {
        return true;
    }
    
    bool
    EventFieldList::jsonDecode(boost::property_tree::ptree& pt, const std::string& element)
    {
    }
    
    bool
    EventFieldList::jsonDecode(boost::property_tree::ptree& pt)
    {
    }
    
    void
    EventFieldList::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	EventFieldList* dst = dynamic_cast<EventFieldList*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    EventFieldList::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	EventFieldList* dst = dynamic_cast<EventFieldList*>(&extensionObjectBase);
    	return *const_cast<EventFieldList*>(this) == *dst;
    }
    
    void
    EventFieldList::out(std::ostream& os)
    {
        os << "ClientHandle=" << clientHandle_;
        os << ", EventFields="; eventFields_.out(os);
    }

}
