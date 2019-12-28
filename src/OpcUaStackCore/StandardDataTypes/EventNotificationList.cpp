/*
    DataTypeClass: EventNotificationList

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

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
    
    EventNotificationList::EventNotificationList(const EventNotificationList& value)
    : NotificationData()
    , events_()
    {
        const_cast<EventNotificationList*>(&value)->copyTo(*this);
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
    	return boost::make_shared<EventNotificationList>();
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
    
    bool
    EventNotificationList::opcUaBinaryEncode(std::ostream& os) const
    {
        bool rc = true;
    
        rc &= NotificationData::opcUaBinaryEncode(os);
        rc &= events_.opcUaBinaryEncode(os);
        return rc;
    }
    
    bool
    EventNotificationList::opcUaBinaryDecode(std::istream& is)
    {
        bool rc = true;
    
        rc &= NotificationData::opcUaBinaryDecode(is);
        rc &= events_.opcUaBinaryDecode(is);
        return rc;
    }
    
    bool
    EventNotificationList::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "EventNotificationList encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    EventNotificationList::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!events_.xmlEncode(elementTree, "EventFieldList", xmlns)) {
            Log(Error, "EventNotificationList encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("Events", elementTree));
    
        return true;
    }
    
    bool
    EventNotificationList::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "EventNotificationList decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    EventNotificationList::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        elementName = xmlns.addPrefix("Events");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "EventNotificationList decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!events_.xmlDecode(*tree, "EventFieldList", xmlns)) {
            Log(Error, "EventNotificationList decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    bool
    EventNotificationList::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        bool rc = true;
    
        rc = rc & jsonArrayEncode(pt, events_, "Events", true);
    
        return rc;
    }
    
    bool
    EventNotificationList::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        bool rc = true;
    
        rc = rc & jsonArrayDecode(pt, events_, "Events", true);
    
        return rc;
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
