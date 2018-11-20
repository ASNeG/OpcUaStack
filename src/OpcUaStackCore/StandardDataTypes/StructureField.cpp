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
    StructureField::encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const
    {
    }
    
    bool
    StructureField::decode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
    }
    
    bool
    StructureField::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    StructureField::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!name_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("Name", elementTree));
    
        elementTree.clear();
        if (!description_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("Description", elementTree));
    
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
        if(!XmlNumber::xmlEncode(elementTree, isOptional_)) return false;
        pt.push_back(std::make_pair("IsOptional", elementTree));
    
        return true;
    }
    
    bool
    StructureField::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(element);
        if (!tree) return false;
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    StructureField::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree;
    
        tree = pt.get_child_optional("Name");
        if (!tree) return false;
        if (!name_.xmlDecode(*tree, xmlns)) return false;
    
        tree = pt.get_child_optional("Description");
        if (!tree) return false;
        if (!description_.xmlDecode(*tree, xmlns)) return false;
    
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
    
        tree = pt.get_child_optional("IsOptional");
        if (!tree) return false;
        if(!XmlNumber::xmlDecode(*tree, isOptional_)) return false;
    
        return true;
    }
    
    bool
    StructureField::jsonEncode(boost::property_tree::ptree& pt, const std::string& element)
    {
        return true;
    }
    
    bool
    StructureField::jsonEncode(boost::property_tree::ptree& pt)
    {
        return true;
    }
    
    bool
    StructureField::jsonDecode(boost::property_tree::ptree& pt, const std::string& element)
    {
    }
    
    bool
    StructureField::jsonDecode(boost::property_tree::ptree& pt)
    {
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
