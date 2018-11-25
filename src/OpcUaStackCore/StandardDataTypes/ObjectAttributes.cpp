/*
    DataTypeClass: ObjectAttributes

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/ObjectAttributes.h"

namespace OpcUaStackCore
{
    
    /**
     * The attributes for an object node.
     */
    ObjectAttributes::ObjectAttributes(void)
    : NodeAttributes()
    , eventNotifier_()
    {
    }
    
    ObjectAttributes::~ObjectAttributes(void)
    {
    }
    
    OpcUaByte&
    ObjectAttributes::eventNotifier(void)
    {
        return eventNotifier_;
    }
    
    bool
    ObjectAttributes::operator==(const ObjectAttributes& value)
    {
        ObjectAttributes* dst = const_cast<ObjectAttributes*>(&value);
        if (eventNotifier_ != dst->eventNotifier()) return false;
        return true;
    }
    
    bool
    ObjectAttributes::operator!=(const ObjectAttributes& value)
    {
        return !this->operator==(value);
    }
    
    void
    ObjectAttributes::copyTo(ObjectAttributes& value)
    {
        value.eventNotifier_ = eventNotifier_;
    }
    
    ObjectAttributes&
    ObjectAttributes::operator=(const ObjectAttributes& value)
    {
        const_cast<ObjectAttributes*>(&value)->copyTo(*this);
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
    ObjectAttributes::factory(void)
    {
    	return constructSPtr<ObjectAttributes>();
    }
    
    std::string
    ObjectAttributes::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    ObjectAttributes::typeName(void)
    {
    	return "ObjectAttributes";
    }
    
    OpcUaNodeId
    ObjectAttributes::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)352,0);
    }
    
    OpcUaNodeId
    ObjectAttributes::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)354, 0);
    }
    
    OpcUaNodeId
    ObjectAttributes::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)353, 0);
    }
    
    OpcUaNodeId
    ObjectAttributes::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15152, 0);
    }
    
    void
    ObjectAttributes::opcUaBinaryEncode(std::ostream& os) const
    {
        NodeAttributes::opcUaBinaryEncode(os);
        OpcUaNumber::opcUaBinaryEncode(os,eventNotifier_);
    }
    
    void
    ObjectAttributes::opcUaBinaryDecode(std::istream& is)
    {
        NodeAttributes::opcUaBinaryDecode(is);
        OpcUaNumber::opcUaBinaryDecode(is,eventNotifier_);
    }
    
    bool
    ObjectAttributes::encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const
    {
    }
    
    bool
    ObjectAttributes::decode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
    }
    
    bool
    ObjectAttributes::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    ObjectAttributes::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, eventNotifier_)) return false;
        pt.push_back(std::make_pair("EventNotifier", elementTree));
    
        return true;
    }
    
    bool
    ObjectAttributes::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(element);
        if (!tree) return false;
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    ObjectAttributes::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree;
    
        tree = pt.get_child_optional("EventNotifier");
        if (!tree) return false;
        if(!XmlNumber::xmlDecode(*tree, eventNotifier_)) return false;
    
        return true;
    }
    
    bool
    ObjectAttributes::jsonEncode(boost::property_tree::ptree& pt, const std::string& element)
    {
        return true;
    }
    
    bool
    ObjectAttributes::jsonEncode(boost::property_tree::ptree& pt)
    {
        return true;
    }
    
    bool
    ObjectAttributes::jsonDecode(boost::property_tree::ptree& pt, const std::string& element)
    {
    }
    
    bool
    ObjectAttributes::jsonDecode(boost::property_tree::ptree& pt)
    {
    }
    
    void
    ObjectAttributes::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	ObjectAttributes* dst = dynamic_cast<ObjectAttributes*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    ObjectAttributes::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	ObjectAttributes* dst = dynamic_cast<ObjectAttributes*>(&extensionObjectBase);
    	return *const_cast<ObjectAttributes*>(this) == *dst;
    }
    
    void
    ObjectAttributes::out(std::ostream& os)
    {
        os << "EventNotifier=" << eventNotifier_;
    }

}