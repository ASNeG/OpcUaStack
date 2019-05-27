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
    
    /**
     * This abstract Structured DataType is the base DataType for all DataTypes representing a bit mask.
     */
    OptionSet::OptionSet(const OptionSet& value)
    : Object()
    , ExtensionObjectBase()
    , value_()
    , validBits_()
    {
        const_cast<OptionSet*>(&value)->copyTo(*this);
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
    OptionSet::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "OptionSet encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    OptionSet::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!value_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "OptionSet encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("Value", elementTree));
    
        elementTree.clear();
        if (!validBits_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "OptionSet encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("ValidBits", elementTree));
    
        return true;
    }
    
    bool
    OptionSet::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "OptionSet decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    OptionSet::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        elementName = xmlns.addPrefix("Value");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "OptionSet decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!value_.xmlDecode(*tree, xmlns)) {
            Log(Error, "OptionSet decode xml error - decode failed")
                .parameter("Element", "Value");
            return false;
        }
    
        elementName = xmlns.addPrefix("ValidBits");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "OptionSet decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!validBits_.xmlDecode(*tree, xmlns)) {
            Log(Error, "OptionSet decode xml error - decode failed")
                .parameter("Element", "ValidBits");
            return false;
        }
    
        return true;
    }
    
    bool
    OptionSet::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!value_.jsonEncode(elementTree))
        {
    	     Log(Error, "OptionSet json encoder error")
    		     .parameter("Element", "value_");
            return false;
        }
        pt.push_back(std::make_pair("Value", elementTree));
    
        elementTree.clear();
        if (!validBits_.jsonEncode(elementTree))
        {
    	     Log(Error, "OptionSet json encoder error")
    		     .parameter("Element", "validBits_");
            return false;
        }
        pt.push_back(std::make_pair("ValidBits", elementTree));
    
        return true;
    }
    
    bool
    OptionSet::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        std::string elementName;
        boost::optional<const boost::property_tree::ptree&> tree;
    
        elementName = "Value";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "OptionSet decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!value_.jsonDecode(*tree)) {
            Log(Error, "OptionSet decode json error - decode failed")
                .parameter("Element", "Value");
            return false;
        }
    
        elementName = "ValidBits";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "OptionSet decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!validBits_.jsonDecode(*tree)) {
            Log(Error, "OptionSet decode json error - decode failed")
                .parameter("Element", "ValidBits");
            return false;
        }
    
        return true;
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
