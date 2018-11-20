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
        typeDefinitionId_.opcUaBinaryEncode(os);
        browsePath_.opcUaBinaryEncode(os);
        OpcUaNumber::opcUaBinaryEncode(os,attributeId_);
        indexRange_.opcUaBinaryEncode(os);
    }
    
    void
    SimpleAttributeOperand::opcUaBinaryDecode(std::istream& is)
    {
        typeDefinitionId_.opcUaBinaryDecode(is);
        browsePath_.opcUaBinaryDecode(is);
        OpcUaNumber::opcUaBinaryDecode(is,attributeId_);
        indexRange_.opcUaBinaryDecode(is);
    }
    
    bool
    SimpleAttributeOperand::encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const
    {
    }
    
    bool
    SimpleAttributeOperand::decode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
    }
    
    bool
    SimpleAttributeOperand::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    SimpleAttributeOperand::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!typeDefinitionId_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("TypeDefinitionId", elementTree));
    
        elementTree.clear();
        if (!browsePath_.xmlEncode(elementTree, "QualifiedName", xmlns)) return false;
        pt.push_back(std::make_pair("BrowsePath", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, attributeId_)) return false;
        pt.push_back(std::make_pair("AttributeId", elementTree));
    
        elementTree.clear();
        if (!indexRange_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("IndexRange", elementTree));
    
        return true;
    }
    
    bool
    SimpleAttributeOperand::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(element);
        if (!tree) return false;
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    SimpleAttributeOperand::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree;
    
        tree = pt.get_child_optional("TypeDefinitionId");
        if (!tree) return false;
        if (!typeDefinitionId_.xmlDecode(*tree, xmlns)) return false;
    
        tree = pt.get_child_optional("BrowsePath");
        if (!tree) return false;
        if (!browsePath_.xmlDecode(*tree, "QualifiedName", xmlns)) return false;
    
        tree = pt.get_child_optional("AttributeId");
        if (!tree) return false;
        if(!XmlNumber::xmlDecode(*tree, attributeId_)) return false;
    
        tree = pt.get_child_optional("IndexRange");
        if (!tree) return false;
        if (!indexRange_.xmlDecode(*tree, xmlns)) return false;
    
        return true;
    }
    
    bool
    SimpleAttributeOperand::jsonEncode(boost::property_tree::ptree& pt, const std::string& element)
    {
        return true;
    }
    
    bool
    SimpleAttributeOperand::jsonEncode(boost::property_tree::ptree& pt)
    {
        return true;
    }
    
    bool
    SimpleAttributeOperand::jsonDecode(boost::property_tree::ptree& pt, const std::string& element)
    {
    }
    
    bool
    SimpleAttributeOperand::jsonDecode(boost::property_tree::ptree& pt)
    {
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
