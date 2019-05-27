/*
    DataTypeClass: DataTypeDefinition

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/DataTypeDefinition.h"

namespace OpcUaStackCore
{
    
    DataTypeDefinition::DataTypeDefinition(void)
    : Object()
    , ExtensionObjectBase()
    {
    }
    
    DataTypeDefinition::DataTypeDefinition(const DataTypeDefinition& value)
    : Object()
    , ExtensionObjectBase()
    {
        const_cast<DataTypeDefinition*>(&value)->copyTo(*this);
    }
    
    DataTypeDefinition::~DataTypeDefinition(void)
    {
    }
    
    bool
    DataTypeDefinition::operator==(const DataTypeDefinition& value)
    {
        DataTypeDefinition* dst = const_cast<DataTypeDefinition*>(&value);
        return true;
    }
    
    bool
    DataTypeDefinition::operator!=(const DataTypeDefinition& value)
    {
        return !this->operator==(value);
    }
    
    void
    DataTypeDefinition::copyTo(DataTypeDefinition& value)
    {
    }
    
    DataTypeDefinition&
    DataTypeDefinition::operator=(const DataTypeDefinition& value)
    {
        const_cast<DataTypeDefinition*>(&value)->copyTo(*this);
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
    DataTypeDefinition::factory(void)
    {
    	return constructSPtr<DataTypeDefinition>();
    }
    
    std::string
    DataTypeDefinition::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    DataTypeDefinition::typeName(void)
    {
    	return "DataTypeDefinition";
    }
    
    OpcUaNodeId
    DataTypeDefinition::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)97,0);
    }
    
    OpcUaNodeId
    DataTypeDefinition::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)121, 0);
    }
    
    OpcUaNodeId
    DataTypeDefinition::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)14797, 0);
    }
    
    OpcUaNodeId
    DataTypeDefinition::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15063, 0);
    }
    
    void
    DataTypeDefinition::opcUaBinaryEncode(std::ostream& os) const
    {
    }
    
    void
    DataTypeDefinition::opcUaBinaryDecode(std::istream& is)
    {
    }
    
    bool
    DataTypeDefinition::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "DataTypeDefinition encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    DataTypeDefinition::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        return true;
    }
    
    bool
    DataTypeDefinition::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "DataTypeDefinition decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    DataTypeDefinition::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        return true;
    }
    
    bool
    DataTypeDefinition::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        boost::property_tree::ptree elementTree;
    
        return true;
    }
    
    bool
    DataTypeDefinition::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        std::string elementName;
        boost::optional<const boost::property_tree::ptree&> tree;
    
        return true;
    }
    
    void
    DataTypeDefinition::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	DataTypeDefinition* dst = dynamic_cast<DataTypeDefinition*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    DataTypeDefinition::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	DataTypeDefinition* dst = dynamic_cast<DataTypeDefinition*>(&extensionObjectBase);
    	return *const_cast<DataTypeDefinition*>(this) == *dst;
    }
    
    void
    DataTypeDefinition::out(std::ostream& os)
    {
    }

}
