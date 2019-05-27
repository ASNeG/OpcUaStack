/*
    DataTypeClass: DataTypeSchemaHeader

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/DataTypeSchemaHeader.h"

namespace OpcUaStackCore
{
    
    DataTypeSchemaHeader::DataTypeSchemaHeader(void)
    : Object()
    , ExtensionObjectBase()
    , namespaces_()
    , structureDataTypes_()
    , enumDataTypes_()
    , simpleDataTypes_()
    {
    }
    
    DataTypeSchemaHeader::DataTypeSchemaHeader(const DataTypeSchemaHeader& value)
    : Object()
    , ExtensionObjectBase()
    , namespaces_()
    , structureDataTypes_()
    , enumDataTypes_()
    , simpleDataTypes_()
    {
        const_cast<DataTypeSchemaHeader*>(&value)->copyTo(*this);
    }
    
    DataTypeSchemaHeader::~DataTypeSchemaHeader(void)
    {
    }
    
    OpcUaStringArray&
    DataTypeSchemaHeader::namespaces(void)
    {
        return namespaces_;
    }
    
    StructureDescriptionArray&
    DataTypeSchemaHeader::structureDataTypes(void)
    {
        return structureDataTypes_;
    }
    
    EnumDescriptionArray&
    DataTypeSchemaHeader::enumDataTypes(void)
    {
        return enumDataTypes_;
    }
    
    SimpleTypeDescriptionArray&
    DataTypeSchemaHeader::simpleDataTypes(void)
    {
        return simpleDataTypes_;
    }
    
    bool
    DataTypeSchemaHeader::operator==(const DataTypeSchemaHeader& value)
    {
        DataTypeSchemaHeader* dst = const_cast<DataTypeSchemaHeader*>(&value);
        if (namespaces_ != dst->namespaces()) return false;
        if (structureDataTypes_ != dst->structureDataTypes()) return false;
        if (enumDataTypes_ != dst->enumDataTypes()) return false;
        if (simpleDataTypes_ != dst->simpleDataTypes()) return false;
        return true;
    }
    
    bool
    DataTypeSchemaHeader::operator!=(const DataTypeSchemaHeader& value)
    {
        return !this->operator==(value);
    }
    
    void
    DataTypeSchemaHeader::copyTo(DataTypeSchemaHeader& value)
    {
        namespaces_.copyTo(value.namespaces());
        structureDataTypes_.copyTo(value.structureDataTypes());
        enumDataTypes_.copyTo(value.enumDataTypes());
        simpleDataTypes_.copyTo(value.simpleDataTypes());
    }
    
    DataTypeSchemaHeader&
    DataTypeSchemaHeader::operator=(const DataTypeSchemaHeader& value)
    {
        const_cast<DataTypeSchemaHeader*>(&value)->copyTo(*this);
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
    DataTypeSchemaHeader::factory(void)
    {
    	return constructSPtr<DataTypeSchemaHeader>();
    }
    
    std::string
    DataTypeSchemaHeader::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    DataTypeSchemaHeader::typeName(void)
    {
    	return "DataTypeSchemaHeader";
    }
    
    OpcUaNodeId
    DataTypeSchemaHeader::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15534,0);
    }
    
    OpcUaNodeId
    DataTypeSchemaHeader::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15676, 0);
    }
    
    OpcUaNodeId
    DataTypeSchemaHeader::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15950, 0);
    }
    
    OpcUaNodeId
    DataTypeSchemaHeader::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)16151, 0);
    }
    
    void
    DataTypeSchemaHeader::opcUaBinaryEncode(std::ostream& os) const
    {
        namespaces_.opcUaBinaryEncode(os);
        structureDataTypes_.opcUaBinaryEncode(os);
        enumDataTypes_.opcUaBinaryEncode(os);
        simpleDataTypes_.opcUaBinaryEncode(os);
    }
    
    void
    DataTypeSchemaHeader::opcUaBinaryDecode(std::istream& is)
    {
        namespaces_.opcUaBinaryDecode(is);
        structureDataTypes_.opcUaBinaryDecode(is);
        enumDataTypes_.opcUaBinaryDecode(is);
        simpleDataTypes_.opcUaBinaryDecode(is);
    }
    
    bool
    DataTypeSchemaHeader::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "DataTypeSchemaHeader encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    DataTypeSchemaHeader::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!namespaces_.xmlEncode(elementTree, "String", xmlns)) {
            Log(Error, "DataTypeSchemaHeader encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("Namespaces", elementTree));
    
        elementTree.clear();
        if (!structureDataTypes_.xmlEncode(elementTree, "StructureDescription", xmlns)) {
            Log(Error, "DataTypeSchemaHeader encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("StructureDataTypes", elementTree));
    
        elementTree.clear();
        if (!enumDataTypes_.xmlEncode(elementTree, "EnumDescription", xmlns)) {
            Log(Error, "DataTypeSchemaHeader encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("EnumDataTypes", elementTree));
    
        elementTree.clear();
        if (!simpleDataTypes_.xmlEncode(elementTree, "SimpleTypeDescription", xmlns)) {
            Log(Error, "DataTypeSchemaHeader encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("SimpleDataTypes", elementTree));
    
        return true;
    }
    
    bool
    DataTypeSchemaHeader::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "DataTypeSchemaHeader decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    DataTypeSchemaHeader::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        elementName = xmlns.addPrefix("Namespaces");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "DataTypeSchemaHeader decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!namespaces_.xmlDecode(*tree, "String", xmlns)) {
            Log(Error, "DataTypeSchemaHeader decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("StructureDataTypes");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "DataTypeSchemaHeader decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!structureDataTypes_.xmlDecode(*tree, "StructureDescription", xmlns)) {
            Log(Error, "DataTypeSchemaHeader decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("EnumDataTypes");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "DataTypeSchemaHeader decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!enumDataTypes_.xmlDecode(*tree, "EnumDescription", xmlns)) {
            Log(Error, "DataTypeSchemaHeader decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("SimpleDataTypes");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "DataTypeSchemaHeader decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!simpleDataTypes_.xmlDecode(*tree, "SimpleTypeDescription", xmlns)) {
            Log(Error, "DataTypeSchemaHeader decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    bool
    DataTypeSchemaHeader::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!namespaces_.jsonEncode(elementTree, ""))
        {
    	     Log(Error, "DataTypeSchemaHeader json encoder error")
    		     .parameter("Element", "namespaces_");
            return false;
        }
        pt.push_back(std::make_pair("Namespaces", elementTree));
    
        elementTree.clear();
        if (!structureDataTypes_.jsonEncode(elementTree, ""))
        {
    	     Log(Error, "DataTypeSchemaHeader json encoder error")
    		     .parameter("Element", "structureDataTypes_");
            return false;
        }
        pt.push_back(std::make_pair("StructureDataTypes", elementTree));
    
        elementTree.clear();
        if (!enumDataTypes_.jsonEncode(elementTree, ""))
        {
    	     Log(Error, "DataTypeSchemaHeader json encoder error")
    		     .parameter("Element", "enumDataTypes_");
            return false;
        }
        pt.push_back(std::make_pair("EnumDataTypes", elementTree));
    
        elementTree.clear();
        if (!simpleDataTypes_.jsonEncode(elementTree, ""))
        {
    	     Log(Error, "DataTypeSchemaHeader json encoder error")
    		     .parameter("Element", "simpleDataTypes_");
            return false;
        }
        pt.push_back(std::make_pair("SimpleDataTypes", elementTree));
    
        return true;
    }
    
    bool
    DataTypeSchemaHeader::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        std::string elementName;
        boost::optional<const boost::property_tree::ptree&> tree;
    
        elementName = "Namespaces";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "DataTypeSchemaHeader decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!namespaces_.jsonDecode(*tree, "")) {
            Log(Error, "DataTypeSchemaHeader decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "StructureDataTypes";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "DataTypeSchemaHeader decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!structureDataTypes_.jsonDecode(*tree, "")) {
            Log(Error, "DataTypeSchemaHeader decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "EnumDataTypes";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "DataTypeSchemaHeader decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!enumDataTypes_.jsonDecode(*tree, "")) {
            Log(Error, "DataTypeSchemaHeader decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "SimpleDataTypes";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "DataTypeSchemaHeader decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!simpleDataTypes_.jsonDecode(*tree, "")) {
            Log(Error, "DataTypeSchemaHeader decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    void
    DataTypeSchemaHeader::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	DataTypeSchemaHeader* dst = dynamic_cast<DataTypeSchemaHeader*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    DataTypeSchemaHeader::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	DataTypeSchemaHeader* dst = dynamic_cast<DataTypeSchemaHeader*>(&extensionObjectBase);
    	return *const_cast<DataTypeSchemaHeader*>(this) == *dst;
    }
    
    void
    DataTypeSchemaHeader::out(std::ostream& os)
    {
        os << "Namespaces="; namespaces_.out(os);
        os << ", StructureDataTypes="; structureDataTypes_.out(os);
        os << ", EnumDataTypes="; enumDataTypes_.out(os);
        os << ", SimpleDataTypes="; simpleDataTypes_.out(os);
    }

}
