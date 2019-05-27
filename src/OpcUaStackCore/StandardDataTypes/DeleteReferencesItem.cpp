/*
    DataTypeClass: DeleteReferencesItem

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/DeleteReferencesItem.h"

namespace OpcUaStackCore
{
    
    /**
     * A request to delete a node from the server address space.
     */
    DeleteReferencesItem::DeleteReferencesItem(void)
    : Object()
    , ExtensionObjectBase()
    , sourceNodeId_()
    , referenceTypeId_()
    , isForward_()
    , targetNodeId_()
    , deleteBidirectional_()
    {
    }
    
    /**
     * A request to delete a node from the server address space.
     */
    DeleteReferencesItem::DeleteReferencesItem(const DeleteReferencesItem& value)
    : Object()
    , ExtensionObjectBase()
    , sourceNodeId_()
    , referenceTypeId_()
    , isForward_()
    , targetNodeId_()
    , deleteBidirectional_()
    {
        const_cast<DeleteReferencesItem*>(&value)->copyTo(*this);
    }
    
    DeleteReferencesItem::~DeleteReferencesItem(void)
    {
    }
    
    OpcUaNodeId&
    DeleteReferencesItem::sourceNodeId(void)
    {
        return sourceNodeId_;
    }
    
    OpcUaNodeId&
    DeleteReferencesItem::referenceTypeId(void)
    {
        return referenceTypeId_;
    }
    
    OpcUaBoolean&
    DeleteReferencesItem::isForward(void)
    {
        return isForward_;
    }
    
    OpcUaExpandedNodeId&
    DeleteReferencesItem::targetNodeId(void)
    {
        return targetNodeId_;
    }
    
    OpcUaBoolean&
    DeleteReferencesItem::deleteBidirectional(void)
    {
        return deleteBidirectional_;
    }
    
    bool
    DeleteReferencesItem::operator==(const DeleteReferencesItem& value)
    {
        DeleteReferencesItem* dst = const_cast<DeleteReferencesItem*>(&value);
        if (sourceNodeId_ != dst->sourceNodeId()) return false;
        if (referenceTypeId_ != dst->referenceTypeId()) return false;
        if (isForward_ != dst->isForward()) return false;
        if (targetNodeId_ != dst->targetNodeId()) return false;
        if (deleteBidirectional_ != dst->deleteBidirectional()) return false;
        return true;
    }
    
    bool
    DeleteReferencesItem::operator!=(const DeleteReferencesItem& value)
    {
        return !this->operator==(value);
    }
    
    void
    DeleteReferencesItem::copyTo(DeleteReferencesItem& value)
    {
        sourceNodeId_.copyTo(value.sourceNodeId());
        referenceTypeId_.copyTo(value.referenceTypeId());
        value.isForward_ = isForward_;
        targetNodeId_.copyTo(value.targetNodeId());
        value.deleteBidirectional_ = deleteBidirectional_;
    }
    
    DeleteReferencesItem&
    DeleteReferencesItem::operator=(const DeleteReferencesItem& value)
    {
        const_cast<DeleteReferencesItem*>(&value)->copyTo(*this);
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
    DeleteReferencesItem::factory(void)
    {
    	return constructSPtr<DeleteReferencesItem>();
    }
    
    std::string
    DeleteReferencesItem::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    DeleteReferencesItem::typeName(void)
    {
    	return "DeleteReferencesItem";
    }
    
    OpcUaNodeId
    DeleteReferencesItem::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)385,0);
    }
    
    OpcUaNodeId
    DeleteReferencesItem::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)387, 0);
    }
    
    OpcUaNodeId
    DeleteReferencesItem::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)386, 0);
    }
    
    OpcUaNodeId
    DeleteReferencesItem::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15175, 0);
    }
    
    void
    DeleteReferencesItem::opcUaBinaryEncode(std::ostream& os) const
    {
        sourceNodeId_.opcUaBinaryEncode(os);
        referenceTypeId_.opcUaBinaryEncode(os);
        OpcUaNumber::opcUaBinaryEncode(os,isForward_);
        targetNodeId_.opcUaBinaryEncode(os);
        OpcUaNumber::opcUaBinaryEncode(os,deleteBidirectional_);
    }
    
    void
    DeleteReferencesItem::opcUaBinaryDecode(std::istream& is)
    {
        sourceNodeId_.opcUaBinaryDecode(is);
        referenceTypeId_.opcUaBinaryDecode(is);
        OpcUaNumber::opcUaBinaryDecode(is,isForward_);
        targetNodeId_.opcUaBinaryDecode(is);
        OpcUaNumber::opcUaBinaryDecode(is,deleteBidirectional_);
    }
    
    bool
    DeleteReferencesItem::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "DeleteReferencesItem encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    DeleteReferencesItem::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!sourceNodeId_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "DeleteReferencesItem encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("SourceNodeId", elementTree));
    
        elementTree.clear();
        if (!referenceTypeId_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "DeleteReferencesItem encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("ReferenceTypeId", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, isForward_))
        {
            Log(Error, "DeleteReferencesItem encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("IsForward", elementTree));
    
        elementTree.clear();
        if (!targetNodeId_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "DeleteReferencesItem encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("TargetNodeId", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, deleteBidirectional_))
        {
            Log(Error, "DeleteReferencesItem encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("DeleteBidirectional", elementTree));
    
        return true;
    }
    
    bool
    DeleteReferencesItem::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "DeleteReferencesItem decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    DeleteReferencesItem::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        elementName = xmlns.addPrefix("SourceNodeId");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "DeleteReferencesItem decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!sourceNodeId_.xmlDecode(*tree, xmlns)) {
            Log(Error, "DeleteReferencesItem decode xml error - decode failed")
                .parameter("Element", "SourceNodeId");
            return false;
        }
    
        elementName = xmlns.addPrefix("ReferenceTypeId");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "DeleteReferencesItem decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!referenceTypeId_.xmlDecode(*tree, xmlns)) {
            Log(Error, "DeleteReferencesItem decode xml error - decode failed")
                .parameter("Element", "ReferenceTypeId");
            return false;
        }
    
        elementName = xmlns.addPrefix("IsForward");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "DeleteReferencesItem decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, isForward_)) {
            Log(Error, "DeleteReferencesItem decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("TargetNodeId");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "DeleteReferencesItem decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!targetNodeId_.xmlDecode(*tree, xmlns)) {
            Log(Error, "DeleteReferencesItem decode xml error - decode failed")
                .parameter("Element", "TargetNodeId");
            return false;
        }
    
        elementName = xmlns.addPrefix("DeleteBidirectional");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "DeleteReferencesItem decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, deleteBidirectional_)) {
            Log(Error, "DeleteReferencesItem decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    bool
    DeleteReferencesItem::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!sourceNodeId_.jsonEncode(elementTree))
        {
    	     Log(Error, "DeleteReferencesItem json encoder error")
    		     .parameter("Element", "sourceNodeId_");
            return false;
        }
        pt.push_back(std::make_pair("SourceNodeId", elementTree));
    
        elementTree.clear();
        if (!referenceTypeId_.jsonEncode(elementTree))
        {
    	     Log(Error, "DeleteReferencesItem json encoder error")
    		     .parameter("Element", "referenceTypeId_");
            return false;
        }
        pt.push_back(std::make_pair("ReferenceTypeId", elementTree));
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, isForward_))
        {
    	     Log(Error, "DeleteReferencesItem json encoder error")
    		     .parameter("Element", "isForward_");
           return false;
        }
        pt.push_back(std::make_pair("IsForward", elementTree));
    
        elementTree.clear();
        if (!targetNodeId_.jsonEncode(elementTree))
        {
    	     Log(Error, "DeleteReferencesItem json encoder error")
    		     .parameter("Element", "targetNodeId_");
            return false;
        }
        pt.push_back(std::make_pair("TargetNodeId", elementTree));
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, deleteBidirectional_))
        {
    	     Log(Error, "DeleteReferencesItem json encoder error")
    		     .parameter("Element", "deleteBidirectional_");
           return false;
        }
        pt.push_back(std::make_pair("DeleteBidirectional", elementTree));
    
        return true;
    }
    
    bool
    DeleteReferencesItem::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        std::string elementName;
        boost::optional<const boost::property_tree::ptree&> tree;
    
        elementName = "SourceNodeId";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "DeleteReferencesItem decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!sourceNodeId_.jsonDecode(*tree)) {
            Log(Error, "DeleteReferencesItem decode json error - decode failed")
                .parameter("Element", "SourceNodeId");
            return false;
        }
    
        elementName = "ReferenceTypeId";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "DeleteReferencesItem decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!referenceTypeId_.jsonDecode(*tree)) {
            Log(Error, "DeleteReferencesItem decode json error - decode failed")
                .parameter("Element", "ReferenceTypeId");
            return false;
        }
    
        elementName = "IsForward";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "DeleteReferencesItem decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, isForward_)) {
            Log(Error, "DeleteReferencesItem decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "TargetNodeId";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "DeleteReferencesItem decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!targetNodeId_.jsonDecode(*tree)) {
            Log(Error, "DeleteReferencesItem decode json error - decode failed")
                .parameter("Element", "TargetNodeId");
            return false;
        }
    
        elementName = "DeleteBidirectional";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "DeleteReferencesItem decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, deleteBidirectional_)) {
            Log(Error, "DeleteReferencesItem decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    void
    DeleteReferencesItem::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	DeleteReferencesItem* dst = dynamic_cast<DeleteReferencesItem*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    DeleteReferencesItem::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	DeleteReferencesItem* dst = dynamic_cast<DeleteReferencesItem*>(&extensionObjectBase);
    	return *const_cast<DeleteReferencesItem*>(this) == *dst;
    }
    
    void
    DeleteReferencesItem::out(std::ostream& os)
    {
        os << "SourceNodeId="; sourceNodeId_.out(os);
        os << ", ReferenceTypeId="; referenceTypeId_.out(os);
        os << ", IsForward=" << isForward_;
        os << ", TargetNodeId="; targetNodeId_.out(os);
        os << ", DeleteBidirectional=" << deleteBidirectional_;
    }

}
