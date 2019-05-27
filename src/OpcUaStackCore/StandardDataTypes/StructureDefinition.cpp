/*
    DataTypeClass: StructureDefinition

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/StructureDefinition.h"

namespace OpcUaStackCore
{
    
    StructureDefinition::StructureDefinition(void)
    : DataTypeDefinition()
    , defaultEncodingId_()
    , baseDataType_()
    , structureType_()
    , fields_()
    {
    }
    
    StructureDefinition::StructureDefinition(const StructureDefinition& value)
    : DataTypeDefinition()
    , defaultEncodingId_()
    , baseDataType_()
    , structureType_()
    , fields_()
    {
        const_cast<StructureDefinition*>(&value)->copyTo(*this);
    }
    
    StructureDefinition::~StructureDefinition(void)
    {
    }
    
    OpcUaNodeId&
    StructureDefinition::defaultEncodingId(void)
    {
        return defaultEncodingId_;
    }
    
    OpcUaNodeId&
    StructureDefinition::baseDataType(void)
    {
        return baseDataType_;
    }
    
    StructureType&
    StructureDefinition::structureType(void)
    {
        return structureType_;
    }
    
    StructureFieldArray&
    StructureDefinition::fields(void)
    {
        return fields_;
    }
    
    bool
    StructureDefinition::operator==(const StructureDefinition& value)
    {
        StructureDefinition* dst = const_cast<StructureDefinition*>(&value);
        if (defaultEncodingId_ != dst->defaultEncodingId()) return false;
        if (baseDataType_ != dst->baseDataType()) return false;
        if (structureType_ != dst->structureType()) return false;
        if (fields_ != dst->fields()) return false;
        return true;
    }
    
    bool
    StructureDefinition::operator!=(const StructureDefinition& value)
    {
        return !this->operator==(value);
    }
    
    void
    StructureDefinition::copyTo(StructureDefinition& value)
    {
        defaultEncodingId_.copyTo(value.defaultEncodingId());
        baseDataType_.copyTo(value.baseDataType());
        structureType_.copyTo(value.structureType());
        fields_.copyTo(value.fields());
    }
    
    StructureDefinition&
    StructureDefinition::operator=(const StructureDefinition& value)
    {
        const_cast<StructureDefinition*>(&value)->copyTo(*this);
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
    StructureDefinition::factory(void)
    {
    	return constructSPtr<StructureDefinition>();
    }
    
    std::string
    StructureDefinition::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    StructureDefinition::typeName(void)
    {
    	return "StructureDefinition";
    }
    
    OpcUaNodeId
    StructureDefinition::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)99,0);
    }
    
    OpcUaNodeId
    StructureDefinition::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)122, 0);
    }
    
    OpcUaNodeId
    StructureDefinition::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)14798, 0);
    }
    
    OpcUaNodeId
    StructureDefinition::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15066, 0);
    }
    
    void
    StructureDefinition::opcUaBinaryEncode(std::ostream& os) const
    {
        DataTypeDefinition::opcUaBinaryEncode(os);
        defaultEncodingId_.opcUaBinaryEncode(os);
        baseDataType_.opcUaBinaryEncode(os);
        structureType_.opcUaBinaryEncode(os);
        fields_.opcUaBinaryEncode(os);
    }
    
    void
    StructureDefinition::opcUaBinaryDecode(std::istream& is)
    {
        DataTypeDefinition::opcUaBinaryDecode(is);
        defaultEncodingId_.opcUaBinaryDecode(is);
        baseDataType_.opcUaBinaryDecode(is);
        structureType_.opcUaBinaryDecode(is);
        fields_.opcUaBinaryDecode(is);
    }
    
    bool
    StructureDefinition::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "StructureDefinition encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    StructureDefinition::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!defaultEncodingId_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "StructureDefinition encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("DefaultEncodingId", elementTree));
    
        elementTree.clear();
        if (!baseDataType_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "StructureDefinition encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("BaseDataType", elementTree));
    
        elementTree.clear();
        if (!structureType_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "StructureDefinition encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("StructureType", elementTree));
    
        elementTree.clear();
        if (!fields_.xmlEncode(elementTree, "StructureField", xmlns)) {
            Log(Error, "StructureDefinition encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("Fields", elementTree));
    
        return true;
    }
    
    bool
    StructureDefinition::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "StructureDefinition decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    StructureDefinition::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        elementName = xmlns.addPrefix("DefaultEncodingId");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "StructureDefinition decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!defaultEncodingId_.xmlDecode(*tree, xmlns)) {
            Log(Error, "StructureDefinition decode xml error - decode failed")
                .parameter("Element", "DefaultEncodingId");
            return false;
        }
    
        elementName = xmlns.addPrefix("BaseDataType");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "StructureDefinition decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!baseDataType_.xmlDecode(*tree, xmlns)) {
            Log(Error, "StructureDefinition decode xml error - decode failed")
                .parameter("Element", "BaseDataType");
            return false;
        }
    
        elementName = xmlns.addPrefix("StructureType");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "StructureDefinition decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!structureType_.xmlDecode(*tree, xmlns)) {
            Log(Error, "StructureDefinition decode xml error - decode failed")
                .parameter("Element", "StructureType");
            return false;
        }
    
        elementName = xmlns.addPrefix("Fields");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "StructureDefinition decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!fields_.xmlDecode(*tree, "StructureField", xmlns)) {
            Log(Error, "StructureDefinition decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    bool
    StructureDefinition::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!defaultEncodingId_.jsonEncode(elementTree))
        {
    	     Log(Error, "StructureDefinition json encoder error")
    		     .parameter("Element", "defaultEncodingId_");
            return false;
        }
        pt.push_back(std::make_pair("DefaultEncodingId", elementTree));
    
        elementTree.clear();
        if (!baseDataType_.jsonEncode(elementTree))
        {
    	     Log(Error, "StructureDefinition json encoder error")
    		     .parameter("Element", "baseDataType_");
            return false;
        }
        pt.push_back(std::make_pair("BaseDataType", elementTree));
    
        elementTree.clear();
        if (!structureType_.jsonEncode(elementTree))
        {
    	     Log(Error, "StructureDefinition json encoder error")
    		     .parameter("Element", "structureType_");
            return false;
        }
        pt.push_back(std::make_pair("StructureType", elementTree));
    
        elementTree.clear();
        if (!fields_.jsonEncode(elementTree, ""))
        {
    	     Log(Error, "StructureDefinition json encoder error")
    		     .parameter("Element", "fields_");
            return false;
        }
        pt.push_back(std::make_pair("Fields", elementTree));
    
        return true;
    }
    
    bool
    StructureDefinition::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        std::string elementName;
        boost::optional<const boost::property_tree::ptree&> tree;
    
        elementName = "DefaultEncodingId";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "StructureDefinition decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!defaultEncodingId_.jsonDecode(*tree)) {
            Log(Error, "StructureDefinition decode json error - decode failed")
                .parameter("Element", "DefaultEncodingId");
            return false;
        }
    
        elementName = "BaseDataType";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "StructureDefinition decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!baseDataType_.jsonDecode(*tree)) {
            Log(Error, "StructureDefinition decode json error - decode failed")
                .parameter("Element", "BaseDataType");
            return false;
        }
    
        elementName = "StructureType";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "StructureDefinition decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!structureType_.jsonDecode(*tree)) {
            Log(Error, "StructureDefinition decode json error - decode failed")
                .parameter("Element", "StructureType");
            return false;
        }
    
        elementName = "Fields";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "StructureDefinition decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!fields_.jsonDecode(*tree, "")) {
            Log(Error, "StructureDefinition decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    void
    StructureDefinition::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	StructureDefinition* dst = dynamic_cast<StructureDefinition*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    StructureDefinition::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	StructureDefinition* dst = dynamic_cast<StructureDefinition*>(&extensionObjectBase);
    	return *const_cast<StructureDefinition*>(this) == *dst;
    }
    
    void
    StructureDefinition::out(std::ostream& os)
    {
        os << "DefaultEncodingId="; defaultEncodingId_.out(os);
        os << ", BaseDataType="; baseDataType_.out(os);
        os << ", StructureType="; structureType_.out(os);
        os << ", Fields="; fields_.out(os);
    }

}
