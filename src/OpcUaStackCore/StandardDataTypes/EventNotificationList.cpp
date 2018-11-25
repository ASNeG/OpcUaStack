/*
    DataTypeClass: EventNotificationList

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/EventNotificationList.h"

namespace OpcUaStackCore
{
    
    EventNotificationList::EventNotificationList(void)
    : NotificationData()
    , events_()
    {
    }
    
    EventNotificationList::~EventNotificationList(void)
    {
    }
    
    EventFieldListArray&
    EventNotificationList::events(void)
    {
        return events_;
    }
    
    bool
    EventNotificationList::operator==(const EventNotificationList& value)
    {
        EventNotificationList* dst = const_cast<EventNotificationList*>(&value);
        if (events_ != dst->events()) return false;
        return true;
    }
    
    bool
    EventNotificationList::operator!=(const EventNotificationList& value)
    {
        return !this->operator==(value);
    }
    
    void
    EventNotificationList::copyTo(EventNotificationList& value)
    {
        events_.copyTo(value.events());
    }
    
    EventNotificationList&
    EventNotificationList::operator=(const EventNotificationList& value)
    {
        const_cast<EventNotificationList*>(&value)->copyTo(*this);
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
    EventNotificationList::factory(void)
    {
    	return constructSPtr<EventNotificationList>();
    }
    
    std::string
    EventNotificationList::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    EventNotificationList::typeName(void)
    {
    	return "EventNotificationList";
    }
    
    OpcUaNodeId
    EventNotificationList::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)914,0);
    }
    
    OpcUaNodeId
    EventNotificationList::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)916, 0);
    }
    
    OpcUaNodeId
    EventNotificationList::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)915, 0);
    }
    
    OpcUaNodeId
    EventNotificationList::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15347, 0);
    }
    
    void
    EventNotificationList::opcUaBinaryEncode(std::ostream& os) const
    {
        NotificationData::opcUaBinaryEncode(os);
        events_.opcUaBinaryEncode(os);
    }
    
    void
    EventNotificationList::opcUaBinaryDecode(std::istream& is)
    {
        NotificationData::opcUaBinaryDecode(is);
        events_.opcUaBinaryDecode(is);
    }
    
    bool
    EventNotificationList::encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const
    {
    }
    
    bool
    EventNotificationList::decode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
    }
    
    bool
    EventNotificationList::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    EventNotificationList::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!events_.xmlEncode(elementTree, "EventFieldList", xmlns)) return false;
        pt.push_back(std::make_pair("Events", elementTree));
    
        return true;
    }
    
    bool
    EventNotificationList::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(element);
        if (!tree) return false;
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    EventNotificationList::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree;
    
        tree = pt.get_child_optional("Events");
        if (!tree) return false;
        if (!events_.xmlDecode(*tree, "EventFieldList", xmlns)) return false;
    
        return true;
    }
    
    bool
    EventNotificationList::jsonEncode(boost::property_tree::ptree& pt, const std::string& element)
    {
        return true;
    }
    
    bool
    EventNotificationList::jsonEncode(boost::property_tree::ptree& pt)
    {
        return true;
    }
    
    bool
    EventNotificationList::jsonDecode(boost::property_tree::ptree& pt, const std::string& element)
    {
    }
    
    bool
    EventNotificationList::jsonDecode(boost::property_tree::ptree& pt)
    {
    }
    
    void
    EventNotificationList::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	EventNotificationList* dst = dynamic_cast<EventNotificationList*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    EventNotificationList::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	EventNotificationList* dst = dynamic_cast<EventNotificationList*>(&extensionObjectBase);
    	return *const_cast<EventNotificationList*>(this) == *dst;
    }
    
    void
    EventNotificationList::out(std::ostream& os)
    {
        os << "Events="; events_.out(os);
    }

}
