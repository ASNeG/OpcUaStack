/*
    DataTypeClass: LiteralOperand

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/LiteralOperand.h"

namespace OpcUaStackCore
{
    
    LiteralOperand::LiteralOperand(void)
    : FilterOperand()
    , value_()
    {
    }
    
    LiteralOperand::LiteralOperand(const LiteralOperand& value)
    : FilterOperand()
    , value_()
    {
        const_cast<LiteralOperand*>(&value)->copyTo(*this);
    }
    
    LiteralOperand::~LiteralOperand(void)
    {
    }
    
    OpcUaVariant&
    LiteralOperand::value(void)
    {
        return value_;
    }
    
    bool
    LiteralOperand::operator==(const LiteralOperand& value)
    {
        LiteralOperand* dst = const_cast<LiteralOperand*>(&value);
        if (value_ != dst->value()) return false;
        return true;
    }
    
    bool
    LiteralOperand::operator!=(const LiteralOperand& value)
    {
        return !this->operator==(value);
    }
    
    void
    LiteralOperand::copyTo(LiteralOperand& value)
    {
        value_.copyTo(value.value());
    }
    
    LiteralOperand&
    LiteralOperand::operator=(const LiteralOperand& value)
    {
        const_cast<LiteralOperand*>(&value)->copyTo(*this);
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
    LiteralOperand::factory(void)
    {
    	return constructSPtr<LiteralOperand>();
    }
    
    std::string
    LiteralOperand::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    LiteralOperand::typeName(void)
    {
    	return "LiteralOperand";
    }
    
    OpcUaNodeId
    LiteralOperand::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)595,0);
    }
    
    OpcUaNodeId
    LiteralOperand::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)597, 0);
    }
    
    OpcUaNodeId
    LiteralOperand::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)596, 0);
    }
    
    OpcUaNodeId
    LiteralOperand::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15208, 0);
    }
    
    void
    LiteralOperand::opcUaBinaryEncode(std::ostream& os) const
    {
        FilterOperand::opcUaBinaryEncode(os);
        value_.opcUaBinaryEncode(os);
    }
    
    void
    LiteralOperand::opcUaBinaryDecode(std::istream& is)
    {
        FilterOperand::opcUaBinaryDecode(is);
        value_.opcUaBinaryDecode(is);
    }
    
    bool
    LiteralOperand::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "LiteralOperand encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    LiteralOperand::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!value_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "LiteralOperand encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("Value", elementTree));
    
        return true;
    }
    
    bool
    LiteralOperand::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "LiteralOperand decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    LiteralOperand::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        elementName = xmlns.addPrefix("Value");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "LiteralOperand decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!value_.xmlDecode(*tree, xmlns)) {
            Log(Error, "LiteralOperand decode xml error - decode failed")
                .parameter("Element", "Value");
            return false;
        }
    
        return true;
    }
    
    bool
    LiteralOperand::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!value_.jsonEncode(elementTree))
        {
    	     Log(Error, "LiteralOperand json encoder error")
    		     .parameter("Element", "value_");
            return false;
        }
        pt.push_back(std::make_pair("Value", elementTree));
    
        return true;
    }
    
    bool
    LiteralOperand::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        std::string elementName;
        boost::optional<const boost::property_tree::ptree&> tree;
    
        elementName = "Value";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "LiteralOperand decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!value_.jsonDecode(*tree)) {
            Log(Error, "LiteralOperand decode json error - decode failed")
                .parameter("Element", "Value");
            return false;
        }
    
        return true;
    }
    
    void
    LiteralOperand::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	LiteralOperand* dst = dynamic_cast<LiteralOperand*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    LiteralOperand::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	LiteralOperand* dst = dynamic_cast<LiteralOperand*>(&extensionObjectBase);
    	return *const_cast<LiteralOperand*>(this) == *dst;
    }
    
    void
    LiteralOperand::out(std::ostream& os)
    {
        os << "Value="; value_.out(os);
    }

}
