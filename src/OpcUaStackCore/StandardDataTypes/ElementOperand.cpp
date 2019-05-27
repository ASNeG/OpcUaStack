/*
    DataTypeClass: ElementOperand

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/ElementOperand.h"

namespace OpcUaStackCore
{
    
    ElementOperand::ElementOperand(void)
    : FilterOperand()
    , index_()
    {
    }
    
    ElementOperand::ElementOperand(const ElementOperand& value)
    : FilterOperand()
    , index_()
    {
        const_cast<ElementOperand*>(&value)->copyTo(*this);
    }
    
    ElementOperand::~ElementOperand(void)
    {
    }
    
    OpcUaUInt32&
    ElementOperand::index(void)
    {
        return index_;
    }
    
    bool
    ElementOperand::operator==(const ElementOperand& value)
    {
        ElementOperand* dst = const_cast<ElementOperand*>(&value);
        if (index_ != dst->index()) return false;
        return true;
    }
    
    bool
    ElementOperand::operator!=(const ElementOperand& value)
    {
        return !this->operator==(value);
    }
    
    void
    ElementOperand::copyTo(ElementOperand& value)
    {
        value.index_ = index_;
    }
    
    ElementOperand&
    ElementOperand::operator=(const ElementOperand& value)
    {
        const_cast<ElementOperand*>(&value)->copyTo(*this);
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
    ElementOperand::factory(void)
    {
    	return constructSPtr<ElementOperand>();
    }
    
    std::string
    ElementOperand::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    ElementOperand::typeName(void)
    {
    	return "ElementOperand";
    }
    
    OpcUaNodeId
    ElementOperand::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)592,0);
    }
    
    OpcUaNodeId
    ElementOperand::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)594, 0);
    }
    
    OpcUaNodeId
    ElementOperand::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)593, 0);
    }
    
    OpcUaNodeId
    ElementOperand::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15207, 0);
    }
    
    void
    ElementOperand::opcUaBinaryEncode(std::ostream& os) const
    {
        FilterOperand::opcUaBinaryEncode(os);
        OpcUaNumber::opcUaBinaryEncode(os,index_);
    }
    
    void
    ElementOperand::opcUaBinaryDecode(std::istream& is)
    {
        FilterOperand::opcUaBinaryDecode(is);
        OpcUaNumber::opcUaBinaryDecode(is,index_);
    }
    
    bool
    ElementOperand::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "ElementOperand encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    ElementOperand::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, index_))
        {
            Log(Error, "ElementOperand encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("Index", elementTree));
    
        return true;
    }
    
    bool
    ElementOperand::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ElementOperand decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    ElementOperand::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        elementName = xmlns.addPrefix("Index");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ElementOperand decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, index_)) {
            Log(Error, "ElementOperand decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    bool
    ElementOperand::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, index_))
        {
    	     Log(Error, "ElementOperand json encoder error")
    		     .parameter("Element", "index_");
           return false;
        }
        pt.push_back(std::make_pair("Index", elementTree));
    
        return true;
    }
    
    bool
    ElementOperand::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        std::string elementName;
        boost::optional<const boost::property_tree::ptree&> tree;
    
        elementName = "Index";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ElementOperand decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, index_)) {
            Log(Error, "ElementOperand decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    void
    ElementOperand::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	ElementOperand* dst = dynamic_cast<ElementOperand*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    ElementOperand::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	ElementOperand* dst = dynamic_cast<ElementOperand*>(&extensionObjectBase);
    	return *const_cast<ElementOperand*>(this) == *dst;
    }
    
    void
    ElementOperand::out(std::ostream& os)
    {
        os << "Index=" << index_;
    }

}
