/*
    DataTypeClass: HistoryEvent

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/HistoryEvent.h"

namespace OpcUaStackCore
{
    
    HistoryEvent::HistoryEvent(void)
    : Object()
    , ExtensionObjectBase()
    , events_()
    {
    }
    
    HistoryEvent::HistoryEvent(const HistoryEvent& value)
    : Object()
    , ExtensionObjectBase()
    , events_()
    {
        const_cast<HistoryEvent*>(&value)->copyTo(*this);
    }
    
    HistoryEvent::~HistoryEvent(void)
    {
    }
    
    HistoryEventFieldListArray&
    HistoryEvent::events(void)
    {
        return events_;
    }
    
    bool
    HistoryEvent::operator==(const HistoryEvent& value)
    {
        HistoryEvent* dst = const_cast<HistoryEvent*>(&value);
        if (events_ != dst->events()) return false;
        return true;
    }
    
    bool
    HistoryEvent::operator!=(const HistoryEvent& value)
    {
        return !this->operator==(value);
    }
    
    void
    HistoryEvent::copyTo(HistoryEvent& value)
    {
        events_.copyTo(value.events());
    }
    
    HistoryEvent&
    HistoryEvent::operator=(const HistoryEvent& value)
    {
        const_cast<HistoryEvent*>(&value)->copyTo(*this);
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
    HistoryEvent::factory(void)
    {
    	return constructSPtr<HistoryEvent>();
    }
    
    std::string
    HistoryEvent::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    HistoryEvent::typeName(void)
    {
    	return "HistoryEvent";
    }
    
    OpcUaNodeId
    HistoryEvent::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)659,0);
    }
    
    OpcUaNodeId
    HistoryEvent::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)661, 0);
    }
    
    OpcUaNodeId
    HistoryEvent::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)660, 0);
    }
    
    OpcUaNodeId
    HistoryEvent::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15273, 0);
    }
    
    void
    HistoryEvent::opcUaBinaryEncode(std::ostream& os) const
    {
        events_.opcUaBinaryEncode(os);
    }
    
    void
    HistoryEvent::opcUaBinaryDecode(std::istream& is)
    {
        events_.opcUaBinaryDecode(is);
    }
    
    bool
    HistoryEvent::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "HistoryEvent encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    HistoryEvent::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!events_.xmlEncode(elementTree, "HistoryEventFieldList", xmlns)) {
            Log(Error, "HistoryEvent encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("Events", elementTree));
    
        return true;
    }
    
    bool
    HistoryEvent::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "HistoryEvent decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    HistoryEvent::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        elementName = xmlns.addPrefix("Events");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "HistoryEvent decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!events_.xmlDecode(*tree, "HistoryEventFieldList", xmlns)) {
            Log(Error, "HistoryEvent decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    bool
    HistoryEvent::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!events_.jsonEncode(elementTree, ""))
        {
    	     Log(Error, "HistoryEvent json encoder error")
    		     .parameter("Element", "events_");
            return false;
        }
        pt.push_back(std::make_pair("Events", elementTree));
    
        return true;
    }
    
    bool
    HistoryEvent::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        std::string elementName;
        boost::optional<const boost::property_tree::ptree&> tree;
    
        elementName = "Events";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "HistoryEvent decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!events_.jsonDecode(*tree, "")) {
            Log(Error, "HistoryEvent decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    void
    HistoryEvent::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	HistoryEvent* dst = dynamic_cast<HistoryEvent*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    HistoryEvent::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	HistoryEvent* dst = dynamic_cast<HistoryEvent*>(&extensionObjectBase);
    	return *const_cast<HistoryEvent*>(this) == *dst;
    }
    
    void
    HistoryEvent::out(std::ostream& os)
    {
        os << "Events="; events_.out(os);
    }

}
