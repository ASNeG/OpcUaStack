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
    NodeAttributes::encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const
    {
    }
    
    bool
    NodeAttributes::decode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
    }
    
    bool
    NodeAttributes::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    NodeAttributes::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, specifiedAttributes_)) return false;
        pt.push_back(std::make_pair("SpecifiedAttributes", elementTree));
    
        elementTree.clear();
        if (!displayName_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("DisplayName", elementTree));
    
        elementTree.clear();
        if (!description_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("Description", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, writeMask_)) return false;
        pt.push_back(std::make_pair("WriteMask", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, userWriteMask_)) return false;
        pt.push_back(std::make_pair("UserWriteMask", elementTree));
    
        return true;
    }
    
    bool
    NodeAttributes::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(element);
        if (!tree) return false;
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    NodeAttributes::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree;
    
        tree = pt.get_child_optional("SpecifiedAttributes");
        if (!tree) return false;
        if(!XmlNumber::xmlDecode(*tree, specifiedAttributes_)) return false;
    
        tree = pt.get_child_optional("DisplayName");
        if (!tree) return false;
        if (!displayName_.xmlDecode(*tree, xmlns)) return false;
    
        tree = pt.get_child_optional("Description");
        if (!tree) return false;
        if (!description_.xmlDecode(*tree, xmlns)) return false;
    
        tree = pt.get_child_optional("WriteMask");
        if (!tree) return false;
        if(!XmlNumber::xmlDecode(*tree, writeMask_)) return false;
    
        tree = pt.get_child_optional("UserWriteMask");
        if (!tree) return false;
        if(!XmlNumber::xmlDecode(*tree, userWriteMask_)) return false;
    
        return true;
    }
    
    bool
    NodeAttributes::jsonEncode(boost::property_tree::ptree& pt, const std::string& element)
    {
        return true;
    }
    
    bool
    NodeAttributes::jsonEncode(boost::property_tree::ptree& pt)
    {
        return true;
    }
    
    bool
    NodeAttributes::jsonDecode(boost::property_tree::ptree& pt, const std::string& element)
    {
    }
    
    bool
    NodeAttributes::jsonDecode(boost::property_tree::ptree& pt)
    {
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
