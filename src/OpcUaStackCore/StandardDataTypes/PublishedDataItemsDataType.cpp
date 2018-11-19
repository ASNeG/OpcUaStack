/*
    DataTypeClass: PublishedDataItemsDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/PublishedDataItemsDataType.h"

namespace OpcUaStackCore
{
    
    PublishedDataItemsDataType::PublishedDataItemsDataType(void)
    : PublishedDataSetSourceDataType()
    , publishedData_()
    {
    }
    
    PublishedDataItemsDataType::~PublishedDataItemsDataType(void)
    {
    }
    
    PublishedVariableDataTypeArray&
    PublishedDataItemsDataType::publishedData(void)
    {
        return publishedData_;
    }
    
    bool
    PublishedDataItemsDataType::operator==(const PublishedDataItemsDataType& value)
    {
        PublishedDataItemsDataType* dst = const_cast<PublishedDataItemsDataType*>(&value);
        if (publishedData_ != dst->publishedData()) return false;
        return true;
    }
    
    bool
    PublishedDataItemsDataType::operator!=(const PublishedDataItemsDataType& value)
    {
        return !this->operator==(value);
    }
    
    void
    PublishedDataItemsDataType::copyTo(PublishedDataItemsDataType& value)
    {
        publishedData_.copyTo(value.publishedData());
    }
    
    PublishedDataItemsDataType&
    PublishedDataItemsDataType::operator=(const PublishedDataItemsDataType& value)
    {
        const_cast<PublishedDataItemsDataType*>(&value)->copyTo(*this);
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
    PublishedDataItemsDataType::factory(void)
    {
    	return constructSPtr<PublishedDataItemsDataType>();
    }
    
    std::string
    PublishedDataItemsDataType::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    PublishedDataItemsDataType::typeName(void)
    {
    	return "PublishedDataItemsDataType";
    }
    
    OpcUaNodeId
    PublishedDataItemsDataType::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15581,0);
    }
    
    OpcUaNodeId
    PublishedDataItemsDataType::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15679, 0);
    }
    
    OpcUaNodeId
    PublishedDataItemsDataType::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15953, 0);
    }
    
    OpcUaNodeId
    PublishedDataItemsDataType::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)16154, 0);
    }
    
    void
    PublishedDataItemsDataType::opcUaBinaryEncode(std::ostream& os) const
    {
        publishedData_.opcUaBinaryEncode(os);
    }
    
    void
    PublishedDataItemsDataType::opcUaBinaryDecode(std::istream& is)
    {
        publishedData_.opcUaBinaryDecode(is);
    }
    
    bool
    PublishedDataItemsDataType::encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const
    {
    }
    
    bool
    PublishedDataItemsDataType::decode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
    }
    
    bool
    PublishedDataItemsDataType::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    PublishedDataItemsDataType::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!publishedData_.xmlEncode(elementTree, "PublishedVariableDataType", xmlns)) return false;
        pt.push_back(std::make_pair("PublishedData", elementTree));
    
        return true;
    }
    
    bool
    PublishedDataItemsDataType::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(element);
        if (!tree) return false;
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    PublishedDataItemsDataType::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree;
    
        tree = pt.get_child_optional("PublishedData");
        if (!tree) return false;
        if (!publishedData_.xmlDecode(*tree, "PublishedVariableDataType", xmlns)) return false;
    
        return true;
    }
    
    bool
    PublishedDataItemsDataType::jsonEncode(boost::property_tree::ptree& pt, const std::string& element)
    {
        return true;
    }
    
    bool
    PublishedDataItemsDataType::jsonEncode(boost::property_tree::ptree& pt)
    {
        return true;
    }
    
    bool
    PublishedDataItemsDataType::jsonDecode(boost::property_tree::ptree& pt, const std::string& element)
    {
    }
    
    bool
    PublishedDataItemsDataType::jsonDecode(boost::property_tree::ptree& pt)
    {
    }
    
    void
    PublishedDataItemsDataType::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	PublishedDataItemsDataType* dst = dynamic_cast<PublishedDataItemsDataType*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    PublishedDataItemsDataType::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	PublishedDataItemsDataType* dst = dynamic_cast<PublishedDataItemsDataType*>(&extensionObjectBase);
    	return *const_cast<PublishedDataItemsDataType*>(this) == *dst;
    }
    
    void
    PublishedDataItemsDataType::out(std::ostream& os)
    {
        os << "PublishedData="; publishedData_.out(os);
    }

}
