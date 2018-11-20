/*
    DataTypeClass: OptionSet

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/OptionSet.h"

namespace OpcUaStackCore
{
    
    /**
     * This abstract Structured DataType is the base DataType for all DataTypes representing a bit mask.
     */
    OptionSet::OptionSet(void)
    : Object()
    , ExtensionObjectBase()
    , value_()
    , validBits_()
    {
    }
    
    OptionSet::~OptionSet(void)
    {
    }
    
    OpcUaByteString&
    OptionSet::value(void)
    {
        return value_;
    }
    
    OpcUaByteString&
    OptionSet::validBits(void)
    {
        return validBits_;
    }
    
    bool
    OptionSet::operator==(const OptionSet& value)
    {
        OptionSet* dst = const_cast<OptionSet*>(&value);
        if (value_ != dst->value()) return false;
        if (validBits_ != dst->validBits()) return false;
        return true;
    }
    
    bool
    OptionSet::operator!=(const OptionSet& value)
    {
        return !this->operator==(value);
    }
    
    void
    OptionSet::copyTo(OptionSet& value)
    {
        value_.copyTo(value.value());
        validBits_.copyTo(value.validBits());
    }
    
    OptionSet&
    OptionSet::operator=(const OptionSet& value)
    {
        const_cast<OptionSet*>(&value)->copyTo(*this);
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
    OptionSet::factory(void)
    {
    	return constructSPtr<OptionSet>();
    }
    
    std::string
    OptionSet::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    OptionSet::typeName(void)
    {
    	return "OptionSet";
    }
    
    OpcUaNodeId
    OptionSet::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)12755,0);
    }
    
    OpcUaNodeId
    OptionSet::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)12765, 0);
    }
    
    OpcUaNodeId
    OptionSet::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)12757, 0);
    }
    
    OpcUaNodeId
    OptionSet::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15084, 0);
    }
    
    void
    OptionSet::opcUaBinaryEncode(std::ostream& os) const
    {
        value_.opcUaBinaryEncode(os);
        validBits_.opcUaBinaryEncode(os);
    }
    
    void
    OptionSet::opcUaBinaryDecode(std::istream& is)
    {
        value_.opcUaBinaryDecode(is);
        validBits_.opcUaBinaryDecode(is);
    }
    
    bool
    OptionSet::encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const
    {
    }
    
    bool
    OptionSet::decode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
    }
    
    bool
    OptionSet::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    OptionSet::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!value_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("Value", elementTree));
    
        elementTree.clear();
        if (!validBits_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("ValidBits", elementTree));
    
        return true;
    }
    
    bool
    OptionSet::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(element);
        if (!tree) return false;
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    OptionSet::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree;
    
        tree = pt.get_child_optional("Value");
        if (!tree) return false;
        if (!value_.xmlDecode(*tree, xmlns)) return false;
    
        tree = pt.get_child_optional("ValidBits");
        if (!tree) return false;
        if (!validBits_.xmlDecode(*tree, xmlns)) return false;
    
        return true;
    }
    
    bool
    OptionSet::jsonEncode(boost::property_tree::ptree& pt, const std::string& element)
    {
        return true;
    }
    
    bool
    OptionSet::jsonEncode(boost::property_tree::ptree& pt)
    {
        return true;
    }
    
    bool
    OptionSet::jsonDecode(boost::property_tree::ptree& pt, const std::string& element)
    {
    }
    
    bool
    OptionSet::jsonDecode(boost::property_tree::ptree& pt)
    {
    }
    
    void
    OptionSet::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	OptionSet* dst = dynamic_cast<OptionSet*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    OptionSet::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	OptionSet* dst = dynamic_cast<OptionSet*>(&extensionObjectBase);
    	return *const_cast<OptionSet*>(this) == *dst;
    }
    
    void
    OptionSet::out(std::ostream& os)
    {
        os << "Value="; value_.out(os);
        os << ", ValidBits="; validBits_.out(os);
    }

}
