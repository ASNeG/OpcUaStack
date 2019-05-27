/*
    DataTypeClass: DataTypeDescription

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/DataTypeDescription.h"

namespace OpcUaStackCore
{
    
    DataTypeDescription::DataTypeDescription(void)
    : Object()
    , ExtensionObjectBase()
    , dataTypeId_()
    , name_()
    {
    }
    
    DataTypeDescription::DataTypeDescription(const DataTypeDescription& value)
    : Object()
    , ExtensionObjectBase()
    , dataTypeId_()
    , name_()
    {
        const_cast<DataTypeDescription*>(&value)->copyTo(*this);
    }
    
    DataTypeDescription::~DataTypeDescription(void)
    {
    }
    
    OpcUaNodeId&
    DataTypeDescription::dataTypeId(void)
    {
        return dataTypeId_;
    }
    
    OpcUaQualifiedName&
    DataTypeDescription::name(void)
    {
        return name_;
    }
    
    bool
    DataTypeDescription::operator==(const DataTypeDescription& value)
    {
        DataTypeDescription* dst = const_cast<DataTypeDescription*>(&value);
        if (dataTypeId_ != dst->dataTypeId()) return false;
        if (name_ != dst->name()) return false;
        return true;
    }
    
    bool
    DataTypeDescription::operator!=(const DataTypeDescription& value)
    {
        return !this->operator==(value);
    }
    
    void
    DataTypeDescription::copyTo(DataTypeDescription& value)
    {
        dataTypeId_.copyTo(value.dataTypeId());
        name_.copyTo(value.name());
    }
    
    DataTypeDescription&
    DataTypeDescription::operator=(const DataTypeDescription& value)
    {
        const_cast<DataTypeDescription*>(&value)->copyTo(*this);
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
    DataTypeDescription::factory(void)
    {
    	return constructSPtr<DataTypeDescription>();
    }
    
    std::string
    DataTypeDescription::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    DataTypeDescription::typeName(void)
    {
    	return "DataTypeDescription";
    }
    
    OpcUaNodeId
    DataTypeDescription::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)14525,0);
    }
    
    OpcUaNodeId
    DataTypeDescription::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)125, 0);
    }
    
    OpcUaNodeId
    DataTypeDescription::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)14796, 0);
    }
    
    OpcUaNodeId
    DataTypeDescription::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15057, 0);
    }
    
    void
    DataTypeDescription::opcUaBinaryEncode(std::ostream& os) const
    {
        dataTypeId_.opcUaBinaryEncode(os);
        name_.opcUaBinaryEncode(os);
    }
    
    void
    DataTypeDescription::opcUaBinaryDecode(std::istream& is)
    {
        dataTypeId_.opcUaBinaryDecode(is);
        name_.opcUaBinaryDecode(is);
    }
    
    bool
    DataTypeDescription::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "DataTypeDescription encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    DataTypeDescription::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!dataTypeId_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "DataTypeDescription encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("DataTypeId", elementTree));
    
        elementTree.clear();
        if (!name_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "DataTypeDescription encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("Name", elementTree));
    
        return true;
    }
    
    bool
    DataTypeDescription::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "DataTypeDescription decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    DataTypeDescription::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        elementName = xmlns.addPrefix("DataTypeId");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "DataTypeDescription decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!dataTypeId_.xmlDecode(*tree, xmlns)) {
            Log(Error, "DataTypeDescription decode xml error - decode failed")
                .parameter("Element", "DataTypeId");
            return false;
        }
    
        elementName = xmlns.addPrefix("Name");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "DataTypeDescription decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!name_.xmlDecode(*tree, xmlns)) {
            Log(Error, "DataTypeDescription decode xml error - decode failed")
                .parameter("Element", "Name");
            return false;
        }
    
        return true;
    }
    
    bool
    DataTypeDescription::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!dataTypeId_.jsonEncode(elementTree))
        {
    	     Log(Error, "DataTypeDescription json encoder error")
    		     .parameter("Element", "dataTypeId_");
            return false;
        }
        pt.push_back(std::make_pair("DataTypeId", elementTree));
    
        elementTree.clear();
        if (!name_.jsonEncode(elementTree))
        {
    	     Log(Error, "DataTypeDescription json encoder error")
    		     .parameter("Element", "name_");
            return false;
        }
        pt.push_back(std::make_pair("Name", elementTree));
    
        return true;
    }
    
    bool
    DataTypeDescription::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        std::string elementName;
        boost::optional<const boost::property_tree::ptree&> tree;
    
        elementName = "DataTypeId";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "DataTypeDescription decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!dataTypeId_.jsonDecode(*tree)) {
            Log(Error, "DataTypeDescription decode json error - decode failed")
                .parameter("Element", "DataTypeId");
            return false;
        }
    
        elementName = "Name";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "DataTypeDescription decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!name_.jsonDecode(*tree)) {
            Log(Error, "DataTypeDescription decode json error - decode failed")
                .parameter("Element", "Name");
            return false;
        }
    
        return true;
    }
    
    void
    DataTypeDescription::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	DataTypeDescription* dst = dynamic_cast<DataTypeDescription*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    DataTypeDescription::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	DataTypeDescription* dst = dynamic_cast<DataTypeDescription*>(&extensionObjectBase);
    	return *const_cast<DataTypeDescription*>(this) == *dst;
    }
    
    void
    DataTypeDescription::out(std::ostream& os)
    {
        os << "DataTypeId="; dataTypeId_.out(os);
        os << ", Name="; name_.out(os);
    }

}
