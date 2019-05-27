/*
    DataTypeClass: NodeAttributes

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/NodeAttributes.h"

namespace OpcUaStackCore
{
    
    /**
     * The base attributes for all nodes.
     */
    NodeAttributes::NodeAttributes(void)
    : Object()
    , ExtensionObjectBase()
    , specifiedAttributes_()
    , displayName_()
    , description_()
    , writeMask_()
    , userWriteMask_()
    {
    }
    
    /**
     * The base attributes for all nodes.
     */
    NodeAttributes::NodeAttributes(const NodeAttributes& value)
    : Object()
    , ExtensionObjectBase()
    , specifiedAttributes_()
    , displayName_()
    , description_()
    , writeMask_()
    , userWriteMask_()
    {
        const_cast<NodeAttributes*>(&value)->copyTo(*this);
    }
    
    NodeAttributes::~NodeAttributes(void)
    {
    }
    
    OpcUaUInt32&
    NodeAttributes::specifiedAttributes(void)
    {
        return specifiedAttributes_;
    }
    
    OpcUaLocalizedText&
    NodeAttributes::displayName(void)
    {
        return displayName_;
    }
    
    OpcUaLocalizedText&
    NodeAttributes::description(void)
    {
        return description_;
    }
    
    OpcUaUInt32&
    NodeAttributes::writeMask(void)
    {
        return writeMask_;
    }
    
    OpcUaUInt32&
    NodeAttributes::userWriteMask(void)
    {
        return userWriteMask_;
    }
    
    bool
    NodeAttributes::operator==(const NodeAttributes& value)
    {
        NodeAttributes* dst = const_cast<NodeAttributes*>(&value);
        if (specifiedAttributes_ != dst->specifiedAttributes()) return false;
        if (displayName_ != dst->displayName()) return false;
        if (description_ != dst->description()) return false;
        if (writeMask_ != dst->writeMask()) return false;
        if (userWriteMask_ != dst->userWriteMask()) return false;
        return true;
    }
    
    bool
    NodeAttributes::operator!=(const NodeAttributes& value)
    {
        return !this->operator==(value);
    }
    
    void
    NodeAttributes::copyTo(NodeAttributes& value)
    {
        value.specifiedAttributes_ = specifiedAttributes_;
        displayName_.copyTo(value.displayName());
        description_.copyTo(value.description());
        value.writeMask_ = writeMask_;
        value.userWriteMask_ = userWriteMask_;
    }
    
    NodeAttributes&
    NodeAttributes::operator=(const NodeAttributes& value)
    {
        const_cast<NodeAttributes*>(&value)->copyTo(*this);
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
    NodeAttributes::factory(void)
    {
    	return constructSPtr<NodeAttributes>();
    }
    
    std::string
    NodeAttributes::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    NodeAttributes::typeName(void)
    {
    	return "NodeAttributes";
    }
    
    OpcUaNodeId
    NodeAttributes::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)349,0);
    }
    
    OpcUaNodeId
    NodeAttributes::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)351, 0);
    }
    
    OpcUaNodeId
    NodeAttributes::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)350, 0);
    }
    
    OpcUaNodeId
    NodeAttributes::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15151, 0);
    }
    
    void
    NodeAttributes::opcUaBinaryEncode(std::ostream& os) const
    {
        OpcUaNumber::opcUaBinaryEncode(os,specifiedAttributes_);
        displayName_.opcUaBinaryEncode(os);
        description_.opcUaBinaryEncode(os);
        OpcUaNumber::opcUaBinaryEncode(os,writeMask_);
        OpcUaNumber::opcUaBinaryEncode(os,userWriteMask_);
    }
    
    void
    NodeAttributes::opcUaBinaryDecode(std::istream& is)
    {
        OpcUaNumber::opcUaBinaryDecode(is,specifiedAttributes_);
        displayName_.opcUaBinaryDecode(is);
        description_.opcUaBinaryDecode(is);
        OpcUaNumber::opcUaBinaryDecode(is,writeMask_);
        OpcUaNumber::opcUaBinaryDecode(is,userWriteMask_);
    }
    
    bool
    NodeAttributes::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "NodeAttributes encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    NodeAttributes::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, specifiedAttributes_))
        {
            Log(Error, "NodeAttributes encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("SpecifiedAttributes", elementTree));
    
        elementTree.clear();
        if (!displayName_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "NodeAttributes encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("DisplayName", elementTree));
    
        elementTree.clear();
        if (!description_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "NodeAttributes encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("Description", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, writeMask_))
        {
            Log(Error, "NodeAttributes encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("WriteMask", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, userWriteMask_))
        {
            Log(Error, "NodeAttributes encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("UserWriteMask", elementTree));
    
        return true;
    }
    
    bool
    NodeAttributes::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "NodeAttributes decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    NodeAttributes::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        elementName = xmlns.addPrefix("SpecifiedAttributes");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "NodeAttributes decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, specifiedAttributes_)) {
            Log(Error, "NodeAttributes decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("DisplayName");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "NodeAttributes decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!displayName_.xmlDecode(*tree, xmlns)) {
            Log(Error, "NodeAttributes decode xml error - decode failed")
                .parameter("Element", "DisplayName");
            return false;
        }
    
        elementName = xmlns.addPrefix("Description");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "NodeAttributes decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!description_.xmlDecode(*tree, xmlns)) {
            Log(Error, "NodeAttributes decode xml error - decode failed")
                .parameter("Element", "Description");
            return false;
        }
    
        elementName = xmlns.addPrefix("WriteMask");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "NodeAttributes decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, writeMask_)) {
            Log(Error, "NodeAttributes decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("UserWriteMask");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "NodeAttributes decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, userWriteMask_)) {
            Log(Error, "NodeAttributes decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    bool
    NodeAttributes::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, specifiedAttributes_))
        {
    	     Log(Error, "NodeAttributes json encoder error")
    		     .parameter("Element", "specifiedAttributes_");
           return false;
        }
        pt.push_back(std::make_pair("SpecifiedAttributes", elementTree));
    
        elementTree.clear();
        if (!displayName_.jsonEncode(elementTree))
        {
    	     Log(Error, "NodeAttributes json encoder error")
    		     .parameter("Element", "displayName_");
            return false;
        }
        pt.push_back(std::make_pair("DisplayName", elementTree));
    
        elementTree.clear();
        if (!description_.jsonEncode(elementTree))
        {
    	     Log(Error, "NodeAttributes json encoder error")
    		     .parameter("Element", "description_");
            return false;
        }
        pt.push_back(std::make_pair("Description", elementTree));
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, writeMask_))
        {
    	     Log(Error, "NodeAttributes json encoder error")
    		     .parameter("Element", "writeMask_");
           return false;
        }
        pt.push_back(std::make_pair("WriteMask", elementTree));
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, userWriteMask_))
        {
    	     Log(Error, "NodeAttributes json encoder error")
    		     .parameter("Element", "userWriteMask_");
           return false;
        }
        pt.push_back(std::make_pair("UserWriteMask", elementTree));
    
        return true;
    }
    
    bool
    NodeAttributes::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        std::string elementName;
        boost::optional<const boost::property_tree::ptree&> tree;
    
        elementName = "SpecifiedAttributes";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "NodeAttributes decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, specifiedAttributes_)) {
            Log(Error, "NodeAttributes decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "DisplayName";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "NodeAttributes decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!displayName_.jsonDecode(*tree)) {
            Log(Error, "NodeAttributes decode json error - decode failed")
                .parameter("Element", "DisplayName");
            return false;
        }
    
        elementName = "Description";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "NodeAttributes decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!description_.jsonDecode(*tree)) {
            Log(Error, "NodeAttributes decode json error - decode failed")
                .parameter("Element", "Description");
            return false;
        }
    
        elementName = "WriteMask";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "NodeAttributes decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, writeMask_)) {
            Log(Error, "NodeAttributes decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "UserWriteMask";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "NodeAttributes decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, userWriteMask_)) {
            Log(Error, "NodeAttributes decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    void
    NodeAttributes::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	NodeAttributes* dst = dynamic_cast<NodeAttributes*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    NodeAttributes::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	NodeAttributes* dst = dynamic_cast<NodeAttributes*>(&extensionObjectBase);
    	return *const_cast<NodeAttributes*>(this) == *dst;
    }
    
    void
    NodeAttributes::out(std::ostream& os)
    {
        os << "SpecifiedAttributes=" << specifiedAttributes_;
        os << ", DisplayName="; displayName_.out(os);
        os << ", Description="; description_.out(os);
        os << ", WriteMask=" << writeMask_;
        os << ", UserWriteMask=" << userWriteMask_;
    }

}
