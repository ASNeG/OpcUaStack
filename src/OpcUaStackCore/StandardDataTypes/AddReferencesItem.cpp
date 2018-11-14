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
    AddReferencesItem::encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const
    {
    }
    
    bool
    AddReferencesItem::decode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
    }
    
    bool
    AddReferencesItem::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    AddReferencesItem::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        if (!sourceNodeId_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("SourceNodeId", elementTree));
    
        if (!referenceTypeId_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("ReferenceTypeId", elementTree));
    
        if(!XmlNumber::xmlEncode(elementTree, isForward_)) return false;
        pt.push_back(std::make_pair("IsForward", elementTree));
    
        if (!targetServerUri_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("TargetServerUri", elementTree));
    
        if (!targetNodeId_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("TargetNodeId", elementTree));
    
        if (!targetNodeClass_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("TargetNodeClass", elementTree));
    
        return true;
    }
    
    bool
    AddReferencesItem::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(element);
        if (!tree) return false;
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    AddReferencesItem::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree;
    
        tree = pt.get_child_optional("SourceNodeId");
        if (!tree) return false;
        if (!sourceNodeId_.xmlDecode(*tree, xmlns)) return false;
    
        tree = pt.get_child_optional("ReferenceTypeId");
        if (!tree) return false;
        if (!referenceTypeId_.xmlDecode(*tree, xmlns)) return false;
    
        tree = pt.get_child_optional("IsForward");
        if (!tree) return false;
        if(!XmlNumber::xmlDecode(*tree, isForward_)) return false;
    
        tree = pt.get_child_optional("TargetServerUri");
        if (!tree) return false;
        if (!targetServerUri_.xmlDecode(*tree, xmlns)) return false;
    
        tree = pt.get_child_optional("TargetNodeId");
        if (!tree) return false;
        if (!targetNodeId_.xmlDecode(*tree, xmlns)) return false;
    
        tree = pt.get_child_optional("TargetNodeClass");
        if (!tree) return false;
        if (!targetNodeClass_.xmlDecode(*tree, xmlns)) return false;
    
        return true;
    }
    
    bool
    AddReferencesItem::jsonEncode(boost::property_tree::ptree& pt, const std::string& element)
    {
        return true;
    }
    
    bool
    AddReferencesItem::jsonEncode(boost::property_tree::ptree& pt)
    {
        return true;
    }
    
    bool
    AddReferencesItem::jsonDecode(boost::property_tree::ptree& pt, const std::string& element)
    {
    }
    
    bool
    AddReferencesItem::jsonDecode(boost::property_tree::ptree& pt)
    {
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
