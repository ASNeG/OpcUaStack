/*
    DataTypeClass: AddReferencesItem

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/AddReferencesItem.h"

namespace OpcUaStackCore
{
    
    /**
     * A request to add a reference to the server address space.
     */
    AddReferencesItem::AddReferencesItem(void)
    : Object()
    , ExtensionObjectBase()
    , sourceNodeId_()
    , referenceTypeId_()
    , isForward_()
    , targetServerUri_()
    , targetNodeId_()
    , targetNodeClass_()
    {
    }
    
    /**
     * A request to add a reference to the server address space.
     */
    AddReferencesItem::AddReferencesItem(const AddReferencesItem& value)
    : Object()
    , ExtensionObjectBase()
    , sourceNodeId_()
    , referenceTypeId_()
    , isForward_()
    , targetServerUri_()
    , targetNodeId_()
    , targetNodeClass_()
    {
        const_cast<AddReferencesItem*>(&value)->copyTo(*this);
    }
    
    AddReferencesItem::~AddReferencesItem(void)
    {
    }
    
    OpcUaNodeId&
    AddReferencesItem::sourceNodeId(void)
    {
        return sourceNodeId_;
    }
    
    OpcUaNodeId&
    AddReferencesItem::referenceTypeId(void)
    {
        return referenceTypeId_;
    }
    
    OpcUaBoolean&
    AddReferencesItem::isForward(void)
    {
        return isForward_;
    }
    
    OpcUaString&
    AddReferencesItem::targetServerUri(void)
    {
        return targetServerUri_;
    }
    
    OpcUaExpandedNodeId&
    AddReferencesItem::targetNodeId(void)
    {
        return targetNodeId_;
    }
    
    NodeClass&
    AddReferencesItem::targetNodeClass(void)
    {
        return targetNodeClass_;
    }
    
    bool
    AddReferencesItem::operator==(const AddReferencesItem& value)
    {
        AddReferencesItem* dst = const_cast<AddReferencesItem*>(&value);
        if (sourceNodeId_ != dst->sourceNodeId()) return false;
        if (referenceTypeId_ != dst->referenceTypeId()) return false;
        if (isForward_ != dst->isForward()) return false;
        if (targetServerUri_ != dst->targetServerUri()) return false;
        if (targetNodeId_ != dst->targetNodeId()) return false;
        if (targetNodeClass_ != dst->targetNodeClass()) return false;
        return true;
    }
    
    bool
    AddReferencesItem::operator!=(const AddReferencesItem& value)
    {
        return !this->operator==(value);
    }
    
    void
    AddReferencesItem::copyTo(AddReferencesItem& value)
    {
        sourceNodeId_.copyTo(value.sourceNodeId());
        referenceTypeId_.copyTo(value.referenceTypeId());
        value.isForward_ = isForward_;
        targetServerUri_.copyTo(value.targetServerUri());
        targetNodeId_.copyTo(value.targetNodeId());
        targetNodeClass_.copyTo(value.targetNodeClass());
    }
    
    AddReferencesItem&
    AddReferencesItem::operator=(const AddReferencesItem& value)
    {
        const_cast<AddReferencesItem*>(&value)->copyTo(*this);
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
    AddReferencesItem::factory(void)
    {
    	return constructSPtr<AddReferencesItem>();
    }
    
    std::string
    AddReferencesItem::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    AddReferencesItem::typeName(void)
    {
    	return "AddReferencesItem";
    }
    
    OpcUaNodeId
    AddReferencesItem::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)379,0);
    }
    
    OpcUaNodeId
    AddReferencesItem::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)381, 0);
    }
    
    OpcUaNodeId
    AddReferencesItem::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)380, 0);
    }
    
    OpcUaNodeId
    AddReferencesItem::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15169, 0);
    }
    
    void
    AddReferencesItem::opcUaBinaryEncode(std::ostream& os) const
    {
        sourceNodeId_.opcUaBinaryEncode(os);
        referenceTypeId_.opcUaBinaryEncode(os);
        OpcUaNumber::opcUaBinaryEncode(os,isForward_);
        targetServerUri_.opcUaBinaryEncode(os);
        targetNodeId_.opcUaBinaryEncode(os);
        targetNodeClass_.opcUaBinaryEncode(os);
    }
    
    void
    AddReferencesItem::opcUaBinaryDecode(std::istream& is)
    {
        sourceNodeId_.opcUaBinaryDecode(is);
        referenceTypeId_.opcUaBinaryDecode(is);
        OpcUaNumber::opcUaBinaryDecode(is,isForward_);
        targetServerUri_.opcUaBinaryDecode(is);
        targetNodeId_.opcUaBinaryDecode(is);
        targetNodeClass_.opcUaBinaryDecode(is);
    }
    
    bool
    AddReferencesItem::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "AddReferencesItem encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    AddReferencesItem::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!sourceNodeId_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "AddReferencesItem encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("SourceNodeId", elementTree));
    
        elementTree.clear();
        if (!referenceTypeId_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "AddReferencesItem encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("ReferenceTypeId", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, isForward_))
        {
            Log(Error, "AddReferencesItem encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("IsForward", elementTree));
    
        elementTree.clear();
        if (!targetServerUri_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "AddReferencesItem encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("TargetServerUri", elementTree));
    
        elementTree.clear();
        if (!targetNodeId_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "AddReferencesItem encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("TargetNodeId", elementTree));
    
        elementTree.clear();
        if (!targetNodeClass_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "AddReferencesItem encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("TargetNodeClass", elementTree));
    
        return true;
    }
    
    bool
    AddReferencesItem::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "AddReferencesItem decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    AddReferencesItem::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        elementName = xmlns.addPrefix("SourceNodeId");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "AddReferencesItem decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!sourceNodeId_.xmlDecode(*tree, xmlns)) {
            Log(Error, "AddReferencesItem decode xml error - decode failed")
                .parameter("Element", "SourceNodeId");
            return false;
        }
    
        elementName = xmlns.addPrefix("ReferenceTypeId");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "AddReferencesItem decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!referenceTypeId_.xmlDecode(*tree, xmlns)) {
            Log(Error, "AddReferencesItem decode xml error - decode failed")
                .parameter("Element", "ReferenceTypeId");
            return false;
        }
    
        elementName = xmlns.addPrefix("IsForward");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "AddReferencesItem decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, isForward_)) {
            Log(Error, "AddReferencesItem decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("TargetServerUri");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "AddReferencesItem decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!targetServerUri_.xmlDecode(*tree, xmlns)) {
            Log(Error, "AddReferencesItem decode xml error - decode failed")
                .parameter("Element", "TargetServerUri");
            return false;
        }
    
        elementName = xmlns.addPrefix("TargetNodeId");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "AddReferencesItem decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!targetNodeId_.xmlDecode(*tree, xmlns)) {
            Log(Error, "AddReferencesItem decode xml error - decode failed")
                .parameter("Element", "TargetNodeId");
            return false;
        }
    
        elementName = xmlns.addPrefix("TargetNodeClass");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "AddReferencesItem decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!targetNodeClass_.xmlDecode(*tree, xmlns)) {
            Log(Error, "AddReferencesItem decode xml error - decode failed")
                .parameter("Element", "TargetNodeClass");
            return false;
        }
    
        return true;
    }
    
    bool
    AddReferencesItem::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!sourceNodeId_.jsonEncode(elementTree))
        {
    	     Log(Error, "AddReferencesItem json encoder error")
    		     .parameter("Element", "sourceNodeId_");
            return false;
        }
        pt.push_back(std::make_pair("SourceNodeId", elementTree));
    
        elementTree.clear();
        if (!referenceTypeId_.jsonEncode(elementTree))
        {
    	     Log(Error, "AddReferencesItem json encoder error")
    		     .parameter("Element", "referenceTypeId_");
            return false;
        }
        pt.push_back(std::make_pair("ReferenceTypeId", elementTree));
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, isForward_))
        {
    	     Log(Error, "AddReferencesItem json encoder error")
    		     .parameter("Element", "isForward_");
           return false;
        }
        pt.push_back(std::make_pair("IsForward", elementTree));
    
        elementTree.clear();
        if (!targetServerUri_.jsonEncode(elementTree))
        {
    	     Log(Error, "AddReferencesItem json encoder error")
    		     .parameter("Element", "targetServerUri_");
            return false;
        }
        pt.push_back(std::make_pair("TargetServerUri", elementTree));
    
        elementTree.clear();
        if (!targetNodeId_.jsonEncode(elementTree))
        {
    	     Log(Error, "AddReferencesItem json encoder error")
    		     .parameter("Element", "targetNodeId_");
            return false;
        }
        pt.push_back(std::make_pair("TargetNodeId", elementTree));
    
        elementTree.clear();
        if (!targetNodeClass_.jsonEncode(elementTree))
        {
    	     Log(Error, "AddReferencesItem json encoder error")
    		     .parameter("Element", "targetNodeClass_");
            return false;
        }
        pt.push_back(std::make_pair("TargetNodeClass", elementTree));
    
        return true;
    }
    
    bool
    AddReferencesItem::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        std::string elementName;
        boost::optional<const boost::property_tree::ptree&> tree;
    
        elementName = "SourceNodeId";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "AddReferencesItem decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!sourceNodeId_.jsonDecode(*tree)) {
            Log(Error, "AddReferencesItem decode json error - decode failed")
                .parameter("Element", "SourceNodeId");
            return false;
        }
    
        elementName = "ReferenceTypeId";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "AddReferencesItem decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!referenceTypeId_.jsonDecode(*tree)) {
            Log(Error, "AddReferencesItem decode json error - decode failed")
                .parameter("Element", "ReferenceTypeId");
            return false;
        }
    
        elementName = "IsForward";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "AddReferencesItem decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, isForward_)) {
            Log(Error, "AddReferencesItem decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "TargetServerUri";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "AddReferencesItem decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!targetServerUri_.jsonDecode(*tree)) {
            Log(Error, "AddReferencesItem decode json error - decode failed")
                .parameter("Element", "TargetServerUri");
            return false;
        }
    
        elementName = "TargetNodeId";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "AddReferencesItem decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!targetNodeId_.jsonDecode(*tree)) {
            Log(Error, "AddReferencesItem decode json error - decode failed")
                .parameter("Element", "TargetNodeId");
            return false;
        }
    
        elementName = "TargetNodeClass";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "AddReferencesItem decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!targetNodeClass_.jsonDecode(*tree)) {
            Log(Error, "AddReferencesItem decode json error - decode failed")
                .parameter("Element", "TargetNodeClass");
            return false;
        }
    
        return true;
    }
    
    void
    AddReferencesItem::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	AddReferencesItem* dst = dynamic_cast<AddReferencesItem*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    AddReferencesItem::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	AddReferencesItem* dst = dynamic_cast<AddReferencesItem*>(&extensionObjectBase);
    	return *const_cast<AddReferencesItem*>(this) == *dst;
    }
    
    void
    AddReferencesItem::out(std::ostream& os)
    {
        os << "SourceNodeId="; sourceNodeId_.out(os);
        os << ", ReferenceTypeId="; referenceTypeId_.out(os);
        os << ", IsForward=" << isForward_;
        os << ", TargetServerUri="; targetServerUri_.out(os);
        os << ", TargetNodeId="; targetNodeId_.out(os);
        os << ", TargetNodeClass="; targetNodeClass_.out(os);
    }

}
