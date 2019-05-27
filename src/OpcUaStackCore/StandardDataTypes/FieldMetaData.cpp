/*
    DataTypeClass: FieldMetaData

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/FieldMetaData.h"

namespace OpcUaStackCore
{
    
    FieldMetaData::FieldMetaData(void)
    : Object()
    , ExtensionObjectBase()
    , name_()
    , description_()
    , fieldFlags_()
    , builtInType_()
    , dataType_()
    , valueRank_()
    , arrayDimensions_()
    , maxStringLength_()
    , dataSetFieldId_()
    , properties_()
    {
    }
    
    FieldMetaData::FieldMetaData(const FieldMetaData& value)
    : Object()
    , ExtensionObjectBase()
    , name_()
    , description_()
    , fieldFlags_()
    , builtInType_()
    , dataType_()
    , valueRank_()
    , arrayDimensions_()
    , maxStringLength_()
    , dataSetFieldId_()
    , properties_()
    {
        const_cast<FieldMetaData*>(&value)->copyTo(*this);
    }
    
    FieldMetaData::~FieldMetaData(void)
    {
    }
    
    OpcUaString&
    FieldMetaData::name(void)
    {
        return name_;
    }
    
    OpcUaLocalizedText&
    FieldMetaData::description(void)
    {
        return description_;
    }
    
    OpcUaDataSetFieldFlag&
    FieldMetaData::fieldFlags(void)
    {
        return fieldFlags_;
    }
    
    OpcUaByte&
    FieldMetaData::builtInType(void)
    {
        return builtInType_;
    }
    
    OpcUaNodeId&
    FieldMetaData::dataType(void)
    {
        return dataType_;
    }
    
    OpcUaInt32&
    FieldMetaData::valueRank(void)
    {
        return valueRank_;
    }
    
    OpcUaUInt32Array&
    FieldMetaData::arrayDimensions(void)
    {
        return arrayDimensions_;
    }
    
    OpcUaUInt32&
    FieldMetaData::maxStringLength(void)
    {
        return maxStringLength_;
    }
    
    OpcUaGuid&
    FieldMetaData::dataSetFieldId(void)
    {
        return dataSetFieldId_;
    }
    
    KeyValuePairArray&
    FieldMetaData::properties(void)
    {
        return properties_;
    }
    
    bool
    FieldMetaData::operator==(const FieldMetaData& value)
    {
        FieldMetaData* dst = const_cast<FieldMetaData*>(&value);
        if (name_ != dst->name()) return false;
        if (description_ != dst->description()) return false;
        if (fieldFlags_ != dst->fieldFlags()) return false;
        if (builtInType_ != dst->builtInType()) return false;
        if (dataType_ != dst->dataType()) return false;
        if (valueRank_ != dst->valueRank()) return false;
        if (arrayDimensions_ != dst->arrayDimensions()) return false;
        if (maxStringLength_ != dst->maxStringLength()) return false;
        if (dataSetFieldId_ != dst->dataSetFieldId()) return false;
        if (properties_ != dst->properties()) return false;
        return true;
    }
    
    bool
    FieldMetaData::operator!=(const FieldMetaData& value)
    {
        return !this->operator==(value);
    }
    
    void
    FieldMetaData::copyTo(FieldMetaData& value)
    {
        name_.copyTo(value.name());
        description_.copyTo(value.description());
        value.fieldFlags_ = fieldFlags_;
        value.builtInType_ = builtInType_;
        dataType_.copyTo(value.dataType());
        value.valueRank_ = valueRank_;
        arrayDimensions_.copyTo(value.arrayDimensions());
        value.maxStringLength_ = maxStringLength_;
        dataSetFieldId_.copyTo(value.dataSetFieldId());
        properties_.copyTo(value.properties());
    }
    
    FieldMetaData&
    FieldMetaData::operator=(const FieldMetaData& value)
    {
        const_cast<FieldMetaData*>(&value)->copyTo(*this);
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
    FieldMetaData::factory(void)
    {
    	return constructSPtr<FieldMetaData>();
    }
    
    std::string
    FieldMetaData::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    FieldMetaData::typeName(void)
    {
    	return "FieldMetaData";
    }
    
    OpcUaNodeId
    FieldMetaData::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)14524,0);
    }
    
    OpcUaNodeId
    FieldMetaData::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)14839, 0);
    }
    
    OpcUaNodeId
    FieldMetaData::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)14795, 0);
    }
    
    OpcUaNodeId
    FieldMetaData::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15051, 0);
    }
    
    void
    FieldMetaData::opcUaBinaryEncode(std::ostream& os) const
    {
        name_.opcUaBinaryEncode(os);
        description_.opcUaBinaryEncode(os);
        OpcUaNumber::opcUaBinaryEncode(os,fieldFlags_);
        OpcUaNumber::opcUaBinaryEncode(os,builtInType_);
        dataType_.opcUaBinaryEncode(os);
        OpcUaNumber::opcUaBinaryEncode(os,valueRank_);
        arrayDimensions_.opcUaBinaryEncode(os);
        OpcUaNumber::opcUaBinaryEncode(os,maxStringLength_);
        dataSetFieldId_.opcUaBinaryEncode(os);
        properties_.opcUaBinaryEncode(os);
    }
    
    void
    FieldMetaData::opcUaBinaryDecode(std::istream& is)
    {
        name_.opcUaBinaryDecode(is);
        description_.opcUaBinaryDecode(is);
        OpcUaNumber::opcUaBinaryDecode(is,fieldFlags_);
        OpcUaNumber::opcUaBinaryDecode(is,builtInType_);
        dataType_.opcUaBinaryDecode(is);
        OpcUaNumber::opcUaBinaryDecode(is,valueRank_);
        arrayDimensions_.opcUaBinaryDecode(is);
        OpcUaNumber::opcUaBinaryDecode(is,maxStringLength_);
        dataSetFieldId_.opcUaBinaryDecode(is);
        properties_.opcUaBinaryDecode(is);
    }
    
    bool
    FieldMetaData::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "FieldMetaData encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    FieldMetaData::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!name_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "FieldMetaData encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("Name", elementTree));
    
        elementTree.clear();
        if (!description_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "FieldMetaData encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("Description", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, fieldFlags_))
        {
            Log(Error, "FieldMetaData encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("FieldFlags", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, builtInType_))
        {
            Log(Error, "FieldMetaData encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("BuiltInType", elementTree));
    
        elementTree.clear();
        if (!dataType_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "FieldMetaData encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("DataType", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, valueRank_))
        {
            Log(Error, "FieldMetaData encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("ValueRank", elementTree));
    
        elementTree.clear();
        if (!arrayDimensions_.xmlEncode(elementTree, "UInt32", xmlns)) {
            Log(Error, "FieldMetaData encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("ArrayDimensions", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, maxStringLength_))
        {
            Log(Error, "FieldMetaData encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("MaxStringLength", elementTree));
    
        elementTree.clear();
        if (!dataSetFieldId_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "FieldMetaData encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("DataSetFieldId", elementTree));
    
        elementTree.clear();
        if (!properties_.xmlEncode(elementTree, "KeyValuePair", xmlns)) {
            Log(Error, "FieldMetaData encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("Properties", elementTree));
    
        return true;
    }
    
    bool
    FieldMetaData::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "FieldMetaData decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    FieldMetaData::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        elementName = xmlns.addPrefix("Name");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "FieldMetaData decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!name_.xmlDecode(*tree, xmlns)) {
            Log(Error, "FieldMetaData decode xml error - decode failed")
                .parameter("Element", "Name");
            return false;
        }
    
        elementName = xmlns.addPrefix("Description");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "FieldMetaData decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!description_.xmlDecode(*tree, xmlns)) {
            Log(Error, "FieldMetaData decode xml error - decode failed")
                .parameter("Element", "Description");
            return false;
        }
    
        elementName = xmlns.addPrefix("FieldFlags");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "FieldMetaData decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, fieldFlags_)) {
            Log(Error, "FieldMetaData decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("BuiltInType");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "FieldMetaData decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, builtInType_)) {
            Log(Error, "FieldMetaData decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("DataType");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "FieldMetaData decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!dataType_.xmlDecode(*tree, xmlns)) {
            Log(Error, "FieldMetaData decode xml error - decode failed")
                .parameter("Element", "DataType");
            return false;
        }
    
        elementName = xmlns.addPrefix("ValueRank");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "FieldMetaData decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, valueRank_)) {
            Log(Error, "FieldMetaData decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("ArrayDimensions");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "FieldMetaData decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!arrayDimensions_.xmlDecode(*tree, "UInt32", xmlns)) {
            Log(Error, "FieldMetaData decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("MaxStringLength");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "FieldMetaData decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, maxStringLength_)) {
            Log(Error, "FieldMetaData decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("DataSetFieldId");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "FieldMetaData decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!dataSetFieldId_.xmlDecode(*tree, xmlns)) {
            Log(Error, "FieldMetaData decode xml error - decode failed")
                .parameter("Element", "DataSetFieldId");
            return false;
        }
    
        elementName = xmlns.addPrefix("Properties");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "FieldMetaData decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!properties_.xmlDecode(*tree, "KeyValuePair", xmlns)) {
            Log(Error, "FieldMetaData decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    bool
    FieldMetaData::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!name_.jsonEncode(elementTree))
        {
    	     Log(Error, "FieldMetaData json encoder error")
    		     .parameter("Element", "name_");
            return false;
        }
        pt.push_back(std::make_pair("Name", elementTree));
    
        elementTree.clear();
        if (!description_.jsonEncode(elementTree))
        {
    	     Log(Error, "FieldMetaData json encoder error")
    		     .parameter("Element", "description_");
            return false;
        }
        pt.push_back(std::make_pair("Description", elementTree));
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, fieldFlags_))
        {
    	     Log(Error, "FieldMetaData json encoder error")
    		     .parameter("Element", "fieldFlags_");
           return false;
        }
        pt.push_back(std::make_pair("FieldFlags", elementTree));
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, builtInType_))
        {
    	     Log(Error, "FieldMetaData json encoder error")
    		     .parameter("Element", "builtInType_");
           return false;
        }
        pt.push_back(std::make_pair("BuiltInType", elementTree));
    
        elementTree.clear();
        if (!dataType_.jsonEncode(elementTree))
        {
    	     Log(Error, "FieldMetaData json encoder error")
    		     .parameter("Element", "dataType_");
            return false;
        }
        pt.push_back(std::make_pair("DataType", elementTree));
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, valueRank_))
        {
    	     Log(Error, "FieldMetaData json encoder error")
    		     .parameter("Element", "valueRank_");
           return false;
        }
        pt.push_back(std::make_pair("ValueRank", elementTree));
    
        elementTree.clear();
        if (!arrayDimensions_.jsonEncode(elementTree, ""))
        {
    	     Log(Error, "FieldMetaData json encoder error")
    		     .parameter("Element", "arrayDimensions_");
            return false;
        }
        pt.push_back(std::make_pair("ArrayDimensions", elementTree));
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, maxStringLength_))
        {
    	     Log(Error, "FieldMetaData json encoder error")
    		     .parameter("Element", "maxStringLength_");
           return false;
        }
        pt.push_back(std::make_pair("MaxStringLength", elementTree));
    
        elementTree.clear();
        if (!dataSetFieldId_.jsonEncode(elementTree))
        {
    	     Log(Error, "FieldMetaData json encoder error")
    		     .parameter("Element", "dataSetFieldId_");
            return false;
        }
        pt.push_back(std::make_pair("DataSetFieldId", elementTree));
    
        elementTree.clear();
        if (!properties_.jsonEncode(elementTree, ""))
        {
    	     Log(Error, "FieldMetaData json encoder error")
    		     .parameter("Element", "properties_");
            return false;
        }
        pt.push_back(std::make_pair("Properties", elementTree));
    
        return true;
    }
    
    bool
    FieldMetaData::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        std::string elementName;
        boost::optional<const boost::property_tree::ptree&> tree;
    
        elementName = "Name";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "FieldMetaData decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!name_.jsonDecode(*tree)) {
            Log(Error, "FieldMetaData decode json error - decode failed")
                .parameter("Element", "Name");
            return false;
        }
    
        elementName = "Description";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "FieldMetaData decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!description_.jsonDecode(*tree)) {
            Log(Error, "FieldMetaData decode json error - decode failed")
                .parameter("Element", "Description");
            return false;
        }
    
        elementName = "FieldFlags";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "FieldMetaData decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, fieldFlags_)) {
            Log(Error, "FieldMetaData decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "BuiltInType";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "FieldMetaData decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, builtInType_)) {
            Log(Error, "FieldMetaData decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "DataType";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "FieldMetaData decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!dataType_.jsonDecode(*tree)) {
            Log(Error, "FieldMetaData decode json error - decode failed")
                .parameter("Element", "DataType");
            return false;
        }
    
        elementName = "ValueRank";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "FieldMetaData decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, valueRank_)) {
            Log(Error, "FieldMetaData decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "ArrayDimensions";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "FieldMetaData decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!arrayDimensions_.jsonDecode(*tree, "")) {
            Log(Error, "FieldMetaData decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "MaxStringLength";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "FieldMetaData decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, maxStringLength_)) {
            Log(Error, "FieldMetaData decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "DataSetFieldId";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "FieldMetaData decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!dataSetFieldId_.jsonDecode(*tree)) {
            Log(Error, "FieldMetaData decode json error - decode failed")
                .parameter("Element", "DataSetFieldId");
            return false;
        }
    
        elementName = "Properties";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "FieldMetaData decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!properties_.jsonDecode(*tree, "")) {
            Log(Error, "FieldMetaData decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    void
    FieldMetaData::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	FieldMetaData* dst = dynamic_cast<FieldMetaData*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    FieldMetaData::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	FieldMetaData* dst = dynamic_cast<FieldMetaData*>(&extensionObjectBase);
    	return *const_cast<FieldMetaData*>(this) == *dst;
    }
    
    void
    FieldMetaData::out(std::ostream& os)
    {
        os << "Name="; name_.out(os);
        os << ", Description="; description_.out(os);
        os << ", FieldFlags=" << fieldFlags_;
        os << ", BuiltInType=" << builtInType_;
        os << ", DataType="; dataType_.out(os);
        os << ", ValueRank=" << valueRank_;
        os << ", ArrayDimensions="; arrayDimensions_.out(os);
        os << ", MaxStringLength=" << maxStringLength_;
        os << ", DataSetFieldId="; dataSetFieldId_.out(os);
        os << ", Properties="; properties_.out(os);
    }

}
