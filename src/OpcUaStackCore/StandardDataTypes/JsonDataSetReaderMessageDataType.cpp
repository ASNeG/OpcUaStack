/*
    DataTypeClass: JsonDataSetReaderMessageDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/JsonDataSetReaderMessageDataType.h"

namespace OpcUaStackCore
{
    
    JsonDataSetReaderMessageDataType::JsonDataSetReaderMessageDataType(void)
    : DataSetReaderMessageDataType()
    , networkMessageContentMask_()
    , dataSetMessageContentMask_()
    {
    }
    
    JsonDataSetReaderMessageDataType::JsonDataSetReaderMessageDataType(const JsonDataSetReaderMessageDataType& value)
    : DataSetReaderMessageDataType()
    , networkMessageContentMask_()
    , dataSetMessageContentMask_()
    {
        const_cast<JsonDataSetReaderMessageDataType*>(&value)->copyTo(*this);
    }
    
    JsonDataSetReaderMessageDataType::~JsonDataSetReaderMessageDataType(void)
    {
    }
    
    OpcUaJsonNetworkMessageContentMask&
    JsonDataSetReaderMessageDataType::networkMessageContentMask(void)
    {
        return networkMessageContentMask_;
    }
    
    OpcUaJsonDataSetMessageContentMask&
    JsonDataSetReaderMessageDataType::dataSetMessageContentMask(void)
    {
        return dataSetMessageContentMask_;
    }
    
    bool
    JsonDataSetReaderMessageDataType::operator==(const JsonDataSetReaderMessageDataType& value)
    {
        JsonDataSetReaderMessageDataType* dst = const_cast<JsonDataSetReaderMessageDataType*>(&value);
        if (networkMessageContentMask_ != dst->networkMessageContentMask()) return false;
        if (dataSetMessageContentMask_ != dst->dataSetMessageContentMask()) return false;
        return true;
    }
    
    bool
    JsonDataSetReaderMessageDataType::operator!=(const JsonDataSetReaderMessageDataType& value)
    {
        return !this->operator==(value);
    }
    
    void
    JsonDataSetReaderMessageDataType::copyTo(JsonDataSetReaderMessageDataType& value)
    {
        value.networkMessageContentMask_ = networkMessageContentMask_;
        value.dataSetMessageContentMask_ = dataSetMessageContentMask_;
    }
    
    JsonDataSetReaderMessageDataType&
    JsonDataSetReaderMessageDataType::operator=(const JsonDataSetReaderMessageDataType& value)
    {
        const_cast<JsonDataSetReaderMessageDataType*>(&value)->copyTo(*this);
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
    JsonDataSetReaderMessageDataType::factory(void)
    {
    	return constructSPtr<JsonDataSetReaderMessageDataType>();
    }
    
    std::string
    JsonDataSetReaderMessageDataType::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    JsonDataSetReaderMessageDataType::typeName(void)
    {
    	return "JsonDataSetReaderMessageDataType";
    }
    
    OpcUaNodeId
    JsonDataSetReaderMessageDataType::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15665,0);
    }
    
    OpcUaNodeId
    JsonDataSetReaderMessageDataType::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15725, 0);
    }
    
    OpcUaNodeId
    JsonDataSetReaderMessageDataType::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)16019, 0);
    }
    
    OpcUaNodeId
    JsonDataSetReaderMessageDataType::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)16404, 0);
    }
    
    void
    JsonDataSetReaderMessageDataType::opcUaBinaryEncode(std::ostream& os) const
    {
        DataSetReaderMessageDataType::opcUaBinaryEncode(os);
        OpcUaNumber::opcUaBinaryEncode(os,networkMessageContentMask_);
        OpcUaNumber::opcUaBinaryEncode(os,dataSetMessageContentMask_);
    }
    
    void
    JsonDataSetReaderMessageDataType::opcUaBinaryDecode(std::istream& is)
    {
        DataSetReaderMessageDataType::opcUaBinaryDecode(is);
        OpcUaNumber::opcUaBinaryDecode(is,networkMessageContentMask_);
        OpcUaNumber::opcUaBinaryDecode(is,dataSetMessageContentMask_);
    }
    
    bool
    JsonDataSetReaderMessageDataType::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "JsonDataSetReaderMessageDataType encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    JsonDataSetReaderMessageDataType::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, networkMessageContentMask_))
        {
            Log(Error, "JsonDataSetReaderMessageDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("NetworkMessageContentMask", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, dataSetMessageContentMask_))
        {
            Log(Error, "JsonDataSetReaderMessageDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("DataSetMessageContentMask", elementTree));
    
        return true;
    }
    
    bool
    JsonDataSetReaderMessageDataType::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "JsonDataSetReaderMessageDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    JsonDataSetReaderMessageDataType::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        elementName = xmlns.addPrefix("NetworkMessageContentMask");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "JsonDataSetReaderMessageDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, networkMessageContentMask_)) {
            Log(Error, "JsonDataSetReaderMessageDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("DataSetMessageContentMask");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "JsonDataSetReaderMessageDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, dataSetMessageContentMask_)) {
            Log(Error, "JsonDataSetReaderMessageDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    bool
    JsonDataSetReaderMessageDataType::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, networkMessageContentMask_))
        {
    	     Log(Error, "JsonDataSetReaderMessageDataType json encoder error")
    		     .parameter("Element", "networkMessageContentMask_");
           return false;
        }
        pt.push_back(std::make_pair("NetworkMessageContentMask", elementTree));
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, dataSetMessageContentMask_))
        {
    	     Log(Error, "JsonDataSetReaderMessageDataType json encoder error")
    		     .parameter("Element", "dataSetMessageContentMask_");
           return false;
        }
        pt.push_back(std::make_pair("DataSetMessageContentMask", elementTree));
    
        return true;
    }
    
    bool
    JsonDataSetReaderMessageDataType::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        std::string elementName;
        boost::optional<const boost::property_tree::ptree&> tree;
    
        elementName = "NetworkMessageContentMask";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "JsonDataSetReaderMessageDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, networkMessageContentMask_)) {
            Log(Error, "JsonDataSetReaderMessageDataType decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "DataSetMessageContentMask";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "JsonDataSetReaderMessageDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, dataSetMessageContentMask_)) {
            Log(Error, "JsonDataSetReaderMessageDataType decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    void
    JsonDataSetReaderMessageDataType::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	JsonDataSetReaderMessageDataType* dst = dynamic_cast<JsonDataSetReaderMessageDataType*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    JsonDataSetReaderMessageDataType::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	JsonDataSetReaderMessageDataType* dst = dynamic_cast<JsonDataSetReaderMessageDataType*>(&extensionObjectBase);
    	return *const_cast<JsonDataSetReaderMessageDataType*>(this) == *dst;
    }
    
    void
    JsonDataSetReaderMessageDataType::out(std::ostream& os)
    {
        os << "NetworkMessageContentMask=" << networkMessageContentMask_;
        os << ", DataSetMessageContentMask=" << dataSetMessageContentMask_;
    }

}
