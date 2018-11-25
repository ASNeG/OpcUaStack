/*
    DataTypeClass: ReferenceTypeAttributes

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/ReferenceTypeAttributes.h"

namespace OpcUaStackCore
{
    
    /**
     * The attributes for a reference type node.
     */
    ReferenceTypeAttributes::ReferenceTypeAttributes(void)
    : NodeAttributes()
    , isAbstract_()
    , symmetric_()
    , inverseName_()
    {
    }
    
    ReferenceTypeAttributes::~ReferenceTypeAttributes(void)
    {
    }
    
    OpcUaBoolean&
    ReferenceTypeAttributes::isAbstract(void)
    {
        return isAbstract_;
    }
    
    OpcUaBoolean&
    ReferenceTypeAttributes::symmetric(void)
    {
        return symmetric_;
    }
    
    OpcUaLocalizedText&
    ReferenceTypeAttributes::inverseName(void)
    {
        return inverseName_;
    }
    
    bool
    ReferenceTypeAttributes::operator==(const ReferenceTypeAttributes& value)
    {
        ReferenceTypeAttributes* dst = const_cast<ReferenceTypeAttributes*>(&value);
        if (isAbstract_ != dst->isAbstract()) return false;
        if (symmetric_ != dst->symmetric()) return false;
        if (inverseName_ != dst->inverseName()) return false;
        return true;
    }
    
    bool
    ReferenceTypeAttributes::operator!=(const ReferenceTypeAttributes& value)
    {
        return !this->operator==(value);
    }
    
    void
    ReferenceTypeAttributes::copyTo(ReferenceTypeAttributes& value)
    {
        value.isAbstract_ = isAbstract_;
        value.symmetric_ = symmetric_;
        inverseName_.copyTo(value.inverseName());
    }
    
    ReferenceTypeAttributes&
    ReferenceTypeAttributes::operator=(const ReferenceTypeAttributes& value)
    {
        const_cast<ReferenceTypeAttributes*>(&value)->copyTo(*this);
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
    ReferenceTypeAttributes::factory(void)
    {
    	return constructSPtr<ReferenceTypeAttributes>();
    }
    
    std::string
    ReferenceTypeAttributes::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    ReferenceTypeAttributes::typeName(void)
    {
    	return "ReferenceTypeAttributes";
    }
    
    OpcUaNodeId
    ReferenceTypeAttributes::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)367,0);
    }
    
    OpcUaNodeId
    ReferenceTypeAttributes::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)369, 0);
    }
    
    OpcUaNodeId
    ReferenceTypeAttributes::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)368, 0);
    }
    
    OpcUaNodeId
    ReferenceTypeAttributes::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15160, 0);
    }
    
    void
    ReferenceTypeAttributes::opcUaBinaryEncode(std::ostream& os) const
    {
        NodeAttributes::opcUaBinaryEncode(os);
        OpcUaNumber::opcUaBinaryEncode(os,isAbstract_);
        OpcUaNumber::opcUaBinaryEncode(os,symmetric_);
        inverseName_.opcUaBinaryEncode(os);
    }
    
    void
    ReferenceTypeAttributes::opcUaBinaryDecode(std::istream& is)
    {
        NodeAttributes::opcUaBinaryDecode(is);
        OpcUaNumber::opcUaBinaryDecode(is,isAbstract_);
        OpcUaNumber::opcUaBinaryDecode(is,symmetric_);
        inverseName_.opcUaBinaryDecode(is);
    }
    
    bool
    ReferenceTypeAttributes::encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const
    {
    }
    
    bool
    ReferenceTypeAttributes::decode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
    }
    
    bool
    ReferenceTypeAttributes::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    ReferenceTypeAttributes::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, isAbstract_)) return false;
        pt.push_back(std::make_pair("IsAbstract", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, symmetric_)) return false;
        pt.push_back(std::make_pair("Symmetric", elementTree));
    
        elementTree.clear();
        if (!inverseName_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("InverseName", elementTree));
    
        return true;
    }
    
    bool
    ReferenceTypeAttributes::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(element);
        if (!tree) return false;
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    ReferenceTypeAttributes::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree;
    
        tree = pt.get_child_optional("IsAbstract");
        if (!tree) return false;
        if(!XmlNumber::xmlDecode(*tree, isAbstract_)) return false;
    
        tree = pt.get_child_optional("Symmetric");
        if (!tree) return false;
        if(!XmlNumber::xmlDecode(*tree, symmetric_)) return false;
    
        tree = pt.get_child_optional("InverseName");
        if (!tree) return false;
        if (!inverseName_.xmlDecode(*tree, xmlns)) return false;
    
        return true;
    }
    
    bool
    ReferenceTypeAttributes::jsonEncode(boost::property_tree::ptree& pt, const std::string& element)
    {
        return true;
    }
    
    bool
    ReferenceTypeAttributes::jsonEncode(boost::property_tree::ptree& pt)
    {
        return true;
    }
    
    bool
    ReferenceTypeAttributes::jsonDecode(boost::property_tree::ptree& pt, const std::string& element)
    {
    }
    
    bool
    ReferenceTypeAttributes::jsonDecode(boost::property_tree::ptree& pt)
    {
    }
    
    void
    ReferenceTypeAttributes::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	ReferenceTypeAttributes* dst = dynamic_cast<ReferenceTypeAttributes*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    ReferenceTypeAttributes::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	ReferenceTypeAttributes* dst = dynamic_cast<ReferenceTypeAttributes*>(&extensionObjectBase);
    	return *const_cast<ReferenceTypeAttributes*>(this) == *dst;
    }
    
    void
    ReferenceTypeAttributes::out(std::ostream& os)
    {
        os << "IsAbstract=" << isAbstract_;
        os << ", Symmetric=" << symmetric_;
        os << ", InverseName="; inverseName_.out(os);
    }

}
