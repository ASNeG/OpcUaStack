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
    FieldMetaData::encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const
    {
    }
    
    bool
    FieldMetaData::decode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
    }
    
    bool
    FieldMetaData::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    FieldMetaData::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!name_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("Name", elementTree));
    
        elementTree.clear();
        if (!description_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("Description", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, fieldFlags_)) return false;
        pt.push_back(std::make_pair("FieldFlags", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, builtInType_)) return false;
        pt.push_back(std::make_pair("BuiltInType", elementTree));
    
        elementTree.clear();
        if (!dataType_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("DataType", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, valueRank_)) return false;
        pt.push_back(std::make_pair("ValueRank", elementTree));
    
        elementTree.clear();
        if (!arrayDimensions_.xmlEncode(elementTree, "UInt32", xmlns)) return false;
        pt.push_back(std::make_pair("ArrayDimensions", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, maxStringLength_)) return false;
        pt.push_back(std::make_pair("MaxStringLength", elementTree));
    
        elementTree.clear();
        if (!dataSetFieldId_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("DataSetFieldId", elementTree));
    
        elementTree.clear();
        if (!properties_.xmlEncode(elementTree, "KeyValuePair", xmlns)) return false;
        pt.push_back(std::make_pair("Properties", elementTree));
    
        return true;
    }
    
    bool
    FieldMetaData::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(element);
        if (!tree) return false;
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    FieldMetaData::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree;
    
        tree = pt.get_child_optional("Name");
        if (!tree) return false;
        if (!name_.xmlDecode(*tree, xmlns)) return false;
    
        tree = pt.get_child_optional("Description");
        if (!tree) return false;
        if (!description_.xmlDecode(*tree, xmlns)) return false;
    
        tree = pt.get_child_optional("FieldFlags");
        if (!tree) return false;
        if(!XmlNumber::xmlDecode(*tree, fieldFlags_)) return false;
    
        tree = pt.get_child_optional("BuiltInType");
        if (!tree) return false;
        if(!XmlNumber::xmlDecode(*tree, builtInType_)) return false;
    
        tree = pt.get_child_optional("DataType");
        if (!tree) return false;
        if (!dataType_.xmlDecode(*tree, xmlns)) return false;
    
        tree = pt.get_child_optional("ValueRank");
        if (!tree) return false;
        if(!XmlNumber::xmlDecode(*tree, valueRank_)) return false;
    
        tree = pt.get_child_optional("ArrayDimensions");
        if (!tree) return false;
        if (!arrayDimensions_.xmlDecode(*tree, "UInt32", xmlns)) return false;
    
        tree = pt.get_child_optional("MaxStringLength");
        if (!tree) return false;
        if(!XmlNumber::xmlDecode(*tree, maxStringLength_)) return false;
    
        tree = pt.get_child_optional("DataSetFieldId");
        if (!tree) return false;
        if (!dataSetFieldId_.xmlDecode(*tree, xmlns)) return false;
    
        tree = pt.get_child_optional("Properties");
        if (!tree) return false;
        if (!properties_.xmlDecode(*tree, "KeyValuePair", xmlns)) return false;
    
        return true;
    }
    
    bool
    FieldMetaData::jsonEncode(boost::property_tree::ptree& pt, const std::string& element)
    {
        return true;
    }
    
    bool
    FieldMetaData::jsonEncode(boost::property_tree::ptree& pt)
    {
        return true;
    }
    
    bool
    FieldMetaData::jsonDecode(boost::property_tree::ptree& pt, const std::string& element)
    {
    }
    
    bool
    FieldMetaData::jsonDecode(boost::property_tree::ptree& pt)
    {
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
