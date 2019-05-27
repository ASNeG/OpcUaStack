/*
    DataTypeClass: StructureField

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/StructureField.h"

namespace OpcUaStackCore
{
    
    StructureField::StructureField(void)
    : Object()
    , ExtensionObjectBase()
    , name_()
    , description_()
    , dataType_()
    , valueRank_()
    , arrayDimensions_()
    , maxStringLength_()
    , isOptional_()
    {
    }
    
    StructureField::StructureField(const StructureField& value)
    : Object()
    , ExtensionObjectBase()
    , name_()
    , description_()
    , dataType_()
    , valueRank_()
    , arrayDimensions_()
    , maxStringLength_()
    , isOptional_()
    {
        const_cast<StructureField*>(&value)->copyTo(*this);
    }
    
    StructureField::~StructureField(void)
    {
    }
    
    OpcUaString&
    StructureField::name(void)
    {
        return name_;
    }
    
    OpcUaLocalizedText&
    StructureField::description(void)
    {
        return description_;
    }
    
    OpcUaNodeId&
    StructureField::dataType(void)
    {
        return dataType_;
    }
    
    OpcUaInt32&
    StructureField::valueRank(void)
    {
        return valueRank_;
    }
    
    OpcUaUInt32Array&
    StructureField::arrayDimensions(void)
    {
        return arrayDimensions_;
    }
    
    OpcUaUInt32&
    StructureField::maxStringLength(void)
    {
        return maxStringLength_;
    }
    
    OpcUaBoolean&
    StructureField::isOptional(void)
    {
        return isOptional_;
    }
    
    bool
    StructureField::operator==(const StructureField& value)
    {
        StructureField* dst = const_cast<StructureField*>(&value);
        if (name_ != dst->name()) return false;
        if (description_ != dst->description()) return false;
        if (dataType_ != dst->dataType()) return false;
        if (valueRank_ != dst->valueRank()) return false;
        if (arrayDimensions_ != dst->arrayDimensions()) return false;
        if (maxStringLength_ != dst->maxStringLength()) return false;
        if (isOptional_ != dst->isOptional()) return false;
        return true;
    }
    
    bool
    StructureField::operator!=(const StructureField& value)
    {
        return !this->operator==(value);
    }
    
    void
    StructureField::copyTo(StructureField& value)
    {
        name_.copyTo(value.name());
        description_.copyTo(value.description());
        dataType_.copyTo(value.dataType());
        value.valueRank_ = valueRank_;
        arrayDimensions_.copyTo(value.arrayDimensions());
        value.maxStringLength_ = maxStringLength_;
        value.isOptional_ = isOptional_;
    }
    
    StructureField&
    StructureField::operator=(const StructureField& value)
    {
        const_cast<StructureField*>(&value)->copyTo(*this);
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
    StructureField::factory(void)
    {
    	return constructSPtr<StructureField>();
    }
    
    std::string
    StructureField::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    StructureField::typeName(void)
    {
    	return "StructureField";
    }
    
    OpcUaNodeId
    StructureField::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)101,0);
    }
    
    OpcUaNodeId
    StructureField::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)14844, 0);
    }
    
    OpcUaNodeId
    StructureField::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)14800, 0);
    }
    
    OpcUaNodeId
    StructureField::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15065, 0);
    }
    
    void
    StructureField::opcUaBinaryEncode(std::ostream& os) const
    {
        name_.opcUaBinaryEncode(os);
        description_.opcUaBinaryEncode(os);
        dataType_.opcUaBinaryEncode(os);
        OpcUaNumber::opcUaBinaryEncode(os,valueRank_);
        arrayDimensions_.opcUaBinaryEncode(os);
        OpcUaNumber::opcUaBinaryEncode(os,maxStringLength_);
        OpcUaNumber::opcUaBinaryEncode(os,isOptional_);
    }
    
    void
    StructureField::opcUaBinaryDecode(std::istream& is)
    {
        name_.opcUaBinaryDecode(is);
        description_.opcUaBinaryDecode(is);
        dataType_.opcUaBinaryDecode(is);
        OpcUaNumber::opcUaBinaryDecode(is,valueRank_);
        arrayDimensions_.opcUaBinaryDecode(is);
        OpcUaNumber::opcUaBinaryDecode(is,maxStringLength_);
        OpcUaNumber::opcUaBinaryDecode(is,isOptional_);
    }
    
    bool
    StructureField::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "StructureField encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    StructureField::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!name_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "StructureField encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("Name", elementTree));
    
        elementTree.clear();
        if (!description_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "StructureField encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("Description", elementTree));
    
        elementTree.clear();
        if (!dataType_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "StructureField encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("DataType", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, valueRank_))
        {
            Log(Error, "StructureField encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("ValueRank", elementTree));
    
        elementTree.clear();
        if (!arrayDimensions_.xmlEncode(elementTree, "UInt32", xmlns)) {
            Log(Error, "StructureField encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("ArrayDimensions", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, maxStringLength_))
        {
            Log(Error, "StructureField encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("MaxStringLength", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, isOptional_))
        {
            Log(Error, "StructureField encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("IsOptional", elementTree));
    
        return true;
    }
    
    bool
    StructureField::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "StructureField decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    StructureField::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        elementName = xmlns.addPrefix("Name");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "StructureField decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!name_.xmlDecode(*tree, xmlns)) {
            Log(Error, "StructureField decode xml error - decode failed")
                .parameter("Element", "Name");
            return false;
        }
    
        elementName = xmlns.addPrefix("Description");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "StructureField decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!description_.xmlDecode(*tree, xmlns)) {
            Log(Error, "StructureField decode xml error - decode failed")
                .parameter("Element", "Description");
            return false;
        }
    
        elementName = xmlns.addPrefix("DataType");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "StructureField decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!dataType_.xmlDecode(*tree, xmlns)) {
            Log(Error, "StructureField decode xml error - decode failed")
                .parameter("Element", "DataType");
            return false;
        }
    
        elementName = xmlns.addPrefix("ValueRank");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "StructureField decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, valueRank_)) {
            Log(Error, "StructureField decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("ArrayDimensions");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "StructureField decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!arrayDimensions_.xmlDecode(*tree, "UInt32", xmlns)) {
            Log(Error, "StructureField decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("MaxStringLength");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "StructureField decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, maxStringLength_)) {
            Log(Error, "StructureField decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("IsOptional");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "StructureField decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, isOptional_)) {
            Log(Error, "StructureField decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    bool
    StructureField::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!name_.jsonEncode(elementTree))
        {
    	     Log(Error, "StructureField json encoder error")
    		     .parameter("Element", "name_");
            return false;
        }
        pt.push_back(std::make_pair("Name", elementTree));
    
        elementTree.clear();
        if (!description_.jsonEncode(elementTree))
        {
    	     Log(Error, "StructureField json encoder error")
    		     .parameter("Element", "description_");
            return false;
        }
        pt.push_back(std::make_pair("Description", elementTree));
    
        elementTree.clear();
        if (!dataType_.jsonEncode(elementTree))
        {
    	     Log(Error, "StructureField json encoder error")
    		     .parameter("Element", "dataType_");
            return false;
        }
        pt.push_back(std::make_pair("DataType", elementTree));
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, valueRank_))
        {
    	     Log(Error, "StructureField json encoder error")
    		     .parameter("Element", "valueRank_");
           return false;
        }
        pt.push_back(std::make_pair("ValueRank", elementTree));
    
        elementTree.clear();
        if (!arrayDimensions_.jsonEncode(elementTree, ""))
        {
    	     Log(Error, "StructureField json encoder error")
    		     .parameter("Element", "arrayDimensions_");
            return false;
        }
        pt.push_back(std::make_pair("ArrayDimensions", elementTree));
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, maxStringLength_))
        {
    	     Log(Error, "StructureField json encoder error")
    		     .parameter("Element", "maxStringLength_");
           return false;
        }
        pt.push_back(std::make_pair("MaxStringLength", elementTree));
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, isOptional_))
        {
    	     Log(Error, "StructureField json encoder error")
    		     .parameter("Element", "isOptional_");
           return false;
        }
        pt.push_back(std::make_pair("IsOptional", elementTree));
    
        return true;
    }
    
    bool
    StructureField::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        std::string elementName;
        boost::optional<const boost::property_tree::ptree&> tree;
    
        elementName = "Name";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "StructureField decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!name_.jsonDecode(*tree)) {
            Log(Error, "StructureField decode json error - decode failed")
                .parameter("Element", "Name");
            return false;
        }
    
        elementName = "Description";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "StructureField decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!description_.jsonDecode(*tree)) {
            Log(Error, "StructureField decode json error - decode failed")
                .parameter("Element", "Description");
            return false;
        }
    
        elementName = "DataType";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "StructureField decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!dataType_.jsonDecode(*tree)) {
            Log(Error, "StructureField decode json error - decode failed")
                .parameter("Element", "DataType");
            return false;
        }
    
        elementName = "ValueRank";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "StructureField decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, valueRank_)) {
            Log(Error, "StructureField decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "ArrayDimensions";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "StructureField decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!arrayDimensions_.jsonDecode(*tree, "")) {
            Log(Error, "StructureField decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "MaxStringLength";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "StructureField decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, maxStringLength_)) {
            Log(Error, "StructureField decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "IsOptional";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "StructureField decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, isOptional_)) {
            Log(Error, "StructureField decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    void
    StructureField::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	StructureField* dst = dynamic_cast<StructureField*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    StructureField::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	StructureField* dst = dynamic_cast<StructureField*>(&extensionObjectBase);
    	return *const_cast<StructureField*>(this) == *dst;
    }
    
    void
    StructureField::out(std::ostream& os)
    {
        os << "Name="; name_.out(os);
        os << ", Description="; description_.out(os);
        os << ", DataType="; dataType_.out(os);
        os << ", ValueRank=" << valueRank_;
        os << ", ArrayDimensions="; arrayDimensions_.out(os);
        os << ", MaxStringLength=" << maxStringLength_;
        os << ", IsOptional=" << isOptional_;
    }

}
