/*
    DataTypeClass: ViewAttributes

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/ViewAttributes.h"

namespace OpcUaStackCore
{
    
    /**
     * The attributes for a view node.
     */
    ViewAttributes::ViewAttributes(void)
    : NodeAttributes()
    , containsNoLoops_()
    , eventNotifier_()
    {
    }
    
    /**
     * The attributes for a view node.
     */
    ViewAttributes::ViewAttributes(const ViewAttributes& value)
    : NodeAttributes()
    , containsNoLoops_()
    , eventNotifier_()
    {
        const_cast<ViewAttributes*>(&value)->copyTo(*this);
    }
    
    ViewAttributes::~ViewAttributes(void)
    {
    }
    
    OpcUaBoolean&
    ViewAttributes::containsNoLoops(void)
    {
        return containsNoLoops_;
    }
    
    OpcUaByte&
    ViewAttributes::eventNotifier(void)
    {
        return eventNotifier_;
    }
    
    bool
    ViewAttributes::operator==(const ViewAttributes& value)
    {
        ViewAttributes* dst = const_cast<ViewAttributes*>(&value);
        if (containsNoLoops_ != dst->containsNoLoops()) return false;
        if (eventNotifier_ != dst->eventNotifier()) return false;
        return true;
    }
    
    bool
    ViewAttributes::operator!=(const ViewAttributes& value)
    {
        return !this->operator==(value);
    }
    
    void
    ViewAttributes::copyTo(ViewAttributes& value)
    {
        value.containsNoLoops_ = containsNoLoops_;
        value.eventNotifier_ = eventNotifier_;
    }
    
    ViewAttributes&
    ViewAttributes::operator=(const ViewAttributes& value)
    {
        const_cast<ViewAttributes*>(&value)->copyTo(*this);
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
    ViewAttributes::factory(void)
    {
    	return constructSPtr<ViewAttributes>();
    }
    
    std::string
    ViewAttributes::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    ViewAttributes::typeName(void)
    {
    	return "ViewAttributes";
    }
    
    OpcUaNodeId
    ViewAttributes::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)373,0);
    }
    
    OpcUaNodeId
    ViewAttributes::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)375, 0);
    }
    
    OpcUaNodeId
    ViewAttributes::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)374, 0);
    }
    
    OpcUaNodeId
    ViewAttributes::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15162, 0);
    }
    
    void
    ViewAttributes::opcUaBinaryEncode(std::ostream& os) const
    {
        NodeAttributes::opcUaBinaryEncode(os);
        OpcUaNumber::opcUaBinaryEncode(os,containsNoLoops_);
        OpcUaNumber::opcUaBinaryEncode(os,eventNotifier_);
    }
    
    void
    ViewAttributes::opcUaBinaryDecode(std::istream& is)
    {
        NodeAttributes::opcUaBinaryDecode(is);
        OpcUaNumber::opcUaBinaryDecode(is,containsNoLoops_);
        OpcUaNumber::opcUaBinaryDecode(is,eventNotifier_);
    }
    
    bool
    ViewAttributes::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "ViewAttributes encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    ViewAttributes::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, containsNoLoops_))
        {
            Log(Error, "ViewAttributes encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("ContainsNoLoops", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, eventNotifier_))
        {
            Log(Error, "ViewAttributes encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("EventNotifier", elementTree));
    
        return true;
    }
    
    bool
    ViewAttributes::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ViewAttributes decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    ViewAttributes::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        elementName = xmlns.addPrefix("ContainsNoLoops");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ViewAttributes decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, containsNoLoops_)) {
            Log(Error, "ViewAttributes decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("EventNotifier");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ViewAttributes decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, eventNotifier_)) {
            Log(Error, "ViewAttributes decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    bool
    ViewAttributes::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, containsNoLoops_))
        {
    	     Log(Error, "ViewAttributes json encoder error")
    		     .parameter("Element", "containsNoLoops_");
           return false;
        }
        pt.push_back(std::make_pair("ContainsNoLoops", elementTree));
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, eventNotifier_))
        {
    	     Log(Error, "ViewAttributes json encoder error")
    		     .parameter("Element", "eventNotifier_");
           return false;
        }
        pt.push_back(std::make_pair("EventNotifier", elementTree));
    
        return true;
    }
    
    bool
    ViewAttributes::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        std::string elementName;
        boost::optional<const boost::property_tree::ptree&> tree;
    
        elementName = "ContainsNoLoops";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ViewAttributes decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, containsNoLoops_)) {
            Log(Error, "ViewAttributes decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "EventNotifier";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ViewAttributes decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, eventNotifier_)) {
            Log(Error, "ViewAttributes decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    void
    ViewAttributes::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	ViewAttributes* dst = dynamic_cast<ViewAttributes*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    ViewAttributes::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	ViewAttributes* dst = dynamic_cast<ViewAttributes*>(&extensionObjectBase);
    	return *const_cast<ViewAttributes*>(this) == *dst;
    }
    
    void
    ViewAttributes::out(std::ostream& os)
    {
        os << "ContainsNoLoops=" << containsNoLoops_;
        os << ", EventNotifier=" << eventNotifier_;
    }

}
