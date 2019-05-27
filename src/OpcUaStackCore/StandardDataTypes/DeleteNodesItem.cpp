/*
    DataTypeClass: DeleteNodesItem

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/DeleteNodesItem.h"

namespace OpcUaStackCore
{
    
    /**
     * A request to delete a node to the server address space.
     */
    DeleteNodesItem::DeleteNodesItem(void)
    : Object()
    , ExtensionObjectBase()
    , nodeId_()
    , deleteTargetReferences_()
    {
    }
    
    /**
     * A request to delete a node to the server address space.
     */
    DeleteNodesItem::DeleteNodesItem(const DeleteNodesItem& value)
    : Object()
    , ExtensionObjectBase()
    , nodeId_()
    , deleteTargetReferences_()
    {
        const_cast<DeleteNodesItem*>(&value)->copyTo(*this);
    }
    
    DeleteNodesItem::~DeleteNodesItem(void)
    {
    }
    
    OpcUaNodeId&
    DeleteNodesItem::nodeId(void)
    {
        return nodeId_;
    }
    
    OpcUaBoolean&
    DeleteNodesItem::deleteTargetReferences(void)
    {
        return deleteTargetReferences_;
    }
    
    bool
    DeleteNodesItem::operator==(const DeleteNodesItem& value)
    {
        DeleteNodesItem* dst = const_cast<DeleteNodesItem*>(&value);
        if (nodeId_ != dst->nodeId()) return false;
        if (deleteTargetReferences_ != dst->deleteTargetReferences()) return false;
        return true;
    }
    
    bool
    DeleteNodesItem::operator!=(const DeleteNodesItem& value)
    {
        return !this->operator==(value);
    }
    
    void
    DeleteNodesItem::copyTo(DeleteNodesItem& value)
    {
        nodeId_.copyTo(value.nodeId());
        value.deleteTargetReferences_ = deleteTargetReferences_;
    }
    
    DeleteNodesItem&
    DeleteNodesItem::operator=(const DeleteNodesItem& value)
    {
        const_cast<DeleteNodesItem*>(&value)->copyTo(*this);
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
    DeleteNodesItem::factory(void)
    {
    	return constructSPtr<DeleteNodesItem>();
    }
    
    std::string
    DeleteNodesItem::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    DeleteNodesItem::typeName(void)
    {
    	return "DeleteNodesItem";
    }
    
    OpcUaNodeId
    DeleteNodesItem::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)382,0);
    }
    
    OpcUaNodeId
    DeleteNodesItem::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)384, 0);
    }
    
    OpcUaNodeId
    DeleteNodesItem::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)383, 0);
    }
    
    OpcUaNodeId
    DeleteNodesItem::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15172, 0);
    }
    
    void
    DeleteNodesItem::opcUaBinaryEncode(std::ostream& os) const
    {
        nodeId_.opcUaBinaryEncode(os);
        OpcUaNumber::opcUaBinaryEncode(os,deleteTargetReferences_);
    }
    
    void
    DeleteNodesItem::opcUaBinaryDecode(std::istream& is)
    {
        nodeId_.opcUaBinaryDecode(is);
        OpcUaNumber::opcUaBinaryDecode(is,deleteTargetReferences_);
    }
    
    bool
    DeleteNodesItem::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "DeleteNodesItem encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    DeleteNodesItem::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!nodeId_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "DeleteNodesItem encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("NodeId", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, deleteTargetReferences_))
        {
            Log(Error, "DeleteNodesItem encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("DeleteTargetReferences", elementTree));
    
        return true;
    }
    
    bool
    DeleteNodesItem::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "DeleteNodesItem decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    DeleteNodesItem::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        elementName = xmlns.addPrefix("NodeId");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "DeleteNodesItem decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!nodeId_.xmlDecode(*tree, xmlns)) {
            Log(Error, "DeleteNodesItem decode xml error - decode failed")
                .parameter("Element", "NodeId");
            return false;
        }
    
        elementName = xmlns.addPrefix("DeleteTargetReferences");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "DeleteNodesItem decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, deleteTargetReferences_)) {
            Log(Error, "DeleteNodesItem decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    bool
    DeleteNodesItem::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!nodeId_.jsonEncode(elementTree))
        {
    	     Log(Error, "DeleteNodesItem json encoder error")
    		     .parameter("Element", "nodeId_");
            return false;
        }
        pt.push_back(std::make_pair("NodeId", elementTree));
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, deleteTargetReferences_))
        {
    	     Log(Error, "DeleteNodesItem json encoder error")
    		     .parameter("Element", "deleteTargetReferences_");
           return false;
        }
        pt.push_back(std::make_pair("DeleteTargetReferences", elementTree));
    
        return true;
    }
    
    bool
    DeleteNodesItem::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        std::string elementName;
        boost::optional<const boost::property_tree::ptree&> tree;
    
        elementName = "NodeId";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "DeleteNodesItem decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!nodeId_.jsonDecode(*tree)) {
            Log(Error, "DeleteNodesItem decode json error - decode failed")
                .parameter("Element", "NodeId");
            return false;
        }
    
        elementName = "DeleteTargetReferences";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "DeleteNodesItem decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, deleteTargetReferences_)) {
            Log(Error, "DeleteNodesItem decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    void
    DeleteNodesItem::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	DeleteNodesItem* dst = dynamic_cast<DeleteNodesItem*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    DeleteNodesItem::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	DeleteNodesItem* dst = dynamic_cast<DeleteNodesItem*>(&extensionObjectBase);
    	return *const_cast<DeleteNodesItem*>(this) == *dst;
    }
    
    void
    DeleteNodesItem::out(std::ostream& os)
    {
        os << "NodeId="; nodeId_.out(os);
        os << ", DeleteTargetReferences=" << deleteTargetReferences_;
    }

}
