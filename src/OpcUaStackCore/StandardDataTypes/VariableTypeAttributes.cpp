/*
    DataTypeClass: VariableTypeAttributes

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/VariableTypeAttributes.h"

namespace OpcUaStackCore
{
    
    /**
     * The attributes for a variable type node.
     */
    VariableTypeAttributes::VariableTypeAttributes(void)
    : NodeAttributes()
    , value_()
    , dataType_()
    , valueRank_()
    , arrayDimensions_()
    , isAbstract_()
    {
    }
    
    /**
     * The attributes for a variable type node.
     */
    VariableTypeAttributes::VariableTypeAttributes(const VariableTypeAttributes& value)
    : NodeAttributes()
    , value_()
    , dataType_()
    , valueRank_()
    , arrayDimensions_()
    , isAbstract_()
    {
        const_cast<VariableTypeAttributes*>(&value)->copyTo(*this);
    }
    
    VariableTypeAttributes::~VariableTypeAttributes(void)
    {
    }
    
    OpcUaVariant&
    VariableTypeAttributes::value(void)
    {
        return value_;
    }
    
    OpcUaNodeId&
    VariableTypeAttributes::dataType(void)
    {
        return dataType_;
    }
    
    OpcUaInt32&
    VariableTypeAttributes::valueRank(void)
    {
        return valueRank_;
    }
    
    OpcUaUInt32Array&
    VariableTypeAttributes::arrayDimensions(void)
    {
        return arrayDimensions_;
    }
    
    OpcUaBoolean&
    VariableTypeAttributes::isAbstract(void)
    {
        return isAbstract_;
    }
    
    bool
    VariableTypeAttributes::operator==(const VariableTypeAttributes& value)
    {
        VariableTypeAttributes* dst = const_cast<VariableTypeAttributes*>(&value);
        if (value_ != dst->value()) return false;
        if (dataType_ != dst->dataType()) return false;
        if (valueRank_ != dst->valueRank()) return false;
        if (arrayDimensions_ != dst->arrayDimensions()) return false;
        if (isAbstract_ != dst->isAbstract()) return false;
        return true;
    }
    
    bool
    VariableTypeAttributes::operator!=(const VariableTypeAttributes& value)
    {
        return !this->operator==(value);
    }
    
    void
    VariableTypeAttributes::copyTo(VariableTypeAttributes& value)
    {
        value_.copyTo(value.value());
        dataType_.copyTo(value.dataType());
        value.valueRank_ = valueRank_;
        arrayDimensions_.copyTo(value.arrayDimensions());
        value.isAbstract_ = isAbstract_;
    }
    
    VariableTypeAttributes&
    VariableTypeAttributes::operator=(const VariableTypeAttributes& value)
    {
        const_cast<VariableTypeAttributes*>(&value)->copyTo(*this);
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
    VariableTypeAttributes::factory(void)
    {
    	return constructSPtr<VariableTypeAttributes>();
    }
    
    std::string
    VariableTypeAttributes::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    VariableTypeAttributes::typeName(void)
    {
    	return "VariableTypeAttributes";
    }
    
    OpcUaNodeId
    VariableTypeAttributes::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)364,0);
    }
    
    OpcUaNodeId
    VariableTypeAttributes::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)366, 0);
    }
    
    OpcUaNodeId
    VariableTypeAttributes::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)365, 0);
    }
    
    OpcUaNodeId
    VariableTypeAttributes::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15159, 0);
    }
    
    void
    VariableTypeAttributes::opcUaBinaryEncode(std::ostream& os) const
    {
        NodeAttributes::opcUaBinaryEncode(os);
        value_.opcUaBinaryEncode(os);
        dataType_.opcUaBinaryEncode(os);
        OpcUaNumber::opcUaBinaryEncode(os,valueRank_);
        arrayDimensions_.opcUaBinaryEncode(os);
        OpcUaNumber::opcUaBinaryEncode(os,isAbstract_);
    }
    
    void
    VariableTypeAttributes::opcUaBinaryDecode(std::istream& is)
    {
        NodeAttributes::opcUaBinaryDecode(is);
        value_.opcUaBinaryDecode(is);
        dataType_.opcUaBinaryDecode(is);
        OpcUaNumber::opcUaBinaryDecode(is,valueRank_);
        arrayDimensions_.opcUaBinaryDecode(is);
        OpcUaNumber::opcUaBinaryDecode(is,isAbstract_);
    }
    
    bool
    VariableTypeAttributes::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "VariableTypeAttributes encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    VariableTypeAttributes::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!value_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "VariableTypeAttributes encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("Value", elementTree));
    
        elementTree.clear();
        if (!dataType_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "VariableTypeAttributes encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("DataType", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, valueRank_))
        {
            Log(Error, "VariableTypeAttributes encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("ValueRank", elementTree));
    
        elementTree.clear();
        if (!arrayDimensions_.xmlEncode(elementTree, "UInt32", xmlns)) {
            Log(Error, "VariableTypeAttributes encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("ArrayDimensions", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, isAbstract_))
        {
            Log(Error, "VariableTypeAttributes encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("IsAbstract", elementTree));
    
        return true;
    }
    
    bool
    VariableTypeAttributes::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "VariableTypeAttributes decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    VariableTypeAttributes::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        elementName = xmlns.addPrefix("Value");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "VariableTypeAttributes decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!value_.xmlDecode(*tree, xmlns)) {
            Log(Error, "VariableTypeAttributes decode xml error - decode failed")
                .parameter("Element", "Value");
            return false;
        }
    
        elementName = xmlns.addPrefix("DataType");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "VariableTypeAttributes decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!dataType_.xmlDecode(*tree, xmlns)) {
            Log(Error, "VariableTypeAttributes decode xml error - decode failed")
                .parameter("Element", "DataType");
            return false;
        }
    
        elementName = xmlns.addPrefix("ValueRank");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "VariableTypeAttributes decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, valueRank_)) {
            Log(Error, "VariableTypeAttributes decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("ArrayDimensions");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "VariableTypeAttributes decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!arrayDimensions_.xmlDecode(*tree, "UInt32", xmlns)) {
            Log(Error, "VariableTypeAttributes decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("IsAbstract");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "VariableTypeAttributes decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, isAbstract_)) {
            Log(Error, "VariableTypeAttributes decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    bool
    VariableTypeAttributes::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!value_.jsonEncode(elementTree))
        {
    	     Log(Error, "VariableTypeAttributes json encoder error")
    		     .parameter("Element", "value_");
            return false;
        }
        pt.push_back(std::make_pair("Value", elementTree));
    
        elementTree.clear();
        if (!dataType_.jsonEncode(elementTree))
        {
    	     Log(Error, "VariableTypeAttributes json encoder error")
    		     .parameter("Element", "dataType_");
            return false;
        }
        pt.push_back(std::make_pair("DataType", elementTree));
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, valueRank_))
        {
    	     Log(Error, "VariableTypeAttributes json encoder error")
    		     .parameter("Element", "valueRank_");
           return false;
        }
        pt.push_back(std::make_pair("ValueRank", elementTree));
    
        elementTree.clear();
        if (!arrayDimensions_.jsonEncode(elementTree, ""))
        {
    	     Log(Error, "VariableTypeAttributes json encoder error")
    		     .parameter("Element", "arrayDimensions_");
            return false;
        }
        pt.push_back(std::make_pair("ArrayDimensions", elementTree));
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, isAbstract_))
        {
    	     Log(Error, "VariableTypeAttributes json encoder error")
    		     .parameter("Element", "isAbstract_");
           return false;
        }
        pt.push_back(std::make_pair("IsAbstract", elementTree));
    
        return true;
    }
    
    bool
    VariableTypeAttributes::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        std::string elementName;
        boost::optional<const boost::property_tree::ptree&> tree;
    
        elementName = "Value";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "VariableTypeAttributes decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!value_.jsonDecode(*tree)) {
            Log(Error, "VariableTypeAttributes decode json error - decode failed")
                .parameter("Element", "Value");
            return false;
        }
    
        elementName = "DataType";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "VariableTypeAttributes decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!dataType_.jsonDecode(*tree)) {
            Log(Error, "VariableTypeAttributes decode json error - decode failed")
                .parameter("Element", "DataType");
            return false;
        }
    
        elementName = "ValueRank";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "VariableTypeAttributes decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, valueRank_)) {
            Log(Error, "VariableTypeAttributes decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "ArrayDimensions";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "VariableTypeAttributes decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!arrayDimensions_.jsonDecode(*tree, "")) {
            Log(Error, "VariableTypeAttributes decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "IsAbstract";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "VariableTypeAttributes decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, isAbstract_)) {
            Log(Error, "VariableTypeAttributes decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    void
    VariableTypeAttributes::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	VariableTypeAttributes* dst = dynamic_cast<VariableTypeAttributes*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    VariableTypeAttributes::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	VariableTypeAttributes* dst = dynamic_cast<VariableTypeAttributes*>(&extensionObjectBase);
    	return *const_cast<VariableTypeAttributes*>(this) == *dst;
    }
    
    void
    VariableTypeAttributes::out(std::ostream& os)
    {
        os << "Value="; value_.out(os);
        os << ", DataType="; dataType_.out(os);
        os << ", ValueRank=" << valueRank_;
        os << ", ArrayDimensions="; arrayDimensions_.out(os);
        os << ", IsAbstract=" << isAbstract_;
    }

}
