/*
    DataTypeClass: AddNodesItem

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/AddNodesItem.h"

namespace OpcUaStackCore
{
    
    /**
     * A request to add a node to the server address space.
     */
    AddNodesItem::AddNodesItem(void)
    : Object()
    , ExtensionObjectBase()
    , parentNodeId_()
    , referenceTypeId_()
    , requestedNewNodeId_()
    , browseName_()
    , nodeClass_()
    , nodeAttributes_()
    , typeDefinition_()
    {
    }
    
    AddNodesItem::~AddNodesItem(void)
    {
    }
    
    OpcUaExpandedNodeId&
    AddNodesItem::parentNodeId(void)
    {
        return parentNodeId_;
    }
    
    OpcUaNodeId&
    AddNodesItem::referenceTypeId(void)
    {
        return referenceTypeId_;
    }
    
    OpcUaExpandedNodeId&
    AddNodesItem::requestedNewNodeId(void)
    {
        return requestedNewNodeId_;
    }
    
    OpcUaQualifiedName&
    AddNodesItem::browseName(void)
    {
        return browseName_;
    }
    
    NodeClass&
    AddNodesItem::nodeClass(void)
    {
        return nodeClass_;
    }
    
    OpcUaExtensibleParameter&
    AddNodesItem::nodeAttributes(void)
    {
        return nodeAttributes_;
    }
    
    OpcUaExpandedNodeId&
    AddNodesItem::typeDefinition(void)
    {
        return typeDefinition_;
    }
    
    bool
    AddNodesItem::operator==(const AddNodesItem& value)
    {
        AddNodesItem* dst = const_cast<AddNodesItem*>(&value);
        if (parentNodeId_ != dst->parentNodeId()) return false;
        if (referenceTypeId_ != dst->referenceTypeId()) return false;
        if (requestedNewNodeId_ != dst->requestedNewNodeId()) return false;
        if (browseName_ != dst->browseName()) return false;
        if (nodeClass_ != dst->nodeClass()) return false;
        if (nodeAttributes_ != dst->nodeAttributes()) return false;
        if (typeDefinition_ != dst->typeDefinition()) return false;
        return true;
    }
    
    bool
    AddNodesItem::operator!=(const AddNodesItem& value)
    {
        return !this->operator==(value);
    }
    
    void
    AddNodesItem::copyTo(AddNodesItem& value)
    {
        parentNodeId_.copyTo(value.parentNodeId());
        referenceTypeId_.copyTo(value.referenceTypeId());
        requestedNewNodeId_.copyTo(value.requestedNewNodeId());
        browseName_.copyTo(value.browseName());
        nodeClass_.copyTo(value.nodeClass());
        nodeAttributes_.copyTo(value.nodeAttributes());
        typeDefinition_.copyTo(value.typeDefinition());
    }
    
    AddNodesItem&
    AddNodesItem::operator=(const AddNodesItem& value)
    {
        const_cast<AddNodesItem*>(&value)->copyTo(*this);
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
    AddNodesItem::factory(void)
    {
    	return constructSPtr<AddNodesItem>();
    }
    
    std::string
    AddNodesItem::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    AddNodesItem::typeName(void)
    {
    	return "AddNodesItem";
    }
    
    OpcUaNodeId
    AddNodesItem::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)376,0);
    }
    
    OpcUaNodeId
    AddNodesItem::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)378, 0);
    }
    
    OpcUaNodeId
    AddNodesItem::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)377, 0);
    }
    
    OpcUaNodeId
    AddNodesItem::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15165, 0);
    }
    
    void
    AddNodesItem::opcUaBinaryEncode(std::ostream& os) const
    {
        parentNodeId_.opcUaBinaryEncode(os);
        referenceTypeId_.opcUaBinaryEncode(os);
        requestedNewNodeId_.opcUaBinaryEncode(os);
        browseName_.opcUaBinaryEncode(os);
        nodeClass_.opcUaBinaryEncode(os);
        nodeAttributes_.opcUaBinaryEncode(os);
        typeDefinition_.opcUaBinaryEncode(os);
    }
    
    void
    AddNodesItem::opcUaBinaryDecode(std::istream& is)
    {
        parentNodeId_.opcUaBinaryDecode(is);
        referenceTypeId_.opcUaBinaryDecode(is);
        requestedNewNodeId_.opcUaBinaryDecode(is);
        browseName_.opcUaBinaryDecode(is);
        nodeClass_.opcUaBinaryDecode(is);
        nodeAttributes_.opcUaBinaryDecode(is);
        typeDefinition_.opcUaBinaryDecode(is);
    }
    
    bool
    AddNodesItem::encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const
    {
    }
    
    bool
    AddNodesItem::decode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
    }
    
    bool
    AddNodesItem::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    AddNodesItem::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        if (!parentNodeId_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("ParentNodeId", elementTree));
    
        if (!referenceTypeId_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("ReferenceTypeId", elementTree));
    
        if (!requestedNewNodeId_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("RequestedNewNodeId", elementTree));
    
        if (!browseName_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("BrowseName", elementTree));
    
        if (!nodeClass_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("NodeClass", elementTree));
    
        if (!nodeAttributes_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("NodeAttributes", elementTree));
    
        if (!typeDefinition_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("TypeDefinition", elementTree));
    
        return true;
    }
    
    bool
    AddNodesItem::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(element);
        if (!tree) return false;
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    AddNodesItem::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree;
    
        tree = pt.get_child_optional("ParentNodeId");
        if (!tree) return false;
        if (!parentNodeId_.xmlDecode(*tree, xmlns)) return false;
    
        tree = pt.get_child_optional("ReferenceTypeId");
        if (!tree) return false;
        if (!referenceTypeId_.xmlDecode(*tree, xmlns)) return false;
    
        tree = pt.get_child_optional("RequestedNewNodeId");
        if (!tree) return false;
        if (!requestedNewNodeId_.xmlDecode(*tree, xmlns)) return false;
    
        tree = pt.get_child_optional("BrowseName");
        if (!tree) return false;
        if (!browseName_.xmlDecode(*tree, xmlns)) return false;
    
        tree = pt.get_child_optional("NodeClass");
        if (!tree) return false;
        if (!nodeClass_.xmlDecode(*tree, xmlns)) return false;
    
        tree = pt.get_child_optional("NodeAttributes");
        if (!tree) return false;
        if (!nodeAttributes_.xmlDecode(*tree, xmlns)) return false;
    
        tree = pt.get_child_optional("TypeDefinition");
        if (!tree) return false;
        if (!typeDefinition_.xmlDecode(*tree, xmlns)) return false;
    
        return true;
    }
    
    bool
    AddNodesItem::jsonEncode(boost::property_tree::ptree& pt, const std::string& element)
    {
        return true;
    }
    
    bool
    AddNodesItem::jsonEncode(boost::property_tree::ptree& pt)
    {
        return true;
    }
    
    bool
    AddNodesItem::jsonDecode(boost::property_tree::ptree& pt, const std::string& element)
    {
    }
    
    bool
    AddNodesItem::jsonDecode(boost::property_tree::ptree& pt)
    {
    }
    
    void
    AddNodesItem::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	AddNodesItem* dst = dynamic_cast<AddNodesItem*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    AddNodesItem::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	AddNodesItem* dst = dynamic_cast<AddNodesItem*>(&extensionObjectBase);
    	return *const_cast<AddNodesItem*>(this) == *dst;
    }
    
    void
    AddNodesItem::out(std::ostream& os)
    {
        os << "ParentNodeId="; parentNodeId_.out(os);
        os << ", ReferenceTypeId="; referenceTypeId_.out(os);
        os << ", RequestedNewNodeId="; requestedNewNodeId_.out(os);
        os << ", BrowseName="; browseName_.out(os);
        os << ", NodeClass="; nodeClass_.out(os);
        os << ", NodeAttributes="; nodeAttributes_.out(os);
        os << ", TypeDefinition="; typeDefinition_.out(os);
    }

}
