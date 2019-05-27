/*
    DataTypeClass: SimpleAttributeOperand

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/SimpleAttributeOperand.h"

namespace OpcUaStackCore
{
    
    SimpleAttributeOperand::SimpleAttributeOperand(void)
    : FilterOperand()
    , typeDefinitionId_()
    , browsePath_()
    , attributeId_()
    , indexRange_()
    {
    }
    
    SimpleAttributeOperand::SimpleAttributeOperand(const SimpleAttributeOperand& value)
    : FilterOperand()
    , typeDefinitionId_()
    , browsePath_()
    , attributeId_()
    , indexRange_()
    {
        const_cast<SimpleAttributeOperand*>(&value)->copyTo(*this);
    }
    
    SimpleAttributeOperand::~SimpleAttributeOperand(void)
    {
    }
    
    OpcUaNodeId&
    SimpleAttributeOperand::typeDefinitionId(void)
    {
        return typeDefinitionId_;
    }
    
    OpcUaQualifiedNameArray&
    SimpleAttributeOperand::browsePath(void)
    {
        return browsePath_;
    }
    
    OpcUaIntegerId&
    SimpleAttributeOperand::attributeId(void)
    {
        return attributeId_;
    }
    
    OpcUaNumericRange&
    SimpleAttributeOperand::indexRange(void)
    {
        return indexRange_;
    }
    
    bool
    SimpleAttributeOperand::operator==(const SimpleAttributeOperand& value)
    {
        SimpleAttributeOperand* dst = const_cast<SimpleAttributeOperand*>(&value);
        if (typeDefinitionId_ != dst->typeDefinitionId()) return false;
        if (browsePath_ != dst->browsePath()) return false;
        if (attributeId_ != dst->attributeId()) return false;
        if (indexRange_ != dst->indexRange()) return false;
        return true;
    }
    
    bool
    SimpleAttributeOperand::operator!=(const SimpleAttributeOperand& value)
    {
        return !this->operator==(value);
    }
    
    void
    SimpleAttributeOperand::copyTo(SimpleAttributeOperand& value)
    {
        typeDefinitionId_.copyTo(value.typeDefinitionId());
        browsePath_.copyTo(value.browsePath());
        value.attributeId_ = attributeId_;
        indexRange_.copyTo(value.indexRange());
    }
    
    SimpleAttributeOperand&
    SimpleAttributeOperand::operator=(const SimpleAttributeOperand& value)
    {
        const_cast<SimpleAttributeOperand*>(&value)->copyTo(*this);
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
    SimpleAttributeOperand::factory(void)
    {
    	return constructSPtr<SimpleAttributeOperand>();
    }
    
    std::string
    SimpleAttributeOperand::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    SimpleAttributeOperand::typeName(void)
    {
    	return "SimpleAttributeOperand";
    }
    
    OpcUaNodeId
    SimpleAttributeOperand::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)601,0);
    }
    
    OpcUaNodeId
    SimpleAttributeOperand::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)603, 0);
    }
    
    OpcUaNodeId
    SimpleAttributeOperand::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)602, 0);
    }
    
    OpcUaNodeId
    SimpleAttributeOperand::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15210, 0);
    }
    
    void
    SimpleAttributeOperand::opcUaBinaryEncode(std::ostream& os) const
    {
        FilterOperand::opcUaBinaryEncode(os);
        typeDefinitionId_.opcUaBinaryEncode(os);
        browsePath_.opcUaBinaryEncode(os);
        OpcUaNumber::opcUaBinaryEncode(os,attributeId_);
        indexRange_.opcUaBinaryEncode(os);
    }
    
    void
    SimpleAttributeOperand::opcUaBinaryDecode(std::istream& is)
    {
        FilterOperand::opcUaBinaryDecode(is);
        typeDefinitionId_.opcUaBinaryDecode(is);
        browsePath_.opcUaBinaryDecode(is);
        OpcUaNumber::opcUaBinaryDecode(is,attributeId_);
        indexRange_.opcUaBinaryDecode(is);
    }
    
    bool
    SimpleAttributeOperand::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "SimpleAttributeOperand encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    SimpleAttributeOperand::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!typeDefinitionId_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "SimpleAttributeOperand encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("TypeDefinitionId", elementTree));
    
        elementTree.clear();
        if (!browsePath_.xmlEncode(elementTree, "QualifiedName", xmlns)) {
            Log(Error, "SimpleAttributeOperand encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("BrowsePath", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, attributeId_))
        {
            Log(Error, "SimpleAttributeOperand encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("AttributeId", elementTree));
    
        elementTree.clear();
        if (!indexRange_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "SimpleAttributeOperand encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("IndexRange", elementTree));
    
        return true;
    }
    
    bool
    SimpleAttributeOperand::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SimpleAttributeOperand decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    SimpleAttributeOperand::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        elementName = xmlns.addPrefix("TypeDefinitionId");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SimpleAttributeOperand decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!typeDefinitionId_.xmlDecode(*tree, xmlns)) {
            Log(Error, "SimpleAttributeOperand decode xml error - decode failed")
                .parameter("Element", "TypeDefinitionId");
            return false;
        }
    
        elementName = xmlns.addPrefix("BrowsePath");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SimpleAttributeOperand decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!browsePath_.xmlDecode(*tree, "QualifiedName", xmlns)) {
            Log(Error, "SimpleAttributeOperand decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("AttributeId");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SimpleAttributeOperand decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, attributeId_)) {
            Log(Error, "SimpleAttributeOperand decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("IndexRange");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SimpleAttributeOperand decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!indexRange_.xmlDecode(*tree, xmlns)) {
            Log(Error, "SimpleAttributeOperand decode xml error - decode failed")
                .parameter("Element", "IndexRange");
            return false;
        }
    
        return true;
    }
    
    bool
    SimpleAttributeOperand::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!typeDefinitionId_.jsonEncode(elementTree))
        {
    	     Log(Error, "SimpleAttributeOperand json encoder error")
    		     .parameter("Element", "typeDefinitionId_");
            return false;
        }
        pt.push_back(std::make_pair("TypeDefinitionId", elementTree));
    
        elementTree.clear();
        if (!browsePath_.jsonEncode(elementTree, ""))
        {
    	     Log(Error, "SimpleAttributeOperand json encoder error")
    		     .parameter("Element", "browsePath_");
            return false;
        }
        pt.push_back(std::make_pair("BrowsePath", elementTree));
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, attributeId_))
        {
    	     Log(Error, "SimpleAttributeOperand json encoder error")
    		     .parameter("Element", "attributeId_");
           return false;
        }
        pt.push_back(std::make_pair("AttributeId", elementTree));
    
        elementTree.clear();
        if (!indexRange_.jsonEncode(elementTree))
        {
    	     Log(Error, "SimpleAttributeOperand json encoder error")
    		     .parameter("Element", "indexRange_");
            return false;
        }
        pt.push_back(std::make_pair("IndexRange", elementTree));
    
        return true;
    }
    
    bool
    SimpleAttributeOperand::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        std::string elementName;
        boost::optional<const boost::property_tree::ptree&> tree;
    
        elementName = "TypeDefinitionId";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SimpleAttributeOperand decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!typeDefinitionId_.jsonDecode(*tree)) {
            Log(Error, "SimpleAttributeOperand decode json error - decode failed")
                .parameter("Element", "TypeDefinitionId");
            return false;
        }
    
        elementName = "BrowsePath";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SimpleAttributeOperand decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!browsePath_.jsonDecode(*tree, "")) {
            Log(Error, "SimpleAttributeOperand decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "AttributeId";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SimpleAttributeOperand decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, attributeId_)) {
            Log(Error, "SimpleAttributeOperand decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "IndexRange";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SimpleAttributeOperand decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!indexRange_.jsonDecode(*tree)) {
            Log(Error, "SimpleAttributeOperand decode json error - decode failed")
                .parameter("Element", "IndexRange");
            return false;
        }
    
        return true;
    }
    
    void
    SimpleAttributeOperand::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	SimpleAttributeOperand* dst = dynamic_cast<SimpleAttributeOperand*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    SimpleAttributeOperand::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	SimpleAttributeOperand* dst = dynamic_cast<SimpleAttributeOperand*>(&extensionObjectBase);
    	return *const_cast<SimpleAttributeOperand*>(this) == *dst;
    }
    
    void
    SimpleAttributeOperand::out(std::ostream& os)
    {
        os << "TypeDefinitionId="; typeDefinitionId_.out(os);
        os << ", BrowsePath="; browsePath_.out(os);
        os << ", AttributeId=" << attributeId_;
        os << ", IndexRange="; indexRange_.out(os);
    }

}
