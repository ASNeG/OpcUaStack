/*
    DataTypeClass: AttributeOperand

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/AttributeOperand.h"

namespace OpcUaStackCore
{
    
    AttributeOperand::AttributeOperand(void)
    : FilterOperand()
    , nodeId_()
    , alias_()
    , browsePath_()
    , attributeId_()
    , indexRange_()
    {
    }
    
    AttributeOperand::AttributeOperand(const AttributeOperand& value)
    : FilterOperand()
    , nodeId_()
    , alias_()
    , browsePath_()
    , attributeId_()
    , indexRange_()
    {
        const_cast<AttributeOperand*>(&value)->copyTo(*this);
    }
    
    AttributeOperand::~AttributeOperand(void)
    {
    }
    
    OpcUaNodeId&
    AttributeOperand::nodeId(void)
    {
        return nodeId_;
    }
    
    OpcUaString&
    AttributeOperand::alias(void)
    {
        return alias_;
    }
    
    RelativePath&
    AttributeOperand::browsePath(void)
    {
        return browsePath_;
    }
    
    OpcUaIntegerId&
    AttributeOperand::attributeId(void)
    {
        return attributeId_;
    }
    
    OpcUaNumericRange&
    AttributeOperand::indexRange(void)
    {
        return indexRange_;
    }
    
    bool
    AttributeOperand::operator==(const AttributeOperand& value)
    {
        AttributeOperand* dst = const_cast<AttributeOperand*>(&value);
        if (nodeId_ != dst->nodeId()) return false;
        if (alias_ != dst->alias()) return false;
        if (browsePath_ != dst->browsePath()) return false;
        if (attributeId_ != dst->attributeId()) return false;
        if (indexRange_ != dst->indexRange()) return false;
        return true;
    }
    
    bool
    AttributeOperand::operator!=(const AttributeOperand& value)
    {
        return !this->operator==(value);
    }
    
    void
    AttributeOperand::copyTo(AttributeOperand& value)
    {
        nodeId_.copyTo(value.nodeId());
        alias_.copyTo(value.alias());
        browsePath_.copyTo(value.browsePath());
        value.attributeId_ = attributeId_;
        indexRange_.copyTo(value.indexRange());
    }
    
    AttributeOperand&
    AttributeOperand::operator=(const AttributeOperand& value)
    {
        const_cast<AttributeOperand*>(&value)->copyTo(*this);
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
    AttributeOperand::factory(void)
    {
    	return constructSPtr<AttributeOperand>();
    }
    
    std::string
    AttributeOperand::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    AttributeOperand::typeName(void)
    {
    	return "AttributeOperand";
    }
    
    OpcUaNodeId
    AttributeOperand::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)598,0);
    }
    
    OpcUaNodeId
    AttributeOperand::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)600, 0);
    }
    
    OpcUaNodeId
    AttributeOperand::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)599, 0);
    }
    
    OpcUaNodeId
    AttributeOperand::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15209, 0);
    }
    
    void
    AttributeOperand::opcUaBinaryEncode(std::ostream& os) const
    {
        FilterOperand::opcUaBinaryEncode(os);
        nodeId_.opcUaBinaryEncode(os);
        alias_.opcUaBinaryEncode(os);
        browsePath_.opcUaBinaryEncode(os);
        OpcUaNumber::opcUaBinaryEncode(os,attributeId_);
        indexRange_.opcUaBinaryEncode(os);
    }
    
    void
    AttributeOperand::opcUaBinaryDecode(std::istream& is)
    {
        FilterOperand::opcUaBinaryDecode(is);
        nodeId_.opcUaBinaryDecode(is);
        alias_.opcUaBinaryDecode(is);
        browsePath_.opcUaBinaryDecode(is);
        OpcUaNumber::opcUaBinaryDecode(is,attributeId_);
        indexRange_.opcUaBinaryDecode(is);
    }
    
    bool
    AttributeOperand::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "AttributeOperand encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    AttributeOperand::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!nodeId_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "AttributeOperand encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("NodeId", elementTree));
    
        elementTree.clear();
        if (!alias_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "AttributeOperand encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("Alias", elementTree));
    
        elementTree.clear();
        if (!browsePath_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "AttributeOperand encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("BrowsePath", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, attributeId_))
        {
            Log(Error, "AttributeOperand encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("AttributeId", elementTree));
    
        elementTree.clear();
        if (!indexRange_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "AttributeOperand encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("IndexRange", elementTree));
    
        return true;
    }
    
    bool
    AttributeOperand::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "AttributeOperand decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    AttributeOperand::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        elementName = xmlns.addPrefix("NodeId");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "AttributeOperand decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!nodeId_.xmlDecode(*tree, xmlns)) {
            Log(Error, "AttributeOperand decode xml error - decode failed")
                .parameter("Element", "NodeId");
            return false;
        }
    
        elementName = xmlns.addPrefix("Alias");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "AttributeOperand decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!alias_.xmlDecode(*tree, xmlns)) {
            Log(Error, "AttributeOperand decode xml error - decode failed")
                .parameter("Element", "Alias");
            return false;
        }
    
        elementName = xmlns.addPrefix("BrowsePath");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "AttributeOperand decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!browsePath_.xmlDecode(*tree, xmlns)) {
            Log(Error, "AttributeOperand decode xml error - decode failed")
                .parameter("Element", "BrowsePath");
            return false;
        }
    
        elementName = xmlns.addPrefix("AttributeId");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "AttributeOperand decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, attributeId_)) {
            Log(Error, "AttributeOperand decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("IndexRange");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "AttributeOperand decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!indexRange_.xmlDecode(*tree, xmlns)) {
            Log(Error, "AttributeOperand decode xml error - decode failed")
                .parameter("Element", "IndexRange");
            return false;
        }
    
        return true;
    }
    
    bool
    AttributeOperand::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!nodeId_.jsonEncode(elementTree))
        {
    	     Log(Error, "AttributeOperand json encoder error")
    		     .parameter("Element", "nodeId_");
            return false;
        }
        pt.push_back(std::make_pair("NodeId", elementTree));
    
        elementTree.clear();
        if (!alias_.jsonEncode(elementTree))
        {
    	     Log(Error, "AttributeOperand json encoder error")
    		     .parameter("Element", "alias_");
            return false;
        }
        pt.push_back(std::make_pair("Alias", elementTree));
    
        elementTree.clear();
        if (!browsePath_.jsonEncode(elementTree))
        {
    	     Log(Error, "AttributeOperand json encoder error")
    		     .parameter("Element", "browsePath_");
            return false;
        }
        pt.push_back(std::make_pair("BrowsePath", elementTree));
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, attributeId_))
        {
    	     Log(Error, "AttributeOperand json encoder error")
    		     .parameter("Element", "attributeId_");
           return false;
        }
        pt.push_back(std::make_pair("AttributeId", elementTree));
    
        elementTree.clear();
        if (!indexRange_.jsonEncode(elementTree))
        {
    	     Log(Error, "AttributeOperand json encoder error")
    		     .parameter("Element", "indexRange_");
            return false;
        }
        pt.push_back(std::make_pair("IndexRange", elementTree));
    
        return true;
    }
    
    bool
    AttributeOperand::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        std::string elementName;
        boost::optional<const boost::property_tree::ptree&> tree;
    
        elementName = "NodeId";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "AttributeOperand decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!nodeId_.jsonDecode(*tree)) {
            Log(Error, "AttributeOperand decode json error - decode failed")
                .parameter("Element", "NodeId");
            return false;
        }
    
        elementName = "Alias";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "AttributeOperand decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!alias_.jsonDecode(*tree)) {
            Log(Error, "AttributeOperand decode json error - decode failed")
                .parameter("Element", "Alias");
            return false;
        }
    
        elementName = "BrowsePath";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "AttributeOperand decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!browsePath_.jsonDecode(*tree)) {
            Log(Error, "AttributeOperand decode json error - decode failed")
                .parameter("Element", "BrowsePath");
            return false;
        }
    
        elementName = "AttributeId";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "AttributeOperand decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, attributeId_)) {
            Log(Error, "AttributeOperand decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "IndexRange";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "AttributeOperand decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!indexRange_.jsonDecode(*tree)) {
            Log(Error, "AttributeOperand decode json error - decode failed")
                .parameter("Element", "IndexRange");
            return false;
        }
    
        return true;
    }
    
    void
    AttributeOperand::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	AttributeOperand* dst = dynamic_cast<AttributeOperand*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    AttributeOperand::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	AttributeOperand* dst = dynamic_cast<AttributeOperand*>(&extensionObjectBase);
    	return *const_cast<AttributeOperand*>(this) == *dst;
    }
    
    void
    AttributeOperand::out(std::ostream& os)
    {
        os << "NodeId="; nodeId_.out(os);
        os << ", Alias="; alias_.out(os);
        os << ", BrowsePath="; browsePath_.out(os);
        os << ", AttributeId=" << attributeId_;
        os << ", IndexRange="; indexRange_.out(os);
    }

}
