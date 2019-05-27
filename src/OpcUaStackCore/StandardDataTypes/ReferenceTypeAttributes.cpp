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
    
    /**
     * The attributes for a reference type node.
     */
    ReferenceTypeAttributes::ReferenceTypeAttributes(const ReferenceTypeAttributes& value)
    : NodeAttributes()
    , isAbstract_()
    , symmetric_()
    , inverseName_()
    {
        const_cast<ReferenceTypeAttributes*>(&value)->copyTo(*this);
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
    ReferenceTypeAttributes::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "ReferenceTypeAttributes encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    ReferenceTypeAttributes::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, isAbstract_))
        {
            Log(Error, "ReferenceTypeAttributes encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("IsAbstract", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, symmetric_))
        {
            Log(Error, "ReferenceTypeAttributes encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("Symmetric", elementTree));
    
        elementTree.clear();
        if (!inverseName_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "ReferenceTypeAttributes encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("InverseName", elementTree));
    
        return true;
    }
    
    bool
    ReferenceTypeAttributes::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ReferenceTypeAttributes decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    ReferenceTypeAttributes::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        elementName = xmlns.addPrefix("IsAbstract");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ReferenceTypeAttributes decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, isAbstract_)) {
            Log(Error, "ReferenceTypeAttributes decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("Symmetric");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ReferenceTypeAttributes decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, symmetric_)) {
            Log(Error, "ReferenceTypeAttributes decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("InverseName");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ReferenceTypeAttributes decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!inverseName_.xmlDecode(*tree, xmlns)) {
            Log(Error, "ReferenceTypeAttributes decode xml error - decode failed")
                .parameter("Element", "InverseName");
            return false;
        }
    
        return true;
    }
    
    bool
    ReferenceTypeAttributes::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, isAbstract_))
        {
    	     Log(Error, "ReferenceTypeAttributes json encoder error")
    		     .parameter("Element", "isAbstract_");
           return false;
        }
        pt.push_back(std::make_pair("IsAbstract", elementTree));
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, symmetric_))
        {
    	     Log(Error, "ReferenceTypeAttributes json encoder error")
    		     .parameter("Element", "symmetric_");
           return false;
        }
        pt.push_back(std::make_pair("Symmetric", elementTree));
    
        elementTree.clear();
        if (!inverseName_.jsonEncode(elementTree))
        {
    	     Log(Error, "ReferenceTypeAttributes json encoder error")
    		     .parameter("Element", "inverseName_");
            return false;
        }
        pt.push_back(std::make_pair("InverseName", elementTree));
    
        return true;
    }
    
    bool
    ReferenceTypeAttributes::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        std::string elementName;
        boost::optional<const boost::property_tree::ptree&> tree;
    
        elementName = "IsAbstract";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ReferenceTypeAttributes decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, isAbstract_)) {
            Log(Error, "ReferenceTypeAttributes decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "Symmetric";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ReferenceTypeAttributes decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, symmetric_)) {
            Log(Error, "ReferenceTypeAttributes decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "InverseName";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ReferenceTypeAttributes decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!inverseName_.jsonDecode(*tree)) {
            Log(Error, "ReferenceTypeAttributes decode json error - decode failed")
                .parameter("Element", "InverseName");
            return false;
        }
    
        return true;
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
