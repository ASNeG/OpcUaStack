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
    
    PublishedDataItemsDataType::PublishedDataItemsDataType(const PublishedDataItemsDataType& value)
    : PublishedDataSetSourceDataType()
    , publishedData_()
    {
        const_cast<PublishedDataItemsDataType*>(&value)->copyTo(*this);
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
        PublishedDataSetSourceDataType::opcUaBinaryEncode(os);
        publishedData_.opcUaBinaryEncode(os);
    }
    
    void
    PublishedDataItemsDataType::opcUaBinaryDecode(std::istream& is)
    {
        PublishedDataSetSourceDataType::opcUaBinaryDecode(is);
        publishedData_.opcUaBinaryDecode(is);
    }
    
    bool
    PublishedDataItemsDataType::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "PublishedDataItemsDataType encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    PublishedDataItemsDataType::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!publishedData_.xmlEncode(elementTree, "PublishedVariableDataType", xmlns)) {
            Log(Error, "PublishedDataItemsDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("PublishedData", elementTree));
    
        return true;
    }
    
    bool
    PublishedDataItemsDataType::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "PublishedDataItemsDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    PublishedDataItemsDataType::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        elementName = xmlns.addPrefix("PublishedData");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "PublishedDataItemsDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!publishedData_.xmlDecode(*tree, "PublishedVariableDataType", xmlns)) {
            Log(Error, "PublishedDataItemsDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    bool
    PublishedDataItemsDataType::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!publishedData_.jsonEncode(elementTree, ""))
        {
    	     Log(Error, "PublishedDataItemsDataType json encoder error")
    		     .parameter("Element", "publishedData_");
            return false;
        }
        pt.push_back(std::make_pair("PublishedData", elementTree));
    
        return true;
    }
    
    bool
    PublishedDataItemsDataType::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        std::string elementName;
        boost::optional<const boost::property_tree::ptree&> tree;
    
        elementName = "PublishedData";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "PublishedDataItemsDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!publishedData_.jsonDecode(*tree, "")) {
            Log(Error, "PublishedDataItemsDataType decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
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
